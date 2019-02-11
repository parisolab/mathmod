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
#include "mathmod.h"

MathMod::~MathMod()
{
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MathMod::MathMod(QWidget *parent, uint maxtri, uint maxpts, uint gridmax,
                 uint NbComponent,uint NbVariables,uint NbConstantes,
                 uint NbDefinedFunctions,uint NbTextures,int NbSliders,int NbSliderValues,
                 uint nbthreads, uint initGrid, uint FactX, uint FactY, uint FactZ)
    : QWidget(parent)
{
    ui.setupUi(this);
    xyzactivated = uvactivated = uvactivated4D= 1;
    if((ui.glWidget)->memoryallocation(maxtri, maxpts, gridmax, NbComponent, NbVariables, NbConstantes,
                                       NbDefinedFunctions, NbTextures, NbSliders, NbSliderValues,
                                       nbthreads, initGrid, FactX, FactY, FactZ)!=1)
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
void MathMod::linecolumn_valueupdate( int cl)
{
    (ui.glWidget)->ParObjetThread->ParObjet->Vgrid = (ui.glWidget)->Vgrid =
    (ui.glWidget)->ParObjetThread->ParObjet->Ugrid  = (ui.glWidget)->Ugrid    = uint(cl);

    (ui.glWidget)->ParObjetThread->ParObjet->masterthread->Ugrid =
        (ui.glWidget)->ParObjetThread->ParObjet->masterthread->Vgrid = uint(cl);

    for(uint nbthreads=0; nbthreads<(ui.glWidget)->ParObjetThread->ParObjet->WorkerThreadsNumber-1; nbthreads++)
    {
        (ui.glWidget)->ParObjetThread->ParObjet->workerthreads[nbthreads].Ugrid =
            (ui.glWidget)->ParObjetThread->ParObjet->workerthreads[nbthreads].Vgrid = uint(cl);
    }
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::line_valueupdate( int cl)
{
    (ui.glWidget)->ParObjetThread->ParObjet->Ugrid  = (ui.glWidget)->Ugrid =

    (ui.glWidget)->ParObjetThread->ParObjet->masterthread->Ugrid = uint(cl);

    for(uint nbthreads=0; nbthreads<(ui.glWidget)->ParObjetThread->ParObjet->WorkerThreadsNumber-1; nbthreads++)
    {
        (ui.glWidget)->ParObjetThread->ParObjet->workerthreads[nbthreads].Ugrid = uint(cl);
    }
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::column_valueupdate( int cl)
{
    (ui.glWidget)->ParObjetThread->ParObjet->Vgrid = (ui.glWidget)->Vgrid =
    (ui.glWidget)->ParObjetThread->ParObjet->masterthread->Vgrid = uint(cl);

    for(uint nbthreads=0; nbthreads<(ui.glWidget)->ParObjetThread->ParObjet->WorkerThreadsNumber-1; nbthreads++)
    {
        (ui.glWidget)->ParObjetThread->ParObjet->workerthreads[nbthreads].Vgrid = uint(cl);
    }
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::linecolumn_valueChanged( int cl)
{
    linecolumn_valueupdate(cl);
    if(uvactivated  == 1)
        ParametricSurfaceProcess(1);
    else
        (ui.glWidget)->update();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::line_valueChanged( int cl)
{
    line_valueupdate(cl);
    if(uvactivated  == 1)
        ParametricSurfaceProcess(1);
    else
        (ui.glWidget)->update();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::column_valueChanged( int cl)
{
    column_valueupdate(cl);
    if(uvactivated  == 1)
        ParametricSurfaceProcess(1);
    else
        (ui.glWidget)->update();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::linecolumn_valueChanged_2( int cl)
{
    linecolumn_valueupdate(cl);
    if(uvactivated4D  == 1)
        ParametricSurfaceProcess(3);
    else
        (ui.glWidget)->update();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::Initparametricpage()
{
    (ui.glWidget)->LocalScene.typedrawing = -1;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::xyzg_valueupdate(int cl)
{
    (ui.glWidget)->IsoObjetThread->IsoObjet->masterthread->Zgrid  =
        (ui.glWidget)->IsoObjetThread->IsoObjet->masterthread->Ygrid  =
            (ui.glWidget)->IsoObjetThread->IsoObjet->masterthread->Xgrid  = uint(cl);

    (ui.glWidget)->IsoObjetThread->IsoObjet->Zgrid  =
        (ui.glWidget)->IsoObjetThread->IsoObjet->Ygrid  =
            (ui.glWidget)->IsoObjetThread->IsoObjet->Xgrid  = uint(cl);

    (ui.glWidget)->Xgrid   =
        (ui.glWidget)->Ygrid =
            (ui.glWidget)->Zgrid  = cl;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::xyzg_valueChanged(int cl)
{
    xyzg_valueupdate(cl);
    // process the new surface
    if(xyzactivated  == 1)  ProcessNewIsoSurface( );
    else (ui.glWidget)->update();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::xg_valueChanged(int cl)
{
    xyzg_valueupdate(cl);
    // process the new surface
    if(xyzactivated  == 1)  ProcessNewIsoSurface( );
    else (ui.glWidget)->update();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::yg_valueChanged(int cl)
{
    xyzg_valueupdate(cl);
    // process the new surface
    if(xyzactivated  == 1)  ProcessNewIsoSurface( );
    else (ui.glWidget)->update();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::zg_valueChanged( int cl)
{
    xyzg_valueupdate(cl);
    // process the new surface
    if(xyzactivated  == 1)  ProcessNewIsoSurface( );
    else (ui.glWidget)->update();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int MathMod::ParsePar()
{
    stError = (ui.glWidget)->ParObjetThread->ParObjet->masterthread->parse_expression();
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
        (ui.glWidget)->ParObjetThread->ParObjet->ThreadParsersCopy();
    return 1;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void MathMod::ParametricSurfaceProcess(int type)
{
    if(!(ui.glWidget)->ParObjetThread->ParObjet->isRunning())
    {
        if(type == 3)
        {
            (ui.glWidget)->ParObjetThread->ParObjet->masterthread->param4D =  1;
            (ui.glWidget)->ParObjetThread->ParObjet->param4D =  1;
        }
        else
        {
            (ui.glWidget)->ParObjetThread->ParObjet->masterthread->param4D = -1;
            (ui.glWidget)->ParObjetThread->ParObjet->param4D = -1;
        }

        int result = ParsePar();
        if(result == -1) return;
        (ui.glWidget)->LocalScene.typedrawing = -1;
        (ui.glWidget)->ParObjetThread->ParObjet->LocalScene = &((ui.glWidget)->LocalScene);
        connect((ui.glWidget)->ParObjetThread->ParObjet, SIGNAL(finished()), (ui.glWidget), SLOT(UpdateGL()), Qt::UniqueConnection);
        (ui.glWidget)->ParObjetThread->ParObjet->start(QThread::LowPriority);
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int MathMod::ParseIso()
{
    stError = (ui.glWidget)->IsoObjetThread->IsoObjet->masterthread->ParserIso();
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
        (ui.glWidget)->IsoObjetThread->IsoObjet->ThreadParsersCopy();
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
    /// process the new surface
    stError = (ui.glWidget)->IsoObjetThread->IsoObjet->masterthread->ParserIso();
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
        //for(int nbthreds=1; nbthreds < maxnbthreads ; nbthreds++)
        //(ui.glWidget)->IsoObjetThread->IsoObjet->workerthreads[nbthreds].ParserIso();
        /*
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
        */
        stError = (ui.glWidget)->ParObjetThread->ParObjet->masterthread->parse_expression();
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
        (ui.glWidget)->ParObjetThread->ParObjet->ThreadParsersCopy();
    /*
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
        */
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
        (ui.glWidget)->IsoObjetThread->IsoObjet->UpdateThredsNumber(uint(thr[0]));
        (ui.glWidget)->ParObjetThread->ParObjet->UpdateThredsNumber(uint(thr[0]));
    }
}

//++++++++++++++++++++++++++++++++++++++++
void MathMod::updateGLshininess(int shin)
{
    (ui.glWidget)->LocalScene.shininess=shin;
    (ui.glWidget)->update();
}
