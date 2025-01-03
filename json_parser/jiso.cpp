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

#include "jiso.h"

jiso::jiso() {}
jiso::~jiso() {}
void jiso::read(const QJsonObject &jason)
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
    if (jason["Xmin"].isArray())
    {
        array = jason["Xmin"].toArray();
        for (int i = 0; i < array.size(); i++)
            Xmin.append(array[i].toString());
    }
    if (jason["Xmax"].isArray())
    {
        array = jason["Xmax"].toArray();
        for (int i = 0; i < array.size(); i++)
            Xmax.append(array[i].toString());
    }
    if (jason["Ymin"].isArray())
    {
        array = jason["Ymin"].toArray();
        for (int i = 0; i < array.size(); i++)
            Ymin.append(array[i].toString());
    }
    if (jason["Ymax"].isArray())
    {
        array = jason["Ymax"].toArray();
        for (int i = 0; i < array.size(); i++)
            Ymax.append(array[i].toString());
    }
    if (jason["Zmin"].isArray())
    {
        array = jason["Zmin"].toArray();
        for (int i = 0; i < array.size(); i++)
            Zmin.append(array[i].toString());
    }
    if (jason["Zmax"].isArray())
    {
        array = jason["Zmax"].toArray();
        for (int i = 0; i < array.size(); i++)
            Zmax.append(array[i].toString());
    }
    if (jason["Component"].isArray())
    {
        array = jason["Component"].toArray();
        for (int i = 0; i < array.size(); i++)
            Component.append(array[i].toString());
    }
    if (jason["Fxyz"].isArray())
    {
        array = jason["Fxyz"].toArray();
        for (int i = 0; i < array.size(); i++)
            Fxyz.append(array[i].toString());
    }
    if (jason["Cnd"].isArray())
    {
        array = jason["Cnd"].toArray();
        for (int i = 0; i < array.size(); i++)
            Cnd.append(array[i].toString());
    }
}
