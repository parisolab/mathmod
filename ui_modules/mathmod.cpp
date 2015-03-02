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
#include "mathmod.h"

static int TypeDrawin= 10;

MathMod::~MathMod()
{
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MathMod::MathMod(QWidget *parent, int maxtri, int maxpts, int gridmax)
    : QWidget(parent)
{
    ui.setupUi(this);
    xyzactivated = uvactivated = uvactivated4D= 1;
    (ui.glWidget)->memoryallocation(maxtri, maxpts, gridmax);
    (ui.glWidget)->calculateObject();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::keyPressEvent ( QKeyEvent *key)
{
    int button = key->key();
    if(button == Qt::Key_C )
        Parent->show();
    else
        (ui.glWidget)->keyPressEvent(key);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::resizeEvent( QResizeEvent  *e )
{
    (ui.glWidget)->resizeEvent(e);
    (ui.glWidget)->setFixedSize (e->size());
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::fill()
{
    (ui.glWidget)->FillOk();
    (ui.glWidget)->updateGL();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::iso_infos()
{
    (ui.glWidget)->infosOk();
    (ui.glWidget)->updateGL();
}


///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::smoothline()
{
    (ui.glWidget)->LocalScene.smoothline *= -1;
    /// For drawing Lines :
    if((ui.glWidget)->LocalScene.smoothline == 1)
    {
        glEnable (GL_LINE_SMOOTH);
        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint (GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
    }
    else
    {
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_BLEND);
    };

    updateGL();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::updateGL()
{
    (ui.glWidget)->updateGL();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::draw_norm_clicked()
{
    (ui.glWidget)->normOk();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::linecolumn_valueChanged( int cl)
{
    (ui.glWidget)->ParObjet->nb_licol       = cl;
    (ui.glWidget)->ParObjet->nb_colone  = (ui.glWidget)->nb_colone = cl;
    (ui.glWidget)->ParObjet->nb_ligne     = (ui.glWidget)->nb_ligne    = cl;
    if(uvactivated  == 1)
        ParametricSurfaceProcess(1);
    else
        (ui.glWidget)->updateGL();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::linecolumn_valueChanged_2( int cl)
{
    (ui.glWidget)->ParObjet->nb_licol       = cl;
    (ui.glWidget)->ParObjet->nb_colone  = (ui.glWidget)->nb_colone = cl;
    (ui.glWidget)->ParObjet->nb_ligne     = (ui.glWidget)->nb_ligne    = cl;
    if(uvactivated4D  == 1)
        ParametricSurfaceProcess(3);
    else
        (ui.glWidget)->updateGL();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::Initparametricpage()
{
    (ui.glWidget)->LocalScene.typedrawing = -1;
    //(ui.glWidget)->LocalScene.line = 1;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::xyzg_valueChanged( int cl)
{
    (ui.glWidget)->IsoObjet->nb_depth  = (ui.glWidget)->IsoObjet->nb_colon = (ui.glWidget)->IsoObjet->nb_ligne = cl;
    (ui.glWidget)-> isoline =(ui.glWidget)->isocolumn = (ui.glWidget)->isodepth = cl;
    // process the new surface
    if(xyzactivated  == 1)  ProcessNewIsoSurface( );
    else (ui.glWidget)->updateGL();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::xg_valueChanged( int cl)
{
    (ui.glWidget)->IsoObjet->nb_ligne = cl;
    (ui.glWidget)-> isoline = cl;
    // process the new surface
    if(xyzactivated  == 1)  ProcessNewIsoSurface( );
    else (ui.glWidget)->updateGL();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::yg_valueChanged( int cl)
{
    (ui.glWidget)->IsoObjet->nb_colon =  cl;
    (ui.glWidget)->isocolumn =  cl;
    // process the new surface
    if(xyzactivated  == 1)  ProcessNewIsoSurface( );
    else (ui.glWidget)->updateGL();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::zg_valueChanged( int cl)
{
    (ui.glWidget)->IsoObjet->nb_depth  = cl;
    (ui.glWidget)->isodepth = cl;
    // process the new surface
    if(xyzactivated  == 1)  ProcessNewIsoSurface( );
    else (ui.glWidget)->updateGL();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int MathMod::ParsePar()
{
    //Initparametricpage();
    stError = (ui.glWidget)->ParObjet->parse_expression();
    if(stError.iErrorIndex >= 0)
    {
        message.setTextFormat(Qt::RichText);
        int before, after;
        QString sortie = QString::fromStdString(stError.strError);
        if(sortie.length() > (stError.iErrorIndex +30))
            after = 30;
        else after = sortie.length() - stError.iErrorIndex;
        sortie.truncate(stError.iErrorIndex +after);
        if(stError.iErrorIndex-30 > 0)
            before = 30;
        else
            before = 0;
        sortie = sortie.remove(0,stError.iErrorIndex - before);
        sortie.replace("\t", " ");
        sortie.replace("\n", " ");
        sortie.insert(before, " <font size=14  color=#FF0033>Error => </font>");
        message.setText("Error at position: " + QString::number(stError.iErrorIndex) + "<br><br>" +
                        "..." + sortie + "..."
                       );
        message.adjustSize () ;
        message.exec();
        return -1;
    }
    return 1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::ParametricSurfaceProcess(int type)
{
    (type == 3) ? (ui.glWidget)->ParObjet->param4D =  1:
            (ui.glWidget)->ParObjet->param4D = -1;

    int result = ParsePar();
    if(result == -1) return;

    (ui.glWidget)->ParObjet->ParamBuild((ui.glWidget)->LocalScene.ArrayNorVer_localPt,
                                        (ui.glWidget)->LocalScene.ArrayNorVerExtra_localPt,
                                        (ui.glWidget)->LocalScene.PolyIndices_localPt,
                                        &((ui.glWidget)->LocalScene.PolyNumber),
                                        &(ui.glWidget)->LocalScene.VertxNumber,
                                        0,
                                        &((ui.glWidget)->LocalScene.componentsinfos),
                                        (ui.glWidget)->LocalScene.Typetriangles,
                                        (ui.glWidget)->LocalScene.WichPointVerifyCond,
                                        (ui.glWidget)->LocalScene.PolyIndices_localPtMin,
                                        &((ui.glWidget)->LocalScene.NbPolygnNbVertexPtMin)
                                       );
    (ui.glWidget)->LocalScene.typedrawing = -1;
    (ui.glWidget)->initializeGL();
    (ui.glWidget)->updateGL();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int MathMod::ParseIso()
{
    /// process the new surface
    stError = (ui.glWidget)->IsoObjet->ParserIso();
    if(stError.iErrorIndex >= 0)
    {
        message.setTextFormat(Qt::RichText);
        int before, after;
        QString sortie = QString::fromStdString(stError.strError);
        if(sortie.length() > (stError.iErrorIndex +30))
            after = 30;
        else after = sortie.length() - stError.iErrorIndex;
        sortie.truncate(stError.iErrorIndex +after);
        if(stError.iErrorIndex-30 > 0)
            before = 30;
        else
            before = 0;
        sortie = sortie.remove(0,stError.iErrorIndex - before);
        sortie.replace("\t", " ");
        sortie.replace("\n", " ");
        sortie.insert(before, " <font size=14  color=#FF0033>Error => </font>");
        message.setText("Error at position: " + QString::number(stError.iErrorIndex) + "<br><br>" +
                        "..." + sortie + "..."
                       );
        message.adjustSize () ;
        message.exec();
        return -1;
    }
    return 1;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::ProcessNewIsoSurface( )
{

    int result = ParseIso();
    if(result == -1) return;

    (ui.glWidget)->IsoObjet->IsoBuild(
        (ui.glWidget)->LocalScene.ArrayNorVer_localPt,
        (ui.glWidget)->LocalScene.PolyIndices_localPt,
        &(ui.glWidget)->LocalScene.PolyNumber,
        &((ui.glWidget)->LocalScene.VertxNumber),
        (ui.glWidget)->LocalScene.PolyIndices_localPtMin,
        &((ui.glWidget)->LocalScene.NbPolygnNbVertexPtMin),
        &((ui.glWidget)->LocalScene.componentsinfos),
        (ui.glWidget)->LocalScene.Typetriangles,
        (ui.glWidget)->LocalScene.WichPointVerifyCond);
    (ui.glWidget)->initializeGL();
    (ui.glWidget)->LocalScene.typedrawing = 1;
    (ui.glWidget)->updateGL();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::ProcessParisoSurface()
{
    /// process the new surface
    stError = (ui.glWidget)->IsoObjet->ParserIso();
    if(stError.iErrorIndex >= 0)
    {
        message.setTextFormat(Qt::RichText);
        int before, after;
        QString sortie = QString::fromStdString(stError.strError);
        if(sortie.length() > (stError.iErrorIndex +30))
            after = 30;
        else after = sortie.length() - stError.iErrorIndex;
        sortie.truncate(stError.iErrorIndex +after);
        if(stError.iErrorIndex-30 > 0)
            before = 30;
        else
            before = 0;
        sortie = sortie.remove(0,stError.iErrorIndex - before);
        sortie.replace("\t", " ");
        sortie.replace("\n", " ");
        sortie.insert(before, " <font size=14  color=#FF0033>Error ==> </font>");
        message.setText("Error at position: " + QString::number(stError.iErrorIndex) + "\n\n***********\n" +
                        "..." + sortie + "..."
                       );
        message.adjustSize () ;
        message.exec();
        return;
    }

    (ui.glWidget)->LocalScene.typedrawing = 11;

    (ui.glWidget)->IsoObjet->IsoBuild(
        (ui.glWidget)->LocalScene.ArrayNorVer_localPt,
        (ui.glWidget)->LocalScene.PolyIndices_localPt,
        &(ui.glWidget)->LocalScene.PolyNumberTmp1,
        &(ui.glWidget)->LocalScene.VertxNumberTmp1,
        (ui.glWidget)->LocalScene.PolyIndices_localPtMin,
        &((ui.glWidget)->LocalScene.NbPolygnNbVertexPtMin),
        &((ui.glWidget)->LocalScene.componentsinfos),
        (ui.glWidget)->LocalScene.Typetriangles,
        (ui.glWidget)->LocalScene.WichPointVerifyCond
    );


    stError = (ui.glWidget)->ParObjet->parse_expression();
    if(stError.iErrorIndex >= 0)
    {
        message.setTextFormat(Qt::RichText);
        int before, after;
        QString sortie = QString::fromStdString(stError.strError);
        if(sortie.length() > (stError.iErrorIndex +30))
            after = 30;
        else after = sortie.length() - stError.iErrorIndex;
        sortie.truncate(stError.iErrorIndex +after);
        if(stError.iErrorIndex-30 > 0)
            before = 30;
        else
            before = 0;
        sortie = sortie.remove(0,stError.iErrorIndex - before);
        sortie.replace("\t", " ");
        sortie.replace("\n", " ");
        sortie.insert(before, " <font size=14  color=#FF0033>Error => </font>");
        message.setText("Error at position: " + QString::number(stError.iErrorIndex) + "<br><br>" +
                        "..." + sortie + "..."
                       );
        message.adjustSize () ;
        message.exec();
        return;
    }

    (ui.glWidget)->ParObjet->ParamBuild(
        &((ui.glWidget)->LocalScene.ArrayNorVer_localPt[TypeDrawin*((ui.glWidget)->LocalScene.VertxNumberTmp1)]),
        (ui.glWidget)->LocalScene.ArrayNorVerExtra_localPt,
        &((ui.glWidget)->LocalScene.PolyIndices_localPt[(ui.glWidget)->LocalScene.PolyNumberTmp1]),
        &(ui.glWidget)->LocalScene.PolyNumberTmp2,
        &(ui.glWidget)->LocalScene.VertxNumberTmp2,
        (ui.glWidget)->LocalScene.VertxNumberTmp1,
        &((ui.glWidget)->LocalScene.componentsinfos),
        (ui.glWidget)->LocalScene.Typetriangles,
        (ui.glWidget)->LocalScene.WichPointVerifyCond,
        (ui.glWidget)->LocalScene.PolyIndices_localPtMin,
        &((ui.glWidget)->LocalScene.NbPolygnNbVertexPtMin)
    );

    (ui.glWidget)->LocalScene.PolyNumber = (ui.glWidget)->LocalScene.PolyNumberTmp1 + (ui.glWidget)->LocalScene.PolyNumberTmp2;
    (ui.glWidget)->LocalScene.VertxNumber= (ui.glWidget)->LocalScene.VertxNumberTmp1  + (ui.glWidget)->LocalScene.VertxNumberTmp2;

    (ui.glWidget)->initializeGL();
    (ui.glWidget)->updateGL();
}

//++++++++++++++++++++++++++++++++++++++++
void MathMod::slot_checkBox73_clicked()
{
    xyzactivated  *= -1;
    // process the new surface
    if(xyzactivated  == 1)
        ProcessNewIsoSurface();
}

//++++++++++++++++++++++++++++++++++++++++
void MathMod::slot_uv_clicked()
{
    uvactivated  *= -1;
    // process the new surface
    if(uvactivated  == 1)
        ParametricSurfaceProcess(1);
}

//++++++++++++++++++++++++++++++++++++++++
void MathMod::slot_uv4D_clicked()
{
    uvactivated4D  *= -1;
    // process the new surface
    if(uvactivated4D  == 1)
        ParametricSurfaceProcess(3);
}
//++++++++++++++++++++++++++++++++++++++++
void MathMod::slot_triangles_clicked()
{
    (ui.glWidget)->LocalScene.triangles *= -1;
    (ui.glWidget)->updateGL();
}

//++++++++++++++++++++++++++++++++++++++++
void MathMod::Mesh()
{
    (ui.glWidget)->LocalScene.mesh *= -1;
    (ui.glWidget)->updateGL();
}
