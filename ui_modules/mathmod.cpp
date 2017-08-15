/***************************************************************************
 *   Copyright (C) 2017 by Abderrahman Taha                                *
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
    if((ui.glWidget)->memoryallocation(maxtri, maxpts, gridmax)!=1)
        //(ui.glWidget)->calculateObject();
        //else
        exit(0);
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
    (ui.glWidget)->update();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::iso_infos()
{
    (ui.glWidget)->infosOk();
    (ui.glWidget)->update();
}

///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::smoothline()
{
    (ui.glWidget)->smoothline();
    (ui.glWidget)->update();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::updateGL()
{
    (ui.glWidget)->update();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::draw_norm_clicked()
{
    (ui.glWidget)->normOk();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::frames_clicked()
{
    (ui.glWidget)->FramesShot();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::linecolumn_valueChanged( int cl)
{
    (ui.glWidget)->ParObjetThread->ParObjet->nb_colone = (ui.glWidget)->nb_colone = cl;
    (ui.glWidget)->ParObjetThread->ParObjet->nb_ligne  = (ui.glWidget)->nb_ligne    = cl;

    for(int nbthreads=0; nbthreads<(ui.glWidget)->ParObjetThread->ParObjet->WorkerThreadsNumber; nbthreads++)
    {
        (ui.glWidget)->ParObjetThread->ParObjet->workerthreads[nbthreads].nb_ligne =
        (ui.glWidget)->ParObjetThread->ParObjet->workerthreads[nbthreads].nb_colone = cl;
    }

    if(uvactivated  == 1)
        ParametricSurfaceProcess(1);
    else
        (ui.glWidget)->update();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::linecolumn_valueChanged_2( int cl)
{
    (ui.glWidget)->ParObjetThread->ParObjet->nb_colone = (ui.glWidget)->nb_colone = cl;
    (ui.glWidget)->ParObjetThread->ParObjet->nb_ligne  = (ui.glWidget)->nb_ligne    = cl;
    if(uvactivated4D  == 1)
        ParametricSurfaceProcess(3);
    else
        (ui.glWidget)->update();
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
    int maxnbthreads = (ui.glWidget)->IsoObjetThread->IsoObjet->WorkerThreadsNumber;
    for(int nbthreds=0; nbthreds < maxnbthreads ; nbthreds++)
        (ui.glWidget)->IsoObjetThread->IsoObjet->workerthreads[nbthreds].nb_depth  = (ui.glWidget)->IsoObjetThread->IsoObjet->workerthreads[nbthreds].nb_colon = (ui.glWidget)->IsoObjetThread->IsoObjet->workerthreads[nbthreds].nb_ligne = cl;
    (ui.glWidget)->IsoObjetThread->IsoObjet->nb_depth  = (ui.glWidget)->IsoObjetThread->IsoObjet->nb_colon = (ui.glWidget)->IsoObjetThread->IsoObjet->nb_ligne = cl;
    (ui.glWidget)-> isoline =(ui.glWidget)->isocolumn = (ui.glWidget)->isodepth = cl;
    // process the new surface
    if(xyzactivated  == 1)  ProcessNewIsoSurface( );
    else (ui.glWidget)->update();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::xg_valueChanged( int cl)
{
    int maxnbthreads = (ui.glWidget)->IsoObjetThread->IsoObjet->WorkerThreadsNumber;
    for(int nbthreds=0; nbthreds < maxnbthreads ; nbthreds++)
        (ui.glWidget)->IsoObjetThread->IsoObjet->workerthreads[nbthreds].nb_ligne = cl;
    (ui.glWidget)->IsoObjetThread->IsoObjet->nb_ligne = cl;
    (ui.glWidget)-> isoline = cl;
    // process the new surface
    if(xyzactivated  == 1)  ProcessNewIsoSurface( );
    else (ui.glWidget)->update();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::yg_valueChanged( int cl)
{
    int maxnbthreads = (ui.glWidget)->IsoObjetThread->IsoObjet->WorkerThreadsNumber;
    for(int nbthreds=0; nbthreds < maxnbthreads ; nbthreds++)
        (ui.glWidget)->IsoObjetThread->IsoObjet->workerthreads[nbthreds].nb_colon =  cl;
    (ui.glWidget)->IsoObjetThread->IsoObjet->nb_colon =  cl;
    (ui.glWidget)->isocolumn =  cl;
    // process the new surface
    if(xyzactivated  == 1)  ProcessNewIsoSurface( );
    else (ui.glWidget)->update();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::zg_valueChanged( int cl)
{
    int maxnbthreads = (ui.glWidget)->IsoObjetThread->IsoObjet->WorkerThreadsNumber;
    for(int nbthreds=0; nbthreds < maxnbthreads ; nbthreds++)
        (ui.glWidget)->IsoObjetThread->IsoObjet->workerthreads[nbthreds].nb_depth  = cl;
    (ui.glWidget)->IsoObjetThread->IsoObjet->nb_depth  = cl;
    (ui.glWidget)->isodepth = cl;
    // process the new surface
    if(xyzactivated  == 1)  ProcessNewIsoSurface( );
    else (ui.glWidget)->update();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int MathMod::ParsePar()
{
    int maxnbthreads = (ui.glWidget)->IsoObjetThread->IsoObjet->WorkerThreadsNumber;
    stError = (ui.glWidget)->ParObjetThread->ParObjet->workerthreads[0].parse_expression();
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
    else
        for(int nbthreds=1; nbthreds < maxnbthreads ; nbthreds++)
            (ui.glWidget)->ParObjetThread->ParObjet->workerthreads[nbthreds].parse_expression();
        //(ui.glWidget)->ParObjetThread->ParObjet->DeepThreadCopy2((ui.glWidget)->ParObjetThread->ParObjet->workerthreads);
    return 1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::ParametricSurfaceProcess(int type)
{
    int maxnbthreads = (ui.glWidget)->IsoObjetThread->IsoObjet->WorkerThreadsNumber;
    if(type == 3)
    {
        for(int nbthreds=0; nbthreds < maxnbthreads ; nbthreds++)
            (ui.glWidget)->ParObjetThread->ParObjet->workerthreads[nbthreds].param4D =  1;
        (ui.glWidget)->ParObjetThread->ParObjet->param4D =  1;
    }
    else
    {
        for(int nbthreds=0; nbthreds < maxnbthreads ; nbthreds++)
            (ui.glWidget)->ParObjetThread->ParObjet->workerthreads[nbthreds].param4D = -1;
        (ui.glWidget)->ParObjetThread->ParObjet->param4D = -1;
    }
    /*
    int result = ParsePar();
    if(result == -1) return;
*/
    if(!(ui.glWidget)->ParObjetThread->ParObjet->isRunning())
    {
        int result = ParsePar();
        if(result == -1) return;
        (ui.glWidget)->LocalScene.typedrawing = -1;
        (ui.glWidget)->ParObjetThread->ParObjet->LocalScene = &((ui.glWidget)->LocalScene);
        connect((ui.glWidget)->ParObjetThread->ParObjet, SIGNAL(finished()), (ui.glWidget), SLOT(UpdateGL()), Qt::UniqueConnection);
        (ui.glWidget)->ParObjetThread->ParObjet->start(QThread::LowPriority);
    }
    /*
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
    (ui.glWidget)->initialize_GL();
    (ui.glWidget)->update();
    */
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int MathMod::ParseIso()
{
    /// process the new surface
    int maxnbthreads = (ui.glWidget)->IsoObjetThread->IsoObjet->WorkerThreadsNumber;
    stError = (ui.glWidget)->IsoObjetThread->IsoObjet->workerthreads[0].ParserIso();
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
    else
        for(int nbthreds=1; nbthreds < maxnbthreads ; nbthreds++)
            (ui.glWidget)->IsoObjetThread->IsoObjet->workerthreads[nbthreds].ParserIso();
    return 1;
}
/*
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::UpdateFrame()
{
    //(ui.glWidget)->LocalScene.typedrawing = 1;
    (ui.glWidget)->initialize_GL();
    (ui.glWidget)->update();
}
*/
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::ProcessNewIsoSurface()
{
    if(!(ui.glWidget)->IsoObjetThread->IsoObjet->isRunning())
    {
        int result = ParseIso();
        if(result == -1) return;
        (ui.glWidget)->LocalScene.typedrawing = 1;
        (ui.glWidget)->IsoObjetThread->IsoObjet->LocalScene = &((ui.glWidget)->LocalScene);
        connect((ui.glWidget)->IsoObjetThread->IsoObjet, SIGNAL(finished()), (ui.glWidget), SLOT(UpdateGL()), Qt::UniqueConnection);
        (ui.glWidget)->IsoObjetThread->IsoObjet->start(QThread::LowPriority);
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::ProcessParisoSurface()
{
    int maxnbthreads = (ui.glWidget)->IsoObjetThread->IsoObjet->WorkerThreadsNumber;
    /// process the new surface
    stError = (ui.glWidget)->IsoObjetThread->IsoObjet->workerthreads[0].ParserIso();
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
    else
        for(int nbthreds=1; nbthreds < maxnbthreads ; nbthreds++)
            (ui.glWidget)->IsoObjetThread->IsoObjet->workerthreads[nbthreds].ParserIso();

    (ui.glWidget)->LocalScene.typedrawing = 11;

    (ui.glWidget)->IsoObjetThread->IsoObjet->IsoBuild(
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

    stError = (ui.glWidget)->ParObjetThread->ParObjet->workerthreads[0].parse_expression();
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
    else
        for(int nbthreds=1; nbthreds < maxnbthreads ; nbthreds++)
            (ui.glWidget)->ParObjetThread->ParObjet->workerthreads[nbthreds].parse_expression();

    (ui.glWidget)->ParObjetThread->ParObjet->ParamBuild(
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

    (ui.glWidget)->initialize_GL();
    (ui.glWidget)->update();
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
    (ui.glWidget)->update();
}

//++++++++++++++++++++++++++++++++++++++++
void MathMod::Mesh()
{
    (ui.glWidget)->LocalScene.mesh *= -1;
    (ui.glWidget)->update();
}

//++++++++++++++++++++++++++++++++++++++++
void MathMod::activateteGlCacheOption(bool state)
{
    (ui.glWidget)->LocalScene.activateGlCache= state;
}

//++++++++++++++++++++++++++++++++++++++++
void MathMod::updateGLspectrale(float *spec)
{
    (ui.glWidget)->LocalScene.specReflection[0]= spec[0];
    (ui.glWidget)->LocalScene.specReflection[1]= spec[1];
    (ui.glWidget)->LocalScene.specReflection[2]= spec[2];
    (ui.glWidget)->LocalScene.specReflection[3]= spec[3];
    (ui.glWidget)->update();
}

//++++++++++++++++++++++++++++++++++++++++
void MathMod::updateThreads(int *thr)
{
    (ui.glWidget)->LocalScene.threads[0]= thr[0];
    (ui.glWidget)->LocalScene.threads[1]= thr[1];
    (ui.glWidget)->LocalScene.threads[2]= thr[2];
    if(thr[0] > 0)
    {
        (ui.glWidget)->IsoObjetThread->IsoObjet->UpdateThredsNumber(thr[0]);
        (ui.glWidget)->ParObjetThread->ParObjet->UpdateThredsNumber(thr[0]);
    }
}

//++++++++++++++++++++++++++++++++++++++++
void MathMod::updateGLshininess(int shin)
{
    (ui.glWidget)->LocalScene.shininess=shin;
    (ui.glWidget)->update();
}
