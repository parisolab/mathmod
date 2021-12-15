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
screenimage::screenimage(QImage buffer) : QMainWindow(nullptr)
{
    buf = buffer;
    image_quality = 1;


    groupBox = new QGroupBox(this);
    groupBox->setGeometry(QRect(0, 317, 320, 25));

    l = new QLabel(this);
    l->resize(320, 320);
    resize(320, 343);
    this->setWindowTitle("ScreenShot");
    //gridLayout = new QGridLayout(this);
    QPixmap ScreenshotIcon = QPixmap::fromImage(buf.scaled(320, 320));
    l->setPixmap(ScreenshotIcon); //  (ScreenshotIcon);

    about = new QPushButton(groupBox);
    about->setObjectName(QString::fromUtf8("about"));
    about->setText("OK");
    scrollBar55 = new QScrollBar(Qt::Horizontal, groupBox);
    scrollBar55->setGeometry(QRect(160, 2, 80, 16));
    scrollBar55->setPageStep(1);
    scrollBar55->setValue(1);
    pushScreenshot = new QPushButton("pushScreenshot", groupBox);
    pushScreenshot->setGeometry(QRect(250, 2, 75, 18));
    pushScreenshot->setText(tr("Save Screen"));

    gridLayout = new QGridLayout(this);
    gridLayout->addWidget(groupBox, 0, 0, 1, 1);
}
screenimage::~screenimage()
{
    delete l;
}
void screenimage::connectcontrols()
{
    connect(pushScreenshot, SIGNAL(clicked()), this, SLOT(saveas()));
    connect(about, SIGNAL(clicked()), this, SLOT(close()));
    connect(scrollBar55, SIGNAL(valueChanged(int)), this, SLOT(f_1(int)));
}
void screenimage::f_1(int quality)
{
    image_quality = quality;
}
void screenimage::saveas()
{
    QString fn = QFileDialog::getSaveFileName(
                     this, tr("Choose a filename to save under"), "",
                     tr("Images (*.png *.bmp);; All files (*.*)"));
    if (!fn.isEmpty())
    {
        if (fn.contains(".bmp"))
            buf.save(fn, "BMP", 1);
        else if (fn.contains(".png"))
            buf.save(fn, "PNG", 1);
        else
            buf.save(fn + ".png", "PNG", image_quality);
    }
}
