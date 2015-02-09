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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#include <QtGui>
#include <math.h>
#include "parametersoptions.h"


Parametersoptions::Parametersoptions(QWidget *parent)
    : QWidget(parent)
{
    ControlX=20;
    ControlY=20;
    GlwinX=575;
    GlwinY=20;
    ControlW=538;
    ControlH=700;
    GlwinW=780;
    GlwinH=700;
    MaxTri=2000000;
    MaxPt=1800000;
    MaxGrid=150;
    filecollection = "mathmodcollection.js";
    fileconfig       = "mathmodconfig.js";

    darkpalette.setColor(QPalette::Window, QColor(53,53,53));
    darkpalette.setColor(QPalette::WindowText, QColor(255,255,255));
    darkpalette.setColor(QPalette::Base, QColor(15,15,15));
    darkpalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkpalette.setColor(QPalette::ToolTipBase, QColor(255,255,255));
    darkpalette.setColor(QPalette::ToolTipText, QColor(255,255,255));
    darkpalette.setColor(QPalette::Text, QColor(255,255,255));
    darkpalette.setColor(QPalette::Button, QColor(53,53,53));
    darkpalette.setColor(QPalette::ButtonText, QColor(255,255,255));
    darkpalette.setColor(QPalette::BrightText, QColor(255, 0, 0));
    darkpalette.setColor(QPalette::Highlight, QColor(142,45,197).lighter());
    darkpalette.setColor(QPalette::HighlightedText, QColor(0,0,0));




    this->setWindowFlags( Qt::WindowStaysOnTopHint );
    ui.setupUi(this);
}

void Parametersoptions::slot_about_clicked()
{
    this->close();
}


void Parametersoptions::SetStyleAndTheme(QApplication & appli, QString style, QString theme)
{
    if(style != "Default")
        appli.setStyle(QStyleFactory::create(style));
    if(theme == "Dark")
    {
        appli.setPalette(darkpalette);
    }
    else if(theme == "MyTheme")
    {
        appli.setPalette(mypalette);
    }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void Parametersoptions::ReadJsonFile(QString JsonFile, QJsonObject & js)
{
    QJsonParseError err;
    QString sortie;

    QFile file1(JsonFile);
    if ( !file1.exists())
    {
        JsonFile = QFileDialog::getOpenFileName(0, QObject::tr("Open mathmodconfig.js File"),
                                                "",
                                                QObject::tr("Json (*.js)"));
    }

    QFile file(JsonFile);
    if (file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        QJsonDocument doc = QJsonDocument::fromJson(((file.readAll()).trimmed()).replace("\n","").replace("\t",""),&err);
        if (err.error)
        {
            QMessageBox message ;
            message.setWindowTitle("Error at : "+JsonFile);
            file.close();
            file.open( QIODevice::ReadOnly | QIODevice::Text );
            sortie = (file.readAll());
            int before, after;
            if(sortie.length() > (err.offset +30))
                after = 30;
            else after = sortie.length() - err.offset;
            sortie.truncate(err.offset +after);
            if(err.offset-30 > 0)
                before = 30;
            else
                before = 0;
            sortie = sortie.remove(0,err.offset-before);
            sortie.replace("\t", " ");
            sortie.replace("\n", " ");
            sortie.insert(before, " >>> Error <<< ");
            message.setText("Error : " + err.errorString() + " at position: " + QString::number(err.offset) + "\n\n***********\n" +
                            "..." + sortie + "..."
                           );
            message.adjustSize () ;
            message.exec();
            file.close();
            return ;
        }
        js = doc.object();
        file.close();
    }
    return;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void Parametersoptions::ReadCollectionFile(QString JsonFileName, QJsonObject & js)
{
    QJsonParseError err;
    QString sortie;

    QFile JsonFile(JsonFileName);
    if ( !JsonFile.exists())
    {
       QFile file2(":/mathmodcollection_empty.js");
       file2.copy(JsonFileName);
       QFile::setPermissions(JsonFileName, QFileDevice::WriteOther);
    }

    QFile file(JsonFileName);
    if (file.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        QJsonDocument doc = QJsonDocument::fromJson(((file.readAll()).trimmed()).replace("\n","").replace("\t",""),&err);
        if (err.error)
        {
            QMessageBox message ;
            message.setWindowTitle("Error at : "+JsonFileName);
            file.close();
            file.open( QIODevice::ReadOnly | QIODevice::Text );
            sortie = (file.readAll());
            int before, after;
            if(sortie.length() > (err.offset +30))
                after = 30;
            else after = sortie.length() - err.offset;
            sortie.truncate(err.offset +after);
            if(err.offset-30 > 0)
                before = 30;
            else
                before = 0;
            sortie = sortie.remove(0,err.offset-before);
            sortie.replace("\t", " ");
            sortie.replace("\n", " ");
            sortie.insert(before, " >>> Error <<< ");
            message.setText("Error : " + err.errorString() + " at position: " + QString::number(err.offset) + "\n\n***********\n" +
                            "..." + sortie + "..."
                           );
            message.adjustSize () ;
            message.exec();
            file.close();
            return ;
        }
        js = doc.object();
        file.close();
    }
    return;
}



void Parametersoptions::GuiUpdate()
{
    QJsonObject isoparam = (JConfig)["IsoParam"].toObject();
    //Grid
    int mg =    (isoparam)["MaxGrid"].toDouble();
    ui.maxgriLabel->setText("MaxGrid="+ QString::number(mg));
    ui.maxgri->setValue(mg);
    //Triangles
    mg = (isoparam)["MaxTri"].toDouble();
    ui.maxtriLabel->setText("MaxTri="+ QString::number(mg)+"M");
    ui.maxtri->setValue(mg);
    //Points
    mg = (isoparam)["MaxPt"].toDouble();
    ui.maxptLabel->setText("MaxPt="+ QString::number(mg)+"M");
    ui.maxpt->setValue(mg);
    //Styles:
    QString Style = ((JConfig["Styles"].toObject())["StyleUsed"].toString());
    ui.comboBox_2->setCurrentText(Style);
    //Theme:
    QString theme = ((JConfig["Themes"].toObject())["ThemeUsed"].toString());
    ui.comboBox_3->setCurrentText(theme);
    if(theme == "MyTheme")
        ui.groupBox->show();
    else
        ui.groupBox->hide();
}

void Parametersoptions::on_maxgri_valueChanged(int value)
{
    ui.maxgriLabel->setText("MaxGrid="+QString::number(value));
    QJsonObject tmp = JConfig["IsoParam"].toObject();
    tmp["MaxGrid"] = value;
    JConfig["IsoParam"]= tmp;
}

void Parametersoptions::on_maxtri_valueChanged(int value)
{
    ui.maxtriLabel->setText("MaxTri="+QString::number(value)+"M");
    int val = ui.maxpt->value();
    int MaxParametricGrid = value > val? sqrt(val)*10000.0 : sqrt(value)*10000.0;

    ui.MaxParametricGrid->setText("MaxParametricGrid = "+QString::number(MaxParametricGrid));

    QJsonObject tmp = JConfig["IsoParam"].toObject();
    tmp["MaxTri"] = value;
    JConfig["IsoParam"]= tmp;
}

void Parametersoptions::on_maxpt_valueChanged(int value)
{
    ui.maxptLabel->setText("MaxPt="+QString::number(value)+"M");

    int val = ui.maxtri->value();
    int MaxParametricGrid = value > val? sqrt(val)*1000.0 : sqrt(value)*1000.0;
    ui.MaxParametricGrid->setText("MaxParametricGrid = "+QString::number(MaxParametricGrid));

    QJsonObject tmp = JConfig["IsoParam"].toObject();
    tmp["MaxPt"] = value;
    JConfig["IsoParam"]= tmp;
}

void Parametersoptions::on_loadconfig_clicked()
{
    ReadJsonFile(fullpath , JConfig);
    GuiUpdate();
}

ListeModelTexture Parametersoptions::LoadCollectionModels(QJsonObject &Jcollection, jpariso &pariso, int argc)
{

    QFile fconllect(filecollection);
    if(fconllect.exists() && (argc >1))
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


    // Textures List:
    for(int i=0; i< array2.size(); i++)
    {
        if((array2[i].toObject())["Texture"].isObject())
        {
            jsobj = (array2[i].toObject())["Texture"].toObject();
            a = (jsobj)["Name"].toString();
            lst_2.append(a);
        }
    }
    lst_2.insert(0, "Textures List ("+QString::number(lst_2.count())+")");


    // Pigments List:
    for(int i=0; i< array3.size(); i++)
    {
        if((array3[i].toObject())["Pigment"].isObject())
        {
            jsobj = (array3[i].toObject())["Pigment"].toObject();
            a = (jsobj)["Name"].toString();
            lst_3.append(a);
        }
    }
    lst_3.insert(0, "PigmentsList ("+QString::number(lst_3.count())+")");


    for(int i=0; i< array.size(); i++)
    {
        if((array[i].toObject())["Iso3D"].isObject())
        {
            jiso newjiso;
            jsobj = (array[i].toObject())["Iso3D"].toObject();
            newjiso.read( jsobj );
            pariso.JIso.append(newjiso);
            a = (jsobj)["Name"].toArray()[0].toString();
            lst.append(a);
        }
        else if((array[i].toObject())["Param3D"].isObject())
        {
            jpar newjpar;
            jsobj = ((array[i].toObject())["Param3D"].toObject());
            newjpar.read( jsobj );
            pariso.JPar.append(newjpar);
            a = ( jsobj )["Name"].toArray()[0].toString();
            lst.append(a);
        }
        else if((array[i].toObject())["Param4D"].isObject())
        {
            jpar newjpar;
            jsobj = ((array[i].toObject())["Param4D"].toObject());
            newjpar.read( jsobj );
            pariso.JPar.append(newjpar);
            a = ( jsobj )["Name"].toArray()[0].toString();
            lst.append(a);
        }
    }

    lst.insert(0, "Examples ("+QString::number(lst.count())+")");

    ListeModelTexture str;
    str.listeModels     = lst;
    str.listeTextures   = lst_2;
    str.listePigments = lst_3;
    return str;
}

void Parametersoptions::SaveToFile_CurentMathModel(QJsonObject  CurrentJsonObject)
{
    QString fileName = QFileDialog::getSaveFileName(this,
                       tr("Save to file"), "", tr("JSON Files (*.js)"));
    if(fileName != "")
    {
        QJsonObject collection;
        ReadCollectionFile(fileName, collection);
        QJsonDocument document;
        if(collection["MathModels"].isArray())
        {
            QJsonArray array = collection["MathModels"].toArray();
            array.append(CurrentJsonObject);
            collection["MathModels"] = array;
            document.setObject(collection);
            QFile f( fileName );
            if ( f.open(QIODevice::ReadWrite | QIODevice::Text) )
            {
                QTextStream t( &f );
                QString tmp = QString (document.toJson()).toLatin1();
                t << tmp.toUtf8();
                f.close();
            }
        }
    }
}

void Parametersoptions::LoadConfig(QApplication &app,int argc, char *argv[])
{
    if(argc >1)
    {
        QString argv1 = QString(argv[1]);
        if(!argv1.endsWith("/"))
            argv1 +="/";
        filecollection = argv1 + filecollection;
        fileconfig       = argv1 + fileconfig;
    }

    QFile mathmodfile(filecollection);
    if(!mathmodfile.exists() && (argc >1))
    {
        QFile file2(":/mathmodcollection.js");
        file2.copy(filecollection);
        QFile::setPermissions(filecollection, QFileDevice::WriteOther);
    }

    QFile mathmodfileconfig(fileconfig);
    if(!mathmodfileconfig.exists() && (argc >1))
    {
        QFile file3(":/mathmodconfig.js");
        file3.copy(fileconfig);
        QFile::setPermissions(fileconfig, QFileDevice::WriteOther);
    }


    QFile fconf(fileconfig);
    if(fconf.exists())
       ReadJsonFile(fileconfig, JConfig);
    else
       ReadJsonFile(":/mathmodconfig.js", JConfig);

    {
        if(JConfig["IsoParam"].isObject())
        {
            IsoParam = JConfig["IsoParam"].toObject();
            if((IsoParam)["MaxTri"].isDouble())
                MaxTri     = (IsoParam)["MaxTri"].toDouble() * 1000000;
            if((IsoParam)["MaxPt"].isDouble())
                MaxPt     = (IsoParam)["MaxPt"].toDouble() * 1000000;
            if((IsoParam)["MaxGrid"].isDouble())
                MaxGrid = (IsoParam)["MaxGrid"].toDouble();
        }

        QJsonObject tmp;
        if(JConfig["WindowPosition"].isObject())
        {
            tmp = JConfig["WindowPosition"].toObject();
            ControlX = tmp["ControlX"].toDouble();
            ControlY = tmp["ControlY"].toDouble();
            GlwinX = tmp["GlwinX"].toDouble();
            GlwinY = tmp["GlwinY"].toDouble();
        }

        if(JConfig["WindowSize"].isObject())
        {
            tmp = JConfig["WindowSize"].toObject();
            ControlW = tmp["ControlW"].toDouble();
            ControlH = tmp["ControlH"].toDouble();
            GlwinW = tmp["GlwinW"].toDouble();
            GlwinH = tmp["GlwinH"].toDouble();
        }

        if(JConfig["Themes"].isObject() and JConfig["Styles"].isObject() )
        {
            QJsonObject tmp1, tmp2, MyTheme;
            tmp2= JConfig["Styles"].toObject();
            QString style = tmp2["StyleUsed"].toString();

            tmp1 = JConfig["Themes"].toObject();
            QString theme = tmp1["ThemeUsed"].toString();


            if(theme == "MyTheme")
            {
                MyTheme = tmp1["MyTheme"].toObject();
                mypalette.setColor(QPalette::Window, QColor((MyTheme["Window"].toArray())[0].toDouble(), (MyTheme["Window"].toArray())[1].toDouble(), (MyTheme["Window"].toArray())[2].toDouble()));
                mypalette.setColor(QPalette::WindowText, QColor((MyTheme["WindowText"].toArray())[0].toDouble(), (MyTheme["WindowText"].toArray())[1].toDouble(), (MyTheme["WindowText"].toArray())[2].toDouble()));
                mypalette.setColor(QPalette::Base, QColor((MyTheme["Base"].toArray())[0].toDouble(), (MyTheme["Base"].toArray())[1].toDouble(), (MyTheme["Base"].toArray())[2].toDouble()));
                mypalette.setColor(QPalette::AlternateBase, QColor((MyTheme["AlternateBase"].toArray())[0].toDouble(), (MyTheme["AlternateBase"].toArray())[1].toDouble(), (MyTheme["AlternateBase"].toArray())[2].toDouble()));
                mypalette.setColor(QPalette::ToolTipBase, QColor((MyTheme["ToolTipBase"].toArray())[0].toDouble(), (MyTheme["ToolTipBase"].toArray())[1].toDouble(), (MyTheme["ToolTipBase"].toArray())[2].toDouble()));
                mypalette.setColor(QPalette::ToolTipText, QColor((MyTheme["ToolTipText"].toArray())[0].toDouble(), (MyTheme["ToolTipText"].toArray())[1].toDouble(), (MyTheme["ToolTipText"].toArray())[2].toDouble()));
                mypalette.setColor(QPalette::Text, QColor((MyTheme["Text"].toArray())[0].toDouble(), (MyTheme["Text"].toArray())[1].toDouble(), (MyTheme["Text"].toArray())[2].toDouble()));
                mypalette.setColor(QPalette::Button, QColor((MyTheme["Button"].toArray())[0].toDouble(), (MyTheme["Button"].toArray())[1].toDouble(), (MyTheme["Button"].toArray())[2].toDouble()));
                mypalette.setColor(QPalette::BrightText, QColor((MyTheme["BrightText"].toArray())[0].toDouble(), (MyTheme["BrightText"].toArray())[1].toDouble(), (MyTheme["BrightText"].toArray())[2].toDouble()));
                mypalette.setColor(QPalette::ButtonText, QColor((MyTheme["ButtonText"].toArray())[0].toDouble(), (MyTheme["ButtonText"].toArray())[1].toDouble(), (MyTheme["ButtonText"].toArray())[2].toDouble()));
                mypalette.setColor(QPalette::Highlight, QColor((MyTheme["Highlight"].toArray())[0].toDouble(), (MyTheme["Highlight"].toArray())[1].toDouble(), (MyTheme["Highlight"].toArray())[2].toDouble()));
                mypalette.setColor(QPalette::HighlightedText, QColor((MyTheme["HighlightedText"].toArray())[0].toDouble(), (MyTheme["HighlightedText"].toArray())[1].toDouble(), (MyTheme["HighlightedText"].toArray())[2].toDouble()));
                mypalette2 = mypalette;
            }
            SetStyleAndTheme(app, style, theme);
        }
    }
    fullpath = fileconfig;
}
void Parametersoptions::on_save_clicked()
{
    QJsonDocument document;
    document.setObject(JConfig);

    QFile f( fullpath );
    if ( f.open(QIODevice::ReadWrite | QIODevice::Text) )
    {
        QTextStream t( &f );
        t << QString (document.toJson());
        f.close();
    }
}

void Parametersoptions::on_comboBox_2_activated(const QString &arg1)
{
    QJsonObject style = JConfig["Styles"].toObject();
    style["StyleUsed"] = arg1;
    JConfig["Styles"] = style;
}

void Parametersoptions::on_comboBox_3_activated(const QString &arg1)
{
    QJsonObject style = JConfig["Themes"].toObject();
    style["ThemeUsed"] = arg1;
    JConfig["Themes"] = style;
    if(arg1 == "MyTheme")
        //ui.groupBox->setEnabled(true);
        ui.groupBox->show();
    else
        //ui.groupBox->setDisabled(true);
        ui.groupBox->hide();
}

void Parametersoptions::on_comboBox_activated(const QString &arg1)
{
    QPalette tmp;
    QJsonObject tmp1, MyTheme;
    tmp1 = JConfig["Themes"].toObject();
    MyTheme = tmp1["MyTheme"].toObject();

    if(arg1 == "Text")
    {
        tmp.setColor(QPalette::ButtonText, QColor((MyTheme["Text"].toArray())[0].toDouble(), (MyTheme["Text"].toArray())[1].toDouble(), (MyTheme["Text"].toArray())[2].toDouble()));
    }
    else if(arg1 == "BrightText")
    {
        tmp.setColor(QPalette::ButtonText, QColor((MyTheme["BrightText"].toArray())[0].toDouble(), (MyTheme["BrightText"].toArray())[1].toDouble(), (MyTheme["BrightText"].toArray())[2].toDouble()));
    }
    else if(arg1 == "ButtonText")
    {
        tmp.setColor(QPalette::ButtonText, QColor((MyTheme["ButtonText"].toArray())[0].toDouble(), (MyTheme["ButtonText"].toArray())[1].toDouble(), (MyTheme["ButtonText"].toArray())[2].toDouble()));
    }
    else if(arg1 == "Button")
    {
        tmp.setColor(QPalette::ButtonText, QColor((MyTheme["Button"].toArray())[0].toDouble(), (MyTheme["Button"].toArray())[1].toDouble(), (MyTheme["Button"].toArray())[2].toDouble()));
    }
    else if(arg1 == "Base")
    {
        tmp.setColor(QPalette::ButtonText, QColor((MyTheme["Base"].toArray())[0].toDouble(), (MyTheme["Base"].toArray())[1].toDouble(), (MyTheme["Base"].toArray())[2].toDouble()));
    }
    else if(arg1 == "AlternateBase")
    {
        tmp.setColor(QPalette::ButtonText, QColor((MyTheme["AlternateBase"].toArray())[0].toDouble(), (MyTheme["AlternateBase"].toArray())[1].toDouble(), (MyTheme["AlternateBase"].toArray())[2].toDouble()));
    }
    else if(arg1 == "Highlight")
    {
        tmp.setColor(QPalette::ButtonText, QColor((MyTheme["Highlight"].toArray())[0].toDouble(), (MyTheme["Highlight"].toArray())[1].toDouble(), (MyTheme["Highlight"].toArray())[2].toDouble()));
    }
    else if(arg1 == "HighlightedText")
    {
        tmp.setColor(QPalette::ButtonText, QColor((MyTheme["HighlightedText"].toArray())[0].toDouble(), (MyTheme["HighlightedText"].toArray())[1].toDouble(), (MyTheme["HighlightedText"].toArray())[2].toDouble()));
    }
    else if(arg1 == "ToolTipBase")
    {
        tmp.setColor(QPalette::ButtonText, QColor((MyTheme["ToolTipBase"].toArray())[0].toDouble(), (MyTheme["ToolTipBase"].toArray())[1].toDouble(), (MyTheme["ToolTipBase"].toArray())[2].toDouble()));
    }
    else if(arg1 == "ToolTipText")
    {
        tmp.setColor(QPalette::ButtonText, QColor((MyTheme["ToolTipText"].toArray())[0].toDouble(), (MyTheme["ToolTipText"].toArray())[1].toDouble(), (MyTheme["ToolTipText"].toArray())[2].toDouble()));
    }
    else if(arg1 == "WindowText")
    {
        tmp.setColor(QPalette::ButtonText, QColor((MyTheme["WindowText"].toArray())[0].toDouble(), (MyTheme["WindowText"].toArray())[1].toDouble(), (MyTheme["WindowText"].toArray())[2].toDouble()));
    }
    else if(arg1 == "Window")
    {
        tmp.setColor(QPalette::ButtonText, QColor((MyTheme["Window"].toArray())[0].toDouble(), (MyTheme["Window"].toArray())[1].toDouble(), (MyTheme["Window"].toArray())[2].toDouble()));
    }
    ui.ColorsButton->setPalette(tmp);
}

void Parametersoptions::on_red_2_valueChanged(int value)
{
    QString choice = ui.comboBox->currentText();
    QJsonArray tmp = ((JConfig["Themes"].toObject())["MyTheme"].toObject())[choice].toArray();
    tmp[0] = value;
    QJsonObject t1 = JConfig["Themes"].toObject();
    QJsonObject t2 = t1["MyTheme"].toObject();
    t2[choice] = tmp;
    t1["MyTheme"] = t2;
    JConfig["Themes"] = t1;
    on_comboBox_activated(choice);
}

void Parametersoptions::on_green_2_valueChanged(int value)
{
    QString choice = ui.comboBox->currentText();
    QJsonArray tmp = ((JConfig["Themes"].toObject())["MyTheme"].toObject())[choice].toArray();
    tmp[1] = value;
    QJsonObject t1 = JConfig["Themes"].toObject();
    QJsonObject t2 = t1["MyTheme"].toObject();
    t2[choice] = tmp;
    t1["MyTheme"] = t2;
    JConfig["Themes"] = t1;
    on_comboBox_activated(choice);
}

void Parametersoptions::on_blue_2_valueChanged(int value)
{
    QString choice = ui.comboBox->currentText();
    QJsonArray tmp = ((JConfig["Themes"].toObject())["MyTheme"].toObject())[choice].toArray();
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
    if(JConfig["Themes"].isObject() and JConfig["Styles"].isObject() )
    {
        QJsonObject tmp1, tmp2, MyTheme;
        tmp2= JConfig["Styles"].toObject();
        QString style = tmp2["StyleUsed"].toString();

        tmp1 = JConfig["Themes"].toObject();
        QString theme = tmp1["ThemeUsed"].toString();


        if(theme == "MyTheme")
        {
            MyTheme = tmp1["MyTheme"].toObject();
            mypalette.setColor(QPalette::Window, QColor((MyTheme["Window"].toArray())[0].toDouble(), (MyTheme["Window"].toArray())[1].toDouble(), (MyTheme["Window"].toArray())[2].toDouble()));
            mypalette.setColor(QPalette::WindowText, QColor((MyTheme["WindowText"].toArray())[0].toDouble(), (MyTheme["WindowText"].toArray())[1].toDouble(), (MyTheme["WindowText"].toArray())[2].toDouble()));
            mypalette.setColor(QPalette::Base, QColor((MyTheme["Base"].toArray())[0].toDouble(), (MyTheme["Base"].toArray())[1].toDouble(), (MyTheme["Base"].toArray())[2].toDouble()));
            mypalette.setColor(QPalette::AlternateBase, QColor((MyTheme["AlternateBase"].toArray())[0].toDouble(), (MyTheme["AlternateBase"].toArray())[1].toDouble(), (MyTheme["AlternateBase"].toArray())[2].toDouble()));
            mypalette.setColor(QPalette::ToolTipBase, QColor((MyTheme["ToolTipBase"].toArray())[0].toDouble(), (MyTheme["ToolTipBase"].toArray())[1].toDouble(), (MyTheme["ToolTipBase"].toArray())[2].toDouble()));
            mypalette.setColor(QPalette::ToolTipText, QColor((MyTheme["ToolTipText"].toArray())[0].toDouble(), (MyTheme["ToolTipText"].toArray())[1].toDouble(), (MyTheme["ToolTipText"].toArray())[2].toDouble()));
            mypalette.setColor(QPalette::Text, QColor((MyTheme["Text"].toArray())[0].toDouble(), (MyTheme["Text"].toArray())[1].toDouble(), (MyTheme["Text"].toArray())[2].toDouble()));
            mypalette.setColor(QPalette::Button, QColor((MyTheme["Button"].toArray())[0].toDouble(), (MyTheme["Button"].toArray())[1].toDouble(), (MyTheme["Button"].toArray())[2].toDouble()));
            mypalette.setColor(QPalette::BrightText, QColor((MyTheme["BrightText"].toArray())[0].toDouble(), (MyTheme["BrightText"].toArray())[1].toDouble(), (MyTheme["BrightText"].toArray())[2].toDouble()));
            mypalette.setColor(QPalette::ButtonText, QColor((MyTheme["ButtonText"].toArray())[0].toDouble(), (MyTheme["ButtonText"].toArray())[1].toDouble(), (MyTheme["ButtonText"].toArray())[2].toDouble()));
            mypalette.setColor(QPalette::Highlight, QColor((MyTheme["Highlight"].toArray())[0].toDouble(), (MyTheme["Highlight"].toArray())[1].toDouble(), (MyTheme["Highlight"].toArray())[2].toDouble()));
            mypalette.setColor(QPalette::HighlightedText, QColor((MyTheme["HighlightedText"].toArray())[0].toDouble(), (MyTheme["HighlightedText"].toArray())[1].toDouble(), (MyTheme["HighlightedText"].toArray())[2].toDouble()));
            mypalette2 = mypalette;
        }
        SetStyleAndTheme(*MainApp, style, theme);
    }
}
