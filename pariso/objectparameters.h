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
#ifndef OBJECTPARAMETERS_H
#define OBJECTPARAMETERS_H
#include <math.h>
#include <string>

struct ErrorMessage
{
    int iErrorIndex;
    std::string strError;
    std::string strOrigine;
};

struct  ComponentInfos
{
    int NbIso;
    int NbParametric;
    int IsoPositions[1100];
    int Parametricpositions[1100];
    bool Hide[1100];
    int selectedComponent;

    bool ThereisCND;

    int NbTrianglesVerifyCND;
    bool DMTrianglesVerifyCND;
    bool DFTrianglesVerifyCND;

    int NbTrianglesNotVerifyCND;
    bool DMTrianglesNotVerifyCND;
    bool DFTrianglesNotVerifyCND;

    int NbTrianglesBorderCND;
    bool DMTrianglesBorderCND;
};

struct  ObjectProperties
{
    float         * ArrayNorVer_localPt;
    float         * ArrayNorVerExtra_localPt;
    unsigned int  * PolyIndices_localPt;
    unsigned int  * PolyIndices_localPtMin;
    float  * BorderPoints;
    int  * TypeSurfaceTriangleListeCND;
    bool *     WichPointVerifyCond;
    unsigned int    NbPolygnNbVertexPtMin ;
    unsigned int    PolyNumber;
    unsigned int    VertxNumber;
    unsigned int    NbBorderpoints;
    unsigned int    PolyNumberTmp1, PolyNumberTmp2,VertxNumberTmp1, VertxNumberTmp2;
    struct ComponentInfos  componentsinfos;
    int * Typetriangles;
    int IndexCurrentFormula;
    int    border;
    int    anim;
    int    morph;
    int    morphstep;
    int    typedrawing;
    int    mesh;
    int    fill;
    int    front;
    int    back;
    int    smoothline;
    int    transparency;
    int    smoothpoly;
    int    box;
    int    isobox;
    bool    activarecnd;
    int    triangles;
    int    interior;
    int    exterior;
    int    infos;
    int    infosdetails[10];
    int    line;
    int    axe;
    int    clip;
    int    norm;
    int    plan;
    int     png_ok;
    int     jpg_ok;
    int     bmp_ok;
    int     quality_image;
    int     colortype;
    int     colortypeParam;

    unsigned int   texture[1100];
    unsigned int   axeliste;
    unsigned int   boxliste;
    unsigned int   planliste;
    unsigned int   gridplanliste;
    float          boxlimits[18];
    int            ColorOrTexture[10];

    float  *morefloatpt[10];
    float  morefloat[10];
    float  frontcol[4];
    float  backcol[4];

    float  frontcols[1100][4];
    float  backcols[1100][4];
    float red[4];

    float  frontcolsPar[1100][4];
    float  backcolsPar[1100][4];

    float  gridcol[4];
    float  groundcol[4];
    float  polyfactor;
    float  polyunits;
    float  RotStrength, oldRotx, oldRoty;
    float  zminim, BoxLimits[3][6];
    int    viewport[4];

    double matrix[16];
    double matrixInverse[16];
    double axe_x, axe_y, axe_z, ScalCoeff, view_rotx, view_roty, view_rotz;
};

class ObjectParameters
{
public:
    ObjectProperties objectproperties;
    int MaximumNumberPoints, MaximumNumberTriangles, MaximumNumberTrianglesMin;
    int maxtr;
    int maxpt;
public:
    ObjectParameters(int mp=20000000, int mt=30000000);
};

#endif // OBJECTPARAMETERS_H
