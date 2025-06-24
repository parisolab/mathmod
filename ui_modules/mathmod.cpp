﻿/***************************************************************************
 *   Copyright (C) 2025 by Abderrahman Taha                                *
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
#include "mathmod.h"


#ifndef GLERROR_H
#define GLERROR_H

void _check_gl_error(const char *file, int line);

///
/// Usage
/// [... some opengl calls]
/// glCheckError();
///
#define check_gl_error() _check_gl_error(__FILE__,__LINE__)

#endif // GLERROR_H

using namespace std;

void _check_gl_error(const char *file, int line) {
    GLenum err (glGetError());

    while(err!=GL_NO_ERROR) {
        string error;

        switch(err) {
        case GL_INVALID_OPERATION:      error="INVALID_OPERATION";      break;
        case GL_INVALID_ENUM:           error="INVALID_ENUM";           break;
        case GL_INVALID_VALUE:          error="INVALID_VALUE";          break;
        case GL_OUT_OF_MEMORY:          error="OUT_OF_MEMORY";          break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:  error="INVALID_FRAMEBUFFER_OPERATION";  break;
        default: error="UNKNOWN_ERROR";  break;
        }

        cerr << "GL_" << error.c_str() <<" - "<<file<<":"<<line<<endl;
        err=glGetError();
    }
}



void MathMod::CalculateTexturePoints(int type)
{
    double tmp, val[6]={0,0,0,0,0,0};
    uint Jprime;
    LocalScene.componentsinfos.ThereisRGBA[0] = true;
    LocalScene.componentsinfos.NoiseParam[0].NoiseType = 1;
    if (type == 1)
    {
        LocalScene.componentsinfos.NoiseParam[0].RgbtParser =
            IsoObjet->masterthread->RgbtParser;
        LocalScene.componentsinfos.NoiseParam[0].NoiseParser =
            IsoObjet->masterthread->NoiseParser;
        IsoObjet->masterthread->NOISE_STR == ""
        ? LocalScene.componentsinfos.NoiseParam[0].NoiseShape = 0
                : LocalScene.componentsinfos.NoiseParam[0].NoiseShape = 1;
    }
    else // (type == 0)
    {
        LocalScene.componentsinfos.NoiseParam[0].RgbtParser =
            ParObjet->masterthread->RgbtParser;
        LocalScene.componentsinfos.NoiseParam[0].NoiseParser =
            ParObjet->masterthread->NoiseParser;
        ParObjet->masterthread->NOISE_STR == ""
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

void MathMod::CalculatePigmentPoints(int type)
{
    double tmp, val[4];
    LocalScene.componentsinfos.ThereisRGBA[0] = true;
    LocalScene.componentsinfos.NoiseParam[0].NoiseType = 0; // Pigments
    if (type == 1)
    {
        LocalScene.componentsinfos.NoiseParam[0].VRgbtParser =
            IsoObjet->masterthread->VRgbtParser;
        LocalScene.componentsinfos.NoiseParam[0].GradientParser =
            IsoObjet->masterthread->GradientParser;
        LocalScene.componentsinfos.NoiseParam[0].Nb_vrgbts =
            IsoObjet->masterthread->VRgbtSize;
        LocalScene.componentsinfos.NoiseParam[0].NoiseParser =
            IsoObjet->masterthread->NoiseParser;
        IsoObjet->masterthread->NOISE_STR == ""
        ? LocalScene.componentsinfos.NoiseParam[0].NoiseShape = 0
                : LocalScene.componentsinfos.NoiseParam[0].NoiseShape = 1;
    }
    else // (type == 0)
    {
        LocalScene.componentsinfos.NoiseParam[0].VRgbtParser =
            ParObjet->masterthread->VRgbtParser;
        LocalScene.componentsinfos.NoiseParam[0].GradientParser =
            ParObjet->masterthread->GradientParser;
        LocalScene.componentsinfos.NoiseParam[0].Nb_vrgbts =
            ParObjet->masterthread->VRgbtSize;
        LocalScene.componentsinfos.NoiseParam[0].NoiseParser =
            ParObjet->masterthread->NoiseParser;
        ParObjet->masterthread->NOISE_STR == ""
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
                j < LocalScene.componentsinfos.NoiseParam[0].Nb_vrgbts && j < 95;
                j += 5)
            if (tmp <= LocalScene.componentsinfos.NoiseParam[0].VRgbtParser[j].Eval(val))
            {
                LocalScene.ArrayNorVer_localPt[i*10  ] = float(LocalScene.componentsinfos.NoiseParam[0].VRgbtParser[j+1].Eval(val));
                LocalScene.ArrayNorVer_localPt[i*10+1] = float(LocalScene.componentsinfos.NoiseParam[0].VRgbtParser[j+2].Eval(val));
                LocalScene.ArrayNorVer_localPt[i*10+2] = float(LocalScene.componentsinfos.NoiseParam[0].VRgbtParser[j+3].Eval(val));
                LocalScene.ArrayNorVer_localPt[i*10+3] = float(LocalScene.componentsinfos.NoiseParam[0].VRgbtParser[j+4].Eval(val));
                j = 100;
            }
    }
}

int MathMod::memoryallocation(uint nbthreads, uint initparGrid, uint initisoGrid, int *pt)
{
    try
    {
        IsoObjet = new Iso3D(nbthreads, initisoGrid, pt);
        ParObjet = new Par3D(nbthreads, initparGrid, pt);
        return 1;
    }
    catch (const std::bad_alloc&)
    {
        message.setText("Not enough memory available to complete this operation");
        message.adjustSize();
        message.exec();
        return -1;
    }
}

void MathMod::SaveSceneAsObjPoly(int type)
{
    int startpl = 0;
    uint actualpointindice;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save OBJ file"), "",
                       tr("OBJ Files (*.obj)"));
    QFile data(fileName);
    if (data.open(QFile::ReadWrite | QFile::Truncate))
    {
        QTextStream stream(&data);
        stream.setRealNumberNotation(QTextStream::FixedNotation);
        stream.setRealNumberPrecision(3);
        // save vertices:
        if (type == 1)
        {
            for (uint i = 0; i < LocalScene.VertxNumber; i++)
            {
                (stream) << "v "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 7]) *
                                  (difMaximum*factx/ hauteur_fenetre) - decalage_xo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 8]) *
                                  (difMaximum*facty / hauteur_fenetre) - decalage_yo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 9]) *
                                  (difMaximum*factz / hauteur_fenetre) - decalage_zo)
                         << "  " << LocalScene.ArrayNorVer_localPt[10 * i] << "  "
                         << LocalScene.ArrayNorVer_localPt[10 * i + 1] << "  "
                         << LocalScene.ArrayNorVer_localPt[10 * i + 2] << "\n";
            }
        }
        else
        {
            for (uint i = 0; i < LocalScene.VertxNumber; i++)
            {
                (stream) << "v "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 7]) *
                                  (difMaximum*factx / hauteur_fenetre) - decalage_xo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 8]) *
                                  (difMaximum*facty / hauteur_fenetre) - decalage_yo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 9]) *
                                  (difMaximum*factz / hauteur_fenetre) - decalage_zo)
                         << "\n";
            }
        }
        // save faces:
        uint paramcomp= LocalScene.componentsinfos.ParametricGrid.size();
        if(LocalScene.typedrawing == 1)
        {
            startpl = LocalScene.PolyNumber;
            for (uint i = 0; i < LocalScene.NbPolygnNbVertexPtMin; i++)
            {
                uint polysize = LocalScene.PolyIndices_localPtMin[i];
                (stream) << "f";
                for (uint j = 0; j < polysize; j++)
                {
                    actualpointindice = LocalScene.PolyIndices_localPt[startpl++]+1;
                    (stream) << "  " << actualpointindice;
                }
                (stream) << "\n";
            }
        }
        else if(LocalScene.typedrawing == -1)
        {
            //**** Parametric components ***/
            uint ugrid=0;
            uint vgrid =0;
            uint index=0;
           for (uint p = 0; p < paramcomp; p += 2)
           {
                ugrid=LocalScene.componentsinfos.ParametricGrid[p];
                vgrid=LocalScene.componentsinfos.ParametricGrid[p+1];
                for (uint i = 0; i < ugrid-1; i ++)
                    for (uint j = 0; j < vgrid-1; j ++)
                {
                    (stream) << "f "
                             << "  " << (i*vgrid + j+index) +1<< "  "
                             << ((i+1)*vgrid + j+index) +1<< "  "
                             << ((i+1)*vgrid + (j+1)+index) +1<< "  "
                             << (i*vgrid + (j+1)+index) +1<< "\n";
                }
                index += ugrid*vgrid;
           }
        }
        else
        {
            //**** Parametric components ***/

            uint ugrid=0;
            uint vgrid =0;
            uint index=0;
            for (uint p = 0; p < paramcomp; p += 2)
            {
                 ugrid=LocalScene.componentsinfos.ParametricGrid[p];
                 vgrid=LocalScene.componentsinfos.ParametricGrid[p+1];
                 for (uint i = 0; i < ugrid-1; i ++)
                     for (uint j = 0; j < vgrid-1; j ++)
                 {
                     (stream) << "f "
                              << "  " << (i*vgrid + j+index) +1<< "  "
                              << ((i+1)*vgrid + j +index) +1<< "  "
                              << ((i+1)*vgrid + (j+1)+index) +1<< "  "
                              << (i*vgrid + (j+1)+index) +1<< "\n";
                 }
                 index += ugrid*vgrid;
            }
           // Isosurface components
           startpl = LocalScene.PolyNumber+LocalScene.componentsinfos.MinParametricMeshLines;
           uint kl=  LocalScene.componentsinfos.NbParametricMeshLines;
           for (uint i = kl; i < LocalScene.NbPolygnNbVertexPtMin; i++)
           {
               uint polysize = LocalScene.PolyIndices_localPtMin[i];
               (stream) << "f";
               for (uint j = 0; j < polysize; j++)
               {
                   actualpointindice = LocalScene.PolyIndices_localPt[startpl++]+1;
                   (stream) << "  " << actualpointindice;
               }
               (stream) << "\n";
           }
        }
    }
}

void MathMod::SaveSceneAsObjTrian(int type)
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
                                  (difMaximum*factx / hauteur_fenetre) - decalage_xo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 8]) *
                                  (difMaximum*facty / hauteur_fenetre) - decalage_yo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 9]) *
                                  (difMaximum*factz / hauteur_fenetre) - decalage_zo)
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
                                  (difMaximum*factx / hauteur_fenetre) - decalage_xo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 8]) *
                                  (difMaximum*facty / hauteur_fenetre) - decalage_yo)
                         << "  "
                         << float(double(LocalScene.ArrayNorVer_localPt[10 * i + 9]) *
                                  (difMaximum*factz / hauteur_fenetre) - decalage_zo)
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

MathMod::~MathMod()
{
    delete (timer);
    delete ParObjet;
    delete IsoObjet;
}

void MathMod::PutObjectInsideCube()
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
        oldminx = minx; oldminy = miny; oldminz=minz;
        oldmaxx = maxx; oldmaxy = maxy; oldmaxz=maxz;
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
        LocalScene.ArrayNorVer_localPt[10 * (NbVert+id) + 1] = 0.8f;
        LocalScene.ArrayNorVer_localPt[10 * (NbVert+id) + 2] = 0.8f;
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
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+0] = (id<2)?2.0f:0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+1] = (id>1)&&(id<4)?2.0f:0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+2] = (id>3)?2.0f:0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+3] = 1.0f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+7] = AxeArray[3*id  ];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+8] = AxeArray[3*id+1];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+id)+9] = AxeArray[3*id+2];
    }
    // Head of the X Axe
    XStartIndex = NbVert+12+60+6;
    for(uint id=0; id<6; id++)
    {
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+6+id)+0] = (id<2)?2.0f:0.3;
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
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+12+id)+1] = (id<2)?2.0f:0.3;
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
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+18+id)+2] = (id<2)?2.0f:0.3;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+18+id)+3] = 1.0f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+18+id)+7] = AxeArray[3*(id+18)  ];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+18+id)+8] = AxeArray[3*(id+18)+1];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+18+id)+9] = AxeArray[3*(id+18)+2];
    }
    // Letter X Axe
    XletterIndex = NbVert+12+60+24;
    for(uint id=0; id<4; id++)
    {
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+24+id)+0] = 2.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+24+id)+1] = 0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+24+id)+2] = 0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+24+id)+3] = 1.0f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+24+id)+7] = AxeArray[3*(id+24)  ];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+24+id)+8] = AxeArray[3*(id+24)+1];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+24+id)+9] = AxeArray[3*(id+24)+2];
    }
    // Letter Y Axe
    YletterIndex = NbVert+12+60+28;
    for(uint id=0; id<4; id++)
    {
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+28+id)+0] = 0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+28+id)+1] = 2.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+28+id)+2] = 0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+28+id)+3] = 1.0f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+28+id)+7] = AxeArray[3*(id+28)  ];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+28+id)+8] = AxeArray[3*(id+28)+1];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+28+id)+9] = AxeArray[3*(id+28)+2];
    }
    // Letter Y Axe
    ZletterIndex = NbVert+12+60+32;
    for(uint id=0; id<4; id++)
    {
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+32+id)+0] = 0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+32+id)+1] = 0.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+32+id)+2] = 2.0;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+32+id)+3] = 1.0f;
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+32+id)+7] = AxeArray[3*(id+32)  ];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+32+id)+8] = AxeArray[3*(id+32)+1];
        LocalScene.ArrayNorVer_localPt[10*(NbVert+12+60+32+id)+9] = AxeArray[3*(id+32)+2];
    }
    uint polynb=0;
    uint grid=0;
    if(LocalScene.typedrawing == -1)
    {
        uint sz = LocalScene.componentsinfos.ParametricGrid.size();

        for (uint p = 0; p < sz; p += 2)
        {
            grid= (LocalScene.componentsinfos.ParametricGrid[p]*LocalScene.componentsinfos.ParametricGrid[p+1]);
            if(grid!=0)
                polynb += (LocalScene.componentsinfos.ParametricGrid[p]-1) *
                            (LocalScene.componentsinfos.ParametricGrid[p+1]-1);
            else
                polynb +=0;
        }
    }
    else
        polynb = LocalScene.NbPolygnNbVertexPtMin;
  labelinfos = "";
  if((LocalScene.typedrawing == 1) || (LocalScene.typedrawing == -1))
  {
    labelinfos = "Grid[";
    (LocalScene.typedrawing == 1)
    ? labelinfos += QString::number(Xgrid - CutX) + "x" +
            QString::number(Ygrid - CutY) + "x" +
            QString::number(Zgrid - CutZ)+"]"
            : labelinfos += QString::number(Ugrid - CutU) + "x" +
                    QString::number(Vgrid - CutV)+"]";
  }
  labelinfos+=" Vertices["+QString::number(LocalScene.VertxNumber)+"]"+
                           " Triangls["+QString::number(LocalScene.PolyNumber/3)+"]"+
                           " Polygons["+QString::number(polynb)+"]";
  if(LocalScene.morph==-1)
       labelinfos+=" X["+QString::number(minx,'g',3)+","+QString::number(maxx,'g',3)+"]\
 Y["+QString::number(miny,'g',3)+","+QString::number(maxy,'g',3)+"]\
 Z["+QString::number(minz,'g',3)+","+QString::number(maxz,'g',3)+"]";
else
       labelinfos+=" X["+QString::number(oldminx,'g',3)+","+QString::number(oldmaxx,'g',3)+"]\
 Y["+QString::number(oldminy,'g',3)+","+QString::number(oldmaxy,'g',3)+"]\
 Z["+QString::number(oldminz,'g',3)+","+QString::number(oldmaxz,'g',3)+"]";

   if(LocalScene.typedrawing == 1)
   {
       IsoObjet->message = labelinfos + IsoObjet->message;
       IsoObjet->emitUpdateMessageSignal();
       IsoObjet->message = "";
   }
   else if(LocalScene.typedrawing == -1)
        {
           ParObjet->message = labelinfos + ParObjet->message;
           ParObjet->emitUpdateMessageSignal();
           ParObjet->message = "";
        }
       else
       {
           IsoObjet->message = labelinfos + " ISO:" + IsoObjet->message + " PAR:" + ParObjet->message;
           IsoObjet->emitUpdateMessageSignal();
           IsoObjet->message = "";
           ParObjet->message = "";
       }
}

void MathMod::png()
{
    LocalScene.png_ok *= -1;
}

void MathMod::jpg()
{
    LocalScene.jpg_ok *= -1;
}

void MathMod::bmp()
{
    LocalScene.bmp_ok *= -1;
}

void MathMod::quality(int c)
{
    LocalScene.quality_image = c;
}

void MathMod::colorstype(int c)
{
    LocalScene.colortype = c;
}

void MathMod::colorstypeParIso(int c)
{
    LocalScene.colortype = LocalScene.colortypeParam = c;
}

void MathMod::colorstypeParam(int c)
{
    LocalScene.colortypeParam = c;
}

void MathMod::redSpec(int cl)
{
    lightSpecular[0] = (cl/ 100.0f);
    LocalScene.ShininessValUpdated=true;
    update();
}

void MathMod::greenSpec(int cl)
{
    lightSpecular[1] = (cl/ 100.0f);
    LocalScene.ShininessValUpdated=true;
    update();
}

void MathMod::blueSpec(int cl)
{
    lightSpecular[2] = (cl/ 100.0f);
    LocalScene.ShininessValUpdated=true;
    update();
}

void MathMod::redAmb(int cl)
{
    lightAmbient[0] = (cl/ 100.0f);
    LocalScene.AmbientValUpdated=true;
    update();
}

void MathMod::greenAmb(int cl)
{
    lightAmbient[1] = (cl/ 100.0f);
    LocalScene.AmbientValUpdated=true;
    update();
}

void MathMod::blueAmb(int cl)
{
    lightAmbient[2] = (cl/100.0f);
    LocalScene.AmbientValUpdated=true;
    update();
}

void MathMod::transAmb(int cl)
{
    lightAmbient[3] = (cl/100.0f);
    LocalScene.AmbientValUpdated=true;
    update();
}

void MathMod::redDiff(int cl)
{
    lightDiffuse[0] = (cl/100.0f);
    LocalScene.DiffuseValUpdated=true;
    update();
}

void MathMod::greenDiff(int cl)
{
    lightDiffuse[1] = (cl/100.0f);
    LocalScene.DiffuseValUpdated=true;
    update();
}

void MathMod::blueDiff(int cl)
{
    lightDiffuse[2] = (cl/100.0f);
    LocalScene.DiffuseValUpdated=true;
    update();
}

void MathMod::transDiff(int cl)
{
    lightDiffuse[3] = (cl/ 100.0f);
    LocalScene.DiffuseValUpdated=true;
    update();
}

void MathMod::glfrontfacesupp(int val)
{
    LocalScene.glFrontFacingSupport = val;
    LocalScene.FrontSurfValUpdated=true;
    update();
}

void MathMod::drawCube()
{
    glLineWidth(1.0);
    glUniform1i(uniformThereisRGBA, 0);
    glDrawArrays(GL_LINE_STRIP,CubeStartIndex, 12);
    glUniform1i(uniformThereisRGBA, 1);
}

void MathMod::DrawPariso(ObjectProperties *scene, uint ParisoTypeIndex)
{
    uint idx = 0;
    for (uint i = 0; i < ParisoTypeIndex; i++)
        idx += scene->componentsinfos.NbComponentsType[i];
    int start_triangle = scene->componentsinfos.ParisoTriangle[2 * idx];
    float frontcl[4], backcl[4];
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(scene->polyfactor, scene->polyunits);
    if (!scene->componentsinfos.ThereisRGBA[ParisoTypeIndex])
    {
        for (uint j = 0; j < 4; j++)
        {
            frontcl[j] = scene->frontcols[j];
            backcl[j] = scene->backcols[j];
        }
        glUniform1i(uniformThereisRGBA, 1);
        glUniform1i(uniformHSVactive, 0);
        glUniform4fv(uniformFrontColor, 1, frontcl);
        glUniform4fv(uniformBackColor, 1, backcl);
    }
    else
    {
        if(scene->componentsinfos.hsv.size()>0)
            glUniform1i(uniformHSVactive, scene->componentsinfos.hsv[ParisoTypeIndex]?1:0);
        glUniform1i(uniformThereisRGBA, 0);
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
                    glUniform1i(uniformThereisRGBA, 1);
                    glUniform4fv(uniformFrontColor, 1, frontcl);
                    glUniform4fv(uniformBackColor, 1, backcl);
                }
                else
                {
                    glUniform1i(uniformThereisRGBA, 0);
                }
                size_t Offset = scene->componentsinfos.ParisoTriangle[2*(i+idx)]*sizeof( GL_FLOAT);
                glDrawElements(
                    GL_TRIANGLES,
                    int(3 * scene->componentsinfos.ParisoTriangle[2 * (i + idx) + 1]),GL_UNSIGNED_INT,(void *)(Offset));
            }
        }
    }
    glDisable(GL_POLYGON_OFFSET_FILL);
}

void MathMod::normOk()
{
    LocalScene.norm *= -1;
    update();
}

void MathMod::boundingboxOk()
{
    LocalScene.boundingbox *= -1;
}

void MathMod::run() {
    update();
}

bool MathMod::timeractif()
{
    return (LocalScene.anim == 1);
}

void MathMod::stoptimer()
{
    timer->stop();
    update();
}

void MathMod::starttimer()
{
    timer->start(latence,this);
}

void MathMod::restarttimer(int newlatence)
{
    latence = newlatence;
    if (LocalScene.anim == 1)
    {
        timer->stop();
        timer->start(latence, this);
    }
}

void MathMod::CreateShaderProgram()
{
    int IsCompiled_VS, IsCompiled_FS;
    GLuint vertexshader, fragmentshader;
    char *vertexInfoLog;
    char *fragmentInfoLog;
    char *shaderProgramInfoLog;
    int IsLinked;
    int maxLength;
    const int MAX_LENGTH = 2048;
    char log[MAX_LENGTH];
    int logLength = 0;
    bool shaderValid;

    shaderprogramId = glCreateProgram();
    //+++++++++++++++++++++++++++++++//
    //++++++++ Vertex shader ++++++++//
    //+++++++++++++++++++++++++++++++//
    vertexshader = glCreateShader(GL_VERTEX_SHADER);
    shaderValid = glIsShader(vertexshader);
    if (!shaderValid)
    {
        std::cout << "Could not create Vertex Shader!";
    }
    static const char *c_str_vertex =

            R"(
            #ifdef GL_ES
            precision mediump float;
            precision mediump int;
            #endif
            // uniforms
            uniform mat4 matrixModelView;
            uniform mat4 matrixNormal;
            uniform mat4 matrixModelViewProjection;
            uniform int glFrontFacing_1;
            // vertex attribs (input)
            attribute vec3 vertexPosition;
            attribute vec3 vertexNormal;
            attribute vec4 vertexColor;
            // varyings (output)
            varying vec3 esVertex, esNormal;
            varying vec4 color;
            varying vec4 v_position;
            void main()
            {
                esVertex = vec3(matrixModelView * vec4(vertexPosition, 1.0));
                esNormal = vec3(matrixNormal * vec4(vertexNormal, 1.0));
                color = vertexColor;
                if(glFrontFacing_1 == 0)
                {
                    v_position = -matrixModelView * vec4 (vertexPosition, 1.0);
                }
                gl_Position =  matrixModelViewProjection * vec4(vertexPosition, 1.0);
            }
            )";

/*
            R"(#version 300 es
            #ifdef GL_ES
            // Set default precision to medium
            precision mediump int;
            precision mediump float;
            #endif
            // uniforms
            uniform mat4 matrixModelView;
            uniform mat4 matrixNormal;
            uniform mat4 matrixModelViewProjection;
            uniform int glFrontFacing_1;
            // vertex attribs (input)
            in vec3 vertexPosition;
            in vec3 vertexNormal;
            in vec4 vertexColor;
            // varyings (output)
            out vec3 esVertex, esNormal;
            out vec4 color;
            out vec4 v_position;
            void main()
            {
                esVertex = vec3(matrixModelView * vec4(vertexPosition, 1.0));
                esNormal = vec3(matrixNormal * vec4(vertexNormal, 1.0));
                color = vertexColor;
                if(glFrontFacing_1 == 0)
                {
                    v_position = -matrixModelView * vec4 (vertexPosition, 1.0);
                }
                gl_Position =  matrixModelViewProjection * vec4(vertexPosition, 1.0);
            }
            )";
*/
    glShaderSource(vertexshader, 1, &c_str_vertex, NULL);
    glCompileShader(vertexshader);
    glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &IsCompiled_VS);
    if(IsCompiled_VS==GL_FALSE)
    {
       QMessageBox msgBox;
       glGetShaderiv(vertexshader, GL_INFO_LOG_LENGTH, &maxLength);
       vertexInfoLog = (char *)malloc(maxLength);
       glGetShaderInfoLog(vertexshader, maxLength, &maxLength, vertexInfoLog);
       std::string vertexInfoLogString = std::string(vertexInfoLog);
       msgBox.setText("Error : " +QString::fromStdString(std::string(vertexInfoLog)));
       msgBox.adjustSize();
       msgBox.exec();
    }

    //++++++++++++++++++++++++++//
    //++++++ Fragment shader +++//
    //++++++++++++++++++++++++++//
    fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
    shaderValid = glIsShader(fragmentshader);
    if (!shaderValid)
    {
        std::cout << "Could not create Fragment Shader!";
    }
    static const char *c_str_fragment =

            R"(
            #ifdef GL_ES
            precision mediump float;
            precision mediump int;
            #endif
            // uniforms
            uniform vec4 frontColor;
            uniform vec4 backColor;
            uniform vec4 gridColor;
            uniform vec4 lightPosition;
            uniform vec4 lightAmbient;
            uniform vec4 lightDiffuse;
            uniform vec4 lightSpecular;
            uniform int hsvactive;
            uniform int thereisRGBA;
            uniform int drawgridColor;
            uniform float shininess;
            uniform int glFrontFacing_2;
            // varyings
            varying vec3 esVertex, esNormal;
            varying vec4 color;
            varying vec4 v_position;

            // All components are in the range [0…1], including hue.
            vec3 hsv2rgb(vec3 c)
            {
                vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
                vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
                return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
            }

            void main()
            {
                vec4 color1=color;
                vec3 normal = normalize(esNormal);
                if(glFrontFacing_2 == 1)
                {
                    if(gl_FrontFacing == false)
                    {
                        normal *= -1.0;
                        if(thereisRGBA ==1)
                        {
                            color1=backColor;
                        }

                    }
                    else
                    {
                        if(thereisRGBA ==1)
                        {
                            color1=frontColor;
                        }
                    }
                }
                else
                {
                    if(dot(normal, v_position.xyz) <= 0.0)
                    {
                        normal *= -1.0;
                        if(thereisRGBA ==1)
                        {
                            color1=backColor;
                        }
                    }
                    else
                    {
                        if(thereisRGBA ==1)
                        {
                            color1=frontColor;
                        }
                    }
                }
                if(drawgridColor == 1)
                {
                    color1=gridColor;
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
                if(hsvactive == 1)
                    color1 = vec4(hsv2rgb(color1.xyz), color1.w);
                vec3 view = normalize(-esVertex);
                vec3 halfv = normalize(light + view);
                vec4 fragColor = lightAmbient * color1;
                float dotNL = max(dot(normal, light), 0.0);
                fragColor += lightDiffuse* color1 * dotNL;          // add diffuse
                float dotNH = max(dot(normal, halfv), 0.0);
                fragColor += (pow(dotNH, shininess) * lightSpecular) * color1; // add specular
                // set frag color
                //gl_FragColor = (hsvactive == 1)? vec4(hsv2rgb(fragColor.xyz), fragColor.w) : fragColor;
                gl_FragColor = fragColor;
            }
            )";

/*
            R"(#version 300 es
            #ifdef GL_ES
            // Set default precision to medium
            precision mediump int;
            precision mediump float;
            #endif
            // uniforms
            uniform vec4 frontColor;
            uniform vec4 backColor;
            uniform vec4 gridColor;
            uniform vec4 lightPosition;
            uniform vec4 lightAmbient;
            uniform vec4 lightDiffuse;
            uniform vec4 lightSpecular;
            uniform int hsvactive;
            uniform int thereisRGBA;
            uniform int drawgridColor;
            uniform float shininess;
            uniform int glFrontFacing_2;
            // varyings
            //layout(location=0) out vec3 esVertex;
            //layout(location=1) out vec3 esNormal;
            //layout(location=2) out vec4 color;
            //layout(location=3) out vec4 v_position;

            in vec3 esVertex, esNormal;
            in vec4 color, v_position;
            layout(location = 0) out vec4 fragColor;

            // All components are in the range [0…1], including hue.
            vec3 hsv2rgb(vec3 c)
            {
                vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
                vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
                return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
            }

            void main()
            {
                vec4 color1=color;
                vec3 normal = normalize(esNormal);
                if(glFrontFacing_2 == 1)
                {
                    if(gl_FrontFacing == false)
                    {
                        normal *= -1.0;
                        if(thereisRGBA ==1)
                        {
                            color1=backColor;
                        }

                    }
                    else
                    {
                        if(thereisRGBA ==1)
                        {
                            color1=frontColor;
                        }
                    }
                }
                else
                {
                    if(dot(normal, v_position.xyz) <= 0.0)
                    {
                        normal *= -1.0;
                        if(thereisRGBA ==1)
                        {
                            color1=backColor;
                        }
                    }
                    else
                    {
                        if(thereisRGBA ==1)
                        {
                            color1=frontColor;
                        }
                    }
                }
                if(drawgridColor == 1)
                {
                    color1=gridColor;
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
                if(hsvactive == 1)
                    color1 = vec4(hsv2rgb(color1.xyz), color1.w);
                vec3 view = normalize(-esVertex);
                vec3 halfv = normalize(light + view);
                fragColor = lightAmbient * color1;
                float dotNL = max(dot(normal, light), 0.0);
                fragColor += lightDiffuse* color1 * dotNL;          // add diffuse
                float dotNH = max(dot(normal, halfv), 0.0);
                fragColor += (pow(dotNH, shininess) * lightSpecular) * color1; // add specular
                // set frag color
                //gl_FragColor = (hsvactive == 1)? vec4(hsv2rgb(fragColor.xyz), fragColor.w) : fragColor;
                //gl_FragColor = fragColor;
            }
            )";
            */
    glShaderSource(fragmentshader, 1, &c_str_fragment, NULL);
    glCompileShader(fragmentshader);
    glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &IsCompiled_FS);
    if(IsCompiled_FS==GL_FALSE)
    {
        QMessageBox msgBox;
       glGetShaderiv(fragmentshader, GL_INFO_LOG_LENGTH, &maxLength);
       fragmentInfoLog = (char *)malloc(maxLength);
       glGetShaderInfoLog(fragmentshader, maxLength, &maxLength, fragmentInfoLog);
       std::string vertexInfoLogString = std::string(fragmentInfoLog);
       msgBox.setText("Error : " +QString::fromStdString(std::string(fragmentInfoLog)));
       msgBox.adjustSize();
       msgBox.exec();
    }
    glAttachShader(shaderprogramId, vertexshader);
    glAttachShader(shaderprogramId, fragmentshader);
    glBindAttribLocation(shaderprogramId, 0, "in_Position");
    glBindAttribLocation(shaderprogramId, 1, "in_Color");
    glLinkProgram(shaderprogramId);
    glGetProgramiv(shaderprogramId, GL_LINK_STATUS, (int *)&IsLinked);
    if(!IsLinked)
    {
       glGetProgramiv(shaderprogramId, GL_INFO_LOG_LENGTH, &maxLength);
       shaderProgramInfoLog = (char *)malloc(maxLength);
       glGetProgramInfoLog(shaderprogramId, maxLength, &maxLength, shaderProgramInfoLog);
    }
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
    uniformHSVactive                 = glGetUniformLocation(shaderprogramId, "hsvactive");
    uniformShininess                 = glGetUniformLocation(shaderprogramId, "shininess");
    uniformglFrontFacing_1           = glGetUniformLocation(shaderprogramId, "glFrontFacing_1");
    uniformglFrontFacing_2           = glGetUniformLocation(shaderprogramId, "glFrontFacing_2");
    uniformdrawgridColor             = glGetUniformLocation(shaderprogramId, "drawgridColor");
    attribVertexPosition             = glGetAttribLocation(shaderprogramId, "vertexPosition");
    attribVertexNormal               = glGetAttribLocation(shaderprogramId, "vertexNormal");
    attribVertexColor                = glGetAttribLocation(shaderprogramId, "vertexColor");
    glUniform4fv(uniformLightPosition, 1, lightPosition);
    glUniform4fv(uniformLightAmbient, 1, lightAmbient);
    glUniform4fv(uniformLightDiffuse, 1, lightDiffuse);
    glUniform4fv(uniformLightSpecular, 1, lightSpecular);
    glUniform4fv(uniformFrontColor, 1, frontColor);
    glUniform4fv(uniformBackColor, 1, backColor);
    glUniform4fv(uniformGridColor, 1, gridcol);
    glUniform1f(uniformShininess, shininessVal);
    glUniform1i(uniformglFrontFacing_1, LocalScene.glFrontFacingSupport);
    glUniform1i(uniformglFrontFacing_2, LocalScene.glFrontFacingSupport);
    glUniform1i(uniformThereisRGBA, 0);
    glUniform1i(uniformHSVactive, 0);
    glUniform1i(uniformdrawgridColor, 0);
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

void MathMod::proj()
{
    qreal aspect = qreal(screenWidth) / qreal(screenHeight ? screenHeight : 1);
    const qreal zNear = 0.01, zFar = 15, fov = 60.0;
    matrixProjectionx.setToIdentity();
    matrixProjectionx.perspective(fov, aspect, zNear, zFar);
}

void MathMod::LoadShadersFiles()
{
    CreateShaderProgram();
}

void MathMod::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glFrontFace(GL_CCW);
    glClearColor(0, 0, 0, 0);
    proj();
}

void MathMod::resizeGL(int newwidth, int newheight)
{
    screenWidth = newwidth;
    screenHeight = newheight;
    proj();
}

void MathMod::anim()
{
    LocalScene.anim *= -1;
    if (LocalScene.anim == 1)
    {
        timer->start(latence, this);
    }
    else
    {
        oldRotation = rotation;
        if (LocalScene.morph == -1)
        {
            stoptimer();
        }
    }
}

void MathMod::morph()
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
    {
        timer->start(latence, this);
    }
    else
    {
        if (LocalScene.anim == -1)
        {
            stoptimer();
        }
    }
}

void MathMod::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    switch (key)
    {
    case Qt::CTRL|Qt::Key_A:
        anim();
        break;
    case Qt::CTRL|Qt::Key_P:
        morph();
        break;
    }
    update();
}
void MathMod::FillOk()
{
    LocalScene.fill *= -1;
    update();
}

void MathMod::DrawAxe()
{
    glLineWidth(1.0);
    glUniform1i(uniformThereisRGBA, 0);
    glUniform1i(uniformHSVactive, 0);
    // Draw the three axes (lines without head)
    glDrawArrays(GL_LINES,AxesStartIndex,6);
    // Head of the X Axe:
    glDrawArrays(GL_TRIANGLE_FAN,XStartIndex,6);
    // Head of the Y Axe:
    glDrawArrays(GL_TRIANGLE_FAN,YStartIndex,6);
    // Head of the Z Axe:
    glDrawArrays(GL_TRIANGLE_FAN,ZStartIndex,6);
    glLineWidth(3.0);
    // Draw the X axe
    glDrawArrays(GL_LINES,XletterIndex,4);
    // Draw the Y axe
    glDrawArrays(GL_LINES,YletterIndex,4);
    // Draw the Z axe
    glDrawArrays(GL_LINE_STRIP,ZletterIndex,4);
    glUniform1i(uniformThereisRGBA, 1);
}

void MathMod::DrawNormals(ObjectProperties *)
{
}

void MathMod::Winitialize_GL()
{
    if (LocalScene.componentsinfos.updateviewer)
    {
        PutObjectInsideCube();
        PutObjectInsideCubeOk=true;
    }
    // check OpenGL error
    GLenum myGLEnum;
    while ((myGLEnum = glGetError()) != GL_NO_ERROR) {
        qDebug("Error_10 : ");
        /*QMessageBox msgBox;
        qDebug("Error_10: ");
        msgBox.setText("Error_10 : " + QString::number(myGLEnum));
        msgBox.adjustSize();
        msgBox.exec();*/
    }
}

void MathMod::UpdateGL()
{
    if (LocalScene.updategl)
    {
        Winitialize_GL();
        update();
    }
    else
        LocalScene.updategl = true;
}

void MathMod::DrawParisoCND(ObjectProperties *scene, uint compindex)
{
    uint idx = 0;
    for (uint i = 0; i < compindex; i++)
        idx += scene->componentsinfos.NbComponentsType[i];
    int start_triangle = scene->componentsinfos.ParisoTriangle[2 * idx];
    glUniform1i(uniformThereisRGBA, 0);
    glUniform1i(uniformHSVactive, 0);
    if (scene->cndoptions[3])
    {
        size_t Offset0 = (3 * scene->componentsinfos.NbTrianglesNoCND[compindex] + start_triangle)*sizeof( GL_FLOAT);
        glLineWidth(0.3);
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
        for (uint i = 0; i < (3 * scene->componentsinfos.NbTrianglesBorderCND[compindex]); i += 3)
        {
            glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, (void *)(Offset2));
            Offset2+=(3*sizeof( GL_FLOAT));
        }
    }
    glUniform1i(uniformThereisRGBA, 1);
}

void MathMod::DrawTrianglMesh(ObjectProperties *scene)
{
    size_t Offset = 0;
    uint st = 0;
    glUniform4fv(uniformGridColor, 1, scene->gridcol);
    glUniform1i(uniformdrawgridColor, 1);
    glUniform1i(uniformThereisRGBA, 0);
    glUniform1i(uniformHSVactive, 0);
    glLineWidth(0.3);
    for (uint i = 0; i < scene->PolyNumber; i += 3)
    {
        Offset = st*sizeof( GL_FLOAT);
        glDrawElements(GL_LINE_LOOP, 3, GL_UNSIGNED_INT, (void *)(Offset));
        st+=3;
    }
    glUniform1i(uniformdrawgridColor, 0);
    glUniform1i(uniformThereisRGBA, 1);
}

void MathMod::DrawMinimalTopology(ObjectProperties *scene)
{
    glUniform4fv(uniformGridColor, 1,scene->gridcol);
    glUniform1i(uniformdrawgridColor, 1);
    glUniform1i(uniformThereisRGBA, 0);
    glUniform1i(uniformHSVactive, 0);
    glLineWidth(0.4);
    uint st = scene->PolyNumber;
    uint polysize=0;
    size_t Offset;
    if(scene->typedrawing == -1)
    for (uint i = 0; i < (scene->NbPolygnNbVertexPtMin); i++)
    {
        polysize = scene->PolyIndices_localPtMin[i];
        Offset = st*sizeof( GL_FLOAT);
            glDrawElements(
                GL_LINE_STRIP,
                polysize,
                GL_UNSIGNED_INT,
                (void *)(Offset));
        st+=(polysize);
    }
    else
    if(scene->typedrawing == 1)
        for (uint i = 0; i < (scene->NbPolygnNbVertexPtMin); i++)
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
    else
    {
        uint kl=  scene->componentsinfos.NbParametricMeshLines;
        for (uint i = 0; i < (scene->NbPolygnNbVertexPtMin); i++)
        {
            polysize = scene->PolyIndices_localPtMin[i];
            Offset = st*sizeof( GL_FLOAT);
                glDrawElements(
                    (i<kl)? GL_LINE_STRIP:GL_LINE_LOOP,
                    polysize,
                    GL_UNSIGNED_INT,
                    (void *)(Offset));
            st+=(polysize);
        }
    }
    glUniform1i(uniformdrawgridColor, 0);
    glUniform1i(uniformThereisRGBA, 1);
}

void MathMod::plan()
{
    glUniform1i(uniformThereisRGBA, 0);
    glUniform1i(uniformHSVactive, 0);
    glLineWidth(0.3);
    glDrawArrays(GL_LINES,PlanStartIndex,60);
    glUniform1i(uniformThereisRGBA, 1);
}

void MathMod::CopyData(ObjectProperties *scene)
{
    static int firstaction=0;
    static uint previousVertxNumber=0;
    static uint previousPolyNumberNbPolygnNbVertexPtMin=0;
    if(firstaction==0)
    {
        vbo[0]=vbo[1]=0;
        glGenBuffers(2, vbo);
        /* Bind our first VBO as being the active buffer and storing vertex attributes (coordinates) */
        glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT)*10*(scene->VertxNumber+(12+60+36)),scene->ArrayNorVer_localPt, GL_STATIC_DRAW);
        //glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
        /* Bind our first VBO as being the active buffer and storing vertex attributes (coordinates) */
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*(scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize), scene->PolyIndices_localPt, GL_STATIC_DRAW);
        size_t cOffset = 0;
        size_t nOffset = cOffset + 4*sizeof( GL_FLOAT);
        size_t vOffset = nOffset + 3*sizeof (GL_FLOAT);
        // activate attribs
        glEnableVertexAttribArray(attribVertexColor);
        glEnableVertexAttribArray(attribVertexNormal);
        glEnableVertexAttribArray(attribVertexPosition);
        // set attrib arrays using glVertexAttribPointer()
        glVertexAttribPointer(attribVertexPosition, 3, GL_FLOAT, false, 10*sizeof( GL_FLOAT), (void*)vOffset);
        glVertexAttribPointer(attribVertexColor,4, GL_FLOAT, false, 10*sizeof( GL_FLOAT), (void*)cOffset);
        glVertexAttribPointer(attribVertexNormal, 3, GL_FLOAT, false, 10*sizeof( GL_FLOAT), (void*)nOffset);
        previousVertxNumber = scene->VertxNumber;
        previousPolyNumberNbPolygnNbVertexPtMin = (scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize);
        firstaction++;
    }
    else
    {
        glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
        if(scene->VertxNumber>previousVertxNumber>0)
        {
            glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT)*10*(scene->VertxNumber+(12+60+36)), scene->ArrayNorVer_localPt, GL_STATIC_DRAW);
            previousVertxNumber = scene->VertxNumber;
        }
        else
        {
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(GL_FLOAT)*10*(scene->VertxNumber+(12+60+36)), (void *)scene->ArrayNorVer_localPt);
            previousVertxNumber = scene->VertxNumber;
        }

        if((scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize)>previousPolyNumberNbPolygnNbVertexPtMin)
        {
            glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLuint)*(scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize), scene->PolyIndices_localPt, GL_STATIC_DRAW);
            previousPolyNumberNbPolygnNbVertexPtMin =  (scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize);
        }
        else
        {
            glBufferSubData(GL_ELEMENT_ARRAY_BUFFER,0, sizeof(GLuint)*(scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize), scene->PolyIndices_localPt);
            previousPolyNumberNbPolygnNbVertexPtMin =  (scene->PolyNumber + scene->NbPolygnNbVertexPtMinSize);
        }
    }
}

void MathMod::draw(ObjectProperties *scene)
{
    if(!PutObjectInsideCubeOk)
        return;

    if (scene->componentsinfos.Interleave)
    {
        CopyData(scene);
        scene->componentsinfos.Interleave = false;
    }
    glUseProgram(shaderprogramId);
    // clear buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // set modelview matrix
    matrixViewx.setToIdentity();
    matrixViewx.translate(0.0, 0.0, -cameraDistance);
    matrixViewx.rotate(rotation);
    matrixModelViewProjectionx = matrixProjectionx * matrixViewx;
    matrixNormalx=matrixViewx;
    matrixNormalx.setColumn(3, QVector4D(0,0,0,1));
    glUniformMatrix4fv(uniformMatrixModelView, 1, false, matrixViewx.data());
    glUniformMatrix4fv(uniformMatrixModelViewProjection, 1, false, matrixModelViewProjectionx.data());
    glUniformMatrix4fv(uniformMatrixNormal, 1, false, matrixNormalx.data());
    if(LocalScene.ShininessValUpdated)
    {
        glUniform1f(uniformShininess, shininessVal);
        glUniform4fv(uniformLightSpecular, 1, lightSpecular);
        LocalScene.ShininessValUpdated =false;
    }
    if(LocalScene.AmbientValUpdated)
    {
        glUniform4fv(uniformLightAmbient, 1, lightAmbient);
        LocalScene.AmbientValUpdated =false;
    }
    if(LocalScene.DiffuseValUpdated)
    {
        glUniform4fv(uniformLightDiffuse, 1, lightDiffuse);
        LocalScene.DiffuseValUpdated =false;
    }
    if(LocalScene.FrontSurfValUpdated)
    {
        glUniform1i(uniformglFrontFacing_1 , LocalScene.glFrontFacingSupport);
        glUniform1i(uniformglFrontFacing_2 , LocalScene.glFrontFacingSupport);
        LocalScene.FrontSurfValUpdated = false;
    }
    // We draw the Plan first because we don't want it to spin around X,Y and Z axes
    if (scene->plan == 1)
        plan();
    if(LocalScene.animx==1)
        matrixViewx.rotate(rotationx);
    if(LocalScene.animy==1)
        matrixViewx.rotate(rotationy);
    if(LocalScene.animz==1)
        matrixViewx.rotate(rotationz);
    if(LocalScene.animx==1 || LocalScene.animy==1 || LocalScene.animz==1)
    {
        matrixModelViewProjectionx = matrixProjectionx * matrixViewx;
        matrixNormalx=matrixViewx;
        matrixNormalx.setColumn(3, QVector4D(0,0,0,1));
        glUniformMatrix4fv(uniformMatrixModelView, 1, false, matrixViewx.data());
        glUniformMatrix4fv(uniformMatrixModelViewProjection, 1, false, matrixModelViewProjectionx.data());
        glUniformMatrix4fv(uniformMatrixNormal, 1, false, matrixNormalx.data());
    }
    // Blend Effect activation:
    if (scene->transparency == 1)
        glDepthMask(GL_FALSE);

    // Axe :
    if (scene->axe == 1)
        DrawAxe();

    if (scene->fill == 1 && scene->componentsinfos.updateviewer)
        for (uint i = 0; i < scene->componentsinfos.NbComponentsType.size(); i++)
            DrawPariso(scene, i);

    // Draw Mesh Object:
    if (scene->triangles == 1 && scene->componentsinfos.updateviewer)
        DrawTrianglMesh(scene);

    // Bounding Box:
    if (scene->boundingbox == 1)
        drawCube();

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
}

void MathMod::paintGL()
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
    if (LocalScene.morph == 1 && LocalScene.frame == 1)
        FramesSave();
}

void MathMod::timerEvent(QTimerEvent *)
{
    if(LocalScene.anim == 1)
    {
        if(LocalScene.animx==1)
        {
            rotationx = rotationx*QQuaternion::fromAxisAndAngle(QVector3D(1.0,0.0,0.0), LocalScene.animxValueStep);
        }
        if(LocalScene.animy==1)
        {
            rotationy = rotationy*QQuaternion::fromAxisAndAngle(QVector3D(0.0,1.0,0.0), LocalScene.animyValueStep);
        }
        if(LocalScene.animz==1)
        {
            rotationz = rotationz*QQuaternion::fromAxisAndAngle(QVector3D(0.0,0.0,1.0), LocalScene.animzValueStep);
        }
        if(LocalScene.animxyz == 1)
            rotation = QQuaternion::fromAxisAndAngle(n, acc/10) * rotation;
        oldRotation = rotation;
    }
    update();
}

void MathMod::mouseReleaseEvent(QMouseEvent *)
{
    if(LocalScene.anim != 1)
        oldRotation = rotation;
}

void MathMod::mousePressEvent(QMouseEvent *e)
{
    // Save mouse press position
    mousePressPosition = QVector2D(e->pos());
    if(LocalScene.anim != 1)
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
    if (e->button() == Qt::MiddleButton)
        btmilieu = 1;
    else
        btmilieu = 0;

    mouseY = e->pos().y()/2;
}

void MathMod::mouseMoveEvent(QMouseEvent *e)
{
    static int oldx=0, oldy=0;
    static QVector3D oldn=QVector3D(0,0,1);
    if(mouseLeftDown)
    {
        QVector2D diff = QVector2D(e->pos()) - mousePressPosition;
        // Rotation axis is perpendicular to the mouse position difference
        n = QVector3D(diff.y(), diff.x(), 0.0).normalized();
        // Accelerate angular speed relative to the length of the mouse sweep
        acc =std::sqrt((diff.y()-oldy)*(diff.y()-oldy)+ float(diff.x()-oldx)*(diff.x()-oldx))/ /*(double)(LocalScene.viewport[2]+1)*/3.0;
        // Calculate new rotation axis
        rotation = QQuaternion::fromAxisAndAngle(n, acc)*oldRotation;
        oldn = n;
    }
    if(mouseRightDown)
    {
        cameraDistance -= (e->pos().y()/2 - mouseY) * 0.02f;
        mouseY = e->pos().y()/2;
    }
    update();
}

bool MathMod::gestureEvent(QGestureEvent *event)
{
    if (QGesture *pinch = event->gesture(Qt::PinchGesture))
        pinchTriggered(static_cast<QPinchGesture *>(pinch));
    return true;
}
qreal scaleFactor = 1;
void MathMod::pinchTriggered(QPinchGesture *gesture)
{
    QPinchGesture::ChangeFlags changeFlags = gesture->changeFlags();
    if (changeFlags & QPinchGesture::ScaleFactorChanged) {
            scaleFactor = gesture->scaleFactor();
            if(scaleFactor != 0.0f)
                cameraDistance /= scaleFactor;
    }
    update();
}
void MathMod::grabGestures(const QList<Qt::GestureType> &gestures)
{
    //! [enable gestures]
    for (Qt::GestureType gesture : gestures)
        grabGesture(gesture);
    //! [enable gestures]
}

//! [event handler]
bool MathMod::event(QEvent *event)
{
    if (event->type() == QEvent::Gesture)
        return gestureEvent(static_cast<QGestureEvent*>(event));
    return QWidget::event(event);
}
//! [event handler]
void MathMod::screenshot()
{
    QImage image = QOpenGLWidget::grabFramebuffer();
    if (LocalScene.png_ok == 1)
        image.save("GLscreenshot.png", "PNG", LocalScene.quality_image);
    if (LocalScene.bmp_ok == 1)
        image.save("GLscreenshot.bmp", "BMP", LocalScene.quality_image);
}

void MathMod::FramesShot()
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

void MathMod::FramesSave()
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

QImage MathMod::Copyscreenshot()
{
    return (QOpenGLWidget::grabFramebuffer());
}

void MathMod::transparency(int cl, int currentposition)
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

void MathMod::red(int cl, int currentposition)
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

void MathMod::green(int cl, int currentposition)
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

void MathMod::blue(int cl, int currentposition)
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

void MathMod::transSpec(int cl)
{
    lightSpecular[3] = (cl/ 100.0f);
    LocalScene.ShininessValUpdated=true;
    update();
}

void MathMod::Shininess(int cl)
{
    shininessVal= GLfloat(cl);
    LocalScene.ShininessValUpdated=true;
    update();
}

void MathMod::InitSpecularParameters()
{
    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CCW);
    update();
}

MathMod::MathMod(QWidget *parent, uint nbthreads,
                 uint initparGrid, uint initisoGrid, int * pt) :QOpenGLWidget(parent)
{
    //PerlinNoise = new ImprovedNoise(4., 4., 4.);
    latence = 10;
    Vgrid = Ugrid = 64;
    CutV = CutU = 0;
    Xgrid = Ygrid = Zgrid = 64;
    CutX = CutY = CutZ = 0;
    LocalScene.VertxNumber = 0;
    FramesDir = "/home";
    hauteur_fenetre = 2*wh;
    timer = new QBasicTimer();
    xyzactivated = uvactivated = uvactivated4D = 1;
    if (memoryallocation(nbthreads, initparGrid, initisoGrid, pt) != 1)
        exit(0);
}

void MathMod::fill()
{
    FillOk();
    update();
}

void MathMod::updateGL()
{
    update();
}

void MathMod::draw_norm_clicked()
{
    normOk();
}

void MathMod::frames_clicked()
{
    FramesShot();
}

void MathMod::linecolumn_valueupdate(int cl)
{
    ParObjet->Vgrid = Vgrid = ParObjet->Ugrid = Ugrid = uint(cl);
    ParObjet->masterthread->Ugrid =
        ParObjet->masterthread->Vgrid = uint(cl);

    for (uint nbthreads = 0;
            nbthreads < ParObjet->WorkerThreadsNumber - 1;
            nbthreads++)
    {
        ParObjet->workerthreads[nbthreads].Ugrid =
            ParObjet->workerthreads[nbthreads].Vgrid = uint(cl);
    }
}

void MathMod::line_valueupdate(int cl)
{
    ParObjet->Ugrid = Ugrid = ParObjet->masterthread->Ugrid = uint(cl);
    for (uint nbthreads = 0;
            nbthreads < ParObjet->WorkerThreadsNumber - 1;
            nbthreads++)
    {
        ParObjet->workerthreads[nbthreads].Ugrid = uint(cl);
    }
}

void MathMod::column_valueupdate(int cl)
{
    ParObjet->Vgrid = Vgrid = ParObjet->masterthread->Vgrid = uint(cl);

    for (uint nbthreads = 0;
            nbthreads < ParObjet->WorkerThreadsNumber - 1;
            nbthreads++)
    {
        ParObjet->workerthreads[nbthreads].Vgrid = uint(cl);
    }
}

void MathMod::linecolumn_valueChanged(int cl, ModelType type)
{
    linecolumn_valueupdate(cl);
    if (uvactivated == 1)
        (type == PARISO_TYPE) ? ParisoObjectProcess():ParametricSurfaceProcess(1);
    else
        update();
}

void MathMod::line_valueChanged(int cl)
{
    line_valueupdate(cl);
    if (uvactivated == 1)
        ParametricSurfaceProcess(1);
    else
        update();
}

void MathMod::column_valueChanged(int cl)
{
    column_valueupdate(cl);
    if (uvactivated == 1)
        ParametricSurfaceProcess(1);
    else
        update();
}

void MathMod::linecolumn_valueChanged_2(int cl)
{
    linecolumn_valueupdate(cl);
    if (uvactivated4D == 1)
        ParametricSurfaceProcess(3);
    else
        update();
}

void MathMod::Initparametricpage()
{
    LocalScene.typedrawing = -1;
}

void MathMod::xyzg_valueupdate(int cl)
{
    IsoObjet->masterthread->XYZgrid = uint(cl);
    Xgrid = Ygrid = Zgrid = cl;
}

void MathMod::xyzg_valueChanged(int cl, ModelType type)
{
    xyzg_valueupdate(cl);
    // process the new surface
    if (xyzactivated == 1)
        (type == PARISO_TYPE) ? ParisoObjectProcess() : ProcessNewIsoSurface();
}

void MathMod::ShowErrormessage()
{
    message.setTextFormat(Qt::RichText);
    int before, after;
    QString sortie = QString::fromStdString(stError.strError);
    if (sortie.length() > (stError.iErrorIndex + 20))
        after = 20;
    else
        after = sortie.length() - stError.iErrorIndex;
    sortie.truncate(stError.iErrorIndex + after);
    if (stError.iErrorIndex - 20 > 0)
        before = 20;
    else
        before = 0;
    sortie = sortie.remove(0, stError.iErrorIndex - before);
    sortie.replace("\t", " ");
    sortie.replace("\n", " ");
    sortie.insert(before, " <font color=#FF3300> -> </font>");
    message.setText(" <font color=#FF6600> Error Type: </font>"+QString::fromStdString(stError.ErrorType)
                    +"<br><font color=#FF6600> Error position: </font>" + QString::number(stError.iErrorIndex)
                    +"<br><font color=#FF6600> Error Localization: </font>..."+ sortie +"...");
    message.adjustSize();
    message.exec();
    return;
}

int MathMod::ParsePar()
{
    stError = ParObjet->masterthread->parse_expression();
    if (stError.iErrorIndex >= 0)
    {
        ShowErrormessage();
        return -1;
    }
    else
        ParObjet->ThreadParsersCopy();
    return 1;
}

void MathMod::ParametricSurfaceProcess(int type)
{
    if (!ParObjet->isRunning())
    {
        if (type == 3)
        {
            ParObjet->masterthread->param4D = true;
            ParObjet->param4D = true;
            ParObjet->masterthread->param3d_C = false;
        }
        else
        {
            ParObjet->masterthread->param4D = false;
            ParObjet->param4D = false;
            ParObjet->masterthread->param4d_C = false;
        }
        int result = ParsePar();
        if (result == -1)
            return;
        LocalScene.typedrawing = -1;
        ParObjet->localScene = &(LocalScene);
        ParObjet->start(QThread::LowPriority);
    }
}

void MathMod::ParisoObjectProcess()
{
    LocalScene.typedrawing = 0;
    LocalScene.updategl = false;
    LocalScene.componentsinfos.pariso = true;

    if (!ParObjet->isRunning())
    {
        ParObjet->masterthread->param4D =
            ParObjet->param4D = false;
        ParObjet->masterthread->param4d_C =
        ParObjet->masterthread->param3d_C = false;
        int result = ParsePar();
        if (result == -1)
            return;
        ParObjet->localScene = &(LocalScene);
        ParObjet->start(QThread::LowPriority);
        ParObjet->wait();
    }
    if (!IsoObjet->isRunning())
    {
        int result = ParseIso();
        if (result == -1)
            return;
        IsoObjet->localScene = &(LocalScene);
        IsoObjet->start(QThread::LowPriority);
    }
}

int MathMod::ParseIso()
{
    stError = IsoObjet->masterthread->ParserIso();
    if (stError.iErrorIndex >= 0)
    {
        ShowErrormessage();
        return -1;
    }
    else
        IsoObjet->ThreadParsersCopy();
    return 1;
}

void MathMod::ProcessNewIsoSurface()
{
    if (!IsoObjet->isRunning())
    {
        int result = ParseIso();
        if (result == -1)
            return;
        LocalScene.typedrawing = 1;
        IsoObjet->localScene = &(LocalScene);
        IsoObjet->start(QThread::LowPriority);
    }
}

void MathMod::slot_checkBox73_clicked(ModelType type)
{
    xyzactivated *= -1;
    // process the new surface
    if (xyzactivated == 1)
        (type == PARISO_TYPE) ? ParisoObjectProcess() : ProcessNewIsoSurface();
}

void MathMod::slot_uv_clicked(ModelType type)
{
    uvactivated *= -1;
    // process the new surface
    if (uvactivated == 1)
        (type == PARISO_TYPE) ? ParisoObjectProcess() : ParametricSurfaceProcess(1);
}

void MathMod::slot_uv4D_clicked()
{
    uvactivated4D *= -1;
    // process the new surface
    if (uvactivated4D == 1)
        ParametricSurfaceProcess(3);
}

void MathMod::slot_triangles_clicked()
{
    LocalScene.triangles *= -1;
    update();
}

void MathMod::Mesh()
{
    LocalScene.mesh *= -1;
    update();
}

int MathMod::TorsionIso()
{
    stError = IsoObjet->IsoTorsion();
    if (stError.iErrorIndex >= 0)
    {
        ShowErrormessage();
        return -1;
    }
    return 1;
}

void MathMod::TorsionIsoSurface()
{
    if (!IsoObjet->isRunning())
    {
        TorsionIso();
        LocalScene.typedrawing = 1;
        IsoObjet->localScene = &(LocalScene);
        IsoObjet->start(QThread::LowPriority);
    }
}

int MathMod::ThickIso()
{
    stError = IsoObjet->AddThickness();
    if (stError.iErrorIndex >= 0)
    {
        ShowErrormessage();
        return -1;
    }
    return 1;
}

void MathMod::AddThicknessToIsoSurface()
{
    if (!IsoObjet->isRunning())
    {
        ThickIso();
        LocalScene.typedrawing = 1;
        IsoObjet->localScene = &(LocalScene);
        IsoObjet->start(QThread::LowPriority);
    }
}

int MathMod::ScaleIso()
{
    stError = IsoObjet->ScaleIso();
    if (stError.iErrorIndex >= 0)
    {
        ShowErrormessage();
        return -1;
    }
    return 1;
}

void MathMod::ScaleIsoSurface()
{
    if (!IsoObjet->isRunning())
    {
        ScaleIso();
        LocalScene.typedrawing = 1;
        IsoObjet->localScene = &(LocalScene);
        IsoObjet->start(QThread::LowPriority);
    }
}

