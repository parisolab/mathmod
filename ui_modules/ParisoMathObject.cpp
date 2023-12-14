/***************************************************************************
 *   Copyright (C) 2024 by Abderrahman Taha                                *
 *                                                                         *
 *                                                                         *
 *   This program is free software;you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation;either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY;without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program;if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA            *
 ***************************************************************************/
#include "ParisoMathObject.h"
#include <qmessagebox.h>

ParisoMathObject::ParisoMathObject()
{
    NbIsoStruct = NbParamStruct = 0;
    dotsymbol = ".";
}

ParisoMathObject::~ParisoMathObject() {}

void ParisoMathObject::ReadJsonFile(QString JsonFile, QJsonObject &js)
{
    QJsonParseError err;
    QString sortie;
    QFile file1(JsonFile);
    if (!file1.exists())
    {
        JsonFile = QFileDialog::getOpenFileName(
                       nullptr, QObject::tr("Open mathmodcollection.js File"), "",
                       QObject::tr("Json (*.js)"));
    }
    QFile file(JsonFile);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QJsonDocument doc = QJsonDocument::fromJson(
                                ((file.readAll()).trimmed())
                                .replace("\n", "")
                                .replace("\t", "")
                                .replace("DOTSYMBOL", dotsymbol.toStdString().c_str()),
                                &err);
        if (err.error)
        {
            QMessageBox message;
            message.setWindowTitle("Error at : " + JsonFile);
            file.close();
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            sortie = (file.readAll());
            int before, after;
            if (sortie.length() > (err.offset + 30))
                after = 30;
            else
                after = sortie.length() - err.offset;
            sortie.truncate(err.offset + after);
            if (err.offset - 30 > 0)
                before = 30;
            else
                before = 0;
            sortie = sortie.remove(0, err.offset - before);
            sortie.replace("\t", " ");
            sortie.replace("\n", " ");
            sortie.insert(before, " >>> Error <<< ");
            message.setText("Error : " + err.errorString() +
                            " at position: " + QString::number(err.offset) +
                            "\n\n***********\n" + "..." + sortie + "...");
            message.adjustSize();
            message.exec();
            file.close();
            return;
        }
        js = doc.object();
        file.close();
    }
    return;
}
