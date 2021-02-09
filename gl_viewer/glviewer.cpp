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
#include "glviewer.h"
#include <QVector3D>
#include <QQuaternion>
#include <QMatrix4x4>

#define BUFFER_OFFSET(i) ((float *)(i))

QVector2D mousePressPosition;
QVector3D rotationAxis;
qreal angularSpeed = 0;
QQuaternion rotation;
QQuaternion oldRotation;
qreal acc;
//Matrix4 matrixView2;
QVector3D n;
//Matrix4 matrixRotView;
static int FistTimecalibrate = -1;
static double hauteur_fenetre, difMaximum, decalage_xo, decalage_yo,
       decalage_zo;
static GLfloat minx = 999999999.0, miny = 999999999.0, minz = 999999999.0,
               maxx = -999999999.0, maxy = -999999999.0, maxz = -999999999.0;
static GLfloat difX, difY, difZ;
static uint CubeStartIndex=0, PlanStartIndex=0, AxesStartIndex=0;
static uint XStartIndex=0, YStartIndex=0, ZStartIndex=0;
/* This is a handle to the shader program */
//GLuint shaderprogramId;
/* These pointers will receive the contents of our shader source code files */
QString vertexsource, fragmentsource;
/* These are handles used to reference the shaders */
GLuint vertexshader, fragmentshader;
float wh=0.6;
static bool PutObjectInsideCubeOk=false;
#include<string>
#include<iostream>
#include <fstream>


int IsCompiled_VS, IsCompiled_FS;
    int IsLinked;
    int maxLength;
char *vertexInfoLog;
char *fragmentInfoLog;
char *shaderProgramInfoLog;

// constants
const int   SCREEN_WIDTH    = 600;
const int   SCREEN_HEIGHT   = 600;
const float CAMERA_DISTANCE = 1.4f;
int screenWidth;
int screenHeight;
bool mouseLeftDown;
bool mouseRightDown;
float mouseY;
float cameraDistance;
bool vboSupported, vboUsed;
int drawMode = 0;
QMatrix4x4 matrixProjectionx;
// GLSL
GLuint shaderprogramId = 0;                  // ID of GLSL program
bool glslSupported;

GLint uniformFrontColor;
GLint uniformBackColor;
GLint uniformGridColor;
GLint uniformThereisRGBA;
GLint uniformdrawgridColor;

GLint uniformMatrixModelView;
GLint uniformMatrixModelViewProjection;
GLint uniformMatrixNormal;
GLint uniformLightPosition;
GLint uniformLightAmbient;
GLint uniformLightDiffuse;
GLint uniformLightSpecular;
GLint uniformMap0;
GLint attribVertexPosition;
GLint attribVertexNormal;
GLint attribVertexColor;
GLint attribVertexTexCoord;
float gridcol[4]  ={0.4f, 0.4f, 0.4f, 0.9f};
static GLfloat AxeArray[3*24]={5.0f*wh/4.0f, 0.0, 0.0,0.0, 0.0, 0.0,
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
                               0.0, -95.0f*wh/4000.0f, 95.0f*wh/80.0f,95.0f*wh/4000.0f, 0.0, 95.0f*wh/80.0f
                              };

static GLfloat PlanArray[3*60]=
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

void OpenGlWidget::CalculateTexturePoints(int type)
{
    double tmp, val[6]={0,0,0,0,0,0};
    uint Jprime;
    if (type == 1)
    {
        LocalScene.componentsinfos.ThereisRGBA[0] = true;
        LocalScene.componentsinfos.NoiseParam[0].NoiseType = 1;
        LocalScene.componentsinfos.NoiseParam[0].RgbtParser =
            IsoObjet->masterthread->RgbtParser;
        LocalScene.componentsinfos.NoiseParam[0].NoiseParser =
            IsoObjet->masterthread->NoiseParser;
        IsoObjet->masterthread->Noise == ""
        ? LocalScene.componentsinfos.NoiseParam[0].NoiseShape = 0
                : LocalScene.componentsinfos.NoiseParam[0].NoiseShape = 1;
    }
    if (type == 0)
    {
        LocalScene.componentsinfos.ThereisRGBA[0] = true;
        LocalScene.componentsinfos.NoiseParam[0].NoiseType = 1;
        LocalScene.componentsinfos.NoiseParam[0].RgbtParser =
            ParObjet->masterthread->RgbtParser;
        LocalScene.componentsinfos.NoiseParam[0].NoiseParser =
            ParObjet->masterthread->NoiseParser;
        ParObjet->masterthread->Noise == ""
        ? LocalScene.componentsinfos.NoiseParam[0].NoiseShape = 0
                : LocalScene.componentsinfos.NoiseParam[0].NoiseShape = 1;
    }
    for (uint i = 0; i < LocalScene.VertxNumber; i++)
    {
        val[0] = difMaximum *
                 double(LocalScene.ArrayNorVer_localPt[i * 10 + 7]) /
                 hauteur_fenetre -
                 decalage_xo;
        val[1] = difMaximum *
                 double(LocalScene.ArrayNorVer_localPt[i * 10 + 8]) /
                 hauteur_fenetre -
                 decalage_yo;
        val[2] = difMaximum *
                 double(LocalScene.ArrayNorVer_localPt[i * 10 + 9]) /
                 hauteur_fenetre -
                 decalage_zo;
        if (type != 1)
        {
            Jprime = (i) % (ParObjet->Vgrid);
            val[3] = double(Jprime) / double(ParObjet->Vgrid);
            val[3] = val[3] * ParObjet->masterthread->dif_u[0] +
                     ParObjet->masterthread->u_inf[0];
            Jprime = (i) / (ParObjet->Ugrid);
            val[4] = double(Jprime) / double(ParObjet->Ugrid);
            val[4] = val[4] * ParObjet->masterthread->dif_v[0] +
                     ParObjet->masterthread->v_inf[0];
        }
        if (LocalScene.componentsinfos.NoiseParam[0].NoiseShape != 0)
        {
            tmp = LocalScene.componentsinfos.NoiseParam[0].NoiseParser->Eval(val);
        }
        else
        {
            tmp = 1.0;
        }
        val[0] *= tmp;
        val[1] *= tmp;
        val[2] *= tmp;
        // val[3] and val[4] uninitialized!
        val[3] *= tmp;
        val[4] *= tmp;
        LocalScene.ArrayNorVer_localPt[i * 10] =
            float(LocalScene.componentsinfos.NoiseParam[0].RgbtParser[0].Eval(val));
        LocalScene.ArrayNorVer_localPt[i * 10 + 1] =
            float(LocalScene.componentsinfos.NoiseParam[0].RgbtParser[1].Eval(val));
        LocalScene.ArrayNorVer_localPt[i * 10 + 2] =
            float(LocalScene.componentsinfos.NoiseParam[0].RgbtParser[2].Eval(val));
        LocalScene.ArrayNorVer_localPt[i * 10 + 3] =
            float(LocalScene.componentsinfos.NoiseParam[0].RgbtParser[3].Eval(val));
    }
}

void OpenGlWidget::CalculatePigmentPoints(int type)
{
    double tmp, ValCol[100], val[4];
    if (type == 1)
    {
        LocalScene.componentsinfos.ThereisRGBA[0] = true;
        LocalScene.componentsinfos.NoiseParam[0].NoiseType = 0; // Pigments
        LocalScene.componentsinfos.NoiseParam[0].VRgbtParser =
            IsoObjet->masterthread->VRgbtParser;
        LocalScene.componentsinfos.NoiseParam[0].GradientParser =
            IsoObjet->masterthread->GradientParser;
        LocalScene.componentsinfos.NoiseParam[0].Nb_vrgbts =
            IsoObjet->masterthread->VRgbtSize;
        LocalScene.componentsinfos.NoiseParam[0].NoiseParser =
            IsoObjet->masterthread->NoiseParser;
        IsoObjet->masterthread->Noise == ""
        ? LocalScene.componentsinfos.NoiseParam[0].NoiseShape = 0
                : LocalScene.componentsinfos.NoiseParam[0].NoiseShape = 1;
    }
    if (type == 0)
    {
        LocalScene.componentsinfos.ThereisRGBA[0] = true;
        LocalScene.componentsinfos.NoiseParam[0].NoiseType = 0; // Pigments
        LocalScene.componentsinfos.NoiseParam[0].VRgbtParser =
            ParObjet->masterthread->VRgbtParser;
        LocalScene.componentsinfos.NoiseParam[0].GradientParser =
            ParObjet->masterthread->GradientParser;
        LocalScene.componentsinfos.NoiseParam[0].Nb_vrgbts =
            ParObjet->masterthread->VRgbtSize;
        LocalScene.componentsinfos.NoiseParam[0].NoiseParser =
            ParObjet->masterthread->NoiseParser;
        ParObjet->masterthread->Noise == ""
        ? LocalScene.componentsinfos.NoiseParam[0].NoiseShape = 0
                : LocalScene.componentsinfos.NoiseParam[0].NoiseShape = 1;
    }
    for (uint i = 0;
            i < LocalScene.componentsinfos.NoiseParam[0].Nb_vrgbts && i < 100; i++)
    {
        ValCol[i] =
            LocalScene.componentsinfos.NoiseParam[0].VRgbtParser[i].Eval(val);
    }
    for (uint i = 0; i < LocalScene.VertxNumber; i++)
    {
        val[0] = difMaximum *
                 double(LocalScene.ArrayNorVer_localPt[i * 10 + 7]) /
                 hauteur_fenetre -
                 decalage_xo;
        val[1] = difMaximum *
                 double(LocalScene.ArrayNorVer_localPt[i * 10 + 8]) /
                 hauteur_fenetre -
                 decalage_yo;
        val[2] = difMaximum *
                 double(LocalScene.ArrayNorVer_localPt[i * 10 + 9]) /
                 hauteur_fenetre -
                 decalage_zo;
        if (LocalScene.componentsinfos.NoiseParam[0].NoiseShape != 0)
            tmp = LocalScene.componentsinfos.NoiseParam[0].NoiseParser->Eval(val);
        else
            tmp = 1.0;
        val[0] *= tmp;
        val[1] *= tmp;
        val[2] *= tmp;
        tmp = LocalScene.componentsinfos.NoiseParam[0].GradientParser->Eval(val);
        int c = int(tmp);
        tmp = std::abs(tmp - double(c));
        for (uint j = 0;
                j < LocalScene.componentsinfos.NoiseParam[0].Nb_vrgbts && j < 100;
                j += 5)
            if (tmp <= ValCol[j])
            {
                LocalScene.ArrayNorVer_localPt[i*10  ] = float(ValCol[j+1]);
                LocalScene.ArrayNorVer_localPt[i*10+1] = float(ValCol[j+2]);
                LocalScene.ArrayNorVer_localPt[i*10+2] = float(ValCol[j+3]);
                LocalScene.ArrayNorVer_localPt[i*10+3] = float(ValCol[j+4]);
                j = 100;
            }
    }
}

int OpenGlWidget::memoryallocation(uint nbthreads,
                                   uint initparGrid, uint initisoGrid,
                                   uint FactX, uint FactY, uint FactZ)
{
    try
    {
        IsoObjet = new Iso3D(nbthreads, initisoGrid, FactX, FactY, FactZ);
        ParObjet = new Par3D(nbthreads, initparGrid);
        return 1;
    }
    catch (std::bad_alloc &)
    {
        message.setText("Not enough memory available to complete this operation");
        message.adjustSize();
        message.exec();
        return -1;
    }
}

void OpenGlWidget::SaveSceneAsObjPoly(int type)
{
    int startpl = 0;
    uint actualpointindice;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save OBJ file"), "",
                       tr("OBJ Files (*.obj)"));

    QFile data(fileName);
    if (data.open(QFile::ReadWrite | QFile::Truncate))
    {
        uint i;
        QTextStream stream(&data);
        stream.setRealNumberNotation(QTextStream::FixedNotation);
        stream.setRealNumberPrecision(3);
        // save vertices:
        if (type == 1)
        {
            for (i = 0; i < LocalScene.VertxNumber; i++)
            {
                (stream) << "v "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 7]) *
                                  (difMaximum*factx/ hauteur_fenetre) -
                                  decalage_xo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 8]) *
                                  (difMaximum*facty / hauteur_fenetre) -
                                  decalage_yo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 9]) *
                                  (difMaximum*factz / hauteur_fenetre) -
                                  decalage_zo)
                         << "  " << LocalScene.ArrayNorVer_localPt[10 * i] << "  "
                         << LocalScene.ArrayNorVer_localPt[10 * i + 1] << "  "
                         << LocalScene.ArrayNorVer_localPt[10 * i + 2] << "\n";
            }
        }
        else
        {
            for (i = 0; i < LocalScene.VertxNumber; i++)
            {
                (stream) << "v "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 7]) *
                                  (difMaximum*factx / hauteur_fenetre) -
                                  decalage_xo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 8]) *
                                  (difMaximum*facty / hauteur_fenetre) -
                                  decalage_yo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 9]) *
                                  (difMaximum*factz / hauteur_fenetre) -
                                  decalage_zo)
                         << "\n";
            }
        }
        // save faces:
        for (i = 0; i < LocalScene.NbPolygnNbVertexPtMin; i++)
        {
            uint polysize = LocalScene.PolyIndices_localPtMin[startpl++];
            (stream) << "f";
            for (uint j = 0; j < polysize; j++)
            {
                actualpointindice = LocalScene.PolyIndices_localPtMin[startpl] + 1;
                (stream) << "  " << actualpointindice;
                startpl++;
            }
            (stream) << "\n";
            i += polysize;
        }
    }
}

void OpenGlWidget::SaveSceneAsObjTrian(int type)
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save OBJ file"), "",
                       tr("OBJ Files (*.obj)"));
    QFile data(fileName);
    if (data.open(QFile::ReadWrite | QFile::Truncate))
    {
        uint i;
        QTextStream stream(&data);
        stream.setRealNumberNotation(QTextStream::FixedNotation);
        stream.setRealNumberPrecision(3);
        // save vertices:
        if (type == 1)
        {
            for (i = 0; i < LocalScene.VertxNumber; i++)
            {
                (stream) << "v "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 7]) *
                                  (difMaximum*factx / hauteur_fenetre) -
                                  decalage_xo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 8]) *
                                  (difMaximum*facty / hauteur_fenetre) -
                                  decalage_yo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 9]) *
                                  (difMaximum*factz / hauteur_fenetre) -
                                  decalage_zo)
                         << "  " << LocalScene.ArrayNorVer_localPt[10 * i] << "  "
                         << LocalScene.ArrayNorVer_localPt[10 * i + 1] << "  "
                         << LocalScene.ArrayNorVer_localPt[10 * i + 2] << "\n";
            }
        }
        else
        {
            for (i = 0; i < LocalScene.VertxNumber; i++)
            {
                (stream) << "v "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 7]) *
                                  (difMaximum*factx / hauteur_fenetre) -
                                  decalage_xo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 8]) *
                                  (difMaximum*facty / hauteur_fenetre) -
                                  decalage_yo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 9]) *
                                  (difMaximum*factz / hauteur_fenetre) -
                                  decalage_zo)
                         << "\n";
            }
        }
        for (i = 0; i < LocalScene.PolyNumber; i += 3)
        {
            (stream) << "f "
                     << "  " << LocalScene.PolyIndices_localPt[i] + 1 << "  "
                     << LocalScene.PolyIndices_localPt[i + 1] + 1 << "  "
                     << LocalScene.PolyIndices_localPt[i + 2] + 1 << "\n";
        }
    }
}

OpenGlWidget::~OpenGlWidget()
{
    delete (timer);
    delete ParObjet;
    delete IsoObjet;
}

void OpenGlWidget::deleteVBO() {}
void OpenGlWidget::initbox()
{
    oldminx = 999999999.0;
    oldminy = 999999999.0;
    oldminz = 999999999.0;
    oldmaxx = -999999999.0;
    oldmaxy = -999999999.0;
    oldmaxz = -999999999.0;
}

void OpenGlWidget::PutObjectInsideCube()
{
    minx = 999999999.0;
    miny = 999999999.0;
    minz = 999999999.0;
    maxx = -999999999.0;
    maxy = -999999999.0;
    maxz = -999999999.0;
    if ((LocalScene.morph != 1 ||
            (LocalScene.morph == 1 && FistTimecalibrate == 1)) &&
            LocalScene.slider != 1)
    {
        for (uint i = 0; i < LocalScene.VertxNumber; i++)
        {
            if (minx > LocalScene.ArrayNorVer_localPt[10 * i + 3 + 4])
                minx = LocalScene.ArrayNorVer_localPt[10 * i + 3 + 4];
            if (miny > LocalScene.ArrayNorVer_localPt[10 * i + 4 + 4])
                miny = LocalScene.ArrayNorVer_localPt[10 * i + 4 + 4];
            if (minz > LocalScene.ArrayNorVer_localPt[10 * i + 5 + 4])
                minz = LocalScene.ArrayNorVer_localPt[10 * i + 5 + 4];

            if (maxx < LocalScene.ArrayNorVer_localPt[10 * i + 3 + 4])
                maxx = LocalScene.ArrayNorVer_localPt[10 * i + 3 + 4];
            if (maxy < LocalScene.ArrayNorVer_localPt[10 * i + 4 + 4])
                maxy = LocalScene.ArrayNorVer_localPt[10 * i + 4 + 4];
            if (maxz < LocalScene.ArrayNorVer_localPt[10 * i + 5 + 4])
                maxz = LocalScene.ArrayNorVer_localPt[10 * i + 5 + 4];
        }
        FistTimecalibrate = -1;
        difX = maxx - minx;
        difY = maxy - miny;
        difZ = maxz - minz;
        // Recherche du maximum :
        difMaximum = double(difX);
        if (difY > float(difMaximum))
        {
            difMaximum = double(difY);
        }
        if (difZ > float(difMaximum))
        {
            difMaximum = double(difZ);
        }
        /// On va inclure cet objet dans un cube de langueur maximum
        /// egale a "hauteur_fenetre"
        decalage_xo = -double(minx + maxx) / 2;
        decalage_yo = -double(miny + maxy) / 2;
        decalage_zo = -double(minz + maxz) / 2;
    }
    for (uint i = 0; i < LocalScene.VertxNumber; i++)
    {
        LocalScene.ArrayNorVer_localPt[10 * i + 7] = float(
                    hauteur_fenetre *
                    (double(LocalScene.ArrayNorVer_localPt[10 * i + 7]) + decalage_xo) /
                    difMaximum);
        LocalScene.ArrayNorVer_localPt[10 * i + 8] = float(
                    hauteur_fenetre *
                    (double(LocalScene.ArrayNorVer_localPt[10 * i + 8]) + decalage_yo) /
                    difMaximum);
        LocalScene.ArrayNorVer_localPt[10 * i + 9] = float(
                    hauteur_fenetre *
                    (double(LocalScene.ArrayNorVer_localPt[10 * i + 9]) + decalage_zo) /
                    difMaximum);
    }

    // Cube vertices and indexes
    float longX = wh * float(difX / float(difMaximum)),
          longY = wh * (difY / float(difMaximum)),
          longZ = wh * (difZ / float(difMaximum));
    uint NbVert = LocalScene.VertxNumber;
    CubeStartIndex=NbVert;
    for(uint id=0; id<12; id++)
    {
        LocalScene.ArrayNorVer_localPt[10 * (NbVert+id) + 0] = 0.8f;
        LocalScene.ArrayNorVer_localPt[10 * (NbVert+id) + 1] = 0.0f;
        LocalScene.ArrayNorVer_localPt[10 * (NbVert+id) + 2] = 0.0f;
        LocalScene.ArrayNorVer_localPt[10 * (NbVert+id) + 3] = 1.0f;
    }

    LocalScene.ArrayNorVer_localPt[10 * NbVert + 7] = -longX;
    LocalScene.ArrayNorVer_localPt[10 * NbVert + 8] = -longY;
    LocalScene.ArrayNorVer_localPt[10 * NbVert + 9] = -longZ;

    LocalScene.ArrayNorVer_localPt[10 * (NbVert+1) + 7] =  longX;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+1) + 8] = -longY;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+1) + 9] = -longZ;

    LocalScene.ArrayNorVer_localPt[10 * (NbVert+2) + 7] =  longX;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+2) + 8] =  longY;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+2) + 9] = -longZ;

    LocalScene.ArrayNorVer_localPt[10 * (NbVert+3) + 7] = -longX;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+3) + 8] =  longY;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+3) + 9] = -longZ;

    LocalScene.ArrayNorVer_localPt[10 * (NbVert+4) + 7] = -longX;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+4) + 8] = -longY;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+4) + 9] = -longZ;

    LocalScene.ArrayNorVer_localPt[10 * (NbVert+5) + 7] = -longX;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+5) + 8] = -longY;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+5) + 9] =  longZ;

    LocalScene.ArrayNorVer_localPt[10 * (NbVert+6) + 7] = -longX;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+6) + 8] =  longY;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+6) + 9] =  longZ;

    LocalScene.ArrayNorVer_localPt[10 * (NbVert+7) + 7] = -longX;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+7) + 8] =  longY;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+7) + 9] = -longZ;

    LocalScene.ArrayNorVer_localPt[10 * (NbVert+8) + 7] = -longX;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+8) + 8] = -longY;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+8) + 9] = -longZ;

    LocalScene.ArrayNorVer_localPt[10 * (NbVert+9) + 7] = -longX;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+9) + 8] = -longY;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+9) + 9] =  longZ;

    LocalScene.ArrayNorVer_localPt[10 * (NbVert+10) + 7] =  longX;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+10) + 8] = -longY;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+10) + 9] =  longZ;

    LocalScene.ArrayNorVer_localPt[10 * (NbVert+11) + 7] =  longX;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+11) + 8] = -longY;
    LocalScene.ArrayNorVer_localPt[10 * (NbVert+11) + 9] = -longZ;

    // Plan vertices and indexes
    PlanStartIndex=NbVert+12;
    for(uint id=0; id<60; id++)
    {
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+id)+0] = 0.6f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+id)+1] = 0.6f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+id)+2] = 0.6f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+id)+3] = 1.0f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+id)+7] = PlanArray[3*id  ];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+id)+8] = PlanArray[3*id+1];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+id)+9] = PlanArray[3*id+2];
    }

    // Axes vertices and indexes
    AxesStartIndex = NbVert+12+60;
    for(uint id=0; id<6; id++)
    {
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+0] = (id<2)?1.0f:0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+1] = (id>1)&&(id<4)?1.0f:0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+2] = (id>3)?1.0f:0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+3] = 1.0f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+7] = AxeArray[3*id  ];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+8] = AxeArray[3*id+1];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+9] = AxeArray[3*id+2];
    }

    // Head of the X Axe
    XStartIndex = NbVert+12+60+6;
    for(uint id=0; id<6; id++)
    {
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+6+id)+0] = (id<2)?1.0f:0.3;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+6+id)+1] = 0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+6+id)+2] = 0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+6+id)+3] = 1.0f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+6+id)+7] = AxeArray[3*(id+6)  ];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+6+id)+8] = AxeArray[3*(id+6)+1];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+6+id)+9] = AxeArray[3*(id+6)+2];
    }

    // Head of the Y Axe
    YStartIndex = NbVert+12+60+12;
    for(uint id=0; id<6; id++)
    {
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+12+id)+0] = 0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+12+id)+1] = (id<2)?1.0f:0.3;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+12+id)+2] = 0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+12+id)+3] = 1.0f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+12+id)+7] = AxeArray[3*(id+12)  ];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+12+id)+8] = AxeArray[3*(id+12)+1];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+12+id)+9] = AxeArray[3*(id+12)+2];
    }

    // Head of the Z Axe
    ZStartIndex = NbVert+12+60+18;
    for(uint id=0; id<6; id++)
    {
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+18+id)+0] = 0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+18+id)+1] = 0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+18+id)+2] = (id<2)?1.0f:0.3;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+18+id)+3] = 1.0f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+18+id)+7] = AxeArray[3*(id+18)  ];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+18+id)+8] = AxeArray[3*(id+18)+1];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+18+id)+9] = AxeArray[3*(id+18)+2];
    }
}



void OpenGlWidget::png()
{
    LocalScene.png_ok *= -1;
}

void OpenGlWidget::jpg()
{
    LocalScene.jpg_ok *= -1;
}

void OpenGlWidget::bmp()
{
    LocalScene.bmp_ok *= -1;
}

void OpenGlWidget::quality(int c)
{
    LocalScene.quality_image = c;
}

void OpenGlWidget::colorstype(int c)
{
    LocalScene.colortype = c;
}

void OpenGlWidget::colorstypeParIso(int c)
{
    LocalScene.colortype = LocalScene.colortypeParam = c;
}

void OpenGlWidget::colorstypeParam(int c)
{
    LocalScene.colortypeParam = c;
}

void OpenGlWidget::redSpec(int cl)
{
    LocalScene.specReflection[0] = float(cl / 100.0);
}

void OpenGlWidget::greenSpec(int cl)
{
    LocalScene.specReflection[1] = float(cl / 100.0);
}

void OpenGlWidget::blueSpec(int cl)
{
    LocalScene.specReflection[2] = float(cl / 100.0);
}

static void drawCube(float x)
{
    float longX = x * float(difX / float(difMaximum)),
          longY = x * (difY / float(difMaximum)),
          longZ = x * (difZ / float(difMaximum));
    double mix = double(minx), max = double(maxx), miy = double(miny),
           may = double(maxy), miz = double(minz), maz = double(maxz);

    glLineWidth(1.0);
    glDrawArrays(GL_LINE_STRIP,CubeStartIndex, 12);

    // X
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos3f(longX, -longY, longZ + 60);
    glCallLists(QString::number(max, 'g', 3).size(), GL_UNSIGNED_BYTE,
                QString::number(max, 'g', 3).toLatin1());

    glColor3f(1.0, 0.0, 0.0);
    glRasterPos3f(-longX, -longY, longZ + 60);
    glCallLists(QString::number(mix, 'g', 3).size(), GL_UNSIGNED_BYTE,
                QString::number(mix, 'g', 3).toLatin1());
    // Y
    glColor3f(0.0, 1.0, 0.0);
    glRasterPos3f(longX + 100, longY, -longZ);
    glCallLists(QString::number(may, 'g', 3).size(), GL_UNSIGNED_BYTE,
                QString::number(may, 'g', 3).toLatin1());

    glColor3f(0.0, 1.0, 0.0);
    glRasterPos3f(longX + 100, -longY, -longZ);
    glCallLists(QString::number(miy, 'g', 3).size(), GL_UNSIGNED_BYTE,
                QString::number(miy, 'g', 3).toLatin1());
    // Z
    glColor3f(0.4f, 0.4f, 1.0);
    glRasterPos3f(longX + 60, -longY - 60, longZ);
    glCallLists(QString::number(maz, 'g', 3).size(), GL_UNSIGNED_BYTE,
                QString::number(maz, 'g', 3).toLatin1());

    glColor3f(0.4f, 0.4f, 1.0);
    glRasterPos3f(longX + 60, -longY - 60, -longZ);
    glCallLists(QString::number(miz, 'g', 3).size(), GL_UNSIGNED_BYTE,
                QString::number(miz, 'g', 3).toLatin1());
}

static void DrawPariso(ObjectProperties *scene, uint ParisoTypeIndex)
{
    uint idx = 0;
    for (uint i = 0; i < ParisoTypeIndex; i++)
        idx += scene->componentsinfos.NbComponentsType[i];
    int start_triangle = scene->componentsinfos.ParisoTriangle[2 * idx];
    float frontcl[4], backcl[4];
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPolygonOffset(scene->polyfactor, scene->polyunits);

    if (!scene->componentsinfos.ThereisRGBA[ParisoTypeIndex])
    {
        for (uint j = 0; j < 4; j++)
        {
            frontcl[j] = scene->frontcols[j];
            backcl[j] = scene->backcols[j];
        }
        glUniform4fv(uniformFrontColor, 1, frontcl);
        glUniform4fv(uniformBackColor, 1, backcl);
        glUniform1i(uniformThereisRGBA, 1);
    }

    if (scene->componentsinfos.ThereisCND[ParisoTypeIndex])
    {
        size_t Offset0 = start_triangle*sizeof( GL_FLOAT);
        glDrawElements(
            GL_TRIANGLES,
            int(3 * (scene->componentsinfos.NbTrianglesNoCND[ParisoTypeIndex])),
            GL_UNSIGNED_INT, (void *)(Offset0));

        if (scene->cndoptions[0])
        {
            size_t Offset1 = (3 * scene->componentsinfos.NbTrianglesNoCND[ParisoTypeIndex] +start_triangle)*sizeof( GL_FLOAT);
            glDrawElements(
                GL_TRIANGLES,
                int(3 * (scene->componentsinfos.NbTrianglesVerifyCND[ParisoTypeIndex])),
                GL_UNSIGNED_INT, (void *)(Offset1));
        }

        if (scene->cndoptions[1])
        {
            size_t Offset2 = (3 * scene->componentsinfos.NbTrianglesNoCND[ParisoTypeIndex] +
                              3 * scene->componentsinfos.NbTrianglesVerifyCND[ParisoTypeIndex] +
                              start_triangle)*sizeof( GL_FLOAT);
            glDrawElements(
                GL_TRIANGLES,
                int(3 * (scene->componentsinfos.NbTrianglesNotVerifyCND[ParisoTypeIndex])),
                GL_UNSIGNED_INT,
                (void *)(Offset2));
        }
    }
    else
    {
        for (uint i = 0; i < scene->componentsinfos.NbComponentsType[ParisoTypeIndex]; i++)
        {
            uint cmpIndex = (ParisoTypeIndex==1) ? (scene->componentsinfos.NbComponentsType[0]+i):i;
            if (scene->componentsinfos.ShowParIsoCmp[cmpIndex])
            {
                if (!scene->componentsinfos.ThereisRGBA[ParisoTypeIndex])
                {
                    for (uint j = 0; j < 4; j++)
                    {
                        frontcl[j] = scene->frontcols[4 * (i % 10) + j];
                        backcl[j] = scene->backcols[4 * (i % 10) + j];
                    }
                    glUniform4fv(uniformFrontColor, 1, frontcl);
                    glUniform4fv(uniformBackColor, 1, backcl);
                    glUniform1i(uniformThereisRGBA, 1);
                }
                else
                    glUniform1i(uniformThereisRGBA, 0);
                {
                    size_t Offset = scene->componentsinfos.ParisoTriangle[2*(i+idx)]*sizeof( GL_FLOAT);
                    glDrawElements(
                        GL_TRIANGLES,
                        int(3 * scene->componentsinfos.ParisoTriangle[2 * (i + idx) + 1]),GL_UNSIGNED_INT,(void *)(Offset));
                }
            }
        }
    }
    glDisable(GL_POLYGON_OFFSET_FILL);
    glUniform1i(uniformThereisRGBA, 0);
    //glDisable(GL_LIGHTING);
    //glDisable(GL_LIGHT0);
}
void OpenGlWidget::normOk()
{
    LocalScene.norm *= -1;
    update();
}
void OpenGlWidget::infosOk()
{
    LocalScene.infos *= -1;
    update();
}
void OpenGlWidget::smoothline()
{
    LocalScene.smoothline *= -1;
    /// For drawing Lines :
    if (LocalScene.smoothline == 1)
    {
        //glEnable(GL_LINE_SMOOTH);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
    }
    else
    {
        //glDisable(GL_LINE_SMOOTH);
        glDisable(GL_BLEND);
    }
    update();
}
void OpenGlWidget::boundingboxOk()
{
    LocalScene.boundingbox *= -1;
}

void OpenGlWidget::run() {
    update();
}

bool OpenGlWidget::timeractif()
{
    return (LocalScene.anim == 1);
}

void OpenGlWidget::stoptimer()
{
    timer->stop();
    update();
}

void OpenGlWidget::starttimer()
{
    timer->start(latence,this);
}

void OpenGlWidget::restarttimer(int newlatence)
{
    latence = newlatence;
    if (LocalScene.anim == 1)
    {
        timer->stop();
        timer->start(latence, this);
    }
}

void OpenGlWidget::startRendering()
{
    glt.start();
}

void OpenGlWidget::stopRendering()
{
    glt.stop();
    glt.wait();
}

void OpenGlWidget::resizeEvent(QResizeEvent *)
{
}

void OpenGlWidget::initializeGL()
{
}
void OpenGlWidget::closeEvent(QCloseEvent *evt)
{
    stopRendering();
    QOpenGLWidget::closeEvent(evt);
}

void OpenGlWidget::anim()
{
    LocalScene.anim *= -1;
    if (LocalScene.anim == 1)
        timer->start(latence, this);
    else
    {
        oldRotation = rotation;
        if (LocalScene.morph == -1)
        stoptimer();
    }
}

void OpenGlWidget::morph()
{
    LocalScene.morph *= -1;
    FistTimecalibrate *= -1;

    if (LocalScene.typedrawing == 1)
    {
        // Isosurfaces:
        IsoObjet->masterthread->activeMorph = LocalScene.morph;
        for (uint nbthreads = 0; nbthreads < IsoObjet->WorkerThreadsNumber - 1;
                nbthreads++)
            IsoObjet->workerthreads[nbthreads].activeMorph = LocalScene.morph;
        IsoObjet->IsoMorph();
    }
    else if (LocalScene.typedrawing == -1)
    {
        // Parametric surfaces:
        ParObjet->masterthread->activeMorph = LocalScene.morph;
        for (uint nbthreads = 0; nbthreads < ParObjet->WorkerThreadsNumber - 1;
                nbthreads++)
            ParObjet->workerthreads[nbthreads].activeMorph = LocalScene.morph;
        ParObjet->ParMorph();
    }
    else   // Pariso objects
    {
        // Parametric surfaces:
        ParObjet->masterthread->activeMorph = LocalScene.morph;
        for (uint nbthreads = 0; nbthreads < ParObjet->WorkerThreadsNumber - 1;
                nbthreads++)
            ParObjet->workerthreads[nbthreads].activeMorph = LocalScene.morph;
        ParObjet->ParMorph();
        // Isosurfaces:
        IsoObjet->masterthread->activeMorph = LocalScene.morph;
        for (uint nbthreads = 0; nbthreads < IsoObjet->WorkerThreadsNumber - 1;
                nbthreads++)
            IsoObjet->workerthreads[nbthreads].activeMorph = LocalScene.morph;
        IsoObjet->IsoMorph();
    }
    if (LocalScene.morph == 1)
        timer->start(latence, this);
    else if (LocalScene.anim == -1)
        stoptimer();
}

void OpenGlWidget::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    switch (key)
    {
    case Qt::Key_A:
        glt.anim();
        break;
    case Qt::Key_P:
        glt.morph();
        initbox();
        break;
    }
    glt.update();
}

void proj()
{
    //int maxwindow= std::min(screenWidth, screenHeight);
    // Calculate aspect ratio
    qreal aspect = 1;//qreal(screenWidth) / qreal(screenHeight ? screenHeight : 1);

    // Set near plane to 3.0, far plane to 7.0, field of view 45 degrees
    const qreal zNear = 0.01, zFar = 50.0, fov = 60.0;

    // Reset projection
    matrixProjectionx.setToIdentity();

    // Set perspective projection
    matrixProjectionx.perspective(fov, aspect, zNear, zFar);

}

void OpenGlWidget::resizeGL(int newwidth, int newheight)
{
    screenWidth = newwidth;
    screenHeight = newheight;
    //proj();
}

OpenGlWidget::OpenGlWidget(QWidget *parent) : QOpenGLWidget(parent), glt(this)
{
    //setAutoBufferSwap(true);
    OpenGlWidget::context();
    makeCurrent();
    static int NBGlWindow = 0;
    PerlinNoise = new ImprovedNoise(4., 4., 4.);
    latence = 10;
    val1 = val2 = val3 = 0.0;
    Vgrid = Ugrid = 50;
    CutV = CutU = 0;
    Xgrid = Ygrid = Zgrid = 40;
    CutX = CutY = CutZ = 0;
    IDGlWindow = NBGlWindow;
    LocalScene.VertxNumber = 0;
    FramesDir = "/home";
    hauteur_fenetre = 2*wh;
    timer = new QBasicTimer();
    NBGlWindow++;
}

void OpenGlWidget::infosok()
{
    LocalScene.infos *= -1;
}

void OpenGlWidget::FillOk()
{
    LocalScene.fill *= -1;
    update();
}

void OpenGlWidget::PrintInfos()
{
}

static void DrawAxe()
{
    glLineWidth(1.0);
    // Draw the three axes (lines without head)
    glDrawArrays(GL_LINES,AxesStartIndex,6);
    // Head of the X Axe:
    glDrawArrays(GL_TRIANGLE_FAN,XStartIndex,6);
    // Head of the Y Axe:
    glDrawArrays(GL_TRIANGLE_FAN,YStartIndex,6);
    // Head of the Z Axe:
    glDrawArrays(GL_TRIANGLE_FAN,ZStartIndex,6);
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos3i(410, 10, 10);
    glCallLists(strlen("X"), GL_UNSIGNED_BYTE, "X");

    glColor3f(0.0, 1.0, 0.0);
    glRasterPos3i(10, 410, 10);
    glCallLists(strlen("Y"), GL_UNSIGNED_BYTE, "Y");

    glColor3f(0.0, 0.0, 1.0);
    glRasterPos3i(10, 10, 410);
    glCallLists(strlen("Z"), GL_UNSIGNED_BYTE, "Z");
}

static void DrawNormals(ObjectProperties *scene)
{
    /*
    uint j = 0;
    glColor4f(0.8f, 0., 0.7f, 1.0);
    for (uint i = 0; i < scene->PolyNumber; i += 4)
    {
        j = 10 * scene->PolyIndices_localPt[i];
        glBegin(GL_LINES);
        glVertex3f(scene->ArrayNorVer_localPt[j + 7],
                   scene->ArrayNorVer_localPt[j + 8],
                   scene->ArrayNorVer_localPt[j + 9]);
        glVertex3f(scene->ArrayNorVer_localPt[j + 7] +
                   40 * scene->ArrayNorVer_localPt[j + 4],
                   scene->ArrayNorVer_localPt[j + 8] +
                   40 * scene->ArrayNorVer_localPt[j + 5],
                   scene->ArrayNorVer_localPt[j + 9] +
                   40 * scene->ArrayNorVer_localPt[j + 6]);
        glEnd();
    }
    */
}

void OpenGlWidget::Winitialize_GL()
{
    if (LocalScene.componentsinfos.updateviewer)
    {
        PutObjectInsideCube();
        PutObjectInsideCubeOk=true;
    }
}

void OpenGlWidget::UpdateGL()
{
    if (LocalScene.updategl)
    {
        Winitialize_GL();
        update();
    }
    else
        LocalScene.updategl = true;
}

static void DrawParisoCND(ObjectProperties *scene, uint compindex)
{
    uint idx = 0;
    for (uint i = 0; i < compindex; i++)
        idx += scene->componentsinfos.NbComponentsType[i];
    int start_triangle = scene->componentsinfos.ParisoTriangle[2 * idx];
    if (scene->cndoptions[3])
    {
        size_t Offset0 = (3 * scene->componentsinfos.NbTrianglesNoCND[compindex] + start_triangle)*sizeof( GL_FLOAT);
        glLineWidth(0.3);
        /*glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_LINE,
            int(3 * scene->componentsinfos.NbTrianglesVerifyCND[compindex]),
            GL_UNSIGNED_INT, (void *)Offset0);
            */
        for (uint i = 0; i < (3 * scene->componentsinfos.NbTrianglesVerifyCND[compindex]); i += 3)
        {
            glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, (void *)(Offset0));
            Offset0+=(3*sizeof( GL_FLOAT));
        }
    }

    if (scene->cndoptions[4])
    {
        size_t Offset1 = (3 * scene->componentsinfos
                          .NbTrianglesNoCND[compindex] + 3 * scene->componentsinfos
                                                 .NbTrianglesVerifyCND[compindex] +
                                                 start_triangle)*sizeof(GL_FLOAT);
        glLineWidth(0.3);
        /*glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_LINE,
            int(3 * scene->componentsinfos.NbTrianglesNotVerifyCND[compindex]),
            GL_UNSIGNED_INT,(void *)Offset1);
            */
        for (uint i = 0; i < (3 * scene->componentsinfos.NbTrianglesNotVerifyCND[compindex]); i += 3)
        {
            glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, (void *)(Offset1));
            Offset1+=(3*sizeof( GL_FLOAT));
        }
    }

    if (scene->cndoptions[2])
    {
        size_t Offset2 = (3*scene->componentsinfos.NbTrianglesNoCND[compindex]+3*(scene->componentsinfos.NbTrianglesVerifyCND[compindex] +
                          scene->componentsinfos.NbTrianglesNotVerifyCND[compindex])+start_triangle)*sizeof( GL_FLOAT);
        glLineWidth(4.0);
        /*glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_LINE,
            int(3 * scene->componentsinfos.NbTrianglesBorderCND[compindex]),
            GL_UNSIGNED_INT,(void *)Offset2);
            */
        for (uint i = 0; i < (3 * scene->componentsinfos.NbTrianglesBorderCND[compindex]); i += 3)
        {
            glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, (void *)(Offset2));
            Offset2+=(3*sizeof( GL_FLOAT));
        }
    }
}

static void DrawMeshIso(ObjectProperties *scene)
{
    size_t Offset = 0;
    uint st = 0;
    glUniform4fv(uniformGridColor, 1, scene->gridcol);
    glUniform1i(uniformdrawgridColor, 1);
    glLineWidth(0.3);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //glDrawElements(GL_LINE_LOOP, int(scene->PolyNumber), GL_UNSIGNED_INT, (void *)0);
    for (uint i = 0; i < scene->PolyNumber; i += 3)
    {
        Offset = st*sizeof( GL_FLOAT);
        glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, (void *)(Offset));
        st+=3;
    }
    glUniform1i(uniformdrawgridColor, 0);
}

static void DrawMinimalTopology(ObjectProperties *scene)
{
    glUniform4fv(uniformGridColor, 1,scene->gridcol);
    glUniform1i(uniformdrawgridColor, 1);
    glLineWidth(0.4);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    uint st = scene->PolyNumber;
    uint polysize=0;
    size_t Offset;
    for (uint i = 0; i < scene->NbPolygnNbVertexPtMin; i++)
    {
        polysize = scene->PolyIndices_localPtMin[i];
        Offset = st*sizeof( GL_FLOAT);
        glDrawElements(
            GL_LINE_LOOP,
            polysize,
            GL_UNSIGNED_INT,
            (void *)(Offset));
        st+=(polysize);
    }
    glUniform1i(uniformdrawgridColor, 0);
}

static void plan()
{
    glLineWidth(0.3);
    glDrawArrays(GL_LINES,PlanStartIndex,60);
}


static void CreateShaderProgram()
{
    const int MAX_LENGTH = 2048;
    char log[MAX_LENGTH];
    int logLength = 0;

    /* Assign our handles a "name" to new shader objects */
    //glDeleteShader(vertexshader);
    //glDeleteShader(fragmentshader);
    vertexshader = glCreateShader(GL_VERTEX_SHADER);
    bool shaderValid = glIsShader(vertexshader);
    if (!shaderValid)
    {
        std::cout << "Could not create Vertex Shader!";

    }
    fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);

    std::string stvert=vertexsource.toStdString();
    std::string stfrag=fragmentsource.toStdString();
    //c_str_vertex = stvert.c_str();
    //c_str_fragment = stfrag.c_str();

    static const char *c_str_vertex =
            R"(
            // GLSL version
            #version 120
            // uniforms
            uniform mat4 matrixModelView;
            uniform mat4 matrixNormal;
            uniform mat4 matrixModelViewProjection;
            // vertex attribs (input)
            attribute vec3 vertexPosition;
            attribute vec3 vertexNormal;
            attribute vec4 vertexColor;
            //attribute vec2 vertexTexCoord;
            // varyings (output)
            varying vec3 esVertex, esNormal;
            varying vec4 color;
            //varying vec2 texCoord0;
            void main()
            {
                esVertex = vec3(matrixModelView * vec4(vertexPosition, 1.0));
                esNormal = vec3(matrixNormal * vec4(vertexNormal, 1.0));
                color = vertexColor;
                gl_Position = matrixModelViewProjection * vec4(vertexPosition, 1.0);
            }
            )";

    static const char *c_str_fragment =
            R"(
            // GLSL version
            #version 120
            // uniforms
            uniform vec4 frontColor;
            uniform vec4 backColor;
            uniform vec4 gridColor;
            uniform int thereisRGBA;
            uniform int drawgridColor;

            uniform vec4 lightPosition;             // should be in the eye space
            uniform vec4 lightAmbient;              // light ambient color
            uniform vec4 lightDiffuse;              // light diffuse color
            uniform vec4 lightSpecular;             // light specular color
            uniform sampler2D map0;                 // texture map #1
            // varyings
            varying vec3 esVertex, esNormal;
            varying vec4 color;
            void main()
            {
                vec4 color1=color;
                vec3 normal = normalize(esNormal);
                if(!gl_FrontFacing)
                {
                    normal *= -1.0;
                }

                if(drawgridColor == 1)
                {
                    color1=gridColor;
                if(!gl_FrontFacing)
                {
                    normal *= -1.0;
                }
                }
                if(thereisRGBA ==1)
                {
                    if(!gl_FrontFacing)
                    {
                        color1=backColor;
                    }
                    else
                        color1=frontColor;
                }

                vec3 light;
                if(lightPosition.w == 0.0)
                {
                    light = normalize(lightPosition.xyz);
                }
                else
                {
                    light = normalize(lightPosition.xyz - esVertex);
                }
                vec3 view = normalize(-esVertex);
                vec3 halfv = normalize(light + view);

                vec4 fragColor = vec4(lightAmbient.rgb,1.0) * color1;                  // begin with ambient
                float dotNL = max(dot(normal, light), 0.0);
                fragColor += (lightDiffuse.rgb,1.0) * color1 * dotNL;              // add diffuse
                float dotNH = max(dot(normal, halfv), 0.0);
                fragColor += vec4(pow(dotNH, 128.0) * lightSpecular.rgb,1.0) * color1; // add specular
                // set frag color
                gl_FragColor = fragColor;  // keep opaque=1
            }
            )";

    /* Associate the source code buffers with each handle */
    glShaderSource(vertexshader, 1, &c_str_vertex, NULL);

    /* Free the temporary allocated memory */
    //delete(c_str_fragment);
    //free(fragmentSource);
    /*

*/
    /* Compile our shader objects */
    glCompileShader(vertexshader);
    glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &IsCompiled_VS);

        if(IsCompiled_VS==GL_FALSE)
        {
           QMessageBox msgBox;
           glGetShaderiv(vertexshader, GL_INFO_LOG_LENGTH, &maxLength);

           // The maxLength includes the NULL character
           vertexInfoLog = (char *)malloc(maxLength);

           glGetShaderInfoLog(vertexshader, maxLength, &maxLength, vertexInfoLog);

           std::string vertexInfoLogString = std::string(vertexInfoLog);
           msgBox.setText("Error : " +QString::fromStdString(std::string(vertexInfoLog)));
           msgBox.adjustSize();
           msgBox.exec();
           // Handle the error in an appropriate way such as displaying a message or writing to a log file.
           // In this simple program, we'll just leave
           //free(vertexInfoLog);
           //return;
        }


    glShaderSource(fragmentshader, 1, &c_str_fragment, NULL);
    glCompileShader(fragmentshader);
    glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &IsCompiled_FS);
    if(IsCompiled_FS==GL_FALSE)
    {
        QMessageBox msgBox;
       glGetShaderiv(fragmentshader, GL_INFO_LOG_LENGTH, &maxLength);

       /* The maxLength includes the NULL character */
       fragmentInfoLog = (char *)malloc(maxLength);

       glGetShaderInfoLog(fragmentshader, maxLength, &maxLength, fragmentInfoLog);

       std::string vertexInfoLogString = std::string(fragmentInfoLog);
       msgBox.setText("Error : " +QString::fromStdString(std::string(fragmentInfoLog)));
       msgBox.adjustSize();
       msgBox.exec();

       //return;
    }


    /* If we reached this point it means the vertex and fragment shaders compiled and are syntax error free. */
    /* We must link them together to make a GL shader program */
    /* GL shader programs are monolithic. It is a single piece made of 1 vertex shader and 1 fragment shader. */
    /* Assign our program handle a "name" */
    shaderprogramId = glCreateProgram();

    /* Attach our shaders to our program */
    glAttachShader(shaderprogramId, vertexshader);
    glAttachShader(shaderprogramId, fragmentshader);

    /* Bind attribute index 0 (coordinates) to in_Position and attribute index 1 (color) to in_Color */
    /* Attribute locations must be setup before calling glLinkProgram. */
    glBindAttribLocation(shaderprogramId, 0, "in_Position");
    glBindAttribLocation(shaderprogramId, 1, "in_Color");

    /* Link our program */
    /* At this stage, the vertex and fragment programs are inspected, optimized and a binary code is generated for the shader. */
    /* The binary code is uploaded to the GPU, if there is no error. */
    glLinkProgram(shaderprogramId);




    glGetProgramiv(shaderprogramId, GL_LINK_STATUS, (int *)&IsLinked);
    if(!IsLinked)
    {
       /* Noticed that glGetProgramiv is used to get the length for a shader program, not glGetShaderiv. */
       glGetProgramiv(shaderprogramId, GL_INFO_LOG_LENGTH, &maxLength);

       /* The maxLength includes the NULL character */
       shaderProgramInfoLog = (char *)malloc(maxLength);

       /* Notice that glGetProgramInfoLog, not glGetShaderInfoLog. */
       glGetProgramInfoLog(shaderprogramId, maxLength, &maxLength, shaderProgramInfoLog);

       /* Handle the error in an appropriate way such as displaying a message or writing to a log file. */
       /* In this simple program, we'll just leave */
       //free(shaderProgramInfoLog);
       //return;
    }
    /* Load the shader into the rendering pipeline */
    glUseProgram(shaderprogramId);




    uniformMatrixModelView           = glGetUniformLocation(shaderprogramId, "matrixModelView");
    uniformMatrixModelViewProjection = glGetUniformLocation(shaderprogramId, "matrixModelViewProjection");
    uniformMatrixNormal              = glGetUniformLocation(shaderprogramId, "matrixNormal");
    uniformLightPosition             = glGetUniformLocation(shaderprogramId, "lightPosition");
    uniformLightAmbient              = glGetUniformLocation(shaderprogramId, "lightAmbient");
    uniformLightDiffuse              = glGetUniformLocation(shaderprogramId, "lightDiffuse");
    uniformLightSpecular             = glGetUniformLocation(shaderprogramId, "lightSpecular");
    uniformFrontColor                = glGetUniformLocation(shaderprogramId, "frontColor");
    uniformBackColor                 = glGetUniformLocation(shaderprogramId, "backColor");
    uniformGridColor                 = glGetUniformLocation(shaderprogramId, "gridColor");
    uniformThereisRGBA               = glGetUniformLocation(shaderprogramId, "thereisRGBA");
    uniformdrawgridColor             = glGetUniformLocation(shaderprogramId, "drawgridColor");
    uniformMap0                      = glGetUniformLocation(shaderprogramId, "map0");
    attribVertexPosition             = glGetAttribLocation(shaderprogramId, "vertexPosition");
    attribVertexNormal               = glGetAttribLocation(shaderprogramId, "vertexNormal");
    attribVertexColor                = glGetAttribLocation(shaderprogramId, "vertexColor");

    // set uniform values
    float lightPosition[] = {0, 0, 10, 0};
    float lightAmbient[]  = {0.3f, 0.3f, 0.3f, 1};
    float lightDiffuse[]  = {0.7f, 0.7f, 0.7f, 1};
    float lightSpecular[] = {1.0f, 1.0f, 1.0f, 1};
    float frontColor[] = {0.8f, 0.6f, 0.1, 1};
    float backColor[]  = {0.1f, 0.7f, 0.2f, 1};
    glUniform4fv(uniformLightPosition, 1, lightPosition);
    glUniform4fv(uniformLightAmbient, 1, lightAmbient);
    glUniform4fv(uniformLightDiffuse, 1, lightDiffuse);
    glUniform4fv(uniformLightSpecular, 1, lightSpecular);

    glUniform4fv(uniformFrontColor, 1, frontColor);
    glUniform4fv(uniformBackColor, 1, backColor);
    glUniform4fv(uniformGridColor, 1, gridcol);
    glUniform1i(uniformThereisRGBA, 1);
    glUniform1i(uniformdrawgridColor, 0);
    glUniform1i(uniformMap0, 0);

    // unbind GLSL
    glUseProgram(0);

    // check GLSL status
    int linkStatus;
    glGetProgramiv(shaderprogramId, GL_LINK_STATUS, &linkStatus);
    if(linkStatus == GL_FALSE)
    {
        glGetProgramiv(shaderprogramId, GL_INFO_LOG_LENGTH, &logLength);
        glGetProgramInfoLog(shaderprogramId, MAX_LENGTH, &logLength, log);
        std::cout << "===== GLSL Program Log =====\n" << log << std::endl;
        return;
    }
    else
    {
        return;
    }
}

void OpenGlWidget::LoadShadersFiles()
{
    QFile vertexshadfile(":/gl_viewer/shaders/vertexshader.txt");
    QFile fragmentshadfile(":/gl_viewer/shaders/fragmentshader.txt");
    if (vertexshadfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        vertexsource = vertexshadfile.readAll();
        vertexshadfile.close();
    }
    if (fragmentshadfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        fragmentsource = fragmentshadfile.readAll();
        fragmentshadfile.close();
    }
    CreateShaderProgram();
}
/*
static void LoadShaderFiles()
{
    std::ifstream vertexshaderfile("gl_viewer/shaders/vertexshader.txt");
    std::string vertexshaderfilecontents((std::istreambuf_iterator<char>(vertexshaderfile)),
        std::istreambuf_iterator<char>());
    c_str_vertex=vertexshaderfilecontents.c_str();

    std::ifstream fragmentshaderfile(":/gl_viewer/shaders/fragmentshader.txt");
    std::string fragmentshaderfilecontents((std::istreambuf_iterator<char>(fragmentshaderfile)),
        std::istreambuf_iterator<char>());
    c_str_fragment=fragmentshaderfilecontents.c_str();
    CreateShaderProgram();
}
*/
void initLights()
{
    /*
    // set up light colors (ambient, diffuse, specular)
    GLfloat lightKa[] = {.3f, .3f, .3f, 1.0f};  // ambient light
    GLfloat lightKd[] = {.7f, .7f, .7f, 1.0f};  // diffuse light
    GLfloat lightKs[] = {1, 1, 1, 1};
    // specular light
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightKa);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightKd);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightKs);

    // position the light
    float lightPos[4] = {0, 0, 10, 0}; // directional light
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);
                       */
                       // MUST enable each light source after configuration                      // MUST enable each light source after configuration
}

void initGL()
{
    glShadeModel(GL_SMOOTH);                    // shading mathod: GL_SMOOTH or GL_FLAT

    // enable /disable features
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    /////****************
    /// For drawing Filled Polygones :
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_VERTEX_PROGRAM_TWO_SIDE);
    //glLightModelf(GL_LIGHT_MODEL_AMBIENT, GL_TRUE);
    glEnable(GL_NORMALIZE);
    glFrontFace(GL_CCW);

    glEnable(GL_DEPTH_TEST);
    //////*************

     // track material ambient and diffuse from surface color, call it before glEnable(GL_COLOR_MATERIAL)
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    glClearColor(0, 0, 0, 0);                   // background color
    glClearStencil(0);                          // clear stencil buffer
    glClearDepth(1.0f);                         // 0 is near, 1 is far
    //glDepthFunc(GL_LEQUAL);

    initLights();
}
///////////////////////////////////////////////////////////////////////////////
// initialize global variables
///////////////////////////////////////////////////////////////////////////////
bool initSharedMem()
{
    screenWidth = SCREEN_WIDTH;
    screenHeight = SCREEN_HEIGHT;

    mouseLeftDown = mouseRightDown = false;
    mouseY = 0;

    //cameraAngleX = cameraAngleY = 0.0f;
    cameraDistance = CAMERA_DISTANCE;

    drawMode = 0; // 0:fill, 1: wireframe, 2:points

    return true;
}

static void InitialOperations(ObjectProperties *)
{
    static int staticaction = 0;
    if (staticaction < 1)
    {
        glEnable(GL_DEPTH_TEST);
        staticaction += 1;

        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
        initSharedMem();
        initGL();
        proj();
    }
}

/* Create handles for our Vertex Array Object and two Vertex Buffer Objects */
GLuint vao, vbo[2];

static void CopyData(ObjectProperties *scene)
{
    static int firstaction=0;
    static uint previousVertxNumber=0;
    static uint previousPolyNumberNbPolygnNbVertexPtMin=0;
    if(firstaction==0)
    {
        glGenVertexArrays(1, &vao);
        //glDeleteBuffers(2, vbo);
        vbo[0]=vbo[1]=0;
        glGenBuffers(2, vbo);
        /* Bind our first VBO as being the active buffer and storing vertex attributes (coordinates) */
        glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float)*10*(scene->VertxNumber+(12+60+24)),scene->ArrayNorVer_localPt, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

        /* Bind our first VBO as being the active buffer and storing vertex attributes (coordinates) */
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(uint)*(scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize), scene->PolyIndices_localPt, GL_STATIC_DRAW);


        size_t cOffset = 0;
        size_t nOffset = cOffset + 4*sizeof( GL_FLOAT);
        size_t vOffset = nOffset + 3*sizeof (GL_FLOAT);
/*
        // enable vertex arrays
        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);

        // specify vertex arrays with their offsets
        glColorPointer(4, GL_FLOAT, 10*sizeof( GL_FLOAT), (void*)cOffset);
        glNormalPointer(GL_FLOAT, 10*sizeof( GL_FLOAT), (void*)nOffset);
        glVertexPointer(3, GL_FLOAT, 10*sizeof( GL_FLOAT), (void*)vOffset);
*/
        // activate attribs
        glEnableVertexAttribArray(attribVertexColor);
        glEnableVertexAttribArray(attribVertexNormal);
        glEnableVertexAttribArray(attribVertexPosition);

        // set attrib arrays using glVertexAttribPointer()
        glVertexAttribPointer(attribVertexPosition, 3, GL_FLOAT, false, 10*sizeof( GL_FLOAT), (void*)vOffset);
        glVertexAttribPointer(attribVertexNormal, 3, GL_FLOAT, false, 10*sizeof( GL_FLOAT), (void*)nOffset);
        glVertexAttribPointer(attribVertexColor,4, GL_FLOAT, false, 10*sizeof( GL_FLOAT), (void*)cOffset);

        previousVertxNumber = scene->VertxNumber;
        previousPolyNumberNbPolygnNbVertexPtMin = (scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize);
        firstaction++;
    }
    else{

        if(scene->VertxNumber>previousVertxNumber)
        {
            glBufferData(GL_ARRAY_BUFFER, sizeof(float)*10*(scene->VertxNumber+(12+60+24)), scene->ArrayNorVer_localPt, GL_STATIC_DRAW);
            previousVertxNumber = scene->VertxNumber;
        }
        else
        {
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float)*10*(scene->VertxNumber+(12+60+24)), scene->ArrayNorVer_localPt);
            previousVertxNumber = scene->VertxNumber;
        }

        if((scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize)>previousPolyNumberNbPolygnNbVertexPtMin)
        {
           glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(uint)*(scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize), scene->PolyIndices_localPt, GL_STATIC_DRAW);
           previousPolyNumberNbPolygnNbVertexPtMin =  (scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize);

        }
        else
        {
            glBufferSubData(GL_ELEMENT_ARRAY_BUFFER,0, sizeof(uint)*(scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize), scene->PolyIndices_localPt);
            previousPolyNumberNbPolygnNbVertexPtMin =  (scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize);
        }

        size_t cOffset = 0;
        size_t nOffset = cOffset + 4*sizeof( GL_FLOAT);
        size_t vOffset = nOffset + 3*sizeof (GL_FLOAT);
       /*
        glEnable(GL_COLOR_ARRAY);
        glEnable(GL_VERTEX_ARRAY);
        glEnable(GL_NORMAL_ARRAY);
        // specify vertex arrays with their offsets
        glColorPointer(4, GL_FLOAT, 10*sizeof( GL_FLOAT), (void*)cOffset);
        glNormalPointer(GL_FLOAT, 10*sizeof( GL_FLOAT), (void*)nOffset);
        glVertexPointer(3, GL_FLOAT, 10*sizeof( GL_FLOAT), (void*)vOffset);
        */
        // set attrib arrays using glVertexAttribPointer()
        glEnableVertexAttribArray(attribVertexColor);
        glEnableVertexAttribArray(attribVertexNormal);
        glEnableVertexAttribArray(attribVertexPosition);

        // set attrib arrays using glVertexAttribPointer()
        glVertexAttribPointer(attribVertexPosition, 3, GL_FLOAT, false, 10*sizeof( GL_FLOAT), (void*)vOffset);
        glVertexAttribPointer(attribVertexNormal, 3, GL_FLOAT, false, 10*sizeof( GL_FLOAT), (void*)nOffset);
        glVertexAttribPointer(attribVertexColor,4, GL_FLOAT, false, 10*sizeof( GL_FLOAT), (void*)cOffset);
    }
}

void OpenGlWidget::copydata()
{
    CopyData(&LocalScene);
}

static void draw(ObjectProperties *scene)
{
    if(!PutObjectInsideCubeOk)
        return;
    InitialOperations(scene);
    if (scene->componentsinfos.Interleave)
    {
        CopyData(scene);
        scene->componentsinfos.Interleave = false;
    }

    // clear buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // set modelview matrix
    QMatrix4x4 matrixViewx;


    matrixViewx.translate(0.0, 0.0, -cameraDistance);
    matrixViewx.rotate(rotation);

    matrixViewx.rotate(270,1.0,0.0,0.0);
    matrixViewx.rotate(225,0.0,0.0,1.0);
    matrixViewx.rotate(-29,1.0,-1.0,0.0);
    // bind GLSL
    glUseProgram(shaderprogramId);
    QMatrix4x4 matrixModelViewProjectionx = matrixProjectionx * matrixViewx;
    QMatrix4x4 matrixNormalx=matrixViewx;
    matrixNormalx.setColumn(3, QVector4D(0,0,0,1));
    glUniformMatrix4fv(uniformMatrixModelView, 1, false, matrixViewx.data());
    glUniformMatrix4fv(uniformMatrixModelViewProjection, 1, false, matrixModelViewProjectionx.data());
    glUniformMatrix4fv(uniformMatrixNormal, 1, false, matrixNormalx.data());

    // bind VBOs
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);

    // activate attribs
    glEnableVertexAttribArray(attribVertexColor);
    glEnableVertexAttribArray(attribVertexNormal);
    glEnableVertexAttribArray(attribVertexPosition);

    // set attrib arrays using glVertexAttribPointer()
    size_t cOffset = 0;
    size_t nOffset = cOffset + 4*sizeof( GL_FLOAT);
    size_t vOffset = nOffset + 3*sizeof (GL_FLOAT);

    // set attrib arrays using glVertexAttribPointer()
    glVertexAttribPointer(attribVertexPosition, 3, GL_FLOAT, false, 10*sizeof( GL_FLOAT), (void*)vOffset);
    glVertexAttribPointer(attribVertexNormal, 3, GL_FLOAT, false, 10*sizeof( GL_FLOAT), (void*)nOffset);
    glVertexAttribPointer(attribVertexColor,4, GL_FLOAT, false, 10*sizeof( GL_FLOAT), (void*)cOffset);

    // Blend Effect activation:
    if (scene->transparency == 1)
        glDepthMask(GL_FALSE);

    // Plan:
    if (scene->infos == 1)
        plan();

    // Axe :
    if (scene->infos == 1)
        DrawAxe();

    if (scene->fill == 1 && scene->componentsinfos.updateviewer)
        for (uint i = 0; i < scene->componentsinfos.NbComponentsType.size(); i++)
            DrawPariso(scene, i);

    // Draw Mesh Object:
    if (scene->triangles == 1 && scene->componentsinfos.updateviewer)
        DrawMeshIso(scene);

    // Bounding Box:
    if (scene->boundingbox == 1)
        drawCube(wh);

    // Draw Minimal topology for isosurfaces:
    if (scene->mesh == 1 && scene->componentsinfos.updateviewer)
        DrawMinimalTopology(scene);

    if (scene->activarecnd && scene->componentsinfos.updateviewer)
        for (uint i = 0; i < scene->componentsinfos.NbComponentsType.size(); i++)
            if (scene->componentsinfos.ThereisCND[i])
                DrawParisoCND(scene, i);

    // Draw Normales:
    if (scene->norm == 1 && scene->componentsinfos.updateviewer)
        DrawNormals(scene);

    if (scene->transparency == 1)
        glDepthMask(GL_TRUE);

    glDisableVertexAttribArray(attribVertexPosition);
    glDisableVertexAttribArray(attribVertexNormal);
    glDisableVertexAttribArray(attribVertexColor);
    glUseProgram(0);
}

void OpenGlWidget::paintGL()
{
    if (LocalScene.morph == 1)
    {
        if (LocalScene.typedrawing == -1)
        {
            ParObjet->ParamBuild(
                &(LocalScene.ArrayNorVer_localPt), &(LocalScene.PolyIndices_localPt),
                &LocalScene.PolyNumber, &LocalScene.VertxNumber,
                &(LocalScene.componentsinfos), &(LocalScene.PolyIndices_localPtMin),
                &(LocalScene.NbPolygnNbVertexPtMin),
                &(LocalScene.NbPolygnNbVertexPtMinSize));
        }
        else if (LocalScene.typedrawing == 1)
        {
            IsoObjet->IsoBuild(
                &(LocalScene.ArrayNorVer_localPt), &(LocalScene.PolyIndices_localPt),
                &(LocalScene.PolyNumber), &(LocalScene.VertxNumber),
                &(LocalScene.PolyIndices_localPtMin),
                &(LocalScene.NbPolygnNbVertexPtMin),
                &(LocalScene.NbPolygnNbVertexPtMinSize),
                &(LocalScene.componentsinfos));
        }
        else
        {

            ParObjet->ParamBuild(
                &(LocalScene.ArrayNorVer_localPt), &(LocalScene.PolyIndices_localPt),
                &LocalScene.PolyNumber, &LocalScene.VertxNumber,
                &(LocalScene.componentsinfos), &(LocalScene.PolyIndices_localPtMin),
                &(LocalScene.NbPolygnNbVertexPtMin),
                &(LocalScene.NbPolygnNbVertexPtMinSize));
            IsoObjet->IsoBuild(
                &(LocalScene.ArrayNorVer_localPt), &(LocalScene.PolyIndices_localPt),
                &(LocalScene.PolyNumber), &(LocalScene.VertxNumber),
                &(LocalScene.PolyIndices_localPtMin),
                &(LocalScene.NbPolygnNbVertexPtMin),
                &(LocalScene.NbPolygnNbVertexPtMinSize),
                &(LocalScene.componentsinfos));
        }
        Winitialize_GL();
    }

    draw(&LocalScene);

    if (LocalScene.infos == 1)
        PrintInfos();
    if (LocalScene.morph == 1 && LocalScene.frame == 1)
        FramesSave();
}

void OpenGlWidget::timerEvent(QTimerEvent *)
{
    if(LocalScene.anim == 1)
        rotation = QQuaternion::fromAxisAndAngle(n, acc/10) * rotation;
    UpdateGL();
}


void OpenGlWidget::mouseReleaseEvent(QMouseEvent *)
{
    oldRotation = rotation;
}

void OpenGlWidget::mousePressEvent(QMouseEvent *e)
{
    // Save mouse press position
    mousePressPosition = QVector2D(e->localPos());
    rotation = oldRotation;


    if (e->button() == Qt::LeftButton)
    {
        btgauche = 1;
        mouseLeftDown =true;
    }
    else
    {
        btgauche = 0;
        mouseLeftDown =false;
    }
    if (e->button() == Qt::RightButton)
    {
        btdroit = 1;
        mouseRightDown =true;
    }
    else
    {
        btdroit = 0;
        mouseRightDown =false;
    }
    if (e->button() == Qt::MidButton)
        btmilieu = 1;
    else
        btmilieu = 0;

    mouseY = e->y()/2;
}

void OpenGlWidget::mouseMoveEvent(QMouseEvent *e)
{
    static int oldx=0, oldy=0;
    static QVector3D oldn=QVector3D(0,0,1);
    static qreal oldacc;
    if(mouseLeftDown)
    {
        QVector2D diff = QVector2D(e->localPos()) - mousePressPosition;
        // Rotation axis is perpendicular to the mouse position difference
        n = QVector3D(diff.y(), diff.x(), 0.0).normalized();
        // Accelerate angular speed relative to the length of the mouse sweep
        glGetIntegerv(GL_VIEWPORT,LocalScene.viewport);
        acc =std::sqrt((diff.y()-oldy)*(diff.y()-oldy)+ float(diff.x()-oldx)*(diff.x()-oldx))/(double)(LocalScene.viewport[2]+1)*360.0;
        // Calculate new rotation axis
        rotationAxis = (rotationAxis +n).normalized();
        rotation = QQuaternion::fromAxisAndAngle(n, acc)*oldRotation;
        oldacc= acc;
        oldn = n;
    }
    if(mouseRightDown)
    {
        cameraDistance -= (e->y()/2 - mouseY) * 0.02f;
        mouseY = e->y()/2;
        //proj();
    }
    update();
}

void OpenGlWidget::screenshot()
{
    QImage image = QOpenGLWidget::grabFramebuffer();
    if (LocalScene.png_ok == 1)
        image.save("GLscreenshot.png", "PNG", LocalScene.quality_image);
    if (LocalScene.bmp_ok == 1)
        image.save("GLscreenshot.bmp", "BMP", LocalScene.quality_image);
}

void OpenGlWidget::FramesShot()
{
    LocalScene.frame *= -1;
    if (LocalScene.frame == 1)
    {
        FramesDir = QFileDialog::getExistingDirectory(
                        this, tr("Choose Or Create Directory"), FramesDir,
                        QFileDialog::DontResolveSymlinks);
        if (FramesDir != "" && !FramesDir.endsWith("/"))
            FramesDir += "/";
    }
}

void OpenGlWidget::FramesSave()
{
    static int Index = 0;
    if (LocalScene.frame == 1)
    {
        QImage image = QOpenGLWidget::grabFramebuffer();   //:grabFrameBuffer();
        QString FileName =
            FramesDir + QString("%1").arg(Index, 5, 10, QChar('0')) + ".png";
        Index += 1;
        image.save(FileName, "PNG", 1);
    }
}

QImage OpenGlWidget::Copyscreenshot()
{
    return (QOpenGLWidget::grabFramebuffer());
}

void OpenGlWidget::transparency(int cl, int currentposition)
{
    switch (LocalScene.colortype)
    {
    case 1:
        LocalScene.frontcols[(currentposition % 10) * 4 + 3] = (cl / 255.0f);
        break;
    case 0:
        LocalScene.backcols[(currentposition % 10) * 4 + 3] = (cl / 255.0f);
        break;
    case 2:
        LocalScene.gridcol[3] = (cl / 255.0f);
        break;
    case 3:
        LocalScene.groundcol[3] = (cl / 255.0f);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],
                     LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    }
    update();
}

void OpenGlWidget::red(int cl, int currentposition)
{
    switch (LocalScene.colortype)
    {
    case 1:
        LocalScene.frontcols[(currentposition % 10) * 4 + 0] = (cl / 255.0f);
        break;
    case 0:
        LocalScene.backcols[(currentposition % 10) * 4 + 0] = (cl / 255.0f);
        break;
    case 2:
        LocalScene.gridcol[0] = (cl / 255.0f);
        break;
    case 3:
        LocalScene.groundcol[0] = (cl / 255.0f);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],
                     LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    }
    update();
}

void OpenGlWidget::green(int cl, int currentposition)
{
    switch (LocalScene.colortype)
    {
    case 1:
        LocalScene.frontcols[(currentposition % 10) * 4 + 1] = (cl / 255.0f);
        break;
    case 0:
        LocalScene.backcols[(currentposition % 10) * 4 + 1] = (cl / 255.0f);
        break;
    case 2:
        LocalScene.gridcol[1] = (cl / 255.0f);
        break;
    case 3:
        LocalScene.groundcol[1] = (cl / 255.0f);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],
                     LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    }
    update();
}

void OpenGlWidget::blue(int cl, int currentposition)
{
    switch (LocalScene.colortype)
    {
    case 1:
        LocalScene.frontcols[(currentposition % 10) * 4 + 2] = (cl / 255.0f);
        break;
    case 0:
        LocalScene.backcols[(currentposition % 10) * 4 + 2] = (cl / 255.0f);
        break;
    case 2:
        LocalScene.gridcol[2] = (cl / 255.0f);
        break;
    case 3:
        LocalScene.groundcol[2] = (cl / 255.0f);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],
                     LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    }
    update();
}

void OpenGlWidget::transparence(bool trs)
{
    LocalScene.transparency *= -1;
    if (trs)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    else
        glDisable(GL_BLEND);

    update();
}

void OpenGlWidget::transSpec(int cl)
{
    LocalScene.specReflection[3] = (cl / 100.0f);
    InitSpecularParameters();
}

void OpenGlWidget::Shininess(int cl)
{
    LocalScene.shininess = cl;
    InitSpecularParameters();
}

void OpenGlWidget::InitSpecularParameters()
{
    /*
    /// For drawing Filled Polygones :
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_VERTEX_PROGRAM_TWO_SIDE);
    glEnable(GL_NORMALIZE);
    */
    glFrontFace(GL_CCW);
    glEnable(GL_DEPTH_TEST);
    update();
}
