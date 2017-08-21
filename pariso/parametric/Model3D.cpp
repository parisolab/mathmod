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
 *   51 Franklin Street, Fifth Floor,Boston, MA 02110-1301 USA             *
 ***************************************************************************/
#include "Model3D.h"

static int TypeDrawin=10;
static int TypeDrawinNormStep = 4;
static int PreviousSizeMinimalTopology =0;
static int NbPolyMinimalTopology =0;
static int NbVertexTmp = 0;

static float*     NormVertexTab;
static float*     ExtraDimension;

CellNoise *NoiseFunction2 = new CellNoise();
ImprovedNoise *PNoise2 = new ImprovedNoise(4., 4., 4.);

double TurbulenceWorley2(const double* p)
{
    return NoiseFunction2->CellNoiseFunc(
               p[0],
               p[1],
               p[2],
               (int)p[3],
               (int)p[4],
               (int)p[5]);
}

//+++++++++++++++++++++++++++++++++++++++++
double TurbulencePerlin2(const double* p)
{
    return PNoise2->FractalNoise3D(
               p[0],
               p[1],
               p[2],
               (int)p[3],
               p[4],
               p[5]);
}

//+++++++++++++++++++++++++++++++++++++++++
Par3D::~Par3D()
{
}

//+++++++++++++++++++++++++++++++++++++++++
ParWorkerThread::ParWorkerThread()
{
    stepMorph = 0;
    pace = (double)1/(double)30;
    ParsersAllocated = false;
}
//+++++++++++++++++++++++++++++++++++++++++
ParMasterThread::~ParMasterThread()
{
}
/*
//+++++++++++++++++++++++++++++++++++++++++
void ParMasterThread::run()
{
    ParCompute(CurrentPar);
}
*/
ParMasterThread::ParMasterThread()
{
    activeMorph = -1;
    ParConditionRequired = -1;
    Nb_Sliders = -1;
    Gain = 1.0;
    Octaves = 4;
    Lacunarity = 0.5;
    //Add predefined constatnts:
    for(int i=0; i<20; i++)
    {
        SliderNames[i] = "Param_"+QString::number(i).toStdString();
        SliderValues[i] = 1;
    }
}

//+++++++++++++++++++++++++++++++++++++++++
Par3D::Par3D(int maxpoints)
{
    initialiser_parametres();
    NormVertexTab  = new float [10*maxpoints];
    ExtraDimension = new float [maxpoints];
}

//+++++++++++++++++++++++++++++++++++++++++
void ParWorkerThread::run()
{
    ParCompute(CurrentPar);
}

//+++++++++++++++++++++++++++++++++++++++++
void ParWorkerThread::ParCompute(int fctnb)
{
        calcul_objet(fctnb);
}

//+++++++++++++++++++++++++++++++++++++++++
void ParMasterThread::AllocateParsersForThread()
{
    AllocateParsersForMasterThread();
    initialiser_parseur();
}

//+++++++++++++++++++++++++++++++++++++++++
void Par3D::initialiser_parametres()
{
    nb_ligne = nb_colone = 50;
    largeur_fenetre = 620;
    hauteur_fenetre = 620;
    coupure_col = coupure_ligne = 0;
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

    WorkerThreadsNumber = 4;
    workerthreads = new ParWorkerThread[WorkerThreadsNumber-1];
    masterthread  = new ParMasterThread();

    masterthread->AllocateParsersForThread();

    masterthread->nb_ligne  = nb_ligne;
    masterthread->nb_colone = nb_colone;
    masterthread->MyIndex   = 0;
    masterthread->param4D   = param4D;
    masterthread->WorkerThreadsNumber = WorkerThreadsNumber;

    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
    {
        workerthreads[nbthreads].nb_ligne  = nb_ligne;
        workerthreads[nbthreads].nb_colone = nb_colone;
        workerthreads[nbthreads].MyIndex   = nbthreads+1;
        workerthreads[nbthreads].param4D   = param4D;
        workerthreads[nbthreads].WorkerThreadsNumber = WorkerThreadsNumber;
    }
}

//+++++++++++++++++++++++++++++++++++++++++
void ParMasterThread::initialiser_parseur()
{
    NoiseParser->AddConstant("pi", PI);
    NoiseParser->AddFunction("NoiseW",TurbulenceWorley2, 6);
    NoiseParser->AddFunction("NoiseP",TurbulencePerlin2, 6);
    NoiseParser->AddConstant("Lacunarity", Lacunarity);
    NoiseParser->AddConstant("Gain", Gain);
    NoiseParser->AddConstant("Octaves", Octaves);

    NoiseShapeParser->AddConstant("pi", PI);
    NoiseShapeParser->AddFunction("NoiseW",TurbulenceWorley2, 6);
    NoiseShapeParser->AddFunction("NoiseP",TurbulencePerlin2, 6);
    for(int i=0; i<NbComponent; i++)
    {
        myParserUmin[i].AddConstant("pi", PI);
        myParserUmax[i].AddConstant("pi", PI);
        myParserVmin[i].AddConstant("pi", PI);
        myParserVmax[i].AddConstant("pi", PI);
        myParserX[i].AddConstant("pi", PI);
        myParserY[i].AddConstant("pi", PI);
        myParserZ[i].AddConstant("pi", PI);
        myParserW[i].AddConstant("pi", PI);
        myParserCND[i].AddConstant("pi", PI);

        myParserX[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserX[i].AddFunction("NoiseP",TurbulencePerlin2, 6);

        myParserY[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserY[i].AddFunction("NoiseP",TurbulencePerlin2, 6);

        myParserZ[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserZ[i].AddFunction("NoiseP",TurbulencePerlin2, 6);

        myParserW[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserW[i].AddFunction("NoiseP",TurbulencePerlin2, 6);

        myParserCND[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserCND[i].AddFunction("NoiseP",TurbulencePerlin2, 6);
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
/*
//++++++++++++++++++++++++++++++++++++++++
void  Par3D::rotation3()
{
    mat_rotation4D.unit();
    // Construction de la matrice de trnsformation
    if(tetaxy_ok == 1)    mat_rotation4D.xyrot(tetaxy);
    if(tetaxz_ok == 1)    mat_rotation4D.xzrot(tetaxz);
    if(tetayz_ok == 1)    mat_rotation4D.yzrot(tetayz);
// On applique cette transformation a la matrice principale "mat"
    mat4D.mult(mat_rotation4D);
}
*/
//+++++++++++++++++++++++++++++++++++++++++
void  Par3D::boite_englobante4D(int idx)
{
    MINX =999999999;
    MINY =999999999;
    MINZ =999999999;
    MINW =999999999;

    MAXX =-999999999;
    MAXY =-999999999;
    MAXZ =-999999999;
    MAXW =-999999999;

    int IDX = 0;
    for (int i=0; i < nb_ligne; i++)
        for (int j=0; j < nb_colone; j++)
        {
            if(MINX > NormVertexTab[IDX + 3 + idx*TypeDrawin + TypeDrawinNormStep] ) MINX = NormVertexTab[IDX + 3 + idx*TypeDrawin + TypeDrawinNormStep];
            if(MINY > NormVertexTab[IDX + 4 + idx*TypeDrawin + TypeDrawinNormStep] ) MINY = NormVertexTab[IDX + 4 + idx*TypeDrawin + TypeDrawinNormStep];
            if(MINZ > NormVertexTab[IDX + 5 + idx*TypeDrawin + TypeDrawinNormStep] ) MINZ = NormVertexTab[IDX + 5 + idx*TypeDrawin + TypeDrawinNormStep];
            if(MINW > ExtraDimension[i*nb_ligne + j + idx] ) MINW = ExtraDimension[i*nb_ligne + j + idx];

            if(MAXX < NormVertexTab[IDX + 3 + idx*TypeDrawin + TypeDrawinNormStep] ) MAXX = NormVertexTab[IDX + 3 + idx*TypeDrawin + TypeDrawinNormStep];
            if(MAXY < NormVertexTab[IDX + 4 + idx*TypeDrawin + TypeDrawinNormStep] ) MAXY = NormVertexTab[IDX + 4 + idx*TypeDrawin + TypeDrawinNormStep];
            if(MAXZ < NormVertexTab[IDX + 5 + idx*TypeDrawin + TypeDrawinNormStep] ) MAXZ = NormVertexTab[IDX + 5 + idx*TypeDrawin + TypeDrawinNormStep];
            if(MAXW < ExtraDimension[i*nb_ligne + j + idx] ) MAXW = ExtraDimension[i*nb_ligne + j + idx];
            IDX +=TypeDrawin;
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
    };
    if (DIFZ > DIFMAXIMUM)
    {
        DIFMAXIMUM = DIFZ;
    };
    if (DIFW > DIFMAXIMUM)
    {
        DIFMAXIMUM = DIFW;
    };
// On va inclure cet objet dans un HperCube de langueur maximum
// egale a "hauteur_fenetre"

    double decalage_xo  = -(MINX +MAXX)/2 ;
    double decalage_yo  = -(MINY +MAXY)/2 ;
    double decalage_zo  = -(MINZ +MAXZ)/2 ;
    double decalage_wo = -(MINW +MAXW)/2 ;
    IDX =0;
    for (int i=0; i < nb_ligne   ; i++)
        for (int j=0; j < nb_colone   ; j++)
        {
            NormVertexTab[IDX + 3 + idx*TypeDrawin+ TypeDrawinNormStep]= (NormVertexTab[IDX + 3 + idx*TypeDrawin+ TypeDrawinNormStep] + decalage_xo)/DIFMAXIMUM ;
            NormVertexTab[IDX + 4 + idx*TypeDrawin+ TypeDrawinNormStep] = (NormVertexTab[IDX + 4 + idx*TypeDrawin+ TypeDrawinNormStep] + decalage_yo)/DIFMAXIMUM ;
            NormVertexTab[IDX + 5 + idx*TypeDrawin+ TypeDrawinNormStep] = (NormVertexTab[IDX + 5 + idx*TypeDrawin+ TypeDrawinNormStep] + decalage_zo)/DIFMAXIMUM ;
            ExtraDimension[i*nb_ligne + j + idx] = (ExtraDimension[i*nb_ligne + j + idx] + decalage_wo)/DIFMAXIMUM ;
            IDX +=TypeDrawin;
        }
}

//+++++++++++++++++++++++++++++++++++++++++
void  Par3D::Invert_boite_englobante4D(int idx)
{
    double decalage_xo  = -(MINX +MAXX)/2;
    double decalage_yo  = -(MINY +MAXY)/2;
    double decalage_zo  = -(MINZ +MAXZ)/2;
    int IDX =0;
    for (int i=0; i < nb_ligne   ; i++)
        for (int j=0; j < nb_colone   ; j++)
        {
            NormVertexTab[IDX + 3 + idx*TypeDrawin+ TypeDrawinNormStep] = (NormVertexTab[IDX + 3 + idx*TypeDrawin+ TypeDrawinNormStep]*DIFMAXIMUM -  decalage_xo);
            NormVertexTab[IDX + 4 + idx*TypeDrawin+ TypeDrawinNormStep] = (NormVertexTab[IDX + 4 + idx*TypeDrawin+ TypeDrawinNormStep]*DIFMAXIMUM -  decalage_yo);
            NormVertexTab[IDX + 5 + idx*TypeDrawin+ TypeDrawinNormStep] = (NormVertexTab[IDX + 5 + idx*TypeDrawin+ TypeDrawinNormStep]*DIFMAXIMUM -  decalage_zo);
            IDX +=TypeDrawin;
        }
}

//+++++++++++++++++++++++++++++++++++++++++
void Par3D::Anim_Rot4D (int idx)
{
    rotation4();
    calcul_points4(idx);         // On applique la rotation 4D
    boite_englobante4D(idx);
    if(param4D == 1)
        project_4D_to_3D(idx);
    Invert_boite_englobante4D(idx);
}

//+++++++++++++++++++++++++++++++++++++++++
void  Par3D::calcul_points4(int idx)
{
    int i,j;
    double tp1, tp2, tp3, tp4;
    // Changement de coordonnees des points selon les
    // angles angex et angley
    int lndex =0;
    for (i=0; i < nb_ligne  ; i++)
        for (j=0; j < nb_colone   ; j++)
        {
            tp1 = NormVertexTab[lndex + 3 + idx*TypeDrawin+ TypeDrawinNormStep];
            tp2 = NormVertexTab[lndex + 4 + idx*TypeDrawin+ TypeDrawinNormStep];
            tp3 = NormVertexTab[lndex + 5 + idx*TypeDrawin+ TypeDrawinNormStep];
            tp4 = ExtraDimension[i*nb_ligne + j + idx];
            if(param4D == 1)
            {
                NormVertexTab[lndex + 3 + idx*TypeDrawin+ TypeDrawinNormStep] = mat4D.xx*tp1 + mat4D.xy*tp2 + mat4D.xz*tp3 + mat4D.xw*tp4 + mat4D.xo;
                NormVertexTab[lndex + 4 + idx*TypeDrawin+ TypeDrawinNormStep] = mat4D.yx*tp1 + mat4D.yy*tp2 + mat4D.yz*tp3 + mat4D.yw*tp4 + mat4D.yo;
                NormVertexTab[lndex + 5 + idx*TypeDrawin+ TypeDrawinNormStep] = mat4D.zx*tp1 + mat4D.zy*tp2 + mat4D.zz*tp3 + mat4D.zw*tp4 + mat4D.zo;
                ExtraDimension[i*nb_ligne + j + idx] = mat4D.wx*tp1 + mat4D.wy*tp2 + mat4D.wz*tp3 + mat4D.ww*tp4 + mat4D.wo;
            }
            else
            {
                NormVertexTab[lndex + 3 + idx*TypeDrawin+ TypeDrawinNormStep] = mat4D.xx*tp1 + mat4D.xy*tp2 + mat4D.xz*tp3 + mat4D.xo;
                NormVertexTab[lndex + 4 + idx*TypeDrawin+ TypeDrawinNormStep] = mat4D.yx*tp1 + mat4D.yy*tp2 + mat4D.yz*tp3 + mat4D.yo;
                NormVertexTab[lndex + 5 + idx*TypeDrawin+ TypeDrawinNormStep] = mat4D.zx*tp1 + mat4D.zy*tp2 + mat4D.zz*tp3 + mat4D.zo;
            }
            lndex += TypeDrawin;
        }
}

//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::project_4D_to_3D(int idx)
{
    double c4;
    int I = 0;
    for (int i=0; i < nb_ligne; ++i)
        for (int j=0; j < nb_colone  ; ++j)
        {
            c4 = 1/(ExtraDimension[i*nb_ligne + j + idx] - 2);
            NormVertexTab[I + 3 + idx*TypeDrawin + TypeDrawinNormStep] *= c4;
            NormVertexTab[I + 4 + idx*TypeDrawin + TypeDrawinNormStep] *= c4;
            NormVertexTab[I + 5 + idx*TypeDrawin + TypeDrawinNormStep] *= c4;
            I += TypeDrawin;
        }
}

//+++++++++++++++++++++++++++++++++++++++++
void ParMasterThread::AllocateParsersForMasterThread()
{
    if(!ParsersAllocated)
    {
        myParserX = new FunctionParser[NbComponent];
        myParserY = new FunctionParser[NbComponent];
        myParserZ = new FunctionParser[NbComponent];
        myParserW = new FunctionParser[NbComponent];
        Fct = new FunctionParser[NbDefinedFunctions];
        RgbtParser = new FunctionParser[NbTextures];
        VRgbtParser = new FunctionParser[NbTextures];
        GradientParser = new FunctionParser;
        NoiseParser = new FunctionParser;
        NoiseShapeParser = new FunctionParser;
        ParsersAllocated = true;
    }
}

//+++++++++++++++++++++++++++++++++++++++++
void ParWorkerThread::AllocateParsersForWorkerThread(int nbcomp)
{
    if(!ParsersAllocated)
    {
        myParserX = new FunctionParser[nbcomp];
        myParserY = new FunctionParser[nbcomp];
        myParserZ = new FunctionParser[nbcomp];
        myParserW = new FunctionParser[nbcomp];
        Fct = new FunctionParser[NbDefinedFunctions];
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
        delete[] Fct;
        delete[] RgbtParser;
        delete[] VRgbtParser;
        delete GradientParser;
        delete NoiseParser;
        delete NoiseShapeParser;
        ParsersAllocated = false;
    }
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

    for(int i=0; i<NbComponent; i++)
    {
        myParserX[i].AddConstant("pi", PI);
        myParserY[i].AddConstant("pi", PI);
        myParserZ[i].AddConstant("pi", PI);
        myParserW[i].AddConstant("pi", PI);
        myParserCND[i].AddConstant("pi", PI);
        myParserX[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserX[i].AddFunction("NoiseP",TurbulencePerlin2, 6);
        myParserY[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserY[i].AddFunction("NoiseP",TurbulencePerlin2, 6);
        myParserZ[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserZ[i].AddFunction("NoiseP",TurbulencePerlin2, 6);
        myParserW[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserW[i].AddFunction("NoiseP",TurbulencePerlin2, 6);
        myParserCND[i].AddFunction("NoiseW",TurbulenceWorley2, 6);
        myParserCND[i].AddFunction("NoiseP",TurbulencePerlin2, 6);
    }
    for(int i=0; i<NbTextures; i++)
    {
        RgbtParser[i].AddConstant("pi", PI);
        VRgbtParser[i].AddConstant("pi", PI);
    }
    for(int i=0; i<NbDefinedFunctions; i++)
    {
        Fct[i].AddConstant("pi", PI);
    }
}

ErrorMessage  Par3D::ParsePar()
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

    (Const != "") ? Nb_constants = HowManyVariables(Const, 1) : Nb_constants =0;
    InitMasterParsers();
    for(int j=0; j<Nb_constants; j++)
    {
        if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u")) >= 0)
        {
            stdError.strError = Consts[j];
            stdError.strOrigine = ConstNames[j];
            return stdError;
        }
        Cstparser.AddConstant(ConstNames[j], Cstparser.Eval(vals));
    }

    if(Funct != "")
    {
        Nb_functs = HowManyVariables(Funct, 2);

        for(int i=0; i<Nb_functs; i++)
        {
            for(int j=0; j<Nb_constants; j++)
            {
                if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u")) >= 0)
                {
                    stdError.strError = Consts[j];
                    stdError.strOrigine = ConstNames[j];
                    return stdError;
                }
                Fct[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
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
                Fct[i].AddFunction(FunctNames[j], Fct[j]);
            if ((stdError.iErrorIndex = Fct[i].Parse(Functs[i],"u,v,t")) >= 0)
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


    //Colors
    if(Rgbt!= "")
    {
        Nb_rgbts = HowManyVariables(Rgbt, 3);

        for(int i=0; i<Nb_rgbts; i++)
        {
            for(int j=0; j<Nb_constants; j++)
            {
                if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u")) >= 0)
                {
                    stdError.strError = Consts[j];
                    stdError.strOrigine = ConstNames[j];
                    return stdError;
                }
                RgbtParser[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            }
        }
    }
    else
    {
        Nb_rgbts =0;
    }


    //Texture:
    if(VRgbt != "")
    {
        Nb_vrgbts = HowManyVariables(VRgbt, 4);
        for(int j=0; j<Nb_constants; j++)
        {
            if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u")) >= 0)
            {
                stdError.strError = Consts[j];
                stdError.strOrigine = ConstNames[j];
                return stdError;
            }
            GradientParser->AddConstant(ConstNames[j], Cstparser.Eval(vals));
        }

        for(int i=0; i<Nb_vrgbts; i++)
        {
            for(int j=0; j<Nb_constants; j++)
            {
                if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u")) >= 0)
                {
                    stdError.strError = Consts[j];
                    stdError.strOrigine = ConstNames[j];
                    return stdError;
                }
                VRgbtParser[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            }
        }
    }
    else
    {
        Nb_vrgbts =0;
    }

    if(Varu != "")
    {
        Nb_newvariables = HowManyVariables(Varu, 0);

        for(int i=0; i<Nb_newvariables; i++)
        {
            for(int j=0; j<Nb_constants; j++)
            {
                if ((stdError.iErrorIndex =Cstparser.Parse(Consts[j],"u")) >= 0)
                {
                    stdError.strError = Consts[j];
                    stdError.strOrigine = ConstNames[j];
                    return stdError;
                }
                Var[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
                Var[i].AddConstant("pi", PI);
            }

            //Add predefined constatnts:
            for(int k=0; k<Nb_Sliders; k++)
            {
                Var[i].AddConstant(SliderNames[k], SliderValues[k]);
            }
        }

        for(int i=0; i<Nb_newvariables; i++)
        {
            if ((stdError.iErrorIndex =Var[i].Parse(Varus[i],"u,tm")) >= 0)
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

    Nb_paramfunctions = HowManyParamSurface(expression_X, 0);
    HowManyParamSurface(expression_Y, 1);
    HowManyParamSurface(expression_Z, 2);
    HowManyParamSurface(inf_u, 3);
    HowManyParamSurface(sup_u, 4);
    HowManyParamSurface(inf_v, 5);
    HowManyParamSurface(sup_v, 6);
    if(param4D == 1)
        HowManyParamSurface(expression_W, 7);
    if(expression_CND != "")
    {
        ParConditionRequired = 1;
        HowManyParamSurface(expression_CND, 8);
    }
    else
        ParConditionRequired = -1;


    //Add defined constantes:
    for(int i=0; i<Nb_paramfunctions+1; i++)
    {
        for(int j=0; j<Nb_constants; j++)
        {
            if ((stdError.iErrorIndex =Cstparser.Parse(Consts[j],"u")) >= 0)
            {
                stdError.strError = Consts[j];
                stdError.strOrigine = ConstNames[j];
                return stdError;
            }

            if(expression_CND != "")
                myParserCND[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserUmax[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserUmin[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserVmin[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserVmax[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserX[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserY[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserZ[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserW[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
        }


        //Add predefined constatnts:
        for(int k=0; k<Nb_Sliders; k++)
        {
            if(expression_CND != "")
                myParserCND[i].AddConstant(SliderNames[k], SliderValues[k]);
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
    if(Rgbt != "")
        for(int i=0; i<4; i++)
            for(int j=0; j<Nb_functs; j++)
                RgbtParser[i].AddFunction(FunctNames[j], Fct[j]);

    // Add defined functions :
    if(VRgbt != "")
    {
        for(int j=0; j<Nb_functs; j++)
            GradientParser->AddFunction(FunctNames[j], Fct[j]);

        for(int i=0; i<4; i++)
            for(int j=0; j<Nb_functs; j++)
                VRgbtParser[i].AddFunction(FunctNames[j], Fct[j]);
    }


    // Add defined functions :
    for(int i=0; i<Nb_paramfunctions+1; i++)
    {
        for(int j=0; j<Nb_functs; j++)
        {
            myParserX[i].AddFunction(FunctNames[j], Fct[j]);
            myParserY[i].AddFunction(FunctNames[j], Fct[j]);
            myParserZ[i].AddFunction(FunctNames[j], Fct[j]);
            myParserW[i].AddFunction(FunctNames[j], Fct[j]);
            if(expression_CND != "")
                myParserCND[i].AddFunction(FunctNames[j], Fct[j]);
        }
    }


    // Parse
    if(Rgbt!= "")
        for(int i=0; i<Nb_rgbts; i++)
            if ((stdError.iErrorIndex = RgbtParser[i].Parse(Rgbts[i],"x,y,z,u,v,i,j,index,grid")) >= 0)
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

    if(NoiseShape != "")
        if ((stdError.iErrorIndex = NoiseShapeParser->Parse(NoiseShape,"x,y,z,t")) >= 0)
        {
            stdError.strError = NoiseShape;
            stdError.strOrigine = NoiseShape;
            return stdError;
        }

    for(int index=0; index< Nb_paramfunctions + 1; index++)
    {
        if ((stdError.iErrorIndex = myParserUmin[index].Parse(ParamStructs[index].umin, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].umin;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }
        u_inf[index] = myParserUmin[index].Eval(vals);

        if ((stdError.iErrorIndex = myParserUmax[index].Parse(ParamStructs[index].umax, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].umax;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }
        u_sup[index] = myParserUmax[index].Eval(vals);
        dif_u[index] = u_sup[index] - u_inf[index];

        if ((stdError.iErrorIndex = myParserVmin[index].Parse(ParamStructs[index].vmin, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].vmin;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }
        v_inf[index] = myParserVmin[index].Eval(vals);

        if ((stdError.iErrorIndex = myParserVmax[index].Parse(ParamStructs[index].vmax, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].vmax;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }
        v_sup[index] = myParserVmax[index].Eval(vals);
        dif_v[index] = v_sup[index] - v_inf[index];

        if ((stdError.iErrorIndex = myParserX[index].Parse(ParamStructs[index].fx, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].fx;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }

        if ((stdError.iErrorIndex = myParserY[index].Parse(ParamStructs[index].fy, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].fy;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }

        if ((stdError.iErrorIndex = myParserZ[index].Parse(ParamStructs[index].fz, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].fz;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }

        if(param4D == 1)
            if ((stdError.iErrorIndex = myParserW[index].Parse(ParamStructs[index].fw, "u,v,t")) >= 0)
            {
                stdError.strError = ParamStructs[index].fw;
                stdError.strOrigine = ParamStructs[index].index;
                return stdError;
            }

        if(expression_CND != "")
            if ((stdError.iErrorIndex = myParserCND[index].Parse(ParamStructs[index].cnd, "x,y,z,t")) >= 0)
            {
                stdError.strError = ParamStructs[index].cnd;
                stdError.strOrigine = ParamStructs[index].index;
                return stdError;
            }
    }
    return stdError;
}

ErrorMessage  Par3D::parse_expression2()
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    ErrorMessage NodError;

    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
    {
        //Add defined constantes:
        for(int i=0; i<masterthread->Nb_paramfunctions+1; i++)
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

    //Functions:
            for(int ij=0; ij<masterthread->Nb_functs; ij++)
            {
                workerthreads[nbthreads].Fct[ij].AddConstant("pi", PI);
            }

            for(int ii=0; ii<masterthread->Nb_functs; ii++)
            {
                for(int jj=0; jj<masterthread->Nb_constants; jj++)
                {
                    if ((masterthread->stdError.iErrorIndex = masterthread->Cstparser.Parse(masterthread->Consts[jj],"u")) >= 0)
                    {
                        masterthread->stdError.strError = masterthread->Consts[jj];
                        masterthread->stdError.strOrigine = masterthread->ConstNames[jj];
                        return masterthread->stdError;
                    }
                    workerthreads[nbthreads].Fct[ii].AddConstant(masterthread->ConstNames[jj], masterthread->Cstparser.Eval(vals));
                }

                //Add predefined constatnts:
                for(int kk=0; kk<masterthread->Nb_Sliders; kk++)
                {
                    workerthreads[nbthreads].Fct[ii].AddConstant(masterthread->SliderNames[kk], masterthread->SliderValues[kk]);
                }
            }

            for(int ii=0; ii<masterthread->Nb_functs; ii++)
            {
                for(int jj=0; jj<ii; jj++)
                    workerthreads[nbthreads].Fct[ii].AddFunction(masterthread->FunctNames[jj], workerthreads[nbthreads].Fct[jj]);
                if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].Fct[ii].Parse(masterthread->Functs[ii],"u,v,t")) >= 0)
                {
                    masterthread->stdError.strError = masterthread->Functs[ii];
                    masterthread->stdError.strOrigine = masterthread->FunctNames[ii];
                    return masterthread->stdError;
                }
            }

        for(int j=0; j<masterthread->Nb_constants; j++)
        {

            if ((masterthread->stdError.iErrorIndex =masterthread->Cstparser.Parse(masterthread->Consts[j],"u")) >= 0)
            {
                masterthread->stdError.strError = masterthread->Consts[j];
                masterthread->stdError.strOrigine = masterthread->ConstNames[j];
                return masterthread->stdError;
            }

            workerthreads[nbthreads].myParserX[i].AddConstant(masterthread->ConstNames[j], masterthread->Cstparser.Eval(vals));
            workerthreads[nbthreads].myParserY[i].AddConstant(masterthread->ConstNames[j], masterthread->Cstparser.Eval(vals));
            workerthreads[nbthreads].myParserZ[i].AddConstant(masterthread->ConstNames[j], masterthread->Cstparser.Eval(vals));
            workerthreads[nbthreads].myParserW[i].AddConstant(masterthread->ConstNames[j], masterthread->Cstparser.Eval(vals));
        }
        //Add predefined sliders constatnts:
        for(int k=0; k<masterthread->Nb_Sliders; k++)
        {
            workerthreads[nbthreads].myParserX[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
            workerthreads[nbthreads].myParserY[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
            workerthreads[nbthreads].myParserZ[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
            workerthreads[nbthreads].myParserW[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
        }
    }

    // Add defined functions :
    for(int i=0; i<masterthread->Nb_paramfunctions+1; i++)
    {
        for(int j=0; j<masterthread->Nb_functs; j++)
        {
            workerthreads[nbthreads].myParserX[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct[j]);
            workerthreads[nbthreads].myParserY[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct[j]);
            workerthreads[nbthreads].myParserZ[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct[j]);
            workerthreads[nbthreads].myParserW[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct[j]);
        }
    }

    for(int index=0; index< masterthread->Nb_paramfunctions + 1; index++)
    {
        if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserX[index].Parse(masterthread->ParamStructs[index].fx, "u,v,t")) >= 0)
        {
            masterthread->stdError.strError = masterthread->ParamStructs[index].fx;
            masterthread->stdError.strOrigine = masterthread->ParamStructs[index].index;
            return masterthread->stdError;
        }

        if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserY[index].Parse(masterthread->ParamStructs[index].fy, "u,v,t")) >= 0)
        {
            masterthread->stdError.strError = masterthread->ParamStructs[index].fy;
            masterthread->stdError.strOrigine = masterthread->ParamStructs[index].index;
            return masterthread->stdError;
        }

        if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserZ[index].Parse(masterthread->ParamStructs[index].fz, "u,v,t")) >= 0)
        {
            masterthread->stdError.strError = masterthread->ParamStructs[index].fz;
            masterthread->stdError.strOrigine = masterthread->ParamStructs[index].index;
            return masterthread->stdError;
        }

        if(param4D == 1)
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].myParserW[index].Parse(masterthread->ParamStructs[index].fw, "u,v,t")) >= 0)
            {
                masterthread->stdError.strError = masterthread->ParamStructs[index].fw;
                masterthread->stdError.strOrigine = masterthread->ParamStructs[index].index;
                return masterthread->stdError;
            }
        }
    }
    return NodError;
}

//+++++++++++++++++++++++++++++++++++++++++
void Par3D::WorkerThreadCopy(ParWorkerThread *WorkerThreadsTmp)
{
    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
    {
        WorkerThreadsTmp[nbthreads].nb_ligne = masterthread->nb_ligne;
        WorkerThreadsTmp[nbthreads].nb_colone = masterthread->nb_colone;
        WorkerThreadsTmp[nbthreads].MyIndex = nbthreads+1;
        WorkerThreadsTmp[nbthreads].param4D   = param4D;
        WorkerThreadsTmp[nbthreads].WorkerThreadsNumber = WorkerThreadsNumber;
    }
}

//+++++++++++++++++++++++++++++++++++++++++
void Par3D::MasterThreadCopy(ParMasterThread *MasterThreadsTmp)
{
        MasterThreadsTmp->expression_X   = masterthread->expression_X;
        MasterThreadsTmp->expression_Y   = masterthread->expression_Y;
        MasterThreadsTmp->expression_Z   = masterthread->expression_Z;
        MasterThreadsTmp->expression_W   = masterthread->expression_W;
        MasterThreadsTmp->expression_CND = masterthread->expression_CND;
        MasterThreadsTmp->inf_u  		 = masterthread->inf_u;
        MasterThreadsTmp->sup_u          = masterthread->sup_u;
        MasterThreadsTmp->inf_v          = masterthread->inf_v;
        MasterThreadsTmp->sup_v          = masterthread->sup_v;
        MasterThreadsTmp->Grid           = masterthread->Grid;
        MasterThreadsTmp->Funct          = masterthread->Funct;
        MasterThreadsTmp->Varu           = masterthread->Varu;
        MasterThreadsTmp->Const          = masterthread->Const;
        MasterThreadsTmp->Rgbt           = masterthread->Rgbt;
        MasterThreadsTmp->VRgbt          = masterthread->VRgbt;

        MasterThreadsTmp->nb_ligne       = nb_ligne;
        MasterThreadsTmp->nb_colone      = nb_colone;
        MasterThreadsTmp->MyIndex        = 0;
        MasterThreadsTmp->param4D        = param4D;
        MasterThreadsTmp->WorkerThreadsNumber = WorkerThreadsNumber;
}

//+++++++++++++++++++++++++++++++++++++++++
ErrorMessage Par3D::ThreadParsersCopy()
{
    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
    {
        for(int i=0; i< masterthread->Nb_paramfunctions+1; i++)
        {
            workerthreads[nbthreads].dif_u[i] = masterthread->dif_u[i];
            workerthreads[nbthreads].dif_v[i] = masterthread->dif_v[i];
            workerthreads[nbthreads].u_inf[i] = masterthread->u_inf[i];
            workerthreads[nbthreads].v_inf[i] = masterthread->v_inf[i];
            workerthreads[nbthreads].param4D  = masterthread->param4D;
        }
    }

    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
        workerthreads[nbthreads].DeleteWorkerParsers();

    for(int nbthreads=0; nbthreads<WorkerThreadsNumber-1; nbthreads++)
        workerthreads[nbthreads].AllocateParsersForWorkerThread(masterthread->Nb_paramfunctions+1);

    return(parse_expression2());
}

//+++++++++++++++++++++++++++++++++++++++++
int ParMasterThread::HowManyVariables(std::string NewVariables, int type)
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

//+++++++++++++++++++++++++++++++++++++++++
int ParMasterThread::HowManyParamSurface(std::string ParamFct, int type)
{
    std::string tmp, tmp2;
    int position =0, jpos;
    int Nb_paramfunction =0;

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
        if((position = ParamFct.find(";")) >0   )
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
            tmp2 = ParamFct.substr(position+1, jpos=ParamFct.length()-1);
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
    return Nb_paramfunction;
}

//+++++++++++++++++++++++++++++++++++++++++++
void Par3D::BorderCalculation(int NewPosition)
{
    int k=0;
    for(int i=0; i<nb_ligne - coupure_ligne-2; i++)
        for(int j=0; j<nb_colone - coupure_col -2; j++)
        {
            if(VerifCND[i*(nb_colone)+j] != VerifCND[i*(nb_colone)+j+1])
            {
                Border[k + 0] = (NormVertexTab[(i*(nb_colone)+j)*TypeDrawin+3+NewPosition+ TypeDrawinNormStep] + NormVertexTab[(i*(nb_colone)+j+1)*TypeDrawin+3+NewPosition+ TypeDrawinNormStep])/2;
                Border[k + 1] = (NormVertexTab[(i*(nb_colone)+j)*TypeDrawin+4+NewPosition+ TypeDrawinNormStep] + NormVertexTab[(i*(nb_colone)+j+1)*TypeDrawin+4+NewPosition+ TypeDrawinNormStep])/2;
                Border[k + 2] = (NormVertexTab[(i*(nb_colone)+j)*TypeDrawin+5+NewPosition+ TypeDrawinNormStep] + NormVertexTab[(i*(nb_colone)+j+1)*TypeDrawin+5+NewPosition+ TypeDrawinNormStep])/2;
                k += 3;
            }

            if(VerifCND[i*(nb_colone)+j] != VerifCND[(i+1)*(nb_colone)+j])
            {
                Border[k + 0] = (NormVertexTab[(i*(nb_colone)+j)*TypeDrawin+3+NewPosition+ TypeDrawinNormStep] + NormVertexTab[((i+1)*(nb_colone)+j)*TypeDrawin+3+NewPosition+ TypeDrawinNormStep])/2;
                Border[k + 1] = (NormVertexTab[(i*(nb_colone)+j)*TypeDrawin+4+NewPosition+ TypeDrawinNormStep] + NormVertexTab[((i+1)*(nb_colone)+j)*TypeDrawin+4+NewPosition+ TypeDrawinNormStep])/2;
                Border[k + 2] = (NormVertexTab[(i*(nb_colone)+j)*TypeDrawin+5+NewPosition+ TypeDrawinNormStep] + NormVertexTab[((i+1)*(nb_colone)+j)*TypeDrawin+5+NewPosition+ TypeDrawinNormStep])/2;
                k += 3;
            }
        }
}



///+++++++++++++++++++++++++++++++++++++++++
void Par3D::CalculateNoiseShapePoints(int NewPosition)
{
    double tmp, val[4];
    int I =0;
    val[3] = masterthread->stepMorph;
    masterthread->NoiseShape = "NoiseW(x,y,z,1,2,0)";
    masterthread->NoiseShapeParser->Parse(masterthread->NoiseShape, "x,y,z,t");
    if(masterthread->NoiseShape != "")
        for(int j=0; j < nb_ligne   ; j++)
            for(int i= 0; i < nb_colone; i++)
            {
                val[0]= NormVertexTab[I  + 3 + TypeDrawinNormStep +NewPosition ];
                val[1]= NormVertexTab[I  + 4 + TypeDrawinNormStep +NewPosition ];
                val[2]= NormVertexTab[I  + 5 + TypeDrawinNormStep +NewPosition ];
                tmp  = masterthread->NoiseShapeParser->Eval(val);
                NormVertexTab[I + 3 + TypeDrawinNormStep +NewPosition ] *= tmp;
                NormVertexTab[I + 4 + TypeDrawinNormStep +NewPosition ] *= tmp;
                NormVertexTab[I + 5 + TypeDrawinNormStep +NewPosition ] *= tmp;
                I += TypeDrawin;
            }
}

///+++++++++++++++++++++++++++++++++++++++++
void Par3D::CalculateColorsPoints(struct ComponentInfos *components)
{
    int Jprime;
    double tmp, ValCol[100], val[9];
    val[3] = masterthread->stepMorph;

    static int recalculate = 1;

    if((masterthread->activeMorph == 1) &&   (recalculate !=1))
    {
        return;
    }
    if(masterthread->activeMorph == 1)
        recalculate = -1;
    else
        recalculate = 1;

    if(components->ThereisRGBA == true &&  components->NoiseParam.NoiseType == 0)
    {
        for(int i=0; i<masterthread->Nb_vrgbts && i<100; i++)
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
            for (int j=0; j < masterthread->Nb_vrgbts && j < 100; j+=5)
                if(tmp <= ValCol[j])
                {
                    NormVertexTab[i*TypeDrawin    ] = ValCol[j+1];
                    NormVertexTab[i*TypeDrawin+1] = ValCol[j+2];
                    NormVertexTab[i*TypeDrawin+2] = ValCol[j+3];
                    NormVertexTab[i*TypeDrawin+3] = ValCol[j+4];
                    j = 100;
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

            val[7] = (double)i;
            val[8] = (double)(nb_colone);
            Jprime = (i)/(nb_ligne);
            val[6] = (double)Jprime;
            val[4] = val[6]/(double)(nb_ligne) ;
            val[4] = val[4] * masterthread->dif_v[0]  + masterthread->v_inf[0];

            Jprime = (i) %  (nb_colone);
            val[5] =  (double)Jprime;
            val[3] = val[5]/(double)(nb_colone) ;
            val[3] = val[3] * masterthread->dif_u[0]  + masterthread->u_inf[0];

            if(masterthread->Noise != "")
                tmp  = masterthread->NoiseParser->Eval(val);
            else
                tmp =1.0;

            val[0]= tmp*NormVertexTab[i*TypeDrawin  +3+TypeDrawinNormStep ];
            val[1]= tmp*NormVertexTab[i*TypeDrawin  +4+TypeDrawinNormStep ];
            val[2]= tmp*NormVertexTab[i*TypeDrawin  +5+TypeDrawinNormStep ];
            val[3]*= tmp;
            val[4]*= tmp;

            NormVertexTab[i*TypeDrawin  ] = masterthread->RgbtParser[0].Eval(val);
            NormVertexTab[i*TypeDrawin+1] = masterthread->RgbtParser[1].Eval(val);
            NormVertexTab[i*TypeDrawin+2] = masterthread->RgbtParser[2].Eval(val);
            NormVertexTab[i*TypeDrawin+3] = masterthread->RgbtParser[3].Eval(val);
        }
    }
}




/*
///+++++++++++++++++++++++++++++++++++++++++
void Par3D::CalculateColorsPoints(struct ComponentInfos *components)
{
    double tmp, ValCol[100], val[4];
    ImprovedNoise* PerlinNoise = new ImprovedNoise(4., 4., 4.);
    val[3] = stepMorph;
    if(VRgbt != "" && (Nb_vrgbts %5)==0 )
    {
        components->ThereisRGBA = true;
        for(int i=0; i<Nb_vrgbts && i<100; i++)
        {
            ValCol[i] = VRgbtParser[i].Eval(val);
        }

        for(int i= 0; i < NbVertexTmp; i++)
        {
            if(Noise != "")
                tmp = PerlinNoise->Marble(NormVertexTab[i*TypeDrawin  +3 + TypeDrawinNormStep ],
                        NormVertexTab[i*TypeDrawin  +4 + TypeDrawinNormStep ],
                        NormVertexTab[i*TypeDrawin  +5 + TypeDrawinNormStep ], 4);
            else
                tmp =1.0;

            val[0]= tmp*NormVertexTab[i*TypeDrawin  +3 + TypeDrawinNormStep ];
            val[1]= tmp*NormVertexTab[i*TypeDrawin  +4 + TypeDrawinNormStep ];
            val[2]= tmp*NormVertexTab[i*TypeDrawin  +5 + TypeDrawinNormStep ];
            tmp  = GradientParser->Eval(val);

            int c= (int)tmp;
            tmp = std::abs(tmp - (double)c);
            for (int j=0; j < Nb_vrgbts && j < 100; j+=5)
                if(tmp <= ValCol[j])
                {
                    NormVertexTab[i*TypeDrawin    ] = ValCol[j+1];
                    NormVertexTab[i*TypeDrawin+1] = ValCol[j+2];
                    NormVertexTab[i*TypeDrawin+2] = ValCol[j+3];
                    NormVertexTab[i*TypeDrawin+3] = ValCol[j+4];
                    j = 100;
                }
        }
    }
    else if(Nb_rgbts >= 4)
    {
        for(int i= 0; i < NbVertexTmp; i++)
        {
            if(Noise != "")
                tmp = PerlinNoise->Marble(NormVertexTab[i*TypeDrawin  +3 + TypeDrawinNormStep ],
                        NormVertexTab[i*TypeDrawin  +4 + TypeDrawinNormStep ],
                        NormVertexTab[i*TypeDrawin  +5 + TypeDrawinNormStep ], 4);
            else
                tmp =1.0;

            val[0]= tmp*NormVertexTab[i*TypeDrawin  +3+TypeDrawinNormStep ];
            val[1]= tmp*NormVertexTab[i*TypeDrawin  +4+TypeDrawinNormStep ];
            val[2]= tmp*NormVertexTab[i*TypeDrawin  +5+TypeDrawinNormStep ];

            NormVertexTab[i*TypeDrawin    ] = RgbtParser[0].Eval(val);
            NormVertexTab[i*TypeDrawin+1] = RgbtParser[1].Eval(val);
            NormVertexTab[i*TypeDrawin+2] = RgbtParser[2].Eval(val);
            NormVertexTab[i*TypeDrawin+3] = RgbtParser[3].Eval(val);
        }
        components->ThereisRGBA = true;
    }
    else
        components->ThereisRGBA = false;
}
*/

///+++++++++++++++++++++++++++++++++++++++++
void Par3D::CNDCalculation(int NbTriangleIsoSurfaceTmp, struct ComponentInfos *components)
{
    double vals[4];
    vals[3] = masterthread->stepMorph;

    if (masterthread->ParConditionRequired == 1)
    {
        for(int i= 0; i < NbVertexTmp; i++)
        {
            vals[0] = NormVertexTab[i*TypeDrawin+3+ TypeDrawinNormStep];
            vals[1] = NormVertexTab[i*TypeDrawin+4+ TypeDrawinNormStep];
            vals[2] = NormVertexTab[i*TypeDrawin+5+ TypeDrawinNormStep];
            WichPointVerifyCond[i] = (masterthread->myParserCND[0].Eval(vals) == 1);
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
            if(TypeTriangle >=0 && TypeTriangle <= 5)
            {
                /// Bprime
                Bprime[0] = NormVertexTab[3+TypeDrawin*Aindex    + TypeDrawinNormStep];
                Bprime[1] = NormVertexTab[3+TypeDrawin*Aindex+1+ TypeDrawinNormStep];
                Bprime[2] = NormVertexTab[3+TypeDrawin*Aindex+2+ TypeDrawinNormStep];
                Bprime[3] = masterthread->stepMorph;

                DiffX = (NormVertexTab[3+TypeDrawin*Bindex  + TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex  + TypeDrawinNormStep])/20;
                DiffY = (NormVertexTab[3+TypeDrawin*Bindex+1+ TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex+1+ TypeDrawinNormStep])/20;
                DiffZ = (NormVertexTab[3+TypeDrawin*Bindex+2+ TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex+2+ TypeDrawinNormStep])/20;
                Alfa = 0;
                if(TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4)
                {
                    while(masterthread->myParserCND[0].Eval(Bprime) == 1 && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!(masterthread->myParserCND[0].Eval(Bprime) == 1) && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }

                /// Cprime
                Cprime[0] = NormVertexTab[3+TypeDrawin*Aindex    + TypeDrawinNormStep];
                Cprime[1] = NormVertexTab[3+TypeDrawin*Aindex+1+ TypeDrawinNormStep];
                Cprime[2] = NormVertexTab[3+TypeDrawin*Aindex+2+ TypeDrawinNormStep];
                Cprime[3] = masterthread->stepMorph;

                DiffX = (NormVertexTab[3+TypeDrawin*Cindex    + TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex     + TypeDrawinNormStep])/20;
                DiffY = (NormVertexTab[3+TypeDrawin*Cindex+1+ TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex+1+ TypeDrawinNormStep])/20;
                DiffZ = (NormVertexTab[3+TypeDrawin*Cindex+2+ TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex+2+ TypeDrawinNormStep])/20;
                Alfa = 0;
                if(TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4)
                {
                    while(masterthread->myParserCND[0].Eval(Cprime) == 1 && (Alfa < 20))
                    {
                        Cprime[0] += DiffX;
                        Cprime[1] += DiffY;
                        Cprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!(masterthread->myParserCND[0].Eval(Cprime) == 1) && (Alfa < 20))
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

                NormVertexTab[TypeDrawin*NbVertexTmp      + TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Bindex      + TypeDrawinNormStep];
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
                NewIndexPolyTab[3*k       ] =  IndexPolyTab[3*i      ];
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

        for(int fctnb= 0; fctnb< masterthread->Nb_paramfunctions+1; fctnb++)
        {
            if(components != NULL)
            {
                components->Parametricpositions[2*fctnb + 1] = NbTriangleIsoSurfaceTmp;
            }
        }

        components->ThereisCND = true;
    }
    else
    {
        components->ThereisCND = false;
    }
}

//++++++++++++++++++++++++++++++++++++
void Par3D::BuildPar()
{
    ParamBuild(
                    LocalScene->ArrayNorVer_localPt,
                    LocalScene->ArrayNorVerExtra_localPt,
                    LocalScene->PolyIndices_localPt,
                    &LocalScene->PolyNumber,
                    &(LocalScene->VertxNumber),
                    0,
                    &(LocalScene->componentsinfos),
                    LocalScene->Typetriangles,
                    LocalScene->WichPointVerifyCond,
                    LocalScene->PolyIndices_localPtMin,
                    &(LocalScene->NbPolygnNbVertexPtMin)
                );
}

//++++++++++++++++++++++++++++++++++++
void Par3D::run()
{
  BuildPar();
}

//++++++++++++++++++++++++++++++++++++
ParWorkerThread::~ParWorkerThread()
{

}

//++++++++++++++++++++++++++++++++++++
void Par3D::UpdateThredsNumber(int NewThreadsNumber)
{
    int tmp= WorkerThreadsNumber;
    WorkerThreadsNumber = NewThreadsNumber;
    //Create new workerthreads set:
    ParMasterThread *masterthreadtmp  = new ParMasterThread;
    ParWorkerThread *workerthreadstmp = new ParWorkerThread[WorkerThreadsNumber-1];
    masterthreadtmp->AllocateParsersForThread();

    MasterThreadCopy(masterthreadtmp);
    WorkerThreadCopy(workerthreadstmp);
    //Free old memory:
    masterthread->DeleteMasterParsers();
    delete masterthread;

    for(int i=0; i<tmp-1; i++)
    {
        workerthreads[i].DeleteWorkerParsers();
    }
    delete[] workerthreads;

    //Assigne newly allocated memory
    workerthreads = workerthreadstmp;
    masterthread  = masterthreadtmp;
}

///+++++++++++++++++++++++++++++++++++++++++
void Par3D::stopcalculations(bool calculation)
{
    StopCalculations = calculation;
    for(int nbthreads=0; nbthreads< WorkerThreadsNumber-1; nbthreads++)
        workerthreads[nbthreads].StopCalculations = StopCalculations;
    masterthread->StopCalculations = StopCalculations;
}

//+++++++++++++++++++++++++++++++++++++++++++
void  ParWorkerThread::calcul_objet(int cmp)
{
    double vals[] = {0,0,0};
    double iprime, jprime;
    int NewPosition =  cmp*TypeDrawin*(nb_ligne)*(nb_colone);

    if(activeMorph == 1)
        stepMorph += pace;
    vals[2]          = stepMorph;

    int tmp = nb_ligne/WorkerThreadsNumber;
    iStart   = MyIndex*tmp;
    if(MyIndex == (WorkerThreadsNumber-1))
        iFinish = nb_ligne;
    else
        iFinish = (MyIndex+1)*tmp;

    int l=TypeDrawin*iStart*nb_colone;

    for(int j=iStart; j < iFinish   ; j++)
    {
        jprime = (double)j/(double)(nb_ligne -1 ) ;
        jprime = jprime * dif_u[cmp]  + u_inf[cmp] ;
        for (int i=0; i < nb_colone   ; i++)
        {
            iprime = (double)i/(double)(nb_colone-1 ) ;
            iprime = iprime * dif_v[cmp]  + v_inf[cmp] ;
            vals[0]=jprime;
            vals[1]=iprime;

            if(StopCalculations)
                return;
            NormVertexTab[l+3+NewPosition+ TypeDrawinNormStep] = myParserX[cmp].Eval(vals);
            NormVertexTab[l+4+NewPosition+ TypeDrawinNormStep] = myParserY[cmp].Eval(vals);
            NormVertexTab[l+5+NewPosition+ TypeDrawinNormStep] = myParserZ[cmp].Eval(vals);
            l+=TypeDrawin;
            if(param4D == 1)
                ExtraDimension[j*nb_colone + i + (int)(NewPosition/TypeDrawin)] = myParserW[cmp].Eval(vals);
            else
                ExtraDimension[j*nb_colone + i + (int)(NewPosition/TypeDrawin)] = 1;
        }
    }
}

//++++++++++++++++++++++++++++++++++++
void  Par3D::ParamBuild(
    float *NormVertexTabPt,
    float *ExtraDimensionPt,
    unsigned int *IndexPolyTabPt,
    unsigned int *PolyNumber,
    unsigned int *VertxNumber,
    int  IsoPos,
    ComponentInfos *components,
    int *TriangleListeCND,
    bool *typeCND,
    unsigned int *IndexPolyTabMinPt,
    unsigned  int *NbPolyMinPt
)
{
    int NbTriangleIsoSurfaceTmp;
    NbVertexTmp = NbTriangleIsoSurfaceTmp =  0;
    NbPolyMinimalTopology = 0;
    PreviousSizeMinimalTopology =0;

    NbVertex  = (nb_ligne)*(nb_colone);
    IndexPolyTab = IndexPolyTabPt;
    IndexPolyTabMin = IndexPolyTabMinPt;

    if(components != NULL)
        components->NbParametric = masterthread->Nb_paramfunctions+1;

    if(TriangleListeCND != NULL)
        TypeIsoSurfaceTriangleListeCND = TriangleListeCND;

    if(typeCND != NULL)
        WichPointVerifyCond = typeCND;

    stopcalculations(false);
    for(int fctnb= 0; fctnb< masterthread->Nb_paramfunctions+1; fctnb++)
    {
        masterthread->CurrentPar = fctnb;
        for(int nbthreads=0; nbthreads< WorkerThreadsNumber-1; nbthreads++)
            workerthreads[nbthreads].CurrentPar = fctnb;

        masterthread->start();
        for(int nbthreads=0; nbthreads< WorkerThreadsNumber-1; nbthreads++)
            workerthreads[nbthreads].start();

        masterthread->wait();
        for(int nbthreads=0; nbthreads< WorkerThreadsNumber-1; nbthreads++)
            workerthreads[nbthreads].wait();

        if(StopCalculations)
            return;
        if(param4D == 1)
        {
            Anim_Rot4D (fctnb*NbVertex);
        }
        calcul_Norm(fctnb*TypeDrawin*NbVertex);
        make_PolyIndexMin( fctnb,  IsoPos);  //Before
        make_PolyIndexTri( fctnb,  IsoPos);
        if(components != NULL)
        {
            components->Parametricpositions[2*fctnb  ]  = fctnb*6*(nb_ligne  - coupure_ligne -1)*(nb_colone - coupure_col -1)  /*+  IsoPos*/; //save the starting position of this component
            components->Parametricpositions[2*fctnb+1] = 2*(nb_ligne  - coupure_ligne -1)*(nb_colone - coupure_col -1); //save the number of Polygones of this component
        }
    }

    // Save Number of Polys and vertex :
    NbVertexTmp                 = (masterthread->Nb_paramfunctions+1)*(nb_ligne)*(nb_colone);
    NbTriangleIsoSurfaceTmp     = (masterthread->Nb_paramfunctions+1)*2*(nb_ligne  - coupure_ligne -1)*(nb_colone - coupure_col -1);
    NbPolyMinimalTopology       = (masterthread->Nb_paramfunctions+1)*(nb_ligne  - coupure_ligne -1)*(nb_colone - coupure_col -1);
    PreviousSizeMinimalTopology = 5*(masterthread->Nb_paramfunctions+1)*(nb_ligne  - coupure_ligne -1)*(nb_colone - coupure_col -1);

    //CND calculation for the triangles results:
    CNDCalculation(NbTriangleIsoSurfaceTmp, components);

    // Pigment, Texture and Noise :
    if(masterthread->VRgbt != "" && (masterthread->Nb_vrgbts %5)==0 )
    {
        components->ThereisRGBA = true;
        components->NoiseParam.NoiseType = 0; //Pigments
        components->NoiseParam.VRgbtParser = masterthread->VRgbtParser;
        components->NoiseParam.GradientParser = masterthread->GradientParser;
        components->NoiseParam.Nb_vrgbts = masterthread->Nb_vrgbts;
    }
    else if(masterthread->Nb_rgbts >= 4)
    {
        components->ThereisRGBA = true;
        components->NoiseParam.NoiseType = 1; //Texture
        components->NoiseParam.RgbtParser = masterthread->RgbtParser;
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

// 3) Nb Poly & Vertex :
    *PolyNumber      = 3*NbTriangleIsoSurfaceTmp;
    *VertxNumber     = NbVertexTmp;
    *NbPolyMinPt     = NbPolyMinimalTopology;

    memcpy(NormVertexTabPt, NormVertexTab, 10*NbVertexTmp*sizeof(float));
    memcpy(ExtraDimensionPt, ExtraDimension, NbVertexTmp*sizeof(float));
}

//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::make_PolyIndex(int NewPo, int IsoPos)
{
    int k=0;
    int NewPosition = NewPo * 4*(nb_ligne  - coupure_ligne -1)*(nb_colone- coupure_col -1);
    int nbVertex       = NewPo * (nb_ligne  - coupure_ligne)*(nb_colone- coupure_col);
    for (int i=0; i< nb_ligne - coupure_ligne -1; i++)
        for (int j=0; j< nb_colone - coupure_col -1; j++)
        {
            IndexPolyTab[k    +NewPosition] =  i*nb_colone + j+nbVertex + IsoPos;
            IndexPolyTab[k+1+NewPosition] = (i+1)*nb_colone + j +nbVertex + IsoPos;
            IndexPolyTab[k+2+NewPosition] = (i+1)*nb_colone + (j+1)+nbVertex + IsoPos;
            IndexPolyTab[k+3+NewPosition] = i*nb_colone + (j+1)+nbVertex + IsoPos;
            k+=4;
        }
}
//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::make_PolyIndexMin(int NewPo, int IsoPos)
{
    int k=0;
    int NewPosition = NewPo * 5*(nb_ligne  - coupure_ligne -1)*(nb_colone- coupure_col -1);
    int nbVertex       = NewPo * (nb_ligne  - coupure_ligne)*(nb_colone- coupure_col);
    for (int i=0; i< nb_ligne - coupure_ligne -1; i++)
        for (int j=0; j< nb_colone - coupure_col -1; j++)
        {
            IndexPolyTabMin[k    +NewPosition] =  4;
            IndexPolyTabMin[k+1+NewPosition] =  i*nb_colone + j+nbVertex + IsoPos;
            IndexPolyTabMin[k+2+NewPosition] = (i+1)*nb_colone + j +nbVertex + IsoPos;
            IndexPolyTabMin[k+3+NewPosition] = (i+1)*nb_colone + (j+1)+nbVertex + IsoPos;
            IndexPolyTabMin[k+4+NewPosition] = i*nb_colone + (j+1)+nbVertex + IsoPos;
            k+=5;
        }

    PreviousSizeMinimalTopology += 5*(nb_ligne  - coupure_ligne)*(nb_colone- coupure_col);
    NbPolyMinimalTopology += (nb_ligne  - coupure_ligne-1)*(nb_colone- coupure_col-1);
}
//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::make_PolyIndexTri(int NewPo, int IsoPos)
{
    int k=0;
    int NewPosition = NewPo * 6*(nb_ligne  - coupure_ligne -1)*(nb_colone- coupure_col -1);
    int nbVertex       = NewPo * (nb_ligne  - coupure_ligne)*(nb_colone- coupure_col);
    for (int i=0; i< nb_ligne - coupure_ligne -1; i++)
        for (int j=0; j< nb_colone - coupure_col -1; j++)
        {
            IndexPolyTab[k    +NewPosition] =  i*nb_colone + j+nbVertex + IsoPos;
            IndexPolyTab[k+1+NewPosition] = (i+1)*nb_colone + j +nbVertex + IsoPos;
            IndexPolyTab[k+2+NewPosition] = (i+1)*nb_colone + (j+1)+nbVertex + IsoPos;

            IndexPolyTab[k+3+NewPosition] = i*nb_colone + j+nbVertex + IsoPos;
            IndexPolyTab[k+4+NewPosition] = (i+1)*nb_colone + (j+1)+nbVertex + IsoPos;
            IndexPolyTab[k+5+NewPosition] = i*nb_colone + (j+1)+nbVertex + IsoPos;
            k+=6;
        }
}

//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::calcul_Norm(int NewPosition)
{
//calculate Normals
    int        i, j, deplacement = TypeDrawin*nb_colone;
    double caa, bab, cab, baa, ba, ca;

    for (i=0; i < nb_ligne -1  ; i++)
        for (j=0; j < nb_colone -1  ; j++)
        {
            caa = NormVertexTab[(i+1)*deplacement+j*TypeDrawin+4+NewPosition+ TypeDrawinNormStep] - NormVertexTab[i*deplacement +j*TypeDrawin+4+NewPosition+ TypeDrawinNormStep];
            bab = NormVertexTab[i*deplacement+(j+1)*TypeDrawin+5+NewPosition+ TypeDrawinNormStep] - NormVertexTab[i*deplacement +j*TypeDrawin+5+NewPosition+ TypeDrawinNormStep];
            cab = NormVertexTab[(i+1)*deplacement+j*TypeDrawin+5+NewPosition+ TypeDrawinNormStep] - NormVertexTab[i*deplacement +j*TypeDrawin+5+NewPosition+ TypeDrawinNormStep];
            baa = NormVertexTab[i*deplacement+(j+1)*TypeDrawin+4+NewPosition+ TypeDrawinNormStep] - NormVertexTab[i*deplacement +j*TypeDrawin+4+NewPosition+ TypeDrawinNormStep];
            ba   = NormVertexTab[i*deplacement+(j+1)*TypeDrawin+3+NewPosition+ TypeDrawinNormStep] - NormVertexTab[i*deplacement +j*TypeDrawin+3+NewPosition+ TypeDrawinNormStep];
            ca   = NormVertexTab[(i+1)*deplacement+j*TypeDrawin+3+NewPosition+ TypeDrawinNormStep] - NormVertexTab[i*deplacement +j*TypeDrawin+3+NewPosition+ TypeDrawinNormStep];

            NormVertexTab[i*deplacement +j*TypeDrawin     +NewPosition+ TypeDrawinNormStep] = caa*bab  - cab*baa;
            NormVertexTab[i*deplacement +j*TypeDrawin +1+NewPosition+ TypeDrawinNormStep] = cab*ba    - ca*bab;
            NormVertexTab[i*deplacement +j*TypeDrawin +2+NewPosition+ TypeDrawinNormStep] = ca*baa    - caa*ba;

            double b4 = (double)sqrt(
                            (NormVertexTab[i*deplacement +j*TypeDrawin  +NewPosition+ TypeDrawinNormStep]*NormVertexTab[i*deplacement +j*TypeDrawin      +NewPosition+ TypeDrawinNormStep]) +
                            (NormVertexTab[i*deplacement +j*TypeDrawin+1+NewPosition+ TypeDrawinNormStep]*NormVertexTab[i*deplacement +j*TypeDrawin+1+NewPosition+ TypeDrawinNormStep]) +
                            (NormVertexTab[i*deplacement +j*TypeDrawin+2+NewPosition+ TypeDrawinNormStep]*NormVertexTab[i*deplacement +j*TypeDrawin+2+NewPosition+ TypeDrawinNormStep]));

            if( b4 < 0.00000001)  b4 = 0.00000001;

//Normalise:
            NormVertexTab[i*deplacement +j*TypeDrawin    +NewPosition+ TypeDrawinNormStep]/=b4;
            NormVertexTab[i*deplacement +j*TypeDrawin+1+NewPosition+ TypeDrawinNormStep]/=b4;
            NormVertexTab[i*deplacement +j*TypeDrawin+2+NewPosition+ TypeDrawinNormStep]/=b4;
        }

    i = nb_ligne -1;
    for (j=0; j < nb_colone -1   ; j++)
    {
        NormVertexTab[i*deplacement +j*TypeDrawin    +NewPosition+ TypeDrawinNormStep] = NormVertexTab[(i-1)*deplacement +j*TypeDrawin    +NewPosition+ TypeDrawinNormStep];
        NormVertexTab[i*deplacement +j*TypeDrawin+1+NewPosition+ TypeDrawinNormStep] = NormVertexTab[(i-1)*deplacement +j*TypeDrawin+1+NewPosition+ TypeDrawinNormStep];
        NormVertexTab[i*deplacement +j*TypeDrawin+2+NewPosition+ TypeDrawinNormStep] = NormVertexTab[(i-1)*deplacement +j*TypeDrawin+2+NewPosition+ TypeDrawinNormStep];
    }

    j =nb_colone -1;
    for (i=0; i < nb_ligne -1  ; i++)
    {
        NormVertexTab[i*deplacement +j*TypeDrawin    +NewPosition+ TypeDrawinNormStep] = NormVertexTab[i*deplacement +(j-1)*TypeDrawin    +NewPosition+ TypeDrawinNormStep];
        NormVertexTab[i*deplacement +j*TypeDrawin+1+NewPosition+ TypeDrawinNormStep] = NormVertexTab[i*deplacement +(j-1)*TypeDrawin+1+NewPosition+ TypeDrawinNormStep];
        NormVertexTab[i*deplacement +j*TypeDrawin+2+NewPosition+ TypeDrawinNormStep] = NormVertexTab[i*deplacement +(j-1)*TypeDrawin+2+NewPosition+ TypeDrawinNormStep];
    }

    i = nb_ligne -1;
    j =nb_colone -1;
    NormVertexTab[i*deplacement +j*TypeDrawin  +NewPosition+ TypeDrawinNormStep]    = NormVertexTab[(i-1)*deplacement +(j-1)*TypeDrawin    +NewPosition+ TypeDrawinNormStep];
    NormVertexTab[i*deplacement +j*TypeDrawin+1+NewPosition+ TypeDrawinNormStep]  = NormVertexTab[(i-1)*deplacement +(j-1)*TypeDrawin+1+NewPosition+ TypeDrawinNormStep];
    NormVertexTab[i*deplacement +j*TypeDrawin+2+NewPosition+ TypeDrawinNormStep]  = NormVertexTab[(i-1)*deplacement +(j-1)*TypeDrawin+2+NewPosition+ TypeDrawinNormStep];
}
