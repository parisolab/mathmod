/***************************************************************************
 *   Copyright (C) 2014 by Abderrahman Taha                                *
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
#ifndef GLVIEWER_h
#define GLVIEWER_h

#include <math.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <QGLWidget>
#include <qthread.h>
#include <QTimer>
#include <QMouseEvent>
#include <qpixmap.h>
#include <QResizeEvent>
#include <QMessageBox>

#include "../pariso/isosurface/Iso3D.h"
#include "../pariso/parametric/Model3D.h"
#include "qglthread.h"

class OpenGlWidget : public QGLWidget
{
    Q_OBJECT
public :

    int btgauche, btdroit, btmilieu, latence,
        nb_ligne, nb_colone, coupure_col, coupure_ligne,
        IDGlWindow;
    int isoline, isocolumn, isodepth,
        cpisoline, cpisocolumn, cpisodepth, TypeTriangle;
    QTimer        * timer;
    double hauteur_fenetre;
    double Axe_x, Axe_y, Axe_z, angle, val1, val2, val3, old_x, old_y, old_z;
    ObjectProperties  LocalScene;
    Iso3D *IsoObjet;
    Par3D *ParObjet;
    int TypeFormule;
    QMessageBox message;
    ErrorMessage stError;
    GLfloat oldminx, oldminy,oldminz,oldmaxx, oldmaxy, oldmaxz;

public:
    OpenGlWidget( QWidget *parent=0);
    ~OpenGlWidget();
    void initializeGL();
    void resizeGL(int, int);
    void paintGL();
    void update();
    void timerEvent( QTimerEvent * );
    void mousePressEvent( QMouseEvent *);
    void mouseMoveEvent( QMouseEvent *);
    void mouseReleaseEvent( QMouseEvent *);
    void keyPressEvent ( QKeyEvent *);
    virtual   void run();
    void valueChanged();
    void InitGlParameters();
    void boxok();
    void initbox();
    void memoryallocation(int, int, int);
    void calculateObject();
    void PutObjectInsideCube();
    void Add(ObjectParameters *);
    void screenshot();
    QImage Copyscreenshot();
public:
    GLThread glt;
    void startRendering();
    void stopRendering();
    void resizeEvent(QResizeEvent *evt);
    void closeEvent(QCloseEvent *evt);
signals:

public slots:
    void anim();
    void morph();
    void start();
    void starttimer();
    void stoptimer();
    bool timeractif();
    void restarttimer(int);
    void PrintInfos();
    void infosok();
    void FillOk();
    void axeOk();
    void normOk();
    void infosOk();
    void boxOk();
    void lineOk();
    void DrawPlan();
    void DrawGridPlan();
    void transparency(int, int currentposition=0);
    void red(int, int currentposition=0);
    void green(int, int currentposition=0);
    void blue(int, int currentposition=0);
    void transparencypar(int, int currentposition=0);
    void redpar(int, int currentposition=0);
    void greenpar(int, int currentposition=0);
    void bluepar(int, int currentposition=0);
    void transparence(bool);
    void quality(int);
    void bmp();
    void jpg();
    void png();
    void colorstype(int);
    void colorstypeParIso(int);
    void colorstypeParam(int);
    void SaveSceneAsOBJ(int);
};

#endif
