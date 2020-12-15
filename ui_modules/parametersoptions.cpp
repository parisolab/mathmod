/***************************************************************************
 *   Copyright (C) 2020 by Abderrahman Taha                                *
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
#include "parametersoptions.h"
#include "../fparser/fparser.hh"
#include <QtGui>
#include <math.h>
#include <sstream>
#include <string>

static bool MACOS = false;

Parametersoptions::Parametersoptions(QWidget *parent) : QWidget(parent)
{
    ControlX = 20;
    ControlY = 20;
    GlwinX = 575;
    GlwinY = 20;
    ControlW = 538;
    ControlH = 700;
    GlwinW = 780;
    GlwinH = 700;
    IsoMaxGrid = 305;
    ParMaxGrid = 505;
    InitParGrid = 50;
    InitIsoGrid = 40;
    dotsymbol = ".";
    model = "CloseIso_2";
    Shininess = 110;
    Specular[0] = Specular[1] = Specular[2] = 0.5;
    Specular[3] = 1.0;
    Threads[0] = 8;
    Threads[1] = 1;
    Threads[2] = 64;
    CalculFactor[0] = 4;
    CalculFactor[1] = 4;
    CalculFactor[2] = 4;
    filecollection = "mathmodcollection.js";
    fileconfig = "mathmodconfig.js";
    advancedmodels = "advancedmodels.js";
    darkpalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkpalette.setColor(QPalette::WindowText, QColor(255, 255, 255));
    darkpalette.setColor(QPalette::Base, QColor(15, 15, 15));
    darkpalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkpalette.setColor(QPalette::ToolTipBase, QColor(255, 255, 255));
    darkpalette.setColor(QPalette::ToolTipText, QColor(255, 255, 255));
    darkpalette.setColor(QPalette::Text, QColor(255, 255, 255));
    darkpalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkpalette.setColor(QPalette::ButtonText, QColor(255, 255, 255));
    darkpalette.setColor(QPalette::BrightText, QColor(255, 0, 0));
    darkpalette.setColor(QPalette::Highlight, QColor(142, 45, 197).lighter());
    darkpalette.setColor(QPalette::HighlightedText, QColor(0, 0, 0));
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    ui.setupUi(this);
}

void Parametersoptions::slot_about_clicked()
{
    this->close();
}

void Parametersoptions::SetStyleAndTheme(QApplication &appli, QString style,
        QString theme)
{
    if (style != "Default")
        appli.setStyle(QStyleFactory::create(style));
    if (theme == "Dark")
    {
        appli.setPalette(darkpalette);
    }
    else if (theme == "MyTheme")
    {
        appli.setPalette(mypalette);
    }
}

void Parametersoptions::ReadConfigFile(QString JsonFile, QJsonObject &js)
{
    QJsonParseError err;
    QString sortie;

    QFile file1(JsonFile);
    if (!file1.exists())
    {
        JsonFile = QFileDialog::getOpenFileName(
                       nullptr, QObject::tr("Open mathmodconfig.js File"), "",
                       QObject::tr("Json (*.js)"));
    }
    if (JsonFile == "")
        JsonFile = ":/mathmodconfig.js";
    QFile file(JsonFile);
    // QFileDevice::Permissions p = file.permissions();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QJsonDocument doc = QJsonDocument::fromJson(
                                ((file.readAll()).trimmed())
                                .replace("\n", "")
                                .replace("\t", "")
                                .replace("DOTSYMBOL", dotsymbol.toStdString().c_str()),
                                &err);
        if (err.error)
        {
            QMessageBox message;
            message.setWindowTitle("Error at : " + JsonFile);
            file.close();
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            sortie = (file.readAll());
            int before, after;
            if (sortie.length() > (err.offset + 30))
                after = 30;
            else
                after = sortie.length() - err.offset;
            sortie.truncate(err.offset + after);
            if (err.offset - 30 > 0)
                before = 30;
            else
                before = 0;
            sortie = sortie.remove(0, err.offset - before);
            sortie.replace("\t", " ");
            sortie.replace("\n", " ");
            sortie.insert(before, " >>> Error <<< ");
            message.setText("Error : " + err.errorString() +
                            " at position: " + QString::number(err.offset) +
                            "\n\n***********\n" + "..." + sortie + "...");
            message.adjustSize();
            message.exec();
            file.close();
            return;
        }
        js = doc.object();
        file.close();
    }
    return;
}

void Parametersoptions::ReadJsonFile(QString JsonFile, QJsonObject &js)
{
    QJsonParseError err;
    QString sortie;
    QFile file1(JsonFile);
    if (!file1.exists())
    {
        JsonFile = QFileDialog::getOpenFileName(
                       nullptr, QObject::tr("Open mathmodconfig.js File"), "",
                       QObject::tr("Json (*.js)"));
    }
    QFile file(JsonFile);
    // QFileDevice::Permissions p = file.permissions();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QJsonDocument doc = QJsonDocument::fromJson(
                                ((file.readAll()).trimmed())
                                .replace("\n", "")
                                .replace("\t", "")
                                .replace("DOTSYMBOL", dotsymbol.toStdString().c_str()),
                                &err);
        if (err.error)
        {
            QMessageBox message;
            message.setWindowTitle("Error at : " + JsonFile);
            file.close();
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            sortie = (file.readAll());
            int before, after;
            if (sortie.length() > (err.offset + 30))
                after = 30;
            else
                after = sortie.length() - err.offset;
            sortie.truncate(err.offset + after);
            if (err.offset - 30 > 0)
                before = 30;
            else
                before = 0;
            sortie = sortie.remove(0, err.offset - before);
            sortie.replace("\t", " ");
            sortie.replace("\n", " ");
            sortie.insert(before, " >>> Error <<< ");
            message.setText("Error : " + err.errorString() +
                            " at position: " + QString::number(err.offset) +
                            "\n\n***********\n" + "..." + sortie + "...");
            message.adjustSize();
            message.exec();
            file.close();
            return;
        }
        js = doc.object();
        file.close();
    }
    return;
}

void Parametersoptions::ReadCollectionFile(QString JsonFileName,
        QJsonObject &js)
{
    QJsonParseError err;
    QString sortie;
    QFile JsonFile(JsonFileName);
    if (!JsonFile.exists())
    {
        QFile file2(":/mathmodcollection_empty.js");
        file2.copy(JsonFileName);
        QFile::setPermissions(JsonFileName,
                              QFileDevice::ReadOwner | QFileDevice::WriteOwner);
    }
    QFile file(JsonFileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QJsonDocument doc = QJsonDocument::fromJson(
                                ((file.readAll()).trimmed())
                                .replace("\n", "")
                                .replace("\t", "")
                                .replace("DOTSYMBOL", dotsymbol.toStdString().c_str()),
                                &err);
        if (err.error)
        {
            QMessageBox message;
            message.setWindowTitle("Error at : " + JsonFileName);
            file.close();
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            sortie = (file.readAll());
            int before, after;
            if (sortie.length() > (err.offset + 30))
                after = 30;
            else
                after = sortie.length() - err.offset;
            sortie.truncate(err.offset + after);
            if (err.offset - 30 > 0)
                before = 30;
            else
                before = 0;
            sortie = sortie.remove(0, err.offset - before);
            sortie.replace("\t", " ");
            sortie.replace("\n", " ");
            sortie.insert(before, " >>> Error <<< ");
            message.setText("Error : " + err.errorString() +
                            " at position: " + QString::number(err.offset) +
                            "\n\n***********\n" + "..." + sortie + "...");
            message.adjustSize();
            message.exec();
            file.close();
            return;
        }
        js = doc.object();
        file.close();
    }
    return;
}

void Parametersoptions::GuiUpdate()
{
    QJsonObject isoparam = (JConfig)["Parameters"].toObject();
    // Iso Grid
    int mg = (isoparam)["IsoMaxGrid"].toInt();
    ui.IsoMaxGridLineEdit->setText(QString::number(mg));
    // Par Grid
    mg = (isoparam)["ParMaxGrid"].toInt();
    ui.ParMaxGridLineEdit->setText(QString::number(mg));
    // Styles:
    QString Style = ((JConfig["Styles"].toObject())["UsedStyle"].toString());
    ui.comboBox_2->setCurrentText(Style);
    // Theme:
    QString theme = ((JConfig["Themes"].toObject())["UsedTheme"].toString());
    ui.comboBox_3->setCurrentText(theme);
    if (theme == "MyTheme")
        ui.groupBox->show();
    else
        ui.groupBox->hide();
}

void Parametersoptions::maxisogri_valueChanged(int value)
{
    IsoMaxGrid = value;
    QJsonObject tmp = JConfig["Parameters"].toObject();
    tmp["IsoMaxGrid"] = value;
    JConfig["Parameters"] = tmp;
}

void Parametersoptions::maxpargri_valueChanged(int value)
{
    ParMaxGrid = value;
    QJsonObject tmp = JConfig["Parameters"].toObject();
    tmp["ParMaxGrid"] = value;
    JConfig["Parameters"] = tmp;
}

void Parametersoptions::on_loadconfig_clicked()
{
    ReadConfigFile(fullpath, JConfig);
    GuiUpdate();
}

ListeModelTexture
Parametersoptions::LoadCollectionModels(QJsonObject &Jcollection,
                                        jcollection &pariso, int argc)
{

    QFile fconllect(filecollection);
    if (fconllect.exists() && ((argc > 1) || MACOS))
        ReadJsonFile(filecollection, Collection);
    else
        ReadJsonFile(":/mathmodcollection.js", Collection);

    Jcollection = Collection;
    QJsonArray array = Collection["MathModels"].toArray();
    QStringList lst;
    QJsonArray array2 = pariso.JTextures = Collection["TexturesList"].toArray();

    QJsonArray array3 = pariso.JPigments = Collection["PigmentsList"].toArray();

    QStringList lst_2, lst_3;
    QString a;
    QJsonObject jsobj;
    QJsonArray  jsarray;
    // Textures List:
    for (int i = 0; i < array2.size(); i++)
    {
        if ((array2[i].toObject())["Texture"].isObject())
        {
            jsobj = (array2[i].toObject())["Texture"].toObject();
            a = (jsobj)["Name"].toString();
            lst_2.append(a);
        }
    }
    lst_2.insert(0, "Textures List (" + QString::number(lst_2.count()) + ")");

    // Pigments List:
    for (int i = 0; i < array3.size(); i++)
    {
        if ((array3[i].toObject())["Pigment"].isObject())
        {
            jsobj = (array3[i].toObject())["Pigment"].toObject();
            a = (jsobj)["Name"].toString();
            lst_3.append(a);
        }
    }
    lst_3.insert(0, "PigmentsList (" + QString::number(lst_3.count()) + ")");

    for (int i = 0; i < array.size(); i++)
    {
        if ((array[i].toObject())["Iso3D"].isObject())
        {
            jiso newjiso;
            jsobj = (array[i].toObject())["Iso3D"].toObject();
            newjiso.read(jsobj);
            pariso.JIso.append(newjiso);
            a = (jsobj)["Name"].toArray()[0].toString();
            lst.append(a);
        }
        else if ((array[i].toObject())["Param3D"].isObject())
        {
            jpar newjpar;
            jsobj = ((array[i].toObject())["Param3D"].toObject());
            newjpar.read(jsobj);
            pariso.JPar.append(newjpar);
            a = (jsobj)["Name"].toArray()[0].toString();
            lst.append(a);
        }
        else if ((array[i].toObject())["Param4D"].isObject())
        {
            jpar newjpar;
            jsobj = ((array[i].toObject())["Param4D"].toObject());
            newjpar.read(jsobj);
            pariso.JPar.append(newjpar);
            a = (jsobj)["Name"].toArray()[0].toString();
            lst.append(a);
        }
        else if ((array[i].toObject())["ParIso"].isArray())
        {
            jpariso newjpariso;
            jpar newjpar;
            jiso newjiso;
            jsarray = ((array[i].toObject())["ParIso"].toArray());
            for(int i=0; i<jsarray.size(); i++)
            {
                if ((jsarray[i].toObject())["Param3D"].isObject())
                {
                   jsobj =  (jsarray[i].toObject())["Param3D"].toObject();
                   newjpar.read(jsobj);
                   newjpariso.JPar = newjpar;
                } else if ((jsarray[i].toObject())["Iso3D"].isObject())
                {
                   jsobj =  (jsarray[i].toObject())["Iso3D"].toObject();
                   newjiso.read(jsobj);
                   newjpariso.JIso = newjiso;
                }
            }
            a = newjpariso.Name = (array[i].toObject())["Name"].toString();
            pariso.JParIso.append(newjpariso);
            lst.append(a);
        }
    }

    lst.sort();
    lst.insert(0, "Examples (" + QString::number(lst.count()) + ")");

    ListeModelTexture str;
    str.listeModels = lst;
    str.listeTextures = lst_2;
    str.listePigments = lst_3;
    return str;
}

void Parametersoptions::SaveToFile_CurentMathModel(
    QJsonObject CurrentJsonObject)
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save to file"), "",
                       tr("JSON Files (*.js)"));
    if (fileName != "")
    {
        QJsonObject collection;
        ReadCollectionFile(fileName, collection);
        QJsonDocument document;
        if (collection["MathModels"].isArray())
        {
            QJsonArray array = collection["MathModels"].toArray();
            array.append(CurrentJsonObject);
            collection["MathModels"] = array;
            document.setObject(collection);
            QFile f(fileName);
            if (f.open(QIODevice::ReadWrite | QIODevice::Text))
            {
                QTextStream t(&f);
                QString tmp = QString(document.toJson()).toLatin1();
                t << tmp.toUtf8();
                f.close();
            }
        }
    }
}

bool Parametersoptions::isFloat(std::string myString)
{
    std::istringstream iss(myString);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

void Parametersoptions::LoadConfig(QApplication &app, int argc, char *argv[])
{
    QString argv1;
    if (argc > 1)
    {
        argv1 = QString(argv[1]);
        if (!argv1.endsWith("/"))
            argv1 += "/";
        filecollection = argv1 + filecollection;
        fileconfig = argv1 + fileconfig;
        advancedmodels = argv1 + advancedmodels;
    }
    /*
        #ifdef Q_OS_MACOS
            else
            {
                MACOS = true;
                argv1 ="../Resources/";
                filecollection   = argv1 + filecollection;
                fileconfig       = argv1 + fileconfig;
                advancedmodels   = argv1 + advancedmodels;
             }
        #endif
    */
    QFile mathmodfileconfig(fileconfig);
    if (!mathmodfileconfig.exists() && ((argc > 1) || MACOS))
    {
        QFile file3(":/mathmodconfig.js");
        file3.copy(fileconfig);
        QFile::setPermissions(fileconfig,
                              QFileDevice::ReadOwner | QFileDevice::WriteOwner);
    }

    QFile fconf(fileconfig);
    if (fconf.exists())
        ReadJsonFile(fileconfig, JConfig);
    else
        ReadJsonFile(":/mathmodconfig.js", JConfig);

    {
        if (JConfig["Localization"].isObject())
        {
            QJsonObject tmp;
            tmp = JConfig["Localization"].toObject();
            if (tmp["AutomaticDetection"].isBool() &&
                    tmp["AutomaticDetection"].toBool())
            {
                FunctionParser ff;
                if ((ff.Parse("1.02", "t")) >= 0)
                    dotsymbol = ",";
                else
                    dotsymbol = ".";
            }
            else
                dotsymbol = tmp["DotSymbol"].toString();
        }

        if (JConfig["StartOptions"].isObject())
        {
            QJsonObject tmp;
            tmp = JConfig["StartOptions"].toObject();
            model = tmp["Model"].toString();
        }

        if (JConfig["Parameters"].isObject())
        {
            IsoParam = JConfig["Parameters"].toObject();
            if ((IsoParam)["IsoMaxGrid"].isDouble())
                IsoMaxGrid = ((IsoParam)["IsoMaxGrid"]).toInt();

            if ((IsoParam)["ParMaxGrid"].isDouble())
                ParMaxGrid = ((IsoParam)["ParMaxGrid"]).toInt();

            if ((IsoParam)["InitParGrid"].isDouble())
                InitParGrid = (IsoParam)["InitParGrid"].toInt();

            if ((IsoParam)["InitIsoGrid"].isDouble())
                InitIsoGrid = (IsoParam)["InitIsoGrid"].toInt();
        }

        QJsonObject tmp;
        if (JConfig["WindowPosition"].isObject())
        {
            tmp = JConfig["WindowPosition"].toObject();
            ControlX = tmp["ControlX"].toInt();
            ControlY = tmp["ControlY"].toInt();
            GlwinX = tmp["GlwinX"].toInt();
            GlwinY = tmp["GlwinY"].toInt();
        }

        if (JConfig["WindowSize"].isObject())
        {
            tmp = JConfig["WindowSize"].toObject();
            ControlW = tmp["ControlW"].toInt();
            ControlH = tmp["ControlH"].toInt();
            GlwinW = tmp["GlwinW"].toInt();
            GlwinH = tmp["GlwinH"].toInt();
        }

        if (JConfig["OpenGlConfig"].isObject())
        {
            QJsonObject tmp1, tmp2;
            tmp1 = JConfig["OpenGlConfig"].toObject();
            Shininess = tmp1["GL_SHININESS"].toInt();

            tmp2 = JConfig["OpenGlConfig"].toObject();
            if (tmp2["GL_SPECULAR"].isArray())
            {
                Specular[0] =
                    float((tmp2["GL_SPECULAR"].toArray())[0].toDouble() / 100.0);
                Specular[1] =
                    float((tmp2["GL_SPECULAR"].toArray())[1].toDouble() / 100.0);
                Specular[2] =
                    float((tmp2["GL_SPECULAR"].toArray())[2].toDouble() / 100.0);
                Specular[3] =
                    float((tmp2["GL_SPECULAR"].toArray())[3].toDouble() / 100.0);
            }
        }

        if (JConfig["CalculFactorConfig"].isObject())
        {
            QJsonObject tmp = JConfig["CalculFactorConfig"].toObject();
            CalculFactor[0] = tmp["FactX"].toInt();
            CalculFactor[1] = tmp["FactY"].toInt();
            CalculFactor[2] = tmp["FactZ"].toInt();
        }

        if (JConfig["ThreadsConfig"].isObject())
        {
            QJsonObject tmp = JConfig["ThreadsConfig"].toObject();
            if (tmp["AutoDetect"].isBool() && tmp["AutoDetect"].toBool())
                Threads[0] = QThread::idealThreadCount();
            else
                Threads[0] = tmp["ThreadsNumber"].toInt();
            Threads[1] = tmp["MinThreadsNumber"].toInt();
            Threads[2] = tmp["MaxThreadsNumber"].toInt();
        }

        if (JConfig["Themes"].isObject() && JConfig["Styles"].isObject())
        {
            QJsonObject tmp1, tmp2, MyTheme;
            tmp2 = JConfig["Styles"].toObject();
            QString style = tmp2["UsedStyle"].toString();
            tmp1 = JConfig["Themes"].toObject();
            QString theme = tmp1["UsedTheme"].toString();
            if (theme == "MyTheme")
            {
                MyTheme = tmp1["MyTheme"].toObject();
                mypalette.setColor(QPalette::Window,
                                   QColor((MyTheme["Window"].toArray())[0].toInt(),
                                          (MyTheme["Window"].toArray())[1].toInt(),
                                          (MyTheme["Window"].toArray())[2].toInt()));
                mypalette.setColor(
                    QPalette::WindowText,
                    QColor((MyTheme["WindowText"].toArray())[0].toInt(),
                           (MyTheme["WindowText"].toArray())[1].toInt(),
                           (MyTheme["WindowText"].toArray())[2].toInt()));
                mypalette.setColor(QPalette::Base,
                                   QColor((MyTheme["Base"].toArray())[0].toInt(),
                                          (MyTheme["Base"].toArray())[1].toInt(),
                                          (MyTheme["Base"].toArray())[2].toInt()));
                mypalette.setColor(
                    QPalette::AlternateBase,
                    QColor((MyTheme["AlternateBase"].toArray())[0].toInt(),
                           (MyTheme["AlternateBase"].toArray())[1].toInt(),
                           (MyTheme["AlternateBase"].toArray())[2].toInt()));
                mypalette.setColor(
                    QPalette::ToolTipBase,
                    QColor((MyTheme["ToolTipBase"].toArray())[0].toInt(),
                           (MyTheme["ToolTipBase"].toArray())[1].toInt(),
                           (MyTheme["ToolTipBase"].toArray())[2].toInt()));
                mypalette.setColor(
                    QPalette::ToolTipText,
                    QColor((MyTheme["ToolTipText"].toArray())[0].toInt(),
                           (MyTheme["ToolTipText"].toArray())[1].toInt(),
                           (MyTheme["ToolTipText"].toArray())[2].toInt()));
                mypalette.setColor(QPalette::Text,
                                   QColor((MyTheme["Text"].toArray())[0].toInt(),
                                          (MyTheme["Text"].toArray())[1].toInt(),
                                          (MyTheme["Text"].toArray())[2].toInt()));
                mypalette.setColor(QPalette::Button,
                                   QColor((MyTheme["Button"].toArray())[0].toInt(),
                                          (MyTheme["Button"].toArray())[1].toInt(),
                                          (MyTheme["Button"].toArray())[2].toInt()));
                mypalette.setColor(
                    QPalette::BrightText,
                    QColor((MyTheme["BrightText"].toArray())[0].toInt(),
                           (MyTheme["BrightText"].toArray())[1].toInt(),
                           (MyTheme["BrightText"].toArray())[2].toInt()));
                mypalette.setColor(
                    QPalette::ButtonText,
                    QColor((MyTheme["ButtonText"].toArray())[0].toInt(),
                           (MyTheme["ButtonText"].toArray())[1].toInt(),
                           (MyTheme["ButtonText"].toArray())[2].toInt()));
                mypalette.setColor(QPalette::Highlight,
                                   QColor((MyTheme["Highlight"].toArray())[0].toInt(),
                                          (MyTheme["Highlight"].toArray())[1].toInt(),
                                          (MyTheme["Highlight"].toArray())[2].toInt()));
                mypalette.setColor(
                    QPalette::HighlightedText,
                    QColor((MyTheme["HighlightedText"].toArray())[0].toInt(),
                           (MyTheme["HighlightedText"].toArray())[1].toInt(),
                           (MyTheme["HighlightedText"].toArray())[2].toInt()));
                mypalette2 = mypalette;
            }
            SetStyleAndTheme(app, style, theme);
        }
    }
    fullpath = fileconfig;

    QFile advancedmodelsfile(advancedmodels);
    if (!advancedmodelsfile.exists() && ((argc > 1) || MACOS))
    {
        QFile file2(":/advancedmodels.js");
        QString str;
        file2.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream stream(&file2);
        str.append(stream.readAll());
        str.replace("DOTSYMBOL", dotsymbol.toStdString().c_str());

        QFile file(advancedmodels);
        if (!file.open(QIODevice::WriteOnly))
        {
            std::cerr << "Cannot open file for writing: "
                      << qPrintable(file.errorString()) << std::endl;
            return;
        }
        QTextStream out(&file);
        out << str << endl;
        file.close();
        file.copy(advancedmodels);
        QFile::setPermissions(advancedmodels,
                              QFileDevice::ReadOwner | QFileDevice::WriteOwner);
    }

    QFile mathmodfile(filecollection);
    if (!mathmodfile.exists() && ((argc > 1) || MACOS))
    {
        QFile file2(":/mathmodcollection.js");
        QString str;
        file2.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream stream(&file2);
        str.append(stream.readAll());
        str.replace("DOTSYMBOL", dotsymbol.toStdString().c_str());
        QFile file(filecollection);
        if (!file.open(QIODevice::WriteOnly))
        {
            std::cerr << "Cannot open file for writing: "
                      << qPrintable(file.errorString()) << std::endl;
            return;
        }
        QTextStream out(&file);
        out << str << endl;
        file.close();
        file.copy(filecollection);
        QFile::setPermissions(filecollection,
                              QFileDevice::ReadOwner | QFileDevice::WriteOwner);
    }
}
void Parametersoptions::on_save_clicked()
{
    QJsonDocument document;
    document.setObject(JConfig);

    QFile f(fullpath);
    if (f.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream t(&f);
        t << QString(document.toJson());
        f.close();
    }
}

void Parametersoptions::on_comboBox_2_activated(const QString &arg1)
{
    QJsonObject style = JConfig["Styles"].toObject();
    style["UsedStyle"] = arg1;
    JConfig["Styles"] = style;
}

void Parametersoptions::on_comboBox_3_activated(const QString &arg1)
{
    QJsonObject style = JConfig["Themes"].toObject();
    style["UsedTheme"] = arg1;
    JConfig["Themes"] = style;
    if (arg1 == "MyTheme")
        // ui.groupBox->setEnabled(true);
        ui.groupBox->show();
    else
        // ui.groupBox->setDisabled(true);
        ui.groupBox->hide();
}

void Parametersoptions::on_comboBox_activated(const QString &arg1)
{
    QPalette tmp;
    QJsonObject tmp1, MyTheme;
    tmp1 = JConfig["Themes"].toObject();
    MyTheme = tmp1["MyTheme"].toObject();

    if (arg1 == "Text")
    {
        tmp.setColor(QPalette::ButtonText,
                     QColor((MyTheme["Text"].toArray())[0].toInt(),
                            (MyTheme["Text"].toArray())[1].toInt(),
                            (MyTheme["Text"].toArray())[2].toInt()));
    }
    else if (arg1 == "BrightText")
    {
        tmp.setColor(QPalette::ButtonText,
                     QColor((MyTheme["BrightText"].toArray())[0].toInt(),
                            (MyTheme["BrightText"].toArray())[1].toInt(),
                            (MyTheme["BrightText"].toArray())[2].toInt()));
    }
    else if (arg1 == "ButtonText")
    {
        tmp.setColor(QPalette::ButtonText,
                     QColor((MyTheme["ButtonText"].toArray())[0].toInt(),
                            (MyTheme["ButtonText"].toArray())[1].toInt(),
                            (MyTheme["ButtonText"].toArray())[2].toInt()));
    }
    else if (arg1 == "Button")
    {
        tmp.setColor(QPalette::ButtonText,
                     QColor((MyTheme["Button"].toArray())[0].toInt(),
                            (MyTheme["Button"].toArray())[1].toInt(),
                            (MyTheme["Button"].toArray())[2].toInt()));
    }
    else if (arg1 == "Base")
    {
        tmp.setColor(QPalette::ButtonText,
                     QColor((MyTheme["Base"].toArray())[0].toInt(),
                            (MyTheme["Base"].toArray())[1].toInt(),
                            (MyTheme["Base"].toArray())[2].toInt()));
    }
    else if (arg1 == "AlternateBase")
    {
        tmp.setColor(QPalette::ButtonText,
                     QColor((MyTheme["AlternateBase"].toArray())[0].toInt(),
                            (MyTheme["AlternateBase"].toArray())[1].toInt(),
                            (MyTheme["AlternateBase"].toArray())[2].toInt()));
    }
    else if (arg1 == "Highlight")
    {
        tmp.setColor(QPalette::ButtonText,
                     QColor((MyTheme["Highlight"].toArray())[0].toInt(),
                            (MyTheme["Highlight"].toArray())[1].toInt(),
                            (MyTheme["Highlight"].toArray())[2].toInt()));
    }
    else if (arg1 == "HighlightedText")
    {
        tmp.setColor(QPalette::ButtonText,
                     QColor((MyTheme["HighlightedText"].toArray())[0].toInt(),
                            (MyTheme["HighlightedText"].toArray())[1].toInt(),
                            (MyTheme["HighlightedText"].toArray())[2].toInt()));
    }
    else if (arg1 == "ToolTipBase")
    {
        tmp.setColor(QPalette::ButtonText,
                     QColor((MyTheme["ToolTipBase"].toArray())[0].toInt(),
                            (MyTheme["ToolTipBase"].toArray())[1].toInt(),
                            (MyTheme["ToolTipBase"].toArray())[2].toInt()));
    }
    else if (arg1 == "ToolTipText")
    {
        tmp.setColor(QPalette::ButtonText,
                     QColor((MyTheme["ToolTipText"].toArray())[0].toInt(),
                            (MyTheme["ToolTipText"].toArray())[1].toInt(),
                            (MyTheme["ToolTipText"].toArray())[2].toInt()));
    }
    else if (arg1 == "WindowText")
    {
        tmp.setColor(QPalette::ButtonText,
                     QColor((MyTheme["WindowText"].toArray())[0].toInt(),
                            (MyTheme["WindowText"].toArray())[1].toInt(),
                            (MyTheme["WindowText"].toArray())[2].toInt()));
    }
    else if (arg1 == "Window")
    {
        tmp.setColor(QPalette::ButtonText,
                     QColor((MyTheme["Window"].toArray())[0].toInt(),
                            (MyTheme["Window"].toArray())[1].toInt(),
                            (MyTheme["Window"].toArray())[2].toInt()));
    }
    ui.ColorsButton->setPalette(tmp);
}

void Parametersoptions::onred_2valueChanged(int value)
{
    QString choice = ui.comboBox->currentText();
    QJsonArray tmp =
        ((JConfig["Themes"].toObject())["MyTheme"].toObject())[choice].toArray();
    tmp[0] = value;
    QJsonObject t1 = JConfig["Themes"].toObject();
    QJsonObject t2 = t1["MyTheme"].toObject();
    t2[choice] = tmp;
    t1["MyTheme"] = t2;
    JConfig["Themes"] = t1;
    on_comboBox_activated(choice);
}

void Parametersoptions::ongreen_2valueChanged(int value)
{
    QString choice = ui.comboBox->currentText();
    QJsonArray tmp =
        ((JConfig["Themes"].toObject())["MyTheme"].toObject())[choice].toArray();
    tmp[1] = value;
    QJsonObject t1 = JConfig["Themes"].toObject();
    QJsonObject t2 = t1["MyTheme"].toObject();
    t2[choice] = tmp;
    t1["MyTheme"] = t2;
    JConfig["Themes"] = t1;
    on_comboBox_activated(choice);
}

void Parametersoptions::onblue_2valueChanged(int value)
{
    QString choice = ui.comboBox->currentText();
    QJsonArray tmp =
        ((JConfig["Themes"].toObject())["MyTheme"].toObject())[choice].toArray();
    tmp[2] = value;
    QJsonObject t1 = JConfig["Themes"].toObject();
    QJsonObject t2 = t1["MyTheme"].toObject();
    t2[choice] = tmp;
    t1["MyTheme"] = t2;
    JConfig["Themes"] = t1;
    on_comboBox_activated(choice);
}

void Parametersoptions::on_TestConfig_clicked()
{
    if (JConfig["Themes"].isObject() && JConfig["Styles"].isObject())
    {
        QJsonObject tmp1, tmp2, MyTheme;
        tmp2 = JConfig["Styles"].toObject();
        QString style = tmp2["UsedStyle"].toString();

        tmp1 = JConfig["Themes"].toObject();
        QString theme = tmp1["UsedTheme"].toString();

        if (theme == "MyTheme")
        {
            MyTheme = tmp1["MyTheme"].toObject();
            mypalette.setColor(QPalette::Window,
                               QColor((MyTheme["Window"].toArray())[0].toInt(),
                                      (MyTheme["Window"].toArray())[1].toInt(),
                                      (MyTheme["Window"].toArray())[2].toInt()));
            mypalette.setColor(QPalette::WindowText,
                               QColor((MyTheme["WindowText"].toArray())[0].toInt(),
                                      (MyTheme["WindowText"].toArray())[1].toInt(),
                                      (MyTheme["WindowText"].toArray())[2].toInt()));
            mypalette.setColor(QPalette::Base,
                               QColor((MyTheme["Base"].toArray())[0].toInt(),
                                      (MyTheme["Base"].toArray())[1].toInt(),
                                      (MyTheme["Base"].toArray())[2].toInt()));
            mypalette.setColor(
                QPalette::AlternateBase,
                QColor((MyTheme["AlternateBase"].toArray())[0].toInt(),
                       (MyTheme["AlternateBase"].toArray())[1].toInt(),
                       (MyTheme["AlternateBase"].toArray())[2].toInt()));
            mypalette.setColor(QPalette::ToolTipBase,
                               QColor((MyTheme["ToolTipBase"].toArray())[0].toInt(),
                                      (MyTheme["ToolTipBase"].toArray())[1].toInt(),
                                      (MyTheme["ToolTipBase"].toArray())[2].toInt()));
            mypalette.setColor(QPalette::ToolTipText,
                               QColor((MyTheme["ToolTipText"].toArray())[0].toInt(),
                                      (MyTheme["ToolTipText"].toArray())[1].toInt(),
                                      (MyTheme["ToolTipText"].toArray())[2].toInt()));
            mypalette.setColor(QPalette::Text,
                               QColor((MyTheme["Text"].toArray())[0].toInt(),
                                      (MyTheme["Text"].toArray())[1].toInt(),
                                      (MyTheme["Text"].toArray())[2].toInt()));
            mypalette.setColor(QPalette::Button,
                               QColor((MyTheme["Button"].toArray())[0].toInt(),
                                      (MyTheme["Button"].toArray())[1].toInt(),
                                      (MyTheme["Button"].toArray())[2].toInt()));
            mypalette.setColor(QPalette::BrightText,
                               QColor((MyTheme["BrightText"].toArray())[0].toInt(),
                                      (MyTheme["BrightText"].toArray())[1].toInt(),
                                      (MyTheme["BrightText"].toArray())[2].toInt()));
            mypalette.setColor(QPalette::ButtonText,
                               QColor((MyTheme["ButtonText"].toArray())[0].toInt(),
                                      (MyTheme["ButtonText"].toArray())[1].toInt(),
                                      (MyTheme["ButtonText"].toArray())[2].toInt()));
            mypalette.setColor(QPalette::Highlight,
                               QColor((MyTheme["Highlight"].toArray())[0].toInt(),
                                      (MyTheme["Highlight"].toArray())[1].toInt(),
                                      (MyTheme["Highlight"].toArray())[2].toInt()));
            mypalette.setColor(
                QPalette::HighlightedText,
                QColor((MyTheme["HighlightedText"].toArray())[0].toInt(),
                       (MyTheme["HighlightedText"].toArray())[1].toInt(),
                       (MyTheme["HighlightedText"].toArray())[2].toInt()));
            mypalette2 = mypalette;
        }
        SetStyleAndTheme(*MainApp, style, theme);
    }
}
