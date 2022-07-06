{
  "MathModels": [
    {
        "Iso3D": {
            "Description": ["Ukraine Heart Flag by Abderrahman Taha 24/02/2022"],
            "Name": ["Ukraine_Heart_Flag"],
            "Component": ["Heart"],
            "Fxyz": ["(x^2+(9/4)*y^2+z^2-1)^3-x^2*z^3-(9/80)*y^2*z^3"],
            "Xmax": ["13/10"],
            "Xmin": ["-13/10"],
            "Ymax": ["1"],
            "Ymin": ["-1"],
            "Zmax": ["13/10"],
            "Zmin": ["-13/10"]
        },
        "Texture": {
            "Colors": ["R=if((z>1/8),(0),(6/10))",
                "G=if((z>1/8),(1/10),(6/10))",
                "B=if((z>1/8),(9/10),(0))",
                "T=1"],
            "Name": "Ukraine_Flag",
            "Noise": ""
        }
    },
    {
        "Param3D": {
            "Description": ["Moebius_Spheres fabric animation by Abderrahman Taha 13/02/2019"],
            "Name": ["Moebius_Spheres"],
            "Funct": ["Fx=cos(v)+u*cos(k*v/2+t/P)*cos(v)","Fy=sin(v)+u*cos(k*v/2+t/P)*sin(v)","Fz=u*sin(k*v/2+t/P)","Fx=Fx(u,v+if((CmpId(0)%N)=0 | (CmpId(0)%N)=(3),t/k0,0*t/k0),t)","Fy=Fy(u,v+if((CmpId(0)%N)=0 | (CmpId(0)%N)=(3),t/k0,0*t/k0),t)","Fz=Fz(u,v+if((CmpId(0)%N)=0 | (CmpId(0)%N)=(3),t/k0,0*t/k0),t)","Px=r0*cos(u)*cos(v)","Py=r0*cos(u)*sin(v)","Pz=r0*sin(u)","Sx=Px(u,v,t)+Fx(u1min+(CmpId(0)%N)*Gu,v1min+floor(CmpId(0)/N)*Gv,t)","Sy=Py(u,v,t)+Fy(u1min+(CmpId(0)%N)*Gu,v1min+floor(CmpId(0)/N)*Gv,t)","Sz=Pz(u,v,t)+Fz(u1min+(CmpId(0)%N)*Gu,v1min+floor(CmpId(0)/N)*Gv,t)","Sx=Sx(u,v,t)","Sy=Sy(u,v,t)","Sz=Sz(u,v,t)"],
            "Const": ["M=20","N=4","r0=13/100","umin=-pi/2","umax=pi/2","vmin=0","vmax=2*pi","u1min=-4/10","u1max=4/10","v1min=0","v1max=2*pi","Gu=(u1max-u1min)/(N-1)","Gv=(v1max-v1min)/(M)","k=1","k0=100","k1=100","k2=100","P=100"],
            "Component": ["Moebius_Sphere_00","Moebius_Sphere_01","Moebius_Sphere_02","Moebius_Sphere_03","Moebius_Sphere_04","Moebius_Sphere_05","Moebius_Sphere_06","Moebius_Sphere_07","Moebius_Sphere_08","Moebius_Sphere_09","Moebius_Sphere_10","Moebius_Sphere_11","Moebius_Sphere_12","Moebius_Sphere_13","Moebius_Sphere_14","Moebius_Sphere_15","Moebius_Sphere_16","Moebius_Sphere_17","Moebius_Sphere_18","Moebius_Sphere_19","Moebius_Sphere_00","Moebius_Sphere_01","Moebius_Sphere_02","Moebius_Sphere_03","Moebius_Sphere_04","Moebius_Sphere_05","Moebius_Sphere_06","Moebius_Sphere_07","Moebius_Sphere_08","Moebius_Sphere_09","Moebius_Sphere_10","Moebius_Sphere_11","Moebius_Sphere_12","Moebius_Sphere_13","Moebius_Sphere_14","Moebius_Sphere_15","Moebius_Sphere_16","Moebius_Sphere_17","Moebius_Sphere_18","Moebius_Sphere_19","Moebius_Sphere_00","Moebius_Sphere_01","Moebius_Sphere_02","Moebius_Sphere_03","Moebius_Sphere_04","Moebius_Sphere_05","Moebius_Sphere_06","Moebius_Sphere_07","Moebius_Sphere_08","Moebius_Sphere_09","Moebius_Sphere_10","Moebius_Sphere_11","Moebius_Sphere_12","Moebius_Sphere_13","Moebius_Sphere_14","Moebius_Sphere_15","Moebius_Sphere_16","Moebius_Sphere_17","Moebius_Sphere_18","Moebius_Sphere_19","Moebius_Sphere_00","Moebius_Sphere_01","Moebius_Sphere_02","Moebius_Sphere_03","Moebius_Sphere_04","Moebius_Sphere_05","Moebius_Sphere_06","Moebius_Sphere_07","Moebius_Sphere_08","Moebius_Sphere_09","Moebius_Sphere_10","Moebius_Sphere_11","Moebius_Sphere_12","Moebius_Sphere_13","Moebius_Sphere_14","Moebius_Sphere_15","Moebius_Sphere_16","Moebius_Sphere_17","Moebius_Sphere_18","Moebius_Sphere_19"],
            "Fx": ["Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)"],
            "Fy": ["Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)"],
            "Fz": ["Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)"],
            "Umax": ["umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax"],
            "Umin": ["umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin"],
            "Vmax": ["vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax"],
            "Vmin": ["vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin"]
        },
        "Sliders": {
            "Max": ["50"],
            "Min": ["0"],
            "Name": ["k"],
            "Position": ["1"],
            "Step": ["1"]
        },
        "Texture": {
            "Colors": ["R=7/10","G=7/10","B=7/10","T=1"],
            "Name": "Lines1",
            "Noise": ""
        }
    },
    {
        "Param3D_C": {
            "Description": ["Domain coloring for the complex function: f(z)=((Z^2-1)*(Z-2-i)^2)/(Z^2+2+3i)  by Abderrahman Taha 28/05/2021"],
            "Name": ["Complex_Domain_Coloring"],
            "Component": ["complex"],
            "Fx": ["u"],
            "Fy": ["v"],
            "Fz": ["0"],
            "Umax": ["3"],
            "Umin": ["-3"],
            "Vmax": ["3"],
            "Vmin": ["-3"]
        },
        "Texture": {
            "Colors": ["H= arg(((Z^2-1)*(Z-2-1i)^2)/(Z*Z+2+3*1i))",
                "S=(2/pi)*atan(abs(((Z^2-1)*(Z-2-1i)^2)/(Z*Z+2+3*1i)))",
                "B= 51/100",
                "T=1"],
            "Name": "Dream",
            "Noise": ""
        }
    },
    {
        "Param3D_C": {
            "Description": ["Complex function: f(Z)=1/(Z*Z+1)"],
            "Name": ["Complex3D_02"],
            "Component": ["complex"],
            "Const": ["A=15/10"],
            "Vect": ["1"],
            "Fx": ["u"],
            "Fy": ["v"],
            "Fz": ["psh((0),real(1/(Z*Z+1)))*if(csd(0)>A,A,if(csd(0)<-A,-A,csd(0)))"],
            "Umax": ["25/10"],
            "Umin": ["-25/10"],
            "Vmax": ["25/10"],
            "Vmin": ["-25/10"]
        }
    },
    {
        "Param3D_C": {
            "Description": ["Complex3D_01 by Abderrahman Taha 28/04/2021"],
            "Description": ["Complex function: f(Z)=2*Z^2+2*Z+2"],
            "Name": ["Complex3D_01"],
            "Component": ["complex"],
            "Fx": ["u"],
            "Fy": ["v"],
            "Fz": ["-abs(2*Z*Z+2*Z+2)/3"],
            "Umax": ["1"],
            "Umin": ["-2"],
            "Vmax": ["2"],
            "Vmin": ["-2"],
            "Grid": ["400","400"]
        },
        "Texture": {
            "Colors": [
                "H= abs(2*Z*Z+2*Z+2)%1",
                "S=cos(arg(2*Z*Z+2*Z+2))",
                "B=5/10",
                "T=1"],
            "Name": "Dream",
            "Noise": ""
        }
    },
    {
        "Param4D_C": {
            "Description": ["Complex_Saddle by Abderrahman Taha 28/04/2021"],
            "Component": ["Saddle"],
            "Name": ["Complex4D_Saddle"],
            "Fx": ["u"],
            "Fy": ["v"],
            "Fz": ["real(Z*Z)/2"],
            "Fw": ["imag(Z*Z)/2"],
            "Umax": ["2"],
            "Umin": ["-2"],
            "Vmax": ["2"],
            "Vmin": ["-2"]
        }
    },
    {
        "Name": "Pariso_01",
        "ParIso": [
            {
                "Param3D": {
                    "Description": ["Blobby Torus by Abderrahman Taha 07/10/2019"],
                    "Name": ["Blobby_Torus"],
                    "Component": ["BlobbyTorus","TwistedTorus"],
                    "Cnd": ["","(z<0)"],
                    "Const": ["N=5","M=16","P=13","k=5","k0=5","k1=5","L=(3/2)","r0=6","dv=(1/100)","P=5","MM=10"],
                    "Funct": ["G1=(8+(sin(2*(u-v+t+sin(v-u)))+3)*cos(u))*cos(v)","G2=(8+(sin(2*(u-v+t+sin(v-u)))+3)*cos(u))*sin(v)","G3=((sin(2*(u-v+t+sin(v-u)))+3)*sin(u))","Fx=(1+(1/2)*cos(v+t))*cos(u-k*(v)+t)","Fy=(1+(1/2)*cos(v+t))*sin(u-k*(v)+t)","Fz=L*sin(v+t)","DFxv = (Fx(u,v+dv,t)-Fx(u,v,t))/dv","DFyv = (Fy(u,v+dv,t)-Fy(u,v,t))/dv","DFzv = (Fz(u,v+dv,t)-Fz(u,v,t))/dv","DFxv2 = (DFxv(u,v+dv,t)-DFxv(u,v,t))/dv","DFyv2 = (DFyv(u,v+dv,t)-DFyv(u,v,t))/dv","DFzv2 = (DFzv(u,v+dv,t)-DFzv(u,v,t))/dv","Rapp = (u/sqrt(u*u+v*v+t*t))","Nx = Rapp(DFxv2(u,v,t),DFyv2(u,v,t),DFzv2(u,v,t))","Ny = Rapp(DFyv2(u,v,t),DFxv2(u,v,t),DFzv2(u,v,t))","Nz = Rapp(DFzv2(u,v,t),DFyv2(u,v,t),DFxv2(u,v,t))","Bx = 1/sqrt(u*u+v*v+t*t)","Binx = (DFyv(u,v,t)*Nz(u,v,t)-DFzv(u,v,t)*Ny(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))","Biny = (DFzv(u,v,t)*Nx(u,v,t)-DFxv(u,v,t)*Nz(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))","Binz = (DFxv(u,v,t)*Ny(u,v,t)-DFyv(u,v,t)*Nx(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))","S = (r0/100)*((k0-1)*cos(u+k1*t)+cos((k0-1)*u+k1*t))","C = (r0/100)*((k0-1)*sin(u+k1*t)-sin((k0-1)*u+k1*t))","Sx = Fx(pi,v,t)+Nx(pi,v,t)*C(u,v,t)+Binx(pi,v,t)*S(u,v,t)","Sy = Fy(pi,v,t)+Ny(pi,v,t)*C(u,v,t)+Biny(pi,v,t)*S(u,v,t)","Sz = Fz(pi,v,t)+Nz(pi,v,t)*C(u,v,t)+Binz(pi,v,t)*S(u,v,t)"],
                    "Fx": ["-(1/2)*G1(u,v,t)+12","(5/3)*Sx(u,v,t/4)-10"],
                    "Fy": ["(1/2)*G2(u,v,t)-5","(5/3)*Sy(u,v,t/4)-5"],
                    "Fz": ["(1/2)*G3(u,v,t)","(5/3)*Sz(u,v,t/4)"],
                    "Grid": ["50","100","50","100"],
                    "Umax": ["2*pi","pi"],
                    "Umin": ["0","-pi"],
                    "Vmax": ["2*pi","2*pi"],
                    "Vmin": ["0","0"]
                },
                "Texture": {"Colors": ["R= if(cmpId = (0),if((abs(7*u)%pi/2 & abs(7*v)%pi/3),(6/10),(1)),abs(cos(u)))","G=if(cmpId = (0),if((abs(7*u)%pi/2| abs(7*v)%pi/3),(8/10),(4/10)),abs(cos(v)))","B=if(cmpId = (0),if((abs(7*u)%pi/2| abs(7*v)%pi/3),(6/10),(1/10)),abs(sin(v)+sin(u))) ","T=1"],
                    "Name": "Candy",
                    "Noise": "1"
                }
            },
            {
                "Iso3D": {
                    "Description": ["BlackHole by Abderrahman Taha 10/12/2019"],
                    "Name": ["BlackHole"],
                    "Component": ["GravityPlan","EarthPlanet","MoonPlanet","WhiteStar ","fallingdrop"],
                    "Cnd": ["(x-y-(3/2)*z<0)","(x-y-(3/2)*z<0)","(x-y-(3/2)*z<0)","(x-y-(3/2)*z<0)",""],
                    "Const": ["M=pi/10","k=5"],
                    "Funct": ["A=(x-4*sin(t*M))^2","B=(x-2*cos(t*M))^2","C=(x-2*sin(t*pi)-4*sin(t*M))^2","D=(x-2*cos(t*pi)-2*cos(t*M))^2","E=(x-1/5)*(x-1/5)-3/5","F=x*x-3/5","H=x*cos(2*t*pi)","G=x*sin(2*t*pi)","Drop=((z-6*(1-cos(sqrt(x^2+y^2)-t*2*pi))/sqrt(x^2+y^2+4))*(2*(x^2+y^2)+(z-40*sin((t+19/100)*pi)+1)^2-10)-1000)"],
                    "Fxyz": ["((3/2)*(H(x,y,z,t)-G(y,x,z,t))^2+(G(x,y,z,t)+H(y,x,z,t))^2+(z+4/5)^2-(abs((11/5)*sin(t*M))))*(A(x,y,z,t)+B(y,x,z,t)+F(z,y,x,t))*min(((3/2)*(H(x,y,z,t)-G(y,x,z,t))^2+(G(x,y,z,t)+H(y,x,z,t))^2+(z+4/5)^2-(abs((11/5)*sin(t*M))))*(A(x,y,z,t)+B(y,x,z,t)+F(z,y,x,t)),z)+1","A(x,y,z,t)+B(y,x,z,t)+E(z,y,x,t)","C(x,y,z,t)+D(y,x,z,t) +E(z,y,x,t)+1/2","(3/2)*(x*cos(2*t*pi)-y*sin(2*t*pi))^2+(x*sin(2*t*pi)+y*cos(2*t*pi))^2+(z+1/5)^2-(abs((1/5)*sin(t*M)+1/20))","Drop(k*x,50+k*y,k*z,t)"],
                    "Grid": ["20","20","20","20","30"],
                    "Xmax": ["5","1+4*sin(t*M)","1+2*sin(t*pi)+4*sin(t*M)","1/2","20/k"],
                    "Xmin": ["-5","-1+4*sin(t*M)","-1+2*sin(t*pi)+4*sin(t*M)","-1/2","-20/k"],
                    "Ymax": ["4","1+2*cos(t*M)","1+2*cos(t*pi)+2*cos(t*M)","1/2","20/k-50/k"],
                    "Ymin": ["-4","-1+2*cos(t*M)","-1+2*cos(t*pi)+2*cos(t*M)","-1/2","-20/k-50/k"],
                    "Zmax": ["1","11/10","1","1/2","50/k"],
                    "Zmin": ["-2","-1","-1","-7/10","-1/k"]
                },
                "Texture": {
                    "Colors": ["R=if(cmpId=(4),(7/10),(1/2))","G=if(cmpId=(4),(7/10),if(cmpId> (0),(8/5)*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2)),(1/2)))","B=if(cmpId=(4),(7/10),if(cmpId> (0),(9/5)*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2)),(1/6)))","T=1"],
                    "Name": "WorleyNoise",
                    "Noise": "1"
                }
            }
        ]
    },
    {
        "Param3D": {
            "Description": ["Groupings of Knots (from Lindsay D Taylor: http://www.mi.sanu.ac.rs/vismath/taylor2009/) by Abderrahman Taha 24/12/2020"],
            "Name": ["Groupings_of_Knots"],
            "Component": ["Knots"],
            "Const": ["N=1","R=12","du=1/1000000"],
            "Funct": ["C1x=cos(v)","C1y=sin(v)","Cx=if (N=(1),R*((59/100)*cos(u)+(3/10)*cos(-2*u)-(9/20)*cos(-5*u)),if (N=(2),R*((3/5)*cos(u)+(1/4)*cos(-3*u)-(13/50)*cos(9*u)),if(N=(3),R*((9/20)*cos(u)+(1/4)*cos(-u)-(9/20)*cos(-3*u)),R*(sin(u)+2*sin(2*u)))))","Cy=if (N=(1),R*((59/100)*sin(u)+(3/10)*sin(-2*u)-(9/20)*sin(-5*u)),if (N=(2),-R*((3/5)*sin(u)+(1/4)*sin(-3*u)-(13/50)*sin(9*u)),if(N=(3),R*((9/20)*sin(u)+(1/4)*sin(-u)-(9/20)*sin(-3*u)),R*(cos(u)-2*cos(2*u)))))","Cz=if (N=(1),(6/5)*R*((1/10)*sin(9*u)+(1/4)*sin(6*u)),if (N=(2),R*((3/25)*sin(16*u)-(3/50)*sin(4*u)),if(N=(3),R*((1/4)*sin(4*u)+(185/1000)*sin(2*u)),R*sin(3*u))))","Rapp=u/sqrt(u*u+v*v+t*t)","dCxu=(Cx(u+du,v,t)-Cx(u,v,t))/du","dCyu=(Cy(u+du,v,t)-Cy(u,v,t))/du","dCzu=(Cz(u+du,v,t)-Cz(u,v,t))/du","axu=Rapp(dCxu(u,v,t),dCyu(u,v,t),dCzu(u,v,t))","ayu=Rapp(dCyu(u,v,t),dCzu(u,v,t),dCxu(u,v,t))","azu=Rapp(dCzu(u,v,t),dCxu(u,v,t),dCyu(u,v,t))","d2Cxu=(axu(u+du,v,t)-axu(u,v,t))/du","d2Cyu=(ayu(u+du,v,t)-ayu(u,v,t))/du","d2Czu=(azu(u+du,v,t)-azu(u,v,t))/du","Ax=Rapp(d2Cxu(u,v,t),d2Cyu(u,v,t),d2Czu(u,v,t))","Ay=Rapp(d2Cyu(u,v,t),d2Czu(u,v,t),d2Cxu(u,v,t))","Az=Rapp(d2Czu(u,v,t),d2Cxu(u,v,t),d2Cyu(u,v,t))","nx=(ayu(u,v,t)*Az(u,v,t)-azu(u,v,t)*Ay(u,v,t))","ny=(azu(u,v,t)*Ax(u,v,t)-axu(u,v,t)*Az(u,v,t))","nz=(axu(u,v,t)*Ay(u,v,t)-ayu(u,v,t)*Ax(u,v,t))","Bx=Rapp(nx(u,v,t),ny(u,v,t),nz(u,v,t))","By=Rapp(ny(u,v,t),nz(u,v,t),nx(u,v,t))","Bz=Rapp(nz(u,v,t),nx(u,v,t),ny(u,v,t))","S1x=Cx(u,v,t)+(C1x(u,v,t)*Bx(u,v,t)+C1y(u,v,t)*Ax(u,v,t))","S1y=Cy(u,v,t)+(C1x(u,v,t)*By(u,v,t)+C1y(u,v,t)*Ay(u,v,t))","S1z=Cz(u,v,t)+(C1x(u,v,t)*Bz(u,v,t)+C1y(u,v,t)*Az(u,v,t))"],
            "Fx": ["S1x(u,v,t)"],
            "Fy": ["S1y(u,v,t)"],
            "Fz": ["S1z(u,v,t)"],
            "Grid": ["650","80"],
            "Umax": ["2*pi"],
            "Umin": ["0"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        },
        "Sliders": {
            "Max": ["40","4","40","4","40","4","40","4"],
            "Min": ["0","1","0","1","0","1","0","1"],
            "Name": ["R","N"],
            "Position": ["22","1","30","2","26","3","2","4"],
            "SetNames": ["Triple_Knot","Quadruple_Knot","Granny_Knot","Trefoil_Knot"],
            "Step": ["1","1","1","1","1","1","1","1"]
        }
    },
    {
        "Param3D": {
            "Description": ["Knotted Moebius strips by Abderrahman Taha 23/12/2020"],
            "Name": ["Knotted_Moebius"],
            "Component": ["Knots_00"],
            "Const": ["h=2","L=8","N=1","R=12","du=1/1000000"],
            "Funct": ["Cx=R*(sin(u)+2*sin(2*u))","Cy=R*(cos(u)-2*cos(2*u))","Cz=R*sin(3*u)","fx=h*cos(v)","fy=L*sin(v)","C1x=fx(u,v,t)*cos(N*u/(2))-fy(u,v,t)*sin(N*u/(2))","C1y=fx(u,v,t)*sin(N*u/(2))+fy(u,v,t)*cos(N*u/(2))","Rapp=u/sqrt(u*u+v*v+t*t)","dCxu=(Cx(u+du,v,t)-Cx(u,v,t))/du","dCyu=(Cy(u+du,v,t)-Cy(u,v,t))/du","dCzu=(Cz(u+du,v,t)-Cz(u,v,t))/du","axu=Rapp(dCxu(u,v,t),dCyu(u,v,t),dCzu(u,v,t))","ayu=Rapp(dCyu(u,v,t),dCzu(u,v,t),dCxu(u,v,t))","azu=Rapp(dCzu(u,v,t),dCxu(u,v,t),dCyu(u,v,t))","d2Cxu=(axu(u+du,v,t)-axu(u,v,t))/du","d2Cyu=(ayu(u+du,v,t)-ayu(u,v,t))/du","d2Czu=(azu(u+du,v,t)-azu(u,v,t))/du","Ax=Rapp(d2Cxu(u,v,t),d2Cyu(u,v,t),d2Czu(u,v,t))","Ay=Rapp(d2Cyu(u,v,t),d2Czu(u,v,t),d2Cxu(u,v,t))","Az=Rapp(d2Czu(u,v,t),d2Cxu(u,v,t),d2Cyu(u,v,t))","nx=(ayu(u,v,t)*Az(u,v,t)-azu(u,v,t)*Ay(u,v,t))","ny=(azu(u,v,t)*Ax(u,v,t)-axu(u,v,t)*Az(u,v,t))","nz=(axu(u,v,t)*Ay(u,v,t)-ayu(u,v,t)*Ax(u,v,t))","Bx=Rapp(nx(u,v,t),ny(u,v,t),nz(u,v,t))","By=Rapp(ny(u,v,t),nz(u,v,t),nx(u,v,t))","Bz=Rapp(nz(u,v,t),nx(u,v,t),ny(u,v,t))","S1x=Cx(u,v,t)+(C1x(u,v,t)*Bx(u,v,t)+C1y(u,v,t)*Ax(u,v,t))","S1y=Cy(u,v,t)+(C1x(u,v,t)*By(u,v,t)+C1y(u,v,t)*Ay(u,v,t))","S1z=Cz(u,v,t)+(C1x(u,v,t)*Bz(u,v,t)+C1y(u,v,t)*Az(u,v,t))"],
            "Fx": ["S1x(u,v,t)"],
            "Fy": ["S1y(u,v,t)"],
            "Fz": ["S1z(u,v,t)"],
            "Grid": ["350","80"],
            "Umax": ["2*pi"],
            "Umin": ["0"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        },
        "Sliders": {
            "Max": ["40","20","20","40","40","20","20","40","40","20","20","40"],
            "Min": ["0","0","0","0","0","0","0","0","0","0","0","0"],
            "Name": ["N","L","h","R"],
            "Position": ["1","8","2","13","32","9","3","21","0","8","2","12"],
            "Step": ["1","1","1","1","1","1","1","1","1","1","1","1"]
        },
        "Texture": {
            "Colors": ["R=if(j_indx>(max_j/4) & j_indx<(3*max_j/4),(6/10),(8/10))","G=if(j_indx>(max_j/4) & j_indx<(3*max_j/4),(1/10),(6/10))","B=if(j_indx>(max_j/4) & j_indx<(3*max_j/4),(1/10),(4/10))","T=1"],
            "Name": "Lines",
            "Noise": ""
        }
    },
    {
        "Param3D": {
            "Description": ["Interlocked Tori (parametric version) by Abderrahman Taha 11/12/2020"],
            "Name": ["Interlocked_Tori_(parametric_version)"],
            "Component": ["TorisTwist_00","TorisTwist_01"],
            "Const": ["k=0","r=1","N=3","R=2","c=pi/100","du=1/1000000"],
            "Funct": ["Cx=R*cos(u)","Cy=R*sin(u)","Cz=0","C1x=r*if(v<pi-k*c,cos(v+N*u/(2)),cos(k*c+N*u/(2)))","C1y=r*if(v<pi-k*c,sin(v+N*u/(2)),sin(k*c+N*u/(2)))","Rapp=u/sqrt(u*u+v*v+t*t)","C2x=r*if(v<2*pi-k*c,cos(v+N*u/(2)),cos(pi+k*c+N*u/(2)))","C2y=r*if(v<2*pi-k*c,sin(v+N*u/(2)),sin(pi+k*c+N*u/(2)))","dCxu=(Cx(u+du,v,t)-Cx(u,v,t))/du","dCyu=(Cy(u+du,v,t)-Cy(u,v,t))/du","dCzu=(Cz(u+du,v,t)-Cz(u,v,t))/du","axu=Rapp(dCxu(u,v,t),dCyu(u,v,t),dCzu(u,v,t))","ayu=Rapp(dCyu(u,v,t),dCzu(u,v,t),dCxu(u,v,t))","azu=Rapp(dCzu(u,v,t),dCxu(u,v,t),dCyu(u,v,t))","d2Cxu=(axu(u+du,v,t)-axu(u,v,t))/du","d2Cyu=(ayu(u+du,v,t)-ayu(u,v,t))/du","d2Czu=(azu(u+du,v,t)-azu(u,v,t))/du","Ax=Rapp(d2Cxu(u,v,t),d2Cyu(u,v,t),d2Czu(u,v,t))","Ay=Rapp(d2Cyu(u,v,t),d2Czu(u,v,t),d2Cxu(u,v,t))","Az=Rapp(d2Czu(u,v,t),d2Cxu(u,v,t),d2Cyu(u,v,t))","nx=(ayu(u,v,t)*Az(u,v,t)-azu(u,v,t)*Ay(u,v,t))","ny=(azu(u,v,t)*Ax(u,v,t)-axu(u,v,t)*Az(u,v,t))","nz=(axu(u,v,t)*Ay(u,v,t)-ayu(u,v,t)*Ax(u,v,t))","Bx=Rapp(nx(u,v,t),ny(u,v,t),nz(u,v,t))","By=Rapp(ny(u,v,t),nz(u,v,t),nx(u,v,t))","Bz=Rapp(nz(u,v,t),nx(u,v,t),ny(u,v,t))","S1x=Cx(u,v,t)+(C1x(u,v,t)*Bx(u,v,t)+C1y(u,v,t)*Ax(u,v,t))","S1y=Cy(u,v,t)+(C1x(u,v,t)*By(u,v,t)+C1y(u,v,t)*Ay(u,v,t))","S1z=Cz(u,v,t)+(C1x(u,v,t)*Bz(u,v,t)+C1y(u,v,t)*Az(u,v,t))","S2x=Cx(u,v,t)+(C2x(u,v,t)*Bx(u,v,t)+C2y(u,v,t)*Ax(u,v,t))","S2y=Cy(u,v,t)+(C2x(u,v,t)*By(u,v,t)+C2y(u,v,t)*Ay(u,v,t))","S2z=Cz(u,v,t)+(C2x(u,v,t)*Bz(u,v,t)+C2y(u,v,t)*Az(u,v,t))"],
            "Fx": ["S1x(u,v,t)","S2x(u,v,t)"],
            "Fy": ["S1y(u,v,t)","S2y(u,v,t)"],
            "Fz": ["S1z(u,v,t)","S2z(u,v,t)"],
            "Grid": ["200","400","200","400"],
            "Umax": ["2*pi","2*pi"],
            "Umin": ["0","0"],
            "Vmax": ["pi-k*c","2*pi-k*c"],
            "Vmin": ["k*c","pi+k*c"]
        },
        "Sliders": {
            "Max": ["50","30","30","30","50","30","30","30","50","30","30","30"],
            "Min": ["0","0","0","0","0","0","0","0","0","0","0","0"],
            "Name": ["k","R","r","N"],
            "Position": ["10","2","1","3","10","2","1","4","10","2","1","2"],
            "Step": ["1","1","1","1","1","1","1","1","1","1","1","1"]
        },
        "Texture": {
            "Colors": ["R=if(j_indx%(max_j/4)>max_j/4-(6),(6/10),(1/10))","G=if(j_indx%(max_j/4)>max_j/4-(6),(1/10),(3/10))","B=if(j_indx%(max_j/4)>max_j/4-(6),(0),(4/10))","T=1"],
            "Name": "Lines",
            "Noise": ""
        }
    },
    {
        "Iso3D": {
            "Description": ["Interlocked Tori by Abderrahman Taha 09/12/2020"],
            "Name": ["Interlocked_Tori"],
            "Component": ["InterlockedTorus"],
            "Const": ["k=3","R=6","r=4","th=10"],
            "Funct": ["Cylinder=x*x+y*y-r*r","Cube=-(abs(x)>(th/8))","TwistyTorus=Cylinder(x,y,z,t)*Cube(x,y,z,t)","TwistyTorus=TwistyTorus(x*cos(k*pi*(z+pi)/(2*pi))-y*sin(k*pi*(z+pi)/(2*pi)),x*sin(k*pi*(z+pi)/(2*pi))+y*cos(k*pi*(z+pi)/(2*pi)),z,t)","TwistyTorus=TwistyTorus(sqrt(x*x+z*z)-R,y,atan2(x,z),t)-3/100"],
            "Fxyz": ["TwistyTorus(x,y,z,1)"],
            "Xmax": ["(R+r+1/10)"],
            "Xmin": ["-(R+r+1/10)"],
            "Ymax": ["r+1/10"],
            "Ymin": ["-r-1/10"],
            "Zmax": ["R+r+1/10"],
            "Zmin": ["-(R+r+1/10)"]
        },
        "Sliders": {
            "Max": ["10","20","20","20","10","20","20","20","10","20","20","20"],
            "Min": ["1","1","1","0","1","1","1","0","1","1","1","0"],
            "Name": ["k","R","r","th"],
            "Position": ["3","6","5","16","2","6","5","16","1","6","4","12"],
            "SetNames": ["Twist_3","Twist_2","Twist_1"],
            "Step": ["1","1","1","1","1","1","1","1","1","1","1","1"]
        }
    },
    {
        "Iso3D": {
            "Description": ["Twisty interlocked Tori (from Keizo Ushio) by Abderrahman Taha 09/12/2020"],
            "Name": ["Twisty_Interlocked_Tori"],
            "Component": ["TwistyTorus","TwistyTorus_01"],
            "Const": ["k=2","R=6","r=3","th=1/8"],
            "Funct": ["Cylinder=x*x+y*y-r*r","Cube=-if(t>(0),(abs(x)>(th))*(x>0),(abs(x)>(th))*(x<0))","TwistyTorus=Cylinder(x,y,z,t)*Cube(x,y,z,t)","TwistyTorus=TwistyTorus(x*cos(k*pi*(z+pi)/(2*pi))-y*sin(k*pi*(z+pi)/(2*pi)),x*sin(k*pi*(z+pi)/(2*pi))+y*cos(k*pi*(z+pi)/(2*pi)),z,t)","TwistyTorus=TwistyTorus(sqrt(x*x+z*z)-R,y,atan2(x,z),t)-3/100"],
            "Fxyz": ["TwistyTorus(x,y,z,(1))","TwistyTorus(y,-x,z-R,(-1))"],
            "Xmax": ["(R+r+1/10)","(R+r+1/10)"],
            "Xmin": ["-(R+r+1/10)","-(R+r+1/10)"],
            "Ymax": ["r+1/10","R+r+1/10"],
            "Ymin": ["-r-1/10","-(R+r+1/10)"],
            "Zmax": ["R+r+1/10","R+r+1/10+R"],
            "Zmin": ["-(R+r+1/10)","-(R+r+1/10)+R"]
        }
    },
    {
        "Param3D": {
            "Description": ["Catalan Surface by Abderrahman Taha 28/11/2020"],
            "Name": ["Catalan_Surface"],
            "Component": ["Catalan"],
            "Const": ["ki=80","kj=5"],
            "Fx": ["cos(u)+2*cos(2*u)+v*((8*cos(u)^2-cos(u)-4)/(-32*cos(u)^3+24*cos(u)+17)^(1/2))"],
            "Fy": ["sin(u)-2*sin(2*u)+v*(-sin(u)*(8*cos(u)+1)/(-32*cos(u)^3+24*cos(u)+17)^(1/2))"],
            "Fz": ["2*sin(3*u)"],
            "Grid": ["800","100"],
            "Umax": ["2*pi"],
            "Umin": ["0"],
            "Vmax": ["pi/4"],
            "Vmin": ["-pi/4"]
        },
        "Texture": {
            "Colors": [
                "R= if((j_indx%floor(max_j/kj))<1  | (i_indx%floor(max_i/ki))<(1), (1/3),(4/10))",
                "G= if((j_indx%floor(max_j/kj))<1  | (i_indx%floor(max_i/ki))<(1), (1/3),(4/10))",
                "B= if((j_indx%floor(max_j/kj))<1  | (i_indx%floor(max_i/ki))<(1), (1/8),(0))",
                "T=1"
            ],
            "Name": "Rainbow",
            "Noise": ""
        }
    },
    {
        "Param3D": {
            "Description": ["Interlocked knots(p,q) by Abderrahman Taha 14/12/2020"],
            "Name": ["Interlocked_PQ_Knots"],
            "Component": ["Knots_00","Knots_01"],
            "Const": ["p=2","q=3","l=3","k=0","r=1","N=3","R=5","c=pi/100","du=1/1000000"],
            "Funct": ["Cx=R*(cos(q*u)+l)*cos(p*u)","Cy=R*(cos(q*u)+l)*sin(p*u)","Cz=-R*sin(q*u)","C1x=r*if(v<pi-k*c,cos(v+N*u/(2)),cos(k*c+N*u/(2)))","C1y=r*if(v<pi-k*c,sin(v+N*u/(2)),sin(k*c+N*u/(2)))","Rapp=u/sqrt(u*u+v*v+t*t)","C2x=r*if(v<2*pi-k*c,cos(v+N*u/(2)),cos(pi+k*c+N*u/(2)))","C2y=r*if(v<2*pi-k*c,sin(v+N*u/(2)),sin(pi+k*c+N*u/(2)))","dCxu=(Cx(u+du,v,t)-Cx(u,v,t))/du","dCyu=(Cy(u+du,v,t)-Cy(u,v,t))/du","dCzu=(Cz(u+du,v,t)-Cz(u,v,t))/du","axu=Rapp(dCxu(u,v,t),dCyu(u,v,t),dCzu(u,v,t))","ayu=Rapp(dCyu(u,v,t),dCzu(u,v,t),dCxu(u,v,t))","azu=Rapp(dCzu(u,v,t),dCxu(u,v,t),dCyu(u,v,t))","d2Cxu=(axu(u+du,v,t)-axu(u,v,t))/du","d2Cyu=(ayu(u+du,v,t)-ayu(u,v,t))/du","d2Czu=(azu(u+du,v,t)-azu(u,v,t))/du","Ax=Rapp(d2Cxu(u,v,t),d2Cyu(u,v,t),d2Czu(u,v,t))","Ay=Rapp(d2Cyu(u,v,t),d2Czu(u,v,t),d2Cxu(u,v,t))","Az=Rapp(d2Czu(u,v,t),d2Cxu(u,v,t),d2Cyu(u,v,t))","nx=(ayu(u,v,t)*Az(u,v,t)-azu(u,v,t)*Ay(u,v,t))","ny=(azu(u,v,t)*Ax(u,v,t)-axu(u,v,t)*Az(u,v,t))","nz=(axu(u,v,t)*Ay(u,v,t)-ayu(u,v,t)*Ax(u,v,t))","Bx=Rapp(nx(u,v,t),ny(u,v,t),nz(u,v,t))","By=Rapp(ny(u,v,t),nz(u,v,t),nx(u,v,t))","Bz=Rapp(nz(u,v,t),nx(u,v,t),ny(u,v,t))","S1x=Cx(u,v,t)+(C1x(u,v,t)*Bx(u,v,t)+C1y(u,v,t)*Ax(u,v,t))","S1y=Cy(u,v,t)+(C1x(u,v,t)*By(u,v,t)+C1y(u,v,t)*Ay(u,v,t))","S1z=Cz(u,v,t)+(C1x(u,v,t)*Bz(u,v,t)+C1y(u,v,t)*Az(u,v,t))","S2x=Cx(u,v,t)+(C2x(u,v,t)*Bx(u,v,t)+C2y(u,v,t)*Ax(u,v,t))","S2y=Cy(u,v,t)+(C2x(u,v,t)*By(u,v,t)+C2y(u,v,t)*Ay(u,v,t))","S2z=Cz(u,v,t)+(C2x(u,v,t)*Bz(u,v,t)+C2y(u,v,t)*Az(u,v,t))"],
            "Fx": ["S1x(u,v,t)","S2x(u,v,t)"],
            "Fy": ["S1y(u,v,t)","S2y(u,v,t)"],
            "Fz": ["S1z(u,v,t)","S2z(u,v,t)"],
            "Grid": ["200","50","200","50"],
            "Umax": ["2*pi","2*pi"],
            "Umin": ["0","0"],
            "Vmax": ["pi-k*c","2*pi-k*c"],
            "Vmin": ["k*c","pi+k*c"]
        },
        "Sliders": {
            "Max": ["50","30","30","30","20","20","30","50","30","30","30","20","20","30","50","30","30","30","20","20","30"],
            "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
            "Name": ["k","R","r","N","p","q","l"],
            "Position": ["5","3","2","19","2","5","3","5","6","4","9","2","3","2","5","6","2","21","3","5","2"],
            "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        },
        "Texture": {
            "Colors": ["R=if(j_indx%(max_j/4)>max_j/4-(3),(6/10),(8/10))","G=if(j_indx%(max_j/4)>max_j/4-(3),(1/10),(6/10))","B=if(j_indx%(max_j/4)>max_j/4-(3),(1/10),(4/10))","T=1"],
            "Name": "Lines",
            "Noise": ""
        }
    },
    {
        "Param3D": {
            "Description": ["Lissajous Knots by Abderrahman Taha 14/12/2020"],
            "Name": ["Lissajous_Knots"],
            "Component": ["LissajousKnots"],
            "Const": ["du=1/1000000","r=8/10","ax=3","ay=4","az=7","tx=1/10","ty=7/10","tz=0"],
            "Funct": ["Cx= cos(ax*u+tx/10)","Cy=-cos(ay*u+ty/10)","Cz= (3/10)*cos(az*u+tz/10)","Rapp=u/sqrt(u*u+v*v+t*t)","dCxu= (Cx(u+du,v,t)-Cx(u,v,t))/du","dCyu= (Cy(u+du,v,t)-Cy(u,v,t))/du","dCzu= (Cz(u+du,v,t)-Cz(u,v,t))/du","axu=Rapp(dCxu(u,v,t),dCyu(u,v,t),dCzu(u,v,t))","ayu=Rapp(dCyu(u,v,t),dCzu(u,v,t),dCxu(u,v,t))","azu=Rapp(dCzu(u,v,t),dCxu(u,v,t),dCyu(u,v,t))","d2Cxu= (axu(u+du,v,t)-axu(u,v,t))/du","d2Cyu= (ayu(u+du,v,t)-ayu(u,v,t))/du","d2Czu= (azu(u+du,v,t)-azu(u,v,t))/du","Ax=Rapp(d2Cxu(u,v,t),d2Cyu(u,v,t),d2Czu(u,v,t))","Ay=Rapp(d2Cyu(u,v,t),d2Czu(u,v,t),d2Cxu(u,v,t))","Az=Rapp(d2Czu(u,v,t),d2Cxu(u,v,t),d2Cyu(u,v,t))","nx=(ayu(u,v,t)*Az(u,v,t)-azu(u,v,t)*Ay(u,v,t))","ny=(azu(u,v,t)*Ax(u,v,t)-axu(u,v,t)*Az(u,v,t))","nz=(axu(u,v,t)*Ay(u,v,t)-ayu(u,v,t)*Ax(u,v,t))","Bx=Rapp(nx(u,v,t),ny(u,v,t),nz(u,v,t))","By=Rapp(ny(u,v,t),nz(u,v,t),nx(u,v,t))","Bz=Rapp(nz(u,v,t),nx(u,v,t),ny(u,v,t))","Sx= Cx(u,v,t)+ (r/100)*(cos(v)*Bx(u,v,t)+sin(v)*Ax(u,v,t))","Sy= Cy(u,v,t)+ (r/100)*(cos(v)*By(u,v,t)+sin(v)*Ay(u,v,t))","Sz= Cz(u,v,t)+ (r/100)*(cos(v)*Bz(u,v,t)+sin(v)*Az(u,v,t))"],
            "Fx": ["Sx(u,v,t)"],
            "Fy": ["Sy(u,v,t)"],
            "Fz": ["Sz(u,v,t)"],
            "Grid": ["300","30"],
            "Umax": ["2*pi"],
            "Umin": ["0"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        },
        "Sliders": {
            "SetNames": ["8_21_knot","Square_knot","Stevedore_knot","Three-twist_knot"],
            "Max": ["15","15","15","20","20","20","100","15","15","15","20","20","20","100","15","15","15","20","20","20","100","15","15","15","20","20","20","100"],
            "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
            "Name": ["ax","ay","az","tx","ty","tz","r"],
            "Position": ["3","4","7","1","7","0","8","3","5","7","7","10","0","5","3","2","5","14","2","0","11","3","2","7","6","2","0","8"],
            "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        }
    },
    {
        "Param3D": {
            "Description ": ["Planar Enneper Parametric surface by Abderrahman Taha 01/12/2020"],
            "Name": ["Planar_Enneper"],
            "Component": ["Planar Enneper"],
            "Const": ["c=1/10000","ki=6","k=11","Lxy=70","Lz=10","umax=0","umin=0"],
            "Funct": ["Fx=cos(v)/(u)+u^(2*k-1)*cos((2*k-1)*v)/Lxy","Fy=-sin(v)/(u)+u^(2*k-1)*sin(-(2*k-1)*v)/Lxy","Fz=u^(k)*cos((k-1)*v)/Lz"],
            "Fx": ["Fx(u,v,t)"],
            "Fy": ["Fy(u,v,t)"],
            "Fz": ["Fz(u,v,t)"],
            "Grid": ["400","800"],
            "Umax": ["13/10-umax/100"],
            "Umin": ["3/10+umin/100"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        },
        "Sliders": {
            "Max": ["20","500","300","100","100","20","500","300","100","100","20","500","300","100","100","20","500","300","100","100"],
            "Min": ["0","1","1","0","0","0","1","1","0","0","0","1","1","0","0","0","1","1","0","0"],
            "Name": ["k","Lxy","Lz","umax","umin"],
            "Position": ["7","28","4","13","19","6","27","4","8","23","5","28","4","0","14","8","2","1","33","13"],
            "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        },
        "Texture": {
            "Colors": [
                "R=if(j_indx%(max_j/(2*(k-1)))<(1) | i_indx%(max_i/(ki+1))<(1),(3/4),abs(sin(u*u*u))/(20/10))",
                "G=if(j_indx%(max_j/(2*(k-1)))<(1) | i_indx%(max_i/(ki+1))<(1),(3/4),abs(cos(u*u*u))/(17/10))",
                "B=if(j_indx%(max_j/(2*(k-1)))<(1) | i_indx%(max_i/(ki+1))<(1),(3/4),abs(cos(u*u*u)+sin(4*u*u*u))/(27/10))",
                "T=1"],
            "Name": "Rainbow",
            "Noise": ""
        }
    },
    {
        "Param3D": {
            "Description": ["Viviani Curve by Abderrahman Taha 22/11/2020"],
            "Component": ["VivianiCurve","Sphere","Cylinder"],
            "Const": ["du=1/1000000","r=20","R=3"],
            "Funct": ["Cylinderx=(R/2)*cos(v)+R/2",
                "Cylindery=(R/2)*sin(v)",
                "Cylinderz=u",
                "Spherex=R*cos(u)*cos(v)",
                "Spherey=R*cos(u)*sin(v)",
                "Spherez=R*sin(u)",
                "M1v=cos(v)",
                "M2v=sin(v)",
                "Cx=R*cos(u)*cos(u)",
                "Cy=R*cos(u)*sin(u)",
                "Cz=R*sin(u)",
                "Rapp=u/sqrt(u*u+v*v+t*t)",
                "dCxu=(Cx(u+du,v,t)-Cx(u,v,t))/du",
                "dCyu=(Cy(u+du,v,t)-Cy(u,v,t))/du",
                "dCzu=(Cz(u+du,v,t)-Cz(u,v,t))/du",
                "axu=Rapp(dCxu(u,v,t),dCyu(u,v,t),dCzu(u,v,t))",
                "ayu=Rapp(dCyu(u,v,t),dCzu(u,v,t),dCxu(u,v,t))",
                "azu=Rapp(dCzu(u,v,t),dCxu(u,v,t),dCyu(u,v,t))",
                "d2Cxu=(axu(u+du,v,t)-axu(u,v,t))/du",
                "d2Cyu=(ayu(u+du,v,t)-ayu(u,v,t))/du",
                "d2Czu=(azu(u+du,v,t)-azu(u,v,t))/du",
                "Ax=Rapp(d2Cxu(u,v,t),d2Cyu(u,v,t),d2Czu(u,v,t))",
                "Ay=Rapp(d2Cyu(u,v,t),d2Czu(u,v,t),d2Cxu(u,v,t))",
                "Az=Rapp(d2Czu(u,v,t),d2Cxu(u,v,t),d2Cyu(u,v,t))",
                "nx=(ayu(u,v,t)*Az(u,v,t)-azu(u,v,t)*Ay(u,v,t))",
                "ny=(azu(u,v,t)*Ax(u,v,t)-axu(u,v,t)*Az(u,v,t))",
                "nz=(axu(u,v,t)*Ay(u,v,t)-ayu(u,v,t)*Ax(u,v,t))",
                "Bx=Rapp(nx(u,v,t),ny(u,v,t),nz(u,v,t))",
                "By=Rapp(ny(u,v,t),nz(u,v,t),nx(u,v,t))",
                "Bz=Rapp(nz(u,v,t),nx(u,v,t),ny(u,v,t))",
                "Sx=Cx(u,v,t)+(r/100)*(M1v(u,v,t)*Bx(u,v,t)+M2v(u,v,t)*Ax(u,v,t))",
                "Sy=Cy(u,v,t)+(r/100)*(M1v(u,v,t)*By(u,v,t)+M2v(u,v,t)*Ay(u,v,t))",
                "Sz=Cz(u,v,t)+(r/100)*(M1v(u,v,t)*Bz(u,v,t)+M2v(u,v,t)*Az(u,v,t))"],
            "Fx": ["Sx(u,v,t)","Spherex(u,v,t)","Cylinderx(u,v,t)"],
            "Fy": ["Sy(u,v,t)","Spherey(u,v,t)","Cylindery(u,v,t)"],
            "Fz": ["Sz(u,v,t)","Spherez(u,v,t)","Cylinderz(u,v,t)"],
            "Grid": ["200","20","60","60","60","60"],
            "Name": ["Viviani_Curve"],
            "Umax": ["2*pi","2*pi/4","3*R/2"],
            "Umin": ["0","-pi/2","-3*R/2"],
            "Vmax": ["2*pi","2*pi","2*pi"],
            "Vmin": ["0","0","0"]
        },
        "Sliders": {
            "Max": ["20"],
            "Min": ["0"],
            "Name": ["R"],
            "Position": ["3"],
            "Step": ["1"]
        }
    },
    {
        "Iso3D": {
            "Description": ["Filament_Cube by Abderrahman Taha 09/10/2020"],
            "Name": ["Filament_Cube"],
            "Component": ["Cube"],
            "Const": ["C=11/10"],
            "Fxyz": ["-(((73/25)*(x-1)*(x^2)*(x+1)+(17/10)*y^2)^2*(y^2-(22/25))^2+((73/25)*(y-1)*y^2*(y+1)+(17/10)*z^2)^2*(z^2-(22/25))^2+((73/25)*(z-1)*z^2*(z+1)+(17/10)*x^2)^2*(x^2-(22/25))^2-(1/20))"],
            "Xmax": ["C"],
            "Xmin": ["-C"],
            "Ymax": ["C"],
            "Ymin": ["-C"],
            "Zmax": ["C"],
            "Zmin": ["-C"]
        }
    },
    {
        "Iso3D": {
            "Description": ["The fundamental patch for the Gyroid by Abderrahman Taha 12/08/2020"],
            "Name": ["Gyroid_Fundamental_Patch"],
            "Cnd": ["(((x+y)>0)*((x-y)<0)*(y+z)*(y-z))>0"],
            "Component": ["Gyroid"],
            "Const": ["L=pi/2"],
            "Fxyz": ["(cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x))"],
            "Grid": ["100"],
            "Xmax": ["L"],
            "Xmin": ["-L"],
            "Ymax": ["L"],
            "Ymin": ["-L"],
            "Zmax": ["L"],
            "Zmin": ["-L"]
        }
    },
    {
        "Iso3D": {
            "Description": ["PrettyCube by Abderrahman Taha 05/08/2020"],
            "Name": ["PrettyCube_01"],
            "Component": ["PrettyCube_1","PrettyCube_2","PrettyCube_3"],
            "Const": ["L=8","c=1/10000","Th2=1","Th1=3/10","N=200"],
            "Funct": ["Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)","DFx=((Iso(x+c,y,z,t)-Iso(x,y,z,t))/c)","DFy=((Iso(x,y+c,z,t)-Iso(x,y,z,t))/c)","DFz=((Iso(x,y,z+c,t)-Iso(x,y,z,t))/c)","Rapp=(x/sqrt(x*x+y*y+z*z))","Iso=(Iso(x+t*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+t*Rapp(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z+t*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))","isoCondition=(x^N+y^N+z^N-(L-1/10)^N)","ThickIso2=(Iso(x,y,z,-t)*Iso(x,y,z,t))","GyroidLatice_1=if(isoCondition(x,y,z,t)<(0),Iso(x,y,z,Th2),1)","GyroidLatice_2=if(isoCondition(x,y,z,t)<(0),Iso(x,y,z,-Th2),(-1))","GyroidLatice_3=if(isoCondition(x,y,z,t)<(0),ThickIso2(x,y,z,Th1),(1))"],
            "Fxyz": ["GyroidLatice_1(x,y,z,t)","GyroidLatice_2(x,y,z,t)","GyroidLatice_3(x,y,z,t)"],
            "Xmax": ["L","L","L"],
            "Xmin": ["-L","-L","-L"],
            "Ymax": ["L","L","L"],
            "Ymin": ["-L","-L","-L"],
            "Zmax": ["L","L","L"],
            "Zmin": ["-L","-L","-L"]
        }
    },
    {
        "Iso3D": {
            "Description": ["Pretty_Cube_02 by Abderrahman Taha 05/08/2020"],
            "Name": ["PrettyCube_02"],
            "Component": ["PrettyCube_1","PrettyCube_2","PrettyCube_3"],
            "Const": ["L=8","c=1/10000","Th2=1","Th1=3/10","N=20"],
            "Funct": ["Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)","DFx=((Iso(x+c,y,z,t)-Iso(x,y,z,t))/c)","DFy=((Iso(x,y+c,z,t)-Iso(x,y,z,t))/c)","DFz=((Iso(x,y,z+c,t)-Iso(x,y,z,t))/c)","Rapp=(x/sqrt(x*x+y*y+z*z))","Rap=(t/sqrt(x*x+y*y+z*z))","Iso1=(Iso(x+t*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+t*Rapp(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z+t*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))","Iso2=psh((0),DFx(x,y,z,t))*psh((1),DFy(x,y,z,t))*psh((2),DFz(x,y,z,t))*(psh((3),Rap(csd(0),csd(1),csd(2),t*Th2)))*(Iso(x+csd(0)*csd(3),y+csd(1)*csd(3),z+csd(2)*csd(3),t))","ThickIso3=psh((0),DFx(x,y,z,t))*psh((1),DFy(x,y,z,t))*psh((2),DFz(x,y,z,t))*(psh((3),Rap(csd(0),csd(1),csd(2),Th1)))*(Iso(x-csd(0)*csd(3),y-csd(1)*csd(3),z-csd(2)*csd(3),t))*(Iso(x+csd(0)*csd(3),y+csd(1)*csd(3),z+csd(2)*csd(3),t))","isoCondition=(x^N+y^N+z^N-(L-1/10)^N)","ThickIso2=(Iso1(x,y,z,-t)*Iso1(x,y,z,t))","GyroidLatice_1=if(isoCondition(x,y,z,t)<(0),Iso2(x,y,z,(1)),(1))","GyroidLatice_2=if(isoCondition(x,y,z,t)<(0),Iso2(x,y,z,(-1)),(-1))","GyroidLatice_3=if(isoCondition(x,y,z,t)<(0),ThickIso3(x,y,z,t),(1))"],
            "Fxyz": ["GyroidLatice_1(x,y,z,t)","GyroidLatice_2(x,y,z,t)","GyroidLatice_3(x,y,z,t)"],
            "Vect": ["4"],
            "Xmax": ["L","L","L"],
            "Xmin": ["-L","-L","-L"],
            "Ymax": ["L","L","L"],
            "Ymin": ["-L","-L","-L"],
            "Zmax": ["L","L","L"],
            "Zmin": ["-L","-L","-L"]
        }
    },
    {
        "Name": "Pariso_02",
        "ParIso": [
            {
                "Param3D": {"Description": ["Blobby Torus by Abderrahman Taha 19/05/2020"],
                        "Component": ["BlobbyTorus"],
                        "Funct": ["G1=(8+(sin(2*(u-v+t+sin(v-u)))+3)*cos(u))*cos(v)","G2=(8+(sin(2*(u-v+t+sin(v-u)))+3)*cos(u))*sin(v)","G3=((sin(2*(u-v+t+sin(v-u)))+3)*sin(u))"],
                        "Fx": ["-G1(u,v,t)"],
                        "Fy": ["G2(u,v,t)"],
                        "Fz": ["G3(u,v,t)-10"],
                        "Grid": ["100","200"],
                        "Name": ["Blobby_Torus"],
                        "Umax": ["2*pi"],
                        "Umin": ["0"],
                        "Vmax": ["2*pi"],
                        "Vmin": ["0"]
                },
                "Texture": {
                        "Colors": ["R= if((abs(7*u)%pi/2& abs(7*v)%pi/3),(6/10),1) ",
                            "G= if((abs(7*u)%pi/2| abs(7*v)%pi/3),(8/10),(4/10)) ",
                            "B= if((abs(7*u)%pi/2| abs(7*v)%pi/3),(6/10),(1/10)) ",
                            "T=1"],
                        "Name": "Candy",
                        "Noise": "1"
                }
            },
            {
                "Iso3D": {"Description": ["Models Intersection by Abderrahman Taha 04/11/2019"],
                        "Cnd": ["(x-y-(3/2)*z<0)",""],
                        "Component": ["Schwarz","Plan"],
                        "Fxyz": ["cos(x-4*sin(t*pi))+cos(y)+cos(z)","x-y-(3/2)*z-(1/100)"],
                        "Name": ["Models_Intersection"],
                        "Xmax": ["4+4*sin(t*pi)","6"],
                        "Xmin": ["-4+4*sin(t*pi)","-6"],
                        "Ymax": ["4","6"],
                        "Ymin": ["-4","-6"],
                        "Zmax": ["4","6"],
                        "Zmin": ["-4","-6"]
                }
            }
        ]
    },
    {
        "Iso3D": {
            "Description": ["Arena_02 using user defined variables by Abderrahman Taha 27/06/2020"],
            "Name": ["Arena_02"],
            "Component": ["Arena"],
            "Const": ["c=1/10000",
                "th=6/10",
                "N=10"],
            "Vect": ["4"],
            "Funct": ["Scherk=sinh(x)*sinh(y)-4*sin(z)",
                "IsoExterior =Scherk(x,sqrt(y*y+z*z)-(16),N*atan2(z,y),t)",
                "DFx=((IsoExterior(x+c,y,z,t)-IsoExterior(x,y,z,t))/c)",
                "DFy=((IsoExterior(x,y+c,z,t)-IsoExterior(x,y,z,t))/c)",
                "DFz=((IsoExterior(x,y,z+c,t)-IsoExterior(x,y,z,t))/c)",
                "Rapp=(th/sqrt(x*x+y*y+z*z))",
                "ThickIsoExterior=  psh((0),DFx(x,y,z,t))*psh((1),DFy(x,y,z,t))*psh((2),DFz(x,y,z,t))*(psh((3),Rapp(csd(0),csd(1),csd(2),t)))*(IsoExterior(x-csd(0)*csd(3),y-csd(1)*csd(3),z-csd(2)*csd(3),t))*(IsoExterior(x+csd(0)*csd(3),y+csd(1)*csd(3),z+csd(2)*csd(3),t))"],
            "Fxyz": ["if((sqrt(x*x+y*y+z*z)-27)<0 & abs(x)<(99/10),ThickIsoExterior(x,y,z,t),(1))"],
            "Xmax": ["10"],
            "Xmin": ["-10"],
            "Ymax": ["28"],
            "Ymin": ["-28"],
            "Zmax": ["28"],
            "Zmin": ["-28"]
        }
    },
    {
        "Iso3D": {
            "Description": ["Pseudo Lawson_CMC Surfaces by Abderrahman Taha 10/05/2020"],
            "Name": ["Lawson_CMC"],
            "Component": ["Lawson_CMC"],
            "Const": ["N=4",
                "c=1/1000",
                "k=1/2",
                "L=4/10",
                "r=1/4",
                "A=4",
                "N1=10",
                "N2=10"],
            "Funct": ["R=k*(x/(x*x+y*y+z*z))",
                "Scherk_0=sinh(x)*sinh(y)-(1/20)*sin(z)",
                "Scherk_1=sinh(x)*sinh(y)-cos(z)",
                "Scherk_2=((sinh(x)*sinh(cos(pi/3)*x-sin(pi/3)*y)*sinh(cos(2*pi/3)*x-sin(2*pi/3)*y)-cos(z)) )",
                "Scherk_3=((sinh(x)*sinh(cos(pi/4)*x-sin(pi/4)*y)*sinh(cos(2*pi/4)*x-sin(2*pi/4)*y)*sinh(cos(3*pi/4)*x-sin(3*pi/4)*y)-cos(z)) )",
                "Scherk_4=((sinh(x)*sinh(cos(pi/5)*x-sin(pi/5)*y)*sinh(cos(2*pi/5)*x-sin(2*pi/5)*y)*sinh(cos(3*pi/5)*x-sin(3*pi/5)*y)*sinh(cos(4*pi/5)*x-sin(4*pi/5)*y)-cos(z)) )",
                "Scherk_5=Scherk_0(N1*atan2(x,sqrt(y*y+z*z)),(sqrt(x*x+y*y+z*z)-r),N2*atan2(z,y),t)",
                "Lawson_CMC=if(N=(1),Scherk_1(R(x,y,z,t),R(y,x,z,t),R(z,y,x,t),t),if(N=(2),Scherk_2((2/5)*R(x,y,z,t),(2/5)*R(y,x,z,t),R(z,y,x,t),t),if(N=(3),Scherk_3((1/3)*R(x,y,z,t),(1/3)*R(y,x,z,t),R(z,y,x,t),t),if(N=(4),Scherk_4((1/3)*R(x,y,z,t),(1/3)*R(y,x,z,t),R(z,y,x,t),t),if(N=(5),Scherk_5(x,y,z,t),Scherk_1(R(x,y,z,t),R(y,x,z,t),R(z,y,x,t),t))))))"],
            "Fxyz": ["Lawson_CMC(x,y,z,t)"],
            "Grid": ["150"],
            "Xmax": ["L"],
            "Xmin": ["-L"],
            "Ymax": ["L"],
            "Ymin": ["-L"],
            "Zmax": ["L"],
            "Zmin": ["-L"]
        },
        "Texture": {
            "Colors": ["R=(7/10)",
                "G=(7/10)",
                "B=(7/10)",
                "T=1"],
            "Name": "Gray",
            "Noise": ""
        }
    },
    {
        "Iso3D": {
            "Description": ["Infinity Fabric by Abderrahman Taha 07/05/2020"],
            "Name": ["Infinity_Fabric"],
            "Component": ["Infinity"],
            "Const": ["c=1/1000",
                "k=1/2",
                "L=1/10"],
            "Funct": ["R=k*(x/(x*x+y*y+z*z))",
                "PSkeletalGraph=cos(x)+cos(y)+cos(z)+(51/100)*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+(147/100)",
                "InvertPSkeletalGraph = PSkeletalGraph(R(x,y,z,t),R(y,x,z,t),R(z,y,x,t),t)"],
            "Fxyz": ["InvertPSkeletalGraph(x,y,z,t)"],
            "Grid": ["300"],
            "Xmax": ["L"],
            "Xmin": ["-L"],
            "Ymax": ["L"],
            "Ymin": ["-L"],
            "Zmax": ["L"],
            "Zmin": ["-L"]
        },
        "Texture": {
            "Colors": ["R=(7/10)",
                "G=(7/10)",
                "B=(7/10)",
                "T=1"],
            "Name": "Gray",
            "Noise": ""
        }
    },
    {
        "Iso3D": {
            "Description": ["InvertSchwarz  by Abderrahman Taha 05/05/2020"],
            "Name": ["InvertSchwarz"],
            "Component": ["InvertSchwarz"],
            "Const": ["c=1/1000",
                "T=1/100",
                "k=3/2",
                "L=3/10"],
            "Funct": ["R=k*(x/(x*x+y*y+z*z))",
                "Schwarz=cos(x)+cos(y)+cos(z)",
                "InvertSchwarz = Schwarz(R(x,y,z,t),R(y,x,z,t),R(z,y,x,t),t) ",
                "InvertSchwarz =(x*x+y*y+z*z-1/90)*min(InvertSchwarz(x,y,z,t),x*x+y*y+z*z-1/90)+1/5000 ",
                "DFx=((InvertSchwarz(x+c,y,z,t)-InvertSchwarz(x,y,z,t))/c)",
                "DFy=((InvertSchwarz(x,y+c,z,t)-InvertSchwarz(x,y,z,t))/c)",
                "DFz=((InvertSchwarz(x,y,z+c,t)-InvertSchwarz(x,y,z,t))/c)",
                "Rapp=(x/sqrt(x*x+y*y+z*z))",
                "Iso=InvertSchwarz(x-t*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-t*Rapp(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z-t*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t)",
                "Iso=if(x*x*x*x+y*y*y*y+z*z*z*z-L*L*L*L<(0),Iso(x,y,z,T)*Iso(x,y,z,-T),(1)) "],
            "Fxyz": ["Iso(x,y,z,t)"],
            "Grid": ["250"],
            "Xmax": ["L"],
            "Xmin": ["-L"],
            "Ymax": ["L"],
            "Ymin": ["-L"],
            "Zmax": ["L"],
            "Zmin": ["-L"]
        },
        "Texture": {
            "Colors": ["R=(7/10)",
                "G=(7/10)",
                "B=(7/10)",
                "T=1"],
            "Name": "Gray",
            "Noise": ""
        }
    },
    {
        "Param3D": {
        "Description": ["Tree Of Life by Abderrahman Taha 11/04/2020"],
        "Name": ["Tree_Of_Life"],
        "Component": ["Tree_00","Tree_00","Tree_01","Tree_02","Tree_03","Tree_04","Tree_05","Tree_06","Tree_07","Tree_08","Tree_09","Tree_10","Tree_11","Tree_12","Tree_13","Tree_14","Tree_15","Tree_16","Tree_17","Tree_18","Tree_19"],
        "Const": ["r=20/15","K=80","v1min=-pi","v1max=pi","M=20","du=1/10000","dv=1/10000","umin=-pi","umax=pi","vmin=0","vmax=2*pi","Gv=(v1max-v1min)/M","d=12"],
        "Funct": ["Fx=(d)*cosh(u)*(cos(v-u))","Fy=(d)*cosh(u)*(sin(v-u))","Fz=K*if(u<(0),-u,u)","Rapp=u/sqrt(u*u+v*v+t*t)","DFxu=((Fx(u+du,v,t)-Fx(u,v,t))/du)","DFxv=((Fx(u,v+dv,t)-Fx(u,v,t))/dv)","DFyu=((Fy(u+du,v,t)-Fy(u,v,t))/du)","DFyv=((Fy(u,v+dv,t)-Fy(u,v,t))/dv)","DFzu=((Fz(u+du,v,t)-Fz(u,v,t))/du)","DFzv=((Fz(u,v+dv,t)-Fz(u,v,t))/dv)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","F2x=Fx(u,v1min+CmpId(0)*Gv,t)","F2y=Fy(u,v1min+CmpId(0)*Gv,t)","F2z=Fz(u,v1min+CmpId(0)*Gv,t)","DF2xu=DFxu(u,v1min+CmpId(0)*Gv,t)","DF2yu=DFyu(u,v1min+CmpId(0)*Gv,t)","DF2zu=DFzu(u,v1min+CmpId(0)*Gv,t)","DF2xu2=n1(u,v1min+CmpId(0)*Gv,t)","DF2yu2=n2(u,v1min+CmpId(0)*Gv,t)","DF2zu2=n3(u,v1min+CmpId(0)*Gv,t)","Nxu=Rapp(DF2xu2(u,v,t),DF2yu2(u,v,t),DF2zu2(u,v,t))","Nyu=Rapp(DF2yu2(u,v,t),DF2xu2(u,v,t),DF2zu2(u,v,t))","Nzu=Rapp(DF2zu2(u,v,t),DF2yu2(u,v,t),DF2xu2(u,v,t))","Binxu=(DF2yu(u,v,t)*Nzu(u,v,t)-DF2zu(u,v,t)*Nyu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Binyu=(DF2zu(u,v,t)*Nxu(u,v,t)-DF2xu(u,v,t)*Nzu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Binzu=(DF2xu(u,v,t)*Nyu(u,v,t)-DF2yu(u,v,t)*Nxu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Tx=F2x(u,v,t)+r*(Nxu(u,v,t)*cos(v)+Binxu(u,v,t)*sin(v))","Ty=F2y(u,v,t)+r*(Nyu(u,v,t)*cos(v)+Binyu(u,v,t)*sin(v))","Tz=F2z(u,v,t)+r*(Nzu(u,v,t)*cos(v)+Binzu(u,v,t)*sin(v))"],
        "Fx": ["Fx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)"],
        "Fy": ["Fy(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)"],
        "Fz": ["Fz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)"],
        "Grid": ["150","140","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40","150","40"],
        "Umax": ["umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax"],
        "Umin": ["umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin"],
        "Vmax": ["vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax"],
        "Vmin": ["vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin"]
        },
        "Texture": {
        "Colors": ["R=if(cmpId=(0),(1),(7/10))","G=7/10","B=if(cmpId=(0),(1/10),(7/10))","T=if(cmpId=(0),(1),(1))"],
        "Name": "Gray",
        "Noise": ""
        }
    },
    {
        "Param3D": {
            "Description": ["Granny Knot by Abderrahman Taha 14/04/2020"],
            "Name": ["Granny_Knot"],
            "Component": ["knot"],
            "Const": ["k1=2","k0=40","r0=7","dv=(1/1000)"],
            "Funct": ["Fx =(-22*cos(v)-128*sin(v)-44*cos(3*v)-78*sin(3*v))/80",
                "Fy =(-10*cos(2*v)-27*sin(2*v)+38*cos(4*v)+46*sin(4*v))/80",
                "Fz =(70*cos(3*v)-40*sin(3*v))/100",
                "DFxv = (Fx(u,v+dv,t)-Fx(u,v,t))/dv",
                "DFyv = (Fy(u,v+dv,t)-Fy(u,v,t))/dv",
                "DFzv = (Fz(u,v+dv,t)-Fz(u,v,t))/dv",
                "DFxv2 = (DFxv(u,v+dv,t)-DFxv(u,v,t))/dv",
                "DFyv2 = (DFyv(u,v+dv,t)-DFyv(u,v,t))/dv",
                "DFzv2 = (DFzv(u,v+dv,t)-DFzv(u,v,t))/dv",
                "Rapp = (u/sqrt(u*u+v*v+t*t))",
                "Nx = Rapp(DFxv2(u,v,t),DFyv2(u,v,t),DFzv2(u,v,t))",
                "Ny = Rapp(DFyv2(u,v,t),DFxv2(u,v,t),DFzv2(u,v,t))",
                "Nz = Rapp(DFzv2(u,v,t),DFyv2(u,v,t),DFxv2(u,v,t))",
                "Bx = 1/sqrt(u*u+v*v+t*t)",
                "Binx = (DFyv(u,v,t)*Nz(u,v,t)-DFzv(u,v,t)*Ny(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))",
                "Biny = (DFzv(u,v,t)*Nx(u,v,t)-DFxv(u,v,t)*Nz(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))",
                "Binz = (DFxv(u,v,t)*Ny(u,v,t)-DFyv(u,v,t)*Nx(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))",
                "S = (r0/100)*((k0-1)*cos(u+k1*t)+cos((k0-1)*u+k1*t))",
                "C = (r0/100)*((k0-1)*sin(u+k1*t)-sin((k0-1)*u+k1*t))",
                "Sx = Fx(pi,v,t)+(r0/100)*(Nx(pi,v,t)*C(u,v,t)+Binx(pi,v,t)*S(u,v,t))",
                "Sy = Fy(pi,v,t)+(r0/100)*(Ny(pi,v,t)*C(u,v,t)+Biny(pi,v,t)*S(u,v,t))",
                "Sz = Fz(pi,v,t)+(r0/100)*(Nz(pi,v,t)*C(u,v,t)+Binz(pi,v,t)*S(u,v,t))"],
            "Fx": ["-Sx(u,v,t)"],
            "Fy": ["Sy(u,v,t)"],
            "Fz": ["Sz(u,v,t)"],
            "Grid": ["50","450"],
            "Umax": ["pi"],
            "Umin": ["-pi"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        }
    },
    {
        "Param3D": {
            "Description": ["Twisted_Multisided_Torus by Abderrahman Taha 01/01/2020"],
            "Name": ["Twisted_Multisided_Torus"],
            "Component": ["knot"],
            "Const": ["N=5","M=16","P=13","k=5","k0=5","k1=2","L=(3/2)","r0=6","dv=(1/100)","P=5","MM=10","p=7","q=2","R=3","r=1","r0=20","r00=30","dv=1/1000"],
            "Funct": ["Rapp = (u/sqrt(u*u+v*v+t*t))","Bx = 1/sqrt(u*u+v*v+t*t)","Fx = (cos(q*v)*(R+(r/10)*cos(p*v)))+(r0/100)*Rapp((-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))*cos(u)+(r0/100)*((R*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v)))*Rapp((-(p*p*r/10)*sin(p*v)),(-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))))-(p*r/10)*cos(p*v)*Rapp((-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v))))*Bx((-R*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v))),(R*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v))),(p*r/10)*cos(p*v))*sin(u)","Fy = (sin(q*v)*(R+(r/10)*cos(p*v)))+(r0/100)*Rapp((-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))*cos(u)+(r0/100)*((p*r/10)*cos(p*v)*Rapp((-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))-(-R*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v)))*Rapp((-(p*p*r/10)*sin(p*v)),(-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v)))))*Bx((-R*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v))),(R*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v))),(p*r/10)*cos(p*v))*sin(u)","Fz = (r/10)*(sin(p*v))+(r0/100)*Rapp((-(p*p*r/10)*sin(p*v)),(-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))))*cos(u)+(r0/100)*((-R*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v)))*Rapp((-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))-(R*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v)))*Rapp((-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v))))*Bx((-R*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v))),(R*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v))),(p*r/10)*cos(p*v))*sin(u)","DFxv = (Fx(u,v+dv,t)-Fx(u,v,t))/dv","DFyv = (Fy(u,v+dv,t)-Fy(u,v,t))/dv","DFzv = (Fz(u,v+dv,t)-Fz(u,v,t))/dv","DFxv2 = (DFxv(u,v+dv,t)-DFxv(u,v,t))/dv","DFyv2 = (DFyv(u,v+dv,t)-DFyv(u,v,t))/dv","DFzv2 = (DFzv(u,v+dv,t)-DFzv(u,v,t))/dv","Rapp = (u/sqrt(u*u+v*v+t*t))","Nx = Rapp(DFxv2(u,v,t),DFyv2(u,v,t),DFzv2(u,v,t))","Ny = Rapp(DFyv2(u,v,t),DFxv2(u,v,t),DFzv2(u,v,t))","Nz = Rapp(DFzv2(u,v,t),DFyv2(u,v,t),DFxv2(u,v,t))","Bx = 1/sqrt(u*u+v*v+t*t)","Binx = (DFyv(u,v,t)*Nz(u,v,t)-DFzv(u,v,t)*Ny(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))","Biny = (DFzv(u,v,t)*Nx(u,v,t)-DFxv(u,v,t)*Nz(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))","Binz = (DFxv(u,v,t)*Ny(u,v,t)-DFyv(u,v,t)*Nx(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))","S = (r0/100)*((k0-1)*cos(u+k1*t)+cos((k0-1)*u+k1*t))","C = (r0/100)*((k0-1)*sin(u+k1*t)-sin((k0-1)*u+k1*t))","Sx = Fx(pi,v,t)+Nx(pi,v,t)*C(u,v,t)+Binx(pi,v,t)*S(u,v,t)","Sy = Fy(pi,v,t)+Ny(pi,v,t)*C(u,v,t)+Biny(pi,v,t)*S(u,v,t)","Sz = Fz(pi,v,t)+Nz(pi,v,t)*C(u,v,t)+Binz(pi,v,t)*S(u,v,t)"],
            "Fx": ["Sx(u,v,t)"],
            "Fy": ["Sy(u,v,t)"],
            "Fz": ["Sz(u,v,t)"],
            "Grid": ["80","200"],
            "Umax": ["pi"],
            "Umin": ["-pi"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        },
        "Sliders": {
            "Max": ["20","20","10","50","100"],
            "Min": ["0","0","0","0","0"],
            "Name": ["p","q","R","r","r0"],
            "Position": ["5","1","2","7","11"],
            "Step": ["1","1","1","1","1"]
        },
        "Texture": {
            "Colors": ["R=abs(cos(u))","G=abs(cos(v))","B=abs(sin(v)+sin(u))","T=1"],
            "Name": "Rainbow",
            "Noise": ""
        }
    },
    {
        "Param3D": {
            "Description": ["Apples on Moebius by Abderrahman Taha 24/03/2019"],
            "Name": ["Apples_on_Moebius"],
            "Funct": ["Yx=r0*cos(u)*(4+(36/10)*cos(v))","Yy=r0*sin(u)*(4+(36/10)*cos(v))","Yz=r0*((cos(v)+sin(v)-1)*(1+sin(v))*log(1-pi*v/10)+(75/10)*sin(v))","Fx=cos(v)+u*cos(v/2+t/P)*cos(v)","Fy=sin(v)+u*cos(v/2+t/P)*sin(v)","Fz=u*sin(v/2+t/P)","Fx=Fx(u,v+if((CmpId(0)%N)=0|((CmpId(0)%N)=3),(t/k0),(0)),t)","Fy=Fy(u,v+if((CmpId(0)%N)=0|((CmpId(0)%N)=3),(t/k0),(0)),t)","Fz=Fz(u,v+if((CmpId(0)%N)=0|((CmpId(0)%N)=3),(t/k0),(0)),t)","Rapp=u/sqrt(u*u+v*v+t*t)","DFxu=((Fx(u+du,v,t)-Fx(u,v,t))/du)","DFxv=((Fx(u,v+dv,t)-Fx(u,v,t))/dv)","DFyu=((Fy(u+du,v,t)-Fy(u,v,t))/du)","DFyv=((Fy(u,v+dv,t)-Fy(u,v,t))/dv)","DFzu=((Fz(u+du,v,t)-Fz(u,v,t))/du)","DFzv=((Fz(u,v+dv,t)-Fz(u,v,t))/dv)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","n1=n1(u1min+(CmpId(0)%N)*Gu,v1min+(floor(CmpId(0)/N))*Gv,t)","n2=n2(u1min+(CmpId(0)%N)*Gu,v1min+(floor(CmpId(0)/N ))*Gv,t)","n3=n3(u1min+(CmpId(0)%N)*Gu,v1min+(floor(CmpId(0)/N ))*Gv,t)","Nx=Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Ny=Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Nz=Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","n01=0","n02=0","n03=1","n1=Rapp(n01(u,v,t),n02(u,v,t),n03(u,v,t))","n2=Rapp(n02(u,v,t),n03(u,v,t),n01(u,v,t))","n3=Rapp(n03(u,v,t),n01(u,v,t),n02(u,v,t))","u1=(n2(u,v,t)*Nz(u,v,t)-n3(u,v,t)*Ny(u,v,t))","u2=(n3(u,v,t)*Nx(u,v,t)-n1(u,v,t)*Nz(u,v,t))","u3=(n1(u,v,t)*Ny(u,v,t)-n2(u,v,t)*Nx(u,v,t))","U1=Rapp(u1(u,v,t),u2(u,v,t),u3(u,v,t))","U2=Rapp(u2(u,v,t),u3(u,v,t),u1(u,v,t))","U3=Rapp(u3(u,v,t),u1(u,v,t),u2(u,v,t))","Angle=-atan2(Nz(u,v,t),sqrt(Nx(u,v,t)^2+Ny(u,v,t)^2))+pi/2","c=cos(Angle(u,v,t))","s=sin(Angle(u,v,t))","S0x=Yx(u,v,t)","S0y=Yy(u,v,t)","S0z=Yz(u,v,t) ","Sx=(U1(u,v,t)^2*(1-c(u,v,t))+c(u,v,t))*S0x(u,v,t)+(U1(u,v,t)*U2(u,v,t)*(1-c(u,v,t))-U3(u,v,t)*s(u,v,t))*S0y(u,v,t)+(U1(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+U2(u,v,t)*s(u,v,t))*S0z(u,v,t)+Fx(u1min+(CmpId(0)%N)*Gu,v1min+(floor(CmpId(0)/N))*Gv,t)","Sy=(U1(u,v,t)*U2(u,v,t)*(1-c(u,v,t))+U3(u,v,t)*s(u,v,t))*S0x(u,v,t)  +(U2(u,v,t)^2*(1-c(u,v,t))+c(u,v,t))*S0y(u,v,t)+(U2(u,v,t)*U3(u,v,t)*(1-c(u,v,t))-U1(u,v,t)*s(u,v,t))*S0z(u,v,t)+Fy(u1min+(CmpId(0)%N)*Gu,v1min+(floor(CmpId(0)/N))*Gv,t)","Sz=(U1(u,v,t)*U3(u,v,t)*(1-c(u,v,t))-U2(u,v,t)*s(u,v,t))*S0x(u,v,t)+(U2(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+U1(u,v,t)*s(u,v,t))*S0y(u,v,t)+(U3(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+c(u,v,t))*S0z(u,v,t)+Fz(u1min+(CmpId(0)%N)*Gu,v1min+(floor(CmpId(0)/N))*Gv,t)"],
            "Component": ["Apples_Moebius_00","Apples_Moebius_01","Apples_Moebius_02","Apples_Moebius_03","Apples_Moebius_04","Apples_Moebius_05","Apples_Moebius_06","Apples_Moebius_07","Apples_Moebius_08","Apples_Moebius_09","Apples_Moebius_10","Apples_Moebius_11","Apples_Moebius_12","Apples_Moebius_13","Apples_Moebius_14","Apples_Moebius_15","Apples_Moebius_16","Apples_Moebius_17","Apples_Moebius_18","Apples_Moebius_19","Apples_Moebius_00","Apples_Moebius_01","Apples_Moebius_02","Apples_Moebius_03","Apples_Moebius_04","Apples_Moebius_05","Apples_Moebius_06","Apples_Moebius_07","Apples_Moebius_08","Apples_Moebius_09","Apples_Moebius_10","Apples_Moebius_11","Apples_Moebius_12","Apples_Moebius_13","Apples_Moebius_14","Apples_Moebius_15","Apples_Moebius_16","Apples_Moebius_17","Apples_Moebius_18","Apples_Moebius_19","Apples_Moebius_00","Apples_Moebius_01","Apples_Moebius_02","Apples_Moebius_03","Apples_Moebius_04","Apples_Moebius_05","Apples_Moebius_06","Apples_Moebius_07","Apples_Moebius_08","Apples_Moebius_09","Apples_Moebius_10","Apples_Moebius_11","Apples_Moebius_12","Apples_Moebius_13","Apples_Moebius_14","Apples_Moebius_15","Apples_Moebius_16","Apples_Moebius_17","Apples_Moebius_18","Apples_Moebius_19","Apples_Moebius_00","Apples_Moebius_01","Apples_Moebius_02","Apples_Moebius_03","Apples_Moebius_04","Apples_Moebius_05","Apples_Moebius_06","Apples_Moebius_07","Apples_Moebius_08","Apples_Moebius_09","Apples_Moebius_10","Apples_Moebius_11","Apples_Moebius_12","Apples_Moebius_13","Apples_Moebius_14","Apples_Moebius_15","Apples_Moebius_16","Apples_Moebius_17","Apples_Moebius_18","Apples_Moebius_19"],
            "Const": ["u1min=-4/10","u1max=4/10","v1min=0","v1max=2*pi","M=20","N=4","r0=15/1000","du=1/100000","dv=1/100000","umin=0","umax=2*pi","vmin=-pi","vmax=pi","Gu=(u1max-u1min)/(N-1)","Gv=(v1max-v1min)/(M)","k0=100","k1=100","k2=100","P=100"],
            "Fx": ["Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)"],
            "Fy": ["Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)"],
            "Fz": ["Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)"],
            "Umax": ["umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax"],
            "Umin": ["umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin"],
            "Vmax": ["vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax"],
            "Vmin": ["vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin"]
        },
        "Texture": {
            "Colors": ["R=6/10","G=6/10","B=6/10","T=1"],
            "Name": "",
            "Noise": ""
        }
    },
    {
        "Param3D": {
        "Description": ["Basket by Abderrahman Taha 11/10/2018"],
        "Name": ["Basket"],
        "Component": ["Basket"],
        "Const": ["d=(33/1000)","k=33","umin=0","umax=2*pi","vmin=0","vmax=2*pi","du=1/10000","dv=1/10000"],
        "Funct": ["Fx=(u/4)*sin(k*u)+v","Fy=(u/4)*cos(k*u)+v","Fz=exp((u^(185/100))/55)+v","Rapp=u/sqrt(u*u+v*v+t*t)","DFxu=((Fx(u+du,v,t)-Fx(u,v,t))/du)","DFxv=((Fx(u,v+dv,t)-Fx(u,v,t))/dv)","DFyu=((Fy(u+du,v,t)-Fy(u,v,t))/du)","DFyv=((Fy(u,v+dv,t)-Fy(u,v,t))/dv)","DFzu=((Fz(u+du,v,t)-Fz(u,v,t))/du)","DFzv=((Fz(u,v+dv,t)-Fz(u,v,t))/dv)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","F2x=Fx(u,(0),t)","F2y=Fy(u,(0),t)","F2z=Fz(u,(0),t)","DF2xu=DFxu(u,(0),t)","DF2yu=DFyu(u,(0),t)","DF2zu=DFzu(u,(0),t)","DF2xu2=n1(u,(0),t)","DF2yu2=n2(u,(0),t)","DF2zu2=n3(u,(0),t)","Nxu=Rapp(DF2xu2(u,v,t),DF2yu2(u,v,t),DF2zu2(u,v,t))","Nyu=Rapp(DF2yu2(u,v,t),DF2xu2(u,v,t),DF2zu2(u,v,t))","Nzu=Rapp(DF2zu2(u,v,t),DF2yu2(u,v,t),DF2xu2(u,v,t))","Binxu=(DF2yu(u,v,t)*Nzu(u,v,t)-DF2zu(u,v,t)*Nyu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Binyu=(DF2zu(u,v,t)*Nxu(u,v,t)-DF2xu(u,v,t)*Nzu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Binzu=(DF2xu(u,v,t)*Nyu(u,v,t)-DF2yu(u,v,t)*Nxu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Tx=F2x(u,v,t)+d*(Nxu(u,v,t)*cos(v)+Binxu(u,v,t)*sin(v))","Ty=F2y(u,v,t)+d*(Nyu(u,v,t)*cos(v)+Binyu(u,v,t)*sin(v))","Tz=F2z(u,v,t)+d*(Nzu(u,v,t)*cos(v)+Binzu(u,v,t)*sin(v))"],
        "Fx": ["Tx(u,v,t)"],
        "Fy": ["Ty(u,v,t)"],
        "Fz": ["Tz(u,v,t)"],
        "Grid": ["40000","20"],
        "Umax": ["umax"],
        "Umin": ["umin"],
        "Vmax": ["vmax"],
        "Vmin": ["vmin"]
        },
        "Texture": {
        "Colors": ["R=(20000*(3*(x^2+y^2)^4-6*x*x*y*y))%(4/10)+(46/100)","G=(100000*((x^2+y^2)-7*x*x*y*y))%(65/100)","B= (20000*((x^2+y^2)^3-10*x*x*y*y))%(2/10)+(1/10)","T=1"],
        "Name": "Trefoil",
        "Noise": ""
        }
    },
    {
         "Param3D": {
         "Description ": ["Spiky Klein by Abderrahman Taha 19/08/2018"],
         "Name": ["Spiky Klein"],
         "Component": ["SpikyKlein"],
         "Const": ["c=1/1000",
         "N=5",
         "A=35/10",
         "B=2",
         "C=3",
         "D=3"],
         "Funct": ["th = (3/10)*((abs(sin(11*u)*cos(11*v)))^19+(1/10)*((sin(2*N*u))))",
         "Fx= if(v<2*pi,(A-(A-1)*cos(v))*cos(u),if(v<3*pi,-B+(B+cos(u))*cos(v),-B+B*cos(v)-cos(u)))",
         "Fy= if(v<2*pi,(A-(A-1)*cos(v))*sin(u),sin(u))",
         "Fz= if(v<pi,-C*sin(v),if(v<2*pi,D*v-D*pi,if(v<3*pi,((D-1)+cos(u))*sin(v)+D*pi,-D*v+D*4*pi)))",
         "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
         "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
         "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
         "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
         "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
         "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
         "n1= (DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
         "n2= (DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
         "n3= (DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
         "Rapp= u/sqrt(u*u+v*v+t*t)",
         "Gx= Fx(u,v,t)+th(u,v-3*t,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
         "Gy= Fy(u,v,t)+th(u,v-3*t,t)*Rapp(n2(u,v,t),n1(u,v,t),n3(u,v,t))",
         "Gz= Fz(u,v,t)+th(u,v-3*t,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
         "Fx": ["Gx(u,v,t)"],
         "Fy": ["Gy(u,v,t)"],
         "Fz": ["Gz(u,v,t)"],
         "Umax": ["2*pi"],
         "Umin": ["0"],
         "Vmax": ["4*pi"],
         "Vmin": ["0"]
         }
    },
    {
        "Iso3D": {
            "Description ": ["Geode by Abderrahman Taha 20/08/2018"],
            "Component": ["Geode1","Geode2"],
            "Const": ["A=4","B=3"],
            "Fxyz": ["-((((x/(101/100))^2+y^2+(z/(105/100))^2-1)+((4/10)*NoiseW(A*x,A*y,A*z,(4),(1),(0)))/3))*(atan2(x,y)<pi/2)*(x^2+y^2+z^2-2/10)","-(((x^2+y^2+z^2-(21/100))*(atan2(x,y)<pi/2)*((x^2+y^2+z^2-2/10)+(NoiseW(B*x,B*y,B*z,(4),(2),(1))+NoiseW(B*x,B*y,B*z,(4),(2),(1)))/5)))"],
            "Name": ["Geode_02"],
            "Xmax": ["(15/10)","(15/10)"],
            "Xmin": ["-1","-1"],
            "Ymax": ["1","1"],
            "Ymin": ["-1","-1"],
            "Zmax": ["(15/10)","(15/10)"],
            "Zmin": ["-(12/10)","-1"]
        },
        "Texture": {
            "Colors": ["R=if((x*x+y*y+z*z)>(81/100),(95/100)*cos((x*x+y*y+z*z)/(17/10)),(2/10))+(2/10)","G=if((x*x+y*y+z*z)>(8/10),(8/10)*(cos((x*x+y*y+z*z)/5)*sin((x*x+y*y+z*z)))*sin((x*x+y*y+z*z)/(3/10)),(5/10)*sin((x*x+y*y+z*z)*9))+(2/10)","B=if((x*x+y*y+z*z)<(8/10),(cos((x*x+y*y+z*z))*cos((x*x+y*y+z*z))*sin((x*x+y*y+z*z)))+(4/10),(1/10))+(5/10)","T=1"],
            "Name": "WorleyNoise",
            "Noise": "-((35/100)*NoiseW(2*x,2*y,2*z,(4),(1),(0))+(178/100)*NoiseW(2*x,2*y,2*z,(4),(0),(0)))"
        }
    },
    {
        "Param3D": {
            "Description": ["Helix Zome by Abderrahman Taha 01/09/2018"],
            "Name": ["Helix Zome"],
            "Funct": ["Fx=(d/4)*(sin((u)+v)+sin(v))","Fy=(d/4)*(cos((u)+v)+cos(v))","Fz=K*if(u<pi,(d/(2*pi))*(u),  (d/(2*pi))*(2*pi-u))","Rapp=u/sqrt(u*u+v*v+t*t)","DFxu=((Fx(u+du,v,t)-Fx(u,v,t))/du)","DFxv=((Fx(u,v+dv,t)-Fx(u,v,t))/dv)","DFyu=((Fy(u+du,v,t)-Fy(u,v,t))/du)","DFyv=((Fy(u,v+dv,t)-Fy(u,v,t))/dv)","DFzu=((Fz(u+du,v,t)-Fz(u,v,t))/du)","DFzv=((Fz(u,v+dv,t)-Fz(u,v,t))/dv)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","F2x=Fx(u,v1min+CmpId(0)*Gv,t)","F2y=Fy(u,v1min+CmpId(0)*Gv,t)","F2z=Fz(u,v1min+CmpId(0)*Gv,t)","DF2xu=DFxu(u,v1min+CmpId(0)*Gv,t)","DF2yu=DFyu(u,v1min+CmpId(0)*Gv,t)","DF2zu=DFzu(u,v1min+CmpId(0)*Gv,t)","DF2xu2=n1(u,v1min +CmpId(0)*Gv,t)","DF2yu2=n2(u,v1min+CmpId(0)*Gv,t)","DF2zu2=n3(u,v1min+CmpId(0)*Gv,t)","Nxu=Rapp(DF2xu2(u,v,t),DF2yu2(u,v,t),DF2zu2(u,v,t))","Nyu=Rapp(DF2yu2(u,v,t),DF2xu2(u,v,t),DF2zu2(u,v,t))","Nzu=Rapp(DF2zu2(u,v,t),DF2yu2(u,v,t),DF2xu2(u,v,t))","Binxu=(DF2yu(u,v,t)*Nzu(u,v,t)-DF2zu(u,v,t)*Nyu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Binyu=(DF2zu(u,v,t)*Nxu(u,v,t)-DF2xu(u,v,t)*Nzu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Binzu=(DF2xu(u,v,t)*Nyu(u,v,t)-DF2yu(u,v,t)*Nxu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Tx=F2x(u,v,t)+(Nxu(u,v,t)*cos(v)+Binxu(u,v,t)*sin(v))","Ty=F2y(u,v,t)+(Nyu(u,v,t)*cos(v)+Binyu(u,v,t)*sin(v))","Tz=F2z(u,v,t)+(Nzu(u,v,t)*cos(v)+Binzu(u,v,t)*sin(v))"],
            "Component": ["Helix_Zome_00","Helix_Zome_01","Helix_Zome_02","Helix_Zome_03","Helix_Zome_04","Helix_Zome_05","Helix_Zome_06","Helix_Zome_07","Helix_Zome_08","Helix_Zome_09","Helix_Zome_10","Helix_Zome_11","Helix_Zome_12","Helix_Zome_13","Helix_Zome_14","Helix_Zome_15","Helix_Zome_16","Helix_Zome_17","Helix_Zome_18","Helix_Zome_19"],
            "Const": ["v1min=0","v1max=2*pi","M=20","du=1/10000","dv=1/10000","umin=0","umax=2*pi","vmin=0","vmax=2*pi","Gv=(v1max-v1min)/M","d=100","K=3/2"],
            "Grid": ["100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60","100","60"],
            "Fx": ["Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)"],
            "Fy": ["Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)"],
            "Fz": ["Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)"],
            "Umax": ["umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax"],
            "Umin": ["umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin"],
            "Vmax": ["vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax"],
            "Vmin": ["vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin"]
        },  "Texture": {
            "Colors": ["R=7/10","G=7/10","B=7/10","T=1"],
            "Name": "Lines",
            "Noise": ""
        }
    },
    {
      "Iso3D": {
        "Description": ["(2,5)-Torusknoten by Stephan Klaus 03/09/2018"],
        "Component": ["Torusknoten"],
        "Const": ["a=22/100","b=2/10","N=10"],
        "Fxyz": ["x^18+9*x^16*y^2+36*x^14*y^4+84*x^12*y^6+126*x^10*y^8+126*x^8*y^10+84*x^6*y^12+36*x^4*y^14+9*x^2*y^16+y^18+4*x^16*z^2+32*x^14*y^2*z^2+112*x^12*y^4*z^2+224*x^10*y^6*z^2+280*x^8*y^8*z^2+224*x^6*y^10*z^2+112*x^4*y^12*z^2+32*x^2*y^14*z^2+4*y^16*z^2+6*x^14*z^4+42*x^12*y^2*z^4+126*x^10*y^4*z^4+210*x^8*y^6*z^4+210*x^6*y^8*z^4+126*x^4*y^10*z^4+42*x^2*y^12*z^4+6*y^14*z^4+4*x^12*z^6+24*x^10*y^2*z^6+60*x^8*y^4*z^6+80*x^6*y^6*z^6+60*x^4*y^8*z^6+24*x^2*y^10*z^6+4*y^12*z^6+x^10*z^8+5*x^8*y^2*z^8+10*x^6*y^4*z^8+10*x^4*y^6*z^8+5*x^2*y^8*z^8+y^10*z^8-40*x^14*y*z*a^2-120*x^12*y^3*z*a^2-8*x^10*y^5*z*a^2+360*x^8*y^7*z*a^2+520*x^6*y^9*z*a^2+280*x^4*y^11*z*a^2+40*x^2*y^13*z*a^2-8*y^15*z*a^2-80*x^12*y*z^3*a^2-160*x^10*y^3*z^3*a^2+144*x^8*y^5*z^3*a^2+576*x^6*y^7*z^3*a^2+464*x^4*y^9*z^3*a^2+96*x^2*y^11*z^3*a^2-16*y^13*z^3*a^2-40*x^10*y*z^5*a^2-40*x^8*y^3*z^5*a^2+112*x^6*y^5*z^5*a^2+176*x^4*y^7*z^5*a^2+56*x^2*y^9*z^5*a^2-8*y^11*z^5*a^2-2*x^14*a^4+86*x^12*y^2*a^4-242*x^10*y^4*a^4-330*x^8*y^6*a^4+330*x^6*y^8*a^4+242*x^4*y^10*a^4-86*x^2*y^12*a^4+2*y^14*a^4+12*x^12*z^2*a^4+272*x^10*y^2*z^2*a^4-420*x^8*y^4*z^2*a^4+320*x^6*y^6*z^2*a^4+900*x^4*y^8*z^2*a^4-80*x^2*y^10*z^2*a^4+20*y^12*z^2*a^4-2*x^10*z^4*a^4+90*x^8*y^2*z^4*a^4-420*x^6*y^4*z^4*a^4+420*x^4*y^6*z^4*a^4-90*x^2*y^8*z^4*a^4+2*y^10*z^4*a^4-40*x^10*y*z*a^6-40*x^8*y^3*z*a^6+112*x^6*y^5*z*a^6+176*x^4*y^7*z*a^6+56*x^2*y^9*z*a^6-8*y^11*z*a^6+x^10*a^8+5*x^8*y^2*a^8+10*x^6*y^4*a^8+10*x^4*y^6*a^8+5*x^2*y^8*a^8+y^10*a^8-4*x^16*b^2-32*x^14*y^2*b^2-112*x^12*y^4*b^2-224*x^10*y^6*b^2-280*x^8*y^8*b^2-224*x^6*y^10*b^2-112*x^4*y^12*b^2-32*x^2*y^14*b^2-4*y^16*b^2-12*x^14*z^2*b^2-84*x^12*y^2*z^2*b^2-252*x^10*y^4*z^2*b^2-420*x^8*y^6*z^2*b^2-420*x^6*y^8*z^2*b^2-252*x^4*y^10*z^2*b^2-84*x^2*y^12*z^2*b^2-12*y^14*z^2*b^2-12*x^12*z^4*b^2-72*x^10*y^2*z^4*b^2-180*x^8*y^4*z^4*b^2-240*x^6*y^6*z^4*b^2-180*x^4*y^8*z^4*b^2-72*x^2*y^10*z^4*b^2-12*y^12*z^4*b^2-4*x^10*z^6*b^2-20*x^8*y^2*z^6*b^2-40*x^6*y^4*z^6*b^2-40*x^4*y^6*z^6*b^2-20*x^2*y^8*z^6*b^2-4*y^10*z^6*b^2-4*x^14*a^2*b^2-28*x^12*y^2*a^2*b^2-84*x^10*y^4*a^2*b^2-140*x^8*y^6*a^2*b^2-140*x^6*y^8*a^2*b^2-84*x^4*y^10*a^2*b^2-28*x^2*y^12*a^2*b^2-4*y^14*a^2*b^2+80*x^12*y*z*a^2*b^2+160*x^10*y^3*z*a^2*b^2-144*x^8*y^5*z*a^2*b^2-576*x^6*y^7*z*a^2*b^2-464*x^4*y^9*z*a^2*b^2-96*x^2*y^11*z*a^2*b^2+16*y^13*z*a^2*b^2-8*x^12*z^2*a^2*b^2-48*x^10*y^2*z^2*a^2*b^2-120*x^8*y^4*z^2*a^2*b^2-160*x^6*y^6*z^2*a^2*b^2-120*x^4*y^8*z^2*a^2*b^2-48*x^2*y^10*z^2*a^2*b^2-8*y^12*z^2*a^2*b^2+80*x^10*y*z^3*a^2*b^2+80*x^8*y^3*z^3*a^2*b^2-224*x^6*y^5*z^3*a^2*b^2-352*x^4*y^7*z^3*a^2*b^2-112*x^2*y^9*z^3*a^2*b^2+16*y^11*z^3*a^2*b^2-4*x^10*z^4*a^2*b^2-20*x^8*y^2*z^4*a^2*b^2-40*x^6*y^4*z^4*a^2*b^2-40*x^4*y^6*z^4*a^2*b^2-20*x^2*y^8*z^4*a^2*b^2-4*y^10*z^4*a^2*b^2-4*x^12*a^4*b^2-24*x^10*y^2*a^4*b^2-60*x^8*y^4*a^4*b^2-80*x^6*y^6*a^4*b^2-60*x^4*y^8*a^4*b^2-24*x^2*y^10*a^4*b^2-4*y^12*a^4*b^2+80*x^10*y*z*a^4*b^2+80*x^8*y^3*z*a^4*b^2-224*x^6*y^5*z*a^4*b^2-352*x^4*y^7*z*a^4*b^2-112*x^2*y^9*z*a^4*b^2+16*y^11*z*a^4*b^2-4*x^10*z^2*a^4*b^2-20*x^8*y^2*z^2*a^4*b^2-40*x^6*y^4*z^2*a^4*b^2-40*x^4*y^6*z^2*a^4*b^2-20*x^2*y^8*z^2*a^4*b^2-4*y^10*z^2*a^4*b^2-4*x^10*a^6*b^2-20*x^8*y^2*a^6*b^2-40*x^6*y^4*a^6*b^2-40*x^4*y^6*a^6*b^2-20*x^2*y^8*a^6*b^2-4*y^10*a^6*b^2+6*x^14*b^4+42*x^12*y^2*b^4+126*x^10*y^4*b^4+210*x^8*y^6*b^4+210*x^6*y^8*b^4+126*x^4*y^10*b^4+42*x^2*y^12*b^4+6*y^14*b^4+12*x^12*z^2*b^4+72*x^10*y^2*z^2*b^4+180*x^8*y^4*z^2*b^4+240*x^6*y^6*z^2*b^4+180*x^4*y^8*z^2*b^4+72*x^2*y^10*z^2*b^4+12*y^12*z^2*b^4+6*x^10*z^4*b^4+30*x^8*y^2*z^4*b^4+60*x^6*y^4*z^4*b^4+60*x^4*y^6*z^4*b^4+30*x^2*y^8*z^4*b^4+6*y^10*z^4*b^4+8*x^12*a^2*b^4+48*x^10*y^2*a^2*b^4+120*x^8*y^4*a^2*b^4+160*x^6*y^6*a^2*b^4+120*x^4*y^8*a^2*b^4+48*x^2*y^10*a^2*b^4+8*y^12*a^2*b^4-40*x^10*y*z*a^2*b^4-40*x^8*y^3*z*a^2*b^4+112*x^6*y^5*z*a^2*b^4+176*x^4*y^7*z*a^2*b^4+56*x^2*y^9*z*a^2*b^4-8*y^11*z*a^2*b^4+8*x^10*z^2*a^2*b^4+40*x^8*y^2*z^2*a^2*b^4+80*x^6*y^4*z^2*a^2*b^4+80*x^4*y^6*z^2*a^2*b^4+40*x^2*y^8*z^2*a^2*b^4+8*y^10*z^2*a^2*b^4+6*x^10*a^4*b^4+30*x^8*y^2*a^4*b^4+60*x^6*y^4*a^4*b^4+60*x^4*y^6*a^4*b^4+30*x^2*y^8*a^4*b^4+6*y^10*a^4*b^4-4*x^12*b^6-24*x^10*y^2*b^6-60*x^8*y^4*b^6-80*x^6*y^6*b^6-60*x^4*y^8*b^6-24*x^2*y^10*b^6-4*y^12*b^6-4*x^10*z^2*b^6-20*x^8*y^2*z^2*b^6-40*x^6*y^4*z^2*b^6-40*x^4*y^6*z^2*b^6-20*x^2*y^8*z^2*b^6-4*y^10*z^2*b^6-4*x^10*a^2*b^6-20*x^8*y^2*a^2*b^6-40*x^6*y^4*a^2*b^6-40*x^4*y^6*a^2*b^6-20*x^2*y^8*a^2*b^6-4*y^10*a^2*b^6+x^10*b^8+5*x^8*y^2*b^8+10*x^6*y^4*b^8+10*x^4*y^6*b^8+5*x^2*y^8*b^8+y^10*b^8-8*x^15*a^2+40*x^13*y^2*a^2+280*x^11*y^4*a^2+520*x^9*y^6*a^2+360*x^7*y^8*a^2-8*x^5*y^10*a^2-120*x^3*y^12*a^2-40*x*y^14*a^2+16*x^13*z^2*a^2-96*x^11*y^2*z^2*a^2-464*x^9*y^4*z^2*a^2-576*x^7*y^6*z^2*a^2-144*x^5*y^8*z^2*a^2+160*x^3*y^10*z^2*a^2+80*x*y^12*z^2*a^2+24*x^11*z^4*a^2-168*x^9*y^2*z^4*a^2-528*x^7*y^4*z^4*a^2-336*x^5*y^6*z^4*a^2+120*x^3*y^8*z^4*a^2+120*x*y^10*z^4*a^2-80*x^11*y*z*a^4+880*x^9*y^3*z*a^4-1056*x^7*y^5*z*a^4-1056*x^5*y^7*z*a^4+880*x^3*y^9*z*a^4-80*x*y^11*z*a^4-80*x^9*y*z^3*a^4+960*x^7*y^3*z^3*a^4-2016*x^5*y^5*z^3*a^4+960*x^3*y^7*z^3*a^4-80*x*y^9*z^3*a^4+8*x^11*a^6-56*x^9*y^2*a^6-176*x^7*y^4*a^6-112*x^5*y^6*a^6+40*x^3*y^8*a^6+40*x*y^10*a^6-32*x^11*z^2*a^2*b^2+224*x^9*y^2*z^2*a^2*b^2+704*x^7*y^4*z^2*a^2*b^2+448*x^5*y^6*z^2*a^2*b^2-160*x^3*y^8*z^2*a^2*b^2-160*x*y^10*z^2*a^2*b^2-16*x^11*a^4*b^2+112*x^9*y^2*a^4*b^2+352*x^7*y^4*a^4*b^2+224*x^5*y^6*a^4*b^2-80*x^3*y^8*a^4*b^2-80*x*y^10*a^4*b^2+8*x^11*a^2*b^4-56*x^9*y^2*a^2*b^4-176*x^7*y^4*a^2*b^4-112*x^5*y^6*a^2*b^4+40*x^3*y^8*a^2*b^4+40*x*y^10*a^2*b^4-4*x^16-32*x^14*y^2-112*x^12*y^4-224*x^10*y^6-280*x^8*y^8-224*x^6*y^10-112*x^4*y^12-32*x^2*y^14-4*y^16-4*x^14*z^2-28*x^12*y^2*z^2-84*x^10*y^4*z^2-140*x^8*y^6*z^2-140*x^6*y^8*z^2-84*x^4*y^10*z^2-28*x^2*y^12*z^2-4*y^14*z^2+4*x^12*z^4+24*x^10*y^2*z^4+60*x^8*y^4*z^4+80*x^6*y^6*z^4+60*x^4*y^8*z^4+24*x^2*y^10*z^4+4*y^12*z^4+4*x^10*z^6+20*x^8*y^2*z^6+40*x^6*y^4*z^6+40*x^4*y^6*z^6+20*x^2*y^8*z^6+4*y^10*z^6-80*x^12*y*z*a^2-160*x^10*y^3*z*a^2+144*x^8*y^5*z*a^2+576*x^6*y^7*z*a^2+464*x^4*y^9*z*a^2+96*x^2*y^11*z*a^2-16*y^13*z*a^2+80*x^10*y*z^3*a^2+80*x^8*y^3*z^3*a^2-224*x^6*y^5*z^3*a^2-352*x^4*y^7*z^3*a^2-112*x^2*y^9*z^3*a^2+16*y^11*z^3*a^2+20*x^12*a^4-80*x^10*y^2*a^4+900*x^8*y^4*a^4+320*x^6*y^6*a^4-420*x^4*y^8*a^4+272*x^2*y^10*a^4+12*y^12*a^4+12*x^10*z^2*a^4-540*x^8*y^2*z^2*a^4+2520*x^6*y^4*z^2*a^4-2520*x^4*y^6*z^2*a^4+540*x^2*y^8*z^2*a^4-12*y^10*z^2*a^4+4*x^14*b^2+28*x^12*y^2*b^2+84*x^10*y^4*b^2+140*x^8*y^6*b^2+140*x^6*y^8*b^2+84*x^4*y^10*b^2+28*x^2*y^12*b^2+4*y^14*b^2-8*x^12*z^2*b^2-48*x^10*y^2*z^2*b^2-120*x^8*y^4*z^2*b^2-160*x^6*y^6*z^2*b^2-120*x^4*y^8*z^2*b^2-48*x^2*y^10*z^2*b^2-8*y^12*z^2*b^2-12*x^10*z^4*b^2-60*x^8*y^2*z^4*b^2-120*x^6*y^4*z^4*b^2-120*x^4*y^6*z^4*b^2-60*x^2*y^8*z^4*b^2-12*y^10*z^4*b^2-24*x^12*a^2*b^2-144*x^10*y^2*a^2*b^2-360*x^8*y^4*a^2*b^2-480*x^6*y^6*a^2*b^2-360*x^4*y^8*a^2*b^2-144*x^2*y^10*a^2*b^2-24*y^12*a^2*b^2-80*x^10*y*z*a^2*b^2-80*x^8*y^3*z*a^2*b^2+224*x^6*y^5*z*a^2*b^2+352*x^4*y^7*z*a^2*b^2+112*x^2*y^9*z*a^2*b^2-16*y^11*z*a^2*b^2-8*x^10*z^2*a^2*b^2-40*x^8*y^2*z^2*a^2*b^2-80*x^6*y^4*z^2*a^2*b^2-80*x^4*y^6*z^2*a^2*b^2-40*x^2*y^8*z^2*a^2*b^2-8*y^10*z^2*a^2*b^2-4*x^10*a^4*b^2-20*x^8*y^2*a^4*b^2-40*x^6*y^4*a^4*b^2-40*x^4*y^6*a^4*b^2-20*x^2*y^8*a^4*b^2-4*y^10*a^4*b^2+4*x^12*b^4+24*x^10*y^2*b^4+60*x^8*y^4*b^4+80*x^6*y^6*b^4+60*x^4*y^8*b^4+24*x^2*y^10*b^4+4*y^12*b^4+12*x^10*z^2*b^4+60*x^8*y^2*z^2*b^4+120*x^6*y^4*z^2*b^4+120*x^4*y^6*z^2*b^4+60*x^2*y^8*z^2*b^4+12*y^10*z^2*b^4+8*x^10*a^2*b^4+40*x^8*y^2*a^2*b^4+80*x^6*y^4*a^2*b^4+80*x^4*y^6*a^2*b^4+40*x^2*y^8*a^2*b^4+8*y^10*a^2*b^4-4*x^10*b^6-20*x^8*y^2*b^6-40*x^6*y^4*b^6-40*x^4*y^6*b^6-20*x^2*y^8*b^6-4*y^10*b^6+16*x^13*a^2-96*x^11*y^2*a^2-464*x^9*y^4*a^2-576*x^7*y^6*a^2-144*x^5*y^8*a^2+160*x^3*y^10*a^2+80*x*y^12*a^2+16*x^11*z^2*a^2-112*x^9*y^2*z^2*a^2-352*x^7*y^4*z^2*a^2-224*x^5*y^6*z^2*a^2+80*x^3*y^8*z^2*a^2+80*x*y^10*z^2*a^2+80*x^9*y*z*a^4-960*x^7*y^3*z*a^4+2016*x^5*y^5*z*a^4-960*x^3*y^7*z*a^4+80*x*y^9*z*a^4+6*x^14+42*x^12*y^2+126*x^10*y^4+210*x^8*y^6+210*x^6*y^8+126*x^4*y^10+42*x^2*y^12+6*y^14-4*x^12*z^2-24*x^10*y^2*z^2-60*x^8*y^4*z^2-80*x^6*y^6*z^2-60*x^4*y^8*z^2-24*x^2*y^10*z^2-4*y^12*z^2+6*x^10*z^4+30*x^8*y^2*z^4+60*x^6*y^4*z^4+60*x^4*y^6*z^4+30*x^2*y^8*z^4+6*y^10*z^4+120*x^10*y*z*a^2+120*x^8*y^3*z*a^2-336*x^6*y^5*z*a^2-528*x^4*y^7*z*a^2-168*x^2*y^9*z*a^2+24*y^11*z*a^2-2*x^10*a^4+90*x^8*y^2*a^4-420*x^6*y^4*a^4+420*x^4*y^6*a^4-90*x^2*y^8*a^4+2*y^10*a^4+4*x^12*b^2+24*x^10*y^2*b^2+60*x^8*y^4*b^2+80*x^6*y^6*b^2+60*x^4*y^8*b^2+24*x^2*y^10*b^2+4*y^12*b^2-12*x^10*z^2*b^2-60*x^8*y^2*z^2*b^2-120*x^6*y^4*z^2*b^2-120*x^4*y^6*z^2*b^2-60*x^2*y^8*z^2*b^2-12*y^10*z^2*b^2-4*x^10*a^2*b^2-20*x^8*y^2*a^2*b^2-40*x^6*y^4*a^2*b^2-40*x^4*y^6*a^2*b^2-20*x^2*y^8*a^2*b^2-4*y^10*a^2*b^2+6*x^10*b^4+30*x^8*y^2*b^4+60*x^6*y^4*b^4+60*x^4*y^6*b^4+30*x^2*y^8*b^4+6*y^10*b^4-8*x^11*a^2+56*x^9*y^2*a^2+176*x^7*y^4*a^2+112*x^5*y^6*a^2-40*x^3*y^8*a^2-40*x*y^10*a^2-4*x^12-24*x^10*y^2-60*x^8*y^4-80*x^6*y^6-60*x^4*y^8-24*x^2*y^10-4*y^12+4*x^10*z^2+20*x^8*y^2*z^2+40*x^6*y^4*z^2+40*x^4*y^6*z^2+20*x^2*y^8*z^2+4*y^10*z^2-4*x^10*b^2-20*x^8*y^2*b^2-40*x^6*y^4*b^2-40*x^4*y^6*b^2-20*x^2*y^8*b^2-4*y^10*b^2+x^10+5*x^8*y^2+10*x^6*y^4+10*x^4*y^6+5*x^2*y^8+y^10+1/10000"],
            "Name": ["Torusknoten"],
            "Xmax": ["3/2"],
            "Xmin": ["-3/2"],
            "Ymax": ["3/2"],
            "Ymin": ["-3/2"],
            "Zmax": ["1/2"],
            "Zmin": ["-1/2"]
            }
    },
    {
        "Iso3D": {
            "Description": ["Trefoil knot by Stephan Klaus 23/09/2019"],
            "Component": ["Trefoil_knot"],
            "Const": ["a=3/10","b=2/10","N=10"],
            "Fxyz": ["(-8*(x^2+y^2)^2*(x^2+y^2+1+z^2+a^2-b^2)+4*a^2*(x^3-3*x*y^2)*z^2+4*a^2*(2*(x^2+y^2)^2-(x^3-3*x*y^2)*(x^2+y^2+1))+8*a^2*(3*x^2*y-y^3)*z)^2-(x^2+y^2)*(2*(x^2+y^2)*(x^2+y^2+1+z^2+a^2-b^2)^2+8*(x^2+y^2)^2+4*a^2*(2*(x^3-3*x*y^2)-(x^2+y^2)*(x^2+y^2+1))-8*a^2*(3*x^2*y-y^3)*z-4*(x^2+y^2)*a^2*z^2)^2"],
            "Name": ["Trefoil_knot"],
            "Xmax": ["2"],
            "Xmin": ["-2"],
            "Ymax": ["2"],
            "Ymin": ["-2"],
            "Zmax": ["10/14"],
            "Zmin": ["-10/14"]
        }
    },
    {
        "Iso3D": {
            "Description": [
                "Happy_New_Year based on the great work from Abdelhamid Belaid: http://abdelhamid394.blogspot.ca/"],
            "Name": ["Happy_New_Year"],
            "Component": ["Happy","NW","E","YAR","E"],
            "Funct": ["A=4*min(abs(y+8/10),(-abs(x)*cos(pi/10)-y*sin(pi/10)+1))^2+(2*z)^200+(y/3)^200-1","B=4*min(abs(((abs(x)-1)^4+(y+125/100)^4)^(1/4)-125/100),min(x,abs(((abs(x)-5/10)^4+(y-125/100)^4)^(1/4)-125/100)))^2+(2*z)^100+(10*y/29)^200-1","C=max((4*((y^4+4*x^2)^(1/2)-25/10)^2+(2*z)^100-1),-((x-1)^2+(y*12/10)^100-1))","D=max(-2*x,((y*24/10)^4+(2*x)^4)^(2/100)-6)^2+(2*z)^100-1","E=4*min(abs(-(abs(abs(y)-125/100)-125/100)),x+25/100)^2+(2*z)^100+(10*y/29)^200+(x/2)^200-1","F=4*min(abs(-(abs(y-15/10)-1)),x+25/100)^2+(2*z)^100+(10*y/29)^200+(x/2)^200-1","G=min(min((2*(x-1))^100+(4*(y+8/10))^100+(2*z)^100-(1),(4*(x-125/100))^100+(2*(y+105/100))^100+(2*z)^100-1),max((4*((y^4+4*x^2)^(1/2)-25/10)^2+(2*z)^100-1),-((x-1)^2+(12*y/10)^100-1)))","H=4*min(abs(y),-abs(x*14/10)+2)^2+(2*z)^100+(y/3)^200-1","I=(2*x)^100+(y/3)^100+(2*z)^100-1","J=min(max(y+15/(10),(4)*(sqrt((x+1)^2+(y+15/10)^2)-1)^2+(2*z)^100-1),(2*x)^100+((y-15/20)/(45/20))^100+(2*z)^100-1)","L=4*min(y+25/(10),x+25/100)^2+(2*z)^100+(y/3)^200+(x/2)^200-1","M=4*min(-(-abs(x)*cos(pi/4)+y*sin(pi/4)),-abs(x)+175/100)^2+(2*z)^200+(y/3)^200-1","N=4*max(-(x+2),min(-(x-2),x*cos(pi/5)+y*sin(pi/5)))^2+(2*z)^100+(y/3)^300-1","O=4*((y^4+4*x^2)^(1/2)-25/10)^2+(2*z)^100-1","P=4*min(x,abs(((abs(x)-8/10)^4+(y-125/100)^4)^(1/4)-125/100))^2+(2*z)^100+(10*y/29)^200-1","Q=min((4*((y^4/4+4*x^2)^(1/2)-35/10)^2),16*(x*cos(pi/5)+y*sin(pi/5))^2+((y+2)*10/8)^200)+(2*z)^100-1","R=min(4*min(x,abs(((abs(x)-8/10)^4+(y-125/100)^4)^(1/4)-125/100))^2+(2*z)^100+(10*y/29)^200-(1),4*(x*cos(pi/10)+y*sin(pi/10)-12/10)^2+((y+15/10)*10/15)^200+(2*z)^100-1)","S=9*min(max((sqrt(x^2+(y-125/100)^2)-125/100)^(2),min(x,-y+15/10)),max((sqrt(x^2+(-y-125/100)^2)-125/100)^(2),min(-x,y+15/10)))+(2*z)^100-1","T=4*min(abs(x),-y+25/10)^2+(2*z)^100+(y/3)^200+(x/2)^200-1","U=4*max(abs(x)-(2),sqrt(x^2+(y-26/10)^2)-5)^2+(2*z)^100+(y/3)^200-1","V=4*(-abs(x)*cos(pi/10)+y*sin(pi/10)+1)^2+(2*z)^200+(y/3)^200-1","W=4*(-abs(abs(x)-1)*cos(pi/10)+y*sin(pi/10)+1)^2+(2*z)^200+(y/3)^200-1","X=4*min(abs(y*cos(pi/3)-x*sin(pi/3)),abs(y*cos(-pi/3)-x*sin(-pi/3)))^2+(2*z)^200+(y/3)^200-1","Y=4*min(y*cos(pi/3)-x*sin(pi/3),abs(y*cos(-pi/3)-x*sin(-pi/3)))^2+(2*z)^200+(y/3)^200-1","Z=4*max(-(-y+25/10),min(-(-y-25/10),-y*cos(pi/3)+x*sin(pi/3)))^2+(2*z)^100+(x/2)^300-1"],
            "Fxyz": ["H(x,y,z,t)*A((x-5),y,z,t)*P((x-41/5),y,z,t)*P((x-12),y,z,t)*Y((x-17),y,z,t)","N((x-4),(y+13/2),z,t)*W((x-14),(y+13/2),z,t)","E((x-8),(y+13/2),z,t)","Y((x-15/10),(y+13),z,t)*A((x-10),(y+13),z,t)*R((x-14),(y+13),z,t)","E((x-5),(y+13),z,t)"],
            "Xmax": ["30","20","20","20","20"],
            "Xmin": ["-2","-2","-2","-2","-2"],
            "Ymax": ["10","5","5","8","8"],
            "Ymin": ["-5","-15","-15","-20","-20"],
            "Zmax": ["1","1","1","1","1"],
            "Zmin": ["-1","-1","-1","-1","-1"]
        },
        "Texture": {
            "Colors": [
                "R=4/5","G=3/5","B=1/10","T=1"]
        }
    },
    {
    "Iso3D": {
        "Name": ["Wonder_Tree"],
        "Component": ["WonderTree"],
        "Const": ["k=4","e=1/10000"],
        "Funct": [
            "R=k*(x/(x*x+y*y+z*z))",
            "Gyroid=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
            "Fct = Gyroid(R(x,y,z,t),R(y,x,z,t),R(z,y,x,t),t)+exp((1/10)*(x*x+y*y+z*z-(2/10)))-exp(-10*(x*x+y*y+z*z-(5/100)))"],
        "Fxyz": ["-(Fct(x,y,z,t))"],
        "Xmax": ["2"],
        "Xmin": ["-2"],
        "Ymax": ["2"],
        "Ymin": ["-2"],
        "Zmax": ["2"],
        "Zmin": ["-2"]
    }
    },
    {
    "Iso3D": {
        "Description": ["Moebius band by Stephan Klaus 23/09/2019"],
        "Name": ["Moebius_Strip"],
        "Component": ["Moebius"],
        "Const": [
            "a=1/2",
            "b=1/10",
            "N=4"],
        "Fxyz": ["((b^2*x^2+a^2*y^2)*(x^2+y^2)+b^2*(-x+y*z)^2+a^2*(y+x*z)^2-a^2*b^2*(x^2+y^2))^2-4*(x^2+y^2)*(b^2*x*(-x+y*z)-a^2*y*(y+x*z))^2"],
        "Xmax": ["3/2"],
        "Xmin": ["-3/2"],
        "Ymax": ["3/2"],
        "Ymin": ["-3/2"],
        "Zmax": ["1/2"],
        "Zmin": ["-1/2"]
    }
    },
    {
      "Iso3D": {
        "Name": ["Schwarz"],
        "Component": ["Schwarz"],
        "Fxyz": ["cos(x)+cos(y)+cos(z)"],
        "Xmin": ["-4"],
        "Xmax": ["4"],
        "Ymin": ["-4"],
        "Ymax": ["4"],
        "Zmin": ["-4"],
        "Zmax": ["4"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Moon"],
        "Component": ["GravityPlan","EarthPlanet","MoonPlanet"],
        "Fxyz": ["((x-4*sin(t*pi/3))*(x-4*sin(t*pi/3))+(y-2*cos(t*pi/3))*(y-2*cos(t*pi/3))+z*z-3/5)*min((x-4*sin(t*pi/3))*(x-4*sin(t*pi/3))+(y-2*cos(t*pi/3))*(y-2*cos(t*pi/3)) +z*z-(3/5),z)+1/5","(x-4*sin(t*pi/3))*(x-4*sin(t*pi/3))+(y-2*cos(t*pi/3))*(y-2*cos(t*pi/3)) +(z-1/5)*(z-1/5)-3/5 ","(x-2*sin(t*pi)-4*sin(t*pi/3))*(x-2*sin(t*pi)-4*sin(t*pi/3))+(y-2*cos(t*pi)-2*cos(t*pi/3))*(y-2*cos(t*pi)-2*cos(t*pi/3))+(z-1/5)*(z-1/5)-1/10"],
        "Xmin": ["-5","-1+4*sin(t*pi/3)","-1+2*sin(t*pi)+4*sin(t*pi/3)"],
        "Xmax": ["5","1+4*sin(t*pi/3)","1+2*sin(t*pi)+4*sin(t*pi/3)"],
        "Ymin": ["-4","-1+2*cos(t*pi/3)","-1+2*cos(t*pi)+2*cos(t*pi/3)"],
        "Ymax": ["4","1+2*cos(t*pi/3)","1+2*cos(t*pi)+2*cos(t*pi/3)"],
        "Zmin": ["-1","-1","-1"],
        "Zmax": ["1","3/2","1"]
      }
    },
    {
      "Iso3D": {
        "Description": ["BlackHole by Abderrahman Taha 10/12/2019"],
        "Name": ["BlackHole"],
        "Component": ["GravityPlan","EarthPlanet","MoonPlanet","WhiteStar "],
        "Const": ["M=pi/10"],
        "Funct": ["A=(x-4*sin(t*M))^2","B=(x-2*cos(t*M))^2","C=(x-2*sin(t*pi)-4*sin(t*M))^2","D=(x-2*cos(t*pi)-2*cos(t*M))^2","E=(x-1/5)*(x-1/5)-3/5","F=x*x-3/5","H=x*cos(2*t*pi)","G=x*sin(2*t*pi)"],
        "Grid": ["20","20","20","20"],
        "Fxyz": ["((3/2)*(H(x,y,z,t)-G(y,x,z,t))^2+(G(x,y,z,t)+H(y,x,z,t))^2+(z+4/5)^2-(abs((11/5)*sin(t*M))))*(A(x,y,z,t)+B(y,x,z,t)+F(z,y,x,t))*min(((3/2)*(H(x,y,z,t)-G(y,x,z,t))^2+(G(x,y,z,t)+H(y,x,z,t))^2+(z+4/5)^2-(abs((11/5)*sin(t*M))))*(A(x,y,z,t)+B(y,x,z,t)+F(z,y,x,t)),z)+1","A(x,y,z,t)+B(y,x,z,t)+E(z,y,x,t)","C(x,y,z,t)+D(y,x,z,t) +E(z,y,x,t)+1/2","(3/2)*(x*cos(2*t*pi)-y*sin(2*t*pi))^2+(x*sin(2*t*pi)+y*cos(2*t*pi))^2+(z+1/5)^2-(abs((1/5)*sin(t*M)+1/20))"],
        "Xmin": ["-5","-1+4*sin(t*M)","-1+2*sin(t*pi)+4*sin(t*M)","-1/2"],
        "Xmax": ["5","1+4*sin(t*M)","1+2*sin(t*pi)+4*sin(t*M)","1/2"],
        "Ymin": ["-4","-1+2*cos(t*M)","-1+2*cos(t*pi)+2*cos(t*M)","-1/2"],
        "Ymax": ["4","1+2*cos(t*M)","1+2*cos(t*pi)+2*cos(t*M)","1/2"],
        "Zmin": ["-2","-1","-1","-7/10"],
        "Zmax": ["1","11/10","1","1/2"]
      },
        "Texture": {
          "Name": "Gray",
          "Colors": [
            "R=7/10",
            "G=7/10",
            "B=7/10",
            "T=1"]
        }
    },
    {
      "Iso3D": {
        "Name": ["FallingDrop"],
        "Component": ["fallingdrop"],
        "Fxyz": ["-((z-6*(1-cos(sqrt(x^2+y^2)-t*2*pi))/sqrt(x^2+y^2+4))*(2*(x^2+y^2)+(z-40*sin((t+19/100)*pi)+1)^2-10)-1000)"],
        "Xmax": ["20"],
        "Xmin": ["-20"],
        "Ymax": ["20"],
        "Ymin": ["-20"],
        "Zmax": ["50"],
        "Zmin": ["-1"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Menger Sponge by Abderrahman Taha 10/12/2019"],
        "Name": ["MengerSponge"],
        "Component": ["MengerSponge"],
        "Funct": [
            "A = ((abs(x-2/3) <1/81)+(abs(x-20/27) <1/81)+(abs(x-16/27) <1/81)+(abs(x-8/9) <1/81)+(abs(x-26/27) <1/81)+(abs(x-22/27) <1/81)+(abs(x-4/9) <1/81)+(abs(x-14/27) <1/81)+(abs(x-10/27) <1/81)+(abs(x+2/3) <1/81)+(abs(x+16/27) <1/81)+(abs(x+20/27) <1/81)+(abs(x+4/9) <1/81)+(abs(x+10/27) <1/81)+(abs(x+14/27) <1/81)+(abs(x+8/9) <1/81)+(abs(x+22/27) <1/81)+(abs(x+26/27) <1/81)+(abs(x) <1/81)+(abs(x-2/27) <1/81)+(abs(x+2/27) <1/81)+(abs(x-2/9) <1/81)+(abs(x-8/27) <1/81)+(abs(x-4/27) <1/81)+(abs(x+2/9) <1/81)+(abs(x+4/27) <1/81)+(abs(x+8/27) <1/81))",
            "B = ((abs(x-2/3) <1/27)+(abs(x-8/9) <1/27)+(abs(x-4/9) <1/27)+(abs(x+2/3) <1/27)+(abs(x+4/9) <1/27)+(abs(x+8/9) <1/27)+(abs(x) <1/27)+(abs(x-2/9) <1/27)+(abs(x+2/9) <1/27))",
            "C = ((abs(x-2/3) <1/9)+(abs(x+2/3) <1/9)+(abs(x) <1/9))",
            "D = x^600"],
        "Fxyz": ["-(D(x,y,z,t)+D(y,z,x,t)+D(z,x,y,t)-1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*((C(x,y,z,t)*(C(y,z,x,t)+C(z,x,y,t))+C(z,x,y,t)*C(y,z,x,t)) =0)*((B(x,y,z,t)*(B(y,z,x,t)+B(z,x,y,t))+B(z,x,y,t)*B(y,z,x,t)) =0)*((A(x,y,z,t)*(A(y,z,x,t)+A(z,x,y,t))+A(z,x,y,t)*A(y,z,x,t)) =0)) "],
        "Xmin": ["-1001/1000"],
        "Xmax": ["1001/1000"],
        "Ymin": ["-1001/1000"],
        "Ymax": ["1001/1000"],
        "Zmin": ["-1001/1000"],
        "Zmax": ["1001/1000"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Menger Sponge Subdivision by Abderrahman Taha 10/12/2019"],
        "Name": ["MengerSpongeSubdivision"],
        "Funct": [
            "A = ((abs(x-2/3) <1/81)+(abs(x-20/27) <1/81)+(abs(x-16/27) <1/81)+(abs(x-8/9) <1/81)+(abs(x-26/27) <1/81)+(abs(x-22/27) <1/81)+(abs(x-4/9) <1/81)+(abs(x-14/27) <1/81)+(abs(x-10/27) <1/81)+(abs(x+2/3) <1/81)+(abs(x+16/27) <1/81)+(abs(x+20/27) <1/81)+(abs(x+4/9) <1/81)+(abs(x+10/27) <1/81)+(abs(x+14/27) <1/81)+(abs(x+8/9) <1/81)+(abs(x+22/27) <1/81)+(abs(x+26/27) <1/81)+(abs(x) <1/81)+(abs(x-2/27) <1/81)+(abs(x+2/27) <1/81)+(abs(x-2/9) <1/81)+(abs(x-8/27) <1/81)+(abs(x-4/27) <1/81)+(abs(x+2/9) <1/81)+(abs(x+4/27) <1/81)+(abs(x+8/27) <1/81))",
            "B = ((abs(x-2/3) <1/27)+(abs(x-8/9) <1/27)+(abs(x-4/9) <1/27)+(abs(x+2/3) <1/27)+(abs(x+4/9) <1/27)+(abs(x+8/9) <1/27)+(abs(x) <1/27)+(abs(x-2/9) <1/27)+(abs(x+2/9) <1/27))",
            "C = ((abs(x-2/3) <1/9)+(abs(x+2/3) <1/9)+(abs(x) <1/9))",
            "D = x^600",
            "menger =-(D(x,y,z,t)+D(y,x,z,t)+D(z,y,x,t)-1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*((C(x,y,z,t)*(C(y,x,z,t)+C(z,y,x,t))+C(z,y,x,t)*C(y,x,z,t)) =0)*((B(x,y,z,t)*(B(y,x,z,t)+B(z,y,x,t))+B(z,y,x,t)*B(y,x,z,t)) =0)*((A(x,y,z,t)*(A(y,x,z,t)+A(z,y,x,t))+A(z,y,x,t)*A(y,x,z,t)) =0))"],
            "Component": ["MengerSponge1","MengerSponge2","MengerSponge3","MengerSponge4","MengerSponge5","MengerSponge6","MengerSponge7","MengerSponge8"],
            "Fxyz": ["menger(x,y,z,t)","menger(x,y,z,t)","menger(x,y,z,t)","menger(x,y,z,t)","menger(x,y,z,t)","menger(x,y,z,t)","menger(x,y,z,t)","menger(x,y,z,t)"],
            "Xmin": ["-1001/1000","-1001/1000","-1001/1000","-1001/1000","0","0","0","0"],
            "Xmax": ["0","0","0","0","1001/1000","1001/1000","1001/1000","1001/1000"],
            "Ymin": ["-1001/1000","-1001/1000","0","0","-1001/1000","-1001/1000","0","0"],
            "Ymax": ["0","0","1001/1000","1001/1000","0","0","1001/1000","1001/1000"],
            "Zmin": ["-1001/1000","0","-1001/1000","0","-1001/1000","0","-1001/1000","0"],
            "Zmax": ["0","1001/1000","0","1001/1000","0","1001/1000","0","1001/1000"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Cayley_1"],
        "Component": ["Cayley_1"],
        "Fxyz": ["(x^2+y ^2-x^2*z+y ^2*z+z ^2-1)"],
        "Cnd": ["(sqrt(x^2 +y ^2+z ^2)) < 4"],
        "Xmin": ["-4 "],
        "Xmax": ["4"],
        "Ymin": ["-4 "],
        "Ymax": ["4"],
        "Zmin": ["-4 "],
        "Zmax": ["4"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Cayley_2"],
        "Component": ["Cayley_2"],
        "Fxyz": ["-5*(x*x*y+x*x*z+y*y*x+y*y*z+z*z*y+z*z*x)+2*(x*y+x*z+y*z)"],
        "Cnd": ["(sqrt(x^2 +y ^2+z ^2)) < 1"],
        "Xmin": ["-1"],
        "Xmax": ["1"],
        "Ymin": ["-1"],
        "Ymax": ["1"],
        "Zmin": ["-1"],
        "Zmax": ["1"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Nordstrand"],
        "Cnd": ["((x-1/10)^2+(y-1/10)^2+(z-1/10)^2)>1"],
        "Component": ["Nordstrand"],
        "Fxyz": ["25*(x^3*(y+z)+y^3*(x+z)+z^3*(x+y))+50*(x^2*y^2+x^2*z^2+y^2*z^2)-125*(x^2*y*z+y^2*x*z+z^2*x*y)+60*x*y*z-4*(x*y+x*z+y*z)"],
        "Xmax": ["11/10"],
        "Xmin": ["-11/10"],
        "Ymax": ["11/10"],
        "Ymin": ["-11/10"],
        "Zmax": ["11/10"],
        "Zmin": ["-11/10"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Togliatti"],
        "Cnd": ["(x^2+y^2+z^2) > 100"],
        "Component": ["Togliatti"],
        "Const": ["w=13/10"],
        "Fxyz": ["64*(x-w)*(x^4-4*w*x^3-10*x^2*y^2-4*x^2*w^2+16*w^3*x-20*w*x*y^2+5*y^4+16*w^4-20*y^2*w^2)-5*sqrt(5-sqrt(5))*(2*z-sqrt(5-sqrt(5))*w)*(4*(x^2+y^2-z^2)+(1+3*sqrt(5))*w^2)^2"],
        "Xmax": ["10"],
        "Xmin": ["-10"],
        "Ymax": ["10"],
        "Ymin": ["-10"],
        "Zmax": ["10"],
        "Zmin": ["-10"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Dervish"],
        "Component": ["Dervish"],
        "Cnd": ["(x^2+y^2+z^2)>15"],
        "Const": ["B=sqrt(5)",
          "R = (1/4)*(1+3*B)",
          "A =-8*(1+1/B)*sqrt(5-B)/5",
          "C = sqrt(5-B)/2"],
        "Fxyz": ["A*(x-z)*(cos((2*pi)/5)*x-sin((2*pi)/5)*y-z)*(cos((4*pi)/5)*x-sin((4*pi)/5)*y-z)*(cos((6*pi)/5)*x-sin((6*pi)/5)*y-z)*(cos((8*pi)/5)*x-sin((8*pi)/5)*y-z) +(1-C*z)*(x^2+y^2-1+R*z^2)^2"],
        "Xmin": ["-4"],
        "Xmax": ["4"],
        "Ymin": ["-4"],
        "Ymax": ["4"],
        "Zmin": ["-4"],
        "Zmax": ["4"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Barth-sextic"],
        "Component": ["Barth-sextic"],
        "Cnd": ["(x^2+y^2+z^2)>9"],
        "Const": ["w=1",
          "phi=(1/2)*(1+sqrt(5))"],
        "Fxyz": ["4*(phi^2*x^2-y^2)*(phi^2*y^2-z^2)*(phi^2*z^2-x^2)-(1+2*phi)*(x^2+y^2+z^2-w^2)^2*w^2"],
        "Xmax": ["3"],
        "Xmin": ["-3"],
        "Ymax": ["3"],
        "Ymin": ["-3"],
        "Zmax": ["3"],
        "Zmin": ["-3"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Labs-Septic"],
        "Component": ["Labs-Septic"],
        "Cnd": ["(x^2+y^2+z^2)>25"],
        "Const": ["w = 1",
          "b = 14010685/100000000",
          "a1 =-(12/7)*(-b)^2-(384/49)*(-b)-(8/7)",
          "a2 =-(32/7)*(-b)^2+(24/49)*(-b)-4",
          "a3 =-4*(-b)^2+(24/49)*(-b)-4",
          "a4 =-(8/7)*(-b)^2+(8/49)*(-b)-8/7",
          "a5 = 49*(-b)^2-7*(-b) +50"],
        "Fxyz": ["(x*(x^6-3*7*x^4*y^2+5*7*x^2*y^4-7*y^6)+7*z*((x^2+y^2)^3-2^3*z^2*(x^2+y^2)^2+2^4*z^4*(x^2+y^2))-2^6*z^7)-((z+a5*w)*((z+w)*(x^2+y^2)+a1*z^3+a2*z^2*w+a3*z*w^2+a4*w^3)^2)"],
        "Xmax": ["5"],
        "Xmin": ["-5"],
        "Ymax": ["5"],
        "Ymin": ["-5"],
        "Zmax": ["5"],
        "Zmin": ["-5"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Endraß-Octic"],
        "Component": ["Endraß-Octic"],
        "Cnd": ["(x^2+y^2+z^2)>25"],
        "Const": ["w = 1",
          "a1 = 1",
          "a2 = 1",
          "a3 = 1",
          "a4 =-1"],
        "Fxyz": ["64*(x^2-w^2)*(y^2-w^2)*((x+y)^2-2*w^2)*((x-y)^2-2*w^2)-(-4*(1+a1*2^(1/2))*(x^2+y^2)^2+(8*(2+a2*2^(1/2))*z^2+2*(2+a3*7*2^(1/2))*w^2 )*(x^2+y^2)-16*z^4+8*(1+a4*2*2^(1/2))*z^2*w^2-(1+12*2^(1/2))*w^4)^2"],
        "Xmax": ["5"],
        "Xmin": ["-5"],
        "Ymax": ["5"],
        "Ymin": ["-5"],
        "Zmax": ["5"],
        "Zmin": ["-5"]
      }
    },
    {
      "Iso3D": {
        "Name": ["SartiOctic"],
        "Component": ["SartiOctic"],
        "Fxyz": ["-1728*x^4*y^2*z^2+928*z^4*x^4+9024*z^2*x^4+928*z^4*y^4+9024*z^2*y^4+9024*x^2*y^2+2720*x^4*y^4-1728*x^2*z^2-1728*y^2*z^2-1728*x^4*y^2-1728*x^2*y^4-1728*x^2*z^4-1728*y^2*z^4-576*x^6*y^2-576*x^6*z^2-576*x^2*y^6-576*x^2*z^6-576*y^6*z^2+9024*z^4*x^2*y^2-24960*z^2*x^2*y^2-1728*x^2*y^4*z^2+2720*z^4+112*z^8-576*z^2+928*x^4+112*x^8+928*y^4+112*y^8-576*x^2-576*y^2-576*x^6-576*y^6-576*z^6+112-576*y^2*z^6"],
        "Xmax": ["28/5"],
        "Xmin": ["-28/5"],
        "Ymax": ["28/5"],
        "Ymin": ["-28/5"],
        "Zmax": ["28/5"],
        "Zmin": ["-28/5"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Breske-Nonic"],
        "Component": ["Breske-Nonic"],
        "Cnd": ["(x^2+y^2+z^2)>9"],
        "Fxyz": ["(2*x^7-42*x^5*y^2+70*x^3*y^4-14*x*y^6-14*x^6+70*x^4*y^2+70*x^2*y^4-14*y^6+28*x^5+56*x^3*y^2+28*x*y^4-84*x^2*y^2+28*y^4-42*x^3-42*x*y^2+14*x^2-14*y^2+14*x)+(1/2)*(64*z^7-112*z^5+56*z^3-7*z+5)"],
        "Xmax": ["3"],
        "Xmin": ["-3"],
        "Ymax": ["3"],
        "Ymin": ["-3"],
        "Zmax": ["3"],
        "Zmin": ["-3"]
      }
    },
    {
      "Iso3D": {
        "Name": ["BarthDedic"],
        "Component": ["Barth_Dedic"],
        "Cnd": ["(x^2+y^2+z^2)> (1+sqrt(5))+1/5"],
        "Const": ["w  = 1",
          "phi= (1+sqrt(5))/2",
          "C = sqrt(1+sqrt(5))"],
        "Funct": ["Ax  = x^2",
          "Ay  = y^2",
          "Az  = z^2",
          "Bx  = x^4",
          "By  = y^4",
          "Bz  = z^4"],
        "Fxyz": ["8*(Ax(x,y,z,t)-phi^4*Ay(x,y,z,t))*(Ay(x,y,z,t)-phi^4*Az(x,y,z,t))*(Az(x,y,z,t)-phi^4*Ax(x,y,z,t))*(Bx(x,y,z,t)+By(x,y,z,t)+Bz(x,y,z,t)-2*(Ax(x,y,z,t)*Ay(x,y,z,t)+Ax(x,y,z,t)*Az(x,y,z,t)+Ay(x,y,z,t)*Az(x,y,z,t)))+(3+5*phi)*(Ax(x,y,z,t)+Ay(x,y,z,t)+Az(x,y,z,t)-w^2)^2*(Ax(x,y,z,t)+Ay(x,y,z,t)+Az(x,y,z,t)-(2-phi)*w^2)^2*w^2"],
        "Xmax": ["C"],
        "Xmin": ["-C"],
        "Ymax": ["C"],
        "Ymin": ["-C"],
        "Zmax": ["C"],
        "Zmin": ["-C"]
      }
    },
    {
      "Iso3D": {
        "Name": ["SartiDodecic"],
        "Component": ["Sarti-Dodecic"],
        "Cnd": ["(x^2+y^2+z^2)>13"],
        "Const": ["w  = 1"],
        "Fxyz": ["243*(33*sqrt(5)*(((x^2*y^2+z^2*w^2)^2*(x^2*z^2+y^2*w^2)-(x^2*y^2+z^2*w^2)*(x^2*z^2+y^2*w^2)^2)+((x^2*z^2+y^2*w^2)^2*(x^2*w^2+y^2*z^2)-(x^2*z^2+y^2*w^2)*(x^2*w^2+y^2*z^2)^2)+((x^2*w^2+y^2*z^2)^2*(x^2*y^2+z^2*w^2)-(x^2*w^2+y^2*z^2)*(x^2*y^2+z^2*w^2)^2))+19*(((x^2*y^2+z^2*w^2)^2*(x^2*z^2+y^2*w^2)+(x^2*y^2+z^2*w^2)*(x^2*z^2+y^2*w^2)^2)+((x^2*z^2+y^2*w^2)^2*(x^2*w^2+y^2*z^2)+(x^2*z^2+y^2*w^2)*(x^2*w^2+y^2*z^2)^2)+((x^2*w^2+y^2*z^2)^2*(x^2*y^2+z^2*w^2)+(x^2*w^2+y^2*z^2)*(x^2*y^2+z^2*w^2)^2))+10*((x^2*y^2+z^2*w^2)^3+(x^2*z^2+y^2*w^2)^3+(x^2*w^2+y^2*z^2)^3)-14*(x^4+y^4+z^4+w^4)*((x^2*y^2+z^2*w^2)*(x^2*z^2+y^2*w^2)+(x^2*y^2+z^2*w^2)*(x^2*w^2+y^2*z^2)+(x^2*z^2+y^2*w^2)*(x^2*w^2+y^2*z^2))+2*(x^4+y^4+z^4+w^4)^2*((x^2*y^2+z^2*w^2)+(x^2*z^2+y^2*w^2)+(x^2*w^2+y^2*z^2))-6*(x^4+y^4+z^4+w^4)*((x^2*y^2+z^2*w^2)^2+(x^2*z^2+y^2*w^2)^2+(x^2*w^2+y^2*z^2)^2)-352*(x*y*z*w)^2*((x^2*y^2+z^2*w^2)+(x^2*z^2+y^2*w^2)+(x^2*w^2+y^2*z^2))+336*(x*y*z*w)^2*(x^4+y^4+z^4+w^4)+48*((x^2*y^2+z^2*w^2)*(x^2*z^2+y^2*w^2)*(x^2*w^2+y^2*z^2)))-22*(x^2+y^2+z^2+w^2)^6"],
        "Xmax": ["37/10"],
        "Xmin": ["-37/10"],
        "Ymax": ["37/10"],
        "Ymin": ["-37/10"],
        "Zmax": ["37/10"],
        "Zmin": ["-37/10"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Scherk"],
        "Component": ["Scherk"],
        "Fxyz": ["sinh(x)*sinh(y)-sin(z)"],
        "Xmax": ["3"],
        "Xmin": ["-3 "],
        "Ymax": ["3"],
        "Ymin": ["-3 "],
        "Zmax": ["5*pi/2"],
        "Zmin": ["-5*pi/2 "]
      }
    },
    {
      "Iso3D": {
        "Name": ["Blobs"],
        "Component": ["Blobs"],
        "Fxyz": ["x^2+y ^2+z^2+cos(4*x)+cos(4*y)+cos(4*z)-1/10"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-2"],
        "Zmax": ["2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["CubeSphere"],
        "Component": ["CubeSphere"],
        "Fxyz": ["((1/5)*(x^2+y^2+z^2))^-6+((2)^-8*(x^8+y^8+z^8))^6-1"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-2"],
        "Zmax": ["2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Hyperbolic"],
        "Component": ["Hyperbolic"],
        "Fxyz": ["x*x+y-z*z"],
        "Xmin": ["-1"],
        "Xmax": ["1"],
        "Ymin": ["-1"],
        "Ymax": ["1"],
        "Zmin": ["-1"],
        "Zmax": ["1"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Devil"],
        "Component": ["Devil Surface"],
        "Fxyz": ["x^4+2*x^2*z^2-(9/25)*x^2-y^4+(1/4)*y^2+z^4"],
        "Xmin": ["-11/10"],
        "Xmax": ["11/10"],
        "Ymin": ["-1"],
        "Ymax": ["1"],
        "Zmin": ["-1"],
        "Zmax": ["1"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Hyperboloid"],
        "Component": ["Hyperboloid"],
        "Fxyz": ["x^2+y^2-z^2-3/10"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-9/10"],
        "Zmax": ["9/10"]
      }
    },
    {
      "Iso3D": {
        "Name": ["DuplinCyclides"],
        "Component": ["DuplinCyclides"],
        "Fxyz": ["-51*(x^4+y^4+z^4)-102*(x^2*y^2+x^2*z^2+y^2*z^2)+141*(x-1)*(x^2+y^2+z^2)+256*x*(x-2)+282*y^2+256"],
        "Xmin": ["-2"],
        "Xmax": ["11/5"],
        "Ymin": ["-21/10"],
        "Ymax": ["21/10"],
        "Zmin": ["-13/10"],
        "Zmax": ["13/10"]
      },
      "Pigment": {
        "Colors": [
          {
            "Color": {
              "Name": "Red",
              "Vrgba": [
                "V=4/10",
                "R=1",
                "G=85/100",
                "B=4/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": [
                "V=5/10",
                "R=1",
                "G=1/10",
                "B=31/100",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": [
                "V=5/10",
                "R=31/100",
                "G=31/100",
                "B=1",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": [
                "V=7/10",
                "R=1",
                "G=3/10",
                "B=1/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": [
                "V=1",
                "R=4/10",
                "G=6/10",
                "B=1/10",
                "A=1"
              ]
            }
          }
        ],
        "Gradient": "3*cos(x*x+y*y)*cos(y*z-y*x)*(cos(x*y*z)+sin(x*y*z))",
        "Name": "Pigment_5",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Iso3D": {
        "Name": ["Blobs_2"],
        "Component": ["Blobs_2"],
        "Fxyz": ["x^2+y ^2+z^2+sin(4*x)+sin(4*y)+sin(4*z)-1"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-2"],
        "Zmax": ["2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["KleinIso"],
        "Component": ["KleinIso"],
        "Fxyz": ["(x^2+y^2+z^2+2*y-1)*((x^2+y^2+z^2-2*y-1)^2-8*z^2)+16*x*z*(x^2+y^2+z^2-2*y-1)"],
        "Xmin": ["-3"],
        "Xmax": ["3"],
        "Ymin": ["-31/10"],
        "Ymax": ["31/10"],
        "Zmin": ["-4"],
        "Zmax": ["4"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Leminescape"],
        "Component": ["Leminescape"],
        "Fxyz": ["4*x^2*(x^2+y^2+z^2+z)+y^2*(y^2+z^2-1)"],
        "Xmin": ["-1/2"],
        "Xmax": ["1/2"],
        "Ymin": ["-1"],
        "Ymax": ["1"],
        "Zmin": ["-1"],
        "Zmax": ["1"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Drope"],
        "Component": ["Drope"],
        "Fxyz": ["z-4*x*exp(-x^2-y^2)"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-19/10"],
        "Zmax": ["19/10"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Sinus"],
        "Component": ["Sinus"],
        "Fxyz": ["sin(3*pi*((x)^2+(y)^2))/10+z"],
        "Xmax": ["1"],
        "Xmin": ["-1"],
        "Ymax": ["1"],
        "Ymin": ["-1"],
        "Zmax": ["1"],
        "Zmin": ["-1"]
      }
    },
    {
      "Iso3D": {
        "Name": ["TorusIso"],
        "Component": ["TorusIso"],
        "Fxyz": ["(sqrt(x*x+y*y)-3)^2+z*z-1"],
        "Xmin": ["-4"],
        "Xmax": ["4"],
        "Ymin": ["-4"],
        "Ymax": ["4"],
        "Zmin": ["-1"],
        "Zmax": ["1"]
      }
    },
    {
      "Iso3D": {
        "Name": ["SphereIso"],
        "Component": ["SphereIso"],
        "Fxyz": ["x*x+y*y+z*z-1"],
        "Xmin": ["-1"],
        "Xmax": ["1"],
        "Ymin": ["-1"],
        "Ymax": ["1"],
        "Zmin": ["-1"],
        "Zmax": ["1"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Octahedron"],
        "Component": ["Octahedron"],
        "Fxyz": ["abs(x)+abs(y)+abs(z)-1"],
        "Xmin": ["-1"],
        "Xmax": ["1"],
        "Ymin": ["-1"],
        "Ymax": ["1"],
        "Zmin": ["-1"],
        "Zmax": ["1"]
      }
    },
    {
      "Iso3D": {
        "Name": ["IsoCube"],
        "Component": ["IsoCube"],
        "Fxyz": ["x^100+y^100+z^100-1"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-2"],
        "Zmax": ["2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["IsoToupie"],
        "Component": ["IsoToupie"],
        "Fxyz": ["(sqrt(x*x+y*y)-3)^3+z*z-1"],
        "Xmin": ["-4"],
        "Xmax": ["4"],
        "Ymin": ["-4"],
        "Ymax": ["4"],
        "Zmin": ["-6"],
        "Zmax": ["6"]
      }
    },
    {
      "Iso3D": {
        "Name": ["RoundCube"],
        "Component": ["RoundCube"],
        "Fxyz": ["x^4+y^4+z^4-(x^2+y^2+z^2)"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-2"],
        "Zmax": ["2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Chmutov"],
        "Component": ["Chmutov"],
        "Fxyz": ["-((x^2)^2+(y^2)^2+(z^2)^2-(x^2+y^2+z^2-3/10))"],
        "Xmin": ["-3/2"],
        "Xmax": ["3/2"],
        "Ymin": ["-3/2"],
        "Ymax": ["3/2"],
        "Zmin": ["-3/2"],
        "Zmax": ["3/2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Chmutov_2"],
        "Component": ["Chmutov_2"],
        "Fxyz": ["-(2*(x^2*(3-4*x^2)^2+y^2*(3-4*y^2)^2+z^2*(3-4*z^2)^2)-3)"],
        "Xmin": ["-13/10"],
        "Xmax": ["13/10"],
        "Ymin": ["-13/10"],
        "Ymax": ["13/10"],
        "Zmin": ["-13/10"],
        "Zmax": ["13/10"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Composite"],
        "Component": ["Chmutov","RoundCube","Virus","Trap"],
        "Fxyz": ["2*(x^2*(3-4*x^2)^2+y^2*(3-4*y^2)^2+z^2*(3-4*z^2)^2)-3","((x-3)^2)^2+(y^2)^2+(z^2)^2-((x-3)^2+y^2+z^2-3/10)","-(-(x^2+(y-3) ^2+z^2)+cos(5*x)*cos(5*(y-3))*cos(5*z)+(43/200))","((x-3)^8+z^30+(y-3)^8-((x-3)^4+z^50+(y-3)^4-3/10))*((x-3)^2+(y-3)^2+z^2-1/2)"],
        "Xmin": ["-13/10","3/2","-4/5","9/5"],
        "Xmax": ["13/10","9/2","4/5","21/5"],
        "Ymin": ["-13/10","-3/2","11/5","9/5"],
        "Ymax": ["13/10","3/2","19/5","43/10"],
        "Zmin": ["-13/10","-3/2","-4/5","-3/2 "],
        "Zmax": ["13/10","3/2","4/5","3/2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Clebsch_1"],
        "Component": ["Clebsch"],
        "Fxyz": ["81*(x^3+y^3+z^3)-189*(x^2*y+x^2*z+y^2*x+y^2*z+z^2*x+z^2*y)+54*x*y*z+126*(x*y+x*z+y*z)-9*(x^2+y^2+z^2)-9*(x+y+z)+1"],
        "Xmin": ["-1"],
        "Xmax": ["1"],
        "Ymin": ["-1"],
        "Ymax": ["1"],
        "Zmin": ["-1"],
        "Zmax": ["1"]
      }
    },
    {
        "Iso3D": {
            "Description": ["Clebsch surface by Abderrahman Taha 18/05/2019"],
            "Name": ["Clebsch_2"],
            "Component": ["Clebsch"],
            "Grid": ["150"],
            "Const": ["X=1",
                "Y=1",
                "Z=1",
                "N=4",
                "c=1/1000",
                "T=2/100",
                "k1=1",
                "k2=14/10"],
            "Funct": ["Clebsch =81*(x^3+y^3+z^3)-189*(x^2*y+x^2*z+y^2*x+y^2*z+z^2*x+z^2*y)+54*x*y*z+126*(x*y+x*z+y*z)-9*(x^2+y^2+z^2)-9*(x+y+z)+1 ",
                "DFx=((Clebsch(x+c,y,z,t)-Clebsch(x,y,z,t))/c)",
                "DFy=((Clebsch(x,y+c,z,t)-Clebsch(x,y,z,t))/c)",
                "DFz=((Clebsch(x,y,z+c,t)-Clebsch(x,y,z,t))/c)",
                "Rapp=(x/sqrt(x*x+y*y+z*z))",
                "Iso=Clebsch(x-t*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-t*Rapp(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z-t*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t)",
                "Iso=if(x*x+y*y+z*z-1<(0),Iso(x,y,z,T)*Iso(x,y,z,-T),(1/2)*exp((x*x+y*y+z*z-1))) "],
            "Fxyz": ["Iso(x,y,z,t)"],
            "Xmax": ["X"],
            "Xmin": ["-X"],
            "Ymax": ["Y"],
            "Ymin": ["-Y"],
            "Zmax": ["Z"],
            "Zmin": ["-Z"]
        },
        "Texture": {
            "Colors": ["R=(7/10)",
                "G=(7/10)",
                "B=(7/10)",
                "T=1"],
            "Name": "Gray",
            "Noise": ""
        }
    },
    {
      "Iso3D": {
        "Name": ["Icosahedron"],
        "Component": ["Icosahedron"],
        "Const": ["C=(1+sqrt(5))/2"],
        "Fxyz": ["if((x^2+y^2+z^2 < 35),2-(cos(x+C*y)+cos(x-C*y)+cos(y+C*z)+cos(y-C*z)+cos(z-C*x)+cos(z+C*x)),1)"],
        "Xmin": ["-11/2"],
        "Xmax": ["11/2"],
        "Ymin": ["-11/2"],
        "Ymax": ["11/2"],
        "Zmin": ["-11/2"],
        "Zmax": ["11/2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["DingDong"],
        "Component": ["DingDong"],
        "Fxyz": ["-x^2-y^2+(1-z)*z^2"],
        "Xmin": ["-3/2"],
        "Xmax": ["3/2"],
        "Ymin": ["-3/2"],
        "Ymax": ["3/2"],
        "Zmin": ["-1"],
        "Zmax": ["1"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Trap"],
        "Component": ["Trap"],
        "Fxyz": ["(x^8+z^30+y^8-(x^4+z^50+y^4-3/10))*(x^2+y^2+z^2-1/2)"],
        "Xmin": ["-6/5"],
        "Xmax": ["6/5"],
        "Ymin": ["-13/10"],
        "Ymax": ["13/10"],
        "Zmin": ["-3/2"],
        "Zmax": ["3/2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["OrthoCircle"],
        "Component": ["OrthoCircle"],
        "Fxyz": ["((x^2+y^2-1)^2+z^2)*((y^2+z^2-1)^2+x^2)*((z^2+x^2-1)^2+y^2)-(3/40)^2*(1+3*(x^2+y^2+z^2))"],
        "Xmin": ["-3/2"],
        "Xmax": ["3/2"],
        "Ymin": ["-3/2"],
        "Ymax": ["3/2"],
        "Zmin": ["-3/2"],
        "Zmax": ["3/2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["CubeSphere_2"],
        "Component": ["CubeSphere_2"],
        "Fxyz": ["12-((10/23)^2*(x^2+y^2+z^2))^-6-((1/2)^8*(x^8+y^8+z^8))^6"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-2"],
        "Zmax": ["2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["UnionSpheres"],
        "Component": ["UnionSpheres"],
        "Fxyz": ["min(((x-7/10)*(x-7/10)+y*y+z*z-1),((x+1/2)*(x+1/2)+y*y+z*z-1))"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-2"],
        "Zmax": ["2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["DifferenceSpheres"],
        "Component": ["DifferenceSpheres"],
        "Fxyz": ["((x-7/10)*(x-7/10)+y*y+z*z-1)*min(((x-7/10)*(x-7/10)+y*y+z*z-1),((x+3/10)*(x+3/10)+y*y+z*z-1))+1/50"],
        "Xmin": ["-2"],
        "Xmax": ["1/10"],
        "Ymin": ["-1"],
        "Ymax": ["1"],
        "Zmin": ["-1"],
        "Zmax": ["1"]
      }
    },
    {
      "Iso3D": {
        "Name": ["BlendSpheres"],
        "Component": ["BlendSpheres"],
        "Fxyz": ["((x-9/10)*(x-9/10)+y*y+z*z-1)*((x+9/10)*(x+9/10)+y*y+z*z-1)-3/10"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-2"],
        "Zmax": ["2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["IntersectSpheres"],
        "Component": ["IntersectSpheres"],
        "Fxyz": ["max(((x-7/10)*(x-7/10)+y*y+z*z-1),((x+1/2)*(x+1/2)+y*y+z*z-1))"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-2"],
        "Zmax": ["2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["TwoCylinderBlend"],
        "Component": ["TwoCylinderBlend"],
        "Fxyz": ["(x^2+y^2-1)*(x^2+z^2-1)-1"],
        "Xmin": ["-3"],
        "Xmax": ["3"],
        "Ymin": ["-3"],
        "Ymax": ["3"],
        "Zmin": ["-3"],
        "Zmax": ["3"]
      }
    },
    {
      "Iso3D": {
        "Name": ["BlendThreeCylinder"],
        "Component": ["BlendThreeCylinder"],
        "Fxyz": ["(x^2+y^2-1)*(x^2+z^2-1)*(y^2+z^2-1)-1"],
        "Xmin": ["-3"],
        "Xmax": ["3"],
        "Ymin": ["-3"],
        "Ymax": ["3"],
        "Zmin": ["-3"],
        "Zmax": ["3"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Holes"],
        "Component": ["Holes"],
        "Fxyz": ["3*(cos(x)+cos(y)+cos(z))+4*cos(x)*cos(y)*cos(z)"],
        "Xmin": ["-3"],
        "Xmax": ["3"],
        "Ymin": ["-3"],
        "Ymax": ["3"],
        "Zmin": ["-3"],
        "Zmax": ["3"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Gyroid"],
        "Component": ["Gyroid"],
        "Fxyz": ["cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)"],
        "Xmin": ["-4"],
        "Xmax": ["4"],
        "Ymin": ["-4"],
        "Ymax": ["4"],
        "Zmin": ["-4"],
        "Zmax": ["4"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Diamand"],
        "Component": ["Diamand"],
        "Fxyz": ["sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)"],
        "Xmin": ["-4"],
        "Xmax": ["4"],
        "Ymin": ["-4"],
        "Ymax": ["4"],
        "Zmin": ["-4"],
        "Zmax": ["4"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Tetrahedral"],
        "Component": ["Tetrahedral"],
        "Fxyz": ["(x^2+y^2+z^2)^2+8*x*y*z-10*(x^2+y^2+z^2)+25"],
        "Xmin": ["-4"],
        "Xmax": ["4"],
        "Ymin": ["-4"],
        "Ymax": ["4"],
        "Zmin": ["-4"],
        "Zmax": ["4"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Holes_2"],
        "Component": ["Holes_2"],
        "Fxyz": ["sin(4*x)+sin(4*y)+sin(4*z) +4*x*y*z"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-2"],
        "Zmax": ["2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Bugs"],
        "Component": ["Bugs"],
        "Const": [
           "A=7/10",
           "B=29/10",
           "C=86/100"],
        "Fxyz": ["min((((x*cos(C*y)-z*sin(C*y))-A)*((x*cos(C*y)-z*sin(C*y))-A)+(y/B)*(y/B)+(x*sin(C*y)+z*cos(C*y))*(x*sin(C*y)+z*cos(C*y))-1),(((x*cos(C*y)-z*sin(C*y))+(1/2))*((x*cos(C*y)-z*sin(C*y))+(1/2))+(y/B)*(y/B)+(x*sin(C*y)+z*cos(C*y))*(x*sin(C*y)+z*cos(C*y))-1))"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-6"],
        "Ymax": ["6"],
        "Zmin": ["-2"],
        "Zmax": ["2"]
      }
    },
    {
      "Iso3D": {
        "Name": ["pseudo_Torus"],
        "Component": ["pseudo_Torus"],
        "Const": ["A=436332/1000000"],
        "Fxyz": ["(sqrt((10*x/27)*(10*x/27)+(y*sin(A*x)+z*cos(A*x))*(y*sin(A*x)+z*cos(A*x)))-3)^2+(y*cos(A*x)-z*sin(A*x))*(y*cos(A*x)-z*sin(A*x))-1"],
        "Xmin": ["-54/5"],
        "Xmax": ["54/5"],
        "Ymin": ["-4"],
        "Ymax": ["4"],
        "Zmin": ["-4"],
        "Zmax": ["4"]
      }
    },
    {
        "Iso3D": {
            "Description": ["Chmutov_Schwarz surface by Abderrahman Taha 22/04/2019"],
            "Name": ["Chmutov_Schwarz"],
            "Fxyz": ["-((x^k+y ^k+z^k )-(cos(n*l*x/5)+cos(n*l*y/5)+cos(n*l*z/5))-p)"],
            "Component": ["ChmutySchwarz"],
            "Const": ["k=12","l=7","p=1/100","n=1","c=11/10"],
            "Xmax": ["c"],
            "Xmin": ["-c"],
            "Ymax": ["c"],
            "Ymin": ["-c"],
            "Zmax": ["c"],
            "Zmin": ["-c"]
        },
        "Sliders": {
            "Max": ["30","30","30"],
            "Min": ["0","0","0"],
            "Name": ["k","l","n"],
            "Position": ["12","7","5"],
            "Step": ["1","1","1"]
        }
    },
    {
      "Iso3D": {
        "Name": ["Virus"],
        "Component": ["Virus"],
        "Fxyz": ["-(x^2+y ^2+z^2)+cos(5*x)*cos(5*y)*cos(5*z)+43/200"],
        "Xmin": ["-4/5"],
        "Xmax": ["4/5"],
        "Ymin": ["-4/5"],
        "Ymax": ["4/5"],
        "Zmin": ["-4/5"],
        "Zmax": ["4/5"]
      }
    },
    {
      "Iso3D": {
        "Name": ["BlobySchwarz"],
        "Component": ["BlobySchwarz"],
        "Fxyz": ["-(x^2+y ^2+z^2)+cos(5*x)+cos(5*y)+cos(5*z)-1/10"],
        "Xmin": ["-2"],
        "Xmax": ["2"],
        "Ymin": ["-2"],
        "Ymax": ["2"],
        "Zmin": ["-2"],
        "Zmax": ["2"]
      }
    },
    {
      "Iso3D": {
        "Description": ["ThickIso by Abderrahman Taha 08/11/2019"],
        "Name": ["ThickIso"],
        "Component": ["ThickIso"],
        "Fxyz": ["(cos(x)+cos(y)+cos(z))*((cos(x+sin(x)/(2*sqrt(sin(x)^2+sin(y)^2+sin(z)^2)))+cos(y+sin(y)/(2*sqrt(sin(x)^2+sin(y)^2+sin(z)^2)))+cos(z+sin(z)/(2*sqrt(sin(x)^2+sin(y)^2+sin(z)^2)))))"],
        "Xmin": ["-4"],
        "Xmax": ["4"],
        "Ymin": ["-4"],
        "Ymax": ["4"],
        "Zmin": ["-4"],
        "Zmax": ["4"]
      }
    },
    {
      "Iso3D": {
          "Description": ["CloseIso_1 by Abderrahman taha 17/02/2019"],
        "Name": ["CloseIso_1"],
        "Component": ["CloseIso_1"],
        "Const": ["C=1/1000000"],
        "Fxyz": ["-max((cos(x)+cos(y)+cos(z))*((cos(x+sin(x)/(2*sqrt(sin(x)^2+sin(y)^2+sin(z)^2+C)))+cos(y+sin(y)/(2*sqrt(sin(x)^2+sin(y)^2+sin(z)^2+C)))+cos(z+sin(z)/(2*sqrt(sin(x)^2+sin(y)^2+sin(z)^2+C))))),(x^10+y^10+z^10-((39/10)^10)))"],
        "Xmin": ["-4"],
        "Xmax": ["4"],
        "Ymin": ["-4"],
        "Ymax": ["4"],
        "Zmin": ["-4"],
        "Zmax": ["4"]
      }
    },
    {
      "Iso3D": {
        "Description": ["CloseIso_2 by Abderrahman taha 28/11/2018"],
        "Name": ["CloseIso_2"],
        "Component": ["CloseIso_2"],
        "Fxyz": ["-max((x^10+y^10+z^10-100000),(cos(x)+cos(y)+cos(z)))"],
        "Xmin": ["-4"],
        "Xmax": ["4"],
        "Ymin": ["-4"],
        "Ymax": ["4"],
        "Zmin": ["-4"],
        "Zmax": ["4"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Chain"],
        "Component": ["Chain"],
        "Fxyz": ["-((sqrt(x*x+y*y)-3)^2+z*z-2/5)*((sqrt((x-9/2)*(x-9/2)+z*z)-3)^2+y*y-2/5)*((sqrt((x+9/2)*(x+9/2)+z*z)-3)^2+y*y-2/5)*((sqrt((y+9/2)*(y+9/2)+z*z)-3)^2+x*x-2/5)*((sqrt((y-9/2)*(y-9/2)+z*z)-3)^2+x*x-2/5)*((sqrt(x*x+y*y)-5)^2+z*z-2/5)"],
        "Xmin": ["-41/5"],
        "Xmax": ["41/5"],
        "Ymin": ["-41/5"],
        "Ymax": ["41/5"],
        "Zmin": ["-4"],
        "Zmax": ["4"]
      }
    },
    {
      "Iso3D": {
        "Name": ["DiamondLatice"],
        "Cnd": ["(sqrt(x^2+y^2+z^2))<8"],
        "Component": ["DiamondLatice"],
        "Const": ["T=1","G=-1"],
        "Funct": ["df=(cos(x)*sin(y)*sin(z)+cos(x)*cos(y)*cos(z)-sin(x)*sin(y)*cos(z)-sin(x)*cos(y)*sin(z))",
          "R=sqrt((cos(x)*sin(y)*sin(z)+cos(x)*cos(y)*cos(z)-sin(x)*sin(y)*cos(z)-sin(x)*cos(y)*sin(z))^2+(cos(y)*sin(z)*sin(x)+cos(y)*cos(z)*cos(x)-sin(y)*sin(z)*cos(x)-sin(y)*cos(z)*sin(x))^2+(cos(z)*sin(x)*sin(y)+cos(z)*cos(x)*cos(y)-sin(z)*sin(x)*cos(y)-sin(z)*cos(x)*sin(y))^2)",
          "Diamond=(sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z))"],
        "Fxyz": ["Diamond(x-df(x,y,z,t)*T/R(x,y,z,t),y-df(y,z,x,t)*T/R(x,y,z,t),z-df(z,x,y,t)*T/R(x,y,z,t),t)*Diamond(x-df(x,y,z,t)*G/R(x,y,z,t),y-df(y,z,x,t)*G/R(x,y,z,t),z-df(z,x,y,t)*G/R(x,y,z,t),t)"],
        "Xmax": ["8"],
        "Xmin": ["-8"],
        "Ymax": ["8"],
        "Ymin": ["-8"],
        "Zmax": ["8"],
        "Zmin": ["-8"]
      }
    },
    {
      "Iso3D": {
        "Name": ["GyroidLatice"],
        "Component": ["GyroidLatice"],
        "Cnd": ["(sqrt(x^2+y^2+z^2))<8"],
        "Const": ["T=1","G=-T"],
        "Funct": ["R=sqrt((-sin(x)*sin(y)+cos(x)*cos(z))^2+(-sin(y)*sin(z)+cos(y)*cos(x))^2+(-sin(z)*sin(x)+cos(z)*cos(y))^2)",
          "df=(-sin(x)*sin(y)+cos(x)*cos(z))",
          "Gyroid=(cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x))"],
        "Fxyz": ["Gyroid(x-df(x,y,z,t)*T/R(x,y,z,t),y-df(y,z,x,t)*T/R(x,y,z,t),z-df(z,x,y,t)*T/R(x,y,z,t),t)*Gyroid(x-df(x,y,z,t)*G/R(x,y,z,t),y-df(y,z,x,t)*G/R(x,y,z,t),z-df(z,x,y,t)*G/R(x,y,z,t),t)"],
        "Xmax": ["8"],
        "Xmin": ["-8"],
        "Ymax": ["8"],
        "Ymin": ["-8"],
        "Zmax": ["8"],
        "Zmin": ["-8"]
      }
    },
    {
      "Iso3D": {
        "Name": ["NeoviusLatice"],
        "Component": ["NeoviusLatice"],
        "Cnd": ["(sqrt(x^2+y^2+z^2))<9"],
        "Const": ["T=3/10","G=-T"],
        "Funct": ["df=(-3*sin(x)-4*sin(x)*cos(y)*cos(z))",
          "R=sqrt(df(x,y,z,t)^2+df(y,z,x,t)^2+df(z,y,x,t)^2)",
          "Neovius=(3*(cos(x)+cos(y)+cos(z))+4*cos(x)*cos(y)*cos(z))"],
        "Fxyz": ["Neovius(x-df(x,y,z,t)*T/R(x,y,z,t),y-df(y,z,x,t)*T/R(x,y,z,t),z-df(z,x,y,t)*T/R(x,y,z,t),t)*Neovius(x-df(x,y,z,t)*G/R(x,y,z,t),y-df(y,z,x,t)*G/R(x,y,z,t),z-df(z,x,y,t)*G/R(x,y,z,t),t)"],
        "Xmax": ["9"],
        "Xmin": ["-9"],
        "Ymax": ["9"],
        "Ymin": ["-9"],
        "Zmax": ["9"],
        "Zmin": ["-9"]
      }
    },
    {
      "Iso3D": {
        "Name": ["LinoidLatice"],
        "Cnd": ["(sqrt(x^2+y^2+z^2))<3"],
        "Component": ["LinoidLatice"],
        "Const": ["T=(1/20)","G=-T"],
        "Funct": ["df=((1/2)*(2*cos(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*cos(x)-sin(2*z)*sin(x)*sin(y))-(1/2)*(-2*sin(2*x)*cos(2*y)-2*cos(2*z)*sin(2*x)))",
          "R=sqrt(df(x,y,z,t)^2+df(y,z,x,t)^2+df(z,y,x,t)^2)",
          "Linoid=((1/2)*(sin(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*sin(x)+sin(2*z)*cos(x)*sin(y))-(1/2)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+(3/20))"],
        "Fxyz": ["Linoid(x-df(x,y,z,t)*T/R(x,y,z,t),y-df(y,z,x,t)*T/R(x,y,z,t),z-df(z,x,y,t)*T/R(x,y,z,t),t)*Linoid(x-df(x,y,z,t)*G/R(x,y,z,t),y-df(y,z,x,t)*G/R(x,y,z,t),z-df(z,x,y,t)*G/R(x,y,z,t),t)"],
        "Xmax": ["3"],
        "Xmin": ["-3"],
        "Ymax": ["3"],
        "Ymin": ["-3"],
        "Zmax": ["3"],
        "Zmin": ["-3"]
      }
    },
    {
      "Iso3D": {
        "Name": ["Lidinoid"],
        "Component": ["Lidinoid"],
        "Fxyz": ["-((1/2)*(sin(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*sin(x)+sin(2*z)*cos(x)*sin(y))-(1/2)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+(3/20))"],
        "Xmax": ["3"],
        "Xmin": ["-3"],
        "Ymax": ["3"],
        "Ymin": ["-3"],
        "Zmax": ["3"],
        "Zmin": ["-3"]
      }
    },
    {
      "Iso3D": {
        "Name": ["G_SkeletalGraph"],
        "Component": ["G_SkeletalGraph"],
        "Fxyz": ["cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)+(2/25)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+(147/100)"],
        "Xmax": ["(11/4)*pi"],
        "Xmin": ["-pi/4"],
        "Ymax": ["(11/4)*pi"],
        "Ymin": ["-pi/4"],
        "Zmax": ["(11/4)*pi"],
        "Zmin": ["-pi/4"]
      }
    },
    {
      "Iso3D": {
        "Name": ["D_SkeletalGraph"],
        "Component": ["D_SkeletalGraph"],
        "Fxyz": ["sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)-(7/100)*(cos(4*x)+cos(4*y)+cos(4*z))+(117/100)"],
        "Xmax": ["(11/4)*pi"],
        "Xmin": ["-pi/4"],
        "Ymax": ["(11/4)*pi"],
        "Ymin": ["-pi/4"],
        "Zmax": ["(11/4)*pi"],
        "Zmin": ["-pi/4"]
      }
    },
    {
      "Iso3D": {
        "Name": ["P_SkeletalGraph"],
        "Component": ["P_SkeletalGraph"],
        "Fxyz": ["cos(x)+cos(y)+cos(z)+(51/100)*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+(147/100)"],
        "Xmax": ["4*pi"],
        "Xmin": ["0"],
        "Ymax": ["4*pi"],
        "Ymin": ["0"],
        "Zmax": ["4*pi"],
        "Zmin": ["0"]
      }
    },
    {
        "Iso3D": {
            "Description": ["Constructive Solid Geometry (CSG) by Abderrahman Taha 28/07/2020"],
            "Name": ["CSG"],
            "Component": ["CSG"],
            "Const": ["sr=1","tr=1/5","ur=1/5"],
            "Grid": ["150"],
            "Fxyz": ["-max((x*x+y*y+z*z-sr),(x^10+y^10+z^10-ur))*max(max((x*x+y*y+z*z-1),(x^10+y^10+z^10-ur)),min(min((x*x+y*y-tr),(x*x+z*z-tr)),(y*y+z*z-tr)))"],
            "Xmax": ["1"],
            "Xmin": ["-1"],
            "Ymax": ["1"],
            "Ymin": ["-1"],
            "Zmax": ["1"],
            "Zmin": ["-1"]
        }
    },
    {
      "Iso3D": {
        "Description": ["Constructive Solid Geometry (CSG) by Abderrahman Taha 28/07/2020"],
        "Name": ["CSG_Spheres"],
        "Component": ["DifferenceSpheres","UnionSpheres","IntersectSpheres"],
        "Fxyz": ["((x-7/10)*(x-7/10)+y*y+z*z-1)*min(((x-7/10)*(x-7/10)+y*y+z*z-1),((x+3/10)*(x+3/10)+y*y+z*z-1))+1/50",
          "min(((x-47/10)*(x-47/10)+y*y+z*z-1),((x-7/2)*(x-7/2)+y*y+z*z-1))",
          "max(((x-7/10)*(x-7/10)+y*y+z*z-1),((x-2)*(x-2)+y*y+z*z-1))"],
        "Xmax": ["1/2","6","2"],
        "Xmin": ["-2","2","0"],
        "Ymax": ["2","2","2"],
        "Ymin": ["-2","-2","-2"],
        "Zmax": ["2","2","2"],
        "Zmin": ["-2","-2","-2"]
      }
    },
    {
      "Iso3D": {
        "Description": ["The formula : G(x,y,z)=F(x-2*P(x,y,z)*a/R,y-2*P(x,y,z)*b/R,z-2*P(x,y,z)*c/R)Where: P(x,y,z)=ax+by+cz+d(Equation of the Plan) R=(a^2+b^2+c^2)This example shows the result for a Torus(F) and a Plan(P=y-z+4)"],
        "Name": ["MirroredTorus"],
        "Component": ["Torus","Plan"],
        "Const": ["a=0","b=1","c=-1","d=4","R=(a^2+b^2+c^2)"],
        "Funct": ["Torus=((sqrt(x*x+y*y)-3)^2+z*z-1)","P=(a*x+b*y+c*z+d)"],
        "Fxyz": ["Torus(x,y,(z+1),t)*Torus(x-2*P(x,y,z,t)*a/R,y-2*P(x,y,z,t)*b/R,z+1-2*P(x,y,z,t)*c/R,t)","y+4-z"],
        "Xmax": ["4","4"],
        "Xmin": ["-4","-4"],
        "Ymax": ["8","8"],
        "Ymin": ["-6","-6"],
        "Zmax": ["9","9"],
        "Zmin": ["-4","-4"]
      }
    },
    {
      "Iso3D": {
        "Name": ["CheckerTexture"],
        "Component": ["Sphere","Cube","Schwarz","Sinus"],
        "Funct": ["Radius=sqrt(x*x+y*y+z*z)","Theta=atan(y/x)","Phi=acos(z/sqrt(x*x+y*y+z*z))"],
        "Fxyz": ["x*x+y*y+z*z-36","(x+14)^100+y^100+z^100-6*10^77","cos(2*x/3)+cos((y+16)*2/3)+cos(2*z/3)","sin(2*pi*(((x+14)/4)^2+((y+14)/4)^2))/8+z/4"],
        "Xmax": ["6","-8","6","-9"],
        "Xmin": ["-6","-20","-6","-19"],
        "Ymax": ["6","6","-10","-9"],
        "Ymin": ["-6","-6","-22","-19"],
        "Zmax": ["6","6","6","4"],
        "Zmin": ["-6","-6","-6","-4"]
      },
      "Texture": {
        "Colors": ["R=(int(abs(x))+int(abs(y))+int(abs(z)))%2",
          "G=1/10",
          "B=1",
          "T=1"],
        "Name": "Checker"
      }
    },
    {
      "Iso3D": {
        "Name": ["pseudo_Duplin"],
        "Component": ["pseudo_Duplin"],
        "Const": ["A=24/25","B=100/234"],
        "Fxyz": ["-50*((B*x)^4+(y*cos(A*x)-z*sin(A*x))^4+(y*sin(A*x)+z*cos(A*x))^4)+(-100)*((B*x)^2*(y*cos(A*x)-z*sin(A*x))^2+(B*x)^2*(y*sin(A*x)+z*cos(A*x))^2+(y*cos(A*x)-z*sin(A*x))^2*(y*sin(A*x)+z*cos(A*x))^2)+(141*(B*x-1))*((B*x)^2+(y*cos(A*x)-z*sin(A*x))^2+(y*sin(A*x)+z*cos(A*x))^2)+(55*x)*(-4+(17/20)*x)+262*(y*cos(A*x)-z*sin(A*x))^2+256"],
        "Xmax": ["6"],
        "Xmin": ["-5"],
        "Ymax": ["2"],
        "Ymin": ["-2"],
        "Zmax": ["2"],
        "Zmin": ["-2"]
      },
      "Pigment": {
        "Colors": [
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=1/5",
                "R=2/5",
                "G=2/5",
                "B=7/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=3/10",
                "R=1",
                "G=1/10",
                "B=3/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=3/5",
                "R=1/2",
                "G=1/5",
                "B=1",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=3/5",
                "R=1",
                "G=3/10",
                "B=1/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=1",
                "R=9/10",
                "G=1/5",
                "B=1/10",
                "A=1"
              ]
            }
          }
        ],
        "Gradient": "3*cos((x*x+y*y)*pi)*sin((y*y+z*z)*pi)"
      }
    },
    {
        "Iso3D": {
            "Description": ["CellNoiseSchwarz by Abderrahman Taha 08/03/2020"],
            "Name": ["CellNoiseSchwarz"],
            "Component": ["Schwarz"],
            "Fxyz": ["cos(x)+cos(y)+cos(z)-NoiseW(x,y,z,(1),(2),(0))"],
            "Xmax": ["4"],
            "Xmin": ["-4"],
            "Ymax": ["4"],
            "Ymin": ["-4"],
            "Zmax": ["4"],
            "Zmin": ["-4"]
        },
        "Texture": {
            "Colors": ["R=cos(x)*sin(z)+3/10","G=sin(x)*cos(y)+3/10","B=sin(y)*cos(z)+3/10","T=1"],
            "Name": "Lines3",
            "Noise": "NoiseW(x,y,z,(1),(2),(0))"
        }
    },
    {
      "Param3D": {
        "Name": ["Klein"],
        "Component": ["Klein_1","Klein_2"],
        "Fx": ["4*(1-cos(u)/2)*cos(u)*cos(v)+6*cos(u)*(1+sin(u))","4*(1-cos(u)/2)*cos(v+pi)+6*cos(u)*(1+sin(u))"],
        "Fy": ["4*(1-cos(u)/2)*sin(u)*cos(v)+16*sin(u)","16*sin(u)"],
        "Fz": ["4*(1-cos(u)/2)*sin(v)","4*(1-cos(u)/2)*sin(v)"],
        "Umin": ["0","pi"],
        "Umax": ["pi","2*pi"],
        "Vmin": ["0","0"],
        "Vmax": ["2*pi","2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Klein_1"],
        "Component": ["Klein_1"],
        "Funct": ["KleinFunction=(3*(1+sin(v))+2*(1-cos(v)/2)*cos(u))*cos(v)"],
        "Fx": ["KleinFunction(u,v,t)"],
        "Fy": ["(4+2*(1-cos(v)/2)*cos(u))*sin(v)"],
        "Fz": ["-2*(1-cos(v)/2)*sin(u)"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param4D": {
        "Name": ["4DTorus"],
        "Component": ["4DTorus"],
        "Fx": ["sin(u)"],
        "Fy": ["cos(u)"],
        "Fz": ["sin(v)"],
        "Fw": ["cos(v)"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param4D": {
        "Name": ["4DMathModels"],
        "Component": ["4DTorus4D","4DPTorus","4DCliffordTorus"],
        "Fx": ["sin(u)","sin(u)+2","cos(u+v)/(sqrt(2)+cos(v-u))"],
        "Fy": ["cos(u)","cos(u)","sin(u+v)/(sqrt(2)+cos(v-u))+3"],
        "Fz": ["sin(v)","sin(2*v)","(3/2)*(sin(v-u)/(sqrt(2)+cos(v-u)))"],
        "Fw": ["cos(v)","cos(3*v)","cos(u)"],
        "Umax": ["2*pi","2*pi","pi"],
        "Umin": ["0","0","0"],
        "Vmax": ["2*pi","2*pi","2*pi"],
        "Vmin": ["0","0","0"]
      }
    },
    {
      "Param3D": {
        "Name": ["Shell"],
        "Cnd": ["(x^2+y^2)>2"],
        "Component": ["Shell"],
        "Fx": ["(6/5)^v*(sin(u)^2*sin(v))"],
        "Fy": ["(6/5)^v*(sin(u)^2*cos(v))"],
        "Fz": ["(6/5)^v*(sin(u)*cos(u))"],
        "Umax": ["pi"],
        "Umin": ["0"],
        "Vmax": ["5*pi/2"],
        "Vmin": ["-pi/4"]
      }
    },
    {
      "Param3D": {
        "Name": ["Torus"],
        "Component": ["Torus"],
        "Fx": ["(1+cos(u)/2)*cos(v)"],
        "Fy": ["(1+cos(u)/2)*sin(v)"],
        "Fz": ["sin(u)/2"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["SinusPar"],
        "Component": ["Sinus"],
        "Fx": ["u"],
        "Fy": ["v"],
        "Fz": ["-sin(pi*((u)^2+(v)^2))/3"],
        "Umin": ["-1"],
        "Umax": ["1"],
        "Vmin": ["-1"],
        "Vmax": ["1"]
      }
    },
    {
      "Param3D": {
        "Name": ["Moebius"],
        "Component": ["Moebius"],
        "Fx": ["cos(v)+u*cos(v/2)*cos(v)"],
        "Fy": ["sin(v)+u*cos(v/2)*sin(v)"],
        "Fz": ["u*sin(v/2)"],
        "Umin": ["-2/5"],
        "Umax": ["2/5"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Riemann"],
        "Component": ["Riemann"],
        "Fx": ["u*v"],
        "Fy": ["v^2-u^2"],
        "Fz": ["30*u"],
        "Umin": ["-6"],
        "Umax": ["6"],
        "Vmin": ["-25"],
        "Vmax": ["25"]
      }
    },
    {
      "Param3D": {
        "Name": ["Klein_2"],
        "Component": ["Klein_2"],
        "Fx": ["(2+cos(v/2)*sin(u)-sin(v/2)*sin(2*u))*cos(v)"],
        "Fy": ["(2+cos(v/2)*sin(u)-sin(v/2)*sin(2*u))*sin(v)"],
        "Fz": ["sin(v/2)*sin(u)+cos(v/2)*sin(2*u)"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Henneberg"],
        "Component": ["Henneberg"],
        "Fx": ["2*sinh(u)*cos(v)-(2/3)*sinh(3*u)*cos(3*v)"],
        "Fy": ["2*sinh(u)*sin(v)+(2/3)*sinh(3*u)*sin(3*v)"],
        "Fz": ["2*cosh(2*u)*cos(2*v)"],
        "Umin": ["-1"],
        "Umax": ["1"],
        "Vmin": ["-pi/2"],
        "Vmax": ["pi/2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Enneper"],
        "Component": ["Enneper"],
        "Fx": ["u-u^3/3+u*v^2"],
        "Fy": ["v-v^3/3+v*u^2"],
        "Fz": ["u^2-v^2"],
        "Umin": ["-2"],
        "Umax": ["2"],
        "Vmin": ["-2"],
        "Vmax": ["2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Helix"],
        "Component": ["Helix"],
        "Fx": ["(1-cos(v)/10)*cos(u)"],
        "Fy": ["(1-cos(v)/10)*sin(u)"],
        "Fz": ["(sin(v)/10+u/17-1)"],
        "Umin": ["0"],
        "Umax": ["4*pi"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Hexaedron"],
        "Component": ["Hexaedron"],
        "Fx": ["cos(v)^3*cos(u)^3"],
        "Fy": ["sin(v)^3*cos(u)^3"],
        "Fz": ["sin(u)^3"],
        "Umin": ["-13/10"],
        "Umax": ["13/10"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Sphere"],
        "Component": ["Sphere"],
        "Fx": ["cos(u)*cos(v)"],
        "Fy": ["cos(u)*sin(v)"],
        "Fz": ["sin(u)"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Catalan_Minimal_Surface"],
        "Component": ["Catalan"],
        "Fx": ["u-sin(u)*cosh(v)"],
        "Fy": ["1-cos(u)*cosh(v)"],
        "Fz": ["4*sin(1/2*u)*sinh(v/2)"],
        "Umin": ["-pi"],
        "Umax": ["3*pi"],
        "Vmin": ["-2"],
        "Vmax": ["2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Toupie"],
        "Component": ["Toupie"],
        "Fx": ["(abs(u)-1)^2*cos(v)"],
        "Fy": ["(abs(u)-1)^2*sin(v)"],
        "Fz": ["u"],
        "Umin": ["-1"],
        "Umax": ["1"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Trumpet"],
        "Component": ["Trumpet"],
        "Fx": ["cos(u)*sin(v)"],
        "Fy": ["sin(u)*sin(v)"],
        "Fz": ["(cos(v)+log(tan(1/2*v)))"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["3/100"],
        "Vmax": ["2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Bonbon"],
        "Component": ["Bonbon"],
        "Fx": ["u"],
        "Fy": ["cos(u)*cos(v)"],
        "Fz": ["cos(u)*sin(v)"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Kuen"],
        "Component": ["Kuen"],
        "Fx": ["(2*(cos(u)+u*sin(u))*sin(v))/(1+u^2*sin(v)^2)"],
        "Fy": ["(2*(sin(u)-u*cos(u))*sin(v))/(1+u^2*sin(v)^2)"],
        "Fz": ["log(tan(1/2*v))+(2*cos(v))/(1+u^2*sin(v)^2)"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["(1/100)"],
        "Vmax": ["pi-(1/100)"]
      }
    },
    {
      "Param3D": {
        "Name": ["Catenoid"],
        "Component": ["Catenoid"],
        "Fx": ["2*cosh(v/2)*cos(u)"],
        "Fy": ["2*cosh(v/2)*sin(u)"],
        "Fz": ["v"],
        "Umin": ["-pi"],
        "Umax": ["pi"],
        "Vmin": ["-pi"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Shoe"],
        "Component": ["Shoe"],
        "Fx": ["u"],
        "Fy": ["v"],
        "Fz": ["(1/3)*u^3-(1/2)*v^2"],
        "Umin": ["-2"],
        "Umax": ["2"],
        "Vmin": ["-2"],
        "Vmax": ["2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Helicoidal"],
        "Component": ["Helicoidal"],
        "Fx": ["sinh(v)*sin(u)"],
        "Fy": ["-sinh(v)*cos(u)"],
        "Fz": ["3*u"],
        "Umin": ["-pi"],
        "Umax": ["pi"],
        "Vmin": ["-pi"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Cresent"],
        "Component": ["Cresent"],
        "Fx": ["(2+sin(2*pi*u)*sin(2*pi*v))*sin(3*pi*v)"],
        "Fy": ["(2+sin(2*pi*u)*sin(2*pi*v))*cos(3*pi*v)"],
        "Fz": ["cos(2*pi*u)*sin(2*pi*v)+4*v-2"],
        "Umin": ["0"],
        "Umax": ["1"],
        "Vmin": ["0"],
        "Vmax": ["1"]
      }
    },
    {
      "Param3D": {
        "Name": ["HyperbolicHelicoid"],
        "Component": ["HyperbolicHelicoid"],
        "Fx": ["(sinh(v)*cos(3*u))/(1+cosh(u)*cosh(v))"],
        "Fy": ["(sinh(v)*sin(3*u))/(1+cosh(u)*cosh(v))"],
        "Fz": ["(cosh(v)*sinh(u))/(1+cosh(u)*cosh(v))"],
        "Umin": ["-pi"],
        "Umax": ["pi"],
        "Vmin": ["-pi"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Roman"],
        "Component": ["Roman"],
        "Fx": ["sin(2*u)*sin(v)^2"],
        "Fy": ["sin(u)*cos(2*v)"],
        "Fz": ["cos(u)*sin(2*v)"],
        "Umin": ["0"],
        "Umax": ["pi"],
        "Vmin": ["-pi/2"],
        "Vmax": ["pi/2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Snake"],
        "Component": ["Snake"],
        "Fx": ["(6/5)*(1-v/(2*pi))*cos(3*v)*(1+cos(u))+3*cos(3*v)"],
        "Fy": ["(6/5)*(1-v/(2*pi))*sin(3*v)*(1+cos(u))+3*sin(3*v)"],
        "Fz": ["9*v/(2*pi)+(6/5)*(1-v/(2*pi))*sin(u)"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Horn"],
        "Component": ["Horn"],
        "Fx": ["(2+u*cos(v))*sin(2*pi*u)"],
        "Fy": ["(2+u*cos(v))*cos(2*pi*u)+2*u"],
        "Fz": ["u*sin(v)"],
        "Umin": ["0"],
        "Umax": ["1"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Fresnel_1"],
        "Component": ["Fresnel_1"],
        "Fx": ["cos(u)*cos(v)/(-2*sqrt((965/3000)-(935/3000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-(941/6000)+(374/1000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-(1309/6000)*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-(1221/1000)*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt((965/3000)-(935/3000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)+pi)/3)+(4/5))"],
        "Fy": ["sin(u)*cos(v)/(-2*sqrt((965/3000)-(935/3000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-(941/6000)+(374/1000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-(1309/6000)*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-(1221/1000)*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt((965/3000)-(935/3000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)+pi)/3)+(4/5))"],
        "Fz": ["sin(v)/(-2*sqrt((965/3000)-(935/3000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-(941/6000)+(374/1000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-(1309/6000)*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-(1221/1000)*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt((965/3000)-(935/3000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)+pi)/3)+(4/5))"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["-pi/2"],
        "Vmax": ["pi/2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Steiner"],
        "Component": ["Steiner"],
        "Fx": ["(sin(2*u)*cos(v)*cos(v))"],
        "Fy": ["(sin(u)*sin(2*v))"],
        "Fz": ["(cos(u)*sin(2*v))"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["-pi/2"],
        "Vmax": ["pi/2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Cross_cap"],
        "Component": ["Cross_cap"],
        "Fx": ["(sin(u)*sin(2*v)/2)"],
        "Fy": ["(sin(2*u)*cos(v)*cos(v))"],
        "Fz": ["(cos(2*u)*cos(v)*cos(v))"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["-pi/2"],
        "Vmax": ["pi/2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Fresnel_2"],
        "Component": ["Fresnel_2"],
        "Fx": ["cos(u)*cos(v)/(-2*sqrt((322/1000)-(312/1000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-(941/6000)+(374/1000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-(1309/6000)*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-(1221/1000)*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt((322/1000)-(312/1000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+(4/5))"],
        "Fy": ["sin(u)*cos(v)/(-2*sqrt((322/1000)-(312/1000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-(941/6000)+(374/1000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-(1309/6000)*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-(1221/1000)*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt((322/1000)-(312/1000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+(4/5))"],
        "Fz": ["sin(v)/(-2*sqrt((322/1000)-(312/1000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-(941/6000)+(374/1000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-(1309/6000)*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-(1221/1000)*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt((322/1000)-(312/1000)*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+(4/5))"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["-pi/2"],
        "Vmax": ["pi/2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Clifford_Torus"],
        "Component": ["CliffordTorus"],
        "Fx": ["cos(u+v)/(sqrt(2)+cos(v-u))"],
        "Fy": ["sin(u+v)/(sqrt(2)+cos(v-u))"],
        "Fz": ["sin(v-u)/(sqrt(2)+cos(v-u))"],
        "Umin": ["0"],
        "Umax": ["pi"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Stereosphere"],
        "Component": ["Stereosphere"],
        "Fx": ["2*u/(u*u+v*v+1)"],
        "Fy": ["2*v/(u*u+v*v+1)"],
        "Fz": ["(u*u+v*v-1)/(u*u+v*v+1)"],
        "Umin": ["-2"],
        "Umax": ["2"],
        "Vmin": ["-2"],
        "Vmax": ["2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Enneper_2"],
        "Component": ["Enneper_2"],
        "Fx": ["u*cos(v)-u^3/3*cos(3*v)"],
        "Fy": ["-u*sin(v)-u^3/3*sin(3*v)"],
        "Fz": ["u^2*cos(2*v)"],
        "Umin": ["0"],
        "Umax": ["6/5"],
        "Vmin": ["-pi"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Maeder's_Owl"],
        "Component": ["Maeder's_Owl"],
        "Fx": ["v*cos(u)-v^2*cos(2*u)/2"],
        "Fy": ["-v*sin(u)-v^2*sin(2*u)/2"],
        "Fz": ["4*v^(3/2)*cos(3*u/2)/3"],
        "Umin": ["0"],
        "Umax": ["4*pi"],
        "Vmin": ["0"],
        "Vmax": ["1"]
      }
    },
    {
      "Param3D": {
        "Name": ["Boy"],
        "Component": ["Boy"],
        "Fx": ["2/3*(cos(u)*cos(2*v)+sqrt(2)*sin(u)*cos(v))*cos(u)/(sqrt(2)-sin(2*u)*sin(3*v))"],
        "Fy": ["2/3*(cos(u)*sin(2*v)-sqrt(2)*sin(u)*sin(v))*cos(u)/(sqrt(2)-sin(2*u)*sin(3*v))"],
        "Fz": ["sqrt(2)*cos(u)*cos(u)/(sqrt(2)-sin(2*u)*sin(3*v))"],
        "Umin": ["0"],
        "Umax": ["pi"],
        "Vmin": ["0"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Dini"],
        "Component": ["Dini"],
        "Fx": ["cos(u)*sin(v)"],
        "Fy": ["sin(u)*sin(v)"],
        "Fz": ["(cos(v)+log(tan(v/2)))+u/5"],
        "Umin": ["0"],
        "Umax": ["62/5"],
        "Vmin": ["1/10"],
        "Vmax": ["2"]
      }
    },
    {
      "Param3D": {
        "Name": ["EightSurface"],
        "Component": ["EightSurface"],
        "Fx": ["cos(u)*sin(2*v)"],
        "Fy": ["sin(u)*sin(2*v)"],
        "Fz": ["sin(v)"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["-pi/2"],
        "Vmax": ["pi/2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Helliptic_paraboloid"],
        "Component": ["Hellipticparaboloid"],
        "Fx": ["v*2*cos(u)"],
        "Fy": ["v*sin(u)"],
        "Fz": ["v^2"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["0"],
        "Vmax": ["2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Plan"],
        "Component": ["Plan"],
        "Fx": ["u"],
        "Fy": ["0"],
        "Fz": ["v"],
        "Umin": ["-1"],
        "Umax": ["1"],
        "Vmin": ["-1"],
        "Vmax": ["1"]
      }
    },
    {
      "Param3D": {
        "Name": ["Apple"],
        "Component": ["Apple"],
        "Fx": ["cos(u)*(4+(19/5)*cos(v))"],
        "Fy": ["sin(u)*(4+(19/5)*cos(v))"],
        "Fz": ["(cos(v)+sin(v)-1)*(1+sin(v))*log(1-pi*v/10)+(15/2)*sin(v)"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["-pi"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Drop"],
        "Component": ["Drop"],
        "Fx": ["u*cos(v)"],
        "Fy": ["u*sin(v)"],
        "Fz": ["exp(-u*u)*(sin(2*pi*u)-u*cos(3*v))"],
        "Umin": ["0"],
        "Umax": ["2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Cone"],
        "Component": ["Cone"],
        "Fx": ["u*cos(v)"],
        "Fy": ["u*sin(v)"],
        "Fz": ["u"],
        "Umin": ["-1"],
        "Umax": ["1"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Kinky_Torus"],
        "Component": ["Kinky_Torus"],
        "Fx": ["1/cosh(u)-cos(v)"],
        "Fy": ["sin(v)"],
        "Fz": ["u/pi-tanh(v)"],
        "Umin": ["-2*pi"],
        "Umax": ["2*pi"],
        "Vmin": ["-pi"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Kidney"],
        "Component": ["Kidney"],
        "Fx": ["cos(u)*(3*cos(v)-cos(3*v))"],
        "Fy": ["sin(u)*(3*cos(v)-cos(3*v))"],
        "Fz": ["3*sin(v)-sin(3*v)"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["-pi/2"],
        "Vmax": ["pi/2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Triaxial_Hexatorus"],
        "Component": ["Triaxial_Hexatorus"],
        "Fx": ["sin(u)/(sqrt(2)+cos(v))"],
        "Fy": ["sin(u+2*pi/3)/(sqrt(2)+cos(v+2*pi/3))"],
        "Fz": ["cos(u-2*pi/3)/(sqrt(2)+cos(v-2*pi/3))"],
        "Umin": ["-pi"],
        "Umax": ["pi"],
        "Vmin": ["-pi"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Limpet_Torus"],
        "Component": ["Limpet_Torus"],
        "Fx": ["cos(u)/(sqrt(2)+sin(v))"],
        "Fy": ["sin(u)/(sqrt(2)+sin(v))"],
        "Fz": ["1/(sqrt(2)+cos(v))"],
        "Umin": ["-pi"],
        "Umax": ["pi"],
        "Vmin": ["-pi"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Twisted_Triaxial"],
        "Component": ["Twisted_Triaxial"],
        "Fx": ["(1-sqrt(u*u+v*v)/sqrt(2*pi*pi))*cos(u)*cos(v)+sqrt(u*u+v*v)/sqrt(2*pi*pi)*sin(u)*sin(v)"],
        "Fy": ["(1-sqrt(u*u+v*v)/sqrt(2*pi*pi))*cos(u+2*pi/3)*cos(v+2*pi/3)+sqrt(u*u+v*v)/sqrt(2*pi*pi)*sin(u+2*pi/3)*sin(v+2*pi/3)"],
        "Fz": ["(1-sqrt(u*u+v*v)/sqrt(2*pi*pi))*cos(u+4*pi/3)*cos(v+4*pi/3)+sqrt(u*u+v*v)/sqrt(2*pi*pi)*sin(u+4*pi/3)*sin(v+4*pi/3)"],
        "Umin": ["-pi"],
        "Umax": ["pi"],
        "Vmin": ["-pi"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Snail"],
        "Component": ["Snail"],
        "Fx": ["u*cos(v)*sin(u)"],
        "Fy": ["u*cos(u)*cos(v)"],
        "Fz": ["-u*sin(v)"],
        "Umin": ["0"],
        "Umax": ["2"],
        "Vmin": ["-pi/2"],
        "Vmax": ["pi/2"]
      }
    },
    {
      "Param3D": {
        "Name": ["Implicit_Lemniscape"],
        "Component": ["Implicit_Lemniscape"],
        "Fx": ["cos(v)*sqrt(abs(sin(2*u)))*cos(u)"],
        "Fy": ["cos(v)*sqrt(abs(sin(2*u)))*sin(u)"],
        "Fz": ["(cos(v)*sqrt(abs(sin(2*u)))*cos(u))^2-(cos(v)*sqrt(abs(sin(2*u)))*sin(u))^2+2*(cos(v)*sqrt(abs(sin(2*u)))*cos(u))*(cos(v)*sqrt(abs(sin(2*u)))*sin(u))*(tan(v)^2)"],
        "Umin": ["0"],
        "Umax": ["pi"],
        "Vmin": ["0"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Bent_Horns"],
        "Component": ["Bent_Horns"],
        "Fx": ["(2+cos(u))*(v/3-sin(v))"],
        "Fy": ["(2+cos(u-2*pi/3))*(cos(v)-1)"],
        "Fz": ["(2+cos(u+2*pi/3))*(cos(v)-1)"],
        "Umin": ["-pi"],
        "Umax": ["pi"],
        "Vmin": ["-2*pi"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Folium"],
        "Component": ["Folium"],
        "Fx": ["cos(u)*(2*v/pi-tanh(v))"],
        "Fy": ["cos(u+2*pi/3)/cosh(v)"],
        "Fz": ["cos(u-2*pi/3)/cosh(v)"],
        "Umin": ["-pi"],
        "Umax": ["pi"],
        "Vmin": ["-pi"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Heart"],
        "Component": ["Heart"],
        "Fx": ["cos(u)*(4*sqrt(1-v^2)*sin(abs(u))^abs(u))"],
        "Fy": ["sin(u)*(4*sqrt(1-v^2)*sin(abs(u))^abs(u))"],
        "Fz": ["v"],
        "Umin": ["-pi"],
        "Umax": ["pi"],
        "Vmin": ["-1"],
        "Vmax": ["1"]
      }
    },
    {
      "Param3D": {
        "Name": ["Cube"],
        "Component": ["Cube"],
        "Fx": ["cos(u)*cos(v)/((abs(cos(u))^100+abs(sin(u))^100)*(abs(cos(v))^100+abs(sin(v))^100))^(1/100)"],
        "Fy": ["cos(u)*sin(v)/((abs(cos(u))^100+abs(sin(u))^100)*(abs(cos(v))^100+abs(sin(v))^100))^(1/100)"],
        "Fz": ["sin(u)/(abs(cos(u))^100+abs(sin(u))^100)^(1/100)"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Prism"],
        "Component": ["Prism"],
        "Fx": ["cos(u)*cos(v)*(abs(cos(3*v/4))^500+abs(sin(3*v/4))^500)^(-1/260)*(abs(cos(u))^200+abs(sin(u))^200)^(-1/200)"],
        "Fy": ["cos(u)*sin(v)*(abs(cos(3*v/4))^500+abs(sin(3*v/4))^500)^(-1/260)*(abs(cos(u))^200+abs(sin(u))^200)^(-1/200)"],
        "Fz": ["sin(u)*(abs(cos(u))^200+abs(sin(u))^200)^(-1/200)"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Hexagon"],
        "Component": ["Hexagon"],
        "Fx": ["cos(u)*cos(v)*(abs(cos(u))^300+abs(sin(u))^300)^(-1/300)*(abs(cos(3*v/2))^400+abs(sin(3*v/2))^400)^(-1/1000)"],
        "Fy": ["cos(u)*sin(v)*(abs(cos(u))^300+abs(sin(u))^300)^(-1/300)*(abs(cos(3*v/2))^400+abs(sin(3*v/2))^400)^(-1/1000)"],
        "Fz": ["sin(u)*(abs(cos(u))^300+abs(sin(u))^300)^(-1/300)"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Diamond"],
        "Component": ["Diamond"],
        "Fx": ["cos(u)*cos(v)/((abs(cos(u))+abs(sin(u)))*(abs(cos(v))+abs(sin(v))))"],
        "Fy": ["cos(u)*sin(v)/((abs(cos(u))+abs(sin(u)))*(abs(cos(v))+abs(sin(v))))"],
        "Fz": ["sin(u)/(abs(cos(u))+abs(sin(u)))"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Star"],
        "Component": ["Star"],
        "Fx": ["cos(u)*cos(v)*(abs(cos(1*u/4))^(1/2)+abs(sin(1*u/4))^(1/2))^(-10/3)*(abs(cos(5*v/4))^(17/10)+abs(sin(5*v/4))^(17/10))^(-10)"],
        "Fy": ["cos(u)*sin(v)*(abs(cos(1*u/4))^(1/2)+abs(sin(1*u/4))^(1/2))^(-10/3)*(abs(cos(5*v/4))^(17/10)+abs(sin(5*v/4))^(17/10))^(-10)"],
        "Fz": ["sin(u)*(abs(cos(1*u/4))^(1/2)+abs(sin(1*u/4))^(1/2))^(-10/3)"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["1/100000"],
        "Vmax": ["2*pi"]
      }
    },
    {
        "Param3D": {
            "Name": ["Star_7"],
            "Component": ["Star_7"],
            "Fx": ["cos(u)*cos(v)*(abs(cos(7*v/4))^(17/10)+abs(sin(7*v/4))^(17/10))^(-5)*(abs(cos(7*u/4))^(17/10)+abs(sin(7*u/4))^(17/10))^(-5)"],
            "Fy": ["cos(u)*sin(v)*(abs(cos(7*v/4))^(17/10)+abs(sin(7*v/4))^(17/10))^(-5)*(abs(cos(7*u/4))^(17/10)+abs(sin(7*u/4))^(17/10))^(-5)"],
            "Fz": ["sin(u)*(abs(cos(7*u/4))^(17/10)+abs(sin(7*u/4))^(17/10))^(-5)"],
            "Umax": ["pi/2"],
            "Umin": ["-pi/2"],
            "Vmax": ["2*pi"],
            "Vmin": ["1/10000"]
        }
    },
    {
      "Param3D": {
        "Name": ["Shape_9"],
        "Component": ["Shape_9"],
        "Fx": ["cos(u)*cos(v)*(abs(cos(2*u/4))^10+abs(sin(2*u/4))^10)^(-1/10)*(abs(cos(8*v/4))^100+abs(sin(8*v/4))^30)^(-1/60)"],
        "Fy": ["cos(u)*sin(v)*(abs(cos(2*u/4))^10+abs(sin(2*u/4))^10)^(-1/10)*(abs(cos(8*v/4))^100+abs(sin(8*v/4))^30)^(-1/60)"],
        "Fz": ["sin(u)*(abs(cos(2*u/4))^10+abs(sin(2*u/4))^10)^(-1/10)"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Shape_10"],
        "Component": ["Shape_10"],
        "Fx": ["cos(u)*cos(v)*(abs(cos(3*u/4))^1+abs(sin(3*u/4))^1)^(-1/1)*(abs(cos(6*v/4))^1+abs(sin(6*v/4))^1)^(-1/1)"],
        "Fy": ["cos(u)*sin(v)*(abs(cos(3*u/4))^1+abs(sin(3*u/4))^1)^(-1/1)*(abs(cos(6*v/4))^1+abs(sin(6*v/4))^1)^(-1/1)"],
        "Fz": ["sin(u)*(abs(cos(3*u/4))^1+abs(sin(3*u/4))^1)^(-1/1)"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Sphere_2"],
        "Component": ["Sphere_2"],
        "Fx": ["cos(u)*cos(v)"],
        "Fy": ["cos(u)*sin(v)"],
        "Fz": ["sin(u)*sin(v)"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Sphere_3"],
        "Component": ["Sphere_3"],
        "Fx": ["cos(u)*cos(v)"],
        "Fy": ["cos(u)*sin(v)"],
        "Fz": ["sin(u)*sin(v)*cos(v)"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Sphere_4"],
        "Component": ["Sphere_4"],
        "Fx": ["cos(u)*cos(v)"],
        "Fy": ["cos(u)*sin(v)*sin(v)"],
        "Fz": ["sin(u)*sin(v)"],
        "Umin": ["-pi/2"],
        "Umax": ["0"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Sphere_5"],
        "Component": ["Sphere_5"],
        "Fx": ["cos(u)*cos(v)*sin(v)"],
        "Fy": ["cos(u)*sin(v)*sin(v)"],
        "Fz": ["sin(u)*sin(v)"],
        "Umin": ["-pi/2"],
        "Umax": ["0"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Sphere_6"],
        "Component": ["Sphere_6"],
        "Fx": ["cos(u)*cos(v)*sin(u)"],
        "Fy": ["sin(u)"],
        "Fz": ["sin(u)*sin(v)*sin(u)"],
        "Umin": ["-pi/2"],
        "Umax": ["0"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Sphere_7"],
        "Component": ["Sphere_7"],
        "Fx": ["cos(u)*cos(v)*sin(u)"],
        "Fy": ["sin(u)*sin(v)*cos(u)"],
        "Fz": ["sin(u)*sin(v)*sin(u)"],
        "Umin": ["-pi/2"],
        "Umax": ["0"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Sphere_8"],
        "Component": ["Sphere_8"],
        "Fx": ["cos(u)*cos(v)*sin(u)"],
        "Fy": ["cos(u)*sin(v)*cos(u)"],
        "Fz": ["sin(u)*sin(v)*sin(u)"],
        "Umin": ["-pi/2"],
        "Umax": ["0"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Sphere_9"],
        "Component": ["Sphere_9"],
        "Fx": ["cos(u)*cos(v)*sin(u)"],
        "Fy": ["cos(u)*sin(v)*cos(u)*sin(v)"],
        "Fz": ["sin(u)*sin(v)*sin(u)*sin(v)"],
        "Umin": ["-pi/2"],
        "Umax": ["0"],
        "Vmin": ["0"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Sphere_10"],
        "Component": ["Sphere_10"],
        "Fx": ["cos(u)*cos(v)*sin(u)*sin(v)*sin(v)*sin(v)"],
        "Fy": ["cos(u)*sin(v)*cos(u)*sin(v)"],
        "Fz": ["sin(u)*sin(v)*sin(u)*sin(v)*cos(u)"],
        "Umin": ["-pi/2"],
        "Umax": ["0"],
        "Vmin": ["0"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Name": ["Curve"],
        "Component": ["Curve"],
        "Fx": ["cos(2*u)"],
        "Fy": ["sin(3*u)"],
        "Fz": ["cos(u)"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["0"],
        "Vmax": ["0"]
      }
    },
    {
      "Param3D": {
        "Name": ["Helice_Curve"],
        "Component": ["Helice_Curve"],
        "Fx": ["sin(u)"],
        "Fy": ["cos(u)"],
        "Fz": ["(u^2)/100"],
        "Umin": ["0"],
        "Umax": ["6*pi"],
        "Vmin": ["0"],
        "Vmax": ["0"]
      }
    },
    {
      "Param3D": {
        "Description": ["Pseudo Sphere by Abderrahman Taha 05/11/2019"],
        "Name": ["Pseudo_Sphere"],
        "Component": ["PseudoSphere"],
        "Fx": ["cos(u)*cos(v)+sin((sin(u)+1)*2*pi)"],
        "Fy": ["cos(u)*sin(v)+cos((sin(u)+1)*2*pi)"],
        "Fz": ["4*sin(u)"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Description": [
           "Pseudo Catenoid by Abderrahman Taha 05/11/2019"],
        "Name": ["Pseudo_Catenoid"],
        "Component": ["Pseudo_Catenoid"],
        "Fx": ["(22/5)*(cosh(v/2)*cos(u))"],
        "Fy": ["(3/2)*(2*cosh(v/2)*sin(u)*cos(((22/5)*(cosh(v/2)*cos(u))+11)*(9/100)*pi)-(9/5)*(v)*sin(((22/5)*(cosh(v/2)*cos(u))+11)*(9/100)*pi))"],
        "Fz": ["(3/2)*(2*cosh(v/2)*sin(u)*sin(((22/5)*(cosh(v/2)*cos(u))+11)*(9/100)*pi)+(9/5)*(v)*cos(((22/5)*(cosh(v/2)*cos(u))+11)*(9/100)*pi))"],
        "Umin": ["-pi"],
        "Umax": ["pi"],
        "Vmin": ["-pi"],
        "Vmax": ["pi"]
      }
    },
    {
      "Param3D": {
        "Description": [
           "Cone Distorsion by Abderrahman Taha 05/11/2019"],
        "Name": ["Cone_Distorsion"],
        "Component": ["Pseudo_Cone"],
        "Fx": ["u*cos(v)"],
        "Fy": ["(17/20)*(u*sin(v)*cos((u*cos(v)+1)*pi)-u*sin((u*cos(v)+1)*pi))"],
        "Fz": ["(17/20)*(u*sin(v)*sin((u*cos(v)+1)*pi)+u*cos((u*cos(v)+1)*pi))"],
        "Umin": ["-1"],
        "Umax": ["1"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Description": [
           "Pseudo_Hexagon by Abderrahman Taha 05/11/2019"],
        "Name": ["Pseudo_Hexagon"],
        "Component": ["Pseudo_Hexagon"],
        "Fx": ["(17/10)*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))"],
        "Fy": ["(3/4)*((15/10)*(cos(u)*sin(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))*cos(((17/10)*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))+(17/10))*(9/50)*pi)-(7/10)*(sin(u)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300))*sin(((17/10)*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))+(17/10))*(9/50)*pi))"],
        "Fz": ["(3/4)*((15/10)*(cos(u)*sin(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))*sin(((17/10)*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))+(17/10))*(9/50)*pi)+(7/10)*(sin(u)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300))*cos(((17/10)*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))+(17/10))*(9/50)*pi))"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Description": ["Pseudo_Cube by Abderrahman Taha 05/11/2019"],
        "Name": ["Pseudo_Cube"],
        "Component": ["PseudoCube"],
        "Fx": ["(17/20)*(cos(u)*cos(v)*(abs(cos(u))^100+abs(sin(u))^100)^(-1/100)*(abs(cos(v))^100+abs(sin(v))^100)^(-1/100)*cos(((8/5)*(sin(u)*(abs(cos(u))^100+abs(sin(u))^100)^(-1/100))+(8/5))*(19/100)*pi)-cos(u)*sin(v)*(abs(cos(u))^100+abs(sin(u))^100)^(-1/100)*(abs(cos(v))^100+abs(sin(v))^100)^(-1/100)*sin(((8/5)*(sin(u)*(abs(cos(u))^100+abs(sin(u))^100)^(-1/100))+(8/5))*(19/100)*pi))"],
        "Fy": ["(17/20)*(cos(u)*cos(v)*(abs(cos(u))^100+abs(sin(u))^100)^(-1/100)*(abs(cos(v))^100+abs(sin(v))^100)^(-1/100)*sin(((8/5)*(sin(u)*(abs(cos(u))^100+abs(sin(u))^100)^(-1/100))+(8/5))*(19/100)*pi)+cos(u)*sin(v)*(abs(cos(u))^100+abs(sin(u))^100)^(-1/100)*(abs(cos(v))^100+abs(sin(v))^100)^(-1/100)*cos(((8/5)*(sin(u)*(abs(cos(u))^100+abs(sin(u))^100)^(-1/100))+(8/5))*(19/100)*pi))"],
        "Fz": ["(8/5)*(sin(u)*(abs(cos(u))^100+abs(sin(u))^100)^(-1/100))"],
        "Umin": ["-pi/2"],
        "Umax": ["pi/2"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
      "Param3D": {
        "Description": [
           "Pseudo_Torus by Abderrahman Taha 05/11/2019"],
        "Name": ["Pseudo_Torus"],
        "Component": ["Pseudo_Torus"],
        "Fx": ["(1+cos(u)/2)*cos(v)"],
        "Fy": ["(63/100)*((1+cos(u)/2)*sin(v)*cos(((1+cos(u)/2)*cos(v)+(3/2))*(3/5)*pi)-(1/2)*sin(u)*sin(((1+cos(u)/2)*cos(v)+(3/2))*(3/5)*pi))"],
        "Fz": ["(63/100)*((1+cos(u)/2)*sin(v)*sin(((1+cos(u)/2)*cos(v)+(3/2))*(3/5)*pi)+(1/2)*sin(u)*cos(((1+cos(u)/2)*cos(v)+(3/2))*(3/5)*pi))"],
        "Umin": ["0"],
        "Umax": ["2*pi"],
        "Vmin": ["0"],
        "Vmax": ["2*pi"]
      }
    },
    {
        "Param3D": {
            "Description": ["Hurricane by Abderrahman Taha 05/11/2019"],
            "Name": ["Hurricane"],
            "Component": ["Hurricane"],
            "Fx": ["1*(2*cosh(v/2)*cos(u)*cos(((41/10)*v+(66/5))*(113/1000)*pi)-(21/5)*cosh(v/2)*sin(u)*sin(((41/10)*v+(66/5))*(113/1000)*pi))"],
            "Fy": ["1*(2*cosh(v/2)*cos(u)*sin(((41/10)*v+(66/5))*(113/1000)*pi)+(21/5)*cosh(v/2)*sin(u)*cos(((41/10)*v+(66/5))*(113/1000)*pi))"],
            "Fz": ["(41/10)*v"],
            "Umax": ["pi"],
            "Umin": ["-pi"],
            "Vmax": ["pi"],
            "Vmin": ["-pi"]
        }
    },
    {
        "Param3D": {
            "Description": ["Breather by Abderrahman Taha 05/11/2019"],
            "Name": ["Breather"],
            "Component": ["Breather"],
            "Const": ["A=sqrt(21/25)",
                "B=2/5"],
            "Fx": ["(2*A*cosh(B*u)*(-(A*cos(v)*cos(A*v))-sin(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))"],
            "Fy": ["(2*A*cosh(B*u)*(-(A*sin(v)*cos(A*v))+cos(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))"],
            "Fz": ["-u+((42/25)*cosh(B*u)*sinh(B*u))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))"],
            "Umax": ["66/5"],
            "Umin": ["-66/5"],
            "Vmax": ["186/5"],
            "Vmin": ["-186/5"]
        }
    },
    {
      "Param3D": {
        "Description": ["The formula is: 'Gx': ('Fx(u,v,t)+T*n1(u,v,t)/R(u,v,t)')'Gy': ('Fy(u,v,t)+T*n2(u,v,t)/R(u,v,t)')'Gz': ('Fz(u,v,t)+T*n3(u,v,t)/R(u,v,t)')WhereT=Thicknessvalue;'n1=(a2(u,v,t)*b3(u,v,t)-a3(u,v,t)*b2(u,v,t))','n2=(a3(u,v,t)*b1(u,v,t)-a1(u,v,t)*b3(u,v,t))','n3=(a1(u,v,t)*b2(u,v,t)-a2(u,v,t)*b1(u,v,t))','R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)''a1=dFx/du','a2=dFy/du','a3=dFz/du','b1=dFx/dv','b2=dFy/dv','b3=dFz/dv'"],
        "Name": ["Thick_Parametric_Torus"],
        "Component": ["Torus_1","Torus_2"],
        "Const": ["T=13/10","c=1/10000"],
        "Funct": ["Fx=(1+cos(u)/2)*cos(v)",
          "Fy=(1+cos(u)/2)*sin(v)",
          "Fz=sin(u)/2",
          "DFxu= ((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv= ((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu= ((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv= ((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu= ((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv= ((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1= (DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2= (DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3= (DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+T*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+T*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+T*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Fx(u,v,t)","Gx(u,v,t)"],
        "Fy": ["Fy(u,v,t)","Gy(u,v,t)"],
        "Fz": ["Fz(u,v,t)","Gz(u,v,t)"],
        "Umax": ["2*pi","2*pi"],
        "Umin": ["0","0"],
        "Vmax": ["2*pi","2*pi"],
        "Vmin": ["pi/3","pi/3"]
      }
    },
    {
      "Param3D": {
        "Description": ["Helicoid to Catenoid by Abderrahman Taha 04/11/2019"],
        "Name": ["Helicoid_To_Catenoid"],
        "Component": ["HelicoidCatenoid"],
        "Fx": ["cos(2*t*pi)*sinh(v)*sin(u)+sin(2*t*pi)*cosh(v)*cos(u)"],
        "Fy": ["-cos(2*t*pi)*sinh(v)*cos(u)+sin(2*t*pi)*cosh(v)*sin(u)"],
        "Fz": ["3*(u*cos(2*t*pi)+v*sin(2*t*pi))"],
        "Umax": ["pi"],
        "Umin": ["-pi"],
        "Vmax": ["pi"],
        "Vmin": ["-pi"]
      }
    },
    {
      "Param3D": {
        "Description": ["Shells by Abderrahman Taha 04/11/2019"],
        "Name": ["Shells"],
        "Component": ["Shell1","Shell2","Shell3","Shell4"],
        "Const": ["a=1/5","b=1","c=1/10","n=2"],
        "Fx": ["2*(1-exp(u/(6*pi)))*cos(u)*cos(v/2)^2","((a*(1-v/(2*pi))*(1+cos(u))+c)*cos(n*v))*6+4","2^v*(sin(u)*cos(u))/35","(6/5)^v*(sin(u)^2*sin(v))+2"],
        "Fy": ["2*(-1+exp(u/(6*pi)))*sin(u)*cos(v/2)^2","((a*(1-v/(2*pi))*(1+cos(u))+c)*sin(n*v))*6+4","2^v*(sin(u)^2*sin(v))/35-4","(6/5)^v*(sin(u)*cos(u))+5"],
        "Fz": ["1-exp(u/(3*pi))-sin(v)+exp(u/(6*pi))*sin(v)","(b*v/(2*pi)+a*(1-v/(2*pi))*sin(u))*6-6","2^v*(sin(u)^2*cos(v))/35-12","(6/5)^v*(sin(u)^2*cos(v))-12"],
        "Umax": ["6*pi","2*pi","pi","pi"],
        "Umin": ["0","0","0","0"],
        "Vmax": ["2*pi","2*pi","5*pi/2","5*pi/2"],
        "Vmin": ["0","0","0","0"]
      }
    },
    {
        "Iso3D": {
            "Description": ["Models Intersection by Abderrahman Taha 20/02/2020"],
            "Cnd": ["(x-y-(3/2)*z<0)",""],
            "Grid": ["30","20"],
            "Component": ["Schwarz","Plan"],
            "Fxyz": ["cos(x-4*sin(t*pi))+cos(y)+cos(z)","x-y-(3/2)*z-(1/100)"],
            "Name": ["Models_Intersection"],
            "Xmax": ["4+4*sin(t*pi)","6"],
            "Xmin": ["-4+4*sin(t*pi)","-6"],
            "Ymax": ["4","6"],
            "Ymin": ["-4","-6"],
            "Zmax": ["4","6"],
            "Zmin": ["-4","-6"]
        }
    },
    {
      "Param3D": {
        "Description": ["Torus_Noise by Abderrahman Taha 04/11/2019"],
        "Name": ["Fresnel Noise"],
        "Component": ["FresnelNoise"],
        "Const": ["A=941/6000",
          "B=965/3000",
          "C=935/3000",
          "D=4/5",
          "E=1309/6000",
          "F=374/1000",
          "G=1221/1000"],
        "Fx": ["(cos(u)*cos(v)/(-2*sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-A+F*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-E*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-G*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+D))*(1-NoiseW((cos(u)*cos(v)/(-2*sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-A+F*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-E*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-G*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+D)),(sin(u)*cos(v)/(-2*sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-A+F*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-E*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-G*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+D)),(sin(v)/(-2*sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-A+F*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-E*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-G*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+D)),(1),(2),0))"],
        "Fy": ["(sin(u)*cos(v)/(-2*sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-A+F*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-E*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-G*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+D))*(1-NoiseW((cos(u)*cos(v)/(-2*sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-A+F*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-E*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-G*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+D)),(sin(u)*cos(v)/(-2*sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-A+F*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-E*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-G*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+D)),(sin(v)/(-2*sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-A+F*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-E*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-G*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+D)),(1),(2),0))"],
        "Fz": ["(sin(v)/(-2*sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-A+F*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-E*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-G*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+D))*(1-NoiseW((cos(u)*cos(v)/(-2*sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-A+F*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-E*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-G*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+D)),(sin(u)*cos(v)/(-2*sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-A+F*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-E*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-G*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+D)),(sin(v)/(-2*sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-A+F*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-E*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-G*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(B-C*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+D)),(1),(2),0))"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["pi/2"],
        "Vmin": ["-pi/2"]
      }
    },
    {
      "Param3D": {
        "Description": ["Torus_Noise by Abderrahman Taha 04/11/2019"],
        "Name": ["Torus_Noise"],
        "Component": ["TorusNoise"],
        "Fx": ["(1+(1/2)*cos(u))*cos(v)*(1-NoiseW((1+(1/2)*cos(u))*cos(v),(1+(1/2)*cos(u))*sin(v),(1/2)*sin(u),(1),(2),(0)))"],
        "Fy": ["(1+(1/2)*cos(u))*sin(v)*(1-NoiseW((1+(1/2)*cos(u))*cos(v),(1+(1/2)*cos(u))*sin(v),(1/2)*sin(u),(1),(2),(0)))"],
        "Fz": ["sin(u)*(1-NoiseW((1+(1/2)*cos(u))*cos(v),(1+(1/2)*cos(u))*sin(v),(1/2)*sin(u),(1),(2),(0)))"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Texture": {
        "Colors": ["R=(4/5)",
          "G=(8/5)*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "B=(9/5)*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"],
        "Name": "PerlinNoise",
        "Noise": "NoiseP(x,y,z,(4),(4),(4/5))"
      }
    },
    {
      "Param3D": {
        "Description": ["Breather_Noise by Abderrahman Taha 04/11/2019"],
        "Name": ["Breather_Noise"],
        "Component": ["BreatherNoise"],
        "Const": ["A= sqrt(21/25)",
          "B= 2/5",
          "C= 42/25"],
        "Fx": ["((2*A*cosh(B*u)*(-(A*cos(v)*cos(A*v))-sin(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2)))*(1-NoiseW(((2*A*cosh(B*u)*(-(A*cos(v)*cos(A*v))-sin(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),((2*A*cosh(B*u)*(-(A*sin(v)*cos(A*v))+cos(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),(-u+(C*cosh(B*u)*sinh(B*u))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),(1),(2),(0)))"],
        "Fy": ["((2*A*cosh(B*u)*(-(A*sin(v)*cos(A*v))+cos(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2)))*(1-NoiseW(((2*A*cosh(B*u)*(-(A*cos(v)*cos(A*v))-sin(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),((2*A*cosh(B*u)*(-(A*sin(v)*cos(A*v))+cos(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),(-u+(C*cosh(B*u)*sinh(B*u))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),(1),(2),(0)))"],
        "Fz": ["(-u+(C*cosh(B*u)*sinh(B*u))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2)))*(1-NoiseW(((2*A*cosh(B*u)*(-(A*cos(v)*cos(A*v))-sin(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),((2*A*cosh(B*u)*(-(A*sin(v)*cos(A*v))+cos(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),(-u+(C*cosh(B*u)*sinh(B*u))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),(1),(2),(0)))"],
        "Umax": ["66/5"],
        "Umin": ["-66/5"],
        "Vmax": ["186/5"],
        "Vmin": ["-186/5"]
      }
    },
    {
      "Iso3D": {
        "Description": ["P_Skeletal Tori-2.0 by Abderrahman Taha 04/11/2019"],
        "Name": ["P_Skeletal_Tori"],
        "Component": ["P_SkeletalTori"],
        "Const": ["M=1","N1=15","N2=15","P=5","R=15"],
        "Funct": ["P_Skeletal=cos(x)+cos(y)+cos(z)+(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))/2+6/5","isoCondition_0=((x-pi)^2-(pi+1/20)^2)","isoCondition_1=((x-pi)^2-(pi)^2)","isoTransform=if(isoCondition_0(x,y,z,t)<(0),P_Skeletal(x,y,z,t),(1))+M*exp(isoCondition_1(x,y,z,t))","isoTransform2=isoTransform((sqrt(x*x+z*z)-P),y,N1*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-R),N2*atan2(y,x),z,t)"],
        "Xmax": ["30"],
        "Xmin": ["-30"],
        "Ymax": ["30"],
        "Ymin": ["-30"],
        "Zmax": ["15"],
        "Zmin": ["-15"]
      },
      "Sliders": {
        "Max": ["50","10","25","25","25","50","10","25","25","25","50","10","25","25","25","50","10","25","25","25"],
        "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
        "Name": ["M","P","R","N1","N2"],
        "Position": ["1","5","15","15","15","10","7","18","3","11","0","5","19","7","14","33","8","18","2","11"],
        "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
      }
    },
    {
      "Iso3D": {
        "Name": ["fhelix"],
        "Description ": ["Fhelix internal function with sliders by Abderrahman Taha 04/11/2019"],
        "Component": ["fhelix1"],
        "Fxyz": ["-fhelix1(sqrt(x*x+y*y)-(3),Param1*atan2(y,x),z,Param2,Param3,Param4/(15),Param5/(15),Param6/(15),Param7/(10),Param8*pi/(15))"],
        "Xmax": ["5"],
        "Xmin": ["-5"],
        "Ymax": ["5"],
        "Ymin": ["-5"],
        "Zmax": ["11/5"],
        "Zmin": ["-11/5"]
      },
      "Sliders": {
        "Max": ["10","10","10","30","30","30","20","30","10","10","10","30","30","30","20","30","10","10","10","30","30","30","20","30","10","10","10","30","30","30","20","30","10","10","10","30","30","30","20","30"],
        "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
        "Name": ["Param1","Param2","Param3","Param4","Param5","Param6","Param7","Param8"],
        "Position": ["2","2","2","10","22","15","20","0","2","2","2","8","24","17","10","19","2","3","2","5","9","13","7","0","2","2","2","23","9","3","20","3","2","2","2","8","22","16","0","21"],
        "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Inka Star by Abderrahman Taha 04/11/2019"],
        "Name": ["Inka_Star"],
        "Component": ["InkaStar"],
        "Const": ["c=1/10000",
          "A=sqrt(2)",
          "N=2"],
        "Funct": ["Th= ((sin(15*u)*cos(15*u)))^5+(sin(5*N*v))",
          "Fx=-cos(u+v)/(A+cos(v-u))",
          "Fy=sin(v-u)/(A+cos(v-u))",
          "Fz=sin(u+v)/(A+cos(v-u))",
          "DFxu= ((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv= ((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu= ((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv= ((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu= ((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv= ((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1= (DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2= (DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3= (DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Strapped Torus (implicit version) by Abderrahman Taha 04/11/2019"],
        "Name": ["Strapped_Torus"],
        "Component": ["StrappedTorus"],
        "Const": ["A = 2",
          "B = 2",
          "C = 23/15",
          "D = 3/5",
          "E = 1/5",
          "F = 2",
          "G = pi/5"],
        "Funct": ["X = x",
          "Z = z",
          "r = sqrt(X(x,y,z,t)*X(x,y,z,t)+Z(x,y,z,t)*Z(x,y,z,t))",
          "X= if ((X(x,y,z,t) = 0) & (Z(x,y,z,t) = 0),(1/100000),X(x,y,z,t))",
          "th = atan2(Z(x,y,z,t),X(x,y,z,t))",
          "th = ((th(x,y,z,t)*A+y*B*A) % (2*pi))",
          "th = if (th(x,y,z,t) < (0),th(x,y,z,t)+2*pi,th(x,y,z,t))",
          "Z = (th(x,y,z,t)-pi)/E/(B*A)",
          "X = r(x,y,z,t)-D",
          "Z = if ((F = 1 | G = 0)=(0),X(x,y,z,t)*sin(G*pi/180)+Z(x,y,z,t)*cos(G*pi/180),Z(x,y,z,t))",
          "X = if ((F = 1 | G = 0)=(0),X(x,y,z,t)*cos(G*pi/180)-Z(x,y,z,t)*sin(G*pi/180),X(x,y,z,t))",
          "r2 = if (F = (1),sqrt(X(x,y,z,t)*X(x,y,z,t)+Z(x,y,z,t)*Z(x,y,z,t)),if ((F = 0)=(0),(((((abs(X(x,y,z,t)))^(2/F))+((abs(Z(x,y,z,t)))^(2/F))))^(F/2)),if (abs(X(x,y,z,t)) > abs(Z(x,y,z,t)),abs(X(x,y,z,t)),abs(Z(x,y,z,t)))))",
          "r3 = if((D+r(x,y,z,t)) < r2(x,y,z,t),(D+r(x,y,z,t)),r2(x,y,z,t))",
          "helix = (-C+r3(x,y,z,t))"],
        "Fxyz": ["-helix((sqrt(x*x+y*y)-3),(2*atan2(y,x)),z,t)"],
        "Xmax": ["5"],
        "Xmin": ["-5"],
        "Ymax": ["5"],
        "Ymin": ["-5"],
        "Zmax": ["7/3"],
        "Zmin": ["-7/3"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Spiky Fresnel by Abderrahman Taha 04/11/2019"],
        "Name": ["Spiky_Fresnel"],
        "Component": ["SpikyFresnel"],
        "Const": ["c=1/10000"],
        "Funct": ["Th=-(3/10)*(abs(sin(25*u)*cos(27*v)))^(3*sin(17*u-15*v))^2",
          "Fx=(cos(u)*cos(v)/(-2*sqrt(965/3000-935/3000*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-941/6000+374/1000*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1309/6000*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1221/1000*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(965/3000-935/3000*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+4/5))",
          "Fy= sin(v)/(-2*sqrt(965/3000-935/3000*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-941/6000+374/1000*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1309/6000*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1221/1000*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(965/3000-935/3000*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+4/5)",
          "Fz= sin(u)*cos(v)/(-2*sqrt(965/3000-935/3000*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-941/6000+374/1000*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1309/6000*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1221/1000*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(965/3000-935/3000*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3)+4/5)",
          "DFxu= ((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv= ((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu= ((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv= ((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu= ((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv= ((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1= (DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2= (DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3= (DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["-Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["pi/2"],
        "Vmin": ["-pi/2"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Exotic flower-01 by Abderrahman Taha 15/10/2019"],
        "Name": ["Exotic flower"],
        "Component": ["ExoticFlower"],
        "Const": ["c=1/10000","A=sqrt(2)"],
        "Funct": ["Th=-(3/5)*(abs(sin(15*u)*cos(15*v)))^(3*sin(7*u-5*v))^2",
          "Fx=-(cos(u+v)/(A+cos(v-u)))",
          "Fy=sin(v-u)/(A+cos(v-u))",
          "Fz=sin(u+v)/(A+cos(v-u))",
          "DFxu= ((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv= ((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu= ((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv= ((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu= ((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv= ((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1= (DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2= (DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3= (DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["-Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["pi"],
        "Vmin": ["0"]
      }
    },

{
    "Iso3D": {
        "Description ": ["HexagramsMenger4 by Abderrahman Taha 12/01/2022"],
        "Name": ["HexagramsMenger4"],
        "Component": ["MengerSponge"],
        "Grid": ["379"],
        "Const": ["th=5/1000"],
        "Funct": [
            "Ax=((abs(x-2/3)<1/81)+(abs(x-20/27)<1/81)+(abs(x-16/27)<1/81)+(abs(x-8/9)<1/81)+(abs(x-26/27)<1/81)+(abs(x-22/27)<1/81)+(abs(x-4/9)<1/81)+(abs(x-14/27)<1/81)+(abs(x-10/27)<1/81)+(abs(x+2/3)<1/81)+(abs(x+16/27)<1/81)+(abs(x+20/27)<1/81)+(abs(x+4/9)<1/81)+(abs(x+10/27)<1/81)+(abs(x+14/27)<1/81)+(abs(x+8/9)<1/81)+(abs(x+22/27)<1/81)+(abs(x+26/27)<1/81)+(abs(x)<1/81)+(abs(x-2/27)<1/81)+(abs(x+2/27)<1/81)+(abs(x-2/9)<1/81)+(abs(x-8/27)<1/81)+(abs(x-4/27)<1/81)+(abs(x+2/9)<1/81)+(abs(x+4/27)<1/81)+(abs(x+8/27)<1/81))",
            "Ay=((abs(y-2/3)<1/81)+(abs(y-20/27)<1/81)+(abs(y-16/27)<1/81)+(abs(y-8/9)<1/81)+(abs(y-26/27)<1/81)+(abs(y-22/27)<1/81)+(abs(y-4/9)<1/81)+(abs(y-14/27)<1/81)+(abs(y-10/27)<1/81)+(abs(y+2/3)<1/81)+(abs(y+16/27)<1/81)+(abs(y+20/27)<1/81)+(abs(y+4/9)<1/81)+(abs(y+10/27)<1/81)+(abs(y+14/27)<1/81)+(abs(y+8/9)<1/81)+(abs(y+22/27)<1/81)+(abs(y+26/27)<1/81)+(abs(y)<1/81)+(abs(y-2/27)<1/81)+(abs(y+2/27)<1/81)+(abs(y-2/9)<1/81)+(abs(y-8/27)<1/81)+(abs(y-4/27)<1/81)+(abs(y+2/9)<1/81)+(abs(y+4/27)<1/81)+(abs(y+8/27)<1/81))",
            "Az=((abs(z-2/3)<1/81)+(abs(z-20/27)<1/81)+(abs(z-16/27)<1/81)+(abs(z-8/9)<1/81)+(abs(z-26/27)<1/81)+(abs(z-22/27)<1/81)+(abs(z-4/9)<1/81)+(abs(z-14/27)<1/81)+(abs(z-10/27)<1/81)+(abs(z+2/3)<1/81)+(abs(z+16/27)<1/81)+(abs(z+20/27)<1/81)+(abs(z+4/9)<1/81)+(abs(z+10/27)<1/81)+(abs(z+14/27)<1/81)+(abs(z+8/9)<1/81)+(abs(z+22/27)<1/81)+(abs(z+26/27)<1/81)+(abs(z)<1/81)+(abs(z-2/27)<1/81)+(abs(z+2/27)<1/81)+(abs(z-2/9)<1/81)+(abs(z-8/27)<1/81)+(abs(z-4/27)<1/81)+(abs(z+2/9)<1/81)+(abs(z+4/27)<1/81)+(abs(z+8/27)<1/81))",
            "Bx=((abs(x-2/3)<1/27)+(abs(x-8/9)<1/27)+(abs(x-4/9)<1/27)+(abs(x+2/3)<1/27)+(abs(x+4/9)<1/27)+(abs(x+8/9)<1/27)+(abs(x)<1/27)+(abs(x-2/9)<1/27)+(abs(x+2/9)<1/27))",
            "By=((abs(y-2/3)<1/27)+(abs(y-8/9)<1/27)+(abs(y-4/9)<1/27)+(abs(y+2/3)<1/27)+(abs(y+4/9)<1/27)+(abs(y+8/9)<1/27)+(abs(y)<1/27)+(abs(y-2/9)<1/27)+(abs(y+2/9)<1/27))",
            "Bz=((abs(z-2/3)<1/27)+(abs(z-8/9)<1/27)+(abs(z-4/9)<1/27)+(abs(z+2/3)<1/27)+(abs(z+4/9)<1/27)+(abs(z+8/9)<1/27)+(abs(z)<1/27)+(abs(z-2/9)<1/27)+(abs(z+2/9)<1/27))",
            "Cx=((abs(x-2/3)<1/9)+(abs(x+2/3)<1/9)+(abs(x)<1/9))",
            "Cy=((abs(y-2/3)<1/9)+(abs(y+2/3)<1/9)+(abs(y)<1/9))",
            "Cz=((abs(z-2/3)<1/9)+(abs(z+2/3)<1/9)+(abs(z)<1/9))",
            "Dx=x^100",
            "Dy=y^100",
            "Dz=z^100"],
        "Fxyz": [
            "if(abs(x+y+z)<th,-(Dx(x,y,z,t)+Dy(x,y,z,t)+Dz(x,y,z,t)-1)*(((abs(x)>1/3|abs(y)>1/3)*(abs(z)>1/3|abs(y)>1/3)*(abs(x)>1/3|abs(z)>1/3))*((Cx(x,y,z,t)*(Cy(x,y,z,t)+Cz(x,y,z,t))+Cz(x,y,z,t)*Cy(x,y,z,t))=0)*((Bx(x,y,z,t)*(By(x,y,z,t)+Bz(x,y,z,t))+Bz(x,y,z,t)*By(x,y,z,t))=0)*((Ax(x,y,z,t)*(Ay(x,y,z,t)+Az(x,y,z,t))+Az(x,y,z,t)*Ay(x,y,z,t))=0)),(0))"],
        "Xmax": ["(1001/1000)"],
        "Xmin": ["-(1001/1000)"],
        "Ymax": ["(1001/1000)"],
        "Ymin": ["-(1001/1000)"],
        "Zmax": ["(1001/1000)"],
        "Zmin": ["-(1001/1000)"]
    }
}
,

    {
        "Iso3D": {
        "Description": ["The Dome by Abderrahman Taha 10/08/2018"],
        "Name": ["The_Dome_v1"],
        "Component": ["The_Dome_01"],
        "Funct": ["Scherk=sinh(x)*sinh(y)-4*sin(z)","Scherk2=Scherk(N*atan2(x,sqrt(y*y+z*z)),(sqrt(x*x+y*y+z*z)-R),N*atan2(z,y),t)","IsoExterior=Scherk2(x,y,z,t)","DFx2=((IsoExterior(x+c,y,z,t)-IsoExterior(x,y,z,t))/c)","DFy2=((IsoExterior(x,y+c,z,t)-IsoExterior(x,y,z,t))/c)","DFz2=((IsoExterior(x,y,z+c,t)-IsoExterior(x,y,z,t))/c)","Rapp=x/sqrt(x*x+y*y+z*z)","Iso3=(IsoExterior(x-Th*Rapp(DFx2(x,y,z,t),DFy2(x,y,z,t),DFz2(x,y,z,t),t),y-Th*Rapp(DFy2(x,y,z,t),DFx2(x,y,z,t),DFz2(x,y,z,t),t),z-Th*Rapp(DFz2(x,y,z,t),DFx2(x,y,z,t),DFy2(x,y,z,t),t),t))","Iso2=(IsoExterior(x+Th*Rapp(DFx2(x,y,z,t),DFy2(x,y,z,t),DFz2(x,y,z,t),t),y+Th*Rapp(DFy2(x,y,z,t),DFx2(x,y,z,t),DFz2(x,y,z,t),t),z+Th*Rapp(DFz2(x,y,z,t),DFx2(x,y,z,t),DFy2(x,y,z,t),t),t))","TickIsoExterior=(Iso2(x,y,z,t)*Iso3(x,y,z,t))"],
        "Fxyz": ["if((sqrt(x*x+y*y+z*z)-24)<(0),TickIsoExterior(z,y,x,t),(1))"],
        "Const": ["c=1/1000","Th=6/10","N=10","R=16"],
        "Xmax": ["27"],
        "Xmin": ["-27"],
        "Ymax": ["27"],
        "Ymin": ["-27"],
        "Zmax": ["18"],
        "Zmin": ["-18"]
        },
        "Sliders": {
        "Max": ["50","50"],
        "Min": ["0","0"],
        "Name": ["N","R"],
        "Position": ["10","16"],
        "Step": ["1","1"]
        },
        "Texture": {
        "Colors": ["R=(7/10)*(cos(x)*cos(y)*cos(z))^(1/10)","G=(7/10)","B=(7/10)","T=1"],
        "Name": "Lines",
        "Noise": ""
        }
    },
    {
      "Iso3D": {
        "Description": ["Wall Pattern Torus by Abderrahman Taha 18/10/2019"],
         "Name": ["Wall_Pattern_Torus_v2"],
        "Component": ["f_hex_y"],
        "Const": ["X=(57/10)"],
        "Funct": ["f_hex_y_1=if(100*abs(z)<(6),f_hex_y(x,y,z,0)-(2/25),1)",
          "Cylinder=-f_hex_y_1(x,(43/10)*atan2(z,y),sqrt(y*y+z*z)-(3/2),t)",
          "Torus=Cylinder(6*atan2(y,x),sqrt(x*x+y*y)-(4),z,t)"],
        "Fxyz": ["Torus(x,y,z,t)"],
        "Xmax": ["X"],
        "Xmin": ["-X"],
        "Ymax": ["X"],
        "Ymin": ["-X"],
        "Zmax": ["8/5"],
        "Zmin": ["-8/5"]
      }
    },
    {
        "Iso3D": {
            "Description": ["Wall Pattern Sphere v3 by Abderrahman Taha 02/11/2019"],
            "Name": ["Wall_Pattern_Sphere_v3"],
            "Component": ["f_hex_y"],
            "Funct": ["f_hex_y_1=if(abs(z)<(3/50),f_hex_y(x,y,z,0)-(2/25),1)",
                "Cylinder=-f_hex_y_1(x,(43/10)*atan2(z,y),sqrt(y*y+z*z)-(3/2),t)",
                "Sphere=f_hex_y_1(4*atan2(x,sqrt(y*y+z*z)),(9/2)*atan2(z,y),sqrt(y*y+z*z+x*x)-(9/2),t)",
                "Torus=Cylinder(8*atan2(y,x),sqrt(x*x+y*y)-(4),z,t)"],
            "Fxyz": ["Sphere(x,y,z,t)"],
            "Xmax": ["24/5"],
            "Xmin": ["-24/5"],
            "Ymax": ["24/5"],
            "Ymin": ["-24/5"],
            "Zmax": ["24/5"],
            "Zmin": ["-24/5"]
        }
    },
    {
      "Iso3D": {
        "Description": ["Wall Pattern Sphere v2 by Abderrahman Taha 02/11/2019"],
        "Name": ["Wall_Pattern_Sphere_v2"],
        "Component": ["f_hex_y"],
        "Funct": ["f_hex_y_1=if(abs(z)<(3/50),f_hex_y(sqrt(x*x+y*y)-(2),(475/100)*atan2(y,x),z,0)-(2/25),1)",
          "Cylinder=-f_hex_y_1(x,(43/10)*atan2(z,y),sqrt(y*y+z*z)-(3/2),t)",
          "Sphere=f_hex_y_1(4*atan2(x,sqrt(y*y+z*z)),(9/2)*atan2(z,y),sqrt(y*y+z*z+x*x)-(9/2),t)",
          "Torus=Cylinder(8*atan2(y,x),sqrt(x*x+y*y)-(4),z,t)"],
        "Fxyz": ["Sphere(x,y,z,t)"],
        "Xmax": ["24/5"],
        "Xmin": ["-24/5"],
        "Ymax": ["24/5"],
        "Ymin": ["-24/5"],
        "Zmax": ["24/5"],
        "Zmin": ["-24/5"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Wall Pattern Sphere (ref: http://www.povray.org/) by Abderrahman Taha 02/11/2019 "],
        "Name": ["Wall_Pattern_Sphere_v1"],
        "Component": ["f_hex_y"],
        "Funct": ["f_hex_y_1=if(z*z-(1/100) < (0),f_hex_y(sin(x),(13/10)*sin(y),2*z,0),1)-(1/10)",
          "Cylinder=-f_hex_y_1(x,(43/10)*atan2(z,y),sqrt(y*y+z*z)-(3/2),t)",
          "Sphere=f_hex_y_1(4*atan2(x,sqrt(y*y+z*z)),(9/2)*atan2(z,y),sqrt(y*y+z*z+x*x)-(9/2),t)",
          "Torus=Cylinder(8*atan2(y,x),sqrt(x*x+y*y)-(4),z,t)"],
        "Fxyz": ["Sphere(x,y,z,t)"],
        "Xmax": ["23/5"],
        "Xmin": ["-23/5"],
        "Ymax": ["23/5"],
        "Ymin": ["-23/5"],
        "Zmax": ["23/5"],
        "Zmin": ["-23/5"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Wall Pattern Torus (ref: http://www.povray.org/) by Abderrahman Taha 02/11/2019"],
        "Name": ["Wall_Pattern_Torus_v1"],
        "Component": ["f_hex_y"],
        "Funct": ["f_hex_y_1=if(z*z-(1/100) < (0),f_hex_y(sin(x),(13/10)*sin(y),2*z,0),1)-(1/10)",
          "Cylinder=-f_hex_y_1(x,(43/10)*atan2(z,y),sqrt(y*y+z*z)-(15/10),t)",
          "Sphere=f_hex_y_1(4*atan2(x,sqrt(y*y+z*z)),(43/10)*atan2(z,y),sqrt(y*y+z*z+x*x)-(9/2),t)",
          "Torus=Cylinder(8*atan2(y,x),sqrt(x*x+y*y)-(4),z,t)"],
        "Fxyz": ["Torus(x,y,z,t)"],
        "Xmax": ["6"],
        "Xmin": ["-6"],
        "Ymax": ["6"],
        "Ymin": ["-6"],
        "Zmax": ["8/5"],
        "Zmin": ["-8/5"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Interlocked Torus (ref:http://www.povray.org/) by Abderrahman Taha 02/11/2019"],
        "Name": ["Interlocked_Torus_v2"],
        "Component": ["InterlockedTorus"],
        "Const": ["A = 4",
          "B = 1",
          "C = 1/2",
          "D = 1",
          "E = 1",
          "F = 1",
          "G = 30"],
        "Funct": ["X = x",
          "Z = z",
          "r = sqrt(X(x,y,z,t)*X(x,y,z,t)+Z(x,y,z,t)*Z(x,y,z,t))",
          "X= if ((X(x,y,z,t) = 0) & (Z(x,y,z,t) = 0),(1/1000),X(x,y,z,t))",
          "th = atan2(Z(x,y,z,t),X(x,y,z,t))",
          "th = ((th(x,y,z,t)*A+y*B*A) % (2*pi))",
          "th = if (th(x,y,z,t) < (0),th(x,y,z,t)+2*pi,th(x,y,z,t))",
          "Z = (th(x,y,z,t)-pi)/E/(B*A)",
          "X = r(x,y,z,t)-D",
          "Z = if ((F = 1 | G = 0)=(0),X(x,y,z,t)*sin(G*pi/180)+Z(x,y,z,t)*cos(G*pi/180),Z(x,y,z,t))",
          "X = if ((F = 1 | G = 0)=(0),X(x,y,z,t)*cos(G*pi/180)-Z(x,y,z,t)*sin(G*pi/180),X(x,y,z,t))",
          "r2 = if (F = (1),      sqrt(X(x,y,z,t)*X(x,y,z,t)+Z(x,y,z,t)*Z(x,y,z,t)),if ((F = 0)=(0),(((((abs(X(x,y,z,t)))^(2/F))+((abs(Z(x,y,z,t)))^(2/F))))^(F/2)),if (abs(X(x,y,z,t)) > abs(Z(x,y,z,t)),abs(X(x,y,z,t)),abs(Z(x,y,z,t)))))",
          "r3 = if((D+r(x,y,z,t)) < r2(x,y,z,t),(D+r(x,y,z,t)),r2(x,y,z,t))",
          "helix = (-C+r3(x,y,z,t))"],
        "Fxyz": ["-helix(sqrt(x*x+y*y)-(3),2*atan2(y,x),z,t)"],
        "Xmax": ["5"],
        "Xmin": ["-5"],
        "Ymax": ["5"],
        "Ymin": ["-5"],
        "Zmax": ["2"],
        "Zmin": ["-2"]
      },
      "Texture": {
        "Colors": ["R=(9/10)",
          "G=(4/5)*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))+(3/10)",
          "B=(4/5)*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(2*x,2*y,2*z,(4),(2),(0))+NoiseP(2*x,2*y,2*z,(4),(12),(1/10))"
      }
    },
    {
      "Iso3D": {
        "Description": ["Perlin Schwarz  by Abderrahman Taha 02/11/2019"],
        "Name": ["Perlin_Schwarz"],
        "Component": ["PerlinSchwarz"],
        "Funct": ["Schwarz=cos(x)+cos(y)+cos(z)"],
        "Fxyz": ["Schwarz(x,y,z,t)-NoiseP(x,y,z,(4),(11),(1/10))"],
        "Xmax": ["4"],
        "Xmin": ["-4"],
        "Ymax": ["4"],
        "Ymin": ["-4"],
        "Zmax": ["4"],
        "Zmin": ["-4"]
      },
      "Texture": {
        "Colors": ["R=4/5",
          "G=(8/5)*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "B=(9/5)*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"],
        "Name": "Perlin",
        "Noise": "NoiseP(x,y,z,(4),(11),(1/10))"
      }
    },
    {
      "Iso3D": {
        "Description": ["Wired Torus (ref: http://www.povray.org/) by Abderrahman Taha 26/12/2019"],
        "Name": ["Wired_Torus_v1"],
        "Component": ["WiredTorus"],
        "Const": ["A=1/5","B=1/5","C=1","D=1/25","E=1","th=pi/A","ph=pi/B"],
        "Funct": ["r=(x%(A*2))",
          "r=abs(if(r(x,y,z,t)<(0),r(x,y,z,t)+A,r(x,y,z,t)-A))*C",
          "r2=(y-cos(z*ph)*D)*E",
          "temp=-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t))",
          "r=((x-A)%(A*2))",
          "r=abs(if(r(x,y,z,t)<(0),r(x,y,z,t)+A,r(x,y,z,t)-A))*C",
          "r2=(y+cos(z*ph)*D)*E",
          "temp=max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t))",
          "r=(z%(B*2))",
          "r=abs(if(r(x,y,z,t)<(0),r(x,y,z,t)+B,r(x,y,z,t)-B))*C",
          "r2=(y+cos(x*th)*D)*E",
          "temp=max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t))",
          "r=((z-B)%(B*2))",
          "r=abs(if(r(x,y,z,t)<(0),r(x,y,z,t)+B,r(x,y,z,t)-B))*C",
          "r2=(y-cos(x*th)*D)*E",
          "fmesh0=(-max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t)))",
          "fmesh1=-fmesh0(atan2(y,x),sqrt(x*x+y*y)-(1),z,t)+(3/100)",
          "fmesh2=fmesh1(sqrt(x*x+z*z)-(2),y,atan2(z,x),t)"],
        "Fxyz": ["fmesh2(x,y,z,t)"],
        "Xmax": ["31/10"],
        "Xmin": ["-31/10"],
        "Ymax": ["11/10"],
        "Ymin": ["-11/10"],
        "Zmax": ["31/10"],
        "Zmin": ["-31/10"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Wired Sphere-01 (ref: http://www.povray.org/) by Abderrahman Taha 02/11/2019"],
        "Name": ["Wired_Sphere_v1"],
        "Component": ["WiredSphere"],
        "Const": ["A = 3/20",
          "B = 3/20",
          "C = 1",
          "D = 1/50",
          "E = 1",
          "th = pi/A",
          "ph = pi/B"],
        "Funct": ["r = (x % (A*2))",
          "r = abs(if (r(x,y,z,t) < (0),r(x,y,z,t)+A,r(x,y,z,t)-A))*C",
          "r2 = (y-cos(z*ph)*D)*E",
          "temp =-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t))",
          "r = ((x-A) % (A*2))",
          "r = abs(if (r(x,y,z,t) < (0),r(x,y,z,t)+A,r(x,y,z,t)-A))*C",
          "r2 = (y+cos(z*ph)*D)*E",
          "temp = max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t))",
          "r = (z % (B*2))",
          "r = abs(if (r(x,y,z,t) < (0),r(x,y,z,t)+B,r(x,y,z,t)-B))*C",
          "r2 = (y+cos(x*th)*D)*E",
          "temp = max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t))",
          "r = ((z-B) % (B*2))",
          "r = abs(if (r(x,y,z,t) < (0),r(x,y,z,t)+B,r(x,y,z,t)-B))*C",
          "r2 = (y-cos(x*th)*D)*E",
          "fmesh0 = max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t))+(3/100)",
          "fmesh0= fmesh0(atan2(y,x),sqrt(x*x+y*y+z*z)-(1),atan2(z,sqrt(x*x+y*y)),t)"],
        "Fxyz": ["fmesh0(x,y,z,t)"],
        "Xmax": ["11/10"],
        "Xmin": ["-11/10"],
        "Ymax": ["11/10"],
        "Ymin": ["-11/10"],
        "Zmax": ["11/10"],
        "Zmin": ["-11/10"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Straw Basket (ref : http://www.povray.org/) by Abderrahman Taha 02/11/2019"],
        "Name": ["Straw_Basket_v1"],
        "Component": ["StrawBasket"],
        "Const": ["A = 1/2",
          "B = 1/5",
          "C = 1",
          "D = 9/100",
          "E = 1",
          "th = pi/A",
          "ph = pi/B"],
        "Funct": ["r = (x % (A*2))",
          "r = abs(if (r(x,y,z,t) < (0),r(x,y,z,t)+A,r(x,y,z,t)-A))*C",
          "r2 = (y-cos(z*ph)*D)*E",
          "temp =-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t))",
          "r = ((x-A) % (A*2))",
          "r = abs(if (r(x,y,z,t) < (0),r(x,y,z,t)+A,r(x,y,z,t)-A))*C",
          "r2 = (y+cos(z*ph)*D)*E",
          "temp =   max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t))",
          "r = (z % (B*2))",
          "r = abs(if (r(x,y,z,t) < (0),r(x,y,z,t)+B,r(x,y,z,t)-B))*C",
          "r2 = (y+cos(x*th)*D)*E",
          "temp = max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t))",
          "r = ((z-B) % (B*2))",
          "r = abs(if (r(x,y,z,t) < (0),r(x,y,z,t)+B,r(x,y,z,t)-B))*C",
          "r2 = (y-cos(x*th)*D)*E",
          "fmesh0 = max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t))+(2/25)",
          "fmesh0= if(atan2(z,sqrt(x*x+y*y)) < (9/10),fmesh0(atan2(y,x),sqrt(x*x+y*y+z*z)-(4),atan2(z,sqrt(x*x+y*y)),t),1)*(atan2(z,sqrt(x*x+y*y)) < (9/10))"],
        "Fxyz": ["fmesh0(x,y,z,t)"],
        "Xmax": ["5"],
        "Xmin": ["-5"],
        "Ymax": ["5"],
        "Ymin": ["-5"],
        "Zmax": ["5"],
        "Zmin": ["-5"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Mesh Torus (reference : http://www.povray.org/) by Abderrahman Taha 02/11/2019   "],
        "Name": ["Mesh_Torus_01"],
        "Component": ["MeshTorus"],
        "Const": ["A = 1/2",
          "B = 7/20",
          "C = 7/10",
          "D = 1/5",
          "E = 1/2",
          "th = pi/A",
          "ph = pi/B"],
        "Funct": ["r = (x % (A*2))",
          "r = abs(if (r(x,y,z,t) < (0),r(x,y,z,t)+A,r(x,y,z,t)-A))*C",
          "r2 = (y-cos(z*ph)*D)*E",
          "temp =-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t))",
          "r = ((x-A) % (A*2))",
          "r = abs(if (r(x,y,z,t) < (0),r(x,y,z,t)+A,r(x,y,z,t)-A))*C",
          "r2 = (y+cos(z*ph)*D)*E",
          "temp =   max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t))",
          "r = (z % (B*2))",
          "r = abs(if (r(x,y,z,t) < (0),r(x,y,z,t)+B,r(x,y,z,t)-B))*C",
          "r2 = (y+cos(x*th)*D)*E",
          "temp = max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t))",
          "r = ((z-B) % (B*2))",
          "r = abs(if (r(x,y,z,t) < (0),r(x,y,z,t)+B,r(x,y,z,t)-B))*C",
          "r2 = (y-cos(x*th)*D)*E",
          "fmesh0 = (-max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t)))",
          "fmesh1=-fmesh0(atan2(y,x),sqrt(x*x+y*y)-(4),z,t)+2/25",
          "fmesh2= fmesh1(sqrt(x*x+z*z)-(7),y,2*atan2(z,x),t)"],
        "Fxyz": [" fmesh2(x,y,z,t)"],
        "Xmax": ["12"],
        "Xmin": ["-12"],
        "Ymax": ["5"],
        "Ymin": ["-5"],
        "Zmax": ["12"],
        "Zmin": ["-12"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Bottle shape surface by Robert Israel 01/11/2019"],
        "Name": ["Bottle shape"],
        "Component": ["Bottle shape"],
        "Fx": ["(-2/15)*(cos(u)*(3*cos(v)-30*sin(u)+90*cos(u)^4*sin(u)-60*cos(u)^6*sin(u)+5*cos(u)*cos(v)*sin(u))) "],
        "Fy": ["(-1/15)*sin(u)*(3*cos(v)-3*cos(u)^2*cos(v)-48*cos(u)^4*cos(v)+48*cos(u)^6*cos(v)-60*sin(u)+5*cos(u)*cos(v)*sin(u)-5*cos(u)^3*cos(v)*sin(u)-80*cos(u)^5*cos(v)*sin(u)+80*cos(u)^7*cos(v)*sin(u)) "],
        "Fz": ["(2/15)*(3+5*cos(u)*sin(u))*sin(v) "],
        "Umax": ["pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Texture": {
        "Colors": ["R=(9/10)",
          "G=(4/5)*abs(cos((pi*(x*x+y*y+z*z))))",
          "B=(3/5)*abs(cos(cos(pi*(x*x+y*y+z*z))))",
          "T=1"],
        "Name": "Dream",
        "Noise": "NoiseW(2*x,2*y,2*z,(8),(1),(0))"
      }
    },
    {
      "Param3D": {
        "Description ": ["Richmond Polar_2  parametric surface by Abderrahman Taha 01/11/2019"],
        "Name": ["Richmond_Polar_2"],
        "Component": ["RichmondPolar"],
        "Fx": ["-cos(v)/(2*u)-u^3*cos(3*v)/6"],
        "Fy": ["-sin(v)/(2*u)+u^3*sin(3*v)/6"],
        "Fz": ["u*cos(v)*sin(v)"],
        "Umax": ["13/10"],
        "Umin": ["3/10"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Texture": {
        "Colors": ["R=9/10",
          "G=(4/5)*abs(cos((pi*(x*x+y*y+z*z))))",
          "B=(3/5)*abs(cos(cos(pi*(x*x+y*y+z*z))))",
          "T=1"],
        "Name": "Dream",
        "Noise": "NoiseW(4*x,4*y,4*z,(8),(1),(0))"
      }
    },
    {
      "Iso3D": {
        "Description ": ["HexaGrid Torus by Aberrahman Taha 01/11/2019. Origin: Gerd Platl"],
        "Name": ["HexaGrid_Torus_02"],
        "Component": ["HexaGrid Torus"],
        "Const": ["N=3"],
        "Funct": ["HexaGrid=-(11/20)-88*(sqrt(x*x+y*y)-2)^2-cos(8*z)-cos(14*atan2(y,x)-4*z)-cos(14*atan2(y,x)+4*z)-(3/5)*(cos(28*atan2(y,x))+cos(12*z-14*atan2(y,x))+cos(12*z+14*atan2(y,x)))"],
        "Fxyz": ["HexaGrid((sqrt(x*x+z*z)-4),y,N*atan2(z,x),t)"],
        "Xmax": ["31/5"],
        "Xmin": ["-31/5 "],
        "Ymax": ["9/2"],
        "Ymin": ["-9/2"],
        "Zmax": ["31/5"],
        "Zmin": ["-31/5"]
      }
    },
    {
      "Iso3D": {
        "Description ": ["HexaGrid Torus by Aberrahman Taha 01/11/2019. Origin: Gerd Platl "],
        "Name": ["HexaGrid_Torus_01"],
        "Component": ["HexaGrid_Torus"],
        "Funct": ["HexaGrid=-(1/2)-88*(sqrt(x*x+y*y)-2)^2-cos(8*z)-cos(14*atan2(y,x)-4*z)-cos(14*atan2(y,x)+4*z)-(3/25)*(cos(28*atan2(y,x))+cos(12*z-14*atan2(y,x))+cos(12*z+14*atan2(y,x)))"],
        "Fxyz": ["HexaGrid((sqrt(x*x+z*z)-4),y,3*atan2(z,x),t)"],
        "Xmax": ["31/5"],
        "Xmin": ["-31/5 "],
        "Ymax": ["9/2"],
        "Ymin": ["-9/2"],
        "Zmax": ["31/5"],
        "Zmin": ["-31/5"]
      }
    },
    {
        "Iso3D": {
            "Description": ["Menger L4 SchwarzP by Abderrahman Taha 01/11/2019"],
            "Name": ["Menger_4_SchwarzP"],
            "Component": ["MengerSchwarzP"],
            "Const": ["c1=254469/1000","c2=2/1000","c3=3333/10000","c4=10005/10000"],
            "Funct": ["Ax = ((abs(x-2/3) <1/81)+(abs(x-20/27) <1/81)+(abs(x-16/27) <1/81)+(abs(x-8/9) <1/81)+(abs(x-26/27) <1/81)+(abs(x-22/27) <1/81)+(abs(x-4/9) <1/81)+(abs(x-14/27) <1/81)+(abs(x-10/27) <1/81)+(abs(x+2/3) <1/81)+(abs(x+16/27) <1/81)+(abs(x+20/27) <1/81)+(abs(x+4/9) <1/81)+(abs(x+10/27) <1/81)+(abs(x+14/27) <1/81)+(abs(x+8/9) <1/81)+(abs(x+22/27) <1/81)+(abs(x+26/27) <1/81)+(abs(x) <1/81)+(abs(x-2/27) <1/81)+(abs(x+2/27) <1/81)+(abs(x-2/9) <1/81)+(abs(x-8/27) <1/81)+(abs(x-4/27) <1/81)+(abs(x+2/9) <1/81)+(abs(x+4/27) <1/81)+(abs(x+8/27) <1/81))",
                "Ay = ((abs(y-2/3) <1/81)+(abs(y-20/27) <1/81)+(abs(y-16/27) <1/81)+(abs(y-8/9) <1/81)+(abs(y-26/27) <1/81)+(abs(y-22/27) <1/81)+(abs(y-4/9) <1/81)+(abs(y-14/27) <1/81)+(abs(y-10/27) <1/81)+(abs(y+2/3) <1/81)+(abs(y+16/27) <1/81)+(abs(y+20/27) <1/81)+(abs(y+4/9) <1/81)+(abs(y+10/27) <1/81)+(abs(y+14/27) <1/81)+(abs(y+8/9) <1/81)+(abs(y+22/27) <1/81)+(abs(y+26/27) <1/81)+(abs(y) <1/81)+(abs(y-2/27) <1/81)+(abs(y+2/27) <1/81)+(abs(y-2/9) <1/81)+(abs(y-8/27) <1/81)+(abs(y-4/27) <1/81)+(abs(y+2/9) <1/81)+(abs(y+4/27) <1/81)+(abs(y+8/27) <1/81))",
                "Az = ((abs(z-2/3) <1/81)+(abs(z-20/27) <1/81)+(abs(z-16/27) <1/81)+(abs(z-8/9) <1/81)+(abs(z-26/27) <1/81)+(abs(z-22/27) <1/81)+(abs(z-4/9) <1/81)+(abs(z-14/27) <1/81)+(abs(z-10/27) <1/81)+(abs(z+2/3) <1/81)+(abs(z+16/27) <1/81)+(abs(z+20/27) <1/81)+(abs(z+4/9) <1/81)+(abs(z+10/27) <1/81)+(abs(z+14/27) <1/81)+(abs(z+8/9) <1/81)+(abs(z+22/27) <1/81)+(abs(z+26/27) <1/81)+(abs(z) <1/81)+(abs(z-2/27) <1/81)+(abs(z+2/27) <1/81)+(abs(z-2/9) <1/81)+(abs(z-8/27) <1/81)+(abs(z-4/27) <1/81)+(abs(z+2/9) <1/81)+(abs(z+4/27) <1/81)+(abs(z+8/27) <1/81))",
                "Bx = ((abs(x-2/3) <1/27)+(abs(x-8/9) <1/27)+(abs(x-4/9) <1/27)+(abs(x+2/3) <1/27)+(abs(x+4/9) <1/27)+(abs(x+8/9) <1/27)+(abs(x) <1/27)+(abs(x-2/9) <1/27)+(abs(x+2/9) <1/27))",
                "By = ((abs(y-2/3) <1/27)+(abs(y-8/9) <1/27)+(abs(y-4/9) <1/27)+(abs(y+2/3) <1/27)+(abs(y+4/9) <1/27)+(abs(y+8/9) <1/27)+(abs(y) <1/27)+(abs(y-2/9) <1/27)+(abs(y+2/9) <1/27))",
                "Bz = ((abs(z-2/3) <1/27)+(abs(z-8/9) <1/27)+(abs(z-4/9) <1/27)+(abs(z+2/3) <1/27)+(abs(z+4/9) <1/27)+(abs(z+8/9) <1/27)+(abs(z) <1/27)+(abs(z-2/9) <1/27)+(abs(z+2/9) <1/27))",
                "Cx = ((abs(x-2/3) <1/9)+(abs(x+2/3) <1/9)+(abs(x) <1/9))",
                "Cy = ((abs(y-2/3) <1/9)+(abs(y+2/3) <1/9)+(abs(y) <1/9))",
                "Cz = ((abs(z-2/3) <1/9)+(abs(z+2/3) <1/9)+(abs(z) <1/9))",
                "Dx = x^600",
                "Dy = y^600",
                "Dz = z^600",
                "Ex=sin(c1*x)",
                "Ey=sin(c1*y)",
                "Ez=sin(c1*z)"],
            "Fxyz": ["if(-(Dx(x,y,z,t)+Dy(x,y,z,t)+Dz(x,y,z,t)-(102/100))*(((abs(x)>1/3|abs(y)>1/3)*(abs(z)>1/3|abs(y)>1/3)*(abs(x)>1/3|abs(z)>1/3))*((Cx(x,y,z,t)*(Cy(x,y,z,t)+Cz(x,y,z,t))+Cz(x,y,z,t)*Cy(x,y,z,t))=0)*((Bx(x,y,z,t)*(By(x,y,z,t)+Bz(x,y,z,t))+Bz(x,y,z,t)*By(x,y,z,t))=0)*((Ax(x,y,z,t)*(Ay(x,y,z,t)+Az(x,y,z,t))+Az(x,y,z,t)*Ay(x,y,z,t))=0)),(cos(c1*(x+Ex(x,y,z,t)*c2/sqrt(Ex(x,y,z,t)*Ex(x,y,z,t)+Ey(x,y,z,t)*Ey(x,y,z,t)+Ez(x,y,z,t)*Ez(x,y,z,t))))+cos(c1*(y+Ey(x,y,z,t)*c2/sqrt(Ex(x,y,z,t)*Ex(x,y,z,t)+Ey(x,y,z,t)*Ey(x,y,z,t)+Ez(x,y,z,t)*Ez(x,y,z,t))))+cos(c1*(z+Ez(x,y,z,t)*c2/sqrt(Ex(x,y,z,t)*Ex(x,y,z,t)+Ey(x,y,z,t)*Ey(x,y,z,t)+Ez(x,y,z,t)*Ez(x,y,z,t)))))*(cos(c1*(x-Ex(x,y,z,t)*c2/sqrt(Ex(x,y,z,t)*Ex(x,y,z,t)+Ey(x,y,z,t)*Ey(x,y,z,t)+Ez(x,y,z,t)*Ez(x,y,z,t))))+cos(c1*(y-Ey(x,y,z,t)*c2/sqrt(Ex(x,y,z,t)*Ex(x,y,z,t)+Ey(x,y,z,t)*Ey(x,y,z,t)+Ez(x,y,z,t)*Ez(x,y,z,t))))+cos(c1*(z-Ez(x,y,z,t)*c2/sqrt(Ex(x,y,z,t)*Ex(x,y,z,t)+Ey(x,y,z,t)*Ey(x,y,z,t)+Ez(x,y,z,t)*Ez(x,y,z,t))))),1)"],
            "Xmax": ["c4"],
            "Xmin": ["c3"],
            "Ymax": ["c4"],
            "Ymin": ["c3"],
            "Zmax": ["c4"],
            "Zmin": ["c3"]
        },
        "Texture": {
            "Colors": ["R=(6/10)*sqrt(4*x^40+y^4+z^4)",
                "G=(3/10)*sqrt(x^4+y^4+4*z^20)",
                "B=(4/10)*sqrt(x^4+4*y^20+z^4)",
                "T=1"],
            "Name": "ll",
            "Noise": "1"
        }
    },
    {
      "Iso3D": {
        "Description": ["Skeletal SchwarzP Tori by Abderrahman Taha 01/11/2019"],
        "Name": ["Skeletal_SchwarzP_Tori"],
        "Component": ["SkeletalSchwarzPTori"],
        "Const": ["M=1/10","N=15","Th=6/5","S=5"],
        "Funct": ["Iso=cos(x)+cos(y)+cos(z)",
          "Rap=x/sqrt(x*x+y*y+z*z)",
          "SchwarzP=-(Iso(x-Th*Rap(sin(x),sin(y),sin(z),t),y-Th*Rap(sin(y),sin(z),sin(x),t),z-Th*Rap(sin(z),sin(x),sin(y),t),t))",
          "isoCondition_0=((x-S)^2-(12/5)^2)",
          "isoCondition_1=((x-S)^2-(7/5)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),-SchwarzP(x,y,z,-1),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"],
        "Xmax": ["30"],
        "Xmin": ["-30"],
        "Ymax": ["30"],
        "Ymin": ["-30"],
        "Zmax": ["15"],
        "Zmin": ["-15"]
      }
    },
    {
      "Iso3D": {
        "Description": ["G_Skeletal Tori by Abderrahman Taha 01/11/2019"],
        "Name": ["GSkeletal_Tori"],
        "Component": ["GSkeletalTori"],
        "Const": ["M=4","N=10","P=2/5"],
        "Funct": ["G_Skeletal =cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)+(4/25)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+1",
          "isoCondition_0=((x-pi)^2-(pi-P+3/10)^2)",
          "isoCondition_1=((x-pi)^2-(pi-P)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),G_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"],
        "Xmax": ["30"],
        "Xmin": ["-30"],
        "Ymax": ["30"],
        "Ymin": ["-30"],
        "Zmax": ["15"],
        "Zmin": ["-15"]
      }
    },
    {
      "Iso3D": {
        "Description": ["DSkeletal Tori by Abderrahman Taha 01/11/2019"],
        "Name": ["DSkeletal_Tori"],
        "Component": ["DSkeletalTori"],
        "Const": ["M=4","N=8","P=3/10"],
        "Funct": ["D_Skeletal =sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)-(7/100)*(cos(4*x)+cos(4*y)+cos(4*z))+4/5",
          "isoCondition_0=((x-pi)^2-(pi-P+1/100)^2)",
          "isoCondition_1=((x-pi)^2-(pi-P)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),D_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"],
        "Xmax": ["30"],
        "Xmin": ["-30"],
        "Ymax": ["30"],
        "Ymin": ["-30"],
        "Zmax": ["15"],
        "Zmin": ["-15"]
      }
    },
    {
      "Iso3D": {
        "Description": ["DSkeletal Sphere by Abderrahman Taha 01/11/2019"],
        "Name": ["DSkeletal_Sphere"],
        "Component": ["DSkeletalSphere"],
        "Const": ["M=4","N=8","P=3/10"],
        "Funct": ["D_Skeletal =sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)-(7/100)*(cos(4*x)+cos(4*y)+cos(4*z))+95/100",
          "isoCondition_0=((x-pi)^2-(pi-P+1/100)^2)",
          "isoCondition_1=((x-pi)^2-(pi-P)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),D_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),N*pi*atan2(y,sqrt(x*x+z*z)),N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2(x,y,z,t)"],
        "Xmax": ["19"],
        "Xmin": ["-19"],
        "Ymax": ["19"],
        "Ymin": ["-19"],
        "Zmax": ["19"],
        "Zmin": ["-19"]
      }
    },
    {
      "Iso3D": {
        "Description": ["W_Skeletal Cylinder by Abderrahman Taha 01/11/2019"],
        "Name": ["W_Skeletal_Cylinder"],
        "Component": ["W_SkeletalCylinder"],
        "Const": ["M=1","N=8","P=4"],
        "Funct": ["W_Skeletal=cos(2*x)+cos(2*y)+cos(2*z)-2*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+25/10",
          "isoCondition_0=(x^2-(pi+1/2)^2)",
          "isoCondition_1=(x^2-(pi+3/10)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),W_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2(x,y,z,t)"],
        "Xmax": ["11"],
        "Xmin": ["-11"],
        "Ymax": ["26"],
        "Ymin": ["-26"],
        "Zmax": ["11"],
        "Zmin": ["-11"]
      }
    },
    {
      "Iso3D": {
        "Description": ["W_Skeletal Tori by Abderrahman Taha 01/11/2019"],
        "Name": ["W_Skeletal_Tori"],
        "Component": ["W_SkeletalTori"],
        "Const": ["M=1","N=8"],
        "Funct": ["W_Skeletal=cos(2*x)+cos(2*y)+cos(2*z)-2*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+25/10",
          "isoCondition_0=(x^2-(pi+1/2)^2)",
          "isoCondition_1=(x^2-(pi+3/10)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),W_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"],
        "Xmax": ["26"],
        "Xmin": ["-26"],
        "Ymax": ["26"],
        "Ymin": ["-26"],
        "Zmax": ["12"],
        "Zmin": ["-12"]
      }
    },
    {
      "Iso3D": {
        "Description": ["W_Skeletal Sphere by Abderrahman Taha 01/11/2019"],
        "Name": ["W_Skeletal Sphere"],
        "Component": ["W_Skeletal Sphere"],
        "Const": ["M=1","N=10","P=7"],
        "Funct": ["W_Skeletal=cos(2*x)+cos(2*y)+cos(2*z)-2*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+25/10",
          "isoCondition_0=(x^2-(pi+1/2)^2)",
          "isoCondition_1=(x^2-(pi+3/10)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),W_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),P*pi*atan2(y,sqrt(x*x+z*z)),N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2(x,y,z,t)"],
        "Xmax": ["16"],
        "Xmin": ["-16"],
        "Ymax": ["16"],
        "Ymin": ["-16"],
        "Zmax": ["17"],
        "Zmin": ["-17"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Diamond Sphere by Abderrahman Taha 01/11/2019"],
        "Name": ["Diamond_Sphere"],
        "Component": ["DiamondSphere"],
        "Const": ["N=8","M=4"],
        "Funct": ["Diamond =sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
          "isoCondition_0=(x^2-(11/5)^2)",
          "isoCondition_1=(x^2-2^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),Diamond(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),N*pi*atan2(y,sqrt(x*x+z*z)),N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2(x,y,z,t)"],
        "Xmax": ["15"],
        "Xmin": ["-15"],
        "Ymax": ["15"],
        "Ymin": ["-15"],
        "Zmax": ["15"],
        "Zmin": ["-15"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Neovius Sphere by Abderrahman Taha 01/11/2019"],
        "Name": ["Neovius_Sphere"],
        "Const": ["N=10","M=4"],
        "Component": ["NeoviusSphere"],
        "Funct": ["Neovius =3*(cos(x)+cos(y)+cos(z))+7*cos(x)*cos(y)*cos(z)",
          "isoCondition_0=(x^2-(11/5)^2)",
          "isoCondition_1=(x^2-(8/5)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),Neovius(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),10*pi*atan2(y,sqrt(x*x+z*z)),N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2(x,y,z,t)"],
        "Xmax": ["15"],
        "Xmin": ["-15"],
        "Ymax": ["15"],
        "Ymin": ["-15"],
        "Zmax": ["15"],
        "Zmin": ["-15"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Neovius Tori by Abderrahman Taha 31/10/2019"],
        "Name": ["Neovius_Tori"],
        "Component": ["NeoviusTori"],
        "Const": ["M=1","N=10"],
        "Funct": ["Neovius=3*(cos(x)+cos(y)+cos(z))+7*cos(x)*cos(y)*cos(z)",
          "isoCondition_0=(x^2-(12/5)^2)",
          "isoCondition_1=(x^2-(8/5)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),Neovius(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"],
        "Xmax": ["25"],
        "Xmin": ["-25"],
        "Ymax": ["25"],
        "Ymin": ["-25"],
        "Zmax": ["21/2"],
        "Zmin": ["-21/2"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Sleeping bugs by Abderrahman Taha 31/10/2019"],
        "Name": ["Sleeping_bugs"],
        "Component": ["SleepingBugs"],
        "Const": ["c=1/10000","N=3","A=sqrt(2)"],
        "Funct": ["Th= (2/5)*(-(1/2)*(abs(sin(15*u)*cos(15*v)))^9+(7/20)*((sin(2*N*u))))",
          "Fx=-cos(u+v)/(A+cos(v-u))",
          "Fy=sin(v-u)/(A+cos(v-u))",
          "Fz=sin(u+v)/(A+cos(v-u))",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Texture": {
        "Colors": ["R=(9/10)",
          "G=(4/5)*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))+(3/10)",
          "B=(4/5)*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(2*x,2*y,2*z,(4),(2),0)+NoiseP(2*x,2*y,2*z,(4),(12),(1/10))"
      }
    },
    {
      "Iso3D": {
        "Description": ["Gyroidal Tori by Abderrahman Taha 31/10/2019"],
        "Name": ["Gyroidal_Tori_v0"],
        "Component": ["GyroidalTori"],
        "Const": ["N=10"],
        "Funct": ["Gyroid=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "isoCondition_0=(x^2-(11/5)^2)",
          "isoCondition_1=(x^2-(8/5)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),Gyroid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"],
        "Xmax": ["25"],
        "Xmin": ["-25"],
        "Ymax": ["25"],
        "Ymin": ["-25"],
        "Zmax": ["21/2"],
        "Zmin": ["-21/2"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Gyroid Sphere by Abderrahman Taha 31/10/2019"],
        "Name": ["Gyroid_Sphere"],
        "Component": ["GyroidSphere"],
        "Const": ["N=12"],
        "Funct": ["Gyroid=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "isoCondition_0=(x^2-(11/5)^2)",
          "isoCondition_1=(x^2-(8/5)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),Gyroid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),10*pi*atan2(y,sqrt(x*x+z*z)),N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2(x,y,z,t)"],
        "Xmax": ["15"],
        "Xmin": ["-15"],
        "Ymax": ["15"],
        "Ymin": ["-15"],
        "Zmax": ["15"],
        "Zmin": ["-15"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Schwarz Cylinder by Abderrahman Taha 31/10/2019"],
        "Name": ["Schwarz_Cylinder"],
        "Component": ["SchwarzCylinder"],
        "Const": ["N=8"],
        "Funct": ["Schwarz=cos(x)+cos(y)+cos(z)",
          "isoCondition_0=(x^2-(16/5)^2)",
          "isoCondition_1=(x^2-(13/5)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),-Schwarz(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-12),y,N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2(x,y,z,t)"],
        "Xmax": ["15"],
        "Xmin": ["-15"],
        "Ymax": ["25"],
        "Ymin": ["-25"],
        "Zmax": ["15"],
        "Zmin": ["-15"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Lidinoid Sphere by Abderrahman Taha 31/10/2019"],
        "Name": ["Lidinoid_Sphere"],
        "Component": ["LidinoidSphere"],
        "Const": ["N=8"],
        "Funct": ["Lidinoid=((1/2)*(sin(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*sin(x)+sin(2*z)*cos(x)*sin(y))-(1/2)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+(15/100))",
          "isoCondition_0=(x^2-(13/5)^2)",
          "isoCondition_1=(x^2-(12/5)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),-Lidinoid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-12),10*atan2(y,sqrt(x*x+z*z)),N*atan2(z,x),t)",
          "isoTransform3=-isoTransform((sqrt(x*x+y*y+z*z)-12),y,N*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2(x,y,z,t)"],
        "Xmax": ["15"],
        "Xmin": ["-15"],
        "Ymax": ["15"],
        "Ymin": ["-15"],
        "Zmax": ["15"],
        "Zmin": ["-15"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Lidinoid Torus by Abderrahman Taha 31/10/2019"],
        "Name": ["Lidinoid_Torus"],
        "Component": ["NeoviusTorus"],
        "Const": ["N=8"],
        "Funct": ["Lidinoid=((1/2)*(sin(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*sin(x)+sin(2*z)*cos(x)*sin(y))-(1/2)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+3/20)",
          "isoCondition_0=(x^2+z^2-(13/5)^2)",
          "isoCondition_1=(x^2+z^2-(12/5)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),-Lidinoid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))"],
        "Fxyz": ["isoTransform((sqrt(x*x+y*y)-7),N*atan2(y,x),z,t)"],
        "Xmax": ["10"],
        "Xmin": ["-10"],
        "Ymax": ["10"],
        "Ymin": ["-10"],
        "Zmax": ["25/10"],
        "Zmin": ["-25/10"]
      }
    },
    {
      "Param4D": {
        "Name": ["4D Tube"],
        "Description": ["4D Tube by Abderrahman Taha 31/10/2019"],
        "Component": ["4DTube"],
        "Fw": ["(3/10)*(sin(v)+cos(4*u))"],
        "Fx": ["cos(u)"],
        "Fy": ["sin(u)"],
        "Fz": ["(3/10)*(cos(v)+sin(4*u))"],
        "Umax": ["pi"],
        "Umin": ["-pi"],
        "Vmax": ["pi"],
        "Vmin": ["-pi"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Double Twist Neovius Torus by Abderrahman Taha 31/10/2019"],
        "Name": ["Double_Twist_Neovius_Torus"],
        "Component": ["Neovius Torus"],
        "Funct": ["Iso=3*(cos(x)+cos(y)+cos(z))+4*cos(x)*cos(y)*cos(z)",
          "isoCondition_0=(x^2+(z/9)^2-(32/10)^2)",
          "isoCondition_1=(x^2+(z/9)^2-3^2)",
          "isoTransform_1=if(isoCondition_0(x,y,z,t)<(0),Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform_2=if(isoCondition_0(x,y,z,t)<(0),-Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform_3 = isoTransform_2((sqrt(x*x+y*y)-3),atan2(y,x),z,t)"],
        "Fxyz": ["isoTransform_3(x,(sqrt(y*y+z*z)-8),3*atan2(z,y),t)"],
        "Xmax": ["6"],
        "Xmin": ["-6"],
        "Ymax": ["14"],
        "Ymin": ["-14"],
        "Zmax": ["14"],
        "Zmin": ["-14"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Neovius Torus_1 by Abderrahman Taha 31/10/2019"],
        "Name": ["Neovius_Torus"],
        "Component": ["Neovius_Torus"],
        "Const": ["N=12"],
        "Funct": ["Iso=3*(cos(x)+cos(y)+cos(z))+4*cos(x)*cos(y)*cos(z)",
          "isoCondition_0=(x^2+z^2-(16/5)^2)",
          "isoCondition_1=(x^2+z^2-3^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<(0),-Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))"],
        "Fxyz": ["isoTransform((sqrt(x*x+y*y)-7),N*atan2(y,x),z,t)"],
        "Xmax": ["10"],
        "Xmin": ["-10"],
        "Ymax": ["10"],
        "Ymin": ["-10"],
        "Zmax": ["35/10"],
        "Zmin": ["-35/10"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Vase_3 by Abderrahman Taha 31/10/2019"],
        "Name": ["Vase"],
        "Component": ["Vase","Head","Bottom"],
        "Const": ["Th1 = 1/5","Th2 = 6/5","A = 17/10","B = 5/12"],
        "Funct": ["CarvinCondition=abs((z-1)-(8/10)*cos(18*atan2(x,y)/pi))<(13/10)|abs((z+3)-(3/10)*cos(18*atan2(x,y)/pi+pi/4))<(1/2)",
          "Torus=(sqrt(x*x+y*y)-3)^2+z*z-1",
          "Bottom=(x*x+y*y+z*z-1)",
          "ThickIsoExterior=(x*x/3+y*y/3-abs((15/10)*sin(2*z/pi+(3/10))+(18/10)))*(x*x/3+y*y/3-abs((15/10)*sin(2*z/pi+(3/10))+(18/10)))-(1/20)",
          "Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "Rap=t*x/sqrt(x*x+y*y+z*z)",
          "Iso4= Iso(x+Th1*Rap((-sin(x)*sin(y)+cos(z)*cos(x)),(-sin(y)*sin(z)+cos(x)*cos(y)),(-sin(z)*sin(x)+cos(y)*cos(z)),t),y+Th1*Rap((-sin(y)*sin(z)+cos(x)*cos(y)),(-sin(z)*sin(x)+cos(y)*cos(z)),(-sin(x)*sin(y)+cos(z)*cos(x)),t),z+Th1*Rap((-sin(z)*sin(x)+cos(y)*cos(z)),(-sin(x)*sin(y)+cos(z)*cos(x)),(-sin(y)*sin(z)+cos(x)*cos(y)),t),t)",
          "Iso6= Iso(x+Th2*Rap((-sin(x)*sin(y)+cos(z)*cos(x)),(-sin(y)*sin(z)+cos(x)*cos(y)),(-sin(z)*sin(x)+cos(y)*cos(z)),t),y+Th2*Rap((-sin(y)*sin(z)+cos(x)*cos(y)),(-sin(z)*sin(x)+cos(y)*cos(z)),(-sin(x)*sin(y)+cos(z)*cos(x)),t),z+Th2*Rap((-sin(z)*sin(x)+cos(y)*cos(z)),(-sin(x)*sin(y)+cos(z)*cos(x)),(-sin(y)*sin(z)+cos(x)*cos(y)),t),t)",
          "ThickIso2=(Iso4(x,y,z,-1)*Iso4(x,y,z,1))",
          "isoTransform_2=if(CarvinCondition(x,y,z,t)=(0),ThickIsoExterior(x,y,z,t),1)",
          "isoTransform_6=if(CarvinCondition(x,y,z,t)&ThickIsoExterior(x,y,z,t)<(0),-ThickIso2((6*x),(6*y),(6*z),t)*Iso6((x*6),(y*6),(z*6),-1)*(Iso6((x*6),(y*6),(z*6),1)),1)"],
        "Fxyz": ["isoTransform_2(x,y,-z,t)*isoTransform_6(x,y,-z,t)",
          "Torus(A*x,A*y,(11/5)*(z+cos(pi/4*sqrt(x*x+y*y)))-(54/5),t)",
          "Bottom(x*B,y*B,2*(z+(51/10)),t)"],
        "Grid": ["250","250","250"],
        "Xmax": ["7/2","5","3"],
        "Xmin": ["-7/2","-5","-3"],
        "Ymax": ["7/2","5","3"],
        "Ymin": ["-7/2","-5","-3"],
        "Zmax": ["9/2","10","-2"],
        "Zmin": ["-5","0","-7"]
      },
      "Texture": {
        "Colors": ["R=(95/100)*abs(cos(z*y*x*y))",
          "G=(45/100)*abs(cos(z*y*x*y))",
          "B=(2/100)*abs(cos(-z*x*z*x*y*y))",
          "T=1"],
        "Name": "Granit_1",
        "Noise": "NoiseP(x,y,z,(10),(7),(12/100))"
      }
    },
    {
      "Iso3D": {
        "Description": ["Diamon Torus by Abderrahman Taha 31/10/2019"],
        "Name": ["Diamon_Torus"],
        "Const": ["A=98/10","B=35/10"],
        "Component": ["Diamon Torus_1","DiamonTorus_2"],
        "Funct": ["Iso=sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
          "isoCondition_0=(x^2+z^2-(32/10)^2)",
          "isoCondition_1=(x^2+z^2-3^2)",
          "isoTransform_1=if(isoCondition_0(x,y,z,t)<(0),Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform_2=if(isoCondition_0(x,y,z,t)<(0),-Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))"],
        "Fxyz": ["isoTransform_1((sqrt(x*x+y*y)-6),12*atan2(y,x),z,t)",
          "isoTransform_2((sqrt(x*x+y*y)-6),12*atan2(y,x),z,t)"],
        "Xmax": ["A","A"],
        "Xmin": ["-A","-A"],
        "Ymax": ["A","A"],
        "Ymin": ["-A","-A"],
        "Zmax": ["B","B"],
        "Zmin": ["-B","-B"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Octahedron of Octahedra by Abderrahman Taha 31/10/2019"],
        "Name": ["Octahedron_Of_Octahedra"],
        "Component": ["OctahedronOfOctahedra"],
        "Const": ["N=7","A=1/2"],
        "Funct": ["Octahedron=(abs(x)+abs(y)+abs(z))-(1/(2*N))",
          "Octahedr = ((abs(x-A)+abs(y-A)+abs(z-A))-(1/2))",
          "Octahedr1 = ((abs(x-A)+abs(y-A)+abs(z-A))-(1/2-1/(N)))"],
        "Fxyz": ["if(Octahedr(x,y,z,t)<(0) & Octahedr1(x,y,z,t)>(0),Octahedron((x%(1/N))-1/(2*N),(y%(1/N))-1/(2*N),(z%(1/N))-1/(2*N),t),1) "],
        "Xmax": ["1"],
        "Xmin": ["0"],
        "Ymax": ["1"],
        "Ymin": ["0"],
        "Zmax": ["1"],
        "Zmin": ["0"]
      },
      "Sliders": {
        "Max": ["50"],
        "Min": ["0"],
        "Name": ["N"],
        "Position": ["7"],
        "Step": ["1"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Cube of Octahedra by Abderrahman Taha 27/11/2015"],
        "Name": ["Cube_of_Octahedrons"],
        "Component": ["CubeOctahedrons"],
        "Const": ["N=5"],
        "Funct": ["Octahedron=(abs(x)+abs(y)+abs(z))-(1/(2*N))",
          "Cube = (((x < 1/N | x>(1-1/N)) | (y < 1/N | y>(1-1/N)) | (z < 1/N | z>(1-1/N))))"],
        "Fxyz": ["if(Cube(x,y,z,t),Octahedron((x%(1/N))-1/(2*N),(y%(1/N))-1/(2*N),(z%(1/N))-1/(2*N),t),1) "],
        "Xmax": ["1"],
        "Xmin": ["0"],
        "Ymax": ["1"],
        "Ymin": ["0"],
        "Zmax": ["1"],
        "Zmin": ["0"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Cube of Spheres (update) by Abderrahman Taha 31/10/2019"],
        "Name": ["Cube of Spheres"],
        "Component": ["CubeSpheres"],
        "Const": ["N=5"],
        "Funct": ["Sphere=sqrt(x*x+y*y+z*z)-1/(2*N+(1/1000))"],
        "Fxyz": ["if((((x < 1/N | x>(1-1/N)) | (y < 1/N | y>(1-1/N)) | (z < 1/N | z>(1-1/N)))),Sphere((x%(1/N))-1/(2*N),(y%(1/N))-1/(2*N),(z%(1/N))-1/(2*N),t),1) "],
        "Xmax": ["1"],
        "Xmin": ["0"],
        "Ymax": ["1"],
        "Ymin": ["0"],
        "Zmax": ["1"],
        "Zmin": ["0"]
      },
      "Sliders": {
        "Max": ["20"],
        "Min": ["0"],
        "Name": ["N"],
        "Position": ["5"],
        "Step": ["1"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Belted Torus_1 by Abderrahman Taha 31/10/2019"],
        "Name": ["Belted_Torus"],
        "Component": ["BeltedTorus"],
        "Const": ["c=1/10000",
          "A=2/5",
          "B=3/5",
          "N=2"],
        "Funct": ["Th=A*sin(2*N*v)^100+A*sin(N*v-u)^100",
          "Fx=(N/2+1+B*cos(u))*cos(v)",
          "Fy=B*sin(u)",
          "Fz=(N/2+1+B*cos(u))*sin(v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Texture": {
        "Colors": ["R=(9/10)",
          "G=(4/5)*abs(cos((pi*(x*x+y*y+z*z))))",
          "B=(3/5)*abs(cos(cos(pi*(x*x+y*y+z*z))))",
          "T=1"],
        "Name": "Dream",
        "Noise": "NoiseW(2*x,2*y,2*z,(8),(1),2)"
      }
    },
    {
      "Iso3D": {
        "Description": ["Schwarz Torus_1 by Abderrahman Taha 30/10/2019"],
        "Name": ["Schwarz_Torus_v1"],
        "Component": ["SchwarzTorus_1",
          "SchwarzTorus_2"],
        "Const": ["Th1=4/10",
          "Th2=14/10"],
        "Funct": ["Iso=cos(x)+cos(y)+cos(z)",
          "Rap=x/sqrt(x*x+y*y+z*z)",
          "Iso1= (Iso(x+Th1*Rap(sin(x),sin(y),sin(z),t),y+Th1*Rap(sin(y),sin(z),sin(x),t),z+Th1*Rap(sin(z),sin(x),sin(y),t),t))",
          "Iso2= (Iso(x-Th1*Rap(sin(x),sin(y),sin(z),t),y-Th1*Rap(sin(y),sin(z),sin(x),t),z-Th1*Rap(sin(z),sin(x),sin(y),t),t))",
          "Iso3= (Iso(x+Th2*Rap(sin(x),sin(y),sin(z),t),y+Th2*Rap(sin(y),sin(z),sin(x),t),z+Th2*Rap(sin(z),sin(x),sin(y),t),t))",
          "ThickIso=(Iso1(x,y,z,t)*Iso2(x,y,z,t))",
          "isoCondition=(x^2+z^2-20)",
          "isoTransform_1=if(isoCondition(x,y,z,t)<(0),ThickIso(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)",
          "isoTransform_2=if(isoCondition(x,y,z,t)<(0),-Iso3(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)"],
        "Fxyz": ["-isoTransform_1((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)",
          "-isoTransform_2((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)"],
        "Xmax": ["14","16"],
        "Xmin": ["-14","-16"],
        "Ymax": ["14","16"],
        "Ymin": ["-14","-16"],
        "Zmax": ["6","6"],
        "Zmin": ["-6","-6"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Schwarz Torus v2 by Abderrahman Taha 30/10/2019"],
        "Name": ["Schwarz_Torus_v2"],
        "Component": ["SchwarzTorus_1","SchwarzTorus_2","SchwarzTorus_3"],
        "Const": ["Th1=14/10","Th2=4/10"],
        "Funct": ["Iso=cos(x)+cos(y)+cos(z)",
          "Rapp=1/sqrt(x*x+y*y+z*z)",
          "rapp=x/sqrt(x*x+y*y+z*z)",
          "iso7=Iso(x+sin(x)*Th2*t,y+Th2*sin(y)*t,z+Th2*sin(z)*t,0)*Iso(x-sin(x)*Th2*t,y-Th2*sin(y)*t,z-Th2*sin(z)*t,0)",
          "iso0=Iso(x+sin(x)*Th1*t,y+Th1*sin(y)*t,z+Th1*sin(z)*t,0)",
          "iso1=Iso(x-sin(x)*Th1*t,y-Th1*sin(y)*t,z-Th1*sin(z)*t,0)",
          "isoCondition=(x^2+z^2-28)",
          "isoTransform_1=if(isoCondition(x,y,z,t)<(0),iso7(x,y,z,Rapp(sin(x),sin(y),sin(z),t)),1)+exp(isoCondition(x,y,z,t)/3)",
          "isoTransform_2=if(isoCondition(x,y,z,t)<(0),-iso0(x,y,z,Rapp(sin(x),sin(y),sin(z),t)),1)+exp(isoCondition(x,y,z,t)/3)",
          "isoTransform_3=if(isoCondition(x,y,z,t)<(0),iso1(x,y,z,Rapp(sin(x),sin(y),sin(z),t)),1)+exp(isoCondition(x,y,z,t)/3)"],
        "Fxyz": ["-isoTransform_1((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)",
          "isoTransform_2((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)",
          "-isoTransform_3((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)"],
        "Xmax": ["16","16","16"],
        "Xmin": ["-16","-16","-16"],
        "Ymax": ["16","16","16"],
        "Ymin": ["-16","-16","-16"],
        "Zmax": ["6","6","6"],
        "Zmin": ["-6","-6","-6"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Schwarz Torus v3 by Abderrahman Taha 30/10/2019"],
        "Name": ["Schwarz_Torus_v3"],
        "Component": ["SchwarzTorus"],
        "Const": ["N=2","Th=4/10"],
        "Funct": ["Iso=cos(x)+cos(y)+cos(z)",
          "Rap=x/sqrt(x*x+y*y+z*z)",
          "Iso1= (Iso(x+Th*Rap(sin(x),sin(y),sin(z),t),y+Th*Rap(sin(y),sin(z),sin(x),t),z+Th*Rap(sin(z),sin(x),sin(y),t),t))",
          "Iso2= (Iso(x-Th*Rap(sin(x),sin(y),sin(z),t),y-Th*Rap(sin(y),sin(z),sin(x),t),z-Th*Rap(sin(z),sin(x),sin(y),t),t))",
          "ThickIso2=(Iso1(x,y,z,t)*Iso2(x,y,z,t))",
          "isoCondition=(x^2+z^2-28)",
          "isoTransform_1=if(isoCondition(x,y,z,t)<(0),ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)"],
        "Fxyz": ["isoTransform_1((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)"],
        "Xmax": ["15"],
        "Xmin": ["-15"],
        "Ymax": ["15"],
        "Ymin": ["-15"],
        "Zmax": ["5"],
        "Zmin": ["-5"]
      }
    },
    {
        "Iso3D": {
            "Description": ["Symmetrized Costa Surface with genus N by Abderrahman Taha 14/04/2019"],
            "Name": ["SCosta"],
            "Component": ["SCosta"],
            "Const": ["N=6","c=1/10000","th=1/10","Xval=15","Yval=20","Zval=20"],
            "Funct": ["Scherk=sinh(x)*sinh(y)-(35/10)*sin(z)","IsoExterior =Scherk(x,sqrt(y*y+z*z)-(2+N+(3/100)*exp((abs((9/10)*x)))),N*atan2(z,y),t)","DFx=((IsoExterior(x+c,y,z,t)-IsoExterior(x,y,z,t))/c)","DFy=((IsoExterior(x,y+c,z,t)-IsoExterior(x,y,z,t))/c)","DFz=((IsoExterior(x,y,z+c,t)-IsoExterior(x,y,z,t))/c)","Rapp=(x/sqrt(x*x+y*y+z*z))","Iso1=(IsoExterior(x-th*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-th*Rapp(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z-th*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))","Iso2=(IsoExterior(x+th*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+th*Rapp(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z+th*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))","ThickIsoExterior=(Iso2(x,y,z,t)*Iso1(x,y,z,t))","SCosta=if((sqrt(4*x*x+y*y+z*z)-19)<0 & abs(x)<(295/10),ThickIsoExterior(x,y,z,t),1)"],
            "Fxyz": ["-SCosta((55/100)*x,y,z,t)"],
            "Xmax": ["Xval"],
            "Xmin": ["-Xval"],
            "Ymax": ["Yval"],
            "Ymin": ["-Yval"],
            "Zmax": ["Zval"],
            "Zmin": ["-Zval"]
        }
    },
    {
        "Iso3D": {
            "Description": ["Arena by Abderrahman Taha 30/03/2019"],
            "Component": ["Arena"],
            "Const": ["c=1/10000","th=6/10","N=10"],
            "Funct": ["Scherk=sinh(x)*sinh(y)-4*sin(z)","IsoExterior =Scherk(x,sqrt(y*y+z*z)-(16),N*atan2(z,y),t)","DFx=((IsoExterior(x+c,y,z,t)-IsoExterior(x,y,z,t))/c)","DFy=((IsoExterior(x,y+c,z,t)-IsoExterior(x,y,z,t))/c)","DFz=((IsoExterior(x,y,z+c,t)-IsoExterior(x,y,z,t))/c)","Rapp=(x/sqrt(x*x+y*y+z*z))","Iso1=(IsoExterior(x-th*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-th*Rapp(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z-th*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))","Iso2=(IsoExterior(x+th*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+th*Rapp(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z+th*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))","ThickIsoExterior=(Iso2(x,y,z,t)*Iso1(x,y,z,t))"],
            "Fxyz": ["if((sqrt(x*x+y*y+z*z)-27)<0 & abs(x)<(99/10),ThickIsoExterior(x,y,z,t),1)"],
            "Name": ["Arena"],
            "Xmax": ["10"],
            "Xmin": ["-10"],
            "Ymax": ["28"],
            "Ymin": ["-28"],
            "Zmax": ["28"],
            "Zmin": ["-28"]
        }
    },
    {
      "Iso3D": {
        "Description": ["Schwarz Cube Torus by Abderrahman Taha 30/10/2019"],
        "Name": ["Schwarz Cube Torus"],
        "Component": ["SchwarzCubeTorus_1","SchwarzCubeTorus_2","SchwarzCubeTorus_3","SchwarzCubeTorus_4"],
        "Const": ["k=6","C=65/10","D=65/10","E=(323/100)^20","Th=4/10"],
        "Funct": ["Iso=cos(x)+cos(y)+cos(z)",
          "Rap= x/sqrt(x*x+y*y+z*z)",
          "Iso4=(Iso(x+Th*Rap(sin(x),sin(y),sin(z),t),y+Th*Rap(sin(y),sin(z),sin(x),t),z+Th*Rap(sin(z),sin(x),sin(y),t),t))",
          "Iso5=(Iso(x-Th*Rap(sin(x),sin(y),sin(z),t),y-Th*Rap(sin(y),sin(z),sin(x),t),z-Th*Rap(sin(z),sin(x),sin(y),t),t))",
          "ThickIso=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoCondition=(x^20+(y/4)^20+z^20-E)",
          "isoTransform_2=if(isoCondition(x,y,z,t)<(0),ThickIso(k*x,k*y,k*z,t),1)",
          "isoTransform_3=isoTransform_2(x*cos(pi*y/(k*pi))-z*sin(pi*y/(k*pi)),y,x*sin(pi*y/(k*pi))+z*cos(pi*y/(k*pi)),t)"],
        "Fxyz": ["-isoTransform_3(sqrt(x*x+y*y)-C,3*atan2(y,x),z,t)",
          "-isoTransform_3(sqrt(x*x+y*y)-C,3*atan2(y,x),z,t)",
          "-isoTransform_3(sqrt(x*x+y*y)-C,3*atan2(y,x),z,t)",
          "-isoTransform_3(sqrt(x*x+y*y)-C,3*atan2(y,x),z,t)"],
        "Xmax": ["0","0","11","11"],
        "Xmin": ["-11","-11","0","0"],
        "Ymax": ["0","11","0","11"],
        "Ymin": ["-11","0","-11","0"],
        "Zmax": ["5","5","5","5"],
        "Zmin": ["-5","-5","-5","-5"]
      },
      "Texture": {
        "Colors": ["R=8/10",
          "G=6/10",
          "B=1/10",
          "T=1"],
        "Name": "Gold",
        "Noise": "1"
      }
    },
    {
      "Iso3D": {
        "Description": ["Gyroidal Torus by Abderrahman Taha 30/10/2019"],
        "Name": ["Gyroidal_Tori_v1"],
        "Component": ["GyroidalTorus"],
        "Const": ["c=1/100000","Th=4/10"],
        "Funct": ["Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "DFx= ((Iso(x+c,y,z,t)-Iso(x,y,z,t))/c)",
          "DFy= ((Iso(x,y+c,z,t)-Iso(x,y,z,t))/c)",
          "DFz= ((Iso(x,y,z+c,t)-Iso(x,y,z,t))/c)",
          "Rap= x/sqrt(x*x+y*y+z*z)",
          "Iso4= (Iso(x-Th*Rap(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-Th*Rap(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z-Th*Rap(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))",
          "Iso5= (Iso(x+Th*Rap(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+Th*Rap(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z+Th*Rap(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))",
          "ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoCondition=(x^2+z^2-16)",
          "isoTransform_1=if(isoCondition(x,y,z,t)<(0),ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)"],
        "Fxyz": ["isoTransform_1((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)"],
        "Xmax": ["14"],
        "Xmin": ["-14"],
        "Ymax": ["14"],
        "Ymin": ["-14"],
        "Zmax": ["4"],
        "Zmin": ["-4"]
      }
    },
    {
        "Iso3D": {
            "Description": ["Gyroidal Torus using variable (3.2x faster to compute) by Abderrahman Taha 18/07/2020"],
            "Name": ["Gyroidal_Tori_v2"],
            "Component": ["GyroidalTorus"],
            "Const": ["c=1/100000","Th=4/10"],
            "Funct": [
                "Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
                "DFx= ((Iso(x+c,y,z,t)-Iso(x,y,z,t))/c)",
                "DFy= ((Iso(x,y+c,z,t)-Iso(x,y,z,t))/c)",
                "DFz= ((Iso(x,y,z+c,t)-Iso(x,y,z,t))/c)",
                "Rapp= Th/sqrt(x*x+y*y+z*z)",
                "ThickIso=  psh((0),DFx(x,y,z,t))*psh((1),DFy(x,y,z,t))*psh((2),DFz(x,y,z,t))*(psh((3),Rapp(csd(0),csd(1),csd(2),t)))*(Iso(x-csd(0)*csd(3),y-csd(1)*csd(3),z-csd(2)*csd(3),t))*(Iso(x+csd(0)*csd(3),y+csd(1)*csd(3),z+csd(2)*csd(3),t))",
                "isoCondition=(x^2+z^2-16)",
                "isoTransform_1=if(isoCondition(x,y,z,t)<(0),ThickIso(x,y,z,t),(1))+exp(isoCondition(x,y,z,t)/3)"],
            "Fxyz": ["isoTransform_1((sqrt(x*x+y*y)-10),(12)*atan2(y,x),z,t)"],
            "Vect": ["4"],
            "Xmax": ["14"],
            "Xmin": ["-14"],
            "Ymax": ["14"],
            "Ymin": ["-14"],
            "Zmax": ["4"],
            "Zmin": ["-4"]
        }
    },
    {
        "Iso3D": {
            "Description": ["Surface with rotational symmetry of order 5,by Patrice Jeener 21/07/2020"],
            "Name": ["PatriceJ"],
            "Component": ["patrice"],
            "Const": ["X=2","Y=2","Z=13/10","c=1/1000","T=2/100"],
            "Funct": [
                "Patrice=16*z^5-20*z^3+5*z+x^5-10*x^3*y^2+5*x*y^4",
                "DFx=((Patrice(x+c,y,z,t)-Patrice(x,y,z,t))/c)",
                "DFy=((Patrice(x,y+c,z,t)-Patrice(x,y,z,t))/c)",
                "DFz=((Patrice(x,y,z+c,t)-Patrice(x,y,z,t))/c)",
                "Rapport=(x/sqrt(x*x+y*y+z*z))",
                "Rapp=(T/sqrt(x*x+y*y+z*z))",
                "ThickIso=  psh((0),DFx(x,y,z,t))*psh((1),DFy(x,y,z,t))*psh((2),DFz(x,y,z,t))*(psh((3),Rapp(csd(0),csd(1),csd(2),t)))*(Patrice(x-csd(0)*csd(3),y-csd(1)*csd(3),z-csd(2)*csd(3),t))*(Patrice(x+csd(0)*csd(3),y+csd(1)*csd(3),z+csd(2)*csd(3),t))",
                "Iso=Patrice(x-t*T*Rapport(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-t*T*Rapport(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z-t*T*Rapport(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t)",
                "ThickIsoExterior=(Iso(x,y,z,1)*Iso(x,y,z,-1))"],
            "Fxyz": ["if((sqrt(x*x+y*y+z*z)-X)<(0),ThickIsoExterior(x,y,z,t),(1))"],
            "Vect": ["4"],
            "Xmax": ["X"],
            "Xmin": ["-X"],
            "Ymax": ["Y"],
            "Ymin": ["-Y"],
            "Zmax": ["Z"],
            "Zmin": ["-Z"],
            "Grid": ["150"]
        }
    },
    {
        "Iso3D": {
            "Description": ["Icosahedral crystal field,by Abderrahman Taha  (ref: https://core.ac.uk/download/pdf/97962.pdf) 24/11/2019"],
            "Name": ["Icosahedral_crystal"],
            "Component": ["icosahedral"],
            "Const": ["X=2","Y=2","Z=15/10","c=1/1000","T=2/100","r=1"],
            "Funct": ["Icosahedral=(231*z^6-315*r^2*z^4+105*r^4*z^2-5*r^6+42*x*z*(x^4-10*x^2*y^2+5*y^4))","DFx=((Icosahedral(x+c,y,z,t)-Icosahedral(x,y,z,t))/c)","DFy=((Icosahedral(x,y+c,z,t)-Icosahedral(x,y,z,t))/c)","DFz=((Icosahedral(x,y,z+c,t)-Icosahedral(x,y,z,t))/c)","Rapport=(x/sqrt(x*x+y*y+z*z))","Iso=Icosahedral(x-t*T*Rapport(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-t*T*Rapport(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z-t*T*Rapport(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t)","TickIsoExterior=(Iso(x,y,z,1)*Iso(x,y,z,-1))"],
            "Fxyz": ["-if((sqrt(x*x+y*y+z*z)-X)<(0),TickIsoExterior(x,y,z,t),(1))"],
            "Grid": ["150"],
            "Xmax": ["X"],
            "Xmin": ["-X"],
            "Ymax": ["Y"],
            "Ymin": ["-Y"],
            "Zmax": ["Z"],
            "Zmin": ["-Z"]
        }
    },
    {
        "Iso3D": {
        "Description": ["iWP Skeletal Graphis by Abderrahman Taha 30/10/2019"],
        "Name": ["W_SkeletalGraph"],
        "Component": ["W_SkeletalGraphis"],
        "Fxyz": ["-(cos(2*x)+cos(2*y)+cos(2*z)-(195/100)*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+(28/10))"],
        "Xmax": ["4*pi"],
        "Xmin": ["0"],
        "Ymax": ["4*pi"],
        "Ymin": ["0"],
        "Zmax": ["4*pi"],
        "Zmin": ["0"]
        }
    },
    {
      "Iso3D": {
        "Description": ["Pseudo Chmutov by Abderrahman Taha 30/10/2019"],
        "Name": ["Pseudo_Chmutov"],
        "Component": ["PseudoChmutov_1","PseudoChmutov_2"],
        "Const": ["M=7","N=16","L=11/10"],
        "Fxyz": ["-((x^N+y^N+z^N)-(cos(M*x)+cos(M*y)+cos(M*z))-(1/10))","((x^N+y^N+z^N)-(cos((2*M)*x)+cos((2*M)*y)+cos((2*M)*z))+(1/2))"],
        "Xmax": ["L","L"],
        "Xmin": ["-L","-L"],
        "Ymax": ["L","L"],
        "Ymin": ["-L","-L"],
        "Zmax": ["L","L"],
        "Zmin": ["-L","-L"]
      }
    },
    {
      "Param4D": {
        "Description": ["4D Roller Coaster by Abderrahman Taha 30/10/2019"],
        "Name": ["4D_Roller_Coaster"],
        "Component": ["RollerCoaster"],
        "Fx": ["sin(u)*(cos(v%(pi/30)))*cos((v-3*u)%(pi/30))"],
        "Fy": ["cos(u)*(cos(v%(pi/30)))*cos((v-3*u)%(pi/30))"],
        "Fz": ["sin(v-3*u)*(cos(v%(pi/30)))*cos((v-3*u)%(pi/30))"],
        "Fw": ["cos(v-3*u)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["5*pi/6"],
        "Vmin": ["0"],
        "Grid": ["150","50"]
      }
    },
    {
      "Param4D": {
        "Description": ["4D Clliford Ribbon by Abderrahman Taha 30/10/2019"],
        "Name": ["4D_Clliford_Ribbon"],
        "Component": ["CllifordRibbon"],
        "Fx": ["sin(u-4*v)"],
        "Fy": ["cos(u-4*v)"],
        "Fz": ["sin(v)"],
        "Fw": ["cos(v)"],
        "Umax": ["2*pi/3"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"],
        "Grid": ["50",
          "150"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Pseudo Chmutov_2 by Abderrahman Taha 30/10/2019"],
        "Name": ["Pseudo_Chmutov_2"],
        "Component": ["PseudoChmutov"],
        "Const": ["M=7","N=16","L=11/10"],
        "Fxyz": ["-((x^N+y^N+z^N)-(cos(M*x)+cos(M*y)+cos(M*z))-(1/10))"],
        "Xmax": ["L"],
        "Xmin": ["-L"],
        "Ymax": ["L"],
        "Ymin": ["-L"],
        "Zmax": ["L"],
        "Zmin": ["-L"]
      }
    },
    {
        "Param3D": {
            "Description ": ["Bullet by Abderrahman Taha 30/10/2019"],
            "Name": ["Bullet"],
            "Component": ["Bullet1","Bullet2"],
            "Const": ["c=1/10000"],
            "Funct": ["Th=if((t = 1),if (abs(sin(4*u-v))<(1/4),(-1),-u*u*(cos(u)-sin(u))),if (abs(sin(4*u-v))>(1/4),(-1),-u*u*(cos(u)-sin(u))))",
                "Fx=cos(u)*cos(v)",
                "Fy=sin(u)",
                "Fz=cos(u)*sin(v)",
                "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
                "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
                "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
                "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
                "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
                "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
                "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
                "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
                "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
                "R=u/sqrt(u*u+v*v+t*t)",
                "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
                "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
                "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
            "Fx": ["Gx(u,v,1)","Gx(u,v,0)"],
            "Fy": ["Gy(u,v,1)","Gy(u,v,0)"],
            "Fz": ["Gz(u,v,1)","Gz(u,v,0)"],
            "Umax": ["pi/2","pi/2"],
            "Umin": ["-pi/2","-pi/2"],
            "Vmax": ["2*pi","2*pi"],
            "Vmin": ["0","0"]
        }
    },
    {
        "Param3D": {
            "Description ": ["Lobed Torus_1 by Abderrahman Taha 29/10/2019"],
            "Name": ["Lobed_Torus_1"],
            "Component": ["LobedTorus"],
            "Const": ["c=1/10000","N=3"],
            "Funct": ["Th=(4/10)*sin(2*N*v-u)+(9/10)*sin((N*v)% pi/3)",
                "Fx=(N/2+1+(6/10)*cos(u))*cos(v)",
                "Fy=(6/10)*sin(u)",
                "Fz=(N/2+1+(6/10)*cos(u))*sin(v)",
                "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
                "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
                "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
                "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
                "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
                "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
                "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
                "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
                "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
                "R=u/sqrt(u*u+v*v+t*t)",
                "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
                "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
                "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
            "Fx": ["Gx(u,v,t)"],
            "Fy": ["Gy(u,v,t)"],
            "Fz": ["Gz(u,v,t)"],
            "Umax": ["2*pi"],
            "Umin": ["0"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        },
        "Texture": {
            "Colors": ["R=9/10",
                "G=8*abs(cos((pi*(x*x+y*y+z*z))))/10",
                "B=6*abs(cos(cos(pi*(x*x+y*y+z*z))))/10",
                "T=1"],
            "Name": "Dream",
            "Noise": "NoiseW(2*x,2*y,2*z,(8),(1),(2))"
        }
    },
    {
        "Param3D": {
            "Description ": ["Lobed Torus_2 by Abderrahman Taha 29/10/2019"],
            "Name": ["Lobed_Torus_2"],
            "Component": ["LobedTorus"],
            "Const": ["c=1/10000","N=3"],
            "Funct": ["Th=(9/10)*sin((N*v)% pi/3)",
                "Fx=(N/2+1+(6/10)*cos(u))*cos(v)",
                "Fy=(6/10)*sin(u)",
                "Fz=(N/2+1+(6/10)*cos(u))*sin(v)",
                "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
                "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
                "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
                "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
                "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
                "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
                "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
                "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
                "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
                "R=u/sqrt(u*u+v*v+t*t)",
                "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
                "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
                "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
            "Fx": ["Gx(u,v,t)"],
            "Fy": ["Gy(u,v,t)"],
            "Fz": ["Gz(u,v,t)"],
            "Umax": ["2*pi"],
            "Umin": ["0"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        },
        "Texture": {
            "Colors": ["R=9/10",
                "G=8*abs(cos((pi*(x*x+y*y+z*z))))/10",
                "B=6*abs(cos(cos(pi*(x*x+y*y+z*z))))/10",
                "T=1"],
            "Name": "Dream",
            "Noise": "NoiseW(2*x,2*y,2*z,(8),(1),(2))"
        }
    },
    {
        "Param3D": {
            "Description ": ["Lobed Torus_4 by Abderrahman Taha 29/10/2019"],
            "Name": ["Lobed_Torus_4"],
            "Component": ["LobedTorus"],
            "Const": ["c=1/10000","N=3"],
            "Funct": ["Th=(4/10)*sin(N*v)",
                "Fx=(N/2+1+(6/10)*cos(u))*cos(v)",
                "Fy=(6/10)*sin(u)",
                "Fz=(N/2+1+(6/10)*cos(u))*sin(v)",
                "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
                "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
                "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
                "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
                "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
                "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
                "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
                "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
                "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
                "R=u/sqrt(u*u+v*v+t*t)",
                "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
                "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
                "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
            "Fx": ["Gx(u,v,t)"],
            "Fy": ["Gy(u,v,t)"],
            "Fz": ["Gz(u,v,t)"],
            "Umax": ["2*pi"],
            "Umin": ["0"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        },
        "Texture": {
            "Colors": ["R=9/10",
                "G=8*abs(cos((pi*(x*x+y*y+z*z))))/10",
                "B=6*abs(cos(cos(pi*(x*x+y*y+z*z))))/10",
                "T=1"],
            "Name": "Dream",
            "Noise": "NoiseW(2*x,2*y,2*z,(8),(1),(2))"
        }
    },
    {
      "Param3D": {
        "Description ": ["Lobed Torus_5 by Abderrahman Taha 29/10/2019"],
        "Name": ["Lobed_Torus_5"],
        "Component": ["LobedTorus"],
        "Const": ["c=1/10000","N=3"],
        "Funct": ["Th=(4/10)*sin(N*v-u)^100",
          "Fx=(N/2+1+(6/10)*cos(u))*cos(v)",
          "Fy=(6/10)*sin(u)",
          "Fz=(N/2+1+(6/10)*cos(u))*sin(v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
    "Texture": {
       "Colors": [
           "R=9/10",
           "G=8*abs(cos((pi*(x*x+y*y+z*z))))/10",
           "B=6*abs(cos(cos(pi*(x*x+y*y+z*z))))/10",
           "T=1"],
       "Name": "Dream",
           "Noise": "NoiseW(2*x,2*y,2*z,(8),(1),(2))"
    }
    },
    {
      "Param3D": {
        "Description ": ["Lobed Torus_6 by Abderrahman Taha 29/10/2019"],
        "Name": ["Lobed_Torus_6"],
        "Component": ["LobedTorus"],
        "Const": ["c=1/10000","N=3"],
        "Funct": ["Th=(4/10)*sin(2*N*v-u)",
          "Fx=(N/2+1+(6/10)*cos(u))*cos(v)",
          "Fy=(6/10)*sin(u)",
          "Fz=(N/2+1+(6/10)*cos(u))*sin(v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Texture": {
         "Colors": [
             "R=9/10",
             "G=8*abs(cos((pi*(x*x+y*y+z*z))))/10",
             "B=6*abs(cos(cos(pi*(x*x+y*y+z*z))))/10",
             "T=1"
          ],
         "Name": "Dream",
             "Noise": "NoiseW(2*x,2*y,2*z,(8),(1),(2))"
      }
    },
    {
      "Param3D": {
        "Description ": ["Lobed Torus_7 by Abderrahman Taha 29/10/2019"],
        "Name": ["Lobed_Torus_7"],
        "Component": ["LobedTorus"],
        "Const": ["c=1/1000","N=3"],
        "Funct": ["Th=(4/10)*sin(N*v)^10",
          "Fx=(N/2+1+(6/10)*cos(u))*cos(v)",
          "Fy=(6/10)*sin(u)",
          "Fz=(N/2+1+(6/10)*cos(u))*sin(v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Texture": {
        "Colors": ["R=9/10",
          "G=8*abs(cos((pi*(x*x+y*y+z*z))))/10",
          "B=6*abs(cos(cos(pi*(x*x+y*y+z*z))))/10",
          "T=1"],
        "Name": "Dream",
        "Noise": "NoiseW(2*x,2*y,2*z,(8),(1),(2))"
      }
    },
    {
      "Iso3D": {
        "Description ": ["Torus Distortion due to moving surface by Abderrahman Taha 11/12/2019"],
        "Name": ["Torus_Distortion"],
        "Component": ["Drope","Torus"],
        "Fxyz": ["z-(15/10)*x*sin(2*t)*exp(-x*x-y*y)-2*y*cos(3*t)*exp(-x*x-y*y)","(sqrt((x-(15/10)*x*sin(2*t)*exp(-x*x-y*y))^2+(y-2*y*cos(3*t)*exp(-x*x-y*y))^2)-1)^2+(z-(3/2)*x*sin(2*t)*exp(-x*x-y*y)-2*y*cos(3*t)*exp(-x*x-y*y))^2-(1/10)"],
        "Xmax": ["2","18/10"],
        "Xmin": ["-2","-18/10"],
        "Ymax": ["2","18/10"],
        "Ymin": ["-2","-18/10"],
        "Zmax": ["17/10","15/10"],
        "Zmin": ["-17/10","-15/10"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Lobs by Abderrahman Taha 28/10/2019"],
        "Name": ["Lobs"],
        "Component": ["Lobs1","Lobs2"],
        "Const": ["c=1/10000"],
        "Funct": ["Th=if((t = 1),if ((sin(13*v-7*u))<(4/10),(-1),3*cos(u)*cos(v)*sin(u)-(63/100)),if ((sin(13*v-7*u))>(4/10),(-1),3*cos(u)*cos(v)*sin(u)-(63/100)))",
          "Fx=cos(u)*cos(v)",
          "Fy=sin(u)",
          "Fz=cos(u)*sin(v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,1)","Gx(u,v,0)"],
        "Fy": ["Gy(u,v,1)","Gy(u,v,0)"],
        "Fz": ["Gz(u,v,1)","Gz(u,v,0)"],
        "Umax": ["pi/2","pi/2"],
        "Umin": ["-pi/2","-pi/2"],
        "Vmax": ["2*pi","2*pi"],
        "Vmin": ["0","0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Sphere Parts by Abderrahman Taha 29/10/2019"],
        "Name": ["Sphere_Parts"],
        "Component": ["Sphere1","Sphere2"],
        "Const": ["c=1/10000","A=35/100"],
        "Funct": ["Th=if((t = 1),if (abs(sin(4*u-v))>A,(-1),(6/10)*sin(v)),if (abs(sin(4*u-v))<A,(-1),(0)))",
          "Fx=cos(u)*cos(v)",
          "Fy=sin(u)",
          "Fz=cos(u)*sin(v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,(1))","Gx(u,v,(0))"],
        "Fy": ["Gy(u,v,(1))","Gy(u,v,(0))"],
        "Fz": ["Gz(u,v,(1))","Gz(u,v,(0))"],
        "Umax": ["pi/2","pi/2"],
        "Umin": ["-pi/2","-pi/2"],
        "Vmax": ["2*pi","2*pi"],
        "Vmin": ["0","0"]
      },
      "Texture": {
        "Colors": ["R=if((cmpId=0),(1/2)*cos(5*(x*x+y*y)),cos(5*(x*x+y*y)))",
          "G=cos(5*(x*x+y*y+z*z))/2",
          "B=cos(5*(x*x+y*y+z*z))/2",
          "T=1"],
        "Name": "Granit",
        "Noise": "NoiseW((13*x),(13*y),(13*z),(1),(2),(0))"
      }
    },
    {
      "Param4D": {
        "Description": ["Ribbon bending by Abderrahman Taha 05/11/2015"],
        "Name": ["Ribbon bending"],
        "Component": ["Ribbon1","Ribbon2"],
        "Fw": ["sin(200*u)/2000","sin(8*u)/5"],
        "Fx": ["sin(u)","sin(u)"],
        "Fy": ["cos(u)","cos(u)"],
        "Fz": ["sin(v)","sin(v)"],
        "Umax": ["2*pi","2*pi"],
        "Umin": ["0","0"],
        "Vmax": ["2*pi","2*pi"],
        "Vmin": ["0","0"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Bouncing Ball_1 by Abderrahman Taha 29/10/2019"],
        "Name": ["Bouncing Ball"],
        "Component": ["Ball","ThickWalls","TransparentWall"],
        "Fxyz": ["((x-(abs(((t*25/10)%16)-8)-4))^2+(y-(abs(((t*29/10)%16)-8)-4))^2+(z-(44/10-((((t*12/10)%4)-2)^2)))^2-8/10)",
          "(z+4/10)*(y-49/10)*(y+49/10)*(x+49/10)",
          "(x-49/10)"],
        "Grid": ["25","15","5"],
        "Xmax": ["481/100","491/100","491/100"],
        "Xmin": ["-481/100","-491/100","-491/100"],
        "Ymax": ["481/100","491/100","491/100"],
        "Ymin": ["-481/100","-491/100","-491/100"],
        "Zmax": ["55/10","55/10","55/10"],
        "Zmin": ["-1/2","-41/100","-41/100"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Enneper_k_Curls by Abderrahman Taha 24/08/2020"],
        "Name": ["Enneper_k_Curls"],
        "Component": ["Enneper"],
        "Const": ["k=4"],
        "Fx": ["k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t)"],
        "Fy": ["-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t)"],
        "Fz": ["(u^k*cos(k*v+t))"],
        "Umax": ["115/100"],
        "Umin": ["0"],
        "Vmax": ["pi"],
        "Vmin": ["-pi"]
      },
      "Texture": {
        "Colors": ["R=(9/10)",
          "G=(8/10)*abs(cos(5*pi*atan2(x,y)))",
          "B=(8/10)*abs(cos(5*pi*atan2(x,y)))",
          "T=1"],
        "Name": "Candy",
        "Noise": "1"
      }
    },
    {
        "Param3D": {
            "Description ": ["Parametric approximation of the Symmetrized Double Enneper by Abderrahman Taha 17/08/2020"],
            "Name": ["Symmetrized_Double_Enneper"],
            "Component": ["Enneper_1","Enneper_2"],
            "Const": ["k=10"],
            "Funct": ["X=k*u*cos(v)-u^(2*k-1)/6*cos((2*k-1)*v)","Y=-k*u*sin(v)-u^(2*k-1)/6*sin((2*k-1)*v)","Z=-(u^k*cos(k*v))"],
            "Fx": ["X(u,v,t)","X(u,v,t)"],
            "Fy": ["Y(u,v,t)","Y(u,v,t)"],
            "Fz": ["Z(u,v,t)-2*exp(2*cos(4*u))+24/5","-Z(u,v,t)+2*exp(2*cos(4*u))-24/5"],
            "Umax": ["108/100","11/10"],
            "Umin": ["28/100","28/100"],
            "Vmax": ["pi","pi"],
            "Vmin": ["-pi","-pi"]
        },
        "Texture": {
            "Colors": ["R=(8/10)","G=(3/10)*exp((8/10)*abs(cos(4*pi*atan2(x,y))))","B=(2/10)*exp((8/10)*abs(cos(4*pi*atan2(x,y))))","T=1"],
            "Name": "Granit_2",
            "Noise": "1"
        }
    },
    {
      "Iso3D": {
        "Description": ["Contour lines by Abderrahman Taha 28/10/2019"],
        "Name": ["Contour_lines"],
        "Const": ["C=1/4"],
        "Cnd": ["(z-C)*(z+C)*(z-2*C)*(z+2*C)*(z-3*C)*(z+3*C)*(z-1)*(z+1)*(z-6*C)*(z+(3/2))*(z-5*C)*(z+5*C)>0"],
        "Component": ["Drope"],
        "Fxyz": ["4*x*exp(-x^2-y^2)-z"],
        "Xmax": ["2"],
        "Xmin": ["-2"],
        "Ymax": ["2"],
        "Ymin": ["-2"],
        "Zmax": ["18/10"],
        "Zmin": ["-18/10"]
      }
    },
    {
      "Param3D": {
        "Description": ["Double Helical curve by Abderrahman Taha 28/10/2019"],
        "Name": ["Double Helical curve"],
        "Cnd": ["sqrt(z^2+y^2)-(1/5)>0","1"],
        "Component": ["Cosinus","Cylinder"],
        "Fx": ["u","v"],
        "Fy": ["v","sin(pi*u)/5"],
        "Fz": ["-sin(5*pi*u)/5","cos(pi*u)/5"],
        "Umax": ["1","1"],
        "Umin": ["-1","-1"],
        "Vmax": ["1/2","1"],
        "Vmin": ["-1/2","-1"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Menger Schwarz_1 by Abderrahman Taha 11/12/2019 _ Menger Sponge Level 3 made out from the skeletal graph of the Schwarz's D surface"],
        "Name": ["Skeletal Menger"],
        "Const": ["A=84","Th=-13/1000","X=106/100"],
        "Component": ["MengerSchwarz1",
          "MengerSchwarz2",
          "MengerSchwarz3",
          "MengerSchwarz4",
          "MengerSchwarz5",
          "MengerSchwarz6",
          "MengerSchwarz7",
          "MengerSchwarz8"],
        "Funct": ["isoCondition=if((abs(x)>1/3|abs(y)>1/3)&(abs(z)>1/3|abs(y)>1/3)&(abs(x)>1/3|abs(z)>1/3)&(((((abs(x-2/3)<1/9)+(abs(x+2/3)<1/9)+(abs(x)<1/9))*((abs(y-2/3)<1/9)+(abs(y)<1/9)+(abs(y+2/3)<1/9)+(abs(z-2/3)<1/9)+(abs(z)<1/9)+(abs(z+2/3)<1/9)))+(((abs(z-2/3)<1/9)+(abs(z+2/3)<1/9)+(abs(z)<1/9))*((abs(y-2/3)<1/9)+(abs(y)<1/9)+(abs(y+2/3)<1/9))))=0)&(((((abs(x-2/3)<1/27)+(abs(x-2/3-2/9)<1/27)+(abs(x-2/3+2/9)<1/27)+(abs(x+2/3)<1/27)+(abs(x+2/3-2/9)<1/27)+(abs(x+2/3+2/9)<1/27)+(abs(x)<1/27)+(abs(x-2/9)<1/27)+(abs(x+2/9)<1/27))*((abs(y-2/3)<1/27)+(abs(y-2/3-2/9)<1/27)+(abs(y-2/3+2/9)<1/27)+(abs(y)<1/27)+(abs(y-2/9)<1/27)+(abs(y+2/9)<1/27)+(abs(y+2/3)<1/27)+(abs(y+2/3-2/9)<1/27)+(abs(y+2/3+2/9)<1/27)+(abs(z-2/3)<1/27)+(abs(z-2/3-2/9)<1/27)+(abs(z-2/3+2/9)<1/27)+(abs(z)<1/27)+(abs(z-2/9)<1/27)+(abs(z+2/9)<1/27)+(abs(z+2/3)<1/27)+(abs(z+2/3-2/9)<1/27)+(abs(z+2/3+2/9)<1/27)))+(((abs(z-2/3)<1/27)+(abs(z-2/3-2/9)<1/27)+(abs(z-2/3+2/9)<1/27)+(abs(z+2/3)<1/27)+(abs(z+2/3-2/9)<1/27)+(abs(z+2/3+2/9)<1/27)+(abs(z)<1/27)+(abs(z-2/9)<1/27)+(abs(z+2/9)<1/27))*((abs(y-2/3)<1/27)+(abs(y-2/3-2/9)<1/27)+(abs(y-2/3+2/9)<1/27)+(abs(y)<1/27)+(abs(y-2/9)<1/27)+(abs(y+2/9)<1/27)+(abs(y+2/3)<1/27)+(abs(y+2/3-2/9)<1/27)+(abs(y+2/3+2/9)<1/27))))=0),x^100+y^100+z^100-(112/100),1)",
        "SkekatalMenger= if(isoCondition(x,y,z,t)<(0),-(cos(A*(x-sin(A*x)*Th/sqrt(sin(A*x)*sin(A*x)+sin(A*y)*sin(A*y)+sin(A*z)*sin(A*z))))+cos(A*(y-sin(A*y)*Th/sqrt(sin(A*x)*sin(A*x)+sin(A*y)*sin(A*y)+sin(A*z)*sin(A*z))))+cos(A*(z-sin(A*z)*Th/sqrt(sin(A*x)*sin(A*x)+sin(A*y)*sin(A*y)+sin(A*z)*sin(A*z))))),1)"],
        "Fxyz": ["SkekatalMenger(x,y,z,t)",
          "SkekatalMenger(x,y,z,t)",
          "SkekatalMenger(x,y,z,t)",
          "SkekatalMenger(x,y,z,t)",
          "SkekatalMenger(x,y,z,t)",
          "SkekatalMenger(x,y,z,t)",
          "SkekatalMenger(x,y,z,t)",
          "SkekatalMenger(x,y,z,t)"],
        "Xmax": ["X","X","X","X","0","0","0","0"],
        "Xmin": ["0","0","0","0","-X","-X","-X","-X"],
        "Ymax": ["X","0","X","0","0","X","0","X"],
        "Ymin": ["0","-X","0","-X","-X","0","-X","0"],
        "Zmax": ["X","X","0","0","0","0","X","X"],
        "Zmin": ["0","0","-X","-X","-X","-X","0","0"]
      },
      "Texture": {
        "Colors": ["R=(7/10)*sqrt(4*x^40+y^4+z^4)",
          "G=(4/10)*sqrt(x^4+y^4+4*z^20)",
          "B=(5/10)*sqrt(x^4+4*y^20+z^4)",
          "T=1"],
        "Name": "Rainbow",
        "Noise": ""
      }
    },
    {
      "Param3D": {
        "Description ": ["Double Nib Parametric surface by Abderrahman Taha 29/10/2019"],
        "Name": ["Double Nib"],
        "Component": ["DoubleNib"],
        "Const": ["c=1/10000"],
        "Funct": ["Fx=-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6",
          "Fy=-sin(t+v)/(2*u)+u^3*sin(t-3*v)/6",
          "Fz=-u*cos(t-v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Thickness=DFyv(u,v,t)/2",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["13/10"],
        "Umin": ["3/10"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Texture": {
        "Colors": ["R=5/10",
          "G=abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "B=3*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(4*x,4*y,4*z,(4),(2),(0))+NoiseW(4*x,4*y,4*z,(4),(12),(0))"
      }
    },
    {
        "Iso3D": {
            "Description": ["PrettyBall_1 by Abderrahman Taha 03/08/2020"],
            "Name": ["Pretty_Ball_1"],
            "Component": ["PrettyBall_1","PrettyBall_2","PrettyBall_3"],
            "Const": ["L=23/2","c=1/10000","Th2=-8/10","Th1=5/10","N=2"],
            "Funct": ["Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)","DFx=((Iso(x+c,y,z,t)-Iso(x,y,z,t))/c)","DFy=((Iso(x,y+c,z,t)-Iso(x,y,z,t))/c)","DFz=((Iso(x,y,z+c,t)-Iso(x,y,z,t))/c)","Rapp=(x/sqrt(x*x+y*y+z*z))","Iso2=(Iso(x+Th2*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+Th2*Rapp(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z+Th2*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))","Iso3=(Iso(x-Th2*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-Th2*Rapp(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z-Th2*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))","Iso4=(Iso(x+Th1*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+Th1*Rapp(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z+Th1*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))","Iso5=(Iso(x-Th1*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-Th1*Rapp(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z-Th1*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))","isoCondition=(x^N+y^N+z^N-(L-1/10)^N)","ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))","GyroidLatice_1=if(isoCondition(x,y,z,t)<(0),Iso2(x,y,z,t),1)-exp(isoCondition(x,y,z,t)/5)","GyroidLatice_2=if(isoCondition(x,y,z,t)<(0),Iso3(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/5)","GyroidLatice_3=if(isoCondition(x,y,z,t)<(0),ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/5)"],
            "Fxyz": ["GyroidLatice_1(x,y,z,t)","GyroidLatice_2(x,y,z,t)","GyroidLatice_3(x,y,z,t)"],
            "Xmax": ["L","L","L"],
            "Xmin": ["-L","-L","-L"],
            "Ymax": ["L","L","L"],
            "Ymin": ["-L","-L","-L"],
            "Zmax": ["L","L","L"],
            "Zmin": ["-L","-L","-L"]
        }
    },
    {
        "Iso3D": {
            "Description ": ["Hexagrams Menger Sponge Level 4 by Abderrahman Taha 09/12/2019"],
            "Name": ["Hexagrams_Menger_Level4"],
            "Cnd": ["(x+y+z)> 0"],
            "Component": ["MengerSponge"],
            "Funct": ["Ax = ((abs(x-2/3) <1/81)+(abs(x-20/27) <1/81)+(abs(x-16/27) <1/81)+(abs(x-8/9) <1/81)+(abs(x-26/27) <1/81)+(abs(x-22/27) <1/81)+(abs(x-4/9) <1/81)+(abs(x-14/27) <1/81)+(abs(x-10/27) <1/81)+(abs(x+2/3) <1/81)+(abs(x+16/27) <1/81)+(abs(x+20/27) <1/81)+(abs(x+4/9) <1/81)+(abs(x+10/27) <1/81)+(abs(x+14/27) <1/81)+(abs(x+8/9) <1/81)+(abs(x+22/27) <1/81)+(abs(x+26/27) <1/81)+(abs(x) <1/81)+(abs(x-2/27) <1/81)+(abs(x+2/27) <1/81)+(abs(x-2/9) <1/81)+(abs(x-8/27) <1/81)+(abs(x-4/27) <1/81)+(abs(x+2/9) <1/81)+(abs(x+4/27) <1/81)+(abs(x+8/27) <1/81))",
                "Ay = ((abs(y-2/3) <1/81)+(abs(y-20/27) <1/81)+(abs(y-16/27) <1/81)+(abs(y-8/9) <1/81)+(abs(y-26/27) <1/81)+(abs(y-22/27) <1/81)+(abs(y-4/9) <1/81)+(abs(y-14/27) <1/81)+(abs(y-10/27) <1/81)+(abs(y+2/3) <1/81)+(abs(y+16/27) <1/81)+(abs(y+20/27) <1/81)+(abs(y+4/9) <1/81)+(abs(y+10/27) <1/81)+(abs(y+14/27) <1/81)+(abs(y+8/9) <1/81)+(abs(y+22/27) <1/81)+(abs(y+26/27) <1/81)+(abs(y) <1/81)+(abs(y-2/27) <1/81)+(abs(y+2/27) <1/81)+(abs(y-2/9) <1/81)+(abs(y-8/27) <1/81)+(abs(y-4/27) <1/81)+(abs(y+2/9) <1/81)+(abs(y+4/27) <1/81)+(abs(y+8/27) <1/81))",
                "Az = ((abs(z-2/3) <1/81)+(abs(z-20/27) <1/81)+(abs(z-16/27) <1/81)+(abs(z-8/9) <1/81)+(abs(z-26/27) <1/81)+(abs(z-22/27) <1/81)+(abs(z-4/9) <1/81)+(abs(z-14/27) <1/81)+(abs(z-10/27) <1/81)+(abs(z+2/3) <1/81)+(abs(z+16/27) <1/81)+(abs(z+20/27) <1/81)+(abs(z+4/9) <1/81)+(abs(z+10/27) <1/81)+(abs(z+14/27) <1/81)+(abs(z+8/9) <1/81)+(abs(z+22/27) <1/81)+(abs(z+26/27) <1/81)+(abs(z) <1/81)+(abs(z-2/27) <1/81)+(abs(z+2/27) <1/81)+(abs(z-2/9) <1/81)+(abs(z-8/27) <1/81)+(abs(z-4/27) <1/81)+(abs(z+2/9) <1/81)+(abs(z+4/27) <1/81)+(abs(z+8/27) <1/81))",
                "Bx = ((abs(x-2/3) <1/27)+(abs(x-8/9) <1/27)+(abs(x-4/9) <1/27)+(abs(x+2/3) <1/27)+(abs(x+4/9) <1/27)+(abs(x+8/9) <1/27)+(abs(x) <1/27)+(abs(x-2/9) <1/27)+(abs(x+2/9) <1/27))",
                "By = ((abs(y-2/3) <1/27)+(abs(y-8/9) <1/27)+(abs(y-4/9) <1/27)+(abs(y+2/3) <1/27)+(abs(y+4/9) <1/27)+(abs(y+8/9) <1/27)+(abs(y) <1/27)+(abs(y-2/9) <1/27)+(abs(y+2/9) <1/27))",
                "Bz = ((abs(z-2/3) <1/27)+(abs(z-8/9) <1/27)+(abs(z-4/9) <1/27)+(abs(z+2/3) <1/27)+(abs(z+4/9) <1/27)+(abs(z+8/9) <1/27)+(abs(z) <1/27)+(abs(z-2/9) <1/27)+(abs(z+2/9) <1/27))",
                "Cx = ((abs(x-2/3) <1/9)+(abs(x+2/3) <1/9)+(abs(x) <1/9))",
                "Cy = ((abs(y-2/3) <1/9)+(abs(y+2/3) <1/9)+(abs(y) <1/9))",
                "Cz = ((abs(z-2/3) <1/9)+(abs(z+2/3) <1/9)+(abs(z) <1/9))",
                "Dx = x^100",
                "Dy = y^100",
                "Dz = z^100"],
            "Fxyz": ["-(Dx(x,y,z,t)+Dy(x,y,z,t)+Dz(x,y,z,t)-1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*((Cx(x,y,z,t)*(Cy(x,y,z,t)+Cz(x,y,z,t))+Cz(x,y,z,t)*Cy(x,y,z,t)) =0)*((Bx(x,y,z,t)*(By(x,y,z,t)+Bz(x,y,z,t))+Bz(x,y,z,t)*By(x,y,z,t)) =0)*((Ax(x,y,z,t)*(Ay(x,y,z,t)+Az(x,y,z,t))+Az(x,y,z,t)*Ay(x,y,z,t)) =0)) "],
            "Xmax": ["(1001/1000)"],
            "Xmin": ["-(1001/1000)"],
            "Ymax": ["(1001/1000)"],
            "Ymin": ["-(1001/1000)"],
            "Zmax": ["(1001/1000)"],
            "Zmin": ["-(1001/1000)"]
        }
    },
    {
    "Iso3D": {
        "Component": [
            "MengerSponge_H",
            "MengerSponge_0H",
            "MengerSponge_H",
            "MengerSponge_H",
            "MengerSponge_H",
            "MengerSponge_H",
            "MengerSponge_H",
            "MengerSponge_H",
            "MengerSponge_L",
            "MengerSponge_L",
            "MengerSponge_L",
            "MengerSponge_L",
            "MengerSponge_L",
            "MengerSponge_L",
            "MengerSponge_L",
            "MengerSponge_L",
            "MengerSponge_M",
            "MengerSponge_M",
            "MengerSponge_M",
            "MengerSponge_M"],
        "Const": [
            "th=5/1000",
            "L=1001/1000",
            "2L=2*L"],
        "Description ": [
            "Hexagrams Menger L5 by Abderrahman Taha 18/01/2022"
        ],
        "Funct": [
            "Ax=((abs(x-2/3)<1/81)+(abs(x-20/27)<1/81)+(abs(x-16/27)<1/81)+(abs(x-8/9)<1/81)+(abs(x-26/27)<1/81)+(abs(x-22/27)<1/81)+(abs(x-4/9)<1/81)+(abs(x-14/27)<1/81)+(abs(x-10/27)<1/81)+(abs(x+2/3)<1/81)+(abs(x+16/27)<1/81)+(abs(x+20/27)<1/81)+(abs(x+4/9)<1/81)+(abs(x+10/27)<1/81)+(abs(x+14/27)<1/81)+(abs(x+8/9)<1/81)+(abs(x+22/27)<1/81)+(abs(x+26/27)<1/81)+(abs(x)<1/81)+(abs(x-2/27)<1/81)+(abs(x+2/27)<1/81)+(abs(x-2/9)<1/81)+(abs(x-8/27)<1/81)+(abs(x-4/27)<1/81)+(abs(x+2/9)<1/81)+(abs(x+4/27)<1/81)+(abs(x+8/27)<1/81))",
            "Ay=((abs(y-2/3)<1/81)+(abs(y-20/27)<1/81)+(abs(y-16/27)<1/81)+(abs(y-8/9)<1/81)+(abs(y-26/27)<1/81)+(abs(y-22/27)<1/81)+(abs(y-4/9)<1/81)+(abs(y-14/27)<1/81)+(abs(y-10/27)<1/81)+(abs(y+2/3)<1/81)+(abs(y+16/27)<1/81)+(abs(y+20/27)<1/81)+(abs(y+4/9)<1/81)+(abs(y+10/27)<1/81)+(abs(y+14/27)<1/81)+(abs(y+8/9)<1/81)+(abs(y+22/27)<1/81)+(abs(y+26/27)<1/81)+(abs(y)<1/81)+(abs(y-2/27)<1/81)+(abs(y+2/27)<1/81)+(abs(y-2/9)<1/81)+(abs(y-8/27)<1/81)+(abs(y-4/27)<1/81)+(abs(y+2/9)<1/81)+(abs(y+4/27)<1/81)+(abs(y+8/27)<1/81))",
            "Az=((abs(z-2/3)<1/81)+(abs(z-20/27)<1/81)+(abs(z-16/27)<1/81)+(abs(z-8/9)<1/81)+(abs(z-26/27)<1/81)+(abs(z-22/27)<1/81)+(abs(z-4/9)<1/81)+(abs(z-14/27)<1/81)+(abs(z-10/27)<1/81)+(abs(z+2/3)<1/81)+(abs(z+16/27)<1/81)+(abs(z+20/27)<1/81)+(abs(z+4/9)<1/81)+(abs(z+10/27)<1/81)+(abs(z+14/27)<1/81)+(abs(z+8/9)<1/81)+(abs(z+22/27)<1/81)+(abs(z+26/27)<1/81)+(abs(z)<1/81)+(abs(z-2/27)<1/81)+(abs(z+2/27)<1/81)+(abs(z-2/9)<1/81)+(abs(z-8/27)<1/81)+(abs(z-4/27)<1/81)+(abs(z+2/9)<1/81)+(abs(z+4/27)<1/81)+(abs(z+8/27)<1/81))",
            "Bx=((abs(x-2/3)<1/27)+(abs(x-8/9)<1/27)+(abs(x-4/9)<1/27)+(abs(x+2/3)<1/27)+(abs(x+4/9)<1/27)+(abs(x+8/9)<1/27)+(abs(x)<1/27)+(abs(x-2/9)<1/27)+(abs(x+2/9)<1/27))",
            "By=((abs(y-2/3)<1/27)+(abs(y-8/9)<1/27)+(abs(y-4/9)<1/27)+(abs(y+2/3)<1/27)+(abs(y+4/9)<1/27)+(abs(y+8/9)<1/27)+(abs(y)<1/27)+(abs(y-2/9)<1/27)+(abs(y+2/9)<1/27))",
            "Bz=((abs(z-2/3)<1/27)+(abs(z-8/9)<1/27)+(abs(z-4/9)<1/27)+(abs(z+2/3)<1/27)+(abs(z+4/9)<1/27)+(abs(z+8/9)<1/27)+(abs(z)<1/27)+(abs(z-2/9)<1/27)+(abs(z+2/9)<1/27))",
            "Cx=((abs(x-2/3)<1/9)+(abs(x+2/3)<1/9)+(abs(x)<1/9))",
            "Cy=((abs(y-2/3)<1/9)+(abs(y+2/3)<1/9)+(abs(y)<1/9))",
            "Cz=((abs(z-2/3)<1/9)+(abs(z+2/3)<1/9)+(abs(z)<1/9))",
            "Dx=x^100",
            "Dy=y^100",
            "Dz=z^100",
            "Menger=-(Dx(x,y,z,t)+Dy(x,y,z,t)+Dz(x,y,z,t)-1)*(((abs(x)>1/3|abs(y)>1/3)*(abs(z)>1/3|abs(y)>1/3)*(abs(x)>1/3|abs(z)>1/3))*((Cx(x,y,z,t)*(Cy(x,y,z,t)+Cz(x,y,z,t))+Cz(x,y,z,t)*Cy(x,y,z,t))=0)*((Bx(x,y,z,t)*(By(x,y,z,t)+Bz(x,y,z,t))+Bz(x,y,z,t)*By(x,y,z,t))=0)*((Ax(x,y,z,t)*(Ay(x,y,z,t)+Az(x,y,z,t))+Az(x,y,z,t)*Ay(x,y,z,t))=0))"
        ],
        "Fxyz": [
            "if(abs(x+y+z)<th,Menger(x-2*L,y,z-2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x+2*L,y,z-2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x,y-2*L,z-2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x,y+2*L,z-2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x+2*L,y+2*L,z-2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x+2*L,y-2*L,z-2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x-2*L,y+2*L,z-2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x-2*L,y-2*L,z-2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x-2*L,y,z+2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x+2*L,y,z+2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x,y-2*L,z+2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x,y+2*L,z+2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x+2*L,y+2*L,z+2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x+2*L,y-2*L,z+2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x-2*L,y+2*L,z+2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x-2*L,y-2*L,z+2*L,t),(0))",
            "if(abs(x+y+z)<th,Menger(x-2*L,y-2*L,z,t),(0))",
            "if(abs(x+y+z)<th,Menger(x-2*L,y+2*L,z,t),(0))",
            "if(abs(x+y+z)<th,Menger(x+2*L,y+2*L,z,t),(0))",
            "if(abs(x+y+z)<th,Menger(x+2*L,y-2*L,z,t),(0))"
        ],
        "Name": ["Hexagrams_Menger_L5"
        ],
        "Xmax": [
            "L+2*L",
            "L-2*L",
            "L",
            "L",
            "L-2*L",
            "L-2*L",
            "L+2*L",
            "L+2*L",
            "L+2*L",
            "L-2*L",
            "L",
            "L",
            "L-2*L",
            "L-2*L",
            "L+2*L",
            "L+2*L",
            "L+2*L",
            "L+2*L",
            "L-2*L",
            "L-2*L"
        ],
        "Xmin": [
            "-L+2*L",
            "-L-2*L",
            "-L",
            "-L",
            "-L-2*L",
            "-L-2*L",
            "-L+2*L",
            "-L+2*L",
            "-L+2*L",
            "-L-2*L",
            "-L",
            "-L",
            "-L-2*L",
            "-L-2*L",
            "-L+2*L",
            "-L+2*L",
            "-L+2*L",
            "-L+2*L",
            "-L-2*L",
            "-L-2*L"
        ],
        "Ymax": [
            "L",
            "L",
            "L+2*L",
            "L-2*L",
            "L-2*L",
            "L+2*L",
            "L-2*L",
            "L+2*L",
            "L",
            "L",
            "L+2*L",
            "L-2*L",
            "L-2*L",
            "L+2*L",
            "L-2*L",
            "L+2*L",
            "L+2*L",
            "L-2*L",
            "L-2*L",
            "L+2*L"
        ],
        "Ymin": [
            "-L",
            "-L",
            "-L+2*L",
            "-L-2*L",
            "-L-2*L",
            "-L+2*L",
            "-L-2*L",
            "-L+2*L",
            "-L",
            "-L",
            "-L+2*L",
            "-L-2*L",
            "-L-2*L",
            "-L+2*L",
            "-L-2*L",
            "-L+2*L",
            "-L+2*L",
            "-L-2*L",
            "-L-2*L",
            "-L+2*L"
        ],
        "Zmax": [
            "L+2*L",
            "L+2*L",
            "L+2*L",
            "L+2*L",
            "L+2*L",
            "L+2*L",
            "L+2*L",
            "L+2*L",
            "L-2*L",
            "L-2*L",
            "L-2*L",
            "L-2*L",
            "L-2*L",
            "L-2*L",
            "L-2*L",
            "L-2*L",
            "L",
            "L",
            "L",
            "L"
        ],
        "Zmin": [
            "-L+2*L",
            "-L+2*L",
            "-L+2*L",
            "-L+2*L",
            "-L+2*L",
            "-L+2*L",
            "-L+2*L",
            "-L+2*L",
            "-L-2*L",
            "-L-2*L",
            "-L-2*L",
            "-L-2*L",
            "-L-2*L",
            "-L-2*L",
            "-L-2*L",
            "-L-2*L",
            "-L",
            "-L",
            "-L",
            "-L"
        ]
    }
},
 {
      "Param3D": {
        "Description ": ["Virus by Abderrahman Taha 15/05/2020"],
        "Name": ["Virus_2"],
        "Component": ["Virus"],
        "Funct": ["Thickness=-(3/10)*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/(9/5))^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/(19/10))^(11/2))",
          "n1= (-(cos(u))*(cos(u)*cos(v)))",
          "n2= ((cos(u))*(-sin(v)*cos(u)))",
          "n3= ((-sin(u)*cos(v))*(cos(u)*cos(v))-(-sin(u)*sin(v))*(-sin(v)*cos(u)))",
          "Sq= (u/sqrt(u*u+v*v+t*t))",
          "R=1/sqrt(u*u+v*v+t*t)",
          "Gx=cos(u)*cos(v)+Thickness(u,v,t)*Sq(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=cos(u)*sin(v)+Thickness(u,v,t)*Sq(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=sin(u)+Thickness(u,v,t)*Sq(n3(u,v,t),n1(u,v,t),n2(u,v,t))",
          "Hx=n1(u,v,t)*(n1(u,v,t)*Gx(u,v,t)+n2(u,v,t)*Gy(u,v,t)+n3(u,v,t)*Gz(u,v,t))*(1-cos(2*pi*Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))))+Gx(u,v,t)*cos(2*pi*Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t)))+(-n3(u,v,t)*Gy(u,v,t)+n2(u,v,t)*Gz(u,v,t))*sin(2*pi*Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t)))",
          "Hy = n2(u,v,t)*(n1(u,v,t)*Gx(u,v,t)+n2(u,v,t)*Gy(u,v,t)+n3(u,v,t)*Gz(u,v,t))*(1-cos(2*pi*Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))))+Gy(u,v,t)*cos(2*pi*Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t)))+(n3(u,v,t)*Gx(u,v,t)-n1(u,v,t)*Gz(u,v,t))*sin(2*pi*Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t)))",
          "Hz=n3(u,v,t)*(n1(u,v,t)*Gx(u,v,t)+n2(u,v,t)*Gy(u,v,t)+n3(u,v,t)*Gz(u,v,t))*(1-cos(2*pi*Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))))+Gz(u,v,t)*cos(2*pi*Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t)))+(-n2(u,v,t)*Gx(u,v,t)+n1(u,v,t)*Gy(u,v,t))*sin(2*pi*Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))) "],
        "Fx": ["Hx(u,v,t)"],
        "Fy": ["Hy(u,v,t)"],
        "Fz": ["Hz(u,v,t)"],
        "Umax": ["pi/2"],
        "Umin": ["-pi/2"],
        "Vmax": ["pi"],
        "Vmin": ["-pi"]
      },
      "Texture": {
        "Colors": ["R=(9/10)",
          "G=(3/2)*abs(cos((x*x+y*y+z*z)/3)*sin((x*x+y*y+z*z)/3))",
          "B=(1/5)*abs(cos((x*x+y*y+z*z)/3)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/3))",
          "T=1"],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(8*x,8*y,8*z,(4),(2),0)+NoiseW(8*x,8*y,8*z,(4),(12),1/10)"
      }
    },
    {
        "Param3D": {
            "Component": ["Star"],
            "Const": ["cu=1/10000","cv=1/10000","N=5"],
            "Description ": ["Star by Abderrahman Taha 12/09/2018"],
            "Funct": ["Thickness= ((sin(15*u)*cos(15*u)))^4+(sin(2*N*v))",
                "Fx=-cos(u+v)/(sqrt(2)+cos(v-u))",
                "Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
                "Fz=sin(u+v)/(sqrt(2)+cos(v-u))",
                "DFxu=((Fx(u,v,t)-Fx(u+cu,v,t))/cu)",
                "DFxv=((Fx(u,v,t)-Fx(u,v+cv,t))/cv)",
                "DFyu=((Fy(u,v,t)-Fy(u+cu,v,t))/cu)",
                "DFyv=((Fy(u,v,t)-Fy(u,v+cv,t))/cv)",
                "DFzu=((Fz(u,v,t)-Fz(u+cu,v,t))/cu)",
                "DFzv=((Fz(u,v,t)-Fz(u,v+cv,t))/cv)",
                "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
                "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
                "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
                "Rapp=u/(u*u+v*v+t*t)",
                "Gx=Fx(u,v,t)+Thickness(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
                "Gy=Fy(u,v,t)+Thickness(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
                "Gz=Fz(u,v,t)+Thickness(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
            "Fx": ["Gx(u,v,t)"],
            "Fy": ["Gy(u,v,t)"],
            "Fz": ["Gz(u,v,t)"],
            "Name": ["Star_2"],
            "Umax": ["pi"],
            "Umin": ["0"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        }
    },
    {
      "Param3D": {
        "Description ": ["Star by Abderrahman Taha 23/10/2015"],
        "Name": ["Star_3"],
        "Component": ["Star"],
        "Const": ["cu=1/10000","cv=1/10000","N=5"],
        "Funct": [
          "Thickness= ((sin(15*u)*cos(15*v)))^4+(sin(2*N*u))",
          "Fx=-cos(u+v)/(sqrt(2)+cos(v-u))",
          "Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2)+cos(v-u))",
          "DFxu=((Fx(u,v,t)-Fx(u+cu,v,t))/cu)",
          "DFxv=((Fx(u,v,t)-Fx(u,v+cv,t))/cv)",
          "DFyu=((Fy(u,v,t)-Fy(u+cu,v,t))/cu)",
          "DFyv=((Fy(u,v,t)-Fy(u,v+cv,t))/cv)",
          "DFzu=((Fz(u,v,t)-Fz(u+cu,v,t))/cu)",
          "DFzv=((Fz(u,v,t)-Fz(u,v+cv,t))/cv)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=(sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2))^2",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Iso3D": {
        "Description ": ["The Beginning by Abderrahman Taha 21/10/2015"],
        "Name": ["The Beginning"],
        "Component": ["TheBeginning1","TheBeginning2"],
        "Funct": ["tail=x^2+y^2+z^2-(1/10)*t",
          "tail2=(x+sin(5*pi*y/20))^2+(y/10)^2+(z)^2-1",
          "tail3=tail2((x*30),(y*30-30),(z*30),1)"],
        "Fxyz": ["-((x^2+y^2+z^2-1)+(NoiseW(6*x,6*y,6*z,(4),(2),(0))+NoiseW(6*x,6*y,6*z,(4),(0),(0)))/5)*(atan2(y,x)<(pi/2) | atan2(sqrt(x*x+y*y),z)>(pi/2))*tail(x,y,z,1)",
          "tail3(x*cos(-pi/4)-y*sin(-pi/4),x*sin(-pi/4)+y*cos(-pi/4),z,t)"],
        "Xmax": ["1","-(1/2)"],
        "Xmin": ["-1","-1"],
        "Ymax": ["1","(7/5)"],
        "Ymin": ["-1","(1/2)"],
        "Zmax": ["1","(1/10)"],
        "Zmin": ["-1","-(1/10)"]
      },
      "Texture": {
        "Colors": ["R=(3/5)",
          "G=(12/5)*(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))*sin((x*x+y*y+z*z)/2)",
          "B=(7/10)*(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(2*x,2*y,2*z,(4),(0),(0))+NoiseW(2*x,2*y,2*z,(2),(0),(0))"
      }
    },
    {
      "Param3D": {
        "Description ": ["Space Ship by Abderrahman Taha 20/10/2015"],
        "Name": ["Space Ship_1"],
        "Component": ["SpaceShip"],
        "Const": ["cu=(1/1000000)","cv=(1/1000000)","N1=16","N2=11","N3=6"],
        "Funct": ["Thickness= ((1/5)*(abs(sin(N1*u)*cos(N2*v)))^7+(1/5)*((sin(N3*u))))",
          "Fx=-(abs(u)-1)^2*cos(v)",
          "Fy=u",
          "Fz=(abs(u)-1)^2*sin(v)",
          "DFxu=((Fx(u,v,t)-Fx(u+cu,v,t))/cu)",
          "DFxv=((Fx(u,v,t)-Fx(u,v+cv,t))/cv)",
          "DFyu=((Fy(u,v,t)-Fy(u+cu,v,t))/cu)",
          "DFyv=((Fy(u,v,t)-Fy(u,v+cv,t))/cv)",
          "DFzu=((Fz(u,v,t)-Fz(u+cu,v,t))/cu)",
          "DFzv=((Fz(u,v,t)-Fz(u,v+cv,t))/cv)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2+cu*cv)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["1"],
        "Umin": ["-1"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Space Ship by Abderrahman Taha 20/10/2015"],
        "Name": ["Space Ship_2"],
        "Component": ["SpaceShip"],
        "Const": ["cu=(1/1000000)","cv=(1/1000000)","N1=12","N2=7","N3=5"],
        "Funct": ["Thickness= ((1/5)*(abs(sin(N1*u)*cos(N2*v)))^6+(1/100)*((sin(N3*u))))",
          "Fx=-(abs(u)-1)^2*cos(v)",
          "Fy=u",
          "Fz=(abs(u)-1)^2*sin(v)",
          "DFxu=((Fx(u,v,t)-Fx(u+cu,v,t))/cu)",
          "DFxv=((Fx(u,v,t)-Fx(u,v+cv,t))/cv)",
          "DFyu=((Fy(u,v,t)-Fy(u+cu,v,t))/cu)",
          "DFyv=((Fy(u,v,t)-Fy(u,v+cv,t))/cv)",
          "DFzu=((Fz(u,v,t)-Fz(u+cu,v,t))/cu)",
          "DFzv=((Fz(u,v,t)-Fz(u,v+cv,t))/cv)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2+cu*cv)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["1"],
        "Umin": ["-1"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Space Ship by Abderrahman Taha 20/10/2015"],
        "Name": ["Space Ship_3"],
        "Component": ["SpaceShip"],
        "Const": ["N1=12","N2=7","N3=5","c=(1/1000000)"],
        "Funct": ["Thickness=-((1/5)*(abs(sin(N1*u)*cos(N2*v)))^6+(1/100)*((sin(N3*u))))",
          "Fx=-(abs(u)-1)^2*cos(v)",
          "Fy=u",
          "Fz=(abs(u)-1)^2*sin(v)",
          "DFxu=((Fx(u,v,t)-Fx(u+c,v,t))/c)",
          "DFxv=((Fx(u,v,t)-Fx(u,v+c,t))/c)",
          "DFyu=((Fy(u,v,t)-Fy(u+c,v,t))/c)",
          "DFyv=((Fy(u,v,t)-Fy(u,v+c,t))/c)",
          "DFzu=((Fz(u,v,t)-Fz(u+c,v,t))/c)",
          "DFzv=((Fz(u,v,t)-Fz(u,v+c,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "Rapp=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["1"],
        "Umin": ["-1"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Lumpet Tori by Abderrahman Taha 10/10/2015"],
        "Name": ["Lumpet Tori"],
        "Component": ["LumpetTori"],
        "Const": ["cu=(1/10000)","cv=(1/10000)"],
        "Funct": ["Thickness= (1/5)*(abs(sin(14*u)*cos(14*v)))^9+(2/5)*((sin(8*u)))",
          "Fx=-cos(u)/(sqrt(2)+sin(v))",
          "Fy=1/(sqrt(2)+cos(v))",
          "Fz=sin(u)/(sqrt(2)+sin(v))",
          "DFxu=((Fx(u,v,t)-Fx(u+cu,v,t))/cu)",
          "DFxv=((Fx(u,v,t)-Fx(u,v+cv,t))/cv)",
          "DFyu=((Fy(u,v,t)-Fy(u+cu,v,t))/cu)",
          "DFyv=((Fy(u,v,t)-Fy(u,v+cv,t))/cv)",
          "DFzu=((Fz(u,v,t)-Fz(u+cu,v,t))/cu)",
          "DFzv=((Fz(u,v,t)-Fz(u,v+cv,t))/cv)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["pi"],
        "Umin": ["-pi"],
        "Vmax": ["pi"],
        "Vmin": ["-pi"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Sphere modelling by Abderrahman Taha 18/10/2015"],
        "Name": ["Sphere modelling"],
        "Component": ["Sphere modelling1","SphereModelling2"],
        "Const": ["cu=(1/100000)","cv=(1/100000)","N=(3/2)"],
        "Funct": ["Thickness1=if((t = 1),-if (sin(u*(sin(14*v-10*u))) <(2/5),(-1),(1/5)*(13*u-pi)*(cos(u)-sin(u))),-if (sin(u*(sin(14*v-10*u))) >(2/5),(-1),(1/5)*(13*u-pi)*(cos(u)-sin(u))))",
          "Fx=cos(u)*cos(v)",
          "Fy=sin(u)",
          "Fz=cos(u)*sin(v)",
          "DFxu=((Fx(u,v,t)-Fx(u+cu,v,t))/cu)",
          "DFxv=((Fx(u,v,t)-Fx(u,v+cv,t))/cv)",
          "DFyu=((Fy(u,v,t)-Fy(u+cu,v,t))/cu)",
          "DFyv=((Fy(u,v,t)-Fy(u,v+cv,t))/cv)",
          "DFzu=((Fz(u,v,t)-Fz(u+cu,v,t))/cu)",
          "DFzv=((Fz(u,v,t)-Fz(u,v+cv,t))/cv)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)",
          "Gx=Fx(u,v,t)+Thickness1(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness1(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness1(u,v,t)*n3(u,v,t)/R(u,v,t)"],
        "Fx": ["Gx(u,v,1)","Gx(u,v,0)"],
        "Fy": ["Gy(u,v,1)","Gy(u,v,0)"],
        "Fz": ["Gz(u,v,1)","Gz(u,v,0)"],
        "Umax": ["pi/2","pi/2"],
        "Umin": ["-pi/2","-pi/2"],
        "Vmax": ["2*pi","2*pi"],
        "Vmin": ["0","0"]
      }
    },
    {
      "Iso3D": {
        "Description ": ["The lamp by Abderrahman Taha 18/10/2015"],
        "Name": ["Lamp"],
        "Component": ["Lamp"],
        "Funct": ["Hyperboloid=x^2+y^2-z^2-(1/10)",
          "Intersection=max(Hyperboloid(x,y,(z*3),1),Hyperboloid((x*3),(z*3),(y*3),2))",
          "Intersection2=max(Hyperboloid(x,y,(z+5),1),Hyperboloid(x,y,(z-5),1))",
          "Cylinders=((sqrt((x-(9/2))*(x-(9/2))+z*z)-(5/2))^2+y*y-(1/4))*((sqrt((x+(9/2))*(x+(9/2))+z*z)-(5/2))^2+y*y-(1/4))*((sqrt((y+(9/2))*(y+(9/2))+z*z)-(5/2))^2+x*x-(1/4))*((sqrt((y-(9/2))*(y-(9/2))+z*z)-(5/2))^2+x*x-(1/4))*((sqrt(x*x+y*y)-5)^2+z*z-(1/4))*((sqrt(x*x+y*y)-1)^2+(z-(585/100))*(z-(585/100))-(1/50))"],
        "Fxyz": ["(Intersection2(x,y,z,t)*Cylinders(x,y,z,t))-50000"],
        "Xmax": ["(17/2)"],
        "Xmin": ["-(17/2)"],
        "Ymax": ["(17/2)"],
        "Ymin": ["-(17/2)"],
        "Zmax": ["6"],
        "Zmin": ["-6"]
      },
      "Texture": {
        "Colors": ["R=(22/25)*abs(cos(z*y*x))",
          "G=(2/5)*abs(cos(z*y*x))",
          "B=(1/50)*abs(cos(-z*x*z*x*y*y))",
          "T=1"],
        "Name": "Granit_1",
        "Noise": "NoiseP((x-14),(y-17),(z-16),(10),(7),(2/10))*(10/11)"
      }
    },
    {
      "Iso3D": {
        "Description ": ["Pseudo 4-Noids by Abderrahman Taha 12/10/2015"],
        "Name": ["Pseudo 4-Noids_0"],
        "Component": ["Pseudo-4-Noids"],
        "Fxyz": ["((x^2)-(685/1000)*(y)^2)^2-(5/2)*(z)^2-(x^2+(3/4)*abs(y*cos((3/10)*x)-z*sin((3/5)*x))^2+(y*sin((3/2)*x)+z*cos((1/20)*x))^2-(1/2))"],
        "Xmax": ["(19/10)"],
        "Xmin": ["-(19/10)"],
        "Ymax": ["(3/2)"],
        "Ymin": ["-(3/2)"],
        "Zmax": ["(9/5)"],
        "Zmin": ["-(9/5)"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Pseudo Hopf Tori by Abderrahman Taha 14/10/2019"],
        "Name": ["Pseudo Hopf Tori"],
        "Component": ["PseudoHopfTori"],
        "Const": ["c=1/100000","N=3"],
        "Funct": ["Thickness= (abs(sin(15*u)*cos(15*v)))^7+(4/10)*((sin(2*N*u)))",
          "Fx=-cos(u+v)/(sqrt(2)+cos(v-u))",
          "Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2)+cos(v-u))",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u^2+v^2+t^2)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Embedding of the Square Flat Torus (Level 3 ) by Abderrahman Taha 14/10/2019"],
        "Name": ["Embedded Square Flat Torus L3"],
        "Component": ["EmbeddedSquareFlatTorus"],
        "Const": ["c=1/1000","N=10"],
        "Funct": ["Thickness2=if(sin(N*u)>(0),(5/10)*t*((sin(N*u)))^(1/4),-(5/10)*t*(abs(sin(N*u)))^(1/4)) ",
          "Thickness= Thickness2(u,v,1)+Thickness2(15*v-5*u,v,(5/100))",
          "Fx=(4+2*cos(u))*cos(v)",
          "Fy=2*sin(u)",
          "Fz=(4+2*cos(u))*sin(v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u^2+v^2+t^2)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Embedding of the Square Flat Torus (Level 2 ) by Abderrahman Taha 14/10/2019"],
        "Name": ["Embedded Square Flat Torus L2"],
        "Component": ["EmbeddedSquareFlatTorus"],
        "Const": ["c=1/1000","N=10"],
        "Funct": ["Thickness=if(sin(N*u)>(0),(5/10)*((sin(N*u)))^(1/4),-(5/10)*(abs(sin(N*u)))^(1/4)) ",
          "Fx=(4+2*cos(u))*cos(v)",
          "Fy=2*sin(u)",
          "Fz=(4+2*cos(u))*sin(v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u^2+v^2+t^2)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Alien by Abderrahman Taha 10/10/2015"],
        "Name": ["Alien"],
        "Component": ["Alien"],
        "Const": ["cu=(1/10000)","cv=(1/10000)"],
        "Funct": ["Fx=-cos(u)*(3*cos(v)-cos(3*v))",
          "Fy= 3*sin(v)-sin(3*v)",
          "Fz= sin(u)*(3*cos(v)-cos(3*v))",
          "DFxu= ((Fx(u,v,t)-Fx(u+cu,v,t))/cu)",
          "DFxv= ((Fx(u,v,t)-Fx(u,v+cv,t))/cv)",
          "DFyu= ((Fy(u,v,t)-Fy(u+cu,v,t))/cu)",
          "DFyv= ((Fy(u,v,t)-Fy(u,v+cv,t))/cv)",
          "DFzu= ((Fz(u,v,t)-Fz(u+cu,v,t))/cu)",
          "DFzv= ((Fz(u,v,t)-Fz(u,v+cv,t))/cv)",
          "n1= (DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2= (DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3= (DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)",
          "Thickness= ((2/5)*abs(cos(11*(u))^2-sin(13*(v))^5 ))^3",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/(R(u,v,t)+(1/10000))",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/(R(u,v,t)+(1/10000))",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/(R(u,v,t)+(1/10000))"],
        "Fx": ["Gx(u*cos(v),v*sin(u),t)"],
        "Fy": ["Gy(u*cos(v),v*sin(u),t)"],
        "Fz": ["Gz(u*cos(v),v*sin(u),t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["pi/2"],
        "Vmin": ["-pi/2"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Shells by Abderrahman Taha 14/10/2019"],
        "Name": ["Shells_1"],
        "Component": ["Shells"],
        "Const": ["c=1/10000"],
        "Funct": ["Fx=-cos(u)*(3*cos(v)-cos(3*v))",
          "Fy= 3*sin(v)-sin(3*v)",
          "Fz= sin(u)*(3*cos(v)-cos(3*v))",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1= (DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2= (DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3= (DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "Ra=u/(sqrt(u^2+v^2+t^2)+c/10000)",
          "Th=((4/10)*abs(cos(11*(u))^2-sin(13*(v))^5))^3",
          "Gx=Fx(u,v,t)+Th(u,v,t)*Ra(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*Ra(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*Ra(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["pi/2"],
        "Vmin": ["-pi/2"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Spiny Torus by Abderrahman Taha 09/10/2015"],
        "Name": ["Spiny Torus"],
        "Component": ["SpinyTorus"],
        "Funct": ["Thickness=-((27/100)*abs(cos(11*(u+v))^2-sin(13*(v-u))^5 ))^(29/10)"],
        "Fx": ["-(1+(1/2)*cos(u))*cos(v)+Thickness(u,v,t)*((1/2)*cos(u)*(1+(1/2)*cos(u))*cos(v))/sqrt(((1/2)*cos(u)*(1+(1/2)*cos(u))*cos(v))^2+(-(1/2)*sin(u)*sin(v)*sin(v)*(1+(1/2)*cos(u))-(1/2)*sin(u)*cos(v)*(1+(1/2)*cos(u))*cos(v))^2+(-(1/2)*cos(u)*sin(v)*(1+(1/2)*cos(u)))^2)"],
        "Fy": ["(1/2)*sin(u)+Thickness(u,v,t)*(-(1/2)*sin(u)*sin(v)*sin(v)*(1+(1/2)*cos(u))-(1/2)*sin(u)*cos(v)*(1+(1/2)*cos(u))*cos(v))/sqrt(((1/2)*cos(u)*(1+(1/2)*cos(u))*cos(v))^2+(-(1/2)*sin(u)*sin(v)*sin(v)*(1+(1/2)*cos(u))-(1/2)*sin(u)*cos(v)*(1+(1/2)*cos(u))*cos(v))^2+(-(1/2)*cos(u)*sin(v)*(1+(1/2)*cos(u)))^2)"],
        "Fz": ["(1+(1/2)*cos(u))*sin(v)+Thickness(u,v,t)*(-(1/2)*cos(u)*sin(v)*(1+(1/2)*cos(u)))/sqrt(((1/2)*cos(u)*(1+(1/2)*cos(u))*cos(v))^2+(-(1/2)*sin(u)*sin(v)*sin(v)*(1+(1/2)*cos(u))-(1/2)*sin(u)*cos(v)*(1+(1/2)*cos(u))*cos(v))^2+(-(1/2)*cos(u)*sin(v)*(1+(1/2)*cos(u)))^2)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Holed Spheres (implicit version) by Abderrahman Taha 2/10/2019"],
        "Name": ["Holed_Sphere"],
        "Component": ["HoledSphere"],
        "Const": ["c=1/100000","L=(12/10)"],
        "Funct": ["Iso=x*x+y*y+z*z-1",
          "Th=(cos((abs(cos(21*atan2(x,y))+sin(19*atan2(z,sqrt(x*x+y*y)))))^2)/20)",
          "DFx=((Iso(x+c,y,z,t)-Iso(x,y,z,t))/c)",
          "DFy=((Iso(x,y+c,z,t)-Iso(x,y,z,t))/c)",
          "DFz=((Iso(x,y,z+c,t)-Iso(x,y,z,t))/c)",
          "R=(x/sqrt(x*x+y*y+z*z))",
          "Iso2=(Iso(x-Th(x,y,z,t)*R(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-Th(x,y,z,t)*R(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z-Th(x,y,z,t)*R(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))",
          "ThickIso=max(Iso2(x,y,z,1),Iso2(x,y,z,-1))"],
        "Fxyz": ["-max(Iso2(x,y,z,1),(x*x+y*y+z*z-1))*Iso2(x,y,z,1)"],
        "Xmax": ["L"],
        "Xmin": ["-L"],
        "Ymax": ["L"],
        "Ymin": ["-L"],
        "Zmax": ["L"],
        "Zmin": ["-L"]
      }
    },
        {
        "Param3D": {
        "Description ": ["Clifford Torus with spines (urchin) by Abderrahman Taha 11/10/2019"],
        "Name": ["Urchin"],
        "Funct": ["Fx=-(cos(u+v)/(sqrt(2)+cos(v-u)))","Fy=sin(v-u)/(sqrt(2)+cos(v-u))","Fz=sin(u+v)/(sqrt(2)+cos(v-u))","DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)","DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)","DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)","DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)","DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)","DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)","n1= (DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2= (DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3= (DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","R=u/sqrt(u*u+v*v+t*t)","Thickness=-((abs(sin(15*u)*cos(15*v)))^11)/3","Gx=Fx(u,v,t)+Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Gy=Fy(u,v,t)+Thickness(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Gz=Fz(u,v,t)+Thickness(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Component": ["HoledCliffordTorus"],
        "Const": ["c=1/10000"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["pi"],
        "Vmin": ["0"]
        }
        },
    {
      "Param3D": {
        "Description ": ["Holed Spheres by Abderrahman Taha 14/10/2019"],
        "Name": ["Holed_Spheres"],
        "Component": ["HoledSpheres"],
        "Const": ["c=1/100000"],
        "Funct": ["Th= (3/10)*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/(18/10))^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/(19/10))^(55/10))",
          "Fx=cos(u)*cos(v)",
          "Fy=cos(u)*sin(v)",
          "Fz=sin(u)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1= (DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2= (DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3= (DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["pi/2"],
        "Umin": ["-pi/2"],
        "Vmax": ["pi"],
        "Vmin": ["-pi"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Holed Clifford Torus by Abderrahman Taha 14/10/2019"],
        "Name": ["Holed Clifford Torus"],
        "Component": ["HoledCliffordTorus"],
        "Const": ["c=1/100000"],
        "Funct": ["Fx=-(cos(u+v)/(sqrt(2)+cos(v-u)))",
          "Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2)+cos(v-u))",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1= (DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2= (DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3= (DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "Th=(abs(sin(15*u)*cos(15*v)))^7",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Spiny Sea Creature by Abderrahman Taha 14/10/2019"],
        "Name": ["Spiny Sea Creature"],
        "Component": ["SpinySeaCreature"],
        "Const": ["c=1/100000"],
        "Funct": ["Fx=cos(u+v)/(sqrt(2)+cos(v-u))",
          "Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2)+cos(v-u))",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1= (DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2= (DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3= (DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "Th=(abs(sin(15*u)*cos(15*v)))^4",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Skeletal Sphere (parametric version) by Abderrahman Taha 14/10/2019"],
        "Name": ["Skeletal_Sphere_parametric"],
        "Component": ["SkeletalSphere"],
        "Const": ["c=1/100000"],
        "Funct": ["Fx=cos(u)*cos(v)",
          "Fy=cos(u)*sin(v)",
          "Fz=sin(u)",
          "Th=abs(cos(10*u)*sin(10*v)/10)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Th(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Th(u,v,t)*n3(u,v,t)/R(u,v,t)"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["pi/2"],
        "Umin": ["-pi/2"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Skeletal Sphere (implicit version) by Abderrahman Taha 03/10/2019"],
        "Name": ["Skeletal_Sphere_Implicit"],
        "Component": ["SkeletalSphere"],
        "Const": ["c=1/100000",
          "L=12/10"],
        "Funct": ["Iso=x*x+y*y+z*z-1",
          "Th=(cos(10*atan2(x,y))*sin(10*atan2(z,sqrt(x*x+y*y)))/10)",
          "DFx=((Iso(x+c,y,z,t)-Iso(x,y,z,t))/c)",
          "DFy=((Iso(x,y+c,z,t)-Iso(x,y,z,t))/c)",
          "DFz=((Iso(x,y,z+c,t)-Iso(x,y,z,t))/c)",
          "R=(x/sqrt(x*x+y*y+z*z))",
          "Iso2=(Iso(x+t*Th(x,y,z,t)*R(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+t*Th(x,y,z,t)*R(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z+t*Th(x,y,z,t)*R(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))",
          "ThickIso=max(Iso2(x,y,z,1),Iso2(x,y,z,-1))"],
        "Fxyz": ["ThickIso(x,y,z,t)"],
        "Xmax": ["L"],
        "Xmin": ["-L"],
        "Ymax": ["L"],
        "Ymin": ["-L"],
        "Zmax": ["L"],
        "Zmin": ["-L"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Twisted Clifford Torus by Abderrahman Taha 14/10/2019"],
        "Name": ["Twisted Clifford Torus"],
        "Component": ["TwistedClifford"],
        "Const": ["c=1/100000"],
        "Funct": ["Fx=cos(u+v)/(sqrt(2)+cos(v-u))",
          "Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2)+cos(v-u))",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)",
          "Thickness=(3/10)*sin(10*u)*cos(10*v)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Param3D": {
        "Name": ["Bumpy Klein"],
        "Description ": ["Bumpy Klein by Abderrahman Taha 14/10/2019"],
        "Component": ["Klein"],
        "Const": ["c=1/100000"],
        "Funct": ["Fx=(2+cos(v/2)*sin(u)-sin(v/2)*sin(2*u))*cos(v)",
          "Fy=sin(v/2)*sin(u)+cos(v/2)*sin(2*u)",
          "Fz=(2+cos(v/2)*sin(u)-sin(v/2)*sin(2*u))*sin(v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)",
          "Thickness=(1/10)*sin(20*v)*cos(20*u)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Richmond polar Parametric surface by Abderrahman Taha 14/10/2019"],
         "Name": [
           "Richmond Polar_1"],
        "Component": ["richmondpolar1"],
        "Const": ["c=1/10000",
          "Th=3/10"],
        "Funct": ["Fx=-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6",
          "Fy=-sin(t+v)/(2*u)+u^3*sin(t-3*v)/6",
          "Fz=u*cos(t-v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)",
          "Gx=Fx(u,v,t)+Th*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Th*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Th*n3(u,v,t)/R(u,v,t)"],
        "Fx": ["Fx(u,v,t)"],
        "Fy": ["Fy(u,v,t)"],
        "Fz": ["Fz(u,v,t)"],
        "Umax": ["13/10"],
        "Umin": ["3/10"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Richmond polar Parametric surface by Abderrahman Taha 15/10/2019"],
        "Name": ["Richmond Polar_3"],
        "Component": ["richmondpolar1","richmondpolar2"],
        "Const": ["c=1/10000"],
        "Funct": ["Fx=-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6",
          "Fy=-sin(t+v)/(2*u)+u^3*sin(t-3*v)/6",
          "Fz=u*cos(t-v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Th=(1/10)*sin(20*v)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Fx(u,v,t)","Gx(u,v,t)"],
        "Fy": ["Fy(u,v,t)","Gy(u,v,t)"],
        "Fz": ["Fz(u,v,t)","Gz(u,v,t)"],
        "Umax": ["13/10","13/10"],
        "Umin": ["3/10","3/10"],
        "Vmax": ["2*pi","2*pi"],
        "Vmin": ["0","0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Richmond polar Parametric surface by Abderrahman Taha 15/10/2019"],
        "Name": ["Bat coat"],
        "Component": ["Bat_coat"],
        "Const": ["c=1/10000"],
        "Funct": ["Fx=-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6",
          "Fy=-sin(t+v)/(2*u)+u^3*sin(t-3*v)/6",
          "Fz=u*cos(t-v)",
          "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)",
          "DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)",
          "DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)",
          "DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)",
          "DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)",
          "DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=u/sqrt(u*u+v*v+t*t)",
          "Th=DFyu(u,v,t)*DFxv(u,v,t)/2",
          "Gx=Fx(u,v,t)+Th(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*R(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)"],
        "Fy": ["Gy(u,v,t)"],
        "Fz": ["Gz(u,v,t)"],
        "Umax": ["13/10"],
        "Umin": ["3/10"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Devil's Plate by Abderrahman Taha 15/10/2019"],
        "Name": ["Devil Plate"],
        "Component": ["DevilPlate"],
        "Const": ["c=1/10000","Th=1/10"],
        "Funct": ["Devil=x^4+2*x^2*z^2-(36/100)*x^2-y^4+(25/100)*y^2+z^4",
          "Devil2=Devil(x,sqrt(y*y+z*z)-(15/10),z,t)",
          "IsoExterior=Devil2(x,y,sqrt(x*x+z*z)-(15/10),t)",
          "DFx=((IsoExterior(x+c,y,z,t)-IsoExterior(x,y,z,t))/c)",
          "DFy=((IsoExterior(x,y+c,z,t)-IsoExterior(x,y,z,t))/c)",
          "DFz=((IsoExterior(x,y,z+c,t)-IsoExterior(x,y,z,t))/c)",
          "R=x/sqrt(x*x+y*y+z*z)",
          "Iso=(IsoExterior(x+t*Th*R(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+t*Th*R(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z+t*Th*R(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))",
          "ThickIsoExterior=(Iso(x,y,z,1)*Iso(x,y,z,-1))"],
        "Fxyz": ["if(y<(44/10) & y>-(24/10),ThickIsoExterior((10*x/15),y,z,t),1)"],
        "Xmax": ["45/10"],
        "Xmin": ["-45/10"],
        "Ymax": ["45/10"],
        "Ymin": ["-25/10"],
        "Zmax": ["75/10"],
        "Zmin": ["-75/10"]
      },
      "Texture": {
        "Colors": ["R=9/10",
          "G=4/10",
          "B=0",
          "T=1"],
        "Name": "Clay",
        "Noise": ""
      }
    },
    {
      "Iso3D": {
        "Description ": ["Geode by Abderrahman Taha 15/10/2019"],
        "Name": ["Geode_01"],
        "Component": ["Geode1","Geode2"],
        "Const": ["A=4","B=3"],
        "Fxyz": ["-(((x^2+y^2+z^2-1)+(NoiseW(A*x,A*y,A*z,(4),(2),(1))+NoiseW(A*x,A*y,A*z,(4),(0),(0)))/3))*(atan2(x,y)<pi/2)*(x^2+y^2+z^2-2/10)",
          "-(((x^2+y^2+z^2-(21/100))*(atan2(x,y)<pi/2)*((x^2+y^2+z^2-2/10)+(NoiseW(B*x,B*y,B*z,(4),(2),(1))+NoiseW(B*x,B*y,B*z,(4),(2),(1)))/5)))"],
        "Xmax": ["(15/10)","(15/10)"],
        "Xmin": ["-1","-1"],
        "Ymax": ["1","1"],
        "Ymin": ["-1","-1"],
        "Zmax": ["15/10","15/10"],
        "Zmin": ["-1","-1"]
      },
      "Texture": {
        "Colors": ["R=if((x*x+y*y+z*z)>(8/10),(95/100)*cos(10*(x*x+y*y+z*z)/17),(2/10))",
          "G=if((x*x+y*y+z*z)>(8/10),(8/10)*(cos((x*x+y*y+z*z)/5)*sin((x*x+y*y+z*z)))*sin(10*(x*x+y*y+z*z)/3),sin((x*x+y*y+z*z)*9)/2)",
          "B=if((x*x+y*y+z*z)<(8/10),(cos((x*x+y*y+z*z))*cos((x*x+y*y+z*z))*sin((x*x+y*y+z*z)))+(4/10),(1/10))",
          "T=1"],
        "Name": "WorleyNoise",
        "Noise": "-(NoiseW(2*x,2*y,2*z,(4),(0),(0))+NoiseW(2*x,2*y,2*z,(4),(0),(0)))"
      }
    },
    {
      "Iso3D": {
        "Description ": ["The core by Abderrahman Taha 15/10/2019"],
        "Name": ["The Core"],
        "Component": ["Core"],
        "Fxyz": ["-((x^2+y^2+z^2-1)+(NoiseW(6*x,6*y,6*z,(4),(2),0)+NoiseW(6*x,6*y,6*z,(4),(0),(0)))/5)*(atan2(x,y)<pi/2)"],
        "Xmax": ["1"],
        "Xmin": ["-1"],
        "Ymax": ["1"],
        "Ymin": ["-1"],
        "Zmax": ["1"],
        "Zmin": ["-1"]
      },
      "Texture": {
        "Colors": ["R=7/10",
          "G=(24/10)*(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))*sin((x*x+y*y+z*z)/2)",
          "B=(7/10)*(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(2*x,2*y,2*z,(4),(0),(0))+NoiseW(2*x,2*y,2*z,(2),(0),(0))"
      }
    },
    {
      "Param3D": {
        "Name": ["Richmond Polar_4"],
        "Component": ["richmondpolar"],
        "Description ": ["richmondpolar(n)[t](u,v):={-cos(t+v)/(2*u)-u^(2*n+1)*cos(t-(2*n+1)*v)/(4*n+2),-sin(t+v)/(2*u)+u^(2*n+1)*sin(t-(2*n+1)*v)/(4*n+2),u^n*cos(t-n*v)/n}is the polar parametrization of a 1-parameter family of minimal surfaces such that {r,theta}->richmondpolar[n][0][r,theta] is a minimal surface with one planar end of degree n."],
        "Fx": ["-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6"],
        "Fy": ["-sin(t+v)/(2*u)+u^3*sin(t-3*v)/6"],
        "Fz": ["u*cos(t-v)"],
        "Umax": ["13/10"],
        "Umin": ["3/10"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Texture": {
        "Colors": ["R=6/10",
          "G=(16/10)*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "B=(17/10)*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(4*x,4*y,4*z,(4),(2),0)+NoiseW(4*x,4*y,4*z,(4),(12),1/10)"
      }
    },
    {
      "Param3D": {
        "Description": ["Flower by Abderrahman Taha 15/10/2019"],
        "Name": ["Flower"],
        "Component": ["BreatherNoise"],
        "Const": ["A=sqrt(84/100)","B=4/10","C=84/100"],
        "Fx": ["((2*A*cosh(B*u)*(-(A*cos(v)*cos(A*v))-sin(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2)))*(1-NoiseW(((2*A*cosh(B*u)*(-(A*cos(v)*cos(A*v))-sin(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),((2*A*cosh(B*u)*(-(A*sin(v)*cos(A*v))+cos(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),(-u+(2*C*cosh(B*u)*sinh(B*u))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),(1),(2),0))"],
        "Fy": ["((2*A*cosh(B*u)*(-(A*sin(v)*cos(A*v))+cos(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2)))*(1-NoiseW(((2*A*cosh(B*u)*(-(A*cos(v)*cos(A*v))-sin(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),((2*A*cosh(B*u)*(-(A*sin(v)*cos(A*v))+cos(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),(-u+(2*C*cosh(B*u)*sinh(B*u))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),(1),(2),0))"],
        "Fz": ["(-u+(2*C*cosh(B*u)*sinh(B*u))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2)))*(1-NoiseW(((2*A*cosh(B*u)*(-(A*cos(v)*cos(A*v))-sin(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),((2*A*cosh(B*u)*(-(A*sin(v)*cos(A*v))+cos(v)*sin(A*v)))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),(-u+(2*C*cosh(B*u)*sinh(B*u))/(B*((A*cosh(B*u))^2+(B*sin(A*v))^2))),(1),(2),0))"],
        "Umax": ["132/10"],
        "Umin": ["-132/10"],
        "Vmax": ["372/10"],
        "Vmin": ["-372/10"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Broken Jar by Abderrahman Taha 16/11/2019"],
        "Name": ["BrokenJar"],
        "Component": ["BoottomHalf","Boottom","TopHalf","Head"],
        "Grid": ["150","60","150","60"],
        "Const": ["c=(1/10000)","S=6","Th2=(1/4)","Th4=(1/5)","Th6=(6/5)"],
        "Funct": ["Angle1=atan2(sqrt(x*x+y*y),(-z+c))",
          "Angle2=atan2(x,(y+c))",
          "rapp=x/sqrt(x*x+y*y+z*z)",
          "CarvinCondition=(abs((z-1)-(4/5)*cos(18*Angle2(x,y,z,t)/pi))<(13/10)|abs((z+3)-(3/10)*cos(18*Angle2(x,y,z,t)/pi+pi/4))<(1/2))",
          "CarvinCondition2=(z-3*sin((16/5)*Angle2(x,y,z,t)/pi))>0",
          "Torus=(sqrt(x*x+y*y)-3)^2+z*z-1",
          "IsoExterior=if(-z<(5),(x*x/3+y*y/3-abs((3/2)*sin(2*z/pi+(3/10))+(9/5))),(z+5))",
          "DFx2=((IsoExterior(x+c,y,z,t)-IsoExterior(x,y,z,t))/c)",
          "DFy2=((IsoExterior(x,y+c,z,t)-IsoExterior(x,y,z,t))/c)",
          "DFz2=((IsoExterior(x,y,z+c,t)-IsoExterior(x,y,z,t))/c)",
          "Iso2=(IsoExterior(
          x+t*Th2*rapp(DFx2(x,y,z,t),DFy2(x,y,z,t),DFz2(x,y,z,t),t),
          y+t*Th2*rapp(DFy2(x,y,z,t),DFz2(x,y,z,t),DFx2(x,y,z,t),t),
          z+t*Th2*rapp(DFz2(x,y,z,t),DFx2(x,y,z,t),DFy2(x,y,z,t),t),t))",
          "ThickIsoExterior=(Iso2(x,y,z,1)*Iso2(x,y,z,-1))",
          "Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "DFx=((Iso(x+c,y,z,t)-Iso(x,y,z,t))/c)",
          "DFy=((Iso(x,y+c,z,t)-Iso(x,y,z,t))/c)",
          "DFz=((Iso(x,y,z+c,t)-Iso(x,y,z,t))/c)",
          "Iso4=(Iso(
          x+t*Th4*rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),
          y+t*Th4*rapp(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),
          z+t*Th4*rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))",
          "ThickIso2=(Iso4(x,y,z,-1)*Iso4(x,y,z,1))",
          "isoTransform_2=if((CarvinCondition(x,y,z,t)=0),ThickIsoExterior(x,y,z,t),1)",
          "Iso6=(Iso(
          x+t*Th6*rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),
          y+t*Th6*rapp(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),
          z+t*Th6*rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))",
          "isoTransform_6=if((CarvinCondition(x,y,z,t)&ThickIsoExterior(x,y,z,t)<0),-ThickIso2(S*x,S*y,S*z,t)*Iso6(x*S,y*S,z*S,-1)*(Iso6(x*S,y*S,z*S,1)),1)",
          "VaseHead=if(CarvinCondition2(x,y,z,t),isoTransform_2(x,y,-z,t)*isoTransform_6(x,y,-z,t),1)",
          "VaseHead2=VaseHead((x+6)*cos(-pi/2)-(z+(5/2))*sin(-pi/2),y,(x+6)*sin(-pi/2)+(z+(5/2))*cos(-pi/2),t)",
          "Torus2=Torus((17/10)*x,(17/10)*y,(11/5)*(z+cos(pi/4*sqrt(x*x+y*y)))-(53/5),t)",
          "Torus3=Torus2((x+6)*cos(-pi/2)-(z+(5/2))*sin(-pi/2),y,(x+6)*sin(-pi/2)+(z+(5/2))*cos(-pi/2),t)",
          "VaseBottom=if((CarvinCondition2(x,y,z,t)=0),isoTransform_2(x,y,-z,t)*isoTransform_6(x,y,-z,t),1)"],
        "Fxyz": ["VaseBottom(x*cos(-pi/5)-y*sin(-pi/5),x*sin(-pi/5)+y*cos(-pi/5),z,t)",
          "((x*x+y*y)/(576/100)+4*(z+(51/10))*(z+(51/10))-1)",
          "VaseHead2(x*cos(pi/2)-y*sin(pi/2)-(5),(x*sin(pi/2)+y*cos(pi/2)+6),z,t)",
          "Torus3((x*cos(pi/2)-y*sin(pi/2)-5),(x*sin(pi/2)+y*cos(pi/2)+6),z,t)"],
        "Xmax": ["7/2","3","-3","-2"],
        "Xmin": ["-7/2","-3","-9","-9"],
        "Ymax": ["7/2","3","11/2","8"],
        "Ymin": ["-7/2","-3","-5/2","5"],
        "Zmax": ["3","-9/2","3/2","0"],
        "Zmin": ["-5","-57/10","-6","-5"]
      },
        "Texture": {
            "Colors": ["R=8/10",
                "G=4/10",
                "B=1/10",
                "T=1"],
            "Name": "Granit_1",
            "Noise": ""
        }
    },
    {
        "Iso3D": {
            "Description": ["Old Vase by Abderrahman Taha 16/11/2019"],
            "Name": ["OldVase"],
            "Component": ["Vase1","Vase5","Vase6"],
            "Const": ["c=(1/10000)","S=6","Th2=(1/4)","Th4=(1/5)","Th6=(6/5)"],
            "Funct": ["Angle1=atan2(sqrt(x*x+y*y),(-z+c))",
                "Angle2=atan2(x,(y+c))",
                "rapp=x/sqrt(x*x+y*y+z*z)",
                "CarvinCondition=abs((z-1)-(4/5)*cos(18*Angle2(x,y,z,t)/pi))<(103/10)|abs((z+3)-(3/10)*cos(18*Angle2(x,y,z,t)/pi+pi/4))<(1/2)",
                "Torus=(sqrt(x*x+y*y)-3)^2+z*z-1",
                "Bottom=(x*x+y*y+z*z-1)",
                "IsoExterior=x*x/3+y*y/3-abs((3/2)*sin(2*z/pi+(3/10))+(9/5))",
                "DFx2=((IsoExterior(x+c,y,z,t)-IsoExterior(x,y,z,t))/c)",
                "DFy2=((IsoExterior(x,y+c,z,t)-IsoExterior(x,y,z,t))/c)",
                "DFz2=((IsoExterior(x,y,z+c,t)-IsoExterior(x,y,z,t))/c)",
                "Iso2=(IsoExterior(x+t*Th2*rapp(DFx2(x,y,z,t),DFy2(x,y,z,t),DFz2(x,y,z,t),t),y+t*Th2*rapp(DFy2(x,y,z,t),DFz2(x,y,z,t),DFx2(x,y,z,t),t),z+t*Th2*rapp(DFz2(x,y,z,t),DFx2(x,y,z,t),DFy2(x,y,z,t),t),t))",
                "ThickIsoExterior=(Iso2(x,y,z,1)*Iso2(x,y,z,-1))",
                "Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
                "DFx=((Iso(x+c,y,z,t)-Iso(x,y,z,t))/c)",
                "DFy=((Iso(x,y+c,z,t)-Iso(x,y,z,t))/c)",
                "DFz=((Iso(x,y,z+c,t)-Iso(x,y,z,t))/c)",
                "Iso4=(Iso(x+t*Th4*rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+t*Th4*rapp(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z+t*Th4*rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))",
                "ThickIso2=(Iso4(x,y,z,-1)*Iso4(x,y,z,1))",
                "isoTransform_2=if((CarvinCondition(x,y,z,t)=0),ThickIsoExterior(x,y,z,t),1)",
                "Iso6=(Iso(x+t*Th6*rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+t*Th6*rapp(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z+t*Th6*rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))",
                "isoTransform_6=if((CarvinCondition(x,y,z,t)&ThickIsoExterior(x,y,z,t)<0),-ThickIso2(S*x,S*y,S*z,t)*Iso6(x*S,y*S,z*S,-1)*(Iso6(x*S,y*S,z*S,1)),1)"],
            "Fxyz": ["isoTransform_2(x,y,-z,t)*isoTransform_6(x,y,-z,t)",
                "Torus((17/10)*x,(17/10)*y,(11/5)*(z+cos(pi/4*sqrt(x*x+y*y)))-(53/5),t)",
                "Bottom(x/(12/5),y/(12/5),2*(z+(51/10)),t)"],
            "Xmax": ["7/2","5","3"],
            "Xmin": ["-7/2","-5","-3"],
            "Ymax": ["7/2","5","3"],
            "Ymin": ["-7/2","-5","-3"],
            "Zmax": ["(9/2)","10","-2"],
            "Zmin": ["-5","0","-7"]
        },
        "Texture": {
            "Colors": ["R=8/10",
                "G=4/10",
                "B=1/10",
                "T=1"],
            "Name": "Granit_1",
            "Noise": ""
        }
    },
    {
      "Param3D": {
        "Description": ["SeaShells by Abderrahman Taha 16/09/2019"],
        "Name": ["SeaShells"],
        "Component": ["SeaShells"],
        "Const": ["a = 40",
          "b = 14",
          "D = 1",
          "A = 50",
          "Mu = 10*pi/180",
          "Alfa = 84*pi/180",
          "Beta =-19*pi/180",
          "Omega =-2*pi/180",
          "Phi = 45*pi/180",
          "L = 8",
          "P = 0",
          "W1 = 6*pi/180",
          "W2 = 27*pi/180",
          "N = 8"],
        "Funct": ["Re=(1/sqrt((cos(u)/a)^2+(sin(u)/b)^2)+if((W1=0|W2=0|N=0),(0),L*exp(-(2*(u-P)/W1)^2-((2*((2*pi/N)*(N*v/(2*pi)-floor(N*v/(2*pi)))))/W2))^2))"],
        "Fx": ["D*(A*sin(Beta)*cos(u)+Re(v,u,t)*(cos(v+Phi)*cos(u+Omega)-sin(Mu)*sin(v+Phi)*sin(u+Omega)))*exp(u*cot(Alfa))"],
        "Fy": ["(-A*sin(Beta)*sin(u)-Re(v,u,t)*(cos(v+Phi)*sin(u+Omega)+sin(Mu)*sin(v+Phi)*cos(u+Omega)))*exp(u*cot(Alfa))"],
        "Fz": ["(-A*cos(Beta)+Re(v,u,t)*sin(v+Phi)*cos(Mu))*exp(u*cot(Alfa))"],
        "Umax": ["4*pi"],
        "Umin": ["-4*pi"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Pseudo Duplin_2 by Abderrahman Taha 30/03/2017"],
        "Name": ["Pseudo Duplin_2"],
        "Component": ["PseudoDuplin"],
        "Const": ["Th1=9/10","Th2=2/5"],
        "Funct": ["Iso=cos(x)+cos(y)+cos(z)",
          "DFx=(-sin(x))",
          "DFy=(-sin(y))",
          "DFz=(-sin(z))",
          "Rap=x/sqrt(x*x+y*y+z*z)",
          "Rapport=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
          "Iso3=(Iso(x-Th1*Rap(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-Th1*Rap(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z-Th1*Rap(DFz(x,y,z,t),DFy(x,y,z,t),DFx(x,y,z,t),t),t))",
          "Iso2=(Iso(x+Th1*Rap(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+Th1*Rap(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z+Th1*Rap(DFz(x,y,z,t),DFy(x,y,z,t),DFx(x,y,z,t),t),t))",
          "Iso4=(Iso(x-Th2*Rap(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-Th2*Rap(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z-Th2*Rap(DFz(x,y,z,t),DFy(x,y,z,t),DFx(x,y,z,t),t),t))",
          "Iso5=(Iso(x+Th2*Rap(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+Th2*Rap(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z+Th2*Rap(DFz(x,y,z,t),DFy(x,y,z,t),DFx(x,y,z,t),t),t))",
          "ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoCondition=(-51)*(x^4+y^4+z^4)-100*(x^2*y^2+x^2*z^2+y^2*z^2)+(14112/100)*(x-1)*(x^2+y^2+z^2)+256*x*(x-2)+(28224/100)*y^2+270",
          "isoTransform_2=if((isoCondition((x/4),(y/4),(z/4),t)>0),ThickIso2(4*x,2*y,2*z,t),1)+(1/20)*exp((ThickIso2(4*x,2*y,2*z,t)+isoCondition((x/4),(y/4),(z/4),t))/300)",
          "isoTransform_6=isoTransform_2(x,y*cos((4944/10000)*(x))-z*sin((4944/10000)*(x)),y*sin((4944/10000)*(x))+z*cos((4944/10000)*(x)),t)"],
        "Fxyz": ["-isoTransform_6((x/2),y,z,t)"],
        "Xmax": ["18"],
        "Xmin": ["-16"],
        "Ymax": ["8"],
        "Ymin": ["-8"],
        "Zmax": ["8"],
        "Zmin": ["-8"]
      }
    },
    {
      "Param3D": {
        "Description": ["Super Formula by Abderrahman Taha 12/03/2016"],
        "Name": ["Super Formula"],
        "Cnd": ["sqrt(x*x+y*y)>S"],
        "Component": ["SuperFormula"],
        "Const": ["A1=50",
          "B1=1",
          "M1=9",
          "N11=25",
          "N21=17/10",
          "N31=17/10",
          "A2=50",
          "B2=1",
          "M2=9",
          "N12=20",
          "N22=17/10",
          "N32=17/10",
          "S=41/100"],
        "Funct": ["Ru=(abs(cos(M1*u/4)*50/A1)^N21+abs(sin(M1*u/4)*50/B1)^N31)^(-100/N11)","Rv=(abs(cos(M2*v/4)*50/A2)^N22+abs(sin(M2*v/4)*50/B2)^N32)^(-100/N12)"],
        "Fx": ["-cos(u)*cos(v)*Ru(u,v,t)*Rv(u,v,t)"],
        "Fy": ["cos(u)*sin(v)*Ru(u,v,t)*Rv(u,v,t)"],
        "Fz": ["sin(u)*Ru(u,v,t)"],
        "Umax": ["pi/2"],
        "Umin": ["-pi/2"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
        "Sliders": {
          "Max": ["100","100","100","100","20","20","100","100","100","100","100","100","20","20","100","100","100","100","100","100","20","20","100","100","100","100","100","100","20","20","100","100","100","100","100","100","20","20","100","100","100","100","100","100","20","20","100","100","100","100","100","100","20","20","100","100"],
          "Min": ["1","1","1","1","0","0","1","1","1","1","1","1","0","0","1","1","1","1","1","1","0","0","1","1","1","1","1","1","0","0","1","1","1","1","1","1","0","0","1","1","1","1","1","1","0","0","1","1","1","1","1","1","0","0","1","1"],
          "Name": ["A1","A2","B2","B1","M1","M2","N11","N12"],
          "Position": ["50","50","50","50","9","9","20","20","54","47","44","51","8","10","16","51","52","45","53","38","15","16","39","84","55","55","55","58","10","17","44","100","54","53","75","48","8","10","16","51","54","48","56","56","16","16","100","100","50","53","61","46","7","10","29","46"],
          "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        }
    },
    {
      "Param3D": {
        "Description": ["Double Distorsion by Abderrahman Taha 04/05/2017"],
        "Name": ["Double Distorsion"],
        "Component": ["Torus"],
        "Const": ["N=5",
          "M=16",
          "P=13",
          "k=5",
          "k0=5",
          "k1=5",
          "L=(3/2)",
          "r0=6",
          "dv=(1/100)",
          "P=5",
          "MM=10"],
        "Funct": ["Fx=(1+(1/2)*cos(v+t))*cos(u-k*(v)+t)",
          "Fy=(1+(1/2)*cos(v+t))*sin(u-k*(v)+t)",
          "Fz=L*sin(v+t)",
          "DFxv = (Fx(u,v+dv,t)-Fx(u,v,t))/dv",
          "DFyv = (Fy(u,v+dv,t)-Fy(u,v,t))/dv",
          "DFzv = (Fz(u,v+dv,t)-Fz(u,v,t))/dv",
          "DFxv2 = (DFxv(u,v+dv,t)-DFxv(u,v,t))/dv",
          "DFyv2 = (DFyv(u,v+dv,t)-DFyv(u,v,t))/dv",
          "DFzv2 = (DFzv(u,v+dv,t)-DFzv(u,v,t))/dv",
          "Rapp = (u/sqrt(u*u+v*v+t*t))",
          "Nx = Rapp(DFxv2(u,v,t),DFyv2(u,v,t),DFzv2(u,v,t))",
          "Ny = Rapp(DFyv2(u,v,t),DFxv2(u,v,t),DFzv2(u,v,t))",
          "Nz = Rapp(DFzv2(u,v,t),DFyv2(u,v,t),DFxv2(u,v,t))",
          "Bx = 1/sqrt(u*u+v*v+t*t)",
          "Binx = (DFyv(u,v,t)*Nz(u,v,t)-DFzv(u,v,t)*Ny(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))",
          "Biny = (DFzv(u,v,t)*Nx(u,v,t)-DFxv(u,v,t)*Nz(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))",
          "Binz = (DFxv(u,v,t)*Ny(u,v,t)-DFyv(u,v,t)*Nx(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))",
          "S = (r0/100)*((k0-1)*cos(u+k1*t)+cos((k0-1)*u+k1*t))",
          "C = (r0/100)*((k0-1)*sin(u+k1*t)-sin((k0-1)*u+k1*t))",
          "Sx = Fx(pi,v,t)+Nx(pi,v,t)*C(u,v,t)+Binx(pi,v,t)*S(u,v,t)",
          "Sy = Fy(pi,v,t)+Ny(pi,v,t)*C(u,v,t)+Biny(pi,v,t)*S(u,v,t)",
          "Sz = Fz(pi,v,t)+Nz(pi,v,t)*C(u,v,t)+Binz(pi,v,t)*S(u,v,t)"],
        "Fx": ["Sx(u,v,t)"],
        "Fy": ["Sy(u,v,t)"],
        "Fz": ["Sz(u,v,t)"],
        "Umax": ["pi"],
        "Umin": ["-pi"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Texture": {
        "Colors": ["R= if(int(i_indx)%(M/6)>P | int(j_indx)%(M)>P,(4/5),(4/5)) ",
          "G= if(int(i_indx)%(M/6)>P | int(j_indx)%(M)>P,(1/10),(4/5)) ",
          "B= if(int(i_indx)%(M/6)>P | int(j_indx)%(M)>P,(1/10),(4/5)) ",
          "T= 1 "],
        "Name": "Candy",
        "Noise": "1"
      }
    },
    {
      "Param3D": {
        "Description": ["Torsion spring v2 by Abderrahman Taha 01/05/2017"],
        "Name": ["Torsion_Spring_02"],
        "Component": ["Torus_Section"],
        "Const": ["k=7","L=(3/2)","r0=12","dv=(1/100)"],
        "Funct": ["Fx=(1+(1/2)*cos(t+v))*cos(pi-k*(v))",
          "Fy=(1+(1/2)*cos(t+v))*sin(pi-k*(v))",
          "Fz=L*sin(t+v)",
          "DFxv = (Fx(u,v+dv,t)-Fx(u,v,t))/dv",
          "DFyv = (Fy(u,v+dv,t)-Fy(u,v,t))/dv",
          "DFzv = (Fz(u,v+dv,t)-Fz(u,v,t))/dv",
          "DFxv2 = (DFxv(u,v+dv,t)-DFxv(u,v,t))/dv",
          "DFyv2 = (DFyv(u,v+dv,t)-DFyv(u,v,t))/dv",
          "DFzv2 = (DFzv(u,v+dv,t)-DFzv(u,v,t))/dv",
          "Rapp = (u/sqrt(u*u+v*v+t*t))",
          "Nx = Rapp(DFxv2(u,v,t),DFyv2(u,v,t),DFzv2(u,v,t))",
          "Ny = Rapp(DFyv2(u,v,t),DFxv2(u,v,t),DFzv2(u,v,t))",
          "Nz = Rapp(DFzv2(u,v,t),DFyv2(u,v,t),DFxv2(u,v,t))",
          "Bx = 1/sqrt(u*u+v*v+t*t)",
          "Binx = (DFyv(u,v,t)*Nz(u,v,t)-DFzv(u,v,t)*Ny(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))",
          "Biny = (DFzv(u,v,t)*Nx(u,v,t)-DFxv(u,v,t)*Nz(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))",
          "Binz = (DFxv(u,v,t)*Ny(u,v,t)-DFyv(u,v,t)*Nx(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))",
          "Sx = Fx(u,v,t)+(r0/100)*Nx(u,v,t)*cos(u)+(r0/100)*Binx(u,v,t)*sin(u)",
          "Sy = Fy(u,v,t)+(r0/100)*Ny(u,v,t)*cos(u)+(r0/100)*Biny(u,v,t)*sin(u)",
          "Sz = Fz(u,v,t)+(r0/100)*Nz(u,v,t)*cos(u)+(r0/100)*Binz(u,v,t)*sin(u)"],
        "Fx": ["Sx(u,v,t)"],
        "Fy": ["Sy(u,v,t)"],
        "Fz": ["Sz(u,v,t)"],
        "Umax": ["pi"],
        "Umin": ["-pi"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Twin Klein by Abderrahman Taha 29/04/2017"],
        "Name": ["Twin Klein"],
        "Component": ["TwinKlein"],
        "Const": ["cu=(1/1000)",
          "cv=(1/1000)",
          "N=5",
          "M=3",
          "A=7/2",
          "B=2",
          "C=3",
          "D=3",
          "MaxU=2*pi",
          "MinU=0",
          "MaxV=10*pi",
          "MinV=0"],
        "Funct": ["th=if((M=1),(3/10)*((abs(sin(11*u)*cos(11*v)))^19+(1/10)*((sin(2*N*u)))),if((M=2),(9/10)*sin((N*v)% pi/3),if((M=3),(((2/5)*abs(cos(7*(u))^2-sin(9*(v))^5 ))^3),if((M=4),((2/5)*sin(N*v-u)^100),if((M=5),(2/5)*sin(N*v),if((M=6),(2/5)*sin(2*N*v-u),if((M=7),((2/5)*sin(N*v)^10),if((M=8),-(3/10)*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/(9/5))^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/(19/10))^(11/2)),if((M=9),((sin(15*u)*cos(15*u)))^4+(sin(2*N*v)),if((M=10),((sin(9*u)*cos(9*v)))^2+(1/2)*(sin(2*N*u)),((2/5)*abs(cos(7*(u))^2-sin(9*(v))^5 ))^3))))))))))",
          "Fx=if(v<2*pi,(A-(A-1)*cos(v))*cos(u),if(v<3*pi,-B+(B+cos(u))*cos(v),-B+B*cos(v)-cos(u)))",
          "Fy=if(v<2*pi,(A-(A-1)*cos(v))*sin(u),sin(u))",
          "Fz=if(v<pi,-C*sin(v),if(v<2*pi,D*v-D*pi,if(v<3*pi,((D-1)+cos(u))*sin(v)+D*pi,-D*v+D*4*pi)))",
          "Fx=if(v<6*pi,Fx(u,v,t),-Fx(u,(v-6*pi)%(4*pi),t))",
          "Fy=if(v<6*pi,Fy(u,v,t),Fy(u,(v-6*pi)%(4*pi),t))",
          "Fz=if(v<6*pi,Fz(u,v,t),-Fz(u,(v-6*pi)%(4*pi),t)-19)",
          "DFxu=((Fx(u,v,t)-Fx(u+cu,v,t))/cu)",
          "DFxv=((Fx(u,v,t)-Fx(u,v+cv,t))/cv)",
          "DFyu=((Fy(u,v,t)-Fy(u+cu,v,t))/cu)",
          "DFyv=((Fy(u,v,t)-Fy(u,v+cv,t))/cv)",
          "DFzu=((Fz(u,v,t)-Fz(u+cu,v,t))/cu)",
          "DFzv=((Fz(u,v,t)-Fz(u,v+cv,t))/cv)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "Rapp=u/sqrt(u*u+v*v+t*t)",
          "Fx=Fx(u,v,t)+if(v<6*pi,th(u,v-3*t,t),th(u,v+3*t,t))*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Fy=Fy(u,v,t)+if(v<6*pi,th(u,v-3*t,t),th(u,v+3*t,t))*Rapp(n2(u,v,t),n1(u,v,t),n3(u,v,t))",
          "Fz=Fz(u,v,t)+if(v<6*pi,th(u,v-3*t,t),th(u,v+3*t,t))*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Fx(u,v,t)"],
        "Fy": ["Fy(u,v,t)"],
        "Fz": ["Fz(u,v,t)"],
        "Umax": ["MaxU"],
        "Umin": ["MinU"],
        "Vmax": ["MaxV"],
        "Vmin": ["MinV"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Sea Shell by Abderrahman Taha 04/10/2019"],
        "Name": ["Sea_Shell_001"],
        "Component": ["Sea Shell"],
        "Const": ["c=1/10000",
          "N=5",
          "M=3",
          "MaxU=6*pi",
          "MinU=0",
          "MaxV=2*pi",
          "MinV=0",
          "a=2/10",
          "b=1",
          "c=1/10",
          "n=2"],
        "Funct": ["th=-(((u)/MaxU+5/100)*(4/10)*abs(cos(7*(u))^3-sin(7*(v))^2 ))^3",
          "Fx=2*(1-exp(u/(6*pi)))*cos(u)*cos(v/2)^2",
          "Fy=2*(-1+exp(u/(6*pi)))*sin(u)*cos(v/2)^2",
          "Fz=1-exp(u/(3*pi))-sin(v)+exp(u/(6*pi))*sin(v)",
          "DFxu=((Fx(u,v,t)-Fx(u+c,v,t))/c)",
          "DFxv=((Fx(u,v,t)-Fx(u,v+c,t))/c)",
          "DFyu=((Fy(u,v,t)-Fy(u+c,v,t))/c)",
          "DFyv=((Fy(u,v,t)-Fy(u,v+c,t))/c)",
          "DFzu=((Fz(u,v,t)-Fz(u+c,v,t))/c)",
          "DFzv=((Fz(u,v,t)-Fz(u,v+c,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "Rapp=u/sqrt(u*u+v*v+t*t+c*c)",
          "Fx=Fx(u,v,t)+th(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Fy=Fy(u,v,t)+th(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Fz=Fz(u,v,t)+th(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["-Fx(u,v,t)"],
        "Fy": ["Fy(u,v,t)"],
        "Fz": ["Fz(u,v,t)"],
        "Umax": ["MaxU"],
        "Umin": ["MinU"],
        "Vmax": ["MaxV"],
        "Vmin": ["MinV"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Seashell by Abderrahman Taha 04/10/2019"],
        "Name": ["Sea_Shell_002"],
        "Component": ["Sea Shell"],
        "Const": ["c=1/10000",
          "N=14",
          "M=4",
          "MaxU=pi",
          "MinU=0",
          "MaxV=5*pi/2",
          "MinV=0",
          "a=2/10",
          "b=1",
          "c=1/10",
          "n=2"],
        "Funct": ["th=(2/10)*((1-abs(u-pi/2)/MaxU)*(v/MaxV+5/100)*abs(cos(N*(u))^3-sin(N*(v))^2))^3",
          "Fx=if((M=1),(2*(1-exp(u/(6*pi)))*cos(u)*cos(v/2)^2),if((M=2),(((a*(1-v/(2*pi))*(1+cos(u))+c)*cos(n*v))*6+4),if((M=3),(2^v*(sin(u)*cos(u))/35),if((M=4),((6/5)^v*(sin(u)^2*sin(v))+2),2*(1-exp(u/(6*pi)))*cos(u)*cos(v/2)^2))))",
          "Fy=if((M=1),(2*(-1+exp(u/(6*pi)))*sin(u)*cos(v/2)^2),if((M=2),(((a*(1-v/(2*pi))*(1+cos(u))+c)*sin(n*v))*6+4),if((M=3),(2^v*(sin(u)^2*sin(v))/35-4),if((M=4),((6/5)^v*(sin(u)*cos(u))+5),2*(-1+exp(u/(6*pi)))*sin(u)*cos(v/2)^2))))",
          "Fz=if((M=1),1-exp(u/(3*pi))-sin(v)+exp(u/(6*pi))*sin(v),if((M=2),((b*v/(2*pi)+a*(1-v/(2*pi))*sin(u))*6-6),if((M=3),(2^v*(sin(u)^2*cos(v))/35-12),if((M=4),((6/5)^v*(sin(u)^2*cos(v))-12),1-exp(u/(3*pi))-sin(v)+exp(u/(6*pi))*sin(v)))))",
          "DFxu=((Fx(u,v,t)-Fx(u+c,v,t))/c)",
          "DFxv=((Fx(u,v,t)-Fx(u,v+c,t))/c)",
          "DFyu=((Fy(u,v,t)-Fy(u+c,v,t))/c)",
          "DFyv=((Fy(u,v,t)-Fy(u,v+c,t))/c)",
          "DFzu=((Fz(u,v,t)-Fz(u+c,v,t))/c)",
          "DFzv=((Fz(u,v,t)-Fz(u,v+c,t))/c)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "Rapp=u/sqrt(u*u+v*v+t*t+c*c)",
          "Fx=Fx(u,v,t)+th(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Fy=Fy(u,v,t)+th(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))",
          "Fz=Fz(u,v,t)+th(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Fx(u,v,t)"],
        "Fy": ["Fy(u,v,t)"],
        "Fz": ["Fz(u,v,t)"],
        "Umax": ["MaxU"],
        "Umin": ["MinU"],
        "Vmax": ["MaxV"],
        "Vmin": ["MinV"]
      }
    },
    {
      "Param3D": {
        "Description": ["Torsion spring by Abderrahman Taha 04/10/2019"],
        "Name": ["Torsion_Spring"],
        "Component": ["TorsionSpring"],
        "Const": ["N=6",
          "M=5",
          "R=14",
          "R1=20",
          "r0=19",
          "P=3",
          "MM=6",
          "dv=1/10000"],
        "Funct": ["Fx = ((R1/10)*cos(v)+(R/10)*u*cos(N*v+M*sin(t+v))*cos(v))",
          "Fy = ((R1/10)*sin(v)+(R/10)*u*cos(N*v+M*sin(t+v))*sin(v))",
          "Fz = ((R/10)*u*sin(N*v+M*sin(t+v)))",
          "DFxv =-(R1/10)*sin(v)+(R/10)*u*(-(N+M*cos(t+v))*sin(N*v+M*sin(t+v))*cos(v)  -cos(N*v+M*sin(t+v))*sin(v))",
          "DFyv = (R1/10)*cos(v)+(R/10)*u*(-(N+M*cos(t+v))*sin(N*v+M*sin(t+v))*sin(v)   +cos(N*v+M*sin(t+v))*cos(v))",
          "DFzv =  (R/10)*u*((N+M*cos(t+v))*cos(N*v+M*sin(t+v)))",
          "DFxv2 = (DFxv(u,v+dv,t)-DFxv(u,v,t))/dv",
          "DFyv2 = (DFyv(u,v+dv,t)-DFyv(u,v,t))/dv",
          "DFzv2 = (DFzv(u,v+dv,t)-DFzv(u,v,t))/dv",
          "Rapp = (u/sqrt(u*u+v*v+t*t))",
          "Nx = Rapp(DFxv2(u,v,t),DFyv2(u,v,t),DFzv2(u,v,t))",
          "Ny = Rapp(DFyv2(u,v,t),DFxv2(u,v,t),DFzv2(u,v,t))",
          "Nz = Rapp(DFzv2(u,v,t),DFyv2(u,v,t),DFxv2(u,v,t))",
          "Bx = 1/sqrt(u*u+v*v+t*t)",
          "Binx = (DFyv(u,v,t)*Nz(u,v,t)-DFzv(u,v,t)*Ny(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))",
          "Biny = (DFzv(u,v,t)*Nx(u,v,t)-DFxv(u,v,t)*Nz(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))",
          "Binz = (DFxv(u,v,t)*Ny(u,v,t)-DFyv(u,v,t)*Nx(u,v,t))*Bx(DFxv(u,v,t),DFyv(u,v,t),DFzv(u,v,t))",
          "Sx  = Fx((1),v,t)+(r0/100)*Nx((1),v,t)*cos(u)+(r0/100)*Binx((1),v,t)*sin(u)",
          "Sy  = Fy((1),v,t)+(r0/100)*Ny((1),v,t)*cos(u)+(r0/100)*Biny((1),v,t)*sin(u)",
          "Sz  = Fz((1),v,t)+(r0/100)*Nz((1),v,t)*cos(u)+(r0/100)*Binz((1),v,t)*sin(u)"],
        "Fx": ["Sx(u,v,t)"],
        "Fy": ["Sy(u,v,t)"],
        "Fz": ["Sz(u,v,t)"],
        "Umax": ["pi"],
        "Umin": ["-pi"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
    "Sliders": {
      "Max": ["15","15","30","30","111","15","15","30","30","111","15","15","30","30","111","15","15","30","30","111","15","15","30","30","111"],
      "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
      "Name": ["N","M","R","R1","r0"],
      "Position": ["6","5","14","20","19","11","8","6","20","19","11","15","10","20","19","4","15","6","18","19","11","8","9","22","19"],
      "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
    },
      "Texture": {
        "Colors": ["R= if((int(i_indx)%MM>P & int(i_indx)%MM<P+2),(8/10),(8/10)) ",
          "G= if((int(i_indx)%MM>P & int(i_indx)%MM<P+2),(8/10),(1/10)) ",
          "B= if((int(i_indx)%MM>P & int(i_indx)%MM<P+2),(8/10),(1/10)) ",
          "T= 1 "],
        "Name": "Rings",
        "Noise": "1"
      }
    },
    {
      "Iso3D": {
        "Description": ["Straw Basket using the predefined MathMod function fmesh by Abderrahman Taha 17/09/2019"],
        "Name": ["Straw Basket_02"],
        "Component": ["Straw Basket"],
        "Const": ["A = 5",
          "B = 2",
          "C = 10",
          "D = 1",
          "E = 10",
          "th = A*pi/10",
          "ph = B*pi/10"],
        "Funct": ["fmesh0=-fmesh(x,y,z,(A/10),(B/10),(C/10),(D/10),(E/10))+(8/100) ",
          "fmesh3= if(atan2(z,sqrt(x*x+y*y))<(9/10),fmesh0(atan2(y,x),(sqrt(x*x+y*y+z*z)-4),atan2(z,sqrt(x*x+y*y)),t),1)*(atan2(z,sqrt(x*x+y*y))<(9/10))"],
        "Fxyz": [" fmesh3(x,y,z,t)"],
        "Xmax": ["5"],
        "Xmin": ["-5"],
        "Ymax": ["5"],
        "Ymin": ["-5"],
        "Zmax": ["5"],
        "Zmin": ["-5"]
      },
        "Sliders": {
            "Max": ["15","15","20","10","20"],
            "Min": ["1","1","1","0","1"],
            "Name": ["A","B","C","D","E"],
            "Position": ["5","2","10","1","10"],
            "Step": ["1","1","1","1","1"]
        }
    },
    {
      "Param3D": {
        "Description": ["Twisted_Strip by Abderrahman Taha 04/10/2019"],
        "Name": ["Twisted_Strip"],
        "Component": ["TwistedStrip"],
        "Const": ["N=6","M=5","R=14"],
        "Fx": ["cos(v)+(R/10)*u*cos(N*v+M*sin(t+v))*cos(v)"],
        "Fy": ["sin(v)+(R/10)*u*cos(N*v+M*sin(t+v))*sin(v)"],
        "Fz": ["(R/10)*u*sin(N*v+M*sin(t+v))"],
        "Umax": ["4/10"],
        "Umin": ["-4/10"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Sliders": {
        "Max": ["15","15","30"],
        "Min": ["0","0","0"],
        "Name": ["N","M","R"],
        "Position": ["6","5","14"],
        "Step": ["1","1","1"]
      }
    },
    {
      "Param3D": {
        "Description ": ["Inka_Sun and Twisted_Toroids v02 by Abderrahman Taha 04/10/2019"],
        "Name": ["InkaSun"],
        "Component": ["InkaSun_1","InkaSun_2"],
        "Const": ["N=4","M=1","T=1/2"

        ],
        "Funct": ["InkaSun= if(if((t=1),(abs(sin((N/2)*(u*(sin(v))-u))))<(4/10),(abs(sin((N/2)*(u*(sin(v))-u))))>(38/100)),-(45/100),0)",
          "InkaSun1= if(if((t=1),(abs(sin((N/2)*(u*abs(sin(v))-u))))<(4/10),(abs(sin((N/2)*(u*abs(sin(v))-u))))>(38/100)),-(45/100),0)",
          "TwistedTori=if((t=1),if((abs(sin((N/2)*u-v)))>(38/100),-(45/100),0),if((abs(sin((N/2)*u-v)))<(38/100),-(45/100),0))",
          "Th= if((M=1),InkaSun(u,v,t),if((M=2),InkaSun1(u,v,t),if((M=3),TwistedTori(u,v,t),InkaSun(u,v,t))))",
          "Fx=(1+T*cos(u))*cos(v)",
          "Fy=T*sin(u)",
          "Fz=(1+T*cos(u))*sin(v)",
          "n1=((-T*cos(u))*(-(1+T*cos(u))*cos(v)))",
          "n2=((T*sin(u)*sin(v))*((1+T*cos(u))*sin(v))-(T*sin(u)*cos(v))*(-(1+T*cos(u))*cos(v)))",
          "n3=(-(-T*cos(u))*((1+T*cos(u))*sin(v)))",
          "Rapp=u/sqrt(u*u+v*v+t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*Rapp(n2(u,v,t),n1(u,v,t),n3(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,1)","Gx(u,v,0)"],
        "Fy": ["Gy(u,v,1)","Gy(u,v,0)"],
        "Fz": ["Gz(u,v,1)","Gz(u,v,0)"],
        "Umax": ["2*pi","2*pi"],
        "Umin": ["0","0"],
        "Vmax": ["2*pi","2*pi"],
        "Vmin": ["0","0"]
      },
        "Sliders": {
          "SetNames": ["TwistedTori","InkaSun","InkaSun2"],
          "Max": ["15","3","15","3","15","3"],
          "Min": ["0","1","0","1","0","1"],
          "Name": ["N","M"],
          "Position": ["4","3","2","1","4","2"],
          "Step": ["1","1","1","1","1","1"]
        }
    },
    {
      "Iso3D": {
        "Description": ["Set of Spheres animation v03 by Abderrahman Taha 07/10/2019"],
        "Name": ["SetofSpheres_02"],
        "Component": ["SetSpheres"],
        "Const": ["Step1=41/100",
          "Step2=41/100",
          "R00=35/1000"],
        "Funct": ["Sphere = (x*x+y*y+z*z-R00)",
          "Sphere1 = Sphere(x,((abs(y)%Step1)-Step1/2),z,t)",
          "Sphere2 =-Sphere1(((abs(x)%Step2)-Step2/2),y,z,t)",
          "Plan = Sphere2(x,y,z-(7/10)*(sin(2*t+((x-((abs(x)%Step2)-Step2/2)-7)^2+(y-((abs(y)%Step1)-Step1/2)-7)^2)/4 )),t)"],
        "Fxyz": ["Plan(x,y,z,t)"],
        "Xmax": ["1393/100"],
        "Xmin": ["0"],
        "Ymax": ["1393/100"],
        "Ymin": ["0"],
        "Zmax": ["1"],
        "Zmin": ["-1"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Set of Spheres animation by Abderrahman Taha 08/10/2019"],
        "Name": ["SetOfSpheres_01"],
        "Component": ["SetSpheres"],
        "Const": ["Step1=4/10","Step2=4/10","R00=31/1000"],
        "Funct": ["Sphere = (x*x+y*y+z*z-R00)",
          "Sphere1 = Sphere(x,y,((abs(z)%Step1)-Step1/2),t)",
          "Sphere2 =-Sphere1(((abs(x)%Step2)-Step2/2),y,z,t)",
          "Plan = Sphere2(x,(7/10)*(sin(2*t+((x)^2+(z)^2)/4 ))+y,z,t)"],
        "Fxyz": ["Plan(x,z,y,t)"],
        "Xmax": ["68/10"],
        "Xmin": ["-64/10"],
        "Ymax": ["68/10"],
        "Ymin": ["-64/10"],
        "Zmax": ["16/10"],
        "Zmin": ["-16/10"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Twisted Torus 01 by Abderrahman Taha 08/10/2019"],
        "Name": ["TwistedTorus"],
        "Component": ["TwistedTorus"],
        "Const": ["th=4",
          "P=5",
          "R=3",
          "M=1"],
        "Funct": ["ThickIso=(x*x-th*th/100)",
          "Cylinder=if(sqrt(x*x+y*y)<R,min(ThickIso(x,y,z,t),ThickIso(y,x,z,t)),1)",
          "Cylinder1=if(sqrt(x*x+y*y)<R,ThickIso(x,y,z,t),1)",
          "Twist = Cylinder(x*cos(M*z/4)+y*sin(M*z/4),x*sin(M*z/4)-y*cos(M*z/4),z,t)",
          "Torus = Twist((sqrt(x*x+z*z)-P),y,atan2(z,x),t)",
          "TorusL =(Torus(x,y,z,t))*min((sqrt(x*x+z*z)-P)^2+y*y-R*R,Torus(x,y,z,t)) "],
        "Fxyz": ["-TorusL(x,y,z,t)"],
        "Xmax": ["(P+R)"],
        "Xmin": ["-(P+R)"],
        "Ymax": ["R"],
        "Ymin": ["-R"],
        "Zmax": ["(P+R)"],
        "Zmin": ["-(P+R)"]
      },
        "Sliders": {
          "Max": ["20","20","10","10","20","20","10","10","20","20","10","10","20","20","10","10"],
          "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
          "Name": ["th","M","P","R"],
          "Position": ["4","1","5","3","10","6","5","3","4","8","5","3","12","4","4","4"],
          "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        }
    },
    {
      "Iso3D": {
        "Description": ["Scherk Torus 0N by Abderrahman Taha 07/10/2019"],
        "Name": ["ScherkTorus_03"],
        "Component": ["Scherk"],
        "Const": ["th=1/10",
          "N=5",
          "n=6",
          "P=3",
          "R=17/10",
          "M=1",
          "c=1/1000"],
        "Funct": ["Scherk_2=(sinh(x)*sinh(y)-sin(z))",
          "Scherk_3=((sinh(x)*sinh(cos(pi/3)*x-sin(pi/3)*y)*sinh(cos(2*pi/3)*x-sin(2*pi/3)*y)-cos(z)) )",
          "Scherk_4=((sinh(x)*sinh(cos(pi/4)*x-sin(pi/4)*y)*sinh(cos(2*pi/4)*x-sin(2*pi/4)*y)*sinh(cos(3*pi/4)*x-sin(3*pi/4)*y)-cos(z)) )",
          "Scherk_5=((sinh(x)*sinh(cos(pi/5)*x-sin(pi/5)*y)*sinh(cos(2*pi/5)*x-sin(2*pi/5)*y)*sinh(cos(3*pi/5)*x-sin(3*pi/5)*y)*sinh(cos(4*pi/5)*x-sin(4*pi/5)*y)-cos(z)) )",
          "Iso=if((N=2),Scherk_2(x,y,z,t),if((N=3),Scherk_3(x,y,z,t),if((N=4),Scherk_4(x,y,z,t),Scherk_5(x,y,z,t))))",
          "DFx=(Iso(x+c,y,z,t)-Iso(x,y,z,t))/c",
          "DFy=(Iso(x,y+c,z,t)-Iso(x,y,z,t))/c",
          "DFz=(Iso(x,y,z+c,t)-Iso(x,y,z,t))/c",
          "Rapport=(x/sqrt(x*x+y*y+z*z))",
          "Iso3=(Iso(x-th*Rapport(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-th*Rapport(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z-th*Rapport(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))",
          "Iso2=(Iso(x+th*Rapport(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+th*Rapport(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z+th*Rapport(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))",
          "ThickIso=(Iso2(x,y,z,t)*Iso3(x,y,z,t))",
          "Cylinder=if(sqrt(x*x+y*y)<R,ThickIso(x,y,2*t+z,t),1)",
          "Twist = Cylinder(x*cos(M*z/n)-y*sin(M*z/n),x*sin(M*z/n)+y*cos(M*z/n),z,t)",
          "Torus = Twist((sqrt(x*x+z*z)-P),y,n*atan2(z,x),t)"],
        "Fxyz": ["-Torus(x,z,y,t)"],
        "Xmax": ["P+R"],
        "Xmin": ["-(P+R) "],
        "Ymax": ["P+R"],
        "Ymin": ["-(P+R)"],
        "Zmax": ["R"],
        "Zmin": ["-R"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Scherk Torus 02 by Abderrahman Taha 07/10/2019"],
        "Name": ["ScherkTorus_02"],
        "Component": ["Scherk"],
        "Const": ["th=2/10",
          "N=10",
          "R=8",
          "L=6"],
        "Funct": ["Scherk=((sinh(x)*sinh(cos(pi/3)*x-sin(pi/3)*y)*sinh(cos(2*pi/3)*x-sin(2*pi/3)*y)-cos(z)))",
          "DFx=(Scherk(x+(1/100),y,z,t)-Scherk(x,y,z,t))*100",
          "DFy=(Scherk(x,y+(1/100),z,t)-Scherk(x,y,z,t))*100",
          "DFz=(Scherk(x,y,z+(1/100),t)-Scherk(x,y,z,t))*100",
          "Rapport2=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
          "Iso3=(Scherk(x-DFx(x,y,z,t)*th/Rapport2(x,y,z,t),y-DFy(x,y,z,t)*th/Rapport2(x,y,z,t),z-DFz(x,y,z,t)*th/Rapport2(x,y,z,t),t))",
          "Iso2=(Scherk(x+DFx(x,y,z,t)*th/Rapport2(x,y,z,t),y+DFy(x,y,z,t)*th/Rapport2(x,y,z,t),z+DFz(x,y,z,t)*th/Rapport2(x,y,z,t),t))",
          "TickScherk=(Iso2(x,y,z,t)*Iso3(x,y,z,t))",
          "ScherkTorus=if(sqrt(x*x+y*y)<(16/5),TickScherk(x,y,z,t),1)",
          "Torus = ScherkTorus((sqrt(x*x+z*z)-R),y,N*atan2(z,x),t)"],
        "Fxyz": ["-Torus(x,z,y,t)"],
        "Xmax": ["11"],
        "Xmin": ["-11 "],
        "Ymax": ["11"],
        "Ymin": ["-11 "],
        "Zmax": ["35/10"],
        "Zmin": ["-35/10"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Scherk Torus 01 by Abderrahman Taha 07/10/2019"],
        "Name": ["ScherkTorus_01"],
        "Component": ["Scherk"],
        "Const": ["N=10",
          "R=8"],
        "Funct": ["Scherk0=-((x*y-z)*(x*y-z)-4/10)",
          "Scherk1=if((abs(x)<3 & abs(y)<3),Scherk0(sinh(x),sinh(y),sin(z),t),0)",
          "Scherk2=Scherk1(x*cos(t)-y*sin(t),x*sin(t)+y*cos(t),z,t)",
          "Torus = Scherk2((sqrt(x*x+z*z)-R),y,N*atan2(z,x),t)"],
        "Fxyz": ["Torus(x,y,z,t)"],
        "Xmax": ["11"],
        "Xmin": ["-11 "],
        "Ymax": ["35/10"],
        "Ymin": ["-35/10 "],
        "Zmax": ["11"],
        "Zmin": ["-11 "]
      }
    },
    {
      "Param3D": {
        "Description": ["Blobby Torus by Abderrahman Taha 07/10/2019"],
        "Name": ["Blobby_Torus"],
        "Component": ["BlobbyTorus"],
        "Funct": ["G1=(8+(sin(2*(u-v+t+sin(v-u)))+3)*cos(u))*cos(v)",
          "G2=(8+(sin(2*(u-v+t+sin(v-u)))+3)*cos(u))*sin(v)",
          "G3=((sin(2*(u-v+t+sin(v-u)))+3)*sin(u))"],
        "Fx": ["-G1(u,v,t)"],
        "Fy": ["G2(u,v,t)"],
        "Fz": ["G3(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Texture": {
        "Colors": ["R= if((abs(7*u)%pi/2& abs(7*v)%pi/3),(6/10),1) ",
          "G= if((abs(7*u)%pi/2| abs(7*v)%pi/3),(8/10),(4/10)) ",
          "B= if((abs(7*u)%pi/2| abs(7*v)%pi/3),(6/10),(1/10)) ",
          "T=1"],
        "Name": "Candy",
        "Noise": "1"
      }
    },
    {
        "Param3D": {
            "Description ": ["Wireframe NKlein v1 (Jenner's NKlein) by Abderrahman Taha 03/08/2019"],
            "Name": ["NKlein_wire_01"],
            "Const": ["T=6","S=3","r1=6","H=r1/99","du=1/100000","dv=1/100000","u1max=2*pi","u1min=0","v1max=2*pi","v1min=0","M=114","N=16","umin=0","umax=2*pi","vmin=0","vmax=2*pi","Gu=(u1max-u1min)/N","Gv=(v1max-v1min)/M"],
            "Funct": ["W=((S+1)/4)*cos((S+1)*v+pi/T)+sqrt(2)","Rapp=u/sqrt(u*u+v*v+t*t)","Bx = 1/sqrt(u*u+v*v+t*t)","Fx = S*cos(v)+cos(S*v)-W(u,v,t)*sin(v*(S-1)/2)*cos(u)","Fy = W(u,v,t)*sin(u)","Fz = S*sin(v)-sin(S*v)-W(u,v,t)*cos(v*(S-1)/2)*cos(u)","DFxu=((Fx(u+du,v,t)-Fx(u,v,t))/du)","DFxv=((Fx(u,v+dv,t)-Fx(u,v,t))/dv)","DFyu=((Fy(u+du,v,t)-Fy(u,v,t))/du)","DFyv=((Fy(u,v+dv,t)-Fy(u,v,t))/dv)","DFzu=((Fz(u+du,v,t)-Fz(u,v,t))/du)","DFzv=((Fz(u,v+dv,t)-Fz(u,v,t))/dv)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","Thickness2=H*sin(M*pi*(v-v1min)/(v1max-v1min)+((N*(u-u1min)/(u1max-u1min)))*(pi)+pi/2)","Thickness1=H*sin(N*pi*(u-u1min)/(u1max-u1min)+((M*(v-v1min)/(v1max-v1min)))*(pi)-pi/2)","Thickness3=if((sin(v)*cos(v)>0),2*H,-2*H)","TFx=Fx(u,v,t)+Thickness3(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","TFy=Fy(u,v,t)+Thickness3(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","TFz=Fz(u,v,t)+Thickness3(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Tx=Fx(u,v,t)+Thickness1(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Ty=Fy(u,v,t)+Thickness1(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Tz=Fz(u,v,t)+Thickness1(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Sx=Fx(u,v,t)+Thickness2(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Sy=Fy(u,v,t)+Thickness2(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Sz=Fz(u,v,t)+Thickness2(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","DFxu=((Fx(u+du,v,t)-Fx(u,v,t))/du)","DFxv=((Fx(u,v+dv,t)-Fx(u,v,t))/dv)","DFyu=((Fy(u+du,v,t)-Fy(u,v,t))/du)","DFyv=((Fy(u,v+dv,t)-Fy(u,v,t))/dv)","DFzu=((Fz(u+du,v,t)-Fz(u,v,t))/du)","DFzv=((Fz(u,v+dv,t)-Fz(u,v,t))/dv)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","F2x=Tx(u1min+CmpId(0)*Gu,v,t)","F2y=Ty(u1min+CmpId(0)*Gu,v,t)","F2z=Tz(u1min+CmpId(0)*Gu,v,t)","DF2xv=DFxv(u1min+CmpId(0)*Gu,v,t)","DF2yv=DFyv(u1min+CmpId(0)*Gu,v,t)","DF2zv=DFzv(u1min+CmpId(0)*Gu,v,t)","DF2xv2=n1(u1min+CmpId(0)*Gu,v,t)","DF2yv2=n2(u1min+CmpId(0)*Gu,v,t)","DF2zv2=n3(u1min+CmpId(0)*Gu,v,t)","Nxv=Rapp(DF2xv2(u,v,t),DF2yv2(u,v,t),DF2zv2(u,v,t))","Nyv=Rapp(DF2yv2(u,v,t),DF2xv2(u,v,t),DF2zv2(u,v,t))","Nzv=Rapp(DF2zv2(u,v,t),DF2yv2(u,v,t),DF2xv2(u,v,t))","Binxv=(DF2yv(u,v,t)*Nzv(u,v,t)-DF2zv(u,v,t)*Nyv(u,v,t))*Bx(DF2xv(u,v,t),DF2yv(u,v,t),DF2zv(u,v,t))","Binyv=(DF2zv(u,v,t)*Nxv(u,v,t)-DF2xv(u,v,t)*Nzv(u,v,t))*Bx(DF2xv(u,v,t),DF2yv(u,v,t),DF2zv(u,v,t))","Binzv=(DF2xv(u,v,t)*Nyv(u,v,t)-DF2yv(u,v,t)*Nxv(u,v,t))*Bx(DF2xv(u,v,t),DF2yv(u,v,t),DF2zv(u,v,t))","Tx=F2x(u,v,t)+(r1/100)*(Nxv(u,v,t)*cos(u)+Binxv(u,v,t)*sin(u))","Ty=F2y(u,v,t)+(r1/100)*(Nyv(u,v,t)*cos(u)+Binyv(u,v,t)*sin(u))","Tz=F2z(u,v,t)+(r1/100)*(Nzv(u,v,t)*cos(u)+Binzv(u,v,t)*sin(u))","F2x=Sx(u,v1min+(CmpId(0)-(N+1))*Gv,t)","F2y=Sy(u,v1min+(CmpId(0)-(N+1))*Gv,t)","F2z=Sz(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2xu=DFxu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2yu=DFyu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2zu=DFzu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2xu2=n1(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2yu2=n2(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2zu2=n3(u,v1min+(CmpId(0)-(N+1))*Gv,t)","Nxu=Rapp(DF2xu2(u,v,t),DF2yu2(u,v,t),DF2zu2(u,v,t))","Nyu=Rapp(DF2yu2(u,v,t),DF2xu2(u,v,t),DF2zu2(u,v,t))","Nzu=Rapp(DF2zu2(u,v,t),DF2yu2(u,v,t),DF2xu2(u,v,t))","Binxu=(DF2yu(u,v,t)*Nzu(u,v,t)-DF2zu(u,v,t)*Nyu(u,v,t))*Bx(DF2xu(u,v,t),DF2yu(u,v,t),DF2zu(u,v,t))","Binyu=(DF2zu(u,v,t)*Nxu(u,v,t)-DF2xu(u,v,t)*Nzu(u,v,t))*Bx(DF2xu(u,v,t),DF2yu(u,v,t),DF2zu(u,v,t))","Binzu=(DF2xu(u,v,t)*Nyu(u,v,t)-DF2yu(u,v,t)*Nxu(u,v,t))*Bx(DF2xu(u,v,t),DF2yu(u,v,t),DF2zu(u,v,t))","Sx=F2x(u,v,t)+(r1/100)*(Nxu(u,v,t)*cos(v)+Binxu(u,v,t)*sin(v))","Sy=F2y(u,v,t)+(r1/100)*(Nyu(u,v,t)*cos(v)+Binyu(u,v,t)*sin(v))","Sz=F2z(u,v,t)+(r1/100)*(Nzu(u,v,t)*cos(v)+Binzu(u,v,t)*sin(v))"],
            "Component": ["PlainWeave_00","PlainWeave_01","PlainWeave_02","PlainWeave_03","PlainWeave_04","PlainWeave_05","PlainWeave_06","PlainWeave_07","PlainWeave_08","PlainWeave_09","PlainWeave_10","PlainWeave_11","PlainWeave_12","PlainWeave_13","PlainWeave_14","PlainWeave_15","PlainWeave_16","PlainWeave_17","PlainWeave_18","PlainWeave_19","PlainWeave_20","PlainWeave_21","PlainWeave_22","PlainWeave_23","PlainWeave_24","PlainWeave_25","PlainWeave_26","PlainWeave_27","PlainWeave_28","PlainWeave_29","PlainWeave_30","PlainWeave_31","PlainWeave_32","PlainWeave_33","PlainWeave_34","PlainWeave_35","PlainWeave_36","PlainWeave_37","PlainWeave_38","PlainWeave_39","PlainWeave_40","PlainWeave_41","PlainWeave_42","PlainWeave_43","PlainWeave_44","PlainWeave_45","PlainWeave_46","PlainWeave_47","PlainWeave_48","PlainWeave_49","PlainWeave_50","PlainWeave_51","PlainWeave_52","PlainWeave_53","PlainWeave_54","PlainWeave_55","PlainWeave_56","PlainWeave_57","PlainWeave_58","PlainWeave_59","PlainWeave_60","PlainWeave_61","PlainWeave_62","PlainWeave_63","PlainWeave_64","PlainWeave_65","PlainWeave_66","PlainWeave_67","PlainWeave_68","PlainWeave_69","PlainWeave_70","PlainWeave_71","PlainWeave_72","PlainWeave_73","PlainWeave_74","PlainWeave_75","PlainWeave_76","PlainWeave_77","PlainWeave_78","PlainWeave_79","PlainWeave_80","PlainWeave_81","PlainWeave_82","PlainWeave_83","PlainWeave_84","PlainWeave_85","PlainWeave_86","PlainWeave_87","PlainWeave_88","PlainWeave_89","PlainWeave_90","PlainWeave_91","PlainWeave_92","PlainWeave_93","PlainWeave_94","PlainWeave_95","PlainWeave_96","PlainWeave_97","PlainWeave_98","PlainWeave_99","PlainWeave_100","PlainWeave_101","PlainWeave_102","PlainWeave_103","PlainWeave_104","PlainWeave_105","PlainWeave_106","PlainWeave_107","PlainWeave_108","PlainWeave_109","PlainWeave_110","PlainWeave_111","PlainWeave_112","PlainWeave_113","PlainWeave_114","PlainWeave_115","PlainWeave_116","PlainWeave_117","PlainWeave_118","PlainWeave_119","PlainWeave_120","PlainWeave_121","PlainWeave_122","PlainWeave_123","PlainWeave_124","PlainWeave_125","PlainWeave_126","PlainWeave_127","PlainWeave_128","PlainWeave_129","PlainWeave_130"],
            "Fx": ["Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","TFx(u,v,t)"],
            "Fy": ["Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","TFy(u,v,t)"],
            "Fz": ["Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","TFz(u,v,t)"],
            "Grid": ["75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","300","300"],
            "Umax": ["umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax"],
            "Umin": ["umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin"],
            "Vmax": ["vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax"],
            "Vmin": ["vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin"]
        },
        "Texture": {
            "Colors": ["R=if(cmpId = (130),(6/10),(9/10))","G=if((cmpId = 130),(6/10),(6/10))","B=if((cmpId = 130),(6/10),(0))","T=if((cmpId = 130),(4/10),(1))"],
            "Name": "Gold",
            "Noise": ""
        }
    },
    {
        "Param3D": {
            "Description ": ["Wireframe NKlein v2 (Bonan-Jeener's Klein) by Abderrahman Taha 07/10/2019"],
            "Name": ["NKlein_wire_02"],
            "Const": ["T=-3/2","S=5","r1=6","H=-r1/99","du=1/100000","dv=1/100000","u1max=2*pi","u1min=0","v1max=2*pi","v1min=0","M=114","N=16","umin=0","umax=2*pi","vmin=0","vmax=2*pi","Gu=(u1max-u1min)/N","Gv=(v1max-v1min)/M"],
            "Funct": ["W=sin((S-1)*v)+T","Rapp=u/sqrt(u*u+v*v+t*t)","Bx = 1/sqrt(u*u+v*v+t*t)","Fx=S*cos(v)-cos(S*v)-((S-1)/S)*W(u,v,t)*sin(v*(S+1)/2)*cos(u)","Fy=S*sin(v)-sin(S*v)+((S-1)/S)*W(u,v,t)*cos(v*(S+1)/2)*cos(u)","Fz=W(u,v,t)*sin(u)","DFxu=((Fx(u+du,v,t)-Fx(u,v,t))/du)","DFxv=((Fx(u,v+dv,t)-Fx(u,v,t))/dv)","DFyu=((Fy(u+du,v,t)-Fy(u,v,t))/du)","DFyv=((Fy(u,v+dv,t)-Fy(u,v,t))/dv)","DFzu=((Fz(u+du,v,t)-Fz(u,v,t))/du)","DFzv=((Fz(u,v+dv,t)-Fz(u,v,t))/dv)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","Thickness2=H*sin(M*pi*(v-v1min)/(v1max-v1min)+((N*(u-u1min)/(u1max-u1min)))*(pi)+pi/2)","Thickness1=H*sin(N*pi*(u-u1min)/(u1max-u1min)+((M*(v-v1min)/(v1max-v1min)))*(pi)-pi/2)","Thickness3=if((sin(v)*cos(v)>0),2*H,-2*H)","TFx=Fx(u,v,t)+Thickness3(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","TFy=Fy(u,v,t)+Thickness3(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","TFz=Fz(u,v,t)+Thickness3(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Tx=Fx(u,v,t)+Thickness1(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Ty=Fy(u,v,t)+Thickness1(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Tz=Fz(u,v,t)+Thickness1(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Sx=Fx(u,v,t)+Thickness2(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Sy=Fy(u,v,t)+Thickness2(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Sz=Fz(u,v,t)+Thickness2(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","DFxu=((Fx(u+du,v,t)-Fx(u,v,t))/du)","DFxv=((Fx(u,v+dv,t)-Fx(u,v,t))/dv)","DFyu=((Fy(u+du,v,t)-Fy(u,v,t))/du)","DFyv=((Fy(u,v+dv,t)-Fy(u,v,t))/dv)","DFzu=((Fz(u+du,v,t)-Fz(u,v,t))/du)","DFzv=((Fz(u,v+dv,t)-Fz(u,v,t))/dv)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","F2x=Tx(u1min+CmpId(0)*Gu,v,t)","F2y=Ty(u1min+CmpId(0)*Gu,v,t)","F2z=Tz(u1min+CmpId(0)*Gu,v,t)","DF2xv=DFxv(u1min+CmpId(0)*Gu,v,t)","DF2yv=DFyv(u1min+CmpId(0)*Gu,v,t)","DF2zv=DFzv(u1min+CmpId(0)*Gu,v,t)","DF2xv2=n1(u1min+CmpId(0)*Gu,v,t)","DF2yv2=n2(u1min+CmpId(0)*Gu,v,t)","DF2zv2=n3(u1min+CmpId(0)*Gu,v,t)","Nxv=Rapp(DF2xv2(u,v,t),DF2yv2(u,v,t),DF2zv2(u,v,t))","Nyv=Rapp(DF2yv2(u,v,t),DF2xv2(u,v,t),DF2zv2(u,v,t))","Nzv=Rapp(DF2zv2(u,v,t),DF2yv2(u,v,t),DF2xv2(u,v,t))","Binxv=(DF2yv(u,v,t)*Nzv(u,v,t)-DF2zv(u,v,t)*Nyv(u,v,t))*Bx(DF2xv(u,v,t),DF2yv(u,v,t),DF2zv(u,v,t))","Binyv=(DF2zv(u,v,t)*Nxv(u,v,t)-DF2xv(u,v,t)*Nzv(u,v,t))*Bx(DF2xv(u,v,t),DF2yv(u,v,t),DF2zv(u,v,t))","Binzv=(DF2xv(u,v,t)*Nyv(u,v,t)-DF2yv(u,v,t)*Nxv(u,v,t))*Bx(DF2xv(u,v,t),DF2yv(u,v,t),DF2zv(u,v,t))","Tx=F2x(u,v,t)+(r1/100)*(Nxv(u,v,t)*cos(u)+Binxv(u,v,t)*sin(u))","Ty=F2y(u,v,t)+(r1/100)*(Nyv(u,v,t)*cos(u)+Binyv(u,v,t)*sin(u))","Tz=F2z(u,v,t)+(r1/100)*(Nzv(u,v,t)*cos(u)+Binzv(u,v,t)*sin(u))","F2x=Sx(u,v1min+(CmpId(0)-(N+1))*Gv,t)","F2y=Sy(u,v1min+(CmpId(0)-(N+1))*Gv,t)","F2z=Sz(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2xu=DFxu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2yu=DFyu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2zu=DFzu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2xu2=n1(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2yu2=n2(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2zu2=n3(u,v1min+(CmpId(0)-(N+1))*Gv,t)","Nxu=Rapp(DF2xu2(u,v,t),DF2yu2(u,v,t),DF2zu2(u,v,t))","Nyu=Rapp(DF2yu2(u,v,t),DF2xu2(u,v,t),DF2zu2(u,v,t))","Nzu=Rapp(DF2zu2(u,v,t),DF2yu2(u,v,t),DF2xu2(u,v,t))","Binxu=(DF2yu(u,v,t)*Nzu(u,v,t)-DF2zu(u,v,t)*Nyu(u,v,t))*Bx(DF2xu(u,v,t),DF2yu(u,v,t),DF2zu(u,v,t))","Binyu=(DF2zu(u,v,t)*Nxu(u,v,t)-DF2xu(u,v,t)*Nzu(u,v,t))*Bx(DF2xu(u,v,t),DF2yu(u,v,t),DF2zu(u,v,t))","Binzu=(DF2xu(u,v,t)*Nyu(u,v,t)-DF2yu(u,v,t)*Nxu(u,v,t))*Bx(DF2xu(u,v,t),DF2yu(u,v,t),DF2zu(u,v,t))","Sx=F2x(u,v,t)+(r1/100)*(Nxu(u,v,t)*cos(v)+Binxu(u,v,t)*sin(v))","Sy=F2y(u,v,t)+(r1/100)*(Nyu(u,v,t)*cos(v)+Binyu(u,v,t)*sin(v))","Sz=F2z(u,v,t)+(r1/100)*(Nzu(u,v,t)*cos(v)+Binzu(u,v,t)*sin(v))"],
            "Component": ["PlainWeave_00","PlainWeave_01","PlainWeave_02","PlainWeave_03","PlainWeave_04","PlainWeave_05","PlainWeave_06","PlainWeave_07","PlainWeave_08","PlainWeave_09","PlainWeave_10","PlainWeave_11","PlainWeave_12","PlainWeave_13","PlainWeave_14","PlainWeave_15","PlainWeave_16","PlainWeave_17","PlainWeave_18","PlainWeave_19","PlainWeave_20","PlainWeave_21","PlainWeave_22","PlainWeave_23","PlainWeave_24","PlainWeave_25","PlainWeave_26","PlainWeave_27","PlainWeave_28","PlainWeave_29","PlainWeave_30","PlainWeave_31","PlainWeave_32","PlainWeave_33","PlainWeave_34","PlainWeave_35","PlainWeave_36","PlainWeave_37","PlainWeave_38","PlainWeave_39","PlainWeave_40","PlainWeave_41","PlainWeave_42","PlainWeave_43","PlainWeave_44","PlainWeave_45","PlainWeave_46","PlainWeave_47","PlainWeave_48","PlainWeave_49","PlainWeave_50","PlainWeave_51","PlainWeave_52","PlainWeave_53","PlainWeave_54","PlainWeave_55","PlainWeave_56","PlainWeave_57","PlainWeave_58","PlainWeave_59","PlainWeave_60","PlainWeave_61","PlainWeave_62","PlainWeave_63","PlainWeave_64","PlainWeave_65","PlainWeave_66","PlainWeave_67","PlainWeave_68","PlainWeave_69","PlainWeave_70","PlainWeave_71","PlainWeave_72","PlainWeave_73","PlainWeave_74","PlainWeave_75","PlainWeave_76","PlainWeave_77","PlainWeave_78","PlainWeave_79","PlainWeave_80","PlainWeave_81","PlainWeave_82","PlainWeave_83","PlainWeave_84","PlainWeave_85","PlainWeave_86","PlainWeave_87","PlainWeave_88","PlainWeave_89","PlainWeave_90","PlainWeave_91","PlainWeave_92","PlainWeave_93","PlainWeave_94","PlainWeave_95","PlainWeave_96","PlainWeave_97","PlainWeave_98","PlainWeave_99","PlainWeave_100","PlainWeave_101","PlainWeave_102","PlainWeave_103","PlainWeave_104","PlainWeave_105","PlainWeave_106","PlainWeave_107","PlainWeave_108","PlainWeave_109","PlainWeave_110","PlainWeave_111","PlainWeave_112","PlainWeave_113","PlainWeave_114","PlainWeave_115","PlainWeave_116","PlainWeave_117","PlainWeave_118","PlainWeave_119","PlainWeave_120","PlainWeave_121","PlainWeave_122","PlainWeave_123","PlainWeave_124","PlainWeave_125","PlainWeave_126","PlainWeave_127","PlainWeave_128","PlainWeave_129","PlainWeave_130"],
            "Fx": ["Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","TFx(u,v,t)"],
            "Fy": ["Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","TFy(u,v,t)"],
            "Fz": ["Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","TFz(u,v,t)"],
            "Grid": ["75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","300","300"],
            "Umax": ["umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax"],
            "Umin": ["umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin"],
            "Vmax": ["vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax"],
            "Vmin": ["vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin"]
        },
        "Texture": {
               "Colors": [
                   "R=if((cmpId = 130),(9/10),(6/10))",
                   "G=if((cmpId = 130),(2/10),(4/10))",
                   "B=if((cmpId = 130),(3/10),(0))",
                   "T=if((cmpId = 130),(3/10),(1))"
               ],
               "Name": "Gold",
               "Noise": ""
           }
    },
    {
        "Param3D": {
            "Description": ["Jeener's Klein surface v1 by Abderrahman Taha 26/07/2018"],
            "Name": ["N_Klein_v1"],
            "Component": ["NKlein"],
            "Grid": ["300","300"],
            "Const": ["T=5","S=2","P=6","M=8"],
            "Funct": ["W=((S+1)/4)*cos((S+1)*u+pi/T)+sqrt(2)"],
            "Fx": ["S*cos(u)+cos(S*u)-W(u,v,t)*sin(u*(S-1)/2)*cos(v)"],
            "Fy": ["W(u,v,t)*sin(v)"],
            "Fz": ["S*sin(u)-sin(S*u)-W(u,v,t)*cos(u*(S-1)/2)*cos(v)"],
            "Umax": ["2*pi"],
            "Umin": ["0"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        },
        "Texture": {
            "Colors": ["R=if((i_indx)%(M)>P | (j_indx)%(M)>P,(8/10),(8/10))","G= if((i_indx)%(M)>P | (j_indx)%(M)>P,(2/10),(6/10))","B= if((i_indx)%(M)>P | (j_indx)%(M)>P,(2/10),(2/10))","T= 1"],
            "Name": "square",
            "Noise": ""
        }
    },
    {
        "Param3D": {
            "Description": ["Bonan-Jeener's Klein surface by Abderrahman Taha 25/07/2018"],
            "Name": ["N_Klein_v2"],
            "Component": ["NKlein"],
            "Const": ["T=-3/2","M=4"],
            "Funct": ["W=sin((M-1)*u)+T"],
            "Fx": ["M*cos(u)-cos(M*u)-((M-1)/M)*W(u,v,t)*sin(u*(M+1)/2)*cos(v)"],
            "Fy": ["M*sin(u)-sin(M*u)+((M-1)/M)*W(u,v,t)*cos(u*(M+1)/2)*cos(v)"],
            "Fz": ["W(u,v,t)*sin(v)"],
            "Umax": ["2*pi"],
            "Umin": ["0"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        },
        "Sliders": {
            "Max": ["12"],
            "Min": ["1"],
            "Name": ["M"],
            "Position": ["5"],
            "Step": ["1"]
        }
    },
    {
        "Param3D": {
        "Description ": ["Gears by Abderrahman Taha (Update) 27/06/2018"],
        "Name": ["Gears"],
        "Funct": ["F1=(R3+(R/(10*N))*cos(N2*u/N+((R/(10*N))-R/10)/(R/(10*N))*v)+(R/10-(R/(10*N)))*cos(N2*u/N+v))","F2=((R/(10*N))*sin(N2*u/N+((R/(10*N))-R/10)/(R/(10*N))*v)+(R/10-(R/(10*N)))*sin(N2*u/N+v))","F3=(R3+(R/(10*N1))*cos(N2*u/N1+((R/(10*N1))-R/10)/(R/(10*N1))*v)+(R/10-(R/(10*N1)))*cos(N2*u/N1+v))","F4=((R/(10*N1))*sin(N2*u/N1+((R/(10*N1))-R/10)/(R/(10*N1))*v)+(R/10-(R/(10*N1)))*sin(N2*u/N1+v))"],
        "Fx": ["-sin(u)*F1(u-t,v,t)","-sin(u)*F3(u-t,v,t)","-sin(u)*F3(u-t,v,t)"],
        "Fy": ["cos(u)*F1(u-t,v,t)","cos(u)*F3(u-t,v,t)","cos(u)*F3(u-t,v,t)"],
        "Fz": ["F2(u-t,v,t)+3","F4(u-t,v,t) ","F4(u-t,v,t)+61/10"],
        "Component": ["MultiSidedTorus_0 ","MultiSidedTorus_1","MultiSidedTorus_2"],
        "Const": ["N=4","N1=-4","R3=3","R=15","N2=4","P=8","M=10"],
        "Umax": ["pi","pi","pi"],
        "Umin": ["-pi","-pi","-pi"],
        "Vmax": ["pi","pi","pi"],
        "Vmin": ["-pi","-pi","-pi"]
        },
        "Texture": {
        "Colors": ["R=if((cmpId =1),if((i_indx)%(M)>P | (j_indx)%(M)>P,(8/10),(9/10)),if((i_indx)%(M)>P | (j_indx)%(M)>P,(8/10),(2/10)))","G= if((cmpId =2),if((i_indx)%(M)>P | (j_indx)%(M)>P,(8/10),(7/10)),if((i_indx)%(M)>P | (j_indx)%(M)>P,(8/10),(1/10)))","B= if((cmpId >2),if((i_indx)%(M)>P | (j_indx)%(M)>P,(8/10),(9/10)),if((i_indx)%(M)>P | (j_indx)%(M)>P,(8/10),(2/10)))","T= 1"],
        "Name": "square",
        "Noise": "1"
        }
    },
    {
        "Iso3D": {
            "Description": ["Script by Abderrahman Taha (27/04/2020) to generate TPMS lattices with function definition F,thickness (T) and density (dx,dy,dz)"],
            "Name": ["SchwarzP_Lattice"],
            "Component": ["SchwarzP"],
            "Const": ["T=3/10",
                "dx=5*pi",
                "dy=3*pi",
                "dz=3*pi",
                "m=1/1000",
                "c=1/10000"],
            "Funct": ["F=cos(x)+cos(y)+cos(z)",
                "F1=cos(x)*sin(y)+sin(x)*cos(z)+cos(y)*sin(z)",
                "DFx=((F(x+c,y,z,t)-F(x,y,z,t))/c)",
                "DFy=((F(x,y+c,z,t)-F(x,y,z,t))/c)",
                "DFz=((F(x,y,z+c,t)-F(x,y,z,t))/c)",
                "Rapp=x/sqrt(x*x+y*y+z*z)",
                "G=((F(x-T*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-T*Rapp(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z-T*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t)))",
                "L=(F(x+T*Rapp(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+T*Rapp(DFy(x,y,z,t),DFz(x,y,z,t),DFx(x,y,z,t),t),z+T*Rapp(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t))",
                "Iso=(L(x,y,z,t)*G(x,y,z,t))",
                "ExternalShape=(abs(x)+m<dx & abs(y)+m<dy & abs(z)+m<dz)"],
            "Fxyz": ["if(ExternalShape(x,y,z,t),Iso(x,y,z,t),1)"],
            "Xmax": ["dx"],
            "Xmin": ["-dx"],
            "Ymax": ["dy"],
            "Ymin": ["-dy"],
            "Zmax": ["dz"],
            "Zmin": ["-dz"]
        }
    },
    {
        "Iso3D": {
        "Description": ["Oloid by Abderrahman Taha 02/08/2018"],
        "Name": ["Oloid"],
        "Component": ["oloid"],
        "Fxyz": ["(4*x^2+4*x^3-7*x^4-8*x^5+2*x^6+4*x^7+x^8+4*y^2+4*x*y^2-18*x^2*y^2-16*x^3*(y^2)+14*x^4*y^2+12*x^5*y^2-11*y^4-8*x*y^4+22*x^2*y^4+12*x^3*y^4-6*x^4*y^4+10*y^6+4*x*y^6-8*x^2*y^6-3*y^8+4*x*z^2-6*x^2*z^2-48*x^3*z^2-46*x^4*z^2-12*x^5*z^2-10*y^2*z^2-52*x*y^2*z^2-46*x^2*y^2*z^2+12*x^3*y^2*z^2+6*x^4*y^2*z^2+24*x*y^4*z^2+12*x^2*y^4*z^2+6*y^6*z^2+z^4-8*x*z^4-50*x^2*z^4-36*x^3*z^4-6*x^4*z^4-12*y^2*z^4+12*x^2*y^2*z^4-9*y^4*z^4-2*z^6-20*x*z^6-8*x^2*z^6+6*y^2*z^6-3*z^8) "],
        "Xmax": ["1"],
        "Xmin": ["-2"],
        "Ymax": ["1"],
        "Ymin": ["-1"],
        "Zmax": ["1"],
        "Zmin": ["-1"]
        }
    },
    {
      "Iso3D": {
        "Description": ["Tori of Helices by Abderrahman Taha 07/05/2016"],
        "Name": ["Tori of helices"],
        "Component": ["TorHelices"],
        "Const": ["Step1=5",
          "N1=8",
          "N2=8",
          "P1=10",
          "P2=16",
          "Param1 = 2",
          "Param2= 2",
          "Param3= 2",
          "Param4= 10",
          "Param5= 22",
          "Param6= 15",
          "Param7= 20",
          "Param8= 0"],
        "Funct": ["Helix=-fhelix1(x,y,z,Param2,Param3,(Param4/15),(Param5/15),(Param6/15),(Param7/10),Param8*pi/15)",
          "Helix1 = Helix(((abs(x+8*t)%Step1)-Step1/2),y+8*t,z,t)",
          "Cylinder2 = Helix1(N1*atan2(x,z),y, (sqrt(x*x+z*z)-P1),t)",
          "Cylinder3 = Helix1(N1*atan2(x,z),y, (sqrt(x*x+z*z)-P1),t)",
          "Torus3 = Cylinder2((sqrt(y*y+x*x)-P2), N2*atan2(x,y),z,t)"],
        "Fxyz": ["Torus3(x,y,z,t)"],
        "Xmax": ["28"],
        "Xmin": ["-28"],
        "Ymax": ["28"],
        "Ymin": ["-28"],
        "Zmax": ["12"],
        "Zmin": ["-12"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Helical Tori by Abderrahman Taha 08/10/2019"],
        "Name": ["Helical Tori"],
        "Component": ["HelicalTori"],
        "Const": ["M=13/10",
          "N1=8",
          "N2=8",
          "P=85/10",
          "R=145/10"],
        "Funct": ["Diamond=sin(x)*sin(y)*sin(z)-sin(x)*cos(y)*cos(z)-cos(x)*sin(y)*cos(z)/2",
          "isoTransform=if(x*x<(484/100),-Diamond(x,y,z+8*t,t),1)+M*exp(x*x-(256/100))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-P),y,N1*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-R),N2*atan2(y,x),z/(15/10),t)"],
        "Xmax": ["25"],
        "Xmin": ["-25"],
        "Ymax": ["25"],
        "Ymin": ["-25"],
        "Zmax": ["15"],
        "Zmin": ["-15"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Tori of Octahedra v02 by Abderrahman Taha 08/10/2019"],
        "Name": ["ToriofOctahedra"],
        "Component": ["TorOctahedra"],
        "Const": ["Step1=7",
          "Step2=7",
          "N1=20",
          "N2=30",
          "P1=25",
          "P2=40",
          "R00=10"],
        "Funct": ["Octahedra=(abs(x)+abs(y)+abs(z))-38*R00/1000",
          "Octahedra1 = Octahedra(x,y,((abs(z)%(Step1/10))-Step1/20),t)",
          "Octahedra2 =-Octahedra1(((abs(x+2*t)%(Step2/10))-Step2/20),y,z+2*t,t)",
          "Cylinder2 = Octahedra2(x,(sqrt(y*y+z*z)-P1/10),(N1*atan2(y,z)/10),t)",
          "Torus3 = Cylinder2((N2*atan2(x,y)/10),(sqrt(y*y+x*x)-P2/10),z,t)"],
        "Fxyz": ["Torus3(x,y,z,t)"],
        "Xmax": ["((P1+P2)/10+R00/25)"],
        "Xmin": ["-((P1+P2)/10+R00/25)"],
        "Ymax": ["((P1+P2)/10+R00/25)"],
        "Ymin": ["-((P1+P2)/10+R00/25)"],
        "Zmax": ["(P1/10+R00/25)"],
        "Zmin": ["-(P1/10+R00/25)"]
      },
        "Sliders": {
          "Max": ["50","50","50","50","50","50","50","50","50","50","50","50","50","50","50","50","50","50","50","50","50","50","50","50","50"],
          "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
          "Name": ["N1","N2","P1","P2","R00"],
          "Position": ["20","30","25","40","10","15","12","45","40","10","0","29","25","38","14","13","10","50","38","14","12","21","50","50","15"],
          "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        }
    },
    {
      "Iso3D": {
        "Description": ["Tori of Spheres by Abderrahman Taha 08/10/2019"],
        "Name": ["Tori of Spheres"],
        "Component": ["TorSpheres"],
        "Const": ["Step1=7/10",
          "Step2=7/10",
          "M=13/10",
          "N1=2",
          "N2=301/100",
          "P1=25/10",
          "P2=4",
          "R00=1/10",
          "R01=24/100"],
        "Funct": ["Sphere = (x*x+y*y+z*z-R00)",
          "Sphere1 = Sphere(x,y,((abs(z)%Step1)-Step1/2),t)",
          "Sphere2 =-Sphere1(((abs(x+2*t)%Step2)-Step2/2),y,z+2*t,t)",
          "Cylinder2 = Sphere2(x,(sqrt(y*y+z*z)-P1),N1*atan2(y,z),t)",
          "Torus3 = Cylinder2(N2*atan2(x,y),(sqrt(y*y+x*x)-P2),z,t)"],
        "Fxyz": ["Torus3(x,y,z,t)"],
        "Xmax": ["7"],
        "Xmin": ["-7"],
        "Ymax": ["7"],
        "Ymin": ["-7"],
        "Zmax": ["3"],
        "Zmin": ["-3"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Tori of Toris by Abderrahman Taha 08/10/2019"],
        "Name": ["Tori of Toris"],
        "Component": ["TorToris"],
        "Const": ["Step1=6/10",
          "Step2=1",
          "M=13/10",
          "N1=2",
          "N2=35/10",
          "P1=2",
          "P2=4",
          "R00=4/100",
          "R01=24/100"],
        "Funct": ["Torus0 = (sqrt(x*x+y*y)-R01)^2+z*z-R00",
          "Torus1 = Torus0(x,y,((abs(z)%Step1)-Step1/2),t)",
          "Torus2 =-Torus1(((abs(x+t)%Step2)-Step2/2),y,z+t,t)",
          "Cylinder = Torus2(N1*atan2(y,x),(sqrt(x*x+y*y)-P1),z,t)",
          "Cylinder2 = Torus2(x,(sqrt(y*y+z*z)-P1),N1*atan2(y,z),t)",
          "Torus3 = Cylinder2(N2*atan2(x,y),(sqrt(y*y+x*x)-P2),z,t)"],
        "Fxyz": ["Torus3(x,y,z,t)"],
        "Xmax": ["7"],
        "Xmin": ["-7"],
        "Ymax": ["7"],
        "Ymin": ["-7"],
        "Zmax": ["3"],
        "Zmin": ["-3"]
      }
    },
    {
      "Iso3D": {
        "Description": ["Animated Bone Cage model by Abderrahman Taha 12/11/2020"],
        "Name": ["Animated Bone Cage"],
        "Component": ["BoneCage"],
        "Const": ["N1=13",
          "N2=10",
          "P=5",
          "R=15"],
        "Funct": ["P_Skeletal0=-y-z+(51/100)*(-x*y+y*z+z*x)+12/10",
          "P_Skeletal=sin(x)+P_Skeletal0(cos(x),cos(y),cos(z),t)",
          "isoTransform=if((x-pi)*(x-pi)<(13),P_Skeletal(x,y-4*t,z-20*t,t),(1))+exp((x-pi)*(x-pi)-9)",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-P),y,N1*atan2(z,x),t)",
          "isoTransform3=isoTransform2(x*cos(y/N1)-z*sin(y/N1),y,x*sin(y/N1)+z*cos(y/N1),t)"],
        "Fxyz": ["-isoTransform3((sqrt(x*x+y*y)-R),N2*atan2(y,x),z,t)"],
        "Xmax": ["30"],
        "Xmin": ["-30"],
        "Ymax": ["30"],
        "Ymin": ["-30"],
        "Zmax": ["15"],
        "Zmin": ["-15"]
      }
    },
    {
      "Iso3D": {
        "Description ": ["Red giant by Abderrahman Taha 08/10/2019"],
        "Name": ["Red giant"],
        "Component": ["Redgiant"],
        "Fxyz": ["-((x*x+y*y+z*z-1)+(if((t<pi/2),(1),(5)*if(t<pi,abs(sin(t-pi/2)),abs(sin(3*t-pi/2)))))*(NoiseW(6*x,6*y,5*cos(t)+6*z,(4),(2),0) +NoiseW(4*sin(t)+6*x,(5)*cos(t)+6*y,(6)*z,(4),(0),0))/5)*(atan2(y,x)<(pi/2) | atan2(sqrt(x*x+y*y),z)>(pi/2))*(x^2+y^2+z^2-(3/100))"],
        "Xmax": ["1"],
        "Xmin": ["-1"],
        "Ymax": ["1"],
        "Ymin": ["-1"],
        "Zmax": ["1"],
        "Zmin": ["-1"]
      },
      "Texture": {
        "Colors": ["R=(6/10)",
          "G=(24/10)*(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))*sin((x*x+y*y+z*z)/2)",
          "B=(7/10)*(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(2*x,2*y,2*z,(4),(0),(0))+NoiseW(2*x,2*y,2*z,(2),(0),(0))"
      }
    },
    {
      "Iso3D": {
        "Description": ["PrettyBall_2 by Abderrahman Taha 11/12/2019"],
        "Name": ["Pretty_Ball_2"],
        "Component": ["PrettyBall"],
        "Fxyz": ["if((x*x+y*y+z*z<64),(cos(x-t)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x-t))*(cos(x-t)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x-t))-(6/10),(1)) +exp(((x)*(x)+y*y+z*z-64)/3)"],
        "Xmax": ["8"],
        "Xmin": ["-8"],
        "Ymax": ["8"],
        "Ymin": ["-8"],
        "Zmax": ["8"],
        "Zmin": ["-8"]
      },
      "Texture": {
        "Colors": ["R=(73/100)",
          "G=(18/10)*abs(cos(10*(x*x+y*y+z*z)/23)*sin(10*(x*x+y*y+z*z)/23))",
          "B=2*abs(cos(10*(x*x+y*y+z*z)/23)*cos(10*(x*x+y*y+z*z)/23)*sin(10*(x*x+y*y+z*z)/23))","T=1"],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(x,y,z,(4),(2),(0))/2"
      }
    },
    {
      "Iso3D": {
        "Description": ["P_Skeletal Sphere by Abderrahman Taha 08/12/2015"],
        "Name": ["P_Skeletal Sphere"],
        "Component": ["P_Skeletal Sphere"],
        "Const": ["M=1",
          "N=4",
          "P=10",
          "R=13",
          "S=51",
          "T=12"],
        "Funct": ["P_Skeletal=x+y+z+(S/100)*(x*y+y*z+x*z)+(T/10)",
          "isoTransform=if((x*(x-2*pi)<0),P_Skeletal(cos(x),cos(y),cos(z),t),1)+M*exp(x*(x-2*pi))"],
        "Fxyz": ["-isoTransform((sqrt(x*x+y*y+z*z)-R),P*atan2(y,x),N*pi*atan2(z,sqrt(x*x+y*y)),t)"],
        "Xmax": ["19"],
        "Xmin": ["-19"],
        "Ymax": ["19"],
        "Ymin": ["-19"],
        "Zmax": ["19"],
        "Zmin": ["-19"]
      },
        "Sliders": {
          "Max": ["50","50","30","30","100","50","50","50","30","30","100","50","50","50","30","30","100","50","50","50","30","30","100","50"],
          "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
          "Name": ["M","N","P","R","S","T"],
          "Position": ["1","4","10","13","51","12","10","4","10","13","63","12","10","4","6","12","0","9","6","2","5","13","32","13"],
          "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        }
    },
    {
      "Param3D": {
        "Description": ["Original Klein Bottle formula from http://www.gnuplotting.org/klein-bottle/. Implemented by Abderrahman Taha 03/04/2016"],
        "Name": ["Klein_4"],
        "Component": ["Klein"],
        "Funct": ["tx=if(v<2*pi,(A-(A-1)*cos(v))*cos(u),if(v<3*pi,-B+(B+cos(u))*cos(v),-B+B*cos(v)-cos(u)))",
          "ty=if(v<2*pi,(A-(A-1)*cos(v))*sin(u),sin(u))",
          "tz=if(v<pi,-C*sin(v),if(v<2*pi,D*v-D*pi,if(v<3*pi,((D-1)+cos(u))*sin(v)+D*pi,-D*v+D*4*pi  )))"],
        "Fx": ["tx(u,v,t)"],
        "Fy": ["-ty(u,v,t)"],
        "Fz": ["-tz(u,v,t)"],
        "Umax": ["2*pi"],
        "Umin": ["0"],
        "Vmax": ["4*pi"],
        "Vmin": ["0"]
      },
        "Sliders": {
          "Max": ["20","20","20","20","20","20","20","20","20","20","20","20","20","20","20","20"],
          "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
          "Name": ["A","B","C","D"],
          "Position": ["3","2","3","3","5","3","0","3","3","0","9","3","7","6","10","3"],
          "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        }
    },
    {
      "Iso3D": {
        "Description": ["Schwarz P Sphere  by Abderrahman Taha 29/03/2016"],
        "Name": ["Schwarz P Sphere"],
        "Component": ["SchwarzPSphere"],
        "Const": ["M=1",
          "N=10",
          "P=10",
          "th=4"],
        "Funct": ["Iso=cos(x)+cos(y)+cos(z)",
          "Iso2=th*x/(10*sqrt(x*x+y*y+z*z))",
          "Iso4=Iso(x+Iso2(sin(x),sin(y),sin(z),t),y+Iso2(sin(y),sin(x),sin(z),t),z+Iso2(sin(z),sin(y),sin(x),t),t)",
          "Iso5=Iso(x-Iso2(sin(x),sin(y),sin(z),t),y-Iso2(sin(y),sin(x),sin(z),t),z-Iso2(sin(z),sin(y),sin(x),t),t)",
          "SchwarzP= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoTransform=if((x*x<16),SchwarzP(x,y,z,t),1)+M*exp(x*x-14)",
          "SchwarzPSphere =-isoTransform((sqrt(x*x+y*y+z*z)-9),P*pi*atan2(y,sqrt(x*x+z*z)),N*atan2(z,x),t)"],
        "Fxyz": ["SchwarzPSphere(x,z,y,t)"],
        "Xmax": ["13"],
        "Xmin": ["-13"],
        "Ymax": ["13"],
        "Ymin": ["-13"],
        "Zmax": ["13"],
        "Zmin": ["-13"]
      },
        "Sliders": {
          "Max": ["20","20","20","10","20","20","20","10","20","20","20","10"],
          "Min": ["0","0","0","0","0","0","0","0","0","0","0","0"],
          "Name": ["M","N","P","th"],
          "Position": ["10","10","10","4","1","12","7","4","1","5","3","4"],
          "Step": ["1","1","1","1","1","1","1","1","1","1","1","1"]
        }
    },
    {
        "Param3D": {
            "Description ": ["Multi-sided Torus by Abderrahman Taha (Update) 08/10/2019"],
            "Name": ["Multi-sidedTorus"],
            "Component": ["MultiSidedTorus "],
            "Const": ["N=10",
                "R3=3",
                "R=5",
                "N2=4",
                "P=8",
                "M=10"],
            "Funct": ["F1 = (R3+(R/(10*N))*cos(N2*u/N+((R/(10*N))-R/10)/(R/(10*N))*v)+(R/10-(R/(10*N)))*cos(N2*u/N+v))",
                "F2 = ((R/(10*N))*sin(N2*u/N+((R/(10*N))-R/10)/(R/(10*N))*v)+(R/10-(R/(10*N)))*sin(N2*u/N+v))"],
            "Fx": ["-sin(u)*F1(u-t,v,t)"],
            "Fy": ["cos(u)*F1(u-t,v,t) "],
            "Fz": ["F2(u-t,v,t)"],
            "Umax": ["pi"],
            "Umin": ["-pi"],
            "Vmax": ["pi"],
            "Vmin": ["-pi"]
        },
        "Sliders": {
            "Max": ["30","30","50","20"],
            "Min": ["1","1","1","0"],
            "Name": ["N","R3","R","N2"],
            "Position": ["4","3","15","4"],
            "Step": ["1","1","1","1"]
        },
        "Texture": {
            "Colors": ["R= if((i_indx)%(M)>P | (j_indx)%(M)>P,(1/2),(7/10)) ",
                "G= if((i_indx)%(M)>P | (j_indx)%(M)>P,(1/2),(14/100)) ",
                "B= if((i_indx)%(M)>P | (j_indx)%(M)>P,(3/10),(2/10))",
                "T= 1 "],
            "Name": "square",
            "Noise": "1"
        }
    },
    {
      "Param3D": {
        "Description ": ["Under Sea by Abderrahman Taha 25/03/2016"],
        "Name": ["Under The Sea"],
        "Component": ["UnderSea"],
        "Const": ["M=9",
          "N=6",
          "A=5"],
        "Fx": ["u*cos(v)"],
        "Fy": ["u*sin(v)"],
        "Fz": ["A*exp(-u*u)*(sin(M*pi*(u)/3)-u*cos(N*v))/5"],
        "Umax": ["2"],
        "Umin": ["0"],
        "Vmax": ["2*pi"],
        "Vmin": ["0"]
      },
      "Texture": {
        "Colors": ["R=(61/100)",
          "G=(162/100)*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "B=(172/100)*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))","T=1"],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(4*x,4*y,4*z,(4),(2),(0))+NoiseW(4*x,4*y,4*z,(4),(12),(0))"
      },
    "Sliders": {
      "Max": ["30","30","30","30","30","30","30","30","30"],
      "Min": ["0","0","1","0","0","1","0","0","1"],
      "Name": ["M","N","A"],
      "Position": ["9","6","4","9","1","4","20","3","3"],
      "Step": ["1","1","1","1","1","1","1","1","1"]
    }
    },
    {
      "Iso3D": {
        "Description": ["The Dome-2.0 by Abderrahman Taha 27/02/2016"],
        "Name": ["The_Dome_02"],
        "Component": ["Dome"],
        "Cnd": ["sqrt(x*x+y*y+z*z)>S/3"],
        "Const": ["A=4","N1=10","N2=10","R=16"],
        "Funct": ["Scherk=sinh(x)*sinh(y)-A*sin(z)",
          "Scherk2=Scherk(N1*atan2(x,sqrt(y*y+z*z)),(sqrt(x*x+y*y+z*z)-R),N2*atan2(z,y),t)"],
        "Fxyz": ["-Scherk2(z,y,x,t)"],
        "Xmax": ["27"],
        "Xmin": ["-27"],
        "Ymax": ["27"],
        "Ymin": ["-27"],
        "Zmax": ["18"],
        "Zmin": ["-18"]
      },
        "Sliders": {
          "Max": ["20","30","30","30","100","20","30","30","30","100","20","30","30","30","100"],
          "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
          "Name": ["A","N1","N2","R","S"],
          "Position": ["4","10","10","16","63","4","1","7","16","44","4","2","9","15","73"],
          "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        }
    },
    {
      "Iso3D": {
        "Description": ["Schwarz P Tori-1.0 by Abderrahman Taha 08/10/2019"],
        "Name": ["SchwarzP_Tori"],
        "Component": ["Schwarz P Tori"],
        "Const": ["M=1","N1=15","N2=15","R1=8","R2=15","H=4"],
        "Funct": ["Iso=cos(x)+cos(y)+cos(z)",
          "R=H*x/(10*sqrt(x*x+y*y+z*z))",
          "Iso4= (Iso(x+R(sin(x),sin(y),sin(z),t),y+R(sin(y),sin(x),sin(z),t),z+R(sin(z),sin(y),sin(x),t),t))",
          "Iso5= (Iso(x-R(sin(x),sin(y),sin(z),t),y-R(sin(y),sin(x),sin(z),t),z-R(sin(z),sin(y),sin(x),t),t))",
          "SchwarzP= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoTransform=if(x*x<(1024/100),SchwarzP(x,y-2*t,z-3*t,t),1)+M*exp(x*x-9)/10",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-R1),y,N1*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-R2),N2*atan2(y,x),z,t)"],
        "Xmax": ["27"],
        "Xmin": ["-27"],
        "Ymax": ["27"],
        "Ymin": ["-27"],
        "Zmax": ["12"],
        "Zmin": ["-12"]
      },
        "Sliders": {
          "Max": ["20","20","20","15","25","30","20","20","20","15","25","30","20","20","20","15","25","30"],
          "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
          "Name": ["H","N1","N2","R1","R2","M"],
          "Position": ["4","15","15","8","15","1","4","3","13","8","16","0","5","7","9","8","16","0"],
          "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        }
    },
    {
      "Iso3D": {
        "Description": ["Diamond Tori-2.0 by Abderrahman Taha 07/10/2019"],
        "Name": ["DiamondTori"],
        "Component": ["DiamondTori"],
        "Const": ["M=1","N1=10","N2=10","P=5","R=15"],
        "Funct": ["Diamond=sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
          "isoCondition_0=(x^2-(22/10)^2)",
          "isoCondition_1=(x^2-(16/10)^2)",
          "isoTransform=if((isoCondition_0(x,y,z,t)<0),-Diamond(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-P),y,N1*atan2(z,x),t)"],
        "Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-R),N2*atan2(y,x),z,t)"],
        "Xmax": ["25"],
        "Xmin": ["-25"],
        "Ymax": ["25"],
        "Ymin": ["-25"],
        "Zmax": ["105/10"],
        "Zmin": ["-105/10"]
      },
        "Sliders": {
          "Max": ["50","10","25","25","25","50","10","25","25","25","50","10","25","25","25"],
          "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
          "Name": ["M","P","R","N1","N2"],
          "Position": ["1","7","16","10","12","1","7","16","3","11","5","9","14","7","1"],
          "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        }
    },
    {
      "Iso3D": {
        "Description": ["Implicit Costa minimal surface by Abderrahman Taha 07/10/2019"],
         "Name": ["Implicit Costa"],
        "Funct": ["Costa=(z*((x^2+y^2)-18-8*sin((-11+abs(z*13/10))/4)-18*exp((-12+abs(z*13/10))/2))-(x^2-y^2)) ",
          "DFx=((Costa(x+c,y,z,t)-Costa(x,y,z,t))/c)",
          "DFy=((Costa(x,y+c,z,t)-Costa(x,y,z,t))/c)",
          "DFz=((Costa(x,y,z+c,t)-Costa(x,y,z,t))/c)",
          "Rapport=(x/sqrt(x*x+y*y+z*z))",
          "Iso3=Costa(x-T*Rapport(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y-T*Rapport(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z-T*Rapport(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t)",
          "Iso2=Costa(x+T*Rapport(DFx(x,y,z,t),DFy(x,y,z,t),DFz(x,y,z,t),t),y+T*Rapport(DFy(x,y,z,t),DFx(x,y,z,t),DFz(x,y,z,t),t),z+T*Rapport(DFz(x,y,z,t),DFx(x,y,z,t),DFy(x,y,z,t),t),t)",
          "TickIsoExterior=(Iso2(x,y,z,t)*Iso3(x,y,z,t))+exp((4/10)*min((k1*x*x+k1*y*y-100),min(((x+6)^2+k2*y^2+z^2-80),min(((x-6)^2+k2*y^2+z^2-80),min (((y+6)^2+k2*x^2+z^2-80),((y-6)^2+k2*x^2+z^2-80))))))-1"],
        "Component": ["Schwarz"],
        "Const": ["X=16","Y=16","Z=18","c=1/100","T=21/100","k1=1","k2=14/10"],
        "Fxyz": ["TickIsoExterior(x,y,(8*z/10),t)"],
        "Xmax": ["X"],
        "Xmin": ["-X"],
        "Ymax": ["Y"],
        "Ymin": ["-Y"],
        "Zmax": ["Z"],
        "Zmin": ["-Z"]
      },
      "Texture": {
        "Colors": ["R=(8/10)*abs(cos(x)*cos(y)*cos(z))^(1/10)","G=2/10","B=1/100","T=1"],
        "Name": "Lines1",
        "Noise": ""
      }
    },
    {
      "Param3D": {
        "Description ": ["Plain weave patterns over sinusoidal surfaces by Abderrahman Taha 07/10/2019"],
        "Name": ["Sinus_Plain_weave"],
        "Component": ["PlainWeave_00","PlainWeave_01","PlainWeave_02","PlainWeave_03","PlainWeave_04","PlainWeave_05","PlainWeave_06","PlainWeave_07","PlainWeave_08","PlainWeave_09","PlainWeave_10","PlainWeave_11","PlainWeave_12","PlainWeave_13","PlainWeave_14","PlainWeave_15"],
        "Const": ["c=1/10000","umax=1","umin=-1","vmax=1","vmin=-1","N=8","M=8","H=25/1000","k=1/40"],
        "Funct": ["Fx=u","Fy=v","Fz=-sin(pi*((u)^2+(v)^2))/3","DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)","DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)","DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)","DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)","DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)","DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","R=u/sqrt(u^2+v^2+t^2)","Thickness=H*sin(N*pi*(v-vmin)/(vmax-vmin)+int((M*(u-umin)/(umax-umin)+1/2)%M)*pi+pi)","Thickness2=H*sin(N*pi*(u-umin)/(umax-umin)+int((M*(v-vmin)/(vmax-vmin)+1/2)%M)*pi)","Gx=Fx(u,v,t)+Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Gy=Fy(u,v,t)+Thickness(u,v,t)*R(n2(u,v,t),n1(u,v,t),n3(u,v,t))","Gz=Fz(u,v,t)+Thickness(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Gx2=Fx(u,v,t)+Thickness2(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Gy2=Fy(u,v,t)+Thickness2(u,v,t)*R(n2(u,v,t),n1(u,v,t),n3(u,v,t))","Gz2=Fz(u,v,t)+Thickness2(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)"],
        "Fy": ["Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)"],
        "Fz": ["Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)"],
        "Umax": ["umin+(umax-umin)/N-k","umin+2*(umax-umin)/N-k","umin+3*(umax-umin)/N-k","umin+4*(umax-umin)/N-k","umin+5*(umax-umin)/N-k","umin+6*(umax-umin)/N-k","umin+7*(umax-umin)/N-k","umin+8*(umax-umin)/N-k","umax","umax","umax","umax","umax","umax","umax","umax"],
        "Umin": ["umin+k","umin+(umax-umin)/N+k","umin+2*(umax-umin)/N+k","umin+3*(umax-umin)/N+k","umin+4*(umax-umin)/N+k","umin+5*(umax-umin)/N+k","umin+6*(umax-umin)/N+k","umin+7*(umax-umin)/N+k","umin","umin","umin","umin","umin","umin","umin","umin"],
        "Vmax": ["vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmin+(vmax-vmin)/N-k","vmin+2*(vmax-vmin)/N-k","vmin+3*(vmax-vmin)/N-k","vmin+4*(vmax-vmin)/N-k","vmin+5*(vmax-vmin)/N-k","vmin+6*(vmax-vmin)/N-k","vmin+7*(vmax-vmin)/N-k","vmin+8*(vmax-vmin)/N-k"],
        "Vmin": ["vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin+k","vmin+(vmax-vmin)/N+k","vmin+2*(vmax-vmin)/N+k","vmin+3*(vmax-vmin)/N+k","vmin+4*(vmax-vmin)/N+k","vmin+5*(vmax-vmin)/N+k","vmin+6*(vmax-vmin)/N+k","vmin+7*(vmax-vmin)/N+k"]
      },
      "Texture": {
        "Colors": ["R=1/2","G=1/2","B=1/2","T=1"],
        "Name": "Gray",
        "Noise": ""
      }
    },
    {
      "Param3D": {
        "Description ": ["Plain weave Catenoid by Abderrahman Taha 07/10/2019"],
        "Name": ["Catenoid_Plain_weave"],
        "Component": ["PlainWeave_00","PlainWeave_01","PlainWeave_02","PlainWeave_03","PlainWeave_04","PlainWeave_05","PlainWeave_06","PlainWeave_07","PlainWeave_08","PlainWeave_09","PlainWeave_10","PlainWeave_11","PlainWeave_12","PlainWeave_13","PlainWeave_14","PlainWeave_15"],
        "Const": ["c=1/10000","umax=pi","umin=-pi","vmax=pi","vmin=-pi","N=8","M=8","H=200/1000","k=1/20"],
        "Funct": ["Fx=2*cosh(v/2)*cos(u)","Fy=2*cosh(v/2)*sin(u)","Fz=v","DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)","DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)","DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)","DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)","DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)","DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","R=u/sqrt(u^2+v^2+t^2)","Thickness=H*sin(N*pi*(v-vmin)/(vmax-vmin)+int((M*(u-umin)/(umax-umin)+1/2)%M)*pi+pi)","Thickness2=H*sin(N*pi*(u-umin)/(umax-umin)+int((M*(v-vmin)/(vmax-vmin)+1/2)%M)*pi)","Gx=Fx(u,v,t)+Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Gy=Fy(u,v,t)+Thickness(u,v,t)*R(n2(u,v,t),n1(u,v,t),n3(u,v,t))","Gz=Fz(u,v,t)+Thickness(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Gx2=Fx(u,v,t)+Thickness2(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Gy2=Fy(u,v,t)+Thickness2(u,v,t)*R(n2(u,v,t),n1(u,v,t),n3(u,v,t))","Gz2=Fz(u,v,t)+Thickness2(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Fx": ["Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)"],
        "Fy": ["Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)"],
        "Fz": ["Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)"],
        "Umax": ["umin+(umax-umin)/N-k","umin+2*(umax-umin)/N-k","umin+3*(umax-umin)/N-k","umin+4*(umax-umin)/N-k","umin+5*(umax-umin)/N-k","umin+6*(umax-umin)/N-k","umin+7*(umax-umin)/N-k","umin+8*(umax-umin)/N-k","umax","umax","umax","umax","umax","umax","umax","umax"],
        "Umin": ["umin+k","umin+(umax-umin)/N+k","umin+2*(umax-umin)/N+k","umin+3*(umax-umin)/N+k","umin+4*(umax-umin)/N+k","umin+5*(umax-umin)/N+k","umin+6*(umax-umin)/N+k","umin+7*(umax-umin)/N+k","umin","umin","umin","umin","umin","umin","umin","umin"],
        "Vmax": ["vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmin+(vmax-vmin)/N-k","vmin+2*(vmax-vmin)/N-k","vmin+3*(vmax-vmin)/N-k","vmin+4*(vmax-vmin)/N-k","vmin+5*(vmax-vmin)/N-k","vmin+6*(vmax-vmin)/N-k","vmin+7*(vmax-vmin)/N-k","vmin+8*(vmax-vmin)/N-k"],
        "Vmin": ["vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin+k","vmin+(vmax-vmin)/N+k","vmin+2*(vmax-vmin)/N+k","vmin+3*(vmax-vmin)/N+k","vmin+4*(vmax-vmin)/N+k","vmin+5*(vmax-vmin)/N+k","vmin+6*(vmax-vmin)/N+k","vmin+7*(vmax-vmin)/N+k"]
      },
      "Texture": {
         "Colors": [
            "R=1/2",
            "G=1/2",
            "B=1/2",
            "T=1"
         ],
         "Name": "Gray",
         "Noise": ""
      }
    },
    {
        "Param3D": {
            "Description": ["Wireframe Sinus fabric animation by Abderrahman Taha 11/10/2019"],
            "Name": ["Wireframe_sinus"],
            "Component": ["WireframeSinus_00","WireframeSinus_01","WireframeSinus_02","WireframeSinus_03","WireframeSinus_04","WireframeSinus_05","WireframeSinus_06","WireframeSinus_07","WireframeSinus_08","WireframeSinus_09","WireframeSinus_10","WireframeSinus_11","WireframeSinus_12","WireframeSinus_13","WireframeSinus_14","WireframeSinus_15","WireframeSinus_16","WireframeSinus_17","WireframeSinus_18","WireframeSinus_19","WireframeSinus_20","WireframeSinus_00","WireframeSinus_01","WireframeSinus_02","WireframeSinus_03","WireframeSinus_04","WireframeSinus_05","WireframeSinus_06","WireframeSinus_07","WireframeSinus_08","WireframeSinus_09","WireframeSinus_10","WireframeSinus_11","WireframeSinus_12","WireframeSinus_13","WireframeSinus_14","WireframeSinus_15","WireframeSinus_16","WireframeSinus_17","WireframeSinus_18","WireframeSinus_19","WireframeSinus_20"],
            "Const": ["u1min=-1","u1max=1","v1min=-1","v1max=1","M=20","N=20","r0=22/10","H=r0/99","c=1/10000","umin=0","umax=2*pi","vmin=0","vmax=2*pi","Gu=(u1max-u1min)/N","Gv=(v1max-v1min)/M"],
            "Funct": ["Fx=v","Fy=u","Fz=-sin(2*pi*(u*u+v*v)+t/6)/6","Rapp=u/sqrt(u*u+v*v+t*t)","DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)","DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)","DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)","DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)","DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)","DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","Thickness1=H*sin(N*pi*(v-v1min)/(v1max-v1min)+int((M*(u-u1min)/(u1max-u1min))%M)*(pi)+pi/2)","Thickness2=H*sin(N*pi*(u-u1min)/(u1max-u1min)+int((M*(v-v1min)/(v1max-v1min))%M)*(pi)-pi/2)","Sx=Fx(u,v,t)+Thickness1(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Sy=Fy(u,v,t)+Thickness1(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Sz=Fz(u,v,t)+Thickness1(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Tx=Fx(u,v,t)+Thickness2(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Ty=Fy(u,v,t)+Thickness2(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Tz=Fz(u,v,t)+Thickness2(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)","DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)","DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)","DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)","DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)","DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","F2x=Sx(u1min+CmpId(0)*Gu,v,t)","F2y=Sy(u1min+CmpId(0)*Gu,v,t)","F2z=Sz(u1min+CmpId(0)*Gu,v,t)","DF2xv=DFxv(u1min+CmpId(0)*Gu,v,t)","DF2yv=DFyv(u1min+CmpId(0)*Gu,v,t)","DF2zv=DFzv(u1min+CmpId(0)*Gu,v,t)","DF2xv2=n1(u1min+CmpId(0)*Gu,v,t)","DF2yv2=n2(u1min+CmpId(0)*Gu,v,t)","DF2zv2=n3(u1min+CmpId(0)*Gu,v,t)","Nxv=Rapp(DF2xv2(u,v,t),DF2yv2(u,v,t),DF2zv2(u,v,t))","Nyv=Rapp(DF2yv2(u,v,t),DF2xv2(u,v,t),DF2zv2(u,v,t))","Nzv=Rapp(DF2zv2(u,v,t),DF2yv2(u,v,t),DF2xv2(u,v,t))","Binxv=(DF2yv(u,v,t)*Nzv(u,v,t)-DF2zv(u,v,t)*Nyv(u,v,t))/sqrt(DF2xv(u,v,t)^2+DF2yv(u,v,t)^2+DF2zv(u,v,t)^2)","Binyv=(DF2zv(u,v,t)*Nxv(u,v,t)-DF2xv(u,v,t)*Nzv(u,v,t))/sqrt(DF2xv(u,v,t)^2+DF2yv(u,v,t)^2+DF2zv(u,v,t)^2)","Binzv=(DF2xv(u,v,t)*Nyv(u,v,t)-DF2yv(u,v,t)*Nxv(u,v,t))/sqrt(DF2xv(u,v,t)^2+DF2yv(u,v,t)^2+DF2zv(u,v,t)^2)","Sx=F2x(u,v,t)+(r0/100)*(Nxv(u,v,t)*cos(u)+Binxv(u,v,t)*sin(u))","Sy=F2y(u,v,t)+(r0/100)*(Nyv(u,v,t)*cos(u)+Binyv(u,v,t)*sin(u))","Sz=F2z(u,v,t)+(r0/100)*(Nzv(u,v,t)*cos(u)+Binzv(u,v,t)*sin(u))","F2x=Tx(u,v1min+(CmpId(0)-(N+1))*Gv,t)","F2y=Ty(u,v1min+(CmpId(0)-(N+1))*Gv,t)","F2z=Tz(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2xu=DFxu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2yu=DFyu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2zu=DFzu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2xu2=n1(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2yu2=n2(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2zu2=n3(u,v1min+(CmpId(0)-(N+1))*Gv,t)","Nxu=Rapp(DF2xu2(u,v,t),DF2yu2(u,v,t),DF2zu2(u,v,t))","Nyu=Rapp(DF2yu2(u,v,t),DF2xu2(u,v,t),DF2zu2(u,v,t))","Nzu=Rapp(DF2zu2(u,v,t),DF2yu2(u,v,t),DF2xu2(u,v,t))","Binxu=(DF2yu(u,v,t)*Nzu(u,v,t)-DF2zu(u,v,t)*Nyu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Binyu=(DF2zu(u,v,t)*Nxu(u,v,t)-DF2xu(u,v,t)*Nzu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Binzu=(DF2xu(u,v,t)*Nyu(u,v,t)-DF2yu(u,v,t)*Nxu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Tx=F2x(u,v,t)+(r0/100)*(Nxu(u,v,t)*cos(v)+Binxu(u,v,t)*sin(v))","Ty=F2y(u,v,t)+(r0/100)*(Nyu(u,v,t)*cos(v)+Binyu(u,v,t)*sin(v))","Tz=F2z(u,v,t)+(r0/100)*(Nzu(u,v,t)*cos(v)+Binzu(u,v,t)*sin(v))"],
            "Fx": ["Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)"],
            "Fy": ["Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)"],
            "Fz": ["Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)"],
            "Grid": ["30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30"],
            "Umax": ["umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max"],
            "Umin": ["umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min"],
            "Vmax": ["v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax"],
            "Vmin": ["v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin"]
        }
    },
    {
        "Param3D": {
            "Description": ["Wireframe Shell by Abderrahman Taha 11/10/2019"],
            "Name": ["Wireframe_Shell"],
            "Component": ["WIRE_00","WIRE_01","WIRE_02","WIRE_03","WIRE_04","WIRE_05","WIRE_06","WIRE_07","WIRE_08","WIRE_09","WIRE_10","WIRE_11","WIRE_12","WIRE_13","WIRE_14","WIRE_15","WIRE_16","WIRE_17","WIRE_18","WIRE_19","WIRE_20","WIRE_00","WIRE_01","WIRE_02","WIRE_03","WIRE_04","WIRE_05","WIRE_06","WIRE_07","WIRE_08","WIRE_09","WIRE_10","WIRE_11","WIRE_12","WIRE_13","WIRE_14","WIRE_15","WIRE_16","WIRE_17","WIRE_18","WIRE_19","WIRE_20"],
            "Const": ["u1min=1/100000","u1max=pi","v1min=-pi/4","v1max=5*pi/2","M=20","N=20","r0=5","H=r0/99","c=1/10000","umin=0","umax=2*pi","vmin=0","vmax=2*pi","Gu=(u1max-u1min)/N","Gv=(v1max-v1min)/M"],
            "Funct": ["Fx=(12/10)^v*(sin(u)^2*sin(v))","Fy=(12/10)^v*(sin(u)^2*cos(v))","Fz=(12/10)^v*(sin(u)*cos(u))","Rapp=u/sqrt(u*u+v*v+t*t)","DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)","DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)","DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)","DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)","DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)","DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","Thickness1=H*sin(N*pi*(v-v1min)/(v1max-v1min)+int((M*(u-u1min)/(u1max-u1min))%M)*(pi)+pi/2)","Thickness2=H*sin(N*pi*(u-u1min)/(u1max-u1min)+int((M*(v-v1min)/(v1max-v1min))%M)*(pi)-pi/2)","Sx=Fx(u,v,t)+Thickness1(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Sy=Fy(u,v,t)+Thickness1(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Sz=Fz(u,v,t)+Thickness1(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Tx=Fx(u,v,t)+Thickness2(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Ty=Fy(u,v,t)+Thickness2(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Tz=Fz(u,v,t)+Thickness2(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)","DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)","DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)","DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)","DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)","DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","F2x=Sx(u1min+CmpId(0)*Gu,v,t)","F2y=Sy(u1min+CmpId(0)*Gu,v,t)","F2z=Sz(u1min+CmpId(0)*Gu,v,t)","DF2xv=DFxv(u1min+CmpId(0)*Gu,v,t)","DF2yv=DFyv(u1min+CmpId(0)*Gu,v,t)","DF2zv=DFzv(u1min+CmpId(0)*Gu,v,t)","DF2xv2=n1(u1min+CmpId(0)*Gu,v,t)","DF2yv2=n2(u1min+CmpId(0)*Gu,v,t)","DF2zv2=n3(u1min+CmpId(0)*Gu,v,t)","Nxv=Rapp(DF2xv2(u,v,t),DF2yv2(u,v,t),DF2zv2(u,v,t))","Nyv=Rapp(DF2yv2(u,v,t),DF2xv2(u,v,t),DF2zv2(u,v,t))","Nzv=Rapp(DF2zv2(u,v,t),DF2yv2(u,v,t),DF2xv2(u,v,t))","Binxv=(DF2yv(u,v,t)*Nzv(u,v,t)-DF2zv(u,v,t)*Nyv(u,v,t))/sqrt(DF2xv(u,v,t)^2+DF2yv(u,v,t)^2+DF2zv(u,v,t)^2)","Binyv=(DF2zv(u,v,t)*Nxv(u,v,t)-DF2xv(u,v,t)*Nzv(u,v,t))/sqrt(DF2xv(u,v,t)^2+DF2yv(u,v,t)^2+DF2zv(u,v,t)^2)","Binzv=(DF2xv(u,v,t)*Nyv(u,v,t)-DF2yv(u,v,t)*Nxv(u,v,t))/sqrt(DF2xv(u,v,t)^2+DF2yv(u,v,t)^2+DF2zv(u,v,t)^2)","Sx=F2x(u,v,t)+(r0/100)*(Nxv(u,v,t)*cos(u)+Binxv(u,v,t)*sin(u))","Sy=F2y(u,v,t)+(r0/100)*(Nyv(u,v,t)*cos(u)+Binyv(u,v,t)*sin(u))","Sz=F2z(u,v,t)+(r0/100)*(Nzv(u,v,t)*cos(u)+Binzv(u,v,t)*sin(u))","F2x=Tx(u,v1min+(CmpId(0)-(N+1))*Gv,t)","F2y=Ty(u,v1min+(CmpId(0)-(N+1))*Gv,t)","F2z=Tz(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2xu=DFxu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2yu=DFyu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2zu=DFzu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2xu2=n1(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2yu2=n2(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2zu2=n3(u,v1min+(CmpId(0)-(N+1))*Gv,t)","Nxu=Rapp(DF2xu2(u,v,t),DF2yu2(u,v,t),DF2zu2(u,v,t))","Nyu=Rapp(DF2yu2(u,v,t),DF2xu2(u,v,t),DF2zu2(u,v,t))","Nzu=Rapp(DF2zu2(u,v,t),DF2yu2(u,v,t),DF2xu2(u,v,t))","Binxu=(DF2yu(u,v,t)*Nzu(u,v,t)-DF2zu(u,v,t)*Nyu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Binyu=(DF2zu(u,v,t)*Nxu(u,v,t)-DF2xu(u,v,t)*Nzu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Binzu=(DF2xu(u,v,t)*Nyu(u,v,t)-DF2yu(u,v,t)*Nxu(u,v,t))/sqrt(DF2xu(u,v,t)^2+DF2yu(u,v,t)^2+DF2zu(u,v,t)^2)","Tx=F2x(u,v,t)+(r0/100)*(Nxu(u,v,t)*cos(v)+Binxu(u,v,t)*sin(v))","Ty=F2y(u,v,t)+(r0/100)*(Nyu(u,v,t)*cos(v)+Binyu(u,v,t)*sin(v))","Tz=F2z(u,v,t)+(r0/100)*(Nzu(u,v,t)*cos(v)+Binzu(u,v,t)*sin(v))"],
            "Fx": ["Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)"],
            "Fy": ["Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)"],
            "Fz": ["Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)"],
            "Grid": ["30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30","600","30"],
            "Umax": ["umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max","u1max"],
            "Umin": ["umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min","u1min"],
            "Vmax": ["v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","v1max","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax"],
            "Vmin": ["v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","v1min","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin"]
        }
    },
    {
      "Param3D": {
        "Description ": ["Knot weave patterns by Abderrahman Taha 20/12/2017"],
        "Name": ["knot_weave"],
        "Const": ["c=1/10000","umax=pi","umin=-pi","vmax=2*pi","vmin=0","N=114","M=16","H=1/100","k=1/180","k1=1/50","p=7","q=2","R=30","r=1","r0=20","r00=30"],
        "Funct": ["Rapp = (u/sqrt(u*u+v*v+t*t))","Bx = 1/sqrt(u*u+v*v+t*t)",
            "Fx = (cos(q*v)*((R/10)+(r/10)*cos(p*v)))+(r0/100)*Rapp((-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))*cos(u)+(r0/100)*(((R/10)*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v)))*Rapp((-(p*p*r/10)*sin(p*v)),(-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))))-(p*r/10)*cos(p*v)*Rapp((-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v))))*Bx((-(R/10)*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v))),((R/10)*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v))),(p*r/10)*cos(p*v))*sin(u)","Fy = (sin(q*v)*((R/10)+(r/10)*cos(p*v)))+(r0/100)*Rapp((-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))*cos(u)+(r0/100)*((p*r/10)*cos(p*v)*Rapp((-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))-(-(R/10)*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v)))*Rapp((-(p*p*r/10)*sin(p*v)),(-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v)))))*Bx((-(R/10)*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v))),((R/10)*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v))),(p*r/10)*cos(p*v))*sin(u)","Fz = (r/10)*(sin(p*v))+(r0/100)*Rapp((-(p*p*r/10)*sin(p*v)),(-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))))*cos(u)+(r0/100)*((-(R/10)*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v)))*Rapp((-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))-((R/10)*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v)))*Rapp((-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v))))*Bx((-(R/10)*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v))),((R/10)*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v))),(p*r/10)*cos(p*v))*sin(u)","DFxu=((Fx(u,v,t)-Fx(u+c,v,t))/c)","DFxv=((Fx(u,v,t)-Fx(u,v+c,t))/c)","DFyu=((Fy(u,v,t)-Fy(u+c,v,t))/c)","DFyv=((Fy(u,v,t)-Fy(u,v+c,t))/c)","DFzu=((Fz(u,v,t)-Fz(u+c,v,t))/c)","DFzv=((Fz(u,v,t)-Fz(u,v+c,t))/c)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","Thickness=H*sin(M*pi*(u-umin)/(umax-umin)+int((N*(v-vmin)/(vmax-vmin)+1/2)%N)*pi+pi)","Thickness2=H*sin(N*pi*(v-vmin)/(vmax-vmin)+int((M*(u-umin)/(umax-umin)+1/2)%M)*pi)","Gx=Fx(u,v,t)+Thickness(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Gy=Fy(u,v,t)+Thickness(u,v,t)*Rapp(n2(u,v,t),n1(u,v,t),n3(u,v,t))","Gz=Fz(u,v,t)+Thickness(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Gx2=Fx(u,v,t)+Thickness2(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Gy2=Fy(u,v,t)+Thickness2(u,v,t)*Rapp(n2(u,v,t),n1(u,v,t),n3(u,v,t))","Gz2=Fz(u,v,t)+Thickness2(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
        "Component": ["PlainWeave_00","PlainWeave_01","PlainWeave_02","PlainWeave_03","PlainWeave_04","PlainWeave_05","PlainWeave_06","PlainWeave_07","PlainWeave_08","PlainWeave_09","PlainWeave_10","PlainWeave_11","PlainWeave_12","PlainWeave_13","PlainWeave_14","PlainWeave_15","PlainWeave_16","PlainWeave_17","PlainWeave_18","PlainWeave_19","PlainWeave_20","PlainWeave_21","PlainWeave_22","PlainWeave_23","PlainWeave_24","PlainWeave_25","PlainWeave_26","PlainWeave_27","PlainWeave_28","PlainWeave_29","PlainWeave_30","PlainWeave_31","PlainWeave_32","PlainWeave_33","PlainWeave_34","PlainWeave_35","PlainWeave_36","PlainWeave_37","PlainWeave_38","PlainWeave_39","PlainWeave_40","PlainWeave_41","PlainWeave_42","PlainWeave_43","PlainWeave_44","PlainWeave_45","PlainWeave_46","PlainWeave_47","PlainWeave_48","PlainWeave_49","PlainWeave_50","PlainWeave_51","PlainWeave_52","PlainWeave_53","PlainWeave_54","PlainWeave_55","PlainWeave_56","PlainWeave_57","PlainWeave_58","PlainWeave_59","PlainWeave_60","PlainWeave_61","PlainWeave_62","PlainWeave_63","PlainWeave_64","PlainWeave_65","PlainWeave_66","PlainWeave_67","PlainWeave_68","PlainWeave_69","PlainWeave_70","PlainWeave_71","PlainWeave_72","PlainWeave_73","PlainWeave_74","PlainWeave_75","PlainWeave_76","PlainWeave_77","PlainWeave_78","PlainWeave_79","PlainWeave_80","PlainWeave_81","PlainWeave_82","PlainWeave_83","PlainWeave_84","PlainWeave_85","PlainWeave_86","PlainWeave_87","PlainWeave_88","PlainWeave_89","PlainWeave_90","PlainWeave_91","PlainWeave_92","PlainWeave_93","PlainWeave_94","PlainWeave_95","PlainWeave_96","PlainWeave_97","PlainWeave_98","PlainWeave_99","PlainWeave_100","PlainWeave_101","PlainWeave_102","PlainWeave_103","PlainWeave_104","PlainWeave_105","PlainWeave_106","PlainWeave_107","PlainWeave_108","PlainWeave_109","PlainWeave_110","PlainWeave_111","PlainWeave_112","PlainWeave_113","PlainWeave_114","PlainWeave_115","PlainWeave_116","PlainWeave_117","PlainWeave_118","PlainWeave_119","PlainWeave_120","PlainWeave_121","PlainWeave_122","PlainWeave_123","PlainWeave_124","PlainWeave_125","PlainWeave_126","PlainWeave_127","PlainWeave_128","PlainWeave_129"],
        "Fx": ["Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)","Gx2(u,v,t)"],
        "Fy": ["Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)","Gy2(u,v,t)"],
        "Fz": ["Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)","Gz2(u,v,t)"],
        "Grid": ["75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500"],
        "Umax": ["umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umin+(umax-umin)/M-k1","umin+2*(umax-umin)/M-k1","umin+3*(umax-umin)/M-k1","umin+4*(umax-umin)/M-k1","umin+5*(umax-umin)/M-k1","umin+6*(umax-umin)/M-k1","umin+7*(umax-umin)/M-k1","umin+8*(umax-umin)/M-k1","umin+9*(umax-umin)/M-k1","umin+10*(umax-umin)/M-k1","umin+11*(umax-umin)/M-k1","umin+12*(umax-umin)/M-k1","umin+13*(umax-umin)/M-k1","umin+14*(umax-umin)/M-k1","umin+15*(umax-umin)/M-k1","umin+16*(umax-umin)/M-k1"],
        "Umin": ["umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin+k1","umin+(umax-umin)/M +k1","umin+2*(umax-umin)/M+k1","umin+3*(umax-umin)/M+k1","umin+4*(umax-umin)/M+k1","umin+5*(umax-umin)/M+k1","umin+6*(umax-umin)/M+k1","umin+7*(umax-umin)/M+k1","umin+8*(umax-umin)/M+k1","umin+9*(umax-umin)/M+k1","umin+10*(umax-umin)/M+k1","umin+11*(umax-umin)/M+k1","umin+12*(umax-umin)/M+k1","umin+13*(umax-umin)/M+k1","umin+14*(umax-umin)/M+k1","umin+15*(umax-umin)/M+k1"],
        "Vmax": ["vmin+(vmax-vmin)/N-k","vmin+2*(vmax-vmin)/N-k","vmin+3*(vmax-vmin)/N-k","vmin+4*(vmax-vmin)/N-k","vmin+5*(vmax-vmin)/N-k","vmin+6*(vmax-vmin)/N-k","vmin+7*(vmax-vmin)/N-k","vmin+8*(vmax-vmin)/N-k","vmin+9*(vmax-vmin)/N-k","vmin+10*(vmax-vmin)/N-k","vmin+11*(vmax-vmin)/N-k","vmin+12*(vmax-vmin)/N-k","vmin+13*(vmax-vmin)/N-k","vmin+14*(vmax-vmin)/N-k","vmin+15*(vmax-vmin)/N-k","vmin+16*(vmax-vmin)/N-k","vmin+17*(vmax-vmin)/N-k","vmin+18*(vmax-vmin)/N-k","vmin+19*(vmax-vmin)/N-k","vmin+20*(vmax-vmin)/N-k","vmin+21*(vmax-vmin)/N-k","vmin+22*(vmax-vmin)/N-k","vmin+23*(vmax-vmin)/N-k","vmin+24*(vmax-vmin)/N-k","vmin+25*(vmax-vmin)/N-k","vmin+26*(vmax-vmin)/N-k","vmin+27*(vmax-vmin)/N-k","vmin+28*(vmax-vmin)/N-k","vmin+29*(vmax-vmin)/N-k","vmin+30*(vmax-vmin)/N-k","vmin+31*(vmax-vmin)/N-k","vmin+32*(vmax-vmin)/N-k","vmin+33*(vmax-vmin)/N-k","vmin+34*(vmax-vmin)/N-k","vmin+35*(vmax-vmin)/N-k","vmin+36*(vmax-vmin)/N-k","vmin+37*(vmax-vmin)/N-k","vmin+38*(vmax-vmin)/N-k","vmin+39*(vmax-vmin)/N-k","vmin+40*(vmax-vmin)/N-k","vmin+41*(vmax-vmin)/N-k","vmin+42*(vmax-vmin)/N-k","vmin+43*(vmax-vmin)/N-k","vmin+44*(vmax-vmin)/N-k","vmin+45*(vmax-vmin)/N-k","vmin+46*(vmax-vmin)/N-k","vmin+47*(vmax-vmin)/N-k","vmin+48*(vmax-vmin)/N-k","vmin+49*(vmax-vmin)/N-k","vmin+50*(vmax-vmin)/N-k","vmin+51*(vmax-vmin)/N-k","vmin+52*(vmax-vmin)/N-k","vmin+53*(vmax-vmin)/N-k","vmin+54*(vmax-vmin)/N-k","vmin+55*(vmax-vmin)/N-k","vmin+56*(vmax-vmin)/N-k","vmin+57*(vmax-vmin)/N-k","vmin+58*(vmax-vmin)/N-k","vmin+59*(vmax-vmin)/N-k","vmin+60*(vmax-vmin)/N-k","vmin+61*(vmax-vmin)/N-k","vmin+62*(vmax-vmin)/N-k","vmin+63*(vmax-vmin)/N-k","vmin+64*(vmax-vmin)/N-k","vmin+65*(vmax-vmin)/N-k","vmin+66*(vmax-vmin)/N-k","vmin+67*(vmax-vmin)/N-k","vmin+68*(vmax-vmin)/N-k","vmin+69*(vmax-vmin)/N-k","vmin+70*(vmax-vmin)/N-k","vmin+71*(vmax-vmin)/N-k","vmin+72*(vmax-vmin)/N-k","vmin+73*(vmax-vmin)/N-k","vmin+74*(vmax-vmin)/N-k","vmin+75*(vmax-vmin)/N-k","vmin+76*(vmax-vmin)/N-k","vmin+77*(vmax-vmin)/N-k","vmin+78*(vmax-vmin)/N-k","vmin+79*(vmax-vmin)/N-k","vmin+80*(vmax-vmin)/N-k","vmin+81*(vmax-vmin)/N-k","vmin+82*(vmax-vmin)/N-k","vmin+83*(vmax-vmin)/N-k","vmin+84*(vmax-vmin)/N-k","vmin+85*(vmax-vmin)/N-k","vmin+86*(vmax-vmin)/N-k","vmin+87*(vmax-vmin)/N-k","vmin+88*(vmax-vmin)/N-k","vmin+89*(vmax-vmin)/N-k","vmin+90*(vmax-vmin)/N-k","vmin+91*(vmax-vmin)/N-k","vmin+92*(vmax-vmin)/N-k","vmin+93*(vmax-vmin)/N-k","vmin+94*(vmax-vmin)/N-k","vmin+95*(vmax-vmin)/N-k","vmin+96*(vmax-vmin)/N-k","vmin+97*(vmax-vmin)/N-k","vmin+98*(vmax-vmin)/N-k","vmin+99*(vmax-vmin)/N-k","vmin+100*(vmax-vmin)/N-k","vmin+101*(vmax-vmin)/N-k","vmin+102*(vmax-vmin)/N-k","vmin+103*(vmax-vmin)/N-k","vmin+104*(vmax-vmin)/N-k","vmin+105*(vmax-vmin)/N-k","vmin+106*(vmax-vmin)/N-k","vmin+107*(vmax-vmin)/N-k","vmin+108*(vmax-vmin)/N-k","vmin+109*(vmax-vmin)/N-k","vmin+110*(vmax-vmin)/N-k","vmin+111*(vmax-vmin)/N-k","vmin+112*(vmax-vmin)/N-k","vmin+113*(vmax-vmin)/N-k","vmin+114*(vmax-vmin)/N-k","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax"],
        "Vmin": ["vmin+k","vmin+(vmax-vmin)/N+k","vmin+2*(vmax-vmin)/N+k","vmin+3*(vmax-vmin)/N+k","vmin+4*(vmax-vmin)/N+k","vmin+5*(vmax-vmin)/N+k","vmin+6*(vmax-vmin)/N+k","vmin+7*(vmax-vmin)/N+k","vmin+8*(vmax-vmin)/N+k","vmin+9*(vmax-vmin)/N+k","vmin+10*(vmax-vmin)/N+k","vmin+11*(vmax-vmin)/N+k","vmin+12*(vmax-vmin)/N+k","vmin+13*(vmax-vmin)/N+k","vmin+14*(vmax-vmin)/N+k","vmin+15*(vmax-vmin)/N+k","vmin+16*(vmax-vmin)/N+k","vmin+17*(vmax-vmin)/N+k","vmin+18*(vmax-vmin)/N+k","vmin+19*(vmax-vmin)/N+k","vmin+20*(vmax-vmin)/N+k","vmin+21*(vmax-vmin)/N+k","vmin+22*(vmax-vmin)/N+k","vmin+23*(vmax-vmin)/N+k","vmin+24*(vmax-vmin)/N+k","vmin+25*(vmax-vmin)/N+k","vmin+26*(vmax-vmin)/N+k","vmin+27*(vmax-vmin)/N+k","vmin+28*(vmax-vmin)/N+k","vmin+29*(vmax-vmin)/N+k","vmin+30*(vmax-vmin)/N+k","vmin+31*(vmax-vmin)/N+k","vmin+32*(vmax-vmin)/N+k","vmin+33*(vmax-vmin)/N+k","vmin+34*(vmax-vmin)/N+k","vmin+35*(vmax-vmin)/N+k","vmin+36*(vmax-vmin)/N+k","vmin+37*(vmax-vmin)/N+k","vmin+38*(vmax-vmin)/N+k","vmin+39*(vmax-vmin)/N+k","vmin+40*(vmax-vmin)/N+k","vmin+41*(vmax-vmin)/N+k","vmin+42*(vmax-vmin)/N+k","vmin+43*(vmax-vmin)/N+k","vmin+44*(vmax-vmin)/N+k","vmin+45*(vmax-vmin)/N+k","vmin+46*(vmax-vmin)/N+k","vmin+47*(vmax-vmin)/N+k","vmin+48*(vmax-vmin)/N+k","vmin+49*(vmax-vmin)/N+k","vmin+50*(vmax-vmin)/N+k","vmin+51*(vmax-vmin)/N+k","vmin+52*(vmax-vmin)/N+k","vmin+53*(vmax-vmin)/N+k","vmin+54*(vmax-vmin)/N+k","vmin+55*(vmax-vmin)/N+k","vmin+56*(vmax-vmin)/N+k","vmin+57*(vmax-vmin)/N+k","vmin+58*(vmax-vmin)/N+k","vmin+59*(vmax-vmin)/N+k","vmin+60*(vmax-vmin)/N+k","vmin+61*(vmax-vmin)/N+k","vmin+62*(vmax-vmin)/N+k","vmin+63*(vmax-vmin)/N+k","vmin+64*(vmax-vmin)/N+k","vmin+65*(vmax-vmin)/N+k","vmin+66*(vmax-vmin)/N+k","vmin+67*(vmax-vmin)/N+k","vmin+68*(vmax-vmin)/N+k","vmin+69*(vmax-vmin)/N+k","vmin+70*(vmax-vmin)/N+k","vmin+71*(vmax-vmin)/N+k","vmin+72*(vmax-vmin)/N+k","vmin+73*(vmax-vmin)/N+k","vmin+74*(vmax-vmin)/N+k","vmin+75*(vmax-vmin)/N+k","vmin+76*(vmax-vmin)/N+k","vmin+77*(vmax-vmin)/N+k","vmin+78*(vmax-vmin)/N+k","vmin+79*(vmax-vmin)/N+k","vmin+80*(vmax-vmin)/N+k","vmin+81*(vmax-vmin)/N+k","vmin+82*(vmax-vmin)/N+k","vmin+83*(vmax-vmin)/N+k","vmin+84*(vmax-vmin)/N+k","vmin+85*(vmax-vmin)/N+k","vmin+86*(vmax-vmin)/N+k","vmin+87*(vmax-vmin)/N+k","vmin+88*(vmax-vmin)/N+k","vmin+89*(vmax-vmin)/N+k","vmin+90*(vmax-vmin)/N+k","vmin+91*(vmax-vmin)/N+k","vmin+92*(vmax-vmin)/N+k","vmin+93*(vmax-vmin)/N+k","vmin+94*(vmax-vmin)/N+k","vmin+95*(vmax-vmin)/N+k","vmin+96*(vmax-vmin)/N+k","vmin+97*(vmax-vmin)/N+k","vmin+98*(vmax-vmin)/N+k","vmin+99*(vmax-vmin)/N+k","vmin+100*(vmax-vmin)/N+k","vmin+101*(vmax-vmin)/N+k","vmin+102*(vmax-vmin)/N+k","vmin+103*(vmax-vmin)/N+k","vmin+104*(vmax-vmin)/N+k","vmin+105*(vmax-vmin)/N+k","vmin+106*(vmax-vmin)/N+k","vmin+107*(vmax-vmin)/N+k","vmin+108*(vmax-vmin)/N+k","vmin+109*(vmax-vmin)/N+k","vmin+110*(vmax-vmin)/N+k","vmin+111*(vmax-vmin)/N+k","vmin+112*(vmax-vmin)/N+k","vmin+113*(vmax-vmin)/N+k","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin"]
      },
      "Sliders": {
        "Max": ["20","20","100","50","100","20","20","100","50","100","20","20","100","50","100","20","20","100","50","100","20","20","100","50","100","20","20","100","50","100","20","20","100","50","100","20","20","100","50","100"],
        "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
        "Name": ["p","q","R","r","r0"],
        "Position": ["3","2","12","6","42","5","2","20","7","62","4","3","42","22","120","5","2","20","5","22","3","2","10","5","18","4","3","40","22","55","8","1","50","23","60","1","5","40","28","45"],
        "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
      }
    },
    {
        "Param3D": {
        "Description ": ["Wireframe Knot by Abderrahman Taha 11/10/2019"],
        "Name": ["Knot_wireframe"],
        "Funct": ["Rapp=u/sqrt(u*u+v*v+t*t)","Bx = 1/sqrt(u*u+v*v+t*t)",
        "Fx = (cos(q*v)*((R/10)+(r/10)*cos(p*v)))+(r0/100)*Rapp((-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))*cos(u)+(r0/100)*(((R/10)*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v)))*Rapp((-(p*p*r/10)*sin(p*v)),(-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))))-(p*r/10)*cos(p*v)*Rapp((-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v))))*Bx((-(R/10)*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v))),((R/10)*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v))),(p*r/10)*cos(p*v))*sin(u)","Fy = (sin(q*v)*((R/10)+(r/10)*cos(p*v)))+(r0/100)*Rapp((-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))*cos(u)+(r0/100)*((p*r/10)*cos(p*v)*Rapp((-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))-(-(R/10)*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v)))*Rapp((-(p*p*r/10)*sin(p*v)),(-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v)))))*Bx((-(R/10)*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v))),((R/10)*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v))),(p*r/10)*cos(p*v))*sin(u)","Fz = (r/10)*(sin(p*v))+(r0/100)*Rapp((-(p*p*r/10)*sin(p*v)),(-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))))*cos(u)+(r0/100)*((-(R/10)*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v)))*Rapp((-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))-((R/10)*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v)))*Rapp((-(R/10)*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(R/10)*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v))))*Bx((-(R/10)*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v))),((R/10)*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v))),(p*r/10)*cos(p*v))*sin(u)",
        "DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)","DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)","DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)","DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)","DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)","DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","Thickness2=H*sin(M*pi*(v-v1min)/(v1max-v1min)+((N*(u-u1min)/(u1max-u1min)))*(pi)+pi/2)","Thickness1=H*sin(N*pi*(u-u1min)/(u1max-u1min)+((M*(v-v1min)/(v1max-v1min)))*(pi)-pi/2)","Thickness3=-2*H","TFx=Fx(u,v,t)+Thickness3(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","TFy=Fy(u,v,t)+Thickness3(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","TFz=Fz(u,v,t)+Thickness3(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Tx=Fx(u,v,t)+Thickness1(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Ty=Fy(u,v,t)+Thickness1(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Tz=Fz(u,v,t)+Thickness1(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Sx=Fx(u,v,t)+Thickness2(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Sy=Fy(u,v,t)+Thickness2(u,v,t)*Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Sz=Fz(u,v,t)+Thickness2(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)","DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)","DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)","DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)","DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)","DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","F2x=Tx(u1min+CmpId(0)*Gu,v,t)","F2y=Ty(u1min+CmpId(0)*Gu,v,t)","F2z=Tz(u1min+CmpId(0)*Gu,v,t)","DF2xv=DFxv(u1min+CmpId(0)*Gu,v,t)","DF2yv=DFyv(u1min+CmpId(0)*Gu,v,t)","DF2zv=DFzv(u1min+CmpId(0)*Gu,v,t)","DF2xv2=n1(u1min+CmpId(0)*Gu,v,t)","DF2yv2=n2(u1min+CmpId(0)*Gu,v,t)","DF2zv2=n3(u1min+CmpId(0)*Gu,v,t)","Nxv=Rapp(DF2xv2(u,v,t),DF2yv2(u,v,t),DF2zv2(u,v,t))","Nyv=Rapp(DF2yv2(u,v,t),DF2xv2(u,v,t),DF2zv2(u,v,t))","Nzv=Rapp(DF2zv2(u,v,t),DF2yv2(u,v,t),DF2xv2(u,v,t))","Binxv=(DF2yv(u,v,t)*Nzv(u,v,t)-DF2zv(u,v,t)*Nyv(u,v,t))*Bx(DF2xv(u,v,t),DF2yv(u,v,t),DF2zv(u,v,t))","Binyv=(DF2zv(u,v,t)*Nxv(u,v,t)-DF2xv(u,v,t)*Nzv(u,v,t))*Bx(DF2xv(u,v,t),DF2yv(u,v,t),DF2zv(u,v,t))","Binzv=(DF2xv(u,v,t)*Nyv(u,v,t)-DF2yv(u,v,t)*Nxv(u,v,t))*Bx(DF2xv(u,v,t),DF2yv(u,v,t),DF2zv(u,v,t))","Tx=F2x(u,v,t)+(r1/100)*(Nxv(u,v,t)*cos(u)+Binxv(u,v,t)*sin(u))","Ty=F2y(u,v,t)+(r1/100)*(Nyv(u,v,t)*cos(u)+Binyv(u,v,t)*sin(u))","Tz=F2z(u,v,t)+(r1/100)*(Nzv(u,v,t)*cos(u)+Binzv(u,v,t)*sin(u))","F2x=Sx(u,v1min+(CmpId(0)-(N+1))*Gv,t)","F2y=Sy(u,v1min+(CmpId(0)-(N+1))*Gv,t)","F2z=Sz(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2xu=DFxu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2yu=DFyu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2zu=DFzu(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2xu2=n1(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2yu2=n2(u,v1min+(CmpId(0)-(N+1))*Gv,t)","DF2zu2=n3(u,v1min+(CmpId(0)-(N+1))*Gv,t)","Nxu=Rapp(DF2xu2(u,v,t),DF2yu2(u,v,t),DF2zu2(u,v,t))","Nyu=Rapp(DF2yu2(u,v,t),DF2xu2(u,v,t),DF2zu2(u,v,t))","Nzu=Rapp(DF2zu2(u,v,t),DF2yu2(u,v,t),DF2xu2(u,v,t))","Binxu=(DF2yu(u,v,t)*Nzu(u,v,t)-DF2zu(u,v,t)*Nyu(u,v,t))*Bx(DF2xu(u,v,t),DF2yu(u,v,t),DF2zu(u,v,t))","Binyu=(DF2zu(u,v,t)*Nxu(u,v,t)-DF2xu(u,v,t)*Nzu(u,v,t))*Bx(DF2xu(u,v,t),DF2yu(u,v,t),DF2zu(u,v,t))","Binzu=(DF2xu(u,v,t)*Nyu(u,v,t)-DF2yu(u,v,t)*Nxu(u,v,t))*Bx(DF2xu(u,v,t),DF2yu(u,v,t),DF2zu(u,v,t))","Sx=F2x(u,v,t)+(r1/100)*(Nxu(u,v,t)*cos(v)+Binxu(u,v,t)*sin(v))","Sy=F2y(u,v,t)+(r1/100)*(Nyu(u,v,t)*cos(v)+Binyu(u,v,t)*sin(v))","Sz=F2z(u,v,t)+(r1/100)*(Nzu(u,v,t)*cos(v)+Binzu(u,v,t)*sin(v))"],
        "Component": ["PlainWeave_00","PlainWeave_01","PlainWeave_02","PlainWeave_03","PlainWeave_04","PlainWeave_05","PlainWeave_06","PlainWeave_07","PlainWeave_08","PlainWeave_09","PlainWeave_10","PlainWeave_11","PlainWeave_12","PlainWeave_13","PlainWeave_14","PlainWeave_15","PlainWeave_16","PlainWeave_17","PlainWeave_18","PlainWeave_19","PlainWeave_20","PlainWeave_21","PlainWeave_22","PlainWeave_23","PlainWeave_24","PlainWeave_25","PlainWeave_26","PlainWeave_27","PlainWeave_28","PlainWeave_29","PlainWeave_30","PlainWeave_31","PlainWeave_32","PlainWeave_33","PlainWeave_34","PlainWeave_35","PlainWeave_36","PlainWeave_37","PlainWeave_38","PlainWeave_39","PlainWeave_40","PlainWeave_41","PlainWeave_42","PlainWeave_43","PlainWeave_44","PlainWeave_45","PlainWeave_46","PlainWeave_47","PlainWeave_48","PlainWeave_49","PlainWeave_50","PlainWeave_51","PlainWeave_52","PlainWeave_53","PlainWeave_54","PlainWeave_55","PlainWeave_56","PlainWeave_57","PlainWeave_58","PlainWeave_59","PlainWeave_60","PlainWeave_61","PlainWeave_62","PlainWeave_63","PlainWeave_64","PlainWeave_65","PlainWeave_66","PlainWeave_67","PlainWeave_68","PlainWeave_69","PlainWeave_70","PlainWeave_71","PlainWeave_72","PlainWeave_73","PlainWeave_74","PlainWeave_75","PlainWeave_76","PlainWeave_77","PlainWeave_78","PlainWeave_79","PlainWeave_80","PlainWeave_81","PlainWeave_82","PlainWeave_83","PlainWeave_84","PlainWeave_85","PlainWeave_86","PlainWeave_87","PlainWeave_88","PlainWeave_89","PlainWeave_90","PlainWeave_91","PlainWeave_92","PlainWeave_93","PlainWeave_94","PlainWeave_95","PlainWeave_96","PlainWeave_97","PlainWeave_98","PlainWeave_99","PlainWeave_100","PlainWeave_101","PlainWeave_102","PlainWeave_103","PlainWeave_104","PlainWeave_105","PlainWeave_106","PlainWeave_107","PlainWeave_108","PlainWeave_109","PlainWeave_110","PlainWeave_111","PlainWeave_112","PlainWeave_113","PlainWeave_114","PlainWeave_115","PlainWeave_116","PlainWeave_117","PlainWeave_118","PlainWeave_119","PlainWeave_120","PlainWeave_121","PlainWeave_122","PlainWeave_123","PlainWeave_124","PlainWeave_125","PlainWeave_126","PlainWeave_127","PlainWeave_128","PlainWeave_129","PlainWeave_130"],
        "Const": ["r1=3","p=3","q=2","R=125/100","r=6","r0=42","H=3/99","c=1/10000","u1max=2*pi","u1min=0","v1max=2*pi","v1min=0","M=114","N=16","umin=0","umax=2*pi","vmin=0","vmax=2*pi","Gu=(u1max-u1min)/N","Gv=(v1max-v1min)/M"],"Fx": ["Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","Tx(u,v,t)","TFx(u,v,t)"],
        "Fy": ["Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","Ty(u,v,t)","TFy(u,v,t)"],
        "Fz": ["Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","Tz(u,v,t)","TFz(u,v,t)"],
        "Grid": ["75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","75","30","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","30","500","300","300"],
        "Umax": ["umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax"],
        "Umin": ["umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin"],
        "Vmax": ["vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax"],
        "Vmin": ["vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin"]
        },
        "Sliders": {
        "Max": ["20","20","100","50","100","20","20","20","100","50","100","20","20","20","100","50","100","20","20","20","100","50","100","20","20","20","100","50","100","20"],
        "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
        "Name": ["p","q","R","r","r0","r1"],
        "Position": ["3","2","13","6","42","5","5","2","22","7","62","5","4","3","42","22","100","5","8","1","5","23","60","5","1","5","4","28","45","5"],
        "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        },
        "Texture": {
        "Colors": ["R=if(cmpId = (130),(9/10),(6/10))","G=if((cmpId = 130),(2/10),(4/10))","B=if((cmpId = 130),(3/10),(0))","T=if((cmpId = 130),(4/10),(1))"],
        "Name": "Gold",
        "Noise": ""
        }
    },
    {
        "Param3D": {
            "Description": ["Torus knot(p,q) by Abderrahman Taha 10/04/2019"],
            "Name": ["Knot_pq"],
            "Component": ["knot"],
            "Const": ["p=7","q=2","R=3","r=1","r0=20","r00=30","dv=1/1000"],
            "Funct": ["Rapp = (u/sqrt(u*u+v*v+t*t))","Bx = 1/sqrt(u*u+v*v+t*t)","Fx = (cos(q*v)*(R+(r/10)*cos(p*v)))+(r0/100)*Rapp((-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))*cos(u)+(r0/100)*((R*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v)))*Rapp((-(p*p*r/10)*sin(p*v)),(-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))))-(p*r/10)*cos(p*v)*Rapp((-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v))))*Bx((-R*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v))),(R*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v))),(p*r/10)*cos(p*v))*sin(u)","Fy = (sin(q*v)*(R+(r/10)*cos(p*v)))+(r0/100)*Rapp((-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))*cos(u)+(r0/100)*((p*r/10)*cos(p*v)*Rapp((-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))-(-R*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v)))*Rapp((-(p*p*r/10)*sin(p*v)),(-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v)))))*Bx((-R*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v))),(R*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v))),(p*r/10)*cos(p*v))*sin(u)","Fz = (r/10)*(sin(p*v))+(r0/100)*Rapp((-(p*p*r/10)*sin(p*v)),(-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))))*cos(u)+(r0/100)*((-R*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v)))*Rapp((-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v)))-(R*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v)))*Rapp((-R*q*q*cos(q*v)+(r/10)*(-q*q*cos(q*v)*cos(p*v)+p*q*sin(q*v)*sin(p*v)+p*q*sin(q*v)*sin(p*v)-p*p*cos(q*v)*cos(p*v))),(-R*q*q*sin(q*v)+(r/10)*(-q*q*sin(q*v)*cos(p*v)-p*q*cos(q*v)*sin(p*v)-q*p*cos(q*v)*sin(p*v)-p*p*sin(q*v)*cos(p*v))),(-(p*p*r/10)*sin(p*v))))*Bx((-R*q*sin(q*v)+(r/10)*(-q*sin(q*v)*cos(p*v)-p*cos(q*v)*sin(p*v))),(R*q*cos(q*v)+(r/10)*(q*cos(q*v)*cos(p*v)-p*sin(q*v)*sin(p*v))),(p*r/10)*cos(p*v))*sin(u)"],
            "Fx": ["-Fx(u,v,t)"],
            "Fy": ["Fy(u,v,t)"],
            "Fz": ["-Fz(u,v,t)"],
            "Grid": ["50","200"],
            "Umax": ["pi"],
            "Umin": ["-pi"],
            "Vmax": ["2*pi"],
            "Vmin": ["0"]
        },
        "Sliders": {
            "Max": ["20","20","10","50","100","20","20","10","50","100","20","20","10","50","100","20","20","10","50","100","20","20","10","50","100"],
            "Min": ["0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"],
            "Name": ["p","q","R","r","r0"],
            "Position": ["5","2","2","5","22","3","2","1","5","18","4","3","4","22","55","8","1","5","23","60","1","5","4","28","45"],
            "Step": ["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]
        }
    },
    {
        "Param3D": {
            "Description": ["Half Cylinder Section with chained pattern v02 by Abderrahman Taha 19/03/2019"],
            "Name": ["Chained Cylinder"],
            "Const": ["u1min=0","u1max=pi","v1min=0","v1max=15/10","M=13","N=13","r0=3","H=r0/95","du=1/10000","dv=1/10000","umin=0","umax=2*pi","vmin=0","vmax=2*pi","Gu=(u1max-u1min)/(M-1)","Gv=(v1max-v1min)/(N-1)","k0=76/10000","k1=1/10","beta=pi/2","beta2=pi/8"],
            "Funct": ["Yx=(k1+k0*cos(u))*cos(v)","Yy=(k1+k0*cos(u))*sin(v)","Yz=k0*sin(u)","Fz=8*sin(u)/10","Fy=8*cos(u)/10","Fx=v","Rapp=(u/sqrt(u*u+v*v+t*t))","DFxu=((Fx(u+du,v,t)-Fx(u,v,t))/du)","DFxv=((Fx(u,v+dv,t)-Fx(u,v,t))/dv)","DFyu=((Fy(u+du,v,t)-Fy(u,v,t))/du)","DFyv=((Fy(u,v+dv,t)-Fy(u,v,t))/dv)","DFzu=((Fz(u+du,v,t)-Fz(u,v,t))/du)","DFzv=((Fz(u,v+dv,t)-Fz(u,v,t))/dv)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","n1=n1(u1min+(CmpId(0)%M)*Gu,v1min+(floor(CmpId(0)/N))*Gv,t)","n2=n2(u1min+(CmpId(0)%M)*Gu,v1min+(floor(CmpId(0)/N))*Gv,t)","n3=n3(u1min+(CmpId(0)%M)*Gu,v1min+(floor(CmpId(0)/N))*Gv,t)","Nx=n1(u,v,t)/sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)","Ny=n2(u,v,t)/sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)","Nz=n3(u,v,t)/sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)","n01= 0","n02= 0","n03= 1","n1=Rapp(n01(u,v,t),n02(u,v,t),n03(u,v,t))","n2=Rapp(n02(u,v,t),n03(u,v,t),n01(u,v,t))","n3=Rapp(n03(u,v,t),n01(u,v,t),n02(u,v,t))","u1=(n2(u,v,t)*Nz(u,v,t)-n3(u,v,t)*Ny(u,v,t))","u2=(n3(u,v,t)*Nx(u,v,t)-n1(u,v,t)*Nz(u,v,t))","u3=(n1(u,v,t)*Ny(u,v,t)-n2(u,v,t)*Nx(u,v,t))","U1=Rapp(u1(u,v,t),u2(u,v,t),u3(u,v,t))","U2=Rapp(u2(u,v,t),u3(u,v,t),u1(u,v,t))","U3=Rapp(u3(u,v,t),u1(u,v,t),u2(u,v,t))","c=n1(u,v,t)*Nx(u,v,t)+n2(u,v,t)*Ny(u,v,t)+n3(u,v,t)*Nz(u,v,t)","s=sin(acos(c(u,v,t)))","S0x=Yx(u,v,t) ","S0y=Yy(u,v,t) ","S0z=Yz(u,v,t) ","S2x=(U1(u,v,t)^2*(1-c(u,v,t))+c(u,v,t))*S0x(u,v,t)+(U1(u,v,t)*U2(u,v,t)*(1-c(u,v,t))-U3(u,v,t)*s(u,v,t))*S0y(u,v,t)+(U1(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+U2(u,v,t)*s(u,v,t))*S0z(u,v,t) ","S2y=(U1(u,v,t)*U2(u,v,t)*(1-c(u,v,t))+U3(u,v,t)*s(u,v,t))*S0x(u,v,t)+(U2(u,v,t)^2*(1-c(u,v,t))+c(u,v,t))*S0y(u,v,t)+(U2(u,v,t)*U3(u,v,t)*(1-c(u,v,t))-U1(u,v,t)*s(u,v,t))*S0z(u,v,t) ","S2z=(U1(u,v,t)*U3(u,v,t)*(1-c(u,v,t))-U2(u,v,t)*s(u,v,t))*S0x(u,v,t)+(U2(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+U1(u,v,t)*s(u,v,t))*S0y(u,v,t)+(U3(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+c(u,v,t))*S0z(u,v,t)","Sx= S2x(u,v,t) ","Sy= S2y(u,v,t) ","Sz= S2z(u,v,t) ","n01=if((floor(CmpId(0)/M)%2) = (0),DFxv(u1min+(CmpId(0)%M)*Gu+(floor(CmpId(0)/M)%2)*(Gu/2),v1min+(floor(CmpId(0)/N))*Gv,t),-DFxv(u1min+(CmpId(0)%M)*Gu+(floor(CmpId(0)/M)%2)*(Gu/2),v1min+(floor(CmpId(0)/N))*Gv,t))","n02=if((floor(CmpId(0)/M)%2) = (0),DFyv(u1min+(CmpId(0)%M)*Gu+(floor(CmpId(0)/M)%2)*(Gu/2),v1min+(floor(CmpId(0)/N))*Gv,t),-DFyv(u1min+(CmpId(0)%M)*Gu+(floor(CmpId(0)/M)%2)*(Gu/2),v1min+(floor(CmpId(0)/N))*Gv,t))","n03=if((floor(CmpId(0)/M)%2) = (0),DFzv(u1min+(CmpId(0)%M)*Gu+(floor(CmpId(0)/M)%2)*(Gu/2),v1min+(floor(CmpId(0)/N))*Gv,t),-DFzv(u1min+(CmpId(0)%M)*Gu+(floor(CmpId(0)/M)%2)*(Gu/2),v1min+(floor(CmpId(0)/N))*Gv,t))","n1=Rapp(n01(u,v,t),n02(u,v,t),n03(u,v,t))","n2=Rapp(n02(u,v,t),n03(u,v,t),n01(u,v,t))","n3=Rapp(n03(u,v,t),n01(u,v,t),n02(u,v,t))","u1=(n2(u,v,t)*Nz(u,v,t)-n3(u,v,t)*Ny(u,v,t))","u2=(n3(u,v,t)*Nx(u,v,t)-n1(u,v,t)*Nz(u,v,t))","u3=(n1(u,v,t)*Ny(u,v,t)-n2(u,v,t)*Nx(u,v,t))","U1=Rapp(u1(u,v,t),u2(u,v,t),u3(u,v,t))","U2=Rapp(u2(u,v,t),u3(u,v,t),u1(u,v,t))","U3=Rapp(u3(u,v,t),u1(u,v,t),u2(u,v,t))","c=cos(beta2)","s=sin(beta2)","S0x=Sx(u,v,t) ","S0y=Sy(u,v,t) ","S0z=Sz(u,v,t) ","S2x=(U1(u,v,t)^2*(1-c(u,v,t))+c(u,v,t))*S0x(u,v,t)+(U1(u,v,t)*U2(u,v,t)*(1-c(u,v,t))-U3(u,v,t)*s(u,v,t))*S0y(u,v,t)+(U1(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+U2(u,v,t)*s(u,v,t))*S0z(u,v,t) ","S2y=(U1(u,v,t)*U2(u,v,t)*(1-c(u,v,t))+U3(u,v,t)*s(u,v,t))*S0x(u,v,t)+(U2(u,v,t)^2*(1-c(u,v,t))+c(u,v,t))*S0y(u,v,t)+(U2(u,v,t)*U3(u,v,t)*(1-c(u,v,t))-U1(u,v,t)*s(u,v,t))*S0z(u,v,t) ","S2z=(U1(u,v,t)*U3(u,v,t)*(1-c(u,v,t))-U2(u,v,t)*s(u,v,t))*S0x(u,v,t)+(U2(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+U1(u,v,t)*s(u,v,t))*S0y(u,v,t)+(U3(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+c(u,v,t))*S0z(u,v,t)","Sx= S2x(u,v,t)+Fx(u1min+(CmpId(0)%M)*Gu+(floor(CmpId(0)/M)%2)*(Gu/2),v1min+(floor(CmpId(0)/N))*Gv,t)","Sy= S2y(u,v,t)+Fy(u1min+(CmpId(0)%M)*Gu+(floor(CmpId(0)/M)%2)*(Gu/2),v1min+(floor(CmpId(0)/N))*Gv,t) ","Sz= S2z(u,v,t)+Fz(u1min+(CmpId(0)%M)*Gu+(floor(CmpId(0)/M)%2)*(Gu/2),v1min+(floor(CmpId(0)/N))*Gv,t)"],
            "Component": ["Cylinder_00","Cylinder_01","Cylinder_02","Cylinder_03","Cylinder_04","Cylinder_05","Cylinder_06","Cylinder_07","Cylinder_08","Cylinder_09","Cylinder_10","Cylinder_11","Cylinder_12","Cylinder_13","Cylinder_14","Cylinder_15","Cylinder_16","Cylinder_17","Cylinder_18","Cylinder_19","Cylinder_20","Cylinder_00","Cylinder_01","Cylinder_02","Cylinder_03","Cylinder_04","Cylinder_05","Cylinder_06","Cylinder_07","Cylinder_08","Cylinder_09","Cylinder_10","Cylinder_11","Cylinder_12","Cylinder_13","Cylinder_14","Cylinder_15","Cylinder_16","Cylinder_17","Cylinder_18","Cylinder_19","Cylinder_20","Cylinder_00","Cylinder_01","Cylinder_02","Cylinder_03","Cylinder_04","Cylinder_05","Cylinder_06","Cylinder_07","Cylinder_08","Cylinder_09","Cylinder_10","Cylinder_11","Cylinder_12","Cylinder_13","Cylinder_14","Cylinder_15","Cylinder_16","Cylinder_17","Cylinder_18","Cylinder_19","Cylinder_20","Cylinder_00","Cylinder_01","Cylinder_02","Cylinder_03","Cylinder_04","Cylinder_05","Cylinder_06","Cylinder_07","Cylinder_08","Cylinder_09","Cylinder_10","Cylinder_11","Cylinder_12","Cylinder_13","Cylinder_14","Cylinder_15","Cylinder_16","Cylinder_17","Cylinder_18","Cylinder_19","Cylinder_20","Cylinder_00","Cylinder_01","Cylinder_02","Cylinder_03","Cylinder_04","Cylinder_05","Cylinder_06","Cylinder_07","Cylinder_08","Cylinder_09","Cylinder_10","Cylinder_11","Cylinder_12","Cylinder_13","Cylinder_14","Cylinder_15","Cylinder_16","Cylinder_17","Cylinder_18","Cylinder_19","Cylinder_20","Cylinder_00","Cylinder_01","Cylinder_02","Cylinder_03","Cylinder_04","Cylinder_05","Cylinder_06","Cylinder_07","Cylinder_08","Cylinder_09","Cylinder_10","Cylinder_11","Cylinder_12","Cylinder_13","Cylinder_14","Cylinder_15","Cylinder_16","Cylinder_17","Cylinder_18","Cylinder_19","Cylinder_20","Cylinder_00","Cylinder_01","Cylinder_02","Cylinder_03","Cylinder_04","Cylinder_05","Cylinder_06","Cylinder_07","Cylinder_08","Cylinder_09","Cylinder_10","Cylinder_11","Cylinder_12","Cylinder_13","Cylinder_14","Cylinder_15","Cylinder_16","Cylinder_17","Cylinder_18","Cylinder_19","Cylinder_20","Cylinder_00","Cylinder_01","Cylinder_02","Cylinder_03","Cylinder_04","Cylinder_05","Cylinder_06","Cylinder_07","Cylinder_08","Cylinder_09","Cylinder_10","Cylinder_11","Cylinder_12","Cylinder_13","Cylinder_14","Cylinder_15","Cylinder_16","Cylinder_17","Cylinder_18","Cylinder_19","Cylinder_20","Cylinder_20"],
            "Fx": ["Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)"],
            "Fy": ["Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)"],
            "Fz": ["Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)"],
            "Grid": ["10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30","10","30"],
            "Umax": ["umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax"],
            "Umin": ["umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin"],
            "Vmax": ["vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax"],
            "Vmin": ["vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin"]
        },
        "Texture": {
            "Colors": ["R=7/10","G=7/10","B=7/10","T=1"],
            "Name": "L",
            "Noise": ""
        }
    },
    {
        "Param3D": {
            "Description ": ["Triaxial weave fabric by Abderrahman Taha 14/10/2019"],
            "Name": ["Triaxial weave"],
            "Component": ["Triaxial_00","Triaxial_01","Triaxial_02","Triaxial_03","Triaxial_04","Triaxial_05","Triaxial_06","Triaxial_07","Triaxial_08","Triaxial_09","Triaxial_10","Triaxial_11"],
            "Const": ["c=1/10000","umax=1","umin=-1","vmax=1","vmin=-1","N=4","M=4","H=1/100","k=10/46","teta=pi/3","Th=0","p1=2","p2=1","p3=2"],
            "Funct": ["Thickness=Th*cos(((4*M*(v-vmin)/(vmax-vmin)+1/2)%M)*(pi/2))","Thickness1=H*cos(((4*M*(u-umin)/(umax-umin)+1/2)%M)*(pi/2))","Thickness2=-H*cos(((4*M*(u-umin)/(umax-umin))%M+1/2)*(pi/2))","U=u","V=v","U2=sin(teta)*u+cos(teta)*v","V2=cos(teta)*u-sin(teta)*v","U3=sin(2*teta)*u+cos(2*teta)*v","V3=cos(2*teta)*u-sin(2*teta)*v","Fx=u","Fy=v","Fz=0","DFxu=((Fx(u+c,v,t)-Fx(u,v,t))/c)","DFxv=((Fx(u,v+c,t)-Fx(u,v,t))/c)","DFyu=((Fy(u+c,v,t)-Fy(u,v,t))/c)","DFyv=((Fy(u,v+c,t)-Fy(u,v,t))/c)","DFzu=((Fz(u+c,v,t)-Fz(u,v,t))/c)","DFzv=((Fz(u,v+c,t)-Fz(u,v,t))/c)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","R=u/sqrt(u^2+v^2+t^2)","Gx=Fx(u,v,t)-Thickness(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Gy=Fy(u,v,t)-Thickness(u,v,t)*R(n2(u,v,t),n1(u,v,t),n3(u,v,t))","Gz=Fz(u,v,t)-Thickness(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Gx2=Fx(u,v,t)+Thickness1(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Gy2=Fy(u,v,t)+Thickness1(u,v,t)*R(n2(u,v,t),n1(u,v,t),n3(u,v,t))","Gz2=Fz(u,v,t)+Thickness1(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))","Gx3=Fx(u,v,t)+Thickness2(u,v,t)*R(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Gy3=Fy(u,v,t)+Thickness2(u,v,t)*R(n2(u,v,t),n1(u,v,t),n3(u,v,t))","Gz3=Fz(u,v,t)+Thickness2(u,v,t)*R(n3(u,v,t),n1(u,v,t),n2(u,v,t))"],
            "Fx": ["Gx(U(u,v,t),V(u,v,t),t)","Gx(U(u,v,t),V(u,v,t),t)","Gx(U(u,v,t),V(u,v,t),t)","Gx(U(u,v,t),V(u,v,t),t)","Gx2(U2(u,v,t),V2(u,v,t),t)","Gx2(U2(u,v,t),V2(u,v,t),t)","Gx2(U2(u,v,t),V2(u,v,t),t)","Gx2(U2(u,v,t),V2(u,v,t),t)","Gx3(U3(u,v,t),V3(u,v,t),t)","Gx3(U3(u,v,t),V3(u,v,t),t)","Gx3(U3(u,v,t),V3(u,v,t),t)","Gx3(U3(u,v,t),V3(u,v,t),t)"],
            "Fy": ["Gy(U(u,v,t),V(u,v,t),t)","Gy(U(u,v,t),V(u,v,t),t)","Gy(U(u,v,t),V(u,v,t),t)","Gy(U(u,v,t),V(u,v,t),t)","Gy2(U2(u,v,t),V2(u,v,t),t)","Gy2(U2(u,v,t),V2(u,v,t),t)","Gy2(U2(u,v,t),V2(u,v,t),t)","Gy2(U2(u,v,t),V2(u,v,t),t)","Gy3(U3(u,v,t),V3(u,v,t),t)","Gy3(U3(u,v,t),V3(u,v,t),t)","Gy3(U3(u,v,t),V3(u,v,t),t)","Gy3(U3(u,v,t),V3(u,v,t),t)"],
            "Fz": ["Gz(U(u,v,t),V(u,v,t),t)","Gz(U(u,v,t),V(u,v,t),t)","Gz(U(u,v,t),V(u,v,t),t)","Gz(U(u,v,t),V(u,v,t),t)","Gz2(U2(u,v,t),V2(u,v,t),t)","Gz2(U2(u,v,t),V2(u,v,t),t)","Gz2(U2(u,v,t),V2(u,v,t),t)","Gz2(U2(u,v,t),V2(u,v,t),t)","Gz3(U3(u,v,t),V3(u,v,t),t)","Gz3(U3(u,v,t),V3(u,v,t),t)","Gz3(U3(u,v,t),V3(u,v,t),t)","Gz3(U3(u,v,t),V3(u,v,t),t)"],
            "Umax": ["umin+(umax-umin)/N-k","umin+2*(umax-umin)/N-k","umin+3*(umax-umin)/N-k","umin+4*(umax-umin)/N-k","umax","umax","umax","umax","umax","umax","umax","umax"],
            "Umin": ["umin+k/p1","umin+(umax-umin)/N+k/p1","umin+2*(umax-umin)/N+k/p1","umin+3*(umax-umin)/N+k/p1","umin","umin","umin","umin","umin","umin","umin","umin"],
            "Vmax": ["vmax","vmax","vmax","vmax","vmin+(vmax-vmin)/N-k/p2","vmin+2*(vmax-vmin)/N-k/p2","vmin+3*(vmax-vmin)/N-k/p2","vmin+4*(vmax-vmin)/N-k/p2","vmin+(vmax-vmin)/N-k/p3","vmin+2*(vmax-vmin)/N-k/p3","vmin+3*(vmax-vmin)/N-k/p3","vmin+4*(vmax-vmin)/N-k/p3"],
            "Vmin": ["vmin","vmin","vmin","vmin","vmin+k/p2","vmin+(vmax-vmin)/N+k/p2","vmin+2*(vmax-vmin)/N+k/p2","vmin+3*(vmax-vmin)/N+k/p2","vmin+k","vmin+(vmax-vmin)/N+k","vmin+2*(vmax-vmin)/N+k","vmin+3*(vmax-vmin)/N+k"]
        },
        "Texture": {
            "Colors": ["R=7/10","G=7/10","B=7/10","T=1"],
            "Name": "Granit",
            "Noise": ""
        }
    },
    {
      "Param3D": {
        "Description": ["Sinusoidal surface with chained patterns by Abderrahman Taha 12/10/2019"],
        "Name": ["Chained_Sinusoid"],
        "Const": ["u1min=-(15/10)","u1max=(15/10)","v1min=-(15/10)","v1max=(15/10)","M=13","N=13","r0=3","H=r0/95","du=1/10000","dv=1/10000","umin=0","umax=2*pi","vmin=0","vmax=2*pi","Gu=(u1max-u1min)/(M-1)","Gv=(v1max-v1min)/(N-1)","k0=3/100","k1=2/10","beta=pi/2","beta2=pi/2"],
        "Funct": ["Yx=(k1+k0*cos(u))*cos(v)","Yy=(k1+k0*cos(u))*sin(v)","Yz=k0*sin(u)","Fx=v","Fy=u","Fz=-sin(pi*(u*u+v*v)/3)*10/26","Rapp=(u/sqrt(u*u+v*v+t*t))","DFxu=((Fx(u+du,v,t)-Fx(u,v,t))/du)","DFxv=((Fx(u,v+dv,t)-Fx(u,v,t))/dv)","DFyu=((Fy(u+du,v,t)-Fy(u,v,t))/du)","DFyv=((Fy(u,v+dv,t)-Fy(u,v,t))/dv)","DFzu=((Fz(u+du,v,t)-Fz(u,v,t))/du)","DFzv=((Fz(u,v+dv,t)-Fz(u,v,t))/dv)","n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))","n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))","n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))","n1=n1(u1min+(CmpId(0)%M)*Gu+if((floor(CmpId(0)/M)%2) = (0),(0),-(CmpId(0) %2)*Gu+Gu),v1min+(floor(CmpId(0)/N))*Gv,t)","n2=n2(u1min+(CmpId(0)%M)*Gu+if((floor(CmpId(0)/M)%2) = (0),(0),-(CmpId(0) %2)*Gu+Gu),v1min+(floor(CmpId(0)/N))*Gv,t)","n3=n3(u1min+(CmpId(0)%M)*Gu+if((floor(CmpId(0)/M)%2) = (0),(0),-(CmpId(0) %2)*Gu+Gu),v1min+(floor(CmpId(0)/N))*Gv,t)","Nx=Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))","Ny=Rapp(n2(u,v,t),n3(u,v,t),n1(u,v,t))","Nz=Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))","n01= 0","n02= 0","n03= 1","n1=Rapp(n01(u,v,t),n02(u,v,t),n03(u,v,t))","n2=Rapp(n02(u,v,t),n03(u,v,t),n01(u,v,t))","n3=Rapp(n03(u,v,t),n01(u,v,t),n02(u,v,t))","u1=(n2(u,v,t)*Nz(u,v,t)-n3(u,v,t)*Ny(u,v,t))","u2=(n3(u,v,t)*Nx(u,v,t)-n1(u,v,t)*Nz(u,v,t))","u3=(n1(u,v,t)*Ny(u,v,t)-n2(u,v,t)*Nx(u,v,t))","U1=Rapp(u1(u,v,t),u2(u,v,t),u3(u,v,t))","U2=Rapp(u2(u,v,t),u3(u,v,t),u1(u,v,t))","U3=Rapp(u3(u,v,t),u1(u,v,t),u2(u,v,t))","c=n1(u,v,t)*Nx(u,v,t)+n2(u,v,t)*Ny(u,v,t)+n3(u,v,t)*Nz(u,v,t)","s=sin(acos(c(u,v,t)))","S0x=Yx(u,v,t) ","S0y=Yy(u,v,t) ","S0z=Yz(u,v,t) ","S2x=(U1(u,v,t)^2*(1-c(u,v,t))+c(u,v,t))*S0x(u,v,t)+(U1(u,v,t)*U2(u,v,t)*(1-c(u,v,t))-U3(u,v,t)*s(u,v,t))*S0y(u,v,t)+(U1(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+U2(u,v,t)*s(u,v,t))*S0z(u,v,t) ","S2y=(U1(u,v,t)*U2(u,v,t)*(1-c(u,v,t))+U3(u,v,t)*s(u,v,t))*S0x(u,v,t)+(U2(u,v,t)^2*(1-c(u,v,t))+c(u,v,t))*S0y(u,v,t)+(U2(u,v,t)*U3(u,v,t)*(1-c(u,v,t))-U1(u,v,t)*s(u,v,t))*S0z(u,v,t) ","S2z=(U1(u,v,t)*U3(u,v,t)*(1-c(u,v,t))-U2(u,v,t)*s(u,v,t))*S0x(u,v,t)+(U2(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+U1(u,v,t)*s(u,v,t))*S0y(u,v,t)+(U3(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+c(u,v,t))*S0z(u,v,t)","Tx=if((floor(CmpId(0)/M)%2) = (0),S2x(u,v,t)*cos(CmpId(0)*beta)-S2z(u,v,t)*sin(CmpId(0)*beta),S2x(u,v,t)) ","Ty=if((floor(CmpId(0)/M)%2) = (0),S2y(u,v,t),S2y(u,v,t)*cos(beta2)-S2z(u,v,t)*sin(beta2)) ","Tz=if((floor(CmpId(0)/M)%2) = (0),S2x(u,v,t)*sin(CmpId(0)*beta)+S2z(u,v,t)*cos(CmpId(0)*beta),S2y(u,v,t)*sin(beta2)+S2z(u,v,t)*cos(beta2))","Sx= S2x(u,v,t) ","Sy= S2y(u,v,t) ","Sz= S2z(u,v,t) ","n01=if((((floor(CmpId(0)/M)%2) = (0)) & (CmpId(0)%2)=(1)),(1),(0))","n02=if(((floor(CmpId(0)/M)%2) = (1)),(1),(0))","n03=if((((floor(CmpId(0)/M)%2) = (0)) & (CmpId(0)%2)=(0)),(1),(0))","n1=Rapp(n01(u,v,t),n02(u,v,t),n03(u,v,t))","n2=Rapp(n02(u,v,t),n03(u,v,t),n01(u,v,t))","n3=Rapp(n03(u,v,t),n01(u,v,t),n02(u,v,t))","u1=(n2(u,v,t)*Nz(u,v,t)-n3(u,v,t)*Ny(u,v,t))","u2=(n3(u,v,t)*Nx(u,v,t)-n1(u,v,t)*Nz(u,v,t))","u3=(n1(u,v,t)*Ny(u,v,t)-n2(u,v,t)*Nx(u,v,t))","U1=Rapp(u1(u,v,t),u2(u,v,t),u3(u,v,t))","U2=Rapp(u2(u,v,t),u3(u,v,t),u1(u,v,t))","U3=Rapp(u3(u,v,t),u1(u,v,t),u2(u,v,t))","c=if((((floor(CmpId(0)/M)%2) = 0) & (CmpId(0)%2)=0 ),(1),(0))","s=if((((floor(CmpId(0)/M)%2) = 0) & (CmpId(0)%2)=0 ),(0),(1))","S0x=Sx(u,v,t) ","S0y=Sy(u,v,t) ","S0z=Sz(u,v,t) ","S2x=(U1(u,v,t)^2*(1-c(u,v,t))+c(u,v,t))*S0x(u,v,t)+(U1(u,v,t)*U2(u,v,t)*(1-c(u,v,t))-U3(u,v,t)*s(u,v,t))*S0y(u,v,t)+(U1(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+U2(u,v,t)*s(u,v,t))*S0z(u,v,t) ","S2y=(U1(u,v,t)*U2(u,v,t)*(1-c(u,v,t))+U3(u,v,t)*s(u,v,t))*S0x(u,v,t)+(U2(u,v,t)^2*(1-c(u,v,t))+c(u,v,t))*S0y(u,v,t)+(U2(u,v,t)*U3(u,v,t)*(1-c(u,v,t))-U1(u,v,t)*s(u,v,t))*S0z(u,v,t) ","S2z=(U1(u,v,t)*U3(u,v,t)*(1-c(u,v,t))-U2(u,v,t)*s(u,v,t))*S0x(u,v,t)+(U2(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+U1(u,v,t)*s(u,v,t))*S0y(u,v,t)+(U3(u,v,t)*U3(u,v,t)*(1-c(u,v,t))+c(u,v,t))*S0z(u,v,t)","Sx= S2x(u,v,t)+Fx(u1min+(CmpId(0)%M)*Gu+if((floor(CmpId(0)/M)%2) = (0),(0),-(CmpId(0) %2)*Gu+Gu),v1min+(floor(CmpId(0)/N))*Gv,t)","Sy= S2y(u,v,t)+Fy(u1min+(CmpId(0)%M)*Gu+if((floor(CmpId(0)/M)%2) = (0),(0),-(CmpId(0) %2)*Gu+Gu),v1min+(floor(CmpId(0)/N))*Gv,t) ","Sz= S2z(u,v,t)+Fz(u1min+(CmpId(0)%M)*Gu+if((floor(CmpId(0)/M)%2) = (0),(0),-(CmpId(0) %2)*Gu+Gu),v1min+(floor(CmpId(0)/N))*Gv,t)"],
        "Component": ["WIRE_00","WIRE_01","WIRE_02","WIRE_03","WIRE_04","WIRE_05","WIRE_06","WIRE_07","WIRE_08","WIRE_09","WIRE_10","WIRE_11","WIRE_12","WIRE_13","WIRE_14","WIRE_15","WIRE_16","WIRE_17","WIRE_18","WIRE_19","WIRE_20","WIRE_00","WIRE_01","WIRE_02","WIRE_03","WIRE_04","WIRE_05","WIRE_06","WIRE_07","WIRE_08","WIRE_09","WIRE_10","WIRE_11","WIRE_12","WIRE_13","WIRE_14","WIRE_15","WIRE_16","WIRE_17","WIRE_18","WIRE_19","WIRE_20","WIRE_00","WIRE_01","WIRE_02","WIRE_03","WIRE_04","WIRE_05","WIRE_06","WIRE_07","WIRE_08","WIRE_09","WIRE_10","WIRE_11","WIRE_12","WIRE_13","WIRE_14","WIRE_15","WIRE_16","WIRE_17","WIRE_18","WIRE_19","WIRE_20","WIRE_00","WIRE_01","WIRE_02","WIRE_03","WIRE_04","WIRE_05","WIRE_06","WIRE_07","WIRE_08","WIRE_09","WIRE_10","WIRE_11","WIRE_12","WIRE_13","WIRE_14","WIRE_15","WIRE_16","WIRE_17","WIRE_18","WIRE_19","WIRE_20","WIRE_00","WIRE_01","WIRE_02","WIRE_03","WIRE_04","WIRE_05","WIRE_06","WIRE_07","WIRE_08","WIRE_09","WIRE_10","WIRE_11","WIRE_12","WIRE_13","WIRE_14","WIRE_15","WIRE_16","WIRE_17","WIRE_18","WIRE_19","WIRE_20","WIRE_00","WIRE_01","WIRE_02","WIRE_03","WIRE_04","WIRE_05","WIRE_06","WIRE_07","WIRE_08","WIRE_09","WIRE_10","WIRE_11","WIRE_12","WIRE_13","WIRE_14","WIRE_15","WIRE_16","WIRE_17","WIRE_18","WIRE_19","WIRE_20","WIRE_00","WIRE_01","WIRE_02","WIRE_03","WIRE_04","WIRE_05","WIRE_06","WIRE_07","WIRE_08","WIRE_09","WIRE_10","WIRE_11","WIRE_12","WIRE_13","WIRE_14","WIRE_15","WIRE_16","WIRE_17","WIRE_18","WIRE_19","WIRE_20","WIRE_00","WIRE_01","WIRE_02","WIRE_03","WIRE_04","WIRE_05","WIRE_06","WIRE_07","WIRE_08","WIRE_09","WIRE_10","WIRE_11","WIRE_12","WIRE_13","WIRE_14","WIRE_15","WIRE_16","WIRE_17","WIRE_18","WIRE_19","WIRE_20","WIRE_20"],
        "Fx": ["Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)","Sx(u,v,t)"],
        "Fy": ["Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)","Sy(u,v,t)"],
        "Fz": ["Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)","Sz(u,v,t)"],
        "Grid": ["20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50","20","50"],
        "Umax": ["umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax","umax"],
        "Umin": ["umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin","umin"],
        "Vmax": ["vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax","vmax"],
        "Vmin": ["vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin","vmin"]
      },
      "Texture": {
        "Colors": ["R=7/10","G=7/10","B=7/10","T=1"],
        "Name": "Gray",
        "Noise": ""
      }
    }
  ],
  "TexturesList": [
    {
      "Texture": {
        "Name": "Lines1",
        "Colors": ["R=cos(7*x*pi)*cos(z*pi)",
          "G=cos(7*y*pi)*cos(x*pi)",
          "B=cos(7*y*pi)*cos(z*pi)",
          "T=1"],
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Texture": {
        "Name": "Lines2",
        "Colors": ["R=sin(7*x*pi)",
          "G=sin(7*y*pi)",
          "B=cos(7*z*pi)",
          "T=1"],
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Texture": {
        "Name": "Lines3",
        "Colors": ["R=(15/10)*cos(x*pi)*sin(z*pi)",
          "G=(15/10)*sin(x*pi)*cos(y*pi)",
          "B=(15/10)*sin(y*pi)*cos(z*pi)",
          "T=1"],
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Texture": {
        "Name": "Lines4",
        "Colors": ["R=cos(7*x*y*pi)",
          "G=sin(7*y*z*pi)",
          "B=sin(7*z*x*pi)",
          "T=1"],
        "Noise": "NoiseW(x,y,z,(1),(3),(0))"
      }
    },
    {
      "Texture": {
        "Colors": ["R=cos(2*x*y*pi)",
          "G=sin(2*y*z*pi)",
          "B=sin(2*z*x*pi)",
          "T=1"],
        "Name": "Lines5",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Texture": {
        "Colors": ["R=cos((x*x+y*y+z*z)*pi)",
          "G=cos((x*x+y*y+z*z)*pi)*cos(x*pi)",
          "B=sin(y*pi)*cos(x*pi)",
          "T=1"],
        "Name": "Lines6",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Texture": {
        "Colors": ["R=cos((x*x+y*y+z*z)*pi)*sin(x*pi)",
          "G=cos((x*x+y*y+z*z)*pi)*sin(y*pi)",
          "B=cos((x*x+y*y+z*z)*pi)*sin(z*pi)",
          "T=1"],
        "Name": "Lines7",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Texture": {
        "Colors": ["R=cos((x*x+y*y)*pi)*cos(x*pi)",
          "G=cos((y*y+z*z)*pi)*cos(y*pi)",
          "B=cos((x*x+z*z)*pi)*cos(z*pi)",
          "T=1"],
        "Name": "Lines8",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Texture": {
        "Colors": ["R=(int(abs(x))+int(abs(y))+int(abs(z)))%2",
          "G=1/10",
          "B=1",
          "T=1"],
        "Name": "Checker",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Texture": {
        "Colors": ["R=1",
          "G=(6/10)*abs(cos(6*z*y*x*y*pi))",
          "B=(1/2)+(3/10)*abs(cos(6*z*z*x*y*pi))",
          "T=1"],
        "Name": "Granit_1",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Texture": {
        "Colors": ["R=1",
          "G=(9/10)*abs(cos(pi*(x*x+y*y+z*z)))",
          "B=(1/2)+(2/10)*abs(cos(3*cos(pi*(x*x+y*y+z*z))))",
          "T=1"],
        "Name": "Granit_2",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Texture": {
        "Colors": ["R=4/10",
          "G=(8/10)*abs(cos(x*x+y*y+z*z)*sin(x*x+y*y+z*z))",
          "B=(86/100)*abs(cos(x*x+y*y+z*z)*cos(x*x+y*y+z*z)*sin(x*x+y*y+z*z))",
          "T=1"],
        "Name": "Granit_3",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Texture": {
        "Colors": ["R=(8/10)",
          "G=(16/10)*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "B=(16/10)*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Texture": {
        "Colors": ["R=8/10",
          "G=(16/10)*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "B=(16/10)*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"],
        "Name": "PerlinNoise",
        "Noise": "NoiseP(x,y,z,Octaves,Lacunarity,Gain)"
      }
    }
  ],
  "PigmentsList": [
    {
      "Pigment": {
        "Name": "Pigment_1",
        "Colors": [
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=2/10",
                "R=4/10",
                "G=4/10",
                "B=7/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=3/10",
                "R=1",
                "G=1/10",
                "B=31/100",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=6/10",
                "R=51/100",
                "G=17/100",
                "B=1",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=6/10",
                "R=1",
                "G=3/10",
                "B=1/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=1",
                "R=9/10",
                "G=17/100",
                "B=1/10",
                "A=1"
              ]
            }
          }
        ],
        "Gradient": "3*cos((x*x+y*y)*pi)*sin((y*y+z*z)*pi)",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Pigment": {
        "Name": "Pigment_2",
        "Colors": [
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=2/10",
                "R=9/10",
                "G=9/10",
                "B=4/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=3/10",
                "R=1",
                "G=1/10",
                "B=31/100",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=6/10",
                "R=1",
                "G=7/10",
                "B=1",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=6/10",
                "R=1",
                "G=3/10",
                "B=1/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=1",
                "R=15/100",
                "G=6/10",
                "B=1/10",
                "A=1"
              ]
            }
          }
        ],
        "Gradient": "3*atan((x*x*y*z)*pi)*cos(y*y*z*pi)",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Pigment": {
        "Name": "Pigment_3",
        "Colors": [
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=0",
                "R=1",
                "G=0",
                "B=0",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=2/10",
                "R=0",
                "G=0",
                "B=1",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=5/10",
                "R=1",
                "G=1",
                "B=0",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=7/10",
                "R=0",
                "G=1",
                "B=0",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=1",
                "R=1",
                "G=0",
                "B=0",
                "A=1"
              ]
            }
          }
        ],
        "Gradient": "sin(x*30)+sin(y*30)",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Pigment": {
        "Name": "Pigment_4",
        "Colors": [
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=2/10",
                "R=1",
                "G=85/100",
                "B=4/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=3/10",
                "R=1",
                "G=1/10",
                "B=31/100",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=6/10",
                "R=31/100",
                "G=31/100",
                "B=1",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=6/10",
                "R=1",
                "G=3/10",
                "B=1/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=1",
                "R=4/10",
                "G=6/10",
                "B=1/10",
                "A=1"
              ]
            }
          }
        ],
        "Gradient": "7*cos(pi*(x*x+y*y))*cos(y*z)*cos(pi*(y*y*x*x))*cos((z*z+x*x)*pi)*(cos(x)*sin(y)*cos(y)*sin(z*z+x*y)-cos(z)*sin(x))",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    },
    {
      "Pigment": {
        "Colors": [
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=4/10",
                "R=1",
                "G=85/100",
                "B=4/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=5/10",
                "R=1",
                "G=1/10",
                "B=31/100",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=5/10",
                "R=31/100",
                "G=31/100",
                "B=1",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=7/10",
                "R=1",
                "G=3/10",
                "B=1/10",
                "A=1"
              ]
            }
          },
          {
            "Color": {
              "Name": "Red",
              "Vrgba": ["V=1",
                "R=4/10",
                "G=6/10",
                "B=1/10",
                "A=1"
              ]
            }
          }
        ],
        "Gradient": "3*cos(x*x+y*y)*cos(y*z-y*x)*(cos(x*y*z)+sin(x*y*z))",
        "Name": "Pigment_5",
        "Noise": "NoiseW(x,y,z,(1),(2),(0))"
      }
    }
  ]
}
