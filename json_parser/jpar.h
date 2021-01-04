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
#ifndef JPAR_H
#define JPAR_H

#include <QJsonArray>
#include <QJsonObject>
#include <QStringList>
#include <iostream>
#include <math.h>
#include <qthread.h>
#include <stdlib.h>
#include <string>

class jpar
{
public:
    jpar();
    ~jpar();
    void read(const QJsonObject &json);

public:
    QStringList Name;
    QStringList Csts;
    QStringList Funct;
    QStringList Grid;
    QStringList Fx;
    QStringList Fy;
    QStringList Fz;
    QStringList Fw;
    QStringList Umin;
    QStringList Umax;
    QStringList Vmin;
    QStringList Vmax;
    QStringList Component;
};

#endif // JPAR_H
