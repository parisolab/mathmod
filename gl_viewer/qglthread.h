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
#ifndef QGLTHREAD_h
#define QGLTHREAD_h

#include <QGLWidget>
#include <QThread>
#include <QTime>

class GLThread;
class OpenGlWidget;

class GLThread : public QThread
{
public:
    GLThread(OpenGlWidget *);
    void resizeViewport(const QSize &size);
    void anim();
    void morph();
    void update();
    void run();
    void stop();

private:
    bool doRendering;
    bool doResize;
    int w;
    int h;
    OpenGlWidget *glw;
};
#endif // GLWidget_h
