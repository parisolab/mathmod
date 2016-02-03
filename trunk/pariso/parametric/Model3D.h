/***************************************************************************
 *   Copyright (C) 2016 by Abderrahman Taha                                *
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
static const int gridscal =1000;

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
    int          index;
};

/** The representation of a 3D model */
class Par3D /*: public ObjectParameters*/
{
public:
    ErrorMessage stdError;
    float* NormVertexTab;
    float* ExtraDimension;
    unsigned int *IndexPolyTab;
    //unsigned int IndexPolyTab_2[30*000000];
    unsigned int *IndexPolyTabMin;
    float *Border;
    bool *WichPointVerifyCond;
    int *TypeIsoSurfaceTriangleListeCND;
    int VerifCND[1000000];

    int nb_ligne, nb_colone;
    int coupure_col, nb_licol, coupure_ligne;
    double MINX,MINY,MINZ,MINW,
           MAXX,MAXY,MAXZ,MAXW,
           DIFX,DIFY,DIFZ,DIFW,
           DIFMAXIMUM;

    FunctionParser * myParserX, * myParserY,* myParserZ, *myParserW, *Fct, *RgbtParser, *VRgbtParser, *GradientParser, *NoiseParser, *NoiseShapeParser;
    FunctionParser myParserCND[100],
                   myParserUmin[100], myParserUmax[100],
                   myParserVmin[100], myParserVmax[100],
                   Var[20], Cstparser;
    ParStruct ParamStructs[100];
    int Nb_paramfunctions, Nb_functs, Nb_rgbts, Nb_vrgbts;
    std::string  expression_X, expression_Y, expression_Z, expression_W, expression_CND, inf_u, sup_u, inf_v, sup_v,
        Varu, Const, Funct, Rgbt, Grid;
    std::string VarName[100], Varus[100], ConstNames[100], Consts[100], FunctNames[100], Functs[100],
    RgbtNames[100], Rgbts[100], VRgbt, VRgbts[100], VRgbtNames[100],
    Gradient, Noise, NoiseShape, SliderNames[50];
    double  v_inf[100], v_sup[100],u_inf[100],u_sup[100],dif_v[100],dif_u[100];
    double SliderValues[5000];
    double stepMorph, pace;
    int activeMorph, Nb_newvariables, Nb_constants, Nb_funct;
    Matrix4D mat4D, mat_rotation4D, mat_rotation_save4D,
             mat_homothetie4D, mat_translation4D, mat_inversetranslation4D;
    double tetaxy, tetaxz, tetayz, tetaxw, tetayw, tetazw;

    int tetaxy_ok, tetaxz_ok, tetayz_ok, tetaxw_ok, tetayw_ok, tetazw_ok, param4D;
    int   largeur_fenetre,hauteur_fenetre;
    int mesh, box,infos, latence, ParConditionRequired;
    unsigned int NbPolygn;
    int NbVertex;
    unsigned int NbPolygnNbVertex[2], nbBorderPts;
    float Lacunarity, Gain;
    int Octaves;
public:
    Par3D();
    ~Par3D();
    void Anim_Rot3D (int idx=0);
    void rotation4();
    void calcul_points4(int idx=0);
    void Anim_Rot4D (int idx=0);
    void project_4D_to_3D(int idx=0);
    void Invert_boite_englobante4D(int idx=0);
    void boite_englobante4D(int index=0);
    void initialiser_parametres();
    void initialiser_parseur();
    void initparser(int);
    void calcul_objet(int i =0, int component =0);
    void calcul_Norm(int i=0);
    void BorderCalculation(int i=0);
    void make_PolyIndex(int i=0, int  IsoPos=0);
    void make_PolyIndexTri(int i=0, int  IsoPos=0);
    void make_PolyIndexMin(int i=0, int  IsoPos=0);
    int  HowManyParamSurface(std::string, int);
    int  HowManyVariables(std::string, int);
    ErrorMessage parse_expression();
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
};
