/***************************************************************************
 *   Copyright (C) 2017 by Abderrahman Taha                                *
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
#include "isothread.h"
#include "Iso3D.h"


IsoThread::IsoThread(Iso3D *iso)
    : QThread(), IsoObjet(iso)
{
    doRendering = true;
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void IsoThread::stop()
{
    doRendering = false;
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void IsoThread::anim()
{
    //IsoObjet->anim();
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void IsoThread::morph()
{
    //IsoObjet->morph();
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void IsoThread::update()
{
    //IsoObjet->update();
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void IsoThread::run()
{
    BuildIso();
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void IsoThread::BuildIso()
{
    IsoObjet->IsoBuild(
            LocalScene->ArrayNorVer_localPt,
            LocalScene->PolyIndices_localPt,
            &LocalScene->PolyNumber,
            &(LocalScene->VertxNumber),
            LocalScene->PolyIndices_localPtMin,
            &(LocalScene->NbPolygnNbVertexPtMin),
            &(LocalScene->componentsinfos),
            LocalScene->Typetriangles,
            LocalScene->WichPointVerifyCond);
}

