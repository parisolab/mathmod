
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
        FunctionParser *implicitFunctionParser, *Fct,
                       *xSupParser, *xInfParser,
                       *ySupParser, *yInfParser,
                       *zSupParser, *zInfParser,
                       *Var;
        int   nb_ligne, nb_colon, nb_depth;
        int iStart, iFinish;
        int GridTable[NbComponent];
        bool AllComponentTraited;
        int morph_activated, Nb_newvariables, maximumgrid;
        double stepMorph, pace;
        int CurrentIso;
        double xLocal[NbComponent][NbMaxGrid],yLocal[NbComponent][NbMaxGrid], zLocal[NbComponent][NbMaxGrid];
        double x_Step[NbComponent], y_Step[NbComponent], z_Step[NbComponent];
        double  vr[3*NbVariables][NbComponent][NbMaxGrid];
        std::string VarName[NbVariables];
        ErrorMessage stdError;
        unsigned int NbPolygn, NbPolygnNbVertex[2], MyIndex,WorkerThreadsNumber;
        bool StopCalculations, ParsersAllocated;
        ImplicitStruct ImplicitStructs[NbComponent];
        public :
            void IsoCompute(int);
            void VoxelEvaluation(int);
            void AllocateParsersForWorkerThread(int, int, int);
            void DeleteWorkerParsers();
            void run() Q_DECL_OVERRIDE;
            IsoWorkerThread();
            ~IsoWorkerThread();
    };

    class IsoMasterThread : public IsoWorkerThread
    {
        public :
            FunctionParser IsoConditionParser[NbComponent], Cstparser, *RgbtParser, *VRgbtParser, *GradientParser, *NoiseParser;
            std::string ImplicitFunction, Condition,
            XlimitSup, XlimitInf,
            YlimitSup, YlimitInf,
            ZlimitSup, ZlimitInf, Grid,
            Const, Consts[NbConstantes], ConstNames[NbConstantes],
            SliderNames[50],
            Varu, Varus[NbVariables],
            Funct, Functs[NbDefinedFunctions], FunctNames[NbDefinedFunctions],
            Rgbt, Rgbts[NbTextures], RgbtNames[NbTextures],
            VRgbt, VRgbts[NbTextures], VRgbtNames[NbTextures],
            Gradient, Noise, varliste;
            int IsoConditionRequired, Nb_implicitfunctions, Nb_constants, Nb_functs, Nb_rgbts, Nb_vrgbts, Nb_Sliders,
            ImplicitFunctionSize, ConditionSize, ConstSize, VaruSize, FunctSize, RgbtSize, VRgbtSize;
            double ConstValues[NbConstantes], SliderValues[5000];
            float Octaves, Lacunarity, Gain;
        public :
            void DeleteMasterParsers();
            void AllocateMasterParsers();
            void InitMasterParsers();
            void AllocateParsersForMasterThread();
            inline ErrorMessage ParseExpression(std::string);
            int HowManyIsosurface(std::string,int);
            int HowManyVariables(std::string, int);
            ErrorMessage InitNoiseParser();
            ErrorMessage ParserIso();
            inline   void InitParser();
            void initparser();
            IsoMasterThread();
            ~IsoMasterThread();
    };

    class Iso3D  : public QThread
    {
        public :
                ObjectProperties *LocalScene;
                IsoWorkerThread *workerthreads;
                IsoMasterThread *masterthread;
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
                inline   void PointEdgeComputation(int);
                void MinimalMeshObjFile();
                inline void CNDCalculation(int, struct ComponentInfos *);
                void IsoBuild(float *, unsigned int *, unsigned int *,unsigned  int *, unsigned int * a=NULL,unsigned  int *b=NULL, ComponentInfos *components = NULL, int *listeCND=NULL, bool *ltypeCND=NULL);
                void SaveIsoGLMap();
                int  setmaxgridto(int);
                void SetMinimuMmeshSize(double);
                void SetMiniMmeshStruct();
                int CNDtoUse(int index, struct ComponentInfos *components);
                void CalculateColorsPoints(struct ComponentInfos *components);
                void BuildIso();
                void UpdateThredsNumber(int);
                void stopcalculations(bool);
                void WorkerThreadCopy(IsoWorkerThread *);
                void MasterThreadCopy(IsoMasterThread *);
                ErrorMessage IsoMorph();
                ErrorMessage parse_expression2();
                ErrorMessage ThreadParsersCopy();
                void ReinitVarTablesWhenMorphActiv(int);
                void run() Q_DECL_OVERRIDE;
    };
