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
 *   51 Franklin Street, Fifth Floor,Boston, MA 02110-1301 USA             *
 ***************************************************************************/

#include <map>
#include <vector>
#include <iostream>
#include <string.h>
#include <cmath>
#include "../objectparameters.h"
#include "ND/Matrix4D.h"
#include <qthread.h>
using std::string;

struct   ParStruct
{
    std::string fx;
    std::string fy;
    std::string fz;
    std::string fw;
    std::string cnd;
    std::string umin;
    std::string umax;
    std::string vmin;
    std::string vmax;
    std::string grid;
    int  index;
};

class ParWorkerThread : public WorkerThread
{
    Q_OBJECT
public :
    uint Ugrid, Vgrid;
    FunctionParser * myParserX, * myParserY,* myParserZ, *myParserW, *Fct;
    std::vector<double>  v_inf, v_sup,u_inf,u_sup,dif_v,dif_u;
    int param4D;
    uint CurrentIndex;

public :
    void ParCompute(uint, uint);
    void calcul_objet(uint component =0, uint idx=0);
    void AllocateParsersForWorkerThread(uint, uint);
    void DeleteWorkerParsers();
    void run() Q_DECL_OVERRIDE;
    ParWorkerThread();
    ~ParWorkerThread() override;
    void emitMySignal();
signals:
    void mySignal(int);

};

class ParMasterThread : public MasterThread, public ParWorkerThread
{
public :


    FunctionParser *myParserUmin,*myParserUmax,
                   *myParserVmin,*myParserVmax;
    std::vector<ParStruct> ParamStructs;
    uint componentsNumber;
    std::string  expression_X, expression_Y, expression_Z, expression_W, expression_CND, inf_u, sup_u, inf_v, sup_v;
    int expression_YSize, expression_ZSize, expression_WSize,
        inf_uSize, sup_uSize, inf_vSize, sup_vSize;
public :
    void InitMasterParsers();
    void  HowManyParamSurface(std::string, int);
    uint  HowManyVariables(std::string, int);
    ErrorMessage parse_expression();
    void AllocateParsersForMasterThread();
    void AllocateParsersForThread();
    void DeleteMasterParsers();
    ParMasterThread();
    ~ParMasterThread();
};

/** The representation of a 3D model */
class Par3D   : public QThread
{
    Q_OBJECT
public:
    ObjectProperties *localScene;
    ParMasterThread *masterthread;
    ParWorkerThread *workerthreads;
    float *Border;
    bool StopCalculations;
    uint WorkerThreadsNumber;
    uint Ugrid, Vgrid;
    uint CutV, CutU;
    float MINX,MINY,MINZ,MINW,
           MAXX,MAXY,MAXZ,MAXW,
           DIFX,DIFY,DIFZ,DIFW,
           DIFMAXIMUM;
    Matrix4D mat4D, mat_rotation4D, mat_rotation_save4D,
             mat_homothetie4D, mat_translation4D, mat_inversetranslation4D;
    double tetaxy, tetaxz, tetayz, tetaxw, tetayw, tetazw;

    int tetaxy_ok, tetaxz_ok, tetayz_ok, tetaxw_ok, tetayw_ok, tetazw_ok, param4D;
    ScriptErrorType messageerror;
    QString message;
public:
    Par3D(uint nbThreads, uint nbGrid);
    ~Par3D()  override;
    void rotation4();
    void calcul_points4(uint idx=0);
    void Anim_Rot4D (uint idx=0);
    void project_4D_to_3D(uint idx=0);
    void Invert_boite_englobante4D(uint idx=0);
    void boite_englobante4D(uint index=0);
    void initialiser_parametres(uint, uint);
    void initialiser_LineColumn(uint, uint);
    void calcul_Norm(uint i=0);
    void make_PolyIndexTri(uint p=0);
    void make_PolyIndexMin(uint p=0);
    uint CNDtoUse(uint, struct ComponentInfos*);
    uint CNDCalculation(uint &, struct ComponentInfos *);
    void CalculateColorsPoints(struct ComponentInfos *, uint);
    void clear(struct ComponentInfos*);
    void ParamBuild(float **, uint **, uint *,
                    uint *, ComponentInfos *,
                    uint **,
                    uint *);
    void BuildPar();
    void UpdateThredsNumber(uint);
    void stopcalculations(bool);
    void WorkerThreadCopy(ParWorkerThread *);
    void MasterThreadCopy(ParMasterThread *);
    ErrorMessage ThreadParsersCopy();
    ErrorMessage  parse_expression2();
    ErrorMessage  ParMorph();
    void copycomponent(struct ComponentInfos*, struct ComponentInfos*);
    void run() Q_DECL_OVERRIDE;
public :
    void emitErrorSignal();
    void emitUpdateMessageSignal();
signals:
    void ErrorSignal(int);
    void UpdateMessageSignal(QString);
};
