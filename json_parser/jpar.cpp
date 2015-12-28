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



#include "jpar.h"

jpar::jpar()
{
}

jpar::~jpar()
{
}

QStringList jpar::text () const
{
    return Text;
}

void jpar::setText(const QStringList & txt)
{
    Text = txt;
}

QStringList jpar::comment() const
{
    return Comment;
}

void jpar::setComment(const QStringList &cmt)
{
    Comment = cmt;
}

QStringList jpar::varu() const
{
    return Varu;
}

void jpar::setVaru(const QStringList &var)
{
    Varu = var;
}

QStringList jpar::csts() const
{
    return Csts;
}

void jpar::setConst(const QStringList &cst)
{
    Csts = cst;
}

QStringList jpar::funct() const
{
    return Funct;
}

void jpar::setFunct(const QStringList &fct)
{
    Funct = fct;
}

QStringList jpar::grid() const
{
    return Grid;
}

void jpar::setGrid(const QStringList &grd)
{
    Grid = grd;
}

QStringList jpar::rgbt() const
{
    return RGBT;
}

void jpar::setRgbt(const QStringList &rgb)
{
    RGBT = rgb;
}

QStringList jpar::fx() const
{
    return Fx;
}

void jpar::setFx(const QStringList &fct)
{
    Fx = fct;
}

QStringList jpar::fy() const
{
    return Fy;
}

void jpar::setFy(const QStringList &fct)
{
    Fy = fct;
}

QStringList jpar::fz() const
{
    return Fz;
}

void jpar::setFz(const QStringList &fct)
{
    Fz = fct;
}


QStringList jpar::fw() const
{
    return Fw;
}

void jpar::setFw(const QStringList &fct)
{
    Fw = fct;
}
QStringList jpar::umin() const
{
    return Umin;
}

void jpar::setUmin(const QStringList &umi)
{
    Umin = umi;
}

QStringList jpar::umax() const
{
    return Umax;
}

void jpar::setUmax(const QStringList &uma)
{
    Umax = uma;
}

QStringList jpar::vmin() const
{
    return Vmin;
}

void jpar::setVmin(const QStringList &vmi)
{
    Vmin = vmi;
}

QStringList jpar::vmax() const
{
    return Vmax;
}

void jpar::setVmax(const QStringList &vma)
{
    Vmax = vma;
}

QStringList jpar::component() const
{
    return Component;
}

void jpar::setComponent(const QStringList &cmp)
{
    Component = cmp;
}

void jpar::read(const QJsonObject & jason)
{
    QJsonArray array;

    JparObj = jason;
    if(jason["Text"].isArray())
    {
        array = jason["Text"].toArray();
        for (int i=0; i< array.size(); i++)
            Text.append(array[i].toString());
    }
    if(jason["Comment"].isArray())
    {
        array = jason["Comment"].toArray();
        for (int i=0; i< array.size(); i++)
            Comment.append(array[i].toString());
    }
    if(jason["Name"].isArray())
    {
        array = jason["Name"].toArray();
        for (int i=0; i< array.size(); i++)
            Name.append(array[i].toString());
    }
    if(jason["Varu"].isArray())
    {
        array = jason["Varu"].toArray();
        for (int i=0; i< array.size(); i++)
            Varu.append(array[i].toString());
    }
    if(jason["Csts"].isArray())
    {
        array = jason["Csts"].toArray();
        for (int i=0; i< array.size(); i++)
            Csts.append(array[i].toString());
    }
    if(jason["Funct"].isArray())
    {
        array = jason["Funct"].toArray();
        for (int i=0; i< array.size(); i++)
            Funct.append(array[i].toString());
    }
    if(jason["Grid"].isArray())
    {
        array = jason["Grid"].toArray();
        for (int i=0; i< array.size(); i++)
            Grid.append(array[i].toString());
    }
    if(jason["RGBT"].isArray())
    {
        array = jason["RGBT"].toArray();
        for (int i=0; i< array.size(); i++)
            RGBT.append(array[i].toString());
    }
    if(jason["Umin"].isArray())
    {
        array = jason["Umin"].toArray();
        for (int i=0; i< array.size(); i++)
            Umin.append(array[i].toString());
    }
    if(jason["Umax"].isArray())
    {
        array = jason["Umax"].toArray();
        for (int i=0; i< array.size(); i++)
            Umax.append(array[i].toString());
    }
    if(jason["Vmin"].isArray())
    {
        array = jason["Vmin"].toArray();
        for (int i=0; i< array.size(); i++)
            Vmin.append(array[i].toString());
    }
    if(jason["Vmax"].isArray())
    {
        array = jason["Vmax"].toArray();
        for (int i=0; i< array.size(); i++)
            Vmax.append(array[i].toString());
    }
    if(jason["Component"].isArray())
    {
        array = jason["Component"].toArray();
        for (int i=0; i< array.size(); i++)
            Component.append(array[i].toString());
    }
    if(jason["Fx"].isArray())
    {
        array = jason["Fx"].toArray();
        for (int i=0; i< array.size(); i++)
            Fx.append(array[i].toString());
    }
    if(jason["Fy"].isArray())
    {
        array = jason["Fy"].toArray();
        for (int i=0; i< array.size(); i++)
            Fy.append(array[i].toString());
    }
    if(jason["Fz"].isArray())
    {
        array = jason["Fz"].toArray();
        for (int i=0; i< array.size(); i++)
            Fz.append(array[i].toString());
    }
}

void jpar::write(QJsonObject &json) const
{
    QJsonArray nm;
    for(int i =0; i< Name.size(); i++)
        nm.append(Name.at(i));
    json["Name"]=nm;

    QJsonArray txt;
    for(int i =0; i< Text.size(); i++)
        txt.append(Text.at(i));
    json["Text"]=txt;

    QJsonArray cmp;
    for(int i =0; i< Component.size(); i++)
        cmp.append(Component.at(i));
    json["Component"]=cmp;

    QJsonArray grd;
    for(int i =0; i< Grid.size(); i++)
        grd.append(Grid.at(i));
    json["Grid"]=grd;

    QJsonArray rgb;
    for(int i =0; i< RGBT.size(); i++)
        rgb.append(RGBT.at(i));
    json["RGBT"]=rgb;

    QJsonArray umi;
    for(int i =0; i< Umin.size(); i++)
        umi.append(Umin.at(i));
    json["Umin"]= umi;

    QJsonArray uma;
    for(int i =0; i< Umax.size(); i++)
        uma.append(Umax.at(i));
    json["Umax"]=uma;

    QJsonArray vmi;
    for(int i =0; i< Vmin.size(); i++)
        vmi.append(Vmin.at(i));
    json["Vmin"]= vmi;

    QJsonArray vma;
    for(int i =0; i< Vmax.size(); i++)
        vma.append(Vmax.at(i));
    json["Vmax"]=vma;

    QJsonArray fx;
    for(int i =0; i< Fx.size(); i++)
        fx.append(Fx.at(i));
    json["Fx"]=fx;

    QJsonArray fy;
    for(int i =0; i< Fy.size(); i++)
        fy.append(Fy.at(i));
    json["Fy"]=fy;

    QJsonArray fz;
    for(int i =0; i< Fz.size(); i++)
        fz.append(Fz.at(i));
    json["Fz"]=fz;
}



