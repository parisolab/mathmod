/***************************************************************************
 *   Copyright (C) 2015 by Abderrahman Taha                                *
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

#include <QApplication>
#include <QTextStream>
#include "ui_modules/parametersoptions.h"
#include "ui_modules/drawingoptions.h"
#include "ui_modules/mathmod.h"
#include "json_parser/parisodef.h"
#ifdef Q_WS_X11
#include <X11/Xlib.h>
#endif


int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
    QApplication app(argc, argv);
    Parametersoptions Parameters;
    Parameters.MainApp = &app;
    Parameters.LoadConfig(app, argc, argv);

    //Creation of the two most important objects:
    MathMod mm(0, Parameters.MaxTri, Parameters.MaxPt, Parameters.MaxGrid);
    DrawingOptions drawingopt;

    //save references of each other:
    drawingopt.Parameters = &Parameters;
    drawingopt.MathmodRef = &mm;
    mm.Parent = &drawingopt;

    //GUI update according to the config file:
    drawingopt.UpdateGui(argc);

    mm.show();
    drawingopt.show();
    if(drawingopt.IsolistItemRef != 0)
        drawingopt.ui.ObjectClasse->expandItem(drawingopt.IsolistItemRef);
    //drawingopt.Run_JsonObject_activeted();
    return app.exec();
}
