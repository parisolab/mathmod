/***************************************************************************
 *   Copyright (C) 2014 by Abderrahman Taha                                *
 *                                                                         *
 *                                                                         *
 *   This program is free software;you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation;either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY;without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program;if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/
#include "ParisoMathObject.h"
#include <qmessagebox.h>


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
ParisoMathObject::ParisoMathObject()
{
    NbIsoStruct = NbParamStruct = 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
ParisoMathObject::~ParisoMathObject()
{
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void ParisoMathObject::ReadJsonFile(QString JsonFile, QJsonObject & js)
{
    QJsonParseError err;
    QString sortie;

    QFile file1(JsonFile);
    if ( !file1.exists())
    {
        JsonFile = QFileDialog::getOpenFileName(0, QObject::tr("Open mathmodcollection.js File"),
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
QStringList ParisoMathObject::LoadScript (QString filename)
{
    QString line ="",  tmp="";
    int i;
    QFile file( filename );
    if ( file.open( QIODevice::ReadOnly ) )
    {
        QTextStream stream( &file );
        while ( !stream.atEnd() )
        {
            line = (stream.readLine());
            if(!line.contains("}"))
                tmp += line+"\n";
            else
            {
                i = line.indexOf("}");
                tmp += line.left(i+1)+"\n";
                RegisterScript(tmp);
                tmp = line.right(i)+"\n";
            }
        }
        file.close();
    }
    QStringList liste;
    liste << "Examples ("+ QString::number(NbParamStruct + NbIsoStruct) +")";
    for(i=0; i<NbParamStruct; i++)
        liste << ParamTable[i].name;

    for(i=0; i<NbIsoStruct; i++)
        liste << IsoTable[i].name;

    return liste;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
QStringList ParisoMathObject::ParObject ()
{
    QStringList liste;
    for(int i=0; i<NbParamStruct; i++)
        liste << ParamTable[i].name;
    return liste;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
QStringList ParisoMathObject::IsoObject()
{
    QStringList liste;
    for(int i=0; i<NbIsoStruct; i++)
        liste << IsoTable[i].name;
    return liste;
}

//++++++++++++++++++++++++++++++++++
void ParisoMathObject::RegisterScript (QString script)
{
    if(script.contains("Iso3D"))
    {
        IsoTable[NbIsoStruct].text   = script;
        IsoTable[NbIsoStruct].index = NbIsoStruct;
        MapIsoTable (script, NbIsoStruct);
        NbIsoStruct++;
    }
    else
    {
        ParamTable[NbParamStruct].text   = script;
        ParamTable[NbParamStruct].index = NbParamStruct;
        MapParamTable (script, NbParamStruct);
        NbParamStruct++;
    }
}

//++++++++++++++++++++++++++++++++++
int ParisoMathObject::FindIsoStruct (QString choice)
{
    int i;
    for(i=0; i<1000; i++)
    {
        if(IsoTable[i].name == choice)
            return i;
    }
    return -1;
}

//++++++++++++++++++++++++++++++++++
int ParisoMathObject::FindParamStruct (QString choice)
{
    int i;
    for(i=0; i<1000; i++)
    {
        if(ParamTable[i].name == choice)
            return i;
    }
    return -1;
}

//++++++++++++++++++++++++++++++++++
QString   ParisoMathObject::MapFunction (QString script, QString F)
{
    int i, j;
    i = script.indexOf(F);
    j = script.indexOf   ("]", i);
    script.truncate(j);
    script.remove(0, i+F.length());
    script.replace("]", "");
    return script;
}

//++++++++++++++++++++++++++++++++++
void   ParisoMathObject::MapBondary (QString script, QString B)
{
    int i, j;
    i = script.indexOf(B);
    j = script.indexOf   ("]", i);
    script.truncate(j);
    script.remove(0, i+3);
    i=script.indexOf(",");
    QString tmp=script;
    tmp.truncate(i);
    if(B == "[u,")
    {
        CurrentParamStruct.umax = script.remove(0,i+1);
        CurrentParamStruct.umin  = tmp;
    }
    else if(B == "[v,")
    {
        CurrentParamStruct.vmax = script.remove(0,i+1);
        CurrentParamStruct.vmin  = tmp;
    }
    else if(B == "[x,")
    {
        CurrentIsoStruct.xmax = script.remove(0,i+1);
        CurrentIsoStruct.xmin  = tmp;
    }
    else if(B == "[y,")
    {
        CurrentIsoStruct.ymax = script.remove(0,i+1);
        CurrentIsoStruct.ymin  = tmp;
    }
    else if(B == "[z,")
    {
        CurrentIsoStruct.zmax = script.remove(0,i+1);
        CurrentIsoStruct.zmin  = tmp;
    }
}

//++++++++++++++++++++++++++++++++++
void   ParisoMathObject::MapBondary (QString script, QString B, int index)
{
    int i, j;
    i = script.indexOf(B);
    j = script.indexOf   ("]", i);
    script.truncate(j);
    script.remove(0, i+3);
    i=script.indexOf(",");
    QString tmp=script;
    tmp.truncate(i);
    if(B == "[u,")
    {
        ParamTable[index].umax = script.remove(0,i+1);
        ParamTable[index].umin  = tmp;
    }
    else if(B == "[v,")
    {
        ParamTable[index].vmax = script.remove(0,i+1);
        ParamTable[index].vmin  = tmp;
    }
    else if(B == "[x,")
    {
        IsoTable[index].xmax = script.remove(0,i+1);
        IsoTable[index].xmin  = tmp;
    }
    else if(B == "[y,")
    {
        IsoTable[index].ymax = script.remove(0,i+1);
        IsoTable[index].ymin  = tmp;
    }
    else if(B == "[z,")
    {
        IsoTable[index].zmax = script.remove(0,i+1);
        IsoTable[index].zmin  = tmp;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++
void ParisoMathObject::MapIsoTable (QString script, int i)
{
    IsoTable[i].text    = script;
    script.replace(" ","");
    script.replace("\n","");
    IsoTable[i].name               = MapFunction (script, "[Name,");
    IsoTable[i].Component    = MapFunction (script, "[Component,");
    IsoTable[i].Const              = MapFunction (script, "[Const,");
    IsoTable[i].Varu                = MapFunction (script, "[Varu,");
    IsoTable[i].Funct               = MapFunction (script, "[Funct,");
    IsoTable[i].fxyz                  = MapFunction (script, "[fxyz,");
    IsoTable[i].Grid                 = MapFunction (script, "[Grid,");
    MapBondary (script, "[x,", i);
    MapBondary (script, "[y,", i);
    MapBondary (script, "[z,", i);
}

//++++++++++++++++++++++++++++++++++++++++++++
void ParisoMathObject::MapParamTable (QString script, int i)
{
    ParamTable[i].text    = script;
    script.replace(" ","");
    script.replace("\n","");
    ParamTable[i].name                  = MapFunction (script, "[Name,");
    ParamTable[i].Component       = MapFunction (script, "[Component,");
    ParamTable[i].Grid                    = MapFunction (script, "[Grid,");
    ParamTable[i].Const                 = MapFunction (script, "[Const,");
    ParamTable[i].Varu                   = MapFunction (script, "[Varu,");
    ParamTable[i].Cnd                   = MapFunction (script, "[Cnd,");
    ParamTable[i].Funct                 = MapFunction (script, "[Funct,");
    ParamTable[i].fx                        = MapFunction (script, "[fx,");
    ParamTable[i].fy                        = MapFunction (script, "[fy,");
    ParamTable[i].fz                        = MapFunction (script, "[fz,");
    MapBondary (script, "[u,", i);
    MapBondary (script, "[v,", i);
}

//++++++++++++++++++++++++++++++++++++++++++++
int ParisoMathObject::LookForIsosurfaceEquation(QString choix)
{
    for(int i =0; i<NbIsoStruct; i++)
    {
        if(IsoTable[i].name == choix)
            return i;
    }
    return(-1);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
int ParisoMathObject::LookForParametricEquation(QString choix)
{
    for(int i =0; i<NbParamStruct; i++)
    {
        if(ParamTable[i].name == choix)
            return i;
    }
    return(-1);
}
