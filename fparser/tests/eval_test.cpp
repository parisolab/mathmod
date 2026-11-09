// Value verification of the eval() built-in added to this fparser fork,
// and of the csd -> get rename of the psh/get slot accessor
// (opcode cGet / cEval in extrasrc/fptypes.hh, name registrations in
// extrasrc/fp_identifier_parser.inc, eval cases in the three
// evaluation loops of fparser.cc, arity rule in CompileFunction()).
//
// Everything goes through the real engine (Parse + Eval / EvalC / Eval2):
//   1. Name probe:
//        get(x)   parses as a built-in (renamed from csd)
//        csd(x)   is no longer a built-in (must be unknown)
//        eval(...) parses only with an argument count equal to the
//                  number of variables of the function being parsed
//        evl(x) / eval2(x) stay unknown
//   2. psh/get slot semantics (scalar):
//        get(N) returns what psh(N, v) stored; out-of-range slot index
//        -> EvalError() == 7 (VAR_OVERFLOW)
//   3. eval() semantics (real): recursive re-evaluation of the function
//        being evaluated with the given arguments (factorial, sum,
//        stack-state restoration after the recursive call, values
//        computed on the stack as arguments, psh/get inside recursion)
//   4. eval() semantics (complex) through FunctionParser_cd
//   5. Batch Eval2 (tiled) results bit-identical to scalar Eval for a
//        4-variable function using eval(); a non-uniform if guarding
//        eval() makes the batch abort with code 5 (IF_FUNCT_ERROR),
//        which is what the application uses to fall back to scalar eval.
//
// Build (from fparser/tests/):
//   c++ -O2 -std=c++17 -ffp-contract=off eval_test.cpp -I.. ../fparser.cc -o eval_test
//   ./eval_test        # exit 0 = pass

#include "fparser.hh"
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <vector>

static int gFail = 0, gPass = 0;

static void checkBits(const char* what, double a, double b)
{
    unsigned long long ba, bb;
    std::memcpy(&ba, &a, 8);
    std::memcpy(&bb, &b, 8);
    const bool ok = (ba == bb) || ((a == 0) && (b == 0)); // +0 / -0
    if(ok) { ++gPass; }
    else
    {
        ++gFail;
        std::printf("FAIL(bits) %s: got %.17g (0x%016llx), want %.17g (0x%016llx)\n",
                    what, a, ba, b, bb);
    }
}

static void checkEq(const char* what, double a, double b)
{
    if(a == b) { ++gPass; }
    else { ++gFail; std::printf("FAIL(eq) %s: got %g, want %g\n", what, a, b); }
}

static void checkTrue(const char* what, bool cond)
{
    if(cond) { ++gPass; }
    else { ++gFail; std::printf("FAIL %s\n", what); }
}

// ------------------------------------------------------------------
// 1. Name probe
// ------------------------------------------------------------------
static void nameProbe()
{
    std::printf("== name probe ==\n");
    // This fork's Parse() returns -1 on success, >= 0 on failure.
    {
        FunctionParser p;
        checkEq("get is a builtin",  p.Parse("get(x)", "x,y,z"), -1);
    }
    {
        FunctionParser p; // csd must be gone (treated as unknown variable,
                          // calling a variable is a parse error)
        checkTrue("csd is unknown",  p.Parse("csd(x)", "x,y,z") >= 0);
    }
    {
        FunctionParser p;
        checkEq("eval arity ok (1 var)", p.Parse("eval(x)", "x"), -1);
    }
    {
        FunctionParser p;
        checkEq("eval arity ok (4 vars)",
                p.Parse("eval(x-1, y, z, t)", "x,y,z,t"), -1);
    }
    {
        FunctionParser p; // too many arguments for 1 variable
        checkTrue("eval arity 2/1 fails", p.Parse("eval(x,y)", "x") >= 0);
    }
    {
        FunctionParser p; // too few arguments for 2 variables
        checkTrue("eval arity 1/2 fails", p.Parse("eval(x)", "x,y") >= 0);
    }
    {
        FunctionParser p;
        checkTrue("evl is unknown",  p.Parse("evl(x)", "x") >= 0);
    }
    {
        FunctionParser p;
        checkTrue("eval2 is unknown", p.Parse("eval2(x)", "x") >= 0);
    }
}

// ------------------------------------------------------------------
// 2. psh/get slot semantics (scalar)
// ------------------------------------------------------------------
static void getProbe()
{
    std::printf("== psh/get probe ==\n");
    {
        FunctionParser p;
        p.AllocateStackMemory(16, 4); // 16 slots x 4 vars
        checkEq("psh parses", p.Parse("psh(0, x*2) + get(0)", "x"), -1);
        double v = 3.5;
        // psh(N, val) returns 1 (it stores val in slot N)
        checkBits("psh/get round trip", p.Eval(&v), 1.0 + 3.5*2);
        checkEq("psh/get no error", p.EvalError(), 0);
    }
    {
        FunctionParser p;
        p.AllocateStackMemory(16, 4);
        checkEq("get parses", p.Parse("get(2)", "x"), -1);
        double v = 1;
        p.Eval(&v);
        // out-of-range slot index -> VAR_OVERFLOW (7)
        FunctionParser q;
        q.AllocateStackMemory(16, 1); // only 16 slots; 999 overflows
        checkEq("get(999) parses", q.Parse("get(999)", "x"), -1);
        q.Eval(&v);
        checkEq("get(999) -> VAR_OVERFLOW", q.EvalError(), 7);
    }
}

// ------------------------------------------------------------------
// 3. eval() semantics (real)
// ------------------------------------------------------------------
static void evalReal()
{
    std::printf("== eval (real) ==\n");
    // 3.1 factorial: f(x) = if(x<=1, 1, x*eval(x-1))
    {
        FunctionParser p;
        checkEq("parse factorial", p.Parse("if(x<=1, 1, x*eval(x-1))", "x"), -1);
        double v;
        v = 5;  checkBits("f(5)",  p.Eval(&v), 120.0);
        v = 6;  checkBits("f(6)",  p.Eval(&v), 720.0);
        v = 1;  checkBits("f(1)",  p.Eval(&v), 1.0);
        checkEq("factorial no error", p.EvalError(), 0);
    }
    // 3.2 two variables, both modified in the recursive call:
    //     f(x,y) = if(x<0, y, y+eval(x-1, y+1))
    //     f(3,10) = 10+11+12+13+14 = 60
    {
        FunctionParser p;
        checkEq("parse sum", p.Parse("if(x<0, y, y+eval(x-1, y+1))", "x,y"), -1);
        double v[2] = { 3, 10 };
        checkBits("f(3,10)", p.Eval(v), 60.0);
    }
    // 3.3 stack-state restoration after the recursive call:
    //     f(x) = x*x + if(x>3, eval(x-1), 0)
    //     f(5) = 25 + 16 + 9 = 50
    {
        FunctionParser p;
        checkEq("parse state", p.Parse("x*x + if(x>3, eval(x-1), 0)", "x"), -1);
        double v = 5;
        checkBits("f(5)", p.Eval(&v), 50.0);
    }
    // 3.4 argument computed on the stack (not a raw variable):
    //     f(x) = if(x<2, x, eval(x/2))  ->  f(8) = 1
    {
        FunctionParser p;
        checkEq("parse stkarg", p.Parse("if(x<2, x, eval(x/2))", "x"), -1);
        double v = 8;
        checkBits("f(8)", p.Eval(&v), 1.0);
    }
    // 3.5 psh/get inside recursion: each level re-runs the whole
    //     bytecode, so it re-stores its own slot values:
    //     f(x) = psh(0, x*10) + get(0) + if(x<1, 0, eval(x-1))
    //     f(0)=1  f(1)=12  f(2)=33  f(3)=64
    {
        FunctionParser p;
        p.AllocateStackMemory(16, 4);
        checkEq("parse psh+eval",
                p.Parse("psh(0, x*10) + get(0) + if(x<1, 0, eval(x-1))", "x"), -1);
        double v = 3;
        checkBits("f(3)", p.Eval(&v), 64.0);
        checkEq("psh+eval no error", p.EvalError(), 0);
    }
}

// ------------------------------------------------------------------
// 4. eval() semantics (complex)
// ------------------------------------------------------------------
static void evalComplex()
{
    std::printf("== eval (complex) ==\n");
    // f(z) = if(abs(z)<1, z, eval(z/2))
    // f(16): |16|>=1 -> eval(8) -> eval(4) -> eval(2) -> eval(1)
    //        -> |1|<1 is false -> eval(0.5) -> |0.5|<1 -> 0.5
    {
        FunctionParser_cd p;
        checkEq("parse complex", p.Parse("if(abs(z)<1, z, eval(z/2))", "z"), -1);
        std::complex<double> z(16, 0);
        checkBits("re f(16)", p.EvalC(&z).real(), 0.5);
        checkBits("im f(16)", p.EvalC(&z).imag(), 0.0);
    }
    // f(3+4i): |5|>=1 -> eval(1.5+2i) -> |2.5|>=1 -> eval(0.75+i)
    // -> |sqrt(0.5625+1)| = sqrt(1.5625) = 1.25 >= 1 -> eval(0.375+0.5i)
    // -> |sqrt(0.140625+0.25)| = sqrt(0.390625) = 0.625 < 1 -> 0.375+0.5i
    {
        FunctionParser_cd p;
        checkEq("parse complex 2", p.Parse("if(abs(z)<1, z, eval(z/2))", "z"), -1);
        std::complex<double> z(3, 4);
        std::complex<double> r = p.EvalC(&z);
        checkBits("re f(3+4i)", r.real(), 0.375);
        checkBits("im f(3+4i)", r.imag(), 0.5);
    }
}

// ------------------------------------------------------------------
// 5. Batch Eval2 vs scalar Eval
// ------------------------------------------------------------------
static void evalBatch()
{
    std::printf("== eval (batch Eval2) ==\n");
    // NOTE: the batch evaluator requires every if() condition to be
    // uniform over the whole batch (that is what IF_FUNCT_ERROR is for).
    // A recursive eval() therefore succeeds in batch mode only when all
    // points recurse to the same depth. The success test below keeps x
    // identical over the batch so that the recursion depth is uniform;
    // y, z and t still vary per point and are carried through the
    // recursive calls.
    // f(x,y,z,t) = if(abs(x)<1e-9, y*z, t + eval(x-1, y, z, t))
    //             = 3*t + y*z  (for x = 3)
    const char* f = "if(abs(x)<1e-9, y*z, t + eval(x-1, y, z, t))";
    const int nbX = 1, nbY = 3, nbZ = 4, nbT = 2;
    const int nbvar = 4;
    const int nbstack = nbX*nbY*nbZ*nbT;
    std::vector<double> vals(nbstack*nbvar);
    std::vector<double> resE2(nbstack), resEval(nbstack);
    {
        FunctionParser p2, p1;
        // App order (cf. Iso3D.cpp): Parse first, then AllocateStackMemory.
        checkEq("parse batch fn", p2.Parse(f, "x,y,z,t"), -1);
        checkEq("parse scalar fn", p1.Parse(f, "x,y,z,t"), -1);
        p2.AllocateStackMemory(nbstack, nbvar);
        p1.AllocateStackMemory(nbstack, nbvar);

        int e = 0;
        for(int tt = 0; tt < nbT; ++tt)
            for(int kk = 0; kk < nbZ; ++kk)
                for(int jj = 0; jj < nbY; ++jj)
                    for(int ii = 0; ii < nbX; ++ii)
                    {
                        vals[e*nbvar+0] = 3.0; // uniform x -> uniform depth
                        vals[e*nbvar+1] = jj - 1;
                        vals[e*nbvar+2] = kk * 0.5;
                        vals[e*nbvar+3] = tt;
                        ++e;
                    }
        const double r2 = p2.Eval2(&vals[0], nbvar, &resE2[0], nbstack);
        checkEq("batch ok (no IF_FUNCT_ERROR)", r2, 6.0);
        for(int l = 0; l < nbstack; ++l)
            resEval[l] = p1.Eval(&vals[l*nbvar]);
        for(int l = 0; l < nbstack; ++l)
            checkBits("batch vs scalar", resE2[l], resEval[l]);
    }
    // 5.2 the nested eval() run hits a non-uniform if() -> the error
    //     must propagate out of cEval so that the application falls back
    //     to scalar eval. f(x) = if(x>0, eval(x-1, y, z, t), 0) with
    //     batch x = {2, 2.5}: outer run uniform (both > 0), nested run
    //     x = {1, 1.5} uniform, nested run x = {0, 0.5} non-uniform.
    {
        FunctionParser p2;
        p2.AllocateStackMemory(64, 4);
        checkEq("parse nonuniform",
                p2.Parse("if(x>0, eval(x-1, y, z, t), 0)", "x,y,z,t"), -1);
        std::vector<double> v(2*4);
        v[0] = 2.0;  v[1] = v[2] = v[3] = 0;
        v[4] = 2.5;  v[5] = v[6] = v[7] = 0;
        std::vector<double> r(2);
        const double res = p2.Eval2(&v[0], 4, &r[0], 2);
        checkEq("nested nonuniform -> IF_FUNCT_ERROR(5)", res, 5.0);
        checkEq("nested nonuniform error type", p2.EvalError(), 5);
    }
}

int main()
{
    setvbuf(stdout, 0, _IONBF, 0);
    nameProbe();
    getProbe();
    evalReal();
    evalComplex();
    evalBatch();
    std::printf("%d checks passed, %d failed\n", gPass, gFail);
    return gFail ? 1 : 0;
}
