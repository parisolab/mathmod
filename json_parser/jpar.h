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
#ifndef JPAR_H
#define JPAR_H

#include <math.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <QStringList>
#include <QJsonArray>
#include <QJsonObject>
#include <qthread.h>

class jpar
{
public:
    jpar();
    ~jpar();

    QStringList name() const;
    void setName(const QStringList &);

    QStringList component() const;
    void setComponent(const QStringList &);

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
    void setRgbt(const QStringList &);

    QStringList fx() const;
    void setFx(const QStringList &);

    QStringList fy() const;
    void setFy(const QStringList &);

    QStringList fz() const;
    void setFz(const QStringList &);

    QStringList fw() const;
    void setFw(const QStringList &);

    QStringList umin() const;
    void setUmin(const QStringList &);

    QStringList umax() const;
    void setUmax(const QStringList &);

    QStringList vmin() const;
    void setVmin(const QStringList &);

    QStringList vmax() const;
    void setVmax(const QStringList &);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

public:
    QStringList Text;
    QStringList Comment;
    QStringList Name;
    QStringList Varu;
    QStringList Csts;
    QStringList Funct;
    QStringList Grid;
    QStringList RGBT;
    QStringList Fx;
    QStringList Fy;
    QStringList Fz;
    QStringList Fw;
    QStringList Umin;
    QStringList Umax;
    QStringList Vmin;
    QStringList Vmax;
    QStringList Component;
    QJsonObject JparObj;
    int          Nbcomponent;
    int          index;
};

#endif // JPAR_H
