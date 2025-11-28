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
#ifndef PARISOOBJECT_H
#define PARISOOBJECT_H

#define VECT_STR      TextureInfos[0]
#define GRID_STR      TextureInfos[1]
#define CONST_STR     TextureInfos[2]
#define FUNCT_STR     TextureInfos[3]
#define RGBT_STR      TextureInfos[4]
#define VRGBT_STR     TextureInfos[5]
#define GRADIENT_STR  TextureInfos[6]
#define NOISE_STR     TextureInfos[7]


#include "commun.h"

#include <QJsonArray>
class GenOperation
{
public:
    virtual ~GenOperation() = default;
    virtual void performAction(QJsonArray){};
};
class ParThickness : public GenOperation
{
public:
    ParThickness();
    ~ParThickness();
public:
    OperationsType OpType=NO_OP;
    bool OriginalSurf=false, UpperSurf=false, BoumdarySurfs=false;
    QString ThExpression="";
    void performAction(QJsonArray) override;
};
class IsoThickness  : public GenOperation
{
public:
    IsoThickness();
    ~IsoThickness();
    void performAction(QJsonArray) override;
};
class ParisoObject : public QThread
{
public:
    ParisoObject();
    ~ParisoObject();
    uint CNDtoUse(uint, struct ComponentInfos *);
    void clear(struct ComponentInfos *);
public:
    ObjectProperties *localScene;
    uint WorkerThreadsNumber;
    bool StopCalculations;
    ScriptErrorType messageerror;
    QString message;
    IsoThicknessParam IsoTh;
    IsoTorsionParam IsoTr;
    IsoScaleParam IsoSc;
    ParThicknessParam ParTh;
    ParTorsionParam ParTr;
    ParScaleParam ParSc;
    ParVarParameters Parxyz;
    static std::vector<uint>  IndexPolyTabVector;
    static std::vector<float> NormVertexTabVector;
    static std::vector<uint> IndexPolyTabMinVector;
    static std::vector<uint> IndexPolyTabMinVector2;
    std::vector<std::shared_ptr<GenOperation>> OperationsTree;
};

class WorkerThread : public QThread
{
public:
    WorkerThread();
    ~WorkerThread();
    uint count_comma(const std::string);
public:
    uint CurrentComponent, ThreadIndex, WorkerThreadsNumber, iStart, iFinish, StackFactor;
    double stepMorph=0.0, pace=0.0;
    bool StopCalculations, ParsersAllocated, ParsersAllocated_C;
    int activeMorph, signalVal;
    int *ptStackFactor;
};

class MasterThread
{
public:
    FunctionParser *ParisoConditionParser, *RgbtParser, *VRgbtParser,
                   *GradientParser, *NoiseParser, *NoiseShapeParser, Cstparser;
    FunctionParser_cd *RgbtParser_C;
    std::vector<InternalFuncDefinition> ImportedInternalFunctions;
    std::vector<std::string> Rgbts, VRgbts, Functs,
        FunctNames, Consts, ConstNames, SliderNames;
    std::string TextureInfos[10];
    std::string Vect, Grid, Const, Funct;
    uint RgbtSize, FunctSize, VRgbtSize, ConstSize, Nb_Sliders;
    std::vector<uint> grid, vect;
    bool *UsedFunct, *UsedFunct2, gridnotnull, vectnotnull, constnotnull, functnotnull,
         cndnotnull, rgbtnotnull, rgbtnotnull_C, vrgbtnotnull, importnotnull;
    std::vector<double> ConstValues, SliderValues;
    double Octaves, Lacunarity, Gain;
    int ParisoCondition;
    ErrorMessage stdError;
public:
    MasterThread();
    ~MasterThread();
    void clearTextureInfos();
};

#endif // PARISOOBJECT_H
