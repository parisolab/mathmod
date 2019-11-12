/***************************************************************************
 *   Copyright (C) 2019 by Abderrahman Taha                                *
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
#include <qstring.h>
#include <qfile.h>
#include <QTextStream>
#include <QStringList>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFileDialog>
#include <QDialog>
#include <QTranslator>

struct ParamStruct
{
    QString text;
    QString Varu;
    QString Const;
    QString Funct;
    QString Cnd;
    QString Grid;
    QString RGBT;
    QString fx;
    QString fy;
    QString fz;
    QString fw;
    QString umin;
    QString umax;
    QString vmin;
    QString vmax;
    QString tmin;
    QString tmax;
    QString comment;
    QString name;
    QString Component;
    int     Nbcomponent;
    int     index;
};

struct IsoStruct
{
    QString text;
    QString comment;
    QString name;
    QString Varu;
    QString Const;
    QString Funct;
    QString Cnd;
    QString Grid;
    QString RGBT;
    QString VRGBT;
    QString fxyz;
    QString xmin;
    QString xmax;
    QString ymin;
    QString ymax;
    QString zmin;
    QString zmax;
    QString Component;
    int          Nbcomponent;
    int          index;
};

struct TreeStruct
{
    QStringList name;
    QStringList Component;
    QStringList Varu;
    QStringList Const;
    QStringList Funct;
    QStringList Grid;
    QStringList Cnd;
    QStringList RGBT;
    QStringList VRGBT;
    QStringList Gradient;

    QString       Noise;
    QString       text;

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
};

class ParisoMathObject
{
public :
    IsoStruct  IsoTable[2000];
    ParamStruct ParamTable[2000];

    int NbIsoStruct;
    int NbParamStruct;
    ParamStruct CurrentParamStruct;
    IsoStruct        CurrentIsoStruct;
    QJsonObject CurrentJsonObject;
    QJsonArray MyJsonObjectSelection;
    TreeStruct CurrentTreestruct;
    QString dotsymbol;

public :
    ParisoMathObject();
    ~ParisoMathObject();
    void ReadJsonFile(QString, QJsonObject &);
    QStringList ParObject();
    QStringList IsoObject();
};
