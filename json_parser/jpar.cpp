/***************************************************************************
 *   Copyright (C) 2023 by Abderrahman Taha                                *
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

jpar::jpar() {}
jpar::~jpar() {}
void jpar::read(const QJsonObject &jason)
{
    QJsonArray array;
    if (jason["Name"].isArray())
    {
        array = jason["Name"].toArray();
        for (int i = 0; i < array.size(); i++)
            Name.append(array[i].toString());
    }
    if (jason["Const"].isArray())
    {
        array = jason["Const"].toArray();
        for (int i = 0; i < array.size(); i++)
            Csts.append(array[i].toString());
    }
    if (jason["Funct"].isArray())
    {
        array = jason["Funct"].toArray();
        for (int i = 0; i < array.size(); i++)
            Funct.append(array[i].toString());
    }
    if (jason["Grid"].isArray())
    {
        array = jason["Grid"].toArray();
        for (int i = 0; i < array.size(); i++)
            Grid.append(array[i].toString());
    }
    if (jason["Umin"].isArray())
    {
        array = jason["Umin"].toArray();
        for (int i = 0; i < array.size(); i++)
            Umin.append(array[i].toString());
    }
    if (jason["Umax"].isArray())
    {
        array = jason["Umax"].toArray();
        for (int i = 0; i < array.size(); i++)
            Umax.append(array[i].toString());
    }
    if (jason["Vmin"].isArray())
    {
        array = jason["Vmin"].toArray();
        for (int i = 0; i < array.size(); i++)
            Vmin.append(array[i].toString());
    }
    if (jason["Vmax"].isArray())
    {
        array = jason["Vmax"].toArray();
        for (int i = 0; i < array.size(); i++)
            Vmax.append(array[i].toString());
    }
    if (jason["Component"].isArray())
    {
        array = jason["Component"].toArray();
        for (int i = 0; i < array.size(); i++)
            Component.append(array[i].toString());
    }
    if (jason["Fx"].isArray())
    {
        array = jason["Fx"].toArray();
        for (int i = 0; i < array.size(); i++)
            Fx.append(array[i].toString());
    }
    if (jason["Fy"].isArray())
    {
        array = jason["Fy"].toArray();
        for (int i = 0; i < array.size(); i++)
            Fy.append(array[i].toString());
    }
    if (jason["Fz"].isArray())
    {
        array = jason["Fz"].toArray();
        for (int i = 0; i < array.size(); i++)
            Fz.append(array[i].toString());
    }
}
