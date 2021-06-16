/***************************************************************************
 *   Copyright (C) 2021 by Abderrahman Taha                                *
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
    // QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
    QApplication app(argc, argv);

    QSurfaceFormat fmt;
    fmt.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(fmt);
    Parametersoptions Parameters;
    Parameters.fileconfig2= app.applicationDirPath();
    Parameters.MainApp = &app;
    Parameters.LoadConfig(app, argc, argv);
    // Creation of the two most important objects:
    MathMod mm(nullptr, uint(Parameters.Threads[0]),
               uint(Parameters.InitParGrid), uint(Parameters.InitIsoGrid),
               uint(Parameters.CalculFactor[0]), uint(Parameters.CalculFactor[1]),
               uint(Parameters.CalculFactor[2]));
    DrawingOptions drawingopt;
    // save references:
    drawingopt.Parameters = &Parameters;
    drawingopt.MathmodRef = &mm;
    mm.Parent = &drawingopt;
    mm.Xgrid = mm.Ygrid = mm.Zgrid=uint(Parameters.InitIsoGrid);
    mm.Ugrid = mm.Vgrid = uint(Parameters.InitParGrid);
    // GUI update:
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
    QObject::connect(drawingopt.Parameters->ui.ApplypushButton, SIGNAL(clicked()),
                     &drawingopt, SLOT(ApplypushButton_clicked()));
    drawingopt.show();
    mm.show();
    drawingopt.raise();
    mm.LoadShadersFiles();
    drawingopt.on_choice_activated(Parameters.model);
    return app.exec();
}
