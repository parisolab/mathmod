/***************************************************************************
 *   Copyright (C) 2005 by Warp                                            *
 *                                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/
//==============================
// Function parser v2.7 by Warp
//==============================

// Comment out the following line if your compiler supports the (non-standard)
// asinh, acosh and atanh functions and you want them to be supported. If
// you are not sure, just leave it (those function will then not be supported).
#define NO_ASINH


// Uncomment the following line to disable the eval() function if it could
// be too dangerous in the target application:
//#define DISABLE_EVAL


// Comment this line out if you are not going to use the optimizer and want
// a slightly smaller library. The Optimize() method can still be called,
// but it will not do anything.
// If you are unsure, just leave it. It won't slow down the other parts of
// the library.
#define SUPPORT_OPTIMIZER


//============================================================================

#include "fparser.h"

#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>


using namespace std;

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

namespace
{
// The functions must be in alphabetical order:
enum OPCODE
{
    cAbs, cAcos,
#ifndef NO_ASINH
    cAcosh,
#endif
    cAsin,
#ifndef NO_ASINH
    cAsinh,
#endif
    cAtan,
    cAtan2,
#ifndef NO_ASINH
    cAtanh,
#endif
    cCeil, cCos, cCosh, cCot, cCsc,
#ifndef DISABLE_EVAL
    cEval,
#endif
    cExp, cPOw, cFloor, cIf, cInt, cLog, cLog10, cMax, cMin, cRnd,
    cSec, cSin, cSinh, cSqrt, cTan, cTanh,
// These do not need any ordering:
    cImmed, cJump,
    cNeg, cAdd, cSub, cMul, cDiv, cMod, cPow,
    cEqual, cLess, cGreater, cAnd, cOr,

    cDeg, cRad,

    cFCall, cPCall,

#ifdef SUPPORT_OPTIMIZER
    cVar, cDup, cInv,
#endif

    VarBegin
};

struct FuncDefinition
{
    const char* name;
    unsigned nameLength;
    unsigned opcode;
    unsigned params;

    // This is basically strcmp(), but taking 'nameLength' as string
    // length (not ending '\0'):
    bool operator<(const FuncDefinition& rhs) const
    {
        for(unsigned i = 0; i < nameLength; ++i)
        {
            if(i == rhs.nameLength) return false;
            const char c1 = name[i], c2 = rhs.name[i];
            if(c1 < c2) return true;
            if(c2 < c1) return false;
        }
        return nameLength < rhs.nameLength;
    }
};

// This list must be in alphabetical order:
const FuncDefinition Functions[]=
{
    { "abs", 3, cAbs, 1 },
    { "acos", 4, cAcos, 1 },
#ifndef NO_ASINH
    { "acosh", 5, cAcosh, 1 },
#endif
    { "asin", 4, cAsin, 1 },
#ifndef NO_ASINH
    { "asinh", 5, cAsinh, 1 },
#endif
    { "atan", 4, cAtan, 1 },
    { "atan2", 5, cAtan2, 2 },
#ifndef NO_ASINH
    { "atanh", 5, cAtanh, 1 },
#endif
    { "ceil", 4, cCeil, 1 },
    { "cos", 3, cCos, 1 },
    { "cosh", 4, cCosh, 1 },
    { "cot", 3, cCot, 1 },
    { "csc", 3, cCsc, 1 },
#ifndef DISABLE_EVAL
    { "eval", 4, cEval, 0 },
#endif
    { "exp", 3, cExp, 1 },
    { "floor", 5, cFloor, 1 },
    { "if", 2, cIf, 0 },
    { "int", 3, cInt, 1 },
    { "log", 3, cLog, 1 },
    { "log10", 5, cLog10, 1 },
    { "max", 3, cMax, 2 },
    { "min", 3, cMin, 2 },
    { "pow", 3, cPOw, 2 },
    { "rnd", 3, cRnd, 0 },
    { "sec", 3, cSec, 1 },
    { "sin", 3, cSin, 1 },
    { "sinh", 4, cSinh, 1 },
    { "sqrt", 4, cSqrt, 1 },
    { "tan", 3, cTan, 1 },
    { "tanh", 4, cTanh, 1 }
};

const unsigned FUNC_AMOUNT = sizeof(Functions)/sizeof(Functions[0]);


// BCB4 does not implement the standard lower_bound function.
// This is used instead:
const FuncDefinition* fp_lower_bound(const FuncDefinition* first,
                                     const FuncDefinition* last,
                                     const FuncDefinition& value)
{
    while(first < last)
    {
        const FuncDefinition* middle = first+(last-first)/2;
        if(*middle < value) first = middle+1;
        else last = middle;
    }
    return last;
}


// Returns a pointer to the FuncDefinition instance which 'name' is
// the same as the one given by 'F'. If no such function name exists,
// returns 0.
inline const FuncDefinition* FindFunction(const char* F)
{
    FuncDefinition func = { F, 0, 0, 0 };
    while(isalnum(F[func.nameLength])) ++func.nameLength;
    if(func.nameLength)
    {
        const FuncDefinition* found =
            fp_lower_bound(Functions, Functions+FUNC_AMOUNT, func);
        if(found == Functions+FUNC_AMOUNT || func < *found)
            return 0;
        return found;
    }
    return 0;
}
};


//---------------------------------------------------------------------------
// Copy-on-write method
//---------------------------------------------------------------------------
inline void FunctionParser::copyOnWrite()
{
    if(data->referenceCounter > 1)
    {
        Data* oldData = data;
        data = new Data(*oldData);
        --(oldData->referenceCounter);
        data->referenceCounter = 1;
    }
}


//---------------------------------------------------------------------------
// Constructors and destructors
//---------------------------------------------------------------------------
//===========================================================================
FunctionParser::FunctionParser():
    parseErrorType(FP_NO_ERROR), evalErrorType(0),
    data(new Data)
{
    data->referenceCounter = 1;
}

FunctionParser::~FunctionParser()
{
    if(--(data->referenceCounter) == 0)
    {
        delete data;
    }
}

FunctionParser::FunctionParser(const FunctionParser& cpy):
    parseErrorType(cpy.parseErrorType),
    evalErrorType(cpy.evalErrorType),
    data(cpy.data)
{
    ++(data->referenceCounter);
}

FunctionParser& FunctionParser::operator=(const FunctionParser& cpy)
{
    if(data != cpy.data)
    {
        if(--(data->referenceCounter) == 0) delete data;

        parseErrorType = cpy.parseErrorType;
        evalErrorType = cpy.evalErrorType;
        data = cpy.data;

        ++(data->referenceCounter);
    }

    return *this;
}


FunctionParser::Data::Data():
    useDegreeConversion(false),
    ByteCode(0), ByteCodeSize(0),
    Immed(0), ImmedSize(0),
    Stack(0), StackSize(0)
{}

FunctionParser::Data::~Data()
{
    if(ByteCode)
    {
        delete[] ByteCode;
        ByteCode=0;
    }
    if(Immed)
    {
        delete[] Immed;
        Immed=0;
    }
    if(Stack)
    {
        delete[] Stack;
        Stack=0;
    }
}

// Makes a deep-copy of Data:
FunctionParser::Data::Data(const Data& cpy):
    varAmount(cpy.varAmount), useDegreeConversion(cpy.useDegreeConversion),
    Variables(cpy.Variables), Constants(cpy.Constants),
    FuncPtrNames(cpy.FuncPtrNames), FuncPtrs(cpy.FuncPtrs),
    FuncParserNames(cpy.FuncParserNames), FuncParsers(cpy.FuncParsers),
    ByteCode(0), ByteCodeSize(cpy.ByteCodeSize),
    Immed(0), ImmedSize(cpy.ImmedSize),
    Stack(0), StackSize(cpy.StackSize)
{
    if(ByteCodeSize) ByteCode = new unsigned[ByteCodeSize];
    if(ImmedSize) Immed = new double[ImmedSize];
    if(StackSize) Stack = new double[StackSize];
    //for(unsigned i=0; i<cpy.FuncPtrs.size(); ++i)
        FuncPtrs = cpy.FuncPtrs;
        FuncParsers=cpy.FuncParsers;
    for(unsigned i=0; i<ByteCodeSize; ++i) ByteCode[i] = cpy.ByteCode[i];
    for(unsigned i=0; i<ImmedSize; ++i) Immed[i] = cpy.Immed[i];

    // No need to copy the stack contents because it's obsolete outside Eval()
}


//---------------------------------------------------------------------------
// Function parsing
//---------------------------------------------------------------------------
//===========================================================================
namespace
{
// Error messages returned by ErrorMsg():
const char* ParseErrorMessage[]=
{
    "Syntax error",                             // 0
    "Mismatched parenthesis",                   // 1
    "Missing ')'",                              // 2
    "Empty parentheses",                        // 3
    "Syntax error: Operator expected",          // 4
    "Not enough memory",                        // 5
    "An unexpected error ocurred. Please make a full bug report "
    "to warp@iki.fi",                           // 6
    "Syntax error in parameter 'Vars' given to "
    "FunctionParser::Parse()",                  // 7
    "Illegal number of parameters to function", // 8
    "Syntax error: Premature end of string",    // 9
    "Syntax error: Expecting ( after function", // 10
    ""
};


// Parse variables
bool ParseVars(const string& Vars, map<string, unsigned>& dest)
{
    unsigned varNumber = VarBegin;
    unsigned ind1 = 0, ind2;

    while(ind1 < Vars.size())
    {
        if(!isalpha(Vars[ind1]) && Vars[ind1]!='_') return false;
        for(ind2=ind1+1; ind2<Vars.size() && Vars[ind2]!=','; ++ind2)
            if(!isalnum(Vars[ind2]) && Vars[ind2]!='_') return false;
        const string varName = Vars.substr(ind1, ind2-ind1);

        if(dest.insert(make_pair(varName, varNumber++)).second == false)
            return false;

        ind1 = ind2+1;
    }
    return true;
}
};

bool FunctionParser::isValidName(const std::string& name) const
{
    if(name.empty() || (!isalpha(name[0]) && name[0] != '_')) return false;
    for(unsigned i=0; i<name.size(); ++i)
        if(!isalnum(name[i]) && name[i] != '_') return false;

    if(FindFunction(name.c_str())) return false;

    return true;
}


// Constants:
bool FunctionParser::AddConstant(const string& name, double value)
{
    if(isValidName(name))
    {
        const char* n = name.c_str();
        if(FindVariable(n, data->FuncParserNames) !=
                data->FuncParserNames.end() ||
                FindVariable(n, data->FuncPtrNames) !=
                data->FuncPtrNames.end())
            return false;

        copyOnWrite();

        data->Constants[name] = value;
        return true;
    }
    return false;
}

// Function pointers
bool FunctionParser::AddFunction(const std::string& name,
                                 FunctionPtr func, unsigned paramsAmount)
{
    if(paramsAmount == 0) return false; // Currently must be at least one

    if(isValidName(name))
    {
        const char* n = name.c_str();
        if(FindVariable(n, data->FuncParserNames) !=
                data->FuncParserNames.end() ||
                FindConstant(n) != data->Constants.end())
            return false;

        copyOnWrite();

        data->FuncPtrNames[name] = data->FuncPtrs.size();
        data->FuncPtrs.push_back(Data::FuncPtrData(func, paramsAmount));
        return true;
    }
    return false;
}

bool FunctionParser::checkRecursiveLinking(const FunctionParser* fp) const
{
    if(fp == this) return true;
    for(unsigned i=0; i<fp->data->FuncParsers.size(); ++i)
        if(checkRecursiveLinking(fp->data->FuncParsers[i])) return true;
    return false;
}

bool FunctionParser::AddFunction(const std::string& name,
                                 FunctionParser& parser)
{
    if(parser.data->varAmount == 0) // Currently must be at least one
        return false;

    if(isValidName(name))
    {
        const char* n = name.c_str();
        if(FindVariable(n, data->FuncPtrNames) != data->FuncPtrNames.end() ||
                FindConstant(n) != data->Constants.end())
            return false;

        if(checkRecursiveLinking(&parser)) return false;

        copyOnWrite();

        data->FuncParserNames[name] = data->FuncParsers.size();
        data->FuncParsers.push_back(&parser);
        return true;
    }
    return false;
}



// Main parsing function
// ---------------------
int FunctionParser::Parse(const std::string& Function,
                          const std::string& Vars,
                          bool useDegrees)
{
    copyOnWrite();

    data->Variables.clear();

    if(!ParseVars(Vars, data->Variables))
    {
        parseErrorType = INVALID_VARS;
        return Function.size();
    }
    data->varAmount = data->Variables.size(); // this is for Eval()

    const char* Func = Function.c_str();

    parseErrorType = FP_NO_ERROR;

    int Result = CheckSyntax(Func);
    if(Result>=0) return Result;

    data->useDegreeConversion = useDegrees;
    if(!Compile(Func)) return Function.size();

    data->Variables.clear();

    parseErrorType = FP_NO_ERROR;
    return -1;
}

namespace
{
// Is given char an operator?
inline bool IsOperator(int c)
{
    return strchr("+-*/%^=<>&|",c)!=NULL;
}

// skip whitespace
inline void sws(const char* F, int& Ind)
{
    while(F[Ind] && isspace(F[Ind])) ++Ind;
}
};

// Returns an iterator to the variable with the same name as 'F', or to
// Variables.end() if no such variable exists:
inline FunctionParser::Data::VarMap_t::const_iterator
FunctionParser::FindVariable(const char* F, const Data::VarMap_t& vars) const
{
    if(vars.size())
    {
        unsigned ind = 0;
        while(isalnum(F[ind]) || F[ind] == '_') ++ind;
        if(ind)
        {
            string name(F, ind);
            return vars.find(name);
        }
    }
    return vars.end();
}

inline FunctionParser::Data::ConstMap_t::const_iterator
FunctionParser::FindConstant(const char* F) const
{
    if(data->Constants.size())
    {
        unsigned ind = 0;
        while(isalnum(F[ind]) || F[ind] == '_') ++ind;
        if(ind)
        {
            string name(F, ind);
            return data->Constants.find(name);
        }
    }
    return data->Constants.end();
}

//---------------------------------------------------------------------------
// Check function string syntax
// ----------------------------
int FunctionParser::CheckSyntax(const char* Function)
{
    const Data::VarMap_t& Variables = data->Variables;
    const Data::ConstMap_t& Constants = data->Constants;
    const Data::VarMap_t& FuncPtrNames = data->FuncPtrNames;
    const Data::VarMap_t& FuncParserNames = data->FuncParserNames;

    vector<int> functionParenthDepth;

    int Ind=0, ParenthCnt=0, c;
    char* Ptr;
    //double rt;

    while(true)
    {
        sws(Function, Ind);
        c=Function[Ind];

// Check for valid operand (must appear)

        // Check for leading -
        if(c=='-')
        {
            sws(Function, ++Ind);
            c=Function[Ind];
        }
        if(c==0)
        {
            parseErrorType=PREMATURE_EOS;
            return Ind;
        }

        // Check for math function
        bool foundFunc = false;
        const FuncDefinition* fptr = FindFunction(&Function[Ind]);
        if(fptr)
        {
            Ind += fptr->nameLength;
            foundFunc = true;
        }
        else
        {
            // Check for user-defined function
            Data::VarMap_t::const_iterator fIter =
                FindVariable(&Function[Ind], FuncPtrNames);
            if(fIter != FuncPtrNames.end())
            {
                Ind += fIter->first.size();
                foundFunc = true;
            }
            else
            {
                Data::VarMap_t::const_iterator pIter =
                    FindVariable(&Function[Ind], FuncParserNames);
                if(pIter != FuncParserNames.end())
                {
                    Ind += pIter->first.size();
                    foundFunc = true;
                }
            }
        }

        if(foundFunc)
        {
            sws(Function, Ind);
            c = Function[Ind];
            if(c!='(')
            {
                parseErrorType=EXPECT_PARENTH_FUNC;
                return Ind;
            }
            functionParenthDepth.push_back(ParenthCnt+1);
        }

        // Check for opening parenthesis
        if(c=='(')
        {
            ++ParenthCnt;
            sws(Function, ++Ind);
            if(Function[Ind]==')')
            {
                parseErrorType=EMPTY_PARENTH;
                return Ind;
            }
            continue;
        }

        // Check for number
        if(isdigit(c) || ((c=='.') && isdigit(Function[Ind+1])))
        {
            strtod(&Function[Ind], &Ptr);
            Ind += int(Ptr-&Function[Ind]);
            sws(Function, Ind);
            c = Function[Ind];
        }
        else
        {
            // Check for variable
            Data::VarMap_t::const_iterator vIter =
                FindVariable(&Function[Ind], Variables);
            if(vIter != Variables.end())
                Ind += vIter->first.size();
            else
            {
                // Check for constant
                Data::ConstMap_t::const_iterator cIter =
                    FindConstant(&Function[Ind]);
                if(cIter != Constants.end())
                    Ind += cIter->first.size();
                else
                {
                    parseErrorType=SYNTAX_ERROR;
                    return Ind;
                }
            }
            sws(Function, Ind);
            c = Function[Ind];
        }

        // Check for closing parenthesis
        while(c==')')
        {
            if(functionParenthDepth.size() &&
                    functionParenthDepth.back() == ParenthCnt)
                functionParenthDepth.pop_back();
            if((--ParenthCnt)<0)
            {
                parseErrorType=MISM_PARENTH;
                return Ind;
            }
            sws(Function, ++Ind);
            c=Function[Ind];
        }

// If we get here, we have a legal operand and now a legal operator or
// end of string must follow

        // Check for EOS
        if(c==0) break; // The only way to end the checking loop without error
        // Check for operator
        if(!IsOperator(c) &&
                (c != ',' || functionParenthDepth.empty() ||
                 functionParenthDepth.back() != ParenthCnt))
        {
            parseErrorType=EXPECT_OPERATOR;
            return Ind;
        }

// If we get here, we have an operand and an operator; the next loop will
// check for another operand (must appear)
        ++Ind;
    } // while

    // Check that all opened parentheses are also closed
    if(ParenthCnt>0)
    {
        parseErrorType=MISSING_PARENTH;
        return Ind;
    }

// The string is ok
    parseErrorType=FP_NO_ERROR;
    return -1;
}


// Compile function string to bytecode
// -----------------------------------
bool FunctionParser::Compile(const char* Function)
{
    if(data->ByteCode)
    {
        delete[] data->ByteCode;
        data->ByteCode=0;
    }
    if(data->Immed)
    {
        delete[] data->Immed;
        data->Immed=0;
    }
    if(data->Stack)
    {
        delete[] data->Stack;
        data->Stack=0;
    }

    vector<unsigned> byteCode;
    byteCode.reserve(1024);
    tempByteCode = &byteCode;

    vector<double> immed;
    immed.reserve(1024);
    tempImmed = &immed;

    data->StackSize = StackPtr = 0;

    CompileExpression(Function, 0);
    if(parseErrorType != FP_NO_ERROR) return false;

    data->ByteCodeSize = byteCode.size();
    data->ImmedSize = immed.size();

    if(data->ByteCodeSize)
    {
        data->ByteCode = new unsigned[data->ByteCodeSize];
        memcpy(data->ByteCode, &byteCode[0],
               sizeof(unsigned)*data->ByteCodeSize);
    }
    if(data->ImmedSize)
    {
        data->Immed = new double[data->ImmedSize];
        memcpy(data->Immed, &immed[0],
               sizeof(double)*data->ImmedSize);
    }
    if(data->StackSize)
    {
        data->Stack = new double[data->StackSize];
    }
    return true;
}


inline void FunctionParser::AddCompiledByte(unsigned c)
{
    tempByteCode->push_back(c);
}

inline void FunctionParser::AddImmediate(double i)
{
    tempImmed->push_back(i);
}

inline void FunctionParser::AddFunctionOpcode(unsigned opcode)
{
    if(data->useDegreeConversion)
        switch(opcode)
        {
        case cCos:
        case cCosh:
        case cCot:
        case cCsc:
        case cSec:
        case cSin:
        case cSinh:
        case cTan:
        case cTanh:
            AddCompiledByte(cRad);
        }

    AddCompiledByte(opcode);

    if(data->useDegreeConversion)
        switch(opcode)
        {
        case cAcos:
#ifndef NO_ASINH
        case cAcosh:
        case cAsinh:
        case cAtanh:
#endif
        case cAsin:
        case cAtan:
        case cAtan2:
            AddCompiledByte(cDeg);
        }
}

inline void FunctionParser::incStackPtr()
{
    if(++StackPtr > data->StackSize) ++(data->StackSize);
}

// Compile if()
int FunctionParser::CompileIf(const char* F, int ind)
{
    int ind2 = CompileExpression(F, ind, true); // condition
    sws(F, ind2);
    if(F[ind2] != ',')
    {
        parseErrorType=ILL_PARAMS_AMOUNT;
        return ind2;
    }
    AddCompiledByte(cIf);
    unsigned curByteCodeSize = tempByteCode->size();
    AddCompiledByte(0); // Jump index; to be set later
    AddCompiledByte(0); // Immed jump index; to be set later

    --StackPtr;

    ind2 = CompileExpression(F, ind2+1, true); // then
    sws(F, ind2);
    if(F[ind2] != ',')
    {
        parseErrorType=ILL_PARAMS_AMOUNT;
        return ind2;
    }
    AddCompiledByte(cJump);
    unsigned curByteCodeSize2 = tempByteCode->size();
    unsigned curImmedSize2 = tempImmed->size();
    AddCompiledByte(0); // Jump index; to be set later
    AddCompiledByte(0); // Immed jump index; to be set later

    --StackPtr;

    ind2 = CompileExpression(F, ind2+1, true); // else
    sws(F, ind2);
    if(F[ind2] != ')')
    {
        parseErrorType=ILL_PARAMS_AMOUNT;
        return ind2;
    }

    // Set jump indices
    (*tempByteCode)[curByteCodeSize] = curByteCodeSize2+1;
    (*tempByteCode)[curByteCodeSize+1] = curImmedSize2;
    (*tempByteCode)[curByteCodeSize2] = tempByteCode->size()-1;
    (*tempByteCode)[curByteCodeSize2+1] = tempImmed->size();

    return ind2+1;
}

int FunctionParser::CompileFunctionParams(const char* F, int ind,
        unsigned requiredParams)
{
    unsigned curStackPtr = StackPtr;
    int ind2 = CompileExpression(F, ind);

    if(StackPtr != curStackPtr+requiredParams)
    {
        parseErrorType=ILL_PARAMS_AMOUNT;
        return ind;
    }

    StackPtr -= requiredParams - 1;
    sws(F, ind2);
    return ind2+1; // F[ind2] is ')'
}

// Compiles element
int FunctionParser::CompileElement(const char* F, int ind)
{
    sws(F, ind);
    char c = F[ind];

    if(c == '(')
    {
        ind = CompileExpression(F, ind+1);
        sws(F, ind);
        return ind+1; // F[ind] is ')'
    }

    if(isdigit(c) || (c=='.') /*|| c=='-'*/) // Number
    {
        const char* startPtr = &F[ind];
        char* endPtr;
        double val = strtod(startPtr, &endPtr);
        AddImmediate(val);
        AddCompiledByte(cImmed);
        incStackPtr();
        return ind+(endPtr-startPtr);
    }

    if(isalpha(c) || c == '_') // Function, variable or constant
    {
        const FuncDefinition* func = FindFunction(F+ind);
        if(func) // is function
        {
            int ind2 = ind + func->nameLength;
            sws(F, ind2); // F[ind2] is '('
            if(strcmp(func->name, "if") == 0) // "if" is a special case
            {
                return CompileIf(F, ind2+1);
            }

#ifndef DISABLE_EVAL
            unsigned requiredParams =
                strcmp(func->name, "eval") == 0 ?
                data->Variables.size() : func->params;
#else
            unsigned requiredParams = func->params;
#endif
            ind2 = CompileFunctionParams(F, ind2+1, requiredParams);
            AddFunctionOpcode(func->opcode);
            return ind2; // F[ind2-1] is ')'
        }

        Data::VarMap_t::const_iterator vIter =
            FindVariable(F+ind, data->Variables);
        if(vIter != data->Variables.end()) // is variable
        {
            AddCompiledByte(vIter->second);
            incStackPtr();
            return ind + vIter->first.size();
        }

        Data::ConstMap_t::const_iterator cIter = FindConstant(F+ind);
        if(cIter != data->Constants.end()) // is constant
        {
            AddImmediate(cIter->second);
            AddCompiledByte(cImmed);
            incStackPtr();
            return ind + cIter->first.size();
        }

        Data::VarMap_t::const_iterator fIter =
            FindVariable(F+ind, data->FuncPtrNames);
        if(fIter != data->FuncPtrNames.end()) // is user-defined func pointer
        {
            unsigned index = fIter->second;

            int ind2 = ind + fIter->first.length();
            sws(F, ind2); // F[ind2] is '('

            ind2 = CompileFunctionParams(F, ind2+1,
                                         data->FuncPtrs[index].params);

            AddCompiledByte(cFCall);
            AddCompiledByte(index);
            return ind2;
        }

        Data::VarMap_t::const_iterator pIter =
            FindVariable(F+ind, data->FuncParserNames);
        if(pIter != data->FuncParserNames.end()) // is user-defined func parser
        {
            unsigned index = pIter->second;

            int ind2 = ind + pIter->first.length();
            sws(F, ind2); // F[ind2] is '('

            ind2 = CompileFunctionParams
                   (F, ind2+1, data->FuncParsers[index]->data->varAmount);

            AddCompiledByte(cPCall);
            AddCompiledByte(index);
            return ind2;
        }
    }

    parseErrorType = UNEXPECTED_ERROR;
    return ind;
}

// Compiles '^'
int FunctionParser::CompilePow(const char* F, int ind)
{
    int ind2 = CompileElement(F, ind);
    sws(F, ind2);

    while(F[ind2] == '^')
    {
        ind2 = CompileUnaryMinus(F, ind2+1);
        sws(F, ind2);
        AddCompiledByte(cPow);
        --StackPtr;
    }

    return ind2;
}

// Compiles unary '-'
int FunctionParser::CompileUnaryMinus(const char* F, int ind)
{
    sws(F, ind);
    if(F[ind] == '-')
    {
        int ind2 = ind+1;
        sws(F, ind2);
        ind2 = CompilePow(F, ind2);
        sws(F, ind2);

        // if we are negating a constant, negate the constant itself:
        if(tempByteCode->back() == cImmed)
            tempImmed->back() = -tempImmed->back();

        // if we are negating a negation, we can remove both:
        else if(tempByteCode->back() == cNeg)
            tempByteCode->pop_back();

        else
            AddCompiledByte(cNeg);

        return ind2;
    }

    int ind2 = CompilePow(F, ind);
    sws(F, ind2);
    return ind2;
}

// Compiles '*', '/' and '%'
int FunctionParser::CompileMult(const char* F, int ind)
{
    int ind2 = CompileUnaryMinus(F, ind);
    sws(F, ind2);
    char op;

    while((op = F[ind2]) == '*' || op == '/' || op == '%')
    {
        ind2 = CompileUnaryMinus(F, ind2+1);
        sws(F, ind2);
        switch(op)
        {
        case '*':
            AddCompiledByte(cMul);
            break;
        case '/':
            AddCompiledByte(cDiv);
            break;
        case '%':
            AddCompiledByte(cMod);
            break;
        }
        --StackPtr;
    }

    return ind2;
}

// Compiles '+' and '-'
int FunctionParser::CompileAddition(const char* F, int ind)
{
    int ind2 = CompileMult(F, ind);
    sws(F, ind2);
    char op;

    while((op = F[ind2]) == '+' || op == '-')
    {
        ind2 = CompileMult(F, ind2+1);
        sws(F, ind2);
        AddCompiledByte(op=='+' ? cAdd : cSub);
        --StackPtr;
    }

    return ind2;
}

// Compiles '=', '<' and '>'
int FunctionParser::CompileComparison(const char* F, int ind)
{
    int ind2 = CompileAddition(F, ind);
    sws(F, ind2);
    char op;

    while((op = F[ind2]) == '=' || op == '<' || op == '>')
    {
        ind2 = CompileAddition(F, ind2+1);
        sws(F, ind2);
        switch(op)
        {
        case '=':
            AddCompiledByte(cEqual);
            break;
        case '<':
            AddCompiledByte(cLess);
            break;
        case '>':
            AddCompiledByte(cGreater);
            break;
        }
        --StackPtr;
    }

    return ind2;
}

// Compiles '&'
int FunctionParser::CompileAnd(const char* F, int ind)
{
    int ind2 = CompileComparison(F, ind);
    sws(F, ind2);

    while(F[ind2] == '&')
    {
        ind2 = CompileComparison(F, ind2+1);
        sws(F, ind2);
        AddCompiledByte(cAnd);
        --StackPtr;
    }

    return ind2;
}

// Compiles '|'
int FunctionParser::CompileOr(const char* F, int ind)
{
    int ind2 = CompileAnd(F, ind);
    sws(F, ind2);

    while(F[ind2] == '|')
    {
        ind2 = CompileAnd(F, ind2+1);
        sws(F, ind2);
        AddCompiledByte(cOr);
        --StackPtr;
    }

    return ind2;
}

// Compiles ','
int FunctionParser::CompileExpression(const char* F, int ind, bool stopAtComma)
{
    int ind2 = CompileOr(F, ind);
    sws(F, ind2);

    if(stopAtComma) return ind2;

    while(F[ind2] == ',')
    {
        ind2 = CompileOr(F, ind2+1);
        sws(F, ind2);
    }

    return ind2;
}

// Return parse error message
// --------------------------
const char* FunctionParser::ErrorMsg() const
{
    if(parseErrorType != FP_NO_ERROR) return ParseErrorMessage[parseErrorType];
    return 0;
}

//--------------------------------------------------------------------------
// Function evaluation
//--------------------------------------------------------------------------
//==============================================================
namespace
{
inline int doubleToInt(double d)
{
    return d<0 ? -int((-d)+.5) : int(d+.5);
}

inline double Min(double d1, double d2)
{
    return d1<d2 ? d1 : d2;
}
inline double Max(double d1, double d2)
{
    return d1>d2 ? d1 : d2;
}

inline double DegreesToRadians(double degrees)
{
    return degrees*(M_PI/180.0);
}
inline double RadiansToDegrees(double radians)
{
    return radians*(180.0/M_PI);
}
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void FunctionParser::AllocateMemoryForStackArray(double* , double* , double* , double* , double* , double* , double* , double* , double* ,
        double t1, int grmax1, double* Results1, int depth1, int *DataA, double* DataT[])
{

//  This part is for the Stack memory optimisation:   //
    unsigned* const ByteCode = data->ByteCode;
    unsigned ByteCodeSize = data->ByteCodeSize;
    int SP =0, MaxSP = 0;
    unsigned IP;

    if(MaxSP < SP) MaxSP = SP;
    for(IP=0; IP<ByteCodeSize; ++IP)
    {
        switch(ByteCode[IP])
        {
// Functions:
        case   cAdd:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case   cSub:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case   cMul:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case   cDiv:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case   cSin:
            break;
        case   cCos:
            break;
        case   cPow:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case   cPOw:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case   cExp:
            break;
        case   cNeg:
            break;
        case cFloor:
            break;
        case   cAbs:
            break;
// Misc:
        case cImmed:
            ++SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case  cJump:
            break;
        case  cAcos:
            break;
#ifndef NO_ASINH
        case cAcosh:
            break;
#endif
        case  cAsin:
            break;
#ifndef NO_ASINH
        case cAsinh:
            break;
#endif
        case  cAtan:
            break;
        case cAtan2:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
#ifndef NO_ASINH
        case cAtanh:
            break;
#endif
        case  cCeil:
            break;
        case  cCosh:
            break;
        case   cCot:
            break;
        case   cCsc:
            break;
#ifndef DISABLE_EVAL
        case  cEval:
            break;
#endif
        case    cIf:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case   cInt:
            break;
        case   cLog:
            break;
        case cLog10:
            break;
        case   cMax:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case   cMin:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case   cSec:
            break;
        case  cSinh:
            break;
        case  cSqrt:
            break;
        case   cTan:
            break;
        case  cTanh:
            break;
// Operators:
        case     cMod:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case   cEqual:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case    cLess:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case cGreater:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case     cAnd:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case      cOr:
            --SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
// Degrees-radians conversion:
        case   cDeg:
            break;
        case   cRad:
            break;
// User-defined function calls:
        case cFCall:
            break;
        case cPCall:
            break;
#ifdef SUPPORT_OPTIMIZER
        case   cVar:
            break;
        case   cDup:
            ++SP;
            if(MaxSP < SP) MaxSP = SP;
            break;
        case   cInv:
            break;
#endif
// Variables:
        default:
            ++SP;
            if(MaxSP < SP) MaxSP = SP;
        }
    }
//End memory optimisation

    delete (StackArray);
    StackArray  = new double[64*MaxSP];
    datatable   = DataT;
    dataactive  = DataA;
    grmax       = grmax1;
    t_parameter = t1;
    Results     = Results1;
    depth       = depth1;
};


///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void FunctionParser::Eval6(int )
{
    const unsigned* const ByteCode = data->ByteCode;
    const double* const Immed = data->Immed;
    double* const Stack = data->Stack;
    double* const StackArraytmp = StackArray;
    double* const results = Results;
    const unsigned ByteCodeSize = data->ByteCodeSize;
    unsigned IP, DP=0;
    int SP=-1;
    int i,j,k,l,I,J,IJK,StartI,StartJ,StartK;
    unsigned SPtmp;
    int max = grmax, maxxmax = max*max;
    double* const xlocal = datatable[0];
    double* const ylocal = datatable[1];
    double* const zlocal = datatable[2];

    double* const Dxy = datatable[13];
    double* const Dxz = datatable[14];
    double* const Dyz = datatable[15];
    double* const Dyx = datatable[16];
    double* const Dzx = datatable[17];
    double* const Dzy = datatable[18];

    double* const Exy = datatable[19];
    double* const Exz = datatable[20];
    double* const Eyz = datatable[21];
    double* const Eyx = datatable[22];
    double* const Ezx = datatable[23];
    double* const Ezy = datatable[24];

    double* const Fxy = datatable[25];
    double* const Fxz = datatable[26];
    double* const Fyz = datatable[27];
    double* const Fyx = datatable[28];
    double* const Fzx = datatable[29];
    double* const Fzy = datatable[30];

    double *  SPtmppt;
    double powval, productval, savepowvalue, abssavepowvalue;
    unsigned index;
    unsigned params;
    int startI=0, limitI=depth;

    for(StartI = startI; StartI<limitI; StartI+=4)
    {
//x
        l=0;
        for(i=0; i<4; i++)
            for(j=0; j<4; j++)
                for(k=0; k<4; k++)
                    Vars[l++]  = xlocal[i+StartI];
        if(dataactive[4]==1)
        {
//A[x]
            l=0;
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                    for(k=0; k<4; k++)
                        Vars[256 + (l++)]  = xlocal[i+StartI+depth];
        }
        if(dataactive[7]==1)
        {
//B[x]
            l=0;
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                    for(k=0; k<4; k++)
                        Vars[448 + (l++)]  = xlocal[i+StartI+2*depth];
        }
        if(dataactive[10]==1)
        {
//C[x]
            l=0;
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                    for(k=0; k<4; k++)
                        Vars[640 + (l++)]   = xlocal[i+StartI+3*depth];
        }
        for(StartJ=0; StartJ<depth; StartJ+=4)
        {
//y
            l=0;
            for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                    for(k=0; k<4; k++)
                        Vars[64 + (l++)]  = ylocal[j+StartJ];
            if(dataactive[5]==1)
            {
//A[y]
                l=0;
                for(i=0; i<4; i++)
                    for(j=0; j<4; j++)
                        for(k=0; k<4; k++)
                            Vars[320 + (l++)] = ylocal[j+StartJ+depth];
            }
            if(dataactive[8]==1)
            {
//B[y]
                l=0;
                for(i=0; i<4; i++)
                    for(j=0; j<4; j++)
                        for(k=0; k<4; k++)
                            Vars[512 + (l++)] = ylocal[j+StartJ+2*depth];
            }
            if(dataactive[11]==1)
            {
//C[y]
                l=0;
                for(i=0; i<4; i++)
                    for(j=0; j<4; j++)
                        for(k=0; k<4; k++)
                            Vars[704 + (l++)]   = ylocal[j+StartJ+3*depth];
            }
            if(dataactive[13]==1)
            {
//D[x,y]
                l=0;
                for(i=0; i<4; i++)
                    for(j=0; j<4; j++)
                        for(k=0; k<4; k++)
                            Vars[832 + (l++)] = Dxy[(i+StartI)*depth + j+StartJ];
            }
            if(dataactive[16]==1)
            {
//D[y,x]
                l=0;
                for(i=0; i<4; i++)
                    for(j=0; j<4; j++)
                        for(k=0; k<4; k++)
                            Vars[1024 + (l++)] = Dyx[(i+StartI)*depth + j+StartJ];
            }
            if(dataactive[19]==1)
            {
//E[x,y]
                l=0;
                for(i=0; i<4; i++)
                    for(j=0; j<4; j++)
                        for(k=0; k<4; k++)
                            Vars[1216 + (l++)] = Exy[(i+StartI)*depth + j+StartJ];
            }
            if(dataactive[22]==1)
            {
//E[y,x]
                l=0;
                for(i=0; i<4; i++)
                    for(j=0; j<4; j++)
                        for(k=0; k<4; k++)
                            Vars[1408 + (l++)] = Eyx[(i+StartI)*depth + j+StartJ];
            }
            if(dataactive[25]==1)
            {
//F[x,y]
                l=0;
                for(i=0; i<4; i++)
                    for(j=0; j<4; j++)
                        for(k=0; k<4; k++)
                            Vars[1600 + (l++)] = Fxy[(i+StartI)*depth + j+StartJ];
            }
            if(dataactive[28]==1)
            {
//F[y,x]
                l=0;
                for(i=0; i<4; i++)
                    for(j=0; j<4; j++)
                        for(k=0; k<4; k++)
                            Vars[1792 + (l++)] = Fyx[(i+StartI)*depth + j+StartJ];
            }

            for(StartK=0; StartK<depth; StartK+=4)
            {
                DP=0;
                SP=-1;
                /// Initialise the Vars array
//z
                l=0;
                for(i=0; i<4; i++)
                    for(j=0; j<4; j++)
                        for(k=0; k<4; k++)
                            Vars[128 + (l++)] = zlocal[k+StartK];
                if(dataactive[6]==1)
                {
//A[z]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[384 + (l++)] = zlocal[k+StartK+depth];
                }
                if(dataactive[9]==1)
                {
//B[z]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[576 + (l++)]   = zlocal[k+StartK+2*depth];
                }
//C[z]
                l=0;
                for(i=0; i<4; i++)
                    for(j=0; j<4; j++)
                        for(k=0; k<4; k++)
                            Vars[768 +  (l++)]  = zlocal[k+StartK+3*depth];
//+++++++++++
                if(dataactive[14]==1)
                {
//D[x,z]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[896 + (l++)] = Dxz[(i+StartI)*depth +k+StartK];
                }
                if(dataactive[17]==1)
                {
//D[z,x]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[1088 + (l++)] = Dzx[(i+StartI)*depth +k+StartK];
                }
                if(dataactive[15]==1)
                {
//D[y,z]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[960 + (l++)] = Dyz[(j+StartJ)*depth +k+StartK];
                }
                if(dataactive[18]==1)
                {
//D[z,y]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[1152 + (l++)] = Dzy[(j+StartJ)*depth +k+StartK];
                }

//+++++++++++
                if(dataactive[20]==1)
                {
//E[x,z]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[1280 + (l++)] = Exz[(i+StartI)*depth +k+StartK];
                }
                if(dataactive[23]==1)
                {
//E[z,x]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[1472 + (l++)] = Ezx[(i+StartI)*depth +k+StartK];
                }
                if(dataactive[21]==1)
                {
//E[y,z]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[1344 + (l++)] = Eyz[(j+StartJ)*depth +k+StartK];
                }
                if(dataactive[24]==1)
                {
//E[z,y]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[1536 + (l++)] = Ezy[(j+StartJ)*depth +k+StartK];
                }

//++++++++++
                if(dataactive[26]==1)
                {
//F[x,z]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[1664 + (l++)] = Fxz[(i+StartI)*depth +k+StartK];
                }
                if(dataactive[29]==1)
                {
//F[z,x]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[1856 + (l++)] = Fzx[(i+StartI)*depth +k+StartK];
                }
                if(dataactive[27]==1)
                {
//F[y,z]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[1728 + (l++)] = Fyz[(j+StartJ)*depth +k+StartK];
                }
                if(dataactive[30]==1)
                {
//F[z,y]
                    l=0;
                    for(i=0; i<4; i++)
                        for(j=0; j<4; j++)
                            for(k=0; k<4; k++)
                                Vars[1920 + (l++)] = Fzy[(j+StartJ)*depth +k+StartK];
                }

                /// Start Calculations for the 4x4x4 voxels :
                for(IP=0; IP<ByteCodeSize; ++IP)
                {
                    switch(ByteCode[IP])
                    {
// Functions:
                    case   cAdd:
                        SPtmp     = (SP-1)*64;
                        SPtmppt   = &StackArraytmp[SPtmp];

                        SPtmppt[0]  += SPtmppt[64];
                        SPtmppt[1]  += SPtmppt[65];
                        SPtmppt[2]  += SPtmppt[66];
                        SPtmppt[3]  += SPtmppt[67];
                        SPtmppt[4]  += SPtmppt[68];
                        SPtmppt[5]  += SPtmppt[69];
                        SPtmppt[6]  += SPtmppt[70];
                        SPtmppt[7]  += SPtmppt[71];
                        SPtmppt[8]  += SPtmppt[72];
                        SPtmppt[9]  += SPtmppt[73];
                        SPtmppt[10] += SPtmppt[74];
                        SPtmppt[11] += SPtmppt[75];
                        SPtmppt[12] += SPtmppt[76];
                        SPtmppt[13] += SPtmppt[77];
                        SPtmppt[14] += SPtmppt[78];
                        SPtmppt[15] += SPtmppt[79];
                        SPtmppt[16] += SPtmppt[80];
                        SPtmppt[17] += SPtmppt[81];
                        SPtmppt[18] += SPtmppt[82];
                        SPtmppt[19] += SPtmppt[83];
                        SPtmppt[20] += SPtmppt[84];
                        SPtmppt[21] += SPtmppt[85];
                        SPtmppt[22] += SPtmppt[86];
                        SPtmppt[23] += SPtmppt[87];
                        SPtmppt[24] += SPtmppt[88];
                        SPtmppt[25] += SPtmppt[89];
                        SPtmppt[26] += SPtmppt[90];
                        SPtmppt[27] += SPtmppt[91];
                        SPtmppt[28] += SPtmppt[92];
                        SPtmppt[29] += SPtmppt[93];
                        SPtmppt[30] += SPtmppt[94];
                        SPtmppt[31] += SPtmppt[95];
                        SPtmppt[32] += SPtmppt[96];
                        SPtmppt[33] += SPtmppt[97];
                        SPtmppt[34] += SPtmppt[98];
                        SPtmppt[35] += SPtmppt[99];
                        SPtmppt[36] += SPtmppt[100];
                        SPtmppt[37] += SPtmppt[101];
                        SPtmppt[38] += SPtmppt[102];
                        SPtmppt[39] += SPtmppt[103];
                        SPtmppt[40] += SPtmppt[104];
                        SPtmppt[41] += SPtmppt[105];
                        SPtmppt[42] += SPtmppt[106];
                        SPtmppt[43] += SPtmppt[107];
                        SPtmppt[44] += SPtmppt[108];
                        SPtmppt[45] += SPtmppt[109];
                        SPtmppt[46] += SPtmppt[110];
                        SPtmppt[47] += SPtmppt[111];
                        SPtmppt[48] += SPtmppt[112];
                        SPtmppt[49] += SPtmppt[113];
                        SPtmppt[50] += SPtmppt[114];
                        SPtmppt[51] += SPtmppt[115];
                        SPtmppt[52] += SPtmppt[116];
                        SPtmppt[53] += SPtmppt[117];
                        SPtmppt[54] += SPtmppt[118];
                        SPtmppt[55] += SPtmppt[119];
                        SPtmppt[56] += SPtmppt[120];
                        SPtmppt[57] += SPtmppt[121];
                        SPtmppt[58] += SPtmppt[122];
                        SPtmppt[59] += SPtmppt[123];
                        SPtmppt[60] += SPtmppt[124];
                        SPtmppt[61] += SPtmppt[125];
                        SPtmppt[62] += SPtmppt[126];
                        SPtmppt[63] += SPtmppt[127];

                        --SP;

                        break;
                    case   cSub:
                        SPtmp     = (SP-1)*64;
                        SPtmppt   = &StackArraytmp[SPtmp];

                        SPtmppt[0]  -= SPtmppt[64];
                        SPtmppt[1]  -= SPtmppt[65];
                        SPtmppt[2]  -= SPtmppt[66];
                        SPtmppt[3]  -= SPtmppt[67];
                        SPtmppt[4]  -= SPtmppt[68];
                        SPtmppt[5]  -= SPtmppt[69];
                        SPtmppt[6]  -= SPtmppt[70];
                        SPtmppt[7]  -= SPtmppt[71];
                        SPtmppt[8]  -= SPtmppt[72];
                        SPtmppt[9]  -= SPtmppt[73];
                        SPtmppt[10] -= SPtmppt[74];
                        SPtmppt[11] -= SPtmppt[75];
                        SPtmppt[12] -= SPtmppt[76];
                        SPtmppt[13] -= SPtmppt[77];
                        SPtmppt[14] -= SPtmppt[78];
                        SPtmppt[15] -= SPtmppt[79];
                        SPtmppt[16] -= SPtmppt[80];
                        SPtmppt[17] -= SPtmppt[81];
                        SPtmppt[18] -= SPtmppt[82];
                        SPtmppt[19] -= SPtmppt[83];
                        SPtmppt[20] -= SPtmppt[84];
                        SPtmppt[21] -= SPtmppt[85];
                        SPtmppt[22] -= SPtmppt[86];
                        SPtmppt[23] -= SPtmppt[87];
                        SPtmppt[24] -= SPtmppt[88];
                        SPtmppt[25] -= SPtmppt[89];
                        SPtmppt[26] -= SPtmppt[90];
                        SPtmppt[27] -= SPtmppt[91];
                        SPtmppt[28] -= SPtmppt[92];
                        SPtmppt[29] -= SPtmppt[93];
                        SPtmppt[30] -= SPtmppt[94];
                        SPtmppt[31] -= SPtmppt[95];
                        SPtmppt[32] -= SPtmppt[96];
                        SPtmppt[33] -= SPtmppt[97];
                        SPtmppt[34] -= SPtmppt[98];
                        SPtmppt[35] -= SPtmppt[99];
                        SPtmppt[36] -= SPtmppt[100];
                        SPtmppt[37] -= SPtmppt[101];
                        SPtmppt[38] -= SPtmppt[102];
                        SPtmppt[39] -= SPtmppt[103];
                        SPtmppt[40] -= SPtmppt[104];
                        SPtmppt[41] -= SPtmppt[105];
                        SPtmppt[42] -= SPtmppt[106];
                        SPtmppt[43] -= SPtmppt[107];
                        SPtmppt[44] -= SPtmppt[108];
                        SPtmppt[45] -= SPtmppt[109];
                        SPtmppt[46] -= SPtmppt[110];
                        SPtmppt[47] -= SPtmppt[111];
                        SPtmppt[48] -= SPtmppt[112];
                        SPtmppt[49] -= SPtmppt[113];
                        SPtmppt[50] -= SPtmppt[114];
                        SPtmppt[51] -= SPtmppt[115];
                        SPtmppt[52] -= SPtmppt[116];
                        SPtmppt[53] -= SPtmppt[117];
                        SPtmppt[54] -= SPtmppt[118];
                        SPtmppt[55] -= SPtmppt[119];
                        SPtmppt[56] -= SPtmppt[120];
                        SPtmppt[57] -= SPtmppt[121];
                        SPtmppt[58] -= SPtmppt[122];
                        SPtmppt[59] -= SPtmppt[123];
                        SPtmppt[60] -= SPtmppt[124];
                        SPtmppt[61] -= SPtmppt[125];
                        SPtmppt[62] -= SPtmppt[126];
                        SPtmppt[63] -= SPtmppt[127];

                        --SP;

                        break;
                    case   cMul:
                        SPtmp     = (SP-1)*64;
                        SPtmppt   = &StackArraytmp[SPtmp];

                        SPtmppt[0]  *= SPtmppt[64];
                        SPtmppt[1]  *= SPtmppt[65];
                        SPtmppt[2]  *= SPtmppt[66];
                        SPtmppt[3]  *= SPtmppt[67];
                        SPtmppt[4]  *= SPtmppt[68];
                        SPtmppt[5]  *= SPtmppt[69];
                        SPtmppt[6]  *= SPtmppt[70];
                        SPtmppt[7]  *= SPtmppt[71];
                        SPtmppt[8]  *= SPtmppt[72];
                        SPtmppt[9]  *= SPtmppt[73];
                        SPtmppt[10] *= SPtmppt[74];
                        SPtmppt[11] *= SPtmppt[75];
                        SPtmppt[12] *= SPtmppt[76];
                        SPtmppt[13] *= SPtmppt[77];
                        SPtmppt[14] *= SPtmppt[78];
                        SPtmppt[15] *= SPtmppt[79];
                        SPtmppt[16] *= SPtmppt[80];
                        SPtmppt[17] *= SPtmppt[81];
                        SPtmppt[18] *= SPtmppt[82];
                        SPtmppt[19] *= SPtmppt[83];
                        SPtmppt[20] *= SPtmppt[84];
                        SPtmppt[21] *= SPtmppt[85];
                        SPtmppt[22] *= SPtmppt[86];
                        SPtmppt[23] *= SPtmppt[87];
                        SPtmppt[24] *= SPtmppt[88];
                        SPtmppt[25] *= SPtmppt[89];
                        SPtmppt[26] *= SPtmppt[90];
                        SPtmppt[27] *= SPtmppt[91];
                        SPtmppt[28] *= SPtmppt[92];
                        SPtmppt[29] *= SPtmppt[93];
                        SPtmppt[30] *= SPtmppt[94];
                        SPtmppt[31] *= SPtmppt[95];
                        SPtmppt[32] *= SPtmppt[96];
                        SPtmppt[33] *= SPtmppt[97];
                        SPtmppt[34] *= SPtmppt[98];
                        SPtmppt[35] *= SPtmppt[99];
                        SPtmppt[36] *= SPtmppt[100];
                        SPtmppt[37] *= SPtmppt[101];
                        SPtmppt[38] *= SPtmppt[102];
                        SPtmppt[39] *= SPtmppt[103];
                        SPtmppt[40] *= SPtmppt[104];
                        SPtmppt[41] *= SPtmppt[105];
                        SPtmppt[42] *= SPtmppt[106];
                        SPtmppt[43] *= SPtmppt[107];
                        SPtmppt[44] *= SPtmppt[108];
                        SPtmppt[45] *= SPtmppt[109];
                        SPtmppt[46] *= SPtmppt[110];
                        SPtmppt[47] *= SPtmppt[111];
                        SPtmppt[48] *= SPtmppt[112];
                        SPtmppt[49] *= SPtmppt[113];
                        SPtmppt[50] *= SPtmppt[114];
                        SPtmppt[51] *= SPtmppt[115];
                        SPtmppt[52] *= SPtmppt[116];
                        SPtmppt[53] *= SPtmppt[117];
                        SPtmppt[54] *= SPtmppt[118];
                        SPtmppt[55] *= SPtmppt[119];
                        SPtmppt[56] *= SPtmppt[120];
                        SPtmppt[57] *= SPtmppt[121];
                        SPtmppt[58] *= SPtmppt[122];
                        SPtmppt[59] *= SPtmppt[123];
                        SPtmppt[60] *= SPtmppt[124];
                        SPtmppt[61] *= SPtmppt[125];
                        SPtmppt[62] *= SPtmppt[126];
                        SPtmppt[63] *= SPtmppt[127];
                        --SP;

                        break;

                    case   cDiv:
                        SPtmp     = (SP-1)*64;
                        SPtmppt   = &StackArraytmp[SPtmp];

                        SPtmppt[0]  /= SPtmppt[64];
                        SPtmppt[1]  /= SPtmppt[65];
                        SPtmppt[2]  /= SPtmppt[66];
                        SPtmppt[3]  /= SPtmppt[67];
                        SPtmppt[4]  /= SPtmppt[68];
                        SPtmppt[5]  /= SPtmppt[69];
                        SPtmppt[6]  /= SPtmppt[70];
                        SPtmppt[7]  /= SPtmppt[71];
                        SPtmppt[8]  /= SPtmppt[72];
                        SPtmppt[9]  /= SPtmppt[73];
                        SPtmppt[10] /= SPtmppt[74];
                        SPtmppt[11] /= SPtmppt[75];
                        SPtmppt[12] /= SPtmppt[76];
                        SPtmppt[13] /= SPtmppt[77];
                        SPtmppt[14] /= SPtmppt[78];
                        SPtmppt[15] /= SPtmppt[79];
                        SPtmppt[16] /= SPtmppt[80];
                        SPtmppt[17] /= SPtmppt[81];
                        SPtmppt[18] /= SPtmppt[82];
                        SPtmppt[19] /= SPtmppt[83];
                        SPtmppt[20] /= SPtmppt[84];
                        SPtmppt[21] /= SPtmppt[85];
                        SPtmppt[22] /= SPtmppt[86];
                        SPtmppt[23] /= SPtmppt[87];
                        SPtmppt[24] /= SPtmppt[88];
                        SPtmppt[25] /= SPtmppt[89];
                        SPtmppt[26] /= SPtmppt[90];
                        SPtmppt[27] /= SPtmppt[91];
                        SPtmppt[28] /= SPtmppt[92];
                        SPtmppt[29] /= SPtmppt[93];
                        SPtmppt[30] /= SPtmppt[94];
                        SPtmppt[31] /= SPtmppt[95];
                        SPtmppt[32] /= SPtmppt[96];
                        SPtmppt[33] /= SPtmppt[97];
                        SPtmppt[34] /= SPtmppt[98];
                        SPtmppt[35] /= SPtmppt[99];
                        SPtmppt[36] /= SPtmppt[100];
                        SPtmppt[37] /= SPtmppt[101];
                        SPtmppt[38] /= SPtmppt[102];
                        SPtmppt[39] /= SPtmppt[103];
                        SPtmppt[40] /= SPtmppt[104];
                        SPtmppt[41] /= SPtmppt[105];
                        SPtmppt[42] /= SPtmppt[106];
                        SPtmppt[43] /= SPtmppt[107];
                        SPtmppt[44] /= SPtmppt[108];
                        SPtmppt[45] /= SPtmppt[109];
                        SPtmppt[46] /= SPtmppt[110];
                        SPtmppt[47] /= SPtmppt[111];
                        SPtmppt[48] /= SPtmppt[112];
                        SPtmppt[49] /= SPtmppt[113];
                        SPtmppt[50] /= SPtmppt[114];
                        SPtmppt[51] /= SPtmppt[115];
                        SPtmppt[52] /= SPtmppt[116];
                        SPtmppt[53] /= SPtmppt[117];
                        SPtmppt[54] /= SPtmppt[118];
                        SPtmppt[55] /= SPtmppt[119];
                        SPtmppt[56] /= SPtmppt[120];
                        SPtmppt[57] /= SPtmppt[121];
                        SPtmppt[58] /= SPtmppt[122];
                        SPtmppt[59] /= SPtmppt[123];
                        SPtmppt[60] /= SPtmppt[124];
                        SPtmppt[61] /= SPtmppt[125];
                        SPtmppt[62] /= SPtmppt[126];
                        SPtmppt[63] /= SPtmppt[127];

                        --SP;

                        break;

                    case   cSin:

                        SPtmp      = SP*64;
                        SPtmppt    = &StackArraytmp[SPtmp];

                        SPtmppt[0]  = sin(SPtmppt[0]);
                        SPtmppt[1]  = sin(SPtmppt[1]);
                        SPtmppt[2]  = sin(SPtmppt[2]);
                        SPtmppt[3]  = sin(SPtmppt[3]);
                        SPtmppt[4]  = sin(SPtmppt[4]);
                        SPtmppt[5]  = sin(SPtmppt[5]);
                        SPtmppt[6]  = sin(SPtmppt[6]);
                        SPtmppt[7]  = sin(SPtmppt[7]);
                        SPtmppt[8]  = sin(SPtmppt[8]);
                        SPtmppt[9]  = sin(SPtmppt[9]);
                        SPtmppt[10] = sin(SPtmppt[10]);
                        SPtmppt[11] = sin(SPtmppt[11]);
                        SPtmppt[12] = sin(SPtmppt[12]);
                        SPtmppt[13] = sin(SPtmppt[13]);
                        SPtmppt[14] = sin(SPtmppt[14]);
                        SPtmppt[15] = sin(SPtmppt[15]);
                        SPtmppt[16] = sin(SPtmppt[16]);
                        SPtmppt[17] = sin(SPtmppt[17]);
                        SPtmppt[18] = sin(SPtmppt[18]);
                        SPtmppt[19] = sin(SPtmppt[19]);
                        SPtmppt[20] = sin(SPtmppt[20]);
                        SPtmppt[21] = sin(SPtmppt[21]);
                        SPtmppt[22] = sin(SPtmppt[22]);
                        SPtmppt[23] = sin(SPtmppt[23]);
                        SPtmppt[24] = sin(SPtmppt[24]);
                        SPtmppt[25] = sin(SPtmppt[25]);
                        SPtmppt[26] = sin(SPtmppt[26]);
                        SPtmppt[27] = sin(SPtmppt[27]);
                        SPtmppt[28] = sin(SPtmppt[28]);
                        SPtmppt[29] = sin(SPtmppt[29]);
                        SPtmppt[30] = sin(SPtmppt[30]);
                        SPtmppt[31] = sin(SPtmppt[31]);
                        SPtmppt[32] = sin(SPtmppt[32]);
                        SPtmppt[33] = sin(SPtmppt[33]);
                        SPtmppt[34] = sin(SPtmppt[34]);
                        SPtmppt[35] = sin(SPtmppt[35]);
                        SPtmppt[36] = sin(SPtmppt[36]);
                        SPtmppt[37] = sin(SPtmppt[37]);
                        SPtmppt[38] = sin(SPtmppt[38]);
                        SPtmppt[39] = sin(SPtmppt[39]);
                        SPtmppt[40] = sin(SPtmppt[40]);
                        SPtmppt[41] = sin(SPtmppt[41]);
                        SPtmppt[42] = sin(SPtmppt[42]);
                        SPtmppt[43] = sin(SPtmppt[43]);
                        SPtmppt[44] = sin(SPtmppt[44]);
                        SPtmppt[45] = sin(SPtmppt[45]);
                        SPtmppt[46] = sin(SPtmppt[46]);
                        SPtmppt[47] = sin(SPtmppt[47]);
                        SPtmppt[48] = sin(SPtmppt[48]);
                        SPtmppt[49] = sin(SPtmppt[49]);
                        SPtmppt[50] = sin(SPtmppt[50]);
                        SPtmppt[51] = sin(SPtmppt[51]);
                        SPtmppt[52] = sin(SPtmppt[52]);
                        SPtmppt[53] = sin(SPtmppt[53]);
                        SPtmppt[54] = sin(SPtmppt[54]);
                        SPtmppt[55] = sin(SPtmppt[55]);
                        SPtmppt[56] = sin(SPtmppt[56]);
                        SPtmppt[57] = sin(SPtmppt[57]);
                        SPtmppt[58] = sin(SPtmppt[58]);
                        SPtmppt[59] = sin(SPtmppt[59]);
                        SPtmppt[60] = sin(SPtmppt[60]);
                        SPtmppt[61] = sin(SPtmppt[61]);
                        SPtmppt[62] = sin(SPtmppt[62]);
                        SPtmppt[63] = sin(SPtmppt[63]);

                        break;

                    case   cCos:
                        SPtmp      = SP*64;
                        SPtmppt    = &StackArraytmp[SPtmp];

                        SPtmppt[0]  = cos(SPtmppt[0]);
                        SPtmppt[1]  = cos(SPtmppt[1]);
                        SPtmppt[2]  = cos(SPtmppt[2]);
                        SPtmppt[3]  = cos(SPtmppt[3]);
                        SPtmppt[4]  = cos(SPtmppt[4]);
                        SPtmppt[5]  = cos(SPtmppt[5]);
                        SPtmppt[6]  = cos(SPtmppt[6]);
                        SPtmppt[7]  = cos(SPtmppt[7]);
                        SPtmppt[8]  = cos(SPtmppt[8]);
                        SPtmppt[9]  = cos(SPtmppt[9]);
                        SPtmppt[10] = cos(SPtmppt[10]);
                        SPtmppt[11] = cos(SPtmppt[11]);
                        SPtmppt[12] = cos(SPtmppt[12]);
                        SPtmppt[13] = cos(SPtmppt[13]);
                        SPtmppt[14] = cos(SPtmppt[14]);
                        SPtmppt[15] = cos(SPtmppt[15]);
                        SPtmppt[16] = cos(SPtmppt[16]);
                        SPtmppt[17] = cos(SPtmppt[17]);
                        SPtmppt[18] = cos(SPtmppt[18]);
                        SPtmppt[19] = cos(SPtmppt[19]);
                        SPtmppt[20] = cos(SPtmppt[20]);
                        SPtmppt[21] = cos(SPtmppt[21]);
                        SPtmppt[22] = cos(SPtmppt[22]);
                        SPtmppt[23] = cos(SPtmppt[23]);
                        SPtmppt[24] = cos(SPtmppt[24]);
                        SPtmppt[25] = cos(SPtmppt[25]);
                        SPtmppt[26] = cos(SPtmppt[26]);
                        SPtmppt[27] = cos(SPtmppt[27]);
                        SPtmppt[28] = cos(SPtmppt[28]);
                        SPtmppt[29] = cos(SPtmppt[29]);
                        SPtmppt[30] = cos(SPtmppt[30]);
                        SPtmppt[31] = cos(SPtmppt[31]);
                        SPtmppt[32] = cos(SPtmppt[32]);
                        SPtmppt[33] = cos(SPtmppt[33]);
                        SPtmppt[34] = cos(SPtmppt[34]);
                        SPtmppt[35] = cos(SPtmppt[35]);
                        SPtmppt[36] = cos(SPtmppt[36]);
                        SPtmppt[37] = cos(SPtmppt[37]);
                        SPtmppt[38] = cos(SPtmppt[38]);
                        SPtmppt[39] = cos(SPtmppt[39]);
                        SPtmppt[40] = cos(SPtmppt[40]);
                        SPtmppt[41] = cos(SPtmppt[41]);
                        SPtmppt[42] = cos(SPtmppt[42]);
                        SPtmppt[43] = cos(SPtmppt[43]);
                        SPtmppt[44] = cos(SPtmppt[44]);
                        SPtmppt[45] = cos(SPtmppt[45]);
                        SPtmppt[46] = cos(SPtmppt[46]);
                        SPtmppt[47] = cos(SPtmppt[47]);
                        SPtmppt[48] = cos(SPtmppt[48]);
                        SPtmppt[49] = cos(SPtmppt[49]);
                        SPtmppt[50] = cos(SPtmppt[50]);
                        SPtmppt[51] = cos(SPtmppt[51]);
                        SPtmppt[52] = cos(SPtmppt[52]);
                        SPtmppt[53] = cos(SPtmppt[53]);
                        SPtmppt[54] = cos(SPtmppt[54]);
                        SPtmppt[55] = cos(SPtmppt[55]);
                        SPtmppt[56] = cos(SPtmppt[56]);
                        SPtmppt[57] = cos(SPtmppt[57]);
                        SPtmppt[58] = cos(SPtmppt[58]);
                        SPtmppt[59] = cos(SPtmppt[59]);
                        SPtmppt[60] = cos(SPtmppt[60]);
                        SPtmppt[61] = cos(SPtmppt[61]);
                        SPtmppt[62] = cos(SPtmppt[62]);
                        SPtmppt[63] = cos(SPtmppt[63]);

                        break;
                    case   cPow: //Stack[SP-1] = pow(Stack[SP-1], Stack[SP]);
                        SPtmp     = (SP-1)*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        savepowvalue    = SPtmppt[64];
                        abssavepowvalue = abs(savepowvalue);
                        if(SPtmppt[64] < 11 )
                        {
                            if(abssavepowvalue==2)
                                for(i=0; i<64; i++) SPtmppt[i] *= SPtmppt[i];
                            else if(abssavepowvalue==3)
                                for(i=0; i<64; i++) SPtmppt[i] *= (SPtmppt[i]*SPtmppt[i]);
                            else if(abssavepowvalue==4)
                                for(i=0; i<64; i++)
                                {
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                }
                            else if(abssavepowvalue==5)
                                for(i=0; i<64; i++)
                                {
                                    powval = SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= powval;
                                }
                            else if(abssavepowvalue==6)
                                for(i=0; i<64; i++)
                                {
                                    SPtmppt[i] *= SPtmppt[i]*SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                }
                            else if(abssavepowvalue==7)
                                for(i=0; i<64; i++)
                                {
                                    powval = SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i]*SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= powval;
                                }
                            else if(abssavepowvalue==8)
                                for(i=0; i<64; i++)
                                {
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                }
                            else if(abssavepowvalue==9)
                                for(i=0; i<64; i++)
                                {
                                    powval = SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= powval;
                                }
                            else if(abssavepowvalue==10)
                                for(i=0; i<64; i++)
                                {
                                    powval = SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= powval;
                                    SPtmppt[i] *= SPtmppt[i];
                                }

/// Inverse values in case the coefficient is negatif
                            if(savepowvalue < 0)
                            {
                                productval = 1.0;
                                for(i=0; i<64; i++) productval *= SPtmppt[i];
                                if (productval !=0)
                                    for(i=0; i<64; i++) SPtmppt[i] = 1.0/SPtmppt[i];
//else { evalErrorType=1; /*return 0; */}
                            }
                        }
                        else for(i=0; i<64; i++) SPtmppt[i] = pow(SPtmppt[i], SPtmppt[64]);
                        --SP;

                        break;

                    case   cPOw: //Stack[SP-1] = pow(Stack[SP-1], Stack[SP]);
                        SPtmp     = (SP-1)*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        savepowvalue    = SPtmppt[64];
                        abssavepowvalue = abs(savepowvalue);
                        if(SPtmppt[64] < 11 )
                        {
                            if(abssavepowvalue==2)
                                for(i=0; i<64; i++) SPtmppt[i] *= SPtmppt[i];
                            else if(abssavepowvalue==3)
                                for(i=0; i<64; i++) SPtmppt[i] *= (SPtmppt[i]*SPtmppt[i]);
                            else if(abssavepowvalue==4)
                                for(i=0; i<64; i++)
                                {
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                }
                            else if(abssavepowvalue==5)
                                for(i=0; i<64; i++)
                                {
                                    powval = SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= powval;
                                }
                            else if(abssavepowvalue==6)
                                for(i=0; i<64; i++)
                                {
                                    SPtmppt[i] *= SPtmppt[i]*SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                }
                            else if(abssavepowvalue==7)
                                for(i=0; i<64; i++)
                                {
                                    powval = SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i]*SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= powval;
                                }
                            else if(abssavepowvalue==8)
                                for(i=0; i<64; i++)
                                {
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                }
                            else if(abssavepowvalue==9)
                                for(i=0; i<64; i++)
                                {
                                    powval = SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= powval;
                                }
                            else if(abssavepowvalue==10)
                                for(i=0; i<64; i++)
                                {
                                    powval = SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= SPtmppt[i];
                                    SPtmppt[i] *= powval;
                                    SPtmppt[i] *= SPtmppt[i];
                                }

/// Inverse values in case the coefficient is negatif
                            if(savepowvalue < 0)
                            {
                                productval = 1.0;
                                for(i=0; i<64; i++) productval *= SPtmppt[i];
                                if (productval !=0)
                                    for(i=0; i<64; i++) SPtmppt[i] = 1.0/SPtmppt[i];
//else { evalErrorType=1; /*return 0; */}
                            }
                        }
                        else for(i=0; i<64; i++) SPtmppt[i] = pow(SPtmppt[i], SPtmppt[64]);
                        --SP;

                        break;


                    case   cExp: //Stack[SP] = exp(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = exp(SPtmppt[i]);

                        break;

                    case   cNeg: //Stack[SP] = -Stack[SP];
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = -SPtmppt[i];

                        break;

                    case cFloor: //Stack[SP] = floor(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = floor(SPtmppt[i]);

                        break;

                    case   cAbs: ///Stack[SP] = fabs(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = fabs(SPtmppt[i]);

                        break;

// Misc:
                    case cImmed: //Stack[++SP] = Immed[DP++];
                        ++SP;
                        SPtmp   = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = Immed[DP];
                        DP++;

                        break;

                    case  cJump:
                        DP = ByteCode[IP+2];
                        IP = ByteCode[IP+1];

                        break;

                    case  cAcos: //if(Stack[SP] < -1 || Stack[SP] > 1)
                        //{ evalErrorType=4;/* return 0; */}
                        //Stack[SP] = acos(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = acos(SPtmppt[i]);

                        break;

#ifndef NO_ASINH
                    case cAcosh: //Stack[SP] = acosh(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = acosh(SPtmppt[i]);

                        break;

#endif
                    case  cAsin: //if(Stack[SP] < -1 || Stack[SP] > 1)
                        //{ evalErrorType=4; /*return 0;*/ }
                        //Stack[SP] = asin(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = asin(SPtmppt[i]);

                        break;

#ifndef NO_ASINH
                    case cAsinh: //Stack[SP] = asinh(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = asinh(SPtmppt[i]);

                        break;
#endif
                    case  cAtan: //Stack[SP] = atan(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = atan(SPtmppt[i]);

                        break;

                    case cAtan2: //Stack[SP-1] = atan2(Stack[SP-1], Stack[SP]);
                        SPtmp      = (SP-1)*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = atan2(SPtmppt[i], SPtmppt[i+64]);
                        --SP;

                        break;

#ifndef NO_ASINH
                    case cAtanh: //Stack[SP] = atanh(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = atanh(SPtmppt[i]);

                        break;

#endif
                    case  cCeil: //Stack[SP] = ceil(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = ceil(SPtmppt[i]);

                        break;

                    case  cCosh: //Stack[SP] = cosh(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = cosh(SPtmppt[i]);

                        break;

                    case   cCot:
                    {
                        double t = tan(Stack[SP]);
                        if(t == 0)
                        {
                            evalErrorType=1; /*return 0;*/
                        }
                        Stack[SP] = 1/t;

                        break;
                    }
                    case   cCsc:
                    {
                        double s = sin(Stack[SP]);
                        if(s == 0)
                        {
                            evalErrorType=1; /*return 0; */
                        }
                        Stack[SP] = 1/s;

                        break;
                    }

#ifndef DISABLE_EVAL
                    case  cEval:
                    {
                        data->Stack = new double[data->StackSize];
                        double retVal = Eval(&Stack[SP-data->varAmount+1]);
                        delete[] data->Stack;
                        data->Stack = Stack;
                        SP -= data->varAmount-1;
                        Stack[SP] = retVal;

                        break;
                    }
#endif

                    case    cIf:
                    {
                        unsigned jumpAddr  = ByteCode[++IP];
                        unsigned immedAddr = ByteCode[++IP];
                        SPtmp      = SP*64;
                        SPtmppt    = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++)
                            if(doubleToInt(SPtmppt[i]) == 0)
                            {
                                IP = jumpAddr;
                                DP = immedAddr;
                            }
                        --SP;
                        break;
                    }

                    case   cInt: //Stack[SP] = floor(Stack[SP]+.5);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = floor(SPtmppt[i]+.5);

                        break;

                    case   cLog: //if(Stack[SP] <= 0) { evalErrorType=3; /*return 0; */}
                        //Stack[SP] = log(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = log(SPtmppt[i]);

                        break;

                    case cLog10: //if(Stack[SP] <= 0) { evalErrorType=3; /*return 0;*/ }
                        //Stack[SP] = log10(Stack[SP]);
                        SPtmp      = (SP-1)*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = log10(SPtmppt[i]);

                        break;

                    case   cMax: //Stack[SP-1] = Max(Stack[SP-1], Stack[SP]);
                        SPtmp      = (SP-1)*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = Max(SPtmppt[i], SPtmppt[i+64]);
                        --SP;

                        break;

                    case   cMin: //Stack[SP-1] = Min(Stack[SP-1], Stack[SP]);
                        SPtmp      = (SP-1)*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = Min(SPtmppt[i], SPtmppt[i+64]);
                        --SP;

                        break;

                    case   cSec:
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = 1/cos(SPtmppt[SP]);

                        break;

                    case  cSinh: //Stack[SP] = sinh(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = sinh(SPtmppt[i]);

                        break;

                    case  cSqrt: //if(Stack[SP] < 0) { evalErrorType=2; /*return 0;*/}
                        //Stack[SP] = sqrt(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = sqrt(SPtmppt[i]);

                        break;

                    case   cTan: //Stack[SP] = tan(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = tan(SPtmppt[i]);

                        break;

                    case  cTanh: //Stack[SP] = tanh(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = tanh(SPtmppt[i]);

                        break;

// Operators:
                    case   cMod: //if(Stack[SP] == 0) { evalErrorType=1; /*return 0;*/ }
                        //Stack[SP-1] = fmod(Stack[SP-1], Stack[SP]);
                        SPtmp      = (SP-1)*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = fmod(SPtmppt[i], SPtmppt[i+64]);
                        --SP;

                        break;

                    case cEqual: //Stack[SP-1] = (Stack[SP-1] == Stack[SP]);
                        SPtmp      = (SP-1)*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = (SPtmppt[i] == SPtmppt[i+64]);
                        --SP;

                        break;

                    case  cLess: //Stack[SP-1] = (Stack[SP-1] < Stack[SP]);
                        SPtmp      = (SP-1)*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = (SPtmppt[i] < SPtmppt[i+64]);
                        --SP;

                        break;

                    case cGreater: //Stack[SP-1] = (Stack[SP-1] > Stack[SP]);
                        SPtmp      = (SP-1)*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = (SPtmppt[i] > SPtmppt[i+64]);
                        --SP;

                        break;

                    case   cAnd: //Stack[SP-1] =
                        //(doubleToInt(Stack[SP-1]) &&
                        //doubleToInt(Stack[SP]));
                        SPtmp      = (SP-1)*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = (doubleToInt(SPtmppt[i]) &&
                                                              doubleToInt(SPtmppt[i+64]));
                        --SP;

                        break;

                    case    cOr: //Stack[SP-1] =
                        //(doubleToInt(Stack[SP-1]) ||
                        //doubleToInt(Stack[SP]));
                        SPtmp      = (SP-1)*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = (doubleToInt(SPtmppt[i]) ||
                                                              doubleToInt(SPtmppt[i+64]));
                        --SP;

                        break;

// Degrees-radians conversion:
                    case   cDeg: //Stack[SP] = RadiansToDegrees(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = RadiansToDegrees(SPtmppt[i]);

                        break;

                    case   cRad:
                        Stack[SP] = DegreesToRadians(Stack[SP]);
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++) SPtmppt[i] = DegreesToRadians(SPtmppt[i]);

                        break;

// User-defined function calls:
                    case cFCall:
                        index = ByteCode[++IP];
                        params = data->FuncPtrs[index].params;
                        SP -= params-1;
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++)
                            SPtmppt[i] = data->FuncPtrs[index].ptr(&SPtmppt[i]);

                        break;

                    case cPCall:
                        index = ByteCode[++IP];
                        params = data->FuncParsers[index]->data->varAmount;
                        SP -= params-1;
                        SPtmp      = SP*64;
                        SPtmppt = &StackArraytmp[SPtmp];
                        for(i=0; i<64; i++)
                            SPtmppt[i] = data->FuncParsers[index]->Eval(&SPtmppt[i]);

                        break;
#ifdef SUPPORT_OPTIMIZER
                    case   cVar:
                        break;
                    case   cDup:
                        Stack[SP+1] = Stack[SP];
                        ++SP;
                        break;
                    case   cInv:
                        if(Stack[SP] == 0.0)
                        {
                            evalErrorType=1;
                        }
                        Stack[SP] = 1.0/Stack[SP];

                        break;
#endif

// Variables:
                    default:
                        ++SP;
                        SPtmppt = &StackArraytmp[SP*64];

                        if((ByteCode[IP]-VarBegin) == 0)
                        {
//memcpy(&StackArraytmp[SP*64], Vars, marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 1)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[ 64], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[i+64];

                        }
                        else if((ByteCode[IP]-VarBegin) == 2)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[128], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[128+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 3)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = t_parameter;//Vars[192+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 4)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[256+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 5)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[320+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 6)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[384+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 7)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[448+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 8)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[512+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 9)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[576+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 10)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[640+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 11)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[704+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 12)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[768+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 13)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[832+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 14)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[896+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 15)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[960+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 16)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1024+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 17)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1088+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 18)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1152+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 19)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1216+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 20)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1280+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 21)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1344+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 22)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1408+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 23)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1472+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 24)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1536+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 25)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1600+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 26)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1664+i];

                        }
                        else if((ByteCode[IP]-VarBegin) == 27)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1728+i];
                        }
                        else if((ByteCode[IP]-VarBegin) == 28)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1792+i];
                        }
                        else if((ByteCode[IP]-VarBegin) == 29)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1856+i];
                        }
                        else if((ByteCode[IP]-VarBegin) == 30)
                        {
//memcpy(&StackArraytmp[SP*64], &Vars[192], marchsize);
                            for(i=0; i<64; i++)SPtmppt[i] = Vars[1920+i];
                        }
                    }
                }
/// Now we save those results :
                SPtmp = SP*64;
                l = 0;
                for(i=0; i<4; i++)
                {
                    I   = (i+StartI)*maxxmax;
                    for(j=0; j<4; j++)
                    {
                        J   = I + (j+StartJ)*max;
                        for(k=0; k<4; k++)
                        {
                            IJK = J + (k+StartK);
                            results[IJK] = StackArraytmp[SPtmp+l];
                            l++;
                        }
                    }
                }
            }
        }
    }
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
double FunctionParser::Eval(const double* Vars)
{
    const unsigned* const ByteCode = data->ByteCode;
    const double* const Immed = data->Immed;
    double* const Stack = data->Stack;
    const unsigned ByteCodeSize = data->ByteCodeSize;
    unsigned IP, DP=0;
    int SP=-1;

    for(IP=0; IP<ByteCodeSize; ++IP)
    {
        switch(ByteCode[IP])
        {
// Misc:
        case cImmed:
            Stack[++SP] = Immed[DP++];
            break;
        case  cJump:
            DP = ByteCode[IP+2];
            IP = ByteCode[IP+1];
            break;
// Functions:
        case   cAdd:
            Stack[SP-1] += Stack[SP];
            --SP;
            break;
        case   cSub:
            Stack[SP-1] -= Stack[SP];
            --SP;
            break;
        case   cMul:
            Stack[SP-1] *= Stack[SP];
            --SP;
            break;
        case   cDiv:
            if(Stack[SP] == 0)
            {
                evalErrorType=1;
                return 0;
            }
            Stack[SP-1] /= Stack[SP];
            --SP;
            break;
        case   cCos:
            Stack[SP] = cos(Stack[SP]);
            break;
        case   cSin:
            Stack[SP] = sin(Stack[SP]);
            break;
        case   cPow:
            Stack[SP-1] = pow(Stack[SP-1], Stack[SP]);
            --SP;
            break;
        case   cPOw:
            Stack[SP-1] = pow(Stack[SP-1], Stack[SP]);
            --SP;
            break;
        case   cNeg:
            Stack[SP] = -Stack[SP];
            break;
        case   cExp:
            Stack[SP] = exp(Stack[SP]);
            break;
        case cFloor:
            Stack[SP] = floor(Stack[SP]);
            break;

        case   cAbs:
            Stack[SP] = fabs(Stack[SP]);
            break;
        case  cAcos:
            if(Stack[SP] < -1 || Stack[SP] > 1)
            {
                evalErrorType=4;
                return 0;
            }
            Stack[SP] = acos(Stack[SP]);
            break;
#ifndef NO_ASINH
        case cAcosh:
            Stack[SP] = acosh(Stack[SP]);
            break;
#endif
        case  cAsin:
            if(Stack[SP] < -1 || Stack[SP] > 1)
            {
                evalErrorType=4;
                return 0;
            }
            Stack[SP] = asin(Stack[SP]);
            break;
#ifndef NO_ASINH
        case cAsinh:
            Stack[SP] = asinh(Stack[SP]);
            break;
#endif
        case  cAtan:
            Stack[SP] = atan(Stack[SP]);
            break;
        case cAtan2:
            Stack[SP-1] = atan2(Stack[SP-1], Stack[SP]);
            --SP;
            break;
#ifndef NO_ASINH
        case cAtanh:
            Stack[SP] = atanh(Stack[SP]);
            break;
#endif
        case  cCeil:
            Stack[SP] = ceil(Stack[SP]);
            break;
        case  cCosh:
            Stack[SP] = cosh(Stack[SP]);
            break;

        case   cCot:
        {
            double t = tan(Stack[SP]);
            if(t == 0)
            {
                evalErrorType=1;
                return 0;
            }
            Stack[SP] = 1/t;
            break;
        }
        case   cCsc:
        {
            double s = sin(Stack[SP]);
            if(s == 0)
            {
                evalErrorType=1;
                return 0;
            }
            Stack[SP] = 1/s;
            break;
        }


#ifndef DISABLE_EVAL
        case  cEval:
        {
            data->Stack = new double[data->StackSize];
            double retVal = Eval(&Stack[SP-data->varAmount+1]);
            delete[] data->Stack;
            data->Stack = Stack;
            SP -= data->varAmount-1;
            Stack[SP] = retVal;
            break;
        }
#endif
        case    cIf:
        {
            unsigned jumpAddr  = ByteCode[++IP];
            unsigned immedAddr = ByteCode[++IP];
            if(doubleToInt(Stack[SP]) == 0)
            {
                IP = jumpAddr;
                DP = immedAddr;
            }
            --SP;
            break;
        }

        case   cInt:
            Stack[SP] = floor(Stack[SP]+.5);
            break;
        case   cLog:
            if(Stack[SP] <= 0)
            {
                evalErrorType=3;
                return 0;
            }
            Stack[SP] = log(Stack[SP]);
            break;
        case cLog10:
            if(Stack[SP] <= 0)
            {
                evalErrorType=3;
                return 0;
            }
            Stack[SP] = log10(Stack[SP]);
            break;
        case   cMax:
            Stack[SP-1] = Max(Stack[SP-1], Stack[SP]);
            --SP;
            break;
        case   cMin:
            Stack[SP-1] = Min(Stack[SP-1], Stack[SP]);
            --SP;
            break;
        case   cSec:
        {
            double c = cos(Stack[SP]);
            if(c == 0)
            {
                evalErrorType=1;
                return 0;
            }
            Stack[SP] = 1/c;
            break;
        }
        case  cSinh:
            Stack[SP] = sinh(Stack[SP]);
            break;
        case  cSqrt:
            if(Stack[SP] < 0)
            {
                evalErrorType=2;
                return 0;
            }
            Stack[SP] = sqrt(Stack[SP]);
            break;
        case   cTan:
            Stack[SP] = tan(Stack[SP]);
            break;
        case  cTanh:
            Stack[SP] = tanh(Stack[SP]);
            break;

// Operators:
        case   cMod:
            if(Stack[SP] == 0)
            {
                evalErrorType=1;
                return 0;
            }
            Stack[SP-1] = fmod(Stack[SP-1], Stack[SP]);
            --SP;
            break;
        case cEqual:
            Stack[SP-1] = (Stack[SP-1] == Stack[SP]);
            --SP;
            break;
        case  cLess:
            Stack[SP-1] = (Stack[SP-1] < Stack[SP]);
            --SP;
            break;
        case cGreater:
            Stack[SP-1] = (Stack[SP-1] > Stack[SP]);
            --SP;
            break;
        case   cAnd:
            Stack[SP-1] =
                (doubleToInt(Stack[SP-1]) &&
                 doubleToInt(Stack[SP]));
            --SP;
            break;
        case    cOr:
            Stack[SP-1] =
                (doubleToInt(Stack[SP-1]) ||
                 doubleToInt(Stack[SP]));
            --SP;
            break;

// Degrees-radians conversion:
        case   cDeg:
            Stack[SP] = RadiansToDegrees(Stack[SP]);
            break;
        case   cRad:
            Stack[SP] = DegreesToRadians(Stack[SP]);
            break;

// User-defined function calls:
        case cFCall:
        {
            unsigned index = ByteCode[++IP];
            unsigned params = data->FuncPtrs[index].params;
            double retVal =
                data->FuncPtrs[index].ptr(&Stack[SP-params+1]);
            SP -= params-1;
            Stack[SP] = retVal;
            break;
        }

        case cPCall:
        {
            unsigned index = ByteCode[++IP];
            unsigned params = data->FuncParsers[index]->data->varAmount;
            double retVal =
                data->FuncParsers[index]->Eval(&Stack[SP-params+1]);
            SP -= params-1;
            Stack[SP] = retVal;
            break;
        }

#ifdef SUPPORT_OPTIMIZER
        case   cVar:
            break; // Paranoia. These should never exist
        case   cDup:
            Stack[SP+1] = Stack[SP];
            ++SP;
            break;
        case   cInv:
            if(Stack[SP] == 0.0)
            {
                evalErrorType=1;
                return 0;
            }
            Stack[SP] = 1.0/Stack[SP];
            break;
#endif

// Variables:
        default:
            Stack[++SP] = Vars[ByteCode[IP]-VarBegin];
        }
    }

    evalErrorType=0;
    return Stack[SP];
}

#ifdef FUNCTIONPARSER_SUPPORT_DEBUG_OUTPUT
namespace
{
inline void printHex(std::ostream& dest, unsigned n)
{
    dest.width(8);
    dest.fill('0');
    hex(dest); //uppercase(dest);
    dest << n;
}
}

void FunctionParser::PrintByteCode(std::ostream& dest) const
{
    const unsigned* const ByteCode = data->ByteCode;
    const double* const Immed = data->Immed;

    for(unsigned IP=0, DP=0; IP<data->ByteCodeSize; ++IP)
    {
        printHex(dest, IP);
        dest << ": ";

        unsigned opcode = ByteCode[IP];

        switch(opcode)
        {
        case cIf:
            dest << "jz\t";
            printHex(dest, ByteCode[IP+1]+1);
            dest << endl;
            IP += 2;
            break;

        case cJump:
            dest << "jump\t";
            printHex(dest, ByteCode[IP+1]+1);
            dest << endl;
            IP += 2;
            break;
        case cImmed:
            dest.precision(10);
            dest << "push\t" << Immed[DP++] << endl;
            break;

        case cFCall:
        {
            unsigned index = ByteCode[++IP];
            Data::VarMap_t::const_iterator iter =
                data->FuncPtrNames.begin();
            while(iter->second != index) ++iter;
            dest << "call\t" << iter->first << endl;
            break;
        }

        case cPCall:
        {
            unsigned index = ByteCode[++IP];
            Data::VarMap_t::const_iterator iter =
                data->FuncParserNames.begin();
            while(iter->second != index) ++iter;
            dest << "call\t" << iter->first << endl;
            break;
        }

        default:
            if(opcode < VarBegin)
            {
                string n;
                switch(opcode)
                {
                case cNeg:
                    n = "neg";
                    break;
                case cAdd:
                    n = "add";
                    break;
                case cSub:
                    n = "sub";
                    break;
                case cMul:
                    n = "mul";
                    break;
                case cDiv:
                    n = "div";
                    break;
                case cMod:
                    n = "mod";
                    break;
                case cPow:
                    n = "pow";
                    break;
                case cEqual:
                    n = "eq";
                    break;
                case cLess:
                    n = "lt";
                    break;
                case cGreater:
                    n = "gt";
                    break;
                case cAnd:
                    n = "and";
                    break;
                case cOr:
                    n = "or";
                    break;
                case cDeg:
                    n = "deg";
                    break;
                case cRad:
                    n = "rad";
                    break;

#ifndef DISABLE_EVAL
                case cEval:
                    n = "call\t0";
                    break;
#endif

#ifdef SUPPORT_OPTIMIZER
                case cVar:
                    n = "(var)";
                    break;
                case cDup:
                    n = "dup";
                    break;
                case cInv:
                    n = "inv";
                    break;
#endif

                default:
                    n = Functions[opcode-cAbs].name;
                }
                dest << n << endl;
            }
            else
            {
                dest << "push\tVar" << opcode-VarBegin << endl;
            }
        }
    }
}
#endif

