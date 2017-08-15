
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

#include <iostream>
#include <string.h>
#include <cmath>
#include "../objectparameters.h"
//#include "../commun.h"


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


class IsoWorkerThread : public QThread
{
public :

    FunctionParser * implicitFunctionParser, *Fct, *RgbtParser, *VRgbtParser, *GradientParser, *NoiseParser;
    FunctionParser IsoConditionParser[NbComponent],
                   xSupParser[NbComponent], xInfParser[NbComponent],
                   ySupParser[NbComponent], yInfParser[NbComponent],
                   zSupParser[NbComponent], zInfParser[NbComponent],
                   Var[NbVariables], Cstparser;
    int   nb_ligne, nb_colon, nb_depth;
    int GridTable[NbComponent];
    bool AllComponentTraited;
    int morph_activated, maximumgrid;
    double stepMorph, pace;
    std::string ImplicitFunction, Condition,
        XlimitSup, XlimitInf,
        YlimitSup, YlimitInf,
        ZlimitSup, ZlimitInf, Grid,
        Const, Consts[NbConstantes], ConstNames[NbConstantes],
        SliderNames[50],
        Varu, Varus[NbVariables], VarName[NbVariables],
        Funct, Functs[NbDefinedFunctions], FunctNames[NbDefinedFunctions],
        Rgbt, Rgbts[NbTextures], RgbtNames[NbTextures],
        VRgbt, VRgbts[NbTextures], VRgbtNames[NbTextures],
        Gradient, Noise, varliste;
    int IsoConditionRequired, Nb_implicitfunctions, Nb_newvariables, Nb_constants, Nb_functs, Nb_rgbts, Nb_vrgbts, Nb_Sliders;
    double ConstValues[NbConstantes];
    float Lacunarity, Gain;
    int Octaves, CurrentIso;
    double xLocal[NbComponent][NbMaxGrid],yLocal[NbComponent][NbMaxGrid], zLocal[NbComponent][NbMaxGrid];
    //double *xlocal;
    double X_Start, X_End, X_Step,
           Y_Start, Y_End, Y_Step,
           Z_Start, Z_End, Z_Step;
    double x_Step[NbComponent], y_Step[NbComponent], z_Step[NbComponent];
    double  vr[3*NbVariables][NbComponent][NbMaxGrid];//3* because each varu can be used for x,y or z
    ImplicitStruct ImplicitStructs[NbComponent];
    ErrorMessage stdError;
    double SliderValues[5000];
    double Xamplitude[NbComponent], Yamplitude[NbComponent], Zamplitude[NbComponent];

    int TimeFlow, iStart, iFinish;
    int  IsoMesh, IsoInfos, NbTriangleUsed, hauteur_fenetre, NbVertex;
    unsigned int NbPolygn, NbPolygnNbVertex[2], MyIndex,WorkerThreadsNumber;
    bool StopCalculations;
    public :
        void IsoCompute(int);
        void VoxelEvaluation(int);
        void EvalExpressionAtIndex(int);
        void deleteparsers();
        void allocateparsers(int N);
        inline ErrorMessage ParseExpression(std::string);
        int HowManyIsosurface(std::string,int);
        int HowManyVariables(std::string, int);
        ErrorMessage InitNoiseParser();
        ErrorMessage ParserIso();
        inline   void InitParser();
        void initparser(int N);
        void run() Q_DECL_OVERRIDE;
        IsoWorkerThread();
        ~IsoWorkerThread();
    };

    class Iso3D  : public QThread
    {
    public :
        ObjectProperties *LocalScene;
        IsoWorkerThread *workerthreads;
        int   nb_ligne, nb_colon, nb_depth;
        int WorkerThreadsNumber;
        int   *     IsoSurfaceTriangleListe;
        bool *     WichPointVerifyCond, StopCalculations;
        int *     TypeIsoSurfaceTriangleListeCND;
        unsigned int *  IndexPolyTab;
        int NbTriangleIsoSurface,NbPointIsoMap;

    public :
        Iso3D(int, int, int);
        ~Iso3D();
        inline   void DrawIsoSurface();
        inline   void InitParameter();
        inline   void SignatureComputation();
        inline   void ConstructIsoSurface();
        inline void ConstructIsoNormale();
        inline   void PointEdgeComputation(int,int);
        inline   void PointEdgeComputation2(int,int);
        void MinimalMeshObjFile();
        inline void CNDCalculation(int, struct ComponentInfos *);
        void IsoBuild(float *, unsigned int *, unsigned int *,unsigned  int *, unsigned int * a=NULL,unsigned  int *b=NULL, ComponentInfos *components = NULL, int *listeCND=NULL, bool *ltypeCND=NULL);
        void SaveIsoGLMap();
        int  setmaxgridto(int);
        void SetMinimuMmeshSize(double);
        void SetMiniMmeshStruct();
        void stopcalculations();
        int CNDtoUse(int index, struct ComponentInfos *components);
        void CalculateColorsPoints(struct ComponentInfos *components);
        void BuildIso();
        void UpdateThredsNumber(int);
        void stopcalculations(bool);
        void run() Q_DECL_OVERRIDE;
    };
