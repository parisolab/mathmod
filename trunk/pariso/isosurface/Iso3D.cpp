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
#include "TableMap.h"
#include "Iso3D.h"

static unsigned int *IndexPolyTabMin;
static int NbPolyMin;
static float * NormOriginaltmp;
static Voxel *GridVoxelVarPt;
static double *Results;
static int TypeDrawin=10;
//static int TypeDrawinStep = 3;
static int TypeDrawinNormStep = 4;
static int PreviousSizeMinimalTopology =0;
static int NbPolyMinimalTopology =0;
static int NbVertexTmp = 0;

/// +++++++++++++++++++++++++++++++++++++++++
void Iso3D::stopcalculations()
{
}

/// +++++++++++++++++++++++++++++++++++++++++
void Iso3D::SetMinimuMmeshSize(double)
{
}

/// +++++++++++++++++++++++++++++++++++++++++
int Iso3D::setmaxgridto(int maxgrid)
{
    maximumgrid = maxgrid;
    delete GridVoxelVarPt;
    delete Results;
//delete DataXYZ;
    GridVoxelVarPt = new Voxel[maxgrid*maxgrid*maxgrid];
    Results        = new double[maxgrid*maxgrid*maxgrid];
    return(1);
}

/// +++++++++++++++++++++++++++++++++++++++++
Iso3D::Iso3D( int maxtri, int maxpts, int gridmax)
{
    ErrorMessage stError;
    static int staticaction = 1;
    MaximumNumberPoints                = maxpts; //20000000;
    MaximumNumberTriangles           = maxtri; //30000000;
    NbPolygonImposedLimit               = MaximumNumberTriangles;
    IsoSurfaceTriangleListe                 = new int[3*MaximumNumberTriangles];
    NormOriginaltmp                            = new float[3*MaximumNumberTriangles];
    maximumgrid = gridmax;

    /// Things to do one time...
    if(staticaction == 1)
    {
        GridVoxelVarPt  = new  Voxel[maximumgrid*maximumgrid*maximumgrid];
        Results             = new double[maximumgrid*maximumgrid*maximumgrid];
        staticaction     *= -1;
    }
    NbPointIsoMap = 0;
    NbTriangleIsoSurface = 0;
    IsoConditionRequired = -1;
    Cstparser.AddConstant("pi", 3.14159265);
    ImplicitFunction =  "cos(x) + cos(y) + cos(z)";
    XlimitSup = "4";
    YlimitSup = "4";
    ZlimitSup = "4";
    XlimitInf   = "-4";
    YlimitInf   = "-4";
    ZlimitInf   = "-4";
    nb_ligne = nb_colon = nb_depth = 26;
    IsoMesh = -1;
    IsoInfos = 1; /// To show infos
    hauteur_fenetre = 650;
    stepMorph = 0;
    pace = (double)1/(double)30;
    morph_activated = -1;
    AllComponentTraited = false;

    InitParser();
    stError = ParserIso();
}

///+++++++++++++++++++++++++++++++++++++++++
int Iso3D::HowManyVariables(std::string NewVariables, int type)
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

///+++++++++++++++++++++++++++++++++++++++++
int Iso3D::HowManyIsosurface(std::string ImplicitFct, int type)
{
    std::string tmp, tmp2;
    int position =0, jpos;
    int Nb_implicitfunction =0;
    double val=0.0;
    if(type ==0)
    {
        ImplicitStructs[0].fxyz = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) >0   )
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].fxyz = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
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
    //++++++++++++++++++
    else if(type == 1)  //xmin
    {
        ImplicitStructs[0].xmin = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) >0   )
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].xmin = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
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
            if((position = ImplicitFct.find(";")) >0   )
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].xmax = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
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
            if((position = ImplicitFct.find(";")) >0   )
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].ymin = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
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
            if((position = ImplicitFct.find(";")) >0   )
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].ymax = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
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
            if((position = ImplicitFct.find(";")) >0   )
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].zmin = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
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
            if((position = ImplicitFct.find(";")) >0   )
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].zmax = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
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

    else if(type == 7) //Grid
    {
        ImplicitStructs[0].grid = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) >0   )
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].grid = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
                ImplicitFct = tmp2;
            }
            else
            {
                ImplicitStructs[Nb_implicitfunction].grid  = ImplicitFct;
                ImplicitFct ="";
            }
        }

        for(int i=0; i<100; i++)
            GridTable[i] = 0;
        for(int i=0; i<Nb_implicitfunction+1; i++)
        {
            if(ImplicitStructs[i].grid != "")
            {
                Cstparser.Parse(ImplicitStructs[i].grid, "u");
                GridTable[i] = Cstparser.Eval(&val); //position is used only to make the Eval function work
            }
        }
        return Nb_implicitfunction;
    }


    else if(type == 8) //Cnd
    {
        ImplicitStructs[0].cnd = ImplicitFct;

        while( ImplicitFct!= "")
        {
            if((position = ImplicitFct.find(";")) >0   )
            {
                tmp = ImplicitFct;
                ImplicitStructs[Nb_implicitfunction].cnd = (tmp.substr(0,position));
                Nb_implicitfunction++;
                tmp2 = ImplicitFct.substr(position+1, jpos=ImplicitFct.length()-1);
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

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::InitParser()
{
    initparser(1100);

    for(int i=0; i<1100; i++)
    {
        implicitFunctionParser[i].AddConstant("pi", 3.14159265);
        IsoConditionParser[i].AddConstant("pi", 3.14159265);
        xSupParser[i].AddConstant("pi", 3.14159265);
        ySupParser[i].AddConstant("pi", 3.14159265);
        zSupParser[i].AddConstant("pi", 3.14159265);
        xInfParser[i].AddConstant("pi", 3.14159265);
        yInfParser[i].AddConstant("pi", 3.14159265);
        zInfParser[i].AddConstant("pi", 3.14159265);
    }
    for(int i=0; i<20; i++)
    {
        Var[i].AddConstant("pi", 3.14159265);
    }

    for(int i=0; i<50; i++)
    {
        Fct[i].AddConstant("pi", 3.14159265);
    }
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::VoxelEvaluation(int IsoIndex)
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    double vals2[] = {0,0};
    int maxgrscalemaxgr = maximumgrid*maximumgrid;

    const int limitX = nb_ligne, limitY = nb_colon, limitZ = nb_depth;
    int I, J, IJK;

    if(AllComponentTraited && morph_activated ==1)
    {
        stepMorph += pace;
    }
    vals[3]          = stepMorph;

    // Add constatntes definition and values to variables:
    for(int i=0; i<Nb_newvariables; i++)
    {
        for(int j=0; j<Nb_constants; j++)
        {
            Var[i].AddConstant(ConstNames[j], ConstValues[j]);
        }
    }

    // Add constatntes definition and values to Functions:
    for(int i=0; i<Nb_implicitfunctions+1; i++)
    {
        for(int j=0; j<Nb_constants; j++)
        {
            implicitFunctionParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            IsoConditionParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            xSupParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            ySupParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            zSupParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            xInfParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            yInfParser[i].AddConstant(ConstNames[j], ConstValues[j]);
            zInfParser[i].AddConstant(ConstNames[j], ConstValues[j]);
        }
    }

    xLocal[IsoIndex][0]=xSupParser[IsoIndex].Eval(vals);
    yLocal[IsoIndex][0]=ySupParser[IsoIndex].Eval(vals);
    zLocal[IsoIndex][0]=zSupParser[IsoIndex].Eval(vals);

    x_Step[IsoIndex] = /*x_Step[IsoIndex] = */(xLocal[IsoIndex][0] - xInfParser[IsoIndex].Eval(vals))/(limitX-1);
    y_Step[IsoIndex] = /*y_Step[IsoIndex] = */(yLocal[IsoIndex][0] - yInfParser[IsoIndex].Eval(vals))/(limitY-1);
    z_Step[IsoIndex] = /*z_Step[IsoIndex] = */(zLocal[IsoIndex][0] - zInfParser[IsoIndex].Eval(vals))/(limitZ-1);

    for (int i= 1; i < limitX; i++)
        xLocal[IsoIndex][i] = xLocal[IsoIndex][i-1] - x_Step[IsoIndex];

    for (int j= 1; j < limitY; j++)
        yLocal[IsoIndex][j] = yLocal[IsoIndex][j-1] - y_Step[IsoIndex];

    for (int k= 1; k < limitZ; k++)
        zLocal[IsoIndex][k] = zLocal[IsoIndex][k-1] - z_Step[IsoIndex];

    std::string stringtoparse=ImplicitStructs[IsoIndex].fxyz;


    for(int l=0; l<Nb_newvariables; l++)
    {
        if(stringtoparse.find(VarName [l]+"x") !=std::string::npos  && Varus[l].find("tm") !=std::string::npos)
            for(int i=0; i<limitX; i++)
            {
                vals2[0] = xLocal[IsoIndex][i];
                vals2[1] = stepMorph;
                vr[l*3][IsoIndex][i] =Var[l] .Eval(vals2);
            }

        if(stringtoparse.find(VarName [l]+"y") !=std::string::npos && Varus[l].find("tm") !=std::string::npos)
            for(int i=0; i<limitY; i++)
            {
                vals2[0] = yLocal[IsoIndex][i];
                vals2[1] = stepMorph;
                vr[l*3+1][IsoIndex][i] =Var[l] .Eval(vals2);
            }

        if(stringtoparse.find(VarName [l]+"z") !=std::string::npos && Varus[l].find("tm") !=std::string::npos)
            for(int i=0; i<limitZ; i++)
            {
                vals2[0] = zLocal[IsoIndex][i];
                vals2[1] = stepMorph;
                vr[l*3+2][IsoIndex][i] =Var[l] .Eval(vals2);
            }
    }



    for(int i=0; i<limitX; i++)
    {
        vals[0] = xLocal[IsoIndex][i];

        for(int l=0; l<Nb_newvariables; l++)
        {
            vals[4 + l*3] = vr[l*3][IsoIndex][i];
        }

        I = i*maxgrscalemaxgr;
        for(int j=0; j<limitY; j++)
        {
            vals[1] = yLocal[IsoIndex][j];
            for(int l=0; l<Nb_newvariables; l++)
            {
                vals[5 + l*3] = vr[l*3+1][IsoIndex][j];
            }

            J = I + j*maximumgrid;
            for(int k=0; k<limitZ; k++)
            {
                vals[2] = zLocal[IsoIndex][k];

                for(int l=0; l<Nb_newvariables; l++)
                {
                    vals[6 + l*3] = vr[l*3+2][IsoIndex][k];
                }

                IJK = J+k;
                Results[IJK]= implicitFunctionParser[IsoIndex].Eval(vals);
                GridVoxelVarPt[IJK].Signature   = 0; // Signature initialisation
                GridVoxelVarPt[IJK].NbEdgePoint = 0; // No EdgePoint yet!
                for(int l=0; l<12; l++) GridVoxelVarPt[IJK].Edge_Points[l] = -20;
            }
        }
    }
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::ConstructIsoNormale()
{
    float val1, val2, val3, val4, val5, val6,
           pt1_x, pt1_y, pt1_z,
           pt2_x, pt2_y, pt2_z,
           pt3_x, pt3_y, pt3_z,
           scalar;
    int ThreeTimesI, IndexFirstPoint, IndexSecondPoint, IndexThirdPoint;

    for(i = 0; i<NbTriangleIsoSurface; ++i)
    {

        ThreeTimesI   = i*3;

        IndexFirstPoint      = 3+TypeDrawin*IsoSurfaceTriangleListe[ThreeTimesI         ]+ TypeDrawin*NbVertexTmp +TypeDrawinNormStep;
        IndexSecondPoint = 3+TypeDrawin*IsoSurfaceTriangleListe[ThreeTimesI+1    ]+ TypeDrawin*NbVertexTmp +TypeDrawinNormStep;
        IndexThirdPoint     = 3+TypeDrawin*IsoSurfaceTriangleListe[ThreeTimesI+2    ]+ TypeDrawin*NbVertexTmp +TypeDrawinNormStep;

        pt1_x= NormVertexTab[IndexFirstPoint     ];
        pt1_y= NormVertexTab[IndexFirstPoint+1 ];
        pt1_z= NormVertexTab[IndexFirstPoint+2 ];

        pt2_x= NormVertexTab[IndexSecondPoint    ];
        pt2_y= NormVertexTab[IndexSecondPoint+1];
        pt2_z= NormVertexTab[IndexSecondPoint+2];

        pt3_x= NormVertexTab[IndexThirdPoint     ];
        pt3_y= NormVertexTab[IndexThirdPoint+1 ];
        pt3_z= NormVertexTab[IndexThirdPoint+2 ];

        val1 = pt2_y - pt1_y;
        val2 = pt3_z - pt1_z;
        val3 = pt2_z - pt1_z;
        val4 = pt3_y - pt1_y;
        val5 = pt3_x - pt1_x;
        val6 = pt2_x - pt1_x;

        NormOriginaltmp[ThreeTimesI     ] = val1*val2 - val3*val4;
        NormOriginaltmp[ThreeTimesI+1] = val3*val5 - val6*val2;
        NormOriginaltmp[ThreeTimesI+2] = val6*val4 - val1*val5;

        scalar = (double)sqrt((NormOriginaltmp[ThreeTimesI    ]*NormOriginaltmp[ThreeTimesI     ]) +
                                           (NormOriginaltmp[ThreeTimesI+1]*NormOriginaltmp[ThreeTimesI +1]) +
                                           (NormOriginaltmp[ThreeTimesI+2]*NormOriginaltmp[ThreeTimesI+2]));

        if(scalar < 0.000000001)  scalar  = 0.000000001;
        (NormOriginaltmp[ThreeTimesI    ]/=scalar);
        (NormOriginaltmp[ThreeTimesI+1]/=scalar);
        (NormOriginaltmp[ThreeTimesI+2]/=scalar);
    }
}

///++++++++++++++++++++ OutPut The IsoSurface +++++++++++++++++++++++

void Iso3D::SaveIsoGLMap()
{
    int IndexFirstPoint, IndexSecondPoint, IndexThirdPoint, ThreeTimesI;
    double scalar;

/// Recalculate the normals so we have one for each Point (like Pov Mesh) :
    for (i=0; i < NbPointIsoMap ; i++)
    {
        ThreeTimesI = TypeDrawin*i  + TypeDrawinNormStep;
        NormVertexTab[ TypeDrawin*NbVertexTmp +ThreeTimesI    ] = 0;
        NormVertexTab[ TypeDrawin*NbVertexTmp +ThreeTimesI+1] = 0;
        NormVertexTab[ TypeDrawin*NbVertexTmp +ThreeTimesI+2] = 0;
    }

    for(i = 0; i<NbTriangleIsoSurface; ++i)
    {
        ThreeTimesI   = i*3;

        IndexFirstPoint      = TypeDrawin*IsoSurfaceTriangleListe[ThreeTimesI          ]+ TypeDrawin*NbVertexTmp  + TypeDrawinNormStep ;
        IndexSecondPoint = TypeDrawin*IsoSurfaceTriangleListe[ThreeTimesI     + 1]+ TypeDrawin*NbVertexTmp  + TypeDrawinNormStep;
        IndexThirdPoint      = TypeDrawin*IsoSurfaceTriangleListe[ThreeTimesI    +2 ]+ TypeDrawin*NbVertexTmp  + TypeDrawinNormStep;

        NormVertexTab[IndexFirstPoint    ] += NormOriginaltmp[ThreeTimesI    ];
        NormVertexTab[IndexFirstPoint+1] += NormOriginaltmp[ThreeTimesI+1];
        NormVertexTab[IndexFirstPoint+2] += NormOriginaltmp[ThreeTimesI+2];

        NormVertexTab[IndexSecondPoint    ] += NormOriginaltmp[ThreeTimesI    ];
        NormVertexTab[IndexSecondPoint+1] += NormOriginaltmp[ThreeTimesI+1];
        NormVertexTab[IndexSecondPoint+2] += NormOriginaltmp[ThreeTimesI+2];

        NormVertexTab[IndexThirdPoint    ] += NormOriginaltmp[ThreeTimesI    ];
        NormVertexTab[IndexThirdPoint+1] += NormOriginaltmp[ThreeTimesI+1];
        NormVertexTab[IndexThirdPoint+2] += NormOriginaltmp[ThreeTimesI+2];
    }

/// Normalisation of theses resulting normales
    int idx;
    for (i=0; i < NbPointIsoMap  ; i++)
    {
        idx = TypeDrawin*i + TypeDrawinNormStep;
        scalar = (double)sqrt((NormVertexTab[idx  ]*NormVertexTab[idx  ]) +
                              (NormVertexTab[idx+1]*NormVertexTab[idx+1]) +
                              (NormVertexTab[idx+2]*NormVertexTab[idx+2]));
        if(scalar < 0.000000001)  scalar = 0.000000001;
        NormVertexTab[idx    ] /= scalar;
        NormVertexTab[idx+1] /= scalar;
        NormVertexTab[idx+2] /= scalar;
    }
}

///++++++++++++++++++++++++++++++++++++++++++
ErrorMessage Iso3D::ParserIso()
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::string varliste = "x,y,z,t";

    (Const != "") ? Nb_constants = HowManyVariables(Const, 1) : Nb_constants =0;
    /*
    for(int j=0; j<Nb_constants; j++)
    {
        Cstparser.Parse(Consts[j],"u");
    }
    */
    initparser(1100);

    //Evaluates defined constantes:
    for(int j=0; j<Nb_constants; j++)
    {
        if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u")) >= 0)
        {
            stdError.strError = Consts[j];
            stdError.strOrigine = ConstNames[j];
            return stdError;
        }
        ConstValues[j] = Cstparser.Eval(&vals[3]);
        Cstparser.AddConstant(ConstNames[j], ConstValues[j]);
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

        for(int i=0; i<Nb_functs; i++)
        {
            for(int j=0; j<i; j++)
                Fct[i].AddFunction(FunctNames[j], Fct[j]);
            if ((stdError.iErrorIndex = Fct[i].Parse(Functs[i],"x,y,z,t"))>=0)
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
                if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u"))>=0)
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
            if ((stdError.iErrorIndex = Var[i].Parse(Varus[i],"u,tm")) >= 0)
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

    //ImplicitFunction is composed of more than one isosurface:
    Nb_implicitfunctions = HowManyIsosurface(ImplicitFunction, 0);
    HowManyIsosurface(XlimitInf, 1);
    HowManyIsosurface(XlimitSup, 2);
    HowManyIsosurface(YlimitInf, 3);
    HowManyIsosurface(YlimitSup, 4);
    HowManyIsosurface(ZlimitInf, 5);
    HowManyIsosurface(ZlimitSup, 6);
    HowManyIsosurface(Grid, 7);
    if(Condition != "")
    {
        IsoConditionRequired = 1;
        HowManyIsosurface(Condition, 8);
    }
    else
        IsoConditionRequired = -1;


    //Add defined constantes:
    for(int i=0; i<Nb_implicitfunctions+1; i++)
    {
        for(int j=0; j<Nb_constants; j++)
        {
            if ((stdError.iErrorIndex = Cstparser.Parse(Consts[j],"u")) >= 0)
            {
                stdError.strError = Consts[j];
                stdError.strOrigine = ConstNames[j];
                return stdError;
            }
            implicitFunctionParser[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            if(Condition != "")
                IsoConditionParser[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            xSupParser[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            ySupParser[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            zSupParser[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            xInfParser[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            yInfParser[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
            zInfParser[i].AddConstant(ConstNames[j], Cstparser.Eval(vals));
        }
    }

    // Add defined functions :
    for(int i=0; i<Nb_implicitfunctions+1; i++)
    {
        for(int j=0; j<Nb_functs; j++)
        {
            implicitFunctionParser[i].AddFunction(FunctNames[j], Fct[j]);
            IsoConditionParser[i].AddFunction(FunctNames[j], Fct[j]);
        }
    }

    return ParseExpression(varliste);
}

///+++++++++++++++++++++++++++++++++++++++++
ErrorMessage Iso3D::ParseExpression(std::string VariableListe)
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    double vals2[] = {0,0};
    const int limitX = nb_ligne, limitY = nb_colon, limitZ = nb_depth;

    if(AllComponentTraited && morph_activated ==1)
    {
        stepMorph += pace;
    }

    vals[3]          = stepMorph;

    for(int i=0; i<Nb_implicitfunctions+1; i++)
    {
        if ((stdError.iErrorIndex = implicitFunctionParser[i].Parse(ImplicitStructs[i].fxyz,VariableListe)) >= 0)
        {
            stdError.strError = ImplicitStructs[i].fxyz;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
        if(Condition != "")
        {
            if ((stdError.iErrorIndex = IsoConditionParser[i].Parse(ImplicitStructs[i].cnd,"x,y,z,t")) >= 0)
            {
                stdError.strError = ImplicitStructs[i].cnd;
                stdError.strOrigine = ImplicitStructs[i].index;
                return stdError;
            }
        }

        if ((stdError.iErrorIndex = xSupParser[i].Parse(ImplicitStructs[i].xmax, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].xmax;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
        if ((stdError.iErrorIndex = ySupParser[i].Parse(ImplicitStructs[i].ymax, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].ymax;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
        if ((stdError.iErrorIndex = zSupParser[i].Parse(ImplicitStructs[i].zmax, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].zmax;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
        if ((stdError.iErrorIndex = xInfParser[i].Parse(ImplicitStructs[i].xmin, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].xmin;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
        if ((stdError.iErrorIndex = yInfParser[i].Parse(ImplicitStructs[i].ymin, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].ymin;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
        if ((stdError.iErrorIndex = zInfParser[i].Parse(ImplicitStructs[i].zmin, "x,y,z,t")) >= 0)
        {
            stdError.strError = ImplicitStructs[i].zmin;
            stdError.strOrigine = ImplicitStructs[i].index;
            return stdError;
        }
    }

    for(int IsoIndex=0; IsoIndex<Nb_implicitfunctions+1; IsoIndex++)
    {
        xLocal[IsoIndex][0]=xSupParser[IsoIndex].Eval(vals);
        yLocal[IsoIndex][0]=ySupParser[IsoIndex].Eval(vals);
        zLocal[IsoIndex][0]=zSupParser[IsoIndex].Eval(vals);

        x_Step[IsoIndex] = /*x_Step[IsoIndex] = */(xLocal[IsoIndex][0] - xInfParser[IsoIndex].Eval(vals))/(limitX-1);
        y_Step[IsoIndex] = /*y_Step[IsoIndex] =*/ (yLocal[IsoIndex][0] - yInfParser[IsoIndex].Eval(vals))/(limitY-1);
        z_Step[IsoIndex] = /*z_Step[IsoIndex] = */(zLocal[IsoIndex][0] - zInfParser[IsoIndex].Eval(vals))/(limitZ-1);

        for (int i= 1; i < limitX; i++)  xLocal[IsoIndex][i] = xLocal[IsoIndex][i-1] - x_Step[IsoIndex];
        for (int j= 1; j < limitY; j++) yLocal[IsoIndex][j] = yLocal[IsoIndex][j-1] - y_Step[IsoIndex];
        for (int k= 1; k < limitZ; k++) zLocal[IsoIndex][k] = zLocal[IsoIndex][k-1] - z_Step[IsoIndex];

        std::string stringtoparse=ImplicitStructs[IsoIndex].fxyz    +
                                  ImplicitStructs[IsoIndex].cnd  +
                                  ImplicitStructs[IsoIndex].xmax  +
                                  ImplicitStructs[IsoIndex].ymax  +
                                  ImplicitStructs[IsoIndex].zmax  +
                                  ImplicitStructs[IsoIndex].xmin   +
                                  ImplicitStructs[IsoIndex].ymin   +
                                  ImplicitStructs[IsoIndex].zmin;


        for(int l=0; l<Nb_newvariables; l++)
        {
            if(stringtoparse.find(VarName [l]+"x") !=std::string::npos )
                for(int i=0; i<limitX; i++)
                {
                    vals2[0] = xLocal[IsoIndex][i];
                    vals2[1] = stepMorph;
                    vr[l*3][IsoIndex][i] =Var[l] .Eval(vals2);
                }

            if(stringtoparse.find(VarName [l]+"y") !=std::string::npos )
                for(int i=0; i<limitY; i++)
                {
                    vals2[0] = yLocal[IsoIndex][i];
                    vals2[1] = stepMorph;
                    vr[l*3+1][IsoIndex][i] =Var[l] .Eval(vals2);
                }

            if(stringtoparse.find(VarName [l]+"z") !=std::string::npos )
                for(int i=0; i<limitZ; i++)
                {
                    vals2[0] = zLocal[IsoIndex][i];
                    vals2[1] = stepMorph;
                    vr[l*3+2][IsoIndex][i] =Var[l] .Eval(vals2);
                }
        }
    }
    return stdError;
}
//+++++++++++++++++++++++++++++++++++++++++
void Iso3D::initparser(int N)
{
    delete[] implicitFunctionParser;
    implicitFunctionParser = new FunctionParser[N];
    for(int i=0; i<N; i++)
    {
        implicitFunctionParser[i].AddConstant("pi", 3.14159265);
    }

    delete[] Fct;
    Fct = new FunctionParser[50];
    for(int i=0; i<50; i++)
    {
        Fct[i].AddConstant("pi", 3.14159265);
    }
}
///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::EvalExpressionAtIndex(int IsoIndex)
{
    double vals[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    double vals2[] = {0,0};
    const int limitX = nb_ligne, limitY = nb_colon, limitZ = nb_depth;

    if(AllComponentTraited && morph_activated ==1)
    {
    stepMorph += pace;
    }
    vals[3]          = stepMorph;

    xLocal[IsoIndex][0]=xSupParser[IsoIndex].Eval(vals);
    yLocal[IsoIndex][0]=ySupParser[IsoIndex].Eval(vals);
    zLocal[IsoIndex][0]=zSupParser[IsoIndex].Eval(vals);

    x_Step[IsoIndex] =  (xLocal[IsoIndex][0] - xInfParser[IsoIndex].Eval(vals))/(limitX-1);
    y_Step[IsoIndex] =  (yLocal[IsoIndex][0] - yInfParser[IsoIndex].Eval(vals))/(limitY-1);
    z_Step[IsoIndex] =  (zLocal[IsoIndex][0] - zInfParser[IsoIndex].Eval(vals))/(limitZ-1);

    for (int i= 1; i < limitX; i++)  xLocal[IsoIndex][i]    = xLocal[IsoIndex][i-1] - x_Step[IsoIndex];
    for (int j= 1; j < limitY; j++) yLocal[IsoIndex][j]      = yLocal[IsoIndex][j-1] - y_Step[IsoIndex];
    for (int k= 1; k < limitZ; k++) zLocal[IsoIndex][k] = zLocal[IsoIndex][k-1] - z_Step[IsoIndex];

    std::string stringtoparse=ImplicitStructs[IsoIndex].fxyz    +
                              ImplicitStructs[IsoIndex].cnd  +
                              ImplicitStructs[IsoIndex].xmax  +
                              ImplicitStructs[IsoIndex].ymax  +
                              ImplicitStructs[IsoIndex].zmax  +
                              ImplicitStructs[IsoIndex].xmin   +
                              ImplicitStructs[IsoIndex].ymin   +
                              ImplicitStructs[IsoIndex].zmin;


    for(int l=0; l<Nb_newvariables; l++)
    {
        if(stringtoparse.find(VarName [l]+"x") !=std::string::npos )
            for(int i=0; i<limitX; i++)
            {
                vals2[0] = xLocal[IsoIndex][i];
                vals2[1] = stepMorph;
                vr[l*3][IsoIndex][i] =Var[l] .Eval(vals2);
            }

        if(stringtoparse.find(VarName [l]+"y") !=std::string::npos )
            for(int i=0; i<limitY; i++)
            {
                vals2[0] = yLocal[IsoIndex][i];
                vals2[1] = stepMorph;
                vr[l*3+1][IsoIndex][i] =Var[l] .Eval(vals2);
            }

        if(stringtoparse.find(VarName [l]+"z") !=std::string::npos )
            for(int i=0; i<limitZ; i++)
            {
                vals2[0] = zLocal[IsoIndex][i];
                vals2[1] = stepMorph;
                vr[l*3+2][IsoIndex][i] =Var[l] .Eval(vals2);
            }
    }
}

void Iso3D::IsoBuild (
    float *NormVertexTabPt,
    unsigned int *IndexPolyTabPt,
    unsigned   int *PolyNumber,
    unsigned int *VertexNumberpt,
    unsigned int *IndexPolyTabMinPt,
    unsigned  int *NbPolyMinPt,
    struct ComponentInfos *components,
    int *TriangleListeCND,
    bool *typeCND
)
{
    int    ThreeTimesI, l, NbTriangleIsoSurfaceTmp, nblignetmp=26;

    PreviousSizeMinimalTopology = 0;
    NbPolyMinimalTopology = 0;
    ThreeTimesNbPolygnTmp=0;
    NbVertexTmp = NbTriangleIsoSurfaceTmp =  0;

    NormVertexTab = NormVertexTabPt;
    IndexPolyTabMin = IndexPolyTabMinPt;
    IndexPolyTab = IndexPolyTabPt;
    if(components != NULL)
        components->NbIso = Nb_implicitfunctions+1;

    if(TriangleListeCND != NULL)
        TypeIsoSurfaceTriangleListeCND = TriangleListeCND;

    if(typeCND != NULL)
        WichPointVerifyCond = typeCND;

    // generate Isosurface for all the implicit formulas
    for(int fctnb= 0; fctnb< Nb_implicitfunctions+1; fctnb++)
    {
        if(fctnb == 0)
            AllComponentTraited = true;
        else
            AllComponentTraited = false;
        //++++++++++++++++++
        if(GridTable[fctnb] > 0)
        {
            nblignetmp = nb_ligne ;
            nb_ligne = nb_colon= nb_depth = GridTable[fctnb];
            EvalExpressionAtIndex(fctnb);
        }
        //++++++++++++++++++

        VoxelEvaluation(fctnb);
        PointEdgeComputation(fctnb);
        SignatureComputation();
        ConstructIsoSurface();
        ConstructIsoNormale();
        SaveIsoGLMap();
        SetMiniMmeshStruct();

        // Save the Index:
        l = 3*NbTriangleIsoSurfaceTmp;
        if(components != NULL)
        {
            components->IsoPositions[2*fctnb       ] = l; //save the starting position of this component
            components->IsoPositions[2*fctnb + 1] = NbTriangleIsoSurface; //save the number of triangles of this component

            components->IsoPts[2*fctnb       ] = NbVertexTmp;
            components->IsoPts[2*fctnb  +1] = NbVertexTmp + NbPointIsoMap -1;
        }
        for ( i=0; i < NbTriangleIsoSurface ; ++i)
        {
            ThreeTimesI = 3*i;
            IndexPolyTab[l    ] = IsoSurfaceTriangleListe[ThreeTimesI     ] + NbVertexTmp;
            IndexPolyTab[l+1] = IsoSurfaceTriangleListe[ThreeTimesI+1] + NbVertexTmp;
            IndexPolyTab[l+2] = IsoSurfaceTriangleListe[ThreeTimesI+2] + NbVertexTmp;
            l+=3;
        }
        // Save Number of Polys and vertex :
        NbVertexTmp                        += NbPointIsoMap;
        NbTriangleIsoSurfaceTmp   += NbTriangleIsoSurface;
        ThreeTimesNbPolygnTmp     = 3*NbTriangleIsoSurfaceTmp;

        if(GridTable[fctnb] > 0)
        {
            nb_ligne = nb_colon = nb_depth = nblignetmp;
            EvalExpressionAtIndex(fctnb);
        }
    }

    //CND calculation for the triangles results:
    CNDCalculation(NbTriangleIsoSurfaceTmp, components);

    //CalculateColorsPoints();

    // Save Number of Polys and vertex :
    *PolyNumber = 3*NbTriangleIsoSurfaceTmp;

    // Index Polygones:
    *NbPolyMinPt = NbPolyMinimalTopology;

    // Vertex :
    *VertexNumberpt = NbVertexTmp;

}

int Iso3D::CNDtoUse(int index, struct ComponentInfos *components)
{
    for(int fctnb= 0; fctnb< Nb_implicitfunctions+1; fctnb++)
        if( index <= components->IsoPts[2*fctnb +1] && index >= components->IsoPts[2*fctnb])
            return fctnb;
    return 30;
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::CalculateColorsPoints()
{
    for(int i= 0; i < NbVertexTmp; i++)
    {
        NormVertexTab[i*TypeDrawin  ] = 0.07;
        NormVertexTab[i*TypeDrawin+1] = 0.05;
        NormVertexTab[i*TypeDrawin+2] = 0.91;
        NormVertexTab[i*TypeDrawin+3] = 0.7;
    }
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::CNDCalculation(int NbTriangleIsoSurfaceTmp, struct ComponentInfos *components)
{
    double vals[4];
    vals[3] = stepMorph;
    if (IsoConditionRequired == 1)
    {
        for(int i= 0; i < NbVertexTmp; i++)
        {
            vals[0] = NormVertexTab[i*TypeDrawin+3+ TypeDrawinNormStep];
            vals[1] = NormVertexTab[i*TypeDrawin+4+ TypeDrawinNormStep];
            vals[2] = NormVertexTab[i*TypeDrawin+5+ TypeDrawinNormStep];
            WichPointVerifyCond[i] = (IsoConditionParser[CNDtoUse(i, components)].Eval(vals) == 1);
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
            int cnd = CNDtoUse(Aindex, components);
            if(TypeTriangle >=0 && TypeTriangle <= 5)
            {
                /// Bprime
                Bprime[0] = NormVertexTab[3+TypeDrawin*Aindex  + TypeDrawinNormStep];
                Bprime[1] = NormVertexTab[3+TypeDrawin*Aindex+1+ TypeDrawinNormStep];
                Bprime[2] = NormVertexTab[3+TypeDrawin*Aindex+2+ TypeDrawinNormStep];
                Bprime[3] = stepMorph;

                DiffX = (NormVertexTab[3+TypeDrawin*Bindex  + TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex  + TypeDrawinNormStep])/20;
                DiffY = (NormVertexTab[3+TypeDrawin*Bindex+1+ TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex+1+ TypeDrawinNormStep])/20;
                DiffZ = (NormVertexTab[3+TypeDrawin*Bindex+2+ TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex+2+ TypeDrawinNormStep])/20;
                Alfa = 0;
                if(TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4)
                {
                    while(IsoConditionParser[cnd].Eval(Bprime) == 1 && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!IsoConditionParser[cnd].Eval(Bprime) == 1 && (Alfa < 20))
                    {
                        Bprime[0] += DiffX;
                        Bprime[1] += DiffY;
                        Bprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }

                /// Cprime
                Cprime[0] = NormVertexTab[3+TypeDrawin*Aindex  + TypeDrawinNormStep];
                Cprime[1] = NormVertexTab[3+TypeDrawin*Aindex+1+ TypeDrawinNormStep];
                Cprime[2] = NormVertexTab[3+TypeDrawin*Aindex+2+ TypeDrawinNormStep];
                Cprime[3] = stepMorph;

                DiffX = (NormVertexTab[3+TypeDrawin*Cindex    + TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex     + TypeDrawinNormStep])/20;
                DiffY = (NormVertexTab[3+TypeDrawin*Cindex+1+ TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex+1+ TypeDrawinNormStep])/20;
                DiffZ = (NormVertexTab[3+TypeDrawin*Cindex+2+ TypeDrawinNormStep] - NormVertexTab[3+TypeDrawin*Aindex+2+ TypeDrawinNormStep])/20;
                Alfa = 0;
                if(TypeTriangle == 0 || TypeTriangle == 2 || TypeTriangle == 4)
                {
                    while(IsoConditionParser[cnd].Eval(Cprime) == 1 && (Alfa < 20))
                    {
                        Cprime[0] += DiffX;
                        Cprime[1] += DiffY;
                        Cprime[2] += DiffZ;
                        Alfa += 1;
                    }
                }
                else
                {
                    while(!IsoConditionParser[cnd].Eval(Cprime) == 1 && (Alfa < 20))
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
                NormVertexTab[TypeDrawin*NbVertexTmp+3+ TypeDrawinNormStep] = Bprime[0];
                NormVertexTab[TypeDrawin*NbVertexTmp+4+ TypeDrawinNormStep] = Bprime[1];
                NormVertexTab[TypeDrawin*NbVertexTmp+5+ TypeDrawinNormStep] = Bprime[2];

                NormVertexTab[TypeDrawin*NbVertexTmp   + TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Bindex      + TypeDrawinNormStep];
                NormVertexTab[TypeDrawin*NbVertexTmp +1+ TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Bindex + 1+ TypeDrawinNormStep];
                NormVertexTab[TypeDrawin*NbVertexTmp +2+ TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Bindex + 2+ TypeDrawinNormStep];
                //Add Cprime:
                NormVertexTab[TypeDrawin*NbVertexTmp+ 3 + TypeDrawin + TypeDrawinNormStep] = Cprime[0];
                NormVertexTab[TypeDrawin*NbVertexTmp+ 4 + TypeDrawin + TypeDrawinNormStep] = Cprime[1];
                NormVertexTab[TypeDrawin*NbVertexTmp+ 5 + TypeDrawin + TypeDrawinNormStep] = Cprime[2];

                NormVertexTab[TypeDrawin*NbVertexTmp +   TypeDrawin+ TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Cindex + TypeDrawinNormStep];
                NormVertexTab[TypeDrawin*NbVertexTmp +1+ TypeDrawin+ TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Cindex + 1+ TypeDrawinNormStep];
                NormVertexTab[TypeDrawin*NbVertexTmp +2+ TypeDrawin+ TypeDrawinNormStep] = NormVertexTab[TypeDrawin*Cindex + 2+ TypeDrawinNormStep];
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

        for(int fctnb= 0; fctnb< Nb_implicitfunctions+1; fctnb++)
        {
            if(components != NULL)
            {
                //if(components->IsoPositions[2*fctnb + 1] > NbTriangleIsoSurfaceTmp )
                components->IsoPositions[2*fctnb + 1] = NbTriangleIsoSurfaceTmp;
            }
        }
        components->ThereisCND = true;

    }
    else
        components->ThereisCND = false;
}
///+++++++++++++++++++++++++++++++++++++++++
Iso3D::~Iso3D()
{
}

///++++++++++++++++++++ ConstructIsoSurface +++++++++++++++++++++++++++
void Iso3D::SetMiniMmeshStruct()
{
    int Index, iter, nbpl, iterpl, lnew;
    int I, J, IJK;
    int maxgrscalemaxgr = maximumgrid*maximumgrid;

    lnew = 0;
    NbPolyMin = 0;
    /// Copy Index Polygons :
    for(i=0; i < nb_ligne-1 - CutLigne; i++)
    {
        I  = i*maxgrscalemaxgr;
        for(j=0; j < nb_colon-1 - CutColon; j++)
        {
            J  = I+j*maximumgrid;
            for(k=0; k < nb_depth-1 - CutDepth; k++)
            {
                IJK = J+k;
                Index = GridVoxelVarPt[IJK].Signature;
                nbpl = triTable_min[Index][16];

                if( nbpl == 1)
                {
                    NbPolyMin += nbpl;
                    IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = triTable_min[Index][17];
                    for(iter = 0; iter < triTable_min[Index][17]; iter++)
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter]]  + NbVertexTmp;
                }
                else if( nbpl == 2)
                {
                    NbPolyMin += nbpl;
                    /// First Poly:
                    IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = triTable_min[Index][17];
                    for(iter = 0; iter < triTable_min[Index][17]; iter++)
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter]]  + NbVertexTmp;
                    /// Second Poly:
                    IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = triTable_min[Index][18];
                    for(iter = triTable_min[Index][17]; iter < triTable_min[Index][17]+triTable_min[Index][18]; iter++)
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter]]  + NbVertexTmp;
                }
                else if( nbpl > 2)
                {
                    NbPolyMin += nbpl;
                    /// In this case we have only Triangles (3 or 4):
                    iter = 0;
                    for(iterpl = 0; iterpl < nbpl; iterpl++)
                    {
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = 3;
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter  ]]  + NbVertexTmp;
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter+1]]  + NbVertexTmp;
                        IndexPolyTabMin[PreviousSizeMinimalTopology + lnew++] = GridVoxelVarPt[IJK].Edge_Points[triTable_min[Index][iter+2]]  + NbVertexTmp;
                        iter +=3;
                    }
                }

            } /// End of for(k=0;
        } /// End of for(j=0;
    } /// End of for(i=0;

    PreviousSizeMinimalTopology += lnew;
    NbPolyMinimalTopology += NbPolyMin;
}

///++++++++++++++++++++ ConstructIsoSurface +++++++++++++++++++++++++++
void Iso3D::ConstructIsoSurface()
{
    int IndexNbTriangle, Index, IndexFirstPoint, IndexSeconPoint, IndexThirdPoint;
    int I, J, IJK;
    int maxgrscalemaxgr = maximumgrid*maximumgrid;

    NbTriangleIsoSurface = 0;
    NbPointIsoMapCND = 0;
    NbTriangleIsoSurface = 0;

    //if(IsoConditionRequired != 1 )
    for(i=0; i < nb_ligne-1 - CutLigne; i++)
    {
        I   = i*maxgrscalemaxgr;
        for(j=0; j < nb_colon-1 - CutColon; j++)
        {
            J   = I+j*maximumgrid;
            for(k=0; k < nb_depth-1 - CutDepth; k++)
            {
                IJK = J+k;
                Index = GridVoxelVarPt[IJK].Signature;
                for (l = 0; triTable[Index][l] != -1 && NbTriangleIsoSurface < NbPolygonImposedLimit; l += 3)
                {
                    IndexFirstPoint      = GridVoxelVarPt[IJK].Edge_Points[triTable[Index][l    ]];
                    IndexSeconPoint   = GridVoxelVarPt[IJK].Edge_Points[triTable[Index][l+1]];
                    IndexThirdPoint     = GridVoxelVarPt[IJK].Edge_Points[triTable[Index][l+2]];
                    {
                        if(IndexFirstPoint != -20 && IndexSeconPoint != -20 && IndexThirdPoint != -20 )
                        {
                            IndexNbTriangle = NbTriangleIsoSurface*3;
                            IsoSurfaceTriangleListe[IndexNbTriangle  ] = IndexFirstPoint;
                            IsoSurfaceTriangleListe[IndexNbTriangle+1] = IndexSeconPoint;
                            IsoSurfaceTriangleListe[IndexNbTriangle+2] = IndexThirdPoint;
                            NbTriangleIsoSurface++;
                        }
                    }
                }
            }
        }
    }
}

///+++++++++++++++++++++++++++++++++++++++++
void Iso3D::PointEdgeComputation(int isoindex)
{
    int index, i_Start, i_End, j_Start, j_End, k_Start, k_End;
    double vals[7], IsoValue_1, IsoValue_2, rapport;
    double factor;
    int maxgrscalemaxgr = maximumgrid*maximumgrid;
    int I, J, JK, IJK, IPLUSONEJK, IMINUSONEJK,
        IJPLUSONEK, IJMINUSONEK, IMINUSONEJMINUSONEK, IsoValue=0, NbPointIsoMap_local=0;
    /// We have to compute the edges for the Grid limits ie: i=0, j=0 and k=0

    i_Start = 1;
    j_Start = 1;
    k_Start = 1;

    i_End = nb_ligne-1;
    j_End = nb_colon-1;
    k_End = nb_depth-1;
    /// The code is doubled to eliminate conditions tests

    for(i = i_Start; i < i_End; i++)
    {
        I = i*maxgrscalemaxgr;
        for(j = j_Start; j < j_End; j++)
        {
            J = I + j*maximumgrid;
            for(k = k_Start; k < k_End; k++)
            {
                IJK                 = J+k;
                IPLUSONEJK          = IJK + maxgrscalemaxgr;
                IMINUSONEJK         = IJK - maxgrscalemaxgr;
                IJPLUSONEK          = IJK + maximumgrid;
                IJMINUSONEK         = IJK - maximumgrid;
                IMINUSONEJMINUSONEK = IMINUSONEJK - maximumgrid;

                IsoValue_1 = Results[IJK];
                /// First Case P(i+1)(j)(k)

                IsoValue_2 = Results[IPLUSONEJK];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0 )
                {
                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i] - factor * x_Step[isoindex];
                    vals[1] = yLocal[isoindex][j];
                    vals[2] = zLocal[isoindex][k];
                    ///===========================================================///
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[IJK].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    GridVoxelVarPt[IJMINUSONEK].Edge_Points[4] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJMINUSONEK].NbEdgePoint += 1;

                    GridVoxelVarPt[IJK-1].Edge_Points[2]   = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK-1].NbEdgePoint += 1;

                    GridVoxelVarPt[IJMINUSONEK-1].Edge_Points[6] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJMINUSONEK-1].NbEdgePoint += 1;

                    NbPointIsoMap_local++;
                }
                ///+++++++++++++++++++++++++++++++++++++++++
                /// Second Case P(i)(j+1)(k)

                IsoValue_2 = Results[IJPLUSONEK];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local ;

                    vals[0] = xLocal[isoindex][i];
                    vals[1] = yLocal[isoindex][j] - factor * y_Step[isoindex];
                    vals[2] = zLocal[isoindex][k];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[IJK].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    GridVoxelVarPt[IMINUSONEJK].Edge_Points[9]    = NbPointIsoMap_local;
                    GridVoxelVarPt[IMINUSONEJK].NbEdgePoint += 1;

                    GridVoxelVarPt[IJK-1].Edge_Points[11]   = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK-1].NbEdgePoint += 1;

                    GridVoxelVarPt[IMINUSONEJK-1].Edge_Points[10] = NbPointIsoMap_local;
                    GridVoxelVarPt[IMINUSONEJK-1].NbEdgePoint += 1;

                    NbPointIsoMap_local++;
                }

                // Third Case P(i)(j)(k+1)

                IsoValue_2 = Results[IJK+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i];
                    vals[1] = yLocal[isoindex][j];
                    vals[2] = zLocal[isoindex][k] - factor * z_Step[isoindex];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[IJK].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[IJK].NbEdgePoint += 1;

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
    for(j=0; j < nb_colon; j++)
    {
        J = j*maximumgrid;
        for(k=0; k < nb_depth; k++)
        {
            JK = J +k;

            IsoValue_1 = Results[JK];

            // First Case P(1)(j)(k)

            IsoValue_2 = Results[maxgrscalemaxgr+JK];
            if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
            {
                // Edge Point computation and  save in IsoPointMap
                factor = (IsoValue - IsoValue_1)/rapport;
                index  = TypeDrawin*NbPointIsoMap_local;

                vals[0] = xLocal[isoindex][i] - factor * x_Step[isoindex];
                vals[1] = yLocal[isoindex][j];
                vals[2] = zLocal[isoindex][k];

                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep ] = vals[0];
                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                // save The reference to this point
                GridVoxelVarPt[JK].Edge_Points[0] = NbPointIsoMap_local;
                GridVoxelVarPt[JK].NbEdgePoint += 1;

                // The same Point is used in three other Voxels
                if( j != 0)
                {
                    GridVoxelVarPt[JK-maximumgrid].Edge_Points[4] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK-maximumgrid].NbEdgePoint += 1;
                }
                if ( k != 0 )
                {
                    GridVoxelVarPt[JK-1].Edge_Points[2]   = NbPointIsoMap_local;
                    GridVoxelVarPt[JK-1].NbEdgePoint += 1;
                }
                if( j != 0 && k != 0)
                {
                    GridVoxelVarPt[JK-maximumgrid-1].Edge_Points[6] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK-maximumgrid-1].NbEdgePoint += 1;
                }

                NbPointIsoMap_local++;
            }

            // Second Case P(0)(j+1)(k)
            if ( j != (nb_colon -1))
            {
                IsoValue_2 = Results[JK+maximumgrid];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i];
                    vals[1] = yLocal[isoindex][j] - factor * y_Step[isoindex];
                    vals[2] = zLocal[isoindex][k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[JK].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if ( k != 0)
                    {
                        GridVoxelVarPt[JK-1].Edge_Points[11]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;
                }
            } /// If ( j != nb_colon -1) ...

            // Third Case P(0)(j)(k+1)
            if ( k != (nb_depth-1))
            {
                IsoValue_2 = Results[JK+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i];
                    vals[1] = yLocal[isoindex][j];
                    vals[2] = zLocal[isoindex][k] - factor * z_Step[isoindex];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[JK].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if ( j != 0)
                    {
                        GridVoxelVarPt[JK-maximumgrid].Edge_Points[7]   =NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maximumgrid].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of ( if ( k != nb_depth -1)....
        }
    }



    /// 2) Case i = nb_ligne-1

    i = nb_ligne-1;
    I = i*maxgrscalemaxgr;
    for(j=0; j < nb_colon; j++)
    {
        J = I + j*maximumgrid;
        for(k=0; k < nb_depth; k++)
        {
            JK = J + k;

            IsoValue_1 = Results[JK];


            // Second Case P(i)(j+1)(k)
            if ( j != (nb_colon -1))
            {
                IsoValue_2 = Results[JK+maximumgrid];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i];
                    vals[1] = yLocal[isoindex][j] - factor * y_Step[isoindex];
                    vals[2] = zLocal[isoindex][k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[JK].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if(i != 0)
                    {
                        GridVoxelVarPt[JK-maxgrscalemaxgr].Edge_Points[9]    =NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maxgrscalemaxgr].NbEdgePoint += 1;
                    }
                    if(k != 0)
                    {
                        GridVoxelVarPt[JK-1].Edge_Points[11]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-1].NbEdgePoint += 1;
                    }
                    if(i != 0 && k != 0)
                    {
                        GridVoxelVarPt[JK-maxgrscalemaxgr-1].Edge_Points[10] = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maxgrscalemaxgr-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if (j != nb_colon -1)...

            // Third Case P(i)(j)(k+1)
            if ( k != (nb_depth -1))
            {
                IsoValue_2 = Results[JK+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i];
                    vals[1] = yLocal[isoindex][j];
                    vals[2] = zLocal[isoindex][k] - factor * z_Step[isoindex];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[JK].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[JK].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( i != 0)
                    {
                        GridVoxelVarPt[JK-maxgrscalemaxgr].Edge_Points[1]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maxgrscalemaxgr].NbEdgePoint += 1;
                    }
                    if(j != 0)
                    {
                        GridVoxelVarPt[JK-maximumgrid].Edge_Points[7]   = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maximumgrid].NbEdgePoint += 1;
                    }
                    if( i !=0 && j != 0)
                    {
                        GridVoxelVarPt[JK-maxgrscalemaxgr-maximumgrid].Edge_Points[5] = NbPointIsoMap_local;
                        GridVoxelVarPt[JK-maxgrscalemaxgr-maximumgrid].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if ( k != nb_depth -1)...
        }
    }



    /// 3) Case j = 0
    j= 0;

    for(i=0; i < nb_ligne; i++)
        for(k=0; k < nb_depth; k++)
        {

            IsoValue_1 = Results[i*maxgrscalemaxgr+k];

            // First Case P(i+1)(j)(k)
            if( i != (nb_ligne -1))
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+k];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {

                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i] - factor * x_Step[isoindex];
                    vals[1] = yLocal[isoindex][j];
                    vals[2] = zLocal[isoindex][k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

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

            IsoValue_2 = Results[i*maxgrscalemaxgr+maximumgrid+k];
            // Edge Point computation and  save in IsoPointMap
            if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
            {
                factor = (IsoValue - IsoValue_1)/rapport;
                index  = TypeDrawin*NbPointIsoMap_local;

                vals[0] = xLocal[isoindex][i];
                vals[1] = yLocal[isoindex][j] - factor * y_Step[isoindex];
                vals[2] = zLocal[isoindex][k];

                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

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
            if(k != (nb_depth -1))
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+k+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i];
                    vals[1] = yLocal[isoindex][j];
                    vals[2] = zLocal[isoindex][k] - factor * z_Step[isoindex];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

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
    j = nb_colon-1;

    for(i=0; i < nb_ligne; i++)
        for(k=0; k < nb_depth; k++)
        {

            IsoValue_1 = Results[i*maxgrscalemaxgr+j*maximumgrid+k];


            // First Case P(i+1)(j)(k)
            if( i != (nb_ligne-1))
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+j*maximumgrid+k];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {

                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i] - factor * x_Step[isoindex];
                    vals[1] = yLocal[isoindex][j];
                    vals[2] = zLocal[isoindex][k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( j != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid+k].Edge_Points[4] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid+k].NbEdgePoint += 1;
                    }
                    if(k != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k-1].Edge_Points[2]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k-1].NbEdgePoint += 1;
                    }
                    if(j != 0 && k != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid+k-1].Edge_Points[6] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid+k-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;


                }
            } /// End of if( i != (nb_ligne-1))...

            // Third Case P(i)(j)(k+1)
            if( k != (nb_depth -1))
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+j*maximumgrid+k+1];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i];
                    vals[1] = yLocal[isoindex][j];
                    vals[2] = zLocal[isoindex][k] - factor * z_Step[isoindex];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k].Edge_Points[3] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if(i !=0)
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maximumgrid+k].Edge_Points[1]   = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maximumgrid+k].NbEdgePoint += 1;
                    }
                    if( j!=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid+k].Edge_Points[7]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid+k].NbEdgePoint += 1;
                    }
                    if(i != 0 && j !=0)
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*maximumgrid+k].Edge_Points[5] = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*maximumgrid+k].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if (k != nb_depth)...
        }


    /// 5) Case k = 0

    k =0;

    for(i=0; i < nb_ligne; i++)
        for(j=0; j < nb_colon; j++)
        {
            IsoValue_1 = Results[i*maxgrscalemaxgr+j*maximumgrid];
            // First Case P(i+1)(j)(k)
            if(i != (nb_ligne -1))
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+j*maximumgrid];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i] - factor * x_Step[isoindex];
                    vals[1] = yLocal[isoindex][j];
                    vals[2] = zLocal[isoindex][k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid].NbEdgePoint += 1;

                    // The same Point is used in one other Voxel
                    if(j !=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid].Edge_Points[4] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;


                }
            } /// End of if(i != (nb_ligne -1))

            // Second Case P(i)(j+1)(k)
            if(j != nb_colon -1)
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+(j+1)*maximumgrid];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i];
                    vals[1] = yLocal[isoindex][j] - factor * y_Step[isoindex];
                    vals[2] = zLocal[isoindex][k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid].NbEdgePoint += 1;

                    // The same Point is used in one other Voxels
                    if ( i !=0 )
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maximumgrid].Edge_Points[9]    = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maximumgrid].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            }/// End of if(j != nb_colon -1)...

            // Third Case P(i)(j)(k+1)

            IsoValue_2 = Results[i*maxgrscalemaxgr+j*maximumgrid+1];
            // Edge Point computation and  save in IsoPointMap
            if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
            {
                factor = (IsoValue - IsoValue_1)/rapport;
                index  = TypeDrawin*NbPointIsoMap_local;

                vals[0] = xLocal[isoindex][i];
                vals[1] = yLocal[isoindex][j];
                vals[2] = zLocal[isoindex][k] - factor * z_Step[isoindex];

                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                // save The reference to this point
                GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid].Edge_Points[3] = NbPointIsoMap_local;
                GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid].NbEdgePoint += 1;

                // The same Point is used in three other Voxels
                if ( i !=0 )
                {
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maximumgrid].Edge_Points[1]   = NbPointIsoMap_local;
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maximumgrid].NbEdgePoint += 1;
                }
                if (j != 0 )
                {
                    GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid].Edge_Points[7]   = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid].NbEdgePoint += 1;
                }
                if ( i !=0 && j != 0 )
                {
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*maximumgrid].Edge_Points[5] = NbPointIsoMap_local;
                    GridVoxelVarPt[(i-1)*maxgrscalemaxgr+(j-1)*maximumgrid].NbEdgePoint += 1;
                }

                NbPointIsoMap_local++;

            }
        }


    /// 6) Case k = nb_depth -1

    k = nb_depth -1;

    for(i=0; i < nb_ligne; i++)
        for(j=0; j < nb_colon; j++)
        {

            IsoValue_1 = Results[i*maxgrscalemaxgr+j*maximumgrid+k];


            // First Case P(i+1)(j)(k)
            if( i != (nb_ligne -1) )
            {
                IsoValue_2 = Results[(i+1)*maxgrscalemaxgr+j*maximumgrid+k];
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {

                    // Edge Point computation and  save in IsoPointMap
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i] - factor * x_Step[isoindex];
                    vals[1] = yLocal[isoindex][j];
                    vals[2] = zLocal[isoindex][k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k].Edge_Points[0] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if(j !=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid+k].Edge_Points[4] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid+k].NbEdgePoint += 1;
                    }
                    if(k !=0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k-1].Edge_Points[2]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k-1].NbEdgePoint += 1;
                    }
                    if(j !=0 && k != 0)
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid+k-1].Edge_Points[6] = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+(j-1)*maximumgrid+k-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;


                }
            } /// End of if(i != nb_ligne-1)...

            // Second Case P(i)(j+1)(k)
            if( j != (nb_colon -1) )
            {
                IsoValue_2 = Results[i*maxgrscalemaxgr+(j+1)*maximumgrid+k];
                // Edge Point computation and  save in IsoPointMap
                if(IsoValue_1 * IsoValue_2 <= 0 && (rapport=IsoValue_2 - IsoValue_1)!=0)
                {
                    factor = (IsoValue - IsoValue_1)/rapport;
                    index  = TypeDrawin*NbPointIsoMap_local;

                    vals[0] = xLocal[isoindex][i];
                    vals[1] = yLocal[isoindex][j] - factor * y_Step[isoindex];
                    vals[2] = zLocal[isoindex][k];

                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index    + TypeDrawinNormStep] = vals[0];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+1  + TypeDrawinNormStep] = vals[1];
                    NormVertexTab[3+ TypeDrawin*NbVertexTmp +index+2  + TypeDrawinNormStep] = vals[2];

                    // save The reference to this point
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k].Edge_Points[8] = NbPointIsoMap_local;
                    GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k].NbEdgePoint += 1;

                    // The same Point is used in three other Voxels
                    if( i !=0 )
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maximumgrid+k].Edge_Points[9]    = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maximumgrid+k].NbEdgePoint += 1;
                    }
                    if( k !=0 )
                    {
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k-1].Edge_Points[11]   = NbPointIsoMap_local;
                        GridVoxelVarPt[i*maxgrscalemaxgr+j*maximumgrid+k-1].NbEdgePoint += 1;
                    }
                    if( i !=0 && k !=0 )
                    {
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maximumgrid+k-1].Edge_Points[10] = NbPointIsoMap_local;
                        GridVoxelVarPt[(i-1)*maxgrscalemaxgr+j*maximumgrid+k-1].NbEdgePoint += 1;
                    }

                    NbPointIsoMap_local++;

                }
            } /// End of if( j != (nb_colon -1) )...

        }


    NbPointIsoMap =    NbPointIsoMap_local;
}



///+++++++++++++++++++++++++++++++++++++++++++++++++++++///
void Iso3D::SignatureComputation()
{

    int i, j, I, J, IJK, IPLUSONEJK,
        IJPLUSONEK,  IPLUSONEJPLUSONEK;
    int maxgrscalemaxgr = maximumgrid*maximumgrid;
    for(i=0; i < nb_ligne; i++)
    {
        I = i*maxgrscalemaxgr;
        for(j=0; j < nb_colon; j++)
        {
            J = I + j*maximumgrid;
            for(k=0; k < nb_depth; k++)
            {
                IJK               = J + k;
                IPLUSONEJK        = IJK + maxgrscalemaxgr;
                IJPLUSONEK        = IJK + maximumgrid;
                IPLUSONEJPLUSONEK = IPLUSONEJK + maximumgrid;

                if(Results[IJK] <= 0) GridVoxelVarPt[IJK].Signature +=1;

                if(i != (nb_ligne-1))
                    if(Results[IPLUSONEJK] <= 0) GridVoxelVarPt[IJK].Signature +=2;

                if(i != (nb_ligne-1) && k != (nb_depth-1))
                    if(Results[IPLUSONEJK+1] <= 0) GridVoxelVarPt[IJK].Signature +=4;

                if(k != (nb_depth-1))
                    if(Results[IJK+1] <= 0) GridVoxelVarPt[IJK].Signature +=8;

                if(j != (nb_colon-1))
                    if(Results[IJPLUSONEK] <= 0) GridVoxelVarPt[IJK].Signature +=16;

                if(i != (nb_ligne-1) && j != (nb_colon-1))
                    if(Results[IPLUSONEJPLUSONEK] <= 0) GridVoxelVarPt[IJK].Signature +=32;

                if(i != (nb_ligne-1) && j != (nb_colon-1) && k != (nb_depth-1))
                    if(Results[IPLUSONEJPLUSONEK+1] <= 0) GridVoxelVarPt[IJK].Signature +=64;

                if(j != (nb_colon-1) && k != (nb_depth-1))
                    if(Results[IJPLUSONEK+1] <= 0) GridVoxelVarPt[IJK].Signature +=128;
            }
        }
    }// End if(Grid...
}
