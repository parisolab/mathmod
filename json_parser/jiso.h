/***************************************************************************
 *   Copyright (C) 2016 by Abderrahman Taha                                *
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
#ifndef JISO_H
#define JISO_H

#include <math.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <QStringList>
#include <QJsonArray>
#include <QJsonObject>

class jiso
{
public:
    jiso();
    ~jiso();

    QStringList name() const;
    void setName(const QStringList &);

    QStringList text () const;
    void setText(const QStringList &);

    QStringList comment() const;
    void setComment(const QStringList &);

    QStringList varu() const;
    void setVaru(const QStringList &);

    QStringList csts() const;
    void setConst(const QStringList &);

    QStringList funct() const;
    void setFunct(const QStringList &);

    QStringList grid() const;
    void setGrid(const QStringList &);

    QStringList rgbt() const;
    void setRGBT(const QStringList &);

    QStringList fxyz() const;
    void setFxyz(const QStringList &);

    QStringList xmin() const;
    void setXmin(const QStringList &);

    QStringList xmax() const;
    void setXmax(const QStringList &);

    QStringList ymin() const;
    void setYmin(const QStringList &);

    QStringList ymax() const;
    void setYmax(const QStringList &);

    QStringList zmin() const;
    void setZmin(const QStringList &);

    QStringList zmax() const;
    void setZmax(const QStringList &);

    QStringList component() const;
    void setComponent(const QStringList &);

    void read(const QJsonObject &);
    void write(QJsonObject &) const;

public:
    QStringList Text;
    QStringList Comment;
    QStringList Name;
    QStringList Varu;
    QStringList Csts;
    QStringList Funct;
    QStringList Grid;
    QStringList RGBT;
    QStringList Fxyz;
    QStringList Xmin;
    QStringList Xmax;
    QStringList Ymin;
    QStringList Ymax;
    QStringList Zmin;
    QStringList Zmax;
    QStringList Cnd;
    QStringList Component;
    QJsonObject JisoObj;
    int          Nbcomponent;
    int          index;
};

#endif // JISO_H
