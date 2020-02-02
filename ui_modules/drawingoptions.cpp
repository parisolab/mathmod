/***************************************************************************
 *   Copyright (C) 2020by Abderrahman Taha                                *
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

static int indexcurrentFormula = -1;
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
    "NBSLIDERS_OUT_OF_RANGE",                   // 27
    "NBSLIDERSVALUES_OUT_OF_RANGE",             // 28
    "VERTEX_TAB_MEM_OVERFLOW",                  // 29
    "TRIANGLES_TAB_MEM_OVERFLOW",               // 30
    "MINPOLY_TAB_MEM_OVERFLOW",                 // 31
    "POLY_TAB_MEM_OVERFLOW",                    // 32
    "CND_TAB_MEM_OVERFLOW",                     // 33
    "CND_POL_MEM_OVERFLOW",                     // 34
    "DEFINED_PARAM_GRID_VERTEX_TAB_OVERFLOW",   // 35
    "DEFINED_PARAM_GRID_TRIANGLE_TAB_OVERFLOW", // 36
    "GRID_SUPERIOR_TO_GRIDMAX"                  // 37
};

// --------------------------
void DrawingOptions::ErrorMsg() const
{
    QMessageBox msgBox;
    if (scriptErrorType != SCRIPT_NO_ERROR)
    {
        statusBar()->showMessage(ScriptErrorMessage[scriptErrorType]);
        msgBox.setText(ScriptErrorMessage[scriptErrorType]);
        msgBox.exec();
    }
}
// --------------------------
void DrawingOptions::MemoryErrorMsg(int err) const
{
    QMessageBox msgBox;
    if (err != SCRIPT_NO_ERROR)
    {
        msgBox.setText(ScriptErrorMessage[err]);
        msgBox.exec();
    }
}
// --------------------------
void DrawingOptions::editorwin()
{
    editor *editorwindow = new editor();
    editorwindow->show();
}

// --------------------------
void DrawingOptions::colorsoptions()
{
    ColorsOptions *colorwindow = new ColorsOptions();
    connect(colorwindow->ui.color_2, SIGNAL(activated(int)), this,
            SLOT(oncolor_2activated(int)));
    connect(colorwindow->ui.red_2, SIGNAL(valueChanged(int)), this,
            SLOT(onred_2valueChanged(int)));
    connect(colorwindow->ui.green_2, SIGNAL(valueChanged(int)), this,
            SLOT(ongreen_2valueChanged(int)));
    connect(colorwindow->ui.blue_2, SIGNAL(valueChanged(int)), this,
            SLOT(onblue_2valueChanged(int)));
    connect(colorwindow->ui.transparent_2, SIGNAL(valueChanged(int)), this,
            SLOT(ontransparent_2valueChanged(int)));
    connect(colorwindow->ui.transparence_2, SIGNAL(clicked(bool)), this,
            SLOT(ontransparence_2clicked(bool)));
    colorwindow->show();
}

// --------------------------
void DrawingOptions::videoplay()
{
    QImage buf = MathmodRef->ui.glWidget->Copyscreenshot();
    screenimage *player = new screenimage(buf);
    player->connectcontrols();
    player->show();
}

// --------------------------
DrawingOptions::~DrawingOptions()
{
    delete[] SliderArray;
}

// --------------------------
DrawingOptions::DrawingOptions(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    indexcurrentFormula = -1;
    IsolistItemRef = nullptr;
    select.selectedoptions.showall = false;
    select.selectedoptions.sensitive = false;
    select.selectedoptions.AND = true;
    select.selectedoptions.parsefunctions = true;
    select.selectedoptions.parsenames = true;
    select.selectedoptions.parsecmpnames = true;
    connect(sliderconf.ui.SaveButton, SIGNAL(clicked()), this,
            SLOT(update_slider_param()));
    connect(sliderconf.ui.ParametersComboBox, SIGNAL(activated(int)), this,
            SLOT(update_infos_param(int)));
    connect(addnewparam.ui.SaveButton, SIGNAL(clicked()), this,
            SLOT(add_new_param()));
    connect(&select, SIGNAL(UpdateSignal()), this, SLOT(SearchListModels()));
    statusBar()->addPermanentWidget(ui.Progressbarwidget, 1);
    SaveSlidersRef();
    BuildAllVect();
    ui.ObjectClasseCurrent->hide();
    ui.ObjectClasseCurrent->header()->setSectionResizeMode(
        QHeaderView::ResizeToContents);
}

// --------------------------
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
// --------------------------
void DrawingOptions::on_xyzg_valueChanged(int value)
{
    ui.Isogroupbox->setTitle("Iso Grid ( " + QString::number(value) + " ) :");
    if (!MathmodRef->ui.glWidget->IsoObjet->isRunning())
    {
        MathmodRef->xyzg_valueChanged(value);
    }
    else
    {
        ui.ChangeGrid->blockSignals(true);
        ui.ChangeGrid->setChecked(false);
        ui.ChangeGrid->blockSignals(false);
        MathmodRef->xyzactivated = -1;
    }
}

// --------------------------
void DrawingOptions::on_ChangeGrid_clicked()
{
    MathmodRef->slot_checkBox73_clicked();
}

// --------------------------
void DrawingOptions::AddParObjectToTree(QTreeWidgetItem *paramlistItem,
                                        TreeStruct &currentstruct)
{
    if (!currentstruct.name.empty())
        paramlistItem->setText(0, currentstruct.name[0]);
    QColor greenColor = QColor(0, 255, 0, 50);
    paramlistItem->setBackgroundColor(0, greenColor);

    if (currentstruct.Component.size() > 0)
    {
        QTreeWidgetItem *cmpitem = new QTreeWidgetItem(paramlistItem);
        cmpitem->setText(0, "Components (" +
                         QString::number(currentstruct.Component.size()) +
                         "):");

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
            cmpitem6->setText(0, "U = [" + currentstruct.umin.at(j) + ", " +
                              currentstruct.umax.at(j) + "]");
            QTreeWidgetItem *cmpitem7 = new QTreeWidgetItem(cmpitem2);
            cmpitem7->setText(0, "V = [" + currentstruct.vmin.at(j) + ", " +
                              currentstruct.vmax.at(j) + "]");
            // Grid resolution:
            if (currentstruct.Grid.size() > 0 &&
                    (2 * j + 1) < currentstruct.Grid.size() &&
                    !MathmodRef->RootObjet.CurrentJsonObject["Param4D"].isObject())
            {
                QTreeWidgetItem *cmpitem7 = new QTreeWidgetItem(cmpitem2);
                cmpitem7->setText(0, "Grid = (" + currentstruct.Grid.at(2 * j) + " , " +
                                  currentstruct.Grid.at(2 * j + 1) + ")");
            }
        }
        // Add Global parameters:
        AddParametersToTree(paramlistItem, currentstruct);
    }
}

// --------------------------
void DrawingOptions::AddIsoObjectToTree(QTreeWidgetItem *IsolistItem,
                                        TreeStruct &currentstruct)
{
    if (!currentstruct.name.empty())
        IsolistItem->setText(0, currentstruct.name[0]);
    QColor greenColor = QColor(0, 255, 0, 50);
    IsolistItem->setBackgroundColor(0, greenColor);

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
            cmpitem4->setText(0, "X = [" + currentstruct.xmin.at(j) + ", " +
                              currentstruct.xmax.at(j) + "]");
            QTreeWidgetItem *cmpitem5 = new QTreeWidgetItem(cmpitem2);
            cmpitem5->setText(0, "Y = [" + currentstruct.ymin.at(j) + ", " +
                              currentstruct.ymax.at(j) + "]");
            QTreeWidgetItem *cmpitem6 = new QTreeWidgetItem(cmpitem2);
            cmpitem6->setText(0, "Z = [" + currentstruct.zmin.at(j) + ", " +
                              currentstruct.zmax.at(j) + "]");
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

// --------------------------
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

// --------------------------
void DrawingOptions::AddObjectToMySelectionTree()
{
    if (MathmodRef->RootObjet.CurrentJsonObject["Iso3D"].isObject())
    {
        QTreeWidgetItem *isolistItem =
            new QTreeWidgetItem(MyselectionItemReference);
        AddIsoObjectToTree(isolistItem, MathmodRef->RootObjet.CurrentTreestruct);
    }
    else if (MathmodRef->RootObjet.CurrentJsonObject["Param3D"].isObject() ||
             MathmodRef->RootObjet.CurrentJsonObject["Param4D"].isObject())
    {
        QTreeWidgetItem *paramlistItem =
            new QTreeWidgetItem(MyselectionItemReference);
        AddParObjectToTree(paramlistItem, MathmodRef->RootObjet.CurrentTreestruct);
    }
}

// -------------------------
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
            QTreeWidgetItem *parisochild =
                new QTreeWidgetItem(ui.ObjectClasseCurrent);
            if (MathmodRef->RootObjet.CurrentParisoTreestruct[i].type == ISO_TYPE)
                AddIsoObjectToTree(parisochild,
                                   MathmodRef->RootObjet.CurrentParisoTreestruct[i]);
            else
                AddParObjectToTree(parisochild,
                                   MathmodRef->RootObjet.CurrentParisoTreestruct[i]);
        }
    }
    else
    {
        if (MathmodRef->RootObjet.CurrentJsonObject["Iso3D"]
                .isObject()) // isoObject
        {
            ui.ObjectClasseCurrent->model()->removeRows(
                0, ui.ObjectClasseCurrent->model()->rowCount());
            QTreeWidgetItem *IsolistItem =
                new QTreeWidgetItem(ui.ObjectClasseCurrent);
            AddIsoObjectToTree(IsolistItem, MathmodRef->RootObjet.CurrentTreestruct);
        }
        else if (MathmodRef->RootObjet.CurrentJsonObject["Param3D"].isObject() ||
                 MathmodRef->RootObjet.CurrentJsonObject["Param4D"].isObject())
        {
            ui.ObjectClasseCurrent->model()->removeRows(
                0, ui.ObjectClasseCurrent->model()->rowCount());
            QTreeWidgetItem *paramlistItem =
                new QTreeWidgetItem(ui.ObjectClasseCurrent);
            AddParObjectToTree(paramlistItem,
                               MathmodRef->RootObjet.CurrentTreestruct);
        }
    }
}
// --------------------------
void DrawingOptions::UpdatePar4DModelDetailsPage(TreeStruct &currentstruct)
{
    ui.ParamComponent_2->clear();
    if (!currentstruct.name.empty())
        ui.groupBox->setTitle(currentstruct.name.at(0));
    ui.ParamComponent_2->insertItems(0, currentstruct.Component);
    ui.stackedProperties->setCurrentIndex(3);
    UpdateDescription(0, PAR_4D_TYPE, currentstruct);
}
// --------------------------
void DrawingOptions::UpdatePar3DModelDetailsPage(TreeStruct &currentstruct)
{
    ui.ParamComponent->clear();
    if (!currentstruct.name.empty())
        ui.groupBox->setTitle(currentstruct.name.at(0));
    ui.ParamComponent->insertItems(0, currentstruct.Component);
    ui.stackedProperties->setCurrentIndex(2);
    UpdateDescription(0, PAR_TYPE, currentstruct);
}
// --------------------------
void DrawingOptions::UpdateIsoModelDetailsPage(TreeStruct &currentstruct)
{
    ui.stackedProperties->setCurrentIndex(1);
    if (!currentstruct.name.empty())
        ui.groupBox->setTitle(currentstruct.name.at(0));
    ui.IsoComponent->clear();
    ui.IsoComponent->insertItems(0, currentstruct.Component);
    UpdateDescription(0, ISO_TYPE, currentstruct);
}
// --------------------------
void DrawingOptions::UpdateScriptEditorAndTreeObject()
{
    // Update the current Tree Object:
    if (ShowCurrentObjectTree)
        UpdateTreeObject();

    // Update the "Script Edit" page
    ui.ParamEdit->setText(MathmodRef->RootObjet.CurrentTreestruct.text);

    // Update the "Model Details" page
    if (MathmodRef->RootObjet.CurrentJsonObject["ParIso"].isArray())
    {
        ui.parisocomboBox->clear();
        if (MathmodRef->RootObjet.CurrentParisoTreestruct.size() > 0)
        {
            for (uint i = 0; i < MathmodRef->RootObjet.CurrentParisoTreestruct.size();
                    i++)
                ui.parisocomboBox->insertItem(
                    i, MathmodRef->RootObjet.CurrentParisoTreestruct[i].name[0]);

            if (MathmodRef->RootObjet.CurrentParisoTreestruct[0].fxyz.size() != 0)
                UpdateIsoModelDetailsPage(
                    MathmodRef->RootObjet.CurrentParisoTreestruct[0]);
            else if (MathmodRef->RootObjet.CurrentParisoTreestruct[0].fw.size() != 0)
                UpdatePar4DModelDetailsPage(
                    MathmodRef->RootObjet.CurrentParisoTreestruct[0]);
            else if (MathmodRef->RootObjet.CurrentParisoTreestruct[0].fx.size() != 0)
                UpdatePar3DModelDetailsPage(
                    MathmodRef->RootObjet.CurrentParisoTreestruct[0]);
        }
    }
    else if (MathmodRef->RootObjet.CurrentJsonObject["Iso3D"].isObject())
        UpdateIsoModelDetailsPage(MathmodRef->RootObjet.CurrentTreestruct);
    else if (MathmodRef->RootObjet.CurrentJsonObject["Param3D"].isObject())
        UpdatePar3DModelDetailsPage(MathmodRef->RootObjet.CurrentTreestruct);
    else if (MathmodRef->RootObjet.CurrentJsonObject["Param4D"].isObject())
        UpdatePar4DModelDetailsPage(MathmodRef->RootObjet.CurrentTreestruct);
    else
        ui.stackedProperties->setCurrentIndex(0);
}

// --------------------------
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

// --------------------------
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

// --------------------------
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
        qlstmin = result.split(";", QString::SkipEmptyParts);

        // Max
        lst = QObj["Max"].toArray();
        ObjArrayToString(lst, result);
        qlstmax = result.split(";", QString::SkipEmptyParts);

        // Position
        lst = QObj["Position"].toArray();
        ObjArrayToString(lst, result);
        qlstPos = result.split(";", QString::SkipEmptyParts);

        for (int i = 0; i < qlstPos.size(); ++i)
        {
            MathmodRef->ui.glWidget->IsoObjet->masterthread->SliderValues.push_back(
                qlstPos.at(i).toDouble());
            MathmodRef->ui.glWidget->ParObjet->masterthread->SliderValues.push_back(
                qlstPos.at(i).toDouble());
        }

        // Name
        lst = QObj["Name"].toArray();
        ObjArrayToString(lst, result);
        qlstnames = result.split(";", QString::SkipEmptyParts);

        for (int i = 0; i < qlstnames.size(); ++i)
        {
            MathmodRef->ui.glWidget->IsoObjet->masterthread->SliderNames.push_back(
                qlstnames.at(i).toStdString());
            MathmodRef->ui.glWidget->ParObjet->masterthread->SliderNames.push_back(
                qlstnames.at(i).toStdString());
        }
        MathmodRef->ui.glWidget->IsoObjet->masterthread->Nb_Sliders =
            uint(qlstnames.size());
        MathmodRef->ui.glWidget->ParObjet->masterthread->Nb_Sliders =
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
        qlstStep = result.split(";", QString::SkipEmptyParts);
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
                qlist += result.split(";", QString::SkipEmptyParts);
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
        MathmodRef->ui.glWidget->IsoObjet->masterthread->Nb_Sliders = 0;
        MathmodRef->ui.glWidget->ParObjet->masterthread->Nb_Sliders = 0;

        HideSliders();
    }
}

// --------------------------
void DrawingOptions::DrawJsonModel(const QJsonObject &Jobj, int textureIndex,
                                   bool Inspect)
{
    if (!(MathmodRef->ui.glWidget)->ParObjet->isRunning() &&
            !(MathmodRef->ui.glWidget)->IsoObjet->isRunning())
    {
        if (Inspect & !VerifiedJsonModel(Jobj, Inspect))
            return;
        ShowJsonModel(Jobj, textureIndex);
        UpdateScriptEditorAndTreeObject();
    }
}

bool DrawingOptions::VerifiedIsoJsonModel(const QJsonObject &QObj)
{
    QJsonArray lst;
    int NbFxyz;

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

// --------------------------
bool DrawingOptions::VerifiedParJsonModel(const QJsonObject &QObj)
{
    QJsonArray lst;
    int NbFx;
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
    QString result = "";
    if ((lst = QObj["Grid"].toArray()).size() > 0 && (lst.size() != 2 * NbFx))
    {
        scriptErrorType = GRID_NBCOMPONENT_MISMATCH;
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

// --------------------------
bool DrawingOptions::VerifiedJsonModel(const QJsonObject &Jobj, bool Inspect)
{
    QJsonArray lst;
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
            MathmodRef->ui.glWidget->LocalScene.componentsinfos.pariso = false;
            MathmodRef->ui.glWidget->LocalScene.componentsinfos.ParisoNbComponents =
                1;
            MathmodRef->ui.glWidget->LocalScene.componentsinfos
            .ParisoCurrentComponentIndex = 0;
        }
        return (verif);
    }
    if (Jobj["Param3D"].isObject())
    {
        QObj = Jobj["Param3D"].toObject();
        MathmodRef->ui.glWidget->LocalScene.componentsinfos.ParisoNbComponents = 1;
        verif = VerifiedParJsonModel(QObj);
        if (verif)
        {
            MathmodRef->ui.glWidget->LocalScene.componentsinfos.pariso = false;
            MathmodRef->ui.glWidget->LocalScene.componentsinfos.ParisoNbComponents =
                1;
            MathmodRef->ui.glWidget->LocalScene.componentsinfos
            .ParisoCurrentComponentIndex = 0;
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
        MathmodRef->ui.glWidget->LocalScene.componentsinfos.pariso = true;
        MathmodRef->ui.glWidget->LocalScene.componentsinfos.ParisoNbComponents =
            listeIsoObj.size() + listeParObj.size();
        MathmodRef->ui.glWidget->LocalScene.componentsinfos
        .ParisoCurrentComponentIndex = 0;
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
    noise1.replace("\n", "");
    noise1.replace("\t", "");
    noise1.replace(" ", "");
    QString result;
    ObjArrayToString(lst, result);
    if (opt == ISO_TYPE)
    {
        MathmodRef->ui.glWidget->IsoObjet->masterthread->Rgbt =
            result.toStdString();
        MathmodRef->ui.glWidget->IsoObjet->masterthread->Noise =
            noise1.toStdString();
        MathmodRef->ui.glWidget->IsoObjet->masterthread->RgbtSize =
            uint(lst.size());
    }
    else if (opt == PAR_TYPE || opt == PAR_4D_TYPE)
    {
        MathmodRef->ui.glWidget->ParObjet->masterthread->Rgbt =
            result.toStdString();
        MathmodRef->ui.glWidget->ParObjet->masterthread->Noise =
            noise1.toStdString();
        MathmodRef->ui.glWidget->ParObjet->masterthread->RgbtSize =
            uint(lst.size());
    }
    MathmodRef->RootObjet.CurrentTreestruct.Noise = noise1;
    MathmodRef->RootObjet.CurrentTreestruct.RGBT =
        result.split(";", QString::SkipEmptyParts);
}

void DrawingOptions::LoadPigment(const QJsonObject &QObj,
                                 const ModelType &opt)
{
    QString noise = "";
    QJsonArray tmp;
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
        MathmodRef->ui.glWidget->IsoObjet->masterthread->Gradient =
            strtmp.toStdString();
        MathmodRef->ui.glWidget->IsoObjet->masterthread->VRgbt =
            result.toStdString();
        MathmodRef->ui.glWidget->IsoObjet->masterthread->Noise =
            noise.toStdString();
        MathmodRef->ui.glWidget->IsoObjet->masterthread->VRgbtSize =
            uint(VRgbtSize);
    }
    else if (opt == PAR_TYPE || opt == PAR_4D_TYPE)
    {
        MathmodRef->ui.glWidget->ParObjet->masterthread->Gradient =
            strtmp.toStdString();
        MathmodRef->ui.glWidget->ParObjet->masterthread->VRgbt =
            result.toStdString();
        MathmodRef->ui.glWidget->ParObjet->masterthread->Noise =
            noise.toStdString();
        MathmodRef->ui.glWidget->ParObjet->masterthread->VRgbtSize =
            uint(VRgbtSize);
    }

    MathmodRef->RootObjet.CurrentTreestruct.Noise = noise;
    MathmodRef->RootObjet.CurrentTreestruct.VRGBT =
        result.split(";", QString::SkipEmptyParts);
}

// --------------------------
void DrawingOptions::ShowJsonModel(const QJsonObject &Jobj, int textureIndex)
{
    QString result;
    QJsonArray lst;
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
        // Right now, we only support pariso object with 1 Iso3D and 1 Param3D
        // objects.
        if (listeParObj.size() > 0)
            QPar = listeParObj[0].toObject();
        if (listeIsoObj.size() > 0)
            QIso = listeIsoObj[0].toObject();

        loadtext = loadpigm = false;
        if (QPar["Texture"].isObject())
            QTextureObj = QPar["Texture"].toObject();
        if (QPar["Pigment"].isObject())
            QPigmentObj = QPar["Pigment"].toObject();
        // Colors
        loadtext = MathmodRef->ui.glWidget->ParObjet->masterthread->rgbtnotnull =
                       (QPar["Texture"].isObject() ||
                        ((textureIndex < 1000) && (textureIndex != -1)));
        // Pigment
        loadpigm = MathmodRef->ui.glWidget->ParObjet->masterthread->vrgbtnotnull =
                       (QPar["Pigment"].isObject() ||
                        ((textureIndex != -1) && (textureIndex > 999)));
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
        loadtext = MathmodRef->ui.glWidget->IsoObjet->masterthread->rgbtnotnull =
                       (QIso["Texture"].isObject() ||
                        ((textureIndex < 1000) && (textureIndex != -1)));
        // Pigment
        loadpigm = MathmodRef->ui.glWidget->IsoObjet->masterthread->vrgbtnotnull =
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
            MathmodRef->ui.glWidget->LocalScene.componentsinfos.pariso = true;
            MathmodRef->ParisoObjectProcess();
        }

        ui.parisogroupbox->show();
    }
    else
    {
        ui.parisogroupbox->hide();
        MathmodRef->ui.glWidget->LocalScene.componentsinfos.pariso = false;
        if (Jobj["Iso3D"].isObject())
        {
            QObj = Jobj["Iso3D"].toObject();

            // Colors
            loadtext = MathmodRef->ui.glWidget->IsoObjet->masterthread->rgbtnotnull =
                           (Jobj["Texture"].isObject() ||
                            ((textureIndex < 1000) && (textureIndex != -1)));

            // Pigment
            loadpigm = MathmodRef->ui.glWidget->IsoObjet->masterthread->vrgbtnotnull =
                           (Jobj["Pigment"].isObject() ||
                            ((textureIndex != -1) && (textureIndex > 999)));

            LoadMandatoryAndOptionnalFields(QObj, ISO_TYPE, loadtext, QTextureObj,
                                            loadpigm, QPigmentObj);

            QJsonObject Jobjtmp = Jobj;
            // Some keys cleaning..
            Jobjtmp.remove("Param3D");
            Jobjtmp.remove("Param4D");
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
                ? MathmodRef->ui.glWidget->CalculateTexturePoints(1)
                : MathmodRef->ui.glWidget->CalculatePigmentPoints(1);
                MathmodRef->ui.glWidget->update();
            }
        }
        else if (Jobj["Param3D"].isObject())
        {
            QObj = Jobj["Param3D"].toObject();
            // Colors
            loadtext = MathmodRef->ui.glWidget->ParObjet->masterthread->rgbtnotnull =
                           (Jobj["Texture"].isObject() ||
                            ((textureIndex < 1000) && (textureIndex != -1)));

            // Pigment
            loadpigm = MathmodRef->ui.glWidget->ParObjet->masterthread->vrgbtnotnull =
                           (Jobj["Pigment"].isObject() ||
                            ((textureIndex != -1) && (textureIndex > 999)));

            LoadMandatoryAndOptionnalFields(QObj, PAR_TYPE, loadtext, QTextureObj,
                                            loadpigm, QPigmentObj);

            QJsonObject Jobjtmp = Jobj;
            // Some keys cleaning..
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
                ? MathmodRef->ui.glWidget->CalculateTexturePoints(0)
                : MathmodRef->ui.glWidget->CalculatePigmentPoints(0);
                MathmodRef->ui.glWidget->update();
            }
        }

        else if (Jobj["Param4D"].isObject())
        {
            QObj = Jobj["Param4D"].toObject();

            // Colors
            loadtext = MathmodRef->ui.glWidget->ParObjet->masterthread->rgbtnotnull =
                           (Jobj["Texture"].isObject() ||
                            ((textureIndex < 1000) && (textureIndex != -1)));

            // Pigment
            loadpigm = MathmodRef->ui.glWidget->ParObjet->masterthread->vrgbtnotnull =
                           (Jobj["Pigment"].isObject() ||
                            ((textureIndex != -1) && (textureIndex > 1000)));

            LoadMandatoryAndOptionnalFields(QObj, PAR_4D_TYPE, loadtext, QTextureObj,
                                            loadpigm, QPigmentObj);

            QJsonObject Jobjtmp = Jobj;
            // Some keys cleaning..
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
                ? MathmodRef->ui.glWidget->CalculateTexturePoints(0)
                : MathmodRef->ui.glWidget->CalculatePigmentPoints(0);
                MathmodRef->ui.glWidget->update();
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
                                                                                                         MathmodRef->RootObjet.CurrentTreestruct
                                                                                                         .zmin = MathmodRef->RootObjet
                                                                                                                 .CurrentTreestruct.zmax =
                                                                                                                         MathmodRef->RootObjet.CurrentTreestruct
                                                                                                                         .tmin = MathmodRef->RootObjet
                                                                                                                                 .CurrentTreestruct.tmax =
                                                                                                                                         MathmodRef->RootObjet
                                                                                                                                         .CurrentTreestruct.name =
                                                                                                                                                 MathmodRef->RootObjet
                                                                                                                                                 .CurrentTreestruct.Component =
                                                                                                                                                         MathmodRef->RootObjet
                                                                                                                                                         .CurrentTreestruct.Grid =
                                                                                                                                                                 QStringList();
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
    QString result, arg = "";
    QJsonArray lst;
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
        if (mod == PAR_4D_TYPE)
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

    lst = QObj[arg].toArray();
    ObjArrayToString(lst, result);
    switch (idx)
    {
    case PAR_FX:
        MathmodRef->ui.glWidget->ParObjet->masterthread->expression_X =
            result.toStdString();
        MathmodRef->ui.glWidget->ParObjet->masterthread->componentsNumber =
            uint(lst.size());
        MathmodRef->RootObjet.CurrentTreestruct.fx =
            result.split(";", QString::SkipEmptyParts);
        break;
    case PAR_FY:
        MathmodRef->ui.glWidget->ParObjet->masterthread->expression_Y =
            result.toStdString();
        MathmodRef->ui.glWidget->ParObjet->masterthread->expression_YSize =
            lst.size();
        MathmodRef->RootObjet.CurrentTreestruct.fy =
            result.split(";", QString::SkipEmptyParts);
        break;
    case PAR_FZ:
        MathmodRef->ui.glWidget->ParObjet->masterthread->expression_Z =
            result.toStdString();
        MathmodRef->ui.glWidget->ParObjet->masterthread->expression_ZSize =
            lst.size();
        MathmodRef->RootObjet.CurrentTreestruct.fz =
            result.split(";", QString::SkipEmptyParts);
        break;
    case PAR_FW:
        if (mod == PAR_4D_TYPE)
        {
            MathmodRef->ui.glWidget->ParObjet->masterthread->expression_W =
                result.toStdString();
            MathmodRef->RootObjet.CurrentTreestruct.fw =
                result.split(";", QString::SkipEmptyParts);
        }
        break;
    case PAR_UMIN:
        MathmodRef->ui.glWidget->ParObjet->masterthread->inf_u =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.umin =
            result.split(";", QString::SkipEmptyParts);
        break;
    case PAR_UMAX:
        MathmodRef->ui.glWidget->ParObjet->masterthread->sup_u =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.umax =
            result.split(";", QString::SkipEmptyParts);
        break;
    case PAR_VMAX:
        MathmodRef->ui.glWidget->ParObjet->masterthread->sup_v =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.vmax =
            result.split(";", QString::SkipEmptyParts);
        break;
    case PAR_VMIN:
        MathmodRef->ui.glWidget->ParObjet->masterthread->inf_v =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.vmin =
            result.split(";", QString::SkipEmptyParts);
        break;
    case PAR_COMP:
        MathmodRef->RootObjet.CurrentTreestruct.Component =
            result.split(";", QString::SkipEmptyParts);
        break;
    case PAR_NAME:
        MathmodRef->RootObjet.CurrentTreestruct.name =
            result.split(";", QString::SkipEmptyParts);
        break;
    }
}

void DrawingOptions::MandatoryIsoFieldprocess(const QJsonObject &QObj,
        const MandatoryIsoField &idx)
{
    QString result, arg = "";
    QJsonArray lst;
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

    lst = QObj[arg].toArray();
    ObjArrayToString(lst, result);
    switch (idx)
    {
    case ISO_FXYZ:
        MathmodRef->ui.glWidget->IsoObjet->masterthread->ImplicitFunction =
            result.toStdString();
        MathmodRef->ui.glWidget->IsoObjet->masterthread->componentsNumber =
            uint(lst.size());
        MathmodRef->RootObjet.CurrentTreestruct.fxyz =
            result.split(";", QString::SkipEmptyParts);
        break;
    case ISO_XMAX:
        MathmodRef->ui.glWidget->IsoObjet->masterthread->XlimitSup =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.xmax =
            result.split(";", QString::SkipEmptyParts);
        break;
    case ISO_YMAX:
        MathmodRef->ui.glWidget->IsoObjet->masterthread->YlimitSup =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.ymax =
            result.split(";", QString::SkipEmptyParts);
        break;
    case ISO_ZMAX:
        MathmodRef->ui.glWidget->IsoObjet->masterthread->ZlimitSup =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.zmax =
            result.split(";", QString::SkipEmptyParts);
        break;
    case ISO_XMIN:
        MathmodRef->ui.glWidget->IsoObjet->masterthread->XlimitInf =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.xmin =
            result.split(";", QString::SkipEmptyParts);
        break;
    case ISO_YMIN:
        MathmodRef->ui.glWidget->IsoObjet->masterthread->YlimitInf =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.ymin =
            result.split(";", QString::SkipEmptyParts);
        break;
    case ISO_ZMIN:
        MathmodRef->ui.glWidget->IsoObjet->masterthread->ZlimitInf =
            result.toStdString();
        MathmodRef->RootObjet.CurrentTreestruct.zmin =
            result.split(";", QString::SkipEmptyParts);
        break;
    case ISO_COMP:
        MathmodRef->RootObjet.CurrentTreestruct.Component =
            result.split(";", QString::SkipEmptyParts);
        break;
    case ISO_NAME:
        MathmodRef->RootObjet.CurrentTreestruct.name =
            result.split(";", QString::SkipEmptyParts);
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
    case ISO_GRID:
        arg = "Grid";
        argnotnull = MathmodRef->ui.glWidget->IsoObjet->masterthread->gridnotnull =
                         QObj[arg].isArray();
        break;
    case ISO_CND:
        arg = "Cnd";
        argnotnull = MathmodRef->ui.glWidget->IsoObjet->masterthread->cndnotnull =
                         QObj[arg].isArray();
        break;
    case ISO_CONST:
        arg = "Const";
        argnotnull = MathmodRef->ui.glWidget->IsoObjet->masterthread->constnotnull =
                         QObj[arg].isArray();
        break;
    case ISO_FUNCT:
        arg = "Funct";
        argnotnull = MathmodRef->ui.glWidget->IsoObjet->masterthread->functnotnull =
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
    case ISO_GRID:
        if (argnotnull)
        {
            MathmodRef->ui.glWidget->IsoObjet->masterthread->grid.clear();
            for (int j = 0; j < lst.size(); j++)
                MathmodRef->ui.glWidget->IsoObjet->masterthread->grid.push_back(
                    (lst[j].toString()).toUInt());
            MathmodRef->ui.glWidget->IsoObjet->masterthread->Grid =
                result.toStdString();
            MathmodRef->RootObjet.CurrentTreestruct.Grid =
                result.split(";", QString::SkipEmptyParts);
        }
        else
        {
            MathmodRef->ui.glWidget->IsoObjet->masterthread->Grid = "";
        }
        break;
    case ISO_CND:
        if (argnotnull)
        {
            MathmodRef->ui.glWidget->IsoObjet->masterthread->Condition = result.toStdString();
            for(int i=0; i<lst.size(); i++)
                MathmodRef->ui.glWidget->LocalScene.componentsinfos.ParisoCondition.push_back((lst[i].toString()).replace(" ", "")=="");
            MathmodRef->RootObjet.CurrentTreestruct.Cnd = result.split(";", QString::SkipEmptyParts);
        }
        else
        {
            for(int i=0; i<lst.size(); i++)
                MathmodRef->ui.glWidget->LocalScene.componentsinfos.ParisoCondition.push_back(false);
            MathmodRef->ui.glWidget->IsoObjet->masterthread->Condition = "";
        }
        break;
    case ISO_FUNCT:
        if (argnotnull)
        {
            MathmodRef->ui.glWidget->IsoObjet->masterthread->Funct = result.toStdString();
            MathmodRef->ui.glWidget->IsoObjet->masterthread->FunctSize = uint(lst.size());
            MathmodRef->RootObjet.CurrentTreestruct.Funct = result.split(";", QString::SkipEmptyParts);
        }
        else
        {
            MathmodRef->ui.glWidget->IsoObjet->masterthread->Funct = "";
            MathmodRef->ui.glWidget->IsoObjet->masterthread->FunctSize = 0;
        }
        break;
    case ISO_CONST:
        if (argnotnull)
        {
            MathmodRef->ui.glWidget->IsoObjet->masterthread->Const =
                result.toStdString();
            MathmodRef->ui.glWidget->IsoObjet->masterthread->ConstSize =
                uint(lst.size());
            MathmodRef->RootObjet.CurrentTreestruct.Const =
                result.split(";", QString::SkipEmptyParts);
        }
        else
        {
            MathmodRef->ui.glWidget->IsoObjet->masterthread->Const = "";
            MathmodRef->ui.glWidget->IsoObjet->masterthread->ConstSize = 0;
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
    case PAR_GRID:
        arg = "Grid";
        argnotnull = MathmodRef->ui.glWidget->ParObjet->masterthread->gridnotnull =
                         QObj[arg].isArray();
        break;
    case PAR_CONST:
        arg = "Const";
        argnotnull = MathmodRef->ui.glWidget->ParObjet->masterthread->constnotnull =
                         QObj[arg].isArray();
        break;
    case PAR_FUNCT:
        arg = "Funct";
        argnotnull = MathmodRef->ui.glWidget->ParObjet->masterthread->functnotnull =
                         QObj[arg].isArray();
        break;
    case PAR_CND:
        arg = "Cnd";
        argnotnull = MathmodRef->ui.glWidget->ParObjet->masterthread->cndnotnull =
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
    case PAR_GRID:
        if (argnotnull)
        {
            MathmodRef->ui.glWidget->ParObjet->masterthread->grid.clear();
            for (int j = 0; j < lst.size(); j++)
                MathmodRef->ui.glWidget->ParObjet->masterthread->grid.push_back(
                    (lst[j].toString()).toUInt());
            MathmodRef->ui.glWidget->ParObjet->masterthread->Grid =
                result.toStdString();
            MathmodRef->RootObjet.CurrentTreestruct.Grid =
                result.split(";", QString::SkipEmptyParts);
        }
        else
        {
            MathmodRef->ui.glWidget->ParObjet->masterthread->Grid = "";
        }
        break;
    case PAR_CND:
        if (argnotnull)
        {
            MathmodRef->ui.glWidget->ParObjet->masterthread->expression_CND = result.toStdString();
            for(int i=0; i<lst.size(); i++)
                MathmodRef->ui.glWidget->LocalScene.componentsinfos.ParisoCondition.push_back((lst[i].toString()).replace(" ", "") == "");
            MathmodRef->RootObjet.CurrentTreestruct.Cnd = result.split(";", QString::SkipEmptyParts);
        }
        else
        {
            for(int i=0; i<lst.size(); i++)
                MathmodRef->ui.glWidget->LocalScene.componentsinfos.ParisoCondition.push_back(false);
            MathmodRef->ui.glWidget->ParObjet->masterthread->expression_CND = "";
        }
        break;
    case PAR_CONST:
        if (argnotnull)
        {
            MathmodRef->ui.glWidget->ParObjet->masterthread->Const = result.toStdString();
            MathmodRef->ui.glWidget->ParObjet->masterthread->ConstSize = uint(lst.size());
            MathmodRef->RootObjet.CurrentTreestruct.Const = result.split(";", QString::SkipEmptyParts);
        }
        else
        {
            MathmodRef->ui.glWidget->ParObjet->masterthread->Const = "";
            MathmodRef->ui.glWidget->ParObjet->masterthread->ConstSize = 0;
        }
        break;
    case PAR_FUNCT:
        if (argnotnull)
        {
            MathmodRef->ui.glWidget->ParObjet->masterthread->Funct =
                result.toStdString();
            MathmodRef->ui.glWidget->ParObjet->masterthread->FunctSize =
                uint(lst.size());
            MathmodRef->RootObjet.CurrentTreestruct.Funct =
                result.split(";", QString::SkipEmptyParts);
        }
        else
        {
            MathmodRef->ui.glWidget->ParObjet->masterthread->Funct = "";
            MathmodRef->ui.glWidget->ParObjet->masterthread->FunctSize = 0;
        }
        break;
    }
}

void DrawingOptions::BuildAllVect()
{
    const OptionnalIsoScriptFIELD optiso[] = {ISO_GRID, ISO_CND, ISO_CONST,
                                              ISO_FUNCT
                                             };
    OptIsoFields = std::vector<OptionnalIsoScriptFIELD>(
                       optiso, optiso + sizeof(optiso) / sizeof(OptionnalIsoScriptFIELD));

    const OptionnalParScriptFIELD optpar[] = {PAR_GRID, PAR_CND, PAR_CONST,
                                              PAR_FUNCT
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

// --------------------------
int DrawingOptions::JSON_choice_activated(const QString &arg1)
{
    QString result;
    QJsonArray array = JSONMathModels["MathModels"].toArray();
    QJsonArray lst;
    QJsonObject QObj, QObj1;
    QJsonObject QTextureObj, QPigmentObj;
    bool loadtext, loadpigm;

    QMessageBox msgBox;
    updateCurrentTreestruct();

    for (int i = 0; i < array.size(); i++)
    {
        if ((QObj1 = array[i].toObject())["ParIso"].isArray())
        {
            MathmodRef->ui.glWidget->LocalScene.componentsinfos.pariso = true;
            ui.parisogroupbox->show();
        }
        else
        {
            MathmodRef->ui.glWidget->LocalScene.componentsinfos.pariso = false;
            MathmodRef->ui.glWidget->LocalScene.componentsinfos.ParisoNbComponents =
                1;
            MathmodRef->ui.glWidget->LocalScene.componentsinfos
            .ParisoCurrentComponentIndex = 0;
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
                if ((loadtext =
                            MathmodRef->ui.glWidget->IsoObjet->masterthread->rgbtnotnull =
                                QObj1["Texture"].isObject()))
                    QTextureObj = QObj1["Texture"].toObject();

                // Pigment
                if ((loadpigm =
                            MathmodRef->ui.glWidget->IsoObjet->masterthread->vrgbtnotnull =
                                QObj1["Pigment"].isObject()))
                    QPigmentObj = QObj1["Pigment"].toObject();

                LoadMandatoryAndOptionnalFields(QObj, ISO_TYPE, loadtext, QTextureObj,
                                                loadpigm, QPigmentObj);

                QJsonDocument document;
                document.setObject(array[i].toObject());
                MathmodRef->RootObjet.CurrentTreestruct.text =
                    QString(document.toJson());

                // Update the current parametric struct
                // MathmodRef->RootObjet.CurrentIsoStruct =
                // MathmodRef->RootObjet.IsoTable[indextable];
                MathmodRef->RootObjet.CurrentJsonObject = array[i].toObject();
                CurrentFormulaType = 2;
                /// process the new surface
                MathmodRef->ProcessNewIsoSurface();
                return (2);
            }
            else if ((array[i].toObject())["Param3D"].isObject() &&
                     (QObj = (array[i].toObject())["Param3D"].toObject())["Name"]
                     .toArray()[0]
                     .toString() == arg1)
            {
                if (!VerifiedJsonModel((array[i].toObject())))
                    return (0);
                ShowSliders(array[i].toObject());

                // Colors
                if ((loadtext =
                            MathmodRef->ui.glWidget->ParObjet->masterthread->rgbtnotnull =
                                QObj1["Texture"].isObject()))
                    QTextureObj = QObj1["Texture"].toObject();

                // Pigment
                if ((loadpigm =
                            MathmodRef->ui.glWidget->ParObjet->masterthread->vrgbtnotnull =
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
            else if ((array[i].toObject())["Param4D"].isObject() &&
                     (QObj = (array[i].toObject())["Param4D"].toObject())["Name"]
                     .toArray()[0]
                     .toString() == arg1)
            {
                if (!VerifiedJsonModel((array[i].toObject())))
                    return (0);
                ShowSliders(array[i].toObject());

                // Colors
                if ((loadtext =
                            MathmodRef->ui.glWidget->ParObjet->masterthread->rgbtnotnull =
                                QObj1["Texture"].isObject()))
                    QTextureObj = QObj1["Texture"].toObject();

                // Pigment
                if ((loadpigm =
                            MathmodRef->ui.glWidget->ParObjet->masterthread->vrgbtnotnull =
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
    MathmodRef->ui.glWidget->LocalScene.componentsinfos.pariso = false;
    MathmodRef->ui.glWidget->LocalScene.componentsinfos.ParisoCondition.clear();
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

// --------------------------
int DrawingOptions::on_choice_activated(const QString &arg)
{
    // Draw here
    int Result = JSON_choice_activated(arg);
    if (Result != 0)
    {
        UpdateScriptEditorAndTreeObject();
    }

    return Result;
}

// --------------------------
void DrawingOptions::Run_JsonObject_activeted()
{
    QJsonParseError err;
    QString sortie;
    QString script =
        ui.ParamEdit->toPlainText()
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

// --------------------------
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
    if (arg1 == "Infos")
    {
        MathmodRef->iso_infos();
        return;
    }
    if (arg1 == "Fill")
    {
        MathmodRef->fill();
        return;
    }
    if (arg1 == "Smooth")
    {
        MathmodRef->smoothline();
        return;
    }
    if (arg1 == "Mesh")
    {
        MathmodRef->Mesh();
        return;
    }
}

// --------------------------
void DrawingOptions::slot_checkBox_clicked()
{
    MathmodRef->slot_uv_clicked();
}

// --------------------------
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
    }

    lst.insert(0, "Examples (" + QString::number(lst.count()) + ")");
    // Load the script containing isosurface and parametric formulas:
    ui.choice->clear();
    ui.choice->insertItems(0, lst);
    AddListModels(upd);
}

// --------------------------
void DrawingOptions::LoadK3DSurfScript(QString filename, int type)
{
    int current = 0, currentfunction = 0, separator = 0;
    QString name, line, IsoFct, Xfct, Yfct, Zfct, xlimit, ylimit, zlimit, ulimit,
            vlimit, xmin, xmax, ymin, ymax, zmin, zmax, umin, umax, vmin, vmax,
            condition, Au, Bu, Cu, Duv, Euv, Fuv, comments, fctcomts;
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
                    umin = umax = vmin = vmax = xmin = xmax = ymin = ymax = zmin = zmax =
                                                           "";
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
                statusBar()->showMessage(tr("Could not write to %1").arg(filename),
                                         2000);
                return;
            }
            QTextStream t(&f);
            t << JsonString;
            f.close();
        }
    }
}

// --------------------------
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

// --------------------------
void DrawingOptions::ParseItemTree(QTreeWidgetItem *item, QList<bool> &list,
                                   bool viewall)
{
    int childcount = item->childCount();
    bool sel = false;
    bool result;
    for (int j = 0; j < childcount; j++)
    {
        item->child(j)->setTextColor(0, QColor(255, 255, 255, 255));
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
                item->child(j)->setTextColor(0, QColor(255, 0, 0, 255));
        }
    }
}

// --------------------------
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
                        ParseItemTree(Childlevel->child(m), select.selectedoptions.complist,
                                      true);
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

// --------------------------
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
    ParlistItem->setBackgroundColor(0, greenColor);
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
    IsolistItem->setBackgroundColor(0, greenColor);
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

    // My Selection:
    // Isosurfaces:
    QTreeWidgetItem *MyselectionItem = new QTreeWidgetItem(ui.ObjectClasse);
    MyselectionItemReference = MyselectionItem;
    MyselectionItem->setBackgroundColor(0, greenColor);
    MyselectionItem->setText(0, "My Selection");
    return;
}

// --------------------------
void DrawingOptions::on_pushButton_clicked()
{
    static int checked = 1;
    checked *= -1;
    if (checked == -1)
    {
        ui.ObjectClasse->hide();
    }
    else
    {
        ui.ObjectClasse->show();
    }
}

// --------------------------
void DrawingOptions::on_action_Exit_triggered()
{
    MathmodRef->close();
    this->close();
}

// --------------------------
void DrawingOptions::on_actionTriangles_triggered()
{
    MathmodRef->slot_triangles_clicked();
}

// --------------------------
void DrawingOptions::on_actionNormales_triggered()
{
    MathmodRef->draw_norm_clicked();
}

// --------------------------
void DrawingOptions::on_actionInfos_triggered()
{
    MathmodRef->iso_infos();
}

// --------------------------
void DrawingOptions::on_actionFill_triggered()
{
    MathmodRef->fill();
}

// --------------------------
void DrawingOptions::on_actionSmooth_triggered()
{
    MathmodRef->smoothline();
}

// --------------------------
void DrawingOptions::on_ObjectClasse_clicked(const QModelIndex &index)
{
    if (!MathmodRef->ui.glWidget->IsoObjet->isRunning() &&
            !MathmodRef->ui.glWidget->ParObjet->isRunning())
    {
        on_InitTButton_clicked();
        // int result;
        QString tst;
        MathmodRef->ui.glWidget->LocalScene.IndexCurrentFormula = -1;
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
                        if ((MathmodRef->RootObjet.MyJsonObjectSelection[i]
                                .toObject()["Iso3D"]
                                .isObject()))
                        {
                            if (s == (tst = (MathmodRef->RootObjet.MyJsonObjectSelection[i]
                                             .toObject()["Iso3D"])
                                            .toObject()["Name"]
                                            .toArray()[0]
                                            .toString()))
                            {
                                // Draw here

                                DrawJsonModel(MathmodRef->RootObjet.MyJsonObjectSelection.at(i)
                                              .toObject());
                                return;
                            }
                        }
                        else if ((MathmodRef->RootObjet.MyJsonObjectSelection[i]
                                  .toObject()["Param3D"]
                                  .isObject()))
                        {
                            if (s == (tst = (MathmodRef->RootObjet.MyJsonObjectSelection[i]
                                             .toObject()["Param3D"])
                                            .toObject()["Name"]
                                            .toArray()[0]
                                            .toString()))
                            {
                                // Draw here
                                DrawJsonModel(MathmodRef->RootObjet.MyJsonObjectSelection.at(i)
                                              .toObject());
                                return;
                            }
                        }
                        else if ((MathmodRef->RootObjet.MyJsonObjectSelection[i]
                                  .toObject()["Param4D"]
                                  .isObject()))
                        {
                            if (s == (tst = (MathmodRef->RootObjet.MyJsonObjectSelection[i]
                                             .toObject()["Param4D"])
                                            .toObject()["Name"]
                                            .toArray()[0]
                                            .toString()))
                            {
                                // Draw here
                                DrawJsonModel(MathmodRef->RootObjet.MyJsonObjectSelection.at(i)
                                              .toObject());
                                return;
                            }
                        }
                }
            }
        }
        return;
    }
}

// --------------------------
void DrawingOptions::slot_pushButton_2_clicked()
{
    MathmodRef->RootObjet.MyJsonObjectSelection.append(
        MathmodRef->RootObjet.CurrentJsonObject);
    AddObjectToMySelectionTree();
}

// --------------------------
void DrawingOptions::slot_unselect_clicked()
{
    int index =
        MyselectionItemReference->indexOfChild(ui.ObjectClasse->currentItem());
    MathmodRef->RootObjet.MyJsonObjectSelection.removeAt(index);
    MyselectionItemReference->removeChild(ui.ObjectClasse->currentItem());
}

// --------------------------
void DrawingOptions::slot_XYZscrollBar_valueChanged(int value)
{
    MathmodRef->xyzg_valueChanged(value);
}

// --------------------------
void DrawingOptions::UpdateDescription(int position, ModelType type,
                                       TreeStruct &currentstruct)
{
    if (type == PAR_TYPE)
    {
        if (position > -1)
        {
            indexcurrentFormula = position;
            MathmodRef->ui.glWidget->LocalScene.IndexCurrentFormula == position
            ? MathmodRef->ui.glWidget->LocalScene.IndexCurrentFormula = -1
                    : MathmodRef->ui.glWidget->LocalScene.IndexCurrentFormula = position;
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
                ui.CndUpdateEdit_2->setText(currentstruct.Cnd.at(0));
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
                    ui.tableWidget_Fct_2->setItem(
                        i, 0, new QTableWidgetItem(currentstruct.Funct.at(i)));
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
                    ui.tableWidget_Cst_2->setItem(
                        i, 0, new QTableWidgetItem(currentstruct.Const.at(i)));
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
            indexcurrentFormula = position;
            MathmodRef->ui.glWidget->LocalScene.IndexCurrentFormula == position
            ? MathmodRef->ui.glWidget->LocalScene.IndexCurrentFormula = -1
                    : MathmodRef->ui.glWidget->LocalScene.IndexCurrentFormula = position;
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
            indexcurrentFormula = position;
            MathmodRef->ui.glWidget->LocalScene.IndexCurrentFormula == position
            ? MathmodRef->ui.glWidget->LocalScene.IndexCurrentFormula = -1
                    : MathmodRef->ui.glWidget->LocalScene.IndexCurrentFormula = position;

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
                    ui.tableWidget_Fct->setItem(
                        i, 0, new QTableWidgetItem(currentstruct.Funct.at(i)));
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
                    ui.tableWidget_Cst->setItem(
                        i, 0, new QTableWidgetItem(currentstruct.Const.at(i)));
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

// --------------------------
void DrawingOptions::oncolor_2activated(int index)
{
    MathmodRef->ui.glWidget->colorstype(index);
}

// --------------------------
void DrawingOptions::onred_2valueChanged(int value)
{
    MathmodRef->ui.glWidget->red(value, indexcurrentFormula);
}

// --------------------------
void DrawingOptions::ongreen_2valueChanged(int value)
{
    MathmodRef->ui.glWidget->green(value, indexcurrentFormula);
}

// --------------------------
void DrawingOptions::onblue_2valueChanged(int value)
{
    MathmodRef->ui.glWidget->blue(value, indexcurrentFormula);
}

// --------------------------
void DrawingOptions::ontransparent_2valueChanged(int value)
{
    MathmodRef->ui.glWidget->transparency(value, indexcurrentFormula);
}

// --------------------------
void DrawingOptions::ontransparence_2clicked(bool checked)
{
    MathmodRef->ui.glWidget->transparence(checked);
}

// --------------------------
void DrawingOptions::on_red_ParIso_valueChanged(int value)
{
    MathmodRef->ui.glWidget->red(value, indexcurrentFormula);
}

// --------------------------
void DrawingOptions::on_green_ParIso_valueChanged(int value)
{
    MathmodRef->ui.glWidget->green(value, indexcurrentFormula);
}

// --------------------------
void DrawingOptions::on_blue_ParIso_valueChanged(int value)
{
    MathmodRef->ui.glWidget->blue(value, indexcurrentFormula);
}

// --------------------------
void DrawingOptions::on_updateJObject(QJsonObject &copyCurrentObject)
{
    QJsonArray array;

    if (copyCurrentObject["Iso3D"].isObject())
    {
        if (indexcurrentFormula != -1)
        {
            QJsonObject copyCurrentObject2 = copyCurrentObject["Iso3D"].toObject();
            // Cut the component at the index indexcurrentFormula :
            if ((ui.isoNameEdit->toPlainText()).replace(" ", "") == "")
            {
                array = copyCurrentObject2["Fxyz"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Fxyz"] = array;

                array = copyCurrentObject2["Xmin"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Xmin"] = array;

                array = copyCurrentObject2["Xmax"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Xmax"] = array;

                array = copyCurrentObject2["Ymin"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Ymin"] = array;

                array = copyCurrentObject2["Ymax"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Ymax"] = array;

                array = copyCurrentObject2["Zmin"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Zmin"] = array;

                array = copyCurrentObject2["Zmax"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Zmax"] = array;

                if (copyCurrentObject2["Component"].isArray())
                {
                    array = copyCurrentObject2["Component"].toArray();
                    array.removeAt(indexcurrentFormula);
                    copyCurrentObject2["Component"] = array;
                }

                if (copyCurrentObject2["Grid"].isArray())
                {
                    array = copyCurrentObject2["Grid"].toArray();
                    array.removeAt(indexcurrentFormula);
                    copyCurrentObject2["Grid"] = array;
                }
                else
                    copyCurrentObject2.remove("Grid");

                if (copyCurrentObject2["Cnd"].isArray() &&
                        copyCurrentObject2["Cnd"].toArray().count() > indexcurrentFormula)
                {
                    array = copyCurrentObject2["Cnd"].toArray();
                    array.removeAt(indexcurrentFormula);
                    copyCurrentObject2["Cnd"] = array;
                }
                else
                    copyCurrentObject2.remove("Cnd");

                /************************************************************************************************/
                // Functions:
                if (copyCurrentObject2["Funct"].isArray() &&
                        ui.tableWidget_Fct->rowCount() > 0)
                {
                    QJsonArray array2;

                    for (int i = 0; i < ui.tableWidget_Fct->rowCount(); i++)
                    {
                        if ((ui.tableWidget_Fct->item(i, 0))->text() != "")
                            array2.append((ui.tableWidget_Fct->item(i, 0))->text());
                    }

                    copyCurrentObject2["Funct"] = array2;
                }
                else
                    copyCurrentObject2.remove("Funct");

                // Constantes:
                if (copyCurrentObject2["Const"].isArray() &&
                        ui.tableWidget_Cst->rowCount() > 0)
                {
                    QJsonArray array2;
                    for (int i = 0; i < ui.tableWidget_Cst->rowCount(); i++)
                    {
                        if ((ui.tableWidget_Cst->item(i, 0))->text() != "")
                            array2.append((ui.tableWidget_Cst->item(i, 0))->text());
                    }

                    copyCurrentObject2["Const"] = array2;
                }
                else
                    copyCurrentObject2.remove("Const");
                /************************************************************************************************/

                // Some keys cleaning..
                copyCurrentObject2.remove("Param3D");
                copyCurrentObject2.remove("Param4D");
                copyCurrentObject["Iso3D"] = copyCurrentObject2;
            }
            // Update the component at the index indexcurrentFormula;
            else if ((copyCurrentObject["Iso3D"].toObject())["Component"]
                     .toArray()
                     .size() > 0 &&
                     indexcurrentFormula > -1 &&
                     indexcurrentFormula <
                     (copyCurrentObject["Iso3D"].toObject())["Component"]
                     .toArray()
                     .size() &&
                     (((copyCurrentObject["Iso3D"].toObject())["Component"]
                       .toArray())[indexcurrentFormula])
                     .toString()
                     .replace(" ", "") ==
                     (ui.isoNameEdit->toPlainText()).replace(" ", ""))
            {

                array = copyCurrentObject2["Fxyz"].toArray();
                array.replace(indexcurrentFormula, ui.UpdateEdit->toPlainText());
                copyCurrentObject2["Fxyz"] = array;

                array = copyCurrentObject2["Xmin"].toArray();
                array.replace(indexcurrentFormula, ui.xmin->toPlainText());
                copyCurrentObject2["Xmin"] = array;

                array = copyCurrentObject2["Xmax"].toArray();
                array.replace(indexcurrentFormula, ui.xmax->toPlainText());
                copyCurrentObject2["Xmax"] = array;

                array = copyCurrentObject2["Ymin"].toArray();
                array.replace(indexcurrentFormula, ui.ymin->toPlainText());
                copyCurrentObject2["Ymin"] = array;

                array = copyCurrentObject2["Ymax"].toArray();
                array.replace(indexcurrentFormula, ui.ymax->toPlainText());
                copyCurrentObject2["Ymax"] = array;

                array = copyCurrentObject2["Zmin"].toArray();
                array.replace(indexcurrentFormula, ui.zmin->toPlainText());
                copyCurrentObject2["Zmin"] = array;

                array = copyCurrentObject2["Zmax"].toArray();
                array.replace(indexcurrentFormula, ui.zmax->toPlainText());
                copyCurrentObject2["Zmax"] = array;

                if (copyCurrentObject2["Cnd"].isArray() &&
                        copyCurrentObject2["Cnd"].toArray().count() > indexcurrentFormula)
                {
                    array = copyCurrentObject2["Cnd"].toArray();
                    array.replace(indexcurrentFormula, ui.CndUpdateEdit->toPlainText());
                    copyCurrentObject2["Cnd"] = array;
                }
                else if (ui.CndUpdateEdit->toPlainText() != "")
                {
                    array = copyCurrentObject2["Cnd"].toArray();
                    for (int i = 0; i < copyCurrentObject2["Fxyz"].toArray().count(); i++)
                        array.append(ui.CndUpdateEdit->toPlainText());
                    copyCurrentObject2["Cnd"] = array;
                }
                else
                    copyCurrentObject2.remove("Cnd");

                if (copyCurrentObject2["Grid"].isArray())
                {
                    array = copyCurrentObject2["Grid"].toArray();
                    copyCurrentObject2["Grid"] = array;
                }
                else
                    copyCurrentObject2.remove("Grid");

                // Functions:
                if (copyCurrentObject2["Funct"].isArray() &&
                        ui.tableWidget_Fct->rowCount() > 0)
                {
                    QJsonArray array2;

                    for (int i = 0; i < ui.tableWidget_Fct->rowCount(); i++)
                    {
                        if ((ui.tableWidget_Fct->item(i, 0))->text() != "")
                            array2.append((ui.tableWidget_Fct->item(i, 0))->text());
                    }

                    copyCurrentObject2["Funct"] = array2;
                }
                else
                    copyCurrentObject2.remove("Funct");

                // Constantes:
                if (copyCurrentObject2["Const"].isArray() &&
                        ui.tableWidget_Cst->rowCount() > 0)
                {
                    QJsonArray array2;
                    for (int i = 0; i < ui.tableWidget_Cst->rowCount(); i++)
                    {
                        if ((ui.tableWidget_Cst->item(i, 0))->text() != "")
                            array2.append((ui.tableWidget_Cst->item(i, 0))->text());
                    }

                    copyCurrentObject2["Const"] = array2;
                }
                else
                    copyCurrentObject2.remove("Const");
                copyCurrentObject2.remove("Param3D");
                copyCurrentObject2.remove("Param4D");
                copyCurrentObject["Iso3D"] = copyCurrentObject2;
            }
            else
            {
                // Add new component:
                if ((((copyCurrentObject["Iso3D"].toObject())["Component"]
                        .toArray())[indexcurrentFormula])
                        .toString()
                        .replace(" ", "") !=
                        (ui.isoNameEdit->toPlainText()).replace(" ", ""))
                {
                    array = copyCurrentObject2["Component"].toArray();
                    array.append(ui.isoNameEdit->toPlainText());
                    copyCurrentObject2["Component"] = array;

                    array = copyCurrentObject2["Fxyz"].toArray();
                    array.append(ui.UpdateEdit->toPlainText());
                    copyCurrentObject2["Fxyz"] = array;

                    array = copyCurrentObject2["Xmin"].toArray();
                    array.append(ui.xmin->toPlainText());
                    copyCurrentObject2["Xmin"] = array;

                    array = copyCurrentObject2["Xmax"].toArray();
                    array.append(ui.xmax->toPlainText());
                    copyCurrentObject2["Xmax"] = array;

                    array = copyCurrentObject2["Ymin"].toArray();
                    array.append(ui.ymin->toPlainText());
                    copyCurrentObject2["Ymin"] = array;

                    array = copyCurrentObject2["Ymax"].toArray();
                    array.append(ui.ymax->toPlainText());
                    copyCurrentObject2["Ymax"] = array;

                    array = copyCurrentObject2["Zmin"].toArray();
                    array.append(ui.zmin->toPlainText());
                    copyCurrentObject2["Zmin"] = array;

                    array = copyCurrentObject2["Zmax"].toArray();
                    array.append(ui.zmax->toPlainText());
                    copyCurrentObject2["Zmax"] = array;

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
                    array = copyCurrentObject2["Fxyz"].toArray();
                    array.insert(indexcurrentFormula, ui.UpdateEdit->toPlainText());
                    copyCurrentObject2["Fxyz"] = array;

                    array = copyCurrentObject2["Xmin"].toArray();
                    array.insert(indexcurrentFormula, ui.xmin->toPlainText());
                    copyCurrentObject2["Xmin"] = array;

                    array = copyCurrentObject2["Xmax"].toArray();
                    array.insert(indexcurrentFormula, ui.xmax->toPlainText());
                    copyCurrentObject2["Xmax"] = array;

                    array = copyCurrentObject2["Ymin"].toArray();
                    array.insert(indexcurrentFormula, ui.ymin->toPlainText());
                    copyCurrentObject2["Ymin"] = array;

                    array = copyCurrentObject2["Ymax"].toArray();
                    array.insert(indexcurrentFormula, ui.ymax->toPlainText());
                    copyCurrentObject2["Ymax"] = array;

                    array = copyCurrentObject2["Zmin"].toArray();
                    array.insert(indexcurrentFormula, ui.zmin->toPlainText());
                    copyCurrentObject2["Zmin"] = array;

                    array = copyCurrentObject2["Zmax"].toArray();
                    array.insert(indexcurrentFormula, ui.zmax->toPlainText());
                    copyCurrentObject2["Zmax"] = array;

                    if (copyCurrentObject2["Component"].isArray())
                    {
                        array = copyCurrentObject2["Component"].toArray();
                        array.insert(indexcurrentFormula, ui.isoNameEdit->toPlainText());
                        copyCurrentObject2["Component"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Component");

                    if (copyCurrentObject2["Cnd"].isArray())
                    {
                        array = copyCurrentObject2["Cnd"].toArray();
                        array.insert(indexcurrentFormula, ui.CndUpdateEdit->toPlainText());
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
                        // array.insert(indexcurrentFormula,
                        // QString::number(ui.xyzg->value()));
                        copyCurrentObject2["Grid"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Grid");
                }

                /************************************************************************************************/
                // Functions:
                if (copyCurrentObject2["Funct"].isArray() &&
                        ui.tableWidget_Fct->rowCount() > 0)
                {
                    QJsonArray array2;

                    for (int i = 0; i < ui.tableWidget_Fct->rowCount(); i++)
                    {
                        if ((ui.tableWidget_Fct->item(i, 0))->text() != "")
                            array2.append((ui.tableWidget_Fct->item(i, 0))->text());
                    }

                    copyCurrentObject2["Funct"] = array2;
                }
                else
                    copyCurrentObject2.remove("Funct");

                // Constantes:
                if (copyCurrentObject2["Const"].isArray() &&
                        ui.tableWidget_Cst->rowCount() > 0)
                {
                    QJsonArray array2;
                    for (int i = 0; i < ui.tableWidget_Cst->rowCount(); i++)
                    {
                        if ((ui.tableWidget_Cst->item(i, 0))->text() != "")
                            array2.append((ui.tableWidget_Cst->item(i, 0))->text());
                    }

                    copyCurrentObject2["Const"] = array2;
                }
                else
                    copyCurrentObject2.remove("Const");
                /************************************************************************************************/

                copyCurrentObject["Iso3D"] = copyCurrentObject2;
            }
        }
    }
    else if (copyCurrentObject["Param3D"].isObject())
    {
        copyCurrentObject.remove("Iso3D");
        QJsonObject copyCurrentObject2 = copyCurrentObject["Param3D"].toObject();
        if (indexcurrentFormula != -1)
        {
            if ((ui.paramNameEdit->toPlainText()).replace(" ", "") == "")
            {
                array = copyCurrentObject2["Fx"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Fx"] = array;

                array = copyCurrentObject2["Fy"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Fy"] = array;

                array = copyCurrentObject2["Fz"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Fz"] = array;

                array = copyCurrentObject2["Umin"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Umin"] = array;

                array = copyCurrentObject2["Umax"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Umax"] = array;

                array = copyCurrentObject2["Vmin"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Vmin"] = array;

                array = copyCurrentObject2["Vmax"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Vmax"] = array;

                if (copyCurrentObject2["Component"].isArray())
                {
                    array = copyCurrentObject2["Component"].toArray();
                    array.removeAt(indexcurrentFormula);
                    copyCurrentObject2["Component"] = array;
                }
                else
                    copyCurrentObject2.remove("Component");

                if (copyCurrentObject2["Grid"].isArray())
                {
                    array = copyCurrentObject2["Grid"].toArray();
                    array.removeAt(indexcurrentFormula);
                    copyCurrentObject2["Grid"] = array;
                }
                else
                    copyCurrentObject2.remove("Grid");

                if (copyCurrentObject2["Cnd"].isArray() &&
                        copyCurrentObject2["Cnd"].toArray().count() > indexcurrentFormula)
                {
                    array = copyCurrentObject2["Cnd"].toArray();
                    array.removeAt(indexcurrentFormula);
                    copyCurrentObject2["Cnd"] = array;
                }
                else
                    copyCurrentObject2.remove("Cnd");

                /************************************************************************************************/
                // Functions:
                if (copyCurrentObject2["Funct"].isArray() &&
                        ui.tableWidget_Fct_2->rowCount() > 0)
                {
                    QJsonArray array2;

                    for (int i = 0; i < ui.tableWidget_Fct_2->rowCount(); i++)
                    {
                        if ((ui.tableWidget_Fct_2->item(i, 0))->text() != "")
                            array2.append((ui.tableWidget_Fct_2->item(i, 0))->text());
                    }

                    copyCurrentObject2["Funct"] = array2;
                }
                else
                    copyCurrentObject2.remove("Funct");

                // Constantes:
                if (copyCurrentObject2["Const"].isArray() &&
                        ui.tableWidget_Cst_2->rowCount() > 0)
                {
                    QJsonArray array2;
                    for (int i = 0; i < ui.tableWidget_Cst_2->rowCount(); i++)
                    {
                        if ((ui.tableWidget_Cst_2->item(i, 0))->text() != "")
                            array2.append((ui.tableWidget_Cst_2->item(i, 0))->text());
                    }

                    copyCurrentObject2["Const"] = array2;
                }
                else
                    copyCurrentObject2.remove("Const");
                /************************************************************************************************/

                // Some keys cleaning..
                copyCurrentObject2.remove("Iso3D");
                copyCurrentObject2.remove("Param4D");
                copyCurrentObject["Param3D"] = copyCurrentObject2;

            }
            else if (((copyCurrentObject["Param3D"].toObject())["Component"]
                      .toArray())
                     .count() > 0 &&
                     indexcurrentFormula > -1 &&
                     indexcurrentFormula <
                     ((copyCurrentObject["Param3D"].toObject())["Component"]
                      .toArray())
                     .size() &&
                     ((copyCurrentObject["Param3D"].toObject())["Component"]
                      .toArray())[indexcurrentFormula]
                     .toString()
                     .replace(" ", "") ==
                     (ui.paramNameEdit->toPlainText()).replace(" ", ""))
            {
                array = copyCurrentObject2["Fx"].toArray();
                array.replace(indexcurrentFormula, ui.XEdit->toPlainText());
                copyCurrentObject2["Fx"] = array;

                array = copyCurrentObject2["Fy"].toArray();
                array.replace(indexcurrentFormula, ui.YEdit->toPlainText());
                copyCurrentObject2["Fy"] = array;

                array = copyCurrentObject2["Fz"].toArray();
                array.replace(indexcurrentFormula, ui.ZEdit->toPlainText());
                copyCurrentObject2["Fz"] = array;

                array = copyCurrentObject2["Umin"].toArray();
                array.replace(indexcurrentFormula, ui.umin->toPlainText());
                copyCurrentObject2["Umin"] = array;

                array = copyCurrentObject2["Umax"].toArray();
                array.replace(indexcurrentFormula, ui.umax->toPlainText());
                copyCurrentObject2["Umax"] = array;

                array = copyCurrentObject2["Vmin"].toArray();
                array.replace(indexcurrentFormula, ui.vmin->toPlainText());
                copyCurrentObject2["Vmin"] = array;

                array = copyCurrentObject2["Vmax"].toArray();
                array.replace(indexcurrentFormula, ui.vmax->toPlainText());
                copyCurrentObject2["Vmax"] = array;

                if (copyCurrentObject2["Grid"].isArray())
                {
                    array = copyCurrentObject2["Grid"].toArray();
                    // array.replace(indexcurrentFormula,
                    // QString::number(ui.linecolumn_2->value()));
                    copyCurrentObject2["Grid"] = array;
                }
                else
                    copyCurrentObject2.remove("Grid");

                if (copyCurrentObject2["Cnd"].isArray() &&
                        copyCurrentObject2["Cnd"].toArray().count() > indexcurrentFormula)
                {
                    array = copyCurrentObject2["Cnd"].toArray();
                    array.replace(indexcurrentFormula, ui.CndUpdateEdit_2->toPlainText());
                    copyCurrentObject2["Cnd"] = array;
                }
                else if (ui.CndUpdateEdit->toPlainText() != "")
                {
                    array = copyCurrentObject2["Cnd"].toArray();
                    for (int i = 0; i < copyCurrentObject2["Fx"].toArray().count(); i++)
                        array.append(ui.CndUpdateEdit->toPlainText());
                    copyCurrentObject2["Cnd"] = array;
                }
                else
                    copyCurrentObject2.remove("Cnd");

                /************************************************************************************************/
                // Functions:
                if (copyCurrentObject2["Funct"].isArray() &&
                        ui.tableWidget_Fct_2->rowCount() > 0)
                {
                    QJsonArray array2;

                    for (int i = 0; i < ui.tableWidget_Fct_2->rowCount(); i++)
                    {
                        if ((ui.tableWidget_Fct_2->item(i, 0))->text() != "")
                            array2.append((ui.tableWidget_Fct_2->item(i, 0))->text());
                    }

                    copyCurrentObject2["Funct"] = array2;
                }
                else
                    copyCurrentObject2.remove("Funct");

                // Constantes:
                if (copyCurrentObject2["Const"].isArray() &&
                        ui.tableWidget_Cst_2->rowCount() > 0)
                {
                    QJsonArray array2;
                    for (int i = 0; i < ui.tableWidget_Cst_2->rowCount(); i++)
                    {
                        if ((ui.tableWidget_Cst_2->item(i, 0))->text() != "")
                            array2.append((ui.tableWidget_Cst_2->item(i, 0))->text());
                    }

                    copyCurrentObject2["Const"] = array2;
                }
                else
                    copyCurrentObject2.remove("Const");
                /************************************************************************************************/

                copyCurrentObject["Param3D"] = copyCurrentObject2;
            }
            else
            {
                if (((copyCurrentObject["Param3D"].toObject())["Component"]
                        .toArray())[indexcurrentFormula]
                        .toString()
                        .replace(" ", "") !=
                        (ui.paramNameEdit->toPlainText()).replace(" ", ""))
                {
                    array = copyCurrentObject2["Fx"].toArray();
                    array.append(ui.XEdit->toPlainText());
                    copyCurrentObject2["Fx"] = array;

                    array = copyCurrentObject2["Fy"].toArray();
                    array.append(ui.YEdit->toPlainText());
                    copyCurrentObject2["Fy"] = array;

                    array = copyCurrentObject2["Fz"].toArray();
                    array.append(ui.ZEdit->toPlainText());
                    copyCurrentObject2["Fz"] = array;

                    array = copyCurrentObject2["Umin"].toArray();
                    array.append(ui.umin->toPlainText());
                    copyCurrentObject2["Umin"] = array;

                    array = copyCurrentObject2["Umax"].toArray();
                    array.append(ui.umax->toPlainText());
                    copyCurrentObject2["Umax"] = array;

                    array = copyCurrentObject2["Vmin"].toArray();
                    array.append(ui.vmin->toPlainText());
                    copyCurrentObject2["Vmin"] = array;

                    array = copyCurrentObject2["Vmax"].toArray();
                    array.append(ui.vmax->toPlainText());
                    copyCurrentObject2["Vmax"] = array;

                    if (copyCurrentObject2["Component"].isArray())
                    {
                        array = copyCurrentObject2["Component"].toArray();
                        array.append(ui.paramNameEdit->toPlainText());
                        copyCurrentObject2["Component"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Component");

                    if (copyCurrentObject2["Grid"].isArray())
                    {
                        array = copyCurrentObject2["Grid"].toArray();
                        array.append(QString::number(ui.linecolumn_2->value()));
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
                    else if (ui.CndUpdateEdit->toPlainText() != "")
                    {
                        array = copyCurrentObject2["Cnd"].toArray();
                        for (int i = 0; i < copyCurrentObject2["Fx"].toArray().count(); i++)
                            array.append(ui.CndUpdateEdit->toPlainText());
                        copyCurrentObject2["Cnd"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Cnd");
                }
                else
                {
                    array = copyCurrentObject2["Fx"].toArray();
                    array.insert(indexcurrentFormula, ui.XEdit->toPlainText());
                    copyCurrentObject2["Fx"] = array;

                    array = copyCurrentObject2["Fy"].toArray();
                    array.insert(indexcurrentFormula, ui.YEdit->toPlainText());
                    copyCurrentObject2["Fy"] = array;

                    array = copyCurrentObject2["Fz"].toArray();
                    array.insert(indexcurrentFormula, ui.ZEdit->toPlainText());
                    copyCurrentObject2["Fz"] = array;

                    array = copyCurrentObject2["Umin"].toArray();
                    array.insert(indexcurrentFormula, ui.umin->toPlainText());
                    copyCurrentObject2["Umin"] = array;

                    array = copyCurrentObject2["Umax"].toArray();
                    array.insert(indexcurrentFormula, ui.umax->toPlainText());
                    copyCurrentObject2["Umax"] = array;

                    array = copyCurrentObject2["Vmin"].toArray();
                    array.insert(indexcurrentFormula, ui.vmin->toPlainText());
                    copyCurrentObject2["Vmin"] = array;

                    array = copyCurrentObject2["Vmax"].toArray();
                    array.insert(indexcurrentFormula, ui.vmax->toPlainText());
                    copyCurrentObject2["Vmax"] = array;

                    if (copyCurrentObject2["Component"].isArray())
                    {
                        array = copyCurrentObject2["Component"].toArray();
                        array.insert(indexcurrentFormula, ui.paramNameEdit->toPlainText());
                        copyCurrentObject2["Component"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Component");

                    if (copyCurrentObject2["Cnd"].isArray())
                    {
                        array = copyCurrentObject2["Cnd"].toArray();
                        array.append(ui.CndUpdateEdit_2->toPlainText());
                        copyCurrentObject2["Cnd"] = array;
                    }
                    else if (ui.CndUpdateEdit->toPlainText() != "")
                    {
                        array = copyCurrentObject2["Cnd"].toArray();
                        for (int i = 0; i < copyCurrentObject2["Fx"].toArray().count(); i++)
                            array.append(ui.CndUpdateEdit->toPlainText());
                        copyCurrentObject2["Cnd"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Cnd");

                    if (copyCurrentObject2["Grid"].isArray())
                    {
                        array = copyCurrentObject2["Grid"].toArray();
                        // array.insert(indexcurrentFormula,
                        // QString::number(ui.linecolumn_2->value()));
                        copyCurrentObject2["Grid"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Grid");
                }

                /************************************************************************************************/
                // Functions:
                if (copyCurrentObject2["Funct"].isArray() &&
                        ui.tableWidget_Fct_2->rowCount() > 0)
                {
                    QJsonArray array2;

                    for (int i = 0; i < ui.tableWidget_Fct_2->rowCount(); i++)
                    {
                        if ((ui.tableWidget_Fct_2->item(i, 0))->text() != "")
                            array2.append((ui.tableWidget_Fct_2->item(i, 0))->text());
                    }

                    copyCurrentObject2["Funct"] = array2;
                }
                else
                    copyCurrentObject2.remove("Funct");

                // Constantes:
                if (copyCurrentObject2["Const"].isArray() &&
                        ui.tableWidget_Cst_2->rowCount() > 0)
                {
                    QJsonArray array2;
                    for (int i = 0; i < ui.tableWidget_Cst_2->rowCount(); i++)
                    {
                        if ((ui.tableWidget_Cst_2->item(i, 0))->text() != "")
                            array2.append((ui.tableWidget_Cst_2->item(i, 0))->text());
                    }

                    copyCurrentObject2["Const"] = array2;
                }
                else
                    copyCurrentObject2.remove("Const");
                /************************************************************************************************/
                copyCurrentObject["Param3D"] = copyCurrentObject2;
            }
        }
    }
    else if (copyCurrentObject["Param4D"].isObject())
    {
        copyCurrentObject.remove("Iso3D");
        copyCurrentObject.remove("Param3D");
        QJsonObject copyCurrentObject2 = copyCurrentObject["Param4D"].toObject();
        if (indexcurrentFormula != -1)
        {
            if ((ui.paramNameEdit_2->toPlainText()).replace(" ", "") == "")
            {
                array = copyCurrentObject2["Fx"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Fx"] = array;

                array = copyCurrentObject2["Fy"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Fy"] = array;

                array = copyCurrentObject2["Fz"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Fz"] = array;

                array = copyCurrentObject2["Fw"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Fw"] = array;

                array = copyCurrentObject2["Umin"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Umin"] = array;

                array = copyCurrentObject2["Umax"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Umax"] = array;

                array = copyCurrentObject2["Vmin"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Vmin"] = array;

                array = copyCurrentObject2["Vmax"].toArray();
                array.removeAt(indexcurrentFormula);
                copyCurrentObject2["Vmax"] = array;

                if (copyCurrentObject2["Component"].isArray())
                {
                    array = copyCurrentObject2["Component"].toArray();
                    array.removeAt(indexcurrentFormula);
                    copyCurrentObject2["Component"] = array;
                }
                else
                    copyCurrentObject2.remove("Component");

                if (copyCurrentObject2["Grid"].isArray())
                {
                    array = copyCurrentObject2["Grid"].toArray();
                    array.removeAt(indexcurrentFormula);
                    copyCurrentObject2["Grid"] = array;
                }
                else
                    copyCurrentObject2.remove("Grid");

                copyCurrentObject["Param4D"] = copyCurrentObject2;
            }
            else if (((copyCurrentObject["Param4D"].toObject())["Component"]
                      .toArray())
                     .count() > 0 &&
                     indexcurrentFormula > -1 &&
                     indexcurrentFormula <
                     ((copyCurrentObject["Param4D"].toObject())["Component"]
                      .toArray())
                     .size() &&
                     ((copyCurrentObject["Param4D"].toObject())["Component"]
                      .toArray())[indexcurrentFormula]
                     .toString()
                     .replace(" ", "") ==
                     (ui.paramNameEdit_2->toPlainText()).replace(" ", ""))
            {

                array = copyCurrentObject2["Fx"].toArray();
                array.replace(indexcurrentFormula, ui.XEdit_2->toPlainText());
                copyCurrentObject2["Fx"] = array;

                array = copyCurrentObject2["Fy"].toArray();
                array.replace(indexcurrentFormula, ui.YEdit_2->toPlainText());
                copyCurrentObject2["Fy"] = array;

                array = copyCurrentObject2["Fz"].toArray();
                array.replace(indexcurrentFormula, ui.ZEdit_2->toPlainText());
                copyCurrentObject2["Fz"] = array;

                array = copyCurrentObject2["Fw"].toArray();
                array.replace(indexcurrentFormula, ui.WEdit_2->toPlainText());
                copyCurrentObject2["Fw"] = array;

                array = copyCurrentObject2["Umin"].toArray();
                array.replace(indexcurrentFormula, ui.umin_2->toPlainText());
                copyCurrentObject2["Umin"] = array;

                array = copyCurrentObject2["Umax"].toArray();
                array.replace(indexcurrentFormula, ui.umax_2->toPlainText());
                copyCurrentObject2["Umax"] = array;

                array = copyCurrentObject2["Vmin"].toArray();
                array.replace(indexcurrentFormula, ui.vmin_2->toPlainText());
                copyCurrentObject2["Vmin"] = array;

                array = copyCurrentObject2["Vmax"].toArray();
                array.replace(indexcurrentFormula, ui.vmax_2->toPlainText());
                copyCurrentObject2["Vmax"] = array;

                if (copyCurrentObject2["Grid"].isArray())
                {
                    array = copyCurrentObject2["Grid"].toArray();
                    // array.replace(indexcurrentFormula,
                    // QString::number(ui.linecolumn_2->value()));
                    copyCurrentObject2["Grid"] = array;
                }
                else
                    copyCurrentObject2.remove("Grid");

                copyCurrentObject["Param4D"] = copyCurrentObject2;
            }
            else
            {
                if (((copyCurrentObject["Param4D"].toObject())["Component"]
                        .toArray())[indexcurrentFormula]
                        .toString()
                        .replace(" ", "") !=
                        (ui.paramNameEdit_2->toPlainText()).replace(" ", ""))
                {
                    array = copyCurrentObject2["Fx"].toArray();
                    array.append(ui.XEdit_2->toPlainText());
                    copyCurrentObject2["Fx"] = array;

                    array = copyCurrentObject2["Fy"].toArray();
                    array.append(ui.YEdit_2->toPlainText());
                    copyCurrentObject2["Fy"] = array;

                    array = copyCurrentObject2["Fz"].toArray();
                    array.append(ui.ZEdit_2->toPlainText());
                    copyCurrentObject2["Fz"] = array;

                    array = copyCurrentObject2["Fw"].toArray();
                    array.append(ui.WEdit_2->toPlainText());
                    copyCurrentObject2["Fw"] = array;

                    array = copyCurrentObject2["Umin"].toArray();
                    array.append(ui.umin_2->toPlainText());
                    copyCurrentObject2["Umin"] = array;

                    array = copyCurrentObject2["Umax"].toArray();
                    array.append(ui.umax_2->toPlainText());
                    copyCurrentObject2["Umax"] = array;

                    array = copyCurrentObject2["Vmin"].toArray();
                    array.append(ui.vmin_2->toPlainText());
                    copyCurrentObject2["Vmin"] = array;

                    array = copyCurrentObject2["Vmax"].toArray();
                    array.append(ui.vmax_2->toPlainText());
                    copyCurrentObject2["Vmax"] = array;

                    if (copyCurrentObject2["Component"].isArray())
                    {
                        array = copyCurrentObject2["Component"].toArray();
                        array.append(ui.paramNameEdit_2->toPlainText());
                        copyCurrentObject2["Component"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Component");

                    if (copyCurrentObject2["Grid"].isArray())
                    {
                        array = copyCurrentObject2["Grid"].toArray();
                        array.append(QString::number(ui.linecolumn_2->value()));
                        copyCurrentObject2["Grid"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Grid");

                    copyCurrentObject["Param4D"] = copyCurrentObject2;
                }
                else
                {
                    array = copyCurrentObject2["Fx"].toArray();
                    array.insert(indexcurrentFormula, ui.XEdit_2->toPlainText());
                    copyCurrentObject2["Fx"] = array;

                    array = copyCurrentObject2["Fy"].toArray();
                    array.insert(indexcurrentFormula, ui.YEdit_2->toPlainText());
                    copyCurrentObject2["Fy"] = array;

                    array = copyCurrentObject2["Fz"].toArray();
                    array.insert(indexcurrentFormula, ui.ZEdit_2->toPlainText());
                    copyCurrentObject2["Fz"] = array;

                    array = copyCurrentObject2["Fw"].toArray();
                    array.insert(indexcurrentFormula, ui.WEdit_2->toPlainText());
                    copyCurrentObject2["Fw"] = array;

                    array = copyCurrentObject2["Umin"].toArray();
                    array.insert(indexcurrentFormula, ui.umin_2->toPlainText());
                    copyCurrentObject2["Umin"] = array;

                    array = copyCurrentObject2["Umax"].toArray();
                    array.insert(indexcurrentFormula, ui.umax_2->toPlainText());
                    copyCurrentObject2["Umax"] = array;

                    array = copyCurrentObject2["Vmin"].toArray();
                    array.insert(indexcurrentFormula, ui.vmin_2->toPlainText());
                    copyCurrentObject2["Vmin"] = array;

                    array = copyCurrentObject2["Vmax"].toArray();
                    array.insert(indexcurrentFormula, ui.vmax_2->toPlainText());
                    copyCurrentObject2["Vmax"] = array;

                    if (copyCurrentObject2["Component"].isArray())
                    {
                        array = copyCurrentObject2["Component"].toArray();
                        array.insert(indexcurrentFormula,
                                     ui.paramNameEdit_2->toPlainText());
                        copyCurrentObject2["Component"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Component");

                    if (copyCurrentObject2["Grid"].isArray())
                    {
                        array = copyCurrentObject2["Grid"].toArray();
                        copyCurrentObject2["Grid"] = array;
                    }
                    else
                        copyCurrentObject2.remove("Grid");

                    copyCurrentObject["Param4D"] = copyCurrentObject2;
                }
            }
        }
    }
}
// --------------------------
void DrawingOptions::RunUpdatedJObject(QJsonObject &CurrentObject)
{
    if (indexcurrentFormula != -1)
    {
        if (CurrentObject["Iso3D"].isObject())
        {
            CurrentObject.remove("Param3D");
            CurrentObject.remove("Param4D");
            CurrentObject.remove("ParIso");
            DrawJsonModel(CurrentObject);
        }
        else if (CurrentObject["Param3D"].isObject())
        {
            CurrentObject.remove("Iso3D");
            CurrentObject.remove("Param4D");
            CurrentObject.remove("ParIso");
            DrawJsonModel(CurrentObject);
        }
        else if (CurrentObject["Param4D"].isObject())
        {
            CurrentObject.remove("Iso3D");
            CurrentObject.remove("Param3D");
            CurrentObject.remove("ParIso");
            DrawJsonModel(CurrentObject);
        }
        else
        {
            CurrentObject.remove("Iso3D");
            CurrentObject.remove("Param3D");
            CurrentObject.remove("Param4D");
            DrawJsonModel(CurrentObject);
        }
    }
}

// --------------------------
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
            /*
            for(int i=0; i<listeObj.size(); i++)
                listeObj.removeAt(i);
                */
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
        on_updateJObject(CurrentObject);
        RunUpdatedJObject(CurrentObject);
    }
}

// --------------------------
void DrawingOptions::on_updateParam_clicked()
{
    on_updateButton_clicked();
}

// --------------------------
void DrawingOptions::on_actionPolygonWavefront_obj_triggered()
{
    MathmodRef->ui.glWidget->SaveSceneAsObjPoly();
}

// --------------------------
void DrawingOptions::on_actionColorPolygonWavefront_obj_triggered()
{
    MathmodRef->ui.glWidget->SaveSceneAsObjPoly(1);
}

// --------------------------
void DrawingOptions::on_linecolumn_2_valueChanged(int value)
{
    ui.ParamgroupBox_2->setTitle("Param Grid(u,v) = ( " + QString::number(value) +
                                 ", " + QString::number(value) + " ) :");
    if (!MathmodRef->ui.glWidget->ParObjet->isRunning())
    {
        MathmodRef->linecolumn_valueChanged(value);
    }
    else
    {
        ui.uv->blockSignals(true);
        ui.uv->setChecked(false);
        ui.uv->blockSignals(false);
        MathmodRef->uvactivated = -1;
    }
}

// --------------------------
void DrawingOptions::on_lineScrollBar_valueChanged(int value)
{
    ui.ParamgroupBox_2->setTitle(
        "Param Grid(u,v) = ( " + QString::number(value) + ", " +
        QString::number(MathmodRef->ui.glWidget->ParObjet->Ugrid) + " ) :");
    if (!MathmodRef->ui.glWidget->ParObjet->isRunning())
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

// --------------------------
void DrawingOptions::on_coloneScrollBar_valueChanged(int value)
{
    ui.ParamgroupBox_2->setTitle(
        "Param Grid(u,v) = ( " +
        QString::number(MathmodRef->ui.glWidget->ParObjet->Vgrid) + ", " +
        QString::number(value) + " ) :");
    if (!MathmodRef->ui.glWidget->ParObjet->isRunning())
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

// --------------------------
void DrawingOptions::on_IsoComponent_activated(int index)
{
    UpdateDescription(index, ISO_TYPE, MathmodRef->RootObjet.CurrentTreestruct);
}

// --------------------------
void DrawingOptions::on_ParamComponent_activated(int index)
{
    UpdateDescription(index, PAR_TYPE, MathmodRef->RootObjet.CurrentTreestruct);
}

// --------------------------
void DrawingOptions::on_xyzcheckBox2_clicked()
{
    MathmodRef->ui.glWidget->LocalScene.animxyz *= -1;
}

// --------------------------
void DrawingOptions::on_xycheckBox2_clicked()
{
    MathmodRef->ui.glWidget->LocalScene.animx *= -1;
}

// --------------------------
void DrawingOptions::on_xyhorizontalScrollBar2_valueChanged(int value)
{
    MathmodRef->ui.glWidget->LocalScene.animxValueStep = float(value) / 4;
}

// --------------------------
void DrawingOptions::on_xzcheckBox2_clicked()
{
    MathmodRef->ui.glWidget->LocalScene.animy *= -1;
}

// --------------------------
void DrawingOptions::on_xzhorizontalScrollBar2_valueChanged(int value)
{
    MathmodRef->ui.glWidget->LocalScene.animyValueStep = float(value) / 4;
}

// --------------------------
void DrawingOptions::on_yzcheckBox2_clicked()
{
    MathmodRef->ui.glWidget->LocalScene.animz *= -1;
}

// --------------------------
void DrawingOptions::on_yzhorizontalScrollBar2_valueChanged(int value)
{
    MathmodRef->ui.glWidget->LocalScene.animzValueStep = float(value) / 4;
}

// --------------------------
void DrawingOptions::on_InitMatrix_2_clicked()
{
    MathmodRef->ui.glWidget->LocalScene.RotStrength =
        MathmodRef->ui.glWidget->LocalScene.animxValueStep =
            MathmodRef->ui.glWidget->LocalScene.animyValueStep =
                MathmodRef->ui.glWidget->LocalScene.animzValueStep = 0.0;
}

// --------------------------
void DrawingOptions::on_xycheckBox_clicked()
{
    MathmodRef->ui.glWidget->ParObjet->tetaxy_ok *= -1;
}

// --------------------------
void DrawingOptions::on_xyhorizontalScrollBar_valueChanged(int value)
{
    MathmodRef->ui.glWidget->ParObjet->tetaxy = value / 4.0;
}

// --------------------------
void DrawingOptions::on_xzcheckBox_clicked()
{
    MathmodRef->ui.glWidget->ParObjet->tetaxz_ok *= -1;
}

// --------------------------
void DrawingOptions::on_xzhorizontalScrollBar_valueChanged(int value)
{
    MathmodRef->ui.glWidget->ParObjet->tetaxz = value / 4.0;
}

// --------------------------
void DrawingOptions::on_yzcheckBox_clicked()
{
    MathmodRef->ui.glWidget->ParObjet->tetayz_ok *= -1;
}

// --------------------------
void DrawingOptions::on_yzhorizontalScrollBar_valueChanged(int value)
{
    MathmodRef->ui.glWidget->ParObjet->tetayz = value / 4.0;
}

// --------------------------
void DrawingOptions::on_xwcheckBox_clicked()
{
    MathmodRef->ui.glWidget->ParObjet->tetaxw_ok *= -1;
}

// --------------------------
void DrawingOptions::on_xwhorizontalScrollBar_valueChanged(int value)
{
    MathmodRef->ui.glWidget->ParObjet->tetaxw = value / 4.0;
}

// --------------------------
void DrawingOptions::on_ywcheckBox_clicked()
{
    MathmodRef->ui.glWidget->ParObjet->tetayw_ok *= -1;
}

// --------------------------
void DrawingOptions::on_ywhorizontalScrollBar_valueChanged(int value)
{
    MathmodRef->ui.glWidget->ParObjet->tetayw = value / 4.0;
}

// --------------------------
void DrawingOptions::on_zwcheckBox_clicked()
{
    MathmodRef->ui.glWidget->ParObjet->tetazw_ok *= -1;
}

// --------------------------
void DrawingOptions::on_zwhorizontalScrollBar_valueChanged(int value)
{
    MathmodRef->ui.glWidget->ParObjet->tetazw = value / 4.0;
}

// --------------------------
void DrawingOptions::on_linecolumn_3_valueChanged(int value)
{
    MathmodRef->linecolumn_valueChanged_2(value);
}

// --------------------------
void DrawingOptions::oncolor_4activated(int index)
{
    MathmodRef->ui.glWidget->colorstypeParam(index);
}

// --------------------------
void DrawingOptions::ontransparence_4toggled(bool checked)
{
    MathmodRef->ui.glWidget->transparence(checked);
}

// --------------------------
void DrawingOptions::on_uv4D_clicked()
{
    MathmodRef->slot_uv4D_clicked();
}

// --------------------------
void DrawingOptions::on_uv_clicked()
{
    MathmodRef->slot_uv_clicked();
}

// --------------------------
void DrawingOptions::on_InitMatrix_clicked()
{
    MathmodRef->ui.glWidget->ParObjet->mat4D.unit();
    on_calculate_clicked();
}

// --------------------------
void DrawingOptions::on_ActivateCND_clicked(bool checked)
{
    ui.CNDgroupBox->setEnabled(checked);
    MathmodRef->ui.glWidget->LocalScene.activarecnd = checked;
    MathmodRef->ui.glWidget->update();
}

// --------------------------
void DrawingOptions::on_TCNDcheckBox_clicked(bool checked)
{
    MathmodRef->ui.glWidget->LocalScene.cndoptions[3] = checked;
    MathmodRef->ui.glWidget->update();
}

// --------------------------
void DrawingOptions::on_FCNDcheckBox_clicked(bool checked)
{
    MathmodRef->ui.glWidget->LocalScene.cndoptions[0] = checked;
    MathmodRef->ui.glWidget->update();
}

// --------------------------
void DrawingOptions::on_TNCNDcheckBox_clicked(bool checked)
{
    MathmodRef->ui.glWidget->LocalScene.cndoptions[4] = checked;
    MathmodRef->ui.glWidget->update();
}

// --------------------------
void DrawingOptions::on_FNCNDcheckBox_clicked(bool checked)
{
    MathmodRef->ui.glWidget->LocalScene.cndoptions[1] = checked;
    MathmodRef->ui.glWidget->update();
}

// --------------------------
void DrawingOptions::on_TBordercheckBox_clicked(bool checked)
{
    MathmodRef->ui.glWidget->LocalScene.cndoptions[2] = checked;
    MathmodRef->ui.glWidget->update();
}

// --------------------------
void DrawingOptions::on_actionMesh_triggered()
{
    MathmodRef->Mesh();
}

// --------------------------
void DrawingOptions::on_calculate_clicked()
{
    on_InitTButton_clicked();
    Run_JsonObject_activeted();
}

// --------------------------
void DrawingOptions::on_actionAbout_2_triggered()
{
    ab.show();
}

// --------------------------
void DrawingOptions::on_actionLoad_json_script_triggered()
{
    LoadNewFileModels(true);
}

// --------------------------
void DrawingOptions::on_actionScreenshot_triggered()
{
    videoplay();
}

// --------------------------
void DrawingOptions::on_actionEditor_triggered()
{
    editorwin();
}

// --------------------------
void DrawingOptions::on_actionColors_triggered()
{
    colorsoptions();
}

// --------------------------
void DrawingOptions::on_actionSmooth_2_clicked()
{
    MathmodRef->smoothline();
}

// --------------------------
void DrawingOptions::on_Infos_clicked()
{
    MathmodRef->iso_infos();
}

// --------------------------
void DrawingOptions::on_Mesh_clicked()
{
    MathmodRef->Mesh();
}

// --------------------------
void DrawingOptions::on_Norm_clicked()
{
    MathmodRef->draw_norm_clicked();
}

// --------------------------
void DrawingOptions::on_Fill_clicked()
{
    MathmodRef->fill();
}

// --------------------------
void DrawingOptions::on_Trian_clicked()
{
    MathmodRef->slot_triangles_clicked();
}

// --------------------------
void DrawingOptions::on_actionOpenGL_triggered()
{
    Parameters->on_loadconfig_clicked();
    Parameters->show();
}

// --------------------------
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

// --------------------------
void DrawingOptions::on_actionConvert_K3DS_script_triggered()
{
    LoadK3DSurfScript("", 1);
}

// --------------------------
void DrawingOptions::on_actionConfiguration_triggered()
{
    on_actionOpenGL_triggered();
}

// --------------------------
void DrawingOptions::on_actionColors_2_triggered()
{
    on_actionColors_triggered();
}

// --------------------------
void DrawingOptions::on_Load_clicked()
{
    LoadNewFileModels(true);
}

// --------------------------
void DrawingOptions::on_ParamComponent_2_activated(int index)
{
    UpdateDescription(index, PAR_4D_TYPE,
                      MathmodRef->RootObjet.CurrentTreestruct);
}

// --------------------------
void DrawingOptions::on_updateParam_2_clicked()
{
    on_updateButton_clicked();
}

// --------------------------
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

// --------------------------
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

        Multiplier(i, j, k, copyCurrentObject, indexcurrentFormula);
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
    ui.xyzg->setValue(int(Parameters->InitIsoGrid));
    ui.xyzg->blockSignals(false);

    ui.linecolumn_2->blockSignals(true);
    ui.linecolumn_2->setMaximum(int(Parameters->ParMaxGrid));
    ui.linecolumn_2->setValue(int(Parameters->InitParGrid));
    ui.linecolumn_2->blockSignals(false);

    ui.linecolumn_3->blockSignals(true);
    ui.linecolumn_3->setMaximum(int(Parameters->ParMaxGrid));
    ui.linecolumn_3->setValue(int(Parameters->InitParGrid));
    ui.linecolumn_3->blockSignals(false);
}
// --------------------------
void DrawingOptions::UpdateGui(int argc)
{
    UpdateGuiMaxgrid();
    ListeModelTexture LstModelTexture = (Parameters->LoadCollectionModels(
            JSONMathModels, MathmodRef->collection, argc));

    // Load the script containing isosurface and parametric formulas:
    ui.choice->insertItems(0, LstModelTexture.listeModels);
    ui.comboBoxTexture->insertItems(0, LstModelTexture.listeTextures);
    ui.comboBoxPigment->insertItems(0, LstModelTexture.listePigments);
    AddListModels();

    // Threads setting:
    SetThreadValues(Parameters->Threads);

    // OpenGl specular:
    SetSpecularValues(Parameters->Specular);

    // OpenGl shininess:
    SetShininessValue(Parameters->Shininess);

    // Show the two windows of the application:
    move(Parameters->ControlX, Parameters->ControlY);
    resize(Parameters->ControlW, Parameters->ControlH);
    // ui.CndGroupBox->hide();
    // ui.NameLabel->hide();
    MathmodRef->move(Parameters->GlwinX, Parameters->GlwinY);
    MathmodRef->resize(Parameters->GlwinW, Parameters->GlwinH);
    // Pigment/texture
    ui.textureEdit->hide();
    // Hide all sliders
    HideSliders();
    // ProgressBar + text informations (set to minimum size 0)
    QList<int> Sizes;
    Sizes << 500 << 300;
    ui.splitter_6->setSizes(Sizes);
    ui.Messagetext->setFontPointSize(10);
}

// --------------------------
void DrawingOptions::on_TimeStepScrollBar_valueChanged(int value)
{
    double P = 1.0 / double(value);
    uint maxnbthreads = MathmodRef->ui.glWidget->IsoObjet->WorkerThreadsNumber;
    ui.label_5->setText("1/" + QString::number(value));

    MathmodRef->ui.glWidget->IsoObjet->masterthread->pace = P;
    for (uint nbthreds = 0; nbthreds < maxnbthreads - 1; nbthreds++)
        MathmodRef->ui.glWidget->IsoObjet->workerthreads[nbthreds].pace = P;

    MathmodRef->ui.glWidget->ParObjet->masterthread->pace = P;
    for (uint nbthreds = 0; nbthreds < maxnbthreads - 1; nbthreds++)
        MathmodRef->ui.glWidget->ParObjet->workerthreads[nbthreds].pace = P;
}

// --------------------------
void DrawingOptions::on_InitTButton_clicked()
{
    uint maxnbthreads = MathmodRef->ui.glWidget->IsoObjet->WorkerThreadsNumber;

    MathmodRef->ui.glWidget->IsoObjet->masterthread->stepMorph = 0;
    for (uint nbthreds = 0; nbthreds < maxnbthreads - 1; nbthreds++)
        MathmodRef->ui.glWidget->IsoObjet->workerthreads[nbthreds].stepMorph = 0;

    MathmodRef->ui.glWidget->ParObjet->masterthread->stepMorph = 0;
    for (uint nbthreds = 0; nbthreds < maxnbthreads - 1; nbthreds++)
        MathmodRef->ui.glWidget->ParObjet->workerthreads[nbthreds].stepMorph = 0;
}

// --------------------------
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
// --------------------------
void DrawingOptions::on_pushButton_2_clicked()
{
    QJsonParseError err;
    QString sortie;
    QString script =
        ui.ParamEdit->toPlainText()
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

    Parameters->SaveToFile_CurentMathModel(doc.object());
}

// --------------------------
void DrawingOptions::on_pushButton_3_clicked()
{
    ui.isoNameEdit->setText(ui.isoNameEdit->toPlainText() + "_01");
    on_updateButton_clicked();
}

// --------------------------
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

// --------------------------
void DrawingOptions::on_pushButton_4_clicked()
{
    ui.paramNameEdit->setText(ui.paramNameEdit->toPlainText() + "_01");
    on_updateButton_clicked();
}

// --------------------------
void DrawingOptions::on_color_5_activated(int index)
{
    MathmodRef->ui.glWidget->colorstypeParIso(index);
}

// --------------------------
void DrawingOptions::on_transparence_ParIso_clicked(bool checked)
{
    MathmodRef->ui.glWidget->transparence(checked);
}

// --------------------------
void DrawingOptions::on_transparent_ParIso_valueChanged(int value)
{
    MathmodRef->ui.glWidget->transparency(value, indexcurrentFormula);
}

// --------------------------
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

// --------------------------
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

// --------------------------
void DrawingOptions::on_actionTrianglesWavefront_obj_triggered()
{
    MathmodRef->ui.glWidget->SaveSceneAsObjTrian();
}

// --------------------------
void DrawingOptions::on_actionColorTrianglesWavefront_obj_triggered()
{
    MathmodRef->ui.glWidget->SaveSceneAsObjTrian(1);
}

// --------------------------
void DrawingOptions::on_OctavesScrollBar_valueChanged(int value)
{
    int Octaves =
        MathmodRef->ui.glWidget->LocalScene.componentsinfos.NoiseParam[0]
        .Octaves =
            MathmodRef->ui.glWidget->LocalScene.componentsinfos.NoiseParam[1]
            .Octaves = value;
    MathmodRef->ui.glWidget->IsoObjet->masterthread->Octaves = Octaves;
    MathmodRef->ui.glWidget->ParObjet->masterthread->Octaves = Octaves;

    ui.OctavesLabel->setText("Octaves = " + QString::number(Octaves));
    on_pushButton_5_clicked();
}

// --------------------------
void DrawingOptions::on_LacunarityScrollBar_valueChanged(int value)
{
    double Lacunarity = double(value) / 10.0;
    MathmodRef->ui.glWidget->LocalScene.componentsinfos.NoiseParam[0].Lacunarity =
        MathmodRef->ui.glWidget->LocalScene.componentsinfos.NoiseParam[1]
        .Lacunarity = float(Lacunarity);
    MathmodRef->ui.glWidget->IsoObjet->masterthread->Lacunarity = Lacunarity;
    MathmodRef->ui.glWidget->ParObjet->masterthread->Lacunarity = Lacunarity;
    ui.LacunarityLabel->setText("Lacunarity = " + QString::number(Lacunarity));
    on_pushButton_5_clicked();
}

// --------------------------
void DrawingOptions::on_GainScrollBar_valueChanged(int value)
{
    double Gain = double(value) / 10.0;
    MathmodRef->ui.glWidget->LocalScene.componentsinfos.NoiseParam[0].Gain =
        MathmodRef->ui.glWidget->LocalScene.componentsinfos.NoiseParam[1].Gain =
            float(Gain);
    MathmodRef->ui.glWidget->IsoObjet->masterthread->Gain = Gain;
    MathmodRef->ui.glWidget->ParObjet->masterthread->Gain = Gain;
    ui.GainLabel->setText("Gain = " + QString::number(Gain));
    on_pushButton_5_clicked();
}

// --------------------------
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

// --------------------------
void DrawingOptions::on_TurbulenceCheckBox_clicked()
{
    MathmodRef->ui.glWidget->LocalScene.componentsinfos.NoiseParam[0]
    .NoiseActive *= -1;
    MathmodRef->ui.glWidget->LocalScene.componentsinfos.NoiseParam[1]
    .NoiseActive *= -1;
    on_pushButton_5_clicked();
}

// --------------------------
void DrawingOptions::on_pushButton_5_clicked()
{
    QJsonParseError err;
    QString sortie;
    QString script =
        ui.textureEdit->toPlainText()
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

    QJsonObject tmp = doc.object();
    if (tmp["Texture"].isObject())
    {
        MathmodRef->collection.JTextures[ui.comboBoxTexture->currentIndex() - 1] =
            doc.object();
        on_comboBoxTexture_activated(ui.comboBoxTexture->currentIndex());
    }
    else
    {
        MathmodRef->collection.JPigments[ui.comboBoxPigment->currentIndex() - 1] =
            doc.object();
        on_comboBoxPigment_activated(ui.comboBoxPigment->currentIndex());
    }
}

// --------------------------
void DrawingOptions::on_C1ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 0);
}

// --------------------------
void DrawingOptions::on_C2ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 1);
}

// --------------------------
void DrawingOptions::on_C3ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 2);
}

// --------------------------
void DrawingOptions::on_C4ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 3);
}

// --------------------------
void DrawingOptions::on_C5ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 4);
}

// --------------------------
void DrawingOptions::on_C6ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 5);
}

// --------------------------
void DrawingOptions::on_C7ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 6);
}

// --------------------------
void DrawingOptions::on_C8ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 7);
}

// --------------------------
void DrawingOptions::on_C9ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 8);
}

// --------------------------
void DrawingOptions::on_C10ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 9);
}

// --------------------------
void DrawingOptions::on_C11ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 10);
}

// --------------------------
void DrawingOptions::on_C12ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 11);
}

// --------------------------
void DrawingOptions::on_C13ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 12);
}

// --------------------------
void DrawingOptions::on_C14ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 13);
}

// --------------------------
void DrawingOptions::on_C15ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 14);
}

// --------------------------
void DrawingOptions::on_C16ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 15);
}

// --------------------------
void DrawingOptions::on_C17ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 16);
}

// --------------------------
void DrawingOptions::on_C18ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 17);
}

// --------------------------
void DrawingOptions::on_C19ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 18);
}

// --------------------------
void DrawingOptions::on_C20ScrollBar_valueChanged(int val)
{
    CScrollBar_valueChanged(val, 19);
}

// --------------------------
void DrawingOptions::CScrollBar_valueChanged(int val, int idx)
{
    MathmodRef->ui.glWidget->LocalScene.slider = 1;
    MathmodRef->ui.glWidget->IsoObjet->masterthread->SliderValues[uint(idx)] =
        val;
    MathmodRef->ui.glWidget->ParObjet->masterthread->SliderValues[uint(idx)] =
        val;
    SliderArray[idx].SliderLabel->setText(qlstnames.at(idx) + " = " +
                                          QString::number(val));
    if (CurrentFormulaType == 2)
        MathmodRef->ProcessNewIsoSurface();
    else
        MathmodRef->ParametricSurfaceProcess(CurrentFormulaType);
    MathmodRef->ui.glWidget->LocalScene.slider = -1;
}

// --------------------------
void DrawingOptions::on_PredefinedSets_activated(int index)
{
    indexcurrentSet = index;
    if (index > 0)
    {
        int size = (qlstnames.size());
        MathmodRef->ui.glWidget->LocalScene.slider = 1;
        for (int i = 0; i < size; ++i)
        {
            MathmodRef->ui.glWidget->IsoObjet->masterthread->SliderValues[uint(i)] =
                qlstPos.at(i + (index - 1) * size).toDouble();
            MathmodRef->ui.glWidget->ParObjet->masterthread->SliderValues[uint(i)] =
                qlstPos.at(i + (index - 1) * size).toDouble();
        }

        for (int sl = 0; sl < 20; sl++)
        {
            if (size >= (sl + 1))
            {
                (SliderArray[sl].SliderLabel)
                ->setText(qlstnames.at(sl) + " = " +
                          qlstPos.at(sl + (index - 1) * size) + "(" +
                          qlstStep.at(sl) + ")");
                (SliderArray[sl].SliderScrollBar)->blockSignals(true);
                if (qlstmin.size() > qlstnames.size())
                {
                    (SliderArray[sl].SliderScrollBar)
                    ->setMaximum(qlstmax.at(sl + (index - 1) * size).toInt());
                    (SliderArray[sl].SliderScrollBar)
                    ->setMinimum(qlstmin.at(sl + (index - 1) * size).toInt());
                    (SliderArray[sl].SliderScrollBar)
                    ->setSingleStep(qlstStep.at(sl + (index - 1) * size).toInt());

                    (SliderArray[sl].SliderLabel)
                    ->setText(qlstnames.at(sl) + " = " +
                              qlstPos.at(sl + (index - 1) * size) + "(" +
                              qlstStep.at(sl + (index - 1) * size) + ")");
                    (SliderArray[sl].SliderLabelMin)
                    ->setText(qlstmin.at(sl + (index - 1) * size));
                    (SliderArray[sl].SliderLabelMax)
                    ->setText(qlstmax.at(sl + (index - 1) * size));
                }
                (SliderArray[sl].SliderScrollBar)
                ->setSliderPosition(qlstPos.at(sl + (index - 1) * size).toInt());
                (SliderArray[sl].SliderScrollBar)->blockSignals(false);
            }
        }

        // Draw
        if (CurrentFormulaType == 2)
            MathmodRef->ProcessNewIsoSurface();
        else
            MathmodRef->ParametricSurfaceProcess(CurrentFormulaType);
        MathmodRef->ui.glWidget->LocalScene.slider = -1;
    }
}
void DrawingOptions::CIndextoolButton_clicked(int idx)
{
    int range = (indexcurrentSet < 1)
                ? (idx - 1)
                : (indexcurrentSet - 1) * qlstnames.size() + (idx - 1);
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

// --------------------------
void DrawingOptions::on_C20toolButton_clicked()
{
    CIndextoolButton_clicked(20);
}

// --------------------------
void DrawingOptions::on_C19toolButton_clicked()
{
    CIndextoolButton_clicked(19);
}

// --------------------------
void DrawingOptions::on_C18toolButton_clicked()
{
    CIndextoolButton_clicked(18);
}

// --------------------------
void DrawingOptions::on_C17toolButton_clicked()
{
    CIndextoolButton_clicked(17);
}

// --------------------------
void DrawingOptions::on_C16toolButton_clicked()
{
    CIndextoolButton_clicked(16);
}

// --------------------------
void DrawingOptions::on_C15toolButton_clicked()
{
    CIndextoolButton_clicked(15);
}

// --------------------------
void DrawingOptions::on_C14toolButton_clicked()
{
    CIndextoolButton_clicked(14);
}

// --------------------------
void DrawingOptions::on_C13toolButton_clicked()
{
    CIndextoolButton_clicked(13);
}

// --------------------------
void DrawingOptions::on_C12toolButton_clicked()
{
    CIndextoolButton_clicked(12);
}

// --------------------------
void DrawingOptions::on_C11toolButton_clicked()
{
    CIndextoolButton_clicked(11);
}

// --------------------------
void DrawingOptions::on_C10toolButton_clicked()
{
    CIndextoolButton_clicked(10);
}

// --------------------------
void DrawingOptions::on_C9toolButton_clicked()
{
    CIndextoolButton_clicked(9);
}

// --------------------------
void DrawingOptions::on_C8toolButton_clicked()
{
    CIndextoolButton_clicked(8);
}

// --------------------------
void DrawingOptions::on_C7toolButton_clicked()
{
    CIndextoolButton_clicked(7);
}

// --------------------------
void DrawingOptions::on_C6toolButton_clicked()
{
    CIndextoolButton_clicked(6);
}

// --------------------------
void DrawingOptions::on_C5toolButton_clicked()
{
    CIndextoolButton_clicked(5);
}

// --------------------------
void DrawingOptions::on_C4toolButton_clicked()
{
    CIndextoolButton_clicked(4);
}

// --------------------------
void DrawingOptions::on_C3toolButton_clicked()
{
    CIndextoolButton_clicked(3);
}

// --------------------------
void DrawingOptions::on_C2toolButton_clicked()
{
    CIndextoolButton_clicked(2);
}

// --------------------------
void DrawingOptions::on_C1toolButton_clicked()
{
    CIndextoolButton_clicked(1);
}
// --------------------------
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
            (SliderArray[sl].SliderScrollBar)
            ->setSliderPosition(qlstPos.at(sl).toInt());
            (SliderArray[sl].SliderLabel)
            ->setText(qlstnames.at(sl) + " = " + qlstPos.at(sl) + "(" +
                      qlstStep.at(sl) + ")");
            (SliderArray[sl].SliderLabelMin)->setText(qlstmin.at(sl));
            (SliderArray[sl].SliderLabelMax)->setText(qlstmax.at(sl));
            (SliderArray[sl].SliderScrollBar)->blockSignals(false);

            MathmodRef->ui.glWidget->IsoObjet->masterthread->SliderNames.push_back(
                qlstnames.at(sl).toStdString());
            MathmodRef->ui.glWidget->ParObjet->masterthread->SliderNames.push_back(
                qlstnames.at(sl).toStdString());

            MathmodRef->ui.glWidget->IsoObjet->masterthread->SliderValues.push_back(
                qlstPos.at(sl).toDouble());
            MathmodRef->ui.glWidget->ParObjet->masterthread->SliderValues.push_back(
                qlstPos.at(sl).toDouble());
        }
    }

    // Draw
    MathmodRef->ui.glWidget->LocalScene.slider = 1;
    if (CurrentFormulaType == 2)
        MathmodRef->ProcessNewIsoSurface();
    else
        MathmodRef->ParametricSurfaceProcess(CurrentFormulaType);
    MathmodRef->ui.glWidget->LocalScene.slider = -1;
}

//-----------------------
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
        array1.append("NewSetName");
    }
    else
        tmp2.remove("SetNames");

    for (int sl = 0; sl < 20; sl++)
    {
        if (size >= (sl + 1))
        {
            array2.append(
                QString::number((SliderArray[sl].SliderScrollBar)->sliderPosition()));
            array3.append(
                QString::number((SliderArray[sl].SliderScrollBar)->minimum()));
            array4.append(
                QString::number((SliderArray[sl].SliderScrollBar)->maximum()));
            array5.append(
                QString::number((SliderArray[sl].SliderScrollBar)->singleStep()));
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

//--------------------
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

//---------------------
void DrawingOptions::on_AddParam_clicked()
{
    addnewparam.ui.NameEdit->setText("ParamName");
    addnewparam.ui.MaxEdit->setText("50");
    addnewparam.ui.MinEdit->setText("0");
    addnewparam.ui.StepEdit->setText("1");
    addnewparam.ui.PosEdit->setText("10");
    addnewparam.show();
}

//---------------------
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

//---------------------
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

//---------------------
void DrawingOptions::update_infos_param(int index)
{
    CIndextoolButton_clicked(index);
    sliderconf.currentSlider = index - 1;
}

//---------------------
void DrawingOptions::on_actionFrames_triggered()
{
    MathmodRef->frames_clicked();
}

//---------------------
void DrawingOptions::SetSpecularValues(float *spec)
{
    ui.red_Specular->blockSignals(true);
    ui.red_Specular->setSliderPosition(int(spec[0] * 100));
    ui.red_Specular->blockSignals(false);

    ui.green_Specular->blockSignals(true);
    ui.green_Specular->setSliderPosition(int(spec[1] * 100));
    ui.green_Specular->blockSignals(false);

    ui.blue_Specular->blockSignals(true);
    ui.blue_Specular->setSliderPosition(int(spec[2] * 100));
    ui.blue_Specular->blockSignals(false);

    ui.transparent_Specular->blockSignals(true);
    ui.transparent_Specular->setSliderPosition(int(spec[3] * 100));
    ui.transparent_Specular->blockSignals(false);
}

//---------------------
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

//---------------------
void DrawingOptions::SetShininessValue(int shin)
{
    ui.ShininessScrollBar->blockSignals(true);
    ui.ShininessScrollBar->setSliderPosition(shin);
    ui.ShininessScrollBar->blockSignals(false);
}
//---------------------
void DrawingOptions::on_red_Specular_valueChanged(int value)
{
    MathmodRef->ui.glWidget->redSpec(value);
    if (ui.GcheckBox->isChecked())
    {
        ui.green_Specular->blockSignals(true);
        ui.green_Specular->setSliderPosition(value);
        ui.green_Specular->blockSignals(false);
        MathmodRef->ui.glWidget->greenSpec(value);
    }
    if (ui.BcheckBox->isChecked())
    {
        ui.blue_Specular->blockSignals(true);
        ui.blue_Specular->setSliderPosition(value);
        ui.blue_Specular->blockSignals(false);
        MathmodRef->ui.glWidget->blueSpec(value);
    }
    MathmodRef->ui.glWidget->InitSpecularParameters();
}

//---------------------
void DrawingOptions::on_green_Specular_valueChanged(int value)
{
    MathmodRef->ui.glWidget->greenSpec(value);
    if (ui.RcheckBox->isChecked())
    {
        ui.red_Specular->blockSignals(true);
        ui.red_Specular->setSliderPosition(value);
        ui.red_Specular->blockSignals(false);
        MathmodRef->ui.glWidget->redSpec(value);
    }
    if (ui.BcheckBox->isChecked())
    {
        ui.blue_Specular->blockSignals(true);
        ui.blue_Specular->setSliderPosition(value);
        ui.blue_Specular->blockSignals(false);
        MathmodRef->ui.glWidget->blueSpec(value);
    }
    MathmodRef->ui.glWidget->InitSpecularParameters();
}

//---------------------
void DrawingOptions::on_blue_Specular_valueChanged(int value)
{
    MathmodRef->ui.glWidget->blueSpec(value);
    if (ui.GcheckBox->isChecked())
    {
        ui.green_Specular->blockSignals(true);
        ui.green_Specular->setSliderPosition(value);
        ui.green_Specular->blockSignals(false);
        MathmodRef->ui.glWidget->greenSpec(value);
    }
    if (ui.RcheckBox->isChecked())
    {
        ui.red_Specular->blockSignals(true);
        ui.red_Specular->setSliderPosition(value);
        ui.red_Specular->blockSignals(false);
        MathmodRef->ui.glWidget->redSpec(value);
    }
    MathmodRef->ui.glWidget->InitSpecularParameters();
}

void DrawingOptions::on_transparent_Specular_valueChanged(int value)
{
    MathmodRef->ui.glWidget->transSpec(value);
}

void DrawingOptions::on_ShininessScrollBar_valueChanged(int value)
{
    MathmodRef->ui.glWidget->Shininess(value);
}

void DrawingOptions::on_ThreadNumberScrollBar_valueChanged(int value)
{
    MathmodRef->ui.glWidget->ParObjet->UpdateThredsNumber(uint(value));
    MathmodRef->ui.glWidget->IsoObjet->UpdateThredsNumber(uint(value));
    ui.ThreadgroupBox->setTitle(
        "Threads: " + QString::number(ui.ThreadNumberScrollBar->minimum()) +
        "  <  " + QString::number(value) + "  <  " +
        QString::number(ui.ThreadNumberScrollBar->maximum()));
}

void DrawingOptions::on_StopCalculationsButton_clicked()
{
    MathmodRef->ui.glWidget->IsoObjet->stopcalculations(true);
    MathmodRef->ui.glWidget->ParObjet->stopcalculations(true);
}

void DrawingOptions::on_stopButton_clicked()
{
    on_StopCalculationsButton_clicked();
}

void DrawingOptions::on_actionScripts_selection_triggered()
{
    select.show();
}

void DrawingOptions::on_actionBoundingBox_clicked()
{
    MathmodRef->ui.glWidget->boundingboxOk();
    MathmodRef->ui.glWidget->update();
}

void DrawingOptions::on_actionAnimation_Rotation_triggered()
{
    MathmodRef->ui.glWidget->anim();
}

void DrawingOptions::on_actionMorph_use_t_parameter_triggered()
{
    MathmodRef->ui.glWidget->morph();
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

void DrawingOptions::ApplypushButton_clicked()
{
    int maxisogrid = 0;
    int maxpargrid = 0;
    if ((maxisogrid = (Parameters->ui.IsoMaxGridLineEdit->text()).toInt()) !=
            Parameters->IsoMaxGrid)
    {
        Parameters->IsoMaxGrid = maxisogrid;
        MathmodRef->ui.glWidget->IsoObjet->UpdateMaxGrid(uint(maxisogrid));
        ui.xyzg->blockSignals(true);
        ui.xyzg->setMaximum(maxisogrid);
        ui.xyzg->blockSignals(false);
    }

    if ((maxpargrid = (Parameters->ui.ParMaxGridLineEdit->text()).toInt()) !=
            Parameters->ParMaxGrid)
    {
        Parameters->ParMaxGrid = maxpargrid;

        ui.linecolumn_2->blockSignals(true);
        ui.linecolumn_2->setMaximum(int(Parameters->ParMaxGrid));
        ui.linecolumn_2->blockSignals(false);

        ui.linecolumn_3->blockSignals(true);
        ui.linecolumn_3->setMaximum(int(Parameters->ParMaxGrid));
        ui.linecolumn_3->blockSignals(false);
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
            UpdateIsoModelDetailsPage(
                MathmodRef->RootObjet.CurrentParisoTreestruct[index]);
        else if (type == PAR_TYPE)
            UpdatePar3DModelDetailsPage(
                MathmodRef->RootObjet.CurrentParisoTreestruct[index]);
        else if (type == PAR_4D_TYPE)
            UpdatePar4DModelDetailsPage(
                MathmodRef->RootObjet.CurrentParisoTreestruct[index]);
    }
}

void DrawingOptions::on_ApplypushButton_clicked()
{
    int maxisogrid = 0;
    if ((maxisogrid = (ui.IsoMaxGridLineEdit->text()).toInt()) !=
            Parameters->IsoMaxGrid)
    {
        Parameters->IsoMaxGrid = maxisogrid;
        MathmodRef->ui.glWidget->IsoObjet->UpdateMaxGrid(uint(maxisogrid));
        ui.Isogroupbox->setTitle("Iso Grid/max Grid ( " +
                                 QString::number(ui.xyzg->value()) + " / " +
                                 ui.IsoMaxGridLineEdit->text() + " ) :");
        ui.xyzg->blockSignals(true);
        ui.xyzg->setMaximum(maxisogrid);
        ui.xyzg->blockSignals(false);
    }
}

void DrawingOptions::on_ApplypushButton_2_clicked()
{
    int maxpargrid = 0;
    if ((maxpargrid = (ui.ParMaxGridLineEdit->text()).toInt()) !=
            Parameters->ParMaxGrid)
    {
        Parameters->ParMaxGrid = maxpargrid;

        ui.linecolumn_2->blockSignals(true);
        ui.linecolumn_2->setMaximum(int(Parameters->ParMaxGrid));
        ui.linecolumn_2->blockSignals(false);

        ui.linecolumn_3->blockSignals(true);
        ui.linecolumn_3->setMaximum(int(Parameters->ParMaxGrid));
        ui.linecolumn_3->blockSignals(false);
    }
}

void DrawingOptions::on_ApplypushButton_3_clicked()
{
    int maxpargrid = 0;
    if ((maxpargrid = (ui.ParMaxGridLineEdit_2->text()).toInt()) !=
            Parameters->ParMaxGrid)
    {
        Parameters->ParMaxGrid = maxpargrid;

        ui.linecolumn_2->blockSignals(true);
        ui.linecolumn_2->setMaximum(int(Parameters->ParMaxGrid));
        ui.linecolumn_2->blockSignals(false);

        ui.linecolumn_3->blockSignals(true);
        ui.linecolumn_3->setMaximum(int(Parameters->ParMaxGrid));
        ui.linecolumn_3->blockSignals(false);
    }
}
