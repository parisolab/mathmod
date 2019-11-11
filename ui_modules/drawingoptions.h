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

#ifndef DRAWINGOPTIONS_H
#define DRAWINGOPTIONS_H

#include "editor.h"
#include "mathmod.h"
#include "ui_drawingoptions.h"
#include "../screenshot/video.h"
#include "about.h"
#include "parametersoptions.h"
#include "colorsoptions.h"
#include "sliderparam.h"
#include "addparam.h"
#include "selectoptions.h"
#include <QMainWindow>

enum ModelType
{
    PAR_TYPE,
    ISO_TYPE
};
enum OptionnalParScriptFIELD
{
    PAR_GRID_FIELD,
    PAR_CND_FIELD,
    PAR_CONST_FIELD,
    PAR_FUNCT_FIELD,
    PAR_VAR_FIELD,
    PAR_TEXT_FIELD,
    PAR_PIGM_FIELD
};

enum OptionnalIsoScriptFIELD
{
    ISO_GRID_FIELD,
    ISO_CND_FIELD,
    ISO_CONST_FIELD,
    ISO_FUNCT_FIELD,
    ISO_VAR_FIELD,
    ISO_TEXT_FIELD,
    ISO_PIGM_FIELD
};

enum MandatoryIsoField
{
    ISO_FXYZ_FIELD,
    ISO_XMIN_FIELD,
    ISO_XMAX_FIELD,
    ISO_YMIN_FIELD,
    ISO_YMAX_FIELD,
    ISO_ZMIN_FIELD,
    ISO_ZMAX_FIELD,
    ISO_COMP_FIELD,
    ISO_NAME_FIELD
};

enum MandatoryParField
{
    PAR_FX_FIELD,
    PAR_FY_FIELD,
    PAR_FZ_FIELD,
    PAR_FW_FIELD,
    PAR_UMIN_FIELD,
    PAR_UMAX_FIELD,
    PAR_VMIN_FIELD,
    PAR_VMAX_FIELD,
    PAR_COMP_FIELD,
    PAR_NAME_FIELD
};

struct SliderStruct
{
    QScrollBar * SliderScrollBar;
    QLabel *     SliderLabel;
    QLabel *     SliderLabelMin;
    QLabel *     SliderLabelMax;
    QGroupBox *  SliderGroupeBox;
};

class DrawingOptions : public QMainWindow
{
    Q_OBJECT

public:

    DrawingOptions(QWidget *parent = nullptr);
    ~DrawingOptions();
    MathMod*  MathmodRef;
    About ab;
    SlidersForm sliderconf;
    AddParamForm addnewparam;
    QTreeWidgetItem *IsolistItemRef;
    Parametersoptions * Parameters;
    SelectOptions select;
    void AddListModels(bool b=false);
    void Run_JsonObject_activeted();
    Ui::DrawingOptions ui;
    QJsonObject JSONMathModels;
    SliderStruct * SliderArray;
    ScriptErrorType scriptErrorType;
    int evalErrorType;
    std::vector<OptionnalIsoScriptFIELD> OptIsoFields;
    std::vector<OptionnalParScriptFIELD> OptParFields;
    std::vector<MandatoryIsoField> MandIsoFields;
    std::vector<MandatoryParField> MandParFields;
public slots:
    void CIndextoolButton_clicked(int);
    void BuildAllVect();
    void OptionalIsoScriptFieldprocess(const QJsonObject &, OptionnalIsoScriptFIELD);
    void OptionalParScriptFieldprocess(const QJsonObject &, OptionnalParScriptFIELD);
    void MandatoryIsoFieldprocess(const QJsonObject &, const MandatoryIsoField &);
    void MandatoryParFieldprocess(const QJsonObject &, const MandatoryParField &);
    void LoadTexture(const QJsonObject &, const ModelType &);
    void LoadPigment(const QJsonObject &, const ModelType &);
    void updateCurrentTreestruct();
    void ErrorMsg() const;
    void MemoryErrorMsg(int) const;
    void SaveSlidersRef(int n=20);
    void editorwin();
    void videoplay();
    void colorsoptions();
    void on_xyzg_valueChanged(int);
    void on_ChangeGrid_clicked();
    int    on_choice_activated(const QString &);
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
    void oncolor_2activated(int index);
    void onred_2valueChanged(int value);
    void ongreen_2valueChanged(int value);
    void ontransparent_2valueChanged(int value);
    void onblue_2valueChanged(int value);
    void ontransparence_2clicked(bool checked);
    void on_updateParam_clicked();
    void on_actionPolygonWavefront_obj_triggered();
    void on_actionColorPolygonWavefront_obj_triggered();
    void on_linecolumn_2_valueChanged(int value);
    void oncolor_3activated(int index);
    void onred_3valueChanged(int value);
    void ongreen_3valueChanged(int value);
    void onblue_3valueChanged(int value);
    void ontransparent_3valueChanged(int value);
    void ontransparence_3toggled(bool checked);
    int JSON_choice_activated(const QString &);
    void ShowJsonModel(const QJsonObject &, int textureIndex=-1);
    void DrawJsonModel(const QJsonObject & Jobj, int textureIndex=-1, bool Inspect=true);
    bool VerifiedJsonModel(const QJsonObject & Jobj, bool Inspect=true);
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
    void oncolor_4activated(int index);
    void onred_4valueChanged(int value);
    void ongreen_4valueChanged(int value);
    void onblue_4valueChanged(int value);
    void ontransparent_4valueChanged(int value);
    void ontransparence_4toggled(bool checked);
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
    void on_red_ParIso_valueChanged(int value);
    void on_green_ParIso_valueChanged(int value);
    void on_blue_ParIso_valueChanged(int value);
    void Multiplier(int, int, int, QJsonObject &iso, int index =0);
    void UpdateGui(int);
    void ShowSliders(const QJsonObject &);
    void on_actionScreenshot_triggered();
    void on_actionEditor_triggered();
    void on_actionColors_triggered();
    void update_slider_param();
    void add_new_param();
    void update_infos_param(int);
    void SearchListModels();
    void ParseItemTree(QTreeWidgetItem*, QList<bool> &list, bool view=false);
    QTreeWidgetItem * ChildItemTreeProperty(QTreeWidgetItem * item, QString proprty);
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
    void on_TimeStepScrollBar_valueChanged(int value);
    void on_InitTButton_clicked();
    void on_pushButton_2_clicked();
    void on_xyhorizontalScrollBar2_valueChanged(int value);
    void on_xzhorizontalScrollBar2_valueChanged(int value);
    void on_yzhorizontalScrollBar2_valueChanged(int value);
    void on_xycheckBox2_clicked();
    void on_xzcheckBox2_clicked();
    void on_yzcheckBox2_clicked();
    void on_InitMatrix_2_clicked();
    void on_xyzcheckBox2_clicked();
    void on_pushButton_3_clicked();
    void on_cut_2_clicked();
    void on_pushButton_4_clicked();
    void on_color_5_activated(int index);
    void on_transparence_ParIso_clicked(bool checked);
    void on_transparent_ParIso_valueChanged(int value);
    void on_comboBoxTexture_activated(int index);
    void on_comboBoxPigment_activated(int index);
    void on_actionTrianglesWavefront_obj_triggered();
    void on_actionColorTrianglesWavefront_obj_triggered();
    void on_OctavesScrollBar_valueChanged(int value);
    void on_LacunarityScrollBar_valueChanged(int value);
    void on_GainScrollBar_valueChanged(int value);
    void on_ShowtextureScript_clicked();
    void on_TurbulenceCheckBox_clicked();
    void on_pushButton_5_clicked();
    void on_C1ScrollBar_valueChanged(int value);
    void on_C2ScrollBar_valueChanged(int value);
    void on_C3ScrollBar_valueChanged(int value);
    void on_C4ScrollBar_valueChanged(int value);
    void on_C5ScrollBar_valueChanged(int value);
    void on_PredefinedSets_activated(int index);
    void on_C6ScrollBar_valueChanged(int value);
    void on_C7ScrollBar_valueChanged(int value);
    void on_C8ScrollBar_valueChanged(int value);
    void on_C9ScrollBar_valueChanged(int value);
    void on_C10ScrollBar_valueChanged(int value);
    void on_C11ScrollBar_valueChanged(int value);
    void on_C12ScrollBar_valueChanged(int value);
    void on_C13ScrollBar_valueChanged(int value);
    void on_C14ScrollBar_valueChanged(int value);
    void on_C15ScrollBar_valueChanged(int value);
    void on_C16ScrollBar_valueChanged(int value);
    void on_C17ScrollBar_valueChanged(int value);
    void on_C18ScrollBar_valueChanged(int value);
    void on_C19ScrollBar_valueChanged(int value);
    void on_C20ScrollBar_valueChanged(int value);
    void CScrollBar_valueChanged(int, int);
    void on_C20toolButton_clicked();
    void on_C19toolButton_clicked();
    void on_C18toolButton_clicked();
    void on_C17toolButton_clicked();
    void on_C16toolButton_clicked();
    void on_C15toolButton_clicked();
    void on_C14toolButton_clicked();
    void on_C13toolButton_clicked();
    void on_C12toolButton_clicked();
    void on_C11toolButton_clicked();
    void on_C10toolButton_clicked();
    void on_C9toolButton_clicked();
    void on_C8toolButton_clicked();
    void on_C7toolButton_clicked();
    void on_C6toolButton_clicked();
    void on_C5toolButton_clicked();
    void on_C4toolButton_clicked();
    void on_C3toolButton_clicked();
    void on_C2toolButton_clicked();
    void on_C1toolButton_clicked();
    void on_AddSetButton_clicked();
    void on_CutSetButton_clicked();
    void HideSliders();
    void on_AddParam_clicked();
    void on_CutParam_clicked();
    void on_actionFrames_triggered();
    void on_red_Specular_valueChanged(int);
    void SetSpecularValues(float *);
    void SetShininessValue(int);
    void SetThreadValues(int *);
    void on_green_Specular_valueChanged(int);
    void on_blue_Specular_valueChanged(int);
    void on_transparent_Specular_valueChanged(int);
    void on_ShininessScrollBar_valueChanged(int value);
    void on_ThreadNumberScrollBar_valueChanged(int value);
    void on_StopCalculationsButton_clicked();
    void on_stopButton_clicked();
    void on_lineScrollBar_valueChanged(int value);
    void on_coloneScrollBar_valueChanged(int value);
    void on_actionScripts_selection_triggered();
    void on_actionBoundingBox_clicked();
    void on_actionAnimation_Rotation_triggered();
    void on_actionMorph_use_t_parameter_triggered();
};
#endif
