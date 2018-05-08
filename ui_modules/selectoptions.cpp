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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/

#include <QtGui>

#include "selectoptions.h"


SelectOptions::SelectOptions(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlags( Qt::WindowStaysOnTopHint );
    ui.setupUi(this);
}

void SelectOptions::on_addpushButton_clicked()
{
    QString select = ui.StringlineEdit->text();
    if(select != "")
    {
        selectedwords.append(ui.StringlineEdit->text());
        ui.StringSelect->clear();
        selectedwords.removeAt(0);
        selectedwords.insert(0, "Words Selection ("+QString::number(selectedwords.count())+")");
        ui.StringSelect->addItems(selectedwords);
    }
}
