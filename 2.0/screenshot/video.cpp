/***************************************************************************
 *   Copyright (C) 2007 by Abderrahman Taha                                *
 *   taha_ab@yahoo.fr                                                      *
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
#include "video.h"

videoplayer::videoplayer(QImage buffer)
    : QMainWindow( 0, 0)
{
    buf = buffer;
    image_quality=1;
    l = new QLabel(this, 0);
    l->resize(320, 320);
    resize(320, 343);
    this->setWindowTitle("ScreenShot");
    //setCaption( "ScreenShot" );
    QPixmap ScreenshotIcon = QPixmap::fromImage(buf.scaled(320, 320));
    l->setPixmap(ScreenshotIcon); //  (ScreenshotIcon);
    groupBox = new QGroupBox(this);
    groupBox->setGeometry( QRect( 0, 317, 320, 25 ) );
    scrollBar55 = new QScrollBar(Qt::Horizontal, 0 );
    scrollBar55->setGeometry( QRect( 160, 2, 80, 16 ) );
    scrollBar55->setPageStep( 1 );
    scrollBar55->setValue( 1 );
    //QLabel * text = new QLabel( "Image quality:", groupBox,0);
    //text->setGeometry( QRect( 3, 5, 150, 16 ) );
    pushScreenshot = new QPushButton("pushScreenshot", groupBox );
    pushScreenshot->setGeometry( QRect( 250, 2, 50, 20 ) );
    pushScreenshot->setText( tr( "Save" ) );
}

videoplayer::~videoplayer()
{
//delete m;
    delete l;
}

void videoplayer::connectcontrols()
{
    connect( pushScreenshot, SIGNAL(clicked() ), this, SLOT(saveas()));
    connect( scrollBar55, SIGNAL(valueChanged(int) ), this, SLOT(f_1(int)));
}
//+++++++++++++++++++++++++++++++++++++++
void videoplayer::f_1(int quality)
{
    image_quality = quality;
}

//+++++++++++++++++++++++++++++++++++++++
void videoplayer::saveas()
{
    QString fn = QFileDialog::getSaveFileName(this,
                 tr("Choose a filename to save under"),
                 "",
                 tr("Images (*.png *.bmp);; All files (*.*)")
                                             );

    if ( !fn.isEmpty() )
    {
        if(fn.contains(".bmp"))  buf.save(fn, "BMP" , 1);
        else if(fn.contains(".png"))  buf.save(fn, "PNG", 1);
        else buf.save(fn+".png", "PNG" , image_quality);
    }
}
