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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#include <iostream>
#include <string.h>
#include <cmath>
#include "../objectparameters.h"
//#include "isotransformation.h"




/*


                     4.-----------4----------------.5
                     /|                                     /|
                    7 |                                 5 |
                   /  |                                  /  |
                 7.---|-----------6------------.6  |
                  |   |                                 |   |
                  |   8                               |   9
                  |   |                                 |   |
                  |   ^ j                               |   |
               11   |                               10   |
                  |   |     i                           |   |
                  |  0.----->-----0------------|---.1
                  |  /                                  |  /
                  | 3 k                               | 1
                  |/                                    |/
                 3.---------------2------------.2
*/
struct ImplicitStruct
{
    std::string fxyz;
    std::string xmin;
    std::string xmax;
    std::string ymin;
    std::string ymax;
    std::string zmin;
    std::string zmax;
    std::string grid;
    std::string cnd;
    int              index;
};

struct  Voxel
{
    int Edge_Points [12]; //reference to the Edge Points
    int Signature; // From 0 to 255
    int NbEdgePoint;
};

class Iso3D
{
public :
    ErrorMessage stdError;
    int   *     IsoSurfaceTriangleListe;
    bool *     WichPointVerifyCond;
    int *     TypeIsoSurfaceTriangleListeCND;
    float *     NormVertexTab;
    unsigned int *  IndexPolyTab;
    double IsoNormOriginal[2*3*1];
    double AxeArrayOriginal[3][1100];  // 3D Axes X, y and Z with 50 points

    int MaximumNumberPoints, MaximumNumberTriangles,MaximumNumberTrianglesMin, maximumgrid;
    int NbPointIsoMap;
    int NbTriangleIsoSurface, IsoConditionRequired,NbPointIsoMapCND,
        ThreeTimesNbPolygnTmp;
    int i,j,k,l;
    FunctionParser * implicitFunctionParser, *Fct, *RgbtParser, *VRgbtParser, *GradientParser, *NoiseParser;
    FunctionParser IsoConditionParser[1100],
                   xSupParser[1100], xInfParser[1100],
                   ySupParser[1100], yInfParser[1100],
                   zSupParser[1100], zInfParser[1100],
                   Var[20], Cstparser;
    double Xamplitude[1100], Yamplitude[1100], Zamplitude[1100];
    std::string ImplicitFunction, Condition,
        XlimitSup, XlimitInf,
        YlimitSup, YlimitInf,
        ZlimitSup, ZlimitInf, Grid,
        Const, Consts[50], ConstNames[50],
        SliderNames[50],
        Varu, Varus[20], VarName[20],
        Funct, Functs[50], FunctNames[50],
        Rgbt, Rgbts[50], RgbtNames[50],
        VRgbt, VRgbts[50], VRgbtNames[50],
        Gradient, Noise, varliste;
    double ConstValues[50];
    double SliderValues[50];
    ImplicitStruct ImplicitStructs[1100];
    int GridTable[1100];
    int Nb_implicitfunctions, Nb_newvariables, Nb_constants, Nb_functs, Nb_rgbts, Nb_vrgbts;
    double stepMorph, pace;
    int morph_activated;
    int TimeFlow;
    bool AllComponentTraited;
    double X_Start, X_End, X_Step,
           Y_Start, Y_End, Y_Step,
           Z_Start, Z_End, Z_Step;
    double x_Step[1100], y_Step[1100], z_Step[1100];
    int   nb_ligne, nb_colon, nb_depth,
          CutLigne, CutColon, CutDepth;

    int  IsoMesh, IsoInfos, NbTriangleUsed, hauteur_fenetre;
    double xLocal[1100][500], yLocal[1100][500], zLocal[1100][500];

    double  vr[60][1100][500];//60-> because we have 20 varu and each can be used for x,y or z
    //2000-> the max isosurface to calculate;
    // 500-> the maximum grid supported (for now)
    int NbPolygonImposedLimit ;
    int NbVertex;
    unsigned int NbPolygn;
    unsigned int NbPolygnNbVertex[2];
    float Lacunarity, Gain;
    int Octaves;

public :
    Iso3D(int, int, int);
    ~Iso3D();
    inline   void VoxelEvaluation(int);
    inline   void PointEdgeComputation(int);
    inline   void DrawIsoSurface();
    inline   void InitParser();
    inline   void InitParameter();
    inline   void SignatureComputation();
    inline   void ConstructIsoSurface();
    inline void ConstructIsoNormale();
    inline ErrorMessage ParseExpression(std::string);
    inline void EvalExpressionAtIndex(int);
    void MinimalMeshObjFile();
    inline void CNDCalculation(int, struct ComponentInfos *);
/// FOR GL Window :
    ErrorMessage ParserIso();
    void initparser(int N);
    void IsoBuild(float *, unsigned int *, unsigned int *,unsigned  int *, unsigned int * a=NULL,unsigned  int *b=NULL, ComponentInfos *components = NULL, int *listeCND=NULL, bool *ltypeCND=NULL);
    void SaveIsoGLMap();
    int  setmaxgridto(int);
    void SetMinimuMmeshSize(double);
    void SetMiniMmeshStruct();
    void stopcalculations();
    int HowManyIsosurface(std::string,int);
    int HowManyVariables(std::string, int);
    int CNDtoUse(int index, struct ComponentInfos *components);
    void CalculateColorsPoints(struct ComponentInfos *components);
    ErrorMessage InitNoiseParser();
};
