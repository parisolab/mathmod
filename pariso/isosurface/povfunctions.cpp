/***************************************************************************
*   Copyright (C) 2018 by Abderrahman Taha                                *
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
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
***************************************************************************/
#define PI1 (static_cast <double> (314159265)/static_cast <double> (100000000))
#include <cmath>

double maxim(double p1, double p2)
{
    return p1 > p2 ? p1 : p2;
}


double p_skeletal_int(const double* pp)
{
    double  cx, cy,cz;
    cx=cos(pp[0]);
    cy=cos(pp[1]);
    cz=cos(pp[2]);
    return(cx+cy+cz+0.51*(cx*cy+cy*cz+cz*cx)+1.2);
}

double f_hex_y(const double* pp)
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
        p[0]=0.000001;
    th=atan2(y1,x1);
    if (th<PI1/6)
        return(y1);
    else
    {
        y1=-sin(PI1/3)*x1+cos(PI1/3)*y1;
        return(fabs(y1));
    }
}

double fmesh(const double* pp) // 40
{
    double th, ph, r, r2, temp;
    double p[10];

    for(int i=0; i<10; i++)
        p[i] = pp[i];

    th = PI1 / p[3];
    ph = PI1/ p[4];
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

double  fhelix1(const double* pp)
{

    double r, r2, r3, temp, th, ph, x2;
    double p[10];
    for(int i=0; i<10; i++)
        p[i] = pp[i];
    r = sqrt(p[0] * p[0] + p[2] * p[2]);
    if ((p[0] == 0.0) && (p[2] == 0.0))
        p[0] = 0.000001;
    th = atan2(p[2], p[0]);
    th = fmod(th * p[3] + p[1] * p[4] * p[3], 2*PI1);
    if (th < 0)
        th += 2*PI1;
    p[2] = (th - PI1) / p[7] / (p[4] * p[3]);

    p[0] = r - p[6];
    if (p[8] == 1.0)
        r2 = sqrt(p[0] * p[0] + p[2] * p[2]);
    else
    {
        if (p[9] != 0.0)
        {
            th = cos(p[9] * PI1/180);
            ph = sin(p[9] * PI1/180);
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

double fhelix2(const double* pp) // 26
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
