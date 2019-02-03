/***************************************************************************
 *   Copyright (C) 2018 by Abderrahman Taha                                *
 *   taha_ab@yahoo.fr                                                      *
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


#include "Matrix4D.h"

/** Create a new unit matrix */
Matrix4D::Matrix4D()
{

    pi = 3.14159265;
    xx = 1.0;
    yy = 1.0;
    zz = 1.0;
    ww = 1.0;
    ko = 1.0;
    xy = xz = xw = xo = 0;
    yx = yz = yw = yo = 0;
    zx = zy = zw = zo = 0;
    wx = wy = wz = wo = 0;
    kx = ky = kz = kw = 0;
}


void Matrix4D::mult(Matrix4D rhs)
{
    double lxx = xx * rhs.xx + yx * rhs.xy + zx * rhs.xz + wx * rhs.xw;
    double lxy = xy * rhs.xx + yy * rhs.xy + zy * rhs.xz + wy * rhs.xw;
    double lxz = xz * rhs.xx + yz * rhs.xy + zz * rhs.xz + wz * rhs.xw;
    double lxw = xw * rhs.xx + yw * rhs.xy + zw * rhs.xz + ww * rhs.xw;
    double lxo = xo * rhs.xx + yo * rhs.xy + zo * rhs.xz + wo * rhs.xw + rhs.xo;

    double lyx = xx * rhs.yx + yx * rhs.yy + zx * rhs.yz + wx * rhs.yw;
    double lyy = xy * rhs.yx + yy * rhs.yy + zy * rhs.yz + wy * rhs.yw;
    double lyz = xz * rhs.yx + yz * rhs.yy + zz * rhs.yz + wz * rhs.yw;
    double lyw = xw * rhs.yx + yw * rhs.yy + zw * rhs.yz + ww * rhs.yw;
    double lyo = xo * rhs.yx + yo * rhs.yy + zo * rhs.yz + wo * rhs.yw + rhs.yo;

    double lzx = xx * rhs.zx + yx * rhs.zy + zx * rhs.zz + wx * rhs.zw;
    double lzy = xy * rhs.zx + yy * rhs.zy + zy * rhs.zz + wy * rhs.zw;
    double lzz = xz * rhs.zx + yz * rhs.zy + zz * rhs.zz + wz * rhs.zw;
    double lzw = xw * rhs.zx + yw * rhs.zy + zw * rhs.zz + ww * rhs.zw;
    double lzo = xo * rhs.zx + yo * rhs.zy + zo * rhs.zz + wo * rhs.zw + rhs.zo;

    double lwx = xx * rhs.wx + yx * rhs.wy + zx * rhs.wz + wx * rhs.ww;
    double lwy = xy * rhs.wx + yy * rhs.wy + zy * rhs.wz + wy * rhs.ww;
    double lwz = xz * rhs.wx + yz * rhs.wy + zz * rhs.wz + wz * rhs.ww;
    double lww = xw * rhs.wx + yw * rhs.wy + zw * rhs.wz + ww * rhs.ww;
    double lwo = xo * rhs.wx + yo * rhs.wy + zo * rhs.wz + wo * rhs.ww + rhs.wo;

    xx = lxx;
    xy = lxy;
    xz = lxz;
    xw = lxw;
    xo = lxo;

    yx = lyx;
    yy = lyy;
    yz = lyz;
    yw = lyw;
    yo = lyo;

    zx = lzx;
    zy = lzy;
    zz = lzz;
    zw = lzw;
    zo = lzo;

    wx = lwx;
    wy = lwy;
    wz = lwz;
    ww = lww;
    wo = lwo;
}

/** rotate theta degrees about the yz plan */
void Matrix4D::yzrot(double theta)
{
    theta *= (pi / 180);
    double ct = cos(theta);
    double st = sin(theta);

    double Nyx = double(yx * ct + zx * st);
    double Nyy = double(yy * ct + zy * st);
    double Nyz = double(yz * ct + zz * st);
    double Nyw = double(yw * ct + zw * st);
    double Nyo = double(yo * ct + zo * st);

    double Nzx = double(zx * ct - yx * st);
    double Nzy = double(zy * ct - yy * st);
    double Nzz = double(zz * ct - yz * st);
    double Nzw = double(zw * ct - yw * st);
    double Nzo = double(zo * ct - yo * st);

    yo = Nyo;
    yx = Nyx;
    yy = Nyy;
    yz = Nyz;
    yw = Nyw;

    zo = Nzo;
    zx = Nzx;
    zy = Nzy;
    zz = Nzz;
    zw = Nzw;
}

/** rotate theta degrees about the xz plan */
void Matrix4D::xzrot(double theta)
{
    theta *= (pi / 180);
    double ct = cos(theta);
    double st = sin(theta);

    double Nxx = double(xx * ct + zx * st);
    double Nxy = double(xy * ct + zy * st);
    double Nxz = double(xz * ct + zz * st);
    double Nxw = double(xw * ct + zw * st);
    double Nxo = double(xo * ct + zo * st);

    double Nzx = double(zx * ct - xx * st);
    double Nzy = double(zy * ct - xy * st);
    double Nzz = double(zz * ct - xz * st);
    double Nzw = double(zw * ct - xw * st);
    double Nzo = double(zo * ct - xo * st);

    xo = Nxo;
    xx = Nxx;
    xy = Nxy;
    xz = Nxz;
    xw = Nxw;

    zo = Nzo;
    zx = Nzx;
    zy = Nzy;
    zz = Nzz;
    zw = Nzw;
}

/** rotate theta degrees about the  xy plan */
void Matrix4D::xyrot(double theta)
{
    theta *= (pi / 180);
    double ct = cos(theta);
    double st = sin(theta);

    double Nyx = double(yx * ct + xx * st);
    double Nyy = double(yy * ct + xy * st);
    double Nyz = double(yz * ct + xz * st);
    double Nyw = double(yw * ct + xw * st);
    double Nyo = double(yo * ct + xo * st);

    double Nxx = double(xx * ct - yx * st);
    double Nxy = double(xy * ct - yy * st);
    double Nxz = double(xz * ct - yz * st);
    double Nxw = double(xw * ct - yw * st);
    double Nxo = double(xo * ct - yo * st);

    yo = Nyo;
    yx = Nyx;
    yy = Nyy;
    yz = Nyz;
    yw = Nyw;

    xo = Nxo;
    xx = Nxx;
    xy = Nxy;
    xz = Nxz;
    xw = Nxw;
}

/** rotate theta degrees about the  xw plan */

void Matrix4D::xwrot(double theta)
{
    theta *= (pi / 180);
    double ct = cos(theta);
    double st = sin(theta);

    double Nwx = double(wx * ct + xx * st);
    double Nwy = double(wy * ct + xy * st);
    double Nwz = double(wz * ct + xz * st);
    double Nww = double(ww * ct + xw * st);
    double Nwo = double(wo * ct + xo * st);

    double Nxx = double(xx * ct - wx * st);
    double Nxy = double(xy * ct - wy * st);
    double Nxz = double(xz * ct - wz * st);
    double Nxw = double(xw * ct - ww * st);
    double Nxo = double(xo * ct - wo * st);

    wo = Nwo;
    wx = Nwx;
    wy = Nwy;
    wz = Nwz;
    ww = Nww;

    xo = Nxo;
    xx = Nxx;
    xy = Nxy;
    xz = Nxz;
    xw = Nxw;
}

/** rotate theta degrees about the  yw plan */

void Matrix4D::ywrot(double theta)
{
    theta *= (pi / 180);
    double ct = cos(theta);
    double st = sin(theta);

    double Nwx = double(wx * ct + yx * st);
    double Nwy = double(wy * ct + yy * st);
    double Nwz = double(wz * ct + yz * st);
    double Nww = double(ww * ct + yw * st);
    double Nwo = double(wo * ct + yo * st);

    double Nyx = double(yx * ct - wx * st);
    double Nyy = double(yy * ct - wy * st);
    double Nyz = double(yz * ct - wz * st);
    double Nyw = double(yw * ct - ww * st);
    double Nyo = double(yo * ct - wo * st);

    wo = Nwo;
    wx = Nwx;
    wy = Nwy;
    wz = Nwz;
    ww = Nww;

    yo = Nyo;
    yx = Nyx;
    yy = Nyy;
    yz = Nyz;
    yw = Nyw;
}


/** rotate theta degrees about the  yw plan */

void Matrix4D::zwrot(double theta)
{
    theta *= (pi / 180);
    double ct = cos(theta);
    double st = sin(theta);

    double Nwx = double(wx * ct + zx * st);
    double Nwy = double(wy * ct + zy * st);
    double Nwz = double(wz * ct + zz * st);
    double Nww = double(ww * ct + zw * st);
    double Nwo = double(wo * ct + zo * st);

    double Nzx = double(zx * ct - wx * st);
    double Nzy = double(zy * ct - wy * st);
    double Nzz = double(zz * ct - wz * st);
    double Nzw = double(zw * ct - ww * st);
    double Nzo = double(zo * ct - wo * st);

    wo = Nwo;
    wx = Nwx;
    wy = Nwy;
    wz = Nwz;
    ww = Nww;

    zo = Nzo;
    zx = Nzx;
    zy = Nzy;
    zz = Nzz;
    zw = Nzw;
}


/** Multiply this matrix by a second: M = M*R */


/** Reinitialize to the unit matrix */
void Matrix4D::unit()
{
    xo = 0;
    xx = 1;
    xy = 0;
    xz = 0;
    xw = 0;

    yo = 0;
    yx = 0;
    yy = 1;
    yz = 0;
    yw = 0;

    zo = 0;
    zx = 0;
    zy = 0;
    zz = 1;
    zw = 0;

    wo = 0;
    wx = 0;
    wy = 0;
    wz = 0;
    ww = 1;

    ko = 1;
    kx = 0;
    ky = 0;
    kz = 0;
    kw = 0;
};

/** Translate the origin */
void Matrix4D::translate(double x, double y, double z, double w)
{
    xo += x;
    yo += y;
    zo += z;
    wo += w;
}

/** Scale by f in all dimensions */
void Matrix4D::scale(double f)
{
    xx *= f;
    xy *= f;
    xz *= f;
    xo *= f;
    yx *= f;
    yy *= f;
    yz *= f;
    yo *= f;
    zx *= f;
    zy *= f;
    zz *= f;
    zo *= f;
}
/** Scale along each axis independently */
void Matrix4D::scale_2(double xf, double yf, double zf)
{
    xx *= xf;
    xy *= xf;
    xz *= xf;
    xo *= xf;
    yx *= yf;
    yy *= yf;
    yz *= yf;
    yo *= yf;
    zx *= zf;
    zy *= zf;
    zz *= zf;
    zo *= zf;
}
