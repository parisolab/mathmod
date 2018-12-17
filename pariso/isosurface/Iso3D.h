
/***************************************************************************
 *   Copyright (C) 2018 by Abderrahman Taha                                *
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


class IsoWorkerThread : public QThread
{
    Q_OBJECT
public :
    FunctionParser *implicitFunctionParser, *Fct;
    int   Xgrid, Ygrid, Zgrid;
    int iStart, iFinish;
    bool AllComponentTraited;
    int morph_activated, Nb_newvariables, maximumgrid;
    double stepMorph, pace;
    int CurrentIso;
    double *xLocal2, *yLocal2, *zLocal2;
    double *vr2;
    ErrorMessage stdError;
    unsigned int NbPolygn, NbPolygnNbVertex[2], MyIndex,WorkerThreadsNumber;
    bool StopCalculations, ParsersAllocated;
    int signalVal;
public :
    void IsoCompute(int);
    void VoxelEvaluation(int);
    void AllocateParsersForWorkerThread(int,int);
    void DeleteWorkerParsers();
    void IsoWorkerTable();
    void run() Q_DECL_OVERRIDE;
    IsoWorkerThread();
    ~IsoWorkerThread();
signals:
    void mySignal(int myParameter);
public:
    void emitMySignal();
};

class IsoMasterThread : public IsoWorkerThread
{
public :
    FunctionParser *IsoConditionParser, Cstparser, *RgbtParser, *VRgbtParser, *GradientParser, *NoiseParser,
                   *xSupParser, *xInfParser,
                   *ySupParser, *yInfParser,
                   *zSupParser, *zInfParser,
                   *Var;
    std::string ImplicitFunction, Condition,
        XlimitSup, XlimitInf,
        YlimitSup, YlimitInf,
        ZlimitSup, ZlimitInf, Grid,
        Const, *Consts, *ConstNames,
        *SliderNames,
        Varu, *Varus, *VarName,
        Funct,*Functs, *FunctNames,
        Rgbt, *Rgbts, *RgbtNames,
        VRgbt, *VRgbts, *VRgbtNames,
        Gradient, Noise, varliste;
    int IsoConditionRequired, Nb_implicitfunctions, Nb_constants, Nb_functs, Nb_rgbts, Nb_vrgbts, Nb_Sliders,
        ImplicitFunctionSize, ConditionSize, ConstSize, VaruSize, FunctSize, RgbtSize, VRgbtSize;
    double *ConstValues, *SliderValues;
    double *x_Step, *y_Step, *z_Step;
    int *GridTable;
    float Octaves, Lacunarity, Gain;
    ImplicitStructure *ImplicitStructs;
    bool *UsedFunct, *UsedFunct2;
public :
    void DeleteMasterParsers();
    void AllocateMasterParsers();
    void InitMasterParsers();
    inline ErrorMessage ParseExpression(std::string);
    int HowManyIsosurface(std::string,int);
    int HowManyVariables(std::string, int);
    ErrorMessage ParserIso();
    void IsoMasterTable();
    void initparser();
    IsoMasterThread();
    ~IsoMasterThread();
};

class Iso3D  : public QThread
{
    Q_OBJECT
public :
    ObjectProperties *LocalScene;
    IsoWorkerThread *workerthreads;
    IsoMasterThread *masterthread;
    int   Xgrid, Ygrid, Zgrid;
    int WorkerThreadsNumber;
    int   *     IsoSurfaceTriangleListe;
    bool *     PointVerifyCond, StopCalculations;
    int *     TypeIsoSurfaceTriangleListeCND;
    //unsigned int *  IndexPolyTab;
    int NbTriangleIsoSurface,NbPointIsoMap;
    ScriptErrorType messageerror;
    QString message;
public :
    Iso3D(int, int,
          int gridmax=NbMaxGrid,
          int NbCmp=NbComponent,
          int NbVar=NbVariables,
          int NbCst=NbConstantes,
          int NbdeFct=NbDefinedFunctions,
          int NbText=NbTextures,
          int nbSlid=NbSliders,
          int nbSlidV=NbSliderValues,
          int nbThreads=6,
          int nbGrid=40,
          int factX=4,
          int factY=4,
          int factZ=4);
    ~Iso3D();
    inline   void SignatureComputation();
    inline   int ConstructIsoSurface();
    inline   void ConstructIsoNormale();
    inline   int PointEdgeComputation(int);
    inline int CNDCalculation(int &, struct ComponentInfos *);
    void IsoBuild(float *, unsigned int *, unsigned int *,unsigned  int *, unsigned int * a=NULL,unsigned  int *b=NULL, struct ComponentInfos * P=NULL, int *listeCND=NULL, bool *ltypeCND=NULL);
    void SaveIsoGLMap();
    int SetMiniMmeshStruct();
    int CNDtoUse(int index, struct ComponentInfos *components);
    void CalculateColorsPoints(struct ComponentInfos *components);
    void BuildIso();
    void UpdateThredsNumber(int);
    void stopcalculations(bool);
    void WorkerThreadCopy(IsoWorkerThread *);
    ErrorMessage IsoMorph();
    ErrorMessage parse_expression2();
    ErrorMessage ThreadParsersCopy();
    void ReinitVarTablesWhenMorphActiv(int);
    void copycomponent(struct ComponentInfos*, struct ComponentInfos*);
    void run() Q_DECL_OVERRIDE;
public :
    void emitErrorSignal();
    void emitUpdateMessageSignal();
signals:
    void ErrorSignal(int);
    void UpdateMessageSignal(QString);
};
