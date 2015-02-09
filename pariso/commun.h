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


struct NoiseParemeters
{
    int Octaves;
    float Lacunarity ;
    float Gain;
    float WindowSize;
    float shiftX;
    float ShiftY;
    float ShiftZ;
    float * IndexPoint;
    int NoiseType; // 0 :Texture ; 1 : Pigments
    FunctionParser *RgbtParser;
    FunctionParser *VRgbtParser, *GradientParser;
    int Nb_vrgbts;
    int NoiseShape; //Nothing = 0, Granit = 1, Wood= 2, Clouds= 3...
};

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
    NoiseParemeters NoiseParam;
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

#define MAGIC_SCALE 1.5707963f

static int permutation[256] = { 151,160,137,91,90,15,
131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
};
 static int p[512];
 class ImprovedNoise {
     int passes;
     float correction;

   public:
    ImprovedNoise(float xsize, float ysize, float zsize)
    {
        passes = int(std::log((float)xsize)/std::log(MAGIC_SCALE) + 0.5f);
        passes = std::max(passes, int(std::log((float)ysize)/std::log(MAGIC_SCALE) + 0.5f));
        passes = std::max(passes, int(std::log((float)zsize)/std::log(MAGIC_SCALE) + 0.5f));
        float factor = 1.0f;
        for (int pass = 0 ; pass < passes; pass++, factor *= MAGIC_SCALE)
            correction += factor*factor;
        correction = 1.0f / std::sqrt(correction);

       for (int i=0; i < 256 ; i++)
           p[256+i] = p[i] = permutation[i];

       for (int i = 0; i < 256; i++)
       {
           int k = tinyrnd()*(256 - i) + i;

           int l = p[i];

           p[i] = p[k];
           p[k] = l;
           p[i + 256] = p[i];
       }
    }

     float noise(float x, float y, float z)
   {
      int X = (int)std::floor(x) & 255,                  // FIND UNIT CUBE THAT
          Y = (int)std::floor(y) & 255,                  // CONTAINS POINT.
          Z = (int)std::floor(z) & 255;
      x -= std::floor(x);                                // FIND RELATIVE X,Y,Z
      y -= std::floor(y);                                // OF POINT IN CUBE.
      z -= std::floor(z);
      float u = fade(x),                                // COMPUTE FADE CURVES
             v = fade(y),                                // FOR EACH OF X,Y,Z.
             w = fade(z);
      int A = p[X  ]+Y, AA = p[A]+Z, AB = p[A+1]+Z,      // HASH COORDINATES OF
          B = p[X+1]+Y, BA = p[B]+Z, BB = p[B+1]+Z;      // THE 8 CUBE CORNERS,

      return lerp(w, lerp(v, lerp(u, grad(p[AA  ], x  , y  , z   ),  // AND ADD
                                     grad(p[BA  ], x-1, y  , z   )), // BLENDED
                             lerp(u, grad(p[AB  ], x  , y-1, z   ),  // RESULTS
                                     grad(p[BB  ], x-1, y-1, z   ))),// FROM  8
                     lerp(v, lerp(u, grad(p[AA+1], x  , y  , z-1 ),  // CORNERS
                                     grad(p[BA+1], x-1, y  , z-1 )), // OF CUBE
                             lerp(u, grad(p[AB+1], x  , y-1, z-1 ),
                                     grad(p[BB+1], x-1, y-1, z-1 ))));
   }

   float fade(float f)
   {
       return f * f * f * (f * (f * 6 - 15) + 10); // t * t * (3.0 - 2.0 * t);
   }


   float lerp(float t, float a, float b)
   {
       return a + t * (b - a);
   }

   float grad(int hash, float x, float y, float z)
   {
      int h = hash & 15;                      // CONVERT LO 4 BITS OF HASH CODE
      float u = h<8 ? x : y,                 // INTO 12 GRADIENT DIRECTIONS.
             v = h<4 ? y : h==12||h==14 ? x : z;
      return ((h&1) == 0 ? u : -u) + ((h&2) == 0 ? v : -v);
   }

   float FractalNoise3D(float x, float y, float z, int octNum, float lacunarity , float gain)
   {
       float freq = 1.0, amp = 1.0, sum = 0;

       for(int i = 0; i < octNum; i++)
       {
           sum +=  noise(x*freq, y*freq, z*freq) * amp;
           freq *= lacunarity;
           amp *= gain;
       }
       return sum;
   }

   float Marble(float x, float y, float z,int octNum)
   {
       float t = 0;
       float factor = 1.0;
       for (int pass = 0 ; pass < octNum; pass++, factor *= MAGIC_SCALE) {
           float r = 1.0f / factor;
           t += noise(x*r,y*r,z*r) * factor;
       }

       return t * correction;
   }

   float lookup(float x, float y, float z)
   {
       float t = 0;
       float factor = 1.0;
       for (int pass = 0 ; pass < passes; pass++, factor *= MAGIC_SCALE)
       {
           float r = 1.0 / factor;
           t += noise(x*r, y*r,z*r) * factor;
       }

       return t * correction;
   }
};

