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
#ifndef PARISODEF_H
#define PARISODEF_H

#include <math.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <QStringList>
#include <qthread.h>
#include "jiso.h"
#include "jpar.h"

class jpariso
{
public:
    jpariso();
    ~jpariso();

//private:
    QList<jpar> JPar;
    QList<jiso> JIso;
    QJsonArray JTextures;
    QJsonArray JPigments;
};














#endif // PARISODEF_H


