/***************************************************************************
 *   Copyright (C) 2007 by Abderrahman Taha                                *
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
#include <qfiledialog.h>
#include <qgroupbox.h>
#include <qimage.h>
#include <qlabel.h>
#include <qmainwindow.h>
#include <qpushbutton.h>
#include <qscrollbar.h>

class screenimage : public QMainWindow
{
    Q_OBJECT

public:
    screenimage(QImage);
    ~screenimage();
public slots:
    void connectcontrols();
    void saveas();
    void f_1(int);

public:
    QLabel *l;
    QGroupBox *groupBox;
    QScrollBar *scrollBar55;
    QPushButton *pushScreenshot;
    QImage buf;
    int image_quality;
};
