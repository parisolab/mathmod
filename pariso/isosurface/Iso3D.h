
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
    uint   Xgrid, Ygrid, Zgrid;
    uint iStart, iFinish;
    bool AllComponentTraited;
    int morph_activated;
    uint maximumgrid, Nb_newvariables, MyIndex, WorkerThreadsNumber;
    double stepMorph, pace;
    uint CurrentIso;
    double *xLocal2, *yLocal2, *zLocal2;
    double *vr2;
    ErrorMessage stdError;
    unsigned int NbPolygn, NbPolygnNbVertex[2];
    bool StopCalculations, ParsersAllocated;
    int signalVal;
public :
    void IsoCompute(uint);
    void VoxelEvaluation(uint);
    void AllocateParsersForWorkerThread(int,int);
    void DeleteWorkerParsers();
    void IsoWorkerTable();
    void run() Q_DECL_OVERRIDE;
    IsoWorkerThread();
    ~IsoWorkerThread() override;
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
    int IsoConditionRequired, Nb_Sliders,
        ImplicitFunctionSize, ConditionSize, ConstSize, VaruSize, FunctSize, RgbtSize, VRgbtSize;
    uint Nb_rgbts, Nb_vrgbts, Nb_constants, Nb_implicitfunctions, Nb_functs;
    double *ConstValues, *SliderValues;
    double *x_Step, *y_Step, *z_Step;
    int *GridTable;
    double Octaves, Lacunarity, Gain;
    ImplicitStructure *ImplicitStructs;
    bool *UsedFunct, *UsedFunct2;
public :
    void DeleteMasterParsers();
    void AllocateMasterParsers();
    void InitMasterParsers();
    inline ErrorMessage ParseExpression(std::string);
    uint HowManyIsosurface(std::string,uint);
    uint HowManyVariables(std::string, uint);
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
    uint   Xgrid, Ygrid, Zgrid;
    uint WorkerThreadsNumber;
    uint   *     IsoSurfaceTriangleListe;
    bool *     PointVerifyCond, StopCalculations;
    int *     TypeIsoSurfaceTriangleListeCND;
    //unsigned int *  IndexPolyTab;
    uint NbTriangleIsoSurface,NbPointIsoMap;
    ScriptErrorType messageerror;
    QString message;
public :
    Iso3D(uint, uint,
          uint gridmax=NbMaxGrid,
          uint NbCmp=NbComponent,
          uint NbVar=NbVariables,
          uint NbCst=NbConstantes,
          uint NbdeFct=NbDefinedFunctions,
          uint NbText=NbTextures,
          int nbSlid=NbSliders,
          int nbSlidV=NbSliderValues,
          uint nbThreads=6,
          uint nbGrid=40,
          uint factX=4,
          uint factY=4,
          uint factZ=4);
    ~Iso3D() override;
    inline   void SignatureComputation();
    inline   uint ConstructIsoSurface();
    inline   void ConstructIsoNormale();
    inline   uint PointEdgeComputation(uint);
    inline int CNDCalculation(int &, struct ComponentInfos *);
    void IsoBuild(float *, unsigned int *, unsigned int *,unsigned  int *, unsigned int *,unsigned  int *, struct ComponentInfos *, int *, bool *);
    void SaveIsoGLMap();
    uint SetMiniMmeshStruct();
    int CNDtoUse(int index, struct ComponentInfos *components);
    void CalculateColorsPoints(struct ComponentInfos *components);
    void BuildIso();
    void UpdateThredsNumber(uint);
    void stopcalculations(bool);
    void WorkerThreadCopy(IsoWorkerThread *);
    ErrorMessage IsoMorph();
    ErrorMessage parse_expression2();
    ErrorMessage ThreadParsersCopy();
    void ReinitVarTablesWhenMorphActiv(uint);
    void copycomponent(struct ComponentInfos*, struct ComponentInfos*);
    void run() Q_DECL_OVERRIDE;
public :
    void emitErrorSignal();
    void emitUpdateMessageSignal();
signals:
    void ErrorSignal(int);
    void UpdateMessageSignal(QString);
};
