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
#include <QOpenGLFunctions>
#include <QLabel>
#include <QVector3D>
#include <QQuaternion>
#include <QMatrix4x4>
#include <QPainter>

class MathMod : public QOpenGLWidget, protected QOpenGLFunctions
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
    QLabel LabelInfos;
    QString labelinfos;
    int FistTimecalibrate = -1;
    double hauteur_fenetre,difMaximum,decalage_xo,decalage_yo,decalage_zo;
    GLfloat minx, miny, minz,maxx, maxy, maxz;
    GLfloat oldminx, oldminy, oldminz,oldmaxx,oldmaxy,oldmaxz;
    GLfloat difX, difY, difZ;
    uint CubeStartIndex=0, PlanStartIndex=0, AxesStartIndex=0;
    uint XStartIndex=0, YStartIndex=0, ZStartIndex=0,
    XletterIndex=0,YletterIndex=0,ZletterIndex=0;
    float wh=0.57;
    GLfloat AxeArray[3*36]={5.0f*wh/4.0f, 0.0, 0.0,0.0, 0.0, 0.0,
                                  0.0, 5.0f*wh/4.0f, 0.0,0.0, 0.0, 0.0,
                                  0.0, 0.0, 5.0f*wh/4.0f,0.0, 0.0, 0.0,
                                  5.0f*wh/4.0f, 0.0, 0.0, 95.0f*wh/80.0f, 95.0f*wh/4000.0f, 0.0,
                                  95.0f*wh/80.0f, 0.0,  95.0f*wh/4000.0f,95.0f*wh/80.0f, -95.0f*wh/4000.0f, 0.0,
                                  95.0f*wh/80.0f, 0.0,  -95.0f*wh/4000.0f,95.0f*wh/80.0f, 95.0f*wh/4000.0f, 0.0,
                                   0.0, 5.0f*wh/4.0f, 0.0,95.0f*wh/4000.0f, 95.0f*wh/80.0f, 0.0,
                                   0.0, 95.0f*wh/80.0f, 95.0f*wh/4000.0f,-95.0f*wh/4000.0f, 95.0f*wh/80.0f, 0.0,
                                   0.0, 95.0f*wh/80.0f, -95.0f*wh/4000.0f,95.0f*wh/4000.0f, 95.0f*wh/80.0f, 0.0,
                                   0.0, 0.0, 5.0f*wh/4.0f,95.0f*wh/4000.0f, 0.0, 95.0f*wh/80.0f,
                                   0.0, 95.0f*wh/4000.0f, 95.0f*wh/80.0f,-95.0f*wh/4000.0f, 0.0, 95.0f*wh/80.0f,
                                   0.0, -95.0f*wh/4000.0f, 95.0f*wh/80.0f,95.0f*wh/4000.0f, 0.0, 95.0f*wh/80.0f,
                                   5.0f*wh/4.0f + (2.5f)*95.0f*wh/4000.0f, 0.0f, -95.0f*wh/4000.0f, 5.0f*wh/4.0f + (1.5f)*95.0f*wh/4000.0f, 0.0f, 95.0f*wh/4000.0f,
                                   5.0f*wh/4.0f + (2.5f)*95.0f*wh/4000.0f, 0.0f, 95.0f*wh/4000.0f, 5.0f*wh/4.0f + (1.5f)*95.0f*wh/4000.0f, 0.0f, -95.0f*wh/4000.0f,
                                   0.0f, 5.0f*wh/4.0f + (2.5f)*95.0f*wh/4000.0f, 95.0f*wh/4000.0f, 0.0f, 5.0f*wh/4.0f + (1.5f)*95.0f*wh/4000.0f, -95.0f*wh/4000.0f,
                                   0.0f, 5.0f*wh/4.0f + (2.0f)*95.0f*wh/4000.0f, 0.0f, 0.0f, 5.0f*wh/4.0f + (1.5f)*95.0f*wh/4000.0f, 95.0f*wh/4000.0f,
                                   60.0f*wh/4000.0f, -60.0f*wh/4000.0f, 5.0f*wh/4.0f + (2.5f)*95.0f*wh/4000.0f, -60.0f*wh/4000.0f, 60.0f*wh/4000.0f, 5.0f*wh/4.0f + (2.5f)*95.0f*wh/4000.0f,
                                   60.0f*wh/4000.0f, -60.0f*wh/4000.0f, 5.0f*wh/4.0f + (1.5f)*95.0f*wh/4000.0f, -60.0f*wh/4000.0f, 60.0f*wh/4000.0f, 5.0f*wh/4.0f + (1.5f)*95.0f*wh/4000.0f
                                  };
    GLfloat PlanArray[3*60]=
    {
        -(4*wh/3)/4, (4*wh/3), -(5*wh/4),
        -(4*wh/3)/4, -(4*wh/3), -(5*wh/4),
        0.0, (4*wh/3), -(5*wh/4),
        0.0, -(4*wh/3), -(5*wh/4),
        (4*wh/3)/4, (4*wh/3), -(5*wh/4),
        (4*wh/3)/4, -(4*wh/3), -(5*wh/4),
        (4*wh/3), -(4*wh/3)/4, -(5*wh/4),
        -(4*wh/3), -(4*wh/3)/4, -(5*wh/4),
        (4*wh/3), 0.0, -(5*wh/4),
        -(4*wh/3), 0.0, -(5*wh/4),
        (4*wh/3), (4*wh/3)/4, -(5*wh/4),
        -(4*wh/3), (4*wh/3)/4, -(5*wh/4),
        -(4*wh/3)/8, (4*wh/3), -(5*wh/4),
        -(4*wh/3)/8, -(4*wh/3), -(5*wh/4),
        -3*(4*wh/3)/8, (4*wh/3), -(5*wh/4),
        -3*(4*wh/3)/8, -(4*wh/3), -(5*wh/4),
        -(4*wh/3)/2, (4*wh/3), -(5*wh/4),
        -(4*wh/3)/2, -(4*wh/3), -(5*wh/4),
        -5*(4*wh/3)/8, (4*wh/3), -(5*wh/4),
        -5*(4*wh/3)/8, -(4*wh/3), -(5*wh/4),
        -3*(4*wh/3)/4, (4*wh/3), -(5*wh/4),
        -3*(4*wh/3)/4, -(4*wh/3), -(5*wh/4),
        -7*(4*wh/3)/8, (4*wh/3), -(5*wh/4),
        -7*(4*wh/3)/8, -(4*wh/3), -(5*wh/4),
        (4*wh/3)/8, (4*wh/3), -(5*wh/4),
        (4*wh/3)/8, -(4*wh/3), -(5*wh/4),
        3*(4*wh/3)/8, (4*wh/3), -(5*wh/4),
        3*(4*wh/3)/8, -(4*wh/3), -(5*wh/4),
        (4*wh/3)/2, (4*wh/3), -(5*wh/4),
        (4*wh/3)/2, -(4*wh/3), -(5*wh/4),
        5*(4*wh/3)/8, (4*wh/3), -(5*wh/4),
        5*(4*wh/3)/8, -(4*wh/3), -(5*wh/4),
        3*(4*wh/3)/4, (4*wh/3), -(5*wh/4),
        3*(4*wh/3)/4, -(4*wh/3), -(5*wh/4),
        7*(4*wh/3)/8, (4*wh/3), -(5*wh/4),
        7*(4*wh/3)/8, -(4*wh/3), -(5*wh/4),
        (4*wh/3), -(4*wh/3)/8, -(5*wh/4),
        -(4*wh/3), -(4*wh/3)/8, -(5*wh/4),
        (4*wh/3), -3*(4*wh/3)/8, -(5*wh/4),
        -(4*wh/3), -3*(4*wh/3)/8, -(5*wh/4),
        (4*wh/3), -(4*wh/3)/2, -(5*wh/4),
        -(4*wh/3), -(4*wh/3)/2, -(5*wh/4),
        (4*wh/3), -5*(4*wh/3)/8, -(5*wh/4),
        -(4*wh/3), -5*(4*wh/3)/8, -(5*wh/4),
        (4*wh/3), -3*(4*wh/3)/4, -(5*wh/4),
        -(4*wh/3), -3*(4*wh/3)/4, -(5*wh/4),
        (4*wh/3), -7*(4*wh/3)/8, -(5*wh/4),
        -(4*wh/3), -7*(4*wh/3)/8, -(5*wh/4),
        (4*wh/3), (4*wh/3)/8, -(5*wh/4),
        -(4*wh/3), (4*wh/3)/8, -(5*wh/4),
        (4*wh/3), 3*(4*wh/3)/8, -(5*wh/4),
        -(4*wh/3), 3*(4*wh/3)/8, -(5*wh/4),
        (4*wh/3), (4*wh/3)/2, -(5*wh/4),
        -(4*wh/3), (4*wh/3)/2, -(5*wh/4),
        (4*wh/3), 5*(4*wh/3)/8, -(5*wh/4),
        -(4*wh/3), 5*(4*wh/3)/8, -(5*wh/4),
        (4*wh/3), 3*(4*wh/3)/4, -(5*wh/4),
        -(4*wh/3), 3*(4*wh/3)/4, -(5*wh/4),
        (4*wh/3), 7*(4*wh/3)/8, -(5*wh/4),
        -(4*wh/3), 7*(4*wh/3)/8, -(5*wh/4)
    };
    bool PutObjectInsideCubeOk=false;
    GLuint vbo[2];
    float gridcol[4]  ={0.4f, 0.4f, 0.4f, 0.9f};
    float lightPosition[4] = {0, 0, 10, 0};
    float lightAmbient[4]  = {0.5f, 0.5f, 0.5f, 1.0f};//{0.4f, 0.4f, 0.4f, 0.1};
    float lightDiffuse[4]  = {0.8f, 0.8f, 0.8f, 1.0};
    float lightSpecular[4] = {0.5f, 0.5f, 0.5f, 0.1f};//{0.4f, 0.4f, 0.4f, 0.1};
    float frontColor[4] = {0.72f, 0.5f, 0.1, 1};
    float backColor[4]  = {0.1f, 0.7f, 0.2f, 1};
    int shininessVal=20;
    int screenWidth=100;
    int screenHeight=100;
    bool mouseLeftDown=false;
    bool mouseRightDown=false;
    float mouseY=0;
    float cameraDistance=1.4f;
    bool vboSupported, vboUsed;
    QMatrix4x4 matrixProjectionx;
    GLuint shaderprogramId = 0;
    bool glslSupported;
    GLint uniformFrontColor;
    GLint uniformBackColor;
    GLint uniformGridColor;
    GLint uniformThereisRGBA;
    GLfloat uniformShininess;
    GLint uniformdrawgridColor;
    GLint uniformMatrixModelView;
    GLint uniformMatrixModelViewProjection;
    GLint uniformMatrixNormal;
    GLint uniformLightPosition;
    GLint uniformLightAmbient;
    GLint uniformLightDiffuse;
    GLint uniformLightSpecular;
    GLint attribVertexPosition;
    GLint attribVertexNormal;
    GLint attribVertexColor;
    GLint attribVertexTexCoord;
    QVector2D mousePressPosition;
    qreal angularSpeed = 0;
    QMatrix4x4 matrixViewx;
    QQuaternion rotation= QQuaternion::fromAxisAndAngle(QVector3D(1.0,0.0,0.0), 270)*
            QQuaternion::fromAxisAndAngle(QVector3D(0.0,0.0,1.0), 225)*
            QQuaternion::fromAxisAndAngle(QVector3D(1.0,-1.0,0.0), -29);
    QQuaternion rotationx;
    QQuaternion rotationy;
    QQuaternion rotationz;
    QQuaternion oldRotation= rotation;
    QMatrix4x4 matrixModelViewProjectionx;
    QMatrix4x4 matrixNormalx;
    qreal acc;
    QVector3D n;
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
    void attachinfos();
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
    void Mesh();
    void slot_triangles_clicked();
    int ParseIso();
    int ParsePar();
    void ShowErrormessage();
    void frames_clicked();
    void CreateShaderProgram();
    void draw(ObjectProperties *);
    void plan();
    void CopyData(ObjectProperties *);
    void DrawMinimalTopology(ObjectProperties *);
    void DrawMeshIso(ObjectProperties *);
    void DrawParisoCND(ObjectProperties *, uint);
    void DrawNormals(ObjectProperties *);
    void DrawAxe();
    void proj();
    void DrawPariso(ObjectProperties *, uint);
    void drawCube();
    void initializeGL() override;
    void Winitialize_GL();
    void resizeGL(int, int) override;
    void paintGL()  override;
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
    void moveEvent(QMoveEvent *) override;
    void closeEvent(QCloseEvent *) override;
public slots:
    void anim();
    void morph();
    void starttimer();
    void stoptimer();
    bool timeractif();
    void restarttimer(int);
    void FillOk();
    void normOk();
    void boundingboxOk();
    void transparency(int, int currentposition = 0);
    void red(int, int currentposition = 0);
    void green(int, int currentposition = 0);
    void blue(int, int currentposition = 0);
    void redSpec(int);
    void greenSpec(int);
    void blueSpec(int);
    void transSpec(int);
    void redAmb(int);
    void greenAmb(int);
    void blueAmb(int);
    void transAmb(int);
    void redDiff(int);
    void greenDiff(int);
    void blueDiff(int);
    void transDiff(int);
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
