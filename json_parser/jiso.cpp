/***************************************************************************
 *   Copyright (C) 2020by Abderrahman Taha                                *
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

#include "jiso.h"

jiso::jiso() {}

jiso::~jiso() {}

QStringList jiso::text() const { return Text; }

void jiso::setText(const QStringList &txt) { Text = txt; }

QStringList jiso::comment() const { return Comment; }

void jiso::setComment(const QStringList &cmt) { Comment = cmt; }

QStringList jiso::csts() const { return Csts; }

void jiso::setConst(const QStringList &cst) { Csts = cst; }

QStringList jiso::funct() const { return Funct; }

void jiso::setFunct(const QStringList &fct) { Funct = fct; }

QStringList jiso::grid() const { return Grid; }

void jiso::setGrid(const QStringList &grd) { Grid = grd; }

QStringList jiso::rgbt() const { return RGBT; }

void jiso::setRGBT(const QStringList &rgb) { RGBT = rgb; }

QStringList jiso::fxyz() const { return Fxyz; }

void jiso::setFxyz(const QStringList &fct) { Fxyz = fct; }

QStringList jiso::xmin() const { return Xmin; }

void jiso::setXmin(const QStringList &xmi) { Xmin = xmi; }

QStringList jiso::xmax() const { return Xmax; }

void jiso::setXmax(const QStringList &xma) { Xmax = xma; }

QStringList jiso::ymin() const { return Ymin; }

void jiso::setYmin(const QStringList &ymi) { Ymin = ymi; }

QStringList jiso::ymax() const { return Ymax; }

void jiso::setYmax(const QStringList &yma) { Ymax = yma; }

QStringList jiso::zmin() const { return Zmin; }

void jiso::setZmin(const QStringList &zmi) { Zmin = zmi; }

QStringList jiso::zmax() const { return Zmax; }

void jiso::setZmax(const QStringList &zma) { Zmax = zma; }

QStringList jiso::component() const { return Component; }

void jiso::setComponent(const QStringList &cmp) { Component = cmp; }

void jiso::read(const QJsonObject &jason) {
  QJsonArray array;
  JisoObj = jason;

  if (jason["Text"].isArray()) {
    array = jason["Text"].toArray();
    for (int i = 0; i < array.size(); i++)
      Text.append(array[i].toString());
  }
  if (jason["Comment"].isArray()) {
    array = jason["Comment"].toArray();
    for (int i = 0; i < array.size(); i++)
      Comment.append(array[i].toString());
  }
  if (jason["Name"].isArray()) {
    array = jason["Name"].toArray();
    for (int i = 0; i < array.size(); i++)
      Name.append(array[i].toString());
  }
  if (jason["Csts"].isArray()) {
    array = jason["Csts"].toArray();
    for (int i = 0; i < array.size(); i++)
      Csts.append(array[i].toString());
  }
  if (jason["Funct"].isArray()) {
    array = jason["Funct"].toArray();
    for (int i = 0; i < array.size(); i++)
      Funct.append(array[i].toString());
  }
  if (jason["Grid"].isArray()) {
    array = jason["Grid"].toArray();
    for (int i = 0; i < array.size(); i++)
      Grid.append(array[i].toString());
  }
  if (jason["RGBT"].isArray()) {
    array = jason["RGBT"].toArray();
    for (int i = 0; i < array.size(); i++)
      RGBT.append(array[i].toString());
  }
  if (jason["Xmin"].isArray()) {
    array = jason["Xmin"].toArray();
    for (int i = 0; i < array.size(); i++)
      Xmin.append(array[i].toString());
  }
  if (jason["Xmax"].isArray()) {
    array = jason["Xmax"].toArray();
    for (int i = 0; i < array.size(); i++)
      Xmax.append(array[i].toString());
  }
  if (jason["Ymin"].isArray()) {
    array = jason["Ymin"].toArray();
    for (int i = 0; i < array.size(); i++)
      Ymin.append(array[i].toString());
  }
  if (jason["Ymax"].isArray()) {
    array = jason["Ymax"].toArray();
    for (int i = 0; i < array.size(); i++)
      Ymax.append(array[i].toString());
  }
  if (jason["Zmin"].isArray()) {
    array = jason["Zmin"].toArray();
    for (int i = 0; i < array.size(); i++)
      Zmin.append(array[i].toString());
  }
  if (jason["Zmax"].isArray()) {
    array = jason["Zmax"].toArray();
    for (int i = 0; i < array.size(); i++)
      Zmax.append(array[i].toString());
  }
  if (jason["Component"].isArray()) {
    array = jason["Component"].toArray();
    for (int i = 0; i < array.size(); i++)
      Component.append(array[i].toString());
  }
  if (jason["Fxyz"].isArray()) {
    array = jason["Fxyz"].toArray();
    for (int i = 0; i < array.size(); i++)
      Fxyz.append(array[i].toString());
  }
  if (jason["Cnd"].isArray()) {
    array = jason["Cnd"].toArray();
    for (int i = 0; i < array.size(); i++)
      Cnd.append(array[i].toString());
  }
}

void jiso::write(QJsonObject &json) const {
  QJsonArray nm;
  for (int i = 0; i < Name.size(); i++)
    nm.append(Name.at(i));
  json["Name"] = nm;

  QJsonArray txt;
  for (int i = 0; i < Text.size(); i++)
    txt.append(Text.at(i));
  json["Text"] = txt;

  QJsonArray cmp;
  for (int i = 0; i < Component.size(); i++)
    cmp.append(Component.at(i));
  json["Component"] = cmp;

  QJsonArray grd;
  for (int i = 0; i < Grid.size(); i++)
    grd.append(Grid.at(i));
  json["Grid"] = grd;

  QJsonArray rgb;
  for (int i = 0; i < RGBT.size(); i++)
    rgb.append(RGBT.at(i));
  json["RGBT"] = rgb;

  QJsonArray xmi;
  for (int i = 0; i < Xmin.size(); i++)
    xmi.append(Xmin.at(i));
  json["Xmin"] = xmi;

  QJsonArray xma;
  for (int i = 0; i < Xmax.size(); i++)
    xma.append(Xmax.at(i));
  json["Xmax"] = xma;

  QJsonArray ymi;
  for (int i = 0; i < Ymin.size(); i++)
    ymi.append(Ymin.at(i));
  json["Ymin"] = ymi;

  QJsonArray yma;
  for (int i = 0; i < Ymax.size(); i++)
    yma.append(Ymax.at(i));
  json["Ymax"] = yma;

  QJsonArray zmi;
  for (int i = 0; i < Zmin.size(); i++)
    zmi.append(Zmin.at(i));
  json["Zmin"] = zmi;

  QJsonArray zma;
  for (int i = 0; i < Zmax.size(); i++)
    zma.append(Zmax.at(i));
  json["Zmax"] = zma;
}
