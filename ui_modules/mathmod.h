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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#ifndef mathmod_H
#define mathmod_H
#include "../pariso/isosurface/Iso3D.h"
#include "../pariso/parametric/Model3D.h"
#include <QFileDialog>
#include <QOpenGLWidget>
#include <QMessageBox>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QTextStream>
#include <QTimer>
#include <iostream>
#include <math.h>
#include <qpixmap.h>
#include <qthread.h>
#include <stdlib.h>
#include <string>
#include "../json_parser/parisodef.h"
#include "../ui_modules/ParisoMathObject.h"
#include <QMessageBox>
#include <QOpenGLWidget>

class MathMod : public QOpenGLWidget
{
    Q_OBJECT
public:
    uint Ugrid, Vgrid, CutV, CutU;
    int btgauche, btdroit, btmilieu, latence;
    int Xgrid, Ygrid, Zgrid, CutX, CutY, CutZ, TypeTriangle;
    QBasicTimer *timer;
    double factx=1.0, facty=1.0, factz=1.0;
    ObjectProperties LocalScene;
    QString FramesDir;
    Iso3D *IsoObjet;
    Par3D *ParObjet;
    int TypeFormule;
    QMessageBox message;
    ErrorMessage stError;
    ImprovedNoise *PerlinNoise;


    int xyzactivated, isomesh, uvactivated, uvactivated4D;
    ParisoMathObject RootObjet;
    jcollection collection;
    QWidget *Parent;



public:
    MathMod(QWidget *, uint, uint initpargrid = 50, uint initisogrid = 40,
            uint factx = 4, uint facty = 4, uint factz = 4);
    ~MathMod();
    void ParametricSurfaceProcess(int type = 1);
    void ParisoObjectProcess();
    void Initparametricpage();
    void updateGL();
public slots:
    void fill();
    void iso_infos();
    void draw_norm_clicked();
    void linecolumn_valueChanged(int, ModelType type=PAR_TYPE);
    void line_valueChanged(int);
    void column_valueChanged(int);
    void linecolumn_valueChanged_2(int);
    void linecolumn_valueupdate(int);
    void line_valueupdate(int);
    void column_valueupdate(int);
    void ProcessNewIsoSurface();
    void xyzg_valueChanged(int, ModelType);
    void xyzg_valueupdate(int);
    void slot_checkBox73_clicked(ModelType type=ISO_TYPE);
    void slot_uv_clicked(ModelType type=PAR_TYPE);
    void slot_uv4D_clicked();
    void smoothline();
    void Mesh();
    void slot_triangles_clicked();
    int ParseIso();
    int ParsePar();
    void ShowErrormessage();
    void frames_clicked();

    void Winitialize_GL();
    void resizeGL(int, int) override;
    void paintGL()  override;
    void copydata();
    void timerEvent(QTimerEvent *)  override;
    void mousePressEvent(QMouseEvent *)  override;
    void mouseMoveEvent(QMouseEvent *)  override;
    void mouseReleaseEvent(QMouseEvent *)  override;
    void keyPressEvent(QKeyEvent *)  override;
    virtual void run();
    void InitSpecularParameters();
    void Shininess(int);
    int memoryallocation(uint, uint initpargrid = 50, uint initgrid = 40,
                         uint factx = 4, uint facty = 4, uint factz = 4);
    void PutObjectInsideCube();
    void screenshot();
    void FramesShot();
    void FramesSave();
    QImage Copyscreenshot();
public slots:
    void anim();
    void morph();
    void starttimer();
    void stoptimer();
    bool timeractif();
    void restarttimer(int);
    void PrintInfos();
    void infosok();
    void FillOk();
    void normOk();
    void infosOk();
    void boundingboxOk();
    void transparency(int, int currentposition = 0);
    void red(int, int currentposition = 0);
    void green(int, int currentposition = 0);
    void blue(int, int currentposition = 0);
    void transparence(bool);
    void redSpec(int);
    void greenSpec(int);
    void blueSpec(int);
    void transSpec(int);
    void quality(int);
    void bmp();
    void jpg();
    void png();
    void colorstype(int);
    void colorstypeParIso(int);
    void colorstypeParam(int);
    void SaveSceneAsObjPoly(int n = 0);
    void SaveSceneAsObjTrian(int n = 0);
    void CalculateTexturePoints(int type);
    void CalculatePigmentPoints(int type);
    void LoadShadersFiles();
    void UpdateGL();
};

#endif
