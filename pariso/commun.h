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
#include <cmath>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>
#include <qthread.h>
#include <QElapsedTimer>
#include "../fparser/fparser.hh"

#define PI (double(314159265)/double(100000000))
#define MAGIC_SCALE 1.5707963f
extern template class FunctionParserBase<double>; // explicit instantiation declaration

struct  GlobalParam
{
    uint TypeDrawin=10;
    uint TypeDrawinNormStep = 4;
    uint PreviousSizeMinimalTopology =0;
    uint NbPolyMinimalTopology =0;
    uint NbVertexTmp = 0;
};

struct ImplicitStructure
{
    std::string fxyz;
    std::string xmin;
    std::string xmax;
    std::string ymin;
    std::string ymax;
    std::string zmin;
    std::string zmax;
    std::string grid;
    std::string cnd;
};

extern uint OrignbX, OrignbY, OrignbZ;
extern uint Stack_Factor;

struct  Voxel
{
    uint Edge_Points [12]; //reference to the Edge Points
    uint Signature; // From 0 to 255
    uint NbEdgePoint;
};

struct NoiseParemeters
{
    int Octaves;
    float Lacunarity ;
    float Gain;
    int NoiseType; // 0 :Texture ; 1 : Pigments
    FunctionParser *RgbtParser;
    FunctionParser *VRgbtParser, *GradientParser, *NoiseParser;
    uint Nb_vrgbts;
    int NoiseShape;
    int NoiseActive;
};

struct ErrorMessage
{
    int iErrorIndex;
    std::string strError;
};

// Any modification to this enum must be translated to the same enum in fparser.hh
enum EvalErrorType
{
    EVAL_ERROR=0,
    DIVISION_BY_ZERO,
    COTAN_FUNCT_ERROR,
    EXP_FUNCT_ERROR,
    ARC_TRIGONOMETRIC_FUNCT_ERROR,
    IF_FUNCT_ERROR,
    EVAL_NO_ERROR
};

enum ScriptErrorType
{
    SCRIPT_NO_ERROR=0,
    MAXGRID_OUT_OF_RANGE,
    MAXPT_OUT_OF_RANGE,
    MAXTRI_OUT_OF_RANGE,
    FXYZ_OUT_OF_RANGE,
    FX_OUT_OF_RANGE,
    XMAX_NBCOMPONENT_MISMATCH,
    YMAX_NBCOMPONENT_MISMATCH,
    ZMAX_NBCOMPONENT_MISMATCH,
    XMIN_NBCOMPONENT_MISMATCH,
    YMIN_NBCOMPONENT_MISMATCH,
    ZMIN_NBCOMPONENT_MISMATCH,
    FY_FX_MISMATCH,
    FZ_FX_MISMATCH,
    FW_FX_MISMATCH,
    UMAX_NBCOMPONENT_MISMATCH,
    VMAX_NBCOMPONENT_MISMATCH,
    WMAX_NBCOMPONENT_MISMATCH,
    UMIN_NBCOMPONENT_MISMATCH,
    VMIN_NBCOMPONENT_MISMATCH,
    WMIN_NBCOMPONENT_MISMATCH,
    GRID_NBCOMPONENT_MISMATCH,
    COMPONENT_NBCOMPONENT_MISMATCH,
    CND_NBCOMPONENT_MISMATCH,
    NBVARIABLES_OUT_OF_RANGE,
    NBCONSTANTES_OUT_OF_RANGE,
    NBDEFINEDFUNCTIONS_OUT_OF_RANGE,
    NBTEXTURES_OUT_OF_RANGE,
    NBSLIDERS_OUT_OF_RANGE,
    NBSLIDERSVALUES_OUT_OF_RANGE,
    VERTEX_TAB_MEM_OVERFLOW,
    TRIANGLES_TAB_MEM_OVERFLOW,
    MINPOLY_TAB_MEM_OVERFLOW,
    POLY_TAB_MEM_OVERFLOW,
    CND_TAB_MEM_OVERFLOW,
    CND_POL_MEM_OVERFLOW,
    DEFINED_PARAM_GRID_VERTEX_TAB_OVERFLOW,
    DEFINED_PARAM_GRID_TRIANGLE_TAB_OVERFLOW
};
struct  ComponentInfos
{
    uint NbIso=0;
    uint NbParametric=0;
    uint *IsoPositions;
    uint *IsoPts;
    uint *Parametricpositions;
    uint *ParPts;
    int selectedComponent;
    bool ThereisCND;
    bool ThereisRGBA;
    uint NbTrianglesVerifyCND;
    bool DMTrianglesVerifyCND;
    bool DFTrianglesVerifyCND;
    uint NbTrianglesNotVerifyCND;
    bool DMTrianglesNotVerifyCND;
    bool DFTrianglesNotVerifyCND;
    uint NbTrianglesBorderCND;
    bool DMTrianglesBorderCND;
    NoiseParemeters NoiseParam;
};

struct  ObjectProperties
{
    float         * ArrayNorVer_localPt;
    float         * OriginalArrayNorVer_localPt;
    uint vboId_ArrayNorVer_localPt;
    float         * ArrayNorVerExtra_localPt;
    float         * OriginalArrayNorVerExtra_localPt;
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
    int    boundingbox;
    int    isobox;
    bool   activarecnd;
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
    unsigned int   gridplanliste;
    unsigned int   MeshIsoliste;
    unsigned int   MeshIsoMinimalTopliste;
    unsigned int   MeshParliste;
    unsigned int   *IsoColorliste;
    unsigned int   *ParColorliste;
    unsigned int   *FillIsoliste;
    unsigned int   *FillParliste;
    unsigned int   *CNDverifyIsoliste;
    unsigned int   *CNDverifyParliste;
    unsigned int   *CNDnotverifyIsoliste;
    unsigned int   *CNDnotverifyParliste;
    float  specReflection[4];
    int    threads[3];
    int    shininess;
    float  frontcol[4];
    float  backcol[4];
    float  *frontcols;
    float  *backcols;

    float  *frontcolsPar;
    float  *backcolsPar;
    float red[4];
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



class CellNoise
{
public :
    float rd[3], featurePoint[4];
    const static uint OFFSET_BASIS = 2166136261U;
    const static uint FNV_PRIME = 16777619U;

    float CellNoiseFunc(float, float, float, int, int type=2, int Dist=0);
    float EuclidianDistanceFunc(float,float, float, float, float, float);
    float ManhattanDistanceFunc(float,float, float, float, float, float);
    float ChebyshevDistanceFunc(float,float, float, float, float, float);
    int probLookup(uint );
    void insert(float*, float );
    int lcgRandom(int );
    int hash(int, int, int );
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
    float FractalNoise3D(float, float, float, int, float, float);
    float Marble(float, float, float,int);
    float lookup(float, float, float);
};

extern uint NbTextures;
extern uint NbComponent;
extern uint NbVariables;
extern int NbSliders;
extern int NbSliderValues;
extern uint NbConstantes;
extern uint NbDefinedFunctions;
extern uint NbMaxGrid;  // Should use the defined value in mathmodconfig.js
extern uint NbMaxTri;
extern uint NbMaxPts;
extern uint IsoNbCmp;

extern float* NormVertexTab;
extern unsigned int * IndexPolyTab;
extern unsigned int * IndexPolyTabMin;
extern struct  ComponentInfos componentsStr;
extern struct ComponentInfos * components;
