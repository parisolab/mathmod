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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#ifndef PARAMETERSOPTIONS_H
#define PARAMETERSOPTIONS_H

#include "ui_parametersoptions.h"
#include "../json_parser/parisodef.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonObject>
#include <QStyleFactory>
#include <QMainWindow>

struct ListeModelTexture
{
    QStringList listeModels;
    QStringList listeTextures;
    QStringList listePigments;
};

class Parametersoptions: public QWidget
{
    Q_OBJECT

public:
    Parametersoptions(QWidget *parent = nullptr);
    QString dotsymbol;
    QString model;
    QString fullpath;
    QString filecollection;
    QString fileconfig;
    QString advancedmodels;
    QJsonObject JConfig, Collection, IsoParam;
    QPalette mypalette, mypalette2, darkpalette;
    QApplication * MainApp;
    int ControlX;
    int ControlY;
    int GlwinX;
    int GlwinY;
    int ControlW;
    int ControlH;
    int GlwinW;
    int GlwinH;
    float Specular[4];
    int Threads[3];
    int CalculFactor[3];
    int Shininess;
    int IsoMaxGrid;
    int ParMaxGrid;
    int InitParGrid;
    int InitIsoGrid;

public slots:
    void ReadConfigFile(QString, QJsonObject &);
    void ReadJsonFile(QString, QJsonObject &);
    void ReadCollectionFile(QString, QJsonObject &);
    void SetStyleAndTheme(QApplication &, QString, QString);
    void slot_about_clicked();
    void GuiUpdate();
    void maxisogri_valueChanged(int);
    void maxpargri_valueChanged(int);
    void on_loadconfig_clicked();
    void SaveToFile_CurentMathModel(QJsonObject  CurrentJsonObject);
    void on_save_clicked();
    void LoadConfig(QApplication &,int argc, char *argv[]);
    ListeModelTexture LoadCollectionModels(QJsonObject &, jpariso &, int);
    bool isFloat(std::string);
    void on_comboBox_2_activated(const QString &);
    void on_comboBox_3_activated(const QString &);
    void on_comboBox_activated(const QString &);
    void onred_2valueChanged(int);
    void ongreen_2valueChanged(int);
    void onblue_2valueChanged(int);
    void on_TestConfig_clicked();
public:
    Ui::Parametersoptions ui;
};

#endif
