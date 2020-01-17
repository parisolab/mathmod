/***************************************************************************
 *   Copyright (C) 2020by Abderrahman Taha                                *
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
#ifndef OBJECTPARAMETERS_H
#define OBJECTPARAMETERS_H
#include "commun.h"

class ParisoObject
{
    public:
    ParisoObject();
    ~ParisoObject();
    public:
    FunctionParser *ParisoConditionParser, *RgbtParser, *VRgbtParser,
                   Cstparser, *GradientParser, *NoiseParser;
    bool *UsedFunct, *UsedFunct2, gridnotnull, constnotnull,
    functnotnull, cndnotnull, rgbtnotnull, vrgbtnotnull;
    std::vector<std::string> Rgbts, RgbtNames,
                             VRgbts, VRgbtNames,
                             Functs, FunctNames,
                             Consts, ConstNames,
                             SliderNames;
    std::vector<uint> grid;
    uint componentsSize, RgbtSize, FunctSize, VRgbtSize, ConstSize, Nb_Sliders;
    std::vector<double> ConstValues, SliderValues;
    std::string ConditionStr, Gradient, Noise, Const,  Funct, Rgbt, VRgbt, Grid;
    int ParisoCondition;
    GlobalParam globalparam;
    double Octaves, Lacunarity, Gain;
};

class ObjectParameters
{
public:
    ObjectProperties objectproperties;
public:
    ObjectParameters();
    void InitComponentinfos(struct  ComponentInfos &);
};

#endif // OBJECTPARAMETERS_H
