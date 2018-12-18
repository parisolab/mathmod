/***************************************************************************
 *   Copyright (C) 2018 by Abderrahman Taha                                *
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
#include <QTextStream>
#include <QFileDialog>
#include "glviewer.h"
#include "raster.h"


static int TypeDrawin=10;
static int TypeDrawinNormStep = 4;
int FistTimecalibrate =-1;
static double hauteur_fenetre, difMaximum, decalage_xo, decalage_yo, decalage_zo;


GLfloat minx   = 999999999,  miny  = 999999999,  minz  = 999999999,
        maxx =-999999999,   maxy =-999999999, maxz =-999999999,
        difX, difY, difZ;


void OpenGlWidget::CalculateTexturePoints(int type)
{
    double tmp, val[6];
    int Jprime;
    LocalScene.componentsinfos.ThereisRGBA = true;
    LocalScene.componentsinfos.NoiseParam.NoiseType = 1; //Texture

    if(type == 1)
    {
        LocalScene.componentsinfos.NoiseParam.RgbtParser = IsoObjetThread->IsoObjet->masterthread->RgbtParser;
        LocalScene.componentsinfos.NoiseParam.NoiseParser = IsoObjetThread->IsoObjet->masterthread->NoiseParser;
        IsoObjetThread->IsoObjet->masterthread->Noise == "" ? LocalScene.componentsinfos.NoiseParam.NoiseShape = 0: LocalScene.componentsinfos.NoiseParam.NoiseShape = 1;
    }
    else
    {
        LocalScene.componentsinfos.NoiseParam.RgbtParser = ParObjetThread->ParObjet->masterthread->RgbtParser;
        LocalScene.componentsinfos.NoiseParam.NoiseParser = ParObjetThread->ParObjet->masterthread->NoiseParser;
        ParObjetThread->ParObjet->masterthread->Noise == "" ? LocalScene.componentsinfos.NoiseParam.NoiseShape = 0: LocalScene.componentsinfos.NoiseParam.NoiseShape = 1;
    }

    for(unsigned int i =0; i < LocalScene.VertxNumber; i++)
    {
        val[0]= difMaximum*LocalScene.ArrayNorVer_localPt[i*TypeDrawin  + 3 + TypeDrawinNormStep]/hauteur_fenetre -decalage_xo;
        val[1]= difMaximum*LocalScene.ArrayNorVer_localPt[i*TypeDrawin  + 4 + TypeDrawinNormStep]/hauteur_fenetre -decalage_yo;
        val[2]= difMaximum*LocalScene.ArrayNorVer_localPt[i*TypeDrawin  + 5 + TypeDrawinNormStep]/hauteur_fenetre -decalage_zo;

        if(type != 1)
        {
            Jprime = (i) %  (ParObjetThread->ParObjet->Vgrid);
            val[3] = (double)Jprime/(double)(ParObjetThread->ParObjet->Vgrid) ;
            val[3] = val[3] * ParObjetThread->ParObjet->masterthread->dif_u[0]  + ParObjetThread->ParObjet->masterthread->u_inf[0];

            Jprime = (i)/(ParObjetThread->ParObjet->Ugrid);
            val[4] = (double)Jprime/(double)(ParObjetThread->ParObjet->Ugrid) ;
            val[4] = val[4] * ParObjetThread->ParObjet->masterthread->dif_v[0]  + ParObjetThread->ParObjet->masterthread->v_inf[0];
        }

        if(LocalScene.componentsinfos.NoiseParam.NoiseShape != 0 && LocalScene.componentsinfos.NoiseParam.NoiseActive == 1)
        {
            tmp  = LocalScene.componentsinfos.NoiseParam.NoiseParser->Eval(val);
        }
        else
        {
            tmp =1.0;
        }

        val[0] *= tmp;
        val[1] *= tmp;
        val[2] *= tmp;
        val[3] *= tmp;
        val[4] *= tmp;

        LocalScene.ArrayNorVer_localPt[i*TypeDrawin     ] = LocalScene.componentsinfos.NoiseParam.RgbtParser[0].Eval(val);
        LocalScene.ArrayNorVer_localPt[i*TypeDrawin +1] = LocalScene.componentsinfos.NoiseParam.RgbtParser[1].Eval(val);
        LocalScene.ArrayNorVer_localPt[i*TypeDrawin +2] = LocalScene.componentsinfos.NoiseParam.RgbtParser[2].Eval(val);
        LocalScene.ArrayNorVer_localPt[i*TypeDrawin +3] = LocalScene.componentsinfos.NoiseParam.RgbtParser[3].Eval(val);
    }
}

void OpenGlWidget::CalculatePigmentPoints(int type)
{
    double tmp, ValCol[100], val[4];
    LocalScene.componentsinfos.ThereisRGBA = true;
    LocalScene.componentsinfos.NoiseParam.NoiseType = 0; //Pigments
    if(type == 1)
    {
        LocalScene.componentsinfos.NoiseParam.VRgbtParser = IsoObjetThread->IsoObjet->masterthread->VRgbtParser;
        LocalScene.componentsinfos.NoiseParam.GradientParser = IsoObjetThread->IsoObjet->masterthread->GradientParser;
        LocalScene.componentsinfos.NoiseParam.Nb_vrgbts = IsoObjetThread->IsoObjet->masterthread->Nb_vrgbts;
        LocalScene.componentsinfos.NoiseParam.NoiseParser = IsoObjetThread->IsoObjet->masterthread->NoiseParser;
        IsoObjetThread->IsoObjet->masterthread->Noise == "" ? LocalScene.componentsinfos.NoiseParam.NoiseShape = 0: LocalScene.componentsinfos.NoiseParam.NoiseShape = 1;
    }
    else
    {
        LocalScene.componentsinfos.NoiseParam.VRgbtParser = ParObjetThread->ParObjet->masterthread->VRgbtParser;
        LocalScene.componentsinfos.NoiseParam.GradientParser = ParObjetThread->ParObjet->masterthread->GradientParser;
        LocalScene.componentsinfos.NoiseParam.Nb_vrgbts = ParObjetThread->ParObjet->masterthread->Nb_vrgbts;
        LocalScene.componentsinfos.NoiseParam.NoiseParser = ParObjetThread->ParObjet->masterthread->NoiseParser;
        ParObjetThread->ParObjet->masterthread->Noise == "" ? LocalScene.componentsinfos.NoiseParam.NoiseShape = 0: LocalScene.componentsinfos.NoiseParam.NoiseShape = 1;
    }

    for(int i=0; i<LocalScene.componentsinfos.NoiseParam.Nb_vrgbts && i<100; i++)
    {
        ValCol[i] = LocalScene.componentsinfos.NoiseParam.VRgbtParser[i].Eval(val);
    }

    for(unsigned int i= 0; i < LocalScene.VertxNumber; i++)
    {
        val[0]= difMaximum*LocalScene.ArrayNorVer_localPt[i*TypeDrawin  + 3 + TypeDrawinNormStep]/hauteur_fenetre -decalage_xo;
        val[1]= difMaximum*LocalScene.ArrayNorVer_localPt[i*TypeDrawin  + 4 + TypeDrawinNormStep]/hauteur_fenetre -decalage_yo;
        val[2]= difMaximum*LocalScene.ArrayNorVer_localPt[i*TypeDrawin  + 5 + TypeDrawinNormStep]/hauteur_fenetre -decalage_zo;

        if(LocalScene.componentsinfos.NoiseParam.NoiseShape != 0 && LocalScene.componentsinfos.NoiseParam.NoiseActive == 1)
            tmp  = LocalScene.componentsinfos.NoiseParam.NoiseParser->Eval(val);
        else
            tmp =1.0;

        val[0] *= tmp;
        val[1] *= tmp;
        val[2] *= tmp;

        tmp  = LocalScene.componentsinfos.NoiseParam.GradientParser->Eval(val);

        int c= (int)tmp;
        tmp = std::abs(tmp - (double)c);
        for (int j=0; j < LocalScene.componentsinfos.NoiseParam.Nb_vrgbts && j < 100; j+=5)
            if(tmp <= ValCol[j])
            {
                LocalScene.ArrayNorVer_localPt[i*TypeDrawin    ] = ValCol[j+1];
                LocalScene.ArrayNorVer_localPt[i*TypeDrawin+1] = ValCol[j+2];
                LocalScene.ArrayNorVer_localPt[i*TypeDrawin+2] = ValCol[j+3];
                LocalScene.ArrayNorVer_localPt[i*TypeDrawin+3] = ValCol[j+4];
                j = 100;
            }
    }
}

void OpenGlWidget::CalculateColorsPoints()
{
    double tmp, ValCol[100], val[6];
    int Jprime;

    // First case: Pigment
    if( LocalScene.componentsinfos.NoiseParam.NoiseType == 1)
    {
        LocalScene.componentsinfos.ThereisRGBA = true;
        for(unsigned int i =0; i < LocalScene.VertxNumber; i++)
        {
            val[0]= difMaximum*LocalScene.ArrayNorVer_localPt[i*TypeDrawin  + 3 + TypeDrawinNormStep]/hauteur_fenetre -decalage_xo;
            val[1]= difMaximum*LocalScene.ArrayNorVer_localPt[i*TypeDrawin  + 4 + TypeDrawinNormStep]/hauteur_fenetre -decalage_yo;
            val[2]= difMaximum*LocalScene.ArrayNorVer_localPt[i*TypeDrawin  + 5 + TypeDrawinNormStep]/hauteur_fenetre -decalage_zo;

            Jprime = (i) %  (ParObjetThread->ParObjet->Vgrid);
            val[3] = (double)Jprime/(double)(ParObjetThread->ParObjet->Vgrid) ;
            val[3] = val[3] * ParObjetThread->ParObjet->masterthread->dif_u[0]  + ParObjetThread->ParObjet->masterthread->u_inf[0];

            Jprime = (i)/(ParObjetThread->ParObjet->Ugrid);
            val[4] = (double)Jprime/(double)(ParObjetThread->ParObjet->Ugrid) ;
            val[4] = val[4] * ParObjetThread->ParObjet->masterthread->dif_v[0]  + ParObjetThread->ParObjet->masterthread->v_inf[0];

            if(LocalScene.componentsinfos.NoiseParam.NoiseShape != 0 && LocalScene.componentsinfos.NoiseParam.NoiseActive == 1)
                tmp  = LocalScene.componentsinfos.NoiseParam.NoiseParser->Eval(val);
            else
                tmp =1.0;

            val[0] *= tmp;
            val[1] *= tmp;
            val[2] *= tmp;
            val[3] *= tmp;
            val[4] *= tmp;

            LocalScene.ArrayNorVer_localPt[i*TypeDrawin     ] = LocalScene.componentsinfos.NoiseParam.RgbtParser[0].Eval(val);
            LocalScene.ArrayNorVer_localPt[i*TypeDrawin +1] = LocalScene.componentsinfos.NoiseParam.RgbtParser[1].Eval(val);
            LocalScene.ArrayNorVer_localPt[i*TypeDrawin +2] = LocalScene.componentsinfos.NoiseParam.RgbtParser[2].Eval(val);
            LocalScene.ArrayNorVer_localPt[i*TypeDrawin +3] = LocalScene.componentsinfos.NoiseParam.RgbtParser[3].Eval(val);
        }
    }

    // Second case : Texture
    else if(LocalScene.componentsinfos.NoiseParam.NoiseType != 0)
    {
        LocalScene.componentsinfos.ThereisRGBA = true;
        for(int i=0; i<LocalScene.componentsinfos.NoiseParam.Nb_vrgbts && i<100; i++)
        {
            ValCol[i] = LocalScene.componentsinfos.NoiseParam.VRgbtParser[i].Eval(val);
        }

        for(unsigned int i= 0; i < LocalScene.VertxNumber; i++)
        {
            val[0]= difMaximum*LocalScene.ArrayNorVer_localPt[i*TypeDrawin  + 3 + TypeDrawinNormStep]/hauteur_fenetre -decalage_xo;
            val[1]= difMaximum*LocalScene.ArrayNorVer_localPt[i*TypeDrawin  + 4 + TypeDrawinNormStep]/hauteur_fenetre -decalage_yo;
            val[2]= difMaximum*LocalScene.ArrayNorVer_localPt[i*TypeDrawin  + 5 + TypeDrawinNormStep]/hauteur_fenetre -decalage_zo;

            if(LocalScene.componentsinfos.NoiseParam.NoiseShape != 0 && LocalScene.componentsinfos.NoiseParam.NoiseActive == 1)
                tmp  = LocalScene.componentsinfos.NoiseParam.NoiseParser->Eval(val);
            else
                tmp =1.0;

            val[0] *= tmp;
            val[1] *= tmp;
            val[2] *= tmp;

            tmp  = LocalScene.componentsinfos.NoiseParam.GradientParser->Eval(val);

            int c= (int)tmp;
            tmp = std::abs(tmp - (double)c);
            for (int j=0; j < LocalScene.componentsinfos.NoiseParam.Nb_vrgbts && j < 100; j+=5)
                if(tmp <= ValCol[j])
                {
                    LocalScene.ArrayNorVer_localPt[i*TypeDrawin    ] = ValCol[j+1];
                    LocalScene.ArrayNorVer_localPt[i*TypeDrawin+1] = ValCol[j+2];
                    LocalScene.ArrayNorVer_localPt[i*TypeDrawin+2] = ValCol[j+3];
                    LocalScene.ArrayNorVer_localPt[i*TypeDrawin+3] = ValCol[j+4];
                    j = 100;
                }
        }
    }
    update();
}

int OpenGlWidget::memoryallocation(int maxtri, int maxpts, int gridmax,
                                   int NbComponent,int NbVariables,int NbConstantes,
                                   int NbDefinedFunctions,int NbTextures,int NbSliders,int NbSliderValues, int nbthreads,
                                   int initGrid, int FactX, int FactY, int FactZ)
{
    //memoryallocation
    try
    {
        IsoObjetThread = new IsoThread(new Iso3D(maxtri, maxpts, gridmax,NbComponent,NbVariables,NbConstantes,
                                       NbDefinedFunctions,NbTextures,NbSliders,NbSliderValues, nbthreads,
                                       initGrid, FactX, FactY, FactZ));

        ParObjetThread = new ParThread(new Par3D(maxpts, nbthreads));

        LocalScene     = (new ObjectParameters(maxpts, maxtri))->objectproperties;
        return 1;
    }
    catch(std::bad_alloc&)
    {
        message.setText("Not enough memory available to complete this operation.\n Parameters in mathmodconfig.js are too high : \n (MaxGrid, MaxPt, MaxTri)=( "+QString::number(gridmax)+", "+QString::number(maxpts/1000000.0,'g',  6)+", "+QString::number(maxtri/1000000.0,'g',  6)+" )");
        message.adjustSize () ;
        message.exec();
        return -1;
    }
}

void OpenGlWidget::SaveSceneAsObjPoly(int type)
{
    int startpl = 0;
    int actualpointindice;

    QString fileName = QFileDialog::getSaveFileName(this,
                       tr("Save OBJ file"), "", tr("OBJ Files (*.obj)"));

    QFile data(fileName);
    if (data.open(QFile::ReadWrite | QFile::Truncate))
    {
        unsigned int i;
        QTextStream stream(&data);
        stream.setRealNumberNotation(QTextStream::FixedNotation);
        stream.setRealNumberPrecision(3);
        // save vertices:
        if(type ==1)
        {
            for (i=0; i< LocalScene.VertxNumber; i++)
            {
                (stream) <<"v "<<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+3 + TypeDrawinNormStep]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+4 + TypeDrawinNormStep]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+5 + TypeDrawinNormStep]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i  ]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+1]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+2]<<"\n";
            }
        }
        else
        {
            for (i=0; i< LocalScene.VertxNumber; i++)
            {
                (stream) <<"v "<<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+3 + TypeDrawinNormStep]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+4 + TypeDrawinNormStep]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+5 + TypeDrawinNormStep]<<"\n";
            }
        }

        // save faces:
        for (i = 0; i < LocalScene.NbPolygnNbVertexPtMin; i++)
        {
            int polysize       =  LocalScene.PolyIndices_localPtMin[startpl++];
            (stream) <<"f";
            for (int j = 0; j < polysize; j++)
            {
                actualpointindice = LocalScene.PolyIndices_localPtMin[startpl] +1;
                (stream) <<"  "<<actualpointindice;
                startpl++;
            }
            (stream) <<"\n";
        }
    }
}

void OpenGlWidget::SaveSceneAsObjTrian(int type)
{
    QString fileName = QFileDialog::getSaveFileName(this,
                       tr("Save OBJ file"), "", tr("OBJ Files (*.obj)"));

    QFile data(fileName);
    if (data.open(QFile::ReadWrite | QFile::Truncate))
    {
        unsigned int i;
        QTextStream stream(&data);
        stream.setRealNumberNotation(QTextStream::FixedNotation);
        stream.setRealNumberPrecision(3);
        // save vertices:
        if(type == 1)
        {
            for (i=0; i< LocalScene.VertxNumber; i++)
            {
                (stream) <<"v "<<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+3 + TypeDrawinNormStep]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+4 + TypeDrawinNormStep]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+5 + TypeDrawinNormStep]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i     ]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+1   ]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+2   ]<<"\n";
            }
        }
        else
        {
            for (i=0; i< LocalScene.VertxNumber; i++)
            {
                (stream) <<"v "<<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+3 + TypeDrawinNormStep]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+4 + TypeDrawinNormStep]<<"  "\
                         <<LocalScene.ArrayNorVer_localPt[TypeDrawin*i+5 + TypeDrawinNormStep]<<"\n";
            }
        }
        for (i = 0; i < LocalScene.PolyNumber ; i+=3)
        {

            (stream) <<"f "<<"  "   <<LocalScene.PolyIndices_localPt[i       ] +1<<"  "\
                     <<LocalScene.PolyIndices_localPt[i + 1] +1<<"  "\
                     <<LocalScene.PolyIndices_localPt[i + 2] +1<<"\n";
        }
    }
}

OpenGlWidget::~OpenGlWidget()
{
    //glDeleteBuffers(1, &LocalScene.vboId_ArrayNorVer_localPt);
    //glDeleteBuffers(1, &LocalScene.vboId_PolyIndices_localPt);
    delete(timer);
    delete ParObjetThread->ParObjet;
    delete IsoObjetThread->IsoObjet;
}

void OpenGlWidget::deleteVBO()
{
    //glDeleteBuffers(1, &LocalScene.vboId_ArrayNorVer_localPt);
    //glDeleteBuffers(1, &LocalScene.vboId_PolyIndices_localPt);
}
void OpenGlWidget::initbox()
{
    oldminx = 999999999;
    oldminy = 999999999;
    oldminz = 999999999;
    oldmaxx =-999999999;
    oldmaxy =-999999999;
    oldmaxz =-999999999;
}

void OpenGlWidget::PutObjectInsideCube()
{

    minx   = 999999999;
    miny  = 999999999;
    minz  = 999999999;
    maxx =-999999999 ;
    maxy =-999999999;
    maxz =-999999999;
    if((LocalScene.morph != 1 || (LocalScene.morph == 1 && FistTimecalibrate ==1))   && LocalScene.slider != 1)
    {
        for (unsigned int i=0; i< LocalScene.VertxNumber; i++)
        {
            if (minx >LocalScene.ArrayNorVer_localPt[TypeDrawin*i+3 + TypeDrawinNormStep])  minx = LocalScene.ArrayNorVer_localPt[TypeDrawin*i+3 + TypeDrawinNormStep];
            if (miny >LocalScene.ArrayNorVer_localPt[TypeDrawin*i+4 + TypeDrawinNormStep])  miny = LocalScene.ArrayNorVer_localPt[TypeDrawin*i+4 + TypeDrawinNormStep];
            if (minz >LocalScene.ArrayNorVer_localPt[TypeDrawin*i+5 + TypeDrawinNormStep])  minz = LocalScene.ArrayNorVer_localPt[TypeDrawin*i+5 + TypeDrawinNormStep];

            if (maxx <LocalScene.ArrayNorVer_localPt[TypeDrawin*i+3 + TypeDrawinNormStep])  maxx = LocalScene.ArrayNorVer_localPt[TypeDrawin*i+3 + TypeDrawinNormStep];
            if (maxy <LocalScene.ArrayNorVer_localPt[TypeDrawin*i+4 + TypeDrawinNormStep])  maxy = LocalScene.ArrayNorVer_localPt[TypeDrawin*i+4 + TypeDrawinNormStep];
            if (maxz <LocalScene.ArrayNorVer_localPt[TypeDrawin*i+5 + TypeDrawinNormStep])  maxz = LocalScene.ArrayNorVer_localPt[TypeDrawin*i+5 + TypeDrawinNormStep];
        }
        FistTimecalibrate = -1;
        difX = maxx - minx;
        difY = maxy - miny;
        difZ = maxz - minz;
        // Recherche du maximum :
        difMaximum = difX;
        if (difY > difMaximum)
        {
            difMaximum = difY;
        };
        if (difZ > difMaximum)
        {
            difMaximum = difZ;
        };

        /// On va inclure cet objet dans un cube de langueur maximum
        /// egale a "hauteur_fenetre"
        decalage_xo = -(minx +maxx)/2;
        decalage_yo = -(miny +maxy)/2;
        decalage_zo = -(minz +maxz)/2;
    }

    for (unsigned int i=0; i< LocalScene.VertxNumber; i++)
    {
        LocalScene.ArrayNorVer_localPt[TypeDrawin*i+3 + TypeDrawinNormStep] = hauteur_fenetre*(LocalScene.ArrayNorVer_localPt[TypeDrawin*i+3 + TypeDrawinNormStep] + decalage_xo)/difMaximum;
        LocalScene.ArrayNorVer_localPt[TypeDrawin*i+4 + TypeDrawinNormStep] = hauteur_fenetre*(LocalScene.ArrayNorVer_localPt[TypeDrawin*i+4 + TypeDrawinNormStep] + decalage_yo)/difMaximum;
        LocalScene.ArrayNorVer_localPt[TypeDrawin*i+5 + TypeDrawinNormStep] = hauteur_fenetre*(LocalScene.ArrayNorVer_localPt[TypeDrawin*i+5 + TypeDrawinNormStep] + decalage_zo)/difMaximum;
    }
}

void OpenGlWidget::mouseReleaseEvent( QMouseEvent *)
{
}

void OpenGlWidget::mousePressEvent( QMouseEvent * e)
{
    if ( e->button() == Qt::LeftButton )
        btgauche = 1;
    else btgauche = 0;
    if ( e->button() == Qt::RightButton ) btdroit = 1;
    else btdroit = 0;
    if ( e->button() == Qt::MidButton ) btmilieu = 1;
    else btmilieu = 0;
    old_y = LocalScene.oldRoty = e->y();
    old_x = LocalScene.oldRotx = e->x();
}

void OpenGlWidget::png()
{
    LocalScene.png_ok*=-1;
}

void OpenGlWidget::jpg()
{
    LocalScene.jpg_ok*=-1;
}

void OpenGlWidget::bmp()
{
    LocalScene.bmp_ok*=-1;
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
    LocalScene.specReflection[0] =  (cl/100.0);
}

void OpenGlWidget::greenSpec(int cl)
{
    LocalScene.specReflection[1] =  (cl/100.0);
}

void OpenGlWidget::blueSpec(int cl)
{
    LocalScene.specReflection[2] =  (cl/100.0);
}
