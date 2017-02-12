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
#include "qglthread.h"
#include "glviewer.h"


GLThread::GLThread(OpenGlWidget *gl)
    : QThread(), glw(gl)
{
    doRendering = true;
    doResize = false;
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void GLThread::stop()
{
    doRendering = false;
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void GLThread::resizeViewport(const QSize &size)
{
    w = size.width();
    h = size.height();
    glw->resizeGL(w, h);
    glw->update();
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void GLThread::anim()
{
    glw->anim();
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void GLThread::morph()
{
    glw->morph();
}


///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void GLThread::update()
{
    glw->update();
}
///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void GLThread::run()
{
}

