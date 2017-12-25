/***************************************************************************
 *   Copyright (C) 2017 by Abderrahman Taha                                *
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
    0.3,0.5,0.0,1.0,
//Gold (Front face)
    249./255.,170./255.,0.0,1.0,
// grid:
    0.1,0.4,0.1,1.0,
//Background:
    0.0,0.0,0.0,1.0,
//Condition:
    1.0,0.2,0.0,1.0
}; // greencol, goldcol,...

ObjectParameters::ObjectParameters(int maxpoints, int maxtriangles)
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

    objectproperties.componentsinfos.IsoPositions        = new int[2*NbComponent+1];
    objectproperties.componentsinfos.IsoPts              = new int[2*NbComponent+1];
    objectproperties.componentsinfos.Parametricpositions = new int[2*NbComponent+1];

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

    objectproperties.backcol[0]   = objectproperties.backcols[0]   = objectproperties.backcolsPar[0]   = StaticColor[0];
    objectproperties.backcol[1]   = objectproperties.backcols[1]   = objectproperties.backcolsPar[1]   = StaticColor[1];
    objectproperties.backcol[2]   = objectproperties.backcols[2]   = objectproperties.backcolsPar[2]   = StaticColor[2];
    objectproperties.backcol[3]   = objectproperties.backcols[3]   = objectproperties.backcolsPar[3]   = 1.0;

    objectproperties.backcols[1*4+0]   = objectproperties.backcolsPar[1*4+0]   = 0.93;
    objectproperties.backcols[1*4+1]   = objectproperties.backcolsPar[1*4+1]   = 0.5;
    objectproperties.backcols[1*4+2]   = objectproperties.backcolsPar[1*4+2]   = 0.93;
    objectproperties.backcols[1*4+3]   = objectproperties.backcolsPar[1*4+3]   = 1.0;

    objectproperties.backcols[2*4+0]   = objectproperties.backcolsPar[2*4+0]   = 0.93;
    objectproperties.backcols[2*4+1]   = objectproperties.backcolsPar[2*4+1]   = 0.1;
    objectproperties.backcols[2*4+2]   = objectproperties.backcolsPar[2*4+2]   = 0.1;
    objectproperties.backcols[2*4+3]   = objectproperties.backcolsPar[2*4+3]   = 1.0;

    objectproperties.backcols[3*4+0]   = objectproperties.backcolsPar[3*4+0]   = 0.513;
    objectproperties.backcols[3*4+1]   = objectproperties.backcolsPar[3*4+1]   = 0.2;
    objectproperties.backcols[3*4+2]   = objectproperties.backcolsPar[3*4+2]   = 0.9;
    objectproperties.backcols[3*4+3]   = objectproperties.backcolsPar[3*4+3]   = 1.0;

    objectproperties.backcols[4*4+0]   = objectproperties.backcolsPar[4*4+0]   = 0.93;
    objectproperties.backcols[4*4+1]   = objectproperties.backcolsPar[4*4+1]   = 0.2;
    objectproperties.backcols[4*4+2]   = objectproperties.backcolsPar[4*4+2]   = 0.1;
    objectproperties.backcols[4*4+3]   = objectproperties.backcolsPar[4*4+3]   = 1.0;

    objectproperties.backcols[5*4+0]   = objectproperties.backcolsPar[5*4+0]   = 0.3;
    objectproperties.backcols[5*4+1]   = objectproperties.backcolsPar[5*4+1]   = 0.72;
    objectproperties.backcols[5*4+2]   = objectproperties.backcolsPar[5*4+2]   = 0.63;
    objectproperties.backcols[5*4+3]   = objectproperties.backcolsPar[5*4+3]   = 1.0;

    objectproperties.backcols[6*4+0]   = objectproperties.backcolsPar[6*4+0]   = 0.1;
    objectproperties.backcols[6*4+1]   = objectproperties.backcolsPar[6*4+1]   = 0.5;
    objectproperties.backcols[6*4+2]   = objectproperties.backcolsPar[6*4+2]   = 0.73;
    objectproperties.backcols[6*4+3]   = objectproperties.backcolsPar[6*4+3]   = 1.0;

    objectproperties.backcols[7*4+0]   = objectproperties.backcolsPar[7*4+0]   = 0.9;
    objectproperties.backcols[7*4+1]   = objectproperties.backcolsPar[7*4+1]   = 0.5;
    objectproperties.backcols[7*4+2]   = objectproperties.backcolsPar[7*4+2]   = 0.3;
    objectproperties.backcols[7*4+3]   = objectproperties.backcolsPar[7*4+3]   = 1.0;

    objectproperties.backcols[8*4+0]   = objectproperties.backcolsPar[8*4+0]   = 0.8;
    objectproperties.backcols[8*4+1]   = objectproperties.backcolsPar[8*4+1]   = 0.8;
    objectproperties.backcols[8*4+2]   = objectproperties.backcolsPar[8*4+2]   = 0.6;
    objectproperties.backcols[8*4+3]   = objectproperties.backcolsPar[8*4+3]   = 1.0;

    objectproperties.backcols[9*4+0]   = objectproperties.backcolsPar[9*4+0]   = 0.7;
    objectproperties.backcols[9*4+1]   = objectproperties.backcolsPar[9*4+1]   = 0.9;
    objectproperties.backcols[9*4+2]   = objectproperties.backcolsPar[9*4+2]   = 0.93;
    objectproperties.backcols[9*4+3]   = objectproperties.backcolsPar[9*4+3]   = 1.0;

    objectproperties.frontcol[0]  = objectproperties.frontcols[0] = objectproperties.frontcolsPar[0] = StaticColor[4];
    objectproperties.frontcol[1]  = objectproperties.frontcols[1] = objectproperties.frontcolsPar[1] = StaticColor[5];
    objectproperties.frontcol[2]  = objectproperties.frontcols[2] = objectproperties.frontcolsPar[2] = StaticColor[6];
    objectproperties.frontcol[3]  = objectproperties.frontcols[3] = objectproperties.frontcolsPar[3] = 1.0;

    objectproperties.frontcols[1*4+0] = objectproperties.frontcolsPar[1*4+0] = 0.1;
    objectproperties.frontcols[1*4+1] = objectproperties.frontcolsPar[1*4+1] = 0.6;
    objectproperties.frontcols[1*4+2] = objectproperties.frontcolsPar[1*4+2] = 0.1;
    objectproperties.frontcols[1*4+3] = objectproperties.frontcolsPar[1*4+3] = 1.0;

    objectproperties.frontcols[2*4+0] = objectproperties.frontcolsPar[2*4+0] = 0.1;
    objectproperties.frontcols[2*4+1] = objectproperties.frontcolsPar[2*4+1] = 0.81;
    objectproperties.frontcols[2*4+2] = objectproperties.frontcolsPar[2*4+2] = 0.93;
    objectproperties.frontcols[2*4+3] = objectproperties.frontcolsPar[2*4+3] = 1.0;

    objectproperties.frontcols[3*4+0] = objectproperties.frontcolsPar[3*4+0] = 0.8;
    objectproperties.frontcols[3*4+1] = objectproperties.frontcolsPar[3*4+1] = 0.91;
    objectproperties.frontcols[3*4+2] = objectproperties.frontcolsPar[3*4+2] = 0.9;
    objectproperties.frontcols[3*4+3] = objectproperties.frontcolsPar[3*4+3] = 1.0;

    objectproperties.frontcols[4*4+0] = objectproperties.frontcolsPar[4*4+0] = 0.96;
    objectproperties.frontcols[4*4+1] = objectproperties.frontcolsPar[4*4+1] = 0.71;
    objectproperties.frontcols[4*4+2] = objectproperties.frontcolsPar[4*4+2] = 0.3;
    objectproperties.frontcols[4*4+3] = objectproperties.frontcolsPar[4*4+3] = 1.0;

    objectproperties.frontcols[5*4+0] = objectproperties.frontcolsPar[5*4+0] = 0.1;
    objectproperties.frontcols[5*4+1] = objectproperties.frontcolsPar[5*4+1] = 0.2;
    objectproperties.frontcols[5*4+2] = objectproperties.frontcolsPar[5*4+2] = 0.9;
    objectproperties.frontcols[5*4+3] = objectproperties.frontcolsPar[5*4+3] = 1.0;

    objectproperties.frontcols[6*4+0] = objectproperties.frontcolsPar[6*4+0] = 0.99;
    objectproperties.frontcols[6*4+1] = objectproperties.frontcolsPar[6*4+1] = 0.1;
    objectproperties.frontcols[6*4+2] = objectproperties.frontcolsPar[6*4+2] = 0.843;
    objectproperties.frontcols[6*4+3] = objectproperties.frontcolsPar[6*4+3] = 1.0;

    objectproperties.frontcols[7*4+0] = objectproperties.frontcolsPar[7*4+0] = 0.16;
    objectproperties.frontcols[7*4+1] = objectproperties.frontcolsPar[7*4+1] = 0.91;
    objectproperties.frontcols[7*4+2] = objectproperties.frontcolsPar[7*4+2] = 0.73;
    objectproperties.frontcols[7*4+3] = objectproperties.frontcolsPar[7*4+3] = 1.0;

    objectproperties.frontcols[8*4+0] = objectproperties.frontcolsPar[8*4+0] = 0.8;
    objectproperties.frontcols[8*4+1] = objectproperties.frontcolsPar[8*4+1] = 0.9;
    objectproperties.frontcols[8*4+2] = objectproperties.frontcolsPar[8*4+2] = 0.0;
    objectproperties.frontcols[8*4+3] = objectproperties.frontcolsPar[8*4+3] = 1.0;

    objectproperties.frontcols[9*4+0] = objectproperties.frontcolsPar[9*4+0] = 0.9;
    objectproperties.frontcols[9*4+1] = objectproperties.frontcolsPar[9*4+1] = 0.91;
    objectproperties.frontcols[9*4+2] = objectproperties.frontcolsPar[9*4+2] = 0.3;
    objectproperties.frontcols[9*4+3] = objectproperties.frontcolsPar[9*4+3] = 1.0;

    for(int i=10; i<NbComponent; i++)
    {
        objectproperties.frontcols[i*4+0] = objectproperties.frontcolsPar[i*4+0] = objectproperties.frontcolsPar[(i%10)*4+0];
        objectproperties.frontcols[i*4+1] = objectproperties.frontcolsPar[i*4+1] = objectproperties.frontcolsPar[(i%10)*4+1];
        objectproperties.frontcols[i*4+2] = objectproperties.frontcolsPar[i*4+2] = objectproperties.frontcolsPar[(i%10)*4+2];
        objectproperties.frontcols[i*4+3] = objectproperties.frontcolsPar[i*4+3] = 1;

        objectproperties.backcols[i*4+0] = objectproperties.backcolsPar[i*4+0] = objectproperties.backcolsPar[(i%10)*4+0];
        objectproperties.backcols[i*4+1] = objectproperties.backcolsPar[i*4+1] = objectproperties.backcolsPar[(i%10)*4+1];
        objectproperties.backcols[i*4+2] = objectproperties.backcolsPar[i*4+2] = objectproperties.backcolsPar[(i%10)*4+2];
        objectproperties.backcols[i*4+3] = objectproperties.backcolsPar[i*4+3] = 1;
    }
    objectproperties.border              = 1;
    objectproperties.mesh                = 1;
    objectproperties.activarecnd         = true;
    objectproperties.activateGlCache     = true;
    objectproperties.specReflection[0]   = objectproperties.specReflection[1] = objectproperties.specReflection[2] = 0.2;
    objectproperties.specReflection[3]   = 1.0;
    objectproperties.shininess           = 110;
    objectproperties.fill                = 1;
    objectproperties.line                = 1;
    objectproperties.infos               = 1;
    objectproperties.frame               = -1;
    objectproperties.infosdetails[0]  = objectproperties.infosdetails[1] = objectproperties.infosdetails[2] = 1;
    objectproperties.axe                 = 1;
    objectproperties.box                 = 1;
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

    objectproperties.componentsinfos.NoiseParam.Octaves     = 4;
    objectproperties.componentsinfos.NoiseParam.Lacunarity  = 0.5;
    objectproperties.componentsinfos.NoiseParam.Gain        = 0.5;
    objectproperties.componentsinfos.NoiseParam.NoiseActive = 1;

    objectproperties.componentsinfos.DFTrianglesNotVerifyCND =
        objectproperties.componentsinfos.DFTrianglesVerifyCND =
            objectproperties.componentsinfos.DMTrianglesBorderCND = true;
    objectproperties.componentsinfos.DMTrianglesNotVerifyCND =
        objectproperties.componentsinfos.DMTrianglesVerifyCND = false;
}
