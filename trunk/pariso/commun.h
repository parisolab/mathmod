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
#include <cmath>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>
#include "../fparser/fparser.h"

#define PI ((double)314159265/(double)100000000)

#define MAGIC_SCALE 1.5707963f

static const int NbTextures=50;
static const int NbComponent=21;
static const int NbVariables = 20;
static const int NbConstantes = 30;
static const int NbDefinedFunctions = 50;
static const int NbMaxGrid = 600;  // Should use the defined value in mathmodconfig.js


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
    FunctionParser *VRgbtParser, *GradientParser, *NoiseParser;
    int Nb_vrgbts;
    int NoiseShape;
    int NoiseActive;
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
    int IsoPositions[2*NbComponent + 1];
    int IsoPts[2*NbComponent + 1];
    int Parametricpositions[2*NbComponent + 1];
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
    uint vboId_ArrayNorVer_localPt;
    float         * ArrayNorVerExtra_localPt;
    uint vboId_ArrayNorVerExtra_localPt;
    unsigned int  * PolyIndices_localPt;
    uint vboId_PolyIndices_localPt;
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
    int   slider;
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
    bool   activarecnd;
    bool   activateGlCache;
    int    triangles;
    int    interior;
    int    exterior;
    int    infos;
    int    frame;
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
    unsigned int   axeliste;
    unsigned int   boxliste;
    unsigned int   planliste;
    unsigned int   gridplanliste;
    unsigned int   MeshIsoliste;
    unsigned int   MeshIsoMinimalTopliste;
    unsigned int   MeshParliste;
    unsigned int   IsoColorliste[NbComponent];
    unsigned int   ParColorliste[NbComponent];
    unsigned int   FillIsoliste[NbComponent];
    unsigned int   FillParliste[NbComponent];
    unsigned int   CNDverifyIsoliste[NbComponent];
    unsigned int   CNDverifyParliste[NbComponent];
    unsigned int   CNDnotverifyIsoliste[NbComponent];
    unsigned int   CNDnotverifyParliste[NbComponent];
    float          boxlimits[18];
    int            ColorOrTexture[10];
    float  *morefloatpt[10];
    float  morefloat[10];
    float  specReflection[4];
    int    shininess;
    float  frontcol[4];
    float  backcol[4];
    float  frontcols[NbComponent][4];
    float  backcols[NbComponent][4];
    float red[4];
    float  frontcolsPar[NbComponent][4];
    float  backcolsPar[NbComponent][4];
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

class CellNoise
{
public :
    float rd[3], featurePoint[4];
    const static uint OFFSET_BASIS = 2166136261U;
    const static uint FNV_PRIME = 16777619U;

    float CellNoiseFunc(float, float, float, int, int type=2, int Dist=0);
    float EuclidianDistanceFunc(float ,float , float , float , float , float);
    float ManhattanDistanceFunc(float ,float , float , float , float , float);
    float ChebyshevDistanceFunc(float ,float , float , float , float , float);
    int probLookup(uint );
    void insert(float* , float );
    int lcgRandom(int );
    int hash(int , int , int );
};

class ImprovedNoise
{
public:
    int passes;
    float correction;
    ImprovedNoise(float, float, float);
    float noise(float, float, float);
    float fade(float);
    float lerp(float, float, float);
    float grad(int, float, float, float);
    float FractalNoise3D(float, float, float, int, float , float);
    float Marble(float, float, float,int);
    float lookup(float, float, float);
};

