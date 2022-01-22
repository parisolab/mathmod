/***************************************************************************
 *   Copyright (C) 2021 by Abderrahman Taha                                *
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

//#include "comvar.h"
#include "../json_parser/parisodef.h"
#include "ui_parametersoptions.h"
#include <QFileDialog>
#include <QJsonObject>
#include <QMainWindow>
#include <QMessageBox>
#include <QStyleFactory>

struct ListeModelTexture
{
    QStringList listeModels;
    QStringList listeTextures;
    QStringList listePigments;
};

class Parametersoptions : public QWidget
{
    Q_OBJECT

public:
    Parametersoptions(QWidget *parent = nullptr);
    QString dotsymbol = ".";
    QString model = "CloseIso_2";
    QString filecollection = "mathmodcollection.js";
    QString fileconfig = "mathmodconfig.js";
    QString advancedmodels = "advancedmodels.js";
    QString docpartialpath = "/documentation/index.html";
    QString docabsolutepath = "";
    QString version = "12.1";
    QString fullpath;
    QJsonObject JConfig, Collection, IsoParam;
    QPalette mypalette, mypalette2, darkpalette;
    QApplication *MainApp;
    int ControlX = 20;
    int ControlY = 20;
    int GlwinX = 575;
    int GlwinY = 20;
    int ControlW = 538;
    int ControlH = 700;
    int GlwinW = 780;
    int GlwinH = 700;
    int Specular[4]={50,50,50,100};
    int Ambient[4]={50,50,50,100};
    int Diffuse[4]={80,80,80,100};
    int Shininess=110;
    bool glFrontFacingSupport=true;






    int IsoMaxGrid = 305;
    int ParMaxGrid = 505;
    void on_comboBox_2_activated(const QString &);
    void on_comboBox_3_activated(const QString &);
    void on_comboBox_activated(const QString &);
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
    void SaveToFile_CurentMathModel(QJsonObject CurrentJsonObject);
    void LoadConfig(QApplication &, int argc, char *argv[]);
    ListeModelTexture LoadCollectionModels(QJsonObject &, jcollection &, int);
    bool isFloat(std::string);
    void onred_2valueChanged(int);
    void ongreen_2valueChanged(int);
    void onblue_2valueChanged(int);
public:
    Ui::Parametersoptions ui;
};

#endif
