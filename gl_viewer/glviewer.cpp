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


#define BUFFER_OFFSET(i) ((float *)(i))

static int TypeDrawin=10;
static int TypeDrawinNormStep = 4;
int FistTimecalibrate =-1;
static double hauteur_fenetre, difMaximum, decalage_xo, decalage_yo, decalage_zo;


static void UpdateParColorliste (ObjectProperties *scene)
{
    float frontcl[4], backcl[4];
    for(int i = 0; i < scene->componentsinfos.NbParametric; i++)
    {
        glDeleteLists(scene->ParColorliste[i],1);
        scene->ParColorliste[i] = glGenLists(1);
    }
    for(int i=0; i< scene->componentsinfos.NbParametric; i++)
    {
        glNewList(scene->ParColorliste[i], GL_COMPILE);
        {
            for(int j=0; j<4; j++)
            {
                frontcl[j]=scene->frontcolsPar[4*i+j];
                backcl[j]=scene->backcolsPar[4*i+j];
            }
            glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, backcl);
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frontcl);
        }
        glEndList();
    }
}

static void UpdateFillParliste (ObjectProperties *scene)
{
    for(int i = 0; i < scene->componentsinfos.NbParametric; i++)
    {
        glDeleteLists(scene->FillParliste[i],1);
        scene->FillParliste[i] = glGenLists(1);
    }
    for(int i=0; i< scene->componentsinfos.NbParametric; i++)
    {
        glNewList(scene->FillParliste[i], GL_COMPILE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.Parametricpositions[3*i+1],
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[scene->componentsinfos.Parametricpositions[3*i]])
        );
        glEndList();
    }
}

static void UpdateCNDParliste (ObjectProperties *scene)
{
    if(scene->componentsinfos.ThereisCND)
    {
        for(int i = 0; i < scene->componentsinfos.NbParametric; i++)
        {
            glDeleteLists(scene->CNDverifyParliste[i],1);
            scene->CNDverifyParliste[i] = glGenLists(1);

            glDeleteLists(scene->CNDnotverifyParliste[i],1);
            scene->CNDnotverifyParliste[i] = glGenLists(1);
        }

        for(int i=0; i< scene->componentsinfos.NbParametric; i++)
        {
            glNewList(scene->CNDverifyParliste[i], GL_COMPILE);
            glDrawElements(
                GL_TRIANGLES,
                3*(scene->componentsinfos.NbTrianglesVerifyCND),
                GL_UNSIGNED_INT,
                &(scene->PolyIndices_localPt[0])
            );
            glEndList();

            glNewList(scene->CNDnotverifyParliste[i], GL_COMPILE);
            glDrawElements(
                GL_TRIANGLES,
                3*(scene->componentsinfos.NbTrianglesNotVerifyCND),
                GL_UNSIGNED_INT,
                &(scene->PolyIndices_localPt[3*scene->componentsinfos.NbTrianglesVerifyCND])
            );
            glEndList();
        }
    }
}

static void UpdateCNDIsoliste (ObjectProperties *scene)
{
    if(scene->componentsinfos.ThereisCND)
    {
        for(int i = 0; i < scene->componentsinfos.NbIso; i++)
        {
            glDeleteLists(scene->CNDverifyIsoliste[i],1);
            scene->CNDverifyIsoliste[i] = glGenLists(1);

            glDeleteLists(scene->CNDnotverifyIsoliste[i],1);
            scene->CNDnotverifyIsoliste[i] = glGenLists(1);
        }

        for(int i=0; i< scene->componentsinfos.NbIso; i++)
        {
            glNewList(scene->CNDverifyIsoliste[i], GL_COMPILE);
            glDrawElements(
                GL_TRIANGLES,
                3*(scene->componentsinfos.NbTrianglesVerifyCND),
                GL_UNSIGNED_INT,
                &(scene->PolyIndices_localPt[0])
            );
            glEndList();

            glNewList(scene->CNDnotverifyIsoliste[i], GL_COMPILE);
            glDrawElements(
                GL_TRIANGLES,
                3*(scene->componentsinfos.NbTrianglesNotVerifyCND),
                GL_UNSIGNED_INT,
                &(scene->PolyIndices_localPt[3*scene->componentsinfos.NbTrianglesVerifyCND])
            );
            glEndList();
        }
    }
}

static void DrawParametric_cache (ObjectProperties *scene)
{
    float frontcl[4], backcl[4];
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_POLYGON_OFFSET_FILL);

    if(scene->componentsinfos.ThereisRGBA)
        glEnable(GL_COLOR_MATERIAL);

    glPolygonOffset(scene->polyfactor, scene->polyunits);
    for(int i=0; i< scene->componentsinfos.NbParametric; i++)
    {
        if(!scene->componentsinfos.ThereisRGBA)
        {
            for(int j=0; j<4; j++)
            {
                frontcl[j]=scene->frontcolsPar[4*i+j];
                backcl[j]=scene->backcolsPar[4*i+j];
            }
            glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, backcl);
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frontcl);
        }

        if(scene->componentsinfos.ThereisCND)
        {
            if(scene->componentsinfos.DFTrianglesVerifyCND)
                glCallList(scene->CNDverifyParliste[i]);

            if(scene->componentsinfos.DFTrianglesNotVerifyCND)
                glCallList(scene->CNDnotverifyParliste[i]);
        }
        else
            glCallList(scene->FillParliste[i]);
    }
    if(scene->componentsinfos.ThereisRGBA)
        glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

static void DrawParametric (ObjectProperties *scene)
{
    float frontcl[4], backcl[4];
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_POLYGON_OFFSET_FILL);

    if(scene->componentsinfos.ThereisRGBA)
        glEnable(GL_COLOR_MATERIAL);

    glPolygonOffset(scene->polyfactor, scene->polyunits);
    for(int i=0; i< scene->componentsinfos.NbParametric; i++)
    {
            if(!scene->componentsinfos.ThereisRGBA)
            {
                for(int j=0; j<4; j++)
                {
                    frontcl[j]=scene->frontcolsPar[4*i+j];
                    backcl[j]=scene->backcolsPar[4*i+j];
                }
                glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE,  backcl);
                glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frontcl);
            }
            if(scene->componentsinfos.ThereisCND)
            {
                if(scene->componentsinfos.DFTrianglesVerifyCND)
                    glDrawElements(
                        GL_TRIANGLES,
                        3*(scene->componentsinfos.NbTrianglesVerifyCND),
                        GL_UNSIGNED_INT,
                        &(scene->PolyIndices_localPt[0])
                    );

                if(scene->componentsinfos.DFTrianglesNotVerifyCND)
                    glDrawElements(
                        GL_TRIANGLES,
                        3*(scene->componentsinfos.NbTrianglesNotVerifyCND),
                        GL_UNSIGNED_INT,
                        &(scene->PolyIndices_localPt[3*scene->componentsinfos.NbTrianglesVerifyCND])
                    );
            }
            else
                glDrawElements(
                    GL_TRIANGLES,
                    3*scene->componentsinfos.Parametricpositions[3*i+1],
                    GL_UNSIGNED_INT,
                    &(scene->PolyIndices_localPt[scene->componentsinfos.Parametricpositions[3*i]])
                );
    }

    if(scene->componentsinfos.ThereisRGBA)
        glDisable(GL_COLOR_MATERIAL);

    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

static void DrawMeshIsoListe(ObjectProperties *scene)
{
    glDeleteLists(scene->MeshIsoliste, 1);
    scene->MeshIsoliste = glGenLists(1);
    glNewList(scene->MeshIsoliste, GL_COMPILE );
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_TRIANGLES, scene->PolyNumber, GL_UNSIGNED_INT, scene->PolyIndices_localPt);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEndList();
}

static void DrawMeshIso_cache(ObjectProperties *scene)
{
    glColor4f (scene->gridcol[0], scene->gridcol[1], scene->gridcol[2], scene->gridcol[3]);
    glCallList(scene->MeshIsoliste);
}

static void UpdateIsoColorliste (ObjectProperties *scene)
{
    float frontcl[4], backcl[4];
    for(int i = 0; i < scene->componentsinfos.NbIso; i++)
    {
        glDeleteLists(scene->IsoColorliste[i],1);
        scene->IsoColorliste[i] = glGenLists(1);
    }
    for(int i=0; i< scene->componentsinfos.NbIso; i++)
    {
        glNewList(scene->IsoColorliste[i], GL_COMPILE);
        {
            for(int j=0; j<4; j++)
            {
                frontcl[j]=scene->frontcols[4*i+j];
                backcl[j]=scene->backcols[4*i+j];
            }
            glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, backcl);
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frontcl);
        }
        glEndList();
    }
}

static void UpdateFillIsoliste (ObjectProperties *scene)
{
    for(int i = 0; i < scene->componentsinfos.NbIso; i++)
    {
        glDeleteLists(scene->FillIsoliste[i],1);
        scene->FillIsoliste[i] = glGenLists(1);
    }
    for(int i=0; i< scene->componentsinfos.NbIso; i++)
    {
        glNewList(scene->FillIsoliste[i], GL_COMPILE);
        {
            glDrawElements(
                GL_TRIANGLES,
                3*scene->componentsinfos.IsoPositions[2*i+1],
                GL_UNSIGNED_INT,
                &(scene->PolyIndices_localPt[scene->componentsinfos.IsoPositions[2*i]]));
        }
        glEndList();
    }
}

static void DrawIso_cache (ObjectProperties *scene)
{
    float frontcl[4], backcl[4];
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_POLYGON_OFFSET_FILL);

    if(scene->componentsinfos.ThereisRGBA)
        glEnable(GL_COLOR_MATERIAL);

    glPolygonOffset(scene->polyfactor, scene->polyunits);

    for(int i=0; i< scene->componentsinfos.NbIso; i++)
    {
        if(!scene->componentsinfos.ThereisRGBA)
        {
            for(int j=0; j<4; j++)
            {
                frontcl[j]=scene->frontcols[4*i+j];
                backcl[j]=scene->backcols[4*i+j];
            }
            glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE,  backcl);
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frontcl);
        }

        if(scene->componentsinfos.ThereisCND)
        {
            if(scene->componentsinfos.DFTrianglesVerifyCND)
                glCallList(scene->CNDverifyIsoliste[i]);

            if(scene->componentsinfos.DFTrianglesNotVerifyCND)
                glCallList(scene->CNDnotverifyIsoliste[i]);
        }
        else
            glCallList(scene->FillIsoliste[i]);
    }
    if(scene->componentsinfos.ThereisRGBA)
        glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

static void DrawIso (ObjectProperties *scene)
{
    float frontcl[4], backcl[4];
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_POLYGON_OFFSET_FILL);

    if(scene->componentsinfos.ThereisRGBA)
        glEnable(GL_COLOR_MATERIAL);

    glPolygonOffset(scene->polyfactor, scene->polyunits);

    for(int i=0; i< scene->componentsinfos.NbIso; i++)
    {
        {
            if(!scene->componentsinfos.ThereisRGBA)
            {
                for(int j=0; j<4; j++)
                {
                    frontcl[j]=scene->frontcols[4*i+j];
                    backcl[j]=scene->backcols[4*i+j];
                }
                glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, backcl);
                glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frontcl);
            }
            if(scene->componentsinfos.ThereisCND)
            {
                if(scene->componentsinfos.DFTrianglesVerifyCND)
                    glDrawElements(
                        GL_TRIANGLES,
                        3*(scene->componentsinfos.NbTrianglesVerifyCND),
                        GL_UNSIGNED_INT,
                        &(scene->PolyIndices_localPt[0])
                    );

                if(scene->componentsinfos.DFTrianglesNotVerifyCND)
                    glDrawElements(
                        GL_TRIANGLES,
                        3*(scene->componentsinfos.NbTrianglesNotVerifyCND),
                        GL_UNSIGNED_INT,
                        &(scene->PolyIndices_localPt[3*scene->componentsinfos.NbTrianglesVerifyCND])
                    );
            }
            else
            {
                glDrawElements(
                    GL_TRIANGLES,
                    3*scene->componentsinfos.IsoPositions[2*i+1],
                    GL_UNSIGNED_INT,
                    &(scene->PolyIndices_localPt[scene->componentsinfos.IsoPositions[2*i]])
                );
            }
        }
    }
    if(scene->componentsinfos.ThereisRGBA)
        glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

static void DrawMinimalTopologyListe(ObjectProperties *scene)
{
    glDeleteLists(scene->MeshIsoMinimalTopliste, 1);
    scene->MeshIsoMinimalTopliste = glGenLists(1);
    glNewList(scene->MeshIsoMinimalTopliste, GL_COMPILE );
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    int startpl = 0;
    for (unsigned int i = 0; i < scene->NbPolygnNbVertexPtMin; i++)
    {
        int polysize       =  scene->PolyIndices_localPtMin[startpl++];
        glBegin(GL_POLYGON);
        for (int j = 0; j < polysize; j++)
        {
            int actualpointindice = scene->PolyIndices_localPtMin[startpl];
            glVertex3f(
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+3 + TypeDrawinNormStep],
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+4 + TypeDrawinNormStep],
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+5 + TypeDrawinNormStep]
            );
            startpl++;
        }
        glEnd();
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEndList();
}

static void DrawMinimalTopology_cache (ObjectProperties *scene)
{
    glColor4f (scene->gridcol[0], scene->gridcol[1], scene->gridcol[2], scene->gridcol[3]);
    glCallList(scene->MeshIsoMinimalTopliste);
}

static void DrawMeshParametric_cache (ObjectProperties *scene)
{
    glColor4f (scene->gridcol[0], scene->gridcol[1], scene->gridcol[2], scene->gridcol[3]);
    glCallList(scene->MeshParliste);
}

static void DrawMeshParametricListe(ObjectProperties *scene)
{
    glDeleteLists(scene->MeshParliste, 1);
    scene->MeshParliste = glGenLists(1);
    glNewList(scene->MeshParliste, GL_COMPILE );
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    int startpl = 0;
    for (unsigned int i = 0; i < scene->NbPolygnNbVertexPtMin; i++)
    {
        int polysize       =  scene->PolyIndices_localPtMin[startpl++];
        glBegin(GL_POLYGON);
        for (int j = 0; j < polysize; j++)
        {
            int actualpointindice = scene->PolyIndices_localPtMin[startpl];
            glVertex3f(
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+3 + TypeDrawinNormStep],
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+4 + TypeDrawinNormStep],
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+5 + TypeDrawinNormStep]
            );
            startpl++;
        }
        glEnd();
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEndList();
}


static void DrawIsoPar (ObjectProperties *scene)
{
    if (scene->typedrawing == 1)
    {
        UpdateFillIsoliste(scene);
        UpdateCNDIsoliste(scene);
    }
    if (scene->typedrawing == -1)
    {
        UpdateFillParliste(scene);
        UpdateCNDParliste(scene);
    }
}

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
            Jprime = (i) %  (ParObjetThread->ParObjet->nb_colone);
            val[3] = (double)Jprime/(double)(ParObjetThread->ParObjet->nb_colone) ;
            val[3] = val[3] * ParObjetThread->ParObjet->masterthread->dif_u[0]  + ParObjetThread->ParObjet->masterthread->u_inf[0];

            Jprime = (i)/(ParObjetThread->ParObjet->nb_ligne);
            val[4] = (double)Jprime/(double)(ParObjetThread->ParObjet->nb_ligne) ;
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
    //reinisialize Filled polygones with the new texture
    if(LocalScene.activateGlCache)
        DrawIsoPar(&LocalScene);
}

///+++++++++++++++++++++++++++++++++++++++++
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
    //reinisialize Filled polygones with the new texture
    if(LocalScene.activateGlCache)
        DrawIsoPar(&LocalScene);
}

///+++++++++++++++++++++++++++++++++++++++++
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

            Jprime = (i) %  (ParObjetThread->ParObjet->nb_colone);
            val[3] = (double)Jprime/(double)(ParObjetThread->ParObjet->nb_colone) ;
            val[3] = val[3] * ParObjetThread->ParObjet->masterthread->dif_u[0]  + ParObjetThread->ParObjet->masterthread->u_inf[0];

            Jprime = (i)/(ParObjetThread->ParObjet->nb_ligne);
            val[4] = (double)Jprime/(double)(ParObjetThread->ParObjet->nb_ligne) ;
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
    //reinisialize Filled polygones with the new texture
    if(LocalScene.activateGlCache)
        DrawIsoPar(&LocalScene);
    update();
}

void OpenGlWidget::axeOk()
{
    LocalScene.axe *= -1;
    update();
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
    if(LocalScene.smoothline == 1)
    {
        glEnable (GL_LINE_SMOOTH);
        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint (GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
    }
    else
    {
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_BLEND);
    };

    update();
}

void OpenGlWidget::boxOk()
{
    LocalScene.line *= -1;
}

void OpenGlWidget::lineOk()
{
    LocalScene.line *= -1;
}

void OpenGlWidget::valueChanged()
{
    InitGlParameters();
}

GLuint fontOffset;
void makeRasterFont()
{
    GLuint i;
    if(fontOffset < 128)
    {
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        fontOffset = glGenLists (128);

        for (i = 30; i < 127; i++)
        {
            glNewList(i+fontOffset, GL_COMPILE);
            glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, rasters[i-30]);
            glEndList();
        }
    }
}

void InitFont()
{
    makeRasterFont();
}

void OpenGlWidget::run()
{
}

bool OpenGlWidget::timeractif()
{
    return(LocalScene.anim == 1);
}

void OpenGlWidget::stoptimer()
{
    timer->stop();
    update();
}

void OpenGlWidget::starttimer()
{
    timer->start( latence);
}

void OpenGlWidget::restarttimer(int newlatence)
{
    latence = newlatence;
    if ( LocalScene.anim == 1)
    {
        timer->stop();
        timer->start( latence);
    }
}

void OpenGlWidget::VBOmemoryallocation()
{
    /*
    static int stat=0;
    static uint previous=0;

    if(stat ==0)
    {
    glDeleteBuffersARB(1, &LocalScene.vboId_ArrayNorVer_localPt);
    glDeleteBuffersARB(1, &LocalScene.vboId_PolyIndices_localPt);
    LocalScene.vboId_ArrayNorVer_localPt = LocalScene.vboId_PolyIndices_localPt = 0;

    glGenBuffersARB(1, &LocalScene.vboId_ArrayNorVer_localPt);
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, LocalScene.vboId_ArrayNorVer_localPt);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(float)*10*LocalScene.VertxNumber,LocalScene.ArrayNorVer_localPt, GL_STATIC_DRAW_ARB);


    glGenBuffersARB(1, &LocalScene.vboId_PolyIndices_localPt);
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, LocalScene.vboId_PolyIndices_localPt);
    glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof(uint)*4*LocalScene.PolyNumber/3, LocalScene.PolyIndices_localPt, GL_STATIC_DRAW_ARB);

    glBindBufferARB(GL_ARRAY_BUFFER_ARB, LocalScene.vboId_ArrayNorVer_localPt);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4, GL_FLOAT, sizeof(float)*10, BUFFER_OFFSET(0));   //The starting point of texcoords, 24 bytes away

    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer(GL_FLOAT, sizeof(float)*10, BUFFER_OFFSET(16));   //The starting point of normals, 12 bytes away

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(float)*10, BUFFER_OFFSET(28));   //The starting point of the VBO, for the vertices

    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, LocalScene.vboId_PolyIndices_localPt);
    stat +=1;
    previous = LocalScene.VertxNumber;
    }

    else
    {

    if(LocalScene.VertxNumber > previous)
    {
        glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(float)*10*LocalScene.VertxNumber,LocalScene.ArrayNorVer_localPt, GL_STATIC_DRAW_ARB);
        previous = LocalScene.VertxNumber;
    }
    else
        glBufferSubDataARB(GL_ARRAY_BUFFER_ARB,0, sizeof(float)*10*LocalScene.VertxNumber,LocalScene.ArrayNorVer_localPt);

    glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof(uint)*4*LocalScene.PolyNumber/3, LocalScene.PolyIndices_localPt, GL_STATIC_DRAW_ARB);

    }
    */
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int OpenGlWidget::memoryallocation(int maxtri, int maxpts, int gridmax,
                                   int NbComponent,int NbVariables,int NbConstantes,
                                   int NbDefinedFunctions,int NbTextures,int NbSliders,int NbSliderValues)
{
    //memoryallocation
    try
    {
        IsoObjetThread = new IsoThread(new Iso3D(maxtri, maxpts, gridmax,NbComponent,NbVariables,NbConstantes,
                                                 NbDefinedFunctions,NbTextures,NbSliders,NbSliderValues));

        ParObjetThread = new ParThread(new Par3D(maxpts));

        LocalScene                = (new ObjectParameters(maxpts, maxtri))->objectproperties;
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

void OpenGlWidget::startRendering()
{
    glt.start();
}

void OpenGlWidget::stopRendering()
{
    glt.stop();
    glt.wait();
}

void OpenGlWidget::resizeEvent(QResizeEvent *evt)
{
    glPushMatrix();
    glt.resizeViewport(evt->size());
    glPopMatrix();
}

void OpenGlWidget::closeEvent(QCloseEvent *evt)
{
    stopRendering();
    QGLWidget::closeEvent(evt);
}

void OpenGlWidget::anim()
{
    LocalScene.anim *= -1;
    if (LocalScene.anim == 1)
        timer->start( latence);
    else if(LocalScene.morph == -1)
        stoptimer();
}

void OpenGlWidget::morph()
{
    LocalScene.morph *= -1;
    FistTimecalibrate *= -1;

    if(LocalScene.typedrawing == 1)
    {
        //Isosurfaces:
        IsoObjetThread->IsoObjet->masterthread->morph_activated = LocalScene.morph;
        for(int nbthreads=0; nbthreads< IsoObjetThread->IsoObjet->WorkerThreadsNumber-1; nbthreads++)
            IsoObjetThread->IsoObjet->workerthreads[nbthreads].morph_activated = LocalScene.morph;
        IsoObjetThread->IsoObjet->IsoMorph();
    }
    else
        if(LocalScene.typedrawing == -1)
        {
            //Parametric surfaces:
            ParObjetThread->ParObjet->masterthread->activeMorph = LocalScene.morph;
            for(int nbthreads=0; nbthreads< ParObjetThread->ParObjet->WorkerThreadsNumber-1; nbthreads++)
                ParObjetThread->ParObjet->workerthreads[nbthreads].activeMorph = LocalScene.morph;
            ParObjetThread->ParObjet->ParMorph();
        }

    if (LocalScene.morph == 1)
        timer->start( latence);
    else if(LocalScene.anim == -1)
        stoptimer();
}

void OpenGlWidget::keyPressEvent ( QKeyEvent * e )
{
    int key = e->key();
    switch(key)
    {
    case Qt::Key_A :
        glt.anim();
        break;
    case Qt::Key_P :
        //FistTimecalibrate *= -1;
        glt.morph();
        initbox();
        break;
    }
    glt.update();
}

void OpenGlWidget::resizeGL( int newwidth, int newheight)
{
    Wresult = newwidth;
    Hresult = newheight;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, newwidth, newheight);
    float k=6;
    glFrustum(-newwidth/k, newwidth/k, -newheight/k , newheight/k, 250.0, 3000.0 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef( 0.0, 0, -1000.0 );
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
OpenGlWidget::OpenGlWidget( QWidget *parent)
    : QGLWidget( parent),
      glt(this)
{
    setAutoBufferSwap(true);
    static int NBGlWindow = 0;
    PerlinNoise = new ImprovedNoise(4., 4., 4.);

    latence = 10;
    val1 = val2 = val3 = 0.0;
    nb_colone = nb_ligne = 50;
    coupure_col = coupure_ligne = 0;
    isoline = isocolumn = isodepth = 40;
    cpisoline = cpisocolumn = cpisodepth = 0;
    IDGlWindow        = NBGlWindow;
    LocalScene.VertxNumber      = 0;
    FramesDir = "/home";
    hauteur_fenetre=700;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
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
    (LocalScene.typedrawing == 1) ?
    nbl = QString::number(isoline-cpisoline)+"x"+QString::number(isocolumn-cpisocolumn)+"x"+QString::number(isodepth-cpisodepth) :
          nbl = QString::number(nb_ligne-coupure_ligne)+"x"+QString::number(nb_colone-coupure_col)+" = "+QString::number((nb_ligne-coupure_ligne)*(nb_colone-coupure_col));
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,Wresult, Hresult, 0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    if ( LocalScene.infosdetails[0] ==1)
    {
        glColor3f (0.0, 1.0, 0.0);
        glRasterPos2i(10, 20);
        glCallLists(strlen("Grid = "),
                    GL_UNSIGNED_BYTE,
                    (GLubyte *)"Grid = ");
        glColor3f (1., 0.0, 0.);
        glRasterPos2i(80,20);
        glCallLists(nbl.size(),GL_UNSIGNED_BYTE,nbl.toLatin1());
    }
    if ( LocalScene.infosdetails[1] ==1)
    {
        glColor3f (0.0, 1.0, 0.0);
        glRasterPos2i(10, 40);
        glCallLists(strlen("Poly = "),
                    GL_UNSIGNED_BYTE,
                    (GLubyte *)"Poly = ");
        glColor3f (1.0, 0.0, 0.0);
        glRasterPos2i(80, 40);
        //(LocalScene.typedrawing == 1) ?
        glCallLists(QString::number(LocalScene.PolyNumber/3).size(),
                    GL_UNSIGNED_BYTE,
                    QString::number(LocalScene.PolyNumber/3).toLatin1()) ;
        /*:
        glCallLists(QString::number(LocalScene.PolyNumber/4).size(),
                    GL_UNSIGNED_BYTE,
                    QString::number(LocalScene.PolyNumber/4).toLatin1()) ;
                    */
    }
    if ( LocalScene.infosdetails[2] ==1)
    {
        if (LocalScene.typedrawing == 1)
        {
            glColor3f (0.0, 1.0, 0.0);
            glRasterPos2i(10, 60);
            glCallLists(strlen("Vertx= "),
                        GL_UNSIGNED_BYTE,
                        (GLubyte *)"Vertx= ");
            glColor3f (1.0, 0.0, 0.0);
            glRasterPos2i(80, 60);
            glCallLists(QString::number(LocalScene.VertxNumber).size(),
                        GL_UNSIGNED_BYTE,
                        QString::number(LocalScene.VertxNumber).toLatin1()) ;
        }
    }
    if (LocalScene.anim == 1)
    {
        glColor3f (0.0, 1.0, 0.0);
        glRasterPos2i(10, 80);
        glCallLists(strlen("Anim ="),GL_UNSIGNED_BYTE, (GLubyte *)"Anim =");
        glColor3f (1.0, 0.0, 0.0);
        glRasterPos2i(80, 80);
        glCallLists(strlen("On"),GL_UNSIGNED_BYTE, (GLubyte *)"On");
    }
    if (LocalScene.morph == 1)
    {
        glColor3f (0.0, 1.0, 0.0);
        glRasterPos2i(10, 100);
        glCallLists(strlen("Morph="),GL_UNSIGNED_BYTE, (GLubyte *)"Morph=");
        glColor3f (1.0, 0.0, 0.0);
        glRasterPos2i(80, 100);
        glCallLists(strlen("On"),GL_UNSIGNED_BYTE, (GLubyte *)"On");
    }
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
}


static void DrawAxe()
{
    glLineWidth(1);
    glBegin( GL_LINES );
    glColor3f (1.0, 0.0, 0.0);
    glVertex3f( 400.0, 0.0, 0.0);
    glVertex3f(   0.0, 0.0, 0.0);
    glColor3f (0.0, 1.0, 0.0);
    glVertex3f(0.0, 400.0, 0.0);
    glVertex3f(0.0,   0.0, 0.0);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 400.0);
    glVertex3f(0.0, 0.0,   0.0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 400.0);
    glVertex3f(10.0, 0.0, 380.0);
    glVertex3f(0.0, 10.0, 380.0);
    glColor3f (0.0, 0.0, 0.3);
    glVertex3f(-10.0, 0.0, 380.0);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f(0.0, -10.0, 380.0);
    glColor3f (0.0, 0.0, 0.3);
    glVertex3f(10.0, 0.0, 380.0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f (0.0, 1.0, 0.0);
    glVertex3f(0.0, 400.0, 0.0);
    glVertex3f(10.0, 380.0, 0.0);
    glVertex3f(0.0, 380.0, 10.0);
    glColor3f (0.0, 0.3, 0.0);
    glVertex3f(-10.0, 380.0, 0.0);
    glColor3f (0.0, 1.0, 0.0);
    glVertex3f(.0, 380.0, -10.0);
    glColor3f (0.0, 0.3, 0.0);
    glVertex3f(10.0, 380.0, 0.0);
    glEnd();

    /// Axe X :
    glBegin(GL_TRIANGLE_FAN);
    glColor3f (1.0, 0.0, 0.0);
    glVertex3f(400.0, 0.0, 0.0);
    glVertex3f(380.0, 10.0, 0.0);
    glVertex3f(380.0, 0.0, 10.0);
    glColor3f (0.3, 0.0, 0.0);
    glVertex3f(380.0, -10.0, 0.0);
    glColor3f (1.0, 0.0, 0.0);
    glVertex3f(380.0, 0.0, -10.0);
    glColor3f (0.3, 0.0, 0.0);
    glVertex3f(380.0, 10.0, 0.0);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(400.0, 0.0, 0.0);
    glVertex3f(380.0, 10.0, 0.0);
    glVertex3f(380.0, 0.0, 10.0);
    glVertex3f(380.0, -10.0, 0.0);
    glVertex3f(380.0, 0.0, -10.0);
    glVertex3f(380.0, 10.0, 0.0);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glRasterPos3i(410, 10, 10);
    glCallLists(strlen("X"),GL_UNSIGNED_BYTE,"X");

    glColor3f (0.7, 0.7, 0.7);
    glTranslatef(410.0, 4.0, 4.0);
    glTranslatef(-410.0, -4.0, -4.0);

    glColor3f (0.0, 1.0, 0.0);
    glRasterPos3i(10, 410, 10);
    glCallLists(strlen("Y"),
                GL_UNSIGNED_BYTE,
                "Y");

    glColor3f (1.0, 1.0, 0.0);
    glTranslatef(4.0, 410.0, 4.0);
    glTranslatef(-4.0, -410.0, -4.0);

    glColor3f (0.0, 0.0, 1.0);
    glRasterPos3i(10, 10, 410);
    //printString("Z");
    glCallLists(strlen("Z"),
                GL_UNSIGNED_BYTE,
                "Z");

    glColor3f (0.0, 0.7, 0.7);
    glTranslatef(4.0, 4.0, 410.0);
    glTranslatef(-4.0, -4.0, -410.0);
    glLineWidth(0.9);
}

static void DrawNormals_cache(ObjectProperties *scene)
{
    int j =  0;
    glColor4f (0.8, 0., 0.7, 1.0);
    for (unsigned int i=0; i< scene->PolyNumber; i+=4)
    {
        j =   TypeDrawin*scene->PolyIndices_localPt[i];
        glBegin( GL_LINES );
        glVertex3f(scene->ArrayNorVer_localPt[j+3  + TypeDrawinNormStep],
                   scene->ArrayNorVer_localPt[j+4  + TypeDrawinNormStep],
                   scene->ArrayNorVer_localPt[j+5  + TypeDrawinNormStep]);
        glVertex3f(scene->ArrayNorVer_localPt[j+3  + TypeDrawinNormStep]+40*scene->ArrayNorVer_localPt[j    + TypeDrawinNormStep],
                   scene->ArrayNorVer_localPt[j+4  + TypeDrawinNormStep]+40*scene->ArrayNorVer_localPt[j+1  + TypeDrawinNormStep],
                   scene->ArrayNorVer_localPt[j+5  + TypeDrawinNormStep]+40*scene->ArrayNorVer_localPt[j+2  + TypeDrawinNormStep]);
        glEnd();
    }
}

static void DrawNormals(ObjectProperties *scene)
{
    int j =  0;
    glColor4f (0.8, 0., 0.7, 1.0);
    for (unsigned int i=0; i< scene->PolyNumber; i+=4)
    {
        j =   TypeDrawin*scene->PolyIndices_localPt[i];
        glBegin( GL_LINES );
        glVertex3f(scene->ArrayNorVer_localPt[j+3  + TypeDrawinNormStep],
                   scene->ArrayNorVer_localPt[j+4  + TypeDrawinNormStep],
                   scene->ArrayNorVer_localPt[j+5  + TypeDrawinNormStep]);
        glVertex3f(scene->ArrayNorVer_localPt[j+3  + TypeDrawinNormStep]+40*scene->ArrayNorVer_localPt[j    + TypeDrawinNormStep],
                   scene->ArrayNorVer_localPt[j+4  + TypeDrawinNormStep]+40*scene->ArrayNorVer_localPt[j+1  + TypeDrawinNormStep],
                   scene->ArrayNorVer_localPt[j+5  + TypeDrawinNormStep]+40*scene->ArrayNorVer_localPt[j+2  + TypeDrawinNormStep]);
        glEnd();
    }
}

static int staticaction = 0;
/*
static void DrawPariso (ObjectProperties *scene)
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(scene->polyfactor, scene->polyunits);
    unsigned int  *strtinparam = &(scene->PolyIndices_localPt[scene->PolyNumberTmp1]);
    for(int i=0; i< scene->componentsinfos.NbParametric; i++)
    {
        glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, scene->backcolsPar[i]);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, scene->frontcolsPar[i]);

        glDrawElements(GL_QUADS ,4*scene->componentsinfos.Parametricpositions[2*i +1], GL_UNSIGNED_INT,
                       &(strtinparam[scene->componentsinfos.Parametricpositions[2*i]]));
    }

    for(int i=0; i< scene->componentsinfos.NbIso; i++)
    {
        glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, scene->backcols[i]);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, scene->frontcols[i]);
        glDrawElements(GL_TRIANGLES, 3*scene->componentsinfos.IsoPositions[2*i +1], GL_UNSIGNED_INT, &(scene->PolyIndices_localPt[scene->componentsinfos.IsoPositions[2*i]]));
    }

    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    //Draw mesh quads for parametric surfaces:
    //if (scene->line == 1)
    {
        glColor4f (scene->gridcol[0], scene->gridcol[1], scene->gridcol[2], scene->gridcol[3]);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(GL_QUADS, scene->PolyNumberTmp2, GL_UNSIGNED_INT, &(scene->PolyIndices_localPt[scene->PolyNumberTmp1]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }


    //Draw mesh polygons for isosurfaces:
    //if (scene->typedrawing == 1 && scene->isobox == 1)
    {
        glColor4f (scene->gridcol[0], scene->gridcol[1], scene->gridcol[2], scene->gridcol[3]);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        int startpl = 0;
        for (unsigned int i = 0; i < scene->NbPolygnNbVertexPtMin; i++)
        {
            int polysize       =  scene->PolyIndices_localPtMin[startpl++];
            glBegin(GL_POLYGON);
            for (int j = 0; j < polysize; j++)
            {
                int actualpointindice = scene->PolyIndices_localPtMin[startpl];
                glVertex3f(scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+3  + TypeDrawinNormStep],
                           scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+4  + TypeDrawinNormStep],
                           scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+5  + TypeDrawinNormStep]);
                startpl++;
            }
            glEnd();
        }
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}
*/

void OpenGlWidget::CreateGlLists()
{
    if (LocalScene.typedrawing == 1)
    {
        DrawMinimalTopologyListe(&LocalScene);
        DrawMeshIsoListe(&LocalScene);
        UpdateIsoColorliste(&LocalScene);
        UpdateFillIsoliste(&LocalScene);
        UpdateCNDIsoliste(&LocalScene);
    }
    if (LocalScene.typedrawing == -1)
    {
        DrawMeshParametricListe(&LocalScene);
        UpdateParColorliste(&LocalScene);
        UpdateFillParliste(&LocalScene);
        UpdateCNDParliste(&LocalScene);
    }
}

void OpenGlWidget::deleteAllListes()
{
    for(int i = 0; i < LocalScene.componentsinfos.NbParametric; i++)
    {
        glDeleteLists(LocalScene.ParColorliste[i],1);
        glDeleteLists(LocalScene.FillParliste[i],1);
        if(LocalScene.componentsinfos.ThereisCND)
        {
            glDeleteLists(LocalScene.CNDnotverifyParliste[i],1);
            glDeleteLists(LocalScene.CNDverifyParliste[i],1);
        }
    }
    glDeleteLists(LocalScene.MeshParliste, 1);

    glDeleteLists(LocalScene.MeshIsoliste, 1);
    for(int i = 0; i < LocalScene.componentsinfos.NbIso; i++)
    {
        glDeleteLists(LocalScene.IsoColorliste[i],1);
        glDeleteLists(LocalScene.FillIsoliste[i],1);
        if(LocalScene.componentsinfos.ThereisCND)
        {
            glDeleteLists(LocalScene.CNDnotverifyIsoliste[i],1);
            glDeleteLists(LocalScene.CNDverifyIsoliste[i],1);
        }
    }
    glDeleteLists(LocalScene.MeshIsoMinimalTopliste, 1);
}

void OpenGlWidget::toggleGlCache(bool cache)
{
    LocalScene.activateGlCache = cache;
    if(LocalScene.activateGlCache)
        CreateGlLists();
    else
        deleteAllListes();
    update();
}

void OpenGlWidget::initialize_GL()
{
    static int count =0;
    if(count <2)
    {
        /// For drawing Filled Polygones :
        glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
        glEnable(GL_NORMALIZE);
        glFrontFace (GL_CCW);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, LocalScene.frontcol);
        glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, LocalScene.backcol);

        glMaterialfv(GL_FRONT, GL_SPECULAR,LocalScene.specReflection);
        glMaterialfv(GL_BACK, GL_SPECULAR, LocalScene.specReflection);

        glMateriali(GL_FRONT, GL_SHININESS,LocalScene.shininess);
        glMateriali(GL_BACK, GL_SHININESS, LocalScene.shininess);
        glEnable(GL_DEPTH_TEST);

        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);


        boxok();
        InitFont();
        glInterleavedArrays (GL_C4F_N3F_V3F, 0, LocalScene.ArrayNorVer_localPt);
        count +=1;
    }

    PutObjectInsideCube();
    if(/*LocalScene.VertxNumber != 0 &&*/ LocalScene.activateGlCache)
        CreateGlLists();
}

void OpenGlWidget::UpdateGL()
{
    initialize_GL();
    update();
}

void OpenGlWidget::InitGlParameters()
{
    //reisialize IsoColors listes Filled
    if(LocalScene.activateGlCache)
    {
        if (LocalScene.typedrawing == 1)
            UpdateIsoColorliste(&LocalScene);
        if (LocalScene.typedrawing == -1)
            UpdateParColorliste(&LocalScene);
    }
}

static void DrawIsoCND_cache(ObjectProperties *scene)
{
    if(scene->componentsinfos.DMTrianglesVerifyCND)
    {
        glLineWidth(1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesVerifyCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[0]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }

    if(scene->componentsinfos.DMTrianglesNotVerifyCND)
    {
        glLineWidth(1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesNotVerifyCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[3*scene->componentsinfos.NbTrianglesVerifyCND]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }

    if(scene->componentsinfos.DMTrianglesBorderCND)
    {
        glLineWidth(4);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesBorderCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[3*(scene->componentsinfos.NbTrianglesVerifyCND + scene->componentsinfos.NbTrianglesNotVerifyCND) ]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }
}

static void DrawIsoCND(ObjectProperties *scene)
{
    if(scene->componentsinfos.DMTrianglesVerifyCND)
    {
        glLineWidth(1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesVerifyCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[0]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }

    if(scene->componentsinfos.DMTrianglesNotVerifyCND)
    {
        glLineWidth(1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesNotVerifyCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[3*scene->componentsinfos.NbTrianglesVerifyCND]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }

    if(scene->componentsinfos.DMTrianglesBorderCND)
    {
        glLineWidth(4);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesBorderCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[3*(scene->componentsinfos.NbTrianglesVerifyCND + scene->componentsinfos.NbTrianglesNotVerifyCND) ]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }
}

static void DrawParCND_cache(ObjectProperties *scene)
{
    if(scene->componentsinfos.DMTrianglesVerifyCND)
    {
        glLineWidth(1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesVerifyCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[0]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }

    if(scene->componentsinfos.DMTrianglesNotVerifyCND)
    {
        glLineWidth(1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesNotVerifyCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[3*scene->componentsinfos.NbTrianglesVerifyCND]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }

    if(scene->componentsinfos.DMTrianglesBorderCND)
    {
        glLineWidth(4);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesBorderCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[3*(scene->componentsinfos.NbTrianglesVerifyCND + scene->componentsinfos.NbTrianglesNotVerifyCND) ]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }
}

static void DrawParCND(ObjectProperties *scene)
{
    if(scene->componentsinfos.DMTrianglesVerifyCND)
    {
        glLineWidth(1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesVerifyCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[0]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }

    if(scene->componentsinfos.DMTrianglesNotVerifyCND)
    {
        glLineWidth(1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesNotVerifyCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[3*scene->componentsinfos.NbTrianglesVerifyCND]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }

    if(scene->componentsinfos.DMTrianglesBorderCND)
    {
        glLineWidth(4);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesBorderCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[3*(scene->componentsinfos.NbTrianglesVerifyCND + scene->componentsinfos.NbTrianglesNotVerifyCND) ]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }
}

static void DrawMeshIso(ObjectProperties *scene)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_TRIANGLES, scene->PolyNumber, GL_UNSIGNED_INT, scene->PolyIndices_localPt);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

static void DrawMinimalTopology (ObjectProperties *scene)
{
    glColor4f (scene->gridcol[0], scene->gridcol[1], scene->gridcol[2], scene->gridcol[3]);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    int startpl = 0;
    for (unsigned int i = 0; i < scene->NbPolygnNbVertexPtMin; i++)
    {
        int polysize       =  scene->PolyIndices_localPtMin[startpl++];
        glBegin(GL_POLYGON);
        for (int j = 0; j < polysize; j++)
        {
            int actualpointindice = scene->PolyIndices_localPtMin[startpl];
            glVertex3f(
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+3 + TypeDrawinNormStep],
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+4 + TypeDrawinNormStep],
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+5 + TypeDrawinNormStep]
            );
            startpl++;
        }
        glEnd();
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

static void DrawMeshParametric(ObjectProperties *scene)
{
    glColor4f (scene->gridcol[0], scene->gridcol[1], scene->gridcol[2], scene->gridcol[3]);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    int startpl = 0;
    for (unsigned int i = 0; i < scene->NbPolygnNbVertexPtMin; i++)
    {
        int polysize       =  scene->PolyIndices_localPtMin[startpl++];
        glBegin(GL_POLYGON);
        for (int j = 0; j < polysize; j++)
        {
            int actualpointindice = scene->PolyIndices_localPtMin[startpl];
            glVertex3f(
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+3 + TypeDrawinNormStep],
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+4 + TypeDrawinNormStep],
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+5 + TypeDrawinNormStep]
            );
            startpl++;
        }
        glEnd();
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

static void draw(ObjectProperties *scene)
{
    scene->box =1;
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (staticaction < 1)
    {
        glRotatef(270,1.0,0.0,0.0);
        glRotatef(225,0.0,0.0,1.0);
        glRotatef(-29,1.0,-1.0,0.0);
        staticaction += 1;

        glEnable (GL_LINE_SMOOTH);
        glEnable (GL_BLEND);
        //glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //glBlendFunc (GL_ONE, GL_ONE);
        glHint (GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
    }

    // Blend Effect activation:
    if (scene->transparency == 1)
        glDepthMask(GL_FALSE);

    // Ratation (Animation):
    if (scene->anim == 1 && scene->animxyz == 1)
    {
        glRotatef(scene->RotStrength, scene->axe_x, scene->axe_y, scene->axe_z);
    }

    // Plan:
    if (scene->infos == 1)
        glCallList(scene->gridplanliste);

    // Axe :
    if (scene->infos == 1)
        DrawAxe();

    //glLoadIdentity();
    // Box:
    //if (scene->box == 1) glCallList(scene->boxliste);
    glPushMatrix();

    if (scene->anim == 1 && scene->animx == 1)
    {
        scene->animxValue += scene->animxValueStep;
        glRotatef(scene->animxValue, 1.0, 0, 0);
    }

    if (scene->anim == 1 && scene->animy == 1)
    {
        scene->animyValue += scene->animyValueStep;
        glRotatef(scene->animyValue, 0, 1.0, 0);
    }

    if (scene->anim == 1 && scene->animz == 1)
    {
        scene->animzValue += scene->animzValueStep;
        glRotatef(scene->animzValue, 0, 0, 1.0);
    }

    /*
    // Draw Filled Object:
    if(scene->fill == 1 && scene->typedrawing == 11)
        DrawPariso(scene);
        */
    if (scene->fill == 1 && scene->typedrawing == 1)
        DrawIso(scene);
    if (scene->fill == 1 && scene->typedrawing == -1)
        DrawParametric(scene);



    // Draw Mesh Object:
    if (scene->triangles == 1 /*&& scene->typedrawing == 1*/)
        DrawMeshIso(scene);

    if (scene->mesh == 1 && scene->typedrawing == -1)
        DrawMeshParametric(scene);

    // Draw Minimal topology for isosurfaces:
    if (scene->mesh == 1  && scene->typedrawing == 1)
        DrawMinimalTopology(scene);

    if(scene->activarecnd && scene->componentsinfos.ThereisCND  && scene->typedrawing == 1)
        DrawIsoCND(scene);

    if(scene->activarecnd && scene->componentsinfos.ThereisCND  && scene->typedrawing == -1)
        DrawParCND(scene);

    //Draw Normales:
    if (scene->norm == 1 )
        DrawNormals(scene);

    glPopMatrix();

    if (scene->transparency == 1)
        glDepthMask(GL_TRUE);

    // Draw the scene:
    glFlush();
}

static void draw_cache(ObjectProperties *scene)
{
    //scene->typedrawing = 1;
    scene->box =1;
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (staticaction < 1)
    {
        glRotatef(270,1.0,0.0,0.0);
        glRotatef(225,0.0,0.0,1.0);
        glRotatef(-29,1.0,-1.0,0.0);
        staticaction += 1;

        glEnable (GL_LINE_SMOOTH);
        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint (GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
    }

    // Blend Effect activation:
    if (scene->transparency == 1)
        glDepthMask(GL_FALSE);

    // Ratation (Animation):
    if (scene->anim == 1 && scene->animxyz == 1)
    {
        glRotatef(scene->RotStrength, scene->axe_x, scene->axe_y, scene->axe_z);
    }

    // Plan:
    //if (scene->plan == 1)
    //glLoadIdentity();
    if (scene->infos == 1)
        glCallList(scene->gridplanliste);

    // Axe :
    if (scene->infos == 1)
        DrawAxe();

    //glLoadIdentity();
    // Box:
    //if (scene->box == 1) glCallList(scene->boxliste);
    glPushMatrix();

    if (scene->anim == 1 && scene->animx == 1)
    {
        scene->animxValue += scene->animxValueStep;
        glRotatef(scene->animxValue, 1.0, 0, 0);
    }

    if (scene->anim == 1 && scene->animy == 1)
    {
        scene->animyValue += scene->animyValueStep;
        glRotatef(scene->animyValue, 0, 1.0, 0);
    }

    if (scene->anim == 1 && scene->animz == 1)
    {
        scene->animzValue += scene->animzValueStep;
        glRotatef(scene->animzValue, 0, 0, 1.0);
    }

    if (scene->fill == 1 && scene->typedrawing == -1)
        DrawParametric_cache(scene);

    if (scene->fill == 1 && scene->typedrawing == 1)
        DrawIso_cache(scene);

    // Draw Mesh Object:
    if (scene->triangles == 1 && scene->typedrawing == 1)
        DrawMeshIso_cache(scene);

    if (scene->mesh == 1 && scene->typedrawing == -1)
        DrawMeshParametric_cache(scene);

    // Draw Minimal topology for isosurfaces:
    if (scene->mesh == 1  && scene->typedrawing == 1)
        DrawMinimalTopology_cache(scene);

    if(scene->activarecnd && scene->componentsinfos.ThereisCND  && scene->typedrawing == 1)
        DrawIsoCND_cache(scene);

    if(scene->activarecnd && scene->componentsinfos.ThereisCND  && scene->typedrawing == -1)
        DrawParCND_cache(scene);

    //Draw Normales:
    if (scene->norm == 1 )
        DrawNormals_cache(scene);

    glPopMatrix();

    if (scene->transparency == 1)
        glDepthMask(GL_TRUE);

    // Draw the scene:
    glFlush();
}





///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
        else {
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



///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
        else {
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



void OpenGlWidget::paintGL()
{
    if (LocalScene.morph == 1)
    {
        if(LocalScene.typedrawing == 11)
        {
            IsoObjetThread->IsoObjet->IsoBuild(
                LocalScene.ArrayNorVer_localPt,
                LocalScene.PolyIndices_localPt,
                &LocalScene.PolyNumberTmp1,
                &LocalScene.VertxNumberTmp1,
                LocalScene.PolyIndices_localPtMin,
                &(LocalScene.NbPolygnNbVertexPtMin),
                &(LocalScene.componentsinfos),
                LocalScene.Typetriangles,
                LocalScene.WichPointVerifyCond
            );

            ParObjetThread->ParObjet->ParamBuild(
                &(LocalScene.ArrayNorVer_localPt[TypeDrawin*(LocalScene.VertxNumberTmp1)]),
                LocalScene.ArrayNorVer_localPt,
                &(LocalScene.PolyIndices_localPt[LocalScene.PolyNumberTmp1]),
                &LocalScene.PolyNumberTmp2,
                &LocalScene.VertxNumberTmp2,
                LocalScene.VertxNumberTmp1,
                &(LocalScene.componentsinfos),
                LocalScene.Typetriangles,
                LocalScene.WichPointVerifyCond,
                LocalScene.PolyIndices_localPtMin,
                &(LocalScene.NbPolygnNbVertexPtMin)
            );

            LocalScene.PolyNumber = LocalScene.PolyNumberTmp1 + LocalScene.PolyNumberTmp2;
            LocalScene.VertxNumber= LocalScene.VertxNumberTmp1  + LocalScene.VertxNumberTmp2;

        }
        else if(LocalScene.typedrawing == -1)
        {
            ParObjetThread->ParObjet->ParamBuild
            (
                LocalScene.ArrayNorVer_localPt,
                LocalScene.ArrayNorVerExtra_localPt,
                LocalScene.PolyIndices_localPt,
                &LocalScene.PolyNumber,
                &LocalScene.VertxNumber,
                0,
                &(LocalScene.componentsinfos),
                LocalScene.Typetriangles,
                LocalScene.WichPointVerifyCond,
                LocalScene.PolyIndices_localPtMin,
                &(LocalScene.NbPolygnNbVertexPtMin)
            );
        }
        else if(LocalScene.typedrawing == 1)
        {
            IsoObjetThread->IsoObjet->IsoBuild
            (
                LocalScene.ArrayNorVer_localPt,
                LocalScene.PolyIndices_localPt,
                &(LocalScene.PolyNumber),
                &(LocalScene.VertxNumber),
                LocalScene.PolyIndices_localPtMin,
                &(LocalScene.NbPolygnNbVertexPtMin),
                &(LocalScene.componentsinfos),
                LocalScene.Typetriangles,
                LocalScene.WichPointVerifyCond
            );
        }
        initialize_GL();
    }
    //if(LocalScene.VertxNumber != 0)
    {
        if(LocalScene.activateGlCache)
            draw_cache(&LocalScene);
        else
            draw(&LocalScene);
    }
    if (LocalScene.infos == 1)  PrintInfos();
    if (LocalScene.morph == 1 && LocalScene.frame == 1)  FramesSave();
}

void OpenGlWidget::DrawPlan()
{
    GLuint list;

    list = glGenLists(1);
    glNewList( list, GL_COMPILE );

    glBegin( GL_LINE );
    glVertex3f(-400.0, 0.0, -400.0);
    glNormal3f(0.0, 0.0, 1.0);

    glVertex3f(-400.0, 0.0, 400.0);
    glNormal3f(0.0, 0.0, 1.0);

    glVertex3f(400.0, 0.0, 400.0);
    glNormal3f(0.0, 0.0, 1.0);

    glVertex3f(400.0, 0.0, -400.0);
    glNormal3f(0.0, 0.0, 1.0);
    glEnd();

    glEndList();
}



void OpenGlWidget::timerEvent(QTimerEvent*)
{
    update();
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
    GLfloat minx   = 999999999,  miny  = 999999999,  minz  = 999999999,
            maxx =-999999999,   maxy =-999999999, maxz =-999999999,
            difX, difY, difZ;

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

void OpenGlWidget::boxok()
{
    LocalScene.gridplanliste = glGenLists(1);
    glNewList(LocalScene.gridplanliste, GL_COMPILE );
    glLineWidth(1);
    glColor3f (0.8, 0.0, 0.7);
    glBegin( GL_LINES );
    glVertex3f(-150.0, 600.0, -350);
    glVertex3f(-150.0,-600.0, -350);
    glVertex3f(0.0, 600.0, -350);
    glVertex3f(0.0,-600.0, -350);

    glVertex3f(150.0, 600.0, -350);
    glVertex3f(150.0,-600.0, -350);
    glVertex3f(600.0, -150.0, -350);
    glVertex3f(-600.0,-150.0, -350);

    glVertex3f(600.0, 0.0, -350);
    glVertex3f(-600.0, 0.0, -350);
    glVertex3f(600.0, 150.0, -350);
    glVertex3f(-600.0, 150.0, -350);

    glVertex3f(-75.0, 600.0, -350);
    glVertex3f(-75.0,-600.0, -350);
    glVertex3f(-225.0, 600.0, -350);
    glVertex3f(-225.0,-600.0, -350);
    glVertex3f(-300.0, 600.0, -350);
    glVertex3f(-300.0,-600.0, -350);
    glVertex3f(-375.0, 600.0, -350);
    glVertex3f(-375.0,-600.0, -350);
    glVertex3f(-450.0, 600.0, -350);
    glVertex3f(-450.0,-600.0, -350);
    glVertex3f(-525.0, 600.0, -350);
    glVertex3f(-525.0,-600.0, -350);

    glVertex3f(75.0, 600.0, -350);
    glVertex3f(75.0,-600.0, -350);
    glVertex3f(225.0, 600.0, -350);
    glVertex3f(225.0,-600.0, -350);
    glVertex3f(300.0, 600.0, -350);
    glVertex3f(300.0,-600.0, -350);
    glVertex3f(375.0, 600.0, -350);
    glVertex3f(375.0,-600.0, -350);
    glVertex3f(450.0, 600.0, -350);
    glVertex3f(450.0,-600.0, -350);
    glVertex3f(525.0, 600.0, -350);
    glVertex3f(525.0,-600.0, -350);

    glVertex3f(600.0,-75.0, -350);
    glVertex3f(-600.0,-75.0, -350);
    glVertex3f(600.0,-225.0, -350);
    glVertex3f(-600.0,-225.0, -350);
    glVertex3f(600.0,-300.0, -350);
    glVertex3f(-600.0,-300.0, -350);
    glVertex3f(600.0,-375.0, -350);
    glVertex3f(-600.0,-375.0, -350);
    glVertex3f(600.0,-450.0, -350);
    glVertex3f(-600.0,-450.0, -350);
    glVertex3f(600.0,-525.0, -350);
    glVertex3f(-600.0,-525.0, -350);

    glVertex3f(600.0,75.0, -350);
    glVertex3f(-600.0,75.0, -350);
    glVertex3f(600.0,225.0, -350);
    glVertex3f(-600.0,225.0, -350);
    glVertex3f(600.0,300.0, -350);
    glVertex3f(-600.0,300.0, -350);
    glVertex3f(600.0,375.0, -350);
    glVertex3f(-600.0,375.0, -350);
    glVertex3f(600.0,450.0, -350);
    glVertex3f(-600.0,450.0, -350);
    glVertex3f(600.0,525.0, -350);
    glVertex3f(-600.0,525.0, -350);
    glEnd();
    glLineWidth(4.18);
    glEndList();
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

void OpenGlWidget::mouseMoveEvent( QMouseEvent *e )
{
    static double m[16];
    LocalScene.RotStrength = sqrt((LocalScene.oldRotx-e->x())*(LocalScene.oldRotx-e->x()) +
                                  (LocalScene.oldRoty-e->y())*(LocalScene.oldRoty-e->y()))/2.;
    LocalScene.oldRoty = e->y();
    LocalScene.oldRotx = e->x();

// Scale function :
    if (btdroit ==1)
    {
        if (old_y - e->y() > 0 ) LocalScene.ScalCoeff = 1.02f;
        else if ( LocalScene.ScalCoeff > 0.1f ) LocalScene.ScalCoeff = 0.98f;
        glScalef(LocalScene.ScalCoeff, LocalScene.ScalCoeff, LocalScene.ScalCoeff);
        LocalScene.view_rotx = LocalScene.view_roty = 0.0;
    }
// Rotational function :
    if (btgauche ==1)
    {
        LocalScene.view_roty = -(old_y - e->y());
        LocalScene.view_rotx = -(old_x - e->x());
        LocalScene.ScalCoeff = 1.0;

        glGetIntegerv(GL_VIEWPORT,LocalScene.viewport);
        glGetDoublev(GL_MODELVIEW_MATRIX,LocalScene.matrix);
        memcpy(m, LocalScene.matrix, 16*sizeof(GLdouble));

        ///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++///
        GLdouble det;
        GLdouble d12, d13, d23, d24, d34, d41;
        GLdouble tmp[16]; /* Allow out == in. */

        /* Inverse = adjoint / det. (See linear algebra texts.)*/
        /* pre-compute 2x2 dets for last two rows when computing */
        /* cofactors of first two rows. */
        d12 = (m31*m42-m41*m32);
        d13 = (m31*m43-m41*m33);
        d23 = (m32*m43-m42*m33);
        d24 = (m32*m44-m42*m34);
        d34 = (m33*m44-m43*m34);
        d41 = (m34*m41-m44*m31);

        tmp[0] =  (m22 * d34 - m23 * d24 + m24 * d23);
        tmp[1] = -(m21 * d34 + m23 * d41 + m24 * d13);
        tmp[2] =  (m21 * d24 + m22 * d41 + m24 * d12);
        tmp[3] = -(m21 * d23 - m22 * d13 + m23 * d12);

        /* Compute determinant as early as possible using these cofactors. */
        det = m11 * tmp[0] + m12 * tmp[1] + m13 * tmp[2] + m14 * tmp[3];

        /* Run singularity test. */
        if (det != 0.0)
        {
            GLdouble invDet = 1.0 / det;
            /* Compute rest of inverse. */
            tmp[0] *= invDet;
            tmp[1] *= invDet;
            tmp[2] *= invDet;
            tmp[3] *= invDet;

            tmp[4] = -(m12 * d34 - m13 * d24 + m14 * d23) * invDet;
            tmp[5] =  (m11 * d34 + m13 * d41 + m14 * d13) * invDet;
            tmp[6] = -(m11 * d24 + m12 * d41 + m14 * d12) * invDet;
            tmp[7] =  (m11 * d23 - m12 * d13 + m13 * d12) * invDet;

            d12 = m11*m22-m21*m12;
            d13 = m11*m23-m21*m13;
            d23 = m12*m23-m22*m13;
            d24 = m12*m24-m22*m14;
            d34 = m13*m24-m23*m14;
            d41 = m14*m21-m24*m11;

            tmp[8]  =  (m42 * d34 - m43 * d24 + m44 * d23) * invDet;
            tmp[9]  = -(m41 * d34 + m43 * d41 + m44 * d13) * invDet;
            tmp[10] =  (m41 * d24 + m42 * d41 + m44 * d12) * invDet;
            tmp[11] = -(m41 * d23 - m42 * d13 + m43 * d12) * invDet;
            tmp[12] = -(m32 * d34 - m33 * d24 + m34 * d23) * invDet;
            tmp[13] =  (m31 * d34 + m33 * d41 + m34 * d13) * invDet;
            tmp[14] = -(m31 * d24 + m32 * d41 + m34 * d12) * invDet;
            tmp[15] =  (m31 * d23 - m32 * d13 + m33 * d12) * invDet;
            memcpy(LocalScene.matrixInverse, tmp, 16*sizeof(GLdouble));
        }
        double ax,ay;
        ax = LocalScene.view_roty;
        ay = LocalScene.view_rotx;
        anglefinal += (angle = sqrt(ax*ax + ay*ay)/(double)(LocalScene.viewport[2]+1)*360.0);
        LocalScene.axe_x = Axe_x = LocalScene.matrixInverse[0]*ax + LocalScene.matrixInverse[4]*ay;
        LocalScene.axe_y = Axe_y = LocalScene.matrixInverse[1]*ax + LocalScene.matrixInverse[5]*ay;
        LocalScene.axe_z = Axe_z = LocalScene.matrixInverse[2]*ax + LocalScene.matrixInverse[6]*ay;
        glRotatef(angle,Axe_x,Axe_y,Axe_z);
    }
    old_y = e->y();
    old_x = e->x();
    update();
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

void OpenGlWidget::screenshot()
{
    QImage image = grabFrameBuffer();
    if(LocalScene.png_ok == 1) image.save("GLscreenshot.png", "PNG" , LocalScene.quality_image);
    if(LocalScene.bmp_ok == 1) image.save("GLscreenshot.bmp", "BMP" , LocalScene.quality_image);
}

void OpenGlWidget::FramesShot()
{
    LocalScene.frame *= -1;
    if(LocalScene.frame == 1)
    {
        FramesDir        = QFileDialog::getExistingDirectory(this,
                           tr("Choose Or Create Directory"),
                           FramesDir,
                           QFileDialog::DontResolveSymlinks);
        if(FramesDir != "" && !FramesDir.endsWith("/"))
            FramesDir +="/";
    }
}

void OpenGlWidget::FramesSave()
{
    static int Index =0;
    if(LocalScene.frame == 1)
    {
        QImage image = grabFrameBuffer();
        QString FileName = FramesDir+QString("%1").arg(Index, 5, 10, QChar('0'))+".png";
        Index +=1;
        image.save(FileName, "PNG" , 1);
    }
}

QImage OpenGlWidget::Copyscreenshot()
{
    return(grabFrameBuffer());
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

void OpenGlWidget::transparency(int cl, int currentposition)
{
    switch(LocalScene.colortype)
    {
    case 1:
        LocalScene.frontcols[currentposition*4+3] = (cl/255.);
        break;
    case 0:
        LocalScene.backcols[currentposition*4+3]  = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[3] = (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[3] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };
    InitGlParameters();
    update();
}

void OpenGlWidget::transparencypar(int cl, int currentposition)
{
    switch(LocalScene.colortypeParam)
    {
    case 1:
        LocalScene.frontcolsPar[currentposition*4+3] = (cl/255.) ;
        break;
    case 0:
        LocalScene.backcolsPar[currentposition*4+3] = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[3] = (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[3] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };
    InitGlParameters();
    update();
}

void OpenGlWidget::red(int cl, int currentposition)
{
    switch(LocalScene.colortype)
    {
    case 1:
        LocalScene.frontcols[currentposition*4+0] = (cl/255.);
        break;
    case 0:
        LocalScene.backcols[currentposition*4+0]  =  (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[0] =  (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[0] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };
    InitGlParameters();
    update();
}

void OpenGlWidget::redpar(int cl, int currentposition)
{
    switch(LocalScene.colortypeParam)
    {
    case 1:
        LocalScene.frontcolsPar[currentposition*4+0] = (cl/255.);
        break;
    case 0:
        LocalScene.backcolsPar[currentposition*4+0] = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[0] =  (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[0] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };
    InitGlParameters();
    update();
}

void OpenGlWidget::green(int cl, int currentposition)
{
    switch(LocalScene.colortype)
    {
    case 1:
        LocalScene.frontcols[currentposition*4+1] = (cl/255.);
        break;
    case 0:
        LocalScene.backcols[currentposition*4+1]  = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[1] = (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[1] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1], LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };
    InitGlParameters();
    update();
}

void OpenGlWidget::greenpar(int cl, int currentposition)
{
    switch(LocalScene.colortypeParam)
    {
    case 1:
        LocalScene.frontcolsPar[currentposition*4+1] = (cl/255.);
        break;
    case 0:
        LocalScene.backcolsPar[currentposition*4+1] = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[1] = (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[1] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1], LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };
    InitGlParameters();
    update();
}

void OpenGlWidget::blue(int cl, int currentposition)
{
    switch(LocalScene.colortype)
    {
    case 1:
        LocalScene.frontcols[currentposition*4+2] = (cl/255.);
        break;
    case 0:
        LocalScene.backcols[currentposition*4+2]  = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[2] = (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[2] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };
    InitGlParameters();
    update();
}

void OpenGlWidget::bluepar(int cl, int currentposition)
{
    switch(LocalScene.colortypeParam)
    {
    case 1:
        LocalScene.frontcolsPar[currentposition*4+2] = (cl/255.);
        break;
    case 0:
        LocalScene.backcolsPar[currentposition*4+2] = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[2] = (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[2] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };
    InitGlParameters();
    update();
}

void OpenGlWidget::transparence(bool trs)
{
    LocalScene.transparency *=-1;
    if (trs)
    {
        glEnable(GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE);
    }
    else glDisable(GL_BLEND);
    InitGlParameters();
    update();
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

void OpenGlWidget::transSpec(int cl)
{
    LocalScene.specReflection[3] =  (cl/100.0);
    InitSpecularParameters();
}

void OpenGlWidget::Shininess(int cl)
{
    LocalScene.shininess =  cl;
    InitSpecularParameters();
}

void OpenGlWidget::InitSpecularParameters()
{
    /// For drawing Filled Polygones :
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_NORMALIZE);
    glFrontFace (GL_CCW);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, LocalScene.frontcol);
    glMaterialfv(GL_BACK , GL_AMBIENT_AND_DIFFUSE, LocalScene.backcol);

    glMaterialfv(GL_FRONT, GL_SPECULAR, LocalScene.specReflection);
    glMaterialfv(GL_BACK , GL_SPECULAR, LocalScene.specReflection);

    glMateriali(GL_FRONT, GL_SHININESS, LocalScene.shininess);
    glMateriali(GL_BACK , GL_SHININESS, LocalScene.shininess);
    glEnable(GL_DEPTH_TEST);
    update();
}
