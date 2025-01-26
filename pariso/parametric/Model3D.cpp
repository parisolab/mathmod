/***************************************************************************
 *   Copyright (C) 2025 by Abderrahman Taha                                *
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
#include <QElapsedTimer>
static uint NbVertexTmp = 0;
static QElapsedTimer ptime;
static int nbvariables=0;
extern double ParamThreadId;
double ParComponentId=0;
extern double ComponentId;
std::vector<float>  Par3D::ExtraDimensionVector;

Par3D::~Par3D()
{
}

void Par3D::emitUpdateMessageSignal()
{
    emit UpdateMessageSignal(message);
}
ParWorkerThread::ParWorkerThread()
{



    stepMorph = 0;
    pace = 1.0/30.0;
    ParsersAllocated = ParsersAllocated_C = false;
    ParParametersList.ParFunctParameters="u,v,t";
    ParParametersList.ParComplexFunctParameters="u,v,t,Z";
    ParParametersList.ColorFunctParameters="x,y,z,u,v,i_indx,j_indx,indx,max_i,max_j,cmpId,t";
    ParParametersList.ColorComplexFunctParameters="x,y,z,u,v,i_indx,j_indx,indx,max_i,max_j,cmpId,t,Z";
}
ParWorkerThread::~ParWorkerThread()
{
}
ParMasterThread::~ParMasterThread()
{
    delete[] UsedFunct;
    delete[] UsedFunct2;
    ParamStructs.clear();
    SliderValues.clear();
    SliderNames.clear();
    Rgbts.clear();
    VRgbts.clear();
    Functs.clear();
    FunctNames.clear();
    Consts.clear();
    ConstNames.clear();
    ConstValues.clear();
    vals.clear();
    vals.shrink_to_fit();
    ResX.clear();
    ResX.shrink_to_fit();
    ResY.clear();
    ResY.shrink_to_fit();
    ResZ.clear();
    ResZ.shrink_to_fit();
    ResW.clear();
    ResW.shrink_to_fit();
    valcomplex.clear();
    valcomplex.shrink_to_fit();
}
ParMasterThread::ParMasterThread()
{
    activeMorph = -1;
    ParisoCondition = -1;
    Nb_Sliders = 0;
    Gain = 1.0;
    Octaves = 4;
    Lacunarity = 0.5;
    UsedFunct    = new bool[0];
    UsedFunct2   = new bool[0];
    ImprovedNoise(4.0,4.0,4.0); // Initialize the Noise function
}
void ParWorkerThread::run()
{
    ParCompute(CurrentComponent, CurrentIndex);
}

Par3D::Par3D(uint nbThreads, uint nbGrid, int *pt)
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
    masterthread->ThreadIndex   = 0;
    masterthread->param4D   = param4D;
    masterthread->WorkerThreadsNumber = WorkerThreadsNumber;
    masterthread->AllocateStackFactor(pt);
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        workerthreads[nbthreads].Ugrid  = Ugrid;
        workerthreads[nbthreads].Vgrid = Vgrid;
        workerthreads[nbthreads].ThreadIndex   = nbthreads+1;
        workerthreads[nbthreads].param4D   = param4D;
        workerthreads[nbthreads].WorkerThreadsNumber = WorkerThreadsNumber;
        workerthreads[nbthreads].AllocateStackFactor(pt);
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
void  Par3D::boite_englobante4D(uint idx)
{
    MINX =1000000000000.0;
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
        DIFMAXIMUM = DIFY;
    if (DIFZ > DIFMAXIMUM)
        DIFMAXIMUM = DIFZ;
    if (DIFW > DIFMAXIMUM)
        DIFMAXIMUM = DIFW;
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
void  Par3D::project_4D_to_3D(uint idx)
{
    double clp;
    uint Il = 0;
    for (uint i=0; i < Ugrid; ++i)
        for (uint j=0; j < Vgrid  ; ++j)
        {
            clp = 1.0/double(ExtraDimensionVector[i*Vgrid + j + idx] - 2);
            NormVertexTabVector[Il+idx*10+7] *= float(clp);
            NormVertexTabVector[Il+idx*10+8] *= float(clp);
            NormVertexTabVector[Il+idx*10+9] *= float(clp);
            Il += 10;
        }
}
void ParMasterThread::AllocateParsersForMasterThread()
{
    if(!ParsersAllocated || !ParsersAllocated_C)
    {
        myParserUmin = new FunctionParser[componentsNumber];
        myParserVmin = new FunctionParser[componentsNumber];
        myParserUmax = new FunctionParser[componentsNumber];
        myParserVmax = new FunctionParser[componentsNumber];
        ParisoConditionParser  = new FunctionParser[componentsNumber];
        ParamStructs.resize(componentsNumber);
        v_inf.resize(componentsNumber);
        v_sup.resize(componentsNumber);
        u_inf.resize(componentsNumber);
        u_sup.resize(componentsNumber);
        dif_v.resize(componentsNumber);
        dif_u.resize(componentsNumber);
        (RGBT_STR != "") ?
        RgbtParser = new FunctionParser[(RgbtSize = 4)] :
        RgbtParser = new FunctionParser[(RgbtSize = 0)];
        (RGBT_STR != "") ?
        RgbtParser_C = new FunctionParser_cd[(RgbtSize = 4)] :
        RgbtParser_C = new FunctionParser_cd[(RgbtSize = 0)];
        UsedFunct    = new bool[4*uint(componentsNumber)*FunctSize];
        UsedFunct2   = new bool[FunctSize*FunctSize];
        vectnotnull? nbvariables=vect[0] : nbvariables=0;
        (VRGBT_STR != "") ?
        VRgbtParser = new FunctionParser[VRgbtSize] :
        VRgbtParser = new FunctionParser[(VRgbtSize = 0)];
        if(constnotnull)
            ConstSize=0;
        GradientParser   = new FunctionParser;
        NoiseParser      = new FunctionParser;
        NoiseShapeParser = new FunctionParser;
    }
    if(!ParsersAllocated)
    {
        myParserX = new FunctionParser[componentsNumber];
        myParserY = new FunctionParser[componentsNumber];
        myParserZ = new FunctionParser[componentsNumber];
        myParserW = new FunctionParser[componentsNumber];
        if(!functnotnull)
            FunctSize = 0;
        Fct= new FunctionParser[FunctSize];
        ParsersAllocated = true;
    }
    if(!ParsersAllocated_C)
    {
        myParserX_C = new FunctionParser_cd[componentsNumber];
        myParserY_C = new FunctionParser_cd[componentsNumber];
        myParserZ_C = new FunctionParser_cd[componentsNumber];
        myParserW_C = new FunctionParser_cd[componentsNumber];
        if(!functnotnull)
            FunctSize = 0;
        Fct_C= new FunctionParser_cd[FunctSize];
        ParsersAllocated_C = true;
    }
}
void ParWorkerThread::AllocateParsersForWorkerThread(uint nbcomposants, uint nbfunct)
{
    if(!ParsersAllocated_C)
    {
        myParserX_C = new FunctionParser_cd[nbcomposants];
        myParserY_C = new FunctionParser_cd[nbcomposants];
        myParserZ_C = new FunctionParser_cd[nbcomposants];
        myParserW_C = new FunctionParser_cd[nbcomposants];
        Fct_C       = new FunctionParser_cd[nbfunct];
        ParsersAllocated_C = true;
    }
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
void ParMasterThread::DeleteMasterParsers()
{
    if(ParsersAllocated || ParsersAllocated_C)
    {
        delete[] myParserUmin;
        delete[] myParserVmin;
        delete[] myParserUmax;
        delete[] myParserVmax;
        delete[] ParisoConditionParser;
        delete[] UsedFunct;
        delete[] UsedFunct2;
        delete[] RgbtParser;
        delete[] RgbtParser_C;
        delete[] VRgbtParser;
        delete GradientParser;
        delete NoiseParser;
        delete NoiseShapeParser;
    }
    if(ParsersAllocated)
    {
        delete[] myParserX;
        delete[] myParserY;
        delete[] myParserZ;
        delete[] myParserW;
        delete[] Fct;
        ParsersAllocated = false;
    }
    if(ParsersAllocated_C)
    {
        delete[] myParserX_C;
        delete[] myParserY_C;
        delete[] myParserZ_C;
        delete[] myParserW_C;
        delete[] Fct_C;
        ParsersAllocated_C = false;
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
    VRgbts.clear();
    Functs.clear();
    FunctNames.clear();
    Consts.clear();
    ConstNames.clear();
    ConstValues.clear();
}
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
    if(ParsersAllocated_C)
    {
        delete[] myParserX_C;
        delete[] myParserY_C;
        delete[] myParserZ_C;
        delete[] myParserW_C;
        delete[] Fct_C;
        ParsersAllocated_C = false;
    }
}
void ParMasterThread::InitMasterParsers()
{
    DeleteMasterParsers();
    AllocateParsersForMasterThread();
    GradientParser->AddConstant("pi", PI);
    Cstparser.AddConstant("pi", PI);
    NoiseParser->AddConstant("pi", PI);
    NoiseParser->AddConstant("Lacunarity", Lacunarity);
    NoiseParser->AddConstant("Gain", Gain);
    NoiseParser->AddConstant("Octaves", Octaves);
    NoiseShapeParser->AddConstant("pi", PI);

    for (uint m=0; m<ImportedInternalFunctions.size(); m++)
    {
        NoiseParser->AddFunction(ImportedInternalFunctions[m].name,
                                 ImportedInternalFunctions[m].ptr,
                                 ImportedInternalFunctions[m].param);
        GradientParser->AddFunction(ImportedInternalFunctions[m].name,
                                    ImportedInternalFunctions[m].ptr,
                                    ImportedInternalFunctions[m].param);
        NoiseShapeParser->AddFunction(ImportedInternalFunctions[m].name,
                                      ImportedInternalFunctions[m].ptr,
                                      ImportedInternalFunctions[m].param);
    }
    for(uint i=0; i<componentsNumber; i++)
    {
        if(!param3d_C && !param4d_C)
        {
            myParserX[i].AddConstant("pi", PI);
            myParserY[i].AddConstant("pi", PI);
            myParserZ[i].AddConstant("pi", PI);
            myParserW[i].AddConstant("pi", PI);

            myParserX[i].AddConstant("ThreadId",ThreadIndex);
            myParserY[i].AddConstant("ThreadId",ThreadIndex);
            myParserZ[i].AddConstant("ThreadId",ThreadIndex);
            myParserW[i].AddConstant("ThreadId",ThreadIndex);

            myParserX[i].AddFunction("CmpId",CurrentComponentId, 1);
            myParserY[i].AddFunction("CmpId",CurrentComponentId, 1);
            myParserZ[i].AddFunction("CmpId",CurrentComponentId, 1);
            myParserW[i].AddFunction("CmpId",CurrentComponentId, 1);

            for (uint m=0; m<ImportedInternalFunctions.size(); m++)
            {
                myParserX[i].AddFunction(ImportedInternalFunctions[m].name,
                                         ImportedInternalFunctions[m].ptr,
                                         ImportedInternalFunctions[m].param);
                myParserY[i].AddFunction(ImportedInternalFunctions[m].name,
                                         ImportedInternalFunctions[m].ptr,
                                         ImportedInternalFunctions[m].param);
                myParserZ[i].AddFunction(ImportedInternalFunctions[m].name,
                                         ImportedInternalFunctions[m].ptr,
                                         ImportedInternalFunctions[m].param);
                myParserW[i].AddFunction(ImportedInternalFunctions[m].name,
                                         ImportedInternalFunctions[m].ptr,
                                         ImportedInternalFunctions[m].param);
            }
        }
        else
        {
            myParserX_C[i].AddConstant("pi", PI);
            myParserY_C[i].AddConstant("pi", PI);
            myParserZ_C[i].AddConstant("pi", PI);
            myParserW_C[i].AddConstant("pi", PI);

            myParserX_C[i].AddConstant("ThreadId",ThreadIndex);
            myParserY_C[i].AddConstant("ThreadId",ThreadIndex);
            myParserZ_C[i].AddConstant("ThreadId",ThreadIndex);
            myParserW_C[i].AddConstant("ThreadId",ThreadIndex);
        }
        ParisoConditionParser[i].AddConstant("pi", PI);
        myParserUmin[i].AddConstant("pi", PI);
        myParserVmin[i].AddConstant("pi", PI);
        myParserUmax[i].AddConstant("pi", PI);
        myParserVmax[i].AddConstant("pi", PI);
        for (uint m=0; m<ImportedInternalFunctions.size(); m++)
            ParisoConditionParser[i].AddFunction(ImportedInternalFunctions[m].name,
                                                 ImportedInternalFunctions[m].ptr,
                                                 ImportedInternalFunctions[m].param);
    }
    for(uint i=0; i<RgbtSize; i++)
    {
        RgbtParser_C[i].AddConstant("pi", PI);
        RgbtParser[i].AddConstant("pi", PI);
        for (uint m=0; m<ImportedInternalFunctions.size(); m++)
            RgbtParser[i].AddFunction(ImportedInternalFunctions[m].name,
                                      ImportedInternalFunctions[m].ptr,
                                      ImportedInternalFunctions[m].param);
    }
    for(uint i=0; i<VRgbtSize; i++)
    {
        VRgbtParser[i].AddConstant("pi", PI);
        for (uint m=0; m<ImportedInternalFunctions.size(); m++)
            VRgbtParser[i].AddFunction(ImportedInternalFunctions[m].name,
                                       ImportedInternalFunctions[m].ptr,
                                       ImportedInternalFunctions[m].param);
    }
    for(uint i=0; i<FunctSize; i++)
    {
        if(!param3d_C && !param4d_C)
        {
            Fct[i].AddConstant("pi", PI);
            Fct[i].AddConstant("ThreadId", ThreadIndex);
            Fct[i].AddFunction("CmpId",CurrentComponentId, 1);
            for (uint m=0; m<ImportedInternalFunctions.size(); m++)
                Fct[i].AddFunction(ImportedInternalFunctions[m].name,
                                   ImportedInternalFunctions[m].ptr,
                                   ImportedInternalFunctions[m].param);
        }
        else
        {
            Fct_C[i].AddConstant("pi", PI);
            Fct_C[i].AddConstant("ThreadId", ThreadIndex);
        }
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
    }/*
    else
    {
        ConstSize =0;
    }*/
    if(functnotnull)
    {
        FunctSize = HowManyVariables(Funct, 2);
        if(!param3d_C && !param4d_C)
        {
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
                if ((stdError.iErrorIndex = Fct[i].Parse(Functs[i],ParParametersList.ParFunctParameters)) >= 0)
                {
                    stdError.strError = Functs[i];
                    return stdError;
                }
                Fct[i].AllocateStackMemory(StackFactor, nbvariables);
            }
        }
        else
        {
            for(uint i=0; i<FunctSize; i++)
            {
                for(uint j=0; j<ConstSize; j++)
                {
                    Fct_C[i].AddConstant(ConstNames[j], ConstValues[j]);
                }
                //Add predefined constatnts:
                for(uint k=0; k<Nb_Sliders; k++)
                {
                    Fct_C[i].AddConstant(SliderNames[k], SliderValues[k]);
                }
            }
            for(uint i=0; i<FunctSize; i++)
            {
                for(uint j=0; j<i; j++)
                    if( (UsedFunct2[i*FunctSize+j]=(Functs[i].find(FunctNames[j]) != std::string::npos)))
                        Fct_C[i].AddFunction(FunctNames[j], Fct_C[j]);
                if ((stdError.iErrorIndex = Fct_C[i].Parse(Functs[i],ParParametersList.ParComplexFunctParameters)) >= 0)
                {
                    stdError.strError = Functs[i];
                    return stdError;
                }
                Fct_C[i].AllocateStackMemory(StackFactor, nbvariables);
            }
        }
    }
    else
    {
        FunctSize =0;
    }
    //Colors
    if(RGBT_STR != "")
    {
        RgbtSize = HowManyVariables(RGBT_STR, 3);
        for(uint i=0; i<RgbtSize; i++)
            for(uint j=0; j<ConstSize; j++)
            {
                RgbtParser[i].AddConstant(ConstNames[j], ConstValues[j]);
                RgbtParser_C[i].AddConstant(ConstNames[j], ConstValues[j]);
                for(uint k=0; k<Nb_Sliders; k++)
                {
                    RgbtParser[i].AddConstant(SliderNames[k], SliderValues[k]);
                    RgbtParser_C[i].AddConstant(SliderNames[k], SliderValues[k]);
                }
            }
    }
    else
    {
        RgbtSize =0;
    }
    //Texture:
    if(VRGBT_STR != "")
    {
        VRgbtSize = HowManyVariables(VRGBT_STR, 4);
        for (uint m=0; m<ImportedInternalFunctions.size(); m++)
            GradientParser->AddFunction(ImportedInternalFunctions[m].name,
                                        ImportedInternalFunctions[m].ptr,
                                        ImportedInternalFunctions[m].param);
        for(uint j=0; j<ConstSize; j++)
        {
            GradientParser->AddConstant(ConstNames[j], ConstValues[j]);
            //Add predefined constatnts:
            for(uint k=0; k<Nb_Sliders; k++)
                GradientParser->AddConstant(SliderNames[k], SliderValues[k]);
        }
        for(uint i=0; i<VRgbtSize; i++)
            for(uint j=0; j<ConstSize; j++)
            {
                VRgbtParser[i].AddConstant(ConstNames[j], ConstValues[j]);
                //Add predefined constatnts:
                for(uint k=0; k<Nb_Sliders; k++)
                    VRgbtParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            }
    }
    else
    {
        VRgbtSize =0;
    }
    if(NOISE_STR != "")
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
    HowManyParamSurface(expression_X, 0);
    HowManyParamSurface(expression_Y, 1);
    HowManyParamSurface(expression_Z, 2);
    HowManyParamSurface(inf_u, 3);
    HowManyParamSurface(sup_u, 4);
    HowManyParamSurface(inf_v, 5);
    HowManyParamSurface(sup_v, 6);
    if(param4D)
        HowManyParamSurface(expression_W, 7);
    if(cndnotnull)
    {
        ParisoCondition = 1;
        HowManyParamSurface(expression_CND, 8);
    }
    else
        ParisoCondition = -1;
    //Add defined constantes:
    for(uint i=0; i<componentsNumber; i++)
    {
        for(uint j=0; j<ConstSize; j++)
        {
            if(cndnotnull)
                ParisoConditionParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            myParserUmax[i].AddConstant(ConstNames[j], ConstValues[j]);
            myParserUmin[i].AddConstant(ConstNames[j], ConstValues[j]);
            myParserVmin[i].AddConstant(ConstNames[j], ConstValues[j]);
            myParserVmax[i].AddConstant(ConstNames[j], ConstValues[j]);
            if(!param3d_C && !param4d_C)
            {
                myParserX[i].AddConstant(ConstNames[j], ConstValues[j]);
                myParserY[i].AddConstant(ConstNames[j], ConstValues[j]);
                myParserZ[i].AddConstant(ConstNames[j], ConstValues[j]);
                myParserW[i].AddConstant(ConstNames[j], ConstValues[j]);
            }
            else
            {
                myParserX_C[i].AddConstant(ConstNames[j], ConstValues[j]);
                myParserY_C[i].AddConstant(ConstNames[j], ConstValues[j]);
                myParserZ_C[i].AddConstant(ConstNames[j], ConstValues[j]);
                myParserW_C[i].AddConstant(ConstNames[j], ConstValues[j]);
            }
        }
        //Add predefined constatnts:
        for(uint k=0; k<Nb_Sliders; k++)
        {
            if(cndnotnull)
                ParisoConditionParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            myParserUmin[i].AddConstant(SliderNames[k], SliderValues[k]);
            myParserUmax[i].AddConstant(SliderNames[k], SliderValues[k]);
            myParserVmin[i].AddConstant(SliderNames[k], SliderValues[k]);
            myParserVmax[i].AddConstant(SliderNames[k], SliderValues[k]);
            if(!param3d_C && !param4d_C)
            {
                myParserX[i].AddConstant(SliderNames[k], SliderValues[k]);
                myParserY[i].AddConstant(SliderNames[k], SliderValues[k]);
                myParserZ[i].AddConstant(SliderNames[k], SliderValues[k]);
                myParserW[i].AddConstant(SliderNames[k], SliderValues[k]);
            }
            else
            {
                myParserX_C[i].AddConstant(SliderNames[k], SliderValues[k]);
                myParserY_C[i].AddConstant(SliderNames[k], SliderValues[k]);
                myParserZ_C[i].AddConstant(SliderNames[k], SliderValues[k]);
                myParserW_C[i].AddConstant(SliderNames[k], SliderValues[k]);
            }
        }
    }
    // Add defined functions :
    if(!param3d_C && !param4d_C)
    {
        for(uint i=0; i<componentsNumber; i++)
        {
            for(uint j=0; j<FunctSize; j++)
            {
                if((UsedFunct[i*4*FunctSize+4*j  ]=(ParamStructs[i].fx.find(FunctNames[j]) != std::string::npos)))
                    myParserX[i].AddFunction(FunctNames[j], Fct[j]);
                if((UsedFunct[i*4*FunctSize+4*j+1]=(ParamStructs[i].fy.find(FunctNames[j]) != std::string::npos)))
                    myParserY[i].AddFunction(FunctNames[j], Fct[j]);
                if((UsedFunct[i*4*FunctSize+4*j+2]=(ParamStructs[i].fz.find(FunctNames[j]) != std::string::npos)))
                    myParserZ[i].AddFunction(FunctNames[j], Fct[j]);
                if((UsedFunct[i*4*FunctSize+4*j+3]=(ParamStructs[i].fw.find(FunctNames[j]) != std::string::npos)))
                    myParserW[i].AddFunction(FunctNames[j], Fct[j]);
            }
        }
    }
    else
    {
        for(uint i=0; i<componentsNumber; i++)
        {
            for(uint j=0; j<FunctSize; j++)
            {
                if((UsedFunct[i*4*FunctSize+4*j  ]=(ParamStructs[i].fx.find(FunctNames[j]) != std::string::npos)))
                    myParserX_C[i].AddFunction(FunctNames[j], Fct_C[j]);
                if((UsedFunct[i*4*FunctSize+4*j+1]=(ParamStructs[i].fy.find(FunctNames[j]) != std::string::npos)))
                    myParserY_C[i].AddFunction(FunctNames[j], Fct_C[j]);
                if((UsedFunct[i*4*FunctSize+4*j+2]=(ParamStructs[i].fz.find(FunctNames[j]) != std::string::npos)))
                    myParserZ_C[i].AddFunction(FunctNames[j], Fct_C[j]);
                if((UsedFunct[i*4*FunctSize+4*j+3]=(ParamStructs[i].fw.find(FunctNames[j]) != std::string::npos)))
                    myParserW_C[i].AddFunction(FunctNames[j], Fct_C[j]);
            }
        }
    }
    // Parse
    //rgbtnotnull_C = false;
    if((RGBT_STR != "") && (!param3d_C && !param4d_C))
    {
        for(uint i=0; i<RgbtSize; i++)
        {
            if ((stdError.iErrorIndex = RgbtParser[i].Parse(Rgbts[i],ParParametersList.ColorFunctParameters)) >= 0)
            {
                stdError.strError = Rgbts[i];
                return stdError;
            }
        }
    }
    else
    {
        for(uint i=0; i<RgbtSize; i++)
        {
            if ((stdError.iErrorIndex = RgbtParser_C[i].Parse(Rgbts[i],ParParametersList.ColorComplexFunctParameters)) >= 0)
            {
                stdError.strError = Rgbts[i];
                return stdError;
            }
        }
    }
    // Parse
    if((VRGBT_STR != "") && (VRgbtSize % 5) ==0)
    {
        if ((stdError.iErrorIndex = GradientParser->Parse(GRADIENT_STR,ParParametersList.ColorFunctParameters)) >= 0)
        {
            stdError.strError = GRADIENT_STR;
            return stdError;
        }
        for(uint i=0; i<VRgbtSize; i++)
            if ((stdError.iErrorIndex = VRgbtParser[i].Parse(VRgbts[i],ParParametersList.ColorFunctParameters)) >= 0)
            {
                stdError.strError = VRgbts[i];
                return stdError;
            }
    }
    if(NOISE_STR != "")
        if ((stdError.iErrorIndex = NoiseParser->Parse(NOISE_STR,ParParametersList.ColorFunctParameters)) >= 0)
        {
            stdError.strError = NOISE_STR;
            return stdError;
        }
    for(uint index=0; index< componentsNumber; index++)
    {
        if ((stdError.iErrorIndex = myParserUmin[index].Parse(ParamStructs[index].umin, ParParametersList.ParFunctParameters)) >= 0)
        {
            stdError.strError = ParamStructs[index].umin;
            return stdError;
        }
        u_inf[index] = myParserUmin[index].Eval(vals);
        if ((stdError.iErrorIndex = myParserUmax[index].Parse(ParamStructs[index].umax, ParParametersList.ParFunctParameters)) >= 0)
        {
            stdError.strError = ParamStructs[index].umax;
            return stdError;
        }
        u_sup[index] = myParserUmax[index].Eval(vals);
        dif_u[index] = u_sup[index] - u_inf[index];
        if ((stdError.iErrorIndex = myParserVmin[index].Parse(ParamStructs[index].vmin, ParParametersList.ParFunctParameters)) >= 0)
        {
            stdError.strError = ParamStructs[index].vmin;
            return stdError;
        }
        v_inf[index] = myParserVmin[index].Eval(vals);
        if ((stdError.iErrorIndex = myParserVmax[index].Parse(ParamStructs[index].vmax, ParParametersList.ParFunctParameters)) >= 0)
        {
            stdError.strError = ParamStructs[index].vmax;
            return stdError;
        }
        v_sup[index] = myParserVmax[index].Eval(vals);
        dif_v[index] = v_sup[index] - v_inf[index];

        if(!param3d_C && !param4d_C)
        {
            if ((stdError.iErrorIndex = myParserX[index].Parse(ParamStructs[index].fx, ParParametersList.ParFunctParameters)) >= 0)
            {
                stdError.strError = ParamStructs[index].fx;
                return stdError;
            }
            if ((stdError.iErrorIndex = myParserY[index].Parse(ParamStructs[index].fy, ParParametersList.ParFunctParameters)) >= 0)
            {
                stdError.strError = ParamStructs[index].fy;
                return stdError;
            }
            if ((stdError.iErrorIndex = myParserZ[index].Parse(ParamStructs[index].fz, ParParametersList.ParFunctParameters)) >= 0)
            {
                stdError.strError = ParamStructs[index].fz;
                return stdError;
            }
            if(param4D)
                if ((stdError.iErrorIndex = myParserW[index].Parse(ParamStructs[index].fw, ParParametersList.ParFunctParameters)) >= 0)
                {
                    stdError.strError = ParamStructs[index].fw;
                    return stdError;
                }
        }
        else
        {
            if ((stdError.iErrorIndex = myParserX_C[index].Parse(ParamStructs[index].fx, ParParametersList.ParComplexFunctParameters)) >= 0)
            {
                stdError.strError = ParamStructs[index].fx;
                return stdError;
            }
            if ((stdError.iErrorIndex = myParserY_C[index].Parse(ParamStructs[index].fy, ParParametersList.ParComplexFunctParameters)) >= 0)
            {
                stdError.strError = ParamStructs[index].fy;
                return stdError;
            }
            if ((stdError.iErrorIndex = myParserZ_C[index].Parse(ParamStructs[index].fz, ParParametersList.ParComplexFunctParameters)) >= 0)
            {
                stdError.strError = ParamStructs[index].fz;
                return stdError;
            }
            if(param4d_C)
                if ((stdError.iErrorIndex = myParserW_C[index].Parse(ParamStructs[index].fw, ParParametersList.ParComplexFunctParameters)) >= 0)
                {
                    stdError.strError = ParamStructs[index].fw;
                    return stdError;
                }
        }
        if(cndnotnull && (ParamStructs[index].cnd!=""))
            if ((stdError.iErrorIndex = ParisoConditionParser[index].Parse(ParamStructs[index].cnd, "x,y,z,t")) >= 0)
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
            workerthreads[nbthreads].Fct[ij].AddConstant("ThreadId",workerthreads[nbthreads].ThreadIndex);
            workerthreads[nbthreads].Fct[ij].AddFunction("CmpId",CurrentComponentId, 1);
            for (uint m=0; m<masterthread->ImportedInternalFunctions.size(); m++)
                workerthreads[nbthreads].Fct[ij].AddFunction(masterthread->ImportedInternalFunctions[m].name,
                                                             masterthread->ImportedInternalFunctions[m].ptr,
                                                             masterthread->ImportedInternalFunctions[m].param);
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
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].Fct[ii].Parse(masterthread->Functs[ii],masterthread->ParParametersList.ParFunctParameters)) >= 0)
            {
                masterthread->stdError.strError = masterthread->Functs[ii];
                return masterthread->stdError;
            }
            workerthreads[nbthreads].Fct[ii].AllocateStackMemory(masterthread->StackFactor, nbvariables);
        }
    }
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        //Add defined constantes:
        for(uint i=0; i<masterthread->componentsNumber; i++)
        {
            workerthreads[nbthreads].param4D   = masterthread->param4D;
            workerthreads[nbthreads].param3d_C   = masterthread->param3d_C;
            workerthreads[nbthreads].param4d_C   = masterthread->param4d_C;
            workerthreads[nbthreads].myParserX[i].AddConstant("pi", PI);
            workerthreads[nbthreads].myParserY[i].AddConstant("pi", PI);
            workerthreads[nbthreads].myParserZ[i].AddConstant("pi", PI);
            workerthreads[nbthreads].myParserW[i].AddConstant("pi", PI);

            workerthreads[nbthreads].myParserX[i].AddConstant("ThreadId", workerthreads[nbthreads].ThreadIndex);
            workerthreads[nbthreads].myParserY[i].AddConstant("ThreadId", workerthreads[nbthreads].ThreadIndex);
            workerthreads[nbthreads].myParserZ[i].AddConstant("ThreadId", workerthreads[nbthreads].ThreadIndex);
            workerthreads[nbthreads].myParserW[i].AddConstant("ThreadId", workerthreads[nbthreads].ThreadIndex);

            workerthreads[nbthreads].myParserX[i].AddFunction("CmpId",CurrentComponentId, 1);
            workerthreads[nbthreads].myParserY[i].AddFunction("CmpId",CurrentComponentId, 1);
            workerthreads[nbthreads].myParserZ[i].AddFunction("CmpId",CurrentComponentId, 1);
            workerthreads[nbthreads].myParserW[i].AddFunction("CmpId",CurrentComponentId, 1);
            for (uint m=0; m<masterthread->ImportedInternalFunctions.size(); m++)
            {
                workerthreads[nbthreads].myParserX[i].AddFunction(masterthread->ImportedInternalFunctions[m].name,
                                                                  masterthread->ImportedInternalFunctions[m].ptr,
                                                                  masterthread->ImportedInternalFunctions[m].param);
                workerthreads[nbthreads].myParserY[i].AddFunction(masterthread->ImportedInternalFunctions[m].name,
                                                                  masterthread->ImportedInternalFunctions[m].ptr,
                                                                  masterthread->ImportedInternalFunctions[m].param);
                workerthreads[nbthreads].myParserZ[i].AddFunction(masterthread->ImportedInternalFunctions[m].name,
                                                                  masterthread->ImportedInternalFunctions[m].ptr,
                                                                  masterthread->ImportedInternalFunctions[m].param);
                workerthreads[nbthreads].myParserW[i].AddFunction(masterthread->ImportedInternalFunctions[m].name,
                                                                  masterthread->ImportedInternalFunctions[m].ptr,
                                                                  masterthread->ImportedInternalFunctions[m].param);
            }

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
        for(uint i=0; i<masterthread->componentsNumber; i++)
        {
            for(uint j=0; j<masterthread->FunctSize; j++)
            {
                if(masterthread->UsedFunct[i*4*masterthread->FunctSize+4*j  ])
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
        for(uint index=0; index< masterthread->componentsNumber; index++)
        {
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserX[index].Parse(masterthread->ParamStructs[index].fx, masterthread->ParParametersList.ParFunctParameters)) >= 0)
            {
                masterthread->stdError.strError = masterthread->ParamStructs[index].fx;
                return masterthread->stdError;
            }
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserY[index].Parse(masterthread->ParamStructs[index].fy, masterthread->ParParametersList.ParFunctParameters)) >= 0)
            {
                masterthread->stdError.strError = masterthread->ParamStructs[index].fy;
                return masterthread->stdError;
            }
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserZ[index].Parse(masterthread->ParamStructs[index].fz, masterthread->ParParametersList.ParFunctParameters)) >= 0)
            {
                masterthread->stdError.strError = masterthread->ParamStructs[index].fz;
                return masterthread->stdError;
            }
            if(param4D == 1)
                if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserW[index].Parse(masterthread->ParamStructs[index].fw, masterthread->ParParametersList.ParFunctParameters)) >= 0)
                {
                    masterthread->stdError.strError = masterthread->ParamStructs[index].fw;
                    return masterthread->stdError;
                }
        }
    }
    return NodError;
}

ErrorMessage  Par3D::parse_expression2_C()
{
    ErrorMessage NodError;
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        //Functions:
        for(uint ij=0; ij<masterthread->FunctSize; ij++)
        {
            workerthreads[nbthreads].Fct_C[ij].AddConstant("pi", PI);
        }
        for(uint ii=0; ii<masterthread->FunctSize; ii++)
        {
            for(uint jj=0; jj<masterthread->ConstSize; jj++)
            {
                workerthreads[nbthreads].Fct_C[ii].AddConstant(masterthread->ConstNames[jj], masterthread->ConstValues[jj]);
            }
            //Add predefined constatnts:
            for(uint kk=0; kk<masterthread->Nb_Sliders; kk++)
            {
                workerthreads[nbthreads].Fct_C[ii].AddConstant(masterthread->SliderNames[kk], masterthread->SliderValues[kk]);
            }
        }
        for(uint ii=0; ii<masterthread->FunctSize; ii++)
        {
            for(uint jj=0; jj<ii; jj++)
                if(masterthread->UsedFunct2[ii*masterthread->FunctSize+jj])
                    workerthreads[nbthreads].Fct_C[ii].AddFunction(masterthread->FunctNames[jj], workerthreads[nbthreads].Fct_C[jj]);
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].Fct_C[ii].Parse(masterthread->Functs[ii],masterthread->ParParametersList.ParComplexFunctParameters)) >= 0)
            {
                masterthread->stdError.strError = masterthread->Functs[ii];
                return masterthread->stdError;
            }
            workerthreads[nbthreads].Fct_C[ii].AllocateStackMemory(masterthread->StackFactor, nbvariables);
        }
    }
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        //Add defined constantes:
        for(uint i=0; i<masterthread->componentsNumber; i++)
        {
            workerthreads[nbthreads].param4D   = masterthread->param4D;
            workerthreads[nbthreads].param3d_C = masterthread->param3d_C;
            workerthreads[nbthreads].param4d_C = masterthread->param4d_C;
            workerthreads[nbthreads].myParserX_C[i].AddConstant("pi", PI);
            workerthreads[nbthreads].myParserY_C[i].AddConstant("pi", PI);
            workerthreads[nbthreads].myParserZ_C[i].AddConstant("pi", PI);
            workerthreads[nbthreads].myParserW_C[i].AddConstant("pi", PI);

            workerthreads[nbthreads].myParserX_C[i].AddConstant("ThreadId", workerthreads[nbthreads].ThreadIndex);
            workerthreads[nbthreads].myParserY_C[i].AddConstant("ThreadId", workerthreads[nbthreads].ThreadIndex);
            workerthreads[nbthreads].myParserZ_C[i].AddConstant("ThreadId", workerthreads[nbthreads].ThreadIndex);
            workerthreads[nbthreads].myParserW_C[i].AddConstant("ThreadId", workerthreads[nbthreads].ThreadIndex);
            for(uint j=0; j<masterthread->ConstSize; j++)
            {
                workerthreads[nbthreads].myParserX_C[i].AddConstant(masterthread->ConstNames[j], masterthread->ConstValues[j]);
                workerthreads[nbthreads].myParserY_C[i].AddConstant(masterthread->ConstNames[j], masterthread->ConstValues[j]);
                workerthreads[nbthreads].myParserZ_C[i].AddConstant(masterthread->ConstNames[j], masterthread->ConstValues[j]);
                workerthreads[nbthreads].myParserW_C[i].AddConstant(masterthread->ConstNames[j], masterthread->ConstValues[j]);
            }
            //Add predefined sliders constatnts:
            for(uint k=0; k<masterthread->Nb_Sliders; k++)
            {
                workerthreads[nbthreads].myParserX_C[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
                workerthreads[nbthreads].myParserY_C[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
                workerthreads[nbthreads].myParserZ_C[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
                workerthreads[nbthreads].myParserW_C[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
            }
        }
        // Add defined functions :
        for(uint i=0; i<masterthread->componentsNumber; i++)
        {
            for(uint j=0; j<masterthread->FunctSize; j++)
            {
                if(masterthread->UsedFunct[i*4*masterthread->FunctSize+4*j  ])
                    workerthreads[nbthreads].myParserX_C[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct_C[j]);
                if(masterthread->UsedFunct[i*4*masterthread->FunctSize+4*j+1])
                    workerthreads[nbthreads].myParserY_C[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct_C[j]);
                if(masterthread->UsedFunct[i*4*masterthread->FunctSize+4*j+2])
                    workerthreads[nbthreads].myParserZ_C[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct_C[j]);
                if(masterthread->UsedFunct[i*4*masterthread->FunctSize+4*j+3])
                    workerthreads[nbthreads].myParserW_C[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct_C[j]);
            }
        }
    }
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint index=0; index< masterthread->componentsNumber; index++)
        {
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserX_C[index].Parse(masterthread->ParamStructs[index].fx, masterthread->ParParametersList.ParComplexFunctParameters)) >= 0)
            {
                masterthread->stdError.strError = masterthread->ParamStructs[index].fx;
                return masterthread->stdError;
            }
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserY_C[index].Parse(masterthread->ParamStructs[index].fy, masterthread->ParParametersList.ParComplexFunctParameters)) >= 0)
            {
                masterthread->stdError.strError = masterthread->ParamStructs[index].fy;
                return masterthread->stdError;
            }
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserZ_C[index].Parse(masterthread->ParamStructs[index].fz, masterthread->ParParametersList.ParComplexFunctParameters)) >= 0)
            {
                masterthread->stdError.strError = masterthread->ParamStructs[index].fz;
                return masterthread->stdError;
            }
            if(masterthread->param4d_C)
                if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserW_C[index].Parse(masterthread->ParamStructs[index].fw, masterthread->ParParametersList.ParComplexFunctParameters)) >= 0)
                {
                    masterthread->stdError.strError = masterthread->ParamStructs[index].fw;
                    return masterthread->stdError;
                }
        }
    }
    return NodError;
}

void Par3D::WorkerThreadCopy(ParWorkerThread *WorkerThreadsTmp)
{
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        WorkerThreadsTmp[nbthreads].Ugrid = masterthread->Ugrid;
        WorkerThreadsTmp[nbthreads].Vgrid = masterthread->Vgrid;
        WorkerThreadsTmp[nbthreads].ThreadIndex = nbthreads+1;
        WorkerThreadsTmp[nbthreads].param4D   = param4D;
        WorkerThreadsTmp[nbthreads].param3d_C   = masterthread->param3d_C;
        WorkerThreadsTmp[nbthreads].param4d_C   = masterthread->param4d_C;
        WorkerThreadsTmp[nbthreads].WorkerThreadsNumber = WorkerThreadsNumber;
        WorkerThreadsTmp[nbthreads].AllocateStackFactor(masterthread->ptStackFactor);
    }
}

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
        workerthreads[nbthreads].param3d_C  = masterthread->param3d_C;
        workerthreads[nbthreads].param4d_C  = masterthread->param4d_C;
    }
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
        workerthreads[nbthreads].DeleteWorkerParsers();
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
        workerthreads[nbthreads].AllocateParsersForWorkerThread(masterthread->componentsNumber, masterthread->FunctSize);
    return((masterthread->param3d_C || masterthread->param4d_C) ? parse_expression2_C() : parse_expression2());
}

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
                Rgbts.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 4)
            {
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
                Rgbts.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 4)
            {
                VRgbts.push_back(tmp3.substr(jpos+1,position-1));
            }
            NewVariables = "";
            Nb_variables++;
        }
    }
    return Nb_variables;
}

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

void Par3D::CalculateColorsPoints(struct ComponentInfos *comp, uint index)
{
    uint Iprime, Jprime,cmpId=0, K=0;
    double tmp, val[12];
    std::complex<double> val_C[13];
    std::vector<double> ValCol;
    val[11] = masterthread->stepMorph;
    val[0] = val[1] = val[2] = 0.0;

    ValCol.resize(masterthread->VRgbtSize);
    if(comp->ThereisRGBA[index] == true &&  comp->NoiseParam[comp->ParisoCurrentComponentIndex].NoiseType == 0)
    {
        uint idx=0;
        for(uint i=0; i < comp->NbComponentsType.size()-1; i++)
            idx+=comp->NbComponentsType[i];
        for(uint i= comp->ParisoVertex[2*idx]; i < NbVertexTmp; i++)
        {
            if((i >= uint(comp->ParisoVertex[2*(cmpId+idx)])))
            {
                K = cmpId;
                if((masterthread->componentsNumber -1)>cmpId)
                {
                    cmpId++;
                }
            }
            val[0]= double(NormVertexTabVector[i*10+7]); //"x,y,z,u,v,i_indx,j_indx,indx,max_i,max_j,cmpId,t"
            val[1]= double(NormVertexTabVector[i*10+8]);
            val[2]= double(NormVertexTabVector[i*10+9]);
            if(masterthread->gridnotnull)
            {
                val[7] = double(i);
                val[8] = double(masterthread->grid[2*K]);
                val[9] = double(masterthread->grid[2*K+1]);
                val[10] = double(K);
                Jprime = (i) %  (masterthread->grid[2*K+1]);
                Iprime = floor((i-Jprime)/(masterthread->grid[2*K+1]));
                val[5] = double(Iprime);
                val[6] = double(Jprime);
                val[3] = val[5]/double(masterthread->grid[2*K]);
                val[3] = val[3] * masterthread->dif_u[K]  + masterthread->u_inf[K];
                val[4] = val[6]/double(masterthread->grid[2*K+1]);
                val[4] = val[4] * masterthread->dif_v[K]  + masterthread->v_inf[K];
            }
            else
            {
                val[7] = double(i);
                val[8] = double(Ugrid);
                val[9] = double(Vgrid);
                val[10] = double(K);
                Jprime = (i) %  (Vgrid);
                Iprime = floor((i-Jprime)/(Vgrid));
                val[5] = double(Iprime);
                val[6] = double(Jprime);
                val[3] = val[5]/double(Ugrid);
                val[3] = val[3] * masterthread->dif_u[0]  + masterthread->u_inf[0];
                val[4] = val[6]/double(Vgrid);
                val[4] = val[4] * masterthread->dif_v[0]  + masterthread->v_inf[0];
            }
            for(uint li=0; li<masterthread->VRgbtSize; li++)
            {
                ValCol[li] = masterthread->VRgbtParser[li].Eval(val);
            }
            if(masterthread->NOISE_STR != "")
                tmp  = masterthread->NoiseParser->Eval(val);
            else
                tmp =1.0;
            val[0]= tmp*double(NormVertexTabVector[i*10+7]);
            val[1]= tmp*double(NormVertexTabVector[i*10+8]);
            val[2]= tmp*double(NormVertexTabVector[i*10+9]);
            tmp  = masterthread->GradientParser->Eval(val);
            for (uint j=0; j < masterthread->VRgbtSize; j+=5)
                if(tmp < ValCol[j])
                {
                    float fraction=0;
                    if(j>=5 && (ValCol[j] != ValCol[j-5]))
                    {
                        fraction = (tmp-ValCol[j-5])/(ValCol[j]-ValCol[j-5]);
                        NormVertexTabVector[i*10  ] = float(ValCol[j+1])*(fraction) + (1-fraction)*float(ValCol[(j-5)+1]);
                        NormVertexTabVector[i*10+1] = float(ValCol[j+2])*(fraction) + (1-fraction)*float(ValCol[(j-5)+2]);
                        NormVertexTabVector[i*10+2] = float(ValCol[j+3])*(fraction) + (1-fraction)*float(ValCol[(j-5)+3]);
                        NormVertexTabVector[i*10+3] = float(ValCol[j+4]);
                        j = masterthread->VRgbtSize;
                    }
                }
                else if(tmp == ValCol[j])
                {
                    NormVertexTabVector[i*10  ] = float(ValCol[j+1]);
                    NormVertexTabVector[i*10+1] = float(ValCol[j+2]);
                    NormVertexTabVector[i*10+2] = float(ValCol[j+3]);
                    NormVertexTabVector[i*10+3] = float(ValCol[j+4]);
                    j = masterthread->VRgbtSize;
                }
        }
    }
    else if(comp->ThereisRGBA[index] == true &&  comp->NoiseParam[comp->ParisoCurrentComponentIndex].NoiseType == 1)
    {
        uint idx=0;
        for(uint i=0; i < comp->NbComponentsType.size()-1; i++)
            idx+=comp->NbComponentsType[i];
        for(uint i= comp->ParisoVertex[2*idx]; i < NbVertexTmp; i++)
        {
            if((i >= uint(comp->ParisoVertex[2*(cmpId+idx)])))
            {
                K = cmpId;
                if((masterthread->componentsNumber -1)>cmpId)
                {
                    cmpId++;
                }
            }
            val[0]= double(NormVertexTabVector[i*10+7]);
            val[1]= double(NormVertexTabVector[i*10+8]);
            val[2]= double(NormVertexTabVector[i*10+9]);
            if(masterthread->gridnotnull)
            {
                val[7] = double(i);
                val[8] = double(masterthread->grid[2*K]);
                val[9] = double(masterthread->grid[2*K+1]);
                val[10] = double(K);
                Jprime = (i) %  (masterthread->grid[2*K+1]);
                Iprime = floor((i-Jprime)/(masterthread->grid[2*K+1]));
                val[5] = double(Iprime);
                val[6] = double(Jprime);
                val[3] = val[5]/double(masterthread->grid[2*K]);
                val[3] = val[3] * masterthread->dif_u[K]  + masterthread->u_inf[K];
                val[4] = val[6]/double(masterthread->grid[2*K+1]);
                val[4] = val[4] * masterthread->dif_v[K]  + masterthread->v_inf[K];
            }
            else
            {
                val[7] = double(i);
                val[8] = double(Ugrid);
                val[9] = double(Vgrid);
                val[10] = double(K);
                Jprime = (i) %  (Vgrid);
                Iprime = floor((i-Jprime)/(Vgrid));
                val[5] = double(Iprime);
                val[6] = double(Jprime);
                val[3] = val[5]/double(Ugrid);
                val[3] = val[3] * masterthread->dif_u[0]  + masterthread->u_inf[0];
                val[4] = val[6]/double(Vgrid);
                val[4] = val[4] * masterthread->dif_v[0]  + masterthread->v_inf[0];
            }
            if(masterthread->NOISE_STR != "")
                tmp  = masterthread->NoiseParser->Eval(val);
            else
                tmp =1.0;
            val[0]= tmp*double(NormVertexTabVector[i*10+7]);
            val[1]= tmp*double(NormVertexTabVector[i*10+8]);
            val[2]= tmp*double(NormVertexTabVector[i*10+9]);
            val[3]*= tmp;
            val[4]*= tmp;
            if(!masterthread->param3d_C && !masterthread->param4d_C)
            {
                NormVertexTabVector[i*10  ] = float(masterthread->RgbtParser[0].Eval(val));
                NormVertexTabVector[i*10+1] = float(masterthread->RgbtParser[1].Eval(val));
                NormVertexTabVector[i*10+2] = float(masterthread->RgbtParser[2].Eval(val));
                NormVertexTabVector[i*10+3] = float(masterthread->RgbtParser[3].Eval(val));
            }
            else
            {
                for(uint l=0; l<12; l++)
                    val_C[l]= std::complex<double> (val[l], 0);
                val_C[12]= std::complex<double> (val[3], val[4]);
                NormVertexTabVector[i*10  ] = (masterthread->RgbtParser_C[0].EvalC(val_C)).real();
                NormVertexTabVector[i*10+1] = (masterthread->RgbtParser_C[1].EvalC(val_C)).real();
                NormVertexTabVector[i*10+2] = (masterthread->RgbtParser_C[2].EvalC(val_C)).real();
                NormVertexTabVector[i*10+3] = (masterthread->RgbtParser_C[3].EvalC(val_C)).real();
            }
        }
    }
    ValCol.clear();
    ValCol.shrink_to_fit();
}

uint Par3D::CNDCalculation(uint & NbTriangleIsoSurfaceTmp, struct ComponentInfos *comp)
{
    uint idmx=0;
    for(uint i=0; i < comp->NbComponentsType.size()-1; i++)
        idmx+=comp->NbComponentsType[i];
    uint startpoint=comp->ParisoVertex[2*idmx];
    //In the case the isosurface part of a Pariso object doesn't have a CND condition
    int sz = (comp->ParisoCondition.size() ==
              comp->NbComponentsType[comp->NbComponentsType.size()-1]) ? 0 : idmx;
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
            uint compid= CNDtoUse(i, comp);
            if(comp->ParisoCondition[compid+sz])
                PointVerifyCond.push_back(8);
            else
                PointVerifyCond.push_back(int(masterthread->ParisoConditionParser[compid].Eval(vals)));
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
        uint idpx=0;
        for(uint id=0; id < comp->NbComponentsType.size()-1; id++)
            idpx+=comp->NbComponentsType[id];
        uint starttri = uint(comp->ParisoTriangle[2*idpx]/3);
        std::vector<int> TypeIsoSurfaceTriangleListeCNDVector (NbTriangleIsoSurfaceTmp-starttri, 1);
        for(uint i= starttri; i < nbtriangle; i++)
        {
            Aindex = IndexPolyTabVector[3*i    ];
            Bindex = IndexPolyTabVector[3*i + 1];
            Cindex = IndexPolyTabVector[3*i + 2];
            int TypeTriangle = -1;
            if((PointVerifyCond[Aindex-startpoint] == 8) ||
                    (PointVerifyCond[Bindex-startpoint] == 8) ||
                    (PointVerifyCond[Cindex-startpoint] == 8))
            {
                TypeTriangle = 8;
                TypeIsoSurfaceTriangleListeCNDVector[i-starttri] = 8;
            }
            else if(PointVerifyCond[Aindex-startpoint] && !PointVerifyCond[Bindex-startpoint] && !PointVerifyCond[Cindex-startpoint])
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
                /// (Bprime, B, C)
                IndexPolyTabVector.push_back(IndexBprime);
                IndexPolyTabVector.push_back(Bindex);
                IndexPolyTabVector.push_back(Cindex);
                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCNDVector.push_back(-1) : TypeIsoSurfaceTriangleListeCNDVector.push_back(1);
                NbTriangleIsoSurfaceTmp++;
                /// (Bprime, C, Cprime)
                IndexPolyTabVector.push_back(IndexBprime);
                IndexPolyTabVector.push_back(Cindex);
                IndexPolyTabVector.push_back(IndexCprime);
                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCNDVector.push_back(-1) : TypeIsoSurfaceTriangleListeCNDVector.push_back(1);
                NbTriangleIsoSurfaceTmp++;
                /// (Bprime, Cprime) --> the border
                IndexPolyTabVector.push_back(IndexBprime);
                IndexPolyTabVector.push_back(IndexCprime);
                IndexPolyTabVector.push_back(IndexCprime);
                TypeIsoSurfaceTriangleListeCNDVector.push_back(4); /// Type = 4-->Border
                NbTriangleIsoSurfaceTmp++;
            }
        }
        //***********
        //Reorganize the triangles index:
        //***********
        std::vector<uint>NewIndexPolyTabVector;
        uint k, l, M, N;
        k = l = M = N = 0;
        // In case we have a ParIso object, this will save the triangle arrangement for the parametric CND
        for(uint i=0; i<starttri; i++)
        {
            NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i  ]);
            NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+1]);
            NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+2]);
        }
        // Now we start sorting the triangles list. We have 3 cases
        for(uint i=starttri; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCNDVector[i-starttri] == 8)
            {
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i  ]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+1]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+2]);
                N++;
            }
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
        IndexPolyTabVector.shrink_to_fit();
        IndexPolyTabVector = NewIndexPolyTabVector;
        NewIndexPolyTabVector.clear();
        NewIndexPolyTabVector.shrink_to_fit();
        NbTriangleIsoSurfaceTmp = M + l + k + N;
        comp->NbTrianglesNoCND.push_back(N);
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
        comp->NbTrianglesNoCND.push_back(0);
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
void Par3D::BuildPar()
{
    ParamBuild(
        &(localScene->ArrayNorVer_localPt),
        &(localScene->PolyIndices_localPt),
        &localScene->PolyNumber,
        &(localScene->VertxNumber),
        &(localScene->componentsinfos),
        &(localScene->PolyIndices_localPtMin),
        &(localScene->NbPolygnNbVertexPtMin),
        &(localScene->NbPolygnNbVertexPtMinSize)
    );
}
void Par3D::run()
{
    BuildPar();
}
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
void Par3D::stopcalculations(bool calculation)
{
    StopCalculations = calculation;
    masterthread->StopCalculations = StopCalculations;
    for(uint nbthreads=0; nbthreads+1< WorkerThreadsNumber; nbthreads++)
        workerthreads[nbthreads].StopCalculations = StopCalculations;
}
void ParWorkerThread::emitMySignal()
{
    emit mySignal(signalVal);
}
void ParWorkerThread::AllocateStackFactor(int *pt)
{
    ptStackFactor = pt;
    OrignbU=uint(pt[3]);
    OrignbV=uint(pt[4]);
    StackFactor=pt[3]*pt[4];
    ResX.resize(StackFactor);
    ResY.resize(StackFactor);
    ResZ.resize(StackFactor);
    ResW.resize(StackFactor);
    vals.resize((count_comma(ParParametersList.ParFunctParameters)+1)*StackFactor); //  "u,v,t"
    valcomplex.resize((count_comma(ParParametersList.ParComplexFunctParameters)+1)*StackFactor); // "u,v,t,Z"
}
void  ParWorkerThread::ParCompute(uint cmp, uint idx)
{
    uint NewPosition=10*idx, id=0;
    int PreviousSignal=0;
    uint nbU=OrignbU, nbV=OrignbV;
    uint Iindice=0, Jindice=0, taille=0, nbstack=1;
    uint nbvar=count_comma(ParParametersList.ParFunctParameters)+1;// 3 because we have three parameters ParParametersList.ParFunctParameters
    std::complex<double> pc;
    double res;

    if(activeMorph == 1)
        stepMorph += pace;
    iStart = 0;
    iFinish = 0;
    for(uint i=0; i<Ugrid; i++)
    {
        if((i% (WorkerThreadsNumber))  == ThreadIndex )
        {
            taille += 1;
        }
        if(ThreadIndex <= (i% (WorkerThreadsNumber)))
            iFinish  += 1;
    }
    iStart = iFinish - taille;
    uint remU= (iFinish-iStart)%nbU;
    uint remV= Vgrid%nbV;
    uint Totalpoints=(iFinish-iStart)*Vgrid;

    if(!param3d_C && !param4d_C)
    {
        myParserX[cmp].AllocateStackMemory(StackFactor, nbvariables);
        myParserY[cmp].AllocateStackMemory(StackFactor, nbvariables);
        myParserZ[cmp].AllocateStackMemory(StackFactor, nbvariables);
        if(param4D)
            myParserW[cmp].AllocateStackMemory(StackFactor, nbvariables);
    }
    else
    {
        myParserX_C[cmp].AllocateStackMemory(StackFactor, nbvariables);
        myParserY_C[cmp].AllocateStackMemory(StackFactor, nbvariables);
        myParserZ_C[cmp].AllocateStackMemory(StackFactor, nbvariables);
        if(param4d_C)
            myParserW_C[cmp].AllocateStackMemory(StackFactor, nbvariables);
    }
    for(uint il=iStart; il < iFinish   ; il+=nbU)
    {
        Iindice = il;
        nbV=OrignbV;
        if((remU>0) && ((Iindice+remU)==(iFinish)))
        {
            nbU = remU;
            il= iFinish;
        }
        for (uint j=0; j < Vgrid; j+=nbV)
        {
            Jindice = j;
            if((remV>0) && ((Jindice+remV)==(Vgrid)))
            {
                nbV = remV;
                j= Vgrid;
            }
            nbstack = nbU*nbV;
            int pp=0;
            for(uint ii=0; ii<nbU; ii++)
                for(uint jj=0; jj<nbV; jj++)
                {
                    vals[pp*nbvar  ]= double(Iindice+ ii)*dif_u[cmp]/double(Ugrid-1) + u_inf[cmp];
                    vals[pp*nbvar+1]= double(Jindice+ jj)*dif_v[cmp]/double(Vgrid-1) + v_inf[cmp];
                    vals[pp*nbvar+2]= stepMorph;
                    ++pp;
                }
            if(StopCalculations)
            {
                return;
            }
            if(!param3d_C && !param4d_C)
            {
                res = myParserX[cmp].Eval2(&(vals[0]), nbvar, &(ResX[0]), nbstack);
                if(int(res) == VAR_OVERFLOW)
                {
                    StopCalculations=true;
                    return;
                }
                if(int(res) == IF_FUNCT_ERROR)
                {
                    for(uint l=0; l<nbstack; l++)
                        ResX[l] = myParserX[cmp].Eval(&(vals[l*nbvar]));
                }
                res = myParserY[cmp].Eval2(&(vals[0]), nbvar, &(ResY[0]), nbstack);
                if(int(res) == VAR_OVERFLOW)
                {
                    StopCalculations=true;
                    return;
                }
                if(int(res) == IF_FUNCT_ERROR)
                {
                    for(uint l=0; l<nbstack; l++)
                        ResY[l] = myParserY[cmp].Eval(&(vals[l*nbvar]));
                }
                res = myParserZ[cmp].Eval2(&(vals[0]), nbvar, &(ResZ[0]), nbstack);
                if(int(res) == VAR_OVERFLOW)
                {
                    StopCalculations=true;
                    return;
                }
                if(int(res) == IF_FUNCT_ERROR)
                {
                    for(uint l=0; l<nbstack; l++)
                        ResZ[l] = myParserZ[cmp].Eval(&(vals[l*nbvar]));
                }
                if(param4D)
                {
                    res = myParserW[cmp].Eval2(&(vals[0]), nbvar, &(ResW[0]), nbstack);
                    if(int(res) == VAR_OVERFLOW)
                    {
                        StopCalculations=true;
                        return;
                    }
                    if(int(res) == IF_FUNCT_ERROR)
                    {
                        for(uint l=0; l<nbstack; l++)
                            ResW[l] = myParserW[cmp].Eval(&(vals[l*nbvar]));
                    }
                }
            }
            else
            {
                for(uint l=0; l<nbstack; l++)
                {
                    valcomplex[l*4  ] = std::complex<double>(vals[l*nbvar  ] , 0);
                    valcomplex[l*4+1] = std::complex<double>(vals[l*nbvar+1] , 0);
                    valcomplex[l*4+2] = std::complex<double>(vals[l*nbvar+2] , 0);
                    valcomplex[l*4+3] = std::complex<double>(vals[l*nbvar  ] , vals[l*nbvar+1]);
                }
                for(uint l=0; l<nbstack; l++)
                {
                    pc = (myParserX_C[cmp].EvalC(&valcomplex[l*4]));
                    ResX[l] = pc.real();
                }
                for(uint l=0; l<nbstack; l++)
                {
                    pc = (myParserY_C[cmp].EvalC(&valcomplex[l*4]));
                    ResY[l] = pc.real();
                }
                for(uint l=0; l<nbstack; l++)
                {
                    pc = (myParserZ_C[cmp].EvalC(&valcomplex[l*4]));
                    ResZ[l] = pc.real();
                }
                if(param4d_C)
                {
                    for(uint l=0; l<nbstack; l++)
                    {
                        pc = (myParserW_C[cmp].EvalC(&valcomplex[l*4]));
                        ResW[l] = pc.real();
                    }
                }
            }
            //Signal emission:
            id+=nbstack;
            if(ThreadIndex == 0 && activeMorph != 1)
            {
                Totalpoints !=0 ? (signalVal = int((id*100)/Totalpoints)) : (signalVal = 100);
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
                    ParisoObject::NormVertexTabVector[(Iindice+ii)*10*Vgrid + 10*(Jindice +jj) +7 +NewPosition] = float(ResX[p]);
                    ParisoObject::NormVertexTabVector[(Iindice+ii)*10*Vgrid + 10*(Jindice +jj) +8 +NewPosition] = float(ResY[p]);
                    ParisoObject::NormVertexTabVector[(Iindice+ii)*10*Vgrid + 10*(Jindice +jj) +9 +NewPosition] = float(ResZ[p]);
                    if(param4D || param4d_C)
                        Par3D::ExtraDimensionVector[(Iindice+ii)*Vgrid + (Jindice +jj) + idx] = float(ResW[p]);
                    p++;
                }
        }
    }
}
void Par3D::emitErrorSignal()
{
    emit ErrorSignal(int(messageerror));
}
void Par3D::copycomponent(struct ComponentInfos* copy, struct ComponentInfos* origin)
{
    copy->ParisoTriangle = origin->ParisoTriangle;
    copy->ParisoVertex          = origin->ParisoVertex;
    copy->NbComponentsType    = origin->NbComponentsType;
    copy->ParisoCurrentComponentIndex = origin->ParisoCurrentComponentIndex;
    copy->ParisoNbComponents          = origin->ParisoNbComponents;
    copy->Interleave                  = origin->Interleave;
    copy->pariso                      = origin->pariso;
    copy->updateviewer                = origin->updateviewer;
    copy->ThereisCND                  = origin->ThereisCND;
    copy->ParisoCondition             = origin->ParisoCondition;
    copy->ThereisRGBA                 = origin->ThereisRGBA;
    copy->NbTrianglesVerifyCND        = origin->NbTrianglesVerifyCND;
    copy->NbTrianglesNoCND            = origin->NbTrianglesNoCND;
    copy->NbTrianglesNotVerifyCND     = origin->NbTrianglesNotVerifyCND;
    copy->NbTrianglesBorderCND        = origin->NbTrianglesBorderCND;
    for(int i=0; i<2; i++)
    {
        copy->NoiseParam[i]  = origin->NoiseParam[i];
    }
}

void  Par3D::ParamBuild(
    float **NormVertexTabPt,
    uint **IndexPolyTabPt,
    uint *PolyNumber,
    uint *VertxNumber,
    ComponentInfos *componentsPt,
    uint **IndexPolyTabMinPt,
    unsigned  int *NbPolyMinPt,
    unsigned  int *MinimPolySize
)
{
    uint NbTriangleIsoSurfaceTmp;
    uint nbline_save=Ugrid, nbcolone_save=Vgrid, NextPosition=0;
    bool ParisoType=false;
    NbVertexTmp = NbTriangleIsoSurfaceTmp =  0;
    componentsPt->updateviewer= false;
    componentsPt->NbParametricMeshLines=0;
    componentsPt->MinParametricMeshLines=0;
    componentsPt->ParametricGrid.clear();
    clear(components);
    components->ParisoCondition = componentsPt->ParisoCondition;
    if(((componentsPt->pariso && componentsPt->ParisoCurrentComponentIndex>0)))
    {
        NbVertexTmp = uint(NormVertexTabVector.size()/10);
        NbTriangleIsoSurfaceTmp = uint(IndexPolyTabVector.size()/3);
        copycomponent(components, componentsPt);
    }
    else
    {
        if((ParisoType=componentsPt->pariso))
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
    ExtraDimensionVector.clear();
    ExtraDimensionVector.shrink_to_fit();
    components->NbComponentsType.push_back(masterthread->componentsNumber);
    stopcalculations(false);
    if(masterthread->activeMorph != 1)
    {
        ptime.restart();
    }
    for(uint fctnb= 0; fctnb< masterthread->componentsNumber; fctnb++)
    {
        if(masterthread->activeMorph != 1)
        {
            message = QString("1) Cmp:"+QString::number(fctnb+1)+"/"+QString::number(masterthread->componentsNumber)+"==> Math calculation");
            emitUpdateMessageSignal();
        }
        ComponentId = fctnb;
        if(masterthread->gridnotnull)
        {
            initialiser_LineColumn(masterthread->grid[2*fctnb], masterthread->grid[2*fctnb+1]);
        }
        masterthread->CurrentComponent   = fctnb;
        masterthread->CurrentIndex = NbVertexTmp;
        // Save Number of Polys and vertex :
        components->ParisoVertex.push_back(NbVertexTmp);
        components->ParisoVertex.push_back(NbVertexTmp + (Ugrid)*(Vgrid)  -1);

        NbTriangleIsoSurfaceTmp     += 2*(Ugrid  - CutU -1)*(Vgrid - CutV -1);
        for(uint nbthreads=0; nbthreads+1< WorkerThreadsNumber; nbthreads++)
        {
            workerthreads[nbthreads].CurrentComponent = fctnb;
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
        make_PolyIndexMin(NbVertexTmp, componentsPt);
        make_PolyIndexTri(NbVertexTmp);
        components->ParisoTriangle.push_back(6*NextPosition); //save the starting position of this component
        components->ParisoTriangle.push_back(2*(Ugrid  - CutU -1)*(Vgrid - CutV -1)); //save the number of Polygones of this component

        NextPosition   += (Ugrid  - CutU-1)*(Vgrid - CutV-1);
        NbVertexTmp    += (Ugrid)*(Vgrid);
    }
    if(masterthread->activeMorph != 1)
    {
        message = QString("2) Mesh Processing");
        emitUpdateMessageSignal();
    }
    //CND calculation for the triangles results:
    CNDCalculation(NbTriangleIsoSurfaceTmp, components);
    // Pigment, Texture and Noise :
    if(masterthread->VRGBT_STR != "")
    {
        components->ThereisRGBA.push_back(true);
        components->NoiseParam[components->ParisoCurrentComponentIndex].NoiseType = 0; //Pigments
        components->NoiseParam[components->ParisoCurrentComponentIndex].VRgbtParser = masterthread->VRgbtParser;
        components->NoiseParam[components->ParisoCurrentComponentIndex].GradientParser = masterthread->GradientParser;
        components->NoiseParam[components->ParisoCurrentComponentIndex].Nb_vrgbts = masterthread->VRgbtSize;
    }
    else if(masterthread->RgbtSize >= 4)
    {
        components->ThereisRGBA.push_back(true);
        components->NoiseParam[components->ParisoCurrentComponentIndex].NoiseType = 1; //Texture
        components->NoiseParam[components->ParisoCurrentComponentIndex].RgbtParser = masterthread->RgbtParser;
    }
    else
    {
        components->ThereisRGBA.push_back(false);
        components->NoiseParam[components->ParisoCurrentComponentIndex].NoiseType = -1; //No Pigments or texture
    }
    if(masterthread->NOISE_STR == "")
        components->NoiseParam[components->ParisoCurrentComponentIndex].NoiseShape = 0;
    else
        components->NoiseParam[components->ParisoCurrentComponentIndex].NoiseShape = 1;
    CalculateColorsPoints(components, components->ThereisRGBA.size()-1);
    //revert to their initial values:
    if(masterthread->gridnotnull)
        initialiser_LineColumn(nbline_save, nbcolone_save);
    if(masterthread->activeMorph != 1)
    {
        message = QString("   [Threads:"+QString::number(WorkerThreadsNumber)+"; Cmp:"+QString::number(masterthread->componentsNumber)+"; T="+QString::number(ptime.elapsed()/1000.0)+"s ]");
        emitUpdateMessageSignal();
    }
    // 3) Nb Poly & Vertex :
    *PolyNumber      = uint(IndexPolyTabVector.size());//3*NbTriangleIsoSurfaceTmp;
    *VertxNumber     = uint(NormVertexTabVector.size()/10);//NbVertexTmp;
    *NbPolyMinPt     = uint(IndexPolyTabMinVector.size());
    NormVertexTabVector.resize(NormVertexTabVector.size()+ (12+60+36)*10); // To add memory space to store the cube 12 vertices (three quads)
    uint startpl = 0;
    uint actualpointindice=0;
    if(!ParisoType)
    {
        for (uint i = 0; i < *NbPolyMinPt; i++)
        {
            uint polysize = IndexPolyTabMinVector[startpl++];
            for (uint j = 0; j < polysize; j++)
            {
                actualpointindice = IndexPolyTabMinVector[startpl];
                IndexPolyTabVector.push_back(actualpointindice);
                startpl++;
            }
            i += polysize;
        }
        IndexPolyTabMinVector2.clear();
        for (uint i = 0; i < *NbPolyMinPt; i++)
        {
            uint polysize = IndexPolyTabMinVector[i];
            IndexPolyTabMinVector2.push_back(polysize);
            i += polysize;
        }
    }
    *MinimPolySize = IndexPolyTabVector.size() - *PolyNumber;
    if(!ParisoType)
    {
        *NbPolyMinPt     = uint(IndexPolyTabMinVector2.size());
        *IndexPolyTabMinPt = IndexPolyTabMinVector2.data();
    }
    else
    {
        *NbPolyMinPt     = uint(IndexPolyTabMinVector.size());
        *IndexPolyTabMinPt = IndexPolyTabMinVector.data();
    }
    *NormVertexTabPt   = NormVertexTabVector.data();
    *IndexPolyTabPt    = IndexPolyTabVector.data();

    copycomponent(componentsPt, components);
    componentsPt->Interleave = true;
    if(componentsPt->ParisoCurrentComponentIndex != (componentsPt->ParisoNbComponents-1))
        componentsPt->ParisoCurrentComponentIndex += 1;
    else
        componentsPt->ParisoCurrentComponentIndex = 0;
    InitShowComponent(componentsPt);
    componentsPt->updateviewer = true;
}

void Par3D::InitShowComponent(struct ComponentInfos *cpInfos)
{
    cpInfos->ShowParIsoCmp.clear();
    for(uint i=0; i<cpInfos->NbComponentsType[cpInfos->NbComponentsType.size()-1]; i++)
        cpInfos->ShowParIsoCmp.push_back(true);
}

void  Par3D::make_PolyIndexMin(uint index, ComponentInfos *cp)
{
    cp->NbParametricMeshLines += (Ugrid+Vgrid);
    cp->MinParametricMeshLines += 2*Ugrid*Vgrid;
    cp->ParametricGrid.push_back(Ugrid);
    cp->ParametricGrid.push_back(Vgrid);
    for (uint i=0; i+CutU < Ugrid ; i++)
    {
        IndexPolyTabMinVector.push_back(Vgrid);
        for (uint j=0; j+CutV< Vgrid ; j++)
        {
            IndexPolyTabMinVector.push_back(i*Vgrid + j+index);
        }
    }
    for (uint i=0; i+CutV < Vgrid ; i++)
    {
        IndexPolyTabMinVector.push_back(Ugrid);
        for (uint j=0; j+CutU< Ugrid ; j++)
        {
            IndexPolyTabMinVector.push_back(i + j*Vgrid + index);
        }
    }
}

void  Par3D::make_PolyIndexTri(uint index)
{
    for (uint i=0; i+CutU+1< Ugrid; i++)
        for (uint j=0; j+CutV+1< Vgrid; j++)
        {
            IndexPolyTabVector.push_back(i*Vgrid + j+index);
            IndexPolyTabVector.push_back((i+1)*Vgrid + j +index);
            IndexPolyTabVector.push_back((i+1)*Vgrid + (j+1)+index);

            IndexPolyTabVector.push_back(i*Vgrid + j+index);
            IndexPolyTabVector.push_back((i+1)*Vgrid + (j+1)+index);
            IndexPolyTabVector.push_back(i*Vgrid + (j+1)+index);
        }
}

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
            if( b4 < float(0.0000001))  b4 = float(0.0000001);
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
