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

#include "commun.h"



static int p[512];
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


float CellNoise::CellNoiseFunc(float x, float y, float z, int seed, int type, int CombineDist)
{
    uint lastRandom, numberFeaturePoints;
    float randomDiff[4];
    int cubeX, cubeY, cubeZ;
    float distanceArray[9];
    float color = 0;

    for (int i = 0; i < 9; i++)
        distanceArray[i] = 6666;

    int evalCubeX = (int)floor(x);
    int evalCubeY = (int)floor(y);
    int evalCubeZ = (int)floor(z);

    for (int i = -1; i < 2; ++i)
        for (int j = -1; j < 2; ++j)
            for (int k = -1; k < 2; ++k)
            {
                cubeX = evalCubeX + i;
                cubeY = evalCubeY + j;
                cubeZ = evalCubeZ + k;
                lastRandom = lcgRandom(hash((uint)(cubeX + seed), (uint)(cubeY), (uint)(cubeZ)));
                numberFeaturePoints = probLookup(lastRandom);
                for (uint l = 0; l < numberFeaturePoints; ++l)
                {
                    lastRandom = lcgRandom(lastRandom);
                    randomDiff[0] = (float)lastRandom / 0x100000000;

                    lastRandom = lcgRandom(lastRandom);
                    randomDiff[1] = (float)lastRandom / 0x100000000;

                    lastRandom = lcgRandom(lastRandom);
                    randomDiff[2] = (float)lastRandom / 0x100000000;

                    featurePoint[0] = randomDiff[0] + (float)cubeX;
                    featurePoint[1] = randomDiff[1] + (float)cubeY;
                    featurePoint[2] = randomDiff[2] + (float)cubeZ;
                    if(type == 1)
                        insert(distanceArray, ManhattanDistanceFunc(x, y, z, featurePoint[0], featurePoint[1], featurePoint[2]));
                    else if(type == 2 || type == 4)
                        insert(distanceArray, EuclidianDistanceFunc(x, y, z, featurePoint[0], featurePoint[1], featurePoint[2]));
                    else if(type == 3 || type == 5)
                        insert(distanceArray, ChebyshevDistanceFunc(x, y, z, featurePoint[0], featurePoint[1], featurePoint[2]));
                }
            }
    if(CombineDist ==1)
        color = distanceArray[1] - distanceArray[0];
    else if(CombineDist ==2)
        color = distanceArray[2] - distanceArray[0];
    else
        color = distanceArray[0];
    if(color < 0) color = 0;
    if(color > 1) color = 1;
    return color;
}

float CellNoise::EuclidianDistanceFunc(float x1,float y1, float z1, float x2, float y2, float z2)
{
    return (x1 - x2) * (x1 - x2) +
              (y1 - y2) * (y1 - y2) +
              (z1 - z2) * (z1 - z2);
}

float CellNoise::ManhattanDistanceFunc(float x1,float y1, float z1, float x2, float y2, float z2)
{
    float tmp = std::abs(x1 - x2) + std::abs(y1 - y2) +std:: abs(z1 - z2);
    return tmp;
}

float CellNoise::ChebyshevDistanceFunc(float x1,float y1, float z1, float x2, float y2, float z2)
{
    float diff[3];
    diff[0] = x1 - x2;
    diff[1] = y1 - y2;
    diff[2] = z1 - z2;
    return std::max(std::max(std::abs(diff[0]), std::abs(diff[1])), std::abs(diff[2]));
}

int CellNoise::probLookup(uint value)
{
    if (value < 393325350U) return 1;
    if (value < 1022645910U) return 2;
    if (value < 1861739990U) return 3;
    if (value < 2700834071U) return 4;
    if (value < 3372109335U) return 5;
    if (value < 3819626178U) return 6;
    if (value < 4075350088U) return 7;
    if (value < 4203212043U) return 8;
    return 9;
}

void CellNoise::insert(float* arr, float value)
{
    float temp;
    for (int i = 8; i >= 0; i--)
    {
        if (value > arr[i]) break;
        temp = arr[i];
        arr[i] = value;
        if(i == 0)
        {
            rd[0] =  featurePoint[0];
            rd[1] =  featurePoint[1];
            rd[2] =  featurePoint[2];
        }
        if (i < 8) arr[i + 1] = temp;
    }
}

int CellNoise::lcgRandom(int lastValue)
{
    return (int)((1103515245u * lastValue + 12345u) % 0x100000000u);
}

int CellNoise::hash(int i, int j, int k)
{
    return (int)((((((OFFSET_BASIS ^ (int)i) * FNV_PRIME) ^ (int)j) * FNV_PRIME) ^ (int)k) * FNV_PRIME);
}

ImprovedNoise::ImprovedNoise(float xsize, float ysize, float zsize)
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

 float ImprovedNoise::noise(float x, float y, float z)
{
  int X = (int)std::floor(x) & 255,
      Y = (int)std::floor(y) & 255,
      Z = (int)std::floor(z) & 255;
  x -= std::floor(x);
  y -= std::floor(y);
  z -= std::floor(z);
  float u = fade(x),
         v = fade(y),
         w = fade(z);
  int A = p[X  ]+Y, AA = p[A]+Z, AB = p[A+1]+Z,
      B = p[X+1]+Y, BA = p[B]+Z, BB = p[B+1]+Z;

  return lerp(w, lerp(v, lerp(u, grad(p[AA  ], x  , y  , z   ),
                                 grad(p[BA  ], x-1, y  , z   )),
                         lerp(u, grad(p[AB  ], x  , y-1, z   ),
                                 grad(p[BB  ], x-1, y-1, z   ))),
                 lerp(v, lerp(u, grad(p[AA+1], x  , y  , z-1 ),
                                 grad(p[BA+1], x-1, y  , z-1 )),
                         lerp(u, grad(p[AB+1], x  , y-1, z-1 ),
                                 grad(p[BB+1], x-1, y-1, z-1 ))));
}

float ImprovedNoise::fade(float f)
{
   return f * f * f * (f * (f * 6 - 15) + 10); // t * t * (3.0 - 2.0 * t);
}


float ImprovedNoise::lerp(float t, float a, float b)
{
   return a + t*(b - a);
}

float ImprovedNoise::grad(int hash, float x, float y, float z)
{
  int h = hash & 15;                      // CONVERT LO 4 BITS OF HASH CODE
  float u = h<8 ? x : y,                 // INTO 12 GRADIENT DIRECTIONS.
         v = h<4 ? y : h==12||h==14 ? x : z;
  return ((h&1) == 0 ? u : -u) + ((h&2) == 0 ? v : -v);
}

float ImprovedNoise::FractalNoise3D(float x, float y, float z, int octNum, float lacunarity , float gain)
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

float ImprovedNoise::Marble(float x, float y, float z,int octNum)
{
   float t = 0;
   float factor = 1.0;
   for (int pass = 0 ; pass < octNum; pass++, factor *= MAGIC_SCALE) {
       float r = 1.0f / factor;
       t += noise(x*r,y*r,z*r) * factor;
   }

   return t * correction;
}

float ImprovedNoise::lookup(float x, float y, float z)
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
