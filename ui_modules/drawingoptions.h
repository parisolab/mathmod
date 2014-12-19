/***************************************************************************
 *   Copyright (C) 2014 by Abderrahman Taha                                *
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

#ifndef DRAWINGOPTIONS_H
#define DRAWINGOPTIONS_H

#include "editor.h"
#include "mathmod.h"
#include "ui_drawingoptions.h"
#include "../screenshot/video.h"
#include "about.h"
#include "parametersoptions.h"
#include "colorsoptions.h"
#include <QMainWindow>

class DrawingOptions : public QMainWindow
{
    Q_OBJECT

public:
    DrawingOptions(QWidget *parent = 0);
    ~DrawingOptions();
    MathMod*  MathmodRef;
    About ab;
    QTreeWidgetItem *IsolistItemRef;
    Parametersoptions * Parameters;
    void AddListModels(bool b=false);
    void Run_JsonObject_activeted();
    void keyPressEvent ( QKeyEvent *);
public slots:
    void editorwin();
    void videoplay();
    void colorsoptions();
    void on_xyzg_valueChanged(int);
    void on_ChangeGrid_clicked();
    int on_choice_activated(const QString &);
    int Parametric_choice_activated(const QString &);
    int Iso_choice_activated(const QString &);
    void LoadK3DSurfScript (QString filename, int type);
    void slot_comboBox18_3_activated(const QString &arg1);
    void slot_checkBox_clicked();
    void on_pushButton_clicked();
    void on_action_Exit_triggered();
    void on_actionTriangles_triggered();
    void on_actionNormales_triggered();
    void on_actionInfos_triggered();
    void on_actionFill_triggered();
    void on_actionSmooth_triggered();
    void on_ObjectClasse_clicked(const QModelIndex &index);
    void AddModel(QString, int where=0);
    void UpdateCurrentTreeObject();
    void on_updateButton_clicked();
    void slot_pushButton_2_clicked();
    void slot_unselect_clicked();
    void slot_XYZscrollBar_valueChanged(int);
    void UpdateDescription(int);
    void on_color_2_activated(int index);
    void on_red_2_valueChanged(int value);
    void on_green_2_valueChanged(int value);
    void on_transparent_2_valueChanged(int value);
    void on_blue_2_valueChanged(int value);
    void on_transparence_2_clicked(bool checked);
    void on_updateParam_clicked();
    void on_actionWavefront_obj_triggered();
    void on_linecolumn_2_valueChanged(int value);
    void on_color_3_activated(int index);
    void on_red_3_valueChanged(int value);
    void on_green_3_valueChanged(int value);
    void on_blue_3_valueChanged(int value);
    void on_transparent_3_valueChanged(int value);
    void on_transparence_3_toggled(bool checked);
    int JSON_choice_activated(const QString &);
    void ShowJsonModel(const QJsonObject &);
    void AddObjectToMySelectionTree();
    void on_XhorizontalScrollBar_valueChanged(int value);
    void on_YhorizontalScrollBar_valueChanged(int value);
    void on_ZhorizontalScrollBar_valueChanged(int value);
    void on_IsoComponent_activated(int index);
    void on_ParamComponent_activated(int index);
    void createActions();
    void on_xycheckBox_clicked();
    void on_xyhorizontalScrollBar_valueChanged(int value);
    void on_xzcheckBox_clicked();
    void on_xzhorizontalScrollBar_valueChanged(int value);
    void on_yzcheckBox_clicked();
    void on_yzhorizontalScrollBar_valueChanged(int value);
    void on_xwcheckBox_clicked();
    void on_xwhorizontalScrollBar_valueChanged(int value);
    void on_ywcheckBox_clicked();
    void on_ywhorizontalScrollBar_valueChanged(int value);
    void on_zwcheckBox_clicked();
    void on_zwhorizontalScrollBar_valueChanged(int value);
    void on_linecolumn_3_valueChanged(int value);
    void on_color_4_activated(int index);
    void on_red_4_valueChanged(int value);
    void on_green_4_valueChanged(int value);
    void on_blue_4_valueChanged(int value);
    void on_transparent_4_valueChanged(int value);
    void on_transparence_4_toggled(bool checked);
    void on_uv4D_clicked();
    void on_uv_clicked();
    void on_InitMatrix_clicked();
    void on_ActivateCND_clicked(bool checked);
    void on_TBordercheckBox_clicked(bool checked);
    void on_TCNDcheckBox_clicked(bool checked);
    void on_FCNDcheckBox_clicked(bool checked);
    void on_TNCNDcheckBox_clicked(bool checked);
    void on_FNCNDcheckBox_clicked(bool checked);
    void on_actionMesh_triggered();
    void on_calculate_clicked();
    void on_actionAbout_2_triggered();
    void LoadNewFileModels(bool upd=false);
    void on_actionLoad_json_script_triggered();
    void Multiplier(int, int, int, QJsonObject &iso, int index =0);
    void UpdateGui(int);
public:
    Ui::DrawingOptions ui;
    QJsonObject JSONMathModels;
public slots:
    void on_actionScreenshot_triggered();
    void on_actionEditor_triggered();
    void on_actionColors_triggered();
    void on_anim_clicked();
    void on_morph_clicked();
private slots:
    void on_actionSmooth_2_clicked();
    void on_Infos_clicked();
    void on_Mesh_clicked();
    void on_Norm_clicked();
    void on_Fill_clicked();
    void on_Trian_clicked();
    void on_actionOpenGL_triggered();
    void on_cut_clicked();
    void on_actionConvert_K3DS_script_triggered();
    void on_actionConfiguration_triggered();
    void on_actionColors_2_triggered();
    void on_Load_clicked();
    void on_ParamComponent_2_activated(int index);
    void on_updateParam_2_clicked();
    void on_Multiplier_clicked();
    void on_ActivateCND_2_clicked(bool checked);
    void on_TCNDcheckBox_2_clicked(bool checked);
    void on_TNCNDcheckBox_2_clicked(bool checked);
    void on_TBordercheckBox_2_clicked(bool checked);
    void on_FCNDcheckBox_2_clicked(bool checked);
    void on_FNCNDcheckBox_2_clicked(bool checked);
    void on_TimeStepScrollBar_valueChanged(int value);
    void on_InitTButton_clicked();
    void on_pushButton_2_clicked();
};
#endif
