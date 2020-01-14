/***************************************************************************
 *   Copyright (C) 2020 by Abderrahman Taha                                *
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
        if(selectedoptions.selectedwords.size() > 0)
            selectedoptions.selectedwords.removeAt(0);
        selectedoptions.selectedwords.append(ui.StringlineEdit->text());
        selectedoptions.selectedwords.insert(0, "Words Selection ("+QString::number(selectedoptions.selectedwords.count())+")");
        ui.StringSelect->clear();
        ui.StringSelect->addItems(selectedoptions.selectedwords);
        ui.StringlineEdit->clear();
    }
    emitUpdateSignal();
}

void SelectOptions::on_CutpushButton_clicked()
{
    int currentindex = ui.StringSelect->currentIndex();
    if(currentindex > 0)
    {
        selectedoptions.selectedwords.removeAt(currentindex);
        selectedoptions.selectedwords.removeAt(0);
        if(selectedoptions.selectedwords.count() > 0)
        {
            selectedoptions.selectedwords.insert(0, "Words Selection ("+QString::number(selectedoptions.selectedwords.count())+")");
            ui.StringSelect->clear();
            ui.StringSelect->addItems(selectedoptions.selectedwords);
        }
        else
            ui.StringSelect->clear();
    }
    emitUpdateSignal();
}

void SelectOptions::on_ShowAllcheckBox_clicked(bool checked)
{
    ui.SelectgroupBox->setEnabled(!checked);
    ui.SelectgroupBox->setVisible(!checked);
    selectedoptions.showall = checked;
    if(selectedoptions.selectedwords.count() > 0)
        emitUpdateSignal();
}

void SelectOptions::on_CaseSensitiveCheckBox_clicked(bool checked)
{
    selectedoptions.sensitive = checked;
    emitUpdateSignal();
}

void SelectOptions::emitUpdateSignal()
{
    emit UpdateSignal();
}

void SelectOptions::on_AND_clicked(bool checked)
{
    selectedoptions.AND = checked;
    if(selectedoptions.selectedwords.count() > 1)
        emitUpdateSignal();
}

void SelectOptions::on_radioButton_clicked(bool checked)
{
    selectedoptions.AND = !checked;
    if(selectedoptions.selectedwords.count() > 1)
        emitUpdateSignal();
}

void SelectOptions::on_FunctcheckBox_clicked(bool checked)
{
    selectedoptions.parsefunctions = checked;
    emitUpdateSignal();
}

void SelectOptions::on_NamescheckBox_clicked(bool checked)
{
    selectedoptions.parsenames = checked;
    emitUpdateSignal();
}

void SelectOptions::on_CompcheckBox_clicked(bool checked)
{
    selectedoptions.parsecmpnames = checked;
    emitUpdateSignal();
}
