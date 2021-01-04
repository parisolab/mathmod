/***************************************************************************
 *   Copyright (C) 2021 by Abderrahman Taha                                *
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
#ifndef EDITOR_H
#define EDITOR_H

#include "about.h"
#include "ui_editor.h"
#include <QMainWindow>

namespace Ui
{
class editor;
}

class editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit editor(QWidget *parent = nullptr);
    ~editor();
    void about();
    void newFile();
    void openFile(const QString &);
    void setupEditor();
    void save();
    void saveAs();
    About ab;
private slots:
    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionAbout_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionAbout_MathMod_triggered();

    void on_actionPaste_triggered();

public:
    Ui::editor *ui;
    QString filename;
    QString workfile;
};

#endif // EDITOR_H
