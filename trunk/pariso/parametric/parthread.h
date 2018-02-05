/***************************************************************************
 *   Copyright (C) 2018 by Abderrahman Taha                                *
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

#ifndef PARTHREAD_H
#define PARTHREAD_H

#include <QThread>
#include <QTime>
#include "../objectparameters.h"
class GLThread;
class Par3D;

class ParThread : public QThread
{
    Q_OBJECT
public:
    ParThread(Par3D *);
    void BuildPar();
    void run() Q_DECL_OVERRIDE;
public  slots:
    void stopthread();

public:
    Par3D *ParObjet;
    ObjectProperties*  LocalScene;
};
#endif // PARTHREAD_H
