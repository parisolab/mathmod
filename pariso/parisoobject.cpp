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
#include "parisoobject.h"


std::vector<uint> ParisoObject::IndexPolyTabVector;
std::vector<float> ParisoObject::NormVertexTabVector;
std::vector<uint> ParisoObject::IndexPolyTabMinVector;
std::vector<uint> ParisoObject::IndexPolyTabMinVector2;

ParThickness::ParThickness(){}
ParThickness::~ParThickness(){}
void ParThickness::performAction(const QJsonArray& ptr)
{
    OpType = (OperationsType)ptr[0].toInt();
    OriginalSurf           = ptr[1].toBool();
    UpperSurf              = ptr[2].toBool();
    BoumdarySurfs          = ptr[3].toBool();
    ThExpression           = ptr[4].toString();
};
IsoThickness::IsoThickness(){}
IsoThickness::~IsoThickness(){}

void IsoThickness::performAction(const QJsonArray&)
{
}
MasterThread::MasterThread() {}
MasterThread::~MasterThread() {}

void MasterThread::clearTextureInfos()
{
    RGBT_STR = VRGBT_STR = GRADIENT_STR = NOISE_STR="";
}

WorkerThread::WorkerThread() {}
WorkerThread::~WorkerThread() {}
uint WorkerThread::count_comma(const std::string s)
{
    uint count = 0, size=0;
    size=s.size();
    for (uint i = 0; i < size; i++)
        if (s[i] == ',') count++;
    return count;
}
ParisoObject::ParisoObject() {}
ParisoObject::~ParisoObject() {}
uint ParisoObject::CNDtoUse(uint index, struct ComponentInfos *components)
{
    uint idx = 0;
    for (uint i = 0; i < components->NbComponentsType.size() - 1; i++)
        idx += components->NbComponentsType[i];
    for (uint fctnb = 0;
            fctnb < (components->NbComponentsType[components->NbComponentsType.size() - 1]);
            fctnb++)
        if (index <= components->ParisoVertex[2 * (fctnb + idx) + 1] &&
                index >= components->ParisoVertex[2 * (fctnb + idx)])
            return fctnb;
    return 30;
}
void ParisoObject::clear(struct ComponentInfos *cp)
{
    cp->ParisoTriangle.clear();
    cp->ParisoVertex.clear();
    cp->NbComponentsType.clear();
    cp->ThereisCND.clear();
    cp->ParisoCondition.clear();
    cp->hsv.clear();
    cp->ShowParIsoCmp.clear();
    cp->ThereisRGBA.clear();
    cp->NbTrianglesVerifyCND.clear();
    cp->NbTrianglesNoCND.clear();
    cp->NbTrianglesNotVerifyCND.clear();
    cp->NbTrianglesBorderCND.clear();
    cp->ParisoCurrentComponentIndex = 0;
    cp->ParisoNbComponents = 0;
    cp->Interleave = true;
    cp->pariso = false;
    cp->updateviewer = false;
}
