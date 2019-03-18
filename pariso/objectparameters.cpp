/***************************************************************************
 *   Copyright (C) 2019 by Abderrahman Taha                                *
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
#include "objectparameters.h"

static float StaticColor[20]=
{
//Green(Back face)
    0.3f,0.5f,0.0f,1.0f,
//Gold (Front face)
    249.0f/255.0f,170.0f/255.0f,0.0f,1.0f,
// grid:
    0.1f,0.3f,0.1f,0.5f,
//Background:
    0.0f,0.0f,0.0f,1.0f,
//Condition:
    1.0f,0.2f,0.0f,1.0f
}; // greencol, goldcol,...

ObjectParameters::ObjectParameters(uint maxpoints, uint maxtriangles)
{
    MaximumNumberPoints            = maxpoints;
    MaximumNumberTriangles         = maxtriangles;

    objectproperties.ArrayNorVer_localPt           = new float[10*MaximumNumberPoints];
    objectproperties.ArrayNorVerExtra_localPt      = new float[MaximumNumberPoints   ];
    objectproperties.PolyIndices_localPt           = new unsigned int [4*MaximumNumberTriangles]; //size is 4*MaximumNumberTriangles because of parametric surface
    objectproperties.PolyIndices_localPtMin        = new unsigned int [5*MaximumNumberTriangles];
    objectproperties.BorderPoints                  = new float[3*MaximumNumberPoints ];
    objectproperties.Typetriangles                 = new int  [MaximumNumberTriangles];
    objectproperties.WichPointVerifyCond           = new bool [MaximumNumberPoints];
    objectproperties.VertxNumber    = objectproperties.PolyNumber = objectproperties.NbPolygnNbVertexPtMin = 0;
    objectproperties.RotStrength    = 0;
    objectproperties.zminim         = -350.0;
    objectproperties.polyfactor     = 1.0;
    objectproperties.polyunits      = 1.0;
    objectproperties.ScalCoeff      = 1.0;
    objectproperties.view_rotx      = 90.0;
    objectproperties.view_roty      = 90.0;
    objectproperties.view_rotz      = 1.0;
    objectproperties.IndexCurrentFormula = -1;

    objectproperties.IsoColorliste          = new unsigned int[NbComponent];
    objectproperties.ParColorliste          = new unsigned int[NbComponent];
    objectproperties.FillIsoliste           = new unsigned int[NbComponent];
    objectproperties.FillParliste           = new unsigned int[NbComponent];
    objectproperties.CNDverifyIsoliste      = new unsigned int[NbComponent];
    objectproperties.CNDverifyParliste      = new unsigned int[NbComponent];
    objectproperties.CNDnotverifyIsoliste   = new unsigned int[NbComponent];
    objectproperties.CNDnotverifyParliste   = new unsigned int[NbComponent];

    objectproperties.frontcols    = new float[4*NbComponent];
    objectproperties.backcols     = new float[4*NbComponent];
    objectproperties.frontcolsPar = new float[4*NbComponent];
    objectproperties.backcolsPar  = new float[4*NbComponent];

    objectproperties.red[0]   = 1.0;
    objectproperties.red[1]   = 0.0;
    objectproperties.red[2]   = 0.0;
    objectproperties.red[3]   = 1.0;

    objectproperties.gridcol[0]   = StaticColor[8];
    objectproperties.gridcol[1]   = StaticColor[9];
    objectproperties.gridcol[2]   = StaticColor[10];
    objectproperties.gridcol[3]   = .5;
    objectproperties.groundcol[0] = StaticColor[12];
    objectproperties.groundcol[1] = StaticColor[13];
    objectproperties.groundcol[2] = StaticColor[14];
    objectproperties.groundcol[3] = 1.0;

    //objectproperties.specReflection[0] = objectproperties.specReflection[1] = objectproperties.specReflection[2] = 0.2; objectproperties.specReflection[3] = 1.0;

    objectproperties.backcol[0]   = objectproperties.backcols[0]   = objectproperties.backcolsPar[0]   = 0.2f;
    objectproperties.backcol[1]   = objectproperties.backcols[1]   = objectproperties.backcolsPar[1]   = 0.8f;
    objectproperties.backcol[2]   = objectproperties.backcols[2]   = objectproperties.backcolsPar[2]   = 0.1f;
    objectproperties.backcol[3]   = objectproperties.backcols[3]   = objectproperties.backcolsPar[3]   = 1.0f;

    objectproperties.backcols[1*4+0]   = objectproperties.backcolsPar[1*4+0]   = 0.6f;
    objectproperties.backcols[1*4+1]   = objectproperties.backcolsPar[1*4+1]   = 0.6f;
    objectproperties.backcols[1*4+2]   = objectproperties.backcolsPar[1*4+2]   = 0.9f;
    objectproperties.backcols[1*4+3]   = objectproperties.backcolsPar[1*4+3]   = 1.0f;

    objectproperties.backcols[2*4+0]   = objectproperties.backcolsPar[2*4+0]   = 0.8f;
    objectproperties.backcols[2*4+1]   = objectproperties.backcolsPar[2*4+1]   = 0.6f;
    objectproperties.backcols[2*4+2]   = objectproperties.backcolsPar[2*4+2]   = 0.3f;
    objectproperties.backcols[2*4+3]   = objectproperties.backcolsPar[2*4+3]   = 1.0f;

    objectproperties.backcols[3*4+0]   = objectproperties.backcolsPar[3*4+0]   = 0.9f;
    objectproperties.backcols[3*4+1]   = objectproperties.backcolsPar[3*4+1]   = 0.8f;
    objectproperties.backcols[3*4+2]   = objectproperties.backcolsPar[3*4+2]   = 0.6f;
    objectproperties.backcols[3*4+3]   = objectproperties.backcolsPar[3*4+3]   = 1.0f;

    objectproperties.backcols[4*4+0]   = objectproperties.backcolsPar[4*4+0]   = 0.93f;
    objectproperties.backcols[4*4+1]   = objectproperties.backcolsPar[4*4+1]   = 0.2f;
    objectproperties.backcols[4*4+2]   = objectproperties.backcolsPar[4*4+2]   = 0.1f;
    objectproperties.backcols[4*4+3]   = objectproperties.backcolsPar[4*4+3]   = 1.0f;

    objectproperties.backcols[5*4+0]   = objectproperties.backcolsPar[5*4+0]   = 0.3f;
    objectproperties.backcols[5*4+1]   = objectproperties.backcolsPar[5*4+1]   = 0.72f;
    objectproperties.backcols[5*4+2]   = objectproperties.backcolsPar[5*4+2]   = 0.63f;
    objectproperties.backcols[5*4+3]   = objectproperties.backcolsPar[5*4+3]   = 1.0f;

    objectproperties.backcols[6*4+0]   = objectproperties.backcolsPar[6*4+0]   = 0.1f;
    objectproperties.backcols[6*4+1]   = objectproperties.backcolsPar[6*4+1]   = 0.5f;
    objectproperties.backcols[6*4+2]   = objectproperties.backcolsPar[6*4+2]   = 0.73f;
    objectproperties.backcols[6*4+3]   = objectproperties.backcolsPar[6*4+3]   = 1.0f;

    objectproperties.backcols[7*4+0]   = objectproperties.backcolsPar[7*4+0]   = 0.9f;
    objectproperties.backcols[7*4+1]   = objectproperties.backcolsPar[7*4+1]   = 0.5f;
    objectproperties.backcols[7*4+2]   = objectproperties.backcolsPar[7*4+2]   = 0.3f;
    objectproperties.backcols[7*4+3]   = objectproperties.backcolsPar[7*4+3]   = 1.0f;

    objectproperties.backcols[8*4+0]   = objectproperties.backcolsPar[8*4+0]   = 0.8f;
    objectproperties.backcols[8*4+1]   = objectproperties.backcolsPar[8*4+1]   = 0.8f;
    objectproperties.backcols[8*4+2]   = objectproperties.backcolsPar[8*4+2]   = 0.6f;
    objectproperties.backcols[8*4+3]   = objectproperties.backcolsPar[8*4+3]   = 1.0f;

    objectproperties.backcols[9*4+0]   = objectproperties.backcolsPar[9*4+0]   = 0.7f;
    objectproperties.backcols[9*4+1]   = objectproperties.backcolsPar[9*4+1]   = 0.9f;
    objectproperties.backcols[9*4+2]   = objectproperties.backcolsPar[9*4+2]   = 0.93f;
    objectproperties.backcols[9*4+3]   = objectproperties.backcolsPar[9*4+3]   = 1.0f;

    objectproperties.frontcol[0]  = objectproperties.frontcols[0] = objectproperties.frontcolsPar[0] = 0.9f;
    objectproperties.frontcol[1]  = objectproperties.frontcols[1] = objectproperties.frontcolsPar[1] = 0.6f;
    objectproperties.frontcol[2]  = objectproperties.frontcols[2] = objectproperties.frontcolsPar[2] = 0.1f;
    objectproperties.frontcol[3]  = objectproperties.frontcols[3] = objectproperties.frontcolsPar[3] = 1.0f;

    objectproperties.frontcols[1*4+0] = objectproperties.frontcolsPar[1*4+0] = 0.3f;
    objectproperties.frontcols[1*4+1] = objectproperties.frontcolsPar[1*4+1] = 0.8f;
    objectproperties.frontcols[1*4+2] = objectproperties.frontcolsPar[1*4+2] = 0.5f;
    objectproperties.frontcols[1*4+3] = objectproperties.frontcolsPar[1*4+3] = 1.0f;

    objectproperties.frontcols[2*4+0] = objectproperties.frontcolsPar[2*4+0] = 0.2f;
    objectproperties.frontcols[2*4+1] = objectproperties.frontcolsPar[2*4+1] = 0.5f;
    objectproperties.frontcols[2*4+2] = objectproperties.frontcolsPar[2*4+2] = 0.6f;
    objectproperties.frontcols[2*4+3] = objectproperties.frontcolsPar[2*4+3] = 1.0f;

    objectproperties.frontcols[3*4+0] = objectproperties.frontcolsPar[3*4+0] = 0.1f;
    objectproperties.frontcols[3*4+1] = objectproperties.frontcolsPar[3*4+1] = 0.3f;
    objectproperties.frontcols[3*4+2] = objectproperties.frontcolsPar[3*4+2] = 0.9f;
    objectproperties.frontcols[3*4+3] = objectproperties.frontcolsPar[3*4+3] = 1.0f;

    objectproperties.frontcols[4*4+0] = objectproperties.frontcolsPar[4*4+0] = 0.96f;
    objectproperties.frontcols[4*4+1] = objectproperties.frontcolsPar[4*4+1] = 0.71f;
    objectproperties.frontcols[4*4+2] = objectproperties.frontcolsPar[4*4+2] = 0.3f;
    objectproperties.frontcols[4*4+3] = objectproperties.frontcolsPar[4*4+3] = 1.0f;

    objectproperties.frontcols[5*4+0] = objectproperties.frontcolsPar[5*4+0] = 0.1f;
    objectproperties.frontcols[5*4+1] = objectproperties.frontcolsPar[5*4+1] = 0.2f;
    objectproperties.frontcols[5*4+2] = objectproperties.frontcolsPar[5*4+2] = 0.9f;
    objectproperties.frontcols[5*4+3] = objectproperties.frontcolsPar[5*4+3] = 1.0f;

    objectproperties.frontcols[6*4+0] = objectproperties.frontcolsPar[6*4+0] = 0.99f;
    objectproperties.frontcols[6*4+1] = objectproperties.frontcolsPar[6*4+1] = 0.1f;
    objectproperties.frontcols[6*4+2] = objectproperties.frontcolsPar[6*4+2] = 0.843f;
    objectproperties.frontcols[6*4+3] = objectproperties.frontcolsPar[6*4+3] = 1.0f;

    objectproperties.frontcols[7*4+0] = objectproperties.frontcolsPar[7*4+0] = 0.16f;
    objectproperties.frontcols[7*4+1] = objectproperties.frontcolsPar[7*4+1] = 0.91f;
    objectproperties.frontcols[7*4+2] = objectproperties.frontcolsPar[7*4+2] = 0.73f;
    objectproperties.frontcols[7*4+3] = objectproperties.frontcolsPar[7*4+3] = 1.0f;

    objectproperties.frontcols[8*4+0] = objectproperties.frontcolsPar[8*4+0] = 0.8f;
    objectproperties.frontcols[8*4+1] = objectproperties.frontcolsPar[8*4+1] = 0.9f;
    objectproperties.frontcols[8*4+2] = objectproperties.frontcolsPar[8*4+2] = 0.0f;
    objectproperties.frontcols[8*4+3] = objectproperties.frontcolsPar[8*4+3] = 1.0f;

    objectproperties.frontcols[9*4+0] = objectproperties.frontcolsPar[9*4+0] = 0.9f;
    objectproperties.frontcols[9*4+1] = objectproperties.frontcolsPar[9*4+1] = 0.91f;
    objectproperties.frontcols[9*4+2] = objectproperties.frontcolsPar[9*4+2] = 0.3f;
    objectproperties.frontcols[9*4+3] = objectproperties.frontcolsPar[9*4+3] = 1.0f;

    uint step = 4;
    for(uint i=step; i<NbComponent; i++)
    {
        objectproperties.frontcols[i*4+0] = objectproperties.frontcolsPar[i*4+0] = objectproperties.frontcolsPar[(i%step)*4+0];
        objectproperties.frontcols[i*4+1] = objectproperties.frontcolsPar[i*4+1] = objectproperties.frontcolsPar[(i%step)*4+1];
        objectproperties.frontcols[i*4+2] = objectproperties.frontcolsPar[i*4+2] = objectproperties.frontcolsPar[(i%step)*4+2];
        objectproperties.frontcols[i*4+3] = objectproperties.frontcolsPar[i*4+3] = 1;

        objectproperties.backcols[i*4+0] = objectproperties.backcolsPar[i*4+0] = objectproperties.backcolsPar[(i%step)*4+0];
        objectproperties.backcols[i*4+1] = objectproperties.backcolsPar[i*4+1] = objectproperties.backcolsPar[(i%step)*4+1];
        objectproperties.backcols[i*4+2] = objectproperties.backcolsPar[i*4+2] = objectproperties.backcolsPar[(i%step)*4+2];
        objectproperties.backcols[i*4+3] = objectproperties.backcolsPar[i*4+3] = 1;
    }
    objectproperties.border              = 1;
    objectproperties.mesh                = 1;
    objectproperties.activarecnd         = true;
    objectproperties.specReflection[0]   = objectproperties.specReflection[1] = objectproperties.specReflection[2] = 0.2f;
    objectproperties.specReflection[3]   = 1.0;
    objectproperties.shininess           = 110;
    objectproperties.fill                = 1;
    objectproperties.line                = 1;
    objectproperties.infos               = 1;
    objectproperties.frame               = -1;
    objectproperties.infosdetails[0]  = objectproperties.infosdetails[1] = objectproperties.infosdetails[2] = 1;
    objectproperties.axe                 = 1;
    objectproperties.box                 = 1;
    objectproperties.boundingbox         = -1;
    objectproperties.isobox              = 1;
    objectproperties.triangles           = -1;
    objectproperties.typedrawing         =  1;
    objectproperties.smoothpoly          = 1;
    objectproperties.smoothline          = -1;
    objectproperties.anim                = -1;
    objectproperties.animx               = -1;
    objectproperties.animy               = -1;
    objectproperties.animz               = -1;
    objectproperties.animxyz             = 1;
    objectproperties.animxValue = objectproperties.animyValue  = objectproperties.animzValue = 0.0;
    objectproperties.animxValueStep = objectproperties.animyValueStep = objectproperties.animzValueStep = 0.0;
    objectproperties.slider              =-1;
    objectproperties.morph               =-1;
    objectproperties.morphstep           =-1;
    objectproperties.norm                =-1;
    objectproperties.plan                = 1;
    objectproperties.front               = 1;
    objectproperties.back                = 1;
    objectproperties.transparency        =-1;
    objectproperties.png_ok              = 1;
    objectproperties.jpg_ok = objectproperties.bmp_ok = -1;
    objectproperties.quality_image  = 50;
    objectproperties.colortype      = 0;
    objectproperties.colortypeParam = 0;

    InitComponentinfos(objectproperties.componentsinfos);
    InitComponentinfos(componentsStr);
}

void ObjectParameters::InitComponentinfos(struct  ComponentInfos & compinfos)
{
    compinfos.IsoPositions        = new uint[2*NbComponent+1];
    compinfos.IsoPts              = new uint[2*NbComponent+1];
    compinfos.Parametricpositions = new uint[3*NbComponent+1];
    compinfos.ParPts              = new uint[2*NbComponent+1];

    compinfos.NoiseParam.Octaves     = 4;
    compinfos.NoiseParam.Lacunarity  = 0.5;
    compinfos.NoiseParam.Gain        = 0.5;
    compinfos.NoiseParam.NoiseActive = 1;

    compinfos.DFTrianglesNotVerifyCND =
        compinfos.DFTrianglesVerifyCND =
            compinfos.DMTrianglesBorderCND = true;
    compinfos.DMTrianglesNotVerifyCND =
        compinfos.DMTrianglesVerifyCND = false;
}
