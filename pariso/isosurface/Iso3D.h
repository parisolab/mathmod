
/***************************************************************************
 *   Copyright (C) 2024 by Abderrahman Taha                                *
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
#include <deque>
#include <cmath>
#include "../parisoobject.h"

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


class IsoWorkerThread : public WorkerThread
{
    Q_OBJECT
public :
    FunctionParser *implicitFunctionParser, *Fct;
    uint XYZgrid;
    bool AllComponentTraited;
    uint GridVal;
    std::vector<double> xLocal2, yLocal2, zLocal2;
    std::vector<double> vals, Res;
    uint OrignbX, OrignbY, OrignbZ;
public :
    void IsoCompute(uint);
    void VoxelEvaluation(uint);
    void AllocateParsersForWorkerThread(uint,uint);
    void AllocateStackFactor(int *);
    void DeleteWorkerParsers();
    void run() Q_DECL_OVERRIDE;
    IsoWorkerThread();
    ~IsoWorkerThread() override;
    void emitMySignal();
signals:
    void mySignal(int);
};

class IsoMasterThread : public MasterThread, public IsoWorkerThread
{
public :
    FunctionParser *xSupParser, *xInfParser,
                   *ySupParser, *yInfParser,
                   *zSupParser, *zInfParser;
    std::string ImplicitFunction, Condition,
        XlimitSup, XlimitInf,
        YlimitSup, YlimitInf,
        ZlimitSup, ZlimitInf;
    uint componentsNumber;
    std::vector<double> x_Step, y_Step, z_Step, x_Sup, y_Sup, z_Sup,x_Inf, y_Inf, z_Inf;
    std::vector<ImplicitStructure> ImplicitStructs;
public :
    void DeleteMasterParsers();
    void AllocateMasterParsers();
    void InitMasterParsers();
    inline ErrorMessage ParseExpression();
    uint HowManyIsosurface(std::string,uint);
    uint HowManyVariables(std::string, uint);
    ErrorMessage ParserIso();
    void IsoMasterTable();
    void initparser();
    void initgrid();
    IsoMasterThread();
    ~IsoMasterThread();
};

class Iso3D  : public ParisoObject
{
    Q_OBJECT
public :
    IsoWorkerThread *workerthreads;
    IsoMasterThread *masterthread;
public :
    Iso3D(uint, uint, int *);
    ~Iso3D() override;
    inline void SignatureComputation();
    inline uint ConstructIsoSurface();
    inline void ConstructIsoNormale(uint);
    inline uint PointEdgeComputation(uint);
    inline uint CNDCalculation(uint &, struct ComponentInfos *);
    void Setgrid(uint);
    void IsoBuild(float **, uint **, uint *,unsigned  int *, uint **,unsigned  int *, unsigned  int *, struct ComponentInfos *);
    void InitShowComponent(struct ComponentInfos *);
    void SaveIsoGLMap(uint);
    uint SetMiniMmeshStruct();
    void CalculateColorsPoints(struct ComponentInfos*, uint index);
    void BuildIso();
    void UpdateNbMaxGrid(int);
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
