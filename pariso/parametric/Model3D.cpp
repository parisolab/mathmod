/***************************************************************************
 *   Copyright (C) 2020 by Abderrahman Taha                                *
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
 *   51 Franklin Street, Fifth Floor,Boston, MA 02110-1301 USA             *
 ***************************************************************************/
#include "Model3D.h"

static uint NbVertexTmp = 0;
static std::vector<float>  ExtraDimensionVector;
static CellNoise *NoiseFunction2 = new CellNoise();
static ImprovedNoise *PNoise2 = new ImprovedNoise(4., 4., 4.);
static double ParamComponentId=0;
static double ParamThreadId=0;
static QElapsedTimer ptime;

double CurrentParamCmpId(const double* p)
{
    int pp = int(p[0]);
    if(pp==0)
        return ParamComponentId;
    else
        return ParamThreadId;
}

double TurbulenceWorley2(const double* p)
{
    return double(NoiseFunction2->CellNoiseFunc(
               float(p[0]),
               float(p[1]),
               float(p[2]),
               int(p[3]),
               int(p[4]),
               int(p[5])));
}

//+++++++++++++++++++++++++++++++++++++++++
double TurbulencePerlin2(const double* p)
{
    return double(PNoise2->FractalNoise3D(
               float(p[0]),
               float(p[1]),
               float(p[2]),
               int(p[3]),
               float(p[4]),
               float(p[5])));
}

//+++++++++++++++++++++++++++++++++++++++++
Par3D::~Par3D()
{
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Par3D::emitUpdateMessageSignal()
{
    emit UpdateMessageSignal(message);
}
//+++++++++++++++++++++++++++++++++++++++++
ParWorkerThread::ParWorkerThread()
{
    stepMorph = 0;
    pace = 1.0/30.0;
    ParsersAllocated = false;
    /*
    v_inf = new double[NbParComponent];
    u_inf = new double[NbParComponent];
    v_sup = new double[NbParComponent];
    u_sup = new double[NbParComponent];
    dif_v = new double[NbParComponent];
    dif_u = new double[NbParComponent];
    */
}

//++++++++++++++++++++++++++++++++++++
ParWorkerThread::~ParWorkerThread()
{
    /*
    delete[] u_inf;
    delete[] v_inf;
    delete[] u_sup;
    delete[] v_sup;
    delete[] dif_u;
    delete[] dif_v;
    */
}

//+++++++++++++++++++++++++++++++++++++++++
ParMasterThread::~ParMasterThread()
{
    //delete[] ParamStructs;
    delete[] UsedFunct;
    delete[] UsedFunct2;
    //delete[] grid;

    ParamStructs.clear();
    SliderValues.clear();
    SliderNames.clear();
    Rgbts.clear();
    RgbtNames.clear();
    VRgbts.clear();
    VRgbtNames.clear();
    Functs.clear();
    FunctNames.clear();
    Consts.clear();
    ConstNames.clear();
    ConstValues.clear();
}

//+++++++++++++++++++++++++++++++++++++++++
ParMasterThread::ParMasterThread()
{
    activeMorph = -1;
    ParConditionRequired = -1;
    Nb_Sliders = 0;
    Gain = 1.0;
    Octaves = 4;
    Lacunarity = 0.5;
    //ParamStructs = new ParStruct[NbParComponent];
    //grid         = new uint[2*NbParComponent];
    UsedFunct    = new bool[0];
    UsedFunct2   = new bool[0];
}
//+++++++++++++++++++++++++++++++++++++++++
Par3D::Par3D(uint nbThreads, uint nbGrid)
{
    initialiser_parametres(nbThreads, nbGrid);
}

//+++++++++++++++++++++++++++++++++++++++++
void ParWorkerThread::run()
{
    ParCompute(CurrentPar, CurrentIndex);
}

//+++++++++++++++++++++++++++++++++++++++++
void ParWorkerThread::ParCompute(uint fctnb, uint idx)
{
    calcul_objet(fctnb, idx);
}

//+++++++++++++++++++++++++++++++++++++++++
void Par3D::initialiser_parametres(uint nbThreads, uint nbGrid)
{
    Ugrid = nbGrid;
    Vgrid = nbGrid;
    CutV = CutU = 0;
    tetazw = tetaxy =  tetaxz = tetayz = tetaxw = tetayw =  0;
    tetazw_ok = tetaxy_ok =  tetaxz_ok = tetayz_ok = tetaxw_ok = tetayw_ok =  param4D = -1;
    // initialisation des matrices 4D
    mat4D                     = Matrix4D();
    mat_rotation4D            = Matrix4D();
    mat_rotation_save4D       = Matrix4D();
    mat_homothetie4D          = Matrix4D();
    mat_translation4D         = Matrix4D();
    mat_inversetranslation4D  = Matrix4D();
    mat4D.unit();

    WorkerThreadsNumber = nbThreads;
    workerthreads = new ParWorkerThread[WorkerThreadsNumber-1];
    masterthread  = new ParMasterThread();

    masterthread->Ugrid  = Ugrid;
    masterthread->Vgrid = Vgrid;
    masterthread->MyIndex   = 0;
    masterthread->param4D   = param4D;
    masterthread->WorkerThreadsNumber = WorkerThreadsNumber;

    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        workerthreads[nbthreads].Ugrid  = Ugrid;
        workerthreads[nbthreads].Vgrid = Vgrid;
        workerthreads[nbthreads].MyIndex   = nbthreads+1;
        workerthreads[nbthreads].param4D   = param4D;
        workerthreads[nbthreads].WorkerThreadsNumber = WorkerThreadsNumber;
    }
}

void Par3D::initialiser_LineColumn(uint li, uint cl)
{
    Ugrid  = li;
    Vgrid = cl;
    masterthread->Ugrid  = Ugrid;
    masterthread->Vgrid = Vgrid;
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        workerthreads[nbthreads].Ugrid  = Ugrid;
        workerthreads[nbthreads].Vgrid = Vgrid;
    }
}

//++++++++++++++++++++++++++++++++++++++++
void  Par3D::rotation4()
{
    mat_rotation4D.unit();
    // Construction de la matrice de trnsformation
    if(tetaxy_ok == 1)    mat_rotation4D.xyrot(tetaxy);
    if(tetaxz_ok == 1)    mat_rotation4D.xzrot(tetaxz);
    if(tetayz_ok == 1)    mat_rotation4D.yzrot(tetayz);
    if(param4D == 1)
    {
        if(tetaxw_ok == 1)    mat_rotation4D.xwrot(tetaxw);
        if(tetayw_ok == 1)    mat_rotation4D.ywrot(tetayw);
        if(tetazw_ok == 1)    mat_rotation4D.zwrot(tetazw);
    }
// On applique cette transformation a la matrice principale "mat"
    mat4D.mult(mat_rotation4D);
}

//+++++++++++++++++++++++++++++++++++++++++
void  Par3D::boite_englobante4D(uint idx)
{
    MINX =10^12;
    MINY =MINX;
    MINZ =MINX;
    MINW =MINX;

    MAXX =-MINX;
    MAXY =-MINX;
    MAXZ =-MINX;
    MAXW =-MINX;

    uint IDX = 0;
    for (uint i=0; i < Ugrid; i++)
        for (uint j=0; j < Vgrid; j++)
        {
            if(MINX > NormVertexTabVector[IDX+idx*10+7] ) MINX = NormVertexTabVector[IDX+idx*10+7];
            if(MINY > NormVertexTabVector[IDX+idx*10+8] ) MINY = NormVertexTabVector[IDX+idx*10+8];
            if(MINZ > NormVertexTabVector[IDX+idx*10+9] ) MINZ = NormVertexTabVector[IDX+idx*10+9];
            if(MINW > ExtraDimensionVector[i*Vgrid + j + idx] ) MINW = ExtraDimensionVector[i*Vgrid + j + idx];

            if(MAXX < NormVertexTabVector[IDX+idx*10+7] ) MAXX = NormVertexTabVector[IDX+idx*10+7];
            if(MAXY < NormVertexTabVector[IDX+idx*10+8] ) MAXY = NormVertexTabVector[IDX+idx*10+8];
            if(MAXZ < NormVertexTabVector[IDX+idx*10+9] ) MAXZ = NormVertexTabVector[IDX+idx*10+9];
            if(MAXW < ExtraDimensionVector[i*Vgrid + j + idx] ) MAXW = ExtraDimensionVector[i*Vgrid + j + idx];
            IDX+=10;
        }

    DIFX = MAXX - MINX ;
    DIFY = MAXY - MINY ;
    DIFZ = MAXZ - MINZ ;
    DIFW = MAXW - MINW ;
// Recherche du maximum :
    DIFMAXIMUM = DIFX;
    if (DIFY > DIFMAXIMUM)
    {
        DIFMAXIMUM = DIFY;
    }
    if (DIFZ > DIFMAXIMUM)
    {
        DIFMAXIMUM = DIFZ;
    }
    if (DIFW > DIFMAXIMUM)
    {
        DIFMAXIMUM = DIFW;
    }
// On va inclure cet objet dans un HperCube de langueur maximum
// egale a "hauteur_fenetre"

    float decalage_xo  = -(MINX +MAXX)/2 ;
    float decalage_yo  = -(MINY +MAXY)/2 ;
    float decalage_zo  = -(MINZ +MAXZ)/2 ;
    float decalage_wo  = -(MINW +MAXW)/2 ;
    IDX =0;
    for (uint i=0; i < Ugrid   ; i++)
        for (uint j=0; j < Vgrid   ; j++)
        {
            NormVertexTabVector[IDX+idx*10+7] = (NormVertexTabVector[IDX+idx*10+7] + decalage_xo)/DIFMAXIMUM ;
            NormVertexTabVector[IDX+idx*10+8] = (NormVertexTabVector[IDX+idx*10+8] + decalage_yo)/DIFMAXIMUM ;
            NormVertexTabVector[IDX+idx*10+9] = (NormVertexTabVector[IDX+idx*10+9] + decalage_zo)/DIFMAXIMUM ;
            ExtraDimensionVector[i*Vgrid + j + idx] = (ExtraDimensionVector[i*Vgrid + j + idx] + decalage_wo)/DIFMAXIMUM ;
            IDX+=10;
        }
}

//+++++++++++++++++++++++++++++++++++++++++
void  Par3D::Invert_boite_englobante4D(uint idx)
{
    float decalage_xo  = -(MINX +MAXX)/2;
    float decalage_yo  = -(MINY +MAXY)/2;
    float decalage_zo  = -(MINZ +MAXZ)/2;
    uint IDX =0;
    for (uint i=0; i < Ugrid   ; i++)
        for (uint j=0; j < Vgrid   ; j++)
        {
            NormVertexTabVector[IDX+idx*10+7] = (NormVertexTabVector[IDX+idx*10+7]*DIFMAXIMUM -  decalage_xo);
            NormVertexTabVector[IDX+idx*10+8] = (NormVertexTabVector[IDX+idx*10+8]*DIFMAXIMUM -  decalage_yo);
            NormVertexTabVector[IDX+idx*10+9] = (NormVertexTabVector[IDX+idx*10+9]*DIFMAXIMUM -  decalage_zo);
            IDX+=10;
        }
}

//+++++++++++++++++++++++++++++++++++++++++
void Par3D::Anim_Rot4D (uint idx)
{
    rotation4();
    calcul_points4(idx);
    if(param4D == 1)// On applique la rotation 4D
    {
        boite_englobante4D(idx);
        project_4D_to_3D(idx);
    }
    Invert_boite_englobante4D(idx);
}

//+++++++++++++++++++++++++++++++++++++++++
void  Par3D::calcul_points4(uint idx)
{
    double tp1, tp2, tp3, tp4;
    // Changement de coordonnees des points selon les
    // angles angex et angley
    uint lndex =0;
    for (uint i=0; i < Ugrid  ; i++)
        for (uint j=0; j < Vgrid   ; j++)
        {
            tp1 = double(NormVertexTabVector[lndex+idx*10+7]);
            tp2 = double(NormVertexTabVector[lndex+idx*10+8]);
            tp3 = double(NormVertexTabVector[lndex+idx*10+9]);
            tp4 = double(ExtraDimensionVector[i*Vgrid + j + idx]);
            if(param4D == 1)
            {
                NormVertexTabVector[lndex+idx*10+7] = float(mat4D.xx*tp1 + mat4D.xy*tp2 + mat4D.xz*tp3 + mat4D.xw*tp4 + mat4D.xo);
                NormVertexTabVector[lndex+idx*10+8] = float(mat4D.yx*tp1 + mat4D.yy*tp2 + mat4D.yz*tp3 + mat4D.yw*tp4 + mat4D.yo);
                NormVertexTabVector[lndex+idx*10+9] = float(mat4D.zx*tp1 + mat4D.zy*tp2 + mat4D.zz*tp3 + mat4D.zw*tp4 + mat4D.zo);
                ExtraDimensionVector[i*Vgrid + j + idx] = float(mat4D.wx*tp1 + mat4D.wy*tp2 + mat4D.wz*tp3 + mat4D.ww*tp4 + mat4D.wo);
            }
            else
            {
                NormVertexTabVector[lndex+idx*10+7] = float(mat4D.xx*tp1 + mat4D.xy*tp2 + mat4D.xz*tp3 + mat4D.xo);
                NormVertexTabVector[lndex+idx*10+8] = float(mat4D.yx*tp1 + mat4D.yy*tp2 + mat4D.yz*tp3 + mat4D.yo);
                NormVertexTabVector[lndex+idx*10+9] = float(mat4D.zx*tp1 + mat4D.zy*tp2 + mat4D.zz*tp3 + mat4D.zo);
            }
            lndex += 10;
        }
}

//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::project_4D_to_3D(uint idx)
{
    double c4;
    uint I = 0;
    for (uint i=0; i < Ugrid; ++i)
        for (uint j=0; j < Vgrid  ; ++j)
        {
            c4 = 1.0/double(ExtraDimensionVector[i*Vgrid + j + idx] - 2);
            NormVertexTabVector[I+idx*10+7] *= float(c4);
            NormVertexTabVector[I+idx*10+8] *= float(c4);
            NormVertexTabVector[I+idx*10+9] *= float(c4);
            I += 10;
        }
}

//+++++++++++++++++++++++++++++++++++++++++
void ParMasterThread::AllocateParsersForMasterThread()
{
    if(!ParsersAllocated)
    {
        myParserX = new FunctionParser[expression_XSize];
        myParserY = new FunctionParser[expression_XSize];
        myParserZ = new FunctionParser[expression_XSize];
        myParserW = new FunctionParser[expression_XSize];
        myParserUmin = new FunctionParser[expression_XSize];
        myParserVmin = new FunctionParser[expression_XSize];
        myParserUmax = new FunctionParser[expression_XSize];
        myParserVmax = new FunctionParser[expression_XSize];
        ParConditionParser  = new FunctionParser[expression_XSize];

        ParamStructs.resize(expression_XSize);
        v_inf.resize(expression_XSize);
        v_sup.resize(expression_XSize);
        u_inf.resize(expression_XSize);
        u_sup.resize(expression_XSize);
        dif_v.resize(expression_XSize);
        dif_u.resize(expression_XSize);

        if(!functnotnull)
            FunctSize = 0;
         Fct          = new FunctionParser[FunctSize];
         UsedFunct    = new bool[4*uint(expression_XSize)*FunctSize];
         UsedFunct2   = new bool[FunctSize*FunctSize];

        rgbtnotnull ?
            RgbtParser = new FunctionParser[(RgbtSize = 4)] :
            RgbtParser = new FunctionParser[(RgbtSize = 0)];

        vrgbtnotnull ?
            VRgbtParser = new FunctionParser[VRgbtSize] :
            VRgbtParser = new FunctionParser[(VRgbtSize = 0)];

        if(constnotnull)
            ConstSize=0;

        GradientParser   = new FunctionParser;
        NoiseParser      = new FunctionParser;
        NoiseShapeParser = new FunctionParser;
        ParsersAllocated = true;
    }
}

//+++++++++++++++++++++++++++++++++++++++++
void ParWorkerThread::AllocateParsersForWorkerThread(uint nbcomposants, uint nbfunct)
{
    if(!ParsersAllocated)
    {
        myParserX = new FunctionParser[nbcomposants];
        myParserY = new FunctionParser[nbcomposants];
        myParserZ = new FunctionParser[nbcomposants];
        myParserW = new FunctionParser[nbcomposants];
        Fct       = new FunctionParser[nbfunct];
        ParsersAllocated = true;
    }
}

//+++++++++++++++++++++++++++++++++++++++++
void ParMasterThread::DeleteMasterParsers()
{
    if(ParsersAllocated)
    {
        delete[] myParserX;
        delete[] myParserY;
        delete[] myParserZ;
        delete[] myParserW;
        delete[] myParserUmin;
        delete[] myParserVmin;
        delete[] myParserUmax;
        delete[] myParserVmax;
        delete[] ParConditionParser;
        delete[] Fct;
        delete[] UsedFunct;
        delete[] UsedFunct2;
        delete[] RgbtParser;
        delete[] VRgbtParser;
        delete GradientParser;
        delete NoiseParser;
        delete NoiseShapeParser;
        ParsersAllocated = false;
    }

    ParamStructs.clear();
    v_inf.clear();
    v_sup.clear();
    u_inf.clear();
    u_sup.clear();
    dif_v.clear();
    dif_u.clear();
    SliderValues.clear();
    SliderNames.clear();
    Rgbts.clear();
    RgbtNames.clear();
    VRgbts.clear();
    VRgbtNames.clear();
    Functs.clear();
    FunctNames.clear();
    Consts.clear();
    ConstNames.clear();
    ConstValues.clear();
}

//+++++++++++++++++++++++++++++++++++++++++
void ParWorkerThread::DeleteWorkerParsers()
{
    if(ParsersAllocated)
    {
        delete[] myParserX;
        delete[] myParserY;
        delete[] myParserZ;
        delete[] myParserW;
        delete[] Fct;
        ParsersAllocated = false;
    }
}


//+++++++++++++++++++++++++++++++++++++++++
void ParMasterThread::InitMasterParsers()
{
    DeleteMasterParsers();
    AllocateParsersForMasterThread();

    GradientParser->AddConstant("pi", PI);
    Cstparser.AddConstant("pi", PI);
    NoiseParser->AddConstant("pi", PI);
    NoiseParser->AddFunction("NoiseW",TurbulenceWorley2, 6);
    NoiseParser->AddFunction("NoiseP",TurbulencePerlin2, 6);
    NoiseParser->AddConstant("Lacunarity", Lacunarity);
    NoiseParser->AddConstant("Gain", Gain);
    NoiseParser->AddConstant("Octaves", Octaves);
    NoiseShapeParser->AddConstant("pi", PI);
    NoiseShapeParser->AddFunction("NoiseW",TurbulenceWorley2, 6);
    NoiseShapeParser->AddFunction("NoiseP",TurbulencePerlin2, 6);

    for(uint i=0; i<expression_XSize; i++)
    {
        myParserX[i].AddConstant("pi", PI);
        myParserY[i].AddConstant("pi", PI);
        myParserZ[i].AddConstant("pi", PI);
        myParserW[i].AddConstant("pi", PI);
        ParConditionParser[i].AddConstant("pi", PI);
        myParserUmin[i].AddConstant("pi", PI);
        myParserVmin[i].AddConstant("pi", PI);
        myParserUmax[i].AddConstant("pi", PI);
        myParserVmax[i].AddConstant("pi", PI);

        myParserX[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserX[i].AddFunction("NoiseP",TurbulencePerlin2, 6);
        myParserY[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserY[i].AddFunction("NoiseP",TurbulencePerlin2, 6);
        myParserZ[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserZ[i].AddFunction("NoiseP",TurbulencePerlin2, 6);
        myParserW[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserW[i].AddFunction("NoiseP",TurbulencePerlin2, 6);
        ParConditionParser[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        ParConditionParser[i].AddFunction("NoiseP",TurbulencePerlin2, 6);
    }

    for(uint i=0; i<RgbtSize; i++)
    {
        RgbtParser[i].AddConstant("pi", PI);
    }

    for(uint i=0; i<VRgbtSize; i++)
    {
        VRgbtParser[i].AddConstant("pi", PI);
    }

    for(uint i=0; i<FunctSize; i++)
    {
        Fct[i].AddConstant("pi", PI);
        Fct[i].AddFunction("CmpId",CurrentParamCmpId, 1);
    }
}

ErrorMessage  Par3D::ParMorph()
{
    ErrorMessage err = masterthread->parse_expression();
    if(err.iErrorIndex < 0)
        ThreadParsersCopy();
    return err;
}

ErrorMessage  ParMasterThread::parse_expression()
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::string varliste = "x,y,z,t";

    InitMasterParsers();

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
            ConstValues.push_back(Cstparser.Eval(vals));
            Cstparser.AddConstant(ConstNames[j], ConstValues[j]);
        }
    }
    else
    {
        ConstSize =0;
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
            if ((stdError.iErrorIndex = Fct[i].Parse(Functs[i],"u,v,t")) >= 0)
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

    //Colors
    if(rgbtnotnull)
    {
        RgbtSize = HowManyVariables(Rgbt, 3);

        for(uint i=0; i<RgbtSize; i++)
        {
            for(uint j=0; j<ConstSize; j++)
            {
                RgbtParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            }
        }
    }
    else
    {
        RgbtSize =0;
    }

    //Texture:
    if(vrgbtnotnull)
    {
        VRgbtSize = HowManyVariables(VRgbt, 4);
        for(uint j=0; j<ConstSize; j++)
        {
            GradientParser->AddConstant(ConstNames[j], ConstValues[j]);
        }

        for(uint i=0; i<VRgbtSize; i++)
        {
            for(uint j=0; j<ConstSize; j++)
            {
                VRgbtParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            }
        }
    }
    else
    {
        VRgbtSize =0;
    }
    HowManyParamSurface(expression_X, 0);
    HowManyParamSurface(expression_Y, 1);
    HowManyParamSurface(expression_Z, 2);
    HowManyParamSurface(inf_u, 3);
    HowManyParamSurface(sup_u, 4);
    HowManyParamSurface(inf_v, 5);
    HowManyParamSurface(sup_v, 6);
    if(param4D == 1)
        HowManyParamSurface(expression_W, 7);
    if(cndnotnull)
    {
        ParConditionRequired = 1;
        HowManyParamSurface(expression_CND, 8);
    }
    else
        ParConditionRequired = -1;

    //Add defined constantes:
    for(uint i=0; i<expression_XSize; i++)
    {
        for(uint j=0; j<ConstSize; j++)
        {
            if(cndnotnull)
                ParConditionParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            myParserUmax[i].AddConstant(ConstNames[j], ConstValues[j]);
            myParserUmin[i].AddConstant(ConstNames[j], ConstValues[j]);
            myParserVmin[i].AddConstant(ConstNames[j], ConstValues[j]);
            myParserVmax[i].AddConstant(ConstNames[j], ConstValues[j]);
            myParserX[i].AddConstant(ConstNames[j], ConstValues[j]);
            myParserY[i].AddConstant(ConstNames[j], ConstValues[j]);
            myParserZ[i].AddConstant(ConstNames[j], ConstValues[j]);
            myParserW[i].AddConstant(ConstNames[j], ConstValues[j]);
        }

        //Add predefined constatnts:
        for(uint k=0; k<Nb_Sliders; k++)
        {
            if(cndnotnull)
                ParConditionParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            myParserUmin[i].AddConstant(SliderNames[k], SliderValues[k]);
            myParserUmax[i].AddConstant(SliderNames[k], SliderValues[k]);
            myParserVmin[i].AddConstant(SliderNames[k], SliderValues[k]);
            myParserVmax[i].AddConstant(SliderNames[k], SliderValues[k]);
            myParserX[i].AddConstant(SliderNames[k], SliderValues[k]);
            myParserY[i].AddConstant(SliderNames[k], SliderValues[k]);
            myParserZ[i].AddConstant(SliderNames[k], SliderValues[k]);
            myParserW[i].AddConstant(SliderNames[k], SliderValues[k]);
        }
    }
    // Add defined functions :
    for(uint i=0; i<expression_XSize; i++)
    {
        for(uint j=0; j<FunctSize; j++)
        {
            if((UsedFunct[i*4*FunctSize+4*j]=(ParamStructs[i].fx.find(FunctNames[j]) != std::string::npos)))
                myParserX[i].AddFunction(FunctNames[j], Fct[j]);
            if((UsedFunct[i*4*FunctSize+4*j+1]=(ParamStructs[i].fy.find(FunctNames[j]) != std::string::npos)))
                myParserY[i].AddFunction(FunctNames[j], Fct[j]);
            if((UsedFunct[i*4*FunctSize+4*j+2]=(ParamStructs[i].fz.find(FunctNames[j]) != std::string::npos)))
                myParserZ[i].AddFunction(FunctNames[j], Fct[j]);
            if((UsedFunct[i*4*FunctSize+4*j+3]=(ParamStructs[i].fw.find(FunctNames[j]) != std::string::npos)))
                myParserW[i].AddFunction(FunctNames[j], Fct[j]);
        }
    }

    // Parse
    if(rgbtnotnull)
        for(uint i=0; i<RgbtSize; i++)
            if ((stdError.iErrorIndex = RgbtParser[i].Parse(Rgbts[i],"x,y,z,u,v,i,j,index,grid,cmpId")) >= 0)
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

    if(NoiseShape != "")
        if ((stdError.iErrorIndex = NoiseShapeParser->Parse(NoiseShape,"x,y,z,t")) >= 0)
        {
            stdError.strError = NoiseShape;
            return stdError;
        }

    for(uint index=0; index< expression_XSize; index++)
    {
        if ((stdError.iErrorIndex = myParserUmin[index].Parse(ParamStructs[index].umin, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].umin;
            return stdError;
        }
        u_inf[index] = myParserUmin[index].Eval(vals);

        if ((stdError.iErrorIndex = myParserUmax[index].Parse(ParamStructs[index].umax, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].umax;
            return stdError;
        }
        u_sup[index] = myParserUmax[index].Eval(vals);
        dif_u[index] = u_sup[index] - u_inf[index];

        if ((stdError.iErrorIndex = myParserVmin[index].Parse(ParamStructs[index].vmin, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].vmin;
            return stdError;
        }
        v_inf[index] = myParserVmin[index].Eval(vals);

        if ((stdError.iErrorIndex = myParserVmax[index].Parse(ParamStructs[index].vmax, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].vmax;
            return stdError;
        }
        v_sup[index] = myParserVmax[index].Eval(vals);
        dif_v[index] = v_sup[index] - v_inf[index];

        if ((stdError.iErrorIndex = myParserX[index].Parse(ParamStructs[index].fx, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].fx;
            return stdError;
        }

        if ((stdError.iErrorIndex = myParserY[index].Parse(ParamStructs[index].fy, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].fy;
            return stdError;
        }

        if ((stdError.iErrorIndex = myParserZ[index].Parse(ParamStructs[index].fz, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].fz;
            return stdError;
        }

        if(param4D == 1)
            if ((stdError.iErrorIndex = myParserW[index].Parse(ParamStructs[index].fw, "u,v,t")) >= 0)
            {
                stdError.strError = ParamStructs[index].fw;
                return stdError;
            }

        if(cndnotnull)
            if ((stdError.iErrorIndex = ParConditionParser[index].Parse(ParamStructs[index].cnd, "x,y,z,t")) >= 0)
            {
                stdError.strError = ParamStructs[index].cnd;
                return stdError;
            }
    }
    return stdError;
}

ErrorMessage  Par3D::parse_expression2()
{
    ErrorMessage NodError;

    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        //Functions:
        for(uint ij=0; ij<masterthread->FunctSize; ij++)
        {
            workerthreads[nbthreads].Fct[ij].AddConstant("pi", PI);
            workerthreads[nbthreads].Fct[ij].AddFunction("CmpId",CurrentParamCmpId, 1);
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
            for(uint jj=0; jj<ii; jj++)
                if(masterthread->UsedFunct2[ii*masterthread->FunctSize+jj])
                    workerthreads[nbthreads].Fct[ii].AddFunction(masterthread->FunctNames[jj], workerthreads[nbthreads].Fct[jj]);
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].Fct[ii].Parse(masterthread->Functs[ii],"u,v,t")) >= 0)
            {
                masterthread->stdError.strError = masterthread->Functs[ii];
                return masterthread->stdError;
            }
            workerthreads[nbthreads].Fct[ii].AllocateStackMemory(Stack_Factor);
        }
    }

    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        //Add defined constantes:
        for(uint i=0; i<masterthread->expression_XSize; i++)
        {
            workerthreads[nbthreads].param4D   = masterthread->param4D;
            workerthreads[nbthreads].myParserX[i].AddConstant("pi", PI);
            workerthreads[nbthreads].myParserY[i].AddConstant("pi", PI);
            workerthreads[nbthreads].myParserZ[i].AddConstant("pi", PI);
            workerthreads[nbthreads].myParserW[i].AddConstant("pi", PI);

            workerthreads[nbthreads].myParserX[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
            workerthreads[nbthreads].myParserX[i].AddFunction("NoiseP",TurbulencePerlin2, 6);

            workerthreads[nbthreads].myParserY[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
            workerthreads[nbthreads].myParserY[i].AddFunction("NoiseP",TurbulencePerlin2, 6);

            workerthreads[nbthreads].myParserZ[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
            workerthreads[nbthreads].myParserZ[i].AddFunction("NoiseP",TurbulencePerlin2, 6);

            workerthreads[nbthreads].myParserW[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
            workerthreads[nbthreads].myParserW[i].AddFunction("NoiseP",TurbulencePerlin2, 6);

            for(uint j=0; j<masterthread->ConstSize; j++)
            {
                workerthreads[nbthreads].myParserX[i].AddConstant(masterthread->ConstNames[j], masterthread->ConstValues[j]);
                workerthreads[nbthreads].myParserY[i].AddConstant(masterthread->ConstNames[j], masterthread->ConstValues[j]);
                workerthreads[nbthreads].myParserZ[i].AddConstant(masterthread->ConstNames[j], masterthread->ConstValues[j]);
                workerthreads[nbthreads].myParserW[i].AddConstant(masterthread->ConstNames[j], masterthread->ConstValues[j]);
            }
            //Add predefined sliders constatnts:
            for(uint k=0; k<masterthread->Nb_Sliders; k++)
            {
                workerthreads[nbthreads].myParserX[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
                workerthreads[nbthreads].myParserY[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
                workerthreads[nbthreads].myParserZ[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
                workerthreads[nbthreads].myParserW[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
            }
        }

        // Add defined functions :
        for(uint i=0; i<masterthread->expression_XSize; i++)
        {
            for(uint j=0; j<masterthread->FunctSize; j++)
            {
                if(masterthread->UsedFunct[i*4*masterthread->FunctSize+4*j])
                    workerthreads[nbthreads].myParserX[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct[j]);
                if(masterthread->UsedFunct[i*4*masterthread->FunctSize+4*j+1])
                    workerthreads[nbthreads].myParserY[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct[j]);
                if(masterthread->UsedFunct[i*4*masterthread->FunctSize+4*j+2])
                    workerthreads[nbthreads].myParserZ[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct[j]);
                if(masterthread->UsedFunct[i*4*masterthread->FunctSize+4*j+3])
                    workerthreads[nbthreads].myParserW[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct[j]);
            }

        }
    }
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint index=0; index< masterthread->expression_XSize; index++)
        {
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserX[index].Parse(masterthread->ParamStructs[index].fx, "u,v,t")) >= 0)
            {
                masterthread->stdError.strError = masterthread->ParamStructs[index].fx;
                return masterthread->stdError;
            }

            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserY[index].Parse(masterthread->ParamStructs[index].fy, "u,v,t")) >= 0)
            {
                masterthread->stdError.strError = masterthread->ParamStructs[index].fy;
                return masterthread->stdError;
            }

            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserZ[index].Parse(masterthread->ParamStructs[index].fz, "u,v,t")) >= 0)
            {
                masterthread->stdError.strError = masterthread->ParamStructs[index].fz;
                return masterthread->stdError;
            }

            if(param4D == 1)
                if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserW[index].Parse(masterthread->ParamStructs[index].fw, "u,v,t")) >= 0)
                {
                    masterthread->stdError.strError = masterthread->ParamStructs[index].fw;
                    return masterthread->stdError;
                }
        }
    }
    return NodError;
}

//+++++++++++++++++++++++++++++++++++++++++
void Par3D::WorkerThreadCopy(ParWorkerThread *WorkerThreadsTmp)
{
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        WorkerThreadsTmp[nbthreads].Ugrid = masterthread->Ugrid;
        WorkerThreadsTmp[nbthreads].Vgrid = masterthread->Vgrid;
        WorkerThreadsTmp[nbthreads].MyIndex = nbthreads+1;
        WorkerThreadsTmp[nbthreads].param4D   = param4D;
        WorkerThreadsTmp[nbthreads].WorkerThreadsNumber = WorkerThreadsNumber;
    }
}
//+++++++++++++++++++++++++++++++++++++++++
ErrorMessage Par3D::ThreadParsersCopy()
{
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        workerthreads[nbthreads].dif_u.clear();
        workerthreads[nbthreads].dif_u = masterthread->dif_u;
        workerthreads[nbthreads].dif_v.clear();
        workerthreads[nbthreads].dif_v = masterthread->dif_v;
        workerthreads[nbthreads].u_inf.clear();
        workerthreads[nbthreads].u_inf = masterthread->u_inf;
        workerthreads[nbthreads].v_inf.clear();
        workerthreads[nbthreads].v_inf = masterthread->v_inf;
        workerthreads[nbthreads].param4D  = masterthread->param4D;
    }

    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
        workerthreads[nbthreads].DeleteWorkerParsers();

    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
        workerthreads[nbthreads].AllocateParsersForWorkerThread(masterthread->expression_XSize, masterthread->FunctSize);

    return(parse_expression2());
}

//+++++++++++++++++++++++++++++++++++++++++
uint ParMasterThread::HowManyVariables(std::string NewVariables, int type)
{
    std::string tmp, tmp2,tmp3;
    size_t position =0, jpos;
    uint Nb_variables =0;
    while( NewVariables!= "")
    {
        if((position = NewVariables.find(";")) != string::npos)
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

//+++++++++++++++++++++++++++++++++++++++++
void ParMasterThread::HowManyParamSurface(std::string ParamFct, int type)
{
    std::string tmp, tmp2;
    size_t position =0;
    uint Nb_paramfunction =0;

    switch(type)
    {
    case 0:
        ParamStructs[0].fx = ParamFct;
        break;
    case 1:
        ParamStructs[0].fy = ParamFct;
        break;
    case 2:
        ParamStructs[0].fz = ParamFct;
        break;
    case 3:
        ParamStructs[0].umin = ParamFct;
        break;
    case 4:
        ParamStructs[0].umax = ParamFct;
        break;
    case 5:
        ParamStructs[0].vmin = ParamFct;
        break;
    case 6:
        ParamStructs[0].vmax = ParamFct;
        break;
    case 7:
        ParamStructs[0].fw = ParamFct;
        break;
    case 8:
        ParamStructs[0].cnd = ParamFct;
        break;
    }

    while( ParamFct!= "")
    {
        if((position = ParamFct.find(";")) != string::npos   )
        {
            tmp = ParamFct;
            switch(type)
            {
            case 0:
                ParamStructs[Nb_paramfunction].fx = (tmp.substr(0,position));
                break;
            case 1:
                ParamStructs[Nb_paramfunction].fy = (tmp.substr(0,position));
                break;
            case 2:
                ParamStructs[Nb_paramfunction].fz = (tmp.substr(0,position));
                break;
            case 7:
                ParamStructs[Nb_paramfunction].fw = (tmp.substr(0,position));
                break;
            case 8:
                ParamStructs[Nb_paramfunction].cnd = (tmp.substr(0,position));
                break;
            case 3:
                ParamStructs[Nb_paramfunction].umin = (tmp.substr(0,position));
                break;
            case 4:
                ParamStructs[Nb_paramfunction].umax = (tmp.substr(0,position));
                break;
            case 5:
                ParamStructs[Nb_paramfunction].vmin = (tmp.substr(0,position));
                break;
            case 6:
                ParamStructs[Nb_paramfunction].vmax = (tmp.substr(0,position));
                break;
            }

            Nb_paramfunction++;
            tmp2 = ParamFct.substr(position+1, ParamFct.length()-1);
            ParamFct = tmp2;
        }
        else
        {
            switch(type)
            {
            case 0:
                ParamStructs[Nb_paramfunction].fx = ParamFct;
                break;
            case 1:
                ParamStructs[Nb_paramfunction].fy = ParamFct;
                break;
            case 2:
                ParamStructs[Nb_paramfunction].fz = ParamFct;
                break;
            case 7:
                ParamStructs[Nb_paramfunction].fw = ParamFct;
                break;
            case 8:
                ParamStructs[Nb_paramfunction].cnd = ParamFct;
                break;
            case 3:
                ParamStructs[Nb_paramfunction].umin = ParamFct;
                break;
            case 4:
                ParamStructs[Nb_paramfunction].umax = ParamFct;
                break;
            case 5:
                ParamStructs[Nb_paramfunction].vmin = ParamFct;
                break;
            case 6:
                ParamStructs[Nb_paramfunction].vmax = ParamFct;
                break;
            }
            ParamFct ="";
        }
    }
}

///+++++++++++++++++++++++++++++++++++++++++
void Par3D::CalculateColorsPoints(struct ComponentInfos &comp)
{
    uint Jprime,cmpId=0, K=0;
    double tmp, ValCol[100], val[10];
    val[3] = masterthread->stepMorph;

    if(comp.ThereisRGBA[comp.parisoindex] == true &&  comp.NoiseParam[comp.parisoindex].NoiseType == 0)
    {
        for(uint i=0; i<masterthread->VRgbtSize && i<100; i++)
        {
            ValCol[i] = masterthread->VRgbtParser[i].Eval(val);
        }

        for(uint i= 0; i < NbVertexTmp; i++)
        {
            val[0]= double(NormVertexTabVector[i*10+7]);
            val[1]= double(NormVertexTabVector[i*10+8]);
            val[2]= double(NormVertexTabVector[i*10+9]);

            if(masterthread->Noise != "")
                tmp  = masterthread->NoiseParser->Eval(val);
            else
                tmp =1.0;

            val[0]= tmp*double(NormVertexTabVector[i*10+7]);
            val[1]= tmp*double(NormVertexTabVector[i*10+8]);
            val[2]= tmp*double(NormVertexTabVector[i*10+9]);

            tmp  = masterthread->GradientParser->Eval(val);

            int c= int(tmp);
            tmp = std::abs(tmp - double(c));
            for (uint j=0; j < masterthread->VRgbtSize && j < 100; j+=5)
                if(tmp <= ValCol[j])
                {
                    NormVertexTabVector[i*10  ] = float(ValCol[j+1]);
                    NormVertexTabVector[i*10+1] = float(ValCol[j+2]);
                    NormVertexTabVector[i*10+2] = float(ValCol[j+3]);
                    NormVertexTabVector[i*10+3] = float(ValCol[j+4]);
                    j = 100;
                }
        }
    }
    else if(comp.ThereisRGBA[comp.parisoindex] == true &&  comp.NoiseParam[comp.parisoindex].NoiseType == 1)
    {
        for(uint i= 0; i < NbVertexTmp; i++)
        {
            if((i >= uint(comp.ParPts[2*cmpId])))
            {
                K = cmpId;
                if((masterthread->expression_XSize -1)>cmpId)
                {
                    cmpId++;
                }
            }
            val[0]= double(NormVertexTabVector[i*10+7]);
            val[1]= double(NormVertexTabVector[i*10+8]);
            val[2]= double(NormVertexTabVector[i*10+9]);

            val[7] = double(i);
            val[8] = double(Vgrid);
            val[9] = double(K);
            Jprime = (i)/(Ugrid);
            val[6] = double(Jprime);
            val[4] = val[6]/double(Ugrid) ;
            val[4] = val[4] * masterthread->dif_v[0]  + masterthread->v_inf[0];

            Jprime = (i) %  (Vgrid);
            val[5] =  double(Jprime);
            val[3] = val[5]/double(Vgrid) ;
            val[3] = val[3] * masterthread->dif_u[0]  + masterthread->u_inf[0];

            if(masterthread->Noise != "")
                tmp  = masterthread->NoiseParser->Eval(val);
            else
                tmp =1.0;

            val[0]= tmp*double(NormVertexTabVector[i*10+7]);
            val[1]= tmp*double(NormVertexTabVector[i*10+8]);
            val[2]= tmp*double(NormVertexTabVector[i*10+9]);
            val[3]*= tmp;
            val[4]*= tmp;

            NormVertexTabVector[i*10  ] = float(masterthread->RgbtParser[0].Eval(val));
            NormVertexTabVector[i*10+1] = float(masterthread->RgbtParser[1].Eval(val));
            NormVertexTabVector[i*10+2] = float(masterthread->RgbtParser[2].Eval(val));
            NormVertexTabVector[i*10+3] = float(masterthread->RgbtParser[3].Eval(val));
        }
    }
}
//+++++++++++++++++++++++++++++++++++++++++
uint Par3D::CNDtoUse(uint index, struct ComponentInfos &compts)
{
    for(uint fctnb= 0; fctnb < (masterthread->expression_XSize); fctnb++)
        if( index <= compts.ParPts[2*fctnb +1] && index >= compts.ParPts[2*fctnb])
            return fctnb;
    return 30;
}

//+++++++++++++++++++++++++++++++++++++++++

uint Par3D::CNDCalculation(uint & NbTriangleIsoSurfaceTmp, struct ComponentInfos &comp)
{
    double vals[4];
    std::vector<int> PointVerifyCond;
    std::vector<int> TypeIsoSurfaceTriangleListeCNDVector;
    uint startpoint=comp.ParPts[0];
    vals[3] = masterthread->stepMorph;
    if (masterthread->ParConditionRequired == 1)
    {
        for(uint i= startpoint; i < NbVertexTmp; i++)
        {
            vals[0] = double(NormVertexTabVector[i*10+7]);
            vals[1] = double(NormVertexTabVector[i*10+8]);
            vals[2] = double(NormVertexTabVector[i*10+9]);
            PointVerifyCond.push_back(int(masterthread->ParConditionParser[CNDtoUse(i, comp)].Eval(vals)));
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
        uint starttri = uint(comp.ParisoPositions[0]/3);

        for(uint i= starttri; i < NbTriangleIsoSurfaceTmp; i++)
            TypeIsoSurfaceTriangleListeCNDVector.push_back(1); //Init this triangle type to 1:

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
                    while(masterthread->ParConditionParser[cnd].Eval(Bprime) == 1.0 && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!(masterthread->ParConditionParser[cnd].Eval(Bprime) == 1.0) && (Alfa < 20))
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
                    while(masterthread->ParConditionParser[cnd].Eval(Cprime) == 1.0 && (Alfa < 20))
                    {
                        Cprime[0] += DiffX;
                        Cprime[1] += DiffY;
                        Cprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!(masterthread->ParConditionParser[cnd].Eval(Cprime) == 1.0) && (Alfa < 20))
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

        // Now we start sorting the Isosurfaces triangles according to the CND. We have 3 cases
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

        comp.NbTrianglesVerifyCND[comp.parisoindex]=k;
        comp.NbTrianglesNotVerifyCND[comp.parisoindex]=l;
        comp.NbTrianglesBorderCND[comp.parisoindex]=M;
        comp.ThereisCND[comp.parisoindex] = true;
    }
    else
    {
        comp.ThereisCND[comp.parisoindex] = false;
        comp.NbTrianglesVerifyCND[comp.parisoindex]=0;
        comp.NbTrianglesNotVerifyCND[comp.parisoindex]=0;
        comp.NbTrianglesBorderCND[comp.parisoindex]=0;
        for(uint i= startpoint; i < NbVertexTmp; i++)
        {
            NormVertexTabVector[i*10  ] = 0.5f;
            NormVertexTabVector[i*10+1] = 0.6f;
            NormVertexTabVector[i*10+2] = 0.8f;
            NormVertexTabVector[i*10+3] = 1.0;
        }
    }
    PointVerifyCond.clear();
    PointVerifyCond.shrink_to_fit();
    TypeIsoSurfaceTriangleListeCNDVector.clear();
    TypeIsoSurfaceTriangleListeCNDVector.shrink_to_fit();
    return 1;
}

//++++++++++++++++++++++++++++++++++++
void Par3D::BuildPar()
{
    ParamBuild(
        &(localScene->ArrayNorVer_localPt),
        &(localScene->PolyIndices_localPt),
        &localScene->PolyNumber,
        &(localScene->VertxNumber),
        &(localScene->componentsinfos),
        &(localScene->PolyIndices_localPtMin),
        &(localScene->NbPolygnNbVertexPtMin)
    );
}

//++++++++++++++++++++++++++++++++++++
void Par3D::run()
{
    BuildPar();
}

//++++++++++++++++++++++++++++++++++++
void Par3D::UpdateThredsNumber(uint NewThreadsNumber)
{
    uint tmp= WorkerThreadsNumber;
    WorkerThreadsNumber = NewThreadsNumber;
    ParWorkerThread *workerthreadstmp = new ParWorkerThread[WorkerThreadsNumber-1];
    WorkerThreadCopy(workerthreadstmp);
    //Free old memory:
    for(uint i=0; i+1<tmp; i++)
        workerthreads[i].DeleteWorkerParsers();
    delete[] workerthreads;
    //Assigne newly allocated memory
    workerthreads = workerthreadstmp;
    masterthread->WorkerThreadsNumber  = WorkerThreadsNumber;
}

//+++++++++++++++++++++++++++++++++++++++++
void Par3D::stopcalculations(bool calculation)
{
    StopCalculations = calculation;
    masterthread->StopCalculations = StopCalculations;
    for(uint nbthreads=0; nbthreads+1< WorkerThreadsNumber; nbthreads++)
        workerthreads[nbthreads].StopCalculations = StopCalculations;
}

//+++++++++++++++++++++++++++++++++++++++++++
void ParWorkerThread::emitMySignal()
{
    emit mySignal(signalVal);
}

//+++++++++++++++++++++++++++++++++++++++++++
void  ParWorkerThread::calcul_objet(uint cmp, uint idx)
{
    uint NewPosition =  10*idx, id=0;
    int PreviousSignal=0;
    uint OrignbU=uint (std::sqrt(Stack_Factor));
    uint OrignbV=OrignbU;
    uint nbU=OrignbU, nbV=OrignbV;
    uint nbstack=nbU*nbV;
    uint Iindice=0, Jindice=0;
    double* vals, res;
    double *ResX, *ResY, *ResZ, *ResW;
    uint taille=0;

    vals  = new double[3*nbstack];
    ResX  = new double[nbstack];
    ResY  = new double[nbstack];
    ResZ  = new double[nbstack];
    ResW  = new double[nbstack];

    if(activeMorph == 1)
        stepMorph += pace;

    iStart = 0;
    iFinish = 0;
    for(uint i=0; i<Ugrid; i++)
    {
        if((i% (WorkerThreadsNumber))  == MyIndex )
        {
            taille += 1;
        }
        if(MyIndex <= (i% (WorkerThreadsNumber)))
            iFinish  += 1;
    }
    iStart = iFinish - taille;

    uint remU= (iFinish-iStart)%nbU;
    uint remV= Vgrid%nbV;
    uint Totalpoints=(iFinish-iStart)*Vgrid;
    for(uint l=0; l<nbstack; l++)
        vals[l*3+2]= stepMorph;

    myParserX[cmp].AllocateStackMemory(Stack_Factor);
    myParserY[cmp].AllocateStackMemory(Stack_Factor);
    myParserZ[cmp].AllocateStackMemory(Stack_Factor);
    if(param4D == 1)
        myParserW[cmp].AllocateStackMemory(Stack_Factor);

    for(uint i=iStart; i < iFinish   ; i+=nbU)
    {
        Iindice = i;
        nbV=OrignbV;
        if((remU>0) && ((Iindice+remU)==(iFinish)))
        {
            nbU = remU;
            i= iFinish;
            nbstack = nbU*nbV;
        }

        for (uint j=0; j < Vgrid   ; j+=nbV)
        {
            Jindice = j;
            nbstack = nbU*nbV;
            if((remV>0) && ((Jindice+remV)==(Vgrid)))
            {
                nbV = remV;
                j= Vgrid;
                nbstack = nbU*nbV;
            }

            for(uint l=0; l<nbstack; l++)
            {
                vals[l*3  ]= double(Iindice+ uint(l/nbV))*dif_u[cmp]/double(Ugrid-1) + u_inf[cmp];
                vals[l*3+1]= double(Jindice+(l%nbV))*dif_v[cmp]/double(Vgrid-1) + v_inf[cmp];
            }

            if(StopCalculations)
                return;

            res = myParserX[cmp].Eval2(vals, 3, ResX, nbstack);
            if(int(res) == IF_FUNCT_ERROR)
            {
                for(uint l=0; l<nbstack; l++)
                    ResX[l] = myParserX[cmp].Eval(&(vals[l*3]));
            }

            res = myParserY[cmp].Eval2(vals, 3, ResY, nbstack);
            if(int(res) == IF_FUNCT_ERROR)
            {
                for(uint l=0; l<nbstack; l++)
                    ResY[l] = myParserY[cmp].Eval(&(vals[l*3]));
            }

            res = myParserZ[cmp].Eval2(vals, 3, ResZ, nbstack);
            if(int(res) == IF_FUNCT_ERROR)
            {
                for(uint l=0; l<nbstack; l++)
                    ResZ[l] = myParserZ[cmp].Eval(&(vals[l*3]));
            }

            if(param4D == 1)
            {
                res = myParserW[cmp].Eval2(vals, 3, ResW, nbstack);
                if(int(res) == IF_FUNCT_ERROR)
                {
                    for(uint l=0; l<nbstack; l++)
                        ResW[l] = myParserW[cmp].Eval(&(vals[l*3]));
                }
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

            int p=0;
            for(uint ii=0; ii<nbU; ii++)
                for(uint jj=0; jj<nbV; jj++)
                {
                    NormVertexTabVector[(Iindice+ii)*10*Vgrid + 10*(Jindice +jj) +7 +NewPosition] = float(ResX[p]);
                    NormVertexTabVector[(Iindice+ii)*10*Vgrid + 10*(Jindice +jj) +8 +NewPosition] = float(ResY[p]);
                    NormVertexTabVector[(Iindice+ii)*10*Vgrid + 10*(Jindice +jj) +9 +NewPosition] = float(ResZ[p]);
                    if(param4D == 1)
                        ExtraDimensionVector[(Iindice+ii)*Vgrid + (Jindice +jj) + idx] = float(ResW[p]);
                    p++;
                }
        }
    }

    delete[] vals;
    delete[] ResX;
    delete[] ResY;
    delete[] ResZ;
    delete[] ResW;
}

//++++++++++++++++++++++++++++++++++++
void Par3D::emitErrorSignal()
{
    emit ErrorSignal(int(messageerror));
}
//+++++++++++++++++++++++++++++++++++++++++
void  Par3D::ParamBuild(
    float **NormVertexTabPt,
    uint **IndexPolyTabPt,
    uint *PolyNumber,
    uint *VertxNumber,
    ComponentInfos *componentsPt,
    uint **IndexPolyTabMinPt,
    unsigned  int *NbPolyMinPt
)
{
    uint NbTriangleIsoSurfaceTmp;
    uint nbline_save=Ugrid, nbcolone_save=Vgrid, NextPosition=0;
    NbVertexTmp = NbTriangleIsoSurfaceTmp =  0;

    if(componentsPt->pariso)
    {
        NbVertexTmp = uint(NormVertexTabVector.size()/10);
        NbTriangleIsoSurfaceTmp = uint(IndexPolyTabVector.size()/3);
    }
    else
    {
        NormVertexTabVector.clear();
        NormVertexTabVector.shrink_to_fit();
        IndexPolyTabVector.clear();
        IndexPolyTabVector.shrink_to_fit();
        IndexPolyTabMinVector.clear();
        IndexPolyTabMinVector.shrink_to_fit();
    }

    ExtraDimensionVector.clear();
    ExtraDimensionVector.shrink_to_fit();
    //*******/
    componentsPt->NbComponents[componentsPt->parisoindex] = masterthread->expression_XSize;

    stopcalculations(false);

    if(masterthread->activeMorph != 1)
    {
        ptime.restart();
    }

    for(uint fctnb= 0; fctnb< masterthread->expression_XSize; fctnb++)
    {
        if(masterthread->activeMorph != 1)
        {
            message = QString("1) Cmp:"+QString::number(fctnb+1)+"/"+QString::number(masterthread->expression_XSize)+"==> Math calculation");
            emitUpdateMessageSignal();
        }

        ParamComponentId = fctnb;
        if(masterthread->gridnotnull)
        {
            initialiser_LineColumn(masterthread->grid[2*fctnb], masterthread->grid[2*fctnb+1]);

        }

        masterthread->CurrentPar   = fctnb;
        masterthread->CurrentIndex = NbVertexTmp;

        // Save Number of Polys and vertex :
        componentsPt->ParPts.push_back(NbVertexTmp);
        componentsPt->ParPts.push_back(NbVertexTmp + (Ugrid)*(Vgrid)  -1);

        NbTriangleIsoSurfaceTmp     += 2*(Ugrid  - CutU -1)*(Vgrid - CutV -1);
        for(uint nbthreads=0; nbthreads+1< WorkerThreadsNumber; nbthreads++)
        {
            workerthreads[nbthreads].CurrentPar = fctnb;
            workerthreads[nbthreads].CurrentIndex = NbVertexTmp;
        }

        ExtraDimensionVector.resize(ExtraDimensionVector.size()+Ugrid*Vgrid);
        NormVertexTabVector.resize(NormVertexTabVector.size()+10*Ugrid*Vgrid);

        for(uint nbthreads=0; nbthreads+1< WorkerThreadsNumber; nbthreads++)
            workerthreads[nbthreads].stepMorph = masterthread->stepMorph;

        masterthread->start();
        for(uint nbthreads=0; nbthreads+1< WorkerThreadsNumber; nbthreads++)
            workerthreads[nbthreads].start();

        masterthread->wait();
        for(uint nbthreads=0; nbthreads+1< WorkerThreadsNumber; nbthreads++)
            workerthreads[nbthreads].wait();

        if(StopCalculations)
        {
            initialiser_LineColumn(nbline_save, nbcolone_save);
            return;
        }

        if(masterthread->activeMorph != 1)
        {
            message += QString(" ==> Mesh generation");
            emitUpdateMessageSignal();
        }

        if(param4D == 1)
        {
            Anim_Rot4D (NbVertexTmp);
        }
        calcul_Norm(10*NbVertexTmp);
        make_PolyIndexMin(NbVertexTmp);
        make_PolyIndexTri(NbVertexTmp);

        componentsPt->ParisoPositions.push_back(6*NextPosition); //save the starting position of this component
        componentsPt->ParisoPositions.push_back(2*(Ugrid  - CutU -1)*(Vgrid - CutV -1)); //save the number of Polygones of this component
        //componentsPt->ParisoPositions.push_back(NbVertexTmp);

        NextPosition += (Ugrid  - CutU-1)*(Vgrid - CutV-1);
        NbVertexTmp    += (Ugrid)*(Vgrid);
    }

    if(masterthread->activeMorph != 1)
    {
        message = QString("2) Mesh Processing");
        emitUpdateMessageSignal();
    }

    //CND calculation for the triangles results:
    CNDCalculation(NbTriangleIsoSurfaceTmp, *componentsPt);

    // Pigment, Texture and Noise :
    if(masterthread->vrgbtnotnull)
    {
        componentsPt->ThereisRGBA[componentsPt->parisoindex] = true;
        componentsPt->NoiseParam[componentsPt->parisoindex].NoiseType = 0; //Pigments
        componentsPt->NoiseParam[componentsPt->parisoindex].VRgbtParser = masterthread->VRgbtParser;
        componentsPt->NoiseParam[componentsPt->parisoindex].GradientParser = masterthread->GradientParser;
        componentsPt->NoiseParam[componentsPt->parisoindex].Nb_vrgbts = masterthread->VRgbtSize;
    }
    else if(masterthread->RgbtSize >= 4)
    {
        componentsPt->ThereisRGBA[componentsPt->parisoindex] = true;
        componentsPt->NoiseParam[componentsPt->parisoindex].NoiseType = 1; //Texture
        componentsPt->NoiseParam[componentsPt->parisoindex].RgbtParser = masterthread->RgbtParser;
    }
    else
    {
        componentsPt->ThereisRGBA[componentsPt->parisoindex] = false;
        componentsPt->NoiseParam[componentsPt->parisoindex].NoiseType = -1; //No Pigments or texture
    }

    if(masterthread->Noise == "")
        componentsPt->NoiseParam[componentsPt->parisoindex].NoiseShape = 0;
    else
        componentsPt->NoiseParam[0].NoiseShape = 1;

    CalculateColorsPoints(*componentsPt);

    //revert to their initial values:
    if(masterthread->gridnotnull)
        initialiser_LineColumn(nbline_save, nbcolone_save);

    if(masterthread->activeMorph != 1)
    {
        message = QString("Thr:"+QString::number(WorkerThreadsNumber)+"; Cmp:"+QString::number(masterthread->expression_XSize)+"; T="+QString::number(ptime.elapsed()/1000.0)+"s");
        emitUpdateMessageSignal();
    }

    // 3) Nb Poly & Vertex :

    //if(!componentsPt->pariso)
    *PolyNumber      = uint(IndexPolyTabVector.size());//3*NbTriangleIsoSurfaceTmp;
    *VertxNumber     = uint(NormVertexTabVector.size()/10);//NbVertexTmp;
    *NbPolyMinPt     = uint(IndexPolyTabMinVector.size());//NbPolyMinimalTopology;


    *IndexPolyTabMinPt = IndexPolyTabMinVector.data();
    *NormVertexTabPt   = NormVertexTabVector.data();
    *IndexPolyTabPt    = IndexPolyTabVector.data();

    if(componentsPt->parisoindex == componentsPt->parisosize-1)
        componentsPt->Interleave = true;
    else
        componentsPt->parisoindex++;
}

//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::make_PolyIndexMin(uint index)
{
    uint k=0;
    for (uint i=0; i+CutU+1 < Ugrid ; i++)
        for (uint j=0; j+CutV+1< Vgrid ; j++)
        {
            IndexPolyTabMinVector.push_back(4);
            IndexPolyTabMinVector.push_back(i*Vgrid + j+index);
            IndexPolyTabMinVector.push_back((i+1)*Vgrid + j +index);
            IndexPolyTabMinVector.push_back((i+1)*Vgrid + (j+1)+index);
            IndexPolyTabMinVector.push_back(i*Vgrid + (j+1)+index);
            k+=5;
        }
}

//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::make_PolyIndexTri(uint index)
{
    uint k=0;
    for (uint i=0; i+CutU+1< Ugrid; i++)
        for (uint j=0; j+CutV+1< Vgrid; j++)
        {
            IndexPolyTabVector.push_back(i*Vgrid + j+index);
            IndexPolyTabVector.push_back((i+1)*Vgrid + j +index);
            IndexPolyTabVector.push_back((i+1)*Vgrid + (j+1)+index);

            IndexPolyTabVector.push_back(i*Vgrid + j+index);
            IndexPolyTabVector.push_back((i+1)*Vgrid + (j+1)+index);
            IndexPolyTabVector.push_back(i*Vgrid + (j+1)+index);
            k+=6;
        }
}

//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::calcul_Norm(uint idx)
{
//calculate Normals
    uint  i, j, deplacement = 10*Vgrid;
    float caa, bab, cab, baa, ba, ca, b4;

    for (i=0; i+1 < Ugrid  ; i++)
        for (j=0; j+1 < Vgrid  ; j++)
        {
            caa = NormVertexTabVector[(i+1)*deplacement+j*10+idx+8] - NormVertexTabVector[i*deplacement+j*10+idx+8];
            bab = NormVertexTabVector[i*deplacement+(j+1)*10+idx+9] - NormVertexTabVector[i*deplacement+j*10+idx+9];
            cab = NormVertexTabVector[(i+1)*deplacement+j*10+idx+9] - NormVertexTabVector[i*deplacement+j*10+idx+9];
            baa = NormVertexTabVector[i*deplacement+(j+1)*10+idx+8] - NormVertexTabVector[i*deplacement+j*10+idx+8];
            ba  = NormVertexTabVector[i*deplacement+(j+1)*10+idx+7] - NormVertexTabVector[i*deplacement+j*10+idx+7];
            ca  = NormVertexTabVector[(i+1)*deplacement+j*10+idx+7] - NormVertexTabVector[i*deplacement+j*10+idx+7];

            NormVertexTabVector[i*deplacement+j*10+idx+4] = caa*bab - cab*baa;
            NormVertexTabVector[i*deplacement+j*10+idx+5] = cab*ba  - ca*bab;
            NormVertexTabVector[i*deplacement+j*10+idx+6] = ca*baa  - caa*ba;

            b4  = sqrt((NormVertexTabVector[i*deplacement+j*10+idx+4]*NormVertexTabVector[i*deplacement+j*10+idx+4]) +
                       (NormVertexTabVector[i*deplacement+j*10+idx+5]*NormVertexTabVector[i*deplacement+j*10+idx+5]) +
                       (NormVertexTabVector[i*deplacement+j*10+idx+6]*NormVertexTabVector[i*deplacement+j*10+idx+6]));

            if( b4 < float(0.000001))  b4 = float(0.000001);

//Normalise:
            NormVertexTabVector[i*deplacement +j*10+idx+4]/=b4;
            NormVertexTabVector[i*deplacement +j*10+idx+5]/=b4;
            NormVertexTabVector[i*deplacement +j*10+idx+6]/=b4;
        }

    if(Ugrid>1)
    {
    i = Ugrid -1;
    for (j=0; j+1 < Vgrid   ; j++)
    {
        NormVertexTabVector[i*deplacement+j*10+idx+4] = NormVertexTabVector[(i-1)*deplacement+j*10+idx+4];
        NormVertexTabVector[i*deplacement+j*10+idx+5] = NormVertexTabVector[(i-1)*deplacement+j*10+idx+5];
        NormVertexTabVector[i*deplacement+j*10+idx+6] = NormVertexTabVector[(i-1)*deplacement+j*10+idx+6];
    }
    }

    if(Vgrid>1)
    {
    j =Vgrid -1;
    for (i=0; i+1< Ugrid  ; i++)
    {
        NormVertexTabVector[i*deplacement +j*10  +idx+ 4] = NormVertexTabVector[i*deplacement +(j-1)*10  +idx+ 4];
        NormVertexTabVector[i*deplacement +j*10+1+idx+ 4] = NormVertexTabVector[i*deplacement +(j-1)*10+1+idx+ 4];
        NormVertexTabVector[i*deplacement +j*10+2+idx+ 4] = NormVertexTabVector[i*deplacement +(j-1)*10+2+idx+ 4];
    }
    }
    if(Ugrid>1 && Vgrid>1)
    {
        i = Ugrid -1;
        j =Vgrid -1;
        NormVertexTabVector[i*deplacement +j*10  +idx+ 4]  = NormVertexTabVector[(i-1)*deplacement +(j-1)*10  +idx+ 4];
        NormVertexTabVector[i*deplacement +j*10+1+idx+ 4]  = NormVertexTabVector[(i-1)*deplacement +(j-1)*10+1+idx+ 4];
        NormVertexTabVector[i*deplacement +j*10+2+idx+ 4]  = NormVertexTabVector[(i-1)*deplacement +(j-1)*10+2+idx+ 4];
    }
}
