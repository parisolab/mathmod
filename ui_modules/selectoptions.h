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

#ifndef COLORSOPTIONS_H
#define COLORSOPTIONS_H

#endif

#include "ui_selectoptions.h"

struct SelectedListOptions
{
    QStringList selectedwords;
    QList<bool> namelist;
    QList<bool> functlist;
    QList<bool> cmpnamelist;
    QList<bool> complist;
    bool sensitive;
    bool showall;
    bool AND;
    bool parsenames;
    bool parsecmpnames;
    bool parsefunctions;
    QStringList fieldnames;
};

class SelectOptions : public QWidget
{
    Q_OBJECT
public:
    SelectedListOptions selectedoptions;
public:
    SelectOptions(QWidget *parent = nullptr);

public:
    Ui::SelectOptions ui;
private slots:
    void on_addpushButton_clicked();
    void on_CutpushButton_clicked();
    void on_ShowAllcheckBox_clicked(bool checked);
    void on_CaseSensitiveCheckBox_clicked(bool checked);
    void on_AND_clicked(bool checked);

    void on_radioButton_clicked(bool checked);

    void on_FunctcheckBox_clicked(bool checked);

    void on_NamescheckBox_clicked(bool checked);

    void on_CompcheckBox_clicked(bool checked);

signals:
    void UpdateSignal();
public slots:
    void emitUpdateSignal();
};

