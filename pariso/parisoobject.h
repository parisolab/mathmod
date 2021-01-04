/***************************************************************************
 *   Copyright (C) 2021 by Abderrahman Taha                                *
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
};

class WorkerThread : public QThread
{
public:
    WorkerThread();
    ~WorkerThread();

public:
    uint CurrentComponent, MyIndex, WorkerThreadsNumber, iStart, iFinish;
    double stepMorph, pace;
    bool StopCalculations, ParsersAllocated;
    int activeMorph, signalVal;
};

class MasterThread
{
public:
    FunctionParser *ParisoConditionParser, *RgbtParser, *VRgbtParser,
                   *GradientParser, *NoiseParser, *NoiseShapeParser, Cstparser;
    std::vector<std::string> Rgbts, RgbtNames, VRgbts, VRgbtNames, Functs,
        FunctNames, Consts, ConstNames, SliderNames;
    std::string Vect, Grid, Const, Funct, Rgbt, VRgbt, Gradient, Noise;
    uint RgbtSize, FunctSize, VRgbtSize, ConstSize, Nb_Sliders;
    std::vector<uint> grid, vect;
    bool *UsedFunct, *UsedFunct2, gridnotnull, vectnotnull, constnotnull, functnotnull,
         cndnotnull, rgbtnotnull, vrgbtnotnull;
    std::vector<double> ConstValues, SliderValues;
    double Octaves, Lacunarity, Gain;
    int ParisoCondition;
    ErrorMessage stdError;

public:
    MasterThread();
    ~MasterThread();
};

#endif // PARISOOBJECT_H
