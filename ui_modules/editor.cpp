/***************************************************************************
 *   Copyright (C) 2025 by Abderrahman Taha                                *
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
#include "editor.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

editor::editor(QWidget *parent) : QMainWindow(parent), ui(new Ui::editor)
{
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
}
editor::~editor()
{
    delete ui;
}
void editor::about()
{
    QMessageBox::about(this, tr("About Syntax Highlighter"),
                       tr("<p>The <b>Syntax Highlighter</b> example shows how "
                          "to perform simple syntax highlighting by subclassing "
                          "the QSyntaxHighlighter class and describing "
                          "highlighting rules using regular expressions.</p>"));
}
void editor::newFile()
{
    ui->textEdit->clear();
}
void editor::openFile(const QString &path)
{
    filename = path;
    // if (fileName.isNull())
    filename = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                            "Files (*.js *.*)");
    if (!filename.isEmpty())
    {
        QFile file(filename);
        if (file.open(QFile::ReadOnly | QFile::Text))
            ui->textEdit->setPlainText(file.readAll());
        file.close();
    }
}
void editor::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    ui->textEdit = new QTextEdit;
    ui->textEdit->setFont(font);
    QFile file("mainwindow.h");
    if (file.open(QFile::ReadWrite | QFile::Text))
        ui->textEdit->setPlainText(file.readAll());
}
void editor::on_actionOpen_triggered()
{
    openFile("");
}
void editor::save()
{
    if (filename.isEmpty())
    {
        saveAs();
        return;
    }
    QString text = ui->textEdit->toPlainText();
    QFile f(filename);
    if (f.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream t(&f);
        t << text.toUtf8();
        f.close();
        statusBar()->showMessage(tr("File %1 saved").arg(filename), 20000);
    }
    else
    {
        statusBar()->showMessage(tr("Could not write to %1").arg(filename), 20000);
        return;
    }
}
void editor::saveAs()
{
    QString fn = QFileDialog::getSaveFileName(this, tr("Save file"), "",
                 tr("All Files (*.*)"));

    if (!fn.isEmpty())
    {
        filename = fn;
        save();
    }
    else
    {
        statusBar()->showMessage(tr("Saving aborted"), 20000);
    }
    workfile = fn;
}
void editor::on_actionNew_triggered()
{
    newFile();
}
void editor::on_actionAbout_triggered()
{
    about();
}
void editor::on_actionSave_triggered()
{
    save();
}
void editor::on_actionSave_As_triggered()
{
    saveAs();
}
void editor::on_actionExit_triggered()
{
    this->close();
}
void editor::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}
void editor::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
void editor::on_actionCut_triggered()
{
    ui->textEdit->cut();
}
void editor::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void editor::on_actionAbout_MathMod_triggered()
{
    ab.show();
}
void editor::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
