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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#ifndef PARISOMATHOBJECT_H
#define PARISOMATHOBJECT_H

#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringList>
#include <QTextStream>
#include <iostream>
#include <qfile.h>
#include <qstring.h>

enum ModelType { PAR_TYPE, PAR_4D_TYPE, ISO_TYPE, PARISO_TYPE, UNDEFINED_TYPE };

struct TreeStruct
{
    QStringList name;
    QStringList Component;
    QStringList Const;
    QStringList Funct;
    QStringList Grid;
    QStringList Vect;
    QStringList Cnd;
    QStringList RGBT;
    QStringList VRGBT;
    QStringList Gradient;
    QString Noise;
    QString text;
    QStringList fxyz;
    QStringList xmin;
    QStringList xmax;
    QStringList ymin;
    QStringList ymax;
    QStringList zmin;
    QStringList zmax;
    QStringList fx;
    QStringList fy;
    QStringList fz;
    QStringList fw;
    QStringList umin;
    QStringList umax;
    QStringList vmin;
    QStringList vmax;
    QStringList tmin;
    QStringList tmax;
    QStringList include;
    ModelType type;
};

class ParisoMathObject
{
public:
    int NbIsoStruct;
    int NbParamStruct;
    QJsonObject CurrentJsonObject;
    QJsonArray MyJsonObjectSelection;
    TreeStruct CurrentTreestruct;
    std::vector<TreeStruct> CurrentParisoTreestruct;
    QString dotsymbol;
    QJsonArray PreviousJsonObject;
    int IndexCurrentJsonObject=-1;

public:
    ParisoMathObject();
    ~ParisoMathObject();
    void ReadJsonFile(QString, QJsonObject &);
};

#endif
