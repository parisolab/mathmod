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
#include "drawingoptions.h"
#include <qmessagebox.h>

static int IndexcurrentComponent = -1;
static int indexcurrentSet = 0;
static int CurrentFormulaType = -1; // 0:Pariso; 1:Parametric; 2:Isosurface
static QTreeWidgetItem *MyselectionItemReference;
static QStringList qlstPos, qlstStep, qlstmin, qlstmax, qlstnames;

// Error messages returned by ErrorMsg():
static const char *ScriptErrorMessage[] =
{
    "SCRIPT_NO_ERROR",      // 0
    "MAXGRID_OUT_OF_RANGE", // 1
    "MAXPT_OUT_OF_RANGE",   // 2
    "MAXTRI_OUT_OF_RANGE",  // 3
    "FXYZ_OUT_OF_RANGE",    // 4
    "FX_OUT_OF_RANGE",
    "XMAX_NBCOMPONENT_MISMATCH",                // 5
    "YMAX_NBCOMPONENT_MISMATCH",                // 6
    "ZMAX_NBCOMPONENT_MISMATCH",                // 7
    "XMIN_NBCOMPONENT_MISMATCH",                // 8
    "YMIN_NBCOMPONENT_MISMATCH",                // 9
    "ZMIN_NBCOMPONENT_MISMATCH",                // 10
    "FY_FX_MISMATCH",                           // 11
    "FZ_FX_MISMATCH",                           // 12
    "FW_FX_MISMATCH",                           // 13
    "UMAX_NBCOMPONENT_MISMATCH",                // 14
    "VMAX_NBCOMPONENT_MISMATCH",                // 15
    "WMAX_NBCOMPONENT_MISMATCH",                // 16
    "UMIN_NBCOMPONENT_MISMATCH",                // 17
    "VMIN_NBCOMPONENT_MISMATCH",                // 18
    "WMIN_NBCOMPONENT_MISMATCH",                // 19
    "GRID_NBCOMPONENT_MISMATCH",                // 20
    "COMPONENT_NBCOMPONENT_MISMATCH",           // 21
    "CND_NBCOMPONENT_MISMATCH",                 // 22
    "NBSLIDERS_OUT_OF_RANGE",                   // 23
    "NBSLIDERSVALUES_OUT_OF_RANGE",             // 24
    "VERTEX_TAB_MEM_OVERFLOW",                  // 25
    "TRIANGLES_TAB_MEM_OVERFLOW",               // 26
    "MINPOLY_TAB_MEM_OVERFLOW",                 // 27
    "POLY_TAB_MEM_OVERFLOW",                    // 28
    "CND_TAB_MEM_OVERFLOW",                     // 29
    "CND_POL_MEM_OVERFLOW",                     // 30
    "DEFINED_PARAM_GRID_VERTEX_TAB_OVERFLOW",   // 31
    "DEFINED_PARAM_GRID_TRIANGLE_TAB_OVERFLOW", // 32
    "GRID_SUPERIOR_TO_GRIDMAX",                 // 33
    "Vect_DIMENSION_ERROR",                     // 34
    "Not enough memory available to complete this operation", // 35
    "EMPTY_MANDATORY_FIELD"                     // 36
};

void DrawingOptions::ErrorMsg() const
{
    QMessageBox msgBox;
    if (scriptErrorType != SCRIPT_NO_ERROR)
    {
        msgBox.setText(ScriptErrorMessage[scriptErrorType]);
        msgBox.exec();
    }
}

void DrawingOptions::MemoryErrorMsg(int err) const
{
    QMessageBox msgBox;
    if (err != SCRIPT_NO_ERROR)
    {
        msgBox.setText(ScriptErrorMessage[err]);
        msgBox.exec();
    }
}

void DrawingOptions::editorwin()
{
    editor *editorwindow = new editor();
    editorwindow->show();
}

void DrawingOptions::videoplay()
{
    QImage buf = MathmodRef->Copyscreenshot();
    screenimage *player = new screenimage(buf);
    player->connectcontrols();
    player->show();
}

DrawingOptions::~DrawingOptions()
{
    delete[] SliderArray;
}

DrawingOptions::DrawingOptions(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    IndexcurrentComponent = -1;
    IsolistItemRef = nullptr;
    select.selectedoptions.showall = false;
    select.selectedoptions.sensitive = false;
    select.selectedoptions.AND = true;
    select.selectedoptions.parsefunctions = true;
    select.selectedoptions.parsenames = true;
    select.selectedoptions.parsecmpnames = true;
    connect(sliderconf.ui.SaveButton, SIGNAL(clicked()), this,SLOT(update_slider_param()));
    connect(sliderconf.ui.ParametersComboBox, SIGNAL(activated(int)), this,SLOT(update_infos_param(int)));
    connect(addnewparam.ui.SaveButton, SIGNAL(clicked()), this,SLOT(add_new_param()));
    connect(&select, SIGNAL(UpdateSignal()), this, SLOT(SearchListModels()));
    SaveSlidersRef();
    BuildAllVect();
    ui.ObjectClasseCurrent->hide();
    ui.ObjectClasseCurrent->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void DrawingOptions::SaveSlidersRef(int nb)
{
    SliderArray = new SliderStruct[nb];

    SliderArray[0].SliderScrollBar = ui.C1ScrollBar;
    SliderArray[0].SliderLabel = ui.C1label;
    SliderArray[0].SliderLabelMax = ui.C1labelMax;
    SliderArray[0].SliderLabelMin = ui.C1labelMin;
    SliderArray[0].SliderGroupeBox = ui.groupBox_9;

    SliderArray[1].SliderScrollBar = ui.C2ScrollBar;
    SliderArray[1].SliderLabel = ui.C2label;
    SliderArray[1].SliderLabelMax = ui.C2labelMax;
    SliderArray[1].SliderLabelMin = ui.C2labelMin;
    SliderArray[1].SliderGroupeBox = ui.groupBox_10;

    SliderArray[2].SliderScrollBar = ui.C3ScrollBar;
    SliderArray[2].SliderLabel = ui.C3label;
    SliderArray[2].SliderLabelMax = ui.C3labelMax;
    SliderArray[2].SliderLabelMin = ui.C3labelMin;
    SliderArray[2].SliderGroupeBox = ui.groupBox_11;

    SliderArray[3].SliderScrollBar = ui.C4ScrollBar;
    SliderArray[3].SliderLabel = ui.C4label;
    SliderArray[3].SliderLabelMax = ui.C4labelMax;
    SliderArray[3].SliderLabelMin = ui.C4labelMin;
    SliderArray[3].SliderGroupeBox = ui.groupBox_12;

    SliderArray[4].SliderScrollBar = ui.C5ScrollBar;
    SliderArray[4].SliderLabel = ui.C5label;
    SliderArray[4].SliderLabelMax = ui.C5labelMax;
    SliderArray[4].SliderLabelMin = ui.C5labelMin;
    SliderArray[4].SliderGroupeBox = ui.groupBox_13;

    SliderArray[5].SliderScrollBar = ui.C6ScrollBar;
    SliderArray[5].SliderLabel = ui.C6label;
    SliderArray[5].SliderLabelMax = ui.C6labelMax;
    SliderArray[5].SliderLabelMin = ui.C6labelMin;
    SliderArray[5].SliderGroupeBox = ui.groupBox_14;

    SliderArray[6].SliderScrollBar = ui.C7ScrollBar;
    SliderArray[6].SliderLabel = ui.C7label;
    SliderArray[6].SliderLabelMax = ui.C7labelMax;
    SliderArray[6].SliderLabelMin = ui.C7labelMin;
    SliderArray[6].SliderGroupeBox = ui.groupBox_15;

    SliderArray[7].SliderScrollBar = ui.C8ScrollBar;
    SliderArray[7].SliderLabel = ui.C8label;
    SliderArray[7].SliderLabelMax = ui.C8labelMax;
    SliderArray[7].SliderLabelMin = ui.C8labelMin;
    SliderArray[7].SliderGroupeBox = ui.groupBox_16;

    SliderArray[8].SliderScrollBar = ui.C9ScrollBar;
    SliderArray[8].SliderLabel = ui.C9label;
    SliderArray[8].SliderLabelMax = ui.C9labelMax;
    SliderArray[8].SliderLabelMin = ui.C9labelMin;
    SliderArray[8].SliderGroupeBox = ui.groupBox_17;

    SliderArray[9].SliderScrollBar = ui.C10ScrollBar;
    SliderArray[9].SliderLabel = ui.C10label;
    SliderArray[9].SliderLabelMax = ui.C10labelMax;
    SliderArray[9].SliderLabelMin = ui.C10labelMin;
    SliderArray[9].SliderGroupeBox = ui.groupBox_18;

    SliderArray[10].SliderScrollBar = ui.C11ScrollBar;
    SliderArray[10].SliderLabel = ui.C11label;
    SliderArray[10].SliderLabelMax = ui.C11labelMax;
    SliderArray[10].SliderLabelMin = ui.C11labelMin;
    SliderArray[10].SliderGroupeBox = ui.groupBox_19;

    SliderArray[11].SliderScrollBar = ui.C12ScrollBar;
    SliderArray[11].SliderLabel = ui.C12label;
    SliderArray[11].SliderLabelMax = ui.C12labelMax;
    SliderArray[11].SliderLabelMin = ui.C12labelMin;
    SliderArray[11].SliderGroupeBox = ui.groupBox_20;

    SliderArray[12].SliderScrollBar = ui.C13ScrollBar;
    SliderArray[12].SliderLabel = ui.C13label;
    SliderArray[12].SliderLabelMax = ui.C13labelMax;
    SliderArray[12].SliderLabelMin = ui.C13labelMin;
    SliderArray[12].SliderGroupeBox = ui.groupBox_21;

    SliderArray[13].SliderScrollBar = ui.C14ScrollBar;
    SliderArray[13].SliderLabel = ui.C14label;
    SliderArray[13].SliderLabelMax = ui.C14labelMax;
    SliderArray[13].SliderLabelMin = ui.C14labelMin;
    SliderArray[13].SliderGroupeBox = ui.groupBox_22;

    SliderArray[14].SliderScrollBar = ui.C15ScrollBar;
    SliderArray[14].SliderLabel = ui.C15label;
    SliderArray[14].SliderLabelMax = ui.C15labelMax;
    SliderArray[14].SliderLabelMin = ui.C15labelMin;
    SliderArray[14].SliderGroupeBox = ui.groupBox_23;

    SliderArray[15].SliderScrollBar = ui.C16ScrollBar;
    SliderArray[15].SliderLabel = ui.C16label;
    SliderArray[15].SliderLabelMax = ui.C16labelMax;
    SliderArray[15].SliderLabelMin = ui.C16labelMin;
    SliderArray[15].SliderGroupeBox = ui.groupBox_24;

    SliderArray[16].SliderScrollBar = ui.C17ScrollBar;
    SliderArray[16].SliderLabel = ui.C17label;
    SliderArray[16].SliderLabelMax = ui.C17labelMax;
    SliderArray[16].SliderLabelMin = ui.C17labelMin;
    SliderArray[16].SliderGroupeBox = ui.groupBox_25;

    SliderArray[17].SliderScrollBar = ui.C18ScrollBar;
    SliderArray[17].SliderLabel = ui.C18label;
    SliderArray[17].SliderLabelMax = ui.C18labelMax;
    SliderArray[17].SliderLabelMin = ui.C18labelMin;
    SliderArray[17].SliderGroupeBox = ui.groupBox_26;

    SliderArray[18].SliderScrollBar = ui.C19ScrollBar;
    SliderArray[18].SliderLabel = ui.C19label;
    SliderArray[18].SliderLabelMax = ui.C19labelMax;
    SliderArray[18].SliderLabelMin = ui.C19labelMin;
    SliderArray[18].SliderGroupeBox = ui.groupBox_27;

    SliderArray[19].SliderScrollBar = ui.C20ScrollBar;
    SliderArray[19].SliderLabel = ui.C20label;
    SliderArray[19].SliderLabelMax = ui.C20labelMax;
    SliderArray[19].SliderLabelMin = ui.C20labelMin;
    SliderArray[19].SliderGroupeBox = ui.groupBox_28;
}

void DrawingOptions::on_xyzg_valueChanged(int value)
{
    ui.Isogroupbox->setTitle("Grid/MaxGrid = (" +
                             QString::number(ui.xyzg->value()) + " / " +
                             QString::number(Parameters->IsoMaxGrid) + ")");
    if (!MathmodRef->IsoObjet->isRunning())
    {
        (MathmodRef->RootObjet.CurrentJsonObject["ParIso"].isArray()) ?
        MathmodRef->xyzg_valueChanged(value, PARISO_TYPE) : MathmodRef->xyzg_valueChanged(value, ISO_TYPE);
    }
    else
    {
        ui.ChangeGrid->blockSignals(true);
        ui.ChangeGrid->setChecked(false);
        ui.ChangeGrid->blockSignals(false);
        MathmodRef->xyzactivated = -1;
    }
}

void DrawingOptions::on_ChangeGrid_clicked()
{
    (MathmodRef->RootObjet.CurrentJsonObject["ParIso"].isArray()) ?
    MathmodRef->slot_checkBox73_clicked(PARISO_TYPE) : MathmodRef->slot_checkBox73_clicked(ISO_TYPE);
}

void DrawingOptions::AddParObjectToTree(QTreeWidgetItem *paramlistItem,
                                        TreeStruct &currentstruct)
{
    if (!currentstruct.name.empty())
        paramlistItem->setText(0, currentstruct.name[0]);
    QColor greenColor = QColor(0, 255, 0, 50);
    paramlistItem->setBackground(0, greenColor);

    if (currentstruct.Component.size() > 0)
    {
        QTreeWidgetItem *cmpitem = new QTreeWidgetItem(paramlistItem);
        cmpitem->setText(0, "Components (" +QString::number(currentstruct.Component.size()) +"):");

        for (int j = 0; j < currentstruct.Component.size(); j++)
        {
            QTreeWidgetItem *cmpitem2 = new QTreeWidgetItem(cmpitem);
            cmpitem2->setText(0, currentstruct.Component.at(j));
            QTreeWidgetItem *cmpitem3 = new QTreeWidgetItem(cmpitem2);
            cmpitem3->setText(0, "fx(u,v,t) = " + currentstruct.fx.at(j));
            QTreeWidgetItem *cmpitem4 = new QTreeWidgetItem(cmpitem2);
            cmpitem4->setText(0, "fy(u,v,t) = " + currentstruct.fy.at(j));
            QTreeWidgetItem *cmpitem5 = new QTreeWidgetItem(cmpitem2);
            cmpitem5->setText(0, "fz(u,v,t) = " + currentstruct.fz.at(j));
            if (MathmodRef->RootObjet.CurrentJsonObject["Param4D"].isObject())
            {
                QTreeWidgetItem *cmpitem8 = new QTreeWidgetItem(cmpitem2);
                cmpitem8->setText(0, "fw(u,v,t) = " + currentstruct.fw.at(j));
            }
            QTreeWidgetItem *cmpitem6 = new QTreeWidgetItem(cmpitem2);
            cmpitem6->setText(0, "U = [" + currentstruct.umin.at(j) + ", " +currentstruct.umax.at(j) + "]");
            QTreeWidgetItem *cmpitem7 = new QTreeWidgetItem(cmpitem2);
            cmpitem7->setText(0, "V = [" + currentstruct.vmin.at(j) + ", " +currentstruct.vmax.at(j) + "]");
            // Grid resolution:
            if (currentstruct.Grid.size() > 0 &&(2 * j + 1) < currentstruct.Grid.size() &&
                    !MathmodRef->RootObjet.CurrentJsonObject["Param4D"].isObject())
            {
                QTreeWidgetItem *cmpitem7 = new QTreeWidgetItem(cmpitem2);
                cmpitem7->setText(0, "Grid = (" + currentstruct.Grid.at(2 * j) + " , " +currentstruct.Grid.at(2 * j + 1) + ")");
            }
        }
        // Add Global parameters:
        AddParametersToTree(paramlistItem, currentstruct);
    }
}

void DrawingOptions::AddIsoObjectToTree(QTreeWidgetItem *IsolistItem, TreeStruct &currentstruct)
{
    if (!currentstruct.name.empty())
        IsolistItem->setText(0, currentstruct.name[0]);
    QColor greenColor = QColor(0, 255, 0, 50);
    IsolistItem->setBackground(0, greenColor);
    if (currentstruct.Component.size() > 0)
    {
        QTreeWidgetItem *cmpitem = new QTreeWidgetItem(IsolistItem);
        cmpitem->setText(0, "Components (" +
                         QString::number(currentstruct.Component.size()) +
                         "):");
        for (int j = 0; j < currentstruct.Component.size(); j++)
        {
            QTreeWidgetItem *cmpitem2 = new QTreeWidgetItem(cmpitem);
            cmpitem2->setText(0, currentstruct.Component.at(j));
            QTreeWidgetItem *cmpitem3 = new QTreeWidgetItem(cmpitem2);
            cmpitem3->setText(0, "f(x,y,z) = " + currentstruct.fxyz.at(j));
            QTreeWidgetItem *cmpitem4 = new QTreeWidgetItem(cmpitem2);
            cmpitem4->setText(0, "X = [" + currentstruct.xmin.at(j) + ", " +currentstruct.xmax.at(j) + "]");
            QTreeWidgetItem *cmpitem5 = new QTreeWidgetItem(cmpitem2);
            cmpitem5->setText(0, "Y = [" + currentstruct.ymin.at(j) + ", " +currentstruct.ymax.at(j) + "]");
            QTreeWidgetItem *cmpitem6 = new QTreeWidgetItem(cmpitem2);
            cmpitem6->setText(0, "Z = [" + currentstruct.zmin.at(j) + ", " +currentstruct.zmax.at(j) + "]");
            // Grid resolution:
            if (currentstruct.Grid.size() > 0 && j < currentstruct.Grid.size())
            {
                QTreeWidgetItem *cmpitem7 = new QTreeWidgetItem(cmpitem2);
                cmpitem7->setText(0, "Grid = " + currentstruct.Grid.at(j));
            }
        }
        // Add Global parameters:
        AddParametersToTree(IsolistItem, currentstruct);
    }
}

void DrawingOptions::AddParametersToTree(QTreeWidgetItem *parameterslistItem,
        TreeStruct &currentstruct)
{
    QTreeWidgetItem *parameteritem = new QTreeWidgetItem(parameterslistItem);
    parameteritem->setText(0, "Parameters:");
    int size = 0;

    if ((size = currentstruct.Const.size()) > 0)
    {
        QTreeWidgetItem *cstitem = new QTreeWidgetItem(parameteritem);
        cstitem->setText(0, "Constantes:");
        for (int j = 0; j < size; j++)
        {
            QTreeWidgetItem *cstitem2 = new QTreeWidgetItem(cstitem);
            cstitem2->setText(0, currentstruct.Const.at(j));
        }
    }
    if ((size = currentstruct.Funct.size()) > 0)
    {
        QTreeWidgetItem *fctitem = new QTreeWidgetItem(parameteritem);
        fctitem->setText(0, "Functions:");
        for (int j = 0; j < size; j++)
        {
            QTreeWidgetItem *fctitem2 = new QTreeWidgetItem(fctitem);
            fctitem2->setText(0, currentstruct.Funct.at(j));
        }
    }
}

void DrawingOptions::AddObjectToMySelectionTree()
{
    if (MathmodRef->RootObjet.CurrentJsonObject["Iso3D"].isObject())
    {
        QTreeWidgetItem *isolistItem =
            new QTreeWidgetItem(MyselectionItemReference);
        AddIsoObjectToTree(isolistItem, MathmodRef->RootObjet.CurrentTreestruct);
    }
    else if (MathmodRef->RootObjet.CurrentJsonObject["Param3D"].isObject() ||
             MathmodRef->RootObjet.CurrentJsonObject["Param4D"].isObject() ||
             MathmodRef->RootObjet.CurrentJsonObject["Param3D_C"].isObject() ||
             MathmodRef->RootObjet.CurrentJsonObject["Param4D_C"].isObject())
    {
        QTreeWidgetItem *paramlistItem =
            new QTreeWidgetItem(MyselectionItemReference);
        AddParObjectToTree(paramlistItem, MathmodRef->RootObjet.CurrentTreestruct);
    }
}

void DrawingOptions::UpdateTreeObject()
{
    // Update Object Tree
    if (MathmodRef->RootObjet.CurrentJsonObject["ParIso"].isArray()) // isoObject
    {
        ui.ObjectClasseCurrent->model()->removeRows(
            0, ui.ObjectClasseCurrent->model()->rowCount());
        for (uint i = 0; i < MathmodRef->RootObjet.CurrentParisoTreestruct.size();
                i++)
        {
            QTreeWidgetItem *parisochild = new QTreeWidgetItem(ui.ObjectClasseCurrent);
            if (MathmodRef->RootObjet.CurrentParisoTreestruct[i].type == ISO_TYPE)
                AddIsoObjectToTree(parisochild,MathmodRef->RootObjet.CurrentParisoTreestruct[i]);
            else
                AddParObjectToTree(parisochild,MathmodRef->RootObjet.CurrentParisoTreestruct[i]);
        }
    }
    else
    {
        if (MathmodRef->RootObjet.CurrentJsonObject["Iso3D"].isObject()) // isoObject
        {
            ui.ObjectClasseCurrent->model()->removeRows(0, ui.ObjectClasseCurrent->model()->rowCount());
            QTreeWidgetItem *IsolistItem = new QTreeWidgetItem(ui.ObjectClasseCurrent);
            AddIsoObjectToTree(IsolistItem, MathmodRef->RootObjet.CurrentTreestruct);
        }
        else if (MathmodRef->RootObjet.CurrentJsonObject["Param3D"].isObject() ||
                 MathmodRef->RootObjet.CurrentJsonObject["Param4D"].isObject() ||
                 MathmodRef->RootObjet.CurrentJsonObject["Param3D_C"].isObject() ||
                 MathmodRef->RootObjet.CurrentJsonObject["Param4D_C"].isObject() )
        {
            ui.ObjectClasseCurrent->model()->removeRows(0, ui.ObjectClasseCurrent->model()->rowCount());
            QTreeWidgetItem *paramlistItem =new QTreeWidgetItem(ui.ObjectClasseCurrent);
            AddParObjectToTree(paramlistItem,MathmodRef->RootObjet.CurrentTreestruct);
        }
    }
}

void DrawingOptions::UpdatePar4DModelDetailsPage(TreeStruct &currentstruct)
{
    ui.ParamComponent_2->clear();
    if (!currentstruct.name.empty())
        ui.groupBox->setTitle(currentstruct.name.at(0));
    ui.ParamComponent_2->insertItems(0, currentstruct.Component);
    ui.stackedProperties->setCurrentIndex(3);
    UpdateDescription(0, PAR_4D_TYPE, currentstruct);
}

void DrawingOptions::UpdatePar3DModelDetailsPage(TreeStruct &currentstruct)
{
    ui.ParamComponent->clear();
    if (!currentstruct.name.empty())
        ui.groupBox->setTitle(currentstruct.name.at(0));
    ui.ParamComponent->insertItems(0, currentstruct.Component);
    ui.stackedProperties->setCurrentIndex(2);
    ui.ShowParComp->setChecked(true);
    ui.ShowParComp->setText("Show");
    UpdateDescription(0, PAR_TYPE, currentstruct);
}

void DrawingOptions::UpdateIsoModelDetailsPage(TreeStruct &currentstruct)
{
    ui.stackedProperties->setCurrentIndex(1);
    if (!currentstruct.name.empty())
        ui.groupBox->setTitle(currentstruct.name.at(0));
    ui.IsoComponent->clear();
    ui.IsoComponent->insertItems(0, currentstruct.Component);
    ui.ShowIsoComp->setChecked(true);
    ui.ShowIsoComp->setText("Show");
    UpdateDescription(0, ISO_TYPE, currentstruct);
}

void DrawingOptions::UpdateScriptEditorAndTreeObject()
{
    // Update the current Tree Object:
    if (ShowCurrentObjectTree)
        UpdateTreeObject();
    // Update the "Script Edit" page
    ui.ScriptEditor->setText(MathmodRef->RootObjet.CurrentTreestruct.text);
    // Update the "Model Details" page
    if (MathmodRef->RootObjet.CurrentJsonObject["ParIso"].isArray())
    {
        ui.parisocomboBox->clear();
        if (MathmodRef->RootObjet.CurrentParisoTreestruct.size() > 0)
        {
            for (uint i = 0; i < MathmodRef->RootObjet.CurrentParisoTreestruct.size();i++)
                ui.parisocomboBox->insertItem(i, MathmodRef->RootObjet.CurrentParisoTreestruct[i].name[0]);
            if (MathmodRef->RootObjet.CurrentParisoTreestruct[0].fxyz.size() != 0)
                UpdateIsoModelDetailsPage(MathmodRef->RootObjet.CurrentParisoTreestruct[0]);
            else if (MathmodRef->RootObjet.CurrentParisoTreestruct[0].fw.size() != 0)
                UpdatePar4DModelDetailsPage(MathmodRef->RootObjet.CurrentParisoTreestruct[0]);
            else if (MathmodRef->RootObjet.CurrentParisoTreestruct[0].fx.size() != 0)
                UpdatePar3DModelDetailsPage(MathmodRef->RootObjet.CurrentParisoTreestruct[0]);
        }
    }
    else if (MathmodRef->RootObjet.CurrentJsonObject["Iso3D"].isObject())
        UpdateIsoModelDetailsPage(MathmodRef->RootObjet.CurrentTreestruct);
    else if (MathmodRef->RootObjet.CurrentJsonObject["Param3D"].isObject() ||
             MathmodRef->RootObjet.CurrentJsonObject["Param3D_C"].isObject())
        UpdatePar3DModelDetailsPage(MathmodRef->RootObjet.CurrentTreestruct);
    else if (MathmodRef->RootObjet.CurrentJsonObject["Param4D"].isObject() ||
             MathmodRef->RootObjet.CurrentJsonObject["Param4D_C"].isObject())
        UpdatePar4DModelDetailsPage(MathmodRef->RootObjet.CurrentTreestruct);
    else
        ui.stackedProperties->setCurrentIndex(0);
}

void DrawingOptions::HideSliders()
{
    ui.groupBox_9->hide();
    ui.groupBox_10->hide();
    ui.groupBox_11->hide();
    ui.groupBox_12->hide();
    ui.groupBox_13->hide();
    ui.groupBox_14->hide();
    ui.groupBox_15->hide();
    ui.groupBox_16->hide();
    ui.groupBox_17->hide();
    ui.groupBox_18->hide();
    ui.groupBox_19->hide();
    ui.groupBox_20->hide();
    ui.groupBox_21->hide();
    ui.groupBox_22->hide();
    ui.groupBox_23->hide();
    ui.groupBox_24->hide();
    ui.groupBox_25->hide();
    ui.groupBox_26->hide();
    ui.groupBox_27->hide();
    ui.groupBox_28->hide();
    ui.PredefinedSets->clear();
    ui.PredefinedSets->addItem("Predefined Sets");
    ui.ParametersList->clear();
    ui.ParametersList->addItem("Parameters List");
    sliderconf.ui.ParametersComboBox->clear();
    sliderconf.ui.ParametersComboBox->addItem("Parameters List");
}
void DrawingOptions::ObjArrayToString(QJsonArray &lst, QString &str)
{
    str = "";
    for (int j = 0; j < lst.size() - 1; j++)
        str += lst[j].toString() + ";";
    if (lst.size() >= 1)
        str += lst[lst.size() - 1].toString();
    str.replace("\n", "");
    str.replace("\t", "");
    str.replace(" ", "");
}
void DrawingOptions::ObjArrayToInternalFunctEnum(QJsonArray &lst, std::vector<InternalFuncDefinition> &strFunct)
{
    std::string str;
    uint size = InternalFunctions.size();
    uint lstsize =lst.size();
    strFunct.clear();
    if(lst.size()>0)
    {
        if((lst[0].toString().replace("\n", "").replace("\n", "").replace(" ", "").toStdString()) == "All")
        {
            for(uint i=0; i<size; i++)
            {
                strFunct.push_back(InternalFunctions[i]);
            }
        }
        else
        {
            for (uint j = 0; j < lstsize; j++)
            {
                str=lst[j].toString().replace("\n", "").replace("\n", "").replace(" ", "").toStdString();
                for(uint i=0; i<size; i++)
                {
                    if(str == InternalFunctions[i].name)
                    {
                        strFunct.push_back(InternalFunctions[i]);
                        i=size;
                    }
                }
            }
        }
    }
}
void DrawingOptions::ShowSliders(const QJsonObject &Jobj)
{
    QString result;
    QJsonArray lst;
    QJsonObject QObj;
    if (Jobj["Sliders"].isObject())
    {
        // Hide all sliders
        HideSliders();
        QObj = Jobj["Sliders"].toObject();
        // Min
        lst = QObj["Min"].toArray();
        ObjArrayToString(lst, result);
        qlstmin = result.split(";", Qt::SkipEmptyParts);
        // Max
        lst = QObj["Max"].toArray();
        ObjArrayToString(lst, result);
        qlstmax = result.split(";",Qt::SkipEmptyParts);
        // Position
        lst = QObj["Position"].toArray();
        ObjArrayToString(lst, result);
        qlstPos = result.split(";",Qt::SkipEmptyParts);
        for (int i = 0; i < qlstPos.size(); ++i)
        {
            MathmodRef->IsoObjet->masterthread->SliderValues.push_back(
                qlstPos.at(i).toDouble());
            MathmodRef->ParObjet->masterthread->SliderValues.push_back(
                qlstPos.at(i).toDouble());
        }
        // Name
        lst = QObj["Name"].toArray();
        ObjArrayToString(lst, result);
        qlstnames = result.split(";",Qt::SkipEmptyParts);
        for (int i = 0; i < qlstnames.size(); ++i)
        {
            MathmodRef->IsoObjet->masterthread->SliderNames.push_back(
                qlstnames.at(i).toStdString());
            MathmodRef->ParObjet->masterthread->SliderNames.push_back(
                qlstnames.at(i).toStdString());
        }
        MathmodRef->IsoObjet->masterthread->Nb_Sliders =
            uint(qlstnames.size());
        MathmodRef->ParObjet->masterthread->Nb_Sliders =
            uint(qlstnames.size());
        ui.ParametersList->clear();
        ui.ParametersList->addItem("Parameters List  (" +
                                   QString::number(qlstnames.size()) + ")");
        ui.ParametersList->addItems(qlstnames);
        sliderconf.ui.ParametersComboBox->clear();
        sliderconf.ui.ParametersComboBox->addItem(
            "Parameters List  (" + QString::number(qlstnames.size()) + ")");
        sliderconf.ui.ParametersComboBox->addItems(qlstnames);
        // Step
        lst = QObj["Step"].toArray();
        ObjArrayToString(lst, result);
        qlstStep = result.split(";",Qt::SkipEmptyParts);
        QStringList qlist;
        if (qlstPos.size() >= qlstnames.size())
        {
            ui.PredefinedSets->clear();
            int NbSets = (qlstPos.size() == 0 || qlstnames.size() == 0)
                         ? 0
                         : qlstPos.size() / qlstnames.size();
            qlist += "Predefined Sets (" + QString::number(NbSets) + ")";
            if (QObj["SetNames"].isArray() &&
                    (lst = QObj["SetNames"].toArray()).size())
            {
                ObjArrayToString(lst, result);
                qlist += result.split(";",Qt::SkipEmptyParts);
            }
            else
            {
                for (int i = 1; i < NbSets + 1; i++)
                {
                    qlist += "Set_" + QString::number(i);
                }
            }
            ui.PredefinedSets->addItems(qlist);
        }
        for (int sl = 0; sl < 20; sl++)
        {
            if (qlstnames.size() >= (sl + 1))
            {
                (SliderArray[sl].SliderScrollBar)->blockSignals(true);
                (SliderArray[sl].SliderScrollBar)->setMaximum(qlstmax.at(sl).toInt());
                (SliderArray[sl].SliderScrollBar)->setMinimum(qlstmin.at(sl).toInt());
                (SliderArray[sl].SliderScrollBar)
                ->setSingleStep(qlstStep.at(sl).toInt());
                (SliderArray[sl].SliderScrollBar)->setPageStep(qlstStep.at(sl).toInt());
                (SliderArray[sl].SliderScrollBar)
                ->setSliderPosition(qlstPos.at(sl).toInt());
                (SliderArray[sl].SliderLabel)
                ->setText(qlstnames.at(sl) + " = " + qlstPos.at(sl) + "(" +
                          qlstStep.at(sl) + ")");
                (SliderArray[sl].SliderLabelMin)->setText(qlstmin.at(sl));
                (SliderArray[sl].SliderLabelMax)->setText(qlstmax.at(sl));
                (SliderArray[sl].SliderScrollBar)->blockSignals(false);
                (SliderArray[sl].SliderGroupeBox)->show();
            }
        }
    }
    else
    {
        MathmodRef->IsoObjet->masterthread->Nb_Sliders = 0;
        MathmodRef->ParObjet->masterthread->Nb_Sliders = 0;
        HideSliders();
    }
}

void DrawingOptions::DrawJsonModel(const QJsonObject &Jobj, int textureIndex,
                                   bool Inspect)
{
    if (!MathmodRef->ParObjet->isRunning() &&
            !MathmodRef->IsoObjet->isRunning())
    {
        if (Inspect & !VerifiedJsonModel(Jobj, Inspect))
            return;
        ShowJsonModel(Jobj, textureIndex);
        UpdateScriptEditorAndTreeObject();
    }
}

QString DrawingOptions::MandatoryParFieldToQString(const MandatoryParField &idx)
{
    QString arg = "";
    switch (idx)
    {
    case PAR_FX:
        arg = "Fx";
        break;
    case PAR_FY:
        arg = "Fy";
        break;
    case PAR_FZ:
        arg = "Fz";
        break;
    case PAR_FW:
        arg = "Fw";
        break;
    case PAR_UMAX:
        arg = "Umax";
        break;
    case PAR_UMIN:
        arg = "Umin";
        break;
    case PAR_VMAX:
        arg = "Vmax";
        break;
    case PAR_VMIN:
        arg = "Vmin";
        break;
    case PAR_NAME:
        arg = "Name";
        break;
    case PAR_COMP:
        arg = "Component";
        break;
    }
    return(arg);
}

QString DrawingOptions::MandatoryIsoFieldToQString(const MandatoryIsoField &idx)
{
    QString arg = "";
    switch (idx)
    {
    case ISO_FXYZ:
        arg = "Fxyz";
        break;
    case ISO_XMAX:
        arg = "Xmax";
        break;
    case ISO_YMAX:
        arg = "Ymax";
        break;
    case ISO_ZMAX:
        arg = "Zmax";
        break;
    case ISO_XMIN:
        arg = "Xmin";
        break;
    case ISO_YMIN:
        arg = "Ymin";
        break;
    case ISO_ZMIN:
        arg = "Zmin";
        break;
    case ISO_NAME:
        arg = "Name";
        break;
    case ISO_COMP:
        arg = "Component";
        break;
    }
    return(arg);
}

bool DrawingOptions::VerifyIsoFieldEmptySpace(const QJsonObject &QObj, const MandatoryIsoField &idx)
{
    QString arg = MandatoryIsoFieldToQString(idx);
    for(int i=0; i<(QObj[arg].toArray()).size(); i++)
    {
        if((QObj[arg].toArray())[i].toString().replace(" ","") == "")
        {
            return false;
        }
    }
    return true;
}

bool DrawingOptions::VerifyParFieldEmptySpace(const QJsonObject &QObj, const MandatoryParField &idx)
{
    QString arg = MandatoryParFieldToQString(idx);
    for(int i=0; i<(QObj[arg].toArray()).size(); i++)
    {
        if((QObj[arg].toArray())[i].toString().replace(" ","") == "")
            return false;
    }
    return true;
}

bool DrawingOptions::VerifyParEmptySpace(const QJsonObject& QObj)
{
    for (std::vector<MandatoryParField>::const_iterator it =
                MandParFields.begin();
            it != MandParFields.end(); ++it)
    {
        MandatoryParField Opt = *it;
        if(!VerifyParFieldEmptySpace(QObj, Opt))
            return false;
    }
    return true;
}

bool DrawingOptions::VerifyIsoEmptySpace(const QJsonObject& QObj)
{
    for (std::vector<MandatoryIsoField>::const_iterator it =
                MandIsoFields.begin();
            it != MandIsoFields.end(); ++it)
    {
        MandatoryIsoField Opt = *it;
        if(!VerifyIsoFieldEmptySpace(QObj, Opt))
            return false;
    }
    return true;
}

bool DrawingOptions::VerifiedIsoJsonModel(const QJsonObject &QObj)
{
    QJsonArray lst;
    int NbFxyz;
    if (!VerifyIsoEmptySpace(QObj))
    {
        scriptErrorType = EMPTY_MANDATORY_FIELD;
        ErrorMsg();
        return false;
    }
    // Fxyz
    NbFxyz = (QObj["Fxyz"].toArray()).size();
    if ((QObj["Xmax"].toArray()).size() != NbFxyz)
    {
        scriptErrorType = XMAX_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if ((QObj["Ymax"].toArray()).size() != NbFxyz)
    {
        scriptErrorType = YMAX_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if ((QObj["Zmax"].toArray()).size() != NbFxyz)
    {
        scriptErrorType = ZMAX_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if ((QObj["Xmin"].toArray()).size() != NbFxyz)
    {
        scriptErrorType = XMIN_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if ((QObj["Ymin"].toArray()).size() != NbFxyz)
    {
        scriptErrorType = YMIN_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if ((QObj["Zmin"].toArray()).size() != NbFxyz)
    {
        scriptErrorType = ZMIN_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if ((QObj["Component"].toArray()).size() != NbFxyz)
    {
        scriptErrorType = COMPONENT_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if (((lst = QObj["Grid"].toArray()).size() > 0) && (lst.size() != NbFxyz))
    {
        scriptErrorType = GRID_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    // variables
    if (((lst = QObj["Vect"].toArray()).size() > 1))
    {
        scriptErrorType = VECT_DIMENSION_ERROR;
        ErrorMsg();
        return false;
    }
    if (lst.size() > 0)
    {
        for (int i = 0; i < lst.size(); i++)
            if ((lst[i].toString()).toUInt() >= uint(Parameters->IsoMaxGrid))
            {
                scriptErrorType = GRID_SUPERIOR_TO_GRIDMAX;
                ErrorMsg();
                return false;
            }
    }
    if (((QObj["Cnd"].toArray()).size() > 0) &&
            ((QObj["Cnd"].toArray()).size() != NbFxyz))
    {
        scriptErrorType = CND_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    return true;
}

bool DrawingOptions::VerifiedParJsonModel(const QJsonObject &QObj)
{
    QJsonArray lst;
    int NbFx;
    if (!VerifyParEmptySpace(QObj))
    {
        scriptErrorType = EMPTY_MANDATORY_FIELD;
        ErrorMsg();
        return false;
    }
    // Fx
    NbFx = (QObj["Fx"].toArray()).size();
    // Fy
    if ((QObj["Fy"].toArray()).size() != NbFx)
    {
        scriptErrorType = FY_FX_MISMATCH;
        ErrorMsg();
        return false;
    }
    // Fz
    if ((QObj["Fz"].toArray()).size() != NbFx)
    {
        scriptErrorType = FZ_FX_MISMATCH;
        ErrorMsg();
        return false;
    }
    if (((QObj["Fw"].toArray()).size() != 0) &&
            ((QObj["Fw"].toArray()).size() != NbFx))
    {
        scriptErrorType = FW_FX_MISMATCH;
        ErrorMsg();
        return false;
    }
    if ((QObj["Umax"].toArray()).size() != NbFx)
    {
        scriptErrorType = UMAX_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if ((QObj["Vmax"].toArray()).size() != NbFx)
    {
        scriptErrorType = VMAX_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if (((QObj["Wmax"].toArray()).size() > 0) &&
            ((QObj["Wmax"].toArray()).size() != NbFx))
    {
        scriptErrorType = WMAX_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if ((QObj["Umin"].toArray()).size() != NbFx)
    {
        scriptErrorType = UMIN_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if ((QObj["Vmin"].toArray()).size() != NbFx)
    {
        scriptErrorType = VMIN_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if (((QObj["Wmin"].toArray()).size() > 0) &&
            ((QObj["Wmin"].toArray()).size() != NbFx))
    {
        scriptErrorType = WMIN_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if ((QObj["Component"].toArray()).size() != NbFx)
    {
        scriptErrorType = COMPONENT_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    // Start Grid field processing
    if ((lst = QObj["Grid"].toArray()).size() > 0 && (lst.size() != 2 * NbFx))
    {
        scriptErrorType = GRID_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    if (((lst = QObj["Vect"].toArray()).size() > 1))
    {
        scriptErrorType = VECT_DIMENSION_ERROR;
        ErrorMsg();
        return false;
    }
    if (((QObj["Cnd"].toArray()).size() > 0) &&
            ((QObj["Cnd"].toArray()).size() != NbFx))
    {
        scriptErrorType = CND_NBCOMPONENT_MISMATCH;
        ErrorMsg();
        return false;
    }
    return true;
}

bool DrawingOptions::VerifiedJsonModel(const QJsonObject &Jobj, bool Inspect)
{
    QJsonObject QObj;
    bool verif = false;
    if (!Inspect)
        return true;
    if (Jobj["Iso3D"].isObject())
    {
        QObj = Jobj["Iso3D"].toObject();
        verif = VerifiedIsoJsonModel(QObj);
        if (verif)
        {
            MathmodRef->LocalScene.componentsinfos.pariso = false;
            MathmodRef->LocalScene.componentsinfos.ParisoNbComponents =1;
            MathmodRef->LocalScene.componentsinfos.ParisoCurrentComponentIndex = 0;
        }
        return (verif);
    }
    if (Jobj["Param3D"].isObject() || Jobj["Param3D_C"].isObject() ||
        Jobj["Param4D"].isObject() || Jobj["Param4D_C"].isObject())
    {
        if(Jobj["Param3D"].isObject())
            QObj = Jobj["Param3D"].toObject();
        else if(Jobj["Param4D"].isObject())
                QObj = Jobj["Param4D"].toObject();
        else if(Jobj["Param3D_C"].isObject())
                QObj = Jobj["Param3D_C"].toObject();
        else if(Jobj["Param4D_C"].isObject())
                QObj = Jobj["Param4D_C"].toObject();
        MathmodRef->LocalScene.componentsinfos.ParisoNbComponents = 1;
        verif = VerifiedParJsonModel(QObj);
        if (verif)
        {
            MathmodRef->LocalScene.componentsinfos.pariso = false;
            MathmodRef->LocalScene.componentsinfos.ParisoNbComponents = 1;
            MathmodRef->LocalScene.componentsinfos.ParisoCurrentComponentIndex = 0;
        }
        return (verif);
    }
    if (Jobj["ParIso"].isArray())
    {
        QJsonArray listeObj = Jobj["ParIso"].toArray();
        QJsonArray listeIsoObj;
        QJsonArray listeParObj;
        for (int i = 0; i < listeObj.size(); i++)
            if ((listeObj[i].toObject())["Iso3D"].isObject())
                listeIsoObj.append(listeObj[i].toObject()["Iso3D"].toObject());
            else
                listeParObj.append(listeObj[i].toObject()["Param3D"].toObject());
        MathmodRef->LocalScene.componentsinfos.pariso = true;
        MathmodRef->LocalScene.componentsinfos.ParisoNbComponents = listeIsoObj.size() + listeParObj.size();
        MathmodRef->LocalScene.componentsinfos.ParisoCurrentComponentIndex = 0;
        for (int i = 0; i < listeIsoObj.size(); i++)
            if (!VerifiedIsoJsonModel(listeIsoObj[i].toObject()))
                return (false);
        for (int i = 0; i < listeParObj.size(); i++)
            if (!VerifiedParJsonModel(listeParObj[i].toObject()))
                return (false);
    }
    return true;
}

void DrawingOptions::LoadTexture(const QJsonObject &QObj,
                                 const ModelType &opt)
{
    QString noise1 = QObj["Noise"].toString();
    QJsonArray lst = QObj["Colors"].toArray();
    bool hsv=false;
    noise1.replace("\n", "");
    noise1.replace("\t", "");
    noise1.replace(" ", "");
    QString result;
    ObjArrayToString(lst, result);

    if (opt == ISO_TYPE)
    {
        MathmodRef->IsoObjet->masterthread->Rgbt = result.toStdString();
        MathmodRef->IsoObjet->masterthread->Noise = noise1.toStdString();
        MathmodRef->IsoObjet->masterthread->RgbtSize = uint(lst.size());
    }
    else if (opt == PAR_TYPE || opt == PAR_4D_TYPE)
    {
        MathmodRef->ParObjet->masterthread->Rgbt = result.toStdString();
        MathmodRef->ParObjet->masterthread->Noise = noise1.toStdString();
        MathmodRef->ParObjet->masterthread->RgbtSize = uint(lst.size());
    }
    if((hsv=result.contains("H=")))
        MathmodRef->LocalScene.componentsinfos.hsv.push_back(hsv);
    MathmodRef->RootObjet.CurrentTreestruct.Noise = noise1;
    MathmodRef->RootObjet.CurrentTreestruct.RGBT = result.split(";",Qt::SkipEmptyParts);
}

void DrawingOptions::LoadPigment(const QJsonObject &QObj,
                                 const ModelType &opt)
{
    QString noise = "";
    QJsonArray tmp;
    bool hsv=false;
    QString strtmp = QObj["Gradient"].toString();
    noise = QObj["Noise"].toString();
    QJsonArray lst = QObj["Colors"].toArray();
    QString result = "";
    int VRgbtSize = 0;
    for (int j = 0; j < lst.size(); j++)
    {
        tmp = (lst[j].toObject())["Color"].toObject()["Vrgba"].toArray();
        for (int k = 0; k < tmp.count(); k++)
        {
            result += tmp[k].toString() + ";";
            VRgbtSize++;
        }
    }
    strtmp.replace("\n", "");
    strtmp.replace("\t", "");
    strtmp.replace(" ", "");
    noise.replace("\n", "");
    noise.replace("\t", "");
    noise.replace(" ", "");
    result.replace("\n", "");
    result.replace("\t", "");
    result.replace(" ", "");
    if (opt == ISO_TYPE)
    {
        MathmodRef->IsoObjet->masterthread->Gradient = strtmp.toStdString();
        MathmodRef->IsoObjet->masterthread->VRgbt = result.toStdString();
        MathmodRef->IsoObjet->masterthread->Noise = noise.toStdString();
        MathmodRef->IsoObjet->masterthread->VRgbtSize = uint(VRgbtSize);
    }
    else if (opt == PAR_TYPE || opt == PAR_4D_TYPE)
    {
        MathmodRef->ParObjet->masterthread->Gradient = strtmp.toStdString();
        MathmodRef->ParObjet->masterthread->VRgbt = result.toStdString();
        MathmodRef->ParObjet->masterthread->Noise = noise.toStdString();
        MathmodRef->ParObjet->masterthread->VRgbtSize = uint(VRgbtSize);
    }
    if((hsv=result.contains("H=")))
        MathmodRef->LocalScene.componentsinfos.hsv.push_back(hsv);
    MathmodRef->RootObjet.CurrentTreestruct.Noise = noise;
    MathmodRef->RootObjet.CurrentTreestruct.VRGBT =
        result.split(";",Qt::SkipEmptyParts);
}

void DrawingOptions::ShowJsonModel(const QJsonObject &Jobj, int textureIndex)
{
    QJsonObject QObj, QIso, QPar;
    QJsonObject QTextureObj, QPigmentObj;
    bool loadtext, loadpigm;
    QJsonDocument document;
    if (textureIndex != -1)
    {
        if (textureIndex < 1000)
            QTextureObj = MathmodRef->collection.JTextures[textureIndex]
                          .toObject()["Texture"]
                          .toObject();
        else
            QPigmentObj = MathmodRef->collection.JPigments[textureIndex - 1000]
                          .toObject()["Pigment"]
                          .toObject();
    }
    else
    {
        if (Jobj["Texture"].isObject())
            QTextureObj = Jobj["Texture"].toObject();

        if (Jobj["Pigment"].isObject())
            QPigmentObj = Jobj["Pigment"].toObject();
    }

    ShowSliders(Jobj);
    updateCurrentTreestruct();
    MathmodRef->LocalScene.componentsinfos.ParisoCondition.clear();
    MathmodRef->LocalScene.componentsinfos.hsv.clear();
    if (Jobj["ParIso"].isArray())
    {
        QJsonArray listeObj = Jobj["ParIso"].toArray();
        QJsonArray listeIsoObj;
        QJsonArray listeParObj;
        for (int i = 0; i < listeObj.size(); i++)
            if ((listeObj[i].toObject())["Iso3D"].isObject())
                listeIsoObj.append(listeObj[i].toObject());
            else
                listeParObj.append(listeObj[i].toObject());
        // Right now, we only support pariso object with 1 Iso3D and 1 Param3D objects.
        if (listeParObj.size() > 0)
            QPar = listeParObj[0].toObject();
        if (listeIsoObj.size() > 0)
            QIso = listeIsoObj[0].toObject();
        if (QPar["Texture"].isObject())
        {
            QTextureObj = QPar["Texture"].toObject();
        }
        if (QPar["Pigment"].isObject())
            QPigmentObj = QPar["Pigment"].toObject();
        // Colors
        MathmodRef->ParObjet->masterthread->Noise="";
        loadtext = MathmodRef->ParObjet->masterthread->rgbtnotnull =
                       (QPar["Texture"].isObject() ||
                        ((textureIndex < 1000) && (textureIndex != -1)));
        // Pigment
        loadpigm = MathmodRef->ParObjet->masterthread->vrgbtnotnull =
                       (QPar["Pigment"].isObject() ||
                ((textureIndex != -1) && (textureIndex > 999)));

        LoadMandatoryAndOptionnalFields(QPar["Param3D"].toObject(), PAR_TYPE,
                                        loadtext, QTextureObj, loadpigm,
                                        QPigmentObj);
        // Save this Current Parametric Tree struct
        MathmodRef->RootObjet.CurrentParisoTreestruct.push_back(
            MathmodRef->RootObjet.CurrentTreestruct);
        if (QIso["Texture"].isObject())
            QTextureObj = QIso["Texture"].toObject();
        if (QIso["Pigment"].isObject())
            QPigmentObj = QIso["Pigment"].toObject();
        // Colors
        MathmodRef->IsoObjet->masterthread->Noise="";
        loadtext = MathmodRef->IsoObjet->masterthread->rgbtnotnull =
                       (QIso["Texture"].isObject() ||
                        ((textureIndex < 1000) && (textureIndex != -1)));
        // Pigment
        loadpigm = MathmodRef->IsoObjet->masterthread->vrgbtnotnull =
                       (QIso["Pigment"].isObject() ||
                ((textureIndex != -1) && (textureIndex > 999)));

        LoadMandatoryAndOptionnalFields(QIso["Iso3D"].toObject(), ISO_TYPE,
                                        loadtext, QTextureObj, loadpigm,
                                        QPigmentObj);
        // Save this Current Isosurface Tree struct
        MathmodRef->RootObjet.CurrentParisoTreestruct.push_back(
            MathmodRef->RootObjet.CurrentTreestruct);
        document.setObject(Jobj);
        MathmodRef->RootObjet.CurrentTreestruct.text = QString(document.toJson());
        // Update the current pariso struct
        MathmodRef->RootObjet.CurrentJsonObject = Jobj;
        CurrentFormulaType = 2;
        /// process the new surface
        if (textureIndex == -1)
        {
            MathmodRef->LocalScene.componentsinfos.pariso = true;
            MathmodRef->ParisoObjectProcess();
        }
        ui.parisogroupbox->show();
    }
    else
    {
        ui.parisogroupbox->hide();
        MathmodRef->LocalScene.componentsinfos.pariso = false;
        if (Jobj["Iso3D"].isObject())
        {
            QObj = Jobj["Iso3D"].toObject();

            // Colors
            MathmodRef->IsoObjet->masterthread->Noise="";
            loadtext = MathmodRef->IsoObjet->masterthread->rgbtnotnull =
                           (Jobj["Texture"].isObject() ||
                            ((textureIndex < 1000) && (textureIndex != -1)));
            // Pigment
            loadpigm = MathmodRef->IsoObjet->masterthread->vrgbtnotnull =
                           (Jobj["Pigment"].isObject() ||
                    ((textureIndex != -1) && (textureIndex > 999)));

            LoadMandatoryAndOptionnalFields(QObj, ISO_TYPE, loadtext, QTextureObj,
                                            loadpigm, QPigmentObj);
            QJsonObject Jobjtmp = Jobj;
            // Some keys cleaning..
            Jobjtmp.remove("ParIso");
            Jobjtmp.remove("Param3D");Jobjtmp.remove("Param3D_C");
            Jobjtmp.remove("Param4D");Jobjtmp.remove("Param4D_C");
            document.setObject(Jobjtmp);
            MathmodRef->RootObjet.CurrentTreestruct.text = QString(document.toJson());
            // Update the current parametric struct
            MathmodRef->RootObjet.CurrentJsonObject = Jobjtmp;
            CurrentFormulaType = 2;
            /// process the new surface
            if (textureIndex == -1)
            {
                if (MathmodRef->RootObjet.CurrentTreestruct.fxyz.count() > 0)
                    MathmodRef->ProcessNewIsoSurface();
            }
            else
            {
                int result = MathmodRef->ParseIso();
                if (result == -1)
                    return;
                textureIndex < 1000
                ? MathmodRef->CalculateTexturePoints(1)
                : MathmodRef->CalculatePigmentPoints(1);
                MathmodRef->LocalScene.componentsinfos.Interleave=true;
                MathmodRef->update();
            }
        }
        else if (Jobj["Param3D"].isObject() || (MathmodRef->ParObjet->masterthread->param3d_C=Jobj["Param3D_C"].isObject()))
        {
            if(Jobj["Param3D"].isObject())
                QObj = Jobj["Param3D"].toObject();
            else
                QObj = Jobj["Param3D_C"].toObject();
            // Colors
            MathmodRef->ParObjet->masterthread->Noise="";
            loadtext = MathmodRef->ParObjet->masterthread->rgbtnotnull =
                           (Jobj["Texture"].isObject() ||
                            ((textureIndex < 1000) && (textureIndex != -1)));

            // Pigment
            loadpigm = MathmodRef->ParObjet->masterthread->vrgbtnotnull =
                           (Jobj["Pigment"].isObject() ||
                    ((textureIndex != -1) && (textureIndex > 999)));

            LoadMandatoryAndOptionnalFields(QObj, PAR_TYPE, loadtext, QTextureObj,
                                            loadpigm, QPigmentObj);

            QJsonObject Jobjtmp = Jobj;
            // Some keys cleaning..
            if(Jobj["Param3D"].isObject())
                Jobjtmp.remove("Param3D_C");
            else
                Jobjtmp.remove("Param3D");
            Jobjtmp.remove("ParIso");
            Jobjtmp.remove("Iso3D");
            Jobjtmp.remove("Param4D");

            QJsonDocument document;
            document.setObject(Jobjtmp);
            MathmodRef->RootObjet.CurrentTreestruct.text = QString(document.toJson());

            MathmodRef->RootObjet.CurrentJsonObject = Jobjtmp;
            CurrentFormulaType = 1;
            /// process the new surface
            if (textureIndex == -1)
            {
                MathmodRef->ParametricSurfaceProcess(1);
            }
            else
            {
                int result = MathmodRef->ParsePar();
                if (result == -1)
                    return;
                textureIndex < 1000
                ? MathmodRef->CalculateTexturePoints(0)
                : MathmodRef->CalculatePigmentPoints(0);
                MathmodRef->LocalScene.componentsinfos.Interleave=true;
                MathmodRef->update();
            }
        }
        else if (Jobj["Param4D"].isObject() || (MathmodRef->ParObjet->masterthread->param4d_C=Jobj["Param4D_C"].isObject()))
        {
            if (Jobj["Param4D"].isObject())
                QObj = Jobj["Param4D"].toObject();
            else
                QObj = Jobj["Param4D_C"].toObject();
            // Colors
            MathmodRef->ParObjet->masterthread->Noise="";
            loadtext = MathmodRef->ParObjet->masterthread->rgbtnotnull =
                           (Jobj["Texture"].isObject() ||
                            ((textureIndex < 1000) && (textureIndex != -1)));
            // Pigment
            loadpigm = MathmodRef->ParObjet->masterthread->vrgbtnotnull =
                           (Jobj["Pigment"].isObject() ||
                    ((textureIndex != -1) && (textureIndex > 1000)));
            LoadMandatoryAndOptionnalFields(QObj, PAR_4D_TYPE, loadtext, QTextureObj,
                                            loadpigm, QPigmentObj);
            QJsonObject Jobjtmp = Jobj;
            // Some keys cleaning..
            if (Jobj["Param4D"].isObject())
                Jobjtmp.remove("Param4D_C");
            else
                Jobjtmp.remove("Param4D");
            Jobjtmp.remove("Iso3D");
            Jobjtmp.remove("Param3D");

            QJsonDocument document;
            document.setObject(Jobjtmp);
            MathmodRef->RootObjet.CurrentTreestruct.text = QString(document.toJson());
            MathmodRef->RootObjet.CurrentJsonObject = Jobjtmp;
            CurrentFormulaType = 3;
            /// process the new surface
            if (textureIndex == -1)
            {
                MathmodRef->ParametricSurfaceProcess(3);
            }
            else
            {
                int result = MathmodRef->ParsePar();
                if (result == -1)
                    return;
                textureIndex < 1000
                ? MathmodRef->CalculateTexturePoints(0)
                : MathmodRef->CalculatePigmentPoints(0);
                MathmodRef->LocalScene.componentsinfos.Interleave=true;
                MathmodRef->update();
            }
        }
    }
}

void DrawingOptions::updateCurrentTreestruct()
{
    // Initialize the current Object struct
    MathmodRef->RootObjet.CurrentTreestruct
    .fw = MathmodRef->RootObjet.CurrentTreestruct
    .fx = MathmodRef->RootObjet.CurrentTreestruct
    .fy = MathmodRef->RootObjet.CurrentTreestruct.fz =
    MathmodRef->RootObjet.CurrentTreestruct
    .Cnd = MathmodRef->RootObjet.CurrentTreestruct
    .RGBT = MathmodRef->RootObjet.CurrentTreestruct.Const =
    MathmodRef->RootObjet.CurrentTreestruct
    .Funct = MathmodRef->RootObjet.CurrentTreestruct.VRGBT =
    MathmodRef->RootObjet.CurrentTreestruct
    .Gradient = MathmodRef->RootObjet.CurrentTreestruct.fxyz =
    MathmodRef->RootObjet.CurrentTreestruct
    .umin = MathmodRef->RootObjet.CurrentTreestruct.umax =
    MathmodRef->RootObjet.CurrentTreestruct
    .vmin = MathmodRef->RootObjet.CurrentTreestruct.vmax =
    MathmodRef->RootObjet.CurrentTreestruct
    .xmin = MathmodRef->RootObjet.CurrentTreestruct
    .xmax = MathmodRef->RootObjet
    .CurrentTreestruct.ymin =
    MathmodRef->RootObjet.CurrentTreestruct.ymax =
    MathmodRef->RootObjet.CurrentTreestruct.zmin = MathmodRef->RootObjet
    .CurrentTreestruct.zmax = MathmodRef->RootObjet.CurrentTreestruct.tmin = MathmodRef->RootObjet
    .CurrentTreestruct.tmax = MathmodRef->RootObjet
    .CurrentTreestruct.name = MathmodRef->RootObjet
    .CurrentTreestruct.Component = MathmodRef->RootObjet
    .CurrentTreestruct.Grid = QStringList();
    MathmodRef->RootObjet.CurrentTreestruct.Noise =
        MathmodRef->RootObjet.CurrentTreestruct.text = "";
    MathmodRef->RootObjet.CurrentTreestruct.type = UNDEFINED_TYPE;
    // Initialize the current JSON Object
    MathmodRef->RootObjet.CurrentJsonObject = QJsonObject();
    // Initialize the Current Pariso Trees truct
    MathmodRef->RootObjet.CurrentParisoTreestruct.clear();
}

void DrawingOptions::MandatoryParFieldprocess(const QJsonObject &QObj,
        const MandatoryParField &idx,
        const ModelType &mod)
{
    QString result, arg = MandatoryParFieldToQString(idx);
    QJsonArray lst;

    lst = QObj[arg].toArray();
    ObjArrayToString(lst, result);
    switch (idx)
    {
    case PAR_FX:
        MathmodRef->ParObjet->masterthread->expression_X =
            result.toStdString();
        MathmodRef->ParObjet->masterthread->componentsNumber =
            uint(lst.size());
        MathmodRef->RootObjet.CurrentTreestruct.fx =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case PAR_FY:
        MathmodRef->ParObjet->masterthread->expression_Y =
            result.toStdString();
        MathmodRef->ParObjet->masterthread->expression_YSize =
            lst.size();
        MathmodRef->RootObjet.CurrentTreestruct.fy =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case PAR_FZ:
        MathmodRef->ParObjet->masterthread->expression_Z =
            result.toStdString();
        MathmodRef->ParObjet->masterthread->expression_ZSize =
            lst.size();
        MathmodRef->RootObjet.CurrentTreestruct.fz =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case PAR_FW:
        if (mod == PAR_4D_TYPE)
        {
            MathmodRef->ParObjet->masterthread->expression_W =
                result.toStdString();
            MathmodRef->RootObjet.CurrentTreestruct.fw =
                result.split(";",Qt::SkipEmptyParts);
        }
        break;
    case PAR_UMIN:
        MathmodRef->ParObjet->masterthread->inf_u =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.umin =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case PAR_UMAX:
        MathmodRef->ParObjet->masterthread->sup_u =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.umax =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case PAR_VMAX:
        MathmodRef->ParObjet->masterthread->sup_v =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.vmax =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case PAR_VMIN:
        MathmodRef->ParObjet->masterthread->inf_v =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.vmin =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case PAR_COMP:
        MathmodRef->RootObjet.CurrentTreestruct.Component =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case PAR_NAME:
        MathmodRef->RootObjet.CurrentTreestruct.name =
            result.split(";",Qt::SkipEmptyParts);
        break;
    }
}

void DrawingOptions::MandatoryIsoFieldprocess(const QJsonObject &QObj,
        const MandatoryIsoField &idx)
{
    QString result, arg = MandatoryIsoFieldToQString(idx);
    QJsonArray lst;

    lst = QObj[arg].toArray();
    ObjArrayToString(lst, result);
    switch (idx)
    {
    case ISO_FXYZ:
        MathmodRef->IsoObjet->masterthread->ImplicitFunction =
            result.toStdString();
        MathmodRef->IsoObjet->masterthread->componentsNumber =
            uint(lst.size());
        MathmodRef->RootObjet.CurrentTreestruct.fxyz =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case ISO_XMAX:
        MathmodRef->IsoObjet->masterthread->XlimitSup =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.xmax =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case ISO_YMAX:
        MathmodRef->IsoObjet->masterthread->YlimitSup =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.ymax =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case ISO_ZMAX:
        MathmodRef->IsoObjet->masterthread->ZlimitSup =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.zmax =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case ISO_XMIN:
        MathmodRef->IsoObjet->masterthread->XlimitInf =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.xmin =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case ISO_YMIN:
        MathmodRef->IsoObjet->masterthread->YlimitInf =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.ymin =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case ISO_ZMIN:
        MathmodRef->IsoObjet->masterthread->ZlimitInf =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.zmin =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case ISO_COMP:
        MathmodRef->RootObjet.CurrentTreestruct.Component =
            result.split(";",Qt::SkipEmptyParts);
        break;
    case ISO_NAME:
        MathmodRef->RootObjet.CurrentTreestruct.name =
            result.split(";",Qt::SkipEmptyParts);
        break;
    }
}

void DrawingOptions::OptionalIsoScriptFieldprocess(
    const QJsonObject &QObj, OptionnalIsoScriptFIELD idx)
{
    QString result, arg = "";
    QJsonArray lst;
    bool argnotnull = false;
    switch (idx)
    {
    case ISO_VECT:
        arg = "Vect";
        argnotnull = MathmodRef->IsoObjet->masterthread->vectnotnull =
                         QObj[arg].isArray();
        break;
    case ISO_GRID:
        arg = "Grid";
        argnotnull = MathmodRef->IsoObjet->masterthread->gridnotnull =
                         QObj[arg].isArray();
        break;
    case ISO_CND:
        arg = "Cnd";
        argnotnull = MathmodRef->IsoObjet->masterthread->cndnotnull =
                         QObj[arg].isArray();
        break;
    case ISO_CONST:
        arg = "Const";
        argnotnull = MathmodRef->IsoObjet->masterthread->constnotnull =
                         QObj[arg].isArray();
        break;
    case ISO_FUNCT:
        arg = "Funct";
        argnotnull = MathmodRef->IsoObjet->masterthread->functnotnull =
                         QObj[arg].isArray();
        break;
    case ISO_IMPORTFUNCT:
        arg = "Import";
        argnotnull = MathmodRef->IsoObjet->masterthread->importnotnull =
                         QObj[arg].isArray();
        break;
    }
    if (argnotnull)
    {
        lst = QObj[arg].toArray();
        ObjArrayToString(lst, result);
    }
    switch (idx)
    {
    case ISO_VECT:
        if (argnotnull)
        {
            MathmodRef->IsoObjet->masterthread->vect.clear();
            for (int j = 0; j < lst.size(); j++)
                MathmodRef->IsoObjet->masterthread->vect.push_back(
                    (lst[j].toString()).toUInt());
            MathmodRef->IsoObjet->masterthread->Vect =
                result.toStdString();
            MathmodRef->RootObjet.CurrentTreestruct.Vect =
                result.split(";",Qt::SkipEmptyParts);
        }
        else
        {
            MathmodRef->IsoObjet->masterthread->Vect = "";
        }
        break;
    case ISO_GRID:
        if (argnotnull)
        {
            MathmodRef->IsoObjet->masterthread->grid.clear();
            for (int j = 0; j < lst.size(); j++)
                MathmodRef->IsoObjet->masterthread->grid.push_back(
                    (lst[j].toString()).toUInt());
            MathmodRef->IsoObjet->masterthread->Grid =
                result.toStdString();
            MathmodRef->RootObjet.CurrentTreestruct.Grid =
                result.split(";",Qt::SkipEmptyParts);
        }
        else
        {
            MathmodRef->IsoObjet->masterthread->Grid = "";
        }
        break;
    case ISO_CND:
        if (argnotnull)
        {
            MathmodRef->IsoObjet->masterthread->Condition = result.toStdString();
            for(int i=0; i<lst.size(); i++)
                MathmodRef->LocalScene.componentsinfos.ParisoCondition.push_back((lst[i].toString()).replace(" ", "")=="");
            MathmodRef->RootObjet.CurrentTreestruct.Cnd = result.split(";");
        }
        else
        {
            for(int i=0; i<lst.size(); i++)
                MathmodRef->LocalScene.componentsinfos.ParisoCondition.push_back(false);
            MathmodRef->IsoObjet->masterthread->Condition = "";
        }
        break;
    case ISO_FUNCT:
        if (argnotnull)
        {
            MathmodRef->IsoObjet->masterthread->Funct = result.toStdString();
            MathmodRef->IsoObjet->masterthread->FunctSize = uint(lst.size());
            MathmodRef->RootObjet.CurrentTreestruct.Funct = result.split(";",Qt::SkipEmptyParts);
        }
        else
        {
            MathmodRef->IsoObjet->masterthread->Funct = "";
            MathmodRef->IsoObjet->masterthread->FunctSize = 0;
        }
        break;
    case ISO_CONST:
        if (argnotnull)
        {
            MathmodRef->IsoObjet->masterthread->Const =
                result.toStdString();
            MathmodRef->IsoObjet->masterthread->ConstSize =
                uint(lst.size());
            MathmodRef->RootObjet.CurrentTreestruct.Const =
                result.split(";",Qt::SkipEmptyParts);
        }
        else
        {
            MathmodRef->IsoObjet->masterthread->Const = "";
            MathmodRef->IsoObjet->masterthread->ConstSize = 0;
        }
        break;
    case ISO_IMPORTFUNCT:
        if (argnotnull)
        {
            ObjArrayToInternalFunctEnum(lst, (MathmodRef->IsoObjet->masterthread->ImportedInternalFunctions));
        }
        else
        {
            MathmodRef->IsoObjet->masterthread->ImportedInternalFunctions.clear();
        }
        break;
    }
}

void DrawingOptions::OptionalParScriptFieldprocess(
    const QJsonObject &QObj, OptionnalParScriptFIELD idx)
{
    QString result, arg = "";
    QJsonArray lst;
    bool argnotnull = false;
    switch (idx)
    {
    case PAR_VECT:
        arg = "Vect";
        argnotnull = MathmodRef->ParObjet->masterthread->vectnotnull =
                         QObj[arg].isArray();
        break;
    case PAR_GRID:
        arg = "Grid";
        argnotnull = MathmodRef->ParObjet->masterthread->gridnotnull =
                         QObj[arg].isArray();
        break;
    case PAR_CONST:
        arg = "Const";
        argnotnull = MathmodRef->ParObjet->masterthread->constnotnull =
                         QObj[arg].isArray();
        break;
    case PAR_FUNCT:
        arg = "Funct";
        argnotnull = MathmodRef->ParObjet->masterthread->functnotnull =
                         QObj[arg].isArray();
        break;
    case PAR_CND:
        arg = "Cnd";
        argnotnull = MathmodRef->ParObjet->masterthread->cndnotnull =
                         QObj[arg].isArray();
        break;
    case PAR_IMPORTFUNCT:
        arg = "Import";
        argnotnull = MathmodRef->ParObjet->masterthread->importnotnull =
                         QObj[arg].isArray();
        break;
    }
    if (argnotnull)
    {
        lst = QObj[arg].toArray();
        ObjArrayToString(lst, result);
    }
    switch (idx)
    {
    case PAR_VECT:
        if (argnotnull)
        {
            MathmodRef->ParObjet->masterthread->vect.clear();
            for (int j = 0; j < lst.size(); j++)
                MathmodRef->ParObjet->masterthread->vect.push_back(
                    (lst[j].toString()).toUInt());
            MathmodRef->ParObjet->masterthread->Vect =
                result.toStdString();
            MathmodRef->RootObjet.CurrentTreestruct.Vect =
                result.split(";",Qt::SkipEmptyParts);
        }
        else
        {
            MathmodRef->ParObjet->masterthread->Vect = "";
        }
        break;
    case PAR_GRID:
        if (argnotnull)
        {
            MathmodRef->ParObjet->masterthread->grid.clear();
            for (int j = 0; j < lst.size(); j++)
                MathmodRef->ParObjet->masterthread->grid.push_back(
                    (lst[j].toString()).toUInt());
            MathmodRef->ParObjet->masterthread->Grid =
                result.toStdString();
            MathmodRef->RootObjet.CurrentTreestruct.Grid =
                result.split(";",Qt::SkipEmptyParts);
        }
        else
        {
            MathmodRef->ParObjet->masterthread->Grid = "";
        }
        break;
    case PAR_CND:
        if (argnotnull)
        {
            MathmodRef->ParObjet->masterthread->expression_CND = result.toStdString();
            for(int i=0; i<lst.size(); i++)
                MathmodRef->LocalScene.componentsinfos.ParisoCondition.push_back((lst[i].toString()).replace(" ", "") == "");
            MathmodRef->RootObjet.CurrentTreestruct.Cnd = result.split(";");
        }
        else
        {
            for(int i=0; i<lst.size(); i++)
                MathmodRef->LocalScene.componentsinfos.ParisoCondition.push_back(false);
            MathmodRef->ParObjet->masterthread->expression_CND = "";
        }
        break;
    case PAR_CONST:
        if (argnotnull)
        {
            MathmodRef->ParObjet->masterthread->Const = result.toStdString();
            MathmodRef->ParObjet->masterthread->ConstSize = uint(lst.size());
            MathmodRef->RootObjet.CurrentTreestruct.Const = result.split(";",Qt::SkipEmptyParts);
        }
        else
        {
            MathmodRef->ParObjet->masterthread->Const = "";
            MathmodRef->ParObjet->masterthread->ConstSize = 0;
        }
        break;
    case PAR_FUNCT:
        if (argnotnull)
        {
            MathmodRef->ParObjet->masterthread->Funct =
                result.toStdString();
            MathmodRef->ParObjet->masterthread->FunctSize =
                uint(lst.size());
            MathmodRef->RootObjet.CurrentTreestruct.Funct =
                result.split(";",Qt::SkipEmptyParts);
        }
        else
        {
            MathmodRef->ParObjet->masterthread->Funct = "";
            MathmodRef->ParObjet->masterthread->FunctSize = 0;
        }
        break;
    case PAR_IMPORTFUNCT:
        if (argnotnull)
        {
            ObjArrayToInternalFunctEnum(lst, (MathmodRef->ParObjet->masterthread->ImportedInternalFunctions));
        }
        else
        {
            MathmodRef->ParObjet->masterthread->ImportedInternalFunctions.clear();
        }
        break;
    }
}

void DrawingOptions::BuildAllVect()
{
    const OptionnalIsoScriptFIELD optiso[] = {ISO_VECT, ISO_GRID, ISO_CND, ISO_CONST, ISO_FUNCT, ISO_IMPORTFUNCT};
    OptIsoFields = std::vector<OptionnalIsoScriptFIELD>(
                       optiso, optiso + sizeof(optiso) / sizeof(OptionnalIsoScriptFIELD));

    const OptionnalParScriptFIELD optpar[] = {PAR_VECT, PAR_GRID, PAR_CND, PAR_CONST,
                                              PAR_FUNCT, PAR_IMPORTFUNCT
                                             };
    OptParFields = std::vector<OptionnalParScriptFIELD>(
                       optpar, optpar + sizeof(optpar) / sizeof(OptionnalParScriptFIELD));
    const MandatoryIsoField maniso[] = {ISO_FXYZ, ISO_XMIN, ISO_XMAX,
                                        ISO_YMIN, ISO_YMAX, ISO_ZMIN,
                                        ISO_ZMAX, ISO_COMP, ISO_NAME
                                       };
    MandIsoFields = std::vector<MandatoryIsoField>(
                        maniso, maniso + sizeof(maniso) / sizeof(MandatoryIsoField));
    const MandatoryParField manpar[] = {PAR_FX,   PAR_FY,   PAR_FZ,   PAR_FW,
                                        PAR_UMIN, PAR_UMAX, PAR_VMIN, PAR_VMAX,
                                        PAR_COMP, PAR_NAME
                                       };
    MandParFields = std::vector<MandatoryParField>(
                        manpar, manpar + sizeof(manpar) / sizeof(MandatoryParField));
}

int DrawingOptions::JSON_choice_activated(const QString &arg1)
{
    QJsonArray array = JSONMathModels["MathModels"].toArray();
    QJsonObject QObj, QObj1;
    QJsonObject QTextureObj, QPigmentObj;
    bool loadtext, loadpigm;
    QMessageBox msgBox;
    updateCurrentTreestruct();
    MathmodRef->LocalScene.componentsinfos.ParisoCondition.clear();
    MathmodRef->LocalScene.componentsinfos.hsv.clear();
    for (int i = 0; i < array.size(); i++)
    {
        if ((QObj1 = array[i].toObject())["ParIso"].isArray() &&
                (QObj1)["Name"].toString() == arg1)
        {
            if (!VerifiedJsonModel((array[i].toObject())))
                return (0);
            ShowSliders(array[i].toObject());
            QJsonArray listeObj = QObj1["ParIso"].toArray();
            QJsonArray listeIsoObj;
            QJsonArray listeParObj;
            QJsonObject QPar, QIso;
            for (int i = 0; i < listeObj.size(); i++)
                if ((listeObj[i].toObject())["Iso3D"].isObject())
                    listeIsoObj.append(listeObj[i].toObject());
                else
                    listeParObj.append(listeObj[i].toObject());
            // Right now, we only support pariso object with 1 Iso3D and 1 Param3D objects.
            if (listeParObj.size() > 0)
                QPar = listeParObj[0].toObject();
            if (listeIsoObj.size() > 0)
                QIso = listeIsoObj[0].toObject();
            if (QPar["Texture"].isObject())
                QTextureObj = QPar["Texture"].toObject();
            if (QPar["Pigment"].isObject())
                QPigmentObj = QPar["Pigment"].toObject();
            // Colors
            MathmodRef->ParObjet->masterthread->Noise="";
            loadtext = MathmodRef->ParObjet->masterthread->rgbtnotnull =
                           (QPar["Texture"].isObject());
            // Pigment
            loadpigm = MathmodRef->ParObjet->masterthread->vrgbtnotnull =
                           (QPar["Pigment"].isObject());
            LoadMandatoryAndOptionnalFields(QPar["Param3D"].toObject(), PAR_TYPE,
                                            loadtext, QTextureObj, loadpigm,
                                            QPigmentObj);
            // Save this Current Parametric Tree struct
            MathmodRef->RootObjet.CurrentParisoTreestruct.push_back(
                MathmodRef->RootObjet.CurrentTreestruct);
            loadtext = loadpigm = false;
            if (QIso["Texture"].isObject())
                QTextureObj = QIso["Texture"].toObject();
            if (QIso["Pigment"].isObject())
                QPigmentObj = QIso["Pigment"].toObject();
            // Colors
            MathmodRef->IsoObjet->masterthread->Noise="";
            loadtext = MathmodRef->IsoObjet->masterthread->rgbtnotnull =
                           (QIso["Texture"].isObject());
            // Pigment
            loadpigm = MathmodRef->IsoObjet->masterthread->vrgbtnotnull =
                           (QIso["Pigment"].isObject());
            LoadMandatoryAndOptionnalFields(QIso["Iso3D"].toObject(), ISO_TYPE,
                                            loadtext, QTextureObj, loadpigm,
                                            QPigmentObj);
            // Save this Current Isosurface Tree struct
            MathmodRef->RootObjet.CurrentParisoTreestruct.push_back(
                MathmodRef->RootObjet.CurrentTreestruct);
            QJsonDocument document;
            document.setObject(QObj1);
            MathmodRef->RootObjet.CurrentTreestruct.text = QString(document.toJson());
            // Update the current pariso struct
            MathmodRef->RootObjet.CurrentJsonObject = QObj1;
            CurrentFormulaType = 2;
            /// process the new surface
            MathmodRef->LocalScene.componentsinfos.ParisoCurrentComponentIndex = 0;
            MathmodRef->LocalScene.componentsinfos.ParisoNbComponents =2;
            MathmodRef->LocalScene.componentsinfos.pariso = true;
            MathmodRef->ParisoObjectProcess();
            ui.parisogroupbox->show();
            return (1);
        }
        else
        {
            MathmodRef->LocalScene.componentsinfos.pariso = false;
            MathmodRef->LocalScene.componentsinfos.ParisoNbComponents = 1;
            MathmodRef->LocalScene.componentsinfos.ParisoCurrentComponentIndex = 0;
            ui.parisogroupbox->hide();
            if ((QObj1 = array[i].toObject())["Iso3D"].isObject() &&
                    (QObj = (array[i].toObject())["Iso3D"].toObject())["Name"]
                    .toArray()[0]
                    .toString() == arg1)
            {
                if (!VerifiedJsonModel((array[i].toObject())))
                    return (0);
                ShowSliders(array[i].toObject());
                // Colors
                MathmodRef->IsoObjet->masterthread->Noise="";
                if ((loadtext = MathmodRef->IsoObjet->masterthread->rgbtnotnull = QObj1["Texture"].isObject()))
                    QTextureObj = QObj1["Texture"].toObject();
                // Pigment
                if ((loadpigm = MathmodRef->IsoObjet->masterthread->vrgbtnotnull = QObj1["Pigment"].isObject()))
                    QPigmentObj = QObj1["Pigment"].toObject();
                LoadMandatoryAndOptionnalFields(QObj, ISO_TYPE, loadtext, QTextureObj,
                                                loadpigm, QPigmentObj);
                QJsonDocument document;
                document.setObject(array[i].toObject());
                MathmodRef->RootObjet.CurrentTreestruct.text =
                    QString(document.toJson());
                // Update the current parametric struct
                MathmodRef->RootObjet.CurrentJsonObject = array[i].toObject();
                CurrentFormulaType = 2;
                /// process the new surface
                MathmodRef->ProcessNewIsoSurface();
                return (2);
            }
            else if (((array[i].toObject())["Param3D"].isObject() &&
                     (QObj = (array[i].toObject())["Param3D"].toObject())["Name"]
                     .toArray()[0]
                     .toString() == arg1)  ||

                     ( (MathmodRef->ParObjet->masterthread->param3d_C =  (array[i].toObject())["Param3D_C"].isObject() ) &&
                     (QObj = (array[i].toObject())["Param3D_C"].toObject())["Name"]
                     .toArray()[0]
                     .toString() == arg1))
            {
                if (!VerifiedJsonModel((array[i].toObject())))
                    return (0);
                ShowSliders(array[i].toObject());
                // Colors
                MathmodRef->ParObjet->masterthread->Noise="";
                if ((loadtext =
                            MathmodRef->ParObjet->masterthread->rgbtnotnull =
                                QObj1["Texture"].isObject()))
                    QTextureObj = QObj1["Texture"].toObject();
                // Pigment
                if ((loadpigm =
                            MathmodRef->ParObjet->masterthread->vrgbtnotnull =
                                QObj1["Pigment"].isObject()))
                    QPigmentObj = QObj1["Pigment"].toObject();
                LoadMandatoryAndOptionnalFields(QObj, PAR_TYPE, loadtext, QTextureObj,
                                                loadpigm, QPigmentObj);
                QJsonDocument document;
                document.setObject(array[i].toObject());
                MathmodRef->RootObjet.CurrentTreestruct.text =
                    QString(document.toJson());

                MathmodRef->RootObjet.CurrentJsonObject = array[i].toObject();
                CurrentFormulaType = 1;
                /// process the new surface
                MathmodRef->ParametricSurfaceProcess(1);
                return (1);
            }
            else if (((array[i].toObject())["Param4D"].isObject() &&
                     (QObj = (array[i].toObject())["Param4D"].toObject())["Name"]
                     .toArray()[0]
                     .toString() == arg1)  ||

                     ((MathmodRef->ParObjet->masterthread->param4d_C = (array[i].toObject())["Param4D_C"].isObject()) &&
                                          (QObj = (array[i].toObject())["Param4D_C"].toObject())["Name"]
                                          .toArray()[0]
                                          .toString() == arg1))
            {
                if (!VerifiedJsonModel((array[i].toObject())))
                    return (0);
                ShowSliders(array[i].toObject());
                // Colors
                MathmodRef->ParObjet->masterthread->Noise="";
                if ((loadtext =
                            MathmodRef->ParObjet->masterthread->rgbtnotnull =
                                QObj1["Texture"].isObject()))
                    QTextureObj = QObj1["Texture"].toObject();
                // Pigment
                if ((loadpigm =
                            MathmodRef->ParObjet->masterthread->vrgbtnotnull =
                                QObj1["Pigment"].isObject()))
                    QPigmentObj = QObj1["Pigment"].toObject();
                LoadMandatoryAndOptionnalFields(QObj, PAR_4D_TYPE, loadtext,
                                                QTextureObj, loadpigm, QPigmentObj);
                QJsonDocument document;
                document.setObject(array[i].toObject());
                MathmodRef->RootObjet.CurrentTreestruct.text =
                    QString(document.toJson());
                MathmodRef->RootObjet.CurrentJsonObject = array[i].toObject();
                CurrentFormulaType = 3;
                /// process the new surface
                MathmodRef->ParametricSurfaceProcess(3);
                return (3);
            }
        }
    }
    return (0);
}

void DrawingOptions::LoadMandatoryAndOptionnalFields(
    const QJsonObject &qobj, const ModelType &mod, bool loadtext,
    const QJsonObject &QTextureObj, bool loadpigm,
    const QJsonObject &QPigmentObj)
{
    // We First deactivate the pariso flag
    MathmodRef->LocalScene.componentsinfos.pariso = false;
    MathmodRef->RootObjet.CurrentTreestruct.type = mod;
    switch (mod)
    {
    case PAR_TYPE:
        for (std::vector<MandatoryParField>::const_iterator it =
                    MandParFields.begin();
                it != MandParFields.end(); ++it)
        {
            MandatoryParField Opt = *it;
            MandatoryParFieldprocess(qobj, Opt);
        }

        for (std::vector<OptionnalParScriptFIELD>::const_iterator it =
                    OptParFields.begin();
                it != OptParFields.end(); ++it)
        {
            OptionnalParScriptFIELD Opt = *it;
            OptionalParScriptFieldprocess(qobj, Opt);
        }
        break;
    case PAR_4D_TYPE:
        for (std::vector<MandatoryParField>::const_iterator it =
                    MandParFields.begin();
                it != MandParFields.end(); ++it)
        {
            MandatoryParField Opt = *it;
            MandatoryParFieldprocess(qobj, Opt, PAR_4D_TYPE);
        }

        for (std::vector<OptionnalParScriptFIELD>::const_iterator it =
                    OptParFields.begin();
                it != OptParFields.end(); ++it)
        {
            OptionnalParScriptFIELD Opt = *it;
            OptionalParScriptFieldprocess(qobj, Opt);
        }
        break;
    case ISO_TYPE:
        for (std::vector<MandatoryIsoField>::const_iterator it =
                    MandIsoFields.begin();
                it != MandIsoFields.end(); ++it)
        {
            MandatoryIsoField Opt = *it;
            MandatoryIsoFieldprocess(qobj, Opt);
        }

        for (std::vector<OptionnalIsoScriptFIELD>::const_iterator it =
                    OptIsoFields.begin();
                it != OptIsoFields.end(); ++it)
        {
            OptionnalIsoScriptFIELD Opt = *it;
            OptionalIsoScriptFieldprocess(qobj, Opt);
        }
        break;
    case PARISO_TYPE:
        break;
    case UNDEFINED_TYPE:
        break;
    }
    // Colors
    if (loadtext)
    {
        LoadTexture(QTextureObj, mod);
    }
    // Pigment
    if (loadpigm)
    {
        LoadPigment(QPigmentObj, mod);
    }
}

void DrawingOptions::on_choice_activated(const QString &arg)
{
    // Draw here
    int Result = JSON_choice_activated(arg);
    if (Result != 0)
    {
        UpdateScriptEditorAndTreeObject();
    }
    //return Result;
}

void DrawingOptions::grabGestures(const QList<Qt::GestureType> &gestures)
{
    ui.openGLWidget->grabGestures(gestures);
}
void DrawingOptions::Run_JsonObject_activeted()
{
    QJsonParseError err;
    QString script =
        ui.ScriptEditor->toPlainText()
        .trimmed()
        .replace("\n", "")
        .replace("\t", "")
        .replace("DOTSYMBOL", Parameters->dotsymbol.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(script.toUtf8(), &err);
    if (err.error)
    {
        ShowErrorMessage(err, script);
        return;
    }
    // Draw here
    DrawJsonModel(doc.object());
}

void DrawingOptions::slot_comboBox18_3_activated(const QString &arg1)
{
    if (arg1 == "Triangles")
    {
        MathmodRef->slot_triangles_clicked();
        return;
    }
    if (arg1 == "Normales")
    {
        MathmodRef->draw_norm_clicked();
        return;
    }
    if (arg1 == "Fill")
    {
        MathmodRef->fill();
        return;
    }
    if (arg1 == "Mesh")
    {
        MathmodRef->Mesh();
        return;
    }
}

void DrawingOptions::slot_checkBox_clicked()
{
    MathmodRef->slot_uv_clicked();
}

void DrawingOptions::LoadNewFileModels(bool upd)
{
    QString mathmodcollection;
    mathmodcollection = QFileDialog::getOpenFileName(
                            nullptr, tr("Load Json Script"), "", tr("Json (*.js)"));
    if (upd)
    {
        ui.ObjectClasse->clear();
        for (int i = 0; i < MathmodRef->RootObjet.MyJsonObjectSelection.count();
                i++)
            MathmodRef->RootObjet.MyJsonObjectSelection.removeAt(i);
        MathmodRef->RootObjet.NbIsoStruct = MathmodRef->RootObjet.NbParamStruct = 0;
        MathmodRef->collection.JPar.clear();
        MathmodRef->collection.JIso.clear();
    }
    MathmodRef->RootObjet.ReadJsonFile(mathmodcollection, JSONMathModels);
    QJsonArray array = JSONMathModels["MathModels"].toArray();
    QStringList lst;
    QString a;
    QJsonObject jsobj;
    for (int i = 0; i < array.size(); i++)
    {
        if ((array[i].toObject())["Iso3D"].isObject())
        {
            jiso newjiso;
            jsobj = (array[i].toObject())["Iso3D"].toObject();
            newjiso.read(jsobj);
            MathmodRef->collection.JIso.append(newjiso);
            a = (jsobj)["Name"].toArray()[0].toString();
            lst.append(a);
        }
        else if ((array[i].toObject())["Param3D"].isObject())
        {
            jpar newjpar;
            jsobj = ((array[i].toObject())["Param3D"].toObject());
            newjpar.read(jsobj);
            MathmodRef->collection.JPar.append(newjpar);
            a = (jsobj)["Name"].toArray()[0].toString();
            lst.append(a);
        }
        else if ((array[i].toObject())["Param4D"].isObject())
        {
            jpar newjpar;
            jsobj = ((array[i].toObject())["Param4D"].toObject());
            newjpar.read(jsobj);
            MathmodRef->collection.JPar.append(newjpar);
            a = (jsobj)["Name"].toArray()[0].toString();
            lst.append(a);
        }
        else if ((array[i].toObject())["Param3D_C"].isObject())
        {
            jpar newjpar;
            jsobj = ((array[i].toObject())["Param3D_C"].toObject());
            newjpar.read(jsobj);
            MathmodRef->collection.JPar.append(newjpar);
            a = (jsobj)["Name"].toArray()[0].toString();
            lst.append(a);
        }
        else if ((array[i].toObject())["Param4D_C"].isObject())
        {
            jpar newjpar;
            jsobj = ((array[i].toObject())["Param4D_C"].toObject());
            newjpar.read(jsobj);
            MathmodRef->collection.JPar.append(newjpar);
            a = (jsobj)["Name"].toArray()[0].toString();
            lst.append(a);
        }
    }
    lst.insert(0, "Examples (" + QString::number(lst.count()) + ")");
    // Load the script containing isosurface and parametric formulas:
    ui.choice->clear();
    ui.choice->insertItems(0, lst);
    AddListModels(upd);
}

void DrawingOptions::LoadK3DSurfScript(QString filename, int type)
{
    int current = 0, currentfunction = 0, separator = 0;
    QString
            name, line, IsoFct, Xfct, Yfct, Zfct, xlimit, ylimit, zlimit, ulimit,
            vlimit, xmin, xmax, ymin, ymax, zmin, zmax, umin, umax, vmin, vmax,
            condition, Au, Bu, Cu, Duv, Euv, Fuv, comments;
    int EquationsNumber = 0;
    QString JsonString = "";
    int FctType = -1;
    filename = QFileDialog::getOpenFileName(
                   nullptr, QObject::tr("Open K3DSurf script File"), "",
                   QObject::tr("K3DS (*.k3ds)"));
    QFile file(filename);
    if (type == 1)
    {
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            while (!stream.atEnd())
            {
                line = (stream.readLine()).trimmed(); // line of text excluding '\n'
                if (line.contains("F():"))
                {
                    currentfunction = 1;
                    FctType = 0;
                }
                else if (line.contains("[x]:"))
                    currentfunction = 2;
                else if (line.contains("[y]:"))
                    currentfunction = 3;
                else if (line.contains("[z]:"))
                    currentfunction = 4;

                else if (line.contains("X():"))
                {
                    currentfunction = 21;
                    FctType = 1;
                }
                else if (line.contains("Y():"))
                    currentfunction = 22;
                else if (line.contains("Z():"))
                    currentfunction = 23;
                else if (line.contains("[u]:"))
                    currentfunction = 24;
                else if (line.contains("[v]:"))
                    currentfunction = 25;

                else if (line.contains("Cnd:"))
                    currentfunction = 5;
                else if (line.contains("A[u]:"))
                    currentfunction = 6;
                else if (line.contains("B[u]:"))
                    currentfunction = 7;
                else if (line.contains("C[u]:"))
                    currentfunction = 8;
                else if (line.contains("D[u,v]:"))
                    currentfunction = 9;
                else if (line.contains("E[u,v]:"))
                    currentfunction = 10;
                else if (line.contains("F[u,v]:"))
                    currentfunction = 11;
                else if (line.contains("#"))
                    currentfunction = 12;
                else if (line.contains("/*"))
                    currentfunction = 13;
                else if (line.contains("*/"))
                    currentfunction = 14;
                else if (line.contains("Name:"))
                    currentfunction = 15;
                else if (line.contains(";"))
                    currentfunction = 16;
                else
                    currentfunction = 18;
                switch (currentfunction)
                {
                case 1:
                    IsoFct += line.remove(0, 4);
                    current = 1;
                    break;

                case 21:
                    Xfct += line.replace("X():", "");
                    current = 21;
                    break;
                case 22:
                    Yfct += line.replace("Y():", "");
                    current = 22;
                    break;
                case 23:
                    Zfct += line.replace("Z():", "");
                    current = 23;
                    break;
                case 24:
                    ulimit += line.replace("[u]:", "");
                    current = 24;
                    break;
                case 25:
                    vlimit += line.replace("[v]:", "");
                    current = 25;
                    break;

                case 2:
                    xlimit = line.remove(0, 4);
                    current = 2;
                    break;
                case 3:
                    ylimit = line.remove(0, 4);
                    current = 3;
                    break;
                case 4:
                    zlimit = line.remove(0, 4);
                    current = 4;
                    break;
                case 5:
                    condition = line.remove(0, 4);
                    current = 5;
                    break;
                case 6:
                    Au = line.remove(0, 5);
                    current = 6;
                    break;
                case 7:
                    Bu = line.remove(0, 5);
                    current = 7;
                    break;
                case 8:
                    Cu = line.remove(0, 5);
                    current = 8;
                    break;
                case 9:
                    Duv = line.remove(0, 7);
                    current = 9;
                    break;
                case 10:
                    Euv = line.remove(0, 7);
                    current = 10;
                    break;
                case 11:
                    Fuv = line.remove(0, 7);
                    current = 11;
                    break;
                case 12:
                    comments += line.replace("#", "");
                    current = 12;
                    break;
                case 13:
                    comments += line.replace("/*", "").replace("*/", "");
                    current = 13;
                    break;
                case 14:
                    comments += line.replace("*/", "");
                    current = 14;
                    break;
                case 15:
                    name = line.remove(0, 5);
                    current = 15;
                    break;
                case 16:
                    // Save the equation:
                    name = name.trimmed();
                    if (FctType == 0)
                    {
                        EquationsNumber++;
                        if (name == "")
                            name = "_" + QString::number(EquationsNumber);
                        xlimit = xlimit.trimmed();
                        separator = xlimit.indexOf(",");
                        xmin = xlimit.left(separator);
                        xmax = xlimit.remove(xmin + ",");
                        ylimit = ylimit.trimmed();
                        separator = ylimit.indexOf(",");
                        ymin = ylimit.left(separator);
                        ymax = ylimit.remove(ymin + ",");
                        zlimit = zlimit.trimmed();
                        separator = zlimit.indexOf(",");
                        zmin = zlimit.left(separator);
                        zmax = zlimit.remove(zmin + ",");
                        if (JsonString != "")
                            JsonString += ",";
                        JsonString += "{\"Iso3D\": {  \
                         \"Description \": [ \"" +
                                      comments + "\"], ";
                        JsonString += "\"Name\": [\"" + name + "\"], ";
                        JsonString += "\"Component\": [\"" + name + "\"], ";
                        JsonString += "\"Fxyz\": [\"" + IsoFct.trimmed() + "\"], ";
                        JsonString += "\"Cnd\": [\"" + condition + "\"], ";
                        JsonString += "\"Xmin\": [\"" + xmin + "\"], ";
                        JsonString += "\"Xmax\": [\"" + xmax + "\"], ";
                        JsonString += "\"Ymin\": [\"" + ymin + "\"], ";
                        JsonString += "\"Ymax\": [\"" + ymax + "\"], ";
                        JsonString += "\"Zmin\": [\"" + zmin + "\"], ";
                        JsonString += "\"Zmax\": [\"" + zmax + "\"] ";
                        JsonString += "}}";
                    }

                    else if (FctType == 1)
                    {
                        EquationsNumber++;
                        if (name == "")
                            name = "_" + QString::number(EquationsNumber);

                        ulimit = ulimit.trimmed();
                        separator = ulimit.indexOf(",");
                        umin = ulimit.left(separator);
                        umax = ulimit.remove(umin + ",");
                        vlimit = vlimit.trimmed();
                        separator = vlimit.indexOf(",");
                        vmin = vlimit.left(separator);
                        vmax = vlimit.remove(vmin + ",");
                        if (JsonString != "")
                            JsonString += ",";
                        JsonString += "{\"Param3D\": {  \
                         \"Description \": [ \"" +
                                      comments + "\"],";
                        JsonString += "\"Name\": [\"" + name + "\"],";
                        JsonString += "\"Component\": [\"" + name + "\"],";
                        JsonString += "\"Fx\": [\"" + Xfct.trimmed() + "\"],";
                        JsonString += "\"Fy\": [\"" + Yfct.trimmed() + "\"],";
                        JsonString += "\"Fz\": [\"" + Zfct.trimmed() + "\"],";
                        JsonString += "\"Cnd\": [\"" + condition + "\"],";
                        JsonString += "\"Umin\": [\"" + umin + "\"],";
                        JsonString += "\"Umax\": [\"" + umax + "\"],";
                        JsonString += "\"Vmin\": [\"" + vmin + "\"],";
                        JsonString += "\"Vmax\": [\"" + vmax + "\"]";
                        JsonString += "}}";
                    }
                    current = 16;
                    // Init all Parameters fo new formula:
                    IsoFct = Xfct = Yfct = Zfct = name = comments = condition = "";
                    umin = umax = vmin = vmax = xmin = xmax = ymin = ymax = zmin = zmax = "";
                    ulimit = vlimit = xlimit = ylimit = zlimit = "";
                    FctType = -1;
                    break;
                case 18:
                    if (current == 1)
                        IsoFct += line;
                    else if (current == 2)
                        xlimit += line;
                    else if (current == 3)
                        ylimit += line;
                    else if (current == 4)
                        zlimit += line;
                    else if (current == 21)
                        Xfct += line;
                    else if (current == 22)
                        Yfct += line;
                    else if (current == 23)
                        Zfct += line;
                    else if (current == 24)
                        ulimit += line;
                    else if (current == 25)
                        vlimit += line;
                    else if (current == 5)
                        condition += line;
                    else if (current == 6)
                        Au += line;
                    else if (current == 7)
                        Bu += line;
                    else if (current == 8)
                        Cu += line;
                    else if (current == 9)
                        Duv += line;
                    else if (current == 10)
                        Euv += line;
                    else if (current == 11)
                        Fuv += line;
                    else if (current == 12)
                        comments += line;
                    else if (current == 13)
                        comments += line;
                    else if (current == 14)
                        comments += line;
                    else if (current == 15)
                        name += line;
                    break;
                }
            }
            file.close();
            JsonString = " { \"MathModels\": [ " + JsonString + "]}";
            QFile f(filename.replace(".k3ds", ".js"));
            if (f.exists())
                f.remove();
            if (!f.open(QIODevice::ReadWrite | QIODevice::Text))
            {
                return;
            }
            QTextStream t(&f);
            t << JsonString;
            f.close();
        }
    }
}

QTreeWidgetItem *DrawingOptions::ChildItemTreeProperty(QTreeWidgetItem *item,
        QString proprty)
{
    int childcount = item->childCount();
    for (int j = 0; j < childcount; j++)
    {
        if ((item->child(j))->text(0).contains(proprty))
            return item->child(j);
    }
    return nullptr;
}

void DrawingOptions::ParseItemTree(QTreeWidgetItem *item, QList<bool> &list, bool viewall)
{
    int childcount = item->childCount();
    bool sel = false;
    bool result;
    for (int j = 0; j < childcount; j++)
    {
        item->child(j)->setForeground(0, QColor(255, 255, 255, 255));
        if (!viewall)
        {
            result = false;
            for (int k = 1; k < select.selectedoptions.selectedwords.count(); k++)
            {
                sel = (item->child(j))
                      ->text(0)
                      .contains(select.selectedoptions.selectedwords[k],
                                (select.selectedoptions.sensitive
                                 ? Qt::CaseSensitive
                                 : Qt::CaseInsensitive));
                result = result || sel;
                list[k - 1] = (list.at(k - 1) || sel);
            }
            if (result)
                item->child(j)->setForeground(0, QColor(255, 0, 0, 255));
        }
    }
}

void DrawingOptions::SearchListModels()
{
    QTreeWidgetItem *Toplevel;
    QTreeWidgetItem *Childlevel = nullptr;
    QTreeWidgetItem *SubChildlevel;
    int topcount = ui.ObjectClasse->topLevelItemCount();
    int childcount;
    bool sel1 = false;
    int searchresult = 0;
    // init boolean lists:
    for (int i = 0; i < select.selectedoptions.selectedwords.count() - 1; i++)
    {
        select.selectedoptions.namelist.append(false);
        select.selectedoptions.functlist.append(false);
        select.selectedoptions.cmpnamelist.append(false);
        select.selectedoptions.complist.append(false);
    }
    for (int i = 0; i < topcount; ++i)
    {
        Toplevel = ui.ObjectClasse->topLevelItem(i);
        childcount = Toplevel->childCount();
        searchresult = 0;
        for (int j = 0; j < childcount; j++)
        {
            sel1 = true;
            if (!select.selectedoptions.showall)
            {
                // init boolean lists:
                for (int m = 0; m < select.selectedoptions.selectedwords.count() - 1;
                        m++)
                {
                    select.selectedoptions.namelist[m] = false;
                    select.selectedoptions.functlist[m] = false;
                    select.selectedoptions.cmpnamelist[m] = false;
                    select.selectedoptions.complist[m] = false;
                }
                // Search in scripts names:
                if (select.selectedoptions.parsenames)
                    for (int k = 1; k < select.selectedoptions.selectedwords.count();
                            k++)
                    {
                        select.selectedoptions.namelist[k - 1] =
                            (Toplevel->child(j))
                            ->text(0)
                            .contains(select.selectedoptions.selectedwords[k],
                                      (select.selectedoptions.sensitive
                                       ? Qt::CaseSensitive
                                       : Qt::CaseInsensitive));
                    }
                // continue searching in the functions list when needed:
                if (select.selectedoptions.parsefunctions &&
                        (Childlevel = ChildItemTreeProperty(Toplevel->child(j),
                                      "Parameters")) != nullptr)
                    if ((SubChildlevel =
                                ChildItemTreeProperty(Childlevel, "Functions")) != nullptr)
                    {
                        ParseItemTree(SubChildlevel, select.selectedoptions.functlist);
                    }
                // continue searching in the components names list when needed:
                if (select.selectedoptions.parsecmpnames &&
                        (Childlevel = ChildItemTreeProperty(Toplevel->child(j),
                                      "Components")) != nullptr)
                {
                    ParseItemTree(Childlevel, select.selectedoptions.cmpnamelist);
                    int ct = Childlevel->childCount();
                    for (int m = 0; m < ct; m++)
                        ParseItemTree(Childlevel->child(m),
                                      select.selectedoptions.complist);
                }
                // now look in the search results
                if (select.selectedoptions.AND)
                {
                    sel1 = true;
                    for (int l = 0; l < select.selectedoptions.selectedwords.count() - 1;
                            l++)
                        sel1 = sel1 && (select.selectedoptions.namelist.at(l) ||
                                        select.selectedoptions.functlist.at(l) ||
                                        select.selectedoptions.cmpnamelist.at(l) ||
                                        select.selectedoptions.complist.at(l));
                }
                else
                {
                    sel1 = false;
                    for (int l = 0; l < select.selectedoptions.selectedwords.count() - 1;
                            l++)
                        sel1 = sel1 || (select.selectedoptions.namelist.at(l) ||
                                        select.selectedoptions.functlist.at(l) ||
                                        select.selectedoptions.cmpnamelist.at(l) ||
                                        select.selectedoptions.complist.at(l));
                }
            }
            else
            {
                // Make sure the text color is white when showall is activated
                if ((Childlevel = ChildItemTreeProperty(Toplevel->child(j),
                                                        "Parameters")) != nullptr)
                    if ((SubChildlevel =
                                ChildItemTreeProperty(Childlevel, "Functions")) != nullptr)
                    {
                        ParseItemTree(SubChildlevel, select.selectedoptions.functlist,
                                      true);
                    }
                // Components names and their childs:
                if ((Childlevel = ChildItemTreeProperty(Toplevel->child(j),
                                                        "Components")) != nullptr)
                {
                    ParseItemTree(Childlevel, select.selectedoptions.cmpnamelist, true);
                    int ct = Childlevel->childCount();
                    for (int m = 0; m < ct; m++)
                        ParseItemTree(Childlevel->child(m), select.selectedoptions.complist, true);
                }
            }
            // Now count and show only scripts with appropiate search results:
            if (sel1)
                searchresult++;
            (Toplevel->child(j))->setHidden(!sel1);
            if (Toplevel->text(0).contains("IsoSurfaces"))
                Toplevel->setText(0, "IsoSurfaces (" + QString::number(searchresult) +
                                  ")");
            else if (Toplevel->text(0).contains("Parametric"))
                Toplevel->setText(0,
                                  "Parametric (" + QString::number(searchresult) + ")");
            else
                Toplevel->setText(0, "My Selection (" + QString::number(searchresult) +
                                  ")");
        }
    }
    // Clear boolean lists:
    select.selectedoptions.namelist.clear();
    select.selectedoptions.functlist.clear();
    select.selectedoptions.cmpnamelist.clear();
    select.selectedoptions.complist.clear();
}

void DrawingOptions::AddListModels(bool update)
{
    if (!update)
    {
        QMenu *contextMenu = new QMenu(ui.ObjectClasse);
        ui.ObjectClasse->setContextMenuPolicy(Qt::ActionsContextMenu);
        QAction *addElement =
            new QAction("Add Current Model to MySelection", contextMenu);
        QAction *deleteElement =
            new QAction("Erase selected row from MySelection", contextMenu);
        QAction *separator = new QAction(ui.ObjectClasse);
        separator->setSeparator(true);
        ui.ObjectClasse->addAction(addElement);
        ui.ObjectClasse->addAction(separator);
        ui.ObjectClasse->addAction(deleteElement);
        connect(addElement, SIGNAL(triggered()), this,
                SLOT(slot_pushButton_2_clicked()));
        connect(deleteElement, SIGNAL(triggered()), this,
                SLOT(slot_unselect_clicked()));
    }
    QColor greenColor = QColor(0, 255, 0, 50);
    // Parametric:
    QTreeWidgetItem *ParlistItem = new QTreeWidgetItem(ui.ObjectClasse);
    QString Text = "Parametric (" +
                   QString::number(MathmodRef->collection.JPar.count()) + ")";
    ParlistItem->setBackground(0, greenColor);
    ParlistItem->setText(0, Text);
    for (int i = 0; i < MathmodRef->collection.JPar.count(); ++i)
    {
        QTreeWidgetItem *nameitem = new QTreeWidgetItem(ParlistItem);
        nameitem->setText(0, MathmodRef->collection.JPar[i].Name[0]);
        if (MathmodRef->collection.JPar[i].Component.count() > 0)
        {
            QTreeWidgetItem *cmpitem = new QTreeWidgetItem(nameitem);
            cmpitem->setText(0, "Components");
            for (int j = 0; j < MathmodRef->collection.JPar[i].Component.count();
                    j++)
            {
                QTreeWidgetItem *cmpitem2 = new QTreeWidgetItem(cmpitem);
                cmpitem2->setText(0, MathmodRef->collection.JPar[i].Component.at(j));
                QTreeWidgetItem *cmpitem3 = new QTreeWidgetItem(cmpitem2);
                cmpitem3->setText(0, "X(u,v) = " +
                                  MathmodRef->collection.JPar[i].Fx.at(j));
                QTreeWidgetItem *cmpitem4 = new QTreeWidgetItem(cmpitem2);
                cmpitem4->setText(0, "Y(u,v) = " +
                                  MathmodRef->collection.JPar[i].Fy.at(j));
                QTreeWidgetItem *cmpitem5 = new QTreeWidgetItem(cmpitem2);
                cmpitem5->setText(0, "Z(u,v) = " +
                                  MathmodRef->collection.JPar[i].Fz.at(j));
                QTreeWidgetItem *cmpitem6 = new QTreeWidgetItem(cmpitem2);
                cmpitem6->setText(
                    0, "U = [" + MathmodRef->collection.JPar[i].Umin.at(j) + ", " +
                    MathmodRef->collection.JPar[i].Umax.at(j) + "]");
                QTreeWidgetItem *cmpitem7 = new QTreeWidgetItem(cmpitem2);
                cmpitem7->setText(
                    0, "V = [" + MathmodRef->collection.JPar[i].Vmin.at(j) + ", " +
                    MathmodRef->collection.JPar[i].Vmax.at(j) + "]");
                // Grid resolution:
                if (MathmodRef->collection.JPar[i].Grid.size() > 0 &&
                        2 * j + 1 < MathmodRef->collection.JPar[i].Grid.size())
                {
                    QTreeWidgetItem *cmpitem8 = new QTreeWidgetItem(cmpitem2);
                    cmpitem8->setText(
                        0, "Grid = (" + MathmodRef->collection.JPar[i].Grid.at(2 * j) +
                        " , " + MathmodRef->collection.JPar[i].Grid.at(2 * j + 1) +
                        ")");
                }
            }
        }
        // Add Global parameters:
        if (MathmodRef->collection.JPar[i].Csts.count() ||
                MathmodRef->collection.JPar[i].Funct.count())
        {
            QTreeWidgetItem *parameteritem = new QTreeWidgetItem(nameitem);
            parameteritem->setText(0, "Parameters:");
            if (MathmodRef->collection.JPar[i].Csts.count() > 0)
            {
                QTreeWidgetItem *cstitem = new QTreeWidgetItem(parameteritem);
                cstitem->setText(0, "Constantes:");
                for (int j = 0; j < MathmodRef->collection.JPar[i].Csts.count(); j++)
                {
                    QTreeWidgetItem *cstitem2 = new QTreeWidgetItem(cstitem);
                    cstitem2->setText(0, MathmodRef->collection.JPar[i].Csts.at(j));
                }
            }
            if (MathmodRef->collection.JPar[i].Funct.count() > 0)
            {
                QTreeWidgetItem *fctitem = new QTreeWidgetItem(parameteritem);
                fctitem->setText(0, "Functions:");
                for (int j = 0; j < MathmodRef->collection.JPar[i].Funct.count(); j++)
                {
                    QTreeWidgetItem *fctitem2 = new QTreeWidgetItem(fctitem);
                    fctitem2->setText(0, MathmodRef->collection.JPar[i].Funct.at(j));
                }
            }
        }
    }
    ParlistItem->sortChildren(0, Qt::AscendingOrder);
    // Iso:
    QTreeWidgetItem *IsolistItem = IsolistItemRef =
                                       new QTreeWidgetItem(ui.ObjectClasse);
    Text = "IsoSurfaces (" +
           QString::number(MathmodRef->collection.JIso.count()) + ")";
    IsolistItem->setBackground(0, greenColor);
    IsolistItem->setText(0, Text);
    for (int i = 0; i < MathmodRef->collection.JIso.count(); ++i)
    {
        QTreeWidgetItem *nameitem = new QTreeWidgetItem(IsolistItem);
        nameitem->setText(0, MathmodRef->collection.JIso[i].Name[0]);
        if (MathmodRef->collection.JIso[i].Component.count() > 0)
        {
            QTreeWidgetItem *cmpitem = new QTreeWidgetItem(nameitem);
            cmpitem->setText(0, "Components");
            for (int j = 0; j < MathmodRef->collection.JIso[i].Component.count();
                    j++)
            {
                QTreeWidgetItem *cmpitem2 = new QTreeWidgetItem(cmpitem);
                cmpitem2->setText(0, MathmodRef->collection.JIso[i].Component.at(j));
                QTreeWidgetItem *cmpitem3 = new QTreeWidgetItem(cmpitem2);
                cmpitem3->setText(0, "F(x,y,z) = " +
                                  MathmodRef->collection.JIso[i].Fxyz.at(j));
                QTreeWidgetItem *cmpitem6 = new QTreeWidgetItem(cmpitem2);
                cmpitem6->setText(
                    0, "X = [" + MathmodRef->collection.JIso[i].Xmin.at(j) + ", " +
                    MathmodRef->collection.JIso[i].Xmax.at(j) + "]");
                QTreeWidgetItem *cmpitem7 = new QTreeWidgetItem(cmpitem2);
                cmpitem7->setText(
                    0, "Y = [" + MathmodRef->collection.JIso[i].Ymin.at(j) + ", " +
                    MathmodRef->collection.JIso[i].Ymax.at(j) + "]");
                QTreeWidgetItem *cmpitem8 = new QTreeWidgetItem(cmpitem2);
                cmpitem8->setText(
                    0, "Z = [" + MathmodRef->collection.JIso[i].Zmin.at(j) + ", " +
                    MathmodRef->collection.JIso[i].Zmax.at(j) + "]");
                // Grid resolution:
                if (MathmodRef->collection.JIso[i].Grid.size() > 0 &&
                        j < MathmodRef->collection.JIso[i].Grid.size())
                {
                    QTreeWidgetItem *cmpitem9 = new QTreeWidgetItem(cmpitem2);
                    cmpitem9->setText(0, "Grid = " +
                                      MathmodRef->collection.JIso[i].Grid.at(j));
                }
            }
        }
        // Add Global parameters:
        if (MathmodRef->collection.JIso[i].Csts.count() ||
                MathmodRef->collection.JIso[i].Funct.count())
        {
            QTreeWidgetItem *parameteritem = new QTreeWidgetItem(nameitem);
            parameteritem->setText(0, "Parameters:");
            if (MathmodRef->collection.JIso[i].Csts.count() > 0)
            {
                QTreeWidgetItem *cstitem = new QTreeWidgetItem(parameteritem);
                cstitem->setText(0, "Constantes:");
                for (int j = 0; j < MathmodRef->collection.JIso[i].Csts.count(); j++)
                {
                    QTreeWidgetItem *cstitem2 = new QTreeWidgetItem(cstitem);
                    cstitem2->setText(0, MathmodRef->collection.JIso[i].Csts.at(j));
                }
            }
            if (MathmodRef->collection.JIso[i].Funct.count() > 0)
            {
                QTreeWidgetItem *fctitem = new QTreeWidgetItem(parameteritem);
                fctitem->setText(0, "Functions:");
                for (int j = 0; j < MathmodRef->collection.JIso[i].Funct.count(); j++)
                {
                    QTreeWidgetItem *fctitem2 = new QTreeWidgetItem(fctitem);
                    fctitem2->setText(0, MathmodRef->collection.JIso[i].Funct.at(j));
                }
            }
        }
    }
    IsolistItemRef->sortChildren(0, Qt::AscendingOrder);
    // Parametric:
    QTreeWidgetItem *ParisolistItem = new QTreeWidgetItem(ui.ObjectClasse);
    Text = "Pariso (" +
                   QString::number(MathmodRef->collection.JParIso.count()) + ")";
    ParisolistItem->setBackground(0, greenColor);
    ParisolistItem->setText(0, Text);
    for (int i = 0; i < MathmodRef->collection.JParIso.count(); ++i)
    {
        QTreeWidgetItem *nameitem = new QTreeWidgetItem(ParisolistItem);
        nameitem->setText(0, MathmodRef->collection.JParIso[i].Name);

    }
    ParisolistItem->sortChildren(0, Qt::AscendingOrder);
    // My Selection:
    // Isosurfaces:
    QTreeWidgetItem *MyselectionItem = new QTreeWidgetItem(ui.ObjectClasse);
    MyselectionItemReference = MyselectionItem;
    MyselectionItem->setBackground(0, greenColor);
    MyselectionItem->setText(0, "My Selection");
    return;
}

void DrawingOptions::on_action_Exit_triggered()
{
    MathmodRef->close();
    this->close();
}

void DrawingOptions::on_actionTriangles_triggered()
{
    MathmodRef->slot_triangles_clicked();
}

void DrawingOptions::on_actionInfos_triggered()
{
    infos *= -1;
    if(infos == 1)
       ui.Messagetext->show();
    else
        ui.Messagetext->hide();
    //MathmodRef->iso_infos();
}

void DrawingOptions::on_actionFill_triggered()
{
    MathmodRef->fill();
}

void DrawingOptions::on_ObjectClasse_clicked(const QModelIndex &index)
{
    if (!MathmodRef->IsoObjet->isRunning() &&
            !MathmodRef->ParObjet->isRunning())
    {
        on_InitTButton_clicked();
        // int result;
        QString tst;
        MathmodRef->LocalScene.IndexCurrentFormula = -1;
        if (index.data().isValid())
        {
            QVariant data = index.data();
            QString s = data.toString();
            QModelIndex parent = index.parent();
            if (parent.data().isValid())
            {
                QString prt = parent.data().toString();
                if (prt != "My Selection")
                {
                    on_choice_activated(s);
                }
                else
                {
                    for (int i = 0;
                            i < MathmodRef->RootObjet.MyJsonObjectSelection.size(); i++)
                        if ((MathmodRef->RootObjet.MyJsonObjectSelection[i].toObject()["Iso3D"].isObject()))
                        {
                            if (s == (tst = (MathmodRef->RootObjet.MyJsonObjectSelection[i].toObject()["Iso3D"]).toObject()["Name"].toArray()[0].toString()))
                            {
                                // Draw here

                                DrawJsonModel(MathmodRef->RootObjet.MyJsonObjectSelection.at(i).toObject());
                                return;
                            }
                        }
                        else if ((MathmodRef->RootObjet.MyJsonObjectSelection[i].toObject()["Param3D"].isObject()))
                        {
                            if (s == (tst = (MathmodRef->RootObjet.MyJsonObjectSelection[i].toObject()["Param3D"]).toObject()["Name"].toArray()[0].toString()))
                            {
                                // Draw here
                                DrawJsonModel(MathmodRef->RootObjet.MyJsonObjectSelection.at(i).toObject());
                                return;
                            }
                        }
                        else if ((MathmodRef->RootObjet.MyJsonObjectSelection[i].toObject()["Param4D"].isObject()))
                        {
                            if (s == (tst = (MathmodRef->RootObjet.MyJsonObjectSelection[i].toObject()["Param4D"]).toObject()["Name"].toArray()[0].toString()))
                            {
                                // Draw here
                                DrawJsonModel(MathmodRef->RootObjet.MyJsonObjectSelection.at(i).toObject());
                                return;
                            }
                        }
                        else if ((MathmodRef->RootObjet.MyJsonObjectSelection[i].toObject()["Param3D_C"].isObject()))
                        {
                            if (s == (tst = (MathmodRef->RootObjet.MyJsonObjectSelection[i].toObject()["Param3D_C"]).toObject()["Name"].toArray()[0].toString()))
                            {
                                // Draw here
                                DrawJsonModel(MathmodRef->RootObjet.MyJsonObjectSelection.at(i).toObject());
                                return;
                            }
                        }
                        else if ((MathmodRef->RootObjet.MyJsonObjectSelection[i].toObject()["Param4D_C"].isObject()))
                        {
                            if (s == (tst = (MathmodRef->RootObjet.MyJsonObjectSelection[i].toObject()["Param4D_C"]).toObject()["Name"].toArray()[0].toString()))
                            {
                                // Draw here
                                DrawJsonModel(MathmodRef->RootObjet.MyJsonObjectSelection.at(i).toObject());
                                return;
                            }
                        }
                }
            }
        }
        return;
    }
}

void DrawingOptions::slot_pushButton_2_clicked()
{
    MathmodRef->RootObjet.MyJsonObjectSelection.append(MathmodRef->RootObjet.CurrentJsonObject);
    AddObjectToMySelectionTree();
}

void DrawingOptions::slot_unselect_clicked()
{
    int index =
        MyselectionItemReference->indexOfChild(ui.ObjectClasse->currentItem());
    MathmodRef->RootObjet.MyJsonObjectSelection.removeAt(index);
    MyselectionItemReference->removeChild(ui.ObjectClasse->currentItem());
}

void DrawingOptions::slot_XYZscrollBarValueChanged(int value)
{
    MathmodRef->xyzg_valueChanged(value, ISO_TYPE);
}

void DrawingOptions::UpdateDescription(int position, ModelType type, TreeStruct &currentstruct)
{
    if (type == PAR_TYPE)
    {
        if (position > -1)
        {
            IndexcurrentComponent = position;
            MathmodRef->LocalScene.IndexCurrentFormula == position
            ? MathmodRef->LocalScene.IndexCurrentFormula = -1
                    : MathmodRef->LocalScene.IndexCurrentFormula = position;
            // currentFormula = sparent;
            ui.paramNameEdit->setText(currentstruct.Component.at(position));
            ui.XEdit->setText(currentstruct.fx.at(position));
            ui.YEdit->setText(currentstruct.fy.at(position));
            ui.ZEdit->setText(currentstruct.fz.at(position));
            ui.umin->setText(currentstruct.umin.at(position));
            ui.vmin->setText(currentstruct.vmin.at(position));
            ui.umax->setText(currentstruct.umax.at(position));
            ui.vmax->setText(currentstruct.vmax.at(position));
            if (!currentstruct.Component.empty())
                ui.paramNameEdit->setText(currentstruct.Component.at(position));
            else
                ui.paramNameEdit->setText("");
            if (!currentstruct.Cnd.empty())
            {
                ui.CndUpdateEdit_2->setText(currentstruct.Cnd.at(position));
            }
            else
            {
                ui.CndUpdateEdit_2->setText("");
            }
            // Function:
            if (!currentstruct.Funct.empty())
            {
                ui.tableWidget_Fct_2->clearContents();
                ui.tableWidget_Fct_2->setRowCount(0);
                for (int i = 0; i < currentstruct.Funct.size(); i++)
                {
                    ui.tableWidget_Fct_2->setRowCount(i + 1);
                    ui.tableWidget_Fct_2->setItem(i, 0, new QTableWidgetItem(currentstruct.Funct.at(i)));
                }
            }
            else
            {
                ui.tableWidget_Fct_2->clearContents();
                ui.tableWidget_Fct_2->setRowCount(0);
            }
            // Constantes:
            if (!currentstruct.Const.empty())
            {
                ui.tableWidget_Cst_2->clearContents();
                ui.tableWidget_Cst_2->setRowCount(0);
                for (int i = 0; i < currentstruct.Const.size(); i++)
                {
                    ui.tableWidget_Cst_2->setRowCount(i + 1);
                    ui.tableWidget_Cst_2->setItem(i, 0, new QTableWidgetItem(currentstruct.Const.at(i)));
                }
            }
            else
            {
                ui.tableWidget_Cst_2->clearContents();
                ui.tableWidget_Cst_2->setRowCount(0);
            }
        }
        ui.stackedProperties->setCurrentIndex(2);
    }
    if (type == PAR_4D_TYPE)
    {
        if (position > -1)
        {
            IndexcurrentComponent = position;
            MathmodRef->LocalScene.IndexCurrentFormula == position
            ? MathmodRef->LocalScene.IndexCurrentFormula = -1
                    : MathmodRef->LocalScene.IndexCurrentFormula = position;
            // currentFormula = sparent;
            ui.paramNameEdit_2->setText(currentstruct.Component.at(position));
            ui.XEdit_2->setText(currentstruct.fx.at(position));
            ui.YEdit_2->setText(currentstruct.fy.at(position));
            ui.ZEdit_2->setText(currentstruct.fz.at(position));
            ui.WEdit_2->setText(currentstruct.fw.at(position));
            ui.umin_2->setText(currentstruct.umin.at(position));
            ui.vmin_2->setText(currentstruct.vmin.at(position));
            ui.umax_2->setText(currentstruct.umax.at(position));
            ui.vmax_2->setText(currentstruct.vmax.at(position));
            if (!currentstruct.Component.empty())
                ui.paramNameEdit_2->setText(currentstruct.Component.at(position));
            else
                ui.paramNameEdit_2->setText("");
        }
        ui.stackedProperties->setCurrentIndex(3);
    }
    if (type == ISO_TYPE)
    {
        if (position > -1)
        {
            IndexcurrentComponent = position;
            MathmodRef->LocalScene.IndexCurrentFormula == position
            ? MathmodRef->LocalScene.IndexCurrentFormula = -1
                    : MathmodRef->LocalScene.IndexCurrentFormula = position;
            ui.UpdateEdit->setText(currentstruct.fxyz.at(position));
            ui.xmin->setText(currentstruct.xmin.at(position));
            ui.ymin->setText(currentstruct.ymin.at(position));
            ui.zmin->setText(currentstruct.zmin.at(position));
            ui.xmax->setText(currentstruct.xmax.at(position));
            ui.ymax->setText(currentstruct.ymax.at(position));
            ui.zmax->setText(currentstruct.zmax.at(position));
            if (!currentstruct.Component.empty())
                ui.isoNameEdit->setText(currentstruct.Component.at(position));
            else
                ui.isoNameEdit->setText("");

            if (!currentstruct.Cnd.empty())
            {
                position < currentstruct.Cnd.size()
                ? ui.CndUpdateEdit->setText(currentstruct.Cnd.at(position))
                : ui.CndUpdateEdit->setText(currentstruct.Cnd.at(0));
            }
            else
            {
                ui.CndUpdateEdit->setText("");
            }
            // Function:
            if (!currentstruct.Funct.empty())
            {
                ui.tableWidget_Fct->clearContents();
                ui.tableWidget_Fct->setRowCount(0);
                for (int i = 0; i < currentstruct.Funct.size(); i++)
                {
                    ui.tableWidget_Fct->setRowCount(i + 1);
                    ui.tableWidget_Fct->setItem(i, 0, new QTableWidgetItem(currentstruct.Funct.at(i)));
                }
            }
            else
            {
                ui.tableWidget_Fct->clearContents();
                ui.tableWidget_Fct->setRowCount(0);
            }
            // Constantes:
            if (!currentstruct.Const.empty())
            {
                ui.tableWidget_Cst->clearContents();
                ui.tableWidget_Cst->setRowCount(0);
                for (int i = 0; i < currentstruct.Const.size(); i++)
                {
                    ui.tableWidget_Cst->setRowCount(i + 1);
                    ui.tableWidget_Cst->setItem(i, 0, new QTableWidgetItem(currentstruct.Const.at(i)));
                }
            }
            else
            {
                ui.tableWidget_Cst->clearContents();
                ui.tableWidget_Cst->setRowCount(0);
            }
        }
        ui.stackedProperties->setCurrentIndex(1);
    }
}

void DrawingOptions::oncolor_2activated(int index)
{
    MathmodRef->colorstype(index);
}

void DrawingOptions::onred_2valueChanged(int value)
{
    MathmodRef->red(value, IndexcurrentComponent);
}

void DrawingOptions::ongreen_2valueChanged(int value)
{
    MathmodRef->green(value, IndexcurrentComponent);
}

void DrawingOptions::onblue_2valueChanged(int value)
{
    MathmodRef->blue(value, IndexcurrentComponent);
}

void DrawingOptions::on_red_ParIso_valueChanged(int value)
{
    MathmodRef->red(value, IndexcurrentComponent);
}

void DrawingOptions::on_green_ParIso_valueChanged(int value)
{
    MathmodRef->green(value, IndexcurrentComponent);
}

void DrawingOptions::on_blue_ParIso_valueChanged(int value)
{
    MathmodRef->blue(value, IndexcurrentComponent);
}

void DrawingOptions::removeat(int idx, QJsonObject& QObj, QString str)
{
    QJsonArray array;
    array = QObj[str].toArray();
    array.removeAt(idx);
    QObj[str] = array;
}

void DrawingOptions::removeat2(int idx, QJsonObject& QObj, QString str)
{
    if (QObj[str].isArray())
    {
        QJsonArray array;
        array = QObj[str].toArray();
        array.removeAt(idx);
        QObj[str] = array;
    }
    else
        QObj.remove(str);
}

void DrawingOptions::appendall(QJsonObject& QObj, QString str, QTableWidget* table)
{
    if (QObj[str].isArray() && table->rowCount() > 0)
    {
        QJsonArray array2;
        for (int i = 0; i < table->rowCount(); i++)
        {
            if ((table->item(i, 0))->text() != "")
                array2.append((table->item(i, 0))->text());
        }
        QObj[str] = array2;
    }
    else
        QObj.remove(str);
}

void DrawingOptions::replaceat(int idx, QJsonObject& QObj, QString str, QTextEdit* text)
{
    QJsonArray array;
    array = QObj[str].toArray();
    array.replace(idx, text->toPlainText());
    QObj[str] = array;
}

void DrawingOptions::insertat(int idx, QJsonObject& QObj, QString str, QTextEdit* text)
{
    QJsonArray array;
    array = QObj[str].toArray();
    array.insert(idx, text->toPlainText());
    QObj[str] = array;
}

void DrawingOptions::appednew(QJsonObject& QObj, QString str, QTextEdit* text)
{
    QJsonArray array;
    array = QObj[str].toArray();
    array.append(text->toPlainText());
    QObj[str] = array;
}

void DrawingOptions::on_updateJObject(QJsonObject &copyCurrentObject)
{
    QJsonArray array;
    if (copyCurrentObject["Iso3D"].isObject())
    {
        if (IndexcurrentComponent != -1)
        {
            QJsonObject copyCurrentObject2 = copyCurrentObject["Iso3D"].toObject();
            // Cut the component at the index indexcurrentFormula :
            if ((ui.isoNameEdit->toPlainText()).replace(" ", "") == "")
            {
                for(uint ui=0; ui<MandatoryIsosurfaceFields.size(); ui++)
                    removeat(IndexcurrentComponent, copyCurrentObject2, MandatoryIsosurfaceFields[ui]);

                removeat2(IndexcurrentComponent, copyCurrentObject2, "Grid");
                removeat2(IndexcurrentComponent, copyCurrentObject2, "Cnd");
                appendall(copyCurrentObject2, "Funct", ui.tableWidget_Fct);
                appendall(copyCurrentObject2, "Const", ui.tableWidget_Cst);
                // Some keys cleaning..
                copyCurrentObject2.remove("Param3D");
                copyCurrentObject2.remove("Param4D");
                copyCurrentObject["Iso3D"] = copyCurrentObject2;
            }
            // Update the component at the index indexcurrentFormula;
            else if ((copyCurrentObject["Iso3D"].toObject())["Component"].toArray().size() > 0 &&
                     IndexcurrentComponent > -1 && IndexcurrentComponent <
                     (copyCurrentObject["Iso3D"].toObject())["Component"].toArray().size() &&
                     (((copyCurrentObject["Iso3D"].toObject())["Component"].toArray())[IndexcurrentComponent]).toString().replace(" ", "") ==
                     (ui.isoNameEdit->toPlainText()).replace(" ", ""))
            {
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Fxyz", ui.UpdateEdit);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Xmin", ui.xmin);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Xmax", ui.xmax);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Ymin", ui.ymin);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Ymax", ui.ymax);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Zmin", ui.zmin);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Zmax", ui.zmax);
                appendall(copyCurrentObject2, "Funct", ui.tableWidget_Fct);
                appendall(copyCurrentObject2, "Const", ui.tableWidget_Cst);

                copyCurrentObject2.remove("Param3D");
                copyCurrentObject2.remove("Param4D");
                copyCurrentObject["Iso3D"] = copyCurrentObject2;
            }
            else
            {
                // Add new component:
                if ((((copyCurrentObject["Iso3D"].toObject())["Component"].toArray())[IndexcurrentComponent]).toString().replace(" ", "") !=
                        (ui.isoNameEdit->toPlainText()).replace(" ", ""))
                {
                    appednew(copyCurrentObject2, "Component", ui.isoNameEdit);
                    appednew(copyCurrentObject2, "Fxyz", ui.UpdateEdit);
                    appednew(copyCurrentObject2, "Xmin", ui.xmin);
                    appednew(copyCurrentObject2, "Xmax", ui.xmax);
                    appednew(copyCurrentObject2, "Ymin", ui.ymin);
                    appednew(copyCurrentObject2, "Ymax", ui.ymax);
                    appednew(copyCurrentObject2, "Zmin", ui.zmin);
                    appednew(copyCurrentObject2, "Zmax", ui.zmax);

                    if (copyCurrentObject2["Cnd"].isArray())
                    {
                        array = copyCurrentObject2["Cnd"].toArray();
                        array.append(ui.CndUpdateEdit->toPlainText());
                        copyCurrentObject2["Cnd"] = array;
                    }
                    else if (ui.CndUpdateEdit->toPlainText() != "")
                    {
                        array = copyCurrentObject2["Cnd"].toArray();
                        for (int i = 0; i < copyCurrentObject2["Fxyz"].toArray().count();
                                i++)
                            array.append(ui.CndUpdateEdit->toPlainText());
                        copyCurrentObject2["Cnd"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Cnd");

                    if (copyCurrentObject2["Grid"].isArray())
                    {
                        array = copyCurrentObject2["Grid"].toArray();
                        array.append(QString::number(ui.xyzg->value()));
                        copyCurrentObject2["Grid"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Grid");
                }
                else
                {
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Fxyz", ui.UpdateEdit);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Xmin", ui.xmin);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Xmax", ui.xmax);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Ymin", ui.ymin);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Ymax", ui.ymax);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Zmin", ui.zmin);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Zmax", ui.zmax);

                    if (copyCurrentObject2["Cnd"].isArray())
                    {
                        array = copyCurrentObject2["Cnd"].toArray();
                        array.insert(IndexcurrentComponent, ui.CndUpdateEdit->toPlainText());
                        copyCurrentObject2["Cnd"] = array;
                    }
                    else if (ui.CndUpdateEdit->toPlainText() != "")
                    {
                        array = copyCurrentObject2["Cnd"].toArray();
                        for (int i = 0; i < copyCurrentObject2["Fxyz"].toArray().count();
                                i++)
                            array.append(ui.CndUpdateEdit->toPlainText());
                        copyCurrentObject2["Cnd"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Cnd");
                }

                appendall(copyCurrentObject2, "Funct", ui.tableWidget_Fct);
                appendall(copyCurrentObject2, "Const", ui.tableWidget_Cst);

                copyCurrentObject["Iso3D"] = copyCurrentObject2;
            }
        }
    }
    else if (copyCurrentObject["Param3D"].isObject() || copyCurrentObject["Param3D_C"].isObject())
    {
        copyCurrentObject.remove("Iso3D");
        QJsonObject copyCurrentObject2 =
                copyCurrentObject["Param3D"].isObject() ? copyCurrentObject["Param3D"].toObject() : copyCurrentObject["Param3D_C"].toObject();
        if (IndexcurrentComponent != -1)
        {
            if ((ui.paramNameEdit->toPlainText()).replace(" ", "") == "")
            {
                for(uint ui=0; ui<MandatoryParmetric3DFields.size(); ui++)
                    removeat(IndexcurrentComponent, copyCurrentObject2, MandatoryParmetric3DFields[ui]);
                removeat2(2*IndexcurrentComponent, copyCurrentObject2, "Grid");
                removeat2(2*IndexcurrentComponent, copyCurrentObject2, "Grid");
                removeat2(IndexcurrentComponent, copyCurrentObject2, "Cnd");
                appendall(copyCurrentObject2, "Funct", ui.tableWidget_Fct_2);
                appendall(copyCurrentObject2, "Const", ui.tableWidget_Cst_2);
                // Some keys cleaning..
                copyCurrentObject2.remove("Iso3D");
                copyCurrentObject2.remove("Param4D");
                if(copyCurrentObject["Param3D"].isObject())
                    copyCurrentObject["Param3D"] = copyCurrentObject2;
                else
                    copyCurrentObject["Param3D_C"] = copyCurrentObject2;
            }
            else if ((((copyCurrentObject["Param3D"].toObject())["Component"].toArray()).count() > 0 &&
                     IndexcurrentComponent > -1 && IndexcurrentComponent <
                     ((copyCurrentObject["Param3D"].toObject())["Component"].toArray()).size() &&
                     ((copyCurrentObject["Param3D"].toObject())["Component"].toArray())[IndexcurrentComponent].toString().replace(" ", "") ==
                     (ui.paramNameEdit->toPlainText()).replace(" ", ""))  ||

                     (((copyCurrentObject["Param3D_C"].toObject())["Component"].toArray()).count() > 0 &&
                     IndexcurrentComponent > -1 && IndexcurrentComponent <
                     ((copyCurrentObject["Param3D_C"].toObject())["Component"].toArray()).size() &&
                     ((copyCurrentObject["Param3D_C"].toObject())["Component"].toArray())[IndexcurrentComponent].toString().replace(" ", "") ==
                     (ui.paramNameEdit->toPlainText()).replace(" ", ""))
                     )
            {
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Fx", ui.XEdit);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Fy", ui.YEdit);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Fz", ui.ZEdit);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Umin", ui.umin);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Umax", ui.umax);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Vmin", ui.vmin);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Vmax", ui.vmax);
                appendall(copyCurrentObject2, "Funct", ui.tableWidget_Fct_2);
                appendall(copyCurrentObject2, "Const", ui.tableWidget_Cst_2);
                if (copyCurrentObject2["Cnd"].isArray() &&
                        copyCurrentObject2["Cnd"].toArray().count() > IndexcurrentComponent)
                {
                    array = copyCurrentObject2["Cnd"].toArray();
                    array.replace(IndexcurrentComponent, ui.CndUpdateEdit_2->toPlainText());
                    copyCurrentObject2["Cnd"] = array;
                }
                else if (ui.CndUpdateEdit_2->toPlainText() != "")
                {
                    array = copyCurrentObject2["Cnd"].toArray();
                    for (int i = 0; i < copyCurrentObject2["Fx"].toArray().count(); i++)
                        array.append(ui.CndUpdateEdit_2->toPlainText());
                    copyCurrentObject2["Cnd"] = array;
                }
                else
                    copyCurrentObject2.remove("Cnd");
                if(copyCurrentObject["Param3D"].isObject())
                    copyCurrentObject["Param3D"] = copyCurrentObject2;
                else
                    copyCurrentObject["Param3D_C"] = copyCurrentObject2;
            }
            else
            {
                if ((((copyCurrentObject["Param3D"].toObject())["Component"].toArray())[IndexcurrentComponent].toString().replace(" ", "") !=
                        (ui.paramNameEdit->toPlainText()).replace(" ", "")) ||
                    (((copyCurrentObject["Param3D_C"].toObject())["Component"].toArray())[IndexcurrentComponent].toString().replace(" ", "") !=
                                                (ui.paramNameEdit->toPlainText()).replace(" ", ""))
                    )
                {
                    appednew(copyCurrentObject2, "Component", ui.paramNameEdit);
                    appednew(copyCurrentObject2, "Fx", ui.XEdit);
                    appednew(copyCurrentObject2, "Fy", ui.YEdit);
                    appednew(copyCurrentObject2, "Fz", ui.ZEdit);
                    appednew(copyCurrentObject2, "Umin", ui.umin);
                    appednew(copyCurrentObject2, "Umax", ui.umax);
                    appednew(copyCurrentObject2, "Vmin", ui.vmin);
                    appednew(copyCurrentObject2, "Vmax", ui.vmax);
                    if (copyCurrentObject2["Grid"].isArray())
                    {
                        array = copyCurrentObject2["Grid"].toArray();
                        int pos=2*IndexcurrentComponent;
                        array.append((array.at(pos).toString()));
                        array.append((array.at(pos+1).toString()));
                        copyCurrentObject2["Grid"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Grid");

                    if (copyCurrentObject2["Cnd"].isArray())
                    {
                        array = copyCurrentObject2["Cnd"].toArray();
                        array.append(ui.CndUpdateEdit_2->toPlainText());
                        copyCurrentObject2["Cnd"] = array;
                    }
                    else if (ui.CndUpdateEdit_2->toPlainText() != "")
                    {
                        array = copyCurrentObject2["Cnd"].toArray();
                        for (int i = 0; i < copyCurrentObject2["Fx"].toArray().count(); i++)
                            array.append(ui.CndUpdateEdit_2->toPlainText());
                        copyCurrentObject2["Cnd"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Cnd");
                }
                else
                {
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Fx", ui.XEdit);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Fy", ui.YEdit);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Fz", ui.ZEdit);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Umin", ui.umin);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Umax", ui.umax);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Vmin", ui.vmin);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Vmax", ui.vmax);
                    array = copyCurrentObject2["Component"].toArray();
                    array.insert(IndexcurrentComponent, ui.paramNameEdit->toPlainText());
                    copyCurrentObject2["Component"] = array;
                    if (copyCurrentObject2["Cnd"].isArray())
                    {
                        array = copyCurrentObject2["Cnd"].toArray();
                        array.append(ui.CndUpdateEdit_2->toPlainText());
                        copyCurrentObject2["Cnd"] = array;
                    }
                    else if (ui.CndUpdateEdit_2->toPlainText() != "")
                    {
                        array = copyCurrentObject2["Cnd"].toArray();
                        for (int i = 0; i < copyCurrentObject2["Fx"].toArray().count(); i++)
                            array.append(ui.CndUpdateEdit_2->toPlainText());
                        copyCurrentObject2["Cnd"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Cnd");
                }
                appendall(copyCurrentObject2, "Funct", ui.tableWidget_Fct_2);
                appendall(copyCurrentObject2, "Const", ui.tableWidget_Cst_2);
                if(copyCurrentObject["Param3D"].isObject())
                    copyCurrentObject["Param3D"] = copyCurrentObject2;
                else
                    copyCurrentObject["Param3D_C"] = copyCurrentObject2;
            }
        }
    }
    else if (copyCurrentObject["Param4D"].isObject() || copyCurrentObject["Param4D_C"].isObject())
    {
        copyCurrentObject.remove("Iso3D");
        copyCurrentObject.remove("Param3D");
        copyCurrentObject.remove("Param3D_C");
        QJsonObject copyCurrentObject2 = copyCurrentObject["Param4D"].isObject() ? copyCurrentObject["Param4D"].toObject() : copyCurrentObject["Param4D_C"].toObject();
        if (IndexcurrentComponent != -1)
        {
            if ((ui.paramNameEdit_2->toPlainText()).replace(" ", "") == "")
            {
                for(uint ui=0; ui<MandatoryParmetric4DFields.size(); ui++)
                    removeat(IndexcurrentComponent, copyCurrentObject2, MandatoryParmetric4DFields[ui]);
                removeat2(2*IndexcurrentComponent, copyCurrentObject2, "Grid");
                removeat2(2*IndexcurrentComponent, copyCurrentObject2, "Grid");
                if(copyCurrentObject["Param4D"].isObject())
                    copyCurrentObject["Param4D"] = copyCurrentObject2;
                else
                    copyCurrentObject["Param4D_C"] = copyCurrentObject2;
            }
            else if ((((copyCurrentObject["Param4D"].toObject())["Component"].toArray()).count() > 0 &&
                     IndexcurrentComponent > -1 && IndexcurrentComponent <((copyCurrentObject["Param4D"].toObject())["Component"].toArray()).size() &&
                     ((copyCurrentObject["Param4D"].toObject())["Component"].toArray())[IndexcurrentComponent].toString().replace(" ", "") ==(ui.paramNameEdit_2->toPlainText()).replace(" ", ""))
                 ||
                     (((copyCurrentObject["Param4D_C"].toObject())["Component"].toArray()).count() > 0 &&
                                          IndexcurrentComponent > -1 && IndexcurrentComponent <((copyCurrentObject["Param4D_C"].toObject())["Component"].toArray()).size() &&
                                          ((copyCurrentObject["Param4D_C"].toObject())["Component"].toArray())[IndexcurrentComponent].toString().replace(" ", "") ==(ui.paramNameEdit_2->toPlainText()).replace(" ", ""))
                )
            {
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Fx", ui.XEdit_2);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Fy", ui.YEdit_2);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Fz", ui.ZEdit_2);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Fw", ui.WEdit_2);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Umin", ui.umin_2);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Umax", ui.umax_2);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Vmin", ui.vmin_2);
                replaceat(IndexcurrentComponent, copyCurrentObject2, "Vmax", ui.vmax_2);
                if(copyCurrentObject["Param4D"].isObject())
                    copyCurrentObject["Param4D"] = copyCurrentObject2;
                else
                    copyCurrentObject["Param4D_C"] = copyCurrentObject2;
            }
            else
            {
                if ((((copyCurrentObject["Param4D"].toObject())["Component"].toArray())[IndexcurrentComponent].toString().replace(" ", "") !=
                        (ui.paramNameEdit_2->toPlainText()).replace(" ", "")) ||
                        (((copyCurrentObject["Param4D_C"].toObject())["Component"].toArray())[IndexcurrentComponent].toString().replace(" ", "") !=
                                                (ui.paramNameEdit_2->toPlainText()).replace(" ", ""))
                        )
                {
                    appednew(copyCurrentObject2, "Component", ui.paramNameEdit_2);
                    appednew(copyCurrentObject2, "Fx", ui.XEdit_2);
                    appednew(copyCurrentObject2, "Fy", ui.YEdit_2);
                    appednew(copyCurrentObject2, "Fz", ui.ZEdit_2);
                    appednew(copyCurrentObject2, "Fw", ui.WEdit_2);
                    appednew(copyCurrentObject2, "Umin", ui.umin_2);
                    appednew(copyCurrentObject2, "Umax", ui.umax_2);
                    appednew(copyCurrentObject2, "Vmin", ui.vmin_2);
                    appednew(copyCurrentObject2, "Vmax", ui.vmax_2);
                    if (copyCurrentObject2["Grid"].isArray())
                    {
                        array = copyCurrentObject2["Grid"].toArray();
                        int pos=2*IndexcurrentComponent;
                        array.append((array.at(pos).toString()));
                        array.append((array.at(pos+1).toString()));
                        copyCurrentObject2["Grid"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Grid");
                    if(copyCurrentObject["Param4D"].isObject())
                        copyCurrentObject["Param4D"] = copyCurrentObject2;
                    else
                        copyCurrentObject["Param4D_C"] = copyCurrentObject2;
                }
                else
                {
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Component", ui.paramNameEdit_2);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Fx", ui.XEdit_2);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Fy", ui.YEdit_2);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Fz", ui.ZEdit_2);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Fw", ui.WEdit_2);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Umin", ui.umin_2);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Umax", ui.umax_2);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Vmin", ui.vmin_2);
                    insertat(IndexcurrentComponent, copyCurrentObject2, "Vmax", ui.vmax_2);

                    if(copyCurrentObject["Param4D"].isObject())
                        copyCurrentObject["Param4D"] = copyCurrentObject2;
                    else
                        copyCurrentObject["Param4D_C"] = copyCurrentObject2;
                }
            }
        }
    }
}

void DrawingOptions::RunUpdatedJObject(QJsonObject &CurrentObject)
{
    if (IndexcurrentComponent != -1)
    {
        if (CurrentObject["Iso3D"].isObject())
        {
            CurrentObject.remove("Param3D");CurrentObject.remove("Param3D_C");
            CurrentObject.remove("Param4D");CurrentObject.remove("Param4D_C");
            CurrentObject.remove("ParIso");
            DrawJsonModel(CurrentObject);
        }
        else if (CurrentObject["Param3D"].isObject() || CurrentObject["Param3D_C"].isObject())
        {
            CurrentObject.remove("Iso3D");
            CurrentObject.remove("Param4D");CurrentObject.remove("Param4D_C");
            CurrentObject.remove("ParIso");
            DrawJsonModel(CurrentObject);
        }
        else if (CurrentObject["Param4D"].isObject() || CurrentObject["Param4D_C"].isObject())
        {
            CurrentObject.remove("Iso3D");
            CurrentObject.remove("Param3D");CurrentObject.remove("Param3D_C");
            CurrentObject.remove("ParIso");
            DrawJsonModel(CurrentObject);
        }
        else
        {
            CurrentObject.remove("Iso3D");
            CurrentObject.remove("Param3D");
            CurrentObject.remove("Param4D");
            CurrentObject.remove("Param3D_C");
            CurrentObject.remove("Param4D_C");
            DrawJsonModel(CurrentObject);
        }
    }
}

void DrawingOptions::on_updateButton_clicked()
{
    QJsonObject CurrentObject = MathmodRef->RootObjet.CurrentJsonObject;
    QJsonObject parisoComponent;
    if (CurrentObject["ParIso"].isArray())
    {
        QJsonArray listeObj = CurrentObject["ParIso"].toArray();
        QJsonArray listeIsoObj;
        QJsonArray listeParObj;
        for (int i = 0; i < listeObj.size(); i++)
            if ((listeObj[i].toObject())["Iso3D"].isObject())
                listeIsoObj.append(listeObj[i].toObject());
            else
                listeParObj.append(listeObj[i].toObject());
        int page = ui.parisocomboBox->currentIndex();
        if (page == 1) // Iso3D
        {
            parisoComponent = listeIsoObj[0].toObject();
            on_updateJObject(parisoComponent);
            QJsonArray newlisteObj;
            newlisteObj.append(parisoComponent);
            if (listeParObj.size() > 0)
                newlisteObj.append(listeParObj[0].toObject());
            CurrentObject["ParIso"] = newlisteObj;
            RunUpdatedJObject(CurrentObject);
        }
        else if (page == 0)   // Param3D
        {
            parisoComponent = listeParObj[0].toObject();
            on_updateJObject(parisoComponent);
            QJsonArray newlisteObj;
            newlisteObj.append(parisoComponent);
            if (listeIsoObj.size() > 0)
                newlisteObj.append(listeIsoObj[0].toObject());
            CurrentObject["ParIso"] = newlisteObj;
            RunUpdatedJObject(CurrentObject);
        }
    }
    else
    {
        CurrentObject.remove("ParIso");
        on_updateJObject(CurrentObject);
        RunUpdatedJObject(CurrentObject);
    }
}

void DrawingOptions::on_updateParam_clicked()
{
    on_updateButton_clicked();
}

void DrawingOptions::on_actionPolygonWavefront_obj_triggered()
{
    MathmodRef->SaveSceneAsObjPoly();
}

void DrawingOptions::on_actionColorPolygonWavefront_obj_triggered()
{
    MathmodRef->SaveSceneAsObjPoly(1);
}

void DrawingOptions::on_linecolumn_2_valueChanged(int value)
{
    ui.ParamgroupBox_2->setTitle("Grid(u,v)/MaxGrid = (" + QString::number(value) +
                                 ", " + QString::number(value) +") / "+QString::number(Parameters->ParMaxGrid));
    if (!MathmodRef->ParObjet->isRunning())
    {
        (MathmodRef->RootObjet.CurrentJsonObject["ParIso"].isArray()) ?
        MathmodRef->linecolumn_valueChanged(value, PARISO_TYPE) : MathmodRef->linecolumn_valueChanged(value, PAR_TYPE);
    }
    else
    {
        ui.uv->blockSignals(true);
        ui.uv->setChecked(false);
        ui.uv->blockSignals(false);
        MathmodRef->uvactivated = -1;
    }
}

void DrawingOptions::on_lineScrollBarValueChanged(int value)
{
    ui.ParamgroupBox_2->setTitle(
        "Grid(u,v)/MaxGrid = (" + QString::number(value) + ", " +
        QString::number(MathmodRef->ParObjet->Ugrid) +") / "+QString::number(Parameters->ParMaxGrid));
    if (!MathmodRef->ParObjet->isRunning())
    {
        MathmodRef->line_valueChanged(value);
    }
    else
    {
        ui.uv->blockSignals(true);
        ui.uv->setChecked(false);
        ui.uv->blockSignals(false);
        MathmodRef->uvactivated = -1;
    }
}

void DrawingOptions::on_coloneScrollBarValueChanged(int value)
{
    ui.ParamgroupBox_2->setTitle(
        "Param Grid(u,v)/MaxGrid = (" +
        QString::number(MathmodRef->ParObjet->Vgrid) + ", " +
        QString::number(value) +") / "+QString::number(Parameters->ParMaxGrid));
    if (!MathmodRef->ParObjet->isRunning())
    {
        MathmodRef->column_valueChanged(value);
    }
    else
    {
        ui.uv->blockSignals(true);
        ui.uv->setChecked(false);
        ui.uv->blockSignals(false);
        MathmodRef->uvactivated = -1;
    }
}

void DrawingOptions::onIsoComponentActivated(int index)
{
    UpdateDescription(index, ISO_TYPE, MathmodRef->RootObjet.CurrentTreestruct);
    updateShowIsoCmp(index);
}
void DrawingOptions::updateShowParComp(int index)
{
    if(MathmodRef->LocalScene.componentsinfos.ShowParIsoCmp[index])
    {
        ui.ShowParComp->setChecked(true);
        ui.ShowParComp->setText("Hide");
    }
    else
    {
        ui.ShowParComp->setChecked(false);
        ui.ShowParComp->setText("Show");
    }
}
void DrawingOptions::updateShowIsoCmp(int index)
{
    uint idx=0;
    if(!MathmodRef->LocalScene.componentsinfos.pariso)
        idx = index;
    else
        idx = MathmodRef->LocalScene.componentsinfos.NbComponentsType[0]+index;
    if(MathmodRef->LocalScene.componentsinfos.ShowParIsoCmp[idx])
    {
        ui.ShowIsoComp->setChecked(true);
        ui.ShowIsoComp->setText("Hide");
    }
    else
    {
        ui.ShowIsoComp->setChecked(false);
        ui.ShowIsoComp->setText("Show");
    }
}
void DrawingOptions::on_ParamComponent_activated(int index)
{
    UpdateDescription(index, PAR_TYPE, MathmodRef->RootObjet.CurrentTreestruct);
    updateShowParComp(index);
}

void DrawingOptions::on_xyzcheckBox2_clicked()
{
    MathmodRef->LocalScene.animxyz *= -1;
}

void DrawingOptions::on_xycheckBox2_clicked()
{
    MathmodRef->LocalScene.animx *= -1;
}

void DrawingOptions::on_xyhorizontalScrollBar2_valueChanged(int value)
{
    MathmodRef->LocalScene.animxValueStep = float(value) / 4;
}

void DrawingOptions::on_xzcheckBox2_clicked()
{
    MathmodRef->LocalScene.animy *= -1;
}

void DrawingOptions::on_xzhorizontalScrollBar2_valueChanged(int value)
{
    MathmodRef->LocalScene.animyValueStep = float(value) / 4;
}

void DrawingOptions::on_yzcheckBox2_clicked()
{
    MathmodRef->LocalScene.animz *= -1;
}

void DrawingOptions::on_yzhorizontalScrollBar2_valueChanged(int value)
{
    MathmodRef->LocalScene.animzValueStep = float(value) / 4;
}

void DrawingOptions::on_InitMatrix_2_clicked()
{
    MathmodRef->LocalScene.RotStrength =
        MathmodRef->LocalScene.animxValueStep =
            MathmodRef->LocalScene.animyValueStep =
                MathmodRef->LocalScene.animzValueStep = 0.0;
}

void DrawingOptions::on_xycheckBox_clicked()
{
    MathmodRef->ParObjet->tetaxy_ok *= -1;
}

void DrawingOptions::on_xyhorizontalScrollBarValueChanged(int value)
{
    MathmodRef->ParObjet->tetaxy = value / 4.0;
}

void DrawingOptions::on_xzcheckBox_clicked()
{
    MathmodRef->ParObjet->tetaxz_ok *= -1;
}

void DrawingOptions::on_xzhorizontalScrollBarValueChanged(int value)
{
    MathmodRef->ParObjet->tetaxz = value / 4.0;
}

void DrawingOptions::on_yzcheckBox_clicked()
{
    MathmodRef->ParObjet->tetayz_ok *= -1;
}

void DrawingOptions::on_yzhorizontalScrollBarValueChanged(int value)
{
    MathmodRef->ParObjet->tetayz = value / 4.0;
}

void DrawingOptions::on_xwcheckBox_clicked()
{
    MathmodRef->ParObjet->tetaxw_ok *= -1;
}

void DrawingOptions::on_xwhorizontalScrollBarValueChanged(int value)
{
    MathmodRef->ParObjet->tetaxw = value / 4.0;
}

void DrawingOptions::on_ywcheckBox_clicked()
{
    MathmodRef->ParObjet->tetayw_ok *= -1;
}

void DrawingOptions::on_ywhorizontalScrollBarValueChanged(int value)
{
    MathmodRef->ParObjet->tetayw = value / 4.0;
}

void DrawingOptions::on_zwcheckBox_clicked()
{
    MathmodRef->ParObjet->tetazw_ok *= -1;
}

void DrawingOptions::on_zwhorizontalScrollBarValueChanged(int value)
{
    MathmodRef->ParObjet->tetazw = value / 4.0;
}

void DrawingOptions::on_linecolumn_3_valueChanged(int value)
{
    ui.ParamgroupBox_3->setTitle("Grid(u,v)/MaxGrid = (" + QString::number(value) +
                                 ", " + QString::number(value) +") / "+QString::number(Parameters->ParMaxGrid));
    if (!MathmodRef->ParObjet->isRunning())
    {
        MathmodRef->linecolumn_valueChanged_2(value);
    }
    else
    {
        ui.uv4D->blockSignals(true);
        ui.uv4D->setChecked(false);
        ui.uv4D->blockSignals(false);
        MathmodRef->uvactivated4D = -1;
    }
}

void DrawingOptions::oncolor_4activated(int index)
{
    MathmodRef->colorstypeParam(index);
}

void DrawingOptions::on_uv4D_clicked()
{
    MathmodRef->slot_uv4D_clicked();
}

void DrawingOptions::on_uv_clicked()
{
    (MathmodRef->RootObjet.CurrentJsonObject["ParIso"].isArray()) ?
    MathmodRef->slot_uv_clicked(PARISO_TYPE) : MathmodRef->slot_uv_clicked(PAR_TYPE);
}

void DrawingOptions::on_InitMatrix_clicked()
{
    MathmodRef->ParObjet->mat4D.unit();
    on_calculate_clicked();
}

void DrawingOptions::on_ActivateCNDClicked(bool checked)
{
    ui.CNDgroupBox->setEnabled(checked);
    MathmodRef->LocalScene.activarecnd = checked;
    MathmodRef->update();
}

void DrawingOptions::on_TCNDcheckBoxClicked(bool checked)
{
    MathmodRef->LocalScene.cndoptions[3] = checked;
    MathmodRef->update();
}

void DrawingOptions::on_FCNDcheckBoxClicked(bool checked)
{
    MathmodRef->LocalScene.cndoptions[0] = checked;
    MathmodRef->update();
}

void DrawingOptions::on_TNCNDcheckBoxClicked(bool checked)
{
    MathmodRef->LocalScene.cndoptions[4] = checked;
    MathmodRef->update();
}

void DrawingOptions::on_FNCNDcheckBoxClicked(bool checked)
{
    MathmodRef->LocalScene.cndoptions[1] = checked;
    MathmodRef->update();
}

void DrawingOptions::on_TBordercheckBoxClicked(bool checked)
{
    MathmodRef->LocalScene.cndoptions[2] = checked;
    MathmodRef->update();
}

void DrawingOptions::on_actionMesh_triggered()
{
    MathmodRef->Mesh();
}

void DrawingOptions::on_calculate_clicked()
{
    on_InitTButton_clicked();
    Run_JsonObject_activeted();
}

void DrawingOptions::on_actionAbout_2_triggered()
{
    ab.show();
}

void DrawingOptions::on_actionLoad_json_script_triggered()
{
    LoadNewFileModels(true);
}

void DrawingOptions::on_actionScreenshot_triggered()
{
    videoplay();
}

void DrawingOptions::on_actionEditor_triggered()
{
    editorwin();
}

void DrawingOptions::on_cut_clicked()
{
    if (ui.IsoComponent->count() > 1)
    {
        ui.isoNameEdit->setText("");
        on_updateButton_clicked();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Only one component in this mathematical model.");
        msgBox.exec();
    }
}

void DrawingOptions::on_actionConvert_K3DS_script_triggered()
{
    LoadK3DSurfScript("", 1);
}

void DrawingOptions::on_ParamComponent_2_activated(int index)
{
    UpdateDescription(index, PAR_4D_TYPE,
                      MathmodRef->RootObjet.CurrentTreestruct);
}

void DrawingOptions::on_updateParam_2_clicked()
{
    on_updateButton_clicked();
}

void DrawingOptions::Multiplier(int x, int y, int z, QJsonObject &iso,
                                int index)
{
    QString Minx, Miny, Minz, Maxx, Maxy, Maxz;
    QString Difx, Dify, Difz;
    QString componentName, fct, cnd, grid;
    QJsonArray oldminx, oldminy, oldminz, oldmaxx, oldmaxy, oldmaxz, oldcmpname,
               oldfxyz, oldcnd, oldgrid;
    bool cndb = false;
    bool gridb = false;
    oldminx = iso["Iso3D"].toObject()["Xmin"].toArray();
    oldminy = iso["Iso3D"].toObject()["Ymin"].toArray();
    oldminz = iso["Iso3D"].toObject()["Zmin"].toArray();
    oldmaxx = iso["Iso3D"].toObject()["Xmax"].toArray();
    oldmaxy = iso["Iso3D"].toObject()["Ymax"].toArray();
    oldmaxz = iso["Iso3D"].toObject()["Zmax"].toArray();
    oldcmpname = iso["Iso3D"].toObject()["Component"].toArray();
    oldfxyz = iso["Iso3D"].toObject()["Fxyz"].toArray();
    if ((gridb = (iso["Iso3D"].toObject()["Grid"].isArray())))
        grid =
            (oldgrid = iso["Iso3D"].toObject()["Grid"].toArray())[index].toString();
    if ((cndb = (iso["Iso3D"].toObject()["Cnd"].isArray())))
        cnd = (oldcnd = iso["Iso3D"].toObject()["Cnd"].toArray())[index].toString();
    componentName = oldcmpname[index].toString();
    fct = oldfxyz[index].toString();
    Minx = "(" + oldminx[index].toString() + ")";
    Miny = "(" + oldminy[index].toString() + ")";
    Minz = "(" + oldminz[index].toString() + ")";
    Maxx = "(" + oldmaxx[index].toString() + ")";
    Maxy = "(" + oldmaxy[index].toString() + ")";
    Maxz = "(" + oldmaxz[index].toString() + ")";
    Difx = "((" + Maxx + "-" + Minx + ")/" + QString::number(x) + ")";
    Dify = "((" + Maxy + "-" + Miny + ")/" + QString::number(y) + ")";
    Difz = "((" + Maxz + "-" + Minz + ")/" + QString::number(z) + ")";
    int l = 0;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
            {
                oldminx.append(Minx + "+" + QString::number(i) + "*" + Difx);
                oldmaxx.append(Minx + "+" + QString::number(i + 1) + "*" + Difx);
                oldminy.append(Miny + "+" + QString::number(j) + "*" + Dify);
                oldmaxy.append(Miny + "+" + QString::number(j + 1) + "*" + Dify);
                oldminz.append(Minz + "+" + QString::number(k) + "*" + Difz);
                oldmaxz.append(Minz + "+" + QString::number(k + 1) + "*" + Difz);
                oldcmpname.append(componentName + QString::number(l));
                oldfxyz.append(fct);
                if (cndb)
                    oldcnd.append(cnd);
                if (gridb)
                    oldgrid.append(grid);
                l++;
            }
    oldminx.removeAt(index);
    oldminy.removeAt(index);
    oldminz.removeAt(index);
    oldmaxx.removeAt(index);
    oldmaxy.removeAt(index);
    oldmaxz.removeAt(index);
    oldcmpname.removeAt(index);
    oldfxyz.removeAt(index);
    if (cndb)
        oldcnd.removeAt(index);
    if (gridb)
        oldgrid.removeAt(index);
    QJsonObject tmp = iso["Iso3D"].toObject();
    tmp["Xmin"] = oldminx;
    tmp["Ymin"] = oldminy;
    tmp["Zmin"] = oldminz;
    tmp["Xmax"] = oldmaxx;
    tmp["Ymax"] = oldmaxy;
    tmp["Zmax"] = oldmaxz;
    tmp["Component"] = oldcmpname;
    tmp["Fxyz"] = oldfxyz;
    if (cndb)
        tmp["Cnd"] = oldcnd;
    if (gridb)
        tmp["Grid"] = oldgrid;
    iso["Iso3D"] = tmp;
}

void DrawingOptions::on_Multiplier_clicked()
{
    int i = ui.xcomboBox->currentIndex(), j = ui.ycomboBox->currentIndex(),
        k = ui.zcomboBox->currentIndex();
    if (i > 0 && j > 0 && k > 0)
    {
        QJsonObject copyCurrentObject = MathmodRef->RootObjet.CurrentJsonObject;
        // Erase unused Keys:
        copyCurrentObject.remove("Param3D");
        copyCurrentObject.remove("Param4D");
        copyCurrentObject.remove("Param3D_C");
        copyCurrentObject.remove("Param4D_C");
        Multiplier(i, j, k, copyCurrentObject, IndexcurrentComponent);
        // Draw here
        DrawJsonModel(copyCurrentObject);
    }
    // Init Combo
    ui.xcomboBox->setCurrentIndex(0);
    ui.ycomboBox->setCurrentIndex(0);
    ui.zcomboBox->setCurrentIndex(0);
}

void DrawingOptions::UpdateGuiMaxgrid()
{
    int maxgrd = int(Parameters->IsoMaxGrid);
    ui.xyzg->blockSignals(true);
    ui.xyzg->setMaximum(maxgrd);
    ui.xyzg->setValue(int(InitIsoGrid));
    ui.Isogroupbox->setTitle("Iso Grid/Max Grid ("+QString::number(int(InitIsoGrid)) +"/500 ) :");
    ui.xyzg->blockSignals(false);
    ui.linecolumn_2->blockSignals(true);
    ui.linecolumn_2->setMaximum(int(Parameters->ParMaxGrid));
    ui.linecolumn_2->setValue(int(InitParGrid));
    ui.linecolumn_2->blockSignals(false);
    ui.linecolumn_3->blockSignals(true);
    ui.linecolumn_3->setMaximum(int(Parameters->ParMaxGrid));
    ui.linecolumn_3->setValue(int(InitParGrid));
    ui.linecolumn_3->blockSignals(false);
}

void DrawingOptions::UpdateGui()
{

    UpdateGuiMaxgrid();
    ListeModelTexture LstModelTexture = (Parameters->LoadCollectionModels(
            JSONMathModels, MathmodRef->collection));
    // Load the script containing isosurface and parametric formulas:
    ui.choice->insertItems(0, LstModelTexture.listeModels);
    ui.comboBoxTexture->insertItems(0, LstModelTexture.listeTextures);
    ui.comboBoxPigment->insertItems(0, LstModelTexture.listePigments);
    ui.Messagetext->hide();
    AddListModels();

    // Threads setting:
    SetThreadValues(Threads);
    // OpenGl specular:
    SetSpecularValues(Parameters->Specular);
    // OpenGl shininess:
    SetShininessValue(Parameters->Shininess);
    // OpenGl diffuse:
    SetDiffuseValues(Parameters->Diffuse);
    // OpenGl Ambient:
    SetAmbientValues(Parameters->Ambient);
    // Gl Front Face Suupport

    if(!Parameters->glFrontFacingSupport)
        SetglFrontFacingSupport();

    QList<int> Sizes1;
    Sizes1 << 600 << 750;
    ui.splitter_9->setSizes(Sizes1);

    // Pigment/texture
    ui.textureEdit->hide();
    // Hide all sliders
    HideSliders();

    // ProgressBar + text informations (set to minimum size 0)
    ui.Messagetext->setFontPointSize(12);

    // Script Editor font size
    ui.ScriptEditor->setFontPointSize(Parameters->scripteditorfontsize);
}

void DrawingOptions::on_TimeStepScrollBarValueChanged(int value)
{
    double P = 1.0 / double(value);
    uint maxnbthreads = MathmodRef->IsoObjet->WorkerThreadsNumber;
    ui.label_5->setText("1/" + QString::number(value));
    MathmodRef->IsoObjet->masterthread->pace = P;
    for (uint nbthreds = 0; nbthreds < maxnbthreads - 1; nbthreds++)
        MathmodRef->IsoObjet->workerthreads[nbthreds].pace = P;
    MathmodRef->ParObjet->masterthread->pace = P;
    for (uint nbthreds = 0; nbthreds < maxnbthreads - 1; nbthreds++)
        MathmodRef->ParObjet->workerthreads[nbthreds].pace = P;
}

void DrawingOptions::on_InitTButton_clicked()
{
    uint maxnbthreads = MathmodRef->IsoObjet->WorkerThreadsNumber;
    MathmodRef->IsoObjet->masterthread->stepMorph = 0;
    for (uint nbthreds = 0; nbthreds < maxnbthreads - 1; nbthreds++)
        MathmodRef->IsoObjet->workerthreads[nbthreds].stepMorph = 0;
    MathmodRef->ParObjet->masterthread->stepMorph = 0;
    for (uint nbthreds = 0; nbthreds < maxnbthreads - 1; nbthreds++)
        MathmodRef->ParObjet->workerthreads[nbthreds].stepMorph = 0;
}

void DrawingOptions::ShowErrorMessage(QJsonParseError &err, QString &script)
{
    QString sortie;
    QMessageBox message;
    message.setWindowTitle("Error at : ");
    sortie = (script);
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
    return;
}

void DrawingOptions::ReadCollectionFile(QString JsonFileName,
        QJsonObject &js)
{
    QJsonParseError err;
    QString sortie;
    QFile JsonFile(JsonFileName);
    if (!JsonFile.exists())
    {
        QFile file2(":/mathmodcollection_empty.js");
        file2.copy(JsonFileName);
        QFile::setPermissions(JsonFileName,
                              QFileDevice::ReadOwner | QFileDevice::WriteOwner);
    }
    QFile file(JsonFileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QJsonDocument doc = QJsonDocument::fromJson(
                                ((file.readAll()).trimmed())
                                .replace("\n", "")
                                .replace("\t", "")
                                .replace("DOTSYMBOL", Parameters->dotsymbol.toStdString().c_str()),
                                &err);
        if (err.error)
        {
            QMessageBox message;
            message.setWindowTitle("Error at : " + JsonFileName);
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

void DrawingOptions::SaveToFile_CurentMathModel(
    QJsonObject CurrentJsonObject)
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save to file", "",
                       "JSON Files (*.js)");
    if (fileName != "")
    {
        QJsonObject collection;
        ReadCollectionFile(fileName, collection);
        QJsonDocument document;
        if (collection["MathModels"].isArray())
        {
            QJsonArray array = collection["MathModels"].toArray();
            array.append(CurrentJsonObject);
            collection["MathModels"] = array;
            document.setObject(collection);
            QFile f(fileName);
            if (f.open(QIODevice::ReadWrite | QIODevice::Text))
            {
                QTextStream t(&f);
                QString tmp = QString(document.toJson()).toLatin1();
                t << tmp.toUtf8();
                f.close();
            }
        }
    }
}

void DrawingOptions::on_pushButton_2_clicked()
{
    QJsonParseError err;
    QString sortie;
    QString script =
        ui.ScriptEditor->toPlainText().trimmed().replace("\n", "").replace("\t", "").replace("DOTSYMBOL", Parameters->dotsymbol.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(script.toUtf8(), &err);
    if (err.error)
    {
        ShowErrorMessage(err, script);
        return;
    }
    SaveToFile_CurentMathModel(doc.object());
}

void DrawingOptions::on_pushButton_3_clicked()
{
    ui.isoNameEdit->setText(ui.isoNameEdit->toPlainText() + "_01");
    on_updateButton_clicked();
}

void DrawingOptions::on_cut_2_clicked()
{
    if (ui.ParamComponent->count() > 1)
    {
        ui.paramNameEdit->setText("");
        on_updateButton_clicked();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Only one component in this mathematical model.");
        msgBox.exec();
    }
}

void DrawingOptions::on_pushButton_4_clicked()
{
    ui.paramNameEdit->setText(ui.paramNameEdit->toPlainText() + "_01");
    on_updateButton_clicked();
}

void DrawingOptions::on_color_5_activated(int index)
{
    MathmodRef->colorstypeParIso(index);
}

void DrawingOptions::on_transparent_ParIso_valueChanged(int value)
{
    MathmodRef->transparency(value, IndexcurrentComponent);
}

void DrawingOptions::on_comboBoxTexture_activated(int index)
{
    QJsonObject tmp;
    tmp = MathmodRef->RootObjet.CurrentJsonObject;

    if (index > 0)
    {
        QJsonDocument document;
        document.setObject(MathmodRef->collection.JTextures[index - 1].toObject());
        ui.textureEdit->setText(QString(document.toJson()));
        DrawJsonModel(tmp, index - 1);
    }
    return;
}

void DrawingOptions::on_comboBoxPigment_activated(int index)
{
    QJsonObject tmp;
    tmp = MathmodRef->RootObjet.CurrentJsonObject;
    if (index > 0)
    {
        QJsonDocument document;
        document.setObject(MathmodRef->collection.JPigments[index - 1].toObject());
        ui.textureEdit->setText(QString(document.toJson()));
        DrawJsonModel(tmp, 1000 + index - 1);
    }
    return;
}

void DrawingOptions::on_actionTrianglesWavefront_obj_triggered()
{
    MathmodRef->SaveSceneAsObjTrian();
}

void DrawingOptions::on_actionColorTrianglesWavefront_obj_triggered()
{
    MathmodRef->SaveSceneAsObjTrian(1);
}

void DrawingOptions::on_ShowtextureScript_clicked()
{
    static int show = -1;
    show *= -1;
    if (show == 1)
    {
        ui.textureEdit->show();
        ui.ShowtextureScript->setText("Hide Script");
    }
    else
    {
        ui.textureEdit->hide();
        ui.ShowtextureScript->setText("Show Script");
    }
}

void DrawingOptions::on_pushButton_5_clicked()
{
    QJsonParseError err;
    QString sortie;
    QString script = ui.textureEdit->toPlainText().trimmed().replace("\n", "").replace("\t", "").replace("DOTSYMBOL", Parameters->dotsymbol.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(script.toUtf8(), &err);
    if (err.error)
    {
        ShowErrorMessage(err, script);
        return;
    }
    QJsonObject tmp = doc.object();
    if (tmp["Texture"].isObject())
    {
        MathmodRef->collection.JTextures[ui.comboBoxTexture->currentIndex() - 1] =doc.object();
        on_comboBoxTexture_activated(ui.comboBoxTexture->currentIndex());
    }
    else
    {
        MathmodRef->collection.JPigments[ui.comboBoxPigment->currentIndex() - 1] =doc.object();
        on_comboBoxPigment_activated(ui.comboBoxPigment->currentIndex());
    }
}

void DrawingOptions::on_C1ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 0);
}

void DrawingOptions::on_C2ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 1);
}

void DrawingOptions::on_C3ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 2);
}

void DrawingOptions::on_C4ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 3);
}

void DrawingOptions::on_C5ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 4);
}

void DrawingOptions::on_C6ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 5);
}

void DrawingOptions::on_C7ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 6);
}

void DrawingOptions::on_C8ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 7);
}

void DrawingOptions::on_C9ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 8);
}

void DrawingOptions::on_C10ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 9);
}

void DrawingOptions::on_C11ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 10);
}

void DrawingOptions::on_C12ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 11);
}

void DrawingOptions::on_C13ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 12);
}

void DrawingOptions::on_C14ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 13);
}

void DrawingOptions::on_C15ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 14);
}

void DrawingOptions::on_C16ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 15);
}

void DrawingOptions::on_C17ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 16);
}

void DrawingOptions::on_C18ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 17);
}

void DrawingOptions::on_C19ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 18);
}

void DrawingOptions::on_C20ScrollBarValueChanged(int val)
{
    CScrollBarValueChanged(val, 19);
}

void DrawingOptions::CScrollBarValueChanged(int val, int idx)
{
    MathmodRef->LocalScene.slider = 1;
    MathmodRef->IsoObjet->masterthread->SliderValues[uint(idx)] =val;
    MathmodRef->ParObjet->masterthread->SliderValues[uint(idx)] =val;
    SliderArray[idx].SliderLabel->setText(qlstnames.at(idx) + " = " +QString::number(val));
    if (CurrentFormulaType == 2)
        MathmodRef->ProcessNewIsoSurface();
    else
        MathmodRef->ParametricSurfaceProcess(CurrentFormulaType);
    MathmodRef->LocalScene.slider = -1;
}

void DrawingOptions::on_PredefinedSets_activated(int index)
{
    indexcurrentSet = index;
    if (index > 0)
    {
        int size = (qlstnames.size());
        MathmodRef->LocalScene.slider = 1;
        for (int i = 0; i < size; ++i)
        {
            MathmodRef->IsoObjet->masterthread->SliderValues[uint(i)] =
                qlstPos.at(i + (index - 1) * size).toDouble();
            MathmodRef->ParObjet->masterthread->SliderValues[uint(i)] =
                qlstPos.at(i + (index - 1) * size).toDouble();
        }
        for (int sl = 0; sl < 20; sl++)
        {
            if (size >= (sl + 1))
            {
                (SliderArray[sl].SliderLabel)
                ->setText(qlstnames.at(sl) + " = " +qlstPos.at(sl + (index - 1) * size) + "(" +qlstStep.at(sl) + ")");
                (SliderArray[sl].SliderScrollBar)->blockSignals(true);
                if (qlstmin.size() > qlstnames.size())
                {
                    (SliderArray[sl].SliderScrollBar)->setMaximum(qlstmax.at(sl + (index - 1) * size).toInt());
                    (SliderArray[sl].SliderScrollBar)->setMinimum(qlstmin.at(sl + (index - 1) * size).toInt());
                    (SliderArray[sl].SliderScrollBar)->setSingleStep(qlstStep.at(sl + (index - 1) * size).toInt());
                    (SliderArray[sl].SliderLabel)->setText(qlstnames.at(sl) + " = " +qlstPos.at(sl + (index - 1) * size) + "(" +qlstStep.at(sl + (index - 1) * size) + ")");
                    (SliderArray[sl].SliderLabelMin)->setText(qlstmin.at(sl + (index - 1) * size));
                    (SliderArray[sl].SliderLabelMax)->setText(qlstmax.at(sl + (index - 1) * size));
                }
                (SliderArray[sl].SliderScrollBar)->setSliderPosition(qlstPos.at(sl + (index - 1) * size).toInt());
                (SliderArray[sl].SliderScrollBar)->blockSignals(false);
            }
        }
        // Draw
        if (CurrentFormulaType == 2)
            MathmodRef->ProcessNewIsoSurface();
        else
            MathmodRef->ParametricSurfaceProcess(CurrentFormulaType);
        MathmodRef->LocalScene.slider = -1;
    }
}
void DrawingOptions::CIndextoolButton_clicked(int idx)
{
    int range = (indexcurrentSet < 1)? (idx - 1) : (indexcurrentSet - 1) * qlstnames.size() + (idx - 1);
    sliderconf.currentSlider = (idx - 1);
    sliderconf.ui.MaxEdit->setText(qlstmax[range]);
    sliderconf.ui.MinEdit->setText(qlstmin[range]);
    sliderconf.ui.StepEdit->setText(qlstStep[range]);
    sliderconf.ui.PosEdit->setText(qlstPos[range]);
    sliderconf.ui.ParametersComboBox->blockSignals(true);
    sliderconf.ui.ParametersComboBox->setCurrentIndex(idx);
    sliderconf.ui.ParametersComboBox->blockSignals(false);
    sliderconf.show();
}

void DrawingOptions::on_C20toolButton_clicked()
{
    CIndextoolButton_clicked(20);
}

void DrawingOptions::on_C19toolButton_clicked()
{
    CIndextoolButton_clicked(19);
}

void DrawingOptions::on_C18toolButton_clicked()
{
    CIndextoolButton_clicked(18);
}

void DrawingOptions::on_C17toolButton_clicked()
{
    CIndextoolButton_clicked(17);
}

void DrawingOptions::on_C16toolButton_clicked()
{
    CIndextoolButton_clicked(16);
}

void DrawingOptions::on_C15toolButton_clicked()
{
    CIndextoolButton_clicked(15);
}

void DrawingOptions::on_C14toolButton_clicked()
{
    CIndextoolButton_clicked(14);
}

void DrawingOptions::on_C13toolButton_clicked()
{
    CIndextoolButton_clicked(13);
}

void DrawingOptions::on_C12toolButton_clicked()
{
    CIndextoolButton_clicked(12);
}

void DrawingOptions::on_C11toolButton_clicked()
{
    CIndextoolButton_clicked(11);
}

void DrawingOptions::on_C10toolButton_clicked()
{
    CIndextoolButton_clicked(10);
}

void DrawingOptions::on_C9toolButton_clicked()
{
    CIndextoolButton_clicked(9);
}

void DrawingOptions::on_C8toolButton_clicked()
{
    CIndextoolButton_clicked(8);
}

void DrawingOptions::on_C7toolButton_clicked()
{
    CIndextoolButton_clicked(7);
}

void DrawingOptions::on_C6toolButton_clicked()
{
    CIndextoolButton_clicked(6);
}

void DrawingOptions::on_C5toolButton_clicked()
{
    CIndextoolButton_clicked(5);
}

void DrawingOptions::on_C4toolButton_clicked()
{
    CIndextoolButton_clicked(4);
}

void DrawingOptions::on_C3toolButton_clicked()
{
    CIndextoolButton_clicked(3);
}

void DrawingOptions::on_C2toolButton_clicked()
{
    CIndextoolButton_clicked(2);
}

void DrawingOptions::on_C1toolButton_clicked()
{
    CIndextoolButton_clicked(1);
}

void DrawingOptions::update_slider_param()
{
    int SliderIndex = sliderconf.currentSlider;

    for (int sl = 0; sl < 20; sl++)
    {
        if (SliderIndex == sl)
        {
            qlstmax[sl] = sliderconf.ui.MaxEdit->text();
            qlstmin[sl] = sliderconf.ui.MinEdit->text();
            qlstStep[sl] = sliderconf.ui.StepEdit->text();
            qlstPos[sl] = sliderconf.ui.PosEdit->text();
            (SliderArray[sl].SliderScrollBar)->blockSignals(true);
            (SliderArray[sl].SliderScrollBar)->setMaximum(qlstmax.at(sl).toInt());
            (SliderArray[sl].SliderScrollBar)->setMinimum(qlstmin.at(sl).toInt());
            (SliderArray[sl].SliderScrollBar)->setSingleStep(qlstStep.at(sl).toInt());
            (SliderArray[sl].SliderScrollBar)->setPageStep(qlstStep.at(sl).toInt());
            (SliderArray[sl].SliderScrollBar)->setSliderPosition(qlstPos.at(sl).toInt());
            (SliderArray[sl].SliderLabel)->setText(qlstnames.at(sl) + " = " + qlstPos.at(sl) + "(" +qlstStep.at(sl) + ")");
            (SliderArray[sl].SliderLabelMin)->setText(qlstmin.at(sl));
            (SliderArray[sl].SliderLabelMax)->setText(qlstmax.at(sl));
            (SliderArray[sl].SliderScrollBar)->blockSignals(false);
            MathmodRef->IsoObjet->masterthread->SliderNames.push_back(qlstnames.at(sl).toStdString());
            MathmodRef->ParObjet->masterthread->SliderNames.push_back(qlstnames.at(sl).toStdString());
            MathmodRef->IsoObjet->masterthread->SliderValues.push_back(qlstPos.at(sl).toDouble());
            MathmodRef->ParObjet->masterthread->SliderValues.push_back(qlstPos.at(sl).toDouble());
        }
    }
    // Draw
    MathmodRef->LocalScene.slider = 1;
    if (CurrentFormulaType == 2)
        MathmodRef->ProcessNewIsoSurface();
    else
        MathmodRef->ParametricSurfaceProcess(CurrentFormulaType);
    MathmodRef->LocalScene.slider = -1;
}

void DrawingOptions::on_AddSetButton_clicked()
{
    QJsonArray array1, array2, array3, array4, array5;
    QJsonObject tmp, tmp2;
    tmp = MathmodRef->RootObjet.CurrentJsonObject;
    tmp2 = tmp["Sliders"].toObject();
    array2 = tmp2["Position"].toArray();
    array3 = tmp2["Min"].toArray();
    array4 = tmp2["Max"].toArray();
    array5 = tmp2["Step"].toArray();
    int size = qlstnames.size();
    if (tmp2["SetNames"].isArray())
    {
        array1 = tmp2["SetNames"].toArray();
        array1.append("Objet_"+QString::number(tmp2["SetNames"].toArray().size()));
    }
    else
        tmp2.remove("SetNames");
    for (int sl = 0; sl < 20; sl++)
    {
        if (size >= (sl + 1))
        {
            array2.append(QString::number((SliderArray[sl].SliderScrollBar)->sliderPosition()));
            array3.append(QString::number((SliderArray[sl].SliderScrollBar)->minimum()));
            array4.append(QString::number((SliderArray[sl].SliderScrollBar)->maximum()));
            array5.append(QString::number((SliderArray[sl].SliderScrollBar)->singleStep()));
        }
    }
    if (tmp2["SetNames"].isArray())
    {
        tmp2["SetNames"] = array1;
    }
    else
        tmp2.remove("SetNames");
    tmp2["Position"] = array2;
    tmp2["Min"] = array3;
    tmp2["Max"] = array4;
    tmp2["Step"] = array5;
    tmp["Sliders"] = tmp2;
    // Draw here
    DrawJsonModel(tmp);
}

void DrawingOptions::on_CutSetButton_clicked()
{
    int size2 = qlstPos.size();
    int size = qlstnames.size();
    if (size2 >= 2 * size)
    {
        QJsonArray array1, array2, array3, array4, array5;
        QJsonObject tmp, tmp2;
        tmp = MathmodRef->RootObjet.CurrentJsonObject;
        tmp2 = tmp["Sliders"].toObject();
        if (tmp2["SetNames"].isArray())
        {
            array1 = tmp2["SetNames"].toArray();
            array1.removeAt(indexcurrentSet - 1);
        }
        array2 = tmp2["Position"].toArray();
        for (int i = 0; i < size; i++)
            array2.removeAt((indexcurrentSet - 1) * size);
        array3 = tmp2["Min"].toArray();
        for (int i = 0; i < size; i++)
            array3.removeAt((indexcurrentSet - 1) * size);
        array4 = tmp2["Max"].toArray();
        for (int i = 0; i < size; i++)
            array4.removeAt((indexcurrentSet - 1) * size);
        array5 = tmp2["Step"].toArray();
        for (int i = 0; i < size; i++)
            array5.removeAt((indexcurrentSet - 1) * size);
        if (tmp2["SetNames"].isArray())
        {
            tmp2["SetNames"] = array1;
        }
        else
            tmp2.remove("SetNames");
        tmp2["Position"] = array2;
        tmp2["Min"] = array3;
        tmp2["Max"] = array4;
        tmp2["Step"] = array5;
        tmp["Sliders"] = tmp2;
        // Draw here
        DrawJsonModel(tmp);
    }
}

void DrawingOptions::on_AddParam_clicked()
{
    addnewparam.ui.NameEdit->setText("ParamName");
    addnewparam.ui.MaxEdit->setText("50");
    addnewparam.ui.MinEdit->setText("0");
    addnewparam.ui.StepEdit->setText("1");
    addnewparam.ui.PosEdit->setText("10");
    addnewparam.show();
}

void DrawingOptions::on_CutParam_clicked()
{
    int index = ui.ParametersList->currentIndex();
    if (index > 0)
    {
        QJsonArray array2;
        QJsonObject tmp, tmp2;
        int names, position;
        tmp = MathmodRef->RootObjet.CurrentJsonObject;
        tmp2 = tmp["Sliders"].toObject();
        array2 = tmp2["Name"].toArray();
        names = array2.size();
        array2.removeAt(index - 1);
        tmp2["Name"] = array2;
        array2 = tmp2["Max"].toArray();
        position = array2.size();
        for (int i = 0; i * names < position; i++)
            array2.removeAt(index - 1 - i + i * names);
        tmp2["Max"] = array2;
        array2 = tmp2["Min"].toArray();
        position = array2.size();
        for (int i = 0; i * names < position; i++)
            array2.removeAt(index - 1 - i + i * names);
        tmp2["Min"] = array2;
        array2 = tmp2["Step"].toArray();
        position = array2.size();
        for (int i = 0; i * names < position; i++)
            array2.removeAt(index - 1 - i + i * names);
        tmp2["Step"] = array2;
        array2 = tmp2["Position"].toArray();
        position = array2.size();
        for (int i = 0; i * names < position; i++)
            array2.removeAt(index - 1 - i + i * names);
        tmp2["Position"] = array2;
        tmp["Sliders"] = tmp2;
        // Draw here
        DrawJsonModel(tmp);
    }
}

void DrawingOptions::add_new_param()
{
    QJsonArray array2;
    QJsonObject tmp, tmp2;
    int names, position;
    tmp = MathmodRef->RootObjet.CurrentJsonObject;
    tmp2 = tmp["Sliders"].toObject();
    array2 = tmp2["Name"].toArray();
    names = array2.empty() ? 0 : array2.size();
    array2.append(addnewparam.ui.NameEdit->text());
    tmp2["Name"] = array2;
    array2 = tmp2["Position"].toArray();
    position = array2.empty() ? 0 : array2.size();
    if (names == 0)
        array2.append(addnewparam.ui.PosEdit->text());
    else
        for (int i = 1; i * names <= position; i++)
            array2.insert(i * names + i - 1, addnewparam.ui.PosEdit->text());
    tmp2["Position"] = array2;
    array2 = tmp2["Max"].toArray();
    position = array2.empty() ? 0 : array2.size();
    if (names == 0)
        array2.append(addnewparam.ui.MaxEdit->text());
    else
        for (int i = 1; i * names <= position; i++)
            array2.insert(i * names + i - 1, addnewparam.ui.MaxEdit->text());
    tmp2["Max"] = array2;
    array2 = tmp2["Min"].toArray();
    position = array2.empty() ? 0 : array2.size();
    if (names == 0)
        array2.append(addnewparam.ui.MinEdit->text());
    else
        for (int i = 1; i * names <= position; i++)
            array2.insert(i * names + i - 1, addnewparam.ui.MinEdit->text());
    tmp2["Min"] = array2;
    array2 = tmp2["Step"].toArray();
    position = array2.empty() ? 0 : array2.size();
    if (names == 0)
        array2.append(addnewparam.ui.StepEdit->text());
    else
        for (int i = 1; i * names <= position; i++)
            array2.insert(i * names + i - 1, addnewparam.ui.StepEdit->text());
    tmp2["Step"] = array2;
    tmp["Sliders"] = tmp2;
    // Draw here
    DrawJsonModel(tmp);
}

void DrawingOptions::update_infos_param(int index)
{
    CIndextoolButton_clicked(index);
    sliderconf.currentSlider = index - 1;
}

void DrawingOptions::on_actionFrames_triggered()
{
    MathmodRef->frames_clicked();
}

void DrawingOptions::SetSpecularValues(int *spec)
{
    ui.red_Specular->blockSignals(true);
    ui.red_Specular->setSliderPosition(spec[0]);
    ui.red_Specular->blockSignals(false);
    ui.green_Specular->blockSignals(true);
    ui.green_Specular->setSliderPosition(spec[1]);
    ui.green_Specular->blockSignals(false);
    ui.blue_Specular->blockSignals(true);
    ui.blue_Specular->setSliderPosition(spec[2]);
    ui.blue_Specular->blockSignals(false);
    ui.transparent_Specular->blockSignals(true);
    ui.transparent_Specular->setSliderPosition(spec[3]);
    ui.transparent_Specular->blockSignals(false);
    MathmodRef->lightSpecular[0]= Parameters->Specular[0]/100.0f;
    MathmodRef->lightSpecular[1]= Parameters->Specular[1]/100.0f;
    MathmodRef->lightSpecular[2]= Parameters->Specular[2]/100.0f;
    MathmodRef->lightSpecular[3]= Parameters->Specular[3]/100.0f;
}
void DrawingOptions::SetDiffuseValues(int *spec)
{
    ui.red_Diffuse->blockSignals(true);
    ui.red_Diffuse->setSliderPosition(spec[0]);
    ui.red_Diffuse->blockSignals(false);
    ui.green_Diffuse->blockSignals(true);
    ui.green_Diffuse->setSliderPosition(spec[1]);
    ui.green_Diffuse->blockSignals(false);
    ui.blue_Diffuse->blockSignals(true);
    ui.blue_Diffuse->setSliderPosition(spec[2]);
    ui.blue_Diffuse->blockSignals(false);
    ui.transparent_Diffuse->blockSignals(true);
    ui.transparent_Diffuse->setSliderPosition(spec[3]);
    ui.transparent_Diffuse->blockSignals(false);
    MathmodRef->lightDiffuse[0]= Parameters->Diffuse[0]/100.0f;
    MathmodRef->lightDiffuse[1]= Parameters->Diffuse[1]/100.0f;
    MathmodRef->lightDiffuse[2]= Parameters->Diffuse[2]/100.0f;
    MathmodRef->lightDiffuse[3]= Parameters->Diffuse[3]/100.0f;
}
void DrawingOptions::SetAmbientValues(int *spec)
{
    ui.red_Ambient->blockSignals(true);
    ui.red_Ambient->setSliderPosition(spec[0]);
    ui.red_Ambient->blockSignals(false);
    ui.green_Ambient->blockSignals(true);
    ui.green_Ambient->setSliderPosition(spec[1]);
    ui.green_Ambient->blockSignals(false);
    ui.blue_Ambient->blockSignals(true);
    ui.blue_Ambient->setSliderPosition(spec[2]);
    ui.blue_Ambient->blockSignals(false);
    ui.transparent_Ambient->blockSignals(true);
    ui.transparent_Ambient->setSliderPosition(spec[3]);
    ui.transparent_Ambient->blockSignals(false);
    MathmodRef->lightAmbient[0]= Parameters->Ambient[0]/100.0f;
    MathmodRef->lightAmbient[1]= Parameters->Ambient[1]/100.0f;
    MathmodRef->lightAmbient[2]= Parameters->Ambient[2]/100.0f;
    MathmodRef->lightAmbient[3]= Parameters->Ambient[3]/100.0f;
}

void DrawingOptions::SetThreadValues(int *thread)
{
    ui.ThreadNumberScrollBar->blockSignals(true);
    ui.ThreadNumberScrollBar->setSliderPosition(thread[0]);
    ui.ThreadNumberScrollBar->setMinimum(thread[1]);
    ui.ThreadNumberScrollBar->setMaximum(thread[2]);
    ui.ThreadgroupBox->setTitle(
        "Threads: " + QString::number(ui.ThreadNumberScrollBar->minimum()) +
        "  <  " + QString::number(thread[0]) + "  <  " +
        QString::number(ui.ThreadNumberScrollBar->maximum()));
    ui.ThreadNumberScrollBar->blockSignals(false);
}

void DrawingOptions::SetShininessValue(int shin)
{
    ui.ShininessScrollBar->blockSignals(true);
    ui.ShininessScrollBar->setSliderPosition(shin);
    ui.ShininessScrollBar->blockSignals(false);
    MathmodRef->LocalScene.shininess = Parameters->Shininess;
}

void DrawingOptions::SetglFrontFacingSupport()
{
    ui.GLFrontSurfaceSupport->blockSignals(true);
    ui.GLFrontSurfaceSupport->setChecked(false);
    ui.GLFrontSurfaceSupport->blockSignals(false);
    MathmodRef->LocalScene.glFrontFacingSupport = 0;
}

void DrawingOptions::on_red_Specular_valueChanged(int value)
{
    MathmodRef->redSpec(value);
    if (ui.GcheckBox->isChecked())
    {
        ui.green_Specular->blockSignals(true);
        ui.green_Specular->setSliderPosition(value);
        ui.green_Specular->blockSignals(false);
        MathmodRef->greenSpec(value);
    }
    if (ui.BcheckBox->isChecked())
    {
        ui.blue_Specular->blockSignals(true);
        ui.blue_Specular->setSliderPosition(value);
        ui.blue_Specular->blockSignals(false);
        MathmodRef->blueSpec(value);
    }
}

void DrawingOptions::on_green_Specular_valueChanged(int value)
{
    MathmodRef->greenSpec(value);
    if (ui.RcheckBox->isChecked())
    {
        ui.red_Specular->blockSignals(true);
        ui.red_Specular->setSliderPosition(value);
        ui.red_Specular->blockSignals(false);
        MathmodRef->redSpec(value);
    }
    if (ui.BcheckBox->isChecked())
    {
        ui.blue_Specular->blockSignals(true);
        ui.blue_Specular->setSliderPosition(value);
        ui.blue_Specular->blockSignals(false);
        MathmodRef->blueSpec(value);
    }
}

void DrawingOptions::on_blue_Specular_valueChanged(int value)
{
    MathmodRef->blueSpec(value);
    if (ui.GcheckBox->isChecked())
    {
        ui.green_Specular->blockSignals(true);
        ui.green_Specular->setSliderPosition(value);
        ui.green_Specular->blockSignals(false);
        MathmodRef->greenSpec(value);
    }
    if (ui.RcheckBox->isChecked())
    {
        ui.red_Specular->blockSignals(true);
        ui.red_Specular->setSliderPosition(value);
        ui.red_Specular->blockSignals(false);
        MathmodRef->redSpec(value);
    }
    //MathmodRef->InitSpecularParameters();
}

void DrawingOptions::on_transparent_Specular_valueChanged(int value)
{
    MathmodRef->transSpec(value);
}

void DrawingOptions::on_ShininessScrollBarValueChanged(int value)
{
    MathmodRef->Shininess(value);
}

void DrawingOptions::on_ThreadNumberScrollBarValueChanged(int value)
{
    MathmodRef->ParObjet->UpdateThredsNumber(uint(value));
    MathmodRef->IsoObjet->UpdateThredsNumber(uint(value));
    ui.ThreadgroupBox->setTitle(
        "Threads: " + QString::number(ui.ThreadNumberScrollBar->minimum()) +
        "  <  " + QString::number(value) + "  <  " +
        QString::number(ui.ThreadNumberScrollBar->maximum()));
}

void DrawingOptions::on_StopCalculationsButton_clicked()
{
    MathmodRef->IsoObjet->stopcalculations(true);
    MathmodRef->ParObjet->stopcalculations(true);
}

void DrawingOptions::on_stopButton_clicked()
{
    on_StopCalculationsButton_clicked();
}

void DrawingOptions::on_actionScripts_selection_triggered()
{
    select.show();
}

void DrawingOptions::on_actionAnimation_Rotation_triggered()
{
    MathmodRef->anim();
}

void DrawingOptions::on_actionMorph_use_t_parameter_triggered()
{
    MathmodRef->morph();
}

void DrawingOptions::on_TreeViewButton_clicked()
{
    ShowCurrentObjectTree = !ShowCurrentObjectTree;
    if (ShowCurrentObjectTree)
    {
        UpdateTreeObject();
        ui.ObjectClasseCurrent->show();
    }
    else
    {
        UpdateTreeObject();
        ui.ObjectClasseCurrent->hide();
    }
}

void DrawingOptions::on_ObjectClasseCurrent_clicked(const QModelIndex &idx)
{
    QModelIndex parentItem = idx.parent();
    if (!parentItem.isValid())
    {
        int row = idx.row();
        if (MathmodRef->RootObjet.CurrentParisoTreestruct.size() > 0 &&
                int(MathmodRef->RootObjet.CurrentParisoTreestruct.size()) > row)
            ui.parisocomboBox->setCurrentIndex(row);
    }
}

void DrawingOptions::on_parisocomboBox_currentIndexChanged(int index)
{
    if (index >= 0)
    {
        ModelType type = MathmodRef->RootObjet.CurrentParisoTreestruct[index].type;
        if (type == ISO_TYPE)
            UpdateIsoModelDetailsPage(MathmodRef->RootObjet.CurrentParisoTreestruct[index]);
        else if (type == PAR_TYPE)
            UpdatePar3DModelDetailsPage(MathmodRef->RootObjet.CurrentParisoTreestruct[index]);
        else if (type == PAR_4D_TYPE)
            UpdatePar4DModelDetailsPage(MathmodRef->RootObjet.CurrentParisoTreestruct[index]);
    }
}

void DrawingOptions::on_ApplypushButton_clicked()
{
    int maxisogrid = 0;
    bool IsInt=false;
    QString maxtxt= ui.IsoMaxGridLineEdit->text().replace(" ", "");
    maxisogrid = maxtxt.toInt(&IsInt, 10);
    if ( IsInt && maxisogrid != Parameters->IsoMaxGrid)
    {
        Parameters->IsoMaxGrid = maxisogrid;
        ui.Isogroupbox->setTitle("Grid/MaxGrid = (" +
                                 QString::number(ui.xyzg->value()) + "/" +
                                 QString::number(maxisogrid) + ")");
        ui.xyzg->blockSignals(true);
        ui.xyzg->setMaximum(maxisogrid);
        ui.xyzg->blockSignals(false);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Invalid number");
        msgBox.exec();
    }
}

void DrawingOptions::updateParametricGridSliders(int maxpargrid)
{
    Parameters->ParMaxGrid = maxpargrid;
    ui.linecolumn_2->blockSignals(true);
    ui.linecolumn_2->setMaximum(int(maxpargrid));
    ui.linecolumn_2->blockSignals(false);
    ui.linecolumn_3->blockSignals(true);
    ui.linecolumn_3->setMaximum(int(maxpargrid));
    ui.linecolumn_3->blockSignals(false);
    ui.ParamgroupBox_3->setTitle("Grid(u,v)/MaxGrid = ("+ QString::number(ui.linecolumn_3->value()) +
                                 ", " + QString::number(ui.linecolumn_3->value()) +")/"+QString::number(maxpargrid));
    ui.ParamgroupBox_2->setTitle("Grid(u,v)/MaxGrid = ("+ QString::number(ui.linecolumn_2->value()) +
                                 ", " + QString::number(ui.linecolumn_2->value()) +")/"+QString::number(maxpargrid));
}

void DrawingOptions::on_ApplypushButton_2_clicked()
{
    int maxpargrid = 0;
    bool IsInt=false;
    QString maxtxt= ui.ParMaxGridLineEdit->text().replace(" ", "");
    maxpargrid = maxtxt.toInt(&IsInt, 10);
    if ( IsInt && maxpargrid != Parameters->ParMaxGrid)
        updateParametricGridSliders(maxpargrid);

    else
    {
        QMessageBox msgBox;
        msgBox.setText("Invalid number");
        msgBox.exec();
    }
}

void DrawingOptions::on_ApplypushButton_3_clicked()
{
    int maxpargrid = 0;
    bool IsInt=false;
    QString maxtxt= ui.ParMaxGridLineEdit_2->text().replace(" ", "");
    maxpargrid = maxtxt.toInt(&IsInt, 10);
    if ( IsInt && maxpargrid != Parameters->ParMaxGrid)
        updateParametricGridSliders(maxpargrid);
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Invalid number");
        msgBox.exec();
    }
}

#include <QDesktopServices>
void DrawingOptions::on_actionDocumentation_triggered()
{
    QString link = "";
    link  = ((Parameters->docabsolutepath) == "" ?
    (QString("file:///%1/%2")
     .arg(QApplication::applicationDirPath())
     .arg(Parameters->docpartialpath)):
    Parameters->docabsolutepath);
    link.contains("http") ? QDesktopServices::openUrl(link):
                            QDesktopServices::openUrl(QUrl(link, QUrl::TolerantMode));
}

void DrawingOptions::on_ScaleButton_clicked()
{
    bool valx=false, valy=false, valz=false;
    double fx = ui.lineEditSx->text().toDouble(&valx);
    double fy = ui.lineEditSy->text().toDouble(&valy);
    double fz = ui.lineEditSz->text().toDouble(&valz);
    if (valx && valy && valz)
    {
        MathmodRef->factx=fx;
        MathmodRef->facty=fy;
        MathmodRef->factz=fz;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Invalid number");
        msgBox.exec();
    }
}

void DrawingOptions::on_ShowIsoComp_clicked()
{
    if(!ui.ShowIsoComp->isChecked())
    {
        ui.ShowIsoComp->setText("Show");
        if(!MathmodRef->LocalScene.componentsinfos.pariso)
            MathmodRef->LocalScene.componentsinfos.ShowParIsoCmp[IndexcurrentComponent]=false;
        else
            MathmodRef->LocalScene.componentsinfos.ShowParIsoCmp[MathmodRef->LocalScene.componentsinfos.NbComponentsType[0]+IndexcurrentComponent]=false;
    }
    else
    {
        ui.ShowIsoComp->setText("Hide");
        if(!MathmodRef->LocalScene.componentsinfos.pariso)
            MathmodRef->LocalScene.componentsinfos.ShowParIsoCmp[IndexcurrentComponent]=true;
        else
            MathmodRef->LocalScene.componentsinfos.ShowParIsoCmp[MathmodRef->LocalScene.componentsinfos.NbComponentsType[0]+IndexcurrentComponent]=true;
    }
    MathmodRef->update();
}

void DrawingOptions::on_ShowParComp_clicked()
{
    if(!ui.ShowParComp->isChecked())
    {
        ui.ShowParComp->setText("Show");
        MathmodRef->LocalScene.componentsinfos.ShowParIsoCmp[IndexcurrentComponent]=false;
    }
    else
    {
        ui.ShowParComp->setText("Hide");
        MathmodRef->LocalScene.componentsinfos.ShowParIsoCmp[IndexcurrentComponent]=true;
    }
    MathmodRef->update();
}

void DrawingOptions::on_actionAxe_triggered()
{
    MathmodRef->LocalScene.axe *=-1;
    MathmodRef->update();
}

void DrawingOptions::on_actionPlan_triggered()
{
    MathmodRef->LocalScene.plan *=-1;
    MathmodRef->update();
}

void DrawingOptions::on_red_Ambient_valueChanged(int value)
{
    MathmodRef->redAmb(value);
}

void DrawingOptions::on_green_Ambient_valueChanged(int value)
{
    MathmodRef->greenAmb(value);
}

void DrawingOptions::on_blue_Ambient_valueChanged(int value)
{
    MathmodRef->blueAmb(value);
}

void DrawingOptions::on_transparent_Ambient_valueChanged(int value)
{
    MathmodRef->transAmb(value);
}

void DrawingOptions::on_red_Diffuse_valueChanged(int value)
{
    MathmodRef->redDiff(value);
}

void DrawingOptions::on_green_Diffuse_valueChanged(int value)
{
    MathmodRef->greenDiff(value);
}

void DrawingOptions::on_blue_Diffuse_valueChanged(int value)
{
    MathmodRef->blueDiff(value);
}

void DrawingOptions::on_transparent_Diffuse_valueChanged(int value)
{
    MathmodRef->transDiff(value);
}

void DrawingOptions::on_GLFrontSurfaceSupport_clicked()
{
    if(!(ui.GLFrontSurfaceSupport->isChecked()))
        MathmodRef->glfrontfacesupp(0);
    else
        MathmodRef->glfrontfacesupp(1);
}

void DrawingOptions::on_actionbox_triggered()
{
    MathmodRef->boundingboxOk();
    MathmodRef->update();
}
