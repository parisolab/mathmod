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

#ifndef DRAWINGOPTIONS_H
#define DRAWINGOPTIONS_H

#include "about.h"
#include "addparam.h"
#include "editor.h"
#include "mathmod.h"
#include "parametersoptions.h"
#include "../screenshot/video.h"
#include "selectoptions.h"
#include "sliderparam.h"
#include "ui_drawingoptions.h"
#include <QMainWindow>

enum OptionnalParScriptFIELD {PAR_VECT, PAR_GRID, PAR_CND, PAR_CONST, PAR_FUNCT, PAR_IMPORTFUNCT};

enum OptionnalIsoScriptFIELD {ISO_VECT, ISO_GRID, ISO_CND, ISO_CONST, ISO_FUNCT, ISO_IMPORTFUNCT};

enum MandatoryIsoField
{
    ISO_FXYZ,
    ISO_XMIN,
    ISO_XMAX,
    ISO_YMIN,
    ISO_YMAX,
    ISO_ZMIN,
    ISO_ZMAX,
    ISO_COMP,
    ISO_NAME
};

enum MandatoryParField
{
    PAR_FX,
    PAR_FY,
    PAR_FZ,
    PAR_FW,
    PAR_UMIN,
    PAR_UMAX,
    PAR_VMIN,
    PAR_VMAX,
    PAR_COMP,
    PAR_NAME
};

struct SliderStruct
{
    QScrollBar *SliderScrollBar;
    QLabel *SliderLabel;
    QLabel *SliderLabelMin;
    QLabel *SliderLabelMax;
    QGroupBox *SliderGroupeBox;
};

class DrawingOptions : public QMainWindow
{
    Q_OBJECT

public:
    DrawingOptions(QWidget *parent = nullptr);
    ~DrawingOptions();
    MathMod *MathmodRef;
    About ab;
    std::vector<QString> MandatoryParmetric3DFields={"Fx", "Fy","Fz", "Umin", "Umax", "Vmin", "Vmax", "Component", "Name"};
    std::vector<QString> MandatoryParmetric4DFields={"Fx", "Fy","Fz", "Fw", "Umin", "Umax", "Vmin", "Vmax", "Component", "Name"};
    std::vector<QString> MandatoryIsosurfaceFields={"Fxyz", "Xmin", "Xmax", "Ymin", "Ymax", "Zmin", "Zmax", "Component", "Name"};
    std::vector<QString> OptionalFields={"Grid", "Cnd", "Const", "Funct", "Vect", "Import"};
    SlidersForm sliderconf;
    AddParamForm addnewparam;
    QTreeWidgetItem *IsolistItemRef;
    Parametersoptions *Parameters;
    SelectOptions select;
    int infos=-1;
    Ui::DrawingOptions ui;
    QJsonObject JSONMathModels;
    SliderStruct *SliderArray;
    ScriptErrorType scriptErrorType;
    int evalErrorType;
    std::vector<OptionnalIsoScriptFIELD> OptIsoFields;
    std::vector<OptionnalParScriptFIELD> OptParFields;
    std::vector<MandatoryIsoField> MandIsoFields;
    std::vector<MandatoryParField> MandParFields;
    bool ShowCurrentObjectTree = false;
    void on_choice_activated(const QString &);
    void grabGestures(const QList<Qt::GestureType> &gestures);
public slots:
    void removeat(int, QJsonObject&, QString);
    void removeat2(int, QJsonObject&, QString);
    void appendall(QJsonObject&, QString, QTableWidget*);
    void replaceat(int, QJsonObject&, QString, QTextEdit*);
    void insertat(int, QJsonObject&, QString, QTextEdit*);
    void appednew(QJsonObject&, QString, QTextEdit*);
    void AddListModels(bool b = false);
    void Run_JsonObject_activeted();
    void CIndextoolButton_clicked(int);
    void BuildAllVect();
    void ShowErrorMessage(QJsonParseError &, QString &);
    void OptionalIsoScriptFieldprocess(const QJsonObject &,
                                       OptionnalIsoScriptFIELD);
    void OptionalParScriptFieldprocess(const QJsonObject &,
                                       OptionnalParScriptFIELD);
    void MandatoryIsoFieldprocess(const QJsonObject &, const MandatoryIsoField &);
    void MandatoryParFieldprocess(const QJsonObject &, const MandatoryParField &,
                                  const ModelType &mod = PAR_TYPE);
    void LoadMandatoryAndOptionnalFields(const QJsonObject &, const ModelType &,
                                         bool, const QJsonObject &, bool,
                                         const QJsonObject &);
    void LoadTexture(const QJsonObject &, const ModelType &);
    void LoadPigment(const QJsonObject &, const ModelType &);
    void updateCurrentTreestruct();
    void ErrorMsg() const;
    void MemoryErrorMsg(int) const;
    void SaveSlidersRef(int n = 20);
    void editorwin();
    void videoplay();
    void SaveToFile_CurentMathModel(QJsonObject);
    void ReadCollectionFile(QString, QJsonObject &);
    void on_xyzg_valueChanged(int);
    void on_ChangeGrid_clicked();
    void LoadK3DSurfScript(QString, int);
    void slot_comboBox18_3_activated(const QString &);
    void slot_checkBox_clicked();
    void on_action_Exit_triggered();
    void on_actionTriangles_triggered();
    void on_actionInfos_triggered();
    void on_actionFill_triggered();
    void on_ObjectClasse_clicked(const QModelIndex &);
    void UpdateScriptEditorAndTreeObject();
    void UpdatePar3DModelDetailsPage(TreeStruct &);
    void UpdatePar4DModelDetailsPage(TreeStruct &);
    void UpdateIsoModelDetailsPage(TreeStruct &);
    void UpdateTreeObject();
    void on_updateButton_clicked();
    void on_updateJObject(QJsonObject &);
    void RunUpdatedJObject(QJsonObject &);
    void slot_pushButton_2_clicked();
    void slot_unselect_clicked();
    void slot_XYZscrollBar_valueChanged(int);
    void UpdateDescription(int, ModelType, TreeStruct &);
    void oncolor_2activated(int index);
    void onred_2valueChanged(int);
    void ongreen_2valueChanged(int);
    void onblue_2valueChanged(int);
    void on_updateParam_clicked();
    void on_actionPolygonWavefront_obj_triggered();
    void on_actionColorPolygonWavefront_obj_triggered();
    void on_linecolumn_2_valueChanged(int);
    int JSON_choice_activated(const QString &);
    void ShowJsonModel(const QJsonObject &, int textureIndex = -1);
    void DrawJsonModel(const QJsonObject &, int textureIndex = -1,
                       bool Inspect = true);
    bool VerifiedJsonModel(const QJsonObject &, bool Inspect = true);
    bool VerifiedIsoJsonModel(const QJsonObject &);
    bool VerifyParEmptySpace(const QJsonObject &);
    bool VerifyIsoEmptySpace(const QJsonObject &);
    bool VerifyParFieldEmptySpace(const QJsonObject &, const MandatoryParField &);
    QString MandatoryParFieldToQString(const MandatoryParField &);
    bool VerifyIsoFieldEmptySpace(const QJsonObject &, const MandatoryIsoField &);
    QString MandatoryIsoFieldToQString(const MandatoryIsoField &);
    bool VerifiedParJsonModel(const QJsonObject &);
    void AddObjectToMySelectionTree();
    void AddIsoObjectToTree(QTreeWidgetItem *, TreeStruct &);
    void AddParObjectToTree(QTreeWidgetItem *, TreeStruct &);
    void ObjArrayToString(QJsonArray &, QString &);
    void ObjArrayToInternalFunctEnum(QJsonArray &, std::vector<InternalFuncDefinition> &);
    void AddParametersToTree(QTreeWidgetItem *, TreeStruct &);
    void on_IsoComponent_activated(int);
    void on_ParamComponent_activated(int);
    void on_xycheckBox_clicked();
    void on_xyhorizontalScrollBar_valueChanged(int);
    void on_xzcheckBox_clicked();
    void on_xzhorizontalScrollBar_valueChanged(int);
    void on_yzcheckBox_clicked();
    void on_yzhorizontalScrollBar_valueChanged(int);
    void on_xwcheckBox_clicked();
    void on_xwhorizontalScrollBar_valueChanged(int);
    void on_ywcheckBox_clicked();
    void on_ywhorizontalScrollBar_valueChanged(int);
    void on_zwcheckBox_clicked();
    void on_zwhorizontalScrollBar_valueChanged(int);
    void on_linecolumn_3_valueChanged(int);
    void oncolor_4activated(int);
    void on_uv4D_clicked();
    void on_uv_clicked();
    void on_InitMatrix_clicked();
    void on_ActivateCND_clicked(bool);
    void on_TBordercheckBox_clicked(bool);
    void on_TCNDcheckBox_clicked(bool);
    void on_FCNDcheckBox_clicked(bool);
    void on_TNCNDcheckBox_clicked(bool);
    void on_FNCNDcheckBox_clicked(bool);
    void on_actionMesh_triggered();
    void on_calculate_clicked();
    void on_actionAbout_2_triggered();
    void LoadNewFileModels(bool upd = false);
    void on_actionLoad_json_script_triggered();
    void on_red_ParIso_valueChanged(int);
    void on_green_ParIso_valueChanged(int);
    void on_blue_ParIso_valueChanged(int);
    void Multiplier(int, int, int, QJsonObject &, int index = 0);
    void UpdateGui();
    void UpdateGuiMaxgrid();
    void ShowSliders(const QJsonObject &);
    void on_actionScreenshot_triggered();
    void on_actionEditor_triggered();
    void update_slider_param();
    void add_new_param();
    void update_infos_param(int);
    void SearchListModels();
    void ParseItemTree(QTreeWidgetItem *, QList<bool> &, bool view = false);
    QTreeWidgetItem *ChildItemTreeProperty(QTreeWidgetItem *item,
                                           QString proprty);
    void on_cut_clicked();
    void on_actionConvert_K3DS_script_triggered();
    void on_ParamComponent_2_activated(int);
    void on_updateParam_2_clicked();
    void on_Multiplier_clicked();
    void on_TimeStepScrollBar_valueChanged(int);
    void on_InitTButton_clicked();
    void on_pushButton_2_clicked();
    void on_xyhorizontalScrollBar2_valueChanged(int);
    void on_xzhorizontalScrollBar2_valueChanged(int);
    void on_yzhorizontalScrollBar2_valueChanged(int);
    void on_xycheckBox2_clicked();
    void on_xzcheckBox2_clicked();
    void on_yzcheckBox2_clicked();
    void on_InitMatrix_2_clicked();
    void on_xyzcheckBox2_clicked();
    void on_pushButton_3_clicked();
    void on_cut_2_clicked();
    void on_pushButton_4_clicked();
    void on_color_5_activated(int);
    void on_transparent_ParIso_valueChanged(int);
    void on_comboBoxTexture_activated(int);
    void on_comboBoxPigment_activated(int);
    void on_actionTrianglesWavefront_obj_triggered();
    void on_actionColorTrianglesWavefront_obj_triggered();
    void on_ShowtextureScript_clicked();
    void on_pushButton_5_clicked();
    void on_C1ScrollBar_valueChanged(int);
    void on_C2ScrollBar_valueChanged(int);
    void on_C3ScrollBar_valueChanged(int);
    void on_C4ScrollBar_valueChanged(int);
    void on_C5ScrollBar_valueChanged(int);
    void on_PredefinedSets_activated(int);
    void on_C6ScrollBar_valueChanged(int);
    void on_C7ScrollBar_valueChanged(int);
    void on_C8ScrollBar_valueChanged(int);
    void on_C9ScrollBar_valueChanged(int);
    void on_C10ScrollBar_valueChanged(int);
    void on_C11ScrollBar_valueChanged(int);
    void on_C12ScrollBar_valueChanged(int);
    void on_C13ScrollBar_valueChanged(int);
    void on_C14ScrollBar_valueChanged(int);
    void on_C15ScrollBar_valueChanged(int);
    void on_C16ScrollBar_valueChanged(int);
    void on_C17ScrollBar_valueChanged(int);
    void on_C18ScrollBar_valueChanged(int);
    void on_C19ScrollBar_valueChanged(int);
    void on_C20ScrollBar_valueChanged(int);
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
    void SetSpecularValues(int *);
    void SetAmbientValues(int *);
    void SetDiffuseValues(int *);
    void SetglFrontFacingSupport();
    void SetShininessValue(int);
    void SetThreadValues(int *);
    void on_green_Specular_valueChanged(int);
    void on_blue_Specular_valueChanged(int);
    void on_transparent_Specular_valueChanged(int);
    void on_ShininessScrollBar_valueChanged(int);
    void on_ThreadNumberScrollBar_valueChanged(int);
    void on_StopCalculationsButton_clicked();
    void on_stopButton_clicked();
    void on_lineScrollBar_valueChanged(int);
    void on_coloneScrollBar_valueChanged(int);
    void on_actionScripts_selection_triggered();
    //void on_actionBoundingBox_clicked();
    void on_actionAnimation_Rotation_triggered();
    void on_actionMorph_use_t_parameter_triggered();
    void on_TreeViewButton_clicked();
    void on_ObjectClasseCurrent_clicked(const QModelIndex &);
    void on_parisocomboBox_currentIndexChanged(int);
    void on_ApplypushButton_clicked();
    void on_ApplypushButton_2_clicked();
    void on_ApplypushButton_3_clicked();
    void updateParametricGridSliders(int);
    void on_actionDocumentation_triggered();
    void on_ScaleButton_clicked();
    void on_ShowIsoComp_clicked();
    void updateShowIsoCmp(int);
    void updateShowParComp(int);
    void on_ShowParComp_clicked();
    void on_actionAxe_triggered();
    void on_actionPlan_triggered();
    void on_red_Ambient_valueChanged(int);
    void on_green_Ambient_valueChanged(int);
    void on_blue_Ambient_valueChanged(int);
    void on_transparent_Ambient_valueChanged(int);
    void on_red_Diffuse_valueChanged(int);
    void on_green_Diffuse_valueChanged(int);
    void on_blue_Diffuse_valueChanged(int);
    void on_transparent_Diffuse_valueChanged(int);
    void on_GLFrontSurfaceSupport_clicked();
    void on_ScaleXBar_valueChanged(int);
    void on_ScaleYBar_valueChanged(int);
    void on_ScaleZBar_valueChanged(int);
    void on_TorsionX_valueChanged(int);
    void on_TorsionY_valueChanged(int);
    void on_TorsionZ_valueChanged(int);
    void on_SaveThButton_clicked();
    void on_SaveTrButton_clicked();
    void on_TorsionX_2_valueChanged();
    void on_TorsionY_2_valueChanged();
    void on_TorsionZ_2_valueChanged();
    void on_SaveTrButton_2_clicked();
    void on_SaveThButton_2_clicked();
    void on_ApplyThicknessVal_clicked();

private slots:
    void on_actionbox_triggered();
    void on_InitializeTorsionButton_clicked();
    void on_ApplyThicknessVal_2_clicked();
    void on_RedopushButton_clicked();
};

#endif
