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
#include "objectparameters.h"

static float StaticColor[20]=
{
//Green(Back face)
    0.0,0.7,0.0,1.0,
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
    MaximumNumberPoints              = maxpoints;
    MaximumNumberTriangles         = maxtriangles;

    objectproperties.ArrayNorVer_localPt               = new float              [6*MaximumNumberPoints     ];
    objectproperties.ArrayNorVerExtra_localPt      = new float              [MaximumNumberPoints     ];
    objectproperties.PolyIndices_localPt                = new unsigned int [4*MaximumNumberTriangles ]; //size is 4*MaximumNumberTriangles because of parametric surface
    objectproperties.PolyIndices_localPtMin          = new unsigned int [3*MaximumNumberTriangles];
    objectproperties.BorderPoints                           = new float              [3*MaximumNumberPoints     ];
    objectproperties.Typetriangles                           = new int                  [MaximumNumberTriangles];
    objectproperties.WichPointVerifyCond             = new bool              [MaximumNumberPoints];

    objectproperties.RotStrength    = 0;
    objectproperties.zminim           = -350.0;
    objectproperties.polyfactor       = 1.0;
    objectproperties.polyunits        = 1.0;
    objectproperties.ScalCoeff      = 1.0;
    objectproperties.view_rotx       = 90.0;
    objectproperties.view_roty       = 90.0;
    objectproperties.view_rotz       = 1.0;
    objectproperties.IndexCurrentFormula = -1;

    objectproperties.red[0]   = 1.0;
    objectproperties.red[1]   = 0.0;
    objectproperties.red[2]   = 0.0;
    objectproperties.red[3]   = 1.0;

    objectproperties.gridcol[0]   = StaticColor[8];
    objectproperties.gridcol[1]   = StaticColor[9];
    objectproperties.gridcol[2]   = StaticColor[10];
    objectproperties.gridcol[3]   = 1.0;

    objectproperties.groundcol[0] = StaticColor[12];
    objectproperties.groundcol[1] = StaticColor[13];
    objectproperties.groundcol[2] = StaticColor[14];
    objectproperties.groundcol[3] = 1.0;

    objectproperties.backcol[0]   = objectproperties.backcols[0][0]   = objectproperties.backcolsPar[0][0]   = StaticColor[0];
    objectproperties.backcol[1]   = objectproperties.backcols[0][1]   = objectproperties.backcolsPar[0][1]   = StaticColor[1];
    objectproperties.backcol[2]   = objectproperties.backcols[0][2]   = objectproperties.backcolsPar[0][2]   = StaticColor[2];
    objectproperties.backcol[3]   = objectproperties.backcols[0][3]   = objectproperties.backcolsPar[0][3]   = 1.0;

    objectproperties.backcols[1][0]   = objectproperties.backcolsPar[1][0]   = 0.3;
    objectproperties.backcols[1][1]   = objectproperties.backcolsPar[1][1]   = 0.9;
    objectproperties.backcols[1][2]   = objectproperties.backcolsPar[1][2]   = 0.23;
    objectproperties.backcols[1][3]   = objectproperties.backcolsPar[1][3]   = 1.0;

    objectproperties.backcols[2][0]   = objectproperties.backcolsPar[2][0]   = 0.73;
    objectproperties.backcols[2][1]   = objectproperties.backcolsPar[2][1]   = 0.19;
    objectproperties.backcols[2][2]   = objectproperties.backcolsPar[2][2]   = 0.3;
    objectproperties.backcols[2][3]   = objectproperties.backcolsPar[2][3]   = 1.0;

    objectproperties.backcols[3][0]   = objectproperties.backcolsPar[3][0]   = 0.413;
    objectproperties.backcols[3][1]   = objectproperties.backcolsPar[3][1]   = 0.2;
    objectproperties.backcols[3][2]   = objectproperties.backcolsPar[3][2]   = 0.943;
    objectproperties.backcols[3][3]   = objectproperties.backcolsPar[3][3]   = 1.0;

    objectproperties.frontcol[0]  = objectproperties.frontcols[0][0] = objectproperties.frontcolsPar[0][0] = StaticColor[4];
    objectproperties.frontcol[1]  = objectproperties.frontcols[0][1] = objectproperties.frontcolsPar[0][1] = StaticColor[5];
    objectproperties.frontcol[2]  = objectproperties.frontcols[0][2] = objectproperties.frontcolsPar[0][2] = StaticColor[6];
    objectproperties.frontcol[3]  = objectproperties.frontcols[0][3] = objectproperties.frontcolsPar[0][3] = 1.0;

    objectproperties.frontcols[1][0] = objectproperties.frontcolsPar[1][0] = 0.6;
    objectproperties.frontcols[1][1] = objectproperties.frontcolsPar[1][1] = 0.1;
    objectproperties.frontcols[1][2] = objectproperties.frontcolsPar[1][2] = 0.7;
    objectproperties.frontcols[1][3] = objectproperties.frontcolsPar[1][3] = 1.0;

    objectproperties.frontcols[2][0] = objectproperties.frontcolsPar[2][0] = 0.16;
    objectproperties.frontcols[2][1] = objectproperties.frontcolsPar[2][1] = 0.11;
    objectproperties.frontcols[2][2] = objectproperties.frontcolsPar[2][2] = 0.43;
    objectproperties.frontcols[2][3] = objectproperties.frontcolsPar[2][3] = 1.0;

    objectproperties.frontcols[3][0] = objectproperties.frontcolsPar[3][0] = 0.16;
    objectproperties.frontcols[3][1] = objectproperties.frontcolsPar[3][1] = 0.911;
    objectproperties.frontcols[3][2] = objectproperties.frontcolsPar[3][2] = 0.143;
    objectproperties.frontcols[3][3] = objectproperties.frontcolsPar[3][3] = 1.0;

    for(int i=4; i<1100; i++)
    {   /*
           objectproperties.frontcols[i][0] = objectproperties.frontcolsPar[i%4][0];
           objectproperties.frontcols[i][1] = objectproperties.frontcolsPar[i%4][1];
           objectproperties.frontcols[i][2] = objectproperties.frontcolsPar[i%4][2];
           objectproperties.frontcols[i][3] = objectproperties.frontcolsPar[i%4][3];

           objectproperties.backcols[i][0] = objectproperties.backcolsPar[i%4][0];
           objectproperties.backcols[i][1] = objectproperties.backcolsPar[i%4][1];
           objectproperties.backcols[i][2] = objectproperties.backcolsPar[i%4][2];
           objectproperties.backcols[i][3] = objectproperties.backcolsPar[i%4][3];
           */
        objectproperties.frontcols[i][0] = objectproperties.frontcolsPar[0][0];
        objectproperties.frontcols[i][1] = objectproperties.frontcolsPar[0][1];
        objectproperties.frontcols[i][2] = objectproperties.frontcolsPar[0][2];
        objectproperties.frontcols[i][3] = objectproperties.frontcolsPar[0][3];

        objectproperties.backcols[i][0] = objectproperties.backcolsPar[0][0];
        objectproperties.backcols[i][1] = objectproperties.backcolsPar[0][1];
        objectproperties.backcols[i][2] = objectproperties.backcolsPar[0][2];
        objectproperties.backcols[i][3] = objectproperties.backcolsPar[0][3];

    }

    objectproperties.border              = 1;
    objectproperties.mesh                = 1;
    objectproperties.activarecnd     = true;
    objectproperties.fill                      = 1;
    objectproperties.line                   = 1;
    objectproperties.infos                 = 1;
    objectproperties.infosdetails[0]  = objectproperties.infosdetails[1] = objectproperties.infosdetails[2] = 1;
    objectproperties.axe                   = 1;
    objectproperties.box                   = 1;
    objectproperties.isobox              = 1;
    objectproperties.triangles          = -1;
    objectproperties.typedrawing    =  1;
    objectproperties.smoothpoly      = 1;
    objectproperties.smoothline       =-1;
    objectproperties.anim                 =-1;
    objectproperties.morph              =-1;
    objectproperties.morphstep       =-1;
    objectproperties.norm                =-1;
    objectproperties.plan                  = 1;
    objectproperties.front                  = 1;
    objectproperties.back                 = 1;
    objectproperties.transparency   =-1;
    objectproperties.png_ok = 1;
    objectproperties.jpg_ok = objectproperties.bmp_ok = -1;
    objectproperties.quality_image = 50;
    objectproperties.colortype = 0;
    objectproperties.colortypeParam = 0;

    objectproperties.componentsinfos.DFTrianglesNotVerifyCND =
        objectproperties.componentsinfos.DFTrianglesVerifyCND =
            objectproperties.componentsinfos.DMTrianglesBorderCND =
                objectproperties.componentsinfos.DMTrianglesNotVerifyCND =
                    objectproperties.componentsinfos.DMTrianglesVerifyCND = true;
}
