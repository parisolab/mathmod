/***************************************************************************
 *   Copyright (C) 2015 by Abderrahman Taha                                *
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
#include <cmath>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>
#include "../fparser/fparser.h"


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
    int IsoPositions[2200];
    int IsoPts[2200];
    int Parametricpositions[2200];
    bool Hide[2200];
    int selectedComponent;

    bool ThereisCND;
    bool ThereisRGBA;

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
    int    animxyz;
    int    animx;
    int    animy;
    int    animz;
    float    animxValue;
    float    animyValue;
    float    animzValue;
    float    animxValueStep;
    float    animyValueStep;
    float    animzValueStep;
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

static inline float tinyrnd()
{
    static unsigned trand = 0;
    trand = 1664525u * trand + 1013904223u;
    return (float) trand / 4294967296.0f;
}

class Noise3D {
public:
    int xsize, ysize, zsize;
    std::vector<float> r;
    std::vector<int> p;

    int coord2index(int x, int y, int z) const
    {
        return p[ p[x] + y ] + z;
    }

    Noise3D(int _xsize, int _ysize, int _zsize) :
        xsize(_xsize), ysize(_ysize), zsize(_zsize)
    {
        int i;
        int pxy = std::max(xsize, ysize);
        for (i = 0; i < pxy; i++)
            p.push_back(i);
        for (i = 0; i < pxy; i++) {
            int j = int(tinyrnd()*pxy);
            std::swap(p[i], p[j]);
        }
        for (i = pxy; i < pxy+ysize; i++)
            p.push_back(p[i-pxy]);
        for (i = 0; i < pxy + zsize; i++)
            r.push_back(tinyrnd());
    }

    virtual float lookup(float x, float y, float z) const
    {
        x -= std::floor(x);
        y -= std::floor(y);
        z -= std::floor(z);

        int X = int(x*xsize);
        int Y = int(y*ysize);
        int Z = int(z*zsize);
        int X1 = X + 1;  if (X1 == xsize) X1 = 0;
        int Y1 = Y + 1;  if (Y1 == ysize) Y1 = 0;
        int Z1 = Z + 1;  if (Z1 == zsize) Z1 = 0;

        float xf = x*xsize - X,  xf1 = 1.0f - xf;
        float yf = y*ysize - Y,  yf1 = 1.0f - yf;
        float zf = z*zsize - Z,  zf1 = 1.0f - zf;

        return xf1*(yf1*(zf1*r[coord2index(X , Y , Z )] +
                 zf *r[coord2index(X , Y , Z1)]) +
                yf *(zf1*r[coord2index(X , Y1, Z )] +
                 zf *r[coord2index(X , Y1, Z1)])) +
               xf *(yf1*(zf1*r[coord2index(X1, Y , Z )] +
                 zf *r[coord2index(X1, Y , Z1)]) +
                yf *(zf1*r[coord2index(X1, Y1, Z )] +
                 zf *r[coord2index(X1, Y1, Z1)]));
    }

    virtual ~Noise3D() {}
};


#define MAGIC_SCALE 1.5707963f

class PerlinNoise3D : public Noise3D {
    int passes;
    float correction;
public:
    PerlinNoise3D(int _xsize, int _ysize, int _zsize) :
        Noise3D(_xsize, _ysize, _zsize), correction(0)
    {
        passes = int(std::log((float)xsize)/std::log(MAGIC_SCALE) + 0.5f);
        passes = std::max(passes, int(std::log((float)ysize)/std::log(MAGIC_SCALE) + 0.5f));
        passes = std::max(passes, int(std::log((float)zsize)/std::log(MAGIC_SCALE) + 0.5f));
        float factor = 1.0f;
        for (int pass = 0 ; pass < passes; pass++, factor *= MAGIC_SCALE)
            correction += factor*factor;
        correction = 1.0f / std::sqrt(correction);
    }

    virtual float lookup(float x, float y, float z) const
    {
        float t = 0;
        float factor = 1.0;
        for (int pass = 0 ; pass < passes; pass++, factor *= MAGIC_SCALE) {
            float r = 1.0f / factor;
            t += Noise3D::lookup(x*r,y*r,z*r) * factor;
        }

        return t * correction;
    }
};
