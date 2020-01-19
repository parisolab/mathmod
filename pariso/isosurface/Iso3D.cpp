/***************************************************************************
*   Copyright (C) 2020by Abderrahman Taha                                *
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
#include "TableMap.h"
#include "Iso3D.h"
#include "povfunctions.cpp"

static uint NbPolyMin;
static Voxel *GridVoxelVarPt;
static double *Results;
static uint NbVertexTmp = 0;
static std::vector<float> NormOriginaltmpVector;

static uint NbMaxGrid = 100;

uint OrignbX, OrignbY, OrignbZ;
uint Stack_Factor=OrignbX*OrignbY*OrignbZ;

std::vector<float> NormVertexTabVector;
std::vector<uint>  IndexPolyTabMinVector;
std::vector<uint>  IndexPolyTabVector;

static CellNoise *NoiseFunction = new CellNoise();
static ImprovedNoise *PNoise = new ImprovedNoise(4., 4., 4.);

static double IsoComponentId=0;
static double IsoThreadId=0;

static QElapsedTimer times;

double CurrentIsoCmpId(const double* p)
{
    int pp = int (p[0]);
    if(pp==0)
        return IsoComponentId;
    else
        return IsoThreadId;
}

extern double TurbulenceWorley(const double* p)
{
    return double (
               NoiseFunction->CellNoiseFunc(
                   float (p[0]),
                   float (p[1]),
                   float (p[2]),
                   int (p[3]),
                   int (p[4]),
                   int (p[5]))
           );
}

double TurbulencePerlin(const double* p)
{
    return double (
               PNoise->FractalNoise3D(
                   float (p[0]),
                   float (p[1]),
                   float (p[2]),
                   int (p[3]),
                   float (p[4]),
                   float (p[5])));
}

double MarblePerlin(const double* p)
{
    return double (
               PNoise->Marble(
                   float (p[0]),
                   float (p[1]),
                   float (p[2]),
                   int (p[3])));
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void IsoWorkerThread::run()
{
    IsoCompute(CurrentComponent);
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Iso3D::run()
{
    BuildIso();
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void IsoWorkerThread::emitMySignal()
{
    emit mySignal(signalVal);
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Iso3D::emitErrorSignal()
{
    emit ErrorSignal(int(messageerror));
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Iso3D::emitUpdateMessageSignal()
{
    emit UpdateMessageSignal(message);
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Iso3D::BuildIso()
{
    IsoBuild(
        &(localScene->ArrayNorVer_localPt),
        &(localScene->PolyIndices_localPt),
        &localScene->PolyNumber,
        &(localScene->VertxNumber),
        &(localScene->PolyIndices_localPtMin),
        &(localScene->NbPolygnNbVertexPtMin),
        &(localScene->componentsinfos));
}

//+++++++++++++++++++++++++++++++++++++++++
IsoMasterThread::IsoMasterThread()
{
    ParisoCondition = -1;
    ImplicitFunction =  "cos(x) + cos(y) + cos(z)";
    XlimitSup = "4";
    YlimitSup = "4";
    ZlimitSup = "4";
    XlimitInf   = "-4";
    YlimitInf   = "-4";
    ZlimitInf   = "-4";
    Lacunarity = 0.5;
    Gain = 1.0;
    Octaves = 4;
    Cstparser.AddConstant("pi", PI);
    componentsNumber = ConstSize = FunctSize = RgbtSize = VRgbtSize = 0;
}

//+++++++++++++++++++++++++++++++++++++++++
void IsoMasterThread::IsoMasterTable()
{
    UsedFunct    = new bool[0];
    UsedFunct2   = new bool[0];
}

IsoMasterThread::~IsoMasterThread()
{
    if(ParsersAllocated)
    {
        delete[] implicitFunctionParser;
        delete[] xSupParser;
        delete[] ySupParser;
        delete[] zSupParser;
        delete[] xInfParser;
        delete[] yInfParser;
        delete[] zInfParser;
        delete[] Fct;
        delete[] ParisoConditionParser;
        delete[] VRgbtParser;
        delete[] RgbtParser;
        delete GradientParser;
        delete NoiseParser;
        ParsersAllocated = false;
    }
    delete[] UsedFunct;
    delete[] UsedFunct2;
    grid.clear();
    SliderValues.clear();
    SliderNames.clear();
    Consts.clear();
    ConstNames.clear();
    ConstValues.clear();

    Rgbts.clear();
    RgbtNames.clear();

    VRgbts.clear();
    VRgbtNames.clear();

    Functs.clear();
    FunctNames.clear();
}

IsoWorkerThread::~IsoWorkerThread()
{
    if(ParsersAllocated)
    {
        delete[] implicitFunctionParser;
        delete[] Fct;
        ParsersAllocated = false;
    }
}

IsoWorkerThread::IsoWorkerThread()
{
    Xgrid = Ygrid = Zgrid = 40;
    stepMorph = 0;
    pace = 1.0/30.0;
    activeMorph = -1;
    AllComponentTraited = false;
    ParsersAllocated = false;
    StopCalculations = false;
}

//+++++++++++++++++++++++++++++++++++++++++
void Iso3D::WorkerThreadCopy(IsoWorkerThread *WorkerThreadsTmp)
{
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        WorkerThreadsTmp[nbthreads].Xgrid = masterthread->Xgrid;
        WorkerThreadsTmp[nbthreads].Ygrid = masterthread->Ygrid;
        WorkerThreadsTmp[nbthreads].Zgrid = masterthread->Zgrid;
        WorkerThreadsTmp[nbthreads].MyIndex  = nbthreads+1;
        WorkerThreadsTmp[nbthreads].WorkerThreadsNumber = WorkerThreadsNumber;
        WorkerThreadsTmp[nbthreads].maximumgrid = NbMaxGrid;
    }
}
//+++++++++++++++++++++++++++++++++++++++
void Iso3D::UpdateThredsNumber(uint NewThreadsNumber)
{
    uint OldWorkerThreadsNumber = WorkerThreadsNumber;
    WorkerThreadsNumber = NewThreadsNumber;
    IsoWorkerThread *workerthreadstmp = new IsoWorkerThread[WorkerThreadsNumber-1];
    WorkerThreadCopy(workerthreadstmp);
    //Free old memory:
    for(uint i=0; i+1<OldWorkerThreadsNumber; i++)
        workerthreads[i].DeleteWorkerParsers();

    if(OldWorkerThreadsNumber >1)
        delete[] workerthreads;

    //Assigne newly allocated memory
    workerthreads = workerthreadstmp;
    masterthread->WorkerThreadsNumber = WorkerThreadsNumber;
}

//+++++++++++++++++++++++++++++++++++++++
ErrorMessage  Iso3D::IsoMorph()
{
    ErrorMessage err = masterthread->ParserIso();
    if(err.iErrorIndex < 0)
        ThreadParsersCopy();
    return err;
}

//+++++++++++++++++++++++++++++++++++++++
ErrorMessage Iso3D::ThreadParsersCopy()
{
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        workerthreads[nbthreads].xLocal2.clear();
        workerthreads[nbthreads].xLocal2 = masterthread->xLocal2;
        workerthreads[nbthreads].yLocal2.clear();
        workerthreads[nbthreads].yLocal2 = masterthread->yLocal2;
        workerthreads[nbthreads].zLocal2.clear();
        workerthreads[nbthreads].zLocal2 = masterthread->zLocal2;
        workerthreads[nbthreads].activeMorph = masterthread->activeMorph;
        workerthreads[nbthreads].AllComponentTraited = masterthread->AllComponentTraited;
        workerthreads[nbthreads].Xgrid = masterthread->Xgrid;
        workerthreads[nbthreads].Ygrid = masterthread->Ygrid;
        workerthreads[nbthreads].Zgrid = masterthread->Zgrid;
    }

    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
        workerthreads[nbthreads].DeleteWorkerParsers();

    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
        workerthreads[nbthreads].AllocateParsersForWorkerThread(masterthread->componentsNumber, masterthread->FunctSize);

    return(parse_expression2());
}

ErrorMessage  Iso3D::parse_expression2()
{
    ErrorMessage NodError;
    // Functions :
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint ij=0; ij<masterthread->FunctSize; ij++)
        {
            workerthreads[nbthreads].Fct[ij].AddFunction("CmpId",CurrentIsoCmpId, 1);
            workerthreads[nbthreads].Fct[ij].AddConstant("pi", PI);
        }

        for(uint ii=0; ii<masterthread->FunctSize; ii++)
        {
            for(uint jj=0; jj<masterthread->ConstSize; jj++)
            {
                workerthreads[nbthreads].Fct[ii].AddConstant(masterthread->ConstNames[jj], masterthread->ConstValues[jj]);
            }

            //Add predefined constatnts:
            for(uint kk=0; kk<masterthread->Nb_Sliders; kk++)
            {
                workerthreads[nbthreads].Fct[ii].AddConstant(masterthread->SliderNames[kk], masterthread->SliderValues[kk]);
            }
        }

        for(uint ii=0; ii<masterthread->FunctSize; ii++)
        {
            workerthreads[nbthreads].Fct[ii].AddFunction("NoiseW",TurbulenceWorley, 6);
            workerthreads[nbthreads].Fct[ii].AddFunction("fhelix1",fhelix1, 10);
            workerthreads[nbthreads].Fct[ii].AddFunction("fhelix2",fhelix2, 10);
            workerthreads[nbthreads].Fct[ii].AddFunction("f_hex_y",f_hex_y, 4);
            workerthreads[nbthreads].Fct[ii].AddFunction("p_skeletal_int",p_skeletal_int, 3);
            workerthreads[nbthreads].Fct[ii].AddFunction("fmesh",fmesh, 8);
            workerthreads[nbthreads].Fct[ii].AddFunction("NoiseP",TurbulencePerlin, 6);
            workerthreads[nbthreads].Fct[ii].AddFunction("MarbleP",MarblePerlin, 4);
            for(uint jj=0; jj<ii; jj++)
                if(masterthread->UsedFunct2[ii*masterthread->FunctSize+jj])
                    workerthreads[nbthreads].Fct[ii].AddFunction(masterthread->FunctNames[jj], workerthreads[nbthreads].Fct[jj]);
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].Fct[ii].Parse(masterthread->Functs[ii],"x,y,z,t")) >= 0)
            {
                masterthread->stdError.strError = masterthread->Functs[ii];
                return masterthread->stdError;
            }
            workerthreads[nbthreads].Fct[ii].AllocateStackMemory(Stack_Factor);
        }
    }

    //Add defined constantes:
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint i=0; i<masterthread->componentsNumber; i++)
        {
            workerthreads[nbthreads].implicitFunctionParser[i].AddConstant("pi", PI);


            for(uint j=0; j<masterthread->ConstSize; j++)
            {
                workerthreads[nbthreads].implicitFunctionParser[i].AddConstant(masterthread->ConstNames[j], masterthread->ConstValues[j]);
            }
            //Add predefined sliders constatnts:
            for(uint k=0; k<masterthread->Nb_Sliders; k++)
            {
                workerthreads[nbthreads].implicitFunctionParser[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
            }
        }
    }
    // Add defined functions :
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint i=0; i<masterthread->componentsNumber; i++)
        {
            //Functions:
            workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
            workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("fhelix1",fhelix1, 10);
            workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("fhelix2",fhelix2, 10);
            workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("f_hex_y",f_hex_y, 4);
            workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("p_skeletal_int",p_skeletal_int, 3);
            workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("fmesh",fmesh, 8);
            workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
            workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("MarbleP",MarblePerlin, 4);

            for(uint j=0; j<masterthread->FunctSize; j++)
            {
                if(masterthread->UsedFunct[i*masterthread->FunctSize+j])
                {
                    workerthreads[nbthreads].implicitFunctionParser[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct[j]);
                }
            }
        }
    }

    // Final step: parsing
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint index=0; index< masterthread->componentsNumber; index++)
        {
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].implicitFunctionParser[index].Parse(masterthread-> ImplicitStructs[index].fxyz, masterthread->varliste)) >= 0)
            {
                masterthread->stdError.strError = masterthread->ImplicitStructs[index].fxyz;
                return masterthread->stdError;
            }
        }
    }

    return NodError;
}

//+++++++++++++++++++++++++++++++++++++++++
void Iso3D::UpdateMaxGrid(uint newNbMaxgrid)
{
    NbMaxGrid = newNbMaxgrid;
    masterthread->maximumgrid = newNbMaxgrid;
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        workerthreads[nbthreads].maximumgrid = newNbMaxgrid;
    }
}

//+++++++++++++++++++++++++++++++++++++++++
Iso3D::Iso3D( uint nbmaxgrid,
              uint nbThreads,
              uint nbGrid,
              uint factX,
              uint factY,
              uint factZ)
{
    OrignbX= factX;
    OrignbY= factY;
    OrignbZ=factZ;
    Stack_Factor = factX*factY*factZ;
    NbMaxGrid = nbmaxgrid;
    NbTriangleIsoSurface = 0;
    NbPointIsoMap = 0;
    Xgrid = Ygrid = Zgrid = nbGrid;
    WorkerThreadsNumber = nbThreads;
    masterthread  = new IsoMasterThread();
    masterthread->IsoMasterTable();
    workerthreads = new IsoWorkerThread[WorkerThreadsNumber-1];

    masterthread->Xgrid = Xgrid;
    masterthread->Ygrid = Ygrid;
    masterthread->Zgrid = Zgrid;
    masterthread->maximumgrid = NbMaxGrid;
    masterthread->MyIndex = 0;
    masterthread->WorkerThreadsNumber = WorkerThreadsNumber;

    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        workerthreads[nbthreads].Xgrid = Xgrid;
        workerthreads[nbthreads].Ygrid = Ygrid;
        workerthreads[nbthreads].Zgrid = Zgrid;
        workerthreads[nbthreads].maximumgrid = NbMaxGrid;
        workerthreads[nbthreads].MyIndex = nbthreads+1;
        workerthreads[nbthreads].WorkerThreadsNumber = WorkerThreadsNumber;
    }
}

///+++++++++++++++++++++++++++++++++++++++++
uint IsoMasterThread::HowManyVariables(std::string NewVariables, uint type)
{
    std::string tmp, tmp2,tmp3;
    size_t position =0, jpos;
    uint Nb_variables =0;
    while( NewVariables!= "")
    {
        if((position = NewVariables.find(";")) != std::string::npos)
        {
            tmp = NewVariables;
            tmp2= tmp3 = (tmp.substr(0,position));
            jpos = tmp2.find("=");
            if(type == 1)
            {
                ConstNames.push_back(tmp2.substr(0,jpos));
                Consts.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 2)
            {
                FunctNames.push_back(tmp2.substr(0,jpos));
                Functs.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 3)
            {
                RgbtNames.push_back(tmp2.substr(0,jpos));
                Rgbts.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 4)
            {
                VRgbtNames.push_back(tmp2.substr(0,jpos));
                VRgbts.push_back(tmp3.substr(jpos+1,position-1));
            }
            tmp2 = NewVariables.substr(position+1, NewVariables.length()-1);
            NewVariables = tmp2;
            Nb_variables++;
        }
        else
        {
            tmp = tmp2 = tmp3 = NewVariables;
            jpos = tmp2.find("=");
            if(type == 1)
            {
                ConstNames.push_back(tmp2.substr(0, jpos));
                Consts.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 2)
            {
                FunctNames.push_back(tmp2.substr(0, jpos));
                Functs.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 3)
            {
                RgbtNames.push_back(tmp2.substr(0, jpos));
                Rgbts.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 4)
            {
                VRgbtNames.push_back(tmp2.substr(0, jpos));
                VRgbts.push_back(tmp3.substr(jpos+1,position-1));
            }

            NewVariables = "";
            Nb_variables++;
        }
    }
    return Nb_variables;
}

///+++++++++++++++++++++++++++++++++++++++++
uint IsoMasterThread::HowManyIsosurface(std::string ImplicitFct, uint type)
{
    std::string tmp, tmp2;
    size_t position =0, jpos;
    uint Nb_implicitfunction =0;
    if(type ==0)
    {
        ImplicitStructs[0].fxyz = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) !=std::string::npos   )
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].fxyz = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].fxyz  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    //++++++++++++++++++
    else if(type == 1)  //xmin
    {
        ImplicitStructs[0].xmin = ImplicitFct;
        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].xmin = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].xmin  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 2)  //xmax
    {
        ImplicitStructs[0].xmax = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].xmax = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].xmax  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 3) //ymin
    {
        ImplicitStructs[0].ymin = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].ymin = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].ymin  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 4) //ymax
    {
        ImplicitStructs[0].ymax = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].ymax = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].ymax  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 5) //zmin
    {
        ImplicitStructs[0].zmin = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].zmin = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].zmin  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 6) //zmax
    {
        ImplicitStructs[0].zmax = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].zmax = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].zmax  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 8) //Cnd
    {
        ImplicitStructs[0].cnd = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].cnd = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].cnd  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }

    return 0;
}

//+++++++++++++++++++++++++++++++++++++++++
void Iso3D::ReinitVarTablesWhenMorphActiv(uint IsoIndex)
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    const uint limitX = Xgrid, limitY = Ygrid, limitZ = Zgrid;
    uint maxgridval = NbMaxGrid;
    vals[3]          = masterthread->stepMorph;
    masterthread->xLocal2[IsoIndex*maxgridval]=masterthread->xSupParser[IsoIndex].Eval(vals);
    masterthread->yLocal2[IsoIndex*maxgridval]=masterthread->ySupParser[IsoIndex].Eval(vals);
    masterthread->zLocal2[IsoIndex*maxgridval]=masterthread->zSupParser[IsoIndex].Eval(vals);

    masterthread->x_Step[IsoIndex] =  (masterthread->xLocal2[IsoIndex*maxgridval] - masterthread->xInfParser[IsoIndex].Eval(vals))/(limitX-1);
    masterthread->y_Step[IsoIndex] =  (masterthread->yLocal2[IsoIndex*maxgridval] - masterthread->yInfParser[IsoIndex].Eval(vals))/(limitY-1);
    masterthread->z_Step[IsoIndex] =  (masterthread->zLocal2[IsoIndex*maxgridval] - masterthread->zInfParser[IsoIndex].Eval(vals))/(limitZ-1);

    for (uint i= 1; i < limitX; i++)
        masterthread->xLocal2[IsoIndex*maxgridval+i] = masterthread->xLocal2[IsoIndex*maxgridval+i-1] - masterthread->x_Step[IsoIndex];
    for (uint j= 1; j < limitY; j++)
        masterthread->yLocal2[IsoIndex*maxgridval+j] = masterthread->yLocal2[IsoIndex*maxgridval+j-1] - masterthread->y_Step[IsoIndex];
    for (uint k= 1; k < limitZ; k++)
        masterthread->zLocal2[IsoIndex*maxgridval+k] = masterthread->zLocal2[IsoIndex*maxgridval+k-1] - masterthread->z_Step[IsoIndex];

    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for (uint k= 0; k < limitX; k++)
        {
            workerthreads[nbthreads].xLocal2[IsoIndex*maxgridval+k] = masterthread->xLocal2[IsoIndex*maxgridval+k];
        }
        for (uint k= 0; k < limitY; k++)
        {
            workerthreads[nbthreads].yLocal2[IsoIndex*maxgridval+k] = masterthread->yLocal2[IsoIndex*maxgridval+k];
        }
        for (uint k= 0; k < limitZ; k++)
        {
            workerthreads[nbthreads].zLocal2[IsoIndex*maxgridval+k] = masterthread->zLocal2[IsoIndex*maxgridval+k];
        }
    }
}

//+++++++++++++++++++++++++++++++++++++++++
void IsoWorkerThread::VoxelEvaluation(uint IsoIndex)
{
    double* vals;
    double* Res;
    uint maxgrscalemaxgr = maximumgrid*maximumgrid;
    const uint limitY = Ygrid, limitZ = Zgrid;
    uint I, J, IJK;
    uint id=0;
    uint nbX=OrignbX, nbY=OrignbY, nbZ=OrignbZ;
    uint nbstack=nbX*nbY*nbZ;
    uint Iindice=0, Jindice=0, Kindice=0;
    int PreviousSignal=0;
    vals = new double[34*nbstack];
    Res  = new double[nbstack];
    vals[3]    = stepMorph;
    uint taille=0;
    iStart = 0;
    iFinish = 0;
    for(uint i=0; i<Xgrid; i++)
    {
        if((i% (WorkerThreadsNumber))  == MyIndex )
        {
            taille += 1;
        }
        if(MyIndex <= (i% (WorkerThreadsNumber)))
            iFinish  += 1;
    }
    iStart = iFinish - taille;

    for(uint l=0; l<nbstack; l++)
        vals[l*34+3]= stepMorph;

    uint remX= (iFinish-iStart)%nbX;
    uint remY= limitY%nbY;
    uint remZ= limitZ%nbZ;
    uint Totalpoints=(iFinish-iStart)*limitY*limitZ;
    //****
    implicitFunctionParser[IsoIndex].AllocateStackMemory(Stack_Factor);
    for(uint i=iStart; i<iFinish; i+=nbX )
    {
        Iindice = i;
        nbY=OrignbY;
        nbZ=OrignbZ;
        if((remX>0) && ((Iindice+remX)==(iFinish)))
        {
            nbX = remX;
            i= iFinish;
        }

        I = Iindice*maxgrscalemaxgr;
        for(uint j=0; j<limitY; j+=nbY)
        {
            Jindice = j;
            nbZ=OrignbZ;

            if((remY>0) && ((Jindice+remY)==(limitY)))
            {
                nbY = remY;
                j= limitY;
            }
            J = I + Jindice*maximumgrid;
            for(uint k=0; k<limitZ; k+=nbZ)
            {
                Kindice = k;
                if((remZ>0) && ((Kindice+remZ)==(limitZ)))
                {
                    nbZ = remZ;
                    k= limitZ;
                }
                nbstack = nbX*nbY*nbZ;
                // X, Y and Z arrays construction:

                for(uint l=0; l<nbstack; l++)
                {
                    vals[l*34  ]= xLocal2[IsoIndex*maximumgrid+Iindice+uint(l*nbX/nbstack)];
                    vals[l*34+1]= yLocal2[IsoIndex*maximumgrid+Jindice+((uint(l/nbZ))%nbY)];
                    vals[l*34+2]= zLocal2[IsoIndex*maximumgrid+Kindice+(l%nbZ)];
                }

                IJK = J+Kindice;
                double res = implicitFunctionParser[IsoIndex].Eval2(vals, 34, Res, nbstack);
                if( abs(res - IF_FUNCT_ERROR) == 0.0)
                {
                    for(uint l=0; l<nbstack; l++)
                        Res[l] = implicitFunctionParser[IsoIndex].Eval(&(vals[l*34]));
                }
                else if( abs(res - DIVISION_BY_ZERO) == 0.0)
                {
                    StopCalculations = true;
                }

                if(StopCalculations)
                    return;

                uint p=0;
                uint sect=0;
                for(uint ii=0; ii<nbX; ii++)
                    for(uint jj=0; jj<nbY; jj++)
                        for(uint kk=0; kk<nbZ; kk++)
                        {
                            sect= IJK + (ii)*maxgrscalemaxgr+ (jj)*maximumgrid + (kk);
                            Results[sect] = Res[p];
                            GridVoxelVarPt[sect].Signature   = 0; // Signature initialisation
                            GridVoxelVarPt[sect].NbEdgePoint = 0; // No EdgePoint yet!
                            //for(int l=0; l<12; l++) GridVoxelVarPt[sect].Edge_Points[l] = -20;
                            p++;
                        }
                //Signal emission:
                id+=nbstack;

                if(MyIndex == 0 && activeMorph != 1)
                {
                    signalVal = int((id*100)/Totalpoints);
                    if((signalVal - PreviousSignal) > 1 || id==Totalpoints)
                    {
                        PreviousSignal = signalVal;
                        emitMySignal();
                    }
                }
            }
        }
    }

    delete[] vals;
    delete[] Res;
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::ConstructIsoNormale(uint idx)
{
    float val1, val2, val3, val4, val5, val6,
          pt1_x, pt1_y, pt1_z,
          pt2_x, pt2_y, pt2_z,
          pt3_x, pt3_y, pt3_z,
          scalar, n1, n2, n3;
    uint ThreeTimesI, IndexFirstPoint, IndexSecondPoint, IndexThirdPoint;

    NormOriginaltmpVector.resize(NormOriginaltmpVector.size()+ 3*NbTriangleIsoSurface);

    for(uint i = 0; i<NbTriangleIsoSurface; ++i)
    {
        ThreeTimesI      = i*3;
        IndexFirstPoint  = 10*IndexPolyTabVector[ThreeTimesI  +3*idx] + 7;
        IndexSecondPoint = 10*IndexPolyTabVector[ThreeTimesI+1+3*idx] + 7;
        IndexThirdPoint  = 10*IndexPolyTabVector[ThreeTimesI+2+3*idx] + 7;

        pt1_x= NormVertexTabVector[IndexFirstPoint  ];
        pt1_y= NormVertexTabVector[IndexFirstPoint+1];
        pt1_z= NormVertexTabVector[IndexFirstPoint+2];

        pt2_x= NormVertexTabVector[IndexSecondPoint  ];
        pt2_y= NormVertexTabVector[IndexSecondPoint+1];
        pt2_z= NormVertexTabVector[IndexSecondPoint+2];

        pt3_x= NormVertexTabVector[IndexThirdPoint   ];
        pt3_y= NormVertexTabVector[IndexThirdPoint+1 ];
        pt3_z= NormVertexTabVector[IndexThirdPoint+2 ];

        val1 = pt2_y - pt1_y;
        val2 = pt3_z - pt1_z;
        val3 = pt2_z - pt1_z;
        val4 = pt3_y - pt1_y;
        val5 = pt3_x - pt1_x;
        val6 = pt2_x - pt1_x;

        n1 = (val1*val2 - val3*val4);
        n2 = (val3*val5 - val6*val2);
        n3 = (val6*val4 - val1*val5);

        scalar = float(sqrt(n1*n1+n2*n2+n3*n3));
        if(scalar < float(0.0000001))  scalar  = float(0.0000001);
        (NormOriginaltmpVector[ThreeTimesI  ] = n1/scalar);
        (NormOriginaltmpVector[ThreeTimesI+1] = n2/scalar);
        (NormOriginaltmpVector[ThreeTimesI+2] = n3/scalar);

    }
}

///++++++++++++++++++++ OutPut The IsoSurface +++++++++++++++++++++++

void Iso3D::SaveIsoGLMap(uint indx)
{
    uint IndexFirstPoint, IndexSecondPoint, IndexThirdPoint, ThreeTimesI;
    double scalar;

/// Recalculate the normals so we have one for each Point (like Pov Mesh) :
    for (uint i=0; i < NbPointIsoMap ; i++)
    {
        ThreeTimesI = 10*i  + 4;
        NormVertexTabVector[ 10*NbVertexTmp +ThreeTimesI  ] = 0;
        NormVertexTabVector[ 10*NbVertexTmp +ThreeTimesI+1] = 0;
        NormVertexTabVector[ 10*NbVertexTmp +ThreeTimesI+2] = 0;
    }

    for(uint i = 0; i<NbTriangleIsoSurface; ++i)
    {
        ThreeTimesI   = i*3;
        IndexFirstPoint  = 10*IndexPolyTabVector[ThreeTimesI  +3*indx] + 4;
        IndexSecondPoint = 10*IndexPolyTabVector[ThreeTimesI+1+3*indx] + 4;
        IndexThirdPoint  = 10*IndexPolyTabVector[ThreeTimesI+2+3*indx] + 4;


        NormVertexTabVector[IndexFirstPoint  ] += NormOriginaltmpVector[ThreeTimesI  ];
        NormVertexTabVector[IndexFirstPoint+1] += NormOriginaltmpVector[ThreeTimesI+1];
        NormVertexTabVector[IndexFirstPoint+2] += NormOriginaltmpVector[ThreeTimesI+2];

        NormVertexTabVector[IndexSecondPoint  ] += NormOriginaltmpVector[ThreeTimesI  ];
        NormVertexTabVector[IndexSecondPoint+1] += NormOriginaltmpVector[ThreeTimesI+1];
        NormVertexTabVector[IndexSecondPoint+2] += NormOriginaltmpVector[ThreeTimesI+2];

        NormVertexTabVector[IndexThirdPoint  ]  += NormOriginaltmpVector[ThreeTimesI  ];
        NormVertexTabVector[IndexThirdPoint+1]  += NormOriginaltmpVector[ThreeTimesI+1];
        NormVertexTabVector[IndexThirdPoint+2]  += NormOriginaltmpVector[ThreeTimesI+2];
    }

/// Normalisation
    uint idx;
    for (uint i=0; i < NbPointIsoMap  ; i++)
    {
        idx = 10*i + 4;
        scalar = double(sqrt((NormVertexTabVector[idx  ]*NormVertexTabVector[idx  ]) +
                             (NormVertexTabVector[idx+1]*NormVertexTabVector[idx+1]) +
                             (NormVertexTabVector[idx+2]*NormVertexTabVector[idx+2])));
        if(scalar < 0.000000001)  scalar = 0.000000001;
        NormVertexTabVector[idx  ] /= float(scalar);
        NormVertexTabVector[idx+1] /= float(scalar);
        NormVertexTabVector[idx+2] /= float(scalar);
    }
}

//++++++++++++++++++++++++++++++++++++++++++//
ErrorMessage IsoMasterThread::ParserIso()
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    varliste = "x,y,z,t";

    initparser();

    //Evaluates defined constantes:
    if(constnotnull)
    {
        ConstSize = HowManyVariables(Const, 1);
        for(uint j=0; j<ConstSize; j++)
        {
            if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u")) >= 0)
            {
                stdError.strError = Consts[j];
                return stdError;
            }
            ConstValues.push_back(Cstparser.Eval(&vals[3]));
            Cstparser.AddConstant(ConstNames[j], ConstValues[j]);
        }
    }
    else
    {
        ConstSize = 0;
    }

    if(functnotnull)
    {
        FunctSize = HowManyVariables(Funct, 2);
        for(uint i=0; i<FunctSize; i++)
        {
            for(uint j=0; j<ConstSize; j++)
            {
                Fct[i].AddConstant(ConstNames[j], ConstValues[j]);
            }

            //Add predefined constatnts:
            for(uint k=0; k<Nb_Sliders; k++)
            {
                Fct[i].AddConstant(SliderNames[k], SliderValues[k]);
            }
        }

        for(uint i=0; i<FunctSize; i++)
        {

            for(uint j=0; j<i; j++)
                if( (UsedFunct2[i*FunctSize+j]=(Functs[i].find(FunctNames[j]) != std::string::npos)))
                    Fct[i].AddFunction(FunctNames[j], Fct[j]);
            if ((stdError.iErrorIndex = Fct[i].Parse(Functs[i],"x,y,z,t"))>=0)
            {
                stdError.strError = Functs[i];
                return stdError;
            }
            Fct[i].AllocateStackMemory(Stack_Factor);
        }
    }
    else
    {
        FunctSize =0;
    }


    if(rgbtnotnull)
    {
        RgbtSize = HowManyVariables(Rgbt, 3);

        for(uint i=0; i<RgbtSize; i++)
        {
            for(uint j=0; j<ConstSize; j++)
            {
                RgbtParser[i].AddConstant(ConstNames[j], ConstValues[j]);
                RgbtParser[i].AddConstant("Lacunarity", double(Lacunarity));
                RgbtParser[i].AddConstant("Gain", double(Gain));
                RgbtParser[i].AddConstant("Octaves", double(Octaves));
                RgbtParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
                RgbtParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
                RgbtParser[i].AddFunction("MarbleP",MarblePerlin, 4);
            }
        }
    }
    else
    {
        RgbtSize =0;
    }

    //For Solid Texture :
    if(vrgbtnotnull)
    {
        VRgbtSize = HowManyVariables(VRgbt, 4);
        for(uint j=0; j<ConstSize; j++)
        {
            GradientParser->AddConstant(ConstNames[j], ConstValues[j]);
        }

        GradientParser->AddConstant("Lacunarity", Lacunarity);
        GradientParser->AddConstant("Gain", Gain);
        GradientParser->AddConstant("Octaves", Octaves);
        GradientParser->AddFunction("NoiseW",TurbulenceWorley, 6);
        GradientParser->AddFunction("NoiseP",TurbulencePerlin, 6);
        GradientParser->AddFunction("MarbleP",MarblePerlin, 4);

        for(uint i=0; i<VRgbtSize; i++)
        {
            for(uint j=0; j<ConstSize; j++)
            {
                VRgbtParser[i].AddConstant(ConstNames[j], ConstValues[j]);
                VRgbtParser[i].AddConstant("Lacunarity", Lacunarity);
                VRgbtParser[i].AddConstant("Gain", Gain);
                VRgbtParser[i].AddConstant("Octaves", Octaves);
                VRgbtParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
                VRgbtParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
                VRgbtParser[i].AddFunction("MarbleP",MarblePerlin, 4);
            }
        }
    }
    else
    {
        VRgbtSize =0;
    }

    if(Noise != "")
    {
        for(uint j=0; j<ConstSize; j++)
            NoiseParser->AddConstant(ConstNames[j], ConstValues[j]);
        NoiseParser->AddConstant("Lacunarity", Lacunarity);
        NoiseParser->AddConstant("Gain", Gain);
        NoiseParser->AddConstant("Octaves", Octaves);

        //Add predefined constatnts:
        for(uint k=0; k<Nb_Sliders; k++)
        {
            NoiseParser->AddConstant(SliderNames[k], SliderValues[k]);
        }

    }

    //ImplicitFunction is composed of more than one isosurface:
    HowManyIsosurface(ImplicitFunction, 0);
    HowManyIsosurface(XlimitInf, 1);
    HowManyIsosurface(XlimitSup, 2);
    HowManyIsosurface(YlimitInf, 3);
    HowManyIsosurface(YlimitSup, 4);
    HowManyIsosurface(ZlimitInf, 5);
    HowManyIsosurface(ZlimitSup, 6);
    HowManyIsosurface(Grid, 7);
    if(cndnotnull)
    {
        ParisoCondition = 1;
        HowManyIsosurface(Condition, 8);
    }
    else
        ParisoCondition = -1;

    //Add defined constantes:
    for(uint i=0; i<componentsNumber; i++)
    {
        for(uint j=0; j<ConstSize; j++)
        {
            implicitFunctionParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            if(cndnotnull)
                ParisoConditionParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            xSupParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            ySupParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            zSupParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            xInfParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            yInfParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            zInfParser[i].AddConstant(ConstNames[j], ConstValues[j]);
        }

        //Add predefined constatnts:
        for(uint k=0; k<Nb_Sliders; k++)
        {
            implicitFunctionParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            if(cndnotnull)
                ParisoConditionParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            xSupParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            ySupParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            zSupParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            xInfParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            yInfParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            zInfParser[i].AddConstant(SliderNames[k], SliderValues[k]);
        }
    }

    // Add defined functions :
    if(rgbtnotnull)
        for(int i=0; i<4; i++)
            for(uint j=0; j<FunctSize; j++)
            {
                RgbtParser[i].AddFunction(FunctNames[j], Fct[j]);
                RgbtParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
                RgbtParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
                RgbtParser[i].AddFunction("MarbleP",MarblePerlin, 4);
            }

    // Add defined functions :
    if(vrgbtnotnull)
    {
        for(uint j=0; j<FunctSize; j++)
        {
            GradientParser->AddFunction(FunctNames[j], Fct[j]);
            GradientParser->AddFunction("NoiseW",TurbulenceWorley, 6);
            GradientParser->AddFunction("NoiseP",TurbulencePerlin, 6);
            GradientParser->AddFunction("MarbleP",MarblePerlin, 4);
        }

        for(int i=0; i<4; i++)
            for(uint j=0; j<FunctSize; j++)
            {
                VRgbtParser[i].AddFunction(FunctNames[j], Fct[j]);
                VRgbtParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
                VRgbtParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
                VRgbtParser[i].AddFunction("MarbleP",MarblePerlin, 4);
            }
    }


    //delete NoiseFunction;
    //NoiseFunction = new CellNoise();

    for(uint i=0; i<componentsNumber; i++)
    {
        for(uint j=0; j<FunctSize; j++)
        {
            if((UsedFunct[i*FunctSize+j]=(ImplicitStructs[i].fxyz.find(FunctNames[j]) != std::string::npos)))
            {
                implicitFunctionParser[i].AddFunction(FunctNames[j], Fct[j]);
                ParisoConditionParser[i].AddFunction(FunctNames[j], Fct[j]);
            }
        }
        implicitFunctionParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
        implicitFunctionParser[i].AddFunction("fhelix1",fhelix1, 10);
        implicitFunctionParser[i].AddFunction("fhelix2",fhelix2, 10);
        implicitFunctionParser[i].AddFunction("f_hex_y",f_hex_y, 4);
        implicitFunctionParser[i].AddFunction("p_skeletal_int",p_skeletal_int, 3);
        implicitFunctionParser[i].AddFunction("fmesh",fmesh, 8);
        implicitFunctionParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
        implicitFunctionParser[i].AddFunction("MarbleP",MarblePerlin, 4);

    }
    NoiseParser->AddFunction("NoiseW",TurbulenceWorley, 6);
    NoiseParser->AddFunction("NoiseP",TurbulencePerlin, 6);
    NoiseParser->AddFunction("MarbleP",MarblePerlin, 4);

    return ParseExpression(varliste);
}

///+++++++++++++++++++++++++++++++++++++++++
ErrorMessage IsoMasterThread::ParseExpression(std::string VariableListe)
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint limitX = Xgrid, limitY = Ygrid, limitZ = Zgrid;

    if(AllComponentTraited)
    {
        stepMorph += pace;
    }

    vals[3]          = stepMorph;

    // Parse
    if(rgbtnotnull && RgbtSize == 4)
        for(uint i=0; i<RgbtSize; i++)
            if ((stdError.iErrorIndex = RgbtParser[i].Parse(Rgbts[i],"x,y,z,t,cmpId")) >= 0)
            {
                stdError.strError = Rgbts[i];
                return stdError;
            }

    // Parse
    if(vrgbtnotnull && (VRgbtSize % 5) ==0)
    {
        if ((stdError.iErrorIndex = GradientParser->Parse(Gradient,"x,y,z,t")) >= 0)
        {
            stdError.strError = Gradient;
            return stdError;
        }

        for(uint i=0; i<VRgbtSize; i++)
            if ((stdError.iErrorIndex = VRgbtParser[i].Parse(VRgbts[i],"x,y,z,t")) >= 0)
            {
                stdError.strError = VRgbts[i];
                return stdError;
            }
    }

    if(Noise != "")
        if ((stdError.iErrorIndex = NoiseParser->Parse(Noise,"x,y,z,t")) >= 0)
        {
            stdError.strError = Noise;
            return stdError;
        }

    for(uint i=0; i<componentsNumber; i++)
    {
        if ((stdError.iErrorIndex = implicitFunctionParser[i].Parse(ImplicitStructs[i].fxyz,VariableListe)) >= 0)
        {
            stdError.strError = ImplicitStructs[i].fxyz;
            return stdError;
        }
        if(cndnotnull)
        {
            if ((stdError.iErrorIndex = ParisoConditionParser[i].Parse(ImplicitStructs[i].cnd,"x,y,z,t")) >= 0)
            {
                stdError.strError = ImplicitStructs[i].cnd;
                return stdError;
            }
        }

        if ((stdError.iErrorIndex = xSupParser[i].Parse(ImplicitStructs[i].xmax, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].xmax;
            return stdError;
        }
        if ((stdError.iErrorIndex = ySupParser[i].Parse(ImplicitStructs[i].ymax, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].ymax;
            return stdError;
        }
        if ((stdError.iErrorIndex = zSupParser[i].Parse(ImplicitStructs[i].zmax, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].zmax;
            return stdError;
        }
        if ((stdError.iErrorIndex = xInfParser[i].Parse(ImplicitStructs[i].xmin, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].xmin;
            return stdError;
        }
        if ((stdError.iErrorIndex = yInfParser[i].Parse(ImplicitStructs[i].ymin, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].ymin;
            return stdError;
        }
        if ((stdError.iErrorIndex = zInfParser[i].Parse(ImplicitStructs[i].zmin, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].zmin;
            return stdError;
        }
    }

    for(uint IsoIndex=0; IsoIndex<componentsNumber; IsoIndex++)
    {
        if(gridnotnull)
        {
            limitX = limitY = limitZ = grid[IsoIndex];
        }
        xLocal2[IsoIndex*NbMaxGrid]=xSupParser[IsoIndex].Eval(vals);
        yLocal2[IsoIndex*NbMaxGrid]=ySupParser[IsoIndex].Eval(vals);
        zLocal2[IsoIndex*NbMaxGrid]=zSupParser[IsoIndex].Eval(vals);

        x_Step[IsoIndex] = (xLocal2[IsoIndex*NbMaxGrid] - xInfParser[IsoIndex].Eval(vals))/(limitX-1);
        y_Step[IsoIndex] = (yLocal2[IsoIndex*NbMaxGrid] - yInfParser[IsoIndex].Eval(vals))/(limitY-1);
        z_Step[IsoIndex] = (zLocal2[IsoIndex*NbMaxGrid] - zInfParser[IsoIndex].Eval(vals))/(limitZ-1);

        for (uint i= 1; i < limitX; i++) xLocal2[IsoIndex*NbMaxGrid+i] = xLocal2[IsoIndex*NbMaxGrid+i-1] - x_Step[IsoIndex];
        for (uint j= 1; j < limitY; j++) yLocal2[IsoIndex*NbMaxGrid+j] = yLocal2[IsoIndex*NbMaxGrid+j-1] - y_Step[IsoIndex];
        for (uint k= 1; k < limitZ; k++) zLocal2[IsoIndex*NbMaxGrid+k] = zLocal2[IsoIndex*NbMaxGrid+k-1] - z_Step[IsoIndex];
    }
    return stdError;
}

///+++++++++++++++++++++++++++++++++++++++++
void IsoMasterThread::DeleteMasterParsers()
{
    if(ParsersAllocated)
    {
        delete[] implicitFunctionParser;
        delete[] xSupParser;
        delete[] ySupParser;
        delete[] zSupParser;
        delete[] xInfParser;
        delete[] yInfParser;
        delete[] zInfParser;
        delete[] Fct;
        delete[] UsedFunct;
        delete[] UsedFunct2;
        delete[] ParisoConditionParser;
        delete[] VRgbtParser;
        delete[] RgbtParser;
        delete GradientParser;
        delete NoiseParser;
        ParsersAllocated = false;
    }

    ImplicitStructs.clear();
    xLocal2.clear();
    yLocal2.clear();
    zLocal2.clear();
    x_Step.clear();
    y_Step.clear();
    z_Step.clear();
    SliderValues.clear();
    SliderNames.clear();
    Consts.clear();
    ConstNames.clear();
    ConstValues.clear();

    Rgbts.clear();
    RgbtNames.clear();

    VRgbts.clear();
    VRgbtNames.clear();

    Functs.clear();
    FunctNames.clear();
}

///+++++++++++++++++++++++++++++++++++++++++
void IsoWorkerThread::DeleteWorkerParsers()
{
    if(ParsersAllocated)
    {
        delete[] implicitFunctionParser;
        delete[] Fct;
        ParsersAllocated = false;
    }
}

///+++++++++++++++++++++++++++++++++++++++++
void IsoMasterThread::InitMasterParsers()
{
    for(uint i=0; i<componentsNumber; i++)
    {
        implicitFunctionParser[i].AddConstant("pi", PI);
        ParisoConditionParser[i].AddConstant("pi", PI);
        xSupParser[i].AddConstant("pi", PI);
        ySupParser[i].AddConstant("pi", PI);
        zSupParser[i].AddConstant("pi", PI);
        xInfParser[i].AddConstant("pi", PI);
        yInfParser[i].AddConstant("pi", PI);
        zInfParser[i].AddConstant("pi", PI);
    }
    NoiseParser->AddConstant("pi", PI);
    NoiseParser->AddConstant("Lacunarity", Lacunarity);
    NoiseParser->AddConstant("Gain", Gain);
    NoiseParser->AddConstant("Octaves", Octaves);

    for(uint i=0; i<FunctSize; i++)
    {
        Fct[i].AddConstant("pi", PI);
        Fct[i].AddFunction("CmpId",CurrentIsoCmpId, 1);
        Fct[i].AddFunction("NoiseW",TurbulenceWorley, 6);
        Fct[i].AddFunction("fhelix1",fhelix1, 10);
        Fct[i].AddFunction("fhelix2",fhelix2, 10);
        Fct[i].AddFunction("f_hex_y",f_hex_y, 4);
        Fct[i].AddFunction("p_skeletal_int",p_skeletal_int, 3);
        Fct[i].AddFunction("fmesh",fmesh, 8);
        Fct[i].AddFunction("NoiseP",TurbulencePerlin, 6);
        Fct[i].AddFunction("MarbleP",MarblePerlin, 4);
    }

    for(uint i=0; i< RgbtSize; i++)
    {
        RgbtParser[i].AddConstant("pi", PI);
        RgbtParser[i].AddConstant("Lacunarity", Lacunarity);
        RgbtParser[i].AddConstant("Gain", Gain);
        RgbtParser[i].AddConstant("Octaves", Octaves);
        RgbtParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
        RgbtParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
        RgbtParser[i].AddFunction("MarbleP",MarblePerlin, 4);
    }

    for(uint i=0; i<VRgbtSize; i++)
    {
        VRgbtParser[i].AddConstant("pi", PI);
        VRgbtParser[i].AddConstant("Lacunarity", Lacunarity);
        VRgbtParser[i].AddConstant("Gain", Gain);
        VRgbtParser[i].AddConstant("Octaves", Octaves);
        VRgbtParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
        VRgbtParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
        VRgbtParser[i].AddFunction("MarbleP",MarblePerlin, 4);
    }

    GradientParser->AddConstant("pi", PI);
    GradientParser->AddConstant("Lacunarity", Lacunarity);
    GradientParser->AddConstant("Gain", Gain);
    GradientParser->AddConstant("Octaves", Octaves);
    GradientParser->AddFunction("NoiseW",TurbulenceWorley, 6);
    GradientParser->AddFunction("NoiseP",TurbulencePerlin, 6);
    GradientParser->AddFunction("MarbleP",MarblePerlin, 4);
}

///+++++++++++++++++++++++++++++++++++++++++
void IsoMasterThread::AllocateMasterParsers()
{
    if(!ParsersAllocated)
    {
        implicitFunctionParser = new FunctionParser[componentsNumber];
        xSupParser = new FunctionParser[componentsNumber];
        ySupParser = new FunctionParser[componentsNumber];
        zSupParser = new FunctionParser[componentsNumber];
        xInfParser = new FunctionParser[componentsNumber];
        yInfParser = new FunctionParser[componentsNumber];
        zInfParser = new FunctionParser[componentsNumber];
        ParisoConditionParser = new FunctionParser[componentsNumber];
        ImplicitStructs.resize(componentsNumber);
        xLocal2.resize(NbMaxGrid*componentsNumber);
        yLocal2.resize(NbMaxGrid*componentsNumber);
        zLocal2.resize(NbMaxGrid*componentsNumber);
        x_Step.resize(componentsNumber);
        y_Step.resize(componentsNumber);
        z_Step.resize(componentsNumber);

        if(!functnotnull)
            FunctSize = 0;
         Fct          = new FunctionParser[FunctSize];
         UsedFunct    = new bool[4*componentsNumber*FunctSize];
         UsedFunct2   = new bool[FunctSize*FunctSize];

        rgbtnotnull ?
            RgbtParser = new FunctionParser[(RgbtSize = 4)] :
            RgbtParser = new FunctionParser[(RgbtSize = 0)];


        vrgbtnotnull ?
            VRgbtParser = new FunctionParser[VRgbtSize] :
            VRgbtParser = new FunctionParser[(VRgbtSize = 0)];

        if(constnotnull)
            ConstSize=0;

        GradientParser = new FunctionParser;
        NoiseParser = new FunctionParser;
        ParsersAllocated = true;
    }
}

///+++++++++++++++++++++++++++++++++++++++++
void IsoWorkerThread::AllocateParsersForWorkerThread(uint nbcomp, uint nbfunct)
{
    if(!ParsersAllocated)
    {
        implicitFunctionParser = new FunctionParser[nbcomp];
        Fct = new FunctionParser[nbfunct];
        ParsersAllocated = true;
    }
}

///+++++++++++++++++++++++++++++++++++++++++
void IsoMasterThread::initparser()
{
    DeleteMasterParsers();
    AllocateMasterParsers();
    InitMasterParsers();
}

///+++++++++++++++++++++++++++++++++++++++++
void IsoWorkerThread::IsoCompute(uint fctnb)
{
    (fctnb == 0) ? AllComponentTraited = true : AllComponentTraited = false;
    VoxelEvaluation(fctnb);
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::stopcalculations(bool calculation)
{
    StopCalculations = calculation;
    masterthread->StopCalculations = calculation;
    for(uint nbthreads=0; nbthreads+1< WorkerThreadsNumber; nbthreads++)
        workerthreads[nbthreads].StopCalculations = StopCalculations;
}

//+++++++++++++++++++++++++++++++++++++++++
void Iso3D::copycomponent(struct ComponentInfos* copy, struct ComponentInfos* origin)
{
    copy->ParisoTriangle = origin->ParisoTriangle;
    copy->ParisoVertex          = origin->ParisoVertex;
    copy->NbComponents    = origin->NbComponents;

    copy->ParisoCurrentComponentIndex = origin->ParisoCurrentComponentIndex;
    copy->ParisoNbComponents          = origin->ParisoNbComponents;
    copy->Interleave                  = origin->Interleave;
    copy->pariso                      = origin->pariso;
    copy->updateviewer                = origin->updateviewer;

    copy->ThereisCND                  = origin->ThereisCND;
    copy->ThereisRGBA                 = origin->ThereisRGBA;
    copy->NbTrianglesVerifyCND        = origin->NbTrianglesVerifyCND;
    copy->NbTrianglesNotVerifyCND     = origin->NbTrianglesNotVerifyCND;
    copy->NbTrianglesBorderCND        = origin->NbTrianglesBorderCND;

    for(int i=0; i<2; i++)
    {
        copy->NoiseParam[i]  = origin->NoiseParam[i];
    }
}

//+++++++++++++++++++++++++++++++++++++++++
void Iso3D::clear(struct ComponentInfos* cp)
{
    cp->ParisoTriangle.clear();
    cp->ParisoVertex.clear();
    cp->NbComponents.clear();
    cp->ThereisCND.clear();
    cp->ThereisRGBA.clear();

    cp->NbTrianglesVerifyCND.clear();
    cp->NbTrianglesNotVerifyCND.clear();
    cp->NbTrianglesBorderCND.clear();

    cp->ParisoCurrentComponentIndex = 0;
    cp->ParisoNbComponents          = 0;
    cp->Interleave                  = true;
    cp->pariso                      = false;
    cp->updateviewer                = false;
}

//+++++++++++++++++++++++++++++++++++++++++
void Iso3D::IsoBuild (
    float **NormVertexTabVectorPt,
    uint **IndexPolyTabPt,
    unsigned   int *PolyNumber,
    uint *VertexNumberpt,
    uint **IndexPolyTabMinPt,
    unsigned  int *VertxNumber,
    struct ComponentInfos * componentsPt
)
{
    uint NbTriangleIsoSurfaceTmp, PreviousGridVal=Xgrid;
    NbPointIsoMap= 0;
    NbVertexTmp = NbTriangleIsoSurfaceTmp = 0;
    componentsPt->updateviewer= false;
    clear(components);
    if(componentsPt->pariso && componentsPt->ParisoCurrentComponentIndex>0)
    {
        NbVertexTmp = uint(NormVertexTabVector.size()/10);
        NbTriangleIsoSurfaceTmp = uint(IndexPolyTabVector.size()/3);
        copycomponent(components, componentsPt);
    }
    else
    {
        if(componentsPt->pariso)
        {
            components->pariso = true;
            components->ParisoCurrentComponentIndex = componentsPt->ParisoCurrentComponentIndex;
            components->ParisoNbComponents = componentsPt->ParisoNbComponents;
        }
        NormVertexTabVector.clear();
        NormVertexTabVector.shrink_to_fit();
        IndexPolyTabVector.clear();
        IndexPolyTabVector.shrink_to_fit();
        IndexPolyTabMinVector.clear();
        IndexPolyTabMinVector.shrink_to_fit();
    }
    NormOriginaltmpVector.clear();
    NormOriginaltmpVector.shrink_to_fit();

    //*****//
    uint maxx = std::max(std::max(std::max(Xgrid, Ygrid), Zgrid), masterthread->maximumgrid);
    if(masterthread->gridnotnull)
        for(uint fctnb= 0; fctnb< masterthread->componentsNumber; fctnb++)
            maxx = std::max(maxx, masterthread->grid[fctnb]);

    masterthread->maximumgrid = maxx;
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        workerthreads[nbthreads].maximumgrid = masterthread->maximumgrid;
    }

    if(GridVoxelVarPt != nullptr)
        delete[] GridVoxelVarPt;
    GridVoxelVarPt = new Voxel[maxx*maxx*maxx];
    if(Results != nullptr)
        delete[] Results;
    Results = new double[maxx*maxx*maxx];

    components->NbComponents.push_back(masterthread->componentsNumber);

    stopcalculations(false);

    if(masterthread->activeMorph != 1)
    {
        times.restart();
    }

    // generate Isosurface for all the implicit formulas
    for(uint fctnb= 0; fctnb< masterthread->componentsNumber; fctnb++)
    {
        if(masterthread->activeMorph != 1)
        {
            message = QString("1) Cmp:"+QString::number(fctnb+1)+"/"+QString::number(masterthread->componentsNumber)+"==> Math calculation");
            emitUpdateMessageSignal();
        }

        if(masterthread->gridnotnull)
            Setgrid(masterthread->grid[fctnb]);

        IsoComponentId = fctnb;
        masterthread->CurrentComponent = fctnb;
        for(uint nbthreads=0; nbthreads+1 < WorkerThreadsNumber; nbthreads++)
            workerthreads[nbthreads].CurrentComponent = fctnb;

        for(uint nbthreads=0; nbthreads+1 < WorkerThreadsNumber; nbthreads++)
            workerthreads[nbthreads].stepMorph = masterthread->stepMorph;

        if(masterthread->activeMorph == 1)
        {
            if(fctnb == 0)
            {
                //This code is to ensure that stepmorph values are the same accross all threads because tests show that
                //it's not allways the case when this code is spread inside threads Run() functions!
                masterthread->stepMorph += masterthread->pace;
                for(uint nbthreads=0; nbthreads+1 < WorkerThreadsNumber; nbthreads++)
                    workerthreads[nbthreads].stepMorph = masterthread->stepMorph;
            }
            // Recalculate some tables values:
            ReinitVarTablesWhenMorphActiv(fctnb);
        }

        masterthread->start();
        for(uint nbthreads=0; nbthreads+1 < WorkerThreadsNumber; nbthreads++)
            workerthreads[nbthreads].start();

        masterthread->wait();
        for(uint nbthreads=0; nbthreads+1 < WorkerThreadsNumber; nbthreads++)
            workerthreads[nbthreads].wait();

        bool Stop = masterthread->StopCalculations;
        for(uint nbthreads=0; nbthreads+1 < WorkerThreadsNumber; nbthreads++)
            Stop = Stop || workerthreads[nbthreads].StopCalculations;

        if(StopCalculations || Stop)
        {
            Setgrid(PreviousGridVal);
            delete[] GridVoxelVarPt;
            GridVoxelVarPt = nullptr;
            delete[] Results;
            Results = nullptr;
            return;
        }

        if(masterthread->activeMorph != 1)
        {
            message += QString(" ==> Mesh generation");
            emitUpdateMessageSignal();
        }

        uint result = PointEdgeComputation(fctnb);
        if(result == 0)
        {
            messageerror = VERTEX_TAB_MEM_OVERFLOW;
            emitErrorSignal();
            return;
        }

        SignatureComputation();

        result = ConstructIsoSurface();
        if(result == 0)
        {
            messageerror = TRIANGLES_TAB_MEM_OVERFLOW;
            emitErrorSignal();
            return;
        }

        ConstructIsoNormale(NbTriangleIsoSurfaceTmp);
        SaveIsoGLMap(NbTriangleIsoSurfaceTmp);
        NormOriginaltmpVector.clear();
        result = SetMiniMmeshStruct();
        if(result == 0)
        {
            messageerror = MINPOLY_TAB_MEM_OVERFLOW;
            emitErrorSignal();
            return;
        }

        // Save the Index:
        components->ParisoTriangle.push_back(3*NbTriangleIsoSurfaceTmp); //save the starting position of this component
        components->ParisoTriangle.push_back(NbTriangleIsoSurface);      //save the number of triangles of this component
        components->ParisoVertex.push_back(NbVertexTmp);
        components->ParisoVertex.push_back(NbVertexTmp + NbPointIsoMap -1);

        // Save Number of Polys and vertex :
        NbVertexTmp               += NbPointIsoMap;
        NbTriangleIsoSurfaceTmp   += NbTriangleIsoSurface;
    }



    delete[] GridVoxelVarPt;
    GridVoxelVarPt = nullptr;
    delete[] Results;
    Results = nullptr;
    if(masterthread->activeMorph != 1)
    {
        message = QString("2) Mesh Processing");
        emitUpdateMessageSignal();
    }

    //CND calculation for the triangles results:
    uint result = CNDCalculation(NbTriangleIsoSurfaceTmp, components);
    if(result == 0)
    {
        messageerror = CND_TAB_MEM_OVERFLOW;
        emitErrorSignal();
        return;
    }
    else if(result == 2)
    {
        messageerror = CND_POL_MEM_OVERFLOW;
        emitErrorSignal();
        return;
    }

    // Pigment, Texture and Noise :
    if(masterthread->vrgbtnotnull)
    {
        components->ThereisRGBA.push_back(true);
        components->NoiseParam[1].NoiseType = 0; //Pigments
        components->NoiseParam[1].VRgbtParser = masterthread->VRgbtParser;
        components->NoiseParam[1].GradientParser = masterthread->GradientParser;
        components->NoiseParam[1].NoiseParser =  masterthread->NoiseParser;
        components->NoiseParam[1].Nb_vrgbts = masterthread->VRgbtSize;
    }
    else if(masterthread->RgbtSize >= 4)
    {
        components->ThereisRGBA.push_back(true);
        components->NoiseParam[1].NoiseType = 1; //Texture
        components->NoiseParam[1].RgbtParser = masterthread->RgbtParser;
        components->NoiseParam[1].NoiseParser =  masterthread->NoiseParser;
    }
    else
    {
        components->ThereisRGBA.push_back(false);
        components->NoiseParam[1].NoiseType = -1; //No Pigments or texture
    }

    if(masterthread->Noise == "")
        components->NoiseParam[1].NoiseShape = 0;
    else
        components->NoiseParam[1].NoiseShape = 1;

    CalculateColorsPoints(components, components->ThereisRGBA.size()-1);
    *PolyNumber      = uint(IndexPolyTabVector.size());
    *VertexNumberpt  = uint(NormVertexTabVector.size()/10);
    *VertxNumber     = uint(IndexPolyTabMinVector.size());

    if(masterthread->activeMorph != 1)
    {
        message = QString("Thr:"+QString::number(WorkerThreadsNumber)+"; Cmp:"+QString::number(masterthread->componentsNumber)+"; T="+QString::number(times.elapsed()/1000.0)+"s");
        emitUpdateMessageSignal();
    }

    *NormVertexTabVectorPt = NormVertexTabVector.data();
    *IndexPolyTabPt = IndexPolyTabVector.data();
    *IndexPolyTabMinPt = IndexPolyTabMinVector.data();
    copycomponent(componentsPt, components);
    componentsPt->Interleave = true;
    componentsPt->ParisoCurrentComponentIndex += 1;
    if(componentsPt->ParisoCurrentComponentIndex == componentsPt->ParisoNbComponents)
        componentsPt->ParisoCurrentComponentIndex =0;
    Setgrid(PreviousGridVal);
    componentsPt->updateviewer = true;
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::Setgrid(uint NewGridVal)
{
    if(masterthread->gridnotnull)
    {
        masterthread->Zgrid  =
            masterthread->Ygrid  =
                masterthread->Xgrid  = NewGridVal;
        for(uint th=0; th+1 < WorkerThreadsNumber; th++)
            workerthreads[th].Xgrid =
            workerthreads[th].Ygrid =
            workerthreads[th].Zgrid = NewGridVal;

        Zgrid  =
            Ygrid  =
                Xgrid  = NewGridVal;
    }
}
///+++++++++++++++++++++++++++++++++++++++++
uint Iso3D::CNDtoUse(uint index, struct ComponentInfos* components)
{
    uint idx=0;
    for(uint i=0; i < components->NbComponents.size()-1; i++)
        idx+=components->NbComponents[i];
    for(uint fctnb= 0; fctnb < (masterthread->componentsNumber); fctnb++)
        if( index <= components->ParisoVertex[2*(fctnb+idx) +1] && index >= components->ParisoVertex[2*(fctnb+idx)])
            return fctnb;
    return 30;
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::CalculateColorsPoints(struct ComponentInfos* comp, uint index)
{
    uint cmpId=0, K=0;
    double tmp,
            *ValCol,
            val[10];
    ValCol = new double[masterthread->VRgbtSize+5];
    val[3] = masterthread->stepMorph;

    if(comp->ThereisRGBA[index] == true &&  comp->NoiseParam[1].NoiseType == 0)
    {
        for(uint i=0; i<masterthread->VRgbtSize; i++)
        {
            ValCol[i] = masterthread->VRgbtParser[i].Eval(val);
        }

        uint idx=0;
        for(uint i=0; i < comp->NbComponents.size()-1; i++)
            idx+=comp->NbComponents[i];
        for(uint i= comp->ParisoVertex[2*idx]; i < NbVertexTmp; i++)
        {
            val[0]= double(NormVertexTabVector[i*10  + 3 + 4 ]);
            val[1]= double(NormVertexTabVector[i*10  + 4 + 4 ]);
            val[2]= double(NormVertexTabVector[i*10  + 5 + 4 ]);

            if(masterthread->Noise != "")
                tmp  = masterthread->NoiseParser->Eval(val);
            else
                tmp =1.0;

            val[0]= tmp*double(NormVertexTabVector[i*10  + 3 + 4 ]);
            val[1]= tmp*double(NormVertexTabVector[i*10  + 4 + 4 ]);
            val[2]= tmp*double(NormVertexTabVector[i*10  + 5 + 4 ]);

            tmp  = masterthread->GradientParser->Eval(val);

            int c= int(tmp);
            tmp = std::abs(tmp - double(c));
            for (uint j=0; j < masterthread->VRgbtSize; j+=5)
                if(tmp <= ValCol[j])
                {
                    NormVertexTabVector[i*10  ] = float(ValCol[j+1]);
                    NormVertexTabVector[i*10+1] = float(ValCol[j+2]);
                    NormVertexTabVector[i*10+2] = float(ValCol[j+3]);
                    NormVertexTabVector[i*10+3] = float(ValCol[j+4]);
                    j = masterthread->VRgbtSize;
                }
        }
    }
    else if(comp->ThereisRGBA[index] == true &&  comp->NoiseParam[1].NoiseType == 1)
    {
        uint idx=0;
        for(uint i=0; i < comp->NbComponents.size()-1; i++)
            idx+=comp->NbComponents[i];
        for(uint i= comp->ParisoVertex[2*idx]; i < NbVertexTmp; i++)
        {
                if((i >= uint(comp->ParisoVertex[2*(cmpId+idx)])))
                {
                    K = cmpId;
                    if((masterthread->componentsNumber-1)>cmpId)
                    {
                        cmpId++;
                    }
                }

            val[0]= double(NormVertexTabVector[i*10 + 7]);
            val[1]= double(NormVertexTabVector[i*10 + 8]);
            val[2]= double(NormVertexTabVector[i*10 + 9]);
            val[4]= double(K);
            if(masterthread->Noise != "")
                tmp  = masterthread->NoiseParser->Eval(val);
            else
                tmp =1.0;

            val[0]= tmp*double(NormVertexTabVector[i*10+7]);
            val[1]= tmp*double(NormVertexTabVector[i*10+8]);
            val[2]= tmp*double(NormVertexTabVector[i*10+9]);

            NormVertexTabVector[i*10  ] = float(masterthread->RgbtParser[0].Eval(val));
            NormVertexTabVector[i*10+1] = float(masterthread->RgbtParser[1].Eval(val));
            NormVertexTabVector[i*10+2] = float(masterthread->RgbtParser[2].Eval(val));
            NormVertexTabVector[i*10+3] = float(masterthread->RgbtParser[3].Eval(val));
        }
    }
    delete[] ValCol;
}

///+++++++++++++++++++++++++++++++++++++++++

uint Iso3D::CNDCalculation(uint & NbTriangleIsoSurfaceTmp, struct ComponentInfos *comp)
{
    uint idx=0;
    for(uint i=0; i < comp->NbComponents.size()-1; i++)
        idx+=comp->NbComponents[i];
    uint startpoint=comp->ParisoVertex[2*idx];
    if (masterthread->ParisoCondition == 1)
    {
        double vals[4];
        std::vector<int> PointVerifyCond;
        vals[3] = masterthread->stepMorph;

        for(uint i= startpoint; i < NbVertexTmp; i++)
        {
            vals[0] = double(NormVertexTabVector[i*10+7]);
            vals[1] = double(NormVertexTabVector[i*10+8]);
            vals[2] = double(NormVertexTabVector[i*10+9]);
            PointVerifyCond.push_back(int(masterthread->ParisoConditionParser[CNDtoUse(i, comp)].Eval(vals)));
            if(PointVerifyCond[i-startpoint])
            {
                NormVertexTabVector[i*10  ] = 0.1f;
                NormVertexTabVector[i*10+1] = 0.9f;
                NormVertexTabVector[i*10+2] = 0.0;
                NormVertexTabVector[i*10+3] = 1.0;
            }
            else
            {
                NormVertexTabVector[i*10  ] = 0.9f;
                NormVertexTabVector[i*10+1] = 0.1f;
                NormVertexTabVector[i*10+2] = 0.9;
                NormVertexTabVector[i*10+3] = 1.0;
            }
        }
        uint Aindex, Bindex, Cindex;
        uint nbtriangle = NbTriangleIsoSurfaceTmp;
        //uint starttri = uint(comp->ParIsoPositions[0]/3);
        uint idx=0;
        for(uint id=0; id < comp->NbComponents.size()-1; id++)
            idx+=comp->NbComponents[id];
        uint starttri = uint(comp->ParisoTriangle[2*idx]/3);

        std::vector<int> TypeIsoSurfaceTriangleListeCNDVector (NbTriangleIsoSurfaceTmp-starttri, 1);

        for(uint i= starttri; i < nbtriangle; i++)
        {
            Aindex = IndexPolyTabVector[3*i    ];
            Bindex = IndexPolyTabVector[3*i + 1];
            Cindex = IndexPolyTabVector[3*i + 2];

            int TypeTriangle = -1;
            if(PointVerifyCond[Aindex-startpoint] && !PointVerifyCond[Bindex-startpoint] && !PointVerifyCond[Cindex-startpoint])
                TypeTriangle = 0;
            else if(!PointVerifyCond[Aindex-startpoint] && PointVerifyCond[Bindex-startpoint] && PointVerifyCond[Cindex-startpoint])
                TypeTriangle = 1;
            else if(!PointVerifyCond[Aindex-startpoint] && PointVerifyCond[Bindex-startpoint] && !PointVerifyCond[Cindex-startpoint])
                TypeTriangle = 2;
            else if(PointVerifyCond[Aindex-startpoint] && !PointVerifyCond[Bindex-startpoint] && PointVerifyCond[Cindex-startpoint])
                TypeTriangle = 3;
            else if(!PointVerifyCond[Aindex-startpoint] && !PointVerifyCond[Bindex-startpoint] && PointVerifyCond[Cindex-startpoint])
                TypeTriangle = 4;
            else if(PointVerifyCond[Aindex-startpoint] && PointVerifyCond[Bindex-startpoint] && !PointVerifyCond[Cindex-startpoint])
                TypeTriangle = 5;
            else if(!PointVerifyCond[Aindex-startpoint] && !PointVerifyCond[Bindex-startpoint] && !PointVerifyCond[Cindex-startpoint])
            {
                TypeTriangle = 6;
                TypeIsoSurfaceTriangleListeCNDVector[i-starttri] = -1;
            }
            else if(PointVerifyCond[Aindex-startpoint] && PointVerifyCond[Bindex-startpoint] && PointVerifyCond[Cindex-startpoint])
            {
                TypeTriangle = 7;
                TypeIsoSurfaceTriangleListeCNDVector[i-starttri] = 1;
            }

            if(TypeTriangle == 2 || TypeTriangle == 3)
            {
                Aindex = IndexPolyTabVector[3*i+1];
                Bindex = IndexPolyTabVector[3*i+2];
                Cindex = IndexPolyTabVector[3*i  ];
            }
            else if(TypeTriangle == 4 || TypeTriangle == 5)
            {
                Aindex = IndexPolyTabVector[3*i+2];
                Bindex = IndexPolyTabVector[3*i  ];
                Cindex = IndexPolyTabVector[3*i+1];
            }

            double Bprime[4], Cprime[4], DiffX, DiffY, DiffZ;
            int Alfa;
            uint cnd = CNDtoUse(Aindex, comp);
            if(TypeTriangle >=0 && TypeTriangle <= 5)
            {
                /// Bprime
                Bprime[0] = double(NormVertexTabVector[10*Aindex+7]);
                Bprime[1] = double(NormVertexTabVector[10*Aindex+8]);
                Bprime[2] = double(NormVertexTabVector[10*Aindex+9]);
                Bprime[3] = masterthread->stepMorph;

                DiffX = double(NormVertexTabVector[10*Bindex+7] - NormVertexTabVector[3+10*Aindex  + 4])/20.0;
                DiffY = double(NormVertexTabVector[10*Bindex+8] - NormVertexTabVector[3+10*Aindex+1+ 4])/20.0;
                DiffZ = double(NormVertexTabVector[10*Bindex+9] - NormVertexTabVector[3+10*Aindex+2+ 4])/20.0;
                Alfa = 0;
                if(TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4)
                {
                    while(masterthread->ParisoConditionParser[cnd].Eval(Bprime) == 1.0 && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!(masterthread->ParisoConditionParser[cnd].Eval(Bprime) == 1.0) && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }

                /// Cprime
                Cprime[0] = double(NormVertexTabVector[10*Aindex+7]);
                Cprime[1] = double(NormVertexTabVector[10*Aindex+8]);
                Cprime[2] = double(NormVertexTabVector[10*Aindex+9]);
                Cprime[3] = masterthread->stepMorph;

                DiffX = double(NormVertexTabVector[3+10*Cindex  + 4] - NormVertexTabVector[3+10*Aindex  + 4])/20;
                DiffY = double(NormVertexTabVector[3+10*Cindex+1+ 4] - NormVertexTabVector[3+10*Aindex+1+ 4])/20;
                DiffZ = double(NormVertexTabVector[3+10*Cindex+2+ 4] - NormVertexTabVector[3+10*Aindex+2+ 4])/20;
                Alfa = 0;
                if(TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4)
                {
                    while(masterthread->ParisoConditionParser[cnd].Eval(Cprime) == 1.0 && (Alfa < 20))
                    {
                        Cprime[0] += DiffX;
                        Cprime[1] += DiffY;
                        Cprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!(masterthread->ParisoConditionParser[cnd].Eval(Cprime) == 1.0) && (Alfa < 20))
                    {
                        Cprime[0] += DiffX;
                        Cprime[1] += DiffY;
                        Cprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }

                //***********
                //Add points:
                //***********
                //Add Bprime:
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(NormVertexTabVector[10*Bindex + 4]);
                NormVertexTabVector.push_back(NormVertexTabVector[10*Bindex + 5]);
                NormVertexTabVector.push_back(NormVertexTabVector[10*Bindex + 6]);
                NormVertexTabVector.push_back(float(Bprime[0]));
                NormVertexTabVector.push_back(float(Bprime[1]));
                NormVertexTabVector.push_back(float(Bprime[2]));

                //Add Cprime:
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(NormVertexTabVector[10*Cindex + 4]);
                NormVertexTabVector.push_back(NormVertexTabVector[10*Cindex + 5]);
                NormVertexTabVector.push_back(NormVertexTabVector[10*Cindex + 6]);
                NormVertexTabVector.push_back(float(Cprime[0]));
                NormVertexTabVector.push_back(float(Cprime[1]));
                NormVertexTabVector.push_back(float(Cprime[2]));

                NbVertexTmp += 2;

                //***********
                //Add triangles:
                //***********
                /// Add Three new triangles :
                uint IndexBprime = (NbVertexTmp-2);
                uint IndexCprime = (NbVertexTmp-1);

                // The original triangle will be replaced by four other triangles:
                TypeIsoSurfaceTriangleListeCNDVector[i-starttri]=0;

                /// (A, Bprime, Cprime)
                IndexPolyTabVector.push_back(Aindex);
                IndexPolyTabVector.push_back(IndexBprime);
                IndexPolyTabVector.push_back(IndexCprime);

                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCNDVector.push_back(1) : TypeIsoSurfaceTriangleListeCNDVector.push_back(-1);
                NbTriangleIsoSurfaceTmp++;
                IndexPolyTabMinVector.push_back(3);
                IndexPolyTabMinVector.push_back(Aindex);
                IndexPolyTabMinVector.push_back(IndexBprime);
                IndexPolyTabMinVector.push_back(IndexCprime);

                /// (Bprime, B, C)
                IndexPolyTabVector.push_back(IndexBprime);
                IndexPolyTabVector.push_back(Bindex);
                IndexPolyTabVector.push_back(Cindex);

                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCNDVector.push_back(-1) : TypeIsoSurfaceTriangleListeCNDVector.push_back(1);
                NbTriangleIsoSurfaceTmp++;
                IndexPolyTabMinVector.push_back(3);
                IndexPolyTabMinVector.push_back(IndexBprime);
                IndexPolyTabMinVector.push_back(Bindex);
                IndexPolyTabMinVector.push_back(Cindex);

                /// (Bprime, C, Cprime)
                IndexPolyTabVector.push_back(IndexBprime);
                IndexPolyTabVector.push_back(Cindex);
                IndexPolyTabVector.push_back(IndexCprime);

                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCNDVector.push_back(-1) : TypeIsoSurfaceTriangleListeCNDVector.push_back(1);
                NbTriangleIsoSurfaceTmp++;
                IndexPolyTabMinVector.push_back(3);
                IndexPolyTabMinVector.push_back(IndexBprime);
                IndexPolyTabMinVector.push_back(Cindex);
                IndexPolyTabMinVector.push_back(IndexCprime);

                /// (Bprime, Cprime) --> the border
                IndexPolyTabVector.push_back(IndexBprime);
                IndexPolyTabVector.push_back(IndexCprime);
                IndexPolyTabVector.push_back(IndexCprime);

                TypeIsoSurfaceTriangleListeCNDVector.push_back(4); /// Type = 4-->Border
                NbTriangleIsoSurfaceTmp++;
                IndexPolyTabMinVector.push_back(3);
                IndexPolyTabMinVector.push_back(IndexBprime);
                IndexPolyTabMinVector.push_back(IndexCprime);
                IndexPolyTabMinVector.push_back(IndexCprime);
            }
        }

        //***********
        //Reorganize the triangles index:
        //***********
        std::vector<uint>NewIndexPolyTabVector;
        uint k, l, M;
        k = l = M =0;

        // In case we have a ParIso object, this will save the triangle arrangement for the parametric CND
        for(uint i=0; i<starttri; i++)
        {
            NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i  ]);
            NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+1]);
            NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+2]);
        }

        // Now we start sorting the triangles list. We have 3 cases
        for(uint i=starttri; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCNDVector[i-starttri] == 1)
            {
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i  ]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+1]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+2]);
                k++;
            }

        for(uint i=starttri; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCNDVector[i-starttri] == -1)
            {
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i  ]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+1]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+2]);
                l++;
            }

        for(uint i=starttri; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCNDVector[i-starttri] == 4)
            {
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i  ]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+1]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+2]);
                M++;
            }

        //Copy the new index in the original one:
        IndexPolyTabVector.clear();
        NewIndexPolyTabVector.shrink_to_fit();
        IndexPolyTabVector = NewIndexPolyTabVector;
        NewIndexPolyTabVector.clear();
        NewIndexPolyTabVector.shrink_to_fit();

        NbTriangleIsoSurfaceTmp = M + l + k;

        comp->NbTrianglesVerifyCND.push_back(k);
        comp->NbTrianglesNotVerifyCND.push_back(l);
        comp->NbTrianglesBorderCND.push_back(M);
        comp->ThereisCND.push_back(true);

        PointVerifyCond.clear();
        PointVerifyCond.shrink_to_fit();
        TypeIsoSurfaceTriangleListeCNDVector.clear();
        TypeIsoSurfaceTriangleListeCNDVector.shrink_to_fit();
    }
    else
    {
        comp->NbTrianglesVerifyCND.push_back(0);
        comp->NbTrianglesNotVerifyCND.push_back(0);
        comp->NbTrianglesBorderCND.push_back(0);
        comp->ThereisCND.push_back(false);
        for(uint i= startpoint; i < NbVertexTmp; i++)
        {
            NormVertexTabVector[i*10  ] = 0.5f;
            NormVertexTabVector[i*10+1] = 0.6f;
            NormVertexTabVector[i*10+2] = 0.8f;
            NormVertexTabVector[i*10+3] = 1.0;
        }
    }

    return 1;
}


///+++++++++++++++++++++++++++++++++++++++++
Iso3D::~Iso3D()
{
}

///++++++++++++++++++++ ConstructIsoSurface +++++++++++++++++++++++++++
uint Iso3D::SetMiniMmeshStruct()
{
    uint I, J, IJK, i, j, k, Index, lnew, iter, nbpl, iterpl;
    uint maxgrscalemaxgr = masterthread->maximumgrid*masterthread->maximumgrid;

    lnew = 0;
    NbPolyMin = 0;
    /// Copy Index Polygons :
    for(i=0; i+1 < Xgrid; i++)
    {
        I  = i*maxgrscalemaxgr;
        for(j=0; j+1 < Ygrid; j++)
        {
            J  = I+j*masterthread->maximumgrid;
            for(k=0; k+1 < Zgrid; k++)
            {
                IJK = J+k;
                Index = GridVoxelVarPt[IJK].Signature;
                nbpl = triTable_min[Index][16];

                if( nbpl == 1)
                {
                    NbPolyMin += nbpl;
                    //if((PreviousSizeMinimalTopology + lnew +1 + triTable_min[Index][17]) < 5*NbMaxTri)
                    {
                        IndexPolyTabMinVector.push_back(triTable_min[Index][17]);
                        lnew++;
                        for(iter = 0; iter < triTable_min[Index][17]; iter++)
                            IndexPolyTabMinVector.push_back(GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter]]  + NbVertexTmp);
                        lnew+=triTable_min[Index][17];

                    }
                    //else return 0;
                }
                else if( nbpl == 2)
                {
                    NbPolyMin += nbpl;
                    //if((PreviousSizeMinimalTopology + lnew +2 + triTable_min[Index][17] + triTable_min[Index][18]) < 5*NbMaxTri)
                    {
                        /// First Poly:
                        IndexPolyTabMinVector.push_back(triTable_min[Index][17]);
                        lnew++;
                        for(iter = 0; iter < triTable_min[Index][17]; iter++)
                            IndexPolyTabMinVector.push_back(GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter]]  + NbVertexTmp);
                        lnew+=triTable_min[Index][17];
                        /// Second Poly:
                        IndexPolyTabMinVector.push_back(triTable_min[Index][18]);
                        lnew++;
                        for(iter = triTable_min[Index][17]; iter < triTable_min[Index][17]+triTable_min[Index][18]; iter++)
                            IndexPolyTabMinVector.push_back(GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter]]  + NbVertexTmp);
                        lnew+=triTable_min[Index][17]+triTable_min[Index][18];
                    }
                    //else return 0;
                }
                else if( nbpl > 2)
                {
                    NbPolyMin += nbpl;
                    /// In this case we have only Triangles (3 or 4):
                    iter = 0;
                    //if((PreviousSizeMinimalTopology + lnew + 4*nbpl) < 5*NbMaxTri)
                        for(iterpl = 0; iterpl < nbpl; iterpl++)
                        {
                            IndexPolyTabMinVector.push_back(3);
                            IndexPolyTabMinVector.push_back(GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter  ]]  + NbVertexTmp);
                            IndexPolyTabMinVector.push_back(GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter+1]]  + NbVertexTmp);
                            IndexPolyTabMinVector.push_back(GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter+2]]  + NbVertexTmp);
                            lnew += 4;
                            iter +=3;
                        }
                    //else return 0;
                }
            } /// End of for(k=0;
        } /// End of for(j=0;
    } /// End of for(i=0;
    return 1;
}

///++++++++++++++++++++ ConstructIsoSurface +++++++++++++++++++++++++++
uint Iso3D::ConstructIsoSurface()
{
    uint Index, IndexFirstPoint, IndexSeconPoint, IndexThirdPoint;
    uint I, J, IJK;
    uint maxgrscalemaxgr = masterthread->maximumgrid*masterthread->maximumgrid;

    NbTriangleIsoSurface = 0;
    for(uint i=0; i+1 < Xgrid; i++)
    {
        I   = i*maxgrscalemaxgr;
        for(uint j=0; j+1 < Ygrid; j++)
        {
            J   = I+j*masterthread->maximumgrid;
            for(uint k=0; k+1 < Zgrid; k++)
            {
                IJK = J+k;
                Index = GridVoxelVarPt[IJK].Signature;
                for (uint l = 0; triTable[Index][l] != 111; l += 3)
                {
                    IndexFirstPoint = GridVoxelVarPt[IJK].Edge_Points[triTable[Index][l  ]];
                    IndexSeconPoint = GridVoxelVarPt[IJK].Edge_Points[triTable[Index][l+1]];
                    IndexThirdPoint = GridVoxelVarPt[IJK].Edge_Points[triTable[Index][l+2]];
                    IndexPolyTabVector.push_back(IndexFirstPoint + NbVertexTmp);
                    IndexPolyTabVector.push_back(IndexSeconPoint + NbVertexTmp);
                    IndexPolyTabVector.push_back(IndexThirdPoint + NbVertexTmp);
                    NbTriangleIsoSurface++;
                }
            }
        }
    }
    return 1;
}

///+++++++++++++++++++++++++++++++++++++++++
uint Iso3D::PointEdgeComputation(uint isoindex)
{
    uint index, i_Start, i_End, j_Start, j_End, k_Start, k_End, i, j, k;
    double vals[7], IsoValue_1, IsoValue_2, rapport;
    double factor;
    uint maxgridval=masterthread->maximumgrid;
    uint maxgrscalemaxgr = maxgridval*maxgridval;
    uint I, J, JK, IJK, IPLUSONEJK, IMINUSONEJK,
        IJPLUSONEK, IJMINUSONEK, IMINUSONEJMINUSONEK, IsoValue=0, NbPointIsoMap_local=0;
    /// We have to compute the edges for the Grid limits ie: i=0, j=0 and k=0

    i_Start = 1/*+masterthread->iStart*/;
    j_Start = 1;
    k_Start = 1;

    i_End = Xgrid-1;
    j_End = Ygrid-1;
    k_End = Zgrid-1;
    /// The code is doubled to eliminate conditions tests

    for(i = i_Start; i < i_End; i++)
    {
        I = i*maxgrscalemaxgr;
        for(j = j_Start; j < j_End; j++)
        {
            J = I + j*maxgridval;
            for(k = k_Start; k < k_End; k++)
            {
                IJK                 = J+k;
                IPLUSONEJK          = IJK + maxgrscalemaxgr;
                IMINUSONEJK         = IJK - maxgrscalemaxgr;
                IJPLUSONEK          = IJK + maxgridval;
                IJMINUSONEK         = IJK - maxgridval;
                IMINUSONEJMINUSONEK = IMINUSONEJK - maxgridval;

                IsoValue_1 = Results[IJK];
                /// First Case P(i+1)(j)(k)

                IsoValue_2 = Results[IPLUSONEJK];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0 )
                {
                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i] - factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];
                    ///===========================================================///
                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[IJK].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    GridVoxelVarPt[IJMINUSONEK].Edge_Points[4] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJMINUSONEK].NbEdgePoint += 1;

                    GridVoxelVarPt[IJK-1].Edge_Points[2]   = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK-1].NbEdgePoint += 1;

                    GridVoxelVarPt[IJMINUSONEK-1].Edge_Points[6] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJMINUSONEK-1].NbEdgePoint += 1;

                    NbPointIsoMap_local++;
                }
                ///+++++++++++++++++++++++++++++++++++++++++
                /// Second Case P(i)(j+1)(k)

                IsoValue_2 = Results[IJPLUSONEK];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local ;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j] - factor * masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[IJK].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    GridVoxelVarPt[IMINUSONEJK].Edge_Points[9]    = NbPointIsoMap_local;
                    GridVoxelVarPt[IMINUSONEJK].NbEdgePoint += 1;

                    GridVoxelVarPt[IJK-1].Edge_Points[11]   = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK-1].NbEdgePoint += 1;

                    GridVoxelVarPt[IMINUSONEJK-1].Edge_Points[10] = NbPointIsoMap_local;
                    GridVoxelVarPt[IMINUSONEJK-1].NbEdgePoint += 1;

                    NbPointIsoMap_local++;
                }

                // Third Case P(i)(j)(k+1)

                IsoValue_2 = Results[IJK+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k] - factor * masterthread->z_Step[isoindex];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;
                    // save The reference to this point
                    GridVoxelVarPt[IJK].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    GridVoxelVarPt[IMINUSONEJK].Edge_Points[1]   = NbPointIsoMap_local;
                    GridVoxelVarPt[IMINUSONEJK].NbEdgePoint += 1;

                    GridVoxelVarPt[IJMINUSONEK].Edge_Points[7]   = NbPointIsoMap_local;
                    GridVoxelVarPt[IJMINUSONEK].NbEdgePoint += 1;

                    GridVoxelVarPt[IMINUSONEJMINUSONEK].Edge_Points[5] = NbPointIsoMap_local;
                    GridVoxelVarPt[IMINUSONEJMINUSONEK].NbEdgePoint += 1;

                    NbPointIsoMap_local++;
                }
            }
        }
    }

    /// Now we have to compute the Grid's limits...
    /// The code is quite big but this is much more easy to compute

    /// 1) First case : i =0;

    i =0;
    for(j=0; j < Ygrid; j++)
    {
        J = j*maxgridval;
        for(k=0; k < Zgrid; k++)
        {
            JK = J +k;

            IsoValue_1 = Results[JK];

            // First Case P(1)(j)(k)

            IsoValue_2 = Results[maxgrscalemaxgr+JK];
            if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
            {
                // Edge Point computation and  save in IsoPointMap
                factor = (IsoValue - IsoValue_1)/rapport;
                index  = 10*NbPointIsoMap_local;

                vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i] - factor * masterthread->x_Step[isoindex];
                vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                {
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));
                }
                //else return 0;

                // save The reference to this point
                GridVoxelVarPt[JK].Edge_Points[0] = NbPointIsoMap_local;
                GridVoxelVarPt[JK].NbEdgePoint += 1;

                // The same Point is used in three other Voxels
                if( j != 0)
                {
                    GridVoxelVarPt[JK-maxgridval].Edge_Points[4] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK-maxgridval].NbEdgePoint += 1;
                }
                if ( k != 0 )
                {
                    GridVoxelVarPt[JK-1].Edge_Points[2]   = NbPointIsoMap_local;
                    GridVoxelVarPt[JK-1].NbEdgePoint += 1;
                }
                if( j != 0 && k != 0)
                {
                    GridVoxelVarPt[JK-maxgridval-1].Edge_Points[6] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK-maxgridval-1].NbEdgePoint += 1;
                }

                NbPointIsoMap_local++;
            }

            // Second Case P(0)(j+1)(k)
            if ( j != (Ygrid -1))
            {
                IsoValue_2 = Results[JK+maxgridval];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j] - factor *masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[JK].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if ( k != 0)
                    {
                        GridVoxelVarPt[JK-1].Edge_Points[11]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;
                }
            } /// If ( j != nb_colon -1) ...

            // Third Case P(0)(j)(k+1)
            if ( k != (Zgrid-1))
            {
                IsoValue_2 = Results[JK+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k] - factor * masterthread->z_Step[isoindex];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[JK].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if ( j != 0)
                    {
                        GridVoxelVarPt[JK-maxgridval].Edge_Points[7]   =NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maxgridval].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of ( if ( k != nb_depth -1)....
        }
    }



    /// 2) Case i = nb_ligne-1

    i = Xgrid-1;
    I = i*maxgrscalemaxgr;
    for(j=0; j < Ygrid; j++)
    {
        J = I + j*maxgridval;
        for(k=0; k < Zgrid; k++)
        {
            JK = J + k;

            IsoValue_1 = Results[JK];


            // Second Case P(i)(j+1)(k)
            if ( j != (Ygrid -1))
            {
                IsoValue_2 = Results[JK+maxgridval];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j] - factor *masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[JK].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if(i != 0)
                    {
                        GridVoxelVarPt[JK-maxgrscalemaxgr].Edge_Points[9]    =NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maxgrscalemaxgr].NbEdgePoint += 1;
                    }
                    if(k != 0)
                    {
                        GridVoxelVarPt[JK-1].Edge_Points[11]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-1].NbEdgePoint += 1;
                    }
                    if(i != 0 && k != 0)
                    {
                        GridVoxelVarPt[JK-maxgrscalemaxgr-1].Edge_Points[10] = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maxgrscalemaxgr-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if (j != nb_colon -1)...

            // Third Case P(i)(j)(k+1)
            if ( k != (Zgrid -1))
            {
                IsoValue_2 = Results[JK+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k] - factor * masterthread->z_Step[isoindex];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[JK].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( i != 0)
                    {
                        GridVoxelVarPt[JK-maxgrscalemaxgr].Edge_Points[1]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maxgrscalemaxgr].NbEdgePoint += 1;
                    }
                    if(j != 0)
                    {
                        GridVoxelVarPt[JK-maxgridval].Edge_Points[7]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maxgridval].NbEdgePoint += 1;
                    }
                    if( i !=0 && j != 0)
                    {
                        GridVoxelVarPt[JK-maxgrscalemaxgr-maxgridval].Edge_Points[5] = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maxgrscalemaxgr-maxgridval].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if ( k != nb_depth -1)...
        }
    }



    /// 3) Case j = 0
    j= 0;

    for(i=0; i < Xgrid; i++)
        for(k=0; k < Zgrid; k++)
        {

            IsoValue_1 = Results[i*maxgrscalemaxgr+k];

            // First Case P(i+1)(j)(k)
            if( i != (Xgrid -1))
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+k];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {

                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i] - factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+k].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( k!=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+k-1].Edge_Points[2]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+k-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;
                }
            } /// End of if ( i != nb_ligne -1)...

            // Second Case P(i)(j+1)(k)

            IsoValue_2 = Results[i*maxgrscalemaxgr+maxgridval+k];
            // Edge Point computation and  save in IsoPointMap
            if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
            {
                factor = (IsoValue - IsoValue_1)/rapport;
                index  = 10*NbPointIsoMap_local;

                vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j] - factor * masterthread->y_Step[isoindex];
                vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                {
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));
                }
                //else return 0;

                // save The reference to this point
                GridVoxelVarPt[i*maxgrscalemaxgr+k].Edge_Points[8] = NbPointIsoMap_local;
                GridVoxelVarPt[i*maxgrscalemaxgr+k].NbEdgePoint += 1;

                // The same Point is used in three other Voxels
                if( i !=0 )
                {
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+k].Edge_Points[9]    = NbPointIsoMap_local;
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+k].NbEdgePoint += 1;
                }
                if(k !=0)
                {
                    GridVoxelVarPt[i*maxgrscalemaxgr+k-1].Edge_Points[11]   = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+k-1].NbEdgePoint += 1;
                }
                if( i !=0 && k !=0)
                {
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+k-1].Edge_Points[10] = NbPointIsoMap_local;
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+k-1].NbEdgePoint += 1;
                }

                NbPointIsoMap_local++;

            }


            // Third Case P(i)(j)(k+1)
            if(k != (Zgrid -1))
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+k+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k] - factor * masterthread->z_Step[isoindex];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+k].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( i != 0)
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+k].Edge_Points[1]   = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+k].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if(k != (nb_depth -1))...
        }


    /// 4) Case j = nb_colon -1
    j = Ygrid-1;

    for(i=0; i < Xgrid; i++)
        for(k=0; k < Zgrid; k++)
        {

            IsoValue_1 = Results[i*maxgrscalemaxgr+j*maxgridval+k];


            // First Case P(i+1)(j)(k)
            if( i != (Xgrid-1))
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+j*maxgridval+k];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {

                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i] - factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( j != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k].Edge_Points[4] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k].NbEdgePoint += 1;
                    }
                    if(k != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k-1].Edge_Points[2]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k-1].NbEdgePoint += 1;
                    }
                    if(j != 0 && k != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k-1].Edge_Points[6] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;


                }
            } /// End of if( i != (nb_ligne-1))...

            // Third Case P(i)(j)(k+1)
            if( k != (Zgrid -1))
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+j*maxgridval+k+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k] - factor * masterthread->z_Step[isoindex];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if(i !=0)
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval+k].Edge_Points[1]   = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval+k].NbEdgePoint += 1;
                    }
                    if( j!=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k].Edge_Points[7]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k].NbEdgePoint += 1;
                    }
                    if(i != 0 && j !=0)
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*maxgridval+k].Edge_Points[5] = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*maxgridval+k].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if (k != nb_depth)...
        }


    /// 5) Case k = 0

    k =0;

    for(i=0; i < Xgrid; i++)
        for(j=0; j < Ygrid; j++)
        {
            IsoValue_1 = Results[i*maxgrscalemaxgr+j*maxgridval];
            // First Case P(i+1)(j)(k)
            if(i != (Xgrid -1))
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+j*maxgridval];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i] - factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval].NbEdgePoint += 1;

                    // The same Point is used in one other Voxel
                    if(j !=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval].Edge_Points[4] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;


                }
            } /// End of if(i != (nb_ligne -1))

            // Second Case P(i)(j+1)(k)
            if(j != Ygrid -1)
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+(j+1)*maxgridval];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j] - factor * masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval].NbEdgePoint += 1;

                    // The same Point is used in one other Voxels
                    if ( i !=0 )
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval].Edge_Points[9]    = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            }/// End of if(j != nb_colon -1)...

            // Third Case P(i)(j)(k+1)

            IsoValue_2 = Results[i*maxgrscalemaxgr+j*maxgridval+1];
            // Edge Point computation and  save in IsoPointMap
            if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
            {
                factor = (IsoValue - IsoValue_1)/rapport;
                index  = 10*NbPointIsoMap_local;

                vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k] - factor * masterthread->z_Step[isoindex];

                //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                {
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));
                }
                //else return 0;

                // save The reference to this point
                GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval].Edge_Points[3] = NbPointIsoMap_local;
                GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval].NbEdgePoint += 1;

                // The same Point is used in three other Voxels
                if ( i !=0 )
                {
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval].Edge_Points[1]   = NbPointIsoMap_local;
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval].NbEdgePoint += 1;
                }
                if (j != 0 )
                {
                    GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval].Edge_Points[7]   = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval].NbEdgePoint += 1;
                }
                if ( i !=0 && j != 0 )
                {
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*maxgridval].Edge_Points[5] = NbPointIsoMap_local;
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*maxgridval].NbEdgePoint += 1;
                }

                NbPointIsoMap_local++;

            }
        }


    /// 6) Case k = nb_depth -1

    k = Zgrid -1;

    for(i=0; i < Xgrid; i++)
        for(j=0; j < Ygrid; j++)
        {

            IsoValue_1 = Results[i*maxgrscalemaxgr+j*maxgridval+k];


            // First Case P(i+1)(j)(k)
            if( i != (Xgrid -1) )
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+j*maxgridval+k];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {

                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i] - factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if(j !=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k].Edge_Points[4] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k].NbEdgePoint += 1;
                    }
                    if(k !=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k-1].Edge_Points[2]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k-1].NbEdgePoint += 1;
                    }
                    if(j !=0 && k != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k-1].Edge_Points[6] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;


                }
            } /// End of if(i != nb_ligne-1)...

            // Second Case P(i)(j+1)(k)
            if( j != (Ygrid -1) )
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+(j+1)*maxgridval+k];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = 10*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j] - factor * masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    //if((3+ 10*NbVertexTmp +index+2  + 4) < 10*NbMaxPts)
                    {
                        for(int iter=0; iter<7; iter++)
                            NormVertexTabVector.push_back(1.0);
                        NormVertexTabVector.push_back(float(vals[0]));
                        NormVertexTabVector.push_back(float(vals[1]));
                        NormVertexTabVector.push_back(float(vals[2]));
                    }
                    //else return 0;

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( i !=0 )
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval+k].Edge_Points[9]    = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval+k].NbEdgePoint += 1;
                    }
                    if( k !=0 )
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k-1].Edge_Points[11]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k-1].NbEdgePoint += 1;
                    }
                    if( i !=0 && k !=0 )
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval+k-1].Edge_Points[10] = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval+k-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;
                }
            } /// End of if( j != (nb_colon -1) )...
        }
    NbPointIsoMap =    NbPointIsoMap_local;
    return 1;
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++///
void Iso3D::SignatureComputation()
{
    uint I, J, IJK, IPLUSONEJK,
        IJPLUSONEK,  IPLUSONEJPLUSONEK;
    uint maxgrscalemaxgr = masterthread->maximumgrid*masterthread->maximumgrid;
    for(uint i=0; i < Xgrid; i++)
    {
        I = i*maxgrscalemaxgr;
        for(uint j=0; j < Ygrid; j++)
        {
            J = I + j*masterthread->maximumgrid;
            for(uint k=0; k < Zgrid; k++)
            {
                IJK               = J + k;
                IPLUSONEJK        = IJK + maxgrscalemaxgr;
                IJPLUSONEK        = IJK + masterthread->maximumgrid;
                IPLUSONEJPLUSONEK = IPLUSONEJK + masterthread->maximumgrid;

                if(Results[IJK] <= 0) GridVoxelVarPt[IJK].Signature +=1;

                if(i != (Xgrid-1))
                    if(Results[IPLUSONEJK] <= 0) GridVoxelVarPt[IJK].Signature +=2;

                if(i != (Xgrid-1) && k != (Zgrid-1))
                    if(Results[IPLUSONEJK+1] <= 0) GridVoxelVarPt[IJK].Signature +=4;

                if(k != (Zgrid-1))
                    if(Results[IJK+1] <= 0) GridVoxelVarPt[IJK].Signature +=8;

                if(j != (Ygrid-1))
                    if(Results[IJPLUSONEK] <= 0) GridVoxelVarPt[IJK].Signature +=16;

                if(i != (Xgrid-1) && j != (Ygrid-1))
                    if(Results[IPLUSONEJPLUSONEK] <= 0) GridVoxelVarPt[IJK].Signature +=32;

                if(i != (Xgrid-1) && j != (Ygrid-1) && k != (Zgrid-1))
                    if(Results[IPLUSONEJPLUSONEK+1] <= 0) GridVoxelVarPt[IJK].Signature +=64;

                if(j != (Ygrid-1) && k != (Zgrid-1))
                    if(Results[IJPLUSONEK+1] <= 0) GridVoxelVarPt[IJK].Signature +=128;
            }
        }
    }// End if(Grid...
}
