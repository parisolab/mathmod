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
#include "commun.h"


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
    static std::vector<uint>  IndexPolyTabVector;
    static std::vector<float> NormVertexTabVector;
    static std::vector<uint> IndexPolyTabMinVector;
    static std::vector<uint> IndexPolyTabMinVector2;
};

class WorkerThread : public QThread
{
public:
    WorkerThread();
    ~WorkerThread();
    uint count_comma(const std::string);
public:
    uint CurrentComponent, MyIndex, WorkerThreadsNumber, iStart, iFinish, StackFactor;
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
    std::vector<std::string> Rgbts, RgbtNames, VRgbts, VRgbtNames, Functs,
        FunctNames, Consts, ConstNames, SliderNames, ImportedFunctions;
    std::string Vect, Grid, Const, Funct, Rgbt, VRgbt, Gradient, Noise;
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
};

#endif // PARISOOBJECT_H
