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

#include "commun.h"

static int p[512];
static int permutation[256] =
{
    151, 160, 137, 91,  90,  15,  131, 13,  201, 95,  96,  53,  194, 233, 7,
    225, 140, 36,  103, 30,  69,  142, 8,   99,  37,  240, 21,  10,  23,  190,
    6,   148, 247, 120, 234, 75,  0,   26,  197, 62,  94,  252, 219, 203, 117,
    35,  11,  32,  57,  177, 33,  88,  237, 149, 56,  87,  174, 20,  125, 136,
    171, 168, 68,  175, 74,  165, 71,  134, 139, 48,  27,  166, 77,  146, 158,
    231, 83,  111, 229, 122, 60,  211, 133, 230, 220, 105, 92,  41,  55,  46,
    245, 40,  244, 102, 143, 54,  65,  25,  63,  161, 1,   216, 80,  73,  209,
    76,  132, 187, 208, 89,  18,  169, 200, 196, 135, 130, 116, 188, 159, 86,
    164, 100, 109, 198, 173, 186, 3,   64,  52,  217, 226, 250, 124, 123, 5,
    202, 38,  147, 118, 126, 255, 82,  85,  212, 207, 206, 59,  227, 47,  16,
    58,  17,  182, 189, 28,  42,  223, 183, 170, 213, 119, 248, 152, 2,   44,
    154, 163, 70,  221, 153, 101, 155, 167, 43,  172, 9,   129, 22,  39,  253,
    19,  98,  108, 110, 79,  113, 224, 232, 178, 185, 112, 104, 218, 246, 97,
    228, 251, 34,  242, 193, 238, 210, 144, 12,  191, 179, 162, 241, 81,  51,
    145, 235, 249, 14,  239, 107, 49,  192, 214, 31,  181, 199, 106, 157, 184,
    84,  204, 176, 115, 121, 50,  45,  127, 4,   150, 254, 138, 236, 205, 93,
    222, 114, 67,  29,  24,  72,  243, 141, 128, 195, 78,  66,  215, 61,  156,
    180
};


float rd[3], featurePoint[4];
const static uint OFFSET_BASIS = 2166136261U;
const static uint FNV_PRIME = 16777619U;

int passes;
float correction;




double Mandelbulb(const double* pp) {
    double x = pp[0];
    double y = pp[1];
    double z = pp[2];
    double R2, theta, phi, R6, R8;
    double dr = 1.0;
    for(int i = 0; i < pp[3]; i++) {
        R2 = x * x + y * y + z * z;
        if(R2 > 4) {
            return 0.25 * sqrt(R2) * log(R2) / dr;
        }
        R6 = R2 * R2 * R2;
        dr = 8.0 * R6 * sqrt(R2) * dr + 1.0;
        theta = 8.0 * atan2(sqrt(x * x + y * y), z);
        phi = 8.0 * atan2(y, x);
        R8 = R6 * R2;
        x = R8 * cos(phi) * sin(theta) + pp[0];
        y = R8 * sin(phi) * sin(theta) + pp[1];
        z = R8 * cos(theta) + pp[2];
    }
    return 0.0;
}

double maxim(double p1, double p2)
{
    return p1 > p2 ? p1 : p2;
}
double P_skeletal_int(const double* pp)
{
    double  cx, cy,cz;
    cx=cos(pp[0]);
    cy=cos(pp[1]);
    cz=cos(pp[2]);
    return(cx+cy+cz+0.51*(cx*cy+cy*cz+cz*cx)+1.2);
}
double F_hex_y(const double* pp)
{
    double x1,y1,x2,y2, th;
    double p[10];
    for(int i=0; i<4; i++)
        p[i] = pp[i];
    x1=fabs(fmod(fabs(p[0]), sqrt(3.0))-sqrt(3.0)/2);
    y1=fabs(fmod(fabs(p[1]), 3)-1.5);
    x2=sqrt(3.0)/2-x1;
    y2=1.5-y1;
    if ((x1*x1+y1*y1)>(x2*x2+y2*y2))
    {
        x1=x2;
        y1=y2;
    }
    if ((x1==0.0)&&(y1==0.0))
        p[0]=0.000000001;
    th=atan2(y1,x1);
    if (th<PI/6)
        return(y1);
    else
    {
        y1=-sin(PI/3)*x1+cos(PI/3)*y1;
        return(fabs(y1));
    }
}
double Fmesh(const double* pp)
{
    double th, ph, r, r2, temp;
    double p[10];

    for(int i=0; i<10; i++)
        p[i] = pp[i];
    th = PI / p[3];
    ph = PI/ p[4];
    r = fmod(p[0], p[3] * 2);
    if (r < 0)
        r += p[3] * 2;
    r = fabs(r - p[3]) * p[5];
    r2 = (p[1] - cos(p[2] * ph) * p[6]) * p[7];
    temp = -sqrt(r2 * r2 + r * r);
    r = fmod(p[0] - p[3], p[3] * 2);
    if (r < 0)
        r += p[3] * 2;
    r = fabs(r - p[3]) * p[5];
    r2 = (p[1] + cos(p[2] * ph) * p[6]) * p[7];
    temp =   maxim(-sqrt(r2 * r2 + r * r), temp);
    r = fmod(p[2], p[4] * 2);
    if (r < 0)
        r += p[4] * 2;
    r = fabs(r - p[4]) * p[5];
    r2 = (p[1] + cos(p[0] * th) * p[6]) * p[7];
    temp = maxim(-sqrt(r2 * r2 + r * r), temp);
    r = fmod(p[2] - p[4], p[4] * 2);
    if (r < 0)
        r += p[4] * 2;
    r = fabs(r - p[4]) * p[5];
    r2 = (p[1] - cos(p[0] * th) * p[6]) * p[7];
    return (-maxim(-sqrt(r2 * r2 + r * r), temp));
}
double  Fhelix1(const double* pp)
{
    double r, r2, r3, temp, th, ph, x2;
    double p[10];
    for(int i=0; i<10; i++)
        p[i] = pp[i];
    r = sqrt(p[0] * p[0] + p[2] * p[2]);
    if ((p[0] == 0.0) && (p[2] == 0.0))
        p[0] = 0.0000000001;
    th = atan2(p[2], p[0]);
    th = fmod(th * p[3] + p[1] * p[4] * p[3], 2*PI);
    if (th < 0)
        th += 2*PI;
    p[2] = (th - PI) / p[7] / (p[4] * p[3]);
    p[0] = r - p[6];
    if (p[8] == 1.0)
        r2 = sqrt(p[0] * p[0] + p[2] * p[2]);
    else
    {
        if (p[9] != 0.0)
        {
            th = cos(p[9] * PI/180);
            ph = sin(p[9] * PI/180);
            x2 = p[0] * th - p[2] * ph;
            p[2] = p[0] * ph + p[2] * th;
            p[0] = x2;
        }
        if (p[8] != 0.0)
        {
            temp = 2. / p[8];
            r2 = pow((pow(fabs(p[0]), temp) + pow(fabs(p[2]), temp)), p[8] *.5);
        }
        else
            fabs(p[0]) > fabs(p[2]) ? r2 = fabs(p[0]) : r2 = fabs(p[2]);
    }
    (p[6] + r) < r2 ? r3 = (p[6] + r) : r3 = r2;
    return (-p[5] + r3);
}
double Fhelix2(const double* pp)
{
    double th, ph, x2, z2, r2, temp;
    double p[10];
    for(int i=0; i<10; i++)
        p[i] = pp[i];
    /* helical shape  for (minor radius>major radius  *
     *    cross section   p[5] same as NFUNCTION = 6      */
    th = p[1] * p[4];
    ph = cos(th);
    th = sin(th);
    x2 = p[0] - p[6] * ph;
    z2 = p[2] - p[6] * th;
    p[0] = x2 * ph + z2 * th;
    p[2] = (-x2 * th + z2 * ph);
    if (p[8] == 1.0)
        return (sqrt(p[0] * p[0] + p[2] * p[2]) - p[5]);
    if (p[8] != 0.0)
    {
        temp = 2. / p[8];
        r2 = pow((pow(fabs(p[0]), temp) + pow(fabs(p[2]), temp)), p[8] *0.5);
    }
    else
        r2 = maxim(fabs(p[0]), fabs(p[2]));
    return (r2 - p[5]);
}

/*
double TurbulenceWorley2(const double* p)
{
    return double(CellNoiseFunc(
        float(p[0]),
        float(p[1]),
        float(p[2]),
        int(p[3]),
        int(p[4]),
        int(p[5])));
}
double TurbulencePerlin2(const double* p)
{
    return double(FractalNoise3D(
        float(p[0]),
        float(p[1]),
        float(p[2]),
        int(p[3]),
        float(p[4]),
        float(p[5])));
}
*/
double TurbulenceWorley(const double *p)
{
    return double (
        CellNoiseFunc(float(p[0]),
                      float(p[1]),
                      float(p[2]),
                      int(p[3]),
                      int(p[4]),
                      int(p[5])));
}
double TurbulencePerlin(const double *p)
{
    return double (
        FractalNoise3D(
            float (p[0]),
            float (p[1]),
            float (p[2]),
            int (p[3]),
            float (p[4]),
            float (p[5])));
}
double MarblePerlin(const double *p)
{
    return double (
        Marble(
            float (p[0]),
            float (p[1]),
            float (p[2]),
            int (p[3])));
}

float CellNoiseFunc(float x, float y, float z, int seed, int type, int CombineDist)
{
    uint lastRandom, numberFeaturePoints;
    float randomDiff[4];
    int cubeX, cubeY, cubeZ;
    float distanceArray[9];
    float color = 0;
    for (int i = 0; i < 9; i++)
        distanceArray[i] = 6666;
    int evalCubeX = int(floor(x));
    int evalCubeY = int(floor(y));
    int evalCubeZ = int(floor(z));
    for (int i = -1; i < 2; ++i)
        for (int j = -1; j < 2; ++j)
            for (int k = -1; k < 2; ++k)
            {
                cubeX = evalCubeX + i;
                cubeY = evalCubeY + j;
                cubeZ = evalCubeZ + k;
                lastRandom = uint(lcgRandom(hash((cubeX + seed), (cubeY), (cubeZ))));
                numberFeaturePoints = uint(probLookup(lastRandom));
                for (uint l = 0; l < numberFeaturePoints; ++l)
                {
                    lastRandom = uint(lcgRandom(int(lastRandom)));
                    randomDiff[0] = float(lastRandom) / 0x100000000;

                    lastRandom = uint(lcgRandom(int(lastRandom)));
                    randomDiff[1] = float(lastRandom) / 0x100000000;

                    lastRandom = uint(lcgRandom(int(lastRandom)));
                    randomDiff[2] = float(lastRandom) / 0x100000000;

                    featurePoint[0] = randomDiff[0] + float(cubeX);
                    featurePoint[1] = randomDiff[1] + float(cubeY);
                    featurePoint[2] = randomDiff[2] + float(cubeZ);
                    if (type == 1)
                        insert(distanceArray,
                               ManhattanDistanceFunc(x, y, z, featurePoint[0],
                                                     featurePoint[1], featurePoint[2]));
                    else if (type == 2 || type == 4)
                        insert(distanceArray,
                               EuclidianDistanceFunc(x, y, z, featurePoint[0],
                                                     featurePoint[1], featurePoint[2]));
                    else if (type == 3 || type == 5)
                        insert(distanceArray,
                               ChebyshevDistanceFunc(x, y, z, featurePoint[0],
                                                     featurePoint[1], featurePoint[2]));
                }
            }
    if (CombineDist == 1)
        color = distanceArray[1] - distanceArray[0];
    else if (CombineDist == 2)
        color = distanceArray[2] - distanceArray[0];
    else
        color = distanceArray[0];
    if (color < 0)
        color = 0;
    if (color > 1)
        color = 1;
    return color;
}
float EuclidianDistanceFunc(float x1, float y1, float z1, float x2, float y2, float z2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
}
float ManhattanDistanceFunc(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float tmp = std::abs(x1 - x2) + std::abs(y1 - y2) + std::abs(z1 - z2);
    return tmp;
}
float ChebyshevDistanceFunc(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float diff[3];
    diff[0] = x1 - x2;
    diff[1] = y1 - y2;
    diff[2] = z1 - z2;
    return std::max(std::max(std::abs(diff[0]), std::abs(diff[1])),
                    std::abs(diff[2]));
}
int probLookup(uint value)
{
    if (value < 393325350U)
        return 1;
    if (value < 1022645910U)
        return 2;
    if (value < 1861739990U)
        return 3;
    if (value < 2700834071U)
        return 4;
    if (value < 3372109335U)
        return 5;
    if (value < 3819626178U)
        return 6;
    if (value < 4075350088U)
        return 7;
    if (value < 4203212043U)
        return 8;
    return 9;
}
void insert(float *arr, float value)
{
    float temp;
    for (int i = 8; i >= 0; i--)
    {
        if (value > arr[i])
            break;
        temp = arr[i];
        arr[i] = value;
        if (i == 0)
        {
            rd[0] = featurePoint[0];
            rd[1] = featurePoint[1];
            rd[2] = featurePoint[2];
        }
        if (i < 8)
            arr[i + 1] = temp;
    }
}
int lcgRandom(int lastValue)
{
    return int(((1103515245u * uint(lastValue) + 12345u) % 0x100000000u));
}
int hash(int i, int j, int k)
{
    return ((((((OFFSET_BASIS^i)*FNV_PRIME)^j) * FNV_PRIME)^k)*FNV_PRIME);
}
void ImprovedNoise(float xsize, float ysize, float zsize)
{
    correction = 1.0f / 100000000.0f;
    passes = int(std::log(xsize) / std::log(MAGIC_SCALE) + 0.5f);
    passes =
        std::max(passes, int(std::log(ysize) / std::log(MAGIC_SCALE) + 0.5f));
    passes =
        std::max(passes, int(std::log(zsize) / std::log(MAGIC_SCALE) + 0.5f));
    float factor = 1.0f;
    for (int pass = 0; pass < passes; pass++, factor *= MAGIC_SCALE)
        correction += factor * factor;
    correction = 1.0f / std::sqrt(correction);

    for (int i = 0; i < 256; i++)
        p[256 + i] = p[i] = permutation[i];

    for (int i = 0; i < 256; i++)
    {
        int k = int((tinyrnd() * (256 - i) + i));
        int l = p[i];
        p[i] = p[k];
        p[k] = l;
        p[i + 256] = p[i];
    }
}
float noise(float x, float y, float z)
{
    int X = int(std::floor(x)) & 255, Y = int(std::floor(y)) & 255,
        Z = int(std::floor(z)) & 255;
    x -= std::floor(x);
    y -= std::floor(y);
    z -= std::floor(z);
    float u = fade(x), v = fade(y), w = fade(z);
    int A = p[X] + Y, AA = p[A] + Z, AB = p[A + 1] + Z, B = p[X + 1] + Y,
        BA = p[B] + Z, BB = p[B + 1] + Z;
    return lerp(
        w,
        lerp(v, lerp(u, grad(p[AA], x, y, z), grad(p[BA], x - 1, y, z)),
             lerp(u, grad(p[AB], x, y - 1, z), grad(p[BB], x - 1, y - 1, z))),
        lerp(v,
             lerp(u, grad(p[AA + 1], x, y, z - 1),
                  grad(p[BA + 1], x - 1, y, z - 1)),
             lerp(u, grad(p[AB + 1], x, y - 1, z - 1),
                  grad(p[BB + 1], x - 1, y - 1, z - 1))));
}
float fade(float f)
{
    return f*f*f*(f*(f*6-15)+10); // t * t * (3.0 - 2.0 * t);
}
float lerp(float t, float a, float b)
{
    return a + t*(b - a);
}
float grad(int hash, float x, float y, float z)
{
    int h = hash & 15;       // CONVERT LO 4 BITS OF HASH CODE
    float u = h < 8 ? x : y, // INTO 12 GRADIENT DIRECTIONS.
        v = h < 4 ? y : h == 12 || h == 14 ? x : z;
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}
float FractalNoise3D(float x, float y, float z, int octNum,
                                    float lacunarity, float gain)
{
    float freq = 1.0, amp = 1.0, sum = 0;

    for (int i = 0; i < octNum; i++)
    {
        sum += noise(x * freq, y * freq, z * freq) * amp;
        freq *= lacunarity;
        amp *= gain;
    }
    return sum;
}
float Marble(float x, float y, float z, int octNum)
{
    float t = 0;
    float factor = 1.0;
    for (int pass = 0; pass < octNum; pass++, factor *= MAGIC_SCALE)
    {
        float r = 1.0f / factor;
        t += noise(x * r, y * r, z * r) * factor;
    }
    return t * correction;
}
float lookup(float x, float y, float z)
{
    float t = 0;
    float factor = 1.0;
    for (int pass = 0; pass < passes; pass++, factor *= MAGIC_SCALE)
    {
        float r = 1 / factor;
        t += noise(x*r, y*r, z*r)*factor;
    }
    return t * correction;
}
double julia(double zx, double zy, double cx, double cy, int MAXCOUNT)
{
    double tempx;
    int count;
    count = 0;
    while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT))
    {
        tempx = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = tempx;
        count = count + 1;
    }
    return (double(count));
}

double mandelbrot(double cx, double cy, int MAXCOUNT)
{
    double zx, zy, tempx, Zx, Zy;
    int count;
    zx = 0;
    zy = 0;
    count = 0;
    while (((Zx=(zx * zx)) + (Zy=(zy * zy)) < 4) && (count < MAXCOUNT))
    {
        tempx = Zx -  Zy + cx;
        zy = 2 * zx * zy + cy;
        zx = tempx;
        count = count + 1;
    }
    return (double(count));
}

//associated legendre
double legendre_a (int n, int m, double x)
{
    std::vector<double> v(n+1, 0.0);
    if(m <= n ) {
    v[m] = 1.0;
        double fact = 1.0;
        for(int k = 0; k < m; k++) {
            v[m] *= -fact * std::sqrt(1.0 - x * x);
            fact += 2.0;
        }
    }
    if(m + 1 <= n ) {
        v[m+1] = x * ( double ) ( 2 * m + 1 ) * v[m];
    }
    for(int j = m + 2; j <= n; j++ ) {
        v[j] = ((double)(2 * j - 1 ) * x * v[(j-1)]
                + (double)(- j - m + 1 ) * v[(j-2)])
                / (double)(j - m);
    }
    return v[n];
}

//associated laguerre
double laguerre_a(int n, int m, double x) {
    std::vector<double> v(n+1, 0.0);
    if (n < 0) {
        return -1;
    }
    v[0] = 1.0;
    for (int i = 1; i <= n; i++) {
        v[i] = 0.0;
    }
    if (n == 0) {
        return v[0];
    }
    v[1] = (double)(m + 1) - x;
    for (int i = 2; i <= n; i++) {
        v[i] = (((double)(m + 2 * i - 1) - x) * v[i-1]
               + ( double ) (-m - i + 1 ) * v[i-2])
               / ( double ) (i);
    }
    return v[n];
}

double Julia(const double* pp)
{
    return(julia (pp[0], pp[1], pp[2], pp[3], int (pp[4])));
}

double Mandelbrot(const double* pp)
{
    return(mandelbrot (pp[0], pp[1], int (pp[2])));
}

double Legendre_a(const double* pp)
{
    return(legendre_a (int (pp[0]), int (pp[1]), pp[2]));
}

double Laguerre_a(const double* pp)
{
    return(laguerre_a (int (pp[0]), int (pp[1]), pp[2]));
}

float tinyrnd()
{
    static unsigned trand = 0;
    trand = 1664525u * trand + 1013904223u;
    return (float(trand) / 4294967296.0f);
}
