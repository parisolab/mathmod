/***************************************************************************
*   Copyright (C) 2017 by Abderrahman Taha                                *
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

static unsigned int *IndexPolyTabMin;
static int NbPolyMin;
static float * NormOriginaltmp;
static Voxel *GridVoxelVarPt;
static float *Results;

static int TypeDrawin=10;
static int TypeDrawinNormStep = 4;
static int PreviousSizeMinimalTopology =0;
static int NbPolyMinimalTopology =0;
static int NbVertexTmp = 0;
float* NormVertexTab;

int NbMaxGrid = 100;
int NbComponent = 30;
int NbConstantes = 30;
int NbDefinedFunctions = 50;
int NbVariables = 30;
int NbTextures = 30;
int NbSliders = 50;
int NbSliderValues = 500;

CellNoise *NoiseFunction = new CellNoise();
ImprovedNoise *PNoise = new ImprovedNoise(4., 4., 4.);

double TurbulenceWorley(const double* p)
{
    return NoiseFunction->CellNoiseFunc(
               p[0],
               p[1],
               p[2],
               (int)p[3],
               (int)p[4],
               (int)p[5]);
}

double TurbulencePerlin(const double* p)
{
    return PNoise->FractalNoise3D(
               p[0],
               p[1],
               p[2],
               (int)p[3],
               p[4],
               p[5]);
}

/// +++++++++++++++++++++++++++++++++++++++++
void Iso3D::SetMinimuMmeshSize(double)
{
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void IsoWorkerThread::run()
{
    IsoCompute(CurrentIso);
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
void Iso3D::BuildIso()
{
    IsoBuild(
        LocalScene->ArrayNorVer_localPt,
        LocalScene->PolyIndices_localPt,
        &LocalScene->PolyNumber,
        &(LocalScene->VertxNumber),
        LocalScene->PolyIndices_localPtMin,
        &(LocalScene->NbPolygnNbVertexPtMin),
        &(LocalScene->componentsinfos),
        LocalScene->Typetriangles,
        LocalScene->WichPointVerifyCond);
}

//+++++++++++++++++++++++++++++++++++++++++
int Iso3D::setmaxgridto(int maxgrid)
{
    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
        workerthreads[nbthreads].maximumgrid = maxgrid;
    delete GridVoxelVarPt;
    delete Results;
    GridVoxelVarPt = new Voxel[maxgrid*maxgrid*maxgrid];
    Results        = new float [10*maxgrid*maxgrid*maxgrid];
    return(1);
}

//+++++++++++++++++++++++++++++++++++++++++
IsoMasterThread::IsoMasterThread()
{
    IsoConditionRequired = -1;
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
    ImplicitFunctionSize = ConditionSize = ConstSize = VaruSize = FunctSize = RgbtSize = VRgbtSize = 0;
}

//+++++++++++++++++++++++++++++++++++++++++
void IsoMasterThread::IsoMasterTable()
{
    vr2     = new double[3*(NbVariables+1)*NbComponent*NbMaxGrid];
    xLocal2 = new double[NbComponent*NbMaxGrid];
    yLocal2 = new double[NbComponent*NbMaxGrid];
    zLocal2 = new double[NbComponent*NbMaxGrid];

    Varus        = new std::string[NbVariables];
    VarName      = new std::string[NbVariables];
    Consts       = new std::string[NbConstantes];
    ConstNames   = new std::string[NbConstantes];
    Functs       = new std::string[NbDefinedFunctions];
    FunctNames   = new std::string[NbDefinedFunctions];
    Rgbts        = new std::string[NbTextures];
    RgbtNames    = new std::string[NbTextures];
    VRgbts       = new std::string[NbTextures];
    VRgbtNames   = new std::string[NbTextures];
    x_Step       = new double[NbComponent];
    y_Step       = new double[NbComponent];
    z_Step       = new double[NbComponent];
    GridTable    = new int[NbComponent];
    SliderNames  = new std::string[NbSliders];
    SliderValues = new double[NbSliderValues];
    ConstValues  = new double[NbConstantes];
    ImplicitStructs = new ImplicitStructure[NbComponent];
    UsedFunct    = new bool[NbComponent*NbDefinedFunctions];
    UsedFunct2   = new bool[NbDefinedFunctions*NbDefinedFunctions];
    for(int i=0; i<NbSliders; i++)
    {
        SliderNames[i]= "Param_"+QString::number(i).toStdString();
    }
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
        delete[] Var;
        delete[] IsoConditionParser;
        delete[] VRgbtParser;
        delete[] RgbtParser;
        delete GradientParser;
        delete NoiseParser;
        ParsersAllocated = false;
    }
    delete[] SliderNames;
    delete[] SliderValues;
    delete[] ConstValues;
    delete[] Varus;
    delete[] VarName;
    delete[] Consts;
    delete[] ConstNames;
    delete[] Functs;
    delete[] FunctNames;
    delete[] Rgbts;
    delete[] RgbtNames;
    delete[] VRgbts;
    delete[] VRgbtNames;
    delete[] x_Step;
    delete[] y_Step;
    delete[] z_Step;
    delete[] GridTable;
    delete[] ImplicitStructs;
    delete[] UsedFunct;
    delete[] UsedFunct2;
}

IsoWorkerThread::~IsoWorkerThread()
{
    if(ParsersAllocated)
    {
        delete[] implicitFunctionParser;
        delete[] Fct;
        ParsersAllocated = false;
    }
    delete[] vr2;
    delete[] xLocal2;
    delete[] yLocal2;
    delete[] zLocal2;
}

IsoWorkerThread::IsoWorkerThread()
{
    nb_ligne = nb_colon = nb_depth = 40;
    stepMorph = 0;
    pace = (double)1/(double)30;
    morph_activated = -1;
    AllComponentTraited = false;
    ParsersAllocated = false;
    StopCalculations = false;
}

//+++++++++++++++++++++++++++++++++++++++++
void IsoWorkerThread::IsoWorkerTable()
{
    vr2     = new double[3*(NbVariables+1)*NbComponent*NbMaxGrid];
    xLocal2 = new double[NbComponent*NbMaxGrid];
    yLocal2 = new double[NbComponent*NbMaxGrid];
    zLocal2 = new double[NbComponent*NbMaxGrid];
}

//+++++++++++++++++++++++++++++++++++++++++
void Iso3D::WorkerThreadCopy(IsoWorkerThread *WorkerThreadsTmp)
{
    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
    {
        WorkerThreadsTmp[nbthreads].nb_ligne = masterthread->nb_ligne;
        WorkerThreadsTmp[nbthreads].nb_colon = masterthread->nb_colon;
        WorkerThreadsTmp[nbthreads].nb_depth = masterthread->nb_depth;
        WorkerThreadsTmp[nbthreads].Nb_newvariables = masterthread->Nb_newvariables;
        WorkerThreadsTmp[nbthreads].MyIndex  = nbthreads+1;
        WorkerThreadsTmp[nbthreads].WorkerThreadsNumber = WorkerThreadsNumber;
        WorkerThreadsTmp[nbthreads].maximumgrid = NbMaxGrid;
    }
}

//+++++++++++++++++++++++++++++++++++++++++
void Iso3D::MasterThreadCopy(IsoMasterThread *MasterThreadsTmp)
{
        MasterThreadsTmp->ImplicitFunction   = masterthread->ImplicitFunction;
        MasterThreadsTmp->XlimitSup          = masterthread->XlimitSup;
        MasterThreadsTmp->XlimitInf          = masterthread->XlimitInf;
        MasterThreadsTmp->YlimitSup          = masterthread->YlimitSup;
        MasterThreadsTmp->YlimitInf          = masterthread->YlimitInf;
        MasterThreadsTmp->ZlimitSup          = masterthread->ZlimitSup;
        MasterThreadsTmp->ZlimitInf          = masterthread->ZlimitInf;
        MasterThreadsTmp->Condition          = masterthread->Condition;
        MasterThreadsTmp->Grid               = masterthread->Grid;
        MasterThreadsTmp->Funct              = masterthread->Funct;
        MasterThreadsTmp->Varu               = masterthread->Varu;
        MasterThreadsTmp->Const              = masterthread->Const;
        MasterThreadsTmp->Rgbt               = masterthread->Rgbt;
        MasterThreadsTmp->VRgbt              = masterthread->VRgbt;
        MasterThreadsTmp->Gradient           = masterthread->Gradient;
        MasterThreadsTmp->Noise              = masterthread->Noise;

        MasterThreadsTmp->nb_ligne           = nb_ligne;
        MasterThreadsTmp->nb_colon           = nb_colon;
        MasterThreadsTmp->nb_depth           = nb_depth;
        MasterThreadsTmp->maximumgrid        = NbMaxGrid;
        MasterThreadsTmp->MyIndex            = 0;
        MasterThreadsTmp->WorkerThreadsNumber= WorkerThreadsNumber;
        MasterThreadsTmp->ImplicitFunctionSize = masterthread->ImplicitFunctionSize;
        MasterThreadsTmp->FunctSize = masterthread->FunctSize;
        MasterThreadsTmp->VaruSize = masterthread->VaruSize;
        MasterThreadsTmp->Nb_Sliders = masterthread->Nb_Sliders;
        if(masterthread->Nb_Sliders >0)
        {
            memcpy(MasterThreadsTmp->SliderNames, masterthread->SliderNames, NbSliders*sizeof(std::string));
            memcpy(MasterThreadsTmp->SliderValues, masterthread->SliderValues, NbSliderValues*sizeof(double));
        }
}

//+++++++++++++++++++++++++++++++++++++++
void Iso3D::UpdateThredsNumber(int NewThreadsNumber)
{
    int OldWorkerThreadsNumber = WorkerThreadsNumber;
    WorkerThreadsNumber = NewThreadsNumber;
    IsoWorkerThread *workerthreadstmp = new IsoWorkerThread[WorkerThreadsNumber-1];
    for(int i=0; i<WorkerThreadsNumber-1; i++)
        workerthreadstmp[i].IsoWorkerTable();
    WorkerThreadCopy(workerthreadstmp);
    //Free old memory:
    for(int i=0; i<OldWorkerThreadsNumber-1; i++)
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
    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
    {
        memcpy(workerthreads[nbthreads].xLocal2, masterthread->xLocal2, NbComponent*NbMaxGrid*sizeof(double));
        memcpy(workerthreads[nbthreads].yLocal2, masterthread->yLocal2, NbComponent*NbMaxGrid*sizeof(double));
        memcpy(workerthreads[nbthreads].zLocal2, masterthread->zLocal2, NbComponent*NbMaxGrid*sizeof(double));
        memcpy(workerthreads[nbthreads].vr2, masterthread->vr2, 3*(NbVariables+1)*NbComponent*NbMaxGrid*sizeof(double));
        //memcpy(workerthreads[nbthreads].VarName, masterthread->VarName, NbVariables*sizeof(std::string));

        workerthreads[nbthreads].Nb_newvariables = masterthread->Nb_newvariables;
        workerthreads[nbthreads].morph_activated = masterthread->morph_activated;
        workerthreads[nbthreads].AllComponentTraited = masterthread->AllComponentTraited;
        workerthreads[nbthreads].nb_ligne = masterthread->nb_ligne;
        workerthreads[nbthreads].nb_colon = masterthread->nb_colon;
        workerthreads[nbthreads].nb_depth = masterthread->nb_depth;
    }

    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
        workerthreads[nbthreads].DeleteWorkerParsers();

    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
        workerthreads[nbthreads].AllocateParsersForWorkerThread(masterthread->ImplicitFunctionSize, masterthread->FunctSize);

    return(parse_expression2());
}


ErrorMessage  Iso3D::parse_expression2()
{
    ErrorMessage NodError;
    // Functions :
    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
    {
        for(int ij=0; ij<masterthread->Nb_functs; ij++)
        {
            workerthreads[nbthreads].Fct[ij].AddConstant("pi", PI);
        }

        for(int ii=0; ii<masterthread->Nb_functs; ii++)
        {
            for(int jj=0; jj<masterthread->Nb_constants; jj++)
            {
                workerthreads[nbthreads].Fct[ii].AddConstant(masterthread->ConstNames[jj], masterthread->ConstValues[jj]);
            }

            //Add predefined constatnts:
            for(int kk=0; kk<masterthread->Nb_Sliders; kk++)
            {
                workerthreads[nbthreads].Fct[ii].AddConstant(masterthread->SliderNames[kk], masterthread->SliderValues[kk]);
            }
        }

        for(int ii=0; ii<masterthread->Nb_functs; ii++)
        {
            workerthreads[nbthreads].Fct[ii].AddFunction("NoiseW",TurbulenceWorley, 6);
            workerthreads[nbthreads].Fct[ii].AddFunction("fhelix1",fhelix1, 10);
            workerthreads[nbthreads].Fct[ii].AddFunction("fhelix2",fhelix2, 10);
            workerthreads[nbthreads].Fct[ii].AddFunction("f_hex_y",f_hex_y, 4);
            workerthreads[nbthreads].Fct[ii].AddFunction("p_skeletal_int",p_skeletal_int, 3);
            workerthreads[nbthreads].Fct[ii].AddFunction("fmesh",fmesh, 8);
            workerthreads[nbthreads].Fct[ii].AddFunction("NoiseP",TurbulencePerlin, 6);
            for(int jj=0; jj<ii; jj++)
                if(masterthread->UsedFunct2[ii*NbDefinedFunctions+jj])
                workerthreads[nbthreads].Fct[ii].AddFunction(masterthread->FunctNames[jj], workerthreads[nbthreads].Fct[jj]);
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].Fct[ii].Parse(masterthread->Functs[ii],"x,y,z,t")) >= 0)
            {
                masterthread->stdError.strError = masterthread->Functs[ii];
                masterthread->stdError.strOrigine = masterthread->FunctNames[ii];
                return masterthread->stdError;
            }
        }
    }

    //Add defined constantes:
    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
    {
        for(int i=0; i<masterthread->Nb_implicitfunctions+1; i++)
        {
            workerthreads[nbthreads].implicitFunctionParser[i].AddConstant("pi", PI);


        for(int j=0; j<masterthread->Nb_constants; j++)
        {
            workerthreads[nbthreads].implicitFunctionParser[i].AddConstant(masterthread->ConstNames[j], masterthread->ConstValues[j]);
        }
        //Add predefined sliders constatnts:
        for(int k=0; k<masterthread->Nb_Sliders; k++)
        {
            workerthreads[nbthreads].implicitFunctionParser[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
        }
    }
    }
    // Add defined functions :
    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
    {
    for(int i=0; i<masterthread->Nb_implicitfunctions+1; i++)
    {
        //Functions:
                workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
                workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("fhelix1",fhelix1, 10);
                workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("fhelix2",fhelix2, 10);
                workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("f_hex_y",f_hex_y, 4);
                workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("p_skeletal_int",p_skeletal_int, 3);
                workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("fmesh",fmesh, 8);
                workerthreads[nbthreads].implicitFunctionParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);

        for(int j=0; j<masterthread->Nb_functs; j++)
        {
            if(masterthread->UsedFunct[i*NbDefinedFunctions+j])
                workerthreads[nbthreads].implicitFunctionParser[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct[j]);
        }
    }
   }

    // Final step: parsing
    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
    {
    for(int index=0; index< masterthread->Nb_implicitfunctions + 1; index++)
    {
        if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].implicitFunctionParser[index].Parse(masterthread-> ImplicitStructs[index].fxyz, masterthread->varliste)) >= 0)
        {
            masterthread->stdError.strError = masterthread->ImplicitStructs[index].fxyz;
            masterthread->stdError.strOrigine = masterthread->ImplicitStructs[index].index;
            return masterthread->stdError;
        }
      }
    }
    return NodError;
}

/// +++++++++++++++++++++++++++++++++++++++++
Iso3D::Iso3D( int maxtri, int maxpts, int nbmaxgrid,
                                    int NbCompo,
                                    int NbVariabl,
                                    int NbConstant,
                                    int NbDefinedFunct,
                                    int NbText,
                                    int NbSlid,
                                    int NbSliderV,
                                    int nbThreads,
                                    int nbGrid)
{
    NbTextures=NbText;
    NbComponent=NbCompo;
    NbVariables = NbVariabl;
    NbSliders  = NbSlid;
    NbSliderValues = NbSliderV;
    NbConstantes = NbConstant;
    NbDefinedFunctions = NbDefinedFunct;
    NbMaxGrid = nbmaxgrid;
    NbTriangleIsoSurface = 0;
    NbPointIsoMap = 0;
    nb_ligne = nb_colon = nb_depth = nbGrid;
    WorkerThreadsNumber = nbThreads;
    masterthread  = new IsoMasterThread();
    masterthread->IsoMasterTable();
    workerthreads = new IsoWorkerThread[WorkerThreadsNumber-1];
    for(int i=0; i<WorkerThreadsNumber-1; i++)
        workerthreads[i].IsoWorkerTable();

    masterthread->nb_ligne = nb_ligne;
    masterthread->nb_colon = nb_colon;
    masterthread->nb_depth = nb_depth;
    masterthread->maximumgrid = NbMaxGrid;
    masterthread->MyIndex = 0;
    masterthread->WorkerThreadsNumber = WorkerThreadsNumber;

    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
    {
        workerthreads[nbthreads].nb_ligne = nb_ligne;
        workerthreads[nbthreads].nb_colon = nb_colon;
        workerthreads[nbthreads].nb_depth = nb_depth;
        workerthreads[nbthreads].maximumgrid = NbMaxGrid;
        workerthreads[nbthreads].MyIndex = nbthreads+1;
        workerthreads[nbthreads].WorkerThreadsNumber = WorkerThreadsNumber;
    }
    static int staticaction = 1;
    /// Things to do one time...
    if(staticaction == 1)
    {
        IsoSurfaceTriangleListe  = new int[3*maxtri];
        NormOriginaltmp          = new float[3*maxtri];
        GridVoxelVarPt           = new Voxel[NbMaxGrid*NbMaxGrid*NbMaxGrid];
        Results                  = new float[NbMaxGrid*NbMaxGrid*NbMaxGrid];
        NormVertexTab            = new float [10*maxpts];
        staticaction            *= -1;
    }
    else
    {
        delete[] IsoSurfaceTriangleListe;
        delete[] NormOriginaltmp;
        delete[] GridVoxelVarPt;
        delete[] Results;
        delete[] NormVertexTab;

        IsoSurfaceTriangleListe  = new int[3*maxtri];
        NormOriginaltmp          = new float[3*maxtri];
        GridVoxelVarPt           = new  Voxel[NbMaxGrid*NbMaxGrid*NbMaxGrid];
        Results                  = new float[NbMaxGrid*NbMaxGrid*NbMaxGrid];
        NormVertexTab            = new float [10*maxpts];
        staticaction            *= -1;
    }
}

///+++++++++++++++++++++++++++++++++++++++++
int IsoMasterThread::HowManyVariables(std::string NewVariables, int type)
{
    std::string tmp, tmp2,tmp3;
    int position =0, jpos;
    int Nb_variables =0;
    while( NewVariables!= "")
    {
        if((position = NewVariables.find(";")) >0)
        {
            tmp = NewVariables;
            tmp2= tmp3 = (tmp.substr(0,position));
            jpos = tmp2.find("=");
            if(type == 0)
            {
                VarName[Nb_variables] = tmp2.substr(0,jpos);
                Varus[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            else if(type == 1)
            {
                ConstNames[Nb_variables] = tmp2.substr(0,jpos);
                Consts[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            else if(type == 2)
            {
                FunctNames[Nb_variables] = tmp2.substr(0,jpos);
                Functs[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            else if(type == 3)
            {
                RgbtNames[Nb_variables] = tmp2.substr(0,jpos);
                Rgbts[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            else if(type == 4)
            {
                VRgbtNames[Nb_variables] = tmp2.substr(0,jpos);
                VRgbts[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            tmp2 = NewVariables.substr(position+1, NewVariables.length()-1);
            NewVariables = tmp2;
            Nb_variables++;
        }
        else
        {
            tmp = tmp2 = tmp3 = NewVariables;
            jpos = tmp2.find("=");
            if(type == 0)
            {
                VarName[Nb_variables] = tmp2.substr(0, jpos);
                Varus[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            else if(type == 1)
            {
                ConstNames[Nb_variables] = tmp2.substr(0, jpos);
                Consts[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            else if(type == 2)
            {
                FunctNames[Nb_variables] = tmp2.substr(0, jpos);
                Functs[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            else if(type == 3)
            {
                RgbtNames[Nb_variables] = tmp2.substr(0, jpos);
                Rgbts[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            else if(type == 4)
            {
                VRgbtNames[Nb_variables] = tmp2.substr(0, jpos);
                VRgbts[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }

            NewVariables = "";
            Nb_variables++;
        }
    }
    return Nb_variables;
}

///+++++++++++++++++++++++++++++++++++++++++
int IsoMasterThread::HowManyIsosurface(std::string ImplicitFct, int type)
{
    std::string tmp, tmp2;
    int position =0, jpos;
    int Nb_implicitfunction =0;
    double val=0.0;
    if(type ==0)
    {
        ImplicitStructs[0].fxyz = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) >0   )
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
            if((position = ImplicitFct.find(";")) >0   )
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
            if((position = ImplicitFct.find(";")) >0   )
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
            if((position = ImplicitFct.find(";")) >0   )
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
            if((position = ImplicitFct.find(";")) >0   )
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
            if((position = ImplicitFct.find(";")) >0   )
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
            if((position = ImplicitFct.find(";")) >0   )
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

    else if(type == 7) //Grid
    {
        ImplicitStructs[0].grid = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) >0   )
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].grid = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].grid  = ImplicitFct;
                ImplicitFct ="";
            }
        }

        for(int i=0; i<Nb_implicitfunction; i++)
            GridTable[i] = 0;
        for(int i=0; i<Nb_implicitfunction+1; i++)
        {
            if(ImplicitStructs[i].grid != "")
            {
                Cstparser.Parse(ImplicitStructs[i].grid, "u");
                GridTable[i] = Cstparser.Eval(&val); //position is used only to make the Eval function work
            }
        }
        return Nb_implicitfunction;
    }


    else if(type == 8) //Cnd
    {
        ImplicitStructs[0].cnd = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) >0   )
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
void IsoMasterThread::InitParser()
{
    AllocateMasterParsers();
    InitMasterParsers();
}

//+++++++++++++++++++++++++++++++++++++++++
void Iso3D::ReinitVarTablesWhenMorphActiv(int IsoIndex)
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    double vals2[] = {0,0};
    const int limitX = nb_ligne, limitY = nb_colon, limitZ = nb_depth;

        vals[3]          = masterthread->stepMorph;
        masterthread->xLocal2[IsoIndex*NbMaxGrid]=masterthread->xSupParser[IsoIndex].Eval(vals);
        masterthread->yLocal2[IsoIndex*NbMaxGrid]=masterthread->ySupParser[IsoIndex].Eval(vals);
        masterthread->zLocal2[IsoIndex*NbMaxGrid]=masterthread->zSupParser[IsoIndex].Eval(vals);

        masterthread->x_Step[IsoIndex] =  (masterthread->xLocal2[IsoIndex*NbMaxGrid] - masterthread->xInfParser[IsoIndex].Eval(vals))/(limitX-1);
        masterthread->y_Step[IsoIndex] =  (masterthread->yLocal2[IsoIndex*NbMaxGrid] - masterthread->yInfParser[IsoIndex].Eval(vals))/(limitY-1);
        masterthread->z_Step[IsoIndex] =  (masterthread->zLocal2[IsoIndex*NbMaxGrid] - masterthread->zInfParser[IsoIndex].Eval(vals))/(limitZ-1);

        for (int i= 1; i < limitX; i++)
            masterthread->xLocal2[IsoIndex*NbMaxGrid+i] = masterthread->xLocal2[IsoIndex*NbMaxGrid+i-1] - masterthread->x_Step[IsoIndex];
        for (int j= 1; j < limitY; j++)
            masterthread->yLocal2[IsoIndex*NbMaxGrid+j] = masterthread->yLocal2[IsoIndex*NbMaxGrid+j-1] - masterthread->y_Step[IsoIndex];
        for (int k= 1; k < limitZ; k++)
            masterthread->zLocal2[IsoIndex*NbMaxGrid+k] = masterthread->zLocal2[IsoIndex*NbMaxGrid+k-1] - masterthread->z_Step[IsoIndex];

        for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
        {
            //workerthreads[nbthreads].x_Step[IsoIndex] = masterthread->x_Step[IsoIndex];
            //workerthreads[nbthreads].y_Step[IsoIndex] = masterthread->y_Step[IsoIndex];
            //workerthreads[nbthreads].z_Step[IsoIndex] = masterthread->z_Step[IsoIndex];

            for (int k= 0; k < limitX; k++)
            {
                workerthreads[nbthreads].xLocal2[IsoIndex*NbMaxGrid+k] = masterthread->xLocal2[IsoIndex*NbMaxGrid+k];
                workerthreads[nbthreads].yLocal2[IsoIndex*NbMaxGrid+k] = masterthread->yLocal2[IsoIndex*NbMaxGrid+k];
                workerthreads[nbthreads].zLocal2[IsoIndex*NbMaxGrid+k] = masterthread->zLocal2[IsoIndex*NbMaxGrid+k];
            }
        }

        std::string stringtoparse=masterthread->ImplicitStructs[IsoIndex].fxyz    +
                                  masterthread->ImplicitStructs[IsoIndex].cnd  +
                                  masterthread->ImplicitStructs[IsoIndex].xmax  +
                                  masterthread->ImplicitStructs[IsoIndex].ymax  +
                                  masterthread->ImplicitStructs[IsoIndex].zmax  +
                                  masterthread->ImplicitStructs[IsoIndex].xmin   +
                                  masterthread->ImplicitStructs[IsoIndex].ymin   +
                                  masterthread->ImplicitStructs[IsoIndex].zmin;


        for(int l=0; l<masterthread->Nb_newvariables; l++)
        {
            if(stringtoparse.find(masterthread->VarName [l]+"x") !=std::string::npos )
                for(int i=0; i<limitX; i++)
                {
                    vals2[0] = masterthread->xLocal2[IsoIndex*NbMaxGrid+i];
                    vals2[1] = masterthread->stepMorph;
                    masterthread->vr2[(l*3)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i] =masterthread->Var[l] .Eval(vals2);
                    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
                        workerthreads[nbthreads].vr2[(l*3)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i] =masterthread->vr2[(l*3)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i];
                }

            if(stringtoparse.find(masterthread->VarName [l]+"y") !=std::string::npos )
                for(int i=0; i<limitY; i++)
                {
                    vals2[0] = masterthread->yLocal2[IsoIndex*NbMaxGrid+i];
                    vals2[1] = masterthread->stepMorph;
                    masterthread->vr2[(l*3+1)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i] =masterthread->Var[l] .Eval(vals2);
                    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
                        workerthreads[nbthreads].vr2[(l*3+1)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i] =masterthread->vr2[(l*3+1)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i];
                }

            if(stringtoparse.find(masterthread->VarName [l]+"z") !=std::string::npos )
                for(int i=0; i<limitZ; i++)
                {
                    vals2[0] = masterthread->zLocal2[IsoIndex*NbMaxGrid+i];
                    vals2[1] = masterthread->stepMorph;
                    masterthread->vr2[(l*3+2)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i] =masterthread->Var[l] .Eval(vals2);
                    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
                        workerthreads[nbthreads].vr2[(l*3+2)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i] =masterthread->vr2[(l*3+2)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i];
                }
        }
}

//+++++++++++++++++++++++++++++++++++++++++
void IsoWorkerThread::VoxelEvaluation(int IsoIndex)
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //double vals2[] = {0,0};
    int maxgrscalemaxgr = maximumgrid*maximumgrid;
    const int limitY = nb_colon, limitZ = nb_depth;
    int I, J, IJK;
    int id=0, signStep=0;
    float ss;

    vals[3]          = stepMorph;

    int tmp = nb_ligne/WorkerThreadsNumber;
    iStart   = MyIndex*tmp;
    if(MyIndex == (WorkerThreadsNumber-1))
        iFinish = nb_ligne;
    else
        iFinish = (MyIndex+1)*tmp;

    ss = 100.0/(iFinish*limitY*limitZ);

    for(int i=iStart; i<iFinish; i++)
    {
        vals[0] = xLocal2[IsoIndex*NbMaxGrid+i];

        for(int l=0; l<Nb_newvariables; l++)
        {
            vals[4 + l*3] = vr2[(l*3)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i];
        }

        I = i*maxgrscalemaxgr;
        for(int j=0; j<limitY; j++)
        {
            vals[1] = yLocal2[IsoIndex*NbMaxGrid+j];
            for(int l=0; l<Nb_newvariables; l++)
            {
                vals[5 + l*3] = vr2[(l*3+1)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + j];
            }

            J = I + j*maximumgrid;
            for(int k=0; k<limitZ; k++)
            {
                vals[2] = zLocal2[IsoIndex*NbMaxGrid+k];

                for(int l=0; l<Nb_newvariables; l++)
                {
                    vals[6 + l*3] = vr2[(l*3+2)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + k];
                }
                if(StopCalculations)
                    return;
                IJK = J+k;

                id++;
                if(MyIndex == 0 && morph_activated != 1)
                {
                    signalVal = (int)(id*ss);
                    if(signalVal > (signStep+1))
                    {
                        emitMySignal();
                        signStep += 2;
                    }
                }
                Results[IJK]= implicitFunctionParser[IsoIndex].Eval(vals);
                GridVoxelVarPt[IJK].Signature   = 0; // Signature initialisation
                GridVoxelVarPt[IJK].NbEdgePoint = 0; // No EdgePoint yet!
                for(int l=0; l<12; l++) GridVoxelVarPt[IJK].Edge_Points[l] = -20;
            }
        }
    }
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::ConstructIsoNormale()
{
    float val1, val2, val3, val4, val5, val6,
          pt1_x, pt1_y, pt1_z,
          pt2_x, pt2_y, pt2_z,
          pt3_x, pt3_y, pt3_z,
          scalar;
    int ThreeTimesI, IndexFirstPoint, IndexSecondPoint, IndexThirdPoint;

    for(int i = 0; i<NbTriangleIsoSurface; ++i)
    {

        ThreeTimesI   = i*3;

        IndexFirstPoint  = 3+TypeDrawin*IsoSurfaceTriangleListe[ThreeTimesI      ]+ TypeDrawin*NbVertexTmp +TypeDrawinNormStep;
        IndexSecondPoint = 3+TypeDrawin*IsoSurfaceTriangleListe[ThreeTimesI+1    ]+ TypeDrawin*NbVertexTmp +TypeDrawinNormStep;
        IndexThirdPoint  = 3+TypeDrawin*IsoSurfaceTriangleListe[ThreeTimesI+2    ]+ TypeDrawin*NbVertexTmp +TypeDrawinNormStep;

        pt1_x= NormVertexTab[IndexFirstPoint     ];
        pt1_y= NormVertexTab[IndexFirstPoint+1 ];
        pt1_z= NormVertexTab[IndexFirstPoint+2 ];

        pt2_x= NormVertexTab[IndexSecondPoint    ];
        pt2_y= NormVertexTab[IndexSecondPoint+1];
        pt2_z= NormVertexTab[IndexSecondPoint+2];

        pt3_x= NormVertexTab[IndexThirdPoint     ];
        pt3_y= NormVertexTab[IndexThirdPoint+1 ];
        pt3_z= NormVertexTab[IndexThirdPoint+2 ];

        val1 = pt2_y - pt1_y;
        val2 = pt3_z - pt1_z;
        val3 = pt2_z - pt1_z;
        val4 = pt3_y - pt1_y;
        val5 = pt3_x - pt1_x;
        val6 = pt2_x - pt1_x;

        NormOriginaltmp[ThreeTimesI  ] = val1*val2 - val3*val4;
        NormOriginaltmp[ThreeTimesI+1] = val3*val5 - val6*val2;
        NormOriginaltmp[ThreeTimesI+2] = val6*val4 - val1*val5;

        scalar = (double)sqrt((NormOriginaltmp[ThreeTimesI  ]*NormOriginaltmp[ThreeTimesI  ]) +
                              (NormOriginaltmp[ThreeTimesI+1]*NormOriginaltmp[ThreeTimesI+1]) +
                              (NormOriginaltmp[ThreeTimesI+2]*NormOriginaltmp[ThreeTimesI+2]));

        if(scalar < 0.000000001)  scalar  = 0.000000001;
        (NormOriginaltmp[ThreeTimesI  ]/=scalar);
        (NormOriginaltmp[ThreeTimesI+1]/=scalar);
        (NormOriginaltmp[ThreeTimesI+2]/=scalar);
    }
}

///++++++++++++++++++++ OutPut The IsoSurface +++++++++++++++++++++++

void Iso3D::SaveIsoGLMap()
{
    int IndexFirstPoint, IndexSecondPoint, IndexThirdPoint, ThreeTimesI;
    double scalar;

/// Recalculate the normals so we have one for each Point (like Pov Mesh) :
    for (int i=0; i < NbPointIsoMap ; i++)
    {
        ThreeTimesI = TypeDrawin*i  + TypeDrawinNormStep;
        NormVertexTab[ TypeDrawin*NbVertexTmp +ThreeTimesI  ] = 0;
        NormVertexTab[ TypeDrawin*NbVertexTmp +ThreeTimesI+1] = 0;
        NormVertexTab[ TypeDrawin*NbVertexTmp +ThreeTimesI+2] = 0;
    }

    for(int i = 0; i<NbTriangleIsoSurface; ++i)
    {
        ThreeTimesI   = i*3;
        IndexFirstPoint  = TypeDrawin*IsoSurfaceTriangleListe[ThreeTimesI   ] + TypeDrawin*NbVertexTmp  + TypeDrawinNormStep ;
        IndexSecondPoint = TypeDrawin*IsoSurfaceTriangleListe[ThreeTimesI +1] + TypeDrawin*NbVertexTmp  + TypeDrawinNormStep;
        IndexThirdPoint  = TypeDrawin*IsoSurfaceTriangleListe[ThreeTimesI +2] + TypeDrawin*NbVertexTmp  + TypeDrawinNormStep;

        NormVertexTab[IndexFirstPoint  ] += NormOriginaltmp[ThreeTimesI  ];
        NormVertexTab[IndexFirstPoint+1] += NormOriginaltmp[ThreeTimesI+1];
        NormVertexTab[IndexFirstPoint+2] += NormOriginaltmp[ThreeTimesI+2];

        NormVertexTab[IndexSecondPoint  ] += NormOriginaltmp[ThreeTimesI  ];
        NormVertexTab[IndexSecondPoint+1] += NormOriginaltmp[ThreeTimesI+1];
        NormVertexTab[IndexSecondPoint+2] += NormOriginaltmp[ThreeTimesI+2];

        NormVertexTab[IndexThirdPoint  ]  += NormOriginaltmp[ThreeTimesI  ];
        NormVertexTab[IndexThirdPoint+1]  += NormOriginaltmp[ThreeTimesI+1];
        NormVertexTab[IndexThirdPoint+2]  += NormOriginaltmp[ThreeTimesI+2];
    }

/// Normalisation
    int idx;
    for (int i=0; i < NbPointIsoMap  ; i++)
    {
        idx = TypeDrawin*i + TypeDrawinNormStep;
        scalar = (double)sqrt((NormVertexTab[idx  ]*NormVertexTab[idx  ]) +
                              (NormVertexTab[idx+1]*NormVertexTab[idx+1]) +
                              (NormVertexTab[idx+2]*NormVertexTab[idx+2]));
        if(scalar < 0.000000001)  scalar = 0.000000001;
        NormVertexTab[idx  ] /= scalar;
        NormVertexTab[idx+1] /= scalar;
        NormVertexTab[idx+2] /= scalar;
    }
}

//+++++++++++++++++++++++++++++++++++++++++//
ErrorMessage IsoMasterThread::InitNoiseParser()
{
    if(Noise != "")
    {
        NoiseParser->AddConstant("Lacunarity", Lacunarity);
        NoiseParser->AddConstant("Gain", Gain);
        NoiseParser->AddConstant("Octaves", Octaves);
        NoiseParser->AddConstant("pi", PI);
        NoiseParser->AddFunction("NoiseW",TurbulenceWorley, 6);
        NoiseParser->AddFunction("NoiseP",TurbulencePerlin, 6);

        if ((stdError.iErrorIndex = NoiseParser->Parse(Noise,"x,y,z,t")) >= 0)
        {
            stdError.strError = Noise;
            stdError.strOrigine = Noise;
        }
    }
    return stdError;
}

//++++++++++++++++++++++++++++++++++++++++++//
ErrorMessage IsoMasterThread::ParserIso()
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    varliste = "x,y,z,t";

    (Const != "") ? Nb_constants = HowManyVariables(Const, 1) : Nb_constants =0;

    initparser();

    //Evaluates defined constantes:
    for(int j=0; j<Nb_constants; j++)
    {
        if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u")) >= 0)
        {
            stdError.strError = Consts[j];
            stdError.strOrigine = ConstNames[j];
            return stdError;
        }
        ConstValues[j] = Cstparser.Eval(&vals[3]);
        Cstparser.AddConstant(ConstNames[j], ConstValues[j]);
    }

    if(Funct != "")
    {
        Nb_functs = HowManyVariables(Funct, 2);
        for(int i=0; i<Nb_functs; i++)
        {
            for(int j=0; j<Nb_constants; j++)
            {
                Fct[i].AddConstant(ConstNames[j], ConstValues[j]);
            }

            //Add predefined constatnts:
            for(int k=0; k<Nb_Sliders; k++)
            {
                Fct[i].AddConstant(SliderNames[k], SliderValues[k]);
            }
        }

        for(int i=0; i<Nb_functs; i++)
        {
            for(int j=0; j<i; j++)
                if( (UsedFunct2[i*NbDefinedFunctions+j]=(Functs[i].find(FunctNames[j]) != std::string::npos)))
                    Fct[i].AddFunction(FunctNames[j], Fct[j]);
            if ((stdError.iErrorIndex = Fct[i].Parse(Functs[i],"x,y,z,t"))>=0)
            {
                stdError.strError = Functs[i];
                stdError.strOrigine = FunctNames[i];
                return stdError;
            }
        }
    }
    else
    {
        Nb_functs =0;
    }


    if(Rgbt != "")
    {
        Nb_rgbts = HowManyVariables(Rgbt, 3);

        for(int i=0; i<Nb_rgbts; i++)
        {
            for(int j=0; j<Nb_constants; j++)
            {
                RgbtParser[i].AddConstant(ConstNames[j], ConstValues[j]);
                RgbtParser[i].AddConstant("Lacunarity", Lacunarity);
                RgbtParser[i].AddConstant("Gain", Gain);
                RgbtParser[i].AddConstant("Octaves", Octaves);
                RgbtParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
                RgbtParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
            }
        }
    }
    else
    {
        Nb_rgbts =0;
    }

    //For Solid Texture :
    if(VRgbt != "")
    {
        Nb_vrgbts = HowManyVariables(VRgbt, 4);
        for(int j=0; j<Nb_constants; j++)
        {
            GradientParser->AddConstant(ConstNames[j], ConstValues[j]);
        }

        GradientParser->AddConstant("Lacunarity", Lacunarity);
        GradientParser->AddConstant("Gain", Gain);
        GradientParser->AddConstant("Octaves", Octaves);
        GradientParser->AddFunction("NoiseW",TurbulenceWorley, 6);
        GradientParser->AddFunction("NoiseP",TurbulencePerlin, 6);

        for(int i=0; i<Nb_vrgbts; i++)
        {
            for(int j=0; j<Nb_constants; j++)
            {
                VRgbtParser[i].AddConstant(ConstNames[j], ConstValues[j]);
                VRgbtParser[i].AddConstant("Lacunarity", Lacunarity);
                VRgbtParser[i].AddConstant("Gain", Gain);
                VRgbtParser[i].AddConstant("Octaves", Octaves);
                VRgbtParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
                VRgbtParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
            }
        }
    }
    else
    {
        Nb_vrgbts =0;
    }

    if(Noise != "")
    {
        for(int j=0; j<Nb_constants; j++)
            NoiseParser->AddConstant(ConstNames[j], ConstValues[j]);
        NoiseParser->AddConstant("Lacunarity", Lacunarity);
        NoiseParser->AddConstant("Gain", Gain);
        NoiseParser->AddConstant("Octaves", Octaves);

        //Add predefined constatnts:
        for(int k=0; k<Nb_Sliders; k++)
        {
            NoiseParser->AddConstant(SliderNames[k], SliderValues[k]);
        }

    }

    if(Varu != "")
    {
        Nb_newvariables = HowManyVariables(Varu, 0);

        for(int i=0; i<Nb_newvariables; i++)
        {
            for(int j=0; j<Nb_constants; j++)
            {
                Var[i].AddConstant(ConstNames[j], ConstValues[j]);
            }


            //Add predefined constatnts:
            for(int k=0; k<Nb_Sliders; k++)
            {
                Var[i].AddConstant(SliderNames[k], SliderValues[k]);
            }

        }

        for(int i=0; i<Nb_newvariables; i++)
        {
            if ((stdError.iErrorIndex = Var[i].Parse(Varus[i],"u,tm")) >= 0)
            {
                stdError.strError = Varus[i];
                stdError.strOrigine = VarName[i];
                return stdError;
            }
            varliste += ","+VarName[i]+"x,"+VarName[i]+"y,"+VarName[i]+"z";
        }
    }
    else
    {
        Nb_newvariables =0;
    }

    //ImplicitFunction is composed of more than one isosurface:
    Nb_implicitfunctions = HowManyIsosurface(ImplicitFunction, 0);
    HowManyIsosurface(XlimitInf, 1);
    HowManyIsosurface(XlimitSup, 2);
    HowManyIsosurface(YlimitInf, 3);
    HowManyIsosurface(YlimitSup, 4);
    HowManyIsosurface(ZlimitInf, 5);
    HowManyIsosurface(ZlimitSup, 6);
    HowManyIsosurface(Grid, 7);
    if(Condition != "")
    {
        IsoConditionRequired = 1;
        HowManyIsosurface(Condition, 8);
    }
    else
        IsoConditionRequired = -1;

    //Add defined constantes:
    for(int i=0; i<Nb_implicitfunctions+1; i++)
    {
        for(int j=0; j<Nb_constants; j++)
        {
            implicitFunctionParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            if(Condition != "")
                IsoConditionParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            xSupParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            ySupParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            zSupParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            xInfParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            yInfParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            zInfParser[i].AddConstant(ConstNames[j], ConstValues[j]);
        }

        //Add predefined constatnts:
        for(int k=0; k<Nb_Sliders; k++)
        {
            implicitFunctionParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            if(Condition != "")
                IsoConditionParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            xSupParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            ySupParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            zSupParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            xInfParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            yInfParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            zInfParser[i].AddConstant(SliderNames[k], SliderValues[k]);
        }
    }

    // Add defined functions :
    if(Rgbt != "")
        for(int i=0; i<4; i++)
            for(int j=0; j<Nb_functs; j++)
            {
                RgbtParser[i].AddFunction(FunctNames[j], Fct[j]);
                RgbtParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
                RgbtParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
            }

    // Add defined functions :
    if(VRgbt != "")
    {
        for(int j=0; j<Nb_functs; j++)
        {
            GradientParser->AddFunction(FunctNames[j], Fct[j]);
            GradientParser->AddFunction("NoiseW",TurbulenceWorley, 6);
            GradientParser->AddFunction("NoiseP",TurbulencePerlin, 6);
        }

        for(int i=0; i<4; i++)
            for(int j=0; j<Nb_functs; j++)
            {
                VRgbtParser[i].AddFunction(FunctNames[j], Fct[j]);
                VRgbtParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
                VRgbtParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
            }
    }


    //delete NoiseFunction;
    //NoiseFunction = new CellNoise();

    for(int i=0; i<Nb_implicitfunctions+1; i++)
    {
        for(int j=0; j<Nb_functs; j++)
        {
            if((UsedFunct[i*NbDefinedFunctions+j]=(ImplicitStructs[i].fxyz.find(FunctNames[j]) != std::string::npos)))
            {
                implicitFunctionParser[i].AddFunction(FunctNames[j], Fct[j]);
                IsoConditionParser[i].AddFunction(FunctNames[j], Fct[j]);
            }
        }
        implicitFunctionParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
        implicitFunctionParser[i].AddFunction("fhelix1",fhelix1, 10);
        implicitFunctionParser[i].AddFunction("fhelix2",fhelix2, 10);
        implicitFunctionParser[i].AddFunction("f_hex_y",f_hex_y, 4);
        implicitFunctionParser[i].AddFunction("p_skeletal_int",p_skeletal_int, 3);
        implicitFunctionParser[i].AddFunction("fmesh",fmesh, 8);
        implicitFunctionParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
    }
    NoiseParser->AddFunction("NoiseW",TurbulenceWorley, 6);
    NoiseParser->AddFunction("NoiseP",TurbulencePerlin, 6);

    return ParseExpression(varliste);
}

///+++++++++++++++++++++++++++++++++++++++++
ErrorMessage IsoMasterThread::ParseExpression(std::string VariableListe)
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    double vals2[] = {0,0};
    const int limitX = nb_ligne, limitY = nb_colon, limitZ = nb_depth;

    if(AllComponentTraited /*&& morph_activated != 1*/)
    {
        stepMorph += pace;
    }

    vals[3]          = stepMorph;

    // Parse
    if(Rgbt!= "" && Nb_rgbts == 4)
        for(int i=0; i<Nb_rgbts; i++)
            if ((stdError.iErrorIndex = RgbtParser[i].Parse(Rgbts[i],"x,y,z,t")) >= 0)
            {
                stdError.strError = Rgbts[i];
                stdError.strOrigine = RgbtNames[i];
                return stdError;
            }

    // Parse
    if(VRgbt!= "" && (Nb_vrgbts % 5) ==0)
    {
        if ((stdError.iErrorIndex = GradientParser->Parse(Gradient,"x,y,z,t")) >= 0)
        {
            stdError.strError = Gradient;
            stdError.strOrigine = Gradient;
            return stdError;
        }

        for(int i=0; i<Nb_vrgbts; i++)
            if ((stdError.iErrorIndex = VRgbtParser[i].Parse(VRgbts[i],"x,y,z,t")) >= 0)
            {
                stdError.strError = VRgbts[i];
                stdError.strOrigine = VRgbtNames[i];
                return stdError;
            }
    }

    if(Noise != "")
        if ((stdError.iErrorIndex = NoiseParser->Parse(Noise,"x,y,z,t")) >= 0)
        {
            stdError.strError = Noise;
            stdError.strOrigine = Noise;
            return stdError;
        }

    for(int i=0; i<Nb_implicitfunctions+1; i++)
    {
        if ((stdError.iErrorIndex = implicitFunctionParser[i].Parse(ImplicitStructs[i].fxyz,VariableListe)) >= 0)
        {
            stdError.strError = ImplicitStructs[i].fxyz;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
        if(Condition != "")
        {
            if ((stdError.iErrorIndex = IsoConditionParser[i].Parse(ImplicitStructs[i].cnd,"x,y,z,t")) >= 0)
            {
                stdError.strError = ImplicitStructs[i].cnd;
                stdError.strOrigine = ImplicitStructs[i].index;
                return stdError;
            }
        }

        if ((stdError.iErrorIndex = xSupParser[i].Parse(ImplicitStructs[i].xmax, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].xmax;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
        if ((stdError.iErrorIndex = ySupParser[i].Parse(ImplicitStructs[i].ymax, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].ymax;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
        if ((stdError.iErrorIndex = zSupParser[i].Parse(ImplicitStructs[i].zmax, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].zmax;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
        if ((stdError.iErrorIndex = xInfParser[i].Parse(ImplicitStructs[i].xmin, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].xmin;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
        if ((stdError.iErrorIndex = yInfParser[i].Parse(ImplicitStructs[i].ymin, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].ymin;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
        if ((stdError.iErrorIndex = zInfParser[i].Parse(ImplicitStructs[i].zmin, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].zmin;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
    }

    for(int IsoIndex=0; IsoIndex<Nb_implicitfunctions+1; IsoIndex++)
    {
        xLocal2[IsoIndex*NbMaxGrid]=xSupParser[IsoIndex].Eval(vals);
        yLocal2[IsoIndex*NbMaxGrid]=ySupParser[IsoIndex].Eval(vals);
        zLocal2[IsoIndex*NbMaxGrid]=zSupParser[IsoIndex].Eval(vals);

        x_Step[IsoIndex] = (xLocal2[IsoIndex*NbMaxGrid] - xInfParser[IsoIndex].Eval(vals))/(limitX-1);
        y_Step[IsoIndex] = (yLocal2[IsoIndex*NbMaxGrid] - yInfParser[IsoIndex].Eval(vals))/(limitY-1);
        z_Step[IsoIndex] = (zLocal2[IsoIndex*NbMaxGrid] - zInfParser[IsoIndex].Eval(vals))/(limitZ-1);

        for (int i= 1; i < limitX; i++) xLocal2[IsoIndex*NbMaxGrid+i] = xLocal2[IsoIndex*NbMaxGrid+i-1] - x_Step[IsoIndex];
        for (int j= 1; j < limitY; j++) yLocal2[IsoIndex*NbMaxGrid+j] = yLocal2[IsoIndex*NbMaxGrid+j-1] - y_Step[IsoIndex];
        for (int k= 1; k < limitZ; k++) zLocal2[IsoIndex*NbMaxGrid+k] = zLocal2[IsoIndex*NbMaxGrid+k-1] - z_Step[IsoIndex];

        std::string stringtoparse=ImplicitStructs[IsoIndex].fxyz    +
                                  ImplicitStructs[IsoIndex].cnd  +
                                  ImplicitStructs[IsoIndex].xmax  +
                                  ImplicitStructs[IsoIndex].ymax  +
                                  ImplicitStructs[IsoIndex].zmax  +
                                  ImplicitStructs[IsoIndex].xmin   +
                                  ImplicitStructs[IsoIndex].ymin   +
                                  ImplicitStructs[IsoIndex].zmin;


        for(int l=0; l<Nb_newvariables; l++)
        {
            if(stringtoparse.find(VarName [l]+"x") !=std::string::npos )
                for(int i=0; i<limitX; i++)
                {
                    vals2[0] = xLocal2[IsoIndex*NbMaxGrid+i];
                    vals2[1] = stepMorph;
                    vr2[(l*3)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i] =Var[l] .Eval(vals2);
                }

            if(stringtoparse.find(VarName [l]+"y") !=std::string::npos )
                for(int i=0; i<limitY; i++)
                {
                    vals2[0] = yLocal2[IsoIndex*NbMaxGrid+i];
                    vals2[1] = stepMorph;
                    vr2[(l*3+1)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i] =Var[l] .Eval(vals2);
                }

            if(stringtoparse.find(VarName [l]+"z") !=std::string::npos )
                for(int i=0; i<limitZ; i++)
                {
                    vals2[0] = zLocal2[IsoIndex*NbMaxGrid+i];
                    vals2[1] = stepMorph;
                    vr2[(l*3 + 2)*NbComponent*NbMaxGrid + IsoIndex*NbMaxGrid + i] =Var[l] .Eval(vals2);
                }
        }
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
        delete[] Var;
        delete[] IsoConditionParser;
        delete[] VRgbtParser;
        delete[] RgbtParser;
        delete GradientParser;
        delete NoiseParser;
        ParsersAllocated = false;
    }
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
    for(int i=0; i<ImplicitFunctionSize; i++)
    {
        implicitFunctionParser[i].AddConstant("pi", PI);
        IsoConditionParser[i].AddConstant("pi", PI);
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

    for(int i=0; i<VaruSize; i++)
    {
        Var[i].AddConstant("pi", PI);
    }

    for(int i=0; i<FunctSize; i++)
    {
        Fct[i].AddConstant("pi", PI);
        Fct[i].AddFunction("NoiseW",TurbulenceWorley, 6);
        Fct[i].AddFunction("fhelix1",fhelix1, 10);
        Fct[i].AddFunction("fhelix2",fhelix2, 10);
        Fct[i].AddFunction("f_hex_y",f_hex_y, 4);
        Fct[i].AddFunction("p_skeletal_int",p_skeletal_int, 3);
        Fct[i].AddFunction("fmesh",fmesh, 8);
        Fct[i].AddFunction("NoiseP",TurbulencePerlin, 6);
    }

    for(int i=0; i<NbTextures; i++)
    {
        RgbtParser[i].AddConstant("pi", PI);
        RgbtParser[i].AddConstant("Lacunarity", Lacunarity);
        RgbtParser[i].AddConstant("Gain", Gain);
        RgbtParser[i].AddConstant("Octaves", Octaves);
        RgbtParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
        RgbtParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
    }

    for(int i=0; i<NbTextures; i++)
    {
        VRgbtParser[i].AddConstant("pi", PI);
        VRgbtParser[i].AddConstant("Lacunarity", Lacunarity);
        VRgbtParser[i].AddConstant("Gain", Gain);
        VRgbtParser[i].AddConstant("Octaves", Octaves);
        VRgbtParser[i].AddFunction("NoiseW",TurbulenceWorley, 6);
        VRgbtParser[i].AddFunction("NoiseP",TurbulencePerlin, 6);
    }

    GradientParser->AddConstant("pi", PI);
    GradientParser->AddConstant("Lacunarity", Lacunarity);
    GradientParser->AddConstant("Gain", Gain);
    GradientParser->AddConstant("Octaves", Octaves);
    GradientParser->AddFunction("NoiseW",TurbulenceWorley, 6);
    GradientParser->AddFunction("NoiseP",TurbulencePerlin, 6);
}

///+++++++++++++++++++++++++++++++++++++++++
void IsoMasterThread::AllocateMasterParsers()
{
    if(!ParsersAllocated)
    {
        NoiseParser = new FunctionParser;
        implicitFunctionParser = new FunctionParser[ImplicitFunctionSize];
        xSupParser = new FunctionParser[ImplicitFunctionSize];
        ySupParser = new FunctionParser[ImplicitFunctionSize];
        zSupParser = new FunctionParser[ImplicitFunctionSize];
        xInfParser = new FunctionParser[ImplicitFunctionSize];
        yInfParser = new FunctionParser[ImplicitFunctionSize];
        zInfParser = new FunctionParser[ImplicitFunctionSize];
        IsoConditionParser = new FunctionParser[ImplicitFunctionSize];
        Fct = new FunctionParser[FunctSize];
        Var = new FunctionParser[VaruSize];

        RgbtParser = new FunctionParser[NbTextures];
        VRgbtParser = new FunctionParser[NbTextures];
        GradientParser = new FunctionParser;
        ParsersAllocated = true;
    }
}

///+++++++++++++++++++++++++++++++++++++++++
void IsoWorkerThread::AllocateParsersForWorkerThread(int nbcomp, int nbfunct)
{
    if(!ParsersAllocated)
    {
        implicitFunctionParser = new FunctionParser[nbcomp];
        Fct = new FunctionParser[nbfunct];
        ParsersAllocated = true;
    }
}

void IsoMasterThread::AllocateParsersForMasterThread()
{
    AllocateMasterParsers();
    InitMasterParsers();
}

///+++++++++++++++++++++++++++++++++++++++++
void IsoMasterThread::initparser()
{
    DeleteMasterParsers();
    AllocateMasterParsers();
    InitMasterParsers();
}

///+++++++++++++++++++++++++++++++++++++++++
void IsoWorkerThread::IsoCompute(int fctnb)
{
    (fctnb == 0) ? AllComponentTraited = true : AllComponentTraited = false;
    VoxelEvaluation(fctnb);
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::stopcalculations(bool calculation)
{
    StopCalculations = calculation;
    masterthread->StopCalculations = calculation;
    for(int nbthreads=0; nbthreads< WorkerThreadsNumber-1; nbthreads++)
        workerthreads[nbthreads].StopCalculations = StopCalculations;
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::IsoBuild (
    float *NormVertexTabPt,
    unsigned int *IndexPolyTabPt,
    unsigned   int *PolyNumber,
    unsigned int *VertexNumberpt,
    unsigned int *IndexPolyTabMinPt,
    unsigned  int *NbPolyMinPt,
    struct ComponentInfos *components,
    int *TriangleListeCND,
    bool *typeCND
)
{

    int    ThreeTimesI, l, NbTriangleIsoSurfaceTmp;
    //NormVertexTab = NormVertexTabPt;
    PreviousSizeMinimalTopology = 0;
    NbPolyMinimalTopology = 0;
    NbPointIsoMap= 0;
    NbVertexTmp = NbTriangleIsoSurfaceTmp =  0;

    IndexPolyTabMin = IndexPolyTabMinPt;
    IndexPolyTab = IndexPolyTabPt;
    if(components != NULL)
        components->NbIso = masterthread->Nb_implicitfunctions+1;

    if(TriangleListeCND != NULL)
        TypeIsoSurfaceTriangleListeCND = TriangleListeCND;

    if(typeCND != NULL)
        WichPointVerifyCond = typeCND;

    stopcalculations(false);

    // generate Isosurface for all the implicit formulas
    for(int fctnb= 0; fctnb< masterthread->Nb_implicitfunctions+1; fctnb++)
    {
        masterthread->CurrentIso = fctnb;
        for(int nbthreads=0; nbthreads< WorkerThreadsNumber-1; nbthreads++)
            workerthreads[nbthreads].CurrentIso = fctnb;

        for(int nbthreads=0; nbthreads< WorkerThreadsNumber-1; nbthreads++)
            workerthreads[nbthreads].stepMorph = masterthread->stepMorph;

        if(masterthread->morph_activated == 1)
        {
            if(fctnb == 0)
            {
            //This code is to ensure that stepmorph values are the same accross all threads because tests show that
            //it's not allways the case when this code is spread inside threads Run() functions!
            masterthread->stepMorph += masterthread->pace;
            for(int nbthreads=0; nbthreads< WorkerThreadsNumber-1; nbthreads++)
                workerthreads[nbthreads].stepMorph = masterthread->stepMorph;
            }
            // Recalculate some tables values:
            ReinitVarTablesWhenMorphActiv(fctnb);
        }

        masterthread->start();
        for(int nbthreads=0; nbthreads< WorkerThreadsNumber-1; nbthreads++)
            workerthreads[nbthreads].start();

        masterthread->wait();
        for(int nbthreads=0; nbthreads< WorkerThreadsNumber-1; nbthreads++)
            workerthreads[nbthreads].wait();

        if(StopCalculations)
            return;
        PointEdgeComputation(fctnb);
        SignatureComputation();
        ConstructIsoSurface();
        ConstructIsoNormale();
        SaveIsoGLMap();
        SetMiniMmeshStruct();

        // Save the Index:
        l = 3*NbTriangleIsoSurfaceTmp;
        if(components != NULL)
        {
            components->IsoPositions[2*fctnb       ] = l; //save the starting position of this component
            components->IsoPositions[2*fctnb + 1] = NbTriangleIsoSurface; //save the number of triangles of this component

            components->IsoPts[2*fctnb       ] = NbVertexTmp;
            components->IsoPts[2*fctnb  +1] = NbVertexTmp + NbPointIsoMap -1;
        }
        for (int i=0; i < NbTriangleIsoSurface ; ++i)
        {
            ThreeTimesI = 3*i;
            IndexPolyTab[l    ] = IsoSurfaceTriangleListe[ThreeTimesI     ] + NbVertexTmp;
            IndexPolyTab[l+1] = IsoSurfaceTriangleListe[ThreeTimesI+1] + NbVertexTmp;
            IndexPolyTab[l+2] = IsoSurfaceTriangleListe[ThreeTimesI+2] + NbVertexTmp;
            l+=3;
        }
        // Save Number of Polys and vertex :
        NbVertexTmp                        += NbPointIsoMap;
        NbTriangleIsoSurfaceTmp   += NbTriangleIsoSurface;
    }

    //CND calculation for the triangles results:
    CNDCalculation(NbTriangleIsoSurfaceTmp, components);

    // Pigment, Texture and Noise :
    if(masterthread->VRgbt != "" && (masterthread->Nb_vrgbts %5)==0 )
    {
        components->ThereisRGBA = true;
        components->NoiseParam.NoiseType = 0; //Pigments
        components->NoiseParam.VRgbtParser = masterthread->VRgbtParser;
        components->NoiseParam.GradientParser = masterthread->GradientParser;
        components->NoiseParam.NoiseParser =  masterthread->NoiseParser;
        components->NoiseParam.Nb_vrgbts = masterthread->Nb_vrgbts;
    }
    else if(masterthread->Nb_rgbts >= 4)
    {
        components->ThereisRGBA = true;
        components->NoiseParam.NoiseType = 1; //Texture
        components->NoiseParam.RgbtParser = masterthread->RgbtParser;
        components->NoiseParam.NoiseParser =  masterthread->NoiseParser;
    }
    else
    {
        components->ThereisRGBA = false;
        components->NoiseParam.NoiseType = -1; //No Pigments or texture
    }

    if(masterthread->Noise == "")
        components->NoiseParam.NoiseShape = 0;
    else
        components->NoiseParam.NoiseShape = 1;

    CalculateColorsPoints(components);

    // Save Number of Polys and vertex :
    *PolyNumber = 3*NbTriangleIsoSurfaceTmp;

    // Index Polygones:
    *NbPolyMinPt = NbPolyMinimalTopology;

    // Vertex :
    *VertexNumberpt = NbVertexTmp;
    memcpy(NormVertexTabPt, NormVertexTab, 10*NbVertexTmp*sizeof(float));
    /*
    float *tmpNormvert;
    static int Action=0;
    if(Action == 0)
    {
        memcpy(NormVertexTabPt, NormVertexTab, 10*NbVertexTmp*sizeof(float));
        Action++;
    }
    else
    {
        tmpNormvert = NormVertexTab;
        NormVertexTab = NormVertexTabPt;
        NormVertexTabPt = tmpNormvert;
    }
    */
}
///+++++++++++++++++++++++++++++++++++++++++
int Iso3D::CNDtoUse(int index, struct ComponentInfos *components)
{
    for(int fctnb= 0; fctnb< masterthread->Nb_implicitfunctions+1; fctnb++)
        if( index <= components->IsoPts[2*fctnb +1] && index >= components->IsoPts[2*fctnb])
            return fctnb;
    return 30;
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::CalculateColorsPoints(struct ComponentInfos *components)
{
    double tmp, ValCol[NbTextures+5], val[4];
    val[3] = masterthread->stepMorph;

    if(components->ThereisRGBA == true &&  components->NoiseParam.NoiseType == 0)
    {
        for(int i=0; i<masterthread->Nb_vrgbts && i<NbTextures; i++)
        {
            ValCol[i] = masterthread->VRgbtParser[i].Eval(val);
        }

        for(int i= 0; i < NbVertexTmp; i++)
        {
            val[0]= NormVertexTab[i*TypeDrawin  + 3 + TypeDrawinNormStep ];
            val[1]= NormVertexTab[i*TypeDrawin  + 4 + TypeDrawinNormStep ];
            val[2]= NormVertexTab[i*TypeDrawin  + 5 + TypeDrawinNormStep ];

            if(masterthread->Noise != "")
                tmp  = masterthread->NoiseParser->Eval(val);
            else
                tmp =1.0;

            val[0]= tmp*NormVertexTab[i*TypeDrawin  + 3 + TypeDrawinNormStep ];
            val[1]= tmp*NormVertexTab[i*TypeDrawin  + 4 + TypeDrawinNormStep ];
            val[2]= tmp*NormVertexTab[i*TypeDrawin  + 5 + TypeDrawinNormStep ];

            tmp  = masterthread->GradientParser->Eval(val);

            int c= (int)tmp;
            tmp = std::abs(tmp - (double)c);
            for (int j=0; j < masterthread->Nb_vrgbts && j < NbTextures; j+=5)
                if(tmp <= ValCol[j])
                {
                    NormVertexTab[i*TypeDrawin    ] = ValCol[j+1];
                    NormVertexTab[i*TypeDrawin+1] = ValCol[j+2];
                    NormVertexTab[i*TypeDrawin+2] = ValCol[j+3];
                    NormVertexTab[i*TypeDrawin+3] = ValCol[j+4];
                    j = NbTextures;
                }
        }
    }
    else if(components->ThereisRGBA == true &&  components->NoiseParam.NoiseType == 1)
    {
        for(int i= 0; i < NbVertexTmp; i++)
        {
            val[0]= NormVertexTab[i*TypeDrawin  + 3 + TypeDrawinNormStep ];
            val[1]= NormVertexTab[i*TypeDrawin  + 4 + TypeDrawinNormStep ];
            val[2]= NormVertexTab[i*TypeDrawin  + 5 + TypeDrawinNormStep ];

            if(masterthread->Noise != "")
                tmp  = masterthread->NoiseParser->Eval(val);
            else
                tmp =1.0;

            val[0]= tmp*NormVertexTab[i*TypeDrawin  +3+TypeDrawinNormStep ];
            val[1]= tmp*NormVertexTab[i*TypeDrawin  +4+TypeDrawinNormStep ];
            val[2]= tmp*NormVertexTab[i*TypeDrawin  +5+TypeDrawinNormStep ];

            NormVertexTab[i*TypeDrawin  ] = masterthread->RgbtParser[0].Eval(val);
            NormVertexTab[i*TypeDrawin+1] = masterthread->RgbtParser[1].Eval(val);
            NormVertexTab[i*TypeDrawin+2] = masterthread->RgbtParser[2].Eval(val);
            NormVertexTab[i*TypeDrawin+3] = masterthread->RgbtParser[3].Eval(val);
        }
    }
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::CNDCalculation(int NbTriangleIsoSurfaceTmp, struct ComponentInfos *components)
{
    double vals[4];
    vals[3] = masterthread->stepMorph;
    if (masterthread->IsoConditionRequired == 1)
    {
        for(int i= 0; i < NbVertexTmp; i++)
        {
            vals[0] = NormVertexTab[i*TypeDrawin+3+ TypeDrawinNormStep];
            vals[1] = NormVertexTab[i*TypeDrawin+4+ TypeDrawinNormStep];
            vals[2] = NormVertexTab[i*TypeDrawin+5+ TypeDrawinNormStep];
            WichPointVerifyCond[i] = (masterthread->IsoConditionParser[CNDtoUse(i, components)].Eval(vals) == 1);
            if(WichPointVerifyCond[i])
            {
                NormVertexTab[i*TypeDrawin      ] = 0.1;
                NormVertexTab[i*TypeDrawin  +1] = 0.9;
                NormVertexTab[i*TypeDrawin  +2] = 0.0;
                NormVertexTab[i*TypeDrawin  +3] = 1.0;
            }
            else
            {
                NormVertexTab[i*TypeDrawin      ] = 0.9;
                NormVertexTab[i*TypeDrawin  +1] = 0.1;
                NormVertexTab[i*TypeDrawin  +2] = 0.0;
                NormVertexTab[i*TypeDrawin  +3] = 1.0;
            }
        }
        int Aindex, Bindex, Cindex;
        int nbtriangle = NbTriangleIsoSurfaceTmp;
        for(int i= 0; i < nbtriangle; i++)
        {
            Aindex = IndexPolyTab[3*i       ];
            Bindex = IndexPolyTab[3*i + 1];
            Cindex = IndexPolyTab[3*i + 2];
            //Init this triangle type to 1:
            TypeIsoSurfaceTriangleListeCND[i] = 1;
            int TypeTriangle = -1;
            if(WichPointVerifyCond[Aindex] && !WichPointVerifyCond[Bindex] && !WichPointVerifyCond[Cindex])
                TypeTriangle = 0;
            else if(!WichPointVerifyCond[Aindex] && WichPointVerifyCond[Bindex] && WichPointVerifyCond[Cindex])
                TypeTriangle = 1;
            else if(!WichPointVerifyCond[Aindex] && WichPointVerifyCond[Bindex] && !WichPointVerifyCond[Cindex])
                TypeTriangle = 2;
            else if(WichPointVerifyCond[Aindex] && !WichPointVerifyCond[Bindex] && WichPointVerifyCond[Cindex])
                TypeTriangle = 3;
            else if(!WichPointVerifyCond[Aindex] && !WichPointVerifyCond[Bindex] && WichPointVerifyCond[Cindex])
                TypeTriangle = 4;
            else if(WichPointVerifyCond[Aindex] && WichPointVerifyCond[Bindex] && !WichPointVerifyCond[Cindex])
                TypeTriangle = 5;
            else if(!WichPointVerifyCond[Aindex] && !WichPointVerifyCond[Bindex] && !WichPointVerifyCond[Cindex])
            {
                TypeTriangle = 6;
                TypeIsoSurfaceTriangleListeCND[i] = -1;
            }
            else if(WichPointVerifyCond[Aindex] && WichPointVerifyCond[Bindex] && WichPointVerifyCond[Cindex])
            {
                TypeTriangle = 7;
                TypeIsoSurfaceTriangleListeCND[i] = 1;
            }

            if(TypeTriangle == 2 || TypeTriangle == 3)
            {
                Aindex = IndexPolyTab[3*i  +1];
                Bindex = IndexPolyTab[3*i + 2];
                Cindex = IndexPolyTab[3*i      ];
            }
            else if(TypeTriangle == 4 || TypeTriangle == 5)
            {
                Aindex = IndexPolyTab[3*i  + 2];
                Bindex = IndexPolyTab[3*i       ];
                Cindex = IndexPolyTab[3*i  + 1];
            }

            double Bprime[4], Cprime[4], DiffX, DiffY, DiffZ;
            int Alfa;
            int cnd = CNDtoUse(Aindex, components);
            if(TypeTriangle >=0 && TypeTriangle <= 5)
            {
                /// Bprime
                Bprime[0] = NormVertexTab[3+TypeDrawin*Aindex  + TypeDrawinNormStep];
                Bprime[1] = NormVertexTab[3+TypeDrawin*Aindex+1+ TypeDrawinNormStep];
                Bprime[2] = NormVertexTab[3+TypeDrawin*Aindex+2+ TypeDrawinNormStep];
                Bprime[3] = masterthread->stepMorph;

                DiffX = (NormVertexTab[3+TypeDrawin*Bindex  + TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex  + TypeDrawinNormStep])/20;
                DiffY = (NormVertexTab[3+TypeDrawin*Bindex+1+ TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex+1+ TypeDrawinNormStep])/20;
                DiffZ = (NormVertexTab[3+TypeDrawin*Bindex+2+ TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex+2+ TypeDrawinNormStep])/20;
                Alfa = 0;
                if(TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4)
                {
                    while(masterthread->IsoConditionParser[cnd].Eval(Bprime) == 1 && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!(masterthread->IsoConditionParser[cnd].Eval(Bprime) == 1) && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }

                /// Cprime
                Cprime[0] = NormVertexTab[3+TypeDrawin*Aindex  + TypeDrawinNormStep];
                Cprime[1] = NormVertexTab[3+TypeDrawin*Aindex+1+ TypeDrawinNormStep];
                Cprime[2] = NormVertexTab[3+TypeDrawin*Aindex+2+ TypeDrawinNormStep];
                Cprime[3] = masterthread->stepMorph;

                DiffX = (NormVertexTab[3+TypeDrawin*Cindex    + TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex     + TypeDrawinNormStep])/20;
                DiffY = (NormVertexTab[3+TypeDrawin*Cindex+1+ TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex+1+ TypeDrawinNormStep])/20;
                DiffZ = (NormVertexTab[3+TypeDrawin*Cindex+2+ TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex+2+ TypeDrawinNormStep])/20;
                Alfa = 0;
                if(TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4)
                {
                    while(masterthread->IsoConditionParser[cnd].Eval(Cprime) == 1 && (Alfa < 20))
                    {
                        Cprime[0] += DiffX;
                        Cprime[1] += DiffY;
                        Cprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!(masterthread->IsoConditionParser[cnd].Eval(Cprime) == 1) && (Alfa < 20))
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
                NormVertexTab[TypeDrawin*NbVertexTmp+3+ TypeDrawinNormStep] = Bprime[0];
                NormVertexTab[TypeDrawin*NbVertexTmp+4+ TypeDrawinNormStep] = Bprime[1];
                NormVertexTab[TypeDrawin*NbVertexTmp+5+ TypeDrawinNormStep] = Bprime[2];

                NormVertexTab[TypeDrawin*NbVertexTmp     + TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Bindex      + TypeDrawinNormStep];
                NormVertexTab[TypeDrawin*NbVertexTmp +1+ TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Bindex + 1+ TypeDrawinNormStep];
                NormVertexTab[TypeDrawin*NbVertexTmp +2+ TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Bindex + 2+ TypeDrawinNormStep];

                NormVertexTab[TypeDrawin*NbVertexTmp     ] = 1.0;
                NormVertexTab[TypeDrawin*NbVertexTmp +1] = 1.0;
                NormVertexTab[TypeDrawin*NbVertexTmp +2] = 1.0;
                NormVertexTab[TypeDrawin*NbVertexTmp +3] = 1.0;

                //Add Cprime:
                NormVertexTab[TypeDrawin*NbVertexTmp+ 3 + TypeDrawin + TypeDrawinNormStep] = Cprime[0];
                NormVertexTab[TypeDrawin*NbVertexTmp+ 4 + TypeDrawin + TypeDrawinNormStep] = Cprime[1];
                NormVertexTab[TypeDrawin*NbVertexTmp+ 5 + TypeDrawin + TypeDrawinNormStep] = Cprime[2];

                NormVertexTab[TypeDrawin*NbVertexTmp +     TypeDrawin+ TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Cindex      + TypeDrawinNormStep];
                NormVertexTab[TypeDrawin*NbVertexTmp +1+ TypeDrawin+ TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Cindex + 1+ TypeDrawinNormStep];
                NormVertexTab[TypeDrawin*NbVertexTmp +2+ TypeDrawin+ TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Cindex + 2+ TypeDrawinNormStep];

                NormVertexTab[TypeDrawin*NbVertexTmp      + TypeDrawin] = 1.0;
                NormVertexTab[TypeDrawin*NbVertexTmp +1 + TypeDrawin] = 1.0;
                NormVertexTab[TypeDrawin*NbVertexTmp +2 + TypeDrawin] = 1.0;
                NormVertexTab[TypeDrawin*NbVertexTmp +3 + TypeDrawin] = 1.0;

                NbVertexTmp += 2;

                //***********
                //Add triangles:
                //***********
                /// Add Three new triangles :
                int IndexBprime = (NbVertexTmp-2);
                int IndexCprime = (NbVertexTmp-1);
                int IndexNbTriangle;

                // The original triangle will be replaced by four other triangles:
                TypeIsoSurfaceTriangleListeCND[i] = 0;

                /// (A, Bprime, Cprime)
                IndexNbTriangle = NbTriangleIsoSurfaceTmp*3;
                IndexPolyTab[IndexNbTriangle  ] = Aindex;
                IndexPolyTab[IndexNbTriangle+1] = IndexBprime;
                IndexPolyTab[IndexNbTriangle+2] = IndexCprime;
                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = 1 : TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = -1;
                //TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = -1;
                NbTriangleIsoSurfaceTmp++;

                IndexPolyTabMin[PreviousSizeMinimalTopology++] = 3;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = Aindex;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexBprime;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexCprime;
                NbPolyMinimalTopology++;

                /// (Bprime, B, C)
                IndexNbTriangle = NbTriangleIsoSurfaceTmp*3;
                IndexPolyTab[IndexNbTriangle  ] = IndexBprime;
                IndexPolyTab[IndexNbTriangle+1] = Bindex;
                IndexPolyTab[IndexNbTriangle+2] = Cindex;
                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = -1 : TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = 1;
                //TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = 1;
                NbTriangleIsoSurfaceTmp++;

                IndexPolyTabMin[PreviousSizeMinimalTopology++] = 3;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexBprime;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = Bindex;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = Cindex;
                NbPolyMinimalTopology++;

                /// (Bprime, C, Cprime)
                IndexNbTriangle = NbTriangleIsoSurfaceTmp*3;
                IndexPolyTab[IndexNbTriangle  ] = IndexBprime;
                IndexPolyTab[IndexNbTriangle+1] = Cindex;
                IndexPolyTab[IndexNbTriangle+2] = IndexCprime;
                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = -1 : TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = 1;
                //TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = 1;
                NbTriangleIsoSurfaceTmp++;

                IndexPolyTabMin[PreviousSizeMinimalTopology++] = 3;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexBprime;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = Cindex;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexCprime;
                NbPolyMinimalTopology++;

                /// (Bprime, Cprime) --> the border
                IndexNbTriangle = NbTriangleIsoSurfaceTmp*3;
                IndexPolyTab[IndexNbTriangle  ] = IndexBprime;
                IndexPolyTab[IndexNbTriangle+1] = IndexCprime;
                IndexPolyTab[IndexNbTriangle+2] = IndexCprime;
                TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = 4; /// Type = 4-->Border
                NbTriangleIsoSurfaceTmp++;

                IndexPolyTabMin[PreviousSizeMinimalTopology++] = 3;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexBprime;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexCprime;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexCprime;
                NbPolyMinimalTopology++;
            }
        }

        //***********
        //Reorganize the triangles index:
        //***********
        unsigned int *NewIndexPolyTab = new unsigned int[3*NbTriangleIsoSurfaceTmp];
        int k, l, M;
        k = l = M =0;
        for(int i=0; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCND[i] == 1)
            {
                NewIndexPolyTab[3*k      ] =  IndexPolyTab[3*i      ];
                NewIndexPolyTab[3*k + 1] =  IndexPolyTab[3*i + 1];
                NewIndexPolyTab[3*k + 2] =  IndexPolyTab[3*i + 2];
                k++;
            }

        for(int i=0; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCND[i] == -1)
            {
                NewIndexPolyTab[3*(l + k)       ] =  IndexPolyTab[3*i      ];
                NewIndexPolyTab[3*(l + k) + 1] =  IndexPolyTab[3*i + 1];
                NewIndexPolyTab[3*(l + k) + 2] =  IndexPolyTab[3*i + 2];
                l++;
            }

        for(int i=0; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCND[i] == 4)
            {
                NewIndexPolyTab[3*(M + l + k)      ] =  IndexPolyTab[3*i      ];
                NewIndexPolyTab[3*(M + l + k) + 1] =  IndexPolyTab[3*i + 1];
                NewIndexPolyTab[3*(M + l + k) + 2] =  IndexPolyTab[3*i + 2];
                M++;
            }

        //Copy the new index in the original one:
        memcpy(IndexPolyTab, NewIndexPolyTab, 3*(M + l + k)*sizeof(unsigned int));
        NbTriangleIsoSurfaceTmp = M + l + k;
        delete[] (NewIndexPolyTab);

        components->NbTrianglesVerifyCND = k;
        components->NbTrianglesNotVerifyCND = l;
        components->NbTrianglesBorderCND = M;

        for(int fctnb= 0; fctnb< masterthread->Nb_implicitfunctions+1; fctnb++)
        {
            if(components != NULL)
            {
                //if(components->IsoPositions[2*fctnb + 1] > NbTriangleIsoSurfaceTmp )
                components->IsoPositions[2*fctnb + 1] = NbTriangleIsoSurfaceTmp;
            }
        }
        components->ThereisCND = true;

    }
    else
    {
        components->ThereisCND = false;

        for(int i= 0; i < NbVertexTmp; i++)
        {
            NormVertexTab[i*TypeDrawin    ] = 0.5;
            NormVertexTab[i*TypeDrawin+1] = 0.6;
            NormVertexTab[i*TypeDrawin+2] = 0.8;
            NormVertexTab[i*TypeDrawin+3] = 1.0;
        }
    }
}
///+++++++++++++++++++++++++++++++++++++++++
Iso3D::~Iso3D()
{

}

///++++++++++++++++++++ ConstructIsoSurface +++++++++++++++++++++++++++
void Iso3D::SetMiniMmeshStruct()
{
    int Index, iter, nbpl, iterpl, lnew;
    int I, J, IJK, i, j, k;
    int maxgrscalemaxgr = NbMaxGrid*NbMaxGrid;

    lnew = 0;
    NbPolyMin = 0;
    /// Copy Index Polygons :
    for(i=0; i < nb_ligne-1; i++)
    {
        I  = i*maxgrscalemaxgr;
        for(j=0; j < nb_colon-1; j++)
        {
            J  = I+j*NbMaxGrid;
            for(k=0; k < nb_depth-1; k++)
            {
                IJK = J+k;
                Index = GridVoxelVarPt[IJK].Signature;
                nbpl = triTable_min[Index][16];

                if( nbpl == 1)
                {
                    NbPolyMin += nbpl;
                    IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = triTable_min[Index][17];
                    for(iter = 0; iter < triTable_min[Index][17]; iter++)
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter]]  + NbVertexTmp;
                }
                else if( nbpl == 2)
                {
                    NbPolyMin += nbpl;
                    /// First Poly:
                    IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = triTable_min[Index][17];
                    for(iter = 0; iter < triTable_min[Index][17]; iter++)
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter]]  + NbVertexTmp;
                    /// Second Poly:
                    IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = triTable_min[Index][18];
                    for(iter = triTable_min[Index][17]; iter < triTable_min[Index][17]+triTable_min[Index][18]; iter++)
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter]]  + NbVertexTmp;
                }
                else if( nbpl > 2)
                {
                    NbPolyMin += nbpl;
                    /// In this case we have only Triangles (3 or 4):
                    iter = 0;
                    for(iterpl = 0; iterpl < nbpl; iterpl++)
                    {
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = 3;
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter  ]]  + NbVertexTmp;
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter+1]]  + NbVertexTmp;
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter+2]]  + NbVertexTmp;
                        iter +=3;
                    }
                }

            } /// End of for(k=0;
        } /// End of for(j=0;
    } /// End of for(i=0;

    PreviousSizeMinimalTopology += lnew;
    NbPolyMinimalTopology += NbPolyMin;
}

///++++++++++++++++++++ ConstructIsoSurface +++++++++++++++++++++++++++
void Iso3D::ConstructIsoSurface()
{
    int IndexNbTriangle, Index, IndexFirstPoint, IndexSeconPoint, IndexThirdPoint, limitX;
    int I, J, IJK;
    int maxgrscalemaxgr = NbMaxGrid*NbMaxGrid;

    NbTriangleIsoSurface = 0;
    limitX = nb_ligne;
    for(int i=0; i < limitX-1; i++)
    {
        I   = i*maxgrscalemaxgr;
        for(int j=0; j < nb_colon-1; j++)
        {
            J   = I+j*NbMaxGrid;
            for(int k=0; k < nb_depth-1; k++)
            {
                IJK = J+k;
                Index = GridVoxelVarPt[IJK].Signature;
                for (int l = 0; triTable[Index][l] != -1; l += 3)
                {
                    IndexFirstPoint = GridVoxelVarPt[IJK].Edge_Points[triTable[Index][l  ]];
                    IndexSeconPoint = GridVoxelVarPt[IJK].Edge_Points[triTable[Index][l+1]];
                    IndexThirdPoint = GridVoxelVarPt[IJK].Edge_Points[triTable[Index][l+2]];
                    {
                        if(IndexFirstPoint != -20 && IndexSeconPoint != -20 && IndexThirdPoint != -20)
                        {
                            IndexNbTriangle = NbTriangleIsoSurface*3;
                            IsoSurfaceTriangleListe[IndexNbTriangle  ] = IndexFirstPoint;
                            IsoSurfaceTriangleListe[IndexNbTriangle+1] = IndexSeconPoint;
                            IsoSurfaceTriangleListe[IndexNbTriangle+2] = IndexThirdPoint;
                            NbTriangleIsoSurface++;
                        }
                    }
                }
            }
        }
    }
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::PointEdgeComputation(int isoindex)
{
    int index, i_Start, i_End, j_Start, j_End, k_Start, k_End, i, j, k;
    double vals[7], IsoValue_1, IsoValue_2, rapport;
    double factor;
    int maxgrscalemaxgr = NbMaxGrid*NbMaxGrid;
    int I, J, JK, IJK, IPLUSONEJK, IMINUSONEJK,
        IJPLUSONEK, IJMINUSONEK, IMINUSONEJMINUSONEK, IsoValue=0, NbPointIsoMap_local=0;
    int limitX = nb_ligne;
    /// We have to compute the edges for the Grid limits ie: i=0, j=0 and k=0

    i_Start = 1/*+masterthread->iStart*/;
    j_Start = 1;
    k_Start = 1;

    i_End = nb_ligne-1;
    j_End = nb_colon-1;
    k_End = nb_depth-1;
    /// The code is doubled to eliminate conditions tests

    for(i = i_Start; i < i_End; i++)
    {
        I = i*maxgrscalemaxgr;
        for(j = j_Start; j < j_End; j++)
        {
            J = I + j*NbMaxGrid;
            for(k = k_Start; k < k_End; k++)
            {
                IJK                 = J+k;
                IPLUSONEJK          = IJK + maxgrscalemaxgr;
                IMINUSONEJK         = IJK - maxgrscalemaxgr;
                IJPLUSONEK          = IJK + NbMaxGrid;
                IJMINUSONEK         = IJK - NbMaxGrid;
                IMINUSONEJMINUSONEK = IMINUSONEJK - NbMaxGrid;

                IsoValue_1 = Results[IJK];
                /// First Case P(i+1)(j)(k)

                IsoValue_2 = Results[IPLUSONEJK];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0 )
                {
                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i] - factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];
                    ///===========================================================///
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

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
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local ;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j] - factor * masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

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
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k] - factor * masterthread->z_Step[isoindex];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

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
    for(j=0; j < nb_colon; j++)
    {
        J = j*NbMaxGrid;
        for(k=0; k < nb_depth; k++)
        {
            JK = J +k;

            IsoValue_1 = Results[JK];

            // First Case P(1)(j)(k)

            IsoValue_2 = Results[maxgrscalemaxgr+JK];
            if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
            {
                // Edge Point computation and  save in IsoPointMap
                factor = (IsoValue - IsoValue_1)/rapport;
                index  = TypeDrawin*NbPointIsoMap_local;

                vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i] - factor * masterthread->x_Step[isoindex];
                vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep ] = vals[0];
                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                // save The reference to this point
                GridVoxelVarPt[JK].Edge_Points[0] = NbPointIsoMap_local;
                GridVoxelVarPt[JK].NbEdgePoint += 1;

                // The same Point is used in three other Voxels
                if( j != 0)
                {
                    GridVoxelVarPt[JK-NbMaxGrid].Edge_Points[4] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK-NbMaxGrid].NbEdgePoint += 1;
                }
                if ( k != 0 )
                {
                    GridVoxelVarPt[JK-1].Edge_Points[2]   = NbPointIsoMap_local;
                    GridVoxelVarPt[JK-1].NbEdgePoint += 1;
                }
                if( j != 0 && k != 0)
                {
                    GridVoxelVarPt[JK-NbMaxGrid-1].Edge_Points[6] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK-NbMaxGrid-1].NbEdgePoint += 1;
                }

                NbPointIsoMap_local++;
            }

            // Second Case P(0)(j+1)(k)
            if ( j != (nb_colon -1))
            {
                IsoValue_2 = Results[JK+NbMaxGrid];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j] - factor *masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

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
            if ( k != (nb_depth-1))
            {
                IsoValue_2 = Results[JK+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k] - factor * masterthread->z_Step[isoindex];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[JK].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if ( j != 0)
                    {
                        GridVoxelVarPt[JK-NbMaxGrid].Edge_Points[7]   =NbPointIsoMap_local;
                        GridVoxelVarPt[JK-NbMaxGrid].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of ( if ( k != nb_depth -1)....
        }
    }



    /// 2) Case i = nb_ligne-1

    i = limitX-1;
    I = i*maxgrscalemaxgr;
    for(j=0; j < nb_colon; j++)
    {
        J = I + j*NbMaxGrid;
        for(k=0; k < nb_depth; k++)
        {
            JK = J + k;

            IsoValue_1 = Results[JK];


            // Second Case P(i)(j+1)(k)
            if ( j != (nb_colon -1))
            {
                IsoValue_2 = Results[JK+NbMaxGrid];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j] - factor *masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

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
            if ( k != (nb_depth -1))
            {
                IsoValue_2 = Results[JK+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k] - factor * masterthread->z_Step[isoindex];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

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
                        GridVoxelVarPt[JK-NbMaxGrid].Edge_Points[7]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-NbMaxGrid].NbEdgePoint += 1;
                    }
                    if( i !=0 && j != 0)
                    {
                        GridVoxelVarPt[JK-maxgrscalemaxgr-NbMaxGrid].Edge_Points[5] = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maxgrscalemaxgr-NbMaxGrid].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if ( k != nb_depth -1)...
        }
    }



    /// 3) Case j = 0
    j= 0;

    for(i=0; i < limitX; i++)
        for(k=0; k < nb_depth; k++)
        {

            IsoValue_1 = Results[i*maxgrscalemaxgr+k];

            // First Case P(i+1)(j)(k)
            if( i != (limitX -1))
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+k];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {

                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i] - factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

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

            IsoValue_2 = Results[i*maxgrscalemaxgr+NbMaxGrid+k];
            // Edge Point computation and  save in IsoPointMap
            if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
            {
                factor = (IsoValue - IsoValue_1)/rapport;
                index  = TypeDrawin*NbPointIsoMap_local;

                vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j] - factor * masterthread->y_Step[isoindex];
                vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

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
            if(k != (nb_depth -1))
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+k+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k] - factor * masterthread->z_Step[isoindex];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

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
    j = nb_colon-1;

    for(i=0; i < limitX; i++)
        for(k=0; k < nb_depth; k++)
        {

            IsoValue_1 = Results[i*maxgrscalemaxgr+j*NbMaxGrid+k];


            // First Case P(i+1)(j)(k)
            if( i != (limitX-1))
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+j*NbMaxGrid+k];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {

                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i] - factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( j != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid+k].Edge_Points[4] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid+k].NbEdgePoint += 1;
                    }
                    if(k != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k-1].Edge_Points[2]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k-1].NbEdgePoint += 1;
                    }
                    if(j != 0 && k != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid+k-1].Edge_Points[6] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid+k-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;


                }
            } /// End of if( i != (nb_ligne-1))...

            // Third Case P(i)(j)(k+1)
            if( k != (nb_depth -1))
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+j*NbMaxGrid+k+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k] - factor * masterthread->z_Step[isoindex];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if(i !=0)
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*NbMaxGrid+k].Edge_Points[1]   = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*NbMaxGrid+k].NbEdgePoint += 1;
                    }
                    if( j!=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid+k].Edge_Points[7]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid+k].NbEdgePoint += 1;
                    }
                    if(i != 0 && j !=0)
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*NbMaxGrid+k].Edge_Points[5] = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*NbMaxGrid+k].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if (k != nb_depth)...
        }


    /// 5) Case k = 0

    k =0;

    for(i=0; i < limitX; i++)
        for(j=0; j < nb_colon; j++)
        {
            IsoValue_1 = Results[i*maxgrscalemaxgr+j*NbMaxGrid];
            // First Case P(i+1)(j)(k)
            if(i != (limitX -1))
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+j*NbMaxGrid];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i] - factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid].NbEdgePoint += 1;

                    // The same Point is used in one other Voxel
                    if(j !=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid].Edge_Points[4] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;


                }
            } /// End of if(i != (nb_ligne -1))

            // Second Case P(i)(j+1)(k)
            if(j != nb_colon -1)
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+(j+1)*NbMaxGrid];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j] - factor * masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid].NbEdgePoint += 1;

                    // The same Point is used in one other Voxels
                    if ( i !=0 )
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*NbMaxGrid].Edge_Points[9]    = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*NbMaxGrid].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            }/// End of if(j != nb_colon -1)...

            // Third Case P(i)(j)(k+1)

            IsoValue_2 = Results[i*maxgrscalemaxgr+j*NbMaxGrid+1];
            // Edge Point computation and  save in IsoPointMap
            if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
            {
                factor = (IsoValue - IsoValue_1)/rapport;
                index  = TypeDrawin*NbPointIsoMap_local;

                vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k] - factor * masterthread->z_Step[isoindex];

                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                // save The reference to this point
                GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid].Edge_Points[3] = NbPointIsoMap_local;
                GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid].NbEdgePoint += 1;

                // The same Point is used in three other Voxels
                if ( i !=0 )
                {
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*NbMaxGrid].Edge_Points[1]   = NbPointIsoMap_local;
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*NbMaxGrid].NbEdgePoint += 1;
                }
                if (j != 0 )
                {
                    GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid].Edge_Points[7]   = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid].NbEdgePoint += 1;
                }
                if ( i !=0 && j != 0 )
                {
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*NbMaxGrid].Edge_Points[5] = NbPointIsoMap_local;
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*NbMaxGrid].NbEdgePoint += 1;
                }

                NbPointIsoMap_local++;

            }
        }


    /// 6) Case k = nb_depth -1

    k = nb_depth -1;

    for(i=0; i < limitX; i++)
        for(j=0; j < nb_colon; j++)
        {

            IsoValue_1 = Results[i*maxgrscalemaxgr+j*NbMaxGrid+k];


            // First Case P(i+1)(j)(k)
            if( i != (limitX -1) )
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+j*NbMaxGrid+k];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {

                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i] - factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if(j !=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid+k].Edge_Points[4] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid+k].NbEdgePoint += 1;
                    }
                    if(k !=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k-1].Edge_Points[2]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k-1].NbEdgePoint += 1;
                    }
                    if(j !=0 && k != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid+k-1].Edge_Points[6] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*NbMaxGrid+k-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;


                }
            } /// End of if(i != nb_ligne-1)...

            // Second Case P(i)(j+1)(k)
            if( j != (nb_colon -1) )
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+(j+1)*NbMaxGrid+k];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = masterthread->xLocal2[isoindex*NbMaxGrid+i];
                    vals[1] = masterthread->yLocal2[isoindex*NbMaxGrid+j] - factor * masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*NbMaxGrid+k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( i !=0 )
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*NbMaxGrid+k].Edge_Points[9]    = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*NbMaxGrid+k].NbEdgePoint += 1;
                    }
                    if( k !=0 )
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k-1].Edge_Points[11]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*NbMaxGrid+k-1].NbEdgePoint += 1;
                    }
                    if( i !=0 && k !=0 )
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*NbMaxGrid+k-1].Edge_Points[10] = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*NbMaxGrid+k-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if( j != (nb_colon -1) )...

        }


    NbPointIsoMap =    NbPointIsoMap_local;
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++///
void Iso3D::SignatureComputation()
{
    int I, J, IJK, IPLUSONEJK,
        IJPLUSONEK,  IPLUSONEJPLUSONEK;
    int maxgrscalemaxgr = NbMaxGrid*NbMaxGrid;
    int limitX = nb_ligne;
    for(int i=0; i < limitX; i++)
    {
        I = i*maxgrscalemaxgr;
        for(int j=0; j < nb_colon; j++)
        {
            J = I + j*NbMaxGrid;
            for(int k=0; k < nb_depth; k++)
            {
                IJK               = J + k;
                IPLUSONEJK        = IJK + maxgrscalemaxgr;
                IJPLUSONEK        = IJK + NbMaxGrid;
                IPLUSONEJPLUSONEK = IPLUSONEJK + NbMaxGrid;

                if(Results[IJK] <= 0) GridVoxelVarPt[IJK].Signature +=1;

                if(i != (limitX-1))
                    if(Results[IPLUSONEJK] <= 0) GridVoxelVarPt[IJK].Signature +=2;

                if(i != (limitX-1) && k != (nb_depth-1))
                    if(Results[IPLUSONEJK+1] <= 0) GridVoxelVarPt[IJK].Signature +=4;

                if(k != (nb_depth-1))
                    if(Results[IJK+1] <= 0) GridVoxelVarPt[IJK].Signature +=8;

                if(j != (nb_colon-1))
                    if(Results[IJPLUSONEK] <= 0) GridVoxelVarPt[IJK].Signature +=16;

                if(i != (limitX-1) && j != (nb_colon-1))
                    if(Results[IPLUSONEJPLUSONEK] <= 0) GridVoxelVarPt[IJK].Signature +=32;

                if(i != (limitX-1) && j != (nb_colon-1) && k != (nb_depth-1))
                    if(Results[IPLUSONEJPLUSONEK+1] <= 0) GridVoxelVarPt[IJK].Signature +=64;

                if(j != (nb_colon-1) && k != (nb_depth-1))
                    if(Results[IJPLUSONEK+1] <= 0) GridVoxelVarPt[IJK].Signature +=128;
            }
        }
    }// End if(Grid...
}
