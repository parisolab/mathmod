/***************************************************************************
 *   Copyright (C) 2022 by Abderrahman Taha                                *
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

#include "json_parser/parisodef.h"
#include "ui_modules/drawingoptions.h"
#include "ui_modules/mathmod.h"
#include "ui_modules/parametersoptions.h"
#include <QApplication>
#include <QTextStream>
#include <QGuiApplication>
#include <QSurfaceFormat>
#include <QOpenGLContext>
#ifdef Q_WS_X11
#include <X11/Xlib.h>
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);
    Parametersoptions Parameters;
    Parameters.LoadConfig(argc, argv);
    app.setStyle(QStyleFactory::create("Fusion"));
    app.setPalette(Parameters.darkpalette);
    QList<Qt::GestureType> gestures;
    gestures << Qt::PinchGesture;
    DrawingOptions drawingopt;
    drawingopt.grabGestures(gestures);
    // save references:
    drawingopt.Parameters = &Parameters;
    drawingopt.MathmodRef = drawingopt.ui.openGLWidget;
    drawingopt.ui.openGLWidget->Xgrid = drawingopt.ui.openGLWidget->Ygrid = drawingopt.ui.openGLWidget->Zgrid=uint(InitIsoGrid);
    drawingopt.ui.openGLWidget->Ugrid = drawingopt.ui.openGLWidget->Vgrid = uint(InitParGrid);
    // GUI update:
    drawingopt.show();
    drawingopt.UpdateGui(argc);
    if (drawingopt.IsolistItemRef != nullptr)
        drawingopt.ui.ObjectClasse->expandItem(drawingopt.IsolistItemRef);
    QObject::connect(drawingopt.MathmodRef->IsoObjet->masterthread,
                     SIGNAL(mySignal(int)), drawingopt.ui.progressBar,
                     SLOT(setValue(int)));
    QObject::connect(drawingopt.MathmodRef->ParObjet->masterthread,
                     SIGNAL(mySignal(int)), drawingopt.ui.progressBar,
                     SLOT(setValue(int)));
    QObject::connect(drawingopt.MathmodRef->IsoObjet,
                     SIGNAL(ErrorSignal(int)), &drawingopt,
                     SLOT(MemoryErrorMsg(int)));
    QObject::connect(drawingopt.MathmodRef->ParObjet,
                     SIGNAL(ErrorSignal(int)), &drawingopt,
                     SLOT(MemoryErrorMsg(int)));
    QObject::connect(drawingopt.MathmodRef->IsoObjet,
                     SIGNAL(UpdateMessageSignal(QString)),
                     drawingopt.ui.Messagetext, SLOT(setText(QString)));
    QObject::connect(drawingopt.MathmodRef->ParObjet,
                     SIGNAL(UpdateMessageSignal(QString)),
                     drawingopt.ui.Messagetext, SLOT(setText(QString)));
    QObject::connect(drawingopt.MathmodRef->ParObjet,
                     SIGNAL(finished()), drawingopt.MathmodRef,
                     SLOT(UpdateGL()), Qt::UniqueConnection);
    QObject::connect(drawingopt.MathmodRef->IsoObjet,
                     SIGNAL(finished()), drawingopt.MathmodRef,
                     SLOT(UpdateGL()), Qt::UniqueConnection);
    drawingopt.ui.openGLWidget->LoadShadersFiles();
    drawingopt.on_choice_activated(Parameters.model);
    return app.exec();
}
