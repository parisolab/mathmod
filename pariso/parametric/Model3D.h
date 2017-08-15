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

#include <map>
#include <vector>
#include <iostream>
#include <string.h>
#include <cmath>
#include "../objectparameters.h"
#include "ND/Matrix4D.h"

using std::string;

struct   ParStruct
{
    std::string fx;
    std::string fy;
    std::string fz;
    std::string fw;
    std::string cnd;
    std::string umin;
    std::string umax;
    std::string vmin;
    std::string vmax;
    std::string grid;
    int  index;
};

class ParWorkerThread : public QThread
{
public :
    ErrorMessage stdError;
    int nb_ligne, nb_colone;
    int coupure_col, nb_licol, coupure_ligne;

    FunctionParser * myParserX, * myParserY,* myParserZ, *myParserW, *Fct, *RgbtParser, *VRgbtParser, *GradientParser, *NoiseParser, *NoiseShapeParser;
    FunctionParser myParserCND[3*NbComponent],
                   myParserUmin[3*NbComponent], myParserUmax[3*NbComponent],
                   myParserVmin[3*NbComponent], myParserVmax[3*NbComponent],
                   Var[NbVariables], Cstparser;
    ParStruct ParamStructs[3*NbComponent];
    int Nb_paramfunctions, Nb_functs, Nb_rgbts, Nb_vrgbts, Nb_Sliders, activeMorph, Nb_newvariables, Nb_constants, ParConditionRequired;
    std::string  expression_X, expression_Y, expression_Z, expression_W, expression_CND, inf_u, sup_u, inf_v, sup_v,
        Varu, Const,  Rgbt, Grid;
    std::string VarName[NbVariables], Varus[NbVariables], ConstNames[NbConstantes], Consts[NbConstantes], Funct, FunctNames[NbDefinedFunctions], Functs[NbDefinedFunctions],
        RgbtNames[NbTextures], Rgbts[NbTextures], VRgbt, VRgbts[NbTextures], VRgbtNames[NbTextures],
        Gradient, Noise, NoiseShape, SliderNames[50];
    double  v_inf[3*NbComponent], v_sup[3*NbComponent],u_inf[3*NbComponent],u_sup[3*NbComponent],dif_v[3*NbComponent],dif_u[3*NbComponent];
    double SliderValues[5000];
    double stepMorph, pace;
    int iStart, iFinish, MyIndex, WorkerThreadsNumber;
    unsigned int NbPolygnNbVertex[2], nbBorderPts, param4D, CurrentPar;
    float Lacunarity, Gain;
    int Octaves;
    bool StopCalculations;

public :
    void ParCompute(int);
    void initialiser_parseur();
    void initparser();
    void calcul_objet(int component =0);
    int  HowManyParamSurface(std::string, int);
    int  HowManyVariables(std::string, int);
    ErrorMessage parse_expression();
    void allocateparser();
    void deleteparsers();
    void run() Q_DECL_OVERRIDE;
    ParWorkerThread();
    ~ParWorkerThread();
};


/** The representation of a 3D model */
class Par3D   : public QThread
{
public:
    ObjectProperties *LocalScene;
    ParWorkerThread *workerthreads;
    //float* NormVertexTab;
    //float* ExtraDimension;
    unsigned int *IndexPolyTab;
    unsigned int *IndexPolyTabMin;
    float *Border;
    bool *WichPointVerifyCond, StopCalculations;
    int *TypeIsoSurfaceTriangleListeCND;
    int VerifCND[1000000];
    int nb_ligne, nb_colone, NbVertex, WorkerThreadsNumber;
    int coupure_col, coupure_ligne;
    double MINX,MINY,MINZ,MINW,
           MAXX,MAXY,MAXZ,MAXW,
           DIFX,DIFY,DIFZ,DIFW,
           DIFMAXIMUM;
    Matrix4D mat4D, mat_rotation4D, mat_rotation_save4D,
             mat_homothetie4D, mat_translation4D, mat_inversetranslation4D;
    double tetaxy, tetaxz, tetayz, tetaxw, tetayw, tetazw;

    int tetaxy_ok, tetaxz_ok, tetayz_ok, tetaxw_ok, tetayw_ok, tetazw_ok, param4D;
    int   largeur_fenetre,hauteur_fenetre;
public:
    Par3D(int);
    ~Par3D();
    void rotation4();
    void calcul_points4(int idx=0);
    void Anim_Rot4D (int idx=0);
    void project_4D_to_3D(int idx=0);
    void Invert_boite_englobante4D(int idx=0);
    void boite_englobante4D(int index=0);
    void initialiser_parametres();
    void calcul_Norm(int i=0);
    void BorderCalculation(int i=0);
    void make_PolyIndex(int i=0, int  IsoPos=0);
    void make_PolyIndexTri(int i=0, int  IsoPos=0);
    void make_PolyIndexMin(int i=0, int  IsoPos=0);
    void CNDCalculation(int, struct ComponentInfos *);
    void CalculateColorsPoints(struct ComponentInfos *);
    void CalculateNoiseShapePoints(int);
    void ParamBuild(float * , float * ,unsigned int *, unsigned int *,
                    unsigned int *, int  IsoPos=0,
                    ComponentInfos *components = NULL,
                    int *TriangleListeCND = NULL,
                    bool *typeCND = NULL,
                    unsigned int *IndexPolyTabMinPt = NULL,
                    unsigned  int *NbPolyMinPt = NULL);
    void BuildPar();
    void UpdateThredsNumber(int);
    void stopcalculations(bool);
    void DeepThreadCopy(ParWorkerThread *);
    void ThreadParsersCopy(ParWorkerThread *);
    void run() Q_DECL_OVERRIDE;
};
