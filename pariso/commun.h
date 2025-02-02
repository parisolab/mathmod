/***************************************************************************
 *   Copyright (C) 2025 by Abderrahman Taha                                *
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
#ifndef COMMUN_H
#define COMMUN_H

#include "../fparser/fparser.hh"
#include <qthread.h>
#include <complex.h>
#include <tgmath.h>

#define PI (double(314159265) / double(100000000))
#define MAGIC_SCALE 1.5707963f


double CurrentComponentId(const double*);
double Mandelbrot(const double*);
double Julia(const double*);
double Legendre_a(const double*);
double Laguerre_a(const double*);
void ImprovedNoise(float xsize=4.0, float ysize=4.0, float zsize=4.0);
float noise(float, float, float);
float fade(float);
float lerp(float, float, float);
float grad(int, float, float, float);
float FractalNoise3D(float, float, float, int, float, float);
float Marble(float, float, float, int);
float lookup(float, float, float);
float CellNoiseFunc(float, float, float, int, int type = 2, int Dist = 0);
float EuclidianDistanceFunc(float, float, float, float, float, float);
float ManhattanDistanceFunc(float, float, float, float, float, float);
float ChebyshevDistanceFunc(float, float, float, float, float, float);
int probLookup(uint);
void insert(float *, float);
int lcgRandom(int);
int hash(int, int, int);
float tinyrnd();
double TurbulenceWorley(const double *);
double TurbulencePerlin(const double *);
double MarblePerlin(const double *);
double  Fhelix1(const double*);
double Fhelix2(const double*);
double Fmesh(const double*);
double F_hex_y(const double*);
double P_skeletal_int(const double*);
double maxim(double, double);
double maxim(double, double);
double Mandelbulb(const double*);

struct InternalFuncDefinition
{
    std::string name;
    FunctionParser::FunctionPtr ptr;
    uint param;
};

const std::vector<InternalFuncDefinition> InternalFunctions=
    {
        { "NoiseW", TurbulenceWorley, 6},
        { "fhelix1", Fhelix1, 10},
        { "fhelix2",Fhelix2, 10},
        { "f_hex_y",F_hex_y, 4},
        { "p_skeletal_int",P_skeletal_int, 3},
        { "mandelbulb",Mandelbulb, 4},
        { "fmesh",Fmesh, 8},
        { "NoiseP",TurbulencePerlin, 6},
        { "MarbleP",MarblePerlin, 4},
        { "LegendreA",Legendre_a, 3},
        { "LaguerreA",Laguerre_a, 3},
        { "MandelFractal",Mandelbrot, 3},
        { "JuliaFractal",Julia, 5},
        { "CmpId",CurrentComponentId, 1}
};

struct GlobalParam
{
    uint TypeDrawin = 10;
    uint TypeDrawinNormStep = 4;
    uint PreviousSizeMinimalTopology = 0;
    uint NbPolyMinimalTopology = 0;
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

struct Voxel
{
    uint Edge_Points[12]; // reference to the Edge Points
    uint Signature;       // From 0 to 255
    uint NbEdgePoint;
};

struct NoiseParemeters
{
    int Octaves=4;
    float Lacunarity=0.5f;
    float Gain=0.5f;
    int NoiseType=1; // 0 :Texture ; 1 : Pigments
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

// Any modification to this enum must be translated to the same enum in
// fparser.hh
enum EvalErrorType
{
    EVAL_ERROR = 0,
    DIVISION_BY_ZERO,
    COTAN_FUNCT_ERROR,
    EXP_FUNCT_ERROR,
    ARC_TRIGONOMETRIC_FUNCT_ERROR,
    IF_FUNCT_ERROR,
    EVAL_NO_ERROR,
    VAR_OVERFLOW
};

enum ScriptErrorType
{
    SCRIPT_NO_ERROR = 0,
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
    NBSLIDERS_OUT_OF_RANGE,
    NBSLIDERSVALUES_OUT_OF_RANGE,
    VERTEX_TAB_MEM_OVERFLOW,
    TRIANGLES_TAB_MEM_OVERFLOW,
    MINPOLY_TAB_MEM_OVERFLOW,
    POLY_TAB_MEM_OVERFLOW,
    CND_TAB_MEM_OVERFLOW,
    CND_POL_MEM_OVERFLOW,
    DEFINED_PARAM_GRID_VERTEX_TAB_OVERFLOW,
    DEFINED_PARAM_GRID_TRIANGLE_TAB_OVERFLOW,
    GRID_SUPERIOR_TO_GRIDMAX,
    VECT_DIMENSION_ERROR,
    MEM_OVERFLOW,
    EMPTY_MANDATORY_FIELD
};
struct ComponentInfos
{
    std::vector<uint> ParisoTriangle;
    std::vector<uint> ParisoVertex;
    std::vector<uint> NbComponentsType;
    std::vector<bool> ThereisCND;
    std::vector<bool> ThereisRGBA;
    std::vector<bool> ParisoCondition;
    std::vector<bool> ShowParIsoCmp;
    uint ParisoNbComponents = 1;
    uint ParisoCurrentComponentIndex = 0;
    uint NbParametricMeshLines=0;
    uint MinParametricMeshLines=0;
    std::vector<uint> ParametricGrid;
    std::vector<uint> NbTrianglesVerifyCND;
    std::vector<uint> NbTrianglesNoCND;
    std::vector<uint> NbTrianglesNotVerifyCND;
    std::vector<uint> NbTrianglesBorderCND;
    NoiseParemeters NoiseParam[2];
    bool Interleave = false;
    bool pariso = false;
    bool updateviewer = false;
    std::vector<bool> hsv;
};

struct ObjectProperties
{
    float *ArrayNorVer_localPt;
    uint *PolyIndices_localPt;
    uint *PolyIndices_localPtMin;
    int *TypeSurfaceTriangleListeCND;
    uint NbPolygnNbVertexPtMin = 0;
    uint NbPolygnNbVertexPtMinSize = 0;
    uint PolyNumber = 0;
    uint VertxNumber = 0;
    uint NbBorderpoints;
    struct ComponentInfos componentsinfos;
    int IndexCurrentFormula = -1;
    bool ShininessValUpdated=true;
    bool AmbientValUpdated=true;
    bool DiffuseValUpdated=true;
    bool FrontSurfValUpdated=false;
    int border = 1;
    int anim = -1;
    int animxyz = 1;
    int animx = -1;
    int animy = -1;
    int animz = -1;
    float animxValue = 0.0;
    float animyValue = 0.0;
    float animzValue = 0.0;
    float animxValueStep = 0.0;
    float animyValueStep = 0.0;
    float animzValueStep = 0.0;
    int glFrontFacingSupport = 1;
    int slider = -1;
    int morph = -1;
    int morphstep = -1;
    int typedrawing = 1;
    int mesh = 1;
    int fill = 1;
    int transparency = -1;
    int boundingbox = -1;
    bool activarecnd = true;
    bool updategl = true;
    int triangles = -1;
    int infos = -1;
    int frame = -1;
    int infosdetails[3]={1, 1, 1};
    int line = 1;
    int norm = -1;
    int plan = 1;
    int axe = 1;
    int png_ok =  1;
    int jpg_ok = -1;
    int bmp_ok = -1;
    int quality_image = 50;
    int colortype = 0;
    int colortypeParam = 0;
    float specReflection[4]={0.2f, 0.2f, 0.2f, 1.0f};
    int threads[3];
    int shininess = 110;
    float frontcol[4]={0.9f, 0.5f, 0.1f, 1.0f};
    float backcol[4] ={0.2f, 0.8f, 0.1f, 1.0f};
    float frontcols[40]={0.4f, 0.6f, 0.1f, 1.0f, 0.3f, 0.8f, 0.5f, 1.0f, 0.2f, 0.5f, 0.6f, 1.0f, 0.1f, 0.3f, 0.9f, 1.0f, 0.96f, 0.71f, 0.3f, 1.0f,
                          0.4f, 0.4f, 0.9f, 1.0f, 0.99f, 0.1f, 0.843f, 1.0f, 0.16f, 0.91f, 0.73f, 1.0f, 0.8f, 0.9f, 0.0f, 1.0f, 0.9f, 0.91f, 0.3f, 1.0f};
    float backcols[40]={0.72f, 0.5f, 0.1f, 1.0f, 0.6f, 0.6f, 0.9f, 1.0f, 0.8f, 0.6f, 0.3f, 1.0f, 0.9f, 0.8f, 0.6f, 1.0f, 0.93f, 0.2f, 0.1f, 1.0f,
                        0.3f, 0.72f, 0.63f, 1.0f, 0.1f, 0.5f, 0.73f, 1.0f, 0.9f, 0.5f, 0.3f, 1.0f, 0.8f, 0.8f, 0.6f, 1.0f, 0.7f, 0.9f, 0.93f, 1.0f};
    float gridcol[4]  ={0.25f, 0.2f, 0.0f, 0.08f};
    float groundcol[4]={0.0f, 0.0f, 0.0f, 1.0f};
    float polyfactor= 1.0;
    float polyunits= 1.0;
    float RotStrength=0;
    float oldRotx, oldRoty;
    float zminim= -350.0f;
    float BoxLimits[3][6];
    int viewport[4];
    double matrix[16];
    double matrixInverse[16];
    double ScalCoeff = 1.0;
    double axe_x, axe_y, axe_z;
    double view_rotx = 90.0, view_roty = 90.0, view_rotz = 1.0;
    bool cndoptions[5] = {true, true, true, false, false};
    uint vboId_ArrayNorVer_localPt;
    uint vboId_PolyIndices_localPt;
};

static struct ComponentInfos *components = new (struct ComponentInfos);
#endif // COMMUN_H
