/***************************************************************************
 *   Copyright (C) 2016 by Abderrahman Taha                                *
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

    #include "isotransformation.h"

/*

    void IsoTransformation::IsoTransformation()
    {
        scalex = scaley = scalez=1;
        twistx = twisty = twistz = 0;
    }
    
    QString IsoTransformation::Twistx(QString ImplicitFunction)
    {
        double vals[2]={0,0};
        QString after_1, after_2, angle, XlimitSup, XlimitInf;
        double tmp;

        for(int j=0; j<Nb_functs; j++)
        {
            implicitFunctionParser[i].AddFunction(FunctNames[j], Fct[j]);
        }



        if(twistx != 0  ||  scalex !=1)
        {
           angle = "1/("+XlimitSup+"-"+XlimitInf+")";
           ExpressionEvaluator.Parse(angle, "t");
           tmp = ExpressionEvaluator.Eval(vals);
    
           tmp *= twistx*2*((double)314159265/(double)100000000)/scalex;
           angle = QString::number(tmp)+"*x";
    
           after_1 = "(y*cos("+angle+") - z*sin("+angle+"))";
           after_2 = "(y*sin("+angle+") + z*cos("+angle+"))";
    
           ImplicitFunction = ImplicitFunction_save;
    
           ImplicitFunction.replace(QChar('y'), "u");
           ImplicitFunction.replace(QChar('z'), "v");
           ImplicitFunction.replace(QChar('u'), after_1);
           ImplicitFunction.replace(QChar('v'), after_2);
       }
       return ImplicitFunction;
    }
    
    QString IsoTransformation::Twisty(QString)
    {
    }
    QString IsoTransformation::Twistz(QString)
    {
    }
*/
