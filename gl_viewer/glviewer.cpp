/***************************************************************************
 *   Copyright (C) 2018 by Abderrahman Taha                                *
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

#include "viewer.cpp"

#define BUFFER_OFFSET(i) ((float *)(i))


static void DrawParametric (ObjectProperties *scene)
{
    float frontcl[4], backcl[4];
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_POLYGON_OFFSET_FILL);

    if(scene->componentsinfos.ThereisRGBA)
        glEnable(GL_COLOR_MATERIAL);

    glPolygonOffset(scene->polyfactor, scene->polyunits);
    for(uint i=0; i< scene->componentsinfos.NbParametric; i++)
    {
        if(!scene->componentsinfos.ThereisRGBA)
        {
            for(int j=0; j<4; j++)
            {
                frontcl[j]=scene->frontcolsPar[4*i+j];
                backcl[j]=scene->backcolsPar[4*i+j];
            }
            glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE,  backcl);
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frontcl);
        }
        if(scene->componentsinfos.ThereisCND)
        {
            if(scene->componentsinfos.DFTrianglesVerifyCND)
                glDrawElements(
                    GL_TRIANGLES,
                    3*(scene->componentsinfos.NbTrianglesVerifyCND),
                    GL_UNSIGNED_INT,
                    &(scene->PolyIndices_localPt[0])
                );

            if(scene->componentsinfos.DFTrianglesNotVerifyCND)
                glDrawElements(
                    GL_TRIANGLES,
                    3*(scene->componentsinfos.NbTrianglesNotVerifyCND),
                    GL_UNSIGNED_INT,
                    &(scene->PolyIndices_localPt[3*scene->componentsinfos.NbTrianglesVerifyCND])
                );
        }
        else
            glDrawElements(
                GL_TRIANGLES,
                3*scene->componentsinfos.Parametricpositions[3*i+1],
                GL_UNSIGNED_INT,
                &(scene->PolyIndices_localPt[scene->componentsinfos.Parametricpositions[3*i]])
            );
    }

    if(scene->componentsinfos.ThereisRGBA)
        glDisable(GL_COLOR_MATERIAL);

    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

static void drawCube(float x)
{
    float  longX = x*(difX/difMaximum), longY= x*(difY/difMaximum), longZ= x*(difZ/difMaximum);
    glColor4f (0.8, 0.8, 0.8, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(1);

    glBegin(GL_QUADS);
    glVertex3f(-longX,-longY ,-longZ);
    glVertex3f(longX, -longY, -longZ);
    glVertex3f(longX, longY, -longZ);
    glVertex3f(-longX, longY, -longZ);

    glVertex3f(-longX, -longY, -longZ);
    glVertex3f(-longX, -longY, longZ);
    glVertex3f(-longX, longY, longZ);
    glVertex3f(-longX, longY, -longZ);

    glVertex3f(-longX, -longY, -longZ);
    glVertex3f(-longX, -longY, longZ);
    glVertex3f(longX, -longY, longZ);
    glVertex3f(longX, -longY, -longZ);

    glEnd();
    glLineWidth(1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // this line should be put elsewhere where it's missing

    //X
    glColor3f (1.0, 0.0, 0.0);
    glRasterPos3f(longX, -longY, longZ+60);
    glCallLists(QString::number(maxx,'g',  3).size(),GL_UNSIGNED_BYTE,QString::number(maxx,'g',  3).toLatin1());

    glColor3f (1.0, 0.0, 0.0);
    glRasterPos3f(-longX, -longY, longZ+60);
    glCallLists(QString::number(minx,'g',  3).size(),GL_UNSIGNED_BYTE,QString::number(minx,'g',  3).toLatin1());

    //Y
    glColor3f (0.0, 1.0, 0.0);
    glRasterPos3f(longX+100, longY, -longZ);
    glCallLists(QString::number(maxy,'g',  3).size(),GL_UNSIGNED_BYTE,QString::number(maxy,'g',  3).toLatin1());

    glColor3f (0.0, 1.0, 0.0);
    glRasterPos3f(longX+100, -longY,-longZ);
    glCallLists(QString::number(miny,'g',  3).size(),GL_UNSIGNED_BYTE,QString::number(miny,'g',  3).toLatin1());

    //Z
    glColor3f (0.4, 0.4, 1.0);
    glRasterPos3f(longX+60, -longY-60, longZ);
    glCallLists(QString::number(maxz,'g',  3).size(),GL_UNSIGNED_BYTE,QString::number(maxz,'g',  3).toLatin1());

    glColor3f (0.4, 0.4, 1.0);
    glRasterPos3f(longX+60, -longY-60,-longZ);
    glCallLists(QString::number(minz,'g',  3).size(),GL_UNSIGNED_BYTE,QString::number(minz,'g',  3).toLatin1());
}

static void DrawIso (ObjectProperties *scene)
{
    float frontcl[4], backcl[4];
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_POLYGON_OFFSET_FILL);

    if(scene->componentsinfos.ThereisRGBA)
        glEnable(GL_COLOR_MATERIAL);

    glPolygonOffset(scene->polyfactor, scene->polyunits);

    for(uint i=0; i< scene->componentsinfos.NbIso; i++)
    {
        {
            if(!scene->componentsinfos.ThereisRGBA)
            {
                for(int j=0; j<4; j++)
                {
                    frontcl[j]=scene->frontcols[4*i+j];
                    backcl[j]=scene->backcols[4*i+j];
                }
                glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, backcl);
                glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, frontcl);
            }


            if(scene->componentsinfos.ThereisCND)
            {
                if(scene->componentsinfos.DFTrianglesVerifyCND)
                    glDrawElements(
                        GL_TRIANGLES,
                        3*(scene->componentsinfos.NbTrianglesVerifyCND),
                        GL_UNSIGNED_INT,
                        &(scene->PolyIndices_localPt[0])
                    );

                if(scene->componentsinfos.DFTrianglesNotVerifyCND)
                    glDrawElements(
                        GL_TRIANGLES,
                        3*(scene->componentsinfos.NbTrianglesNotVerifyCND),
                        GL_UNSIGNED_INT,
                        &(scene->PolyIndices_localPt[3*scene->componentsinfos.NbTrianglesVerifyCND])
                    );
            }
            else
            {
                glDrawElements(
                    GL_TRIANGLES,
                    3*scene->componentsinfos.IsoPositions[2*i+1],
                    GL_UNSIGNED_INT,
                    &(scene->PolyIndices_localPt[scene->componentsinfos.IsoPositions[2*i]])
                );
            }
        }
    }
    if(scene->componentsinfos.ThereisRGBA)
        glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_POLYGON_OFFSET_FILL);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
}

void OpenGlWidget::axeOk()
{
    LocalScene.axe *= -1;
    update();
}

void OpenGlWidget::normOk()
{
    LocalScene.norm *= -1;
    update();
}

void OpenGlWidget::infosOk()
{
    LocalScene.infos *= -1;
    update();
}

void OpenGlWidget::smoothline()
{
    LocalScene.smoothline *= -1;
    /// For drawing Lines :
    if(LocalScene.smoothline == 1)
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

    update();
}

void OpenGlWidget::boundingboxOk()
{
    LocalScene.boundingbox *= -1;
}

GLuint fontOffset=0;
void makeRasterFont()
{
    GLuint i;
    if(fontOffset < 128)
    {
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        fontOffset = glGenLists (128);

        for (i = 30; i < 127; i++)
        {
            glNewList(i+fontOffset, GL_COMPILE);
            glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, rasters[i-30]);
            glEndList();
        }
    }
}

void InitFont()
{
    makeRasterFont();
}

void OpenGlWidget::run()
{
}

bool OpenGlWidget::timeractif()
{
    return(LocalScene.anim == 1);
}

void OpenGlWidget::stoptimer()
{
    timer->stop();
    update();
}

void OpenGlWidget::starttimer()
{
    timer->start( latence);
}

void OpenGlWidget::restarttimer(int newlatence)
{
    latence = newlatence;
    if ( LocalScene.anim == 1)
    {
        timer->stop();
        timer->start( latence);
    }
}

void OpenGlWidget::VBOmemoryallocation()
{
    /*
    static int stat=0;
    static uint previous=0;

    if(stat ==0)
    {
    glDeleteBuffersARB(1, &LocalScene.vboId_ArrayNorVer_localPt);
    glDeleteBuffersARB(1, &LocalScene.vboId_PolyIndices_localPt);
    LocalScene.vboId_ArrayNorVer_localPt = LocalScene.vboId_PolyIndices_localPt = 0;

    glGenBuffersARB(1, &LocalScene.vboId_ArrayNorVer_localPt);
    glBindBufferARB(GL_ARRAY_BUFFER_ARB, LocalScene.vboId_ArrayNorVer_localPt);
    glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(float)*10*LocalScene.VertxNumber,LocalScene.ArrayNorVer_localPt, GL_STATIC_DRAW_ARB);


    glGenBuffersARB(1, &LocalScene.vboId_PolyIndices_localPt);
    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, LocalScene.vboId_PolyIndices_localPt);
    glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof(uint)*4*LocalScene.PolyNumber/3, LocalScene.PolyIndices_localPt, GL_STATIC_DRAW_ARB);

    glBindBufferARB(GL_ARRAY_BUFFER_ARB, LocalScene.vboId_ArrayNorVer_localPt);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(4, GL_FLOAT, sizeof(float)*10, BUFFER_OFFSET(0));   //The starting point of texcoords, 24 bytes away

    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer(GL_FLOAT, sizeof(float)*10, BUFFER_OFFSET(16));   //The starting point of normals, 12 bytes away

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(float)*10, BUFFER_OFFSET(28));   //The starting point of the VBO, for the vertices

    glBindBufferARB(GL_ELEMENT_ARRAY_BUFFER_ARB, LocalScene.vboId_PolyIndices_localPt);
    stat +=1;
    previous = LocalScene.VertxNumber;
    }

    else
    {

    if(LocalScene.VertxNumber > previous)
    {
        glBufferDataARB(GL_ARRAY_BUFFER_ARB, sizeof(float)*10*LocalScene.VertxNumber,LocalScene.ArrayNorVer_localPt, GL_STATIC_DRAW_ARB);
        previous = LocalScene.VertxNumber;
    }
    else
        glBufferSubDataARB(GL_ARRAY_BUFFER_ARB,0, sizeof(float)*10*LocalScene.VertxNumber,LocalScene.ArrayNorVer_localPt);

    glBufferDataARB(GL_ELEMENT_ARRAY_BUFFER_ARB, sizeof(uint)*4*LocalScene.PolyNumber/3, LocalScene.PolyIndices_localPt, GL_STATIC_DRAW_ARB);

    }
    */
}

void OpenGlWidget::startRendering()
{
    glt.start();
}

void OpenGlWidget::stopRendering()
{
    glt.stop();
    glt.wait();
}

void OpenGlWidget::resizeEvent(QResizeEvent *evt)
{
    glPushMatrix();
    glt.resizeViewport(evt->size());
    glPopMatrix();
}

void OpenGlWidget::closeEvent(QCloseEvent *evt)
{
    stopRendering();
    QGLWidget::closeEvent(evt);
}

void OpenGlWidget::anim()
{
    LocalScene.anim *= -1;
    if (LocalScene.anim == 1)
        timer->start( latence);
    else if(LocalScene.morph == -1)
        stoptimer();
}

void OpenGlWidget::morph()
{
    LocalScene.morph *= -1;
    FistTimecalibrate *= -1;

    if(LocalScene.typedrawing == 1)
    {
        //Isosurfaces:
        IsoObjetThread->IsoObjet->masterthread->morph_activated = LocalScene.morph;
        for(uint nbthreads=0; nbthreads< IsoObjetThread->IsoObjet->WorkerThreadsNumber-1; nbthreads++)
            IsoObjetThread->IsoObjet->workerthreads[nbthreads].morph_activated = LocalScene.morph;
        IsoObjetThread->IsoObjet->IsoMorph();
    }
    else if(LocalScene.typedrawing == -1)
    {
        //Parametric surfaces:
        ParObjetThread->ParObjet->masterthread->activeMorph = LocalScene.morph;
        for(uint nbthreads=0; nbthreads< ParObjetThread->ParObjet->WorkerThreadsNumber-1; nbthreads++)
            ParObjetThread->ParObjet->workerthreads[nbthreads].activeMorph = LocalScene.morph;
        ParObjetThread->ParObjet->ParMorph();
    }

    if (LocalScene.morph == 1)
        timer->start( latence);
    else if(LocalScene.anim == -1)
        stoptimer();
}

void OpenGlWidget::keyPressEvent ( QKeyEvent * e )
{
    int key = e->key();
    switch(key)
    {
    case Qt::Key_A :
        glt.anim();
        break;
    case Qt::Key_P :
        glt.morph();
        initbox();
        break;
    }
    glt.update();
}

void OpenGlWidget::resizeGL( int newwidth, int newheight)
{
    Wresult = newwidth;
    Hresult = newheight;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, newwidth, newheight);
    float k=6;
    glFrustum(-newwidth/k, newwidth/k, -newheight/k, newheight/k, 250.0, 3000.0 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef( 0.0, 0, -1000.0 );
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
OpenGlWidget::OpenGlWidget( QWidget *parent)
    : QGLWidget( parent),
      glt(this)
{
    setAutoBufferSwap(true);
    static int NBGlWindow = 0;
    PerlinNoise = new ImprovedNoise(4., 4., 4.);

    latence = 10;
    val1 = val2 = val3 = 0.0;
    Vgrid = Ugrid = 50;
    CutV = CutU = 0;
    Xgrid = Ygrid = Zgrid = 40;
    CutX = CutY = CutZ = 0;
    IDGlWindow        = NBGlWindow;
    LocalScene.VertxNumber      = 0;
    FramesDir = "/home";
    hauteur_fenetre=700;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    NBGlWindow++;
}

void OpenGlWidget::infosok()
{
    LocalScene.infos *= -1;
}

void OpenGlWidget::FillOk()
{
    LocalScene.fill *= -1;
    update();
}

void OpenGlWidget::PrintInfos()
{
    (LocalScene.typedrawing == 1) ?
    nbl = QString::number(Xgrid-CutX)+"x"+QString::number(Ygrid-CutY)+"x"+QString::number(Zgrid-CutZ) :
          nbl = QString::number(Ugrid-CutU)+"x"+QString::number(Vgrid-CutV)+" = "+QString::number((Ugrid-CutU)*(Vgrid-CutV));
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,Wresult, Hresult, 0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    if ( LocalScene.infosdetails[0] ==1)
    {
        glColor3f (0.0, 1.0, 0.0);
        glRasterPos2i(10, 20);
        glCallLists(strlen("Grid = "),
                    GL_UNSIGNED_BYTE,
                    (GLubyte *)"Grid = ");
        glColor3f (1., 0.0, 0.);
        glRasterPos2i(80,20);
        glCallLists(nbl.size(),GL_UNSIGNED_BYTE,nbl.toLatin1());
    }
    if ( LocalScene.infosdetails[1] ==1)
    {
        glColor3f (0.0, 1.0, 0.0);
        glRasterPos2i(10, 40);
        glCallLists(strlen("Poly = "),
                    GL_UNSIGNED_BYTE,
                    (GLubyte *)"Poly = ");
        glColor3f (1.0, 0.0, 0.0);
        glRasterPos2i(80, 40);
        glCallLists(QString::number(LocalScene.PolyNumber/3).size(),
                    GL_UNSIGNED_BYTE,
                    QString::number(LocalScene.PolyNumber/3).toLatin1()) ;
    }
    if ( LocalScene.infosdetails[2] ==1)
    {
        if (LocalScene.typedrawing == 1)
        {
            glColor3f (0.0, 1.0, 0.0);
            glRasterPos2i(10, 60);
            glCallLists(strlen("Vertx= "),
                        GL_UNSIGNED_BYTE,
                        (GLubyte *)"Vertx= ");
            glColor3f (1.0, 0.0, 0.0);
            glRasterPos2i(80, 60);
            glCallLists(QString::number(LocalScene.VertxNumber).size(),
                        GL_UNSIGNED_BYTE,
                        QString::number(LocalScene.VertxNumber).toLatin1()) ;
        }
    }
    if (LocalScene.anim == 1)
    {
        glColor3f (0.0, 1.0, 0.0);
        glRasterPos2i(10, 80);
        glCallLists(strlen("Anim ="),GL_UNSIGNED_BYTE, (GLubyte *)"Anim =");
        glColor3f (1.0, 0.0, 0.0);
        glRasterPos2i(80, 80);
        glCallLists(strlen("On"),GL_UNSIGNED_BYTE, (GLubyte *)"On");
    }
    if (LocalScene.morph == 1)
    {
        glColor3f (0.0, 1.0, 0.0);
        glRasterPos2i(10, 100);
        glCallLists(strlen("Morph="),GL_UNSIGNED_BYTE, (GLubyte *)"Morph=");
        glColor3f (1.0, 0.0, 0.0);
        glRasterPos2i(80, 100);
        glCallLists(strlen("On"),GL_UNSIGNED_BYTE, (GLubyte *)"On");
    }
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
}

static void DrawAxe()
{
    glLineWidth(1);
    glBegin( GL_LINES );
    glColor3f (1.0, 0.0, 0.0);
    glVertex3f( 400.0, 0.0, 0.0);
    glVertex3f(   0.0, 0.0, 0.0);
    glColor3f (0.0, 1.0, 0.0);
    glVertex3f(0.0, 400.0, 0.0);
    glVertex3f(0.0,   0.0, 0.0);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 400.0);
    glVertex3f(0.0, 0.0,   0.0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 400.0);
    glVertex3f(10.0, 0.0, 380.0);
    glVertex3f(0.0, 10.0, 380.0);
    glColor3f (0.0, 0.0, 0.3);
    glVertex3f(-10.0, 0.0, 380.0);
    glColor3f (0.0, 0.0, 1.0);
    glVertex3f(0.0, -10.0, 380.0);
    glColor3f (0.0, 0.0, 0.3);
    glVertex3f(10.0, 0.0, 380.0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f (0.0, 1.0, 0.0);
    glVertex3f(0.0, 400.0, 0.0);
    glVertex3f(10.0, 380.0, 0.0);
    glVertex3f(0.0, 380.0, 10.0);
    glColor3f (0.0, 0.3, 0.0);
    glVertex3f(-10.0, 380.0, 0.0);
    glColor3f (0.0, 1.0, 0.0);
    glVertex3f(.0, 380.0, -10.0);
    glColor3f (0.0, 0.3, 0.0);
    glVertex3f(10.0, 380.0, 0.0);
    glEnd();

    /// Axe X :
    glBegin(GL_TRIANGLE_FAN);
    glColor3f (1.0, 0.0, 0.0);
    glVertex3f(400.0, 0.0, 0.0);
    glVertex3f(380.0, 10.0, 0.0);
    glVertex3f(380.0, 0.0, 10.0);
    glColor3f (0.3, 0.0, 0.0);
    glVertex3f(380.0, -10.0, 0.0);
    glColor3f (1.0, 0.0, 0.0);
    glVertex3f(380.0, 0.0, -10.0);
    glColor3f (0.3, 0.0, 0.0);
    glVertex3f(380.0, 10.0, 0.0);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(400.0, 0.0, 0.0);
    glVertex3f(380.0, 10.0, 0.0);
    glVertex3f(380.0, 0.0, 10.0);
    glVertex3f(380.0, -10.0, 0.0);
    glVertex3f(380.0, 0.0, -10.0);
    glVertex3f(380.0, 10.0, 0.0);
    glEnd();

    glColor3f (1.0, 0.0, 0.0);
    glRasterPos3i(410, 10, 10);
    glCallLists(strlen("X"),GL_UNSIGNED_BYTE,"X");

    glColor3f (0.7, 0.7, 0.7);
    glTranslatef(410.0, 4.0, 4.0);
    glTranslatef(-410.0, -4.0, -4.0);

    glColor3f (0.0, 1.0, 0.0);
    glRasterPos3i(10, 410, 10);
    glCallLists(strlen("Y"),
                GL_UNSIGNED_BYTE,
                "Y");

    glColor3f (1.0, 1.0, 0.0);
    glTranslatef(4.0, 410.0, 4.0);
    glTranslatef(-4.0, -410.0, -4.0);

    glColor3f (0.0, 0.0, 1.0);
    glRasterPos3i(10, 10, 410);
    //printString("Z");
    glCallLists(strlen("Z"),
                GL_UNSIGNED_BYTE,
                "Z");

    glColor3f (0.0, 0.7, 0.7);
    glTranslatef(4.0, 4.0, 410.0);
    glTranslatef(-4.0, -4.0, -410.0);
    glLineWidth(0.9);
}

static void DrawNormals(ObjectProperties *scene)
{
    int j =  0;
    glColor4f (0.8, 0., 0.7, 1.0);
    for (unsigned int i=0; i< scene->PolyNumber; i+=4)
    {
        j =   TypeDrawin*scene->PolyIndices_localPt[i];
        glBegin( GL_LINES );
        glVertex3f(scene->ArrayNorVer_localPt[j+3  + TypeDrawinNormStep],
                   scene->ArrayNorVer_localPt[j+4  + TypeDrawinNormStep],
                   scene->ArrayNorVer_localPt[j+5  + TypeDrawinNormStep]);
        glVertex3f(scene->ArrayNorVer_localPt[j+3  + TypeDrawinNormStep]+40*scene->ArrayNorVer_localPt[j    + TypeDrawinNormStep],
                   scene->ArrayNorVer_localPt[j+4  + TypeDrawinNormStep]+40*scene->ArrayNorVer_localPt[j+1  + TypeDrawinNormStep],
                   scene->ArrayNorVer_localPt[j+5  + TypeDrawinNormStep]+40*scene->ArrayNorVer_localPt[j+2  + TypeDrawinNormStep]);
        glEnd();
    }
}

static int staticaction = 0;

void OpenGlWidget::initialize_GL()
{
    static int count =0;
    if(count <2)
    {
        /// For drawing Filled Polygones :
        glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
        glEnable(GL_NORMALIZE);
        glFrontFace (GL_CCW);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, LocalScene.frontcol);
        glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, LocalScene.backcol);

        glMaterialfv(GL_FRONT, GL_SPECULAR,LocalScene.specReflection);
        glMaterialfv(GL_BACK, GL_SPECULAR, LocalScene.specReflection);

        glMateriali(GL_FRONT, GL_SHININESS,LocalScene.shininess);
        glMateriali(GL_BACK, GL_SHININESS, LocalScene.shininess);
        glEnable(GL_DEPTH_TEST);

        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);

        boxok();
        InitFont();
        glInterleavedArrays (GL_C4F_N3F_V3F, 0, LocalScene.ArrayNorVer_localPt);
        count +=1;
    }
    PutObjectInsideCube();
}

void OpenGlWidget::UpdateGL()
{
    initialize_GL();
    update();
}

static void DrawIsoCND(ObjectProperties *scene)
{
    if(scene->componentsinfos.DMTrianglesVerifyCND)
    {
        glLineWidth(1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesVerifyCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[0]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }

    if(scene->componentsinfos.DMTrianglesNotVerifyCND)
    {
        glLineWidth(1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesNotVerifyCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[3*scene->componentsinfos.NbTrianglesVerifyCND]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }

    if(scene->componentsinfos.DMTrianglesBorderCND)
    {
        glLineWidth(4);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesBorderCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[3*(scene->componentsinfos.NbTrianglesVerifyCND + scene->componentsinfos.NbTrianglesNotVerifyCND) ]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }
}

static void DrawParCND(ObjectProperties *scene)
{
    if(scene->componentsinfos.DMTrianglesVerifyCND)
    {
        glLineWidth(1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesVerifyCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[0]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }

    if(scene->componentsinfos.DMTrianglesNotVerifyCND)
    {
        glLineWidth(1);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesNotVerifyCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[3*scene->componentsinfos.NbTrianglesVerifyCND]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }

    if(scene->componentsinfos.DMTrianglesBorderCND)
    {
        glLineWidth(4);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(
            GL_TRIANGLES,
            3*scene->componentsinfos.NbTrianglesBorderCND,
            GL_UNSIGNED_INT,
            &(scene->PolyIndices_localPt[3*(scene->componentsinfos.NbTrianglesVerifyCND + scene->componentsinfos.NbTrianglesNotVerifyCND) ]));
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glLineWidth(1);
    }
}

static void DrawMeshIso(ObjectProperties *scene)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_TRIANGLES, scene->PolyNumber, GL_UNSIGNED_INT, scene->PolyIndices_localPt);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

static void DrawMinimalTopology (ObjectProperties *scene)
{
    glColor4f (scene->gridcol[0], scene->gridcol[1], scene->gridcol[2], scene->gridcol[3]);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    int startpl = 0;
    for (unsigned int i = 0; i < scene->NbPolygnNbVertexPtMin; i++)
    {
        int polysize       =  scene->PolyIndices_localPtMin[startpl++];
        glBegin(GL_POLYGON);
        for (int j = 0; j < polysize; j++)
        {
            int actualpointindice = scene->PolyIndices_localPtMin[startpl];
            glVertex3f(
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+3 + TypeDrawinNormStep],
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+4 + TypeDrawinNormStep],
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+5 + TypeDrawinNormStep]
            );
            startpl++;
        }
        glEnd();
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

static void DrawMeshParametric(ObjectProperties *scene)
{
    glColor4f (scene->gridcol[0], scene->gridcol[1], scene->gridcol[2], scene->gridcol[3]);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    int startpl = 0;
    for (unsigned int i = 0; i < scene->NbPolygnNbVertexPtMin; i++)
    {
        int polysize       =  scene->PolyIndices_localPtMin[startpl++];
        glBegin(GL_POLYGON);
        for (int j = 0; j < polysize; j++)
        {
            int actualpointindice = scene->PolyIndices_localPtMin[startpl];
            glVertex3f(
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+3 + TypeDrawinNormStep],
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+4 + TypeDrawinNormStep],
                scene->ArrayNorVer_localPt[TypeDrawin*actualpointindice+5 + TypeDrawinNormStep]
            );
            startpl++;
        }
        glEnd();
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

static void draw(ObjectProperties *scene)
{
    scene->box =1;
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (staticaction < 1)
    {
        glRotatef(270,1.0,0.0,0.0);
        glRotatef(225,0.0,0.0,1.0);
        glRotatef(-29,1.0,-1.0,0.0);
        staticaction += 1;

        glEnable (GL_LINE_SMOOTH);
        glEnable (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glHint (GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
    }

    // Blend Effect activation:
    if (scene->transparency == 1)
        glDepthMask(GL_FALSE);

    // Ratation (Animation):
    if (scene->anim == 1 && scene->animxyz == 1)
    {
        glRotatef(scene->RotStrength, scene->axe_x, scene->axe_y, scene->axe_z);
    }

    // Plan:
    if (scene->infos == 1)
        glCallList(scene->gridplanliste);

    // Axe :
    if (scene->infos == 1)
        DrawAxe();

    glPushMatrix();

    if (scene->anim == 1 && scene->animx == 1)
    {
        scene->animxValue += scene->animxValueStep;
        glRotatef(scene->animxValue, 1.0, 0, 0);
    }

    if (scene->anim == 1 && scene->animy == 1)
    {
        scene->animyValue += scene->animyValueStep;
        glRotatef(scene->animyValue, 0, 1.0, 0);
    }

    if (scene->anim == 1 && scene->animz == 1)
    {
        scene->animzValue += scene->animzValueStep;
        glRotatef(scene->animzValue, 0, 0, 1.0);
    }

    if (scene->fill == 1 && scene->typedrawing == 1)
        DrawIso(scene);

    if (scene->fill == 1 && scene->typedrawing == -1)
        DrawParametric(scene);

    // Draw Mesh Object:
    if (scene->triangles == 1)
        DrawMeshIso(scene);

    if (scene->mesh == 1 && scene->typedrawing == -1)
        DrawMeshParametric(scene);

    // Bounding Box:
    if (scene->boundingbox == 1)
        drawCube(350);

    // Draw Minimal topology for isosurfaces:
    if (scene->mesh == 1  && scene->typedrawing == 1)
        DrawMinimalTopology(scene);

    if(scene->activarecnd && scene->componentsinfos.ThereisCND  && scene->typedrawing == 1)
        DrawIsoCND(scene);

    if(scene->activarecnd && scene->componentsinfos.ThereisCND  && scene->typedrawing == -1)
        DrawParCND(scene);

    //Draw Normales:
    if (scene->norm == 1 )
        DrawNormals(scene);

    glPopMatrix();

    if (scene->transparency == 1)
        glDepthMask(GL_TRUE);

    // Draw the scene:
    glFlush();
}

void OpenGlWidget::paintGL()
{
    if (LocalScene.morph == 1)
    {
        if(LocalScene.typedrawing == 11)
        {
            IsoObjetThread->IsoObjet->IsoBuild(
                LocalScene.ArrayNorVer_localPt,
                LocalScene.PolyIndices_localPt,
                &LocalScene.PolyNumberTmp1,
                &LocalScene.VertxNumberTmp1,
                LocalScene.PolyIndices_localPtMin,
                &(LocalScene.NbPolygnNbVertexPtMin),
                &(LocalScene.componentsinfos),
                LocalScene.Typetriangles,
                LocalScene.WichPointVerifyCond
            );

            ParObjetThread->ParObjet->ParamBuild(
                &(LocalScene.ArrayNorVer_localPt[TypeDrawin*(LocalScene.VertxNumberTmp1)]),
                LocalScene.ArrayNorVer_localPt,
                &(LocalScene.PolyIndices_localPt[LocalScene.PolyNumberTmp1]),
                &LocalScene.PolyNumberTmp2,
                &LocalScene.VertxNumberTmp2,
                LocalScene.VertxNumberTmp1,
                &(LocalScene.componentsinfos),
                LocalScene.Typetriangles,
                LocalScene.WichPointVerifyCond,
                LocalScene.PolyIndices_localPtMin,
                &(LocalScene.NbPolygnNbVertexPtMin)
            );

            LocalScene.PolyNumber = LocalScene.PolyNumberTmp1 + LocalScene.PolyNumberTmp2;
            LocalScene.VertxNumber= LocalScene.VertxNumberTmp1  + LocalScene.VertxNumberTmp2;

        }
        else if(LocalScene.typedrawing == -1)
        {
            ParObjetThread->ParObjet->ParamBuild
            (
                LocalScene.ArrayNorVer_localPt,
                LocalScene.ArrayNorVerExtra_localPt,
                LocalScene.PolyIndices_localPt,
                &LocalScene.PolyNumber,
                &LocalScene.VertxNumber,
                0,
                &(LocalScene.componentsinfos),
                LocalScene.Typetriangles,
                LocalScene.WichPointVerifyCond,
                LocalScene.PolyIndices_localPtMin,
                &(LocalScene.NbPolygnNbVertexPtMin)
            );
        }
        else if(LocalScene.typedrawing == 1)
        {
            IsoObjetThread->IsoObjet->IsoBuild
            (
                LocalScene.ArrayNorVer_localPt,
                LocalScene.PolyIndices_localPt,
                &(LocalScene.PolyNumber),
                &(LocalScene.VertxNumber),
                LocalScene.PolyIndices_localPtMin,
                &(LocalScene.NbPolygnNbVertexPtMin),
                &(LocalScene.componentsinfos),
                LocalScene.Typetriangles,
                LocalScene.WichPointVerifyCond
            );
        }
        initialize_GL();
    }

    draw(&LocalScene);

    if (LocalScene.infos == 1)  PrintInfos();
    if (LocalScene.morph == 1 && LocalScene.frame == 1)  FramesSave();
}

void OpenGlWidget::timerEvent(QTimerEvent*)
{
    update();
}

void OpenGlWidget::boxok()
{
    LocalScene.gridplanliste = glGenLists(1);
    glNewList(LocalScene.gridplanliste, GL_COMPILE );
    glLineWidth(1);
    glColor3f (0.8, 0.0, 0.7);
    glBegin( GL_LINES );
    glVertex3f(-150.0, 600.0, -500);
    glVertex3f(-150.0,-600.0, -500);
    glVertex3f(0.0, 600.0, -500);
    glVertex3f(0.0,-600.0, -500);

    glVertex3f(150.0, 600.0, -500);
    glVertex3f(150.0,-600.0, -500);
    glVertex3f(600.0, -150.0, -500);
    glVertex3f(-600.0,-150.0, -500);

    glVertex3f(600.0, 0.0, -500);
    glVertex3f(-600.0, 0.0, -500);
    glVertex3f(600.0, 150.0, -500);
    glVertex3f(-600.0, 150.0, -500);

    glVertex3f(-75.0, 600.0, -500);
    glVertex3f(-75.0,-600.0, -500);
    glVertex3f(-225.0, 600.0, -500);
    glVertex3f(-225.0,-600.0, -500);
    glVertex3f(-300.0, 600.0, -500);
    glVertex3f(-300.0,-600.0, -500);
    glVertex3f(-375.0, 600.0, -500);
    glVertex3f(-375.0,-600.0, -500);
    glVertex3f(-450.0, 600.0, -500);
    glVertex3f(-450.0,-600.0, -500);
    glVertex3f(-525.0, 600.0, -500);
    glVertex3f(-525.0,-600.0, -500);

    glVertex3f(75.0, 600.0, -500);
    glVertex3f(75.0,-600.0, -500);
    glVertex3f(225.0, 600.0, -500);
    glVertex3f(225.0,-600.0, -500);
    glVertex3f(300.0, 600.0, -500);
    glVertex3f(300.0,-600.0, -500);
    glVertex3f(375.0, 600.0, -500);
    glVertex3f(375.0,-600.0, -500);
    glVertex3f(450.0, 600.0, -500);
    glVertex3f(450.0,-600.0, -500);
    glVertex3f(525.0, 600.0, -500);
    glVertex3f(525.0,-600.0, -500);

    glVertex3f(600.0,-75.0, -500);
    glVertex3f(-600.0,-75.0, -500);
    glVertex3f(600.0,-225.0, -500);
    glVertex3f(-600.0,-225.0, -500);
    glVertex3f(600.0,-300.0, -500);
    glVertex3f(-600.0,-300.0, -500);
    glVertex3f(600.0,-375.0, -500);
    glVertex3f(-600.0,-375.0, -500);
    glVertex3f(600.0,-450.0, -500);
    glVertex3f(-600.0,-450.0, -500);
    glVertex3f(600.0,-525.0, -500);
    glVertex3f(-600.0,-525.0, -500);

    glVertex3f(600.0,75.0, -500);
    glVertex3f(-600.0,75.0, -500);
    glVertex3f(600.0,225.0, -500);
    glVertex3f(-600.0,225.0, -500);
    glVertex3f(600.0,300.0, -500);
    glVertex3f(-600.0,300.0, -500);
    glVertex3f(600.0,375.0, -500);
    glVertex3f(-600.0,375.0, -500);
    glVertex3f(600.0,450.0, -500);
    glVertex3f(-600.0,450.0, -500);
    glVertex3f(600.0,525.0, -500);
    glVertex3f(-600.0,525.0, -500);
    glEnd();
    glLineWidth(4.18);
    glEndList();
}

void OpenGlWidget::mouseMoveEvent( QMouseEvent *e )
{
    static double m[16];
    LocalScene.RotStrength = sqrt((LocalScene.oldRotx-e->x())*(LocalScene.oldRotx-e->x()) +
                                  (LocalScene.oldRoty-e->y())*(LocalScene.oldRoty-e->y()))/2.;
    LocalScene.oldRoty = e->y();
    LocalScene.oldRotx = e->x();

// Scale function :
    if (btdroit ==1)
    {
        if (old_y - e->y() > 0 ) LocalScene.ScalCoeff = 1.02f;
        else if ( LocalScene.ScalCoeff > 0.1f ) LocalScene.ScalCoeff = 0.98f;
        glScalef(LocalScene.ScalCoeff, LocalScene.ScalCoeff, LocalScene.ScalCoeff);
        LocalScene.view_rotx = LocalScene.view_roty = 0.0;
    }
// Rotational function :
    if (btgauche ==1)
    {
        LocalScene.view_roty = -(old_y - e->y());
        LocalScene.view_rotx = -(old_x - e->x());
        LocalScene.ScalCoeff = 1.0;

        glGetIntegerv(GL_VIEWPORT,LocalScene.viewport);
        glGetDoublev(GL_MODELVIEW_MATRIX,LocalScene.matrix);
        memcpy(m, LocalScene.matrix, 16*sizeof(GLdouble));

        ///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++///
        GLdouble det;
        GLdouble d12, d13, d23, d24, d34, d41;
        GLdouble tmp[16]; /* Allow out == in. */

        /* Inverse = adjoint / det. (See linear algebra texts.)*/
        /* pre-compute 2x2 dets for last two rows when computing */
        /* cofactors of first two rows. */
        d12 = (m31*m42-m41*m32);
        d13 = (m31*m43-m41*m33);
        d23 = (m32*m43-m42*m33);
        d24 = (m32*m44-m42*m34);
        d34 = (m33*m44-m43*m34);
        d41 = (m34*m41-m44*m31);

        tmp[0] =  (m22 * d34 - m23 * d24 + m24 * d23);
        tmp[1] = -(m21 * d34 + m23 * d41 + m24 * d13);
        tmp[2] =  (m21 * d24 + m22 * d41 + m24 * d12);
        tmp[3] = -(m21 * d23 - m22 * d13 + m23 * d12);

        /* Compute determinant as early as possible using these cofactors. */
        det = m11 * tmp[0] + m12 * tmp[1] + m13 * tmp[2] + m14 * tmp[3];

        /* Run singularity test. */
        if (det != 0.0)
        {
            GLdouble invDet = 1.0 / det;
            /* Compute rest of inverse. */
            tmp[0] *= invDet;
            tmp[1] *= invDet;
            tmp[2] *= invDet;
            tmp[3] *= invDet;

            tmp[4] = -(m12 * d34 - m13 * d24 + m14 * d23) * invDet;
            tmp[5] =  (m11 * d34 + m13 * d41 + m14 * d13) * invDet;
            tmp[6] = -(m11 * d24 + m12 * d41 + m14 * d12) * invDet;
            tmp[7] =  (m11 * d23 - m12 * d13 + m13 * d12) * invDet;

            d12 = m11*m22-m21*m12;
            d13 = m11*m23-m21*m13;
            d23 = m12*m23-m22*m13;
            d24 = m12*m24-m22*m14;
            d34 = m13*m24-m23*m14;
            d41 = m14*m21-m24*m11;

            tmp[8]  =  (m42 * d34 - m43 * d24 + m44 * d23) * invDet;
            tmp[9]  = -(m41 * d34 + m43 * d41 + m44 * d13) * invDet;
            tmp[10] =  (m41 * d24 + m42 * d41 + m44 * d12) * invDet;
            tmp[11] = -(m41 * d23 - m42 * d13 + m43 * d12) * invDet;
            tmp[12] = -(m32 * d34 - m33 * d24 + m34 * d23) * invDet;
            tmp[13] =  (m31 * d34 + m33 * d41 + m34 * d13) * invDet;
            tmp[14] = -(m31 * d24 + m32 * d41 + m34 * d12) * invDet;
            tmp[15] =  (m31 * d23 - m32 * d13 + m33 * d12) * invDet;
            memcpy(LocalScene.matrixInverse, tmp, 16*sizeof(GLdouble));
        }
        double ax,ay;
        ax = LocalScene.view_roty;
        ay = LocalScene.view_rotx;
        anglefinal += (angle = sqrt(ax*ax + ay*ay)/(double)(LocalScene.viewport[2]+1)*360.0);
        LocalScene.axe_x = Axe_x = LocalScene.matrixInverse[0]*ax + LocalScene.matrixInverse[4]*ay;
        LocalScene.axe_y = Axe_y = LocalScene.matrixInverse[1]*ax + LocalScene.matrixInverse[5]*ay;
        LocalScene.axe_z = Axe_z = LocalScene.matrixInverse[2]*ax + LocalScene.matrixInverse[6]*ay;
        glRotatef(angle,Axe_x,Axe_y,Axe_z);
    }
    old_y = e->y();
    old_x = e->x();
    update();
}

void OpenGlWidget::screenshot()
{
    QImage image = grabFrameBuffer();
    if(LocalScene.png_ok == 1) image.save("GLscreenshot.png", "PNG", LocalScene.quality_image);
    if(LocalScene.bmp_ok == 1) image.save("GLscreenshot.bmp", "BMP", LocalScene.quality_image);
}

void OpenGlWidget::FramesShot()
{
    LocalScene.frame *= -1;
    if(LocalScene.frame == 1)
    {
        FramesDir        = QFileDialog::getExistingDirectory(this,
                           tr("Choose Or Create Directory"),
                           FramesDir,
                           QFileDialog::DontResolveSymlinks);
        if(FramesDir != "" && !FramesDir.endsWith("/"))
            FramesDir +="/";
    }
}

void OpenGlWidget::FramesSave()
{
    static int Index =0;
    if(LocalScene.frame == 1)
    {
        QImage image = grabFrameBuffer();
        QString FileName = FramesDir+QString("%1").arg(Index, 5, 10, QChar('0'))+".png";
        Index +=1;
        image.save(FileName, "PNG", 1);
    }
}

QImage OpenGlWidget::Copyscreenshot()
{
    return(grabFrameBuffer());
}

void OpenGlWidget::transparency(int cl, int currentposition)
{
    switch(LocalScene.colortype)
    {
    case 1:
        LocalScene.frontcols[currentposition*4+3] = (cl/255.);
        break;
    case 0:
        LocalScene.backcols[currentposition*4+3]  = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[3] = (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[3] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };

    update();
}

void OpenGlWidget::transparencypar(int cl, int currentposition)
{
    switch(LocalScene.colortypeParam)
    {
    case 1:
        LocalScene.frontcolsPar[currentposition*4+3] = (cl/255.) ;
        break;
    case 0:
        LocalScene.backcolsPar[currentposition*4+3] = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[3] = (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[3] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };

    update();
}

void OpenGlWidget::red(int cl, int currentposition)
{
    switch(LocalScene.colortype)
    {
    case 1:
        LocalScene.frontcols[currentposition*4+0] = (cl/255.);
        break;
    case 0:
        LocalScene.backcols[currentposition*4+0]  =  (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[0] =  (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[0] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };

    update();
}

void OpenGlWidget::redpar(int cl, int currentposition)
{
    switch(LocalScene.colortypeParam)
    {
    case 1:
        LocalScene.frontcolsPar[currentposition*4+0] = (cl/255.);
        break;
    case 0:
        LocalScene.backcolsPar[currentposition*4+0] = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[0] =  (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[0] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };

    update();
}

void OpenGlWidget::green(int cl, int currentposition)
{
    switch(LocalScene.colortype)
    {
    case 1:
        LocalScene.frontcols[currentposition*4+1] = (cl/255.);
        break;
    case 0:
        LocalScene.backcols[currentposition*4+1]  = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[1] = (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[1] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1], LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };

    update();
}

void OpenGlWidget::greenpar(int cl, int currentposition)
{
    switch(LocalScene.colortypeParam)
    {
    case 1:
        LocalScene.frontcolsPar[currentposition*4+1] = (cl/255.);
        break;
    case 0:
        LocalScene.backcolsPar[currentposition*4+1] = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[1] = (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[1] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1], LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };

    update();
}

void OpenGlWidget::blue(int cl, int currentposition)
{
    switch(LocalScene.colortype)
    {
    case 1:
        LocalScene.frontcols[currentposition*4+2] = (cl/255.);
        break;
    case 0:
        LocalScene.backcols[currentposition*4+2]  = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[2] = (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[2] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };

    update();
}

void OpenGlWidget::bluepar(int cl, int currentposition)
{
    switch(LocalScene.colortypeParam)
    {
    case 1:
        LocalScene.frontcolsPar[currentposition*4+2] = (cl/255.);
        break;
    case 0:
        LocalScene.backcolsPar[currentposition*4+2] = (cl/255.);
        break;
    case 2:
        LocalScene.gridcol[2] = (cl/255.);
        break;
    case 3:
        LocalScene.groundcol[2] = (cl/255.);
        glClearColor(LocalScene.groundcol[0], LocalScene.groundcol[1],LocalScene.groundcol[2], LocalScene.groundcol[3]);
        break;
    };

    update();
}

void OpenGlWidget::transparence(bool trs)
{
    LocalScene.transparency *=-1;
    if (trs)
    {
        glEnable(GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE);
    }
    else glDisable(GL_BLEND);

    update();
}

void OpenGlWidget::transSpec(int cl)
{
    LocalScene.specReflection[3] =  (cl/100.0);
    InitSpecularParameters();
}

void OpenGlWidget::Shininess(int cl)
{
    LocalScene.shininess =  cl;
    InitSpecularParameters();
}

void OpenGlWidget::InitSpecularParameters()
{
    /// For drawing Filled Polygones :
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_NORMALIZE);
    glFrontFace (GL_CCW);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, LocalScene.frontcol);
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, LocalScene.backcol);

    glMaterialfv(GL_FRONT, GL_SPECULAR, LocalScene.specReflection);
    glMaterialfv(GL_BACK, GL_SPECULAR, LocalScene.specReflection);

    glMateriali(GL_FRONT, GL_SHININESS, LocalScene.shininess);
    glMateriali(GL_BACK, GL_SHININESS, LocalScene.shininess);
    glEnable(GL_DEPTH_TEST);
    update();
}
