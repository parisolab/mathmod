/***************************************************************************
 *   Copyright (C) 2022 by Abderrahman Taha                                *
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

#ifndef SLIDERPARAM
#define SLIDERPARAM

#include "ui_sliderparam.h"

class SlidersForm : public QWidget
{
    Q_OBJECT

public:
    SlidersForm(QWidget *parent = nullptr);

public:
    Ui::SlidersForm ui;
    int currentSlider;
private slots:
    void on_SaveButton_clicked();
    void on_pushButton_clicked();
};

#endif // SLIDERPARAM
