/***************************************************************************
 *   Copyright (C) 2020 by Abderrahman Taha                                *
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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#ifndef mathmod_H
#define mathmod_H
#include "../json_parser/parisodef.h"
#include "../ui_modules/ParisoMathObject.h"
#include "ui_mathmod.h"
#include <qmessagebox.h>
class MathMod : public QWidget
{
    Q_OBJECT

public:
    MathMod(QWidget *, uint, uint initpargrid = 50, uint initisogrid = 40,
            uint factx = 4, uint facty = 4, uint factz = 4);
    ~MathMod();
    void keyPressEvent(QKeyEvent *);
    void resizeEvent(QResizeEvent *);
    void ParametricSurfaceProcess(int type = 1);
    void ParisoObjectProcess();
    void Initparametricpage();
    void updateGL();
    void updateGLspectrale(float *);
    void updateThreads(int *);
    void updateGLshininess(int);
public slots:
    void fill();
    void iso_infos();
    void draw_norm_clicked();
    void linecolumn_valueChanged(int);
    void line_valueChanged(int);
    void column_valueChanged(int);
    void linecolumn_valueChanged_2(int);
    void linecolumn_valueupdate(int);
    void line_valueupdate(int);
    void column_valueupdate(int);
    void ProcessNewIsoSurface();
    void ProcessParisoSurface();
    void xyzg_valueChanged(int);
    void xyzg_valueupdate(int);
    void slot_checkBox73_clicked();
    void slot_uv_clicked();
    void slot_uv4D_clicked();
    void smoothline();
    void Mesh();
    void slot_triangles_clicked();
    int ParseIso();
    int ParsePar();
    void ShowErrormessage();
    void frames_clicked();

public:
    Ui::MathMod ui;
    int xyzactivated, isomesh, uvactivated, uvactivated4D;
    ParisoMathObject RootObjet;
    jcollection collection;
    QWidget *Parent;
    QMessageBox message;
    ErrorMessage stError;
};

#endif
