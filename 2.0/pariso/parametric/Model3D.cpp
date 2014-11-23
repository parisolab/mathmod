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
 *   51 Franklin Street, Fifth Floor,Boston, MA 02110-1301 USA             *
 ***************************************************************************/
#include "Model3D.h"

static int PreviousSizeMinimalTopology =0;
static int NbPolyMinimalTopology =0;
static int NbVertexTmp = 0;

//+++++++++++++++++++++++++++++++++++++++++
Par3D::~Par3D()
{
}

//+++++++++++++++++++++++++++++++++++++++++
Par3D::Par3D()
{
    initparser(100);
    initialiser_parametres();
    initialiser_parseur();
}

//+++++++++++++++++++++++++++++++++++++++++
void Par3D::initialiser_parametres()
{
    nb_licol = 25;
    nb_ligne = nb_colone = nb_licol;
    largeur_fenetre = 620;
    hauteur_fenetre = 620;
    mesh = 1;
    infos =1;
    latence = 30;
    stepMorph = 0;
    pace = (double)1/(double)30;
    coupure_col = coupure_ligne = 0;
    activeMorph = -1;
    ParConditionRequired = -1;
    tetazw = tetaxy =  tetaxz = tetayz = tetaxw = tetayw =  0;
    tetazw_ok = tetaxy_ok =  tetaxz_ok = tetayz_ok = tetaxw_ok = tetayw_ok =  param4D = -1;
    // initialisation des matrices 4D
    mat4D                                     = Matrix4D();
    mat_rotation4D                      = Matrix4D();
    mat_rotation_save4D           = Matrix4D();
    mat_homothetie4D               = Matrix4D();
    mat_translation4D                 = Matrix4D();
    mat_inversetranslation4D    = Matrix4D();
    mat4D.unit();
}

//+++++++++++++++++++++++++++++++++++++++++
void Par3D::initialiser_parseur()
{
    for(int i=0; i<100; i++)
    {
        myParserUmin[i].AddConstant   ("pi", 3.14159265);
        myParserUmax[i].AddConstant   ("pi", 3.14159265);
        myParserVmin[i].AddConstant   ("pi", 3.14159265);
        myParserVmax[i].AddConstant   ("pi", 3.14159265);
        myParserX[i].AddConstant("pi", 3.14159265);
        myParserY[i].AddConstant("pi", 3.14159265);
        myParserZ[i].AddConstant("pi", 3.14159265);
        myParserCND[i].AddConstant("pi", 3.14159265);
    }
}


//++++++++++++++++++++++++++++++++++++++++
void  Par3D::rotation4()
{
    mat_rotation4D.unit();
    // Construction de la matrice de trnsformation
    if(tetaxy_ok == 1)    mat_rotation4D.xyrot(tetaxy);
    if(tetaxz_ok == 1)    mat_rotation4D.xzrot(tetaxz);
    if(tetayz_ok == 1)    mat_rotation4D.yzrot(tetayz);

    if(tetaxw_ok == 1)    mat_rotation4D.xwrot(tetaxw);
    if(tetayw_ok == 1)    mat_rotation4D.ywrot(tetayw);
    if(tetazw_ok == 1)    mat_rotation4D.zwrot(tetazw);

// On applique cette transformation a la matrice principale "mat"
    mat4D.mult(mat_rotation4D);
}

//+++++++++++++++++++++++++++++++++++++++++
void  Par3D::boite_englobante4D(int idx)
{
    MINX =999999999;
    MINY =999999999;
    MINZ =999999999;
    MINW =999999999;

    MAXX =-999999999;
    MAXY =-999999999;
    MAXZ =-999999999;
    MAXW =-999999999;

    int IDX = 0;
    for (int i=0; i < nb_ligne; i++)
        for (int j=0; j < nb_colone; j++)
        {
            if(MINX > NormVertexTab[IDX + 3 + idx*6] ) MINX = NormVertexTab[IDX + 3 + idx*6];
            if(MINY > NormVertexTab[IDX + 4 + idx*6] ) MINY = NormVertexTab[IDX + 4 + idx*6];
            if(MINZ > NormVertexTab[IDX + 5 + idx*6] ) MINZ = NormVertexTab[IDX + 5 + idx*6];
            if(MINW > ExtraDimension[i*nb_ligne + j + idx] ) MINW = ExtraDimension[i*nb_ligne + j + idx];

            if(MAXX < NormVertexTab[IDX + 3 + idx*6] ) MAXX = NormVertexTab[IDX + 3 + idx*6];
            if(MAXY < NormVertexTab[IDX + 4 + idx*6] ) MAXY = NormVertexTab[IDX + 4 + idx*6];
            if(MAXZ < NormVertexTab[IDX + 5 + idx*6] ) MAXZ = NormVertexTab[IDX + 5 + idx*6];
            if(MAXW < ExtraDimension[i*nb_ligne + j + idx] ) MAXW = ExtraDimension[i*nb_ligne + j + idx];
            IDX +=6;
        }

    DIFX = MAXX - MINX ;
    DIFY = MAXY - MINY ;
    DIFZ = MAXZ - MINZ ;
    DIFW = MAXW - MINW ;
// Recherche du maximum :
    DIFMAXIMUM = DIFX;
    if (DIFY > DIFMAXIMUM)
    {
        DIFMAXIMUM = DIFY;
    };
    if (DIFZ > DIFMAXIMUM)
    {
        DIFMAXIMUM = DIFZ;
    };
    if (DIFW > DIFMAXIMUM)
    {
        DIFMAXIMUM = DIFW;
    };
// On va inclure cet objet dans un HperCube de langueur maximum
// egale a "hauteur_fenetre"

    double decalage_xo  = -(MINX +MAXX)/2 ;
    double decalage_yo  = -(MINY +MAXY)/2 ;
    double decalage_zo  = -(MINZ +MAXZ)/2 ;
    double decalage_wo = -(MINW +MAXW)/2 ;
    IDX =0;
    for (int i=0; i < nb_ligne   ; i++)
        for (int j=0; j < nb_colone   ; j++)
        {
            NormVertexTab[IDX + 3 + idx*6]= (NormVertexTab[IDX + 3 + idx*6] + decalage_xo)/DIFMAXIMUM ;
            NormVertexTab[IDX + 4 + idx*6] = (NormVertexTab[IDX + 4 + idx*6] + decalage_yo)/DIFMAXIMUM ;
            NormVertexTab[IDX + 5 + idx*6] = (NormVertexTab[IDX + 5 + idx*6] + decalage_zo)/DIFMAXIMUM ;
            ExtraDimension[i*nb_ligne + j + idx] = (ExtraDimension[i*nb_ligne + j + idx] + decalage_wo)/DIFMAXIMUM ;
            IDX +=6;
        }
}

//+++++++++++++++++++++++++++++++++++++++++
void  Par3D::Invert_boite_englobante4D(int idx)
{
    double decalage_xo  = -(MINX +MAXX)/2;
    double decalage_yo  = -(MINY +MAXY)/2;
    double decalage_zo  = -(MINZ +MAXZ)/2;
    int IDX =0;
    for (int i=0; i < nb_ligne   ; i++)
        for (int j=0; j < nb_colone   ; j++)
        {
            NormVertexTab[IDX + 3 + idx*6] = (NormVertexTab[IDX + 3 + idx*6]*DIFMAXIMUM -  decalage_xo);
            NormVertexTab[IDX + 4 + idx*6] = (NormVertexTab[IDX + 4 + idx*6]*DIFMAXIMUM -  decalage_yo);
            NormVertexTab[IDX + 5 + idx*6] = (NormVertexTab[IDX + 5 + idx*6]*DIFMAXIMUM -  decalage_zo);
            IDX +=6;
        }
}

//+++++++++++++++++++++++++++++++++++++++++
void Par3D::Anim_Rot4D (int idx)
{
    rotation4();
    calcul_points4(idx);         // On applique la rotation 4D
    boite_englobante4D(idx);
    project_4D_to_3D(idx);
    Invert_boite_englobante4D(idx);
}

//+++++++++++++++++++++++++++++++++++++++++
void  Par3D::calcul_points4(int idx)
{
    int i,j;
    double tp1, tp2, tp3, tp4;
// Changement de coordonnees des points selon les
// angles angex et angley
    int lndex =0;
    for (i=0; i < nb_ligne  ; i++)
        for (j=0; j < nb_colone   ; j++)
        {
            tp1 = NormVertexTab[lndex + 3 + idx*6];
            tp2 = NormVertexTab[lndex + 4 + idx*6];
            tp3 = NormVertexTab[lndex + 5 + idx*6];
            tp4 = ExtraDimension[i*nb_ligne + j + idx];

            NormVertexTab[lndex + 3 + idx*6] = mat4D.xx*tp1 + mat4D.xy*tp2 + mat4D.xz*tp3 + mat4D.xw*tp4 + mat4D.xo;
            NormVertexTab[lndex + 4 + idx*6] = mat4D.yx*tp1 + mat4D.yy*tp2 + mat4D.yz*tp3 + mat4D.yw*tp4 + mat4D.yo;
            NormVertexTab[lndex + 5 + idx*6] = mat4D.zx*tp1 + mat4D.zy*tp2 + mat4D.zz*tp3 + mat4D.zw*tp4 + mat4D.zo;
            ExtraDimension[i*nb_ligne + j + idx] = mat4D.wx*tp1 + mat4D.wy*tp2 + mat4D.wz*tp3 + mat4D.ww*tp4 + mat4D.wo;
            lndex += 6;
        }
}

//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::project_4D_to_3D(int idx)
{
    double c4;
    int I = 0;
    for (int i=0; i < nb_ligne; ++i)
        for (int j=0; j < nb_colone  ; ++j)
        {
            c4 = 1/(ExtraDimension[i*nb_ligne + j + idx] - 2);
            NormVertexTab[I + 3 + idx*6] *= c4;
            NormVertexTab[I + 4 + idx*6] *= c4;
            NormVertexTab[I + 5 + idx*6] *= c4;
            I += 6;
        }
}

//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::calcul_objet(int NewPosition,  int cmp)
{
    double vals[] = {0,0,0};
    double iprime, jprime;

    if(stepMorph < 0)
    {
        pace = (double)1/(double)30;
    }
    if(stepMorph > 1)
    {
        pace = -(double)1/(double)30;
    }
    if((cmp == 0) && (activeMorph == 1))
        stepMorph += pace;

    vals[2]          = stepMorph;
    int l=0;
    for(int j=0; j < nb_ligne   ; j++)
    {
        jprime = (double)j/(double)(nb_ligne -1 ) ;
        jprime = jprime * dif_u[cmp]  + u_inf[cmp] ;
        for (int i=0; i < nb_colone   ; i++)
        {
            iprime = (double)i/(double)(nb_colone-1 ) ;
            iprime = iprime * dif_v[cmp]  + v_inf[cmp] ;
            vals[0]=jprime;
            vals[1]=iprime;
            NormVertexTab[l+3+NewPosition] = myParserX[cmp].Eval(vals);
            NormVertexTab[l+4+NewPosition] = myParserY[cmp].Eval(vals);
            NormVertexTab[l+5+NewPosition] = myParserZ[cmp].Eval(vals);
            l+=6;
            if(param4D == 1)
                ExtraDimension[j*nb_colone + i + (int)(NewPosition/6)] = myParserW[cmp].Eval(vals);
        }
    }
}

//+++++++++++++++++++++++++++++++++++++++++
void Par3D::initparser(int N)
{
    delete[] myParserX;
    myParserX = new FunctionParser[N];

    delete[] myParserY;
    myParserY = new FunctionParser[N];

    delete[] myParserZ;
    myParserZ = new FunctionParser[N];

    delete[] Fct;
    Fct = new FunctionParser[N];

    for(int i=0; i<N; i++)
    {
        myParserX[i].AddConstant("pi", 3.14159265);
        myParserY[i].AddConstant("pi", 3.14159265);
        myParserZ[i].AddConstant("pi", 3.14159265);
        myParserCND[i].AddConstant("pi", 3.14159265);
        Fct[i].AddConstant("pi", 3.14159265);
    }
}


ErrorMessage  Par3D::parse_expression()
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::string varliste = "x,y,z,t";

    initparser(100);
    (Const != "") ? Nb_constants = HowManyVariables(Const, 1) : Nb_constants =0;
    for(int j=0; j<Nb_constants; j++)
    {
       if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u")) >= 0)
       {
            stdError.strError = Consts[j];
            stdError.strOrigine = ConstNames[j];
            return stdError;
       }
       Cstparser.AddConstant(ConstNames[j], Cstparser.Eval(vals));
    }

    if(Funct != "")
    {
        Nb_functs = HowManyVariables(Funct, 2);

        for(int i=0; i<Nb_functs; i++)
        {
            for(int j=0; j<Nb_constants; j++)
            {
                if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u")) >= 0)
                {
                     stdError.strError = Consts[j];
                     stdError.strOrigine = ConstNames[j];
                     return stdError;
                }
                Fct[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            }
        }

        //initparser(100);
        for(int i=0; i<Nb_functs; i++)
        {
            for(int j=0; j<i; j++)
                Fct[i].AddFunction(FunctNames[j], Fct[j]);
            if ((stdError.iErrorIndex = Fct[i].Parse(Functs[i],"u,v,t")) >= 0)
            {
                stdError.strError = Functs[i];
                stdError.strOrigine = FunctNames[i];
                return stdError;
            }
        }
    }
    else
    {
        Nb_functs =0;
    }

    if(Varu != "")
    {
        Nb_newvariables = HowManyVariables(Varu, 0);

        for(int i=0; i<Nb_newvariables; i++)
        {
            for(int j=0; j<Nb_constants; j++)
            {
                if ((stdError.iErrorIndex =Cstparser.Parse(Consts[j],"u")) >= 0)
                {
                    stdError.strError = Consts[j];
                    stdError.strOrigine = ConstNames[j];
                    return stdError;
                }
                Var[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            }
        }

        for(int i=0; i<Nb_newvariables; i++)
        {
            if ((stdError.iErrorIndex =Var[i].Parse(Varus[i],"u,tm")) >= 0)
            {
                stdError.strError = Varus[i];
                stdError.strOrigine = VarName[i];
                return stdError;
            }
            varliste += ","+VarName[i]+"x,"+VarName[i]+"y,"+VarName[i]+"z";
        }
    }
    else
    {
        Nb_newvariables =0;
    }

    Nb_paramfunctions = HowManyParamSurface(expression_X, 0);
    HowManyParamSurface(expression_Y, 1);
    HowManyParamSurface(expression_Z, 2);
    HowManyParamSurface(inf_u, 3);
    HowManyParamSurface(sup_u, 4);
    HowManyParamSurface(inf_v, 5);
    HowManyParamSurface(sup_v, 6);
    if(param4D == 1)
        HowManyParamSurface(expression_W, 7);
    if(expression_CND != "")
    {
        ParConditionRequired = 1;
        HowManyParamSurface(expression_CND, 8);
    }
    else
        ParConditionRequired = -1;

    FunctionParser tmp;
    tmp.AddConstant   ("pi", 3.14159265);
    // Add defined functions :
    for(int i=0; i<Nb_paramfunctions+1; i++)
    {
        myParserX[i]= tmp ;
        myParserY[i]= tmp ;
        myParserZ[i]= tmp ;
        myParserCND[i]= tmp ;
        myParserUmin[i]= tmp ;
        myParserUmax[i]= tmp ;
        myParserVmin[i]= tmp ;
        myParserVmax[i]= tmp ;
    }



    //Add defined constantes:
    for(int i=0; i<Nb_paramfunctions+1; i++)
    {
        for(int j=0; j<Nb_constants; j++)
        {
            if ((stdError.iErrorIndex =Cstparser.Parse(Consts[j],"u")) >= 0)
            {
                stdError.strError = Consts[j];
                stdError.strOrigine = ConstNames[j];
                return stdError;
            }

            if(expression_CND != "")
                myParserCND[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserUmax[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserVmin[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserVmax[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserX[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserY[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            myParserZ[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
        }
    }

    // Add defined functions :
    for(int i=0; i<Nb_paramfunctions+1; i++)
    {
        for(int j=0; j<Nb_functs; j++)
        {
            myParserX[i].AddFunction(FunctNames[j], Fct[j]);
            myParserY[i].AddFunction(FunctNames[j], Fct[j]);
            myParserZ[i].AddFunction(FunctNames[j], Fct[j]);
            myParserCND[i].AddFunction(FunctNames[j], Fct[j]);
        }
    }

    for(int index=0; index< Nb_paramfunctions + 1; index++)
    {
        if ((stdError.iErrorIndex = myParserUmin[index].Parse(ParamStructs[index].umin, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].umin;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }
        u_inf[index] = myParserUmin[index].Eval(vals);

        if ((stdError.iErrorIndex = myParserUmax[index].Parse(ParamStructs[index].umax, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].umax;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }
        u_sup[index] = myParserUmax[index].Eval(vals);
        dif_u[index] = u_sup[index] - u_inf[index];

        if ((stdError.iErrorIndex = myParserVmin[index].Parse(ParamStructs[index].vmin, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].vmin;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }
        v_inf[index] = myParserVmin[index].Eval(vals);

        if ((stdError.iErrorIndex = myParserVmax[index].Parse(ParamStructs[index].vmax, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].vmax;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }
        v_sup[index] = myParserVmax[index].Eval(vals);
        dif_v[index] = v_sup[index] - v_inf[index];

        if ((stdError.iErrorIndex = myParserX[index].Parse(ParamStructs[index].fx, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].fx;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }

        if ((stdError.iErrorIndex = myParserY[index].Parse(ParamStructs[index].fy, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].fy;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }

        if ((stdError.iErrorIndex = myParserZ[index].Parse(ParamStructs[index].fz, "u,v,t")) >= 0)
        {
            stdError.strError = ParamStructs[index].fz;
            stdError.strOrigine = ParamStructs[index].index;
            return stdError;
        }

        if(param4D == 1)
            if ((stdError.iErrorIndex = myParserW[index].Parse(ParamStructs[index].fw, "u,v,t")) >= 0)
            {
                stdError.strError = ParamStructs[index].fw;
                stdError.strOrigine = ParamStructs[index].index;
                return stdError;
            }

        if(expression_CND != "")
            if ((stdError.iErrorIndex = myParserW[index].Parse(ParamStructs[index].cnd, "x,y,z,t")) >= 0)
            {
                stdError.strError = ParamStructs[index].cnd;
                stdError.strOrigine = ParamStructs[index].index;
                return stdError;
            }
    }
    return stdError;
}

///+++++++++++++++++++++++++++++++++++++++++
int Par3D::HowManyVariables(std::string NewVariables, int type)
{
    std::string tmp, tmp2,tmp3;
    int position =0, jpos;
    int Nb_variables =0;
    while( NewVariables!= "")
    {
        if((position = NewVariables.find(";")) >0)
        {
            tmp = NewVariables;
            tmp2= tmp3 = (tmp.substr(0,position));
            jpos = tmp2.find("=");
            if(type == 0)
            {
                VarName[Nb_variables] = tmp2.substr(0,jpos);
                Varus[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            else if(type == 1)
            {
                ConstNames[Nb_variables] = tmp2.substr(0,jpos);
                Consts[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            else if(type == 2)
            {
                FunctNames[Nb_variables] = tmp2.substr(0,jpos);
                Functs[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            tmp2 = NewVariables.substr(position+1, NewVariables.length()-1);
            NewVariables = tmp2;
            Nb_variables++;
        }
        else
        {
            tmp = tmp2 = tmp3 = NewVariables;
            jpos = tmp2.find("=");
            if(type == 0)
            {
                VarName[Nb_variables] = tmp2.substr(0, jpos);
                Varus[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            else if(type == 1)
            {
                ConstNames[Nb_variables] = tmp2.substr(0, jpos);
                Consts[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            else if(type == 2)
            {
                FunctNames[Nb_variables] = tmp2.substr(0, jpos);
                Functs[Nb_variables] = tmp3.substr(jpos+1,position-1);
            }
            NewVariables = "";
            Nb_variables++;
        }
    }
    return Nb_variables;
}

//+++++++++++++++++++++++++++++++++++++++++
int Par3D::HowManyParamSurface(std::string ParamFct, int type)
{
    std::string tmp, tmp2;
    int position =0, jpos;
    int Nb_paramfunction =0;

    switch(type)
    {
    case 0:
        ParamStructs[0].fx = ParamFct;
        break;
    case 1:
        ParamStructs[0].fy = ParamFct;
        break;
    case 2:
        ParamStructs[0].fz = ParamFct;
        break;
    case 3:
        ParamStructs[0].umin = ParamFct;
        break;
    case 4:
        ParamStructs[0].umax = ParamFct;
        break;
    case 5:
        ParamStructs[0].vmin = ParamFct;
        break;
    case 6:
        ParamStructs[0].vmax = ParamFct;
        break;
    case 7:
        ParamStructs[0].fw = ParamFct;
        break;
    case 8:
        ParamStructs[0].cnd = ParamFct;
        break;
    }

    while( ParamFct!= "")
    {
        if((position = ParamFct.find(";")) >0   )
        {
            tmp = ParamFct;
            switch(type)
            {
            case 0:
                ParamStructs[Nb_paramfunction].fx = (tmp.substr(0,position));
                break;
            case 1:
                ParamStructs[Nb_paramfunction].fy = (tmp.substr(0,position));
                break;
            case 2:
                ParamStructs[Nb_paramfunction].fz = (tmp.substr(0,position));
                break;
            case 7:
                ParamStructs[Nb_paramfunction].fw = (tmp.substr(0,position));
                break;
            case 8:
                ParamStructs[Nb_paramfunction].cnd = (tmp.substr(0,position));
                break;
            case 3:
                ParamStructs[Nb_paramfunction].umin = (tmp.substr(0,position));
                break;
            case 4:
                ParamStructs[Nb_paramfunction].umax = (tmp.substr(0,position));
                break;
            case 5:
                ParamStructs[Nb_paramfunction].vmin = (tmp.substr(0,position));
                break;
            case 6:
                ParamStructs[Nb_paramfunction].vmax = (tmp.substr(0,position));
                break;
            }

            Nb_paramfunction++;
            tmp2 = ParamFct.substr(position+1, jpos=ParamFct.length()-1);
            ParamFct = tmp2;
        }
        else
        {
            switch(type)
            {
            case 0:
                ParamStructs[Nb_paramfunction].fx = ParamFct;
                break;
            case 1:
                ParamStructs[Nb_paramfunction].fy = ParamFct;
                break;
            case 2:
                ParamStructs[Nb_paramfunction].fz = ParamFct;
                break;
            case 7:
                ParamStructs[Nb_paramfunction].fw = ParamFct;
                break;
            case 8:
                ParamStructs[Nb_paramfunction].cnd = ParamFct;
                break;
            case 3:
                ParamStructs[Nb_paramfunction].umin = ParamFct;
                break;
            case 4:
                ParamStructs[Nb_paramfunction].umax = ParamFct;
                break;
            case 5:
                ParamStructs[Nb_paramfunction].vmin = ParamFct;
                break;
            case 6:
                ParamStructs[Nb_paramfunction].vmax = ParamFct;
                break;
            }
            ParamFct ="";
        }
    }
    return Nb_paramfunction;
}

//+++++++++++++++++++++++++++++++++++++++++++
void Par3D::BorderCalculation(int NewPosition)
{
    int k=0;
    for(int i=0; i<nb_ligne - coupure_ligne-2; i++)
        for(int j=0; j<nb_colone - coupure_col -2; j++)
        {
            if(VerifCND[i*(nb_colone)+j] != VerifCND[i*(nb_colone)+j+1])
            {
                Border[k + 0] = (NormVertexTab[(i*(nb_colone)+j)*6+3+NewPosition] + NormVertexTab[(i*(nb_colone)+j+1)*6+3+NewPosition])/2;
                Border[k + 1] = (NormVertexTab[(i*(nb_colone)+j)*6+4+NewPosition] + NormVertexTab[(i*(nb_colone)+j+1)*6+4+NewPosition])/2;
                Border[k + 2] = (NormVertexTab[(i*(nb_colone)+j)*6+5+NewPosition] + NormVertexTab[(i*(nb_colone)+j+1)*6+5+NewPosition])/2;
                k += 3;
            }

            if(VerifCND[i*(nb_colone)+j] != VerifCND[(i+1)*(nb_colone)+j])
            {
                Border[k + 0] = (NormVertexTab[(i*(nb_colone)+j)*6+3+NewPosition] + NormVertexTab[((i+1)*(nb_colone)+j)*6+3+NewPosition])/2;
                Border[k + 1] = (NormVertexTab[(i*(nb_colone)+j)*6+4+NewPosition] + NormVertexTab[((i+1)*(nb_colone)+j)*6+4+NewPosition])/2;
                Border[k + 2] = (NormVertexTab[(i*(nb_colone)+j)*6+5+NewPosition] + NormVertexTab[((i+1)*(nb_colone)+j)*6+5+NewPosition])/2;
                k += 3;
            }
        }

}

///+++++++++++++++++++++++++++++++++++++++++
void Par3D::CNDCalculation(int NbTriangleIsoSurfaceTmp, struct ComponentInfos *components)
{
    double vals[4];
    vals[3] = stepMorph;

    if (ParConditionRequired == 1)
    {
        for(int i= 0; i < NbVertexTmp; i++)
        {
            vals[0] = NormVertexTab[i*6+3];
            vals[1] = NormVertexTab[i*6+4];
            vals[2] = NormVertexTab[i*6+5];
            WichPointVerifyCond[i] = (myParserCND[0].Eval(vals) == 1);
        }

        int Aindex, Bindex, Cindex;
        int nbtriangle = NbTriangleIsoSurfaceTmp;
        for(int i= 0; i < nbtriangle; i++)
        {
            Aindex = IndexPolyTab[3*i       ];
            Bindex = IndexPolyTab[3*i + 1];
            Cindex = IndexPolyTab[3*i + 2];
            //Init this triangle type to 1:
            TypeIsoSurfaceTriangleListeCND[i] = 1;
            int TypeTriangle;
            if(WichPointVerifyCond[Aindex] && !WichPointVerifyCond[Bindex] && !WichPointVerifyCond[Cindex])
                TypeTriangle = 0;
            else if(!WichPointVerifyCond[Aindex] && WichPointVerifyCond[Bindex] && WichPointVerifyCond[Cindex])
                TypeTriangle = 1;
            else if(!WichPointVerifyCond[Aindex] && WichPointVerifyCond[Bindex] && !WichPointVerifyCond[Cindex])
                TypeTriangle = 2;
            else if(WichPointVerifyCond[Aindex] && !WichPointVerifyCond[Bindex] && WichPointVerifyCond[Cindex])
                TypeTriangle = 3;
            else if(!WichPointVerifyCond[Aindex] && !WichPointVerifyCond[Bindex] && WichPointVerifyCond[Cindex])
                TypeTriangle = 4;
            else if(WichPointVerifyCond[Aindex] && WichPointVerifyCond[Bindex] && !WichPointVerifyCond[Cindex])
                TypeTriangle = 5;
            else if(!WichPointVerifyCond[Aindex] && !WichPointVerifyCond[Bindex] && !WichPointVerifyCond[Cindex])
            {
                TypeTriangle = 6;
                TypeIsoSurfaceTriangleListeCND[i] = -1;
            }
            else if(WichPointVerifyCond[Aindex] && WichPointVerifyCond[Bindex] && WichPointVerifyCond[Cindex])
            {
                TypeTriangle = 7;
                TypeIsoSurfaceTriangleListeCND[i] = 1;
            }

            if(TypeTriangle == 2 || TypeTriangle == 3)
            {
                Aindex = IndexPolyTab[3*i  +1];
                Bindex = IndexPolyTab[3*i + 2];
                Cindex = IndexPolyTab[3*i      ];
            }
            else if(TypeTriangle == 4 || TypeTriangle == 5)
            {
                Aindex = IndexPolyTab[3*i  + 2];
                Bindex = IndexPolyTab[3*i       ];
                Cindex = IndexPolyTab[3*i  + 1];
            }

            double Bprime[4], Cprime[4], DiffX, DiffY, DiffZ;
            int Alfa;
            if(TypeTriangle >=0 && TypeTriangle <= 5)
            {
                /// Bprime
                Bprime[0] = NormVertexTab[3+6*Aindex    ];
                Bprime[1] = NormVertexTab[3+6*Aindex+1];
                Bprime[2] = NormVertexTab[3+6*Aindex+2];
                Bprime[3] = stepMorph;

                DiffX = (NormVertexTab[3+6*Bindex  ] - NormVertexTab[3+6*Aindex  ])/20;
                DiffY = (NormVertexTab[3+6*Bindex+1] - NormVertexTab[3+6*Aindex+1])/20;
                DiffZ = (NormVertexTab[3+6*Bindex+2] - NormVertexTab[3+6*Aindex+2])/20;
                Alfa = 0;
                if(TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4)
                {
                    while(myParserCND[0].Eval(Bprime) == 1 && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!myParserCND[0].Eval(Bprime) == 1 && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }

                /// Cprime
                Cprime[0] = NormVertexTab[3+6*Aindex    ];
                Cprime[1] = NormVertexTab[3+6*Aindex+1];
                Cprime[2] = NormVertexTab[3+6*Aindex+2];
                Cprime[3] = stepMorph;

                DiffX = (NormVertexTab[3+6*Cindex    ] - NormVertexTab[3+6*Aindex     ])/20;
                DiffY = (NormVertexTab[3+6*Cindex+1] - NormVertexTab[3+6*Aindex+1])/20;
                DiffZ = (NormVertexTab[3+6*Cindex+2] - NormVertexTab[3+6*Aindex+2])/20;
                Alfa = 0;
                if(TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4)
                {
                    while(myParserCND[0].Eval(Cprime) == 1 && (Alfa < 20))
                    {
                        Cprime[0] += DiffX;
                        Cprime[1] += DiffY;
                        Cprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!myParserCND[0].Eval(Cprime) == 1 && (Alfa < 20))
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
                NormVertexTab[6*NbVertexTmp+3] = Bprime[0];
                NormVertexTab[6*NbVertexTmp+4] = Bprime[1];
                NormVertexTab[6*NbVertexTmp+5] = Bprime[2];

                NormVertexTab[6*NbVertexTmp      ] = NormVertexTab[6*Bindex      ];
                NormVertexTab[6*NbVertexTmp +1] = NormVertexTab[6*Bindex + 1];
                NormVertexTab[6*NbVertexTmp +2] = NormVertexTab[6*Bindex + 2];
                //Add Cprime:
                NormVertexTab[6*NbVertexTmp+  9] = Cprime[0];
                NormVertexTab[6*NbVertexTmp+10] = Cprime[1];
                NormVertexTab[6*NbVertexTmp+11] = Cprime[2];

                NormVertexTab[6*NbVertexTmp +6] = NormVertexTab[6*Cindex      ];
                NormVertexTab[6*NbVertexTmp +7] = NormVertexTab[6*Cindex + 1];
                NormVertexTab[6*NbVertexTmp +8] = NormVertexTab[6*Cindex + 2];
                NbVertexTmp += 2;


                //***********
                //Add triangles:
                //***********
                /// Add Three new triangles :
                int IndexBprime = (NbVertexTmp-2);
                int IndexCprime = (NbVertexTmp-1);
                int IndexNbTriangle;

                // The original triangle will be replaced by four other triangles:
                TypeIsoSurfaceTriangleListeCND[i] = 0;

                /// (A, Bprime, Cprime)
                IndexNbTriangle = NbTriangleIsoSurfaceTmp*3;
                IndexPolyTab[IndexNbTriangle  ] = Aindex;
                IndexPolyTab[IndexNbTriangle+1] = IndexBprime;
                IndexPolyTab[IndexNbTriangle+2] = IndexCprime;
                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = 1 : TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = -1;
                //TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = -1;
                NbTriangleIsoSurfaceTmp++;

                IndexPolyTabMin[PreviousSizeMinimalTopology++] = 3;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = Aindex;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexBprime;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexCprime;
                NbPolyMinimalTopology++;

                /// (Bprime, B, C)
                IndexNbTriangle = NbTriangleIsoSurfaceTmp*3;
                IndexPolyTab[IndexNbTriangle  ] = IndexBprime;
                IndexPolyTab[IndexNbTriangle+1] = Bindex;
                IndexPolyTab[IndexNbTriangle+2] = Cindex;
                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = -1 : TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = 1;
                //TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = 1;
                NbTriangleIsoSurfaceTmp++;

                IndexPolyTabMin[PreviousSizeMinimalTopology++] = 3;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexBprime;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = Bindex;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = Cindex;
                NbPolyMinimalTopology++;

                /// (Bprime, C, Cprime)
                IndexNbTriangle = NbTriangleIsoSurfaceTmp*3;
                IndexPolyTab[IndexNbTriangle  ] = IndexBprime;
                IndexPolyTab[IndexNbTriangle+1] = Cindex;
                IndexPolyTab[IndexNbTriangle+2] = IndexCprime;
                (TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4) ?
                TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = -1 : TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = 1;
                //TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = 1;
                NbTriangleIsoSurfaceTmp++;

                IndexPolyTabMin[PreviousSizeMinimalTopology++] = 3;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexBprime;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = Cindex;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexCprime;
                NbPolyMinimalTopology++;

                /// (Bprime, Cprime) --> the border
                IndexNbTriangle = NbTriangleIsoSurfaceTmp*3;
                IndexPolyTab[IndexNbTriangle  ] = IndexBprime;
                IndexPolyTab[IndexNbTriangle+1] = IndexCprime;
                IndexPolyTab[IndexNbTriangle+2] = IndexCprime;
                TypeIsoSurfaceTriangleListeCND[NbTriangleIsoSurfaceTmp] = 4; /// Type = 4-->Border
                NbTriangleIsoSurfaceTmp++;

                IndexPolyTabMin[PreviousSizeMinimalTopology++] = 3;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexBprime;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexCprime;
                IndexPolyTabMin[PreviousSizeMinimalTopology++] = IndexCprime;
                NbPolyMinimalTopology++;
            }

        }

        //***********
        //Reorganize the triangles index:
        //***********
        unsigned int *NewIndexPolyTab = new unsigned int[3*NbTriangleIsoSurfaceTmp];
        int k, l, M;
        k = l = M =0;
        for(int i=0; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCND[i] == 1)
            {
                NewIndexPolyTab[3*k       ] =  IndexPolyTab[3*i      ];
                NewIndexPolyTab[3*k + 1] =  IndexPolyTab[3*i + 1];
                NewIndexPolyTab[3*k + 2] =  IndexPolyTab[3*i + 2];
                k++;
            }

        for(int i=0; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCND[i] == -1)
            {
                NewIndexPolyTab[3*(l + k)       ] =  IndexPolyTab[3*i      ];
                NewIndexPolyTab[3*(l + k) + 1] =  IndexPolyTab[3*i + 1];
                NewIndexPolyTab[3*(l + k) + 2] =  IndexPolyTab[3*i + 2];
                l++;
            }

        for(int i=0; i<NbTriangleIsoSurfaceTmp; i++)
            if(TypeIsoSurfaceTriangleListeCND[i] == 4)
            {
                NewIndexPolyTab[3*(M + l + k)      ] =  IndexPolyTab[3*i      ];
                NewIndexPolyTab[3*(M + l + k) + 1] =  IndexPolyTab[3*i + 1];
                NewIndexPolyTab[3*(M + l + k) + 2] =  IndexPolyTab[3*i + 2];
                M++;
            }

        //Copy the new index in the original one:
        memcpy(IndexPolyTab, NewIndexPolyTab, 3*(M + l + k)*sizeof(unsigned int));
        NbTriangleIsoSurfaceTmp = M + l + k;
        delete (NewIndexPolyTab);

        components->NbTrianglesVerifyCND = k;
        components->NbTrianglesNotVerifyCND = l;
        components->NbTrianglesBorderCND = M;

        for(int fctnb= 0; fctnb< Nb_paramfunctions+1; fctnb++)
        {
            if(components != NULL)
            {
                components->Parametricpositions[2*fctnb + 1] = NbTriangleIsoSurfaceTmp;
            }
        }

        components->ThereisCND = true;

    }
    else
        components->ThereisCND = false;
}



//++++++++++++++++++++++++++++++++++++
void  Par3D:: ParamBuild(
    float *NormVertexTabPt,
    float *ExtraDimensionPt,
    unsigned int *IndexPolyTabPt,
    unsigned int *PolyNumber,
    unsigned int *VertxNumber,
    int  IsoPos,
    ComponentInfos *components,
    int *TriangleListeCND,
    bool *typeCND,
    unsigned int *IndexPolyTabMinPt,
    unsigned  int *NbPolyMinPt
)
{
    int NbTriangleIsoSurfaceTmp;
    NbVertexTmp = NbTriangleIsoSurfaceTmp =  0;
    NbPolyMinimalTopology = 0;
    PreviousSizeMinimalTopology =0;

    NbVertex  = (nb_ligne)*(nb_colone);
    NbPolygn = 2*(nb_ligne  - coupure_ligne -1)*(nb_colone - coupure_col -1);

    NormVertexTab = NormVertexTabPt;
    IndexPolyTab = IndexPolyTabPt;
    ExtraDimension = ExtraDimensionPt;
    IndexPolyTabMin = IndexPolyTabMinPt;

    if(components != NULL)
        components->NbParametric = Nb_paramfunctions+1;

    if(TriangleListeCND != NULL)
        TypeIsoSurfaceTriangleListeCND = TriangleListeCND;

    if(typeCND != NULL)
        WichPointVerifyCond = typeCND;

    for(int fctnb= 0; fctnb< Nb_paramfunctions+1; fctnb++)
    {
        calcul_objet(fctnb*6*NbVertex, fctnb);
        if(param4D == 1)
        {
            Anim_Rot4D (fctnb*NbVertex);
        }

        calcul_Norm(fctnb*6*NbVertex);
        make_PolyIndexMin( fctnb,  IsoPos);  //Before
        make_PolyIndexTri( fctnb,  IsoPos);

        if(components != NULL)
        {
            components->Parametricpositions[2*fctnb          ]  = fctnb*6*(nb_ligne  - coupure_ligne -1)*(nb_colone - coupure_col -1)  /*+  IsoPos*/; //save the starting position of this component
            components->Parametricpositions[2*fctnb     + 1] = 2*(nb_ligne  - coupure_ligne -1)*(nb_colone - coupure_col -1); //save the number of Polygones of this component
        }
    }


    // Save Number of Polys and vertex :
    NbVertexTmp                   = (Nb_paramfunctions+1)*(nb_ligne)*(nb_colone);
    NbTriangleIsoSurfaceTmp = (Nb_paramfunctions+1)*NbPolygn;
    NbPolyMinimalTopology    = (Nb_paramfunctions+1)*(nb_ligne  - coupure_ligne -1)*(nb_colone - coupure_col -1);
    PreviousSizeMinimalTopology = 5*(Nb_paramfunctions+1)*(nb_ligne  - coupure_ligne -1)*(nb_colone - coupure_col -1);

    //CND calculation for the triangles results:
    CNDCalculation(NbTriangleIsoSurfaceTmp, components);

// 3) Nb Poly & Vertex :
    *PolyNumber      = 3*NbTriangleIsoSurfaceTmp;
    *VertxNumber     = NbVertexTmp;
    *NbPolyMinPt     = NbPolyMinimalTopology;
}

//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::make_PolyIndex(int NewPo, int IsoPos)
{
    int k=0;
    int NewPosition = NewPo * 4*(nb_ligne  - coupure_ligne -1)*(nb_colone- coupure_col -1);
    int nbVertex       = NewPo * (nb_ligne  - coupure_ligne)*(nb_colone- coupure_col);
    for (int i=0; i< nb_ligne - coupure_ligne -1; i++)
        for (int j=0; j< nb_colone - coupure_col -1; j++)
        {
            IndexPolyTab[k    +NewPosition] =  i*nb_colone + j+nbVertex + IsoPos;
            IndexPolyTab[k+1+NewPosition] = (i+1)*nb_colone + j +nbVertex + IsoPos;
            IndexPolyTab[k+2+NewPosition] = (i+1)*nb_colone + (j+1)+nbVertex + IsoPos;
            IndexPolyTab[k+3+NewPosition] = i*nb_colone + (j+1)+nbVertex + IsoPos;
            k+=4;
        }
}
//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::make_PolyIndexMin(int NewPo, int IsoPos)
{
    int k=0;
    int NewPosition = NewPo * 5*(nb_ligne  - coupure_ligne -1)*(nb_colone- coupure_col -1);
    int nbVertex       = NewPo * (nb_ligne  - coupure_ligne)*(nb_colone- coupure_col);
    for (int i=0; i< nb_ligne - coupure_ligne -1; i++)
        for (int j=0; j< nb_colone - coupure_col -1; j++)
        {
            IndexPolyTabMin[k    +NewPosition] =  4;
            IndexPolyTabMin[k+1+NewPosition] =  i*nb_colone + j+nbVertex + IsoPos;
            IndexPolyTabMin[k+2+NewPosition] = (i+1)*nb_colone + j +nbVertex + IsoPos;
            IndexPolyTabMin[k+3+NewPosition] = (i+1)*nb_colone + (j+1)+nbVertex + IsoPos;
            IndexPolyTabMin[k+4+NewPosition] = i*nb_colone + (j+1)+nbVertex + IsoPos;
            k+=5;
        }

    PreviousSizeMinimalTopology += 5*(nb_ligne  - coupure_ligne)*(nb_colone- coupure_col);
    NbPolyMinimalTopology += (nb_ligne  - coupure_ligne-1)*(nb_colone- coupure_col-1);
}
//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::make_PolyIndexTri(int NewPo, int IsoPos)
{
    int k=0;
    int NewPosition = NewPo * 6*(nb_ligne  - coupure_ligne -1)*(nb_colone- coupure_col -1);
    int nbVertex       = NewPo * (nb_ligne  - coupure_ligne)*(nb_colone- coupure_col);
    for (int i=0; i< nb_ligne - coupure_ligne -1; i++)
        for (int j=0; j< nb_colone - coupure_col -1; j++)
        {
            IndexPolyTab[k    +NewPosition] =  i*nb_colone + j+nbVertex + IsoPos;
            IndexPolyTab[k+1+NewPosition] = (i+1)*nb_colone + j +nbVertex + IsoPos;
            IndexPolyTab[k+2+NewPosition] = (i+1)*nb_colone + (j+1)+nbVertex + IsoPos;

            IndexPolyTab[k+3+NewPosition] = i*nb_colone + j+nbVertex + IsoPos;
            IndexPolyTab[k+4+NewPosition] = (i+1)*nb_colone + (j+1)+nbVertex + IsoPos;
            IndexPolyTab[k+5+NewPosition] = i*nb_colone + (j+1)+nbVertex + IsoPos;
            k+=6;
        }
}

//+++++++++++++++++++++++++++++++++++++++++++
void  Par3D::calcul_Norm(int NewPosition)
{
//calculate Normals
    int        i, j, deplacement = 6*nb_colone;
    double caa, bab, cab, baa, ba, ca;

    for (i=0; i < nb_ligne -1  ; i++)
        for (j=0; j < nb_colone -1  ; j++)
        {
            caa = NormVertexTab[(i+1)*deplacement+j*6+4+NewPosition] - NormVertexTab[i*deplacement +j*6+4+NewPosition];
            bab = NormVertexTab[i*deplacement+(j+1)*6+5+NewPosition] - NormVertexTab[i*deplacement +j*6+5+NewPosition];
            cab = NormVertexTab[(i+1)*deplacement+j*6+5+NewPosition] - NormVertexTab[i*deplacement +j*6+5+NewPosition];
            baa = NormVertexTab[i*deplacement+(j+1)*6+4+NewPosition] - NormVertexTab[i*deplacement +j*6+4+NewPosition];
            ba   = NormVertexTab[i*deplacement+(j+1)*6+3+NewPosition] - NormVertexTab[i*deplacement +j*6+3+NewPosition];
            ca   = NormVertexTab[(i+1)*deplacement+j*6+3+NewPosition] - NormVertexTab[i*deplacement +j*6+3+NewPosition];

            NormVertexTab[i*deplacement +j*6     +NewPosition] = caa*bab  - cab*baa;
            NormVertexTab[i*deplacement +j*6 +1+NewPosition] = cab*ba    - ca*bab;
            NormVertexTab[i*deplacement +j*6 +2+NewPosition] = ca*baa    - caa*ba;

            double b4 = (double)sqrt(
                            (NormVertexTab[i*deplacement +j*6  +NewPosition]*NormVertexTab[i*deplacement +j*6      +NewPosition]) +
                            (NormVertexTab[i*deplacement +j*6+1+NewPosition]*NormVertexTab[i*deplacement +j*6+1+NewPosition]) +
                            (NormVertexTab[i*deplacement +j*6+2+NewPosition]*NormVertexTab[i*deplacement +j*6+2+NewPosition]));

            if( b4 < 0.00000001)  b4 = 0.00000001;

//Normalise:
            NormVertexTab[i*deplacement +j*6    +NewPosition]/=b4;
            NormVertexTab[i*deplacement +j*6+1+NewPosition]/=b4;
            NormVertexTab[i*deplacement +j*6+2+NewPosition]/=b4;
        }

    i = nb_ligne -1;
    for (j=0; j < nb_colone -1   ; j++)
    {
        NormVertexTab[i*deplacement +j*6    +NewPosition] = NormVertexTab[(i-1)*deplacement +j*6    +NewPosition];
        NormVertexTab[i*deplacement +j*6+1+NewPosition] = NormVertexTab[(i-1)*deplacement +j*6+1+NewPosition];
        NormVertexTab[i*deplacement +j*6+2+NewPosition] = NormVertexTab[(i-1)*deplacement +j*6+2+NewPosition];
    }

    j =nb_colone -1;
    for (i=0; i < nb_ligne -1  ; i++)
    {
        NormVertexTab[i*deplacement +j*6    +NewPosition] = NormVertexTab[i*deplacement +(j-1)*6    +NewPosition];
        NormVertexTab[i*deplacement +j*6+1+NewPosition] = NormVertexTab[i*deplacement +(j-1)*6+1+NewPosition];
        NormVertexTab[i*deplacement +j*6+2+NewPosition] = NormVertexTab[i*deplacement +(j-1)*6+2+NewPosition];
    }

    i = nb_ligne -1;
    j =nb_colone -1;
    NormVertexTab[i*deplacement +j*6  +NewPosition]    = NormVertexTab[(i-1)*deplacement +(j-1)*6    +NewPosition];
    NormVertexTab[i*deplacement +j*6+1+NewPosition]  = NormVertexTab[(i-1)*deplacement +(j-1)*6+1+NewPosition];
    NormVertexTab[i*deplacement +j*6+2+NewPosition]  = NormVertexTab[(i-1)*deplacement +(j-1)*6+2+NewPosition];
}
