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
#include "TableMap.h"
#include "Iso3D.h"
#include "internalfunctions.cpp"
#include <QElapsedTimer>


double * Iso3D::Results;
Voxel  * Iso3D::GridVoxelVarPt;
int IsoWorkerThread::nbvariables;
extern double ComponentId;

void IsoWorkerThread::run()
{
    IsoCompute(CurrentComponent);
}
void Iso3D::run()
{
    BuildIso();
}
void IsoWorkerThread::emitMySignal()
{
    emit mySignal(signalVal);
}
void Iso3D::emitErrorSignal()
{
    emit ErrorSignal(int(messageerror));
}
void Iso3D::emitUpdateMessageSignal()
{
    emit UpdateMessageSignal(message);
}
void Iso3D::BuildIso()
{
    IsoBuild(
        &(localScene->ArrayNorVer_localPt),
        &(localScene->PolyIndices_localPt),
        &localScene->PolyNumber,
        &(localScene->VertxNumber),
        &(localScene->PolyIndices_localPtMin),
        &(localScene->NbPolygnNbVertexPtMin),
        &(localScene->NbPolygnNbVertexPtMinSize),
        &(localScene->componentsinfos));
}
IsoMasterThread::IsoMasterThread()
{
    ParisoCondition = -1;
    ImplicitFunction = "cos(x) + cos(y) + cos(z)";
    XlimitSup = "4";
    YlimitSup = "4";
    ZlimitSup = "4";
    XlimitInf   = "-4";
    YlimitInf   = "-4";
    ZlimitInf   = "-4";
    Lacunarity = 0.5;
    Gain = 1.0;
    Octaves = 4;
    Cstparser.AddConstant("pi", PI);
    componentsNumber = ConstSize = FunctSize = RgbtSize = VRgbtSize = 0;
    ImprovedNoise(); // Initialize the Noise function
}
void IsoMasterThread::IsoMasterTable()
{
    UsedFunct    = new bool[0];
    UsedFunct2   = new bool[0];
}
IsoMasterThread::~IsoMasterThread()
{
    if(ParsersAllocated)
    {
        delete[] implicitFunctionParser;
        delete[] xSupParser;
        delete[] ySupParser;
        delete[] zSupParser;
        delete[] xInfParser;
        delete[] yInfParser;
        delete[] zInfParser;
        delete[] Fct;
        delete[] ParisoConditionParser;
        delete[] VRgbtParser;
        delete[] RgbtParser;
        delete GradientParser;
        delete NoiseParser;
        ParsersAllocated = false;
    }
    delete[] UsedFunct;
    delete[] UsedFunct2;
    grid.clear();
    SliderValues.clear();
    SliderNames.clear();
    Consts.clear();
    ConstNames.clear();
    ConstValues.clear();
    Rgbts.clear();
    VRgbts.clear();
    Functs.clear();
    FunctNames.clear();
    vals.clear();
    Res.clear();
    ImportedInternalFunctions.clear();
}
IsoWorkerThread::~IsoWorkerThread()
{
    if(ParsersAllocated)
    {
        delete[] implicitFunctionParser;
        delete[] Fct;
        ParsersAllocated = false;
    }
}
IsoWorkerThread::IsoWorkerThread()
{
    XYZgrid = 40;
    stepMorph = 0;
    pace = 1.0/30.0;
    activeMorph = -1;
    nbvariables=0;
    AllComponentTraited = false;
    ParsersAllocated = false;
    StopCalculations = false;
    IsoParametersList.FunctParameters="x,y,z,t,i_indx,j_indx,k_indx,max_ijk";
    IsoParametersList.BasicFunctParameters="x,y,z,t";
    IsoParametersList.ColorFunctParameters="x,y,z,t,cmpId,indx,x_step,y_step,z_step,max_ijk,x_sup,y_sup,z_sup,x_inf,y_inf,z_inf";
}
void Iso3D::WorkerThreadCopy(IsoWorkerThread *WorkerThreadsTmp)
{
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        WorkerThreadsTmp[nbthreads].XYZgrid = masterthread->XYZgrid;
        WorkerThreadsTmp[nbthreads].ThreadIndex  = nbthreads+1;
        WorkerThreadsTmp[nbthreads].WorkerThreadsNumber = WorkerThreadsNumber;
        WorkerThreadsTmp[nbthreads].GridVal = masterthread->GridVal;
        WorkerThreadsTmp[nbthreads].AllocateStackFactor(masterthread->ptStackFactor);
    }
}
void Iso3D::UpdateThredsNumber(uint NewThreadsNumber)
{
    uint OldWorkerThreadsNumber = WorkerThreadsNumber;
    WorkerThreadsNumber = NewThreadsNumber;
    IsoWorkerThread *workerthreadstmp = new IsoWorkerThread[WorkerThreadsNumber-1];
    WorkerThreadCopy(workerthreadstmp);
    //Free old memory:
    for(uint i=0; i+1<OldWorkerThreadsNumber; i++)
        workerthreads[i].DeleteWorkerParsers();
    if(OldWorkerThreadsNumber >1)
        delete[] workerthreads;
    //Assigne newly allocated memory
    workerthreads = workerthreadstmp;
    masterthread->WorkerThreadsNumber = WorkerThreadsNumber;
}
ErrorMessage  Iso3D::IsoMorph()
{
    ErrorMessage err = masterthread->ParserIso();
    if(err.iErrorIndex < 0)
        ThreadParsersCopy();
    return err;
}
void Iso3D::InitTorsionStruct()
{
    IsoTr.TorsionX=IsoTr.TorsionY=IsoTr.TorsionZ=0.0;
    IsoTr.TorsionX="$x$";
    IsoTr.TorsionY="$y$";
    IsoTr.TorsionZ="$z$";
}
void Iso3D::InitVarParam()
{
    Isoxyz.Vx="$X$";
    Isoxyz.Vy="$Y$";
    Isoxyz.Vz="$Z$";
    Isoxyz.Previousaction=NOACTION;
}
void Iso3D::InitScaleStruct()
{
    IsoSc.ScalX="$x$";
    IsoSc.ScalY="$y$";
    IsoSc.ScalZ="$z$";
    IsoSc.Sx=IsoSc.Sy=IsoSc.Sz=1.0;
}
void  Iso3D::InitGeneratorStruct()
{
    InitTorsionStruct();
}
ErrorMessage  Iso3D::AddThickness()
{
    ErrorMessage NoError;
    QString T = IsoTh.ThExpression;
    // masterthread parsing
    for(uint i=0; i<masterthread->componentsNumber; i++)
    {
        QString I=QString::number(i);
        QString fct("psh((0),(FFFxyz"+I+"(x+(1/1000000),y,z,t,i_indx,j_indx,k_indx,max_ijk)-FFFxyz"+I+"(x,y,z,t,i_indx,j_indx,k_indx,max_ijk))/(1/1000000))"
                                                                                                              "*psh((1),(FFFxyz"+I+"(x,y+(1/1000000),z,t,i_indx,j_indx,k_indx,max_ijk)-FFFxyz"+I+"(x,y,z,t,i_indx,j_indx,k_indx,max_ijk))/(1/1000000))"
                                                                                            "*psh((2),(FFFxyz"+I+"(x,y,z+(1/1000000),t,i_indx,j_indx,k_indx,max_ijk)-FFFxyz"+I+"(x,y,z,t,i_indx,j_indx,k_indx,max_ijk))/(1/1000000))"
                                                                                            "*psh((3),("+T+"/sqrt(csd(0)*csd(0)+ csd(1)*csd(1)+ csd(2)*csd(2))))");
        if(IsoTh.UpperSurf)  fct+= "*(FFFxyz"+I+"(x+csd(0)*csd(3),y+csd(1)*csd(3),z+csd(2)*csd(3),t,i_indx,j_indx,k_indx,max_ijk))";
        if(IsoTh.BottomSurf)  fct+= "*(FFFxyz"+I+"(x-csd(0)*csd(3),y-csd(1)*csd(3),z-csd(2)*csd(3),t,i_indx,j_indx,k_indx,max_ijk))";
        if(IsoTh.OriginalSurf)
        {
            if(IsoTh.UpperSurf || IsoTh.BottomSurf) fct+= "*(FFFxyz"+I+"(x,y,z,t,i_indx,j_indx,k_indx,max_ijk))";
            else fct = "(FFFxyz"+I+"(x,y,z,t,i_indx,j_indx,k_indx,max_ijk))";
        }
        std::string str = fct.toStdString();
        const char* p = str.c_str();
        if ((masterthread->stdError.iErrorIndex = masterthread->implicitFunctionParser[i].Parse(p,"x,y,z,t,i_indx,j_indx,k_indx,max_ijk")) >= 0)
        {
            masterthread->stdError.strError = masterthread->ImplicitStructs[i].fxyz;
            return masterthread->stdError;
        }
    }
    // workerthreads parsing
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint index=0; index< masterthread->componentsNumber; index++)
        {
            QString I=QString::number(index);
            QString fct("psh((0),(FFFxyz"+I+"(x+(1/1000000),y,z,t,i_indx,j_indx,k_indx,max_ijk)-FFFxyz"+I+"(x,y,z,t,i_indx,j_indx,k_indx,max_ijk))/(1/1000000))"
                                                                                                                  "*psh((1),(FFFxyz"+I+"(x,y+(1/1000000),z,t,i_indx,j_indx,k_indx,max_ijk)-FFFxyz"+I+"(x,y,z,t,i_indx,j_indx,k_indx,max_ijk))/(1/1000000))"
                                                                                                "*psh((2),(FFFxyz"+I+"(x,y,z+(1/1000000),t,i_indx,j_indx,k_indx,max_ijk)-FFFxyz"+I+"(x,y,z,t,i_indx,j_indx,k_indx,max_ijk))/(1/1000000))"
                                                                                                "*psh((3),("+T+"/sqrt(csd(0)*csd(0)+ csd(1)*csd(1)+ csd(2)*csd(2))))");
            if(IsoTh.UpperSurf)  fct+= "*(FFFxyz"+I+"(x+csd(0)*csd(3),y+csd(1)*csd(3),z+csd(2)*csd(3),t,i_indx,j_indx,k_indx,max_ijk))";
            if(IsoTh.BottomSurf)  fct+= "*(FFFxyz"+I+"(x-csd(0)*csd(3),y-csd(1)*csd(3),z-csd(2)*csd(3),t,i_indx,j_indx,k_indx,max_ijk))";
            if(IsoTh.OriginalSurf)
            {
                if(IsoTh.UpperSurf || IsoTh.BottomSurf) fct+= "*(FFFxyz"+I+"(x,y,z,t,i_indx,j_indx,k_indx,max_ijk))";
                else fct = "(FFFxyz"+I+"(x,y,z,t,i_indx,j_indx,k_indx,max_ijk))";
            }
            std::string str = fct.toStdString();
            const char* p = str.c_str();
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].implicitFunctionParser[index].Parse(p,"x,y,z,t,i_indx,j_indx,k_indx,max_ijk")) >= 0)
            {
                masterthread->stdError.strError = masterthread->ImplicitStructs[index].fxyz;
                return masterthread->stdError;
            }
        }
    }
    return NoError;
}
ErrorMessage  Iso3D::ScaleIso()
{
    ErrorMessage NoError;
    // masterthread parsing
    for(uint i=0; i<masterthread->componentsNumber; i++)
    {
        QString Vx = Isoxyz.Vx;
        Vx.replace("$X$",IsoSc.ScalX);
        Vx.replace("$Y$",IsoSc.ScalY);
        Vx.replace("$Z$",IsoSc.ScalZ);
        Vx.replace("$","");
        QString Vy = Isoxyz.Vy;
        Vy.replace("$X$",IsoSc.ScalX);
        Vy.replace("$Y$",IsoSc.ScalY);
        Vy.replace("$Z$",IsoSc.ScalZ);
        Vy.replace("$","");
        QString Vz = Isoxyz.Vz;
        Vz.replace("$X$",IsoSc.ScalX);
        Vz.replace("$Y$",IsoSc.ScalY);
        Vz.replace("$Z$",IsoSc.ScalZ);
        Vz.replace("$","");
        std::string str;
        str = ("FFFxyz"+QString::number(i)+"("+Vx+","+Vy+","+Vz+",t,i_indx,j_indx,k_indx,max_ijk)").toStdString() ;
        const char* p = str.c_str();
        if ((masterthread->stdError.iErrorIndex = masterthread->implicitFunctionParser[i].Parse(p,"x,y,z,t,i_indx,j_indx,k_indx,max_ijk")) >= 0)
        {
            masterthread->stdError.strError = masterthread->ImplicitStructs[i].fxyz;
            return masterthread->stdError;
        }
    }
    // workerthreads parsing
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint index=0; index< masterthread->componentsNumber; index++)
        {
            QString Vx = Isoxyz.Vx;
            Vx.replace("$X$",IsoSc.ScalX);
            Vx.replace("$Y$",IsoSc.ScalY);
            Vx.replace("$Z$",IsoSc.ScalZ);
            Vx.replace("$","");
            QString Vy = Isoxyz.Vy;
            Vy.replace("$X$",IsoSc.ScalX);
            Vy.replace("$Y$",IsoSc.ScalY);
            Vy.replace("$Z$",IsoSc.ScalZ);
            Vy.replace("$","");
            QString Vz = Isoxyz.Vz;
            Vz.replace("$X$",IsoSc.ScalX);
            Vz.replace("$Y$",IsoSc.ScalY);
            Vz.replace("$Z$",IsoSc.ScalZ);
            Vz.replace("$","");
            std::string str;
            str = ("FFFxyz"+QString::number(index)+"("+Vx+","+Vy+","+Vz+",t,i_indx,j_indx,k_indx,max_ijk)").toStdString() ;
            const char* p = str.c_str();
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].implicitFunctionParser[index].Parse(p,"x,y,z,t,i_indx,j_indx,k_indx,max_ijk")) >= 0)
            {
                masterthread->stdError.strError = masterthread->ImplicitStructs[index].fxyz;
                return masterthread->stdError;
            }
        }
    }
    return NoError;
}
ErrorMessage  Iso3D::IsoTorsion()
{
    ErrorMessage NoError;
    // masterthread parsing
    for(uint i=0; i<masterthread->componentsNumber; i++)
    {
        QString Vx = Isoxyz.Vx;
        Vx.replace("$X$",IsoTr.TorsionX);
        Vx.replace("$Y$",IsoTr.TorsionY);
        Vx.replace("$Z$",IsoTr.TorsionZ);
        Vx.replace("$","");
        QString Vy = Isoxyz.Vy;
        Vy.replace("$X$",IsoTr.TorsionX);
        Vy.replace("$Y$",IsoTr.TorsionY);
        Vy.replace("$Z$",IsoTr.TorsionZ);
        Vy.replace("$","");
        QString Vz = Isoxyz.Vz;
        Vz.replace("$X$",IsoTr.TorsionX);
        Vz.replace("$Y$",IsoTr.TorsionY);
        Vz.replace("$Z$",IsoTr.TorsionZ);
        Vz.replace("$","");
        std::string str = ("FFFxyz"+QString::number(i)+"("+Vx+","+Vy+","+Vz+",t,i_indx,j_indx,k_indx,max_ijk)").toStdString();
        const char* p = str.c_str();
        if ((masterthread->stdError.iErrorIndex = masterthread->implicitFunctionParser[i].Parse(p,"x,y,z,t,i_indx,j_indx,k_indx,max_ijk")) >= 0)
        {
            masterthread->stdError.strError = masterthread->ImplicitStructs[i].fxyz;
            return masterthread->stdError;
        }
    }
    // workerthreads parsing
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint index=0; index< masterthread->componentsNumber; index++)
        {
            QString Vx = Isoxyz.Vx;
            Vx.replace("$X$",IsoTr.TorsionX);
            Vx.replace("$Y$",IsoTr.TorsionY);
            Vx.replace("$Z$",IsoTr.TorsionZ);
            Vx.replace("$","");
            QString Vy = Isoxyz.Vy;
            Vy.replace("$X$",IsoTr.TorsionX);
            Vy.replace("$Y$",IsoTr.TorsionY);
            Vy.replace("$Z$",IsoTr.TorsionZ);
            Vy.replace("$","");
            QString Vz = Isoxyz.Vz;
            Vz.replace("$X$",IsoTr.TorsionX);
            Vz.replace("$Y$",IsoTr.TorsionY);
            Vz.replace("$Z$",IsoTr.TorsionZ);
            Vz.replace("$","");
            std::string str = ("FFFxyz"+QString::number(index)+"("+Vx+","+Vy+","+Vz+",t,i_indx,j_indx,k_indx,max_ijk)").toStdString();
            const char* p = str.c_str();
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].implicitFunctionParser[index].Parse(p, "x,y,z,t,i_indx,j_indx,k_indx,max_ijk")) >= 0)
            {
                masterthread->stdError.strError = masterthread->ImplicitStructs[index].fxyz;
                return masterthread->stdError;
            }
        }
    }
    return NoError;
}
ErrorMessage Iso3D::ThreadParsersCopy()
{
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        workerthreads[nbthreads].xLocal2.clear();
        workerthreads[nbthreads].xLocal2 = masterthread->xLocal2;
        workerthreads[nbthreads].yLocal2.clear();
        workerthreads[nbthreads].yLocal2 = masterthread->yLocal2;
        workerthreads[nbthreads].zLocal2.clear();
        workerthreads[nbthreads].zLocal2 = masterthread->zLocal2;
        workerthreads[nbthreads].activeMorph = masterthread->activeMorph;
        workerthreads[nbthreads].AllComponentTraited = masterthread->AllComponentTraited;
        workerthreads[nbthreads].XYZgrid = masterthread->XYZgrid;
        workerthreads[nbthreads].GridVal = masterthread->GridVal;
    }
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
        workerthreads[nbthreads].DeleteWorkerParsers();
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
        workerthreads[nbthreads].AllocateParsersForWorkerThread(masterthread->componentsNumber, masterthread->FunctSize);
    return(parse_expression2());
}
ErrorMessage  Iso3D::parse_expression2()
{
    ErrorMessage NodError;
    // Functions :
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint ij=0; ij<masterthread->FunctSize; ij++)
        {
            workerthreads[nbthreads].Fct[ij].AddConstant("pi", PI);
            workerthreads[nbthreads].Fct[ij].AddConstant("ThreadId", workerthreads[nbthreads].ThreadIndex);
        }
        for(uint ii=0; ii<masterthread->FunctSize; ii++)
        {
            for(uint jj=0; jj<masterthread->ConstSize; jj++)
            {
                workerthreads[nbthreads].Fct[ii].AddConstant(masterthread->ConstNames[jj], masterthread->ConstValues[jj]);
            }
            //Add predefined constatnts:
            for(uint kk=0; kk<masterthread->Nb_Sliders; kk++)
            {
                workerthreads[nbthreads].Fct[ii].AddConstant(masterthread->SliderNames[kk], masterthread->SliderValues[kk]);
            }
        }
        for(uint ii=0; ii<masterthread->FunctSize; ii++)
        {
            for (uint m=0; m<masterthread->ImportedInternalFunctions.size(); m++)
                workerthreads[nbthreads].Fct[ii].AddFunction(masterthread->ImportedInternalFunctions[m].name,
                                                             masterthread->ImportedInternalFunctions[m].ptr,
                                                             masterthread->ImportedInternalFunctions[m].param);
            for(uint jj=0; jj<ii; jj++)
                if(masterthread->UsedFunct2[ii*masterthread->FunctSize+jj])
                    workerthreads[nbthreads].Fct[ii].AddFunction(masterthread->FunctNames[jj], workerthreads[nbthreads].Fct[jj]);
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].Fct[ii].Parse(masterthread->Functs[ii],masterthread->IsoParametersList.BasicFunctParameters)) >= 0)
            {
                masterthread->stdError.strError = masterthread->Functs[ii];
                masterthread->stdError.ErrorType = workerthreads[nbthreads].Fct[ii].ErrorMsg();
                return masterthread->stdError;
            }
            workerthreads[nbthreads].Fct[ii].AllocateStackMemory(masterthread->StackFactor, masterthread->nbvariables);
        }
    }
    //Add defined constantes:
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint i=0; i<masterthread->componentsNumber; i++)
        {
            workerthreads[nbthreads].implicitFunctionParser[i].AddConstant("pi", PI);
            workerthreads[nbthreads].implicitFunctionParser[i].AddConstant("ThreadId", workerthreads[nbthreads].ThreadIndex);
            for(uint j=0; j<masterthread->ConstSize; j++)
            {
                workerthreads[nbthreads].implicitFunctionParser[i].AddConstant(masterthread->ConstNames[j], masterthread->ConstValues[j]);
            }
            //Add predefined sliders constatnts:
            for(uint k=0; k<masterthread->Nb_Sliders; k++)
            {
                workerthreads[nbthreads].implicitFunctionParser[i].AddConstant(masterthread->SliderNames[k], masterthread->SliderValues[k]);
            }
        }
    }
    // Add defined functions :
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint i=0; i<masterthread->componentsNumber; i++)
        {
            for (uint m=0; m<masterthread->ImportedInternalFunctions.size(); m++)
                workerthreads[nbthreads].implicitFunctionParser[i].AddFunction(
                    masterthread->ImportedInternalFunctions[m].name,
                    masterthread->ImportedInternalFunctions[m].ptr,
                    masterthread->ImportedInternalFunctions[m].param);
            for(uint j=0; j<masterthread->FunctSize; j++)
            {
                if(masterthread->UsedFunct[i*masterthread->FunctSize+j])
                {
                    workerthreads[nbthreads].implicitFunctionParser[i].AddFunction(masterthread->FunctNames[j], workerthreads[nbthreads].Fct[j]);
                }
            }
        }
    }
    // Final step: parsing
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for(uint index=0; index< masterthread->componentsNumber; index++)
        {
            if ((masterthread->stdError.iErrorIndex = workerthreads[nbthreads].implicitFunctionParser[index].Parse(masterthread->ImplicitStructs[index].fxyz, masterthread->IsoParametersList.FunctParameters)) >= 0)
            {
                masterthread->stdError.strError = masterthread->ImplicitStructs[index].fxyz;
                masterthread->stdError.ErrorType = workerthreads[nbthreads].implicitFunctionParser[index].ErrorMsg();
                return masterthread->stdError;
            }
        }
    }
    return NodError;
}
Iso3D::Iso3D( uint nbThreads,
              uint nbGrid,
              int *pt)
{
    NbTriangleIsoSurface = 0;
    NbPointIsoMap = 0;
    WorkerThreadsNumber = nbThreads;
    masterthread  = new IsoMasterThread();
    masterthread->AllocateStackFactor(pt);
    masterthread->IsoMasterTable();
    workerthreads = new IsoWorkerThread[WorkerThreadsNumber-1];
    masterthread->XYZgrid = nbGrid;
    masterthread->GridVal = nbGrid;
    masterthread->ThreadIndex = 0;
    masterthread->WorkerThreadsNumber = WorkerThreadsNumber;
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        workerthreads[nbthreads].XYZgrid = nbGrid;
        workerthreads[nbthreads].GridVal = nbGrid;
        workerthreads[nbthreads].ThreadIndex = nbthreads+1;
        workerthreads[nbthreads].WorkerThreadsNumber = WorkerThreadsNumber;
        workerthreads[nbthreads].AllocateStackFactor(pt);
    }
}
uint IsoMasterThread::HowManyVariables(std::string NewVariables, uint type)
{
    std::string tmp, tmp2,tmp3;
    size_t position =0, jpos;
    uint Nb_variables =0;
    while( NewVariables!= "")
    {
        if((position = NewVariables.find(";")) != std::string::npos)
        {
            tmp = NewVariables;
            tmp2= tmp3 = (tmp.substr(0,position));
            jpos = tmp2.find("=");
            if(type == 1)
            {
                ConstNames.push_back(tmp2.substr(0,jpos));
                Consts.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 2)
            {
                FunctNames.push_back(tmp2.substr(0,jpos));
                Functs.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 3)
            {
                Rgbts.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 4)
            {
                VRgbts.push_back(tmp3.substr(jpos+1,position-1));
            }
            tmp2 = NewVariables.substr(position+1, NewVariables.length()-1);
            NewVariables = tmp2;
            Nb_variables++;
        }
        else
        {
            tmp = tmp2 = tmp3 = NewVariables;
            jpos = tmp2.find("=");
            if(type == 1)
            {
                ConstNames.push_back(tmp2.substr(0, jpos));
                Consts.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 2)
            {
                FunctNames.push_back(tmp2.substr(0, jpos));
                Functs.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 3)
            {
                Rgbts.push_back(tmp3.substr(jpos+1,position-1));
            }
            else if(type == 4)
            {
                VRgbts.push_back(tmp3.substr(jpos+1,position-1));
            }
            NewVariables = "";
            Nb_variables++;
        }
    }
    return Nb_variables;
}
uint IsoMasterThread::HowManyIsosurface(std::string ImplicitFct, uint type)
{
    std::string tmp, tmp2;
    size_t position =0;
    uint Nb_implicitfunction =0;
    if(type ==0)
    {
        ImplicitStructs[0].fxyz = ImplicitFct;
        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) !=std::string::npos   )
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].fxyz = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].fxyz  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 1)  //xmin
    {
        ImplicitStructs[0].xmin = ImplicitFct;
        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].xmin = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].xmin  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 2)  //xmax
    {
        ImplicitStructs[0].xmax = ImplicitFct;
        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].xmax = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].xmax  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 3) //ymin
    {
        ImplicitStructs[0].ymin = ImplicitFct;
        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].ymin = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].ymin  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 4) //ymax
    {
        ImplicitStructs[0].ymax = ImplicitFct;
        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].ymax = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].ymax  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 5) //zmin
    {
        ImplicitStructs[0].zmin = ImplicitFct;
        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].zmin = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].zmin  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 6) //zmax
    {
        ImplicitStructs[0].zmax = ImplicitFct;
        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].zmax = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].zmax  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    else if(type == 8) //Cnd
    {
        ImplicitStructs[0].cnd = ImplicitFct;
        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) != std::string::npos)
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].cnd = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].cnd  = ImplicitFct;
                ImplicitFct ="";
            }
        }
        return Nb_implicitfunction;
    }
    return 0;
}
void Iso3D::ReinitVarTablesWhenMorphActiv(uint IsoIndex)
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    const uint limitX = masterthread->XYZgrid, limitY = masterthread->XYZgrid, limitZ = masterthread->XYZgrid;
    uint maxgridval = masterthread->GridVal;
    vals[3]         = masterthread->stepMorph;

    masterthread->xLocal2[IsoIndex*maxgridval]=(masterthread->x_Inf[IsoIndex]=masterthread->xInfParser[IsoIndex].Eval(vals));
    masterthread->yLocal2[IsoIndex*maxgridval]=(masterthread->y_Inf[IsoIndex]=masterthread->yInfParser[IsoIndex].Eval(vals));
    masterthread->zLocal2[IsoIndex*maxgridval]=(masterthread->z_Inf[IsoIndex]=masterthread->zInfParser[IsoIndex].Eval(vals));
    masterthread->x_Step[IsoIndex] = (limitX-1)>0 ? ((masterthread->x_Sup[IsoIndex]=masterthread->xSupParser[IsoIndex].Eval(vals)) - masterthread->xLocal2[IsoIndex*maxgridval])/(limitX-1) : 0;
    masterthread->y_Step[IsoIndex] = (limitY-1)>0 ? ((masterthread->y_Sup[IsoIndex]=masterthread->ySupParser[IsoIndex].Eval(vals)) - masterthread->yLocal2[IsoIndex*maxgridval])/(limitY-1) : 0;
    masterthread->z_Step[IsoIndex] = (limitZ-1)>0 ? ((masterthread->z_Sup[IsoIndex]=masterthread->zSupParser[IsoIndex].Eval(vals)) - masterthread->zLocal2[IsoIndex*maxgridval])/(limitZ-1) : 0;
    for (uint i= 1; i < limitX; i++)
        masterthread->xLocal2[IsoIndex*maxgridval+i] = masterthread->xLocal2[IsoIndex*maxgridval+i-1] + masterthread->x_Step[IsoIndex];
    for (uint j= 1; j < limitY; j++)
        masterthread->yLocal2[IsoIndex*maxgridval+j] = masterthread->yLocal2[IsoIndex*maxgridval+j-1] + masterthread->y_Step[IsoIndex];
    for (uint k= 1; k < limitZ; k++)
        masterthread->zLocal2[IsoIndex*maxgridval+k] = masterthread->zLocal2[IsoIndex*maxgridval+k-1] + masterthread->z_Step[IsoIndex];
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        for (uint k= 0; k < limitX; k++)
            workerthreads[nbthreads].xLocal2[IsoIndex*maxgridval+k] = masterthread->xLocal2[IsoIndex*maxgridval+k];
        for (uint k= 0; k < limitY; k++)
            workerthreads[nbthreads].yLocal2[IsoIndex*maxgridval+k] = masterthread->yLocal2[IsoIndex*maxgridval+k];
        for (uint k= 0; k < limitZ; k++)
            workerthreads[nbthreads].zLocal2[IsoIndex*maxgridval+k] = masterthread->zLocal2[IsoIndex*maxgridval+k];
    }
}
void IsoWorkerThread::AllocateStackFactor(int *pt)
{
    ptStackFactor = pt;
    OrignbX=uint(pt[0]);
    OrignbY=uint(pt[1]);
    OrignbZ=uint(pt[2]);
    StackFactor=OrignbX*OrignbY*OrignbZ;
    vals.resize((count_comma(IsoParametersList.FunctParameters)+1)*StackFactor); // NbParameters=8 because we have "x,y,z,t,i_indx,j_indx,k_indx,max_ijk"
    Res.resize(StackFactor);
}
void IsoWorkerThread::VoxelEvaluation(uint IsoIndex)
{
    const uint limitY = XYZgrid, limitZ = XYZgrid;
    uint id=0;
    uint nbX=OrignbX, nbY=OrignbY, nbZ=OrignbZ;
    uint nbstack;
    uint Iindice=0, Jindice=0, Kindice=0 ;
    int PreviousSignal=0;
    uint NbParameters = count_comma(IsoParametersList.FunctParameters)+1;

    vals[3]    = stepMorph;
    uint taille=0;
    iStart = 0;
    iFinish = 0;
    for(uint i=0; i<XYZgrid; i++)
    {
        if((i% (WorkerThreadsNumber))  == ThreadIndex )
            taille += 1;
        if(ThreadIndex <= (i% (WorkerThreadsNumber)))
            iFinish  += 1;
    }
    iStart = iFinish - taille;
    uint remX= (iFinish-iStart)%nbX;
    uint remY= limitY%nbY;
    uint remZ= limitZ%nbZ;
    uint Totalpoints=(iFinish-iStart)*limitY*limitZ;
    implicitFunctionParser[IsoIndex].AllocateStackMemory(StackFactor, nbvariables);
    for(uint i=iStart; i<iFinish; i+=nbX )
    {
        Iindice = i;
        nbY=OrignbY;
        if((remX>0) && ((Iindice+remX)==(iFinish)))
        {
            nbX = remX;
            i= iFinish;
        }
        for(uint j=0; j<limitY; j+=nbY)
        {
            Jindice = j;
            nbZ=OrignbZ;
            if((remY>0) && ((Jindice+remY)==(limitY)))
            {
                nbY = remY;
                j= limitY;
            }
            for(uint k=0; k<limitZ; k+=nbZ)
            {
                Kindice = k;
                if((remZ>0) && ((Kindice+remZ)==(limitZ)))
                {
                    nbZ = remZ;
                    k= limitZ;
                }
                nbstack = nbX*nbY*nbZ;
                // X, Y and Z arrays construction:
                uint l=0;
                for(uint ii=0; ii<nbX; ii++)
                    for(uint jj=0; jj<nbY; jj++)
                        for(uint kk=0; kk<nbZ; kk++)
                        {
                            vals[l*NbParameters  ]= xLocal2[IsoIndex*GridVal+Iindice+ii];
                            vals[l*NbParameters+1]= yLocal2[IsoIndex*GridVal+Jindice+jj];
                            vals[l*NbParameters+2]= zLocal2[IsoIndex*GridVal+Kindice+kk];
                            vals[l*NbParameters+3]= stepMorph;
                            vals[l*NbParameters+4]= Iindice+ii;
                            vals[l*NbParameters+5]= Jindice+jj;
                            vals[l*NbParameters+6]= Kindice+kk;
                            vals[l*NbParameters+7]= GridVal;
                            l++;
                        }
                double res = implicitFunctionParser[IsoIndex].Eval2(&(vals[0]), NbParameters, &(Res[0]), nbstack);
                if( abs(res - IF_FUNCT_ERROR) == 0.0)
                {
                    for(uint l=0; l<nbstack; l++)
                        Res[l] = implicitFunctionParser[IsoIndex].Eval(&(vals[l*NbParameters]));
                }
                else if( abs(res - DIVISION_BY_ZERO) == 0.0 || abs(res - VAR_OVERFLOW) == 0.0)
                {
                    StopCalculations = true;
                }
                if(StopCalculations)
                {
                    return;
                }
                uint p=0;
                uint sect=0;
                for(uint ii=0; ii<nbX; ii++)
                    for(uint jj=0; jj<nbY; jj++)
                        for(uint kk=0; kk<nbZ; kk++)
                        {
                            sect= (Iindice+ii)*GridVal*GridVal+ (Jindice+jj)*GridVal + (Kindice+kk);
                            Iso3D::Results[sect] = Res[p];
                            Iso3D::GridVoxelVarPt[sect].Signature   = 0; // Signature initialisation
                            Iso3D::GridVoxelVarPt[sect].NbEdgePoint = 0; // No EdgePoint yet!
                            p++;
                        }
                //Signal emission:
                id+=nbstack;
                if(ThreadIndex == 0 && activeMorph != 1)
                {
                    signalVal = int((id*100)/Totalpoints);
                    if((signalVal - PreviousSignal) > 1 || id==Totalpoints)
                    {
                        PreviousSignal = signalVal;
                        emitMySignal();
                    }
                }
            }
        }
    }
}
void Iso3D::ConstructIsoNormale(uint idx)
{
    float val1, val2, val3, val4, val5, val6,
          pt1_x, pt1_y, pt1_z,
          pt2_x, pt2_y, pt2_z,
          pt3_x, pt3_y, pt3_z,
          scalar, n1, n2, n3;
    uint ThreeTimesI, IndexFirstPoint, IndexSecondPoint, IndexThirdPoint;
    NormOriginaltmpVector.resize(NormOriginaltmpVector.size()+ 3*NbTriangleIsoSurface);
    for(uint i = 0; i<NbTriangleIsoSurface; ++i)
    {
        ThreeTimesI      = i*3;
        IndexFirstPoint  = 10*IndexPolyTabVector[ThreeTimesI  +3*idx] + 7;
        IndexSecondPoint = 10*IndexPolyTabVector[ThreeTimesI+1+3*idx] + 7;
        IndexThirdPoint  = 10*IndexPolyTabVector[ThreeTimesI+2+3*idx] + 7;
        pt1_x= NormVertexTabVector[IndexFirstPoint  ];
        pt1_y= NormVertexTabVector[IndexFirstPoint+1];
        pt1_z= NormVertexTabVector[IndexFirstPoint+2];
        pt2_x= NormVertexTabVector[IndexSecondPoint  ];
        pt2_y= NormVertexTabVector[IndexSecondPoint+1];
        pt2_z= NormVertexTabVector[IndexSecondPoint+2];
        pt3_x= NormVertexTabVector[IndexThirdPoint   ];
        pt3_y= NormVertexTabVector[IndexThirdPoint+1 ];
        pt3_z= NormVertexTabVector[IndexThirdPoint+2 ];
        val1 = pt2_y - pt1_y;
        val2 = pt3_z - pt1_z;
        val3 = pt2_z - pt1_z;
        val4 = pt3_y - pt1_y;
        val5 = pt3_x - pt1_x;
        val6 = pt2_x - pt1_x;
        n1 = (val1*val2 - val3*val4);
        n2 = (val3*val5 - val6*val2);
        n3 = (val6*val4 - val1*val5);
        scalar = float(sqrt(n1*n1+n2*n2+n3*n3));
        if(scalar < float(0.0000001))  scalar  = float(0.0000001);
        (NormOriginaltmpVector[ThreeTimesI  ] = n1/scalar);
        (NormOriginaltmpVector[ThreeTimesI+1] = n2/scalar);
        (NormOriginaltmpVector[ThreeTimesI+2] = n3/scalar);
    }
}
void Iso3D::SaveIsoGLMap(uint indx)
{
    uint IndexFirstPoint, IndexSecondPoint, IndexThirdPoint, ThreeTimesI;
    double scalar;
/// Recalculate the normals so we have one for each Point (like Pov Mesh) :
    for (uint i=0; i < NbPointIsoMap ; i++)
    {
        ThreeTimesI = 10*i  + 4;
        NormVertexTabVector[ 10*NbVertexTmp +ThreeTimesI  ] = 0;
        NormVertexTabVector[ 10*NbVertexTmp +ThreeTimesI+1] = 0;
        NormVertexTabVector[ 10*NbVertexTmp +ThreeTimesI+2] = 0;
    }
    for(uint i = 0; i<NbTriangleIsoSurface; ++i)
    {
        ThreeTimesI   = i*3;
        IndexFirstPoint  = 10*IndexPolyTabVector[ThreeTimesI  +3*indx] + 4;
        IndexSecondPoint = 10*IndexPolyTabVector[ThreeTimesI+1+3*indx] + 4;
        IndexThirdPoint  = 10*IndexPolyTabVector[ThreeTimesI+2+3*indx] + 4;
        NormVertexTabVector[IndexFirstPoint  ] += NormOriginaltmpVector[ThreeTimesI  ];
        NormVertexTabVector[IndexFirstPoint+1] += NormOriginaltmpVector[ThreeTimesI+1];
        NormVertexTabVector[IndexFirstPoint+2] += NormOriginaltmpVector[ThreeTimesI+2];
        NormVertexTabVector[IndexSecondPoint  ] += NormOriginaltmpVector[ThreeTimesI  ];
        NormVertexTabVector[IndexSecondPoint+1] += NormOriginaltmpVector[ThreeTimesI+1];
        NormVertexTabVector[IndexSecondPoint+2] += NormOriginaltmpVector[ThreeTimesI+2];
        NormVertexTabVector[IndexThirdPoint  ]  += NormOriginaltmpVector[ThreeTimesI  ];
        NormVertexTabVector[IndexThirdPoint+1]  += NormOriginaltmpVector[ThreeTimesI+1];
        NormVertexTabVector[IndexThirdPoint+2]  += NormOriginaltmpVector[ThreeTimesI+2];
    }
/// Normalisation
    uint idx;
    for (uint i=0; i < NbPointIsoMap  ; i++)
    {
        idx = 10*i + 4;
        scalar = double(sqrt((NormVertexTabVector[idx  ]*NormVertexTabVector[idx  ]) +
                             (NormVertexTabVector[idx+1]*NormVertexTabVector[idx+1]) +
                             (NormVertexTabVector[idx+2]*NormVertexTabVector[idx+2])));
        if(scalar < 0.0000001)  scalar = 0.0000001;
        NormVertexTabVector[idx  ] /= float(scalar);
        NormVertexTabVector[idx+1] /= float(scalar);
        NormVertexTabVector[idx+2] /= float(scalar);
    }
}
ErrorMessage IsoMasterThread::ParserIso()
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    initparser();
    //Evaluates defined constantes:
    if(constnotnull)
    {
        ConstSize = HowManyVariables(Const, 1);
        for(uint j=0; j<ConstSize; j++)
        {
            if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u")) >= 0)
            {
                stdError.strError = Consts[j];
                stdError.ErrorType = Cstparser.ErrorMsg();
                return stdError;
            }
            ConstValues.push_back(Cstparser.Eval(&vals[3]));
            Cstparser.AddConstant(ConstNames[j], ConstValues[j]);
        }
    }
    else
    {
        ConstSize = 0;
    }
    if(functnotnull)
    {
        FunctSize = HowManyVariables(Funct, 2);
        for(uint i=0; i<FunctSize; i++)
        {
            for(uint j=0; j<ConstSize; j++)
            {
                Fct[i].AddConstant(ConstNames[j], ConstValues[j]);
            }
            //Add predefined constatnts:
            for(uint k=0; k<Nb_Sliders; k++)
            {
                Fct[i].AddConstant(SliderNames[k], SliderValues[k]);
            }
        }
        for(uint i=0; i<FunctSize; i++)
        {
            for(uint j=0; j<i; j++)
                if( (UsedFunct2[i*FunctSize+j]=(Functs[i].find(FunctNames[j]) != std::string::npos)))
                    Fct[i].AddFunction(FunctNames[j], Fct[j]);
            if ((stdError.iErrorIndex = Fct[i].Parse(Functs[i],IsoParametersList.BasicFunctParameters))>=0)
            {
                stdError.strError = Functs[i];
                stdError.ErrorType = Fct[i].ErrorMsg();
                return stdError;
            }
            Fct[i].AllocateStackMemory(StackFactor, nbvariables);
        }
    }
    else
    {
        FunctSize =0;
    }
    if(RGBT_STR!= "")
    {
        RgbtSize = HowManyVariables(RGBT_STR, 3);
        for(uint i=0; i<RgbtSize; i++)
        {
            for(uint j=0; j<ConstSize; j++)
            {
                RgbtParser[i].AddConstant(ConstNames[j], ConstValues[j]);
                RgbtParser[i].AddConstant("Lacunarity", double(Lacunarity));
                RgbtParser[i].AddConstant("Gain", double(Gain));
                RgbtParser[i].AddConstant("Octaves", double(Octaves));
                for (uint m=0; m<ImportedInternalFunctions.size(); m++)
                    RgbtParser[i].AddFunction(ImportedInternalFunctions[m].name,
                                              ImportedInternalFunctions[m].ptr,
                                              ImportedInternalFunctions[m].param);
            }
            //Add predefined constatnts:
            for(uint k=0; k<Nb_Sliders; k++)
            {
                RgbtParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            }
        }
    }
    else
    {
        RgbtSize =0;
    }
    //For Solid Texture :
    if(VRGBT_STR != "")
    {
        VRgbtSize = HowManyVariables(VRGBT_STR, 4);
        for(uint j=0; j<ConstSize; j++)
        {
            GradientParser->AddConstant(ConstNames[j], ConstValues[j]);
            //Add predefined constatnts:
            for(uint k=0; k<Nb_Sliders; k++)
                GradientParser->AddConstant(SliderNames[k], SliderValues[k]);
        }
        GradientParser->AddConstant("Lacunarity", Lacunarity);
        GradientParser->AddConstant("Gain", Gain);
        GradientParser->AddConstant("Octaves", Octaves);
        for (uint m=0; m<ImportedInternalFunctions.size(); m++)
            GradientParser->AddFunction(ImportedInternalFunctions[m].name,
                                        ImportedInternalFunctions[m].ptr,
                                        ImportedInternalFunctions[m].param);
        for(uint i=0; i<VRgbtSize; i++)
        {
            for(uint j=0; j<ConstSize; j++)
            {
                VRgbtParser[i].AddConstant(ConstNames[j], ConstValues[j]);
                //Add predefined constatnts:
                for(uint k=0; k<Nb_Sliders; k++)
                    VRgbtParser[i].AddConstant(SliderNames[k], SliderValues[k]);
                VRgbtParser[i].AddConstant("Lacunarity", Lacunarity);
                VRgbtParser[i].AddConstant("Gain", Gain);
                VRgbtParser[i].AddConstant("Octaves", Octaves);
                for (uint m=0; m<ImportedInternalFunctions.size(); m++)
                    VRgbtParser[i].AddFunction(ImportedInternalFunctions[m].name,
                                               ImportedInternalFunctions[m].ptr,
                                               ImportedInternalFunctions[m].param);
            }
        }
    }
    else
    {
        VRgbtSize =0;
    }
    if(NOISE_STR != "")
    {
        for(uint j=0; j<ConstSize; j++)
            NoiseParser->AddConstant(ConstNames[j], ConstValues[j]);
        NoiseParser->AddConstant("Lacunarity", Lacunarity);
        NoiseParser->AddConstant("Gain", Gain);
        NoiseParser->AddConstant("Octaves", Octaves);
        //Add predefined constatnts:
        for(uint k=0; k<Nb_Sliders; k++)
        {
            NoiseParser->AddConstant(SliderNames[k], SliderValues[k]);
        }
    }
    //ImplicitFunction is composed of more than one isosurface:
    HowManyIsosurface(ImplicitFunction, 0);
    HowManyIsosurface(XlimitInf, 1);
    HowManyIsosurface(XlimitSup, 2);
    HowManyIsosurface(YlimitInf, 3);
    HowManyIsosurface(YlimitSup, 4);
    HowManyIsosurface(ZlimitInf, 5);
    HowManyIsosurface(ZlimitSup, 6);
    HowManyIsosurface(Grid, 7);
    if(cndnotnull)
    {
        ParisoCondition = 1;
        HowManyIsosurface(Condition, 8);
    }
    else
        ParisoCondition = -1;
    //Add defined constantes:
    for(uint i=0; i<componentsNumber; i++)
    {
        for(uint j=0; j<ConstSize; j++)
        {
            implicitFunctionParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            if(cndnotnull)
                ParisoConditionParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            xSupParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            ySupParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            zSupParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            xInfParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            yInfParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            zInfParser[i].AddConstant(ConstNames[j], ConstValues[j]);
        }
        //Add predefined constatnts:
        for(uint k=0; k<Nb_Sliders; k++)
        {
            implicitFunctionParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            if(cndnotnull)
                ParisoConditionParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            xSupParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            ySupParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            zSupParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            xInfParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            yInfParser[i].AddConstant(SliderNames[k], SliderValues[k]);
            zInfParser[i].AddConstant(SliderNames[k], SliderValues[k]);
        }
    }
    // Add defined functions :
    if(RGBT_STR!= "")
        for(int i=0; i<4; i++)
            for(uint j=0; j<FunctSize; j++)
            {
                RgbtParser[i].AddFunction(FunctNames[j], Fct[j]);
                for (uint m=0; m<ImportedInternalFunctions.size(); m++)
                    RgbtParser[i].AddFunction(ImportedInternalFunctions[m].name,
                                              ImportedInternalFunctions[m].ptr,
                                              ImportedInternalFunctions[m].param);
            }
    // Add defined functions :
    if(VRGBT_STR != "")
    {
        for(uint j=0; j<FunctSize; j++)
        {
            GradientParser->AddFunction(FunctNames[j], Fct[j]);
            for (uint m=0; m<ImportedInternalFunctions.size(); m++)
                GradientParser->AddFunction(ImportedInternalFunctions[m].name,
                                            ImportedInternalFunctions[m].ptr,
                                            ImportedInternalFunctions[m].param);
        }

        for(int i=0; i<4; i++)
            for(uint j=0; j<FunctSize; j++)
            {
                VRgbtParser[i].AddFunction(FunctNames[j], Fct[j]);
                for (uint m=0; m<ImportedInternalFunctions.size(); m++)
                    VRgbtParser[i].AddFunction(ImportedInternalFunctions[m].name,
                                               ImportedInternalFunctions[m].ptr,
                                               ImportedInternalFunctions[m].param);
            }
    }
    //delete NoiseFunction;
    //NoiseFunction = new CellNoise();
    for(uint i=0; i<componentsNumber; i++)
    {
        for(uint j=0; j<FunctSize; j++)
        {
            if((UsedFunct[i*FunctSize+j]=(ImplicitStructs[i].fxyz.find(FunctNames[j]) != std::string::npos)))
            {
                implicitFunctionParser[i].AddFunction(FunctNames[j], Fct[j]);
                ParisoConditionParser[i].AddFunction(FunctNames[j], Fct[j]);
            }
        }
        for (uint m=0; m<ImportedInternalFunctions.size(); m++)
            implicitFunctionParser[i].AddFunction(ImportedInternalFunctions[m].name,
                                                  ImportedInternalFunctions[m].ptr,
                                                  ImportedInternalFunctions[m].param);
    }
    for (uint m=0; m<ImportedInternalFunctions.size(); m++)
        NoiseParser->AddFunction(ImportedInternalFunctions[m].name,
                                              ImportedInternalFunctions[m].ptr,
                                              ImportedInternalFunctions[m].param);
    return ParseExpression();
}
ErrorMessage IsoMasterThread::ParseExpression()
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint limitX = XYZgrid, limitY = XYZgrid, limitZ = XYZgrid;

    if(AllComponentTraited)
    {
        stepMorph += pace;
    }
    vals[3] = stepMorph;
    // Parse
    if((RGBT_STR!= "") && RgbtSize == 4)
        for(uint i=0; i<RgbtSize; i++)
            if ((stdError.iErrorIndex = RgbtParser[i].Parse(Rgbts[i],IsoParametersList.ColorFunctParameters)) >= 0)
            {
                stdError.strError = Rgbts[i];
                stdError.ErrorType = RgbtParser[i].ErrorMsg();
                return stdError;
            }
    // Parse
    if((VRGBT_STR != "") && (VRgbtSize % 5) ==0)
    {
        if ((stdError.iErrorIndex = GradientParser->Parse(GRADIENT_STR,IsoParametersList.ColorFunctParameters)) >= 0)
        {
            stdError.strError = GRADIENT_STR;
            stdError.ErrorType = GradientParser->ErrorMsg();
            return stdError;
        }
        for(uint i=0; i<VRgbtSize; i++)
            if ((stdError.iErrorIndex = VRgbtParser[i].Parse(VRgbts[i],IsoParametersList.ColorFunctParameters)) >= 0)
            {
                stdError.strError = VRgbts[i];
                stdError.ErrorType = VRgbtParser[i].ErrorMsg();
                return stdError;
            }
    }
    if(NOISE_STR != "")
        if ((stdError.iErrorIndex = NoiseParser->Parse(NOISE_STR,IsoParametersList.ColorFunctParameters)) >= 0)
        {
            stdError.strError = NOISE_STR;
            stdError.ErrorType = NoiseParser->ErrorMsg();
            return stdError;
        }
    for(uint i=0; i<componentsNumber; i++)
    {
        if ((stdError.iErrorIndex = implicitFunctionParser[i].Parse(ImplicitStructs[i].fxyz,IsoParametersList.FunctParameters)) >= 0)
        {
            stdError.strError = ImplicitStructs[i].fxyz;
            stdError.ErrorType = implicitFunctionParser[i].ErrorMsg();
            return stdError;
        }
        if(cndnotnull && (ImplicitStructs[i].cnd!=""))
        {
            if ((stdError.iErrorIndex = ParisoConditionParser[i].Parse(ImplicitStructs[i].cnd,IsoParametersList.BasicFunctParameters)) >= 0)
            {
                stdError.strError = ImplicitStructs[i].cnd;
                stdError.ErrorType = ParisoConditionParser[i].ErrorMsg();
                return stdError;
            }
        }
        if ((stdError.iErrorIndex = xSupParser[i].Parse(ImplicitStructs[i].xmax, IsoParametersList.BasicFunctParameters)) >= 0)
        {
            stdError.strError = ImplicitStructs[i].xmax;
            stdError.ErrorType = xSupParser[i].ErrorMsg();
            return stdError;
        }
        if ((stdError.iErrorIndex = ySupParser[i].Parse(ImplicitStructs[i].ymax, IsoParametersList.BasicFunctParameters)) >= 0)
        {
            stdError.strError = ImplicitStructs[i].ymax;
            stdError.ErrorType = ySupParser[i].ErrorMsg();
            return stdError;
        }
        if ((stdError.iErrorIndex = zSupParser[i].Parse(ImplicitStructs[i].zmax, IsoParametersList.BasicFunctParameters)) >= 0)
        {
            stdError.strError = ImplicitStructs[i].zmax;
            stdError.ErrorType = zSupParser[i].ErrorMsg();
            return stdError;
        }
        if ((stdError.iErrorIndex = xInfParser[i].Parse(ImplicitStructs[i].xmin, IsoParametersList.BasicFunctParameters)) >= 0)
        {
            stdError.strError = ImplicitStructs[i].xmin;
            stdError.ErrorType = xInfParser[i].ErrorMsg();
            return stdError;
        }
        if ((stdError.iErrorIndex = yInfParser[i].Parse(ImplicitStructs[i].ymin, IsoParametersList.BasicFunctParameters)) >= 0)
        {
            stdError.strError = ImplicitStructs[i].ymin;
            stdError.ErrorType = yInfParser[i].ErrorMsg();
            return stdError;
        }
        if ((stdError.iErrorIndex = zInfParser[i].Parse(ImplicitStructs[i].zmin, IsoParametersList.BasicFunctParameters)) >= 0)
        {
            stdError.strError = ImplicitStructs[i].zmin;
            stdError.ErrorType = zInfParser[i].ErrorMsg();
            return stdError;
        }
    }
    for(uint IsoIndex=0; IsoIndex<componentsNumber; IsoIndex++)
    {
        if(gridnotnull)
        {
            limitX = limitY = limitZ = grid[IsoIndex];
        }

        xLocal2[IsoIndex*GridVal]=(x_Inf[IsoIndex]=xInfParser[IsoIndex].Eval(vals));
        yLocal2[IsoIndex*GridVal]=(y_Inf[IsoIndex]=yInfParser[IsoIndex].Eval(vals));
        zLocal2[IsoIndex*GridVal]=(z_Inf[IsoIndex]=zInfParser[IsoIndex].Eval(vals));
        x_Step[IsoIndex] = (limitX-1)>0 ? ((x_Sup[IsoIndex]=xSupParser[IsoIndex].Eval(vals)) - xLocal2[IsoIndex*GridVal])/(limitX-1) : 0;
        y_Step[IsoIndex] = (limitY-1)>0 ? ((y_Sup[IsoIndex]=ySupParser[IsoIndex].Eval(vals)) - yLocal2[IsoIndex*GridVal])/(limitY-1) : 0;
        z_Step[IsoIndex] = (limitZ-1)>0 ? ((z_Sup[IsoIndex]=zSupParser[IsoIndex].Eval(vals)) - zLocal2[IsoIndex*GridVal])/(limitZ-1) : 0;
        for (uint i= 1; i < limitX; i++) xLocal2[IsoIndex*GridVal+i] = xLocal2[IsoIndex*GridVal+i-1] + x_Step[IsoIndex];
        for (uint j= 1; j < limitY; j++) yLocal2[IsoIndex*GridVal+j] = yLocal2[IsoIndex*GridVal+j-1] + y_Step[IsoIndex];
        for (uint k= 1; k < limitZ; k++) zLocal2[IsoIndex*GridVal+k] = zLocal2[IsoIndex*GridVal+k-1] + z_Step[IsoIndex];
    }
    return stdError;
}
void IsoMasterThread::DeleteMasterParsers()
{
    if(ParsersAllocated)
    {
        delete[] implicitFunctionParser;
        delete[] xSupParser;
        delete[] ySupParser;
        delete[] zSupParser;
        delete[] xInfParser;
        delete[] yInfParser;
        delete[] zInfParser;
        delete[] Fct;
        delete[] UsedFunct;
        delete[] UsedFunct2;
        delete[] ParisoConditionParser;
        delete[] VRgbtParser;
        delete[] RgbtParser;
        delete GradientParser;
        delete NoiseParser;
        ParsersAllocated = false;
    }
    ImplicitStructs.clear();
    xLocal2.clear();
    yLocal2.clear();
    zLocal2.clear();
    x_Step.clear();
    y_Step.clear();
    z_Step.clear();
    x_Sup.clear();
    y_Sup.clear();
    z_Sup.clear();
    x_Inf.clear();
    y_Inf.clear();
    z_Inf.clear();
    SliderValues.clear();
    SliderNames.clear();
    Consts.clear();
    ConstNames.clear();
    ConstValues.clear();
    Rgbts.clear();
    VRgbts.clear();
    Functs.clear();
    FunctNames.clear();
}
void IsoWorkerThread::DeleteWorkerParsers()
{
    if(ParsersAllocated)
    {
        delete[] implicitFunctionParser;
        delete[] Fct;
        ParsersAllocated = false;
    }
}
void IsoMasterThread::InitMasterParsers()
{
    for(uint i=0; i<componentsNumber; i++)
    {
        implicitFunctionParser[i].AddConstant("pi", PI);
        implicitFunctionParser[i].AddConstant("ThreadId", ThreadIndex);

        ParisoConditionParser[i].AddConstant("pi", PI);
        xSupParser[i].AddConstant("pi", PI);
        ySupParser[i].AddConstant("pi", PI);
        zSupParser[i].AddConstant("pi", PI);
        xInfParser[i].AddConstant("pi", PI);
        yInfParser[i].AddConstant("pi", PI);
        zInfParser[i].AddConstant("pi", PI);
    }
    NoiseParser->AddConstant("pi", PI);
    NoiseParser->AddConstant("Lacunarity", Lacunarity);
    NoiseParser->AddConstant("Gain", Gain);
    NoiseParser->AddConstant("Octaves", Octaves);
    for(uint i=0; i<FunctSize; i++)
    {
        Fct[i].AddConstant("pi", PI);
        Fct[i].AddConstant("ThreadId", ThreadIndex);
        for (uint m=0; m<ImportedInternalFunctions.size(); m++)
            Fct[i].AddFunction(ImportedInternalFunctions[m].name,
                               ImportedInternalFunctions[m].ptr,
                               ImportedInternalFunctions[m].param);
    }
    for(uint i=0; i< RgbtSize; i++)
    {
        RgbtParser[i].AddConstant("pi", PI);
        RgbtParser[i].AddConstant("Lacunarity", Lacunarity);
        RgbtParser[i].AddConstant("Gain", Gain);
        RgbtParser[i].AddConstant("Octaves", Octaves);
        for (uint m=0; m<ImportedInternalFunctions.size(); m++)
            RgbtParser[i].AddFunction(ImportedInternalFunctions[m].name,
                                      ImportedInternalFunctions[m].ptr,
                                      ImportedInternalFunctions[m].param);
    }
    for(uint i=0; i<VRgbtSize; i++)
    {
        VRgbtParser[i].AddConstant("pi", PI);
        VRgbtParser[i].AddConstant("Lacunarity", Lacunarity);
        VRgbtParser[i].AddConstant("Gain", Gain);
        VRgbtParser[i].AddConstant("Octaves", Octaves);
        for (uint m=0; m<ImportedInternalFunctions.size(); m++)
            VRgbtParser[i].AddFunction(ImportedInternalFunctions[m].name,
                                       ImportedInternalFunctions[m].ptr,
                                       ImportedInternalFunctions[m].param);
    }
    GradientParser->AddConstant("pi", PI);
    GradientParser->AddConstant("Lacunarity", Lacunarity);
    GradientParser->AddConstant("Gain", Gain);
    GradientParser->AddConstant("Octaves", Octaves);
    for (uint m=0; m<ImportedInternalFunctions.size(); m++)
        GradientParser->AddFunction(ImportedInternalFunctions[m].name,
                                    ImportedInternalFunctions[m].ptr,
                                    ImportedInternalFunctions[m].param);
}
void IsoMasterThread::AllocateMasterParsers()
{
    if(!ParsersAllocated)
    {
        implicitFunctionParser = new FunctionParser[componentsNumber];
        xSupParser = new FunctionParser[componentsNumber];
        ySupParser = new FunctionParser[componentsNumber];
        zSupParser = new FunctionParser[componentsNumber];
        xInfParser = new FunctionParser[componentsNumber];
        yInfParser = new FunctionParser[componentsNumber];
        zInfParser = new FunctionParser[componentsNumber];
        ParisoConditionParser = new FunctionParser[componentsNumber];
        ImplicitStructs.resize(componentsNumber);
        xLocal2.resize(GridVal*componentsNumber);
        yLocal2.resize(GridVal*componentsNumber);
        zLocal2.resize(GridVal*componentsNumber);
        x_Step.resize(componentsNumber);
        y_Step.resize(componentsNumber);
        z_Step.resize(componentsNumber);
        x_Sup.resize(componentsNumber);
        y_Sup.resize(componentsNumber);
        z_Sup.resize(componentsNumber);
        x_Inf.resize(componentsNumber);
        y_Inf.resize(componentsNumber);
        z_Inf.resize(componentsNumber);
        if(!functnotnull)
            FunctSize = 0;
        Fct          = new FunctionParser[FunctSize];
        UsedFunct    = new bool[componentsNumber*FunctSize]; //Why "4*" ? parametric object have 4 fcts (fx,fy,fz,fw) but isoObject have only one fxyz
        UsedFunct2   = new bool[FunctSize*FunctSize];
        vectnotnull? nbvariables=vect[0] : nbvariables=0;
        (RGBT_STR!= "") ?
        RgbtParser = new FunctionParser[(RgbtSize = 4)] :
        RgbtParser = new FunctionParser[(RgbtSize = 0)];
        (VRGBT_STR != "") ?
        VRgbtParser = new FunctionParser[VRgbtSize] :
        VRgbtParser = new FunctionParser[(VRgbtSize = 0)];
        if(constnotnull)
            ConstSize=0;
        GradientParser = new FunctionParser;
        NoiseParser = new FunctionParser;
        ParsersAllocated = true;
    }
}
void IsoWorkerThread::AllocateParsersForWorkerThread(uint nbcomp, uint nbfunct)
{
    if(!ParsersAllocated)
    {
        implicitFunctionParser = new FunctionParser[nbcomp];
        Fct = new FunctionParser[nbfunct];
        ParsersAllocated = true;
    }
}
void IsoMasterThread::initgrid()
{
    GridVal = XYZgrid;
    if(gridnotnull)
        for(uint fctnb= 0; fctnb< componentsNumber; fctnb++)
            GridVal = std::max(GridVal, grid[fctnb]);
}
void IsoMasterThread::initparser()
{
    DeleteMasterParsers();
    initgrid();
    AllocateMasterParsers();
    InitMasterParsers();
}
void IsoWorkerThread::IsoCompute(uint fctnb)
{
    (fctnb == 0) ? AllComponentTraited = true : AllComponentTraited = false;  // AllComponentTraited = (fctnb == 0);
    VoxelEvaluation(fctnb);
}
void Iso3D::stopcalculations(bool calculation)
{
    StopCalculations = calculation;
    masterthread->StopCalculations = calculation;
    for(uint nbthreads=0; nbthreads+1< WorkerThreadsNumber; nbthreads++)
        workerthreads[nbthreads].StopCalculations = StopCalculations;
}
void Iso3D::copycomponent(struct ComponentInfos* copy, struct ComponentInfos* origin)
{
    copy->ParisoTriangle = origin->ParisoTriangle;
    copy->ParisoVertex          = origin->ParisoVertex;
    copy->NbComponentsType    = origin->NbComponentsType;
    copy->ParisoCurrentComponentIndex = origin->ParisoCurrentComponentIndex;
    copy->ParisoNbComponents          = origin->ParisoNbComponents;
    copy->Interleave                  = origin->Interleave;
    copy->pariso                      = origin->pariso;
    copy->updateviewer                = origin->updateviewer;
    copy->ThereisCND                  = origin->ThereisCND;
    copy->ParisoCondition             = origin->ParisoCondition;
    copy->ThereisRGBA                 = origin->ThereisRGBA;
    copy->NbTrianglesVerifyCND        = origin->NbTrianglesVerifyCND;
    copy->NbTrianglesNoCND            = origin->NbTrianglesNoCND;
    copy->NbTrianglesNotVerifyCND     = origin->NbTrianglesNotVerifyCND;
    copy->NbTrianglesBorderCND        = origin->NbTrianglesBorderCND;
    for(int i=0; i<2; i++)
    {
        copy->NoiseParam[i]  = origin->NoiseParam[i];
    }
}
void Iso3D::IsoBuild (
    float **NormVertexTabVectorPt,
    uint **IndexPolyTabPt,
    unsigned   int *PolyNumber,
    uint *VertexNumberpt,
    uint **IndexPolyTabMinPt,
    unsigned  int *VertxNumber,
    unsigned  int *MinimPolySize,
    struct ComponentInfos * componentsPt
)
{
    uint NbTriangleIsoSurfaceTmp, PreviousGridVal=masterthread->XYZgrid;
    NbPointIsoMap= 0;
    NbVertexTmp = NbTriangleIsoSurfaceTmp = 0;
    componentsPt->updateviewer= false;
    clear(components);
    components->ParisoCondition = componentsPt->ParisoCondition;
    if(componentsPt->pariso && componentsPt->ParisoCurrentComponentIndex>0)
    {
        NbVertexTmp = uint(NormVertexTabVector.size()/10);

        //*********************
        // probleme with pariso objects comes from here since IndexPolyTabVector contains not only triangles but also lines
        // inherited from it's parametric conterpart
        NbTriangleIsoSurfaceTmp = uint(IndexPolyTabVector.size()/3); // <==
        //*********************

        copycomponent(components, componentsPt);
    }
    else
    {
        if(componentsPt->pariso)
        {
            components->pariso = true;
            components->ParisoCurrentComponentIndex = componentsPt->ParisoCurrentComponentIndex;
            components->ParisoNbComponents = componentsPt->ParisoNbComponents;
        }
        NormVertexTabVector = std::vector<float>();
        IndexPolyTabVector = std::vector<uint>();
        IndexPolyTabMinVector = std::vector<uint>();
    }
    NormOriginaltmpVector = std::vector<float>();
    //*****//
    if(GridVoxelVarPt != nullptr)
        delete[] GridVoxelVarPt;
    if(Results != nullptr)
        delete[] Results;

    uint maxx = std::max(masterthread->XYZgrid, masterthread->GridVal);
    if(masterthread->gridnotnull)
        for(uint fctnb= 0; fctnb< masterthread->componentsNumber; fctnb++)
            maxx = std::max(maxx, masterthread->grid[fctnb]);
    masterthread->GridVal = maxx;
    for(uint nbthreads=0; nbthreads+1<WorkerThreadsNumber; nbthreads++)
    {
        workerthreads[nbthreads].GridVal = masterthread->GridVal;
    }
    try
      {
        GridVoxelVarPt = new Voxel[masterthread->GridVal*masterthread->GridVal*masterthread->GridVal];
      }
      catch (std::bad_alloc& e)
      {
        messageerror = MEM_OVERFLOW;
        emitErrorSignal();
        return;
      }
    Results = new (std::nothrow) double[masterthread->GridVal*masterthread->GridVal*masterthread->GridVal];
    if (!Results)
    {
        messageerror = MEM_OVERFLOW;
        emitErrorSignal();
        return;
    }
    components->NbComponentsType.push_back(masterthread->componentsNumber);
    stopcalculations(false);
    if(masterthread->activeMorph != 1)
    {
        times.restart();
    }
    // generate Isosurface for all the implicit formulas
    for(uint fctnb= 0; fctnb< masterthread->componentsNumber; fctnb++)
    {
        if(masterthread->activeMorph != 1)
        {
            message = QString("1) Cmp:"+QString::number(fctnb+1)+"/"+QString::number(masterthread->componentsNumber)+"==> Math calculation");
            emitUpdateMessageSignal();
        }
        ComponentId = fctnb;
        if(masterthread->gridnotnull)
            Setgrid(masterthread->grid[fctnb]);

        masterthread->CurrentComponent = fctnb;
        for(uint nbthreads=0; nbthreads+1 < WorkerThreadsNumber; nbthreads++)
            workerthreads[nbthreads].CurrentComponent = fctnb;
        for(uint nbthreads=0; nbthreads+1 < WorkerThreadsNumber; nbthreads++)
            workerthreads[nbthreads].stepMorph = masterthread->stepMorph;
        if(masterthread->activeMorph == 1)
        {
            if(fctnb == 0)
            {
                //This code is to ensure that stepmorph values are the same accross all threads
                masterthread->stepMorph += masterthread->pace;
                for(uint nbthreads=0; nbthreads+1 < WorkerThreadsNumber; nbthreads++)
                    workerthreads[nbthreads].stepMorph = masterthread->stepMorph;
            }
            // Recalculate some tables values:
            ReinitVarTablesWhenMorphActiv(fctnb);
        }
        masterthread->start();
        for(uint nbthreads=0; nbthreads+1 < WorkerThreadsNumber; nbthreads++)
            workerthreads[nbthreads].start();
        masterthread->wait();
        for(uint nbthreads=0; nbthreads+1 < WorkerThreadsNumber; nbthreads++)
            workerthreads[nbthreads].wait();
        bool Stop = masterthread->StopCalculations;
        for(uint nbthreads=0; nbthreads+1 < WorkerThreadsNumber; nbthreads++)
            Stop = Stop || workerthreads[nbthreads].StopCalculations;
        if(StopCalculations || Stop)
        {
            Setgrid(PreviousGridVal);
            delete[] GridVoxelVarPt;
            GridVoxelVarPt = nullptr;
            delete[] Results;
            Results = nullptr;
            return;
        }
        if(masterthread->activeMorph != 1)
        {
            message += QString(" ==> Mesh generation");
            emitUpdateMessageSignal();
        }
        uint result = PointEdgeComputation(fctnb);
        if(result == 0)
        {
            messageerror = VERTEX_TAB_MEM_OVERFLOW;
            emitErrorSignal();
            return;
        }
        SignatureComputation();
        result = ConstructIsoSurface();
        if(result == 0)
        {
            messageerror = TRIANGLES_TAB_MEM_OVERFLOW;
            emitErrorSignal();
            return;
        }
        ConstructIsoNormale(NbTriangleIsoSurfaceTmp);
        SaveIsoGLMap(NbTriangleIsoSurfaceTmp);
        NormOriginaltmpVector.clear();
        result = SetMiniMmeshStruct();
        if(result == 0)
        {
            messageerror = MINPOLY_TAB_MEM_OVERFLOW;
            emitErrorSignal();
            return;
        }
        // Save the Index:
        components->ParisoTriangle.push_back(3*NbTriangleIsoSurfaceTmp); //save the starting position of this component
        components->ParisoTriangle.push_back(NbTriangleIsoSurface);      //save the number of triangles of this component
        components->ParisoVertex.push_back(NbVertexTmp);
        components->ParisoVertex.push_back(NbVertexTmp + NbPointIsoMap -1);
        // Save Number of Polys and vertex :
        NbVertexTmp               += NbPointIsoMap;
        NbTriangleIsoSurfaceTmp   += NbTriangleIsoSurface;
    }
    delete[] GridVoxelVarPt;
    GridVoxelVarPt = nullptr;
    delete[] Results;
    Results = nullptr;
    if(masterthread->activeMorph != 1)
    {
        message = QString("2) Mesh Processing");
        emitUpdateMessageSignal();
    }
    //CND calculation for the triangles results:
    uint result = CNDCalculation(NbTriangleIsoSurfaceTmp, components);
    if(result == 0)
    {
        messageerror = CND_TAB_MEM_OVERFLOW;
        emitErrorSignal();
        return;
    }
    else if(result == 2)
    {
        messageerror = CND_POL_MEM_OVERFLOW;
        emitErrorSignal();
        return;
    }
    // Pigment, Texture and Noise :
    if(masterthread->VRGBT_STR != "")
    {
        components->ThereisRGBA.push_back(true);
        components->NoiseParam[components->ParisoCurrentComponentIndex].NoiseType = 0; //Pigments
        components->NoiseParam[components->ParisoCurrentComponentIndex].VRgbtParser = masterthread->VRgbtParser;
        components->NoiseParam[components->ParisoCurrentComponentIndex].GradientParser = masterthread->GradientParser;
        components->NoiseParam[components->ParisoCurrentComponentIndex].NoiseParser =  masterthread->NoiseParser;
        components->NoiseParam[components->ParisoCurrentComponentIndex].Nb_vrgbts = masterthread->VRgbtSize;
    }
    else if(masterthread->RgbtSize >= 4)
    {
        components->ThereisRGBA.push_back(true);
        components->NoiseParam[components->ParisoCurrentComponentIndex].NoiseType = 1; //Texture
        components->NoiseParam[components->ParisoCurrentComponentIndex].RgbtParser = masterthread->RgbtParser;
        components->NoiseParam[components->ParisoCurrentComponentIndex].NoiseParser =  masterthread->NoiseParser;
    }
    else
    {
        components->ThereisRGBA.push_back(false);
        components->NoiseParam[components->ParisoCurrentComponentIndex].NoiseType = -1; //No Pigments or texture
    }
    if(masterthread->NOISE_STR == "")
        components->NoiseParam[components->ParisoCurrentComponentIndex].NoiseShape = 0;
    else
        components->NoiseParam[components->ParisoCurrentComponentIndex].NoiseShape = 1;
    CalculateColorsPoints(components, components->ThereisRGBA.size()-1);
    *PolyNumber      = uint(IndexPolyTabVector.size());
    *VertexNumberpt  = uint(NormVertexTabVector.size()/10);
    *VertxNumber     = uint(IndexPolyTabMinVector.size());
    if(masterthread->activeMorph != 1)
    {
        message = QString("     [ Threads:"+QString::number(WorkerThreadsNumber)+"; Componens:"+QString::number(masterthread->componentsNumber)+"; Time="+QString::number(times.elapsed()/1000.0)+"s ]");
        // emitUpdateMessageSignal();
    }
    NormVertexTabVector.resize(NormVertexTabVector.size()+ (12+60+36)*10); // To add memory space to store the cube 12 vertices (three quads)

    uint startpl = 0;
    uint actualpointindice=0;
    for (uint i = 0; i < *VertxNumber; i++)
    {
        uint polysize = IndexPolyTabMinVector[startpl++];
        for (uint j = 0; j < polysize; j++)
        {
            actualpointindice = IndexPolyTabMinVector[startpl];
            IndexPolyTabVector.push_back(actualpointindice);
            startpl++;
        }
        i += polysize;
    }

    IndexPolyTabMinVector2.clear();
    for (uint i = 0; i < IndexPolyTabMinVector.size(); i++)
    {
        uint polysize = IndexPolyTabMinVector[i];
        IndexPolyTabMinVector2.push_back(polysize);
        i += polysize;
    }

    *MinimPolySize = IndexPolyTabVector.size() - *PolyNumber;
    *VertxNumber     = uint(IndexPolyTabMinVector2.size());
    *IndexPolyTabMinPt = IndexPolyTabMinVector2.data();

    *NormVertexTabVectorPt = NormVertexTabVector.data();
    *IndexPolyTabPt = IndexPolyTabVector.data();
    copycomponent(componentsPt, components);
    componentsPt->Interleave = true;
    if(componentsPt->ParisoCurrentComponentIndex != (componentsPt->ParisoNbComponents-1))
        componentsPt->ParisoCurrentComponentIndex += 1;
    else
        componentsPt->ParisoCurrentComponentIndex = 0;
    InitShowComponent(componentsPt);
    Setgrid(PreviousGridVal);
    componentsPt->updateviewer = true;
}

void Iso3D::InitShowComponent(struct ComponentInfos *cpInfos)
{
    cpInfos->ShowParIsoCmp.clear();
    uint idx =0;
    for(uint i=0; i<cpInfos->NbComponentsType.size(); i++)
        idx+=cpInfos->NbComponentsType[i];
    for(uint i=0; i<idx; i++)
        cpInfos->ShowParIsoCmp.push_back(true);
}

void Iso3D::Setgrid(uint NewGridVal)
{
    if(masterthread->gridnotnull)
    {
        masterthread->XYZgrid  = NewGridVal;
        for(uint th=0; th+1 < WorkerThreadsNumber; th++)
            workerthreads[th].XYZgrid = NewGridVal;
    }
}
void Iso3D::CalculateColorsPoints(struct ComponentInfos* comp, uint index)
{
    uint cmpId=0, K=0;
    double tmp,
           *ValCol,
           val[16];
    ValCol = new double[masterthread->VRgbtSize];
    val[3] = masterthread->stepMorph;
    val[0] = val[1] = val[2] = 0.0;
    if(comp->ThereisRGBA[index] == true &&  comp->NoiseParam[comp->ParisoCurrentComponentIndex].NoiseType == 0)
    {
        uint idx=0;
        for(uint i=0; i < comp->NbComponentsType.size()-1; i++)
            idx+=comp->NbComponentsType[i];
        for(uint i= comp->ParisoVertex[2*idx]; i < NbVertexTmp; i++)
        {
            if((i >= uint(comp->ParisoVertex[2*(cmpId+idx)])))
            {
                K = cmpId;
                if((masterthread->componentsNumber-1)>cmpId)
                {
                    cmpId++;
                }
            }
            val[0]= double(NormVertexTabVector[i*10  + 7 ]);
            val[1]= double(NormVertexTabVector[i*10  + 8 ]);
            val[2]= double(NormVertexTabVector[i*10  + 9 ]);
            //val[3]=?
            val[4]= double(K);
            if(masterthread->gridnotnull)
            {
                val[5] = double(i); //"x,y,z,t,cmpId,indx,x_step,y_step,z_step,max_ijk,x_sup,y_sup,z_sup,x_inf,y_inf,z_inf"
                val[6] = masterthread->x_Step[K];
                val[7] = masterthread->y_Step[K];
                val[8] = masterthread->z_Step[K];
                val[9] = double(masterthread->grid[K]);
                val[10] = masterthread->x_Sup[K];
                val[11] = masterthread->y_Sup[K];
                val[12] = masterthread->z_Sup[K];
                val[13] = masterthread->x_Inf[K];
                val[14] = masterthread->y_Inf[K];
                val[15] = masterthread->z_Inf[K];
            }
            else
            {
                val[5] = double(i);
                val[6] = masterthread->x_Step[0];
                val[7] = masterthread->y_Step[0];
                val[8] = masterthread->z_Step[0];
                val[9] = double(masterthread->GridVal);
                val[10] = masterthread->x_Sup[0];
                val[11] = masterthread->y_Sup[0];
                val[12] = masterthread->z_Sup[0];
                val[13] = masterthread->x_Inf[0];
                val[14] = masterthread->y_Inf[0];
                val[15] = masterthread->z_Inf[0];
            }
            for(uint i=0; i<masterthread->VRgbtSize; i++)
            {
                ValCol[i] = masterthread->VRgbtParser[i].Eval(val);
            }
            if(masterthread->NOISE_STR != "")
                tmp  = masterthread->NoiseParser->Eval(val);
            else
                tmp =1.0;
            val[0]= tmp*double(NormVertexTabVector[i*10  + 7 ]);
            val[1]= tmp*double(NormVertexTabVector[i*10  + 8 ]);
            val[2]= tmp*double(NormVertexTabVector[i*10  + 9 ]);
            tmp  = masterthread->GradientParser->Eval(val);
            for (uint j=0; j < masterthread->VRgbtSize; j+=5)
                if(tmp < ValCol[j])
                {
                    float fraction=0;
                    if(j>=5 && (ValCol[j] != ValCol[j-5]))
                    {
                        fraction = (tmp-ValCol[j-5])/(ValCol[j]-ValCol[j-5]);
                        NormVertexTabVector[i*10  ] = float(ValCol[j+1])*(fraction) + (1-fraction)*float(ValCol[(j-5)+1]);
                        NormVertexTabVector[i*10+1] = float(ValCol[j+2])*(fraction) + (1-fraction)*float(ValCol[(j-5)+2]);;
                        NormVertexTabVector[i*10+2] = float(ValCol[j+3])*(fraction) + (1-fraction)*float(ValCol[(j-5)+3]);
                        NormVertexTabVector[i*10+3] = float(ValCol[(j)+4]);
                        j = masterthread->VRgbtSize;
                    }
                }
                else if(tmp == ValCol[j])
                {
                    NormVertexTabVector[i*10  ] = float(ValCol[j+1]);
                    NormVertexTabVector[i*10+1] = float(ValCol[j+2]);
                    NormVertexTabVector[i*10+2] = float(ValCol[j+3]);
                    NormVertexTabVector[i*10+3] = float(ValCol[j+4]);
                    j = masterthread->VRgbtSize;
                }
        }
    }
    else if(comp->ThereisRGBA[index] == true &&  comp->NoiseParam[comp->ParisoCurrentComponentIndex].NoiseType == 1)
    {
        uint idx=0;
        for(uint i=0; i < comp->NbComponentsType.size()-1; i++)
            idx+=comp->NbComponentsType[i];
        for(uint i= comp->ParisoVertex[2*idx]; i < NbVertexTmp; i++)
        {
            if((i >= uint(comp->ParisoVertex[2*(cmpId+idx)])))
            {
                K = cmpId;
                if((masterthread->componentsNumber-1)>cmpId)
                {
                    cmpId++;
                }
            }
            val[0]= double(NormVertexTabVector[i*10 + 7]);
            val[1]= double(NormVertexTabVector[i*10 + 8]);
            val[2]= double(NormVertexTabVector[i*10 + 9]);
            //val[3]=?
            val[4]= double(K);
            if(masterthread->gridnotnull)
            {
                val[5] = double(i);
                val[6] = masterthread->x_Step[K];
                val[7] = masterthread->y_Step[K];
                val[8] = masterthread->z_Step[K];
                val[9] = double(masterthread->grid[K]);
                val[10] = masterthread->x_Sup[K];
                val[11] = masterthread->y_Sup[K];
                val[12] = masterthread->z_Sup[K];
                val[13] = masterthread->x_Inf[K];
                val[14] = masterthread->y_Inf[K];
                val[15] = masterthread->z_Inf[K];
            }
            else
            {
                val[5] = double(i);
                val[6] = masterthread->x_Step[0];
                val[7] = masterthread->y_Step[0];
                val[8] = masterthread->z_Step[0];
                val[9] = double(masterthread->GridVal);
                val[10] = masterthread->x_Sup[0];
                val[11] = masterthread->y_Sup[0];
                val[12] = masterthread->z_Sup[0];
                val[13] = masterthread->x_Inf[0];
                val[14] = masterthread->y_Inf[0];
                val[15] = masterthread->z_Inf[0];
            }
            if(masterthread->NOISE_STR != "")
                tmp  = masterthread->NoiseParser->Eval(val);
            else
                tmp =1.0;
            val[0]= tmp*double(NormVertexTabVector[i*10+7]);
            val[1]= tmp*double(NormVertexTabVector[i*10+8]);
            val[2]= tmp*double(NormVertexTabVector[i*10+9]);
            NormVertexTabVector[i*10  ] = float(masterthread->RgbtParser[0].Eval(val));
            NormVertexTabVector[i*10+1] = float(masterthread->RgbtParser[1].Eval(val));
            NormVertexTabVector[i*10+2] = float(masterthread->RgbtParser[2].Eval(val));
            NormVertexTabVector[i*10+3] = float(masterthread->RgbtParser[3].Eval(val));
        }
    }
    delete[] ValCol;
}
uint Iso3D::CNDCalculation(uint & NbTriangleIsoSurfaceTmp, struct ComponentInfos *comp)
{
    uint idpx=0;
    for(uint i=0; i < comp->NbComponentsType.size()-1; i++)
        idpx+=comp->NbComponentsType[i];
    uint startpoint=comp->ParisoVertex[2*idpx];
    //In the case the parametric part of a Pariso object doesn't have a CND condition
    int sz = (comp->ParisoCondition.size() ==
              comp->NbComponentsType[comp->NbComponentsType.size()-1]) ? 0 : idpx;
    if (masterthread->ParisoCondition == 1)
    {
        double vals[4];
        std::vector<int> PointVerifyCond;
        vals[3] = masterthread->stepMorph;
        for(uint i= startpoint; i < NbVertexTmp; i++)
        {
            vals[0] = double(NormVertexTabVector[i*10+7]);
            vals[1] = double(NormVertexTabVector[i*10+8]);
            vals[2] = double(NormVertexTabVector[i*10+9]);
            uint compid= CNDtoUse(i, comp);
            if(comp->ParisoCondition[compid+sz])
                PointVerifyCond.push_back(8);
            else
                PointVerifyCond.push_back(int(masterthread->ParisoConditionParser[compid].Eval(vals)));
            if(PointVerifyCond[i-startpoint])
            {
                NormVertexTabVector[i*10  ] = 0.1f;
                NormVertexTabVector[i*10+1] = 0.9f;
                NormVertexTabVector[i*10+2] = 0.0;
                NormVertexTabVector[i*10+3] = 1.0;
            }
            else
            {
                NormVertexTabVector[i*10  ] = 0.9f;
                NormVertexTabVector[i*10+1] = 0.1f;
                NormVertexTabVector[i*10+2] = 0.9;
                NormVertexTabVector[i*10+3] = 1.0;
            }
        }
        uint Aindex, Bindex, Cindex;
        uint nbtriangle = NbTriangleIsoSurfaceTmp;
        uint mdx=0;
        for(uint id=0; id < comp->NbComponentsType.size()-1; id++)
            mdx+=comp->NbComponentsType[id];
        uint starttri = uint(comp->ParisoTriangle[2*mdx]/3);
        std::vector<int> TypeIsoSurfaceTriangleListeCNDVector (NbTriangleIsoSurfaceTmp-starttri, 1);
        for(uint i= starttri; i < nbtriangle; i++)
        {
            Aindex = IndexPolyTabVector[3*i    ];
            Bindex = IndexPolyTabVector[3*i + 1];
            Cindex = IndexPolyTabVector[3*i + 2];
            int TypeTriangle = -1;
            if((PointVerifyCond[Aindex-startpoint] == 8) ||
                    (PointVerifyCond[Bindex-startpoint] == 8) ||
                    (PointVerifyCond[Cindex-startpoint] == 8))
            {
                TypeTriangle = 8;
                TypeIsoSurfaceTriangleListeCNDVector[i-starttri] = 8;
            }
            else if(PointVerifyCond[Aindex-startpoint] && !PointVerifyCond[Bindex-startpoint] && !PointVerifyCond[Cindex-startpoint])
                TypeTriangle = 0;
            else if(!PointVerifyCond[Aindex-startpoint] && PointVerifyCond[Bindex-startpoint] && PointVerifyCond[Cindex-startpoint])
                TypeTriangle = 1;
            else if(!PointVerifyCond[Aindex-startpoint] && PointVerifyCond[Bindex-startpoint] && !PointVerifyCond[Cindex-startpoint])
                TypeTriangle = 2;
            else if(PointVerifyCond[Aindex-startpoint] && !PointVerifyCond[Bindex-startpoint] && PointVerifyCond[Cindex-startpoint])
                TypeTriangle = 3;
            else if(!PointVerifyCond[Aindex-startpoint] && !PointVerifyCond[Bindex-startpoint] && PointVerifyCond[Cindex-startpoint])
                TypeTriangle = 4;
            else if(PointVerifyCond[Aindex-startpoint] && PointVerifyCond[Bindex-startpoint] && !PointVerifyCond[Cindex-startpoint])
                TypeTriangle = 5;
            else if(!PointVerifyCond[Aindex-startpoint] && !PointVerifyCond[Bindex-startpoint] && !PointVerifyCond[Cindex-startpoint])
            {
                TypeTriangle = 6;
                TypeIsoSurfaceTriangleListeCNDVector[i-starttri] = -1;
            }
            else if(PointVerifyCond[Aindex-startpoint] && PointVerifyCond[Bindex-startpoint] && PointVerifyCond[Cindex-startpoint])
            {
                TypeTriangle = 7;
                TypeIsoSurfaceTriangleListeCNDVector[i-starttri] = 1;
            }

            if(TypeTriangle == 2 || TypeTriangle == 3)
            {
                Aindex = IndexPolyTabVector[3*i+1];
                Bindex = IndexPolyTabVector[3*i+2];
                Cindex = IndexPolyTabVector[3*i  ];
            }
            else if(TypeTriangle == 4 || TypeTriangle == 5)
            {
                Aindex = IndexPolyTabVector[3*i+2];
                Bindex = IndexPolyTabVector[3*i  ];
                Cindex = IndexPolyTabVector[3*i+1];
            }

            double Bprime[4], Cprime[4], DiffX, DiffY, DiffZ;
            int Alfa;
            uint cnd = CNDtoUse(Aindex, comp);
            if(TypeTriangle >=0 && TypeTriangle <= 5)
            {
                /// Bprime
                Bprime[0] = double(NormVertexTabVector[10*Aindex+7]);
                Bprime[1] = double(NormVertexTabVector[10*Aindex+8]);
                Bprime[2] = double(NormVertexTabVector[10*Aindex+9]);
                Bprime[3] = masterthread->stepMorph;

                DiffX = double(NormVertexTabVector[10*Bindex+7] - NormVertexTabVector[3+10*Aindex  + 4])/20.0;
                DiffY = double(NormVertexTabVector[10*Bindex+8] - NormVertexTabVector[3+10*Aindex+1+ 4])/20.0;
                DiffZ = double(NormVertexTabVector[10*Bindex+9] - NormVertexTabVector[3+10*Aindex+2+ 4])/20.0;
                Alfa = 0;
                if(TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4)
                {
                    while(masterthread->ParisoConditionParser[cnd].Eval(Bprime) == 1.0 && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!(masterthread->ParisoConditionParser[cnd].Eval(Bprime) == 1.0) && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }

                /// Cprime
                Cprime[0] = double(NormVertexTabVector[10*Aindex+7]);
                Cprime[1] = double(NormVertexTabVector[10*Aindex+8]);
                Cprime[2] = double(NormVertexTabVector[10*Aindex+9]);
                Cprime[3] = masterthread->stepMorph;

                DiffX = double(NormVertexTabVector[3+10*Cindex  + 4] - NormVertexTabVector[3+10*Aindex  + 4])/20;
                DiffY = double(NormVertexTabVector[3+10*Cindex+1+ 4] - NormVertexTabVector[3+10*Aindex+1+ 4])/20;
                DiffZ = double(NormVertexTabVector[3+10*Cindex+2+ 4] - NormVertexTabVector[3+10*Aindex+2+ 4])/20;
                Alfa = 0;
                if(TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4)
                {
                    while(masterthread->ParisoConditionParser[cnd].Eval(Cprime) == 1.0 && (Alfa < 20))
                    {
                        Cprime[0] += DiffX;
                        Cprime[1] += DiffY;
                        Cprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!(masterthread->ParisoConditionParser[cnd].Eval(Cprime) == 1.0) && (Alfa < 20))
                    {
                        Cprime[0] += DiffX;
                        Cprime[1] += DiffY;
                        Cprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                //***********
                //Add points:
                //***********
                //Add Bprime:
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(NormVertexTabVector[10*Bindex + 4]);
                NormVertexTabVector.push_back(NormVertexTabVector[10*Bindex + 5]);
                NormVertexTabVector.push_back(NormVertexTabVector[10*Bindex + 6]);
                NormVertexTabVector.push_back(float(Bprime[0]));
                NormVertexTabVector.push_back(float(Bprime[1]));
                NormVertexTabVector.push_back(float(Bprime[2]));

                //Add Cprime:
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(NormVertexTabVector[10*Cindex + 4]);
                NormVertexTabVector.push_back(NormVertexTabVector[10*Cindex + 5]);
                NormVertexTabVector.push_back(NormVertexTabVector[10*Cindex + 6]);
                NormVertexTabVector.push_back(float(Cprime[0]));
                NormVertexTabVector.push_back(float(Cprime[1]));
                NormVertexTabVector.push_back(float(Cprime[2]));

                NbVertexTmp += 2;

                //***********
                //Add triangles:
                //***********
                /// Add Three new triangles :
                uint IndexBprime = (NbVertexTmp-2);
                uint IndexCprime = (NbVertexTmp-1);

                // The original triangle will be replaced by four other triangles:
                TypeIsoSurfaceTriangleListeCNDVector[i-starttri]=0;

                /// (A, Bprime, Cprime)
                IndexPolyTabVector.push_back(Aindex);
                IndexPolyTabVector.push_back(IndexBprime);
                IndexPolyTabVector.push_back(IndexCprime);

                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCNDVector.push_back(1) : TypeIsoSurfaceTriangleListeCNDVector.push_back(-1);
                NbTriangleIsoSurfaceTmp++;
                IndexPolyTabMinVector.push_back(3);
                IndexPolyTabMinVector.push_back(Aindex);
                IndexPolyTabMinVector.push_back(IndexBprime);
                IndexPolyTabMinVector.push_back(IndexCprime);

                /// (Bprime, B, C)
                IndexPolyTabVector.push_back(IndexBprime);
                IndexPolyTabVector.push_back(Bindex);
                IndexPolyTabVector.push_back(Cindex);

                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCNDVector.push_back(-1) : TypeIsoSurfaceTriangleListeCNDVector.push_back(1);
                NbTriangleIsoSurfaceTmp++;
                IndexPolyTabMinVector.push_back(3);
                IndexPolyTabMinVector.push_back(IndexBprime);
                IndexPolyTabMinVector.push_back(Bindex);
                IndexPolyTabMinVector.push_back(Cindex);

                /// (Bprime, C, Cprime)
                IndexPolyTabVector.push_back(IndexBprime);
                IndexPolyTabVector.push_back(Cindex);
                IndexPolyTabVector.push_back(IndexCprime);

                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCNDVector.push_back(-1) : TypeIsoSurfaceTriangleListeCNDVector.push_back(1);
                NbTriangleIsoSurfaceTmp++;
                IndexPolyTabMinVector.push_back(3);
                IndexPolyTabMinVector.push_back(IndexBprime);
                IndexPolyTabMinVector.push_back(Cindex);
                IndexPolyTabMinVector.push_back(IndexCprime);

                /// (Bprime, Cprime) --> the border
                IndexPolyTabVector.push_back(IndexBprime);
                IndexPolyTabVector.push_back(IndexCprime);
                IndexPolyTabVector.push_back(IndexCprime);

                TypeIsoSurfaceTriangleListeCNDVector.push_back(4); /// Type = 4-->Border
                NbTriangleIsoSurfaceTmp++;
                IndexPolyTabMinVector.push_back(3);
                IndexPolyTabMinVector.push_back(IndexBprime);
                IndexPolyTabMinVector.push_back(IndexCprime);
                IndexPolyTabMinVector.push_back(IndexCprime);
            }
        }

        //***********
        //Reorganize the triangles index:
        //***********
        std::vector<uint>NewIndexPolyTabVector;
        uint k, l, M, N;
        k = l = M = N = 0;

        // In case we have a ParIso object, this will save the triangle arrangement for the parametric CND
        for(uint i=0; i<starttri; i++)
        {
            NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i  ]);
            NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+1]);
            NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+2]);
        }

        // Now we start sorting the triangles list. We have 3 cases

        for(uint i=starttri; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCNDVector[i-starttri] == 8)
            {
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i  ]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+1]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+2]);
                N++;
            }

        for(uint i=starttri; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCNDVector[i-starttri] == 1)
            {
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i  ]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+1]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+2]);
                k++;
            }

        for(uint i=starttri; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCNDVector[i-starttri] == -1)
            {
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i  ]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+1]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+2]);
                l++;
            }

        for(uint i=starttri; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCNDVector[i-starttri] == 4)
            {
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i  ]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+1]);
                NewIndexPolyTabVector.push_back(IndexPolyTabVector[3*i+2]);
                M++;
            }
        //Copy the new index in the original one:
        IndexPolyTabVector.clear();
        IndexPolyTabVector.shrink_to_fit();
        IndexPolyTabVector = NewIndexPolyTabVector;
        NewIndexPolyTabVector.clear();
        NewIndexPolyTabVector.shrink_to_fit();

        NbTriangleIsoSurfaceTmp = M + l + k + N;

        comp->NbTrianglesNoCND.push_back(N);
        comp->NbTrianglesVerifyCND.push_back(k);
        comp->NbTrianglesNotVerifyCND.push_back(l);
        comp->NbTrianglesBorderCND.push_back(M);
        comp->ThereisCND.push_back(true);

        PointVerifyCond.clear();
        PointVerifyCond.shrink_to_fit();
        TypeIsoSurfaceTriangleListeCNDVector.clear();
        TypeIsoSurfaceTriangleListeCNDVector.shrink_to_fit();
    }
    else
    {
        comp->NbTrianglesNoCND.push_back(0);
        comp->NbTrianglesVerifyCND.push_back(0);
        comp->NbTrianglesNotVerifyCND.push_back(0);
        comp->NbTrianglesBorderCND.push_back(0);
        comp->ThereisCND.push_back(false);
        for(uint i= startpoint; i < NbVertexTmp; i++)
        {
            NormVertexTabVector[i*10  ] = 0.5f;
            NormVertexTabVector[i*10+1] = 0.6f;
            NormVertexTabVector[i*10+2] = 0.8f;
            NormVertexTabVector[i*10+3] = 1.0;
        }
    }

    return 1;
}

Iso3D::~Iso3D()
{
}

uint Iso3D::SetMiniMmeshStruct()
{
    uint I_mi, J_mi, IJK_mi, Index_mi, iter_mi, nbpl_mi, iterpl_mi;
    uint maxgrscalemaxgr = masterthread->GridVal*masterthread->GridVal;

    NbPolyMin = 0;
    /// Copy Index Polygons :
    for(uint i=0; i+1 < masterthread->XYZgrid; i++)
    {
        I_mi  = i*maxgrscalemaxgr;
        for(uint j=0; j+1 < masterthread->XYZgrid; j++)
        {
            J_mi  = I_mi+j*masterthread->GridVal;
            for(uint k=0; k+1 < masterthread->XYZgrid; k++)
            {
                IJK_mi = J_mi+k;
                Index_mi = GridVoxelVarPt[IJK_mi].Signature;
                nbpl_mi = triTable_min[Index_mi][16];

                if( nbpl_mi == 1)
                {
                    NbPolyMin += nbpl_mi;
                    IndexPolyTabMinVector.push_back(triTable_min[Index_mi][17]);
                    for(iter_mi = 0; iter_mi < triTable_min[Index_mi][17]; iter_mi++)
                        IndexPolyTabMinVector.push_back(GridVoxelVarPt[IJK_mi].Edge_Points[triTable_min[Index_mi][iter_mi]]  + NbVertexTmp);
                }
                else if( nbpl_mi == 2)
                {
                    NbPolyMin += nbpl_mi;
                    /// First Poly:
                    IndexPolyTabMinVector.push_back(triTable_min[Index_mi][17]);
                    for(iter_mi = 0; iter_mi < triTable_min[Index_mi][17]; iter_mi++)
                        IndexPolyTabMinVector.push_back(GridVoxelVarPt[IJK_mi].Edge_Points[triTable_min[Index_mi][iter_mi]]  + NbVertexTmp);
                    /// Second Poly:
                    IndexPolyTabMinVector.push_back(triTable_min[Index_mi][18]);
                    for(iter_mi = triTable_min[Index_mi][17]; iter_mi < triTable_min[Index_mi][17]+triTable_min[Index_mi][18]; iter_mi++)
                        IndexPolyTabMinVector.push_back(GridVoxelVarPt[IJK_mi].Edge_Points[triTable_min[Index_mi][iter_mi]]  + NbVertexTmp);
                }
                else if( nbpl_mi > 2)
                {
                    NbPolyMin += nbpl_mi;
                    /// In this case we have only Triangles (3 or 4):
                    iter_mi = 0;
                    for(iterpl_mi = 0; iterpl_mi < nbpl_mi; iterpl_mi++)
                    {
                        IndexPolyTabMinVector.push_back(3);
                        IndexPolyTabMinVector.push_back(GridVoxelVarPt[IJK_mi].Edge_Points[triTable_min[Index_mi][iter_mi  ]]  + NbVertexTmp);
                        IndexPolyTabMinVector.push_back(GridVoxelVarPt[IJK_mi].Edge_Points[triTable_min[Index_mi][iter_mi+1]]  + NbVertexTmp);
                        IndexPolyTabMinVector.push_back(GridVoxelVarPt[IJK_mi].Edge_Points[triTable_min[Index_mi][iter_mi+2]]  + NbVertexTmp);
                        iter_mi +=3;
                    }
                }
            } /// End of for(k=0;
        } /// End of for(j=0;
    } /// End of for(i=0;
    return 1;
}

uint Iso3D::ConstructIsoSurface()
{
    uint Index, IndexFirstPoint, IndexSeconPoint, IndexThirdPoint;
    uint I_co, J_co, IJK_co;
    uint maxgrscalemaxgr = masterthread->GridVal*masterthread->GridVal;

    NbTriangleIsoSurface = 0;
    for(uint i=0; i+1 < masterthread->XYZgrid; i++)
    {
        I_co   = i*maxgrscalemaxgr;
        for(uint j=0; j+1 < masterthread->XYZgrid; j++)
        {
            J_co   = I_co+j*masterthread->GridVal;
            for(uint k=0; k+1 < masterthread->XYZgrid; k++)
            {
                IJK_co = J_co+k;
                Index = GridVoxelVarPt[IJK_co].Signature;
                for (uint l = 0; triTable[Index][l] != 111; l += 3)
                {
                    IndexFirstPoint = GridVoxelVarPt[IJK_co].Edge_Points[triTable[Index][l  ]];
                    IndexSeconPoint = GridVoxelVarPt[IJK_co].Edge_Points[triTable[Index][l+1]];
                    IndexThirdPoint = GridVoxelVarPt[IJK_co].Edge_Points[triTable[Index][l+2]];
                    IndexPolyTabVector.push_back(IndexFirstPoint + NbVertexTmp);
                    IndexPolyTabVector.push_back(IndexSeconPoint + NbVertexTmp);
                    IndexPolyTabVector.push_back(IndexThirdPoint + NbVertexTmp);
                    NbTriangleIsoSurface++;
                }
            }
        }
    }
    return 1;
}

uint Iso3D::PointEdgeComputation(uint isoindex)
{
    uint i_Start, i_End, j_Start, j_End, k_Start, k_End, i, j, k, XYZgridMinusOne=0;
    double vals[7], IsoValue_1, IsoValue_2, rapport;
    double factor;
    uint maxgridval=masterthread->GridVal;
    uint maxgrscalemaxgr = maxgridval*maxgridval;
    uint I_pl, J_pl, JK_pl, IJK_pl, IPLUSONEJK_pl, IMINUSONEJK,
         IJPLUSONEK, IJMINUSONEK, IMINUSONEJMINUSONEK, IsoValue=0, NbPointIsoMap_local=0;
    /// We have to compute the edges for the Grid limits ie: i=0, j=0 and k=0

    i_Start = 1/*+masterthread->iStart*/;
    j_Start = 1;
    k_Start = 1;
    XYZgridMinusOne = (masterthread->XYZgrid > 0) ? masterthread->XYZgrid-1 : 0;
    i_End = XYZgridMinusOne;
    j_End = XYZgridMinusOne;
    k_End = XYZgridMinusOne;
    /// The code is doubled to eliminate conditions tests

    for(i = i_Start; i < i_End; i++)
    {
        I_pl = i*maxgrscalemaxgr;
        for(j = j_Start; j < j_End; j++)
        {
            J_pl = I_pl + j*maxgridval;
            for(k = k_Start; k < k_End; k++)
            {
                IJK_pl                 = J_pl+k;
                IPLUSONEJK_pl          = IJK_pl + maxgrscalemaxgr;
                IMINUSONEJK         = IJK_pl - maxgrscalemaxgr;
                IJPLUSONEK          = IJK_pl + maxgridval;
                IJMINUSONEK         = IJK_pl - maxgridval;
                IMINUSONEJMINUSONEK = IMINUSONEJK - maxgridval;

                IsoValue_1 = Results[IJK_pl];
                /// First Case P(i+1)(j)(k)

                IsoValue_2 = Results[IPLUSONEJK_pl];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0 )
                {
                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i] + factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k];
                    ///===========================================================///
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));

                    // save The reference to this point
                    GridVoxelVarPt[IJK_pl].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK_pl].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    GridVoxelVarPt[IJMINUSONEK].Edge_Points[4] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJMINUSONEK].NbEdgePoint += 1;

                    GridVoxelVarPt[IJK_pl-1].Edge_Points[2]   = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK_pl-1].NbEdgePoint += 1;

                    GridVoxelVarPt[IJMINUSONEK-1].Edge_Points[6] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJMINUSONEK-1].NbEdgePoint += 1;

                    NbPointIsoMap_local++;
                }
                ///+++++++++++++++++++++++++++++++++++++++++
                /// Second Case P(i)(j+1)(k)

                IsoValue_2 = Results[IJPLUSONEK];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j] + factor * masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));

                    // save The reference to this point
                    GridVoxelVarPt[IJK_pl].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK_pl].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    GridVoxelVarPt[IMINUSONEJK].Edge_Points[9]    = NbPointIsoMap_local;
                    GridVoxelVarPt[IMINUSONEJK].NbEdgePoint += 1;

                    GridVoxelVarPt[IJK_pl-1].Edge_Points[11]   = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK_pl-1].NbEdgePoint += 1;

                    GridVoxelVarPt[IMINUSONEJK-1].Edge_Points[10] = NbPointIsoMap_local;
                    GridVoxelVarPt[IMINUSONEJK-1].NbEdgePoint += 1;

                    NbPointIsoMap_local++;
                }

                // Third Case P(i)(j)(k+1)

                IsoValue_2 = Results[IJK_pl+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k] + factor * masterthread->z_Step[isoindex];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));
                    // save The reference to this point
                    GridVoxelVarPt[IJK_pl].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK_pl].NbEdgePoint += 1;
                    // The same Point is used in three other Voxels
                    GridVoxelVarPt[IMINUSONEJK].Edge_Points[1]   = NbPointIsoMap_local;
                    GridVoxelVarPt[IMINUSONEJK].NbEdgePoint += 1;
                    GridVoxelVarPt[IJMINUSONEK].Edge_Points[7]   = NbPointIsoMap_local;
                    GridVoxelVarPt[IJMINUSONEK].NbEdgePoint += 1;
                    GridVoxelVarPt[IMINUSONEJMINUSONEK].Edge_Points[5] = NbPointIsoMap_local;
                    GridVoxelVarPt[IMINUSONEJMINUSONEK].NbEdgePoint += 1;
                    NbPointIsoMap_local++;
                }
            }
        }
    }

    /// Now we have to compute the Grid's limits...
    /// The code is quite big but this is much more easy to compute

    /// 1) First case : i =0;

    i =0;
    for(j=0; j < masterthread->XYZgrid; j++)
    {
        J_pl = j*maxgridval;
        for(k=0; k < masterthread->XYZgrid; k++)
        {
            JK_pl = J_pl +k;

            IsoValue_1 = Results[JK_pl];

            IsoValue_2 = Results[maxgrscalemaxgr+JK_pl];
            if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
            {
                // Edge Point computation and  save in IsoPointMap
                factor = (IsoValue - IsoValue_1)/rapport;

                vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i] + factor * masterthread->x_Step[isoindex];
                vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j];
                vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k];
                for(int iter=0; iter<7; iter++)
                    NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(float(vals[0]));
                NormVertexTabVector.push_back(float(vals[1]));
                NormVertexTabVector.push_back(float(vals[2]));

                // save The reference to this point
                GridVoxelVarPt[JK_pl].Edge_Points[0] = NbPointIsoMap_local;
                GridVoxelVarPt[JK_pl].NbEdgePoint += 1;

                // The same Point is used in three other Voxels
                if( j != 0)
                {
                    GridVoxelVarPt[JK_pl-maxgridval].Edge_Points[4] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK_pl-maxgridval].NbEdgePoint += 1;
                }
                if ( k != 0 )
                {
                    GridVoxelVarPt[JK_pl-1].Edge_Points[2]   = NbPointIsoMap_local;
                    GridVoxelVarPt[JK_pl-1].NbEdgePoint += 1;
                }
                if( j != 0 && k != 0)
                {
                    GridVoxelVarPt[JK_pl-maxgridval-1].Edge_Points[6] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK_pl-maxgridval-1].NbEdgePoint += 1;
                }

                NbPointIsoMap_local++;
            }

            // Second Case P(0)(j+1)(k)
            if ( j != (XYZgridMinusOne))
            {
                IsoValue_2 = Results[JK_pl+maxgridval];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j] + factor *masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));
                    // save The reference to this point
                    GridVoxelVarPt[JK_pl].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK_pl].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if ( k != 0)
                    {
                        GridVoxelVarPt[JK_pl-1].Edge_Points[11]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK_pl-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;
                }
            } /// If ( j != nb_colon -1) ...

            // Third Case P(0)(j)(k+1)
            if ( k != (XYZgridMinusOne))
            {
                IsoValue_2 = Results[JK_pl+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k] + factor * masterthread->z_Step[isoindex];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));

                    // save The reference to this point
                    GridVoxelVarPt[JK_pl].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK_pl].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if ( j != 0)
                    {
                        GridVoxelVarPt[JK_pl-maxgridval].Edge_Points[7]   =NbPointIsoMap_local;
                        GridVoxelVarPt[JK_pl-maxgridval].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of ( if ( k != nb_depth -1)....
        }
    }
    /// 2) Case i = nb_ligne-1

    i = XYZgridMinusOne;
    I_pl = i*maxgrscalemaxgr;
    for(j=0; j < masterthread->XYZgrid; j++)
    {
        J_pl = I_pl + j*maxgridval;
        for(k=0; k < masterthread->XYZgrid; k++)
        {
            JK_pl = J_pl + k;

            IsoValue_1 = Results[JK_pl];


            // Second Case P(i)(j+1)(k)
            if ( j != (XYZgridMinusOne))
            {
                IsoValue_2 = Results[JK_pl+maxgridval];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j] + factor *masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));

                    // save The reference to this point
                    GridVoxelVarPt[JK_pl].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK_pl].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if(i != 0)
                    {
                        GridVoxelVarPt[JK_pl-maxgrscalemaxgr].Edge_Points[9]    =NbPointIsoMap_local;
                        GridVoxelVarPt[JK_pl-maxgrscalemaxgr].NbEdgePoint += 1;
                    }
                    if(k != 0)
                    {
                        GridVoxelVarPt[JK_pl-1].Edge_Points[11]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK_pl-1].NbEdgePoint += 1;
                    }
                    if(i != 0 && k != 0)
                    {
                        GridVoxelVarPt[JK_pl-maxgrscalemaxgr-1].Edge_Points[10] = NbPointIsoMap_local;
                        GridVoxelVarPt[JK_pl-maxgrscalemaxgr-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if (j != nb_colon -1)...

            // Third Case P(i)(j)(k+1)
            if ( k != (XYZgridMinusOne))
            {
                IsoValue_2 = Results[JK_pl+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k] + factor * masterthread->z_Step[isoindex];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));

                    // save The reference to this point
                    GridVoxelVarPt[JK_pl].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK_pl].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( i != 0)
                    {
                        GridVoxelVarPt[JK_pl-maxgrscalemaxgr].Edge_Points[1]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK_pl-maxgrscalemaxgr].NbEdgePoint += 1;
                    }
                    if(j != 0)
                    {
                        GridVoxelVarPt[JK_pl-maxgridval].Edge_Points[7]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK_pl-maxgridval].NbEdgePoint += 1;
                    }
                    if( i !=0 && j != 0)
                    {
                        GridVoxelVarPt[JK_pl-maxgrscalemaxgr-maxgridval].Edge_Points[5] = NbPointIsoMap_local;
                        GridVoxelVarPt[JK_pl-maxgrscalemaxgr-maxgridval].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if ( k != nb_depth -1)...
        }
    }

    /// 3) Case j = 0
    j= 0;

    for(i=0; i < masterthread->XYZgrid; i++)
        for(k=0; k < masterthread->XYZgrid; k++)
        {

            IsoValue_1 = Results[i*maxgrscalemaxgr+k];

            // First Case P(i+1)(j)(k)
            if( i != (XYZgridMinusOne))
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+k];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {

                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i] + factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+k].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( k!=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+k-1].Edge_Points[2]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+k-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;
                }
            } /// End of if ( i != nb_ligne -1)...

            // Second Case P(i)(j+1)(k)

            IsoValue_2 = Results[i*maxgrscalemaxgr+maxgridval+k];
            // Edge Point computation and  save in IsoPointMap
            if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
            {
                factor = (IsoValue - IsoValue_1)/rapport;

                vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i];
                vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j] + factor * masterthread->y_Step[isoindex];
                vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k];
                for(int iter=0; iter<7; iter++)
                    NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(float(vals[0]));
                NormVertexTabVector.push_back(float(vals[1]));
                NormVertexTabVector.push_back(float(vals[2]));

                // save The reference to this point
                GridVoxelVarPt[i*maxgrscalemaxgr+k].Edge_Points[8] = NbPointIsoMap_local;
                GridVoxelVarPt[i*maxgrscalemaxgr+k].NbEdgePoint += 1;

                // The same Point is used in three other Voxels
                if( i !=0 )
                {
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+k].Edge_Points[9]    = NbPointIsoMap_local;
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+k].NbEdgePoint += 1;
                }
                if(k !=0)
                {
                    GridVoxelVarPt[i*maxgrscalemaxgr+k-1].Edge_Points[11]   = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+k-1].NbEdgePoint += 1;
                }
                if( i !=0 && k !=0)
                {
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+k-1].Edge_Points[10] = NbPointIsoMap_local;
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+k-1].NbEdgePoint += 1;
                }
                NbPointIsoMap_local++;
            }


            // Third Case P(i)(j)(k+1)
            if(k != (XYZgridMinusOne))
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+k+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k] + factor * masterthread->z_Step[isoindex];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+k].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( i != 0)
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+k].Edge_Points[1]   = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+k].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if(k != (nb_depth -1))...
        }
    /// 4) Case j = nb_colon -1
    j = XYZgridMinusOne;

    for(i=0; i < masterthread->XYZgrid; i++)
        for(k=0; k < masterthread->XYZgrid; k++)
        {
            IsoValue_1 = Results[i*maxgrscalemaxgr+j*maxgridval+k];
            // First Case P(i+1)(j)(k)
            if( i != (XYZgridMinusOne))
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+j*maxgridval+k];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {

                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i] + factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));
                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].NbEdgePoint += 1;
                    // The same Point is used in three other Voxels
                    if( j != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k].Edge_Points[4] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k].NbEdgePoint += 1;
                    }
                    if(k != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k-1].Edge_Points[2]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k-1].NbEdgePoint += 1;
                    }
                    if(j != 0 && k != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k-1].Edge_Points[6] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k-1].NbEdgePoint += 1;
                    }
                    NbPointIsoMap_local++;
                }
            } /// End of if( i != (nb_ligne-1))...

            // Third Case P(i)(j)(k+1)
            if( k != (XYZgridMinusOne))
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+j*maxgridval+k+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k] + factor * masterthread->z_Step[isoindex];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));
                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].NbEdgePoint += 1;
                    // The same Point is used in three other Voxels
                    if(i !=0)
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval+k].Edge_Points[1]   = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval+k].NbEdgePoint += 1;
                    }
                    if( j!=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k].Edge_Points[7]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k].NbEdgePoint += 1;
                    }
                    if(i != 0 && j !=0)
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*maxgridval+k].Edge_Points[5] = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*maxgridval+k].NbEdgePoint += 1;
                    }
                    NbPointIsoMap_local++;
                }
            } /// End of if (k != nb_depth)...
        }

    /// 5) Case k = 0

    k =0;

    for(i=0; i < masterthread->XYZgrid; i++)
        for(j=0; j < masterthread->XYZgrid; j++)
        {
            IsoValue_1 = Results[i*maxgrscalemaxgr+j*maxgridval];
            // First Case P(i+1)(j)(k)
            if(i != (XYZgridMinusOne))
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+j*maxgridval];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i] + factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));
                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval].NbEdgePoint += 1;
                    // The same Point is used in one other Voxel
                    if(j !=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval].Edge_Points[4] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval].NbEdgePoint += 1;
                    }
                    NbPointIsoMap_local++;
                }
            } /// End of if(i != (nb_ligne -1))

            // Second Case P(i)(j+1)(k)
            if(j != XYZgridMinusOne)
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+(j+1)*maxgridval];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;

                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j] + factor * masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));
                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval].NbEdgePoint += 1;
                    // The same Point is used in one other Voxels
                    if ( i !=0 )
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval].Edge_Points[9]    = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval].NbEdgePoint += 1;
                    }
                    NbPointIsoMap_local++;
                }
            }/// End of if(j != nb_colon -1)...
            // Third Case P(i)(j)(k+1)
            IsoValue_2 = Results[i*maxgrscalemaxgr+j*maxgridval+1];
            // Edge Point computation and  save in IsoPointMap
            if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
            {
                factor = (IsoValue - IsoValue_1)/rapport;

                vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i];
                vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j];
                vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k] + factor * masterthread->z_Step[isoindex];
                for(int iter=0; iter<7; iter++)
                    NormVertexTabVector.push_back(1.0);
                NormVertexTabVector.push_back(float(vals[0]));
                NormVertexTabVector.push_back(float(vals[1]));
                NormVertexTabVector.push_back(float(vals[2]));
                // save The reference to this point
                GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval].Edge_Points[3] = NbPointIsoMap_local;
                GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval].NbEdgePoint += 1;

                // The same Point is used in three other Voxels
                if ( i !=0 )
                {
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval].Edge_Points[1]   = NbPointIsoMap_local;
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval].NbEdgePoint += 1;
                }
                if (j != 0 )
                {
                    GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval].Edge_Points[7]   = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval].NbEdgePoint += 1;
                }
                if ( i !=0 && j != 0 )
                {
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*maxgridval].Edge_Points[5] = NbPointIsoMap_local;
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*maxgridval].NbEdgePoint += 1;
                }
                NbPointIsoMap_local++;
            }
        }

    /// 6) Case k = nb_depth -1

    k = XYZgridMinusOne;
    for(i=0; i < masterthread->XYZgrid; i++)
        for(j=0; j < masterthread->XYZgrid; j++)
        {
            IsoValue_1 = Results[i*maxgrscalemaxgr+j*maxgridval+k];
            // First Case P(i+1)(j)(k)
            if( i != (XYZgridMinusOne) )
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+j*maxgridval+k];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i] + factor * masterthread->x_Step[isoindex];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));
                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].NbEdgePoint += 1;
                    // The same Point is used in three other Voxels
                    if(j !=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k].Edge_Points[4] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k].NbEdgePoint += 1;
                    }
                    if(k !=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k-1].Edge_Points[2]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k-1].NbEdgePoint += 1;
                    }
                    if(j !=0 && k != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k-1].Edge_Points[6] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maxgridval+k-1].NbEdgePoint += 1;
                    }
                    NbPointIsoMap_local++;
                }
            } /// End of if(i != nb_ligne-1)...

            // Second Case P(i)(j+1)(k)
            if( j != (XYZgridMinusOne) )
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+(j+1)*maxgridval+k];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1) != 0.0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    vals[0] = masterthread->xLocal2[isoindex*masterthread->GridVal+i];
                    vals[1] = masterthread->yLocal2[isoindex*masterthread->GridVal+j] + factor * masterthread->y_Step[isoindex];
                    vals[2] = masterthread->zLocal2[isoindex*masterthread->GridVal+k];
                    for(int iter=0; iter<7; iter++)
                        NormVertexTabVector.push_back(1.0);
                    NormVertexTabVector.push_back(float(vals[0]));
                    NormVertexTabVector.push_back(float(vals[1]));
                    NormVertexTabVector.push_back(float(vals[2]));

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( i !=0 )
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval+k].Edge_Points[9]    = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval+k].NbEdgePoint += 1;
                    }
                    if( k !=0 )
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k-1].Edge_Points[11]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maxgridval+k-1].NbEdgePoint += 1;
                    }
                    if( i !=0 && k !=0 )
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval+k-1].Edge_Points[10] = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maxgridval+k-1].NbEdgePoint += 1;
                    }
                    NbPointIsoMap_local++;
                }
            } /// End of if( j != (nb_colon -1) )...
        }
    NbPointIsoMap =    NbPointIsoMap_local;
    return 1;
}
void Iso3D::SignatureComputation()
{
    uint I_si, J_si, IJK_si, IPLUSONEJK_si,
         IJPLUSONEK_si,  IPLUSONEJPLUSONEK_si,
        XYZgridMinusOne=(masterthread->XYZgrid > 0) ? masterthread->XYZgrid-1 : 0;
    uint maxgrscalemaxgr = masterthread->GridVal*masterthread->GridVal;
    for(uint i=0; i < masterthread->XYZgrid; i++)
    {
        I_si = i*maxgrscalemaxgr;
        for(uint j=0; j < masterthread->XYZgrid; j++)
        {
            J_si = I_si + j*masterthread->GridVal;
            for(uint k=0; k < masterthread->XYZgrid; k++)
            {
                IJK_si               = J_si + k;
                IPLUSONEJK_si        = IJK_si + maxgrscalemaxgr;
                IJPLUSONEK_si        = IJK_si + masterthread->GridVal;
                IPLUSONEJPLUSONEK_si = IPLUSONEJK_si + masterthread->GridVal;

                if(Results[IJK_si] <= 0) GridVoxelVarPt[IJK_si].Signature +=1;

                if(i != (XYZgridMinusOne))
                    if(Results[IPLUSONEJK_si] <= 0) GridVoxelVarPt[IJK_si].Signature +=2;

                if(i != (XYZgridMinusOne) && k != (XYZgridMinusOne))
                    if(Results[IPLUSONEJK_si+1] <= 0) GridVoxelVarPt[IJK_si].Signature +=4;

                if(k != (XYZgridMinusOne))
                    if(Results[IJK_si+1] <= 0) GridVoxelVarPt[IJK_si].Signature +=8;

                if(j != (XYZgridMinusOne))
                    if(Results[IJPLUSONEK_si] <= 0) GridVoxelVarPt[IJK_si].Signature +=16;

                if(i != (XYZgridMinusOne) && j != (XYZgridMinusOne))
                    if(Results[IPLUSONEJPLUSONEK_si] <= 0) GridVoxelVarPt[IJK_si].Signature +=32;

                if(i != (XYZgridMinusOne) && j != (XYZgridMinusOne) && k != (XYZgridMinusOne))
                    if(Results[IPLUSONEJPLUSONEK_si+1] <= 0) GridVoxelVarPt[IJK_si].Signature +=64;

                if(j != (XYZgridMinusOne) && k != (XYZgridMinusOne))
                    if(Results[IJPLUSONEK_si+1] <= 0) GridVoxelVarPt[IJK_si].Signature +=128;
            }
        }
    }// End if(Grid...
}
