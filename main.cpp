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
#ifdef Q_WS_X11
#include <X11/Xlib.h>
#endif

int main(int argc, char *argv[])
{
    // QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
    QApplication app(argc, argv);
    Parametersoptions Parameters;
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
    mm.ui.glWidget->Xgrid = mm.ui.glWidget->Ygrid = mm.ui.glWidget->Zgrid=uint(Parameters.InitIsoGrid);
    mm.ui.glWidget->Ugrid = mm.ui.glWidget->Vgrid = uint(Parameters.InitParGrid);
    // GUI update:
    drawingopt.UpdateGui(argc);
    if (drawingopt.IsolistItemRef != nullptr)
        drawingopt.ui.ObjectClasse->expandItem(drawingopt.IsolistItemRef);
    QObject::connect(drawingopt.MathmodRef->ui.glWidget->IsoObjet->masterthread,
                     SIGNAL(mySignal(int)), drawingopt.ui.progressBar,
                     SLOT(setValue(int)));
    QObject::connect(drawingopt.MathmodRef->ui.glWidget->ParObjet->masterthread,
                     SIGNAL(mySignal(int)), drawingopt.ui.progressBar,
                     SLOT(setValue(int)));
    QObject::connect(drawingopt.MathmodRef->ui.glWidget->IsoObjet,
                     SIGNAL(ErrorSignal(int)), &drawingopt,
                     SLOT(MemoryErrorMsg(int)));
    QObject::connect(drawingopt.MathmodRef->ui.glWidget->ParObjet,
                     SIGNAL(ErrorSignal(int)), &drawingopt,
                     SLOT(MemoryErrorMsg(int)));
    QObject::connect(drawingopt.MathmodRef->ui.glWidget->IsoObjet,
                     SIGNAL(UpdateMessageSignal(QString)),
                     drawingopt.ui.Messagetext, SLOT(setText(QString)));
    QObject::connect(drawingopt.MathmodRef->ui.glWidget->ParObjet,
                     SIGNAL(UpdateMessageSignal(QString)),
                     drawingopt.ui.Messagetext, SLOT(setText(QString)));
    QObject::connect(drawingopt.MathmodRef->ui.glWidget->ParObjet,
                     SIGNAL(finished()), drawingopt.MathmodRef->ui.glWidget,
                     SLOT(UpdateGL()), Qt::UniqueConnection);
    QObject::connect(drawingopt.MathmodRef->ui.glWidget->IsoObjet,
                     SIGNAL(finished()), drawingopt.MathmodRef->ui.glWidget,
                     SLOT(UpdateGL()), Qt::UniqueConnection);
    QObject::connect(drawingopt.Parameters->ui.ApplypushButton, SIGNAL(clicked()),
                     &drawingopt, SLOT(ApplypushButton_clicked()));
    drawingopt.show();
    mm.show();
    drawingopt.raise();
    drawingopt.on_choice_activated(Parameters.model);
    return app.exec();
}
