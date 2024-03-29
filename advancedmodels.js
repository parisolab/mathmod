{
  "MathModels": [
    {
      "Param3D": {
        "Description": [
          "Double Distorsion by Abderrahman Taha 04/05/2017"
        ],
        "Name": [
          "Double Distorsion"
        ],
        "Component": [
          "Torus"
        ],
        "Const": [
          "N=5",
          "M=16",
          "P=13",
          "k=5",
          "k0=5",
          "k1=5",
          "L=1DOTSYMBOL5",
          "r0=6",
          "dv=0DOTSYMBOL01",
          "P=5",
          "MM=10"
        ],
        "Funct": [
          "Fx=(1+0DOTSYMBOL5*cos(v+t))*cos(u-k*(v)+t)",
          "Fy=(1+0DOTSYMBOL5*cos(v+t))*sin(u-k*(v)+t)",
          "Fz=L*sin(v+t)",
          "DFxv = (Fx(u,v+dv,t) - Fx(u,v,t))/dv",
          "DFyv = (Fy(u,v+dv,t) - Fy(u,v,t))/dv",
          "DFzv = (Fz(u,v+dv,t) - Fz(u,v,t))/dv",
          "DFxv2 = (DFxv(u,v+dv,t) - DFxv(u,v,t))/dv",
          "DFyv2 = (DFyv(u,v+dv,t) - DFyv(u,v,t))/dv",
          "DFzv2 = (DFzv(u,v+dv,t) - DFzv(u,v,t))/dv",
          "Rapp = (u/sqrt(u*u+v*v+t*t))",
          "Nx = Rapp(DFxv2(u,v,t),DFyv2(u,v,t),DFzv2(u,v,t))",
          "Ny = Rapp(DFyv2(u,v,t),DFxv2(u,v,t),DFzv2(u,v,t))",
          "Nz = Rapp(DFzv2(u,v,t),DFyv2(u,v,t),DFxv2(u,v,t))",
          "Bx = 1/sqrt(u*u+v*v+t*t)",
          "Binx = (DFyv(u,v,t) * Nz(u,v,t) - DFzv(u,v,t) * Ny(u,v,t))*Bx(DFxv(u,v,t), DFyv(u,v,t), DFzv(u,v,t))",
          "Biny = (DFzv(u,v,t) * Nx(u,v,t) - DFxv(u,v,t) * Nz(u,v,t))*Bx(DFxv(u,v,t), DFyv(u,v,t), DFzv(u,v,t))",
          "Binz = (DFxv(u,v,t) * Ny(u,v,t) - DFyv(u,v,t) * Nx(u,v,t))*Bx(DFxv(u,v,t), DFyv(u,v,t), DFzv(u,v,t))",
          "S = (r0/100)*((k0-1)*cos(u+k1*t) + cos((k0-1)*u+k1*t))",
          "C = (r0/100)*((k0-1)*sin(u+k1*t) - sin((k0-1)*u+k1*t))",
          "Sx = Fx(pi,v,t) + Nx(pi,v,t)*C(u,v,t) + Binx(pi,v,t)*S(u,v,t)",
          "Sy = Fy(pi,v,t) + Ny(pi,v,t)*C(u,v,t) + Biny(pi,v,t)*S(u,v,t)",
          "Sz = Fz(pi,v,t) + Nz(pi,v,t)*C(u,v,t) + Binz(pi,v,t)*S(u,v,t)"
        ],
        "Fx": [
          "Sx(u,v,t)"
        ],
        "Fy": [
          "Sy(u,v,t)"
        ],
        "Fz": [
          "Sz(u,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "-pi"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R= if(int(i)%(M/6)>P | int(j)%(M)>P,0DOTSYMBOL8,0DOTSYMBOL8) ",
          "G= if(int(i)%(M/6)>P | int(j)%(M)>P,0DOTSYMBOL1,0DOTSYMBOL8) ",
          "B= if(int(i)%(M/6)>P | int(j)%(M)>P,0DOTSYMBOL1,0DOTSYMBOL8) ",
          "T= 1 "
        ],
        "Name": "Candy",
        "Noise": "1"
      }
    },
    {
      "Param3D": {
        "Description": [
          "Torsion spring v2 by Abderrahman Taha 01/05/2017"
        ],
        "Name": [
          "Torsion_Spring_02"
        ],
        "Component": [
          "Torus_Section"
        ],
        "Const": [
          "k=7",
          "L=1DOTSYMBOL5",
          "r0=12",
          "dv=0DOTSYMBOL01"
        ],
        "Funct": [
          "Fx=(1+0DOTSYMBOL5*cos(t+v))*cos(pi-k*(v))",
          "Fy=(1+0DOTSYMBOL5*cos(t+v))*sin(pi-k*(v))",
          "Fz=L*sin(t+v)",
          "DFxv = (Fx(u,v+dv,t) - Fx(u,v,t))/dv",
          "DFyv = (Fy(u,v+dv,t) - Fy(u,v,t))/dv",
          "DFzv = (Fz(u,v+dv,t) - Fz(u,v,t))/dv",
          "DFxv2 = (DFxv(u,v+dv,t) - DFxv(u,v,t))/dv",
          "DFyv2 = (DFyv(u,v+dv,t) - DFyv(u,v,t))/dv",
          "DFzv2 = (DFzv(u,v+dv,t) - DFzv(u,v,t))/dv",
          "Rapp = (u/sqrt(u*u+v*v+t*t))",
          "Nx = Rapp(DFxv2(u,v,t),DFyv2(u,v,t),DFzv2(u,v,t))",
          "Ny = Rapp(DFyv2(u,v,t),DFxv2(u,v,t),DFzv2(u,v,t))",
          "Nz = Rapp(DFzv2(u,v,t),DFyv2(u,v,t),DFxv2(u,v,t))",
          "Bx = 1/sqrt(u*u+v*v+t*t)",
          "Binx = (DFyv(u,v,t) * Nz(u,v,t) - DFzv(u,v,t) * Ny(u,v,t))*Bx(DFxv(u,v,t), DFyv(u,v,t), DFzv(u,v,t))",
          "Biny = (DFzv(u,v,t) * Nx(u,v,t) - DFxv(u,v,t) * Nz(u,v,t))*Bx(DFxv(u,v,t), DFyv(u,v,t), DFzv(u,v,t))",
          "Binz = (DFxv(u,v,t) * Ny(u,v,t) - DFyv(u,v,t) * Nx(u,v,t))*Bx(DFxv(u,v,t), DFyv(u,v,t), DFzv(u,v,t))",
          "Sx = Fx(u,v,t) + (r0/100)*Nx(u,v,t)*cos(u) + (r0/100)*Binx(u,v,t)*sin(u)",
          "Sy = Fy(u,v,t) + (r0/100)*Ny(u,v,t)*cos(u) + (r0/100)*Biny(u,v,t)*sin(u)",
          "Sz = Fz(u,v,t) + (r0/100)*Nz(u,v,t)*cos(u) + (r0/100)*Binz(u,v,t)*sin(u)"
        ],
        "Fx": [
          "Sx(u,v,t)"
        ],
        "Fy": [
          "Sy(u,v,t)"
        ],
        "Fz": [
          "Sz(u,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "-pi"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Twin Klein by Abderrahman Taha 29/04/2017"
        ],
        "Name": [
          "Twin Klein"
        ],
        "Component": [
          "TwinKlein"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=5",
          "M=3",
          "A=3DOTSYMBOL5",
          "B=2",
          "C=3",
          "D=3",
          "MaxU=2*pi",
          "MinU=0",
          "MaxV=10*pi",
          "MinV=0"
        ],
        "Funct": [
          "th=if(M=1, 0DOTSYMBOL3*((abs(sin(11*u)*cos(11*v)))^19+0DOTSYMBOL1*((sin(2*N*u)))),if(M=2, 0DOTSYMBOL9*sin((N*v)% pi/3), if(M=3, (0DOTSYMBOL4*abs(cos(7*(u))^2 - sin(9*(v))^5 ))^3,if(M=4, 0DOTSYMBOL4*sin(N*v-u)^100,if(M=5, 0DOTSYMBOL4*sin(N*v),if(M=6, 0DOTSYMBOL4*sin(2*N*v-u),if(M=7, 0DOTSYMBOL4*sin(N*v)^10,if(M=8, -0DOTSYMBOL3*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/1DOTSYMBOL8)^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/1DOTSYMBOL9)^5DOTSYMBOL5),if(M=9, ((sin(15*u)*cos(15*u)))^4 + (sin(2*N*v)),if(M=10, ((sin(9*u)*cos(9*v)))^2 +0DOTSYMBOL5* (sin(2*N*u)), (0DOTSYMBOL4*abs(cos(7*(u))^2 - sin(9*(v))^5 ))^3))))))))))",
          "Fx=if(v<2*pi, (A-(A-1)*cos(v))*cos(u),if(v<3*pi, -B+(B+cos(u))*cos(v),-B+B*cos(v)-cos(u)))",
          "Fy=if(v<2*pi,(A-(A-1)*cos(v))*sin(u), sin(u))",
          "Fz=if(v<pi, -C*sin(v), if(v<2*pi, D*v-D*pi, if(v<3*pi,((D-1)+cos(u))*sin(v)+D*pi,-D*v+D*4*pi)))",
          "Fx=if(v<6*pi, Fx(u,v,t), -Fx(u,(v-6*pi)%(4*pi),t))",
          "Fy=if(v<6*pi,Fy(u,v,t), Fy(u,(v-6*pi)%(4*pi),t))",
          "Fz=if(v<6*pi,Fz(u,v,t), -Fz(u,(v-6*pi)%(4*pi),t)-19)",
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
          "Fz=Fz(u,v,t)+if(v<6*pi,th(u,v-3*t,t),th(u,v+3*t,t))*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))"
        ],
        "Fx": [
          "Fx(u,v,t)"
        ],
        "Fy": [
          "Fy(u,v,t)"
        ],
        "Fz": [
          "Fz(u,v,t)"
        ],
        "Umax": [
          "MaxU"
        ],
        "Umin": [
          "MinU"
        ],
        "Vmax": [
          "MaxV"
        ],
        "Vmin": [
          "MinV"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Sea Shell by Abderrahman Taha 16/04/2017"
        ],
        "Name": [
          "Sea_Shell_001"
        ],
        "Component": [
          "Sea Shell"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=5",
          "M=3",
          "MaxU=6*pi",
          "MinU=0",
          "MaxV=2*pi",
          "MinV=0",
          "a=0DOTSYMBOL2",
          "b=1",
          "c=0DOTSYMBOL1",
          "n=2"
        ],
        "Funct": [
          "th=-(((u)/MaxU+0DOTSYMBOL05)*0DOTSYMBOL4*abs(cos(7*(u))^3 - sin(7*(v))^2 ))^3",
          "Fx=2*(1-exp(u/(6*pi)))*cos(u)*cos(v/2)^2",
          "Fy=2*(-1+exp(u/(6*pi)))*sin(u)*cos(v/2)^2",
          "Fz=1-exp(u/(3*pi))-sin(v)+exp(u/(6*pi))*sin(v)",
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
          "Fx=Fx(u,v,t)+th(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Fy=Fy(u,v,t)+th(u,v,t)*Rapp(n2(u,v,t),n1(u,v,t),n3(u,v,t))",
          "Fz=Fz(u,v,t)+th(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))"
        ],
        "Fx": [
          "-Fx(u,v,t)"
        ],
        "Fy": [
          "Fy(u,v,t)"
        ],
        "Fz": [
          "Fz(u,v,t)"
        ],
        "Umax": [
          "MaxU"
        ],
        "Umin": [
          "MinU"
        ],
        "Vmax": [
          "MaxV"
        ],
        "Vmin": [
          "MinV"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Seashell by Abderrahman Taha 19/04/2017"
        ],
        "Name": [
          "Sea_Shell_002"
        ],
        "Component": [
          "Sea Shell"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=14",
          "M=4",
          "MaxU=pi",
          "MinU=0",
          "MaxV=5*pi/2",
          "MinV=0",
          "a=0DOTSYMBOL2",
          "b=1",
          "c=0DOTSYMBOL1",
          "n=2"
        ],
        "Funct": [
          "th=0DOTSYMBOL2*((1-abs(u-pi/2)/MaxU)*(v/MaxV+0DOTSYMBOL05)*abs(cos(N*(u))^3-sin(N*(v))^2))^3",
          "Fx=if(M=1,2*(1-exp(u/(6*pi)))*cos(u)*cos(v/2)^2,if(M=2,((a*(1-v/(2*pi))*(1+cos(u))+c)*cos(n*v))*6+4,if(M=3,2^v*(sin(u)*cos(u))/35,if(M=4,1DOTSYMBOL2^v*(sin(u)^2*sin(v))+2,2*(1-exp(u/(6*pi)))*cos(u)*cos(v/2)^2))))",
          "Fy=if(M=1,2*(-1+exp(u/(6*pi)))*sin(u)*cos(v/2)^2,if(M=2,((a*(1-v/(2*pi))*(1+cos(u))+c)*sin(n*v))*6+4,if(M=3,2^v*(sin(u)^2*sin(v))/35-4,if(M=4,1DOTSYMBOL2^v*(sin(u)*cos(u))+5,2*(-1+exp(u/(6*pi)))*sin(u)*cos(v/2)^2))))",
          "Fz=if(M=1,1-exp(u/(3*pi))-sin(v)+exp(u/(6*pi))*sin(v),if(M=2,(b*v/(2*pi)+a*(1-v/(2*pi))*sin(u))*6-6,if(M=3,2^v*(sin(u)^2*cos(v))/35-12,if(M=4,1DOTSYMBOL2^v*(sin(u)^2*cos(v))-12,1-exp(u/(3*pi))-sin(v)+exp(u/(6*pi))*sin(v)))))",
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
          "Fx=Fx(u,v,t)+th(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Fy=Fy(u,v,t)+th(u,v,t)*Rapp(n2(u,v,t),n1(u,v,t),n3(u,v,t))",
          "Fz=Fz(u,v,t)+th(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))"
        ],
        "Fx": [
          "Fx(u,v,t)"
        ],
        "Fy": [
          "Fy(u,v,t)"
        ],
        "Fz": [
          "Fz(u,v,t)"
        ],
        "Umax": [
          "MaxU"
        ],
        "Umin": [
          "MinU"
        ],
        "Vmax": [
          "MaxV"
        ],
        "Vmin": [
          "MinV"
        ]
      }
    },
    {
      "Param3D": {
        "Description": [
          "Torsion spring by Abderrahman Taha 28/03/2017"
        ],
        "Name": [
          "Torsion_Spring"
        ],
        "Component": [
          "TorsionSpring"
        ],
        "Const": [
          "N=6",
          "M=5",
          "R=14",
          "R1=20",
          "r0=19",
          "P=3",
          "MM=6",
          "dv=0DOTSYMBOL001"
        ],
        "Funct": [
          "Fx = ((R1/10)*cos(v)+(R/10)*u*cos(N*v+M*sin(t+v))*cos(v))",
          "Fy = ((R1/10)*sin(v)+(R/10)*u*cos(N*v+M*sin(t+v))*sin(v))",
          "Fz = ((R/10)*u*sin(N*v+M*sin(t+v)))",
          "DFxv = -(R1/10)*sin(v) + (R/10)*u*(-(N+M*cos(t+v))*sin(N*v+M*sin(t+v))*cos(v)    - cos(N*v+M*sin(t+v))*sin(v))",
          "DFyv = (R1/10)*cos(v) + (R/10)*u*(-(N+M*cos(t+v))*sin(N*v+M*sin(t+v))*sin(v)    + cos(N*v+M*sin(t+v))*cos(v))",
          "DFzv =  (R/10)*u*( (N+M*cos(t+v))* cos(N*v+M*sin(t+v)) )",
          "DFxv2 = (DFxv(u,v+dv,t) - DFxv(u,v,t))/dv",
          "DFyv2 = (DFyv(u,v+dv,t) - DFyv(u,v,t))/dv",
          "DFzv2 = (DFzv(u,v+dv,t) - DFzv(u,v,t))/dv",
          "Rapp = (u/sqrt(u*u+v*v+t*t))",
          "Nx = Rapp(DFxv2(u,v,t),DFyv2(u,v,t),DFzv2(u,v,t))",
          "Ny = Rapp(DFyv2(u,v,t),DFxv2(u,v,t),DFzv2(u,v,t))",
          "Nz = Rapp(DFzv2(u,v,t),DFyv2(u,v,t),DFxv2(u,v,t))",
          "Bx = 1/sqrt(u*u+v*v+t*t)",
          "Binx = (DFyv(u,v,t) * Nz(u,v,t) - DFzv(u,v,t) * Ny(u,v,t))*Bx(DFxv(u,v,t), DFyv(u,v,t), DFzv(u,v,t))",
          "Biny = (DFzv(u,v,t) * Nx(u,v,t) - DFxv(u,v,t) * Nz(u,v,t))*Bx(DFxv(u,v,t), DFyv(u,v,t), DFzv(u,v,t))",
          "Binz = (DFxv(u,v,t) * Ny(u,v,t) - DFyv(u,v,t) * Nx(u,v,t))*Bx(DFxv(u,v,t), DFyv(u,v,t), DFzv(u,v,t))",
          "Sx  = Fx(1,v,t) + (r0/100)*Nx(1,v,t)*cos(u) + (r0/100)*Binx(1,v,t)*sin(u)",
          "Sy  = Fy(1,v,t) + (r0/100)*Ny(1,v,t)*cos(u) + (r0/100)*Biny(1,v,t)*sin(u)",
          "Sz  = Fz(1,v,t) + (r0/100)*Nz(1,v,t)*cos(u) + (r0/100)*Binz(1,v,t)*sin(u)"
        ],
        "Fx": [
          "Sx(u,v,t)"
        ],
        "Fy": [
          "Sy(u,v,t)"
        ],
        "Fz": [
          "Sz(u,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "-pi"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Sliders": {
        "Max": [
          "15",
          "15",
          "30",
          "30",
          "111",
          "15",
          "15",
          "30",
          "30",
          "111",
          "15",
          "15",
          "30",
          "30",
          "111",
          "15",
          "15",
          "30",
          "30",
          "111",
          "15",
          "15",
          "30",
          "30",
          "111"
        ],
        "Min": [
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0"
        ],
        "Name": [
          "N",
          "M",
          "R",
          "R1",
          "r0"
        ],
        "Position": [
          "6",
          "5",
          "14",
          "20",
          "19",
          "11",
          "8",
          "6",
          "20",
          "19",
          "11",
          "15",
          "10",
          "20",
          "19",
          "4",
          "15",
          "6",
          "18",
          "19",
          "11",
          "8",
          "9",
          "22",
          "19"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      },
      "Texture": {
        "Colors": [
          "R= if(int(i)%MM>P & int(i)%MM<P+2 ,0DOTSYMBOL8,0DOTSYMBOL8) ",
          "G= if(int(i)%MM>P & int(i)%MM<P+2 ,0DOTSYMBOL8,0DOTSYMBOL1) ",
          "B= if(int(i)%MM>P & int(i)%MM<P+2,0DOTSYMBOL8,0DOTSYMBOL1) ",
          "T= 1 "
        ],
        "Name": "Rings",
        "Noise": "1"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Straw Basket using the predefined MathMod function fmesh by Abderrahman Taha 17/09/2019"
        ],
        "Name": [
          "Straw Basket_02"
        ],
        "Component": [
          "Straw Basket"
        ],
        "Const": [
          "A = 5",
          "B = 2",
          "C = 1",
          "D = 0DOTSYMBOL09",
          "E = 1",
          "th = A*pi / 10",
          "ph = B*pi/ 10"
        ],
        "Funct": [
          "fmesh0=-fmesh(x,y,z,A/10,B/10,C,D,E) +0DOTSYMBOL08 ",
          "fmesh3= if(atan2(z,sqrt(x*x+y*y))<0DOTSYMBOL9, fmesh0(atan2(y,x),sqrt(x*x+y*y+z*z)-4,atan2(z,sqrt(x*x+y*y)),t), 1)*(atan2(z,sqrt(x*x+y*y))<0DOTSYMBOL9)"
        ],
        "Fxyz": [
          "  fmesh3(x,y,z,t)"
        ],
        "Xmax": [
          "5"
        ],
        "Xmin": [
          "-5"
        ],
        "Ymax": [
          "5"
        ],
        "Ymin": [
          "-5"
        ],
        "Zmax": [
          "5"
        ],
        "Zmin": [
          "-5"
        ]
      }
    },
    {
      "Param3D": {
        "Description": [
          "Twisted_Strip by Abderrahman Taha 15/03/2017"
        ],
        "Name": [
          "Twisted_Strip_02"
        ],
        "Component": [
          "TwistedStrip"
        ],
        "Const": [
          "N=6",
          "M=5",
          "R=14"
        ],
        "Fx": [
          "cos(v)+(R/10)*u*cos(N*v+M*sin(t+v))*cos(v)"
        ],
        "Fy": [
          "sin(v)+(R/10)*u*cos(N*v+M*sin(t+v))*sin(v)"
        ],
        "Fz": [
          "(R/10)*u*sin(N*v+M*sin(t+v))"
        ],
        "Umax": [
          "0DOTSYMBOL4"
        ],
        "Umin": [
          "-0DOTSYMBOL4"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Sliders": {
        "Max": [
          "15",
          "15",
          "30"
        ],
        "Min": [
          "0",
          "0",
          "0"
        ],
        "Name": [
          "N",
          "M",
          "R"
        ],
        "Position": [
          "6",
          "5",
          "14"
        ],
        "Step": [
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Inka_Sun and Twisted_Toroids v02 by Abderrahman Taha 10/03/2017"
        ],
        "Name": [
          "Inka Sun_02"
        ],
        "Component": [
          "Inka Sun_1",
          "Inka Sun_2"
        ],
        "Const": [
          "N=4",
          "M=1"
        ],
        "Funct": [
          "InkaSun= if(if(t=1,(abs(sin((N/2)*(u*(sin(v))-u))))<0DOTSYMBOL4,(abs(sin((N/2)*(u*(sin(v))-u))))>0DOTSYMBOL38),-0DOTSYMBOL45,0)",
          "InkaSun1= if(if(t=1,(abs(sin((N/2)*(u*abs(sin(v))-u))))<0DOTSYMBOL4,(abs(sin((N/2)*(u*abs(sin(v))-u))))>0DOTSYMBOL38),-0DOTSYMBOL45,0)",
          "TwistedTori=if( t = 1, if ( (abs(sin((N/2)*u-v)))>0DOTSYMBOL38,-0DOTSYMBOL45,0),if ( (abs(sin((N/2)*u-v)))<0DOTSYMBOL38,-0DOTSYMBOL45,0))",
          "Th= if(M = 1, InkaSun(u,v,t),if(M = 2, InkaSun1(u,v,t),if(M = 3, TwistedTori(u,v,t), InkaSun(u,v,t))))",
          "Fx=(1+0DOTSYMBOL5*cos(u))*cos(v)",
          "Fy=0DOTSYMBOL5*sin(u)",
          "Fz=(1+0DOTSYMBOL5*cos(u))*sin(v)",
          "n1=((-0DOTSYMBOL5*cos(u))*(-(1+0DOTSYMBOL5*cos(u))*cos(v)))",
          "n2=((0DOTSYMBOL5*sin(u)*sin(v))*((1+0DOTSYMBOL5*cos(u))*sin(v))-(0DOTSYMBOL5*sin(u)*cos(v))*(-(1+0DOTSYMBOL5*cos(u))*cos(v)))",
          "n3=(-(-0DOTSYMBOL5*cos(u))*((1+0DOTSYMBOL5*cos(u))*sin(v)))",
          "Rapp=u/sqrt(u*u + v*v + t*t)",
          "Gx=Fx(u,v,t)+Th(u,v,t)*Rapp(n1(u,v,t),n2(u,v,t),n3(u,v,t))",
          "Gy=Fy(u,v,t)+Th(u,v,t)*Rapp(n2(u,v,t),n1(u,v,t),n3(u,v,t))",
          "Gz=Fz(u,v,t)+Th(u,v,t)*Rapp(n3(u,v,t),n1(u,v,t),n2(u,v,t))"
        ],
        "Fx": [
          "Gx(u,v,1)",
          "Gx(u,v,0)"
        ],
        "Fy": [
          "Gy(u,v,1)",
          "Gy(u,v,0)"
        ],
        "Fz": [
          "Gz(u,v,1)",
          "Gz(u,v,0)"
        ],
        "Umax": [
          "2*pi",
          "2*pi"
        ],
        "Umin": [
          "0",
          "0"
        ],
        "Vmax": [
          "2*pi",
          "2*pi"
        ],
        "Vmin": [
          "0",
          "0"
        ]
      },
      "Sliders": {
        "SetNames": [
          "TwistedTori",
          "InkaSun",
          "InkaSun2"
        ],
        "Max": [
          "15",
          "3",
          "15",
          "3",
          "15",
          "3"
        ],
        "Min": [
          "0",
          "1",
          "0",
          "1",
          "0",
          "1"
        ],
        "Name": [
          "N",
          "M"
        ],
        "Position": [
          "4",
          "3",
          "2",
          "1",
          "4",
          "2"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Set of Spheres animation v02 by Abderrahman Taha 09/03/2017"
        ],
        "Name": [
          "SetofSpheres_02"
        ],
        "Component": [
          "SetSpheres"
        ],
        "Const": [
          "Step1=0DOTSYMBOL41",
          "Step2=0DOTSYMBOL41",
          "R00=0DOTSYMBOL035"
        ],
        "Funct": [
          "Sphere = (x*x+y*y+ z*z-R00)",
          "Sphere1 = Sphere(x,(abs(y)%Step1)-Step1/2,z,t)",
          "Sphere2 = -Sphere1((abs(x)%Step2)-Step2/2,y,z,t)",
          "Plan = Sphere2(x , y, z - 0DOTSYMBOL7*(sin(2*t+( (x - ( (abs(x)%Step2)-Step2/2)-7)^2+(y -((abs(y)%Step1)-Step1/2)-7)^2)/4 )),t)"
        ],
        "Fxyz": [
          "Plan(x,y,z,t)"
        ],
        "Xmax": [
          " 13DOTSYMBOL93"
        ],
        "Xmin": [
          "0"
        ],
        "Ymax": [
          " 13DOTSYMBOL93"
        ],
        "Ymin": [
          "0"
        ],
        "Zmax": [
          " 1"
        ],
        "Zmin": [
          "-1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Set of Spheres animation by Abderrahman Taha 08/03/2017"
        ],
        "Name": [
          "SetOfSpheres"
        ],
        "Component": [
          "SetSpheres"
        ],
        "Const": [
          "Step1=0DOTSYMBOL4",
          "Step2=0DOTSYMBOL4",
          "R00=0DOTSYMBOL031"
        ],
        "Funct": [
          "Sphere = (x*x+y*y+ z*z-R00)",
          "Sphere1 = Sphere(x,y,(abs(z)%Step1) -Step1/2,t)",
          "Sphere2 = - Sphere1((abs(x)%Step2) -Step2/2,y,z,t)",
          "Plan = Sphere2(x,0DOTSYMBOL7* (sin(2*t+ ( (x)^2+(z)^2)/4 )) +y,z,t)"
        ],
        "Fxyz": [
          "Plan(x,z,y,t)"
        ],
        "Xmax": [
          " 6DOTSYMBOL8"
        ],
        "Xmin": [
          "-6DOTSYMBOL4"
        ],
        "Ymax": [
          " 6DOTSYMBOL8"
        ],
        "Ymin": [
          "-6DOTSYMBOL4"
        ],
        "Zmax": [
          " 1DOTSYMBOL6"
        ],
        "Zmin": [
          "-1DOTSYMBOL6"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Twisted Torus 01 by Abderrahman Taha 26/02/2017"
        ],
        "Name": [
          "TwistedTorus"
        ],
        "Component": [
          "TwistedTorus"
        ],
        "Const": [
          "th=4",
          "P=5",
          "R=3",
          "M=1"
        ],
        "Funct": [
          "ThickIso=(x*x- 0DOTSYMBOL01*th*th)",
          "Cylinder=if(sqrt(x*x+y*y)<R, min(ThickIso(x,y,z,t), ThickIso(y,x,z,t)),1)",
          "Cylinder1=if(sqrt(x*x+y*y)<R, ThickIso(x,y,z,t),1)",
          "Twist = Cylinder( x*cos(0DOTSYMBOL25*M*z)+y*sin(0DOTSYMBOL25*M*z) , x*sin(0DOTSYMBOL25*M*z)-y*cos(0DOTSYMBOL25*M*z), z,t)",
          "Torus = Twist( (sqrt(x*x+z*z)-P) , y, atan2(z,x),t)",
          "TorusL =(Torus(x,y,z,t))* min( (sqrt(x*x+z*z)-P)^2 + y*y - R*R , Torus(x,y,z,t) ) "
        ],
        "Fxyz": [
          "-TorusL(x,y,z,t)"
        ],
        "Xmax": [
          "(P+R)"
        ],
        "Xmin": [
          "-(P+R)"
        ],
        "Ymax": [
          " R"
        ],
        "Ymin": [
          "-R"
        ],
        "Zmax": [
          " (P+R)"
        ],
        "Zmin": [
          "-(P+R)"
        ]
      },
      "Sliders": {
        "Max": [
          "20",
          "20",
          "10",
          "10",
          "20",
          "20",
          "10",
          "10",
          "20",
          "20",
          "10",
          "10",
          "20",
          "20",
          "10",
          "10"
        ],
        "Min": [
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0"
        ],
        "Name": [
          "th",
          "M",
          "P",
          "R"
        ],
        "Position": [
          "4",
          "1",
          "5",
          "3",
          "10",
          "6",
          "5",
          "3",
          "4",
          "8",
          "5",
          "3",
          "12",
          "4",
          "4",
          "4"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Scherk Torus 0N by Abderrahman Taha 25/02/2017"
        ],
        "Name": [
          "Scherk_25"
        ],
        "Component": [
          "Scherk"
        ],
        "Const": [
          "th=0DOTSYMBOL1",
          "N=5",
          "n=6",
          "P=3",
          "R=1DOTSYMBOL7",
          "M=1"
        ],
        "Funct": [
          "Scherk_2=(sinh(x)*sinh(y) - sin(z))",
          "Scherk_3=((sinh(x)*sinh(cos(pi/3)*x-sin(pi/3)*y)*sinh(cos(2*pi/3)*x-sin(2*pi/3)*y)-cos(z) ) )",
          "Scherk_4=((sinh(x)*sinh(cos(pi/4)*x-sin(pi/4)*y)*sinh(cos(2*pi/4)*x-sin(2*pi/4)*y) *sinh(cos(3*pi/4)*x-sin(3*pi/4)*y) -cos(z) ) )",
          "Scherk_5=((sinh(x)*sinh(cos(pi/5)*x-sin(pi/5)*y)*sinh(cos(2*pi/5)*x-sin(2*pi/5)*y) *sinh(cos(3*pi/5)*x-sin(3*pi/5)*y) *sinh(cos(4*pi/5)*x-sin(4*pi/5)*y) -cos(z) ) )",
          "Iso=if(N=2,Scherk_2(x,y,z,t), if(N=3,Scherk_3(x,y,z,t),if(N=4,Scherk_4(x,y,z,t),Scherk_5(x,y,z,t))))",
          "DFx=(Iso(x+0DOTSYMBOL01,y,z,t)-Iso(x,y,z,t))/0DOTSYMBOL01",
          "DFy=(Iso(x,y+0DOTSYMBOL01,z,t)-Iso(x,y,z,t))/0DOTSYMBOL01",
          "DFz=(Iso(x,y,z+0DOTSYMBOL01,t)-Iso(x,y,z,t))/0DOTSYMBOL01",
          "Rapport=(x/sqrt(x*x+y*y+z*z))",
          "Iso3=(Iso(x-th*Rapport(DFx(x,y,z,t), DFy(x,y,z,t), DFz(x,y,z,t), t),y-th*Rapport(DFy(x,y,z,t), DFx(x,y,z,t), DFz(x,y,z,t), t),z-th*Rapport(DFz(x,y,z,t), DFx(x,y,z,t), DFy(x,y,z,t), t), t))",
          "Iso2=(Iso(x+th*Rapport(DFx(x,y,z,t), DFy(x,y,z,t), DFz(x,y,z,t), t),y+th*Rapport(DFy(x,y,z,t), DFx(x,y,z,t), DFz(x,y,z,t), t),z+th*Rapport(DFz(x,y,z,t), DFx(x,y,z,t), DFy(x,y,z,t), t), t))",
          "ThickIso=(Iso2(x,y,z,t)*Iso3(x,y,z,t))",
          "Cylinder=if(sqrt(x*x+y*y)<R, ThickIso(x,y,2*t+z,t),1)",
          "Twist = Cylinder( x*cos(M*z/n)-y*sin(M*z/n) , x*sin(M*z/n)+y*cos(M*z/n), z,t)",
          "Torus = Twist( (sqrt(x*x+z*z)-P) , y, n*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-Torus(x,z,y,t)"
        ],
        "Xmax": [
          " P+R"
        ],
        "Xmin": [
          "-(P+R) "
        ],
        "Ymax": [
          " P+R"
        ],
        "Ymin": [
          "-(P+R)"
        ],
        "Zmax": [
          " R"
        ],
        "Zmin": [
          "-R"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Scherk Torus 02 by Abderrahman Taha 22/02/2017"
        ],
        "Name": [
          "ScherkTorus_02"
        ],
        "Component": [
          "Scherk"
        ],
        "Const": [
          "th=0DOTSYMBOL2",
          "N=10",
          "R=8",
          "L=6"
        ],
        "Funct": [
          "Scherk=((sinh(x)*sinh(cos(pi/3)*x-sin(pi/3)*y)*sinh(cos(2*pi/3)*x-sin(2*pi/3)*y)-cos(z) ) )",
          "DFx=(Scherk(x+0DOTSYMBOL01,y,z,t)-Scherk(x,y,z,t))/0DOTSYMBOL01",
          "DFy=(Scherk(x,y+0DOTSYMBOL01,z,t)-Scherk(x,y,z,t))/0DOTSYMBOL01",
          "DFz=(Scherk(x,y,z+0DOTSYMBOL01,t)-Scherk(x,y,z,t))/0DOTSYMBOL01",
          "Rapport2=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
          "Iso3=(Scherk(x-DFx(x,y,z,t)*th/Rapport2(x,y,z,t),y-DFy(x,y,z,t)*th/Rapport2(x,y,z,t),z-DFz(x,y,z,t)*th/Rapport2(x,y,z,t),t))",
          "Iso2=(Scherk(x+DFx(x,y,z,t)*th/Rapport2(x,y,z,t),y+DFy(x,y,z,t)*th/Rapport2(x,y,z,t),z+DFz(x,y,z,t)*th/Rapport2(x,y,z,t),t))",
          "TickScherk=(Iso2(x,y,z,t)*Iso3(x,y,z,t))",
          "ScherkTorus=if(sqrt(x*x+y*y)<3DOTSYMBOL2, TickScherk(x,y,z,t),1)",
          "Torus = ScherkTorus( (sqrt(x*x+z*z)-R) , y,  N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-Torus(x,z,y,t)"
        ],
        "Xmax": [
          " 11"
        ],
        "Xmin": [
          "-11 "
        ],
        "Ymax": [
          " 11"
        ],
        "Ymin": [
          "-11 "
        ],
        "Zmax": [
          " 3DOTSYMBOL5"
        ],
        "Zmin": [
          "-3DOTSYMBOL5"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Scherk Torus 01 by Abderrahman Taha 22/02/2017"
        ],
        "Name": [
          "ScherkTorus_01"
        ],
        "Component": [
          "Scherk"
        ],
        "Const": [
          "N=10",
          "R=8"
        ],
        "Funct": [
          "Scherk0=-((x*y-z)*(x*y-z)-0DOTSYMBOL4)",
          "Scherk1=if(abs(x)<3 & abs(y)<3, Scherk0(sinh(x),sinh(y),sin(z),t), 0)",
          "Scherk2=Scherk1(x*cos(t)-y*sin(t),x*sin(t)+y*cos(t),z,t)",
          "Torus = Scherk2( (sqrt(x*x+z*z)-R) , y,  N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "Torus(x,y,z,t)"
        ],
        "Xmax": [
          " 11"
        ],
        "Xmin": [
          "-11 "
        ],
        "Ymax": [
          " 3DOTSYMBOL5"
        ],
        "Ymin": [
          "-3DOTSYMBOL5 "
        ],
        "Zmax": [
          " 11"
        ],
        "Zmin": [
          "-11 "
        ]
      }
    },
    {
      "Param3D": {
        "Description": [
          "Twisted Strip by Abderrahman Taha 11/05/2016"
        ],
        "Name": [
          "Twisted Strip"
        ],
        "Component": [
          "TwistedStrip"
        ],
        "Fx": [
          "cos(v)+1DOTSYMBOL4*u*cos(6*v+5*sin(t+v))*cos(v)"
        ],
        "Fy": [
          "sin(v)+1DOTSYMBOL4*u*cos(6*v+5*sin(t+v))*sin(v)"
        ],
        "Fz": [
          "1DOTSYMBOL4*u*sin(6*v+5*sin(t+v))"
        ],
        "Umax": [
          "0DOTSYMBOL4"
        ],
        "Umin": [
          "-0DOTSYMBOL4"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description": [
          "Blobby Torus by Abderrahman Taha 09/05/2016"
        ],
        "Name": [
          "Blobby Torus"
        ],
        "Component": [
          "BlobbyTorus"
        ],
        "Funct": [
          "G1=(8+(sin(2*(u-v+t+sin(v-u))) +3)*cos(u))*cos(v)",
          "G2=(8+(sin(2*(u-v+t+sin(v-u))) +3)*cos(u))*sin(v)",
          "G3=((sin(2*(u-v+t+sin(v-u))) +3)*sin(u))"
        ],
        "Fx": [
          "-G1(u,v,t)"
        ],
        "Fy": [
          "G2(u,v,t)"
        ],
        "Fz": [
          "G3(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R= if(abs(7*u)%pi/2& abs(7*v)%pi/3,0DOTSYMBOL6,1) ",
          "G= if(abs(7*u)%pi/2| abs(7*v)%pi/3,0DOTSYMBOL8,0DOTSYMBOL4) ",
          "B= if(abs(7*u)%pi/2| abs(7*v)%pi/3,0DOTSYMBOL6,0DOTSYMBOL1) ",
          "T=1"
        ],
        "Name": "Candy",
        "Noise": "1"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Tori of Helices by Abderrahman Taha 07/05/2016"
        ],
        "Name": [
          "Tori of helices"
        ],
        "Component": [
          "TorHelices"
        ],
        "Const": [
          "Step1=5",
          "N1=8",
          "N2=8",
          "P1=10",
          "P2=16",
          "Param1 = 2",
          " Param2= 2",
          " Param3= 2",
          " Param4= 10",
          " Param5= 22",
          " Param6= 15",
          " Param7= 20",
          " Param8= 0"
        ],
        "Funct": [
          "Helix=-fhelix1(x,y,z,Param2,Param3,Param4/15,Param5/15,Param6/15,Param7/10,Param8*pi/15)",
          "Helix1 = Helix((abs(x+8*t)%Step1)-Step1/2,y+8*t,z,t)",
          "Cylinder2 = Helix1( N1*atan2(x,z)    , y ,   (sqrt(x*x+z*z)-P1)   ,t)",
          "Cylinder3 = Helix1( N1*atan2(x,z)    , y ,   (sqrt(x*x+z*z)-P1)   ,t)",
          "Torus3 = Cylinder2(  (sqrt(y*y+x*x)-P2)   ,   N2*atan2(x,y)  ,z,t)"
        ],
        "Fxyz": [
          "Torus3(x,y,z,t)"
        ],
        "Xmax": [
          " 28"
        ],
        "Xmin": [
          "-28"
        ],
        "Ymax": [
          " 28"
        ],
        "Ymin": [
          "-28"
        ],
        "Zmax": [
          " 12"
        ],
        "Zmin": [
          "-12"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Helical Tori by Abderrahman Taha 02/05/2016"
        ],
        "Name": [
          "Helical Tori"
        ],
        "Component": [
          "HelicalTori"
        ],
        "Const": [
          "M=1DOTSYMBOL3",
          "N1=8",
          "N2=8",
          "P=8DOTSYMBOL5",
          "R=14DOTSYMBOL5"
        ],
        "Funct": [
          "Diamond=sin(x)*sin(y)*sin(z)-sin(x)*cos(y)*cos(z)-0DOTSYMBOL5*cos(x)*sin(y)*cos(z)",
          "isoTransform=if(x*x<4DOTSYMBOL84,-Diamond(x,y,z+8*t,t),1)+M*exp(x*x-2DOTSYMBOL56)",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-P),y,N1*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-R),N2*atan2(y,x),z/1DOTSYMBOL5,t)"
        ],
        "Xmax": [
          "25"
        ],
        "Xmin": [
          "-25"
        ],
        "Ymax": [
          "25"
        ],
        "Ymin": [
          "-25"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Tori of Octahedra v02 by Abderrahman Taha 07/03/2017"
        ],
        "Name": [
          "ToriofOctahedra"
        ],
        "Component": [
          "TorOctahedra"
        ],
        "Const": [
          "Step1=7",
          "Step2=7",
          "N1=20",
          "N2=30",
          "P1=25",
          "P2=40",
          "R00=10"
        ],
        "Funct": [
          "Octahedra=(abs(x)+abs(y)+abs(z))-3DOTSYMBOL8*R00/100",
          "Octahedra1 = Octahedra(x,y,(abs(z)%(Step1/10))-Step1/20,t)",
          "Octahedra2 = -Octahedra1((abs(x+2*t)%(Step2/10))-Step2/20,y,z+2*t,t)",
          "Cylinder2 = Octahedra2(x, (sqrt(y*y+z*z)-P1/10),N1*atan2(y,z)/10,t)",
          "Torus3 = Cylinder2(N2*atan2(x,y)/10, (sqrt(y*y+x*x)-P2/10),z,t)"
        ],
        "Fxyz": [
          "Torus3(x,y,z,t)"
        ],
        "Xmax": [
          " ((P1+P2)/10 + R00/25)"
        ],
        "Xmin": [
          "-((P1+P2)/10 + R00/25)"
        ],
        "Ymax": [
          " ((P1+P2)/10 + R00/25)"
        ],
        "Ymin": [
          "-((P1+P2)/10 + R00/25)"
        ],
        "Zmax": [
          " (P1/10 + R00/25)"
        ],
        "Zmin": [
          "-(P1/10 + R00/25)"
        ]
      },
      "Sliders": {
        "Max": [
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50",
          "50"
        ],
        "Min": [
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0"
        ],
        "Name": [
          "N1",
          "N2",
          "P1",
          "P2",
          "R00"
        ],
        "Position": [
          "20",
          "30",
          "25",
          "40",
          "10",
          "15",
          "12",
          "45",
          "40",
          "10",
          "0",
          "29",
          "25",
          "38",
          "14",
          "13",
          "10",
          "50",
          "38",
          "14",
          "12",
          "21",
          "50",
          "50",
          "15"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Tori of Spheres by Abderrahman Taha 05/05/2016"
        ],
        "Name": [
          "Tori of Spheres"
        ],
        "Component": [
          "TorSpheres"
        ],
        "Const": [
          "Step1=0DOTSYMBOL7",
          "Step2=0DOTSYMBOL7",
          "M=1DOTSYMBOL3",
          "N1=2",
          "N2=3DOTSYMBOL01",
          "P1=2DOTSYMBOL5",
          "P2=4",
          "R00=0DOTSYMBOL1",
          "R01=0DOTSYMBOL24"
        ],
        "Funct": [
          "Sphere = (x*x+y*y+ z*z-R00)",
          "Sphere1 = Sphere(x,y,(abs(z)%Step1)-Step1/2,t)",
          "Sphere2 = -Sphere1((abs(x+2*t)%Step2)-Step2/2,y,z+2*t,t)",
          "Cylinder2 = Sphere2(x, (sqrt(y*y+z*z)-P1),N1*atan2(y,z),t)",
          "Torus3 = Cylinder2(N2*atan2(x,y), (sqrt(y*y+x*x)-P2),z,t)"
        ],
        "Fxyz": [
          "Torus3(x,y,z,t)"
        ],
        "Xmax": [
          " 7"
        ],
        "Xmin": [
          "-7"
        ],
        "Ymax": [
          " 7"
        ],
        "Ymin": [
          "-7"
        ],
        "Zmax": [
          " 3"
        ],
        "Zmin": [
          "-3"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Tori of Toris by Abderrahman Taha 05/05/2016"
        ],
        "Name": [
          "Tori of Toris"
        ],
        "Component": [
          "TorToris"
        ],
        "Const": [
          "Step1=0DOTSYMBOL6",
          "Step2=1",
          "M=1DOTSYMBOL3",
          "N1=2",
          "N2=3DOTSYMBOL5",
          "P1=2",
          "P2=4",
          "R00=0DOTSYMBOL04",
          "R01=0DOTSYMBOL24"
        ],
        "Funct": [
          "Torus0 = (sqrt(x*x+y*y)-R01)^2 + z*z - R00",
          "Torus1 = Torus0(x,y,(abs(z)%Step1)-Step1/2,t)",
          "Torus2 = -Torus1((abs(x+t)%Step2)-Step2/2,y,z+t,t)",
          "Cylinder = Torus2(N1*atan2(y,x),(sqrt(x*x+y*y)-P1) ,z,t)",
          "Cylinder2 = Torus2(x, (sqrt(y*y+z*z)-P1),N1*atan2(y,z),t)",
          "Torus3 = Cylinder2(N2*atan2(x,y), (sqrt(y*y+x*x)-P2),z,t)"
        ],
        "Fxyz": [
          "Torus3(x,y,z,t)"
        ],
        "Xmax": [
          " 7"
        ],
        "Xmin": [
          "-7"
        ],
        "Ymax": [
          " 7"
        ],
        "Ymin": [
          "-7"
        ],
        "Zmax": [
          " 3"
        ],
        "Zmin": [
          "-3"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Animated Diamond Tori-2.0 by Abderrahman Taha 02/05/2016"
        ],
        "Name": [
          "Animated Diamond Tori"
        ],
        "Component": [
          "Diamond Tori"
        ],
        "Const": [
          "M=1DOTSYMBOL3",
          "N1=8",
          "N2=10",
          "P=8DOTSYMBOL5",
          "R=14DOTSYMBOL5"
        ],
        "Funct": [
          "Diamond=sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
          "isoCondition_0=(x^2-2DOTSYMBOL2^2)",
          "isoCondition_1=(x^2-1DOTSYMBOL6^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,-Diamond(x,y+8*t,1DOTSYMBOL5*z+10*t,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-P),y,N1*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-R),N2*atan2(y,x),z/1DOTSYMBOL5,t)"
        ],
        "Xmax": [
          "25"
        ],
        "Xmin": [
          "-25"
        ],
        "Ymax": [
          "25"
        ],
        "Ymin": [
          "-25"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Animated Bone Cage model by Abderrahman Taha 01/05/2016"
        ],
        "Name": [
          "Animated Bone Cage"
        ],
        "Component": [
          "BoneCage"
        ],
        "Const": [
          "M=1",
          "N1=13",
          "N2=10",
          "P=5",
          "R=15"
        ],
        "Funct": [
          "P_Skeletal0=-y-z+0DOTSYMBOL51*(-x*y+y*z+z*x)+1DOTSYMBOL2",
          "P_Skeletal=sin(x)+P_Skeletal0(cos(x), cos(y), cos(z), t)",
          "isoTransform=if((x-pi)*(x-pi)<13DOTSYMBOL25,P_Skeletal(x,y-4*t,z-20*t,t),1)+M*exp((x-pi)*(x-pi)-9DOTSYMBOL86)",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-P),y,N1*atan2(z,x),t)",
          "isoTransform3=isoTransform2(x*cos(y/N1)-z*sin(y/N1),y,x*sin(y/N1)+z*cos(y/N1),t)"
        ],
        "Fxyz": [
          "-isoTransform3((sqrt(x*x+y*y)-R),N2*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "30"
        ],
        "Xmin": [
          "-30"
        ],
        "Ymax": [
          "30"
        ],
        "Ymin": [
          "-30"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Schwarz P Tori-3.0 by Abderrahman Taha 29/04/2016"
        ],
        "Name": [
          "Schwarz P Tori_3"
        ],
        "Component": [
          "Schwarz P Tori"
        ],
        "Const": [
          "M=1",
          "N1=10",
          "N2=10",
          "R1=8",
          "R2=15",
          "H=4"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
          "R=0DOTSYMBOL1*H*x/sqrt(x*x+y*y+z*z)",
          "Iso4= (Iso(x+R(sin(x),sin(y),sin(z),t),y+R(sin(y),sin(x),sin(z),t), z+R(sin(z),sin(y),sin(x),t),t))",
          "Iso5= (Iso(x-R(sin(x),sin(y),sin(z),t),y-R(sin(y),sin(x),sin(z),t), z-R(sin(z),sin(y),sin(x),t),t))",
          "SchwarzP= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoTransform=if(x*x<10DOTSYMBOL24,SchwarzP(x,y-2*t,z-3*t,t),1)+0DOTSYMBOL1*M*exp(x*x-9)",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-R1),y,N1*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-R2),N2*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "27"
        ],
        "Xmin": [
          "-27"
        ],
        "Ymax": [
          "27"
        ],
        "Ymin": [
          "-27"
        ],
        "Zmax": [
          "12"
        ],
        "Zmin": [
          "-12"
        ]
      }
    },
    {
      "Iso3D": {
        "Description ": [
          "Red giant by Abderrahman Taha 29/04/2016"
        ],
        "Name": [
          "Red giant"
        ],
        "Component": [
          "Redgiant"
        ],
        "Fxyz": [
          "-((x*x+y*y+z*z-1)+(if(t<pi/2, 1,5*  if(t<pi,  abs(sin(t-pi/2)), abs(sin(3*t-pi/2))) ))*(NoiseW(6*x,6*y,5*cos(t)+6*z,4,2,0)  +NoiseW(4*sin(t)+6*x,5*cos(t) + 6*y,6*z,4,0,0))/5)*( atan2(y,x)<(pi/2) | atan2(sqrt(x*x+y*y),z)>(pi/2)) *(x^2+y^2+z^2-3/100)"
        ],
        "Xmax": [
          "1"
        ],
        "Xmin": [
          "-1"
        ],
        "Ymax": [
          "1"
        ],
        "Ymin": [
          "-1"
        ],
        "Zmax": [
          "1"
        ],
        "Zmin": [
          "-1"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL6",
          "G=2DOTSYMBOL4*(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))*sin((x*x+y*y+z*z)/2)",
          "B=0DOTSYMBOL7*(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(2*x,2*y,2*z,4,0,0)+NoiseW(2*x,2*y,2*z,2,0,0)"
      }
    },
    {
      "Iso3D": {
        "Component": [
          "PrettyBall_1"
        ],
        "Description": [
          "PrettyBall_2 by Abderrahman Taha 28/10/2015"
        ],
        "Fxyz": [
          "if( (x)*(x)+y*y+z*z<64 ,(cos(x-t)*Siny+Cosy*Sinz+Cosz*sin(x-t)) * (cos(x-t)*Siny+Cosy*Sinz+Cosz*sin(x-t)) -0DOTSYMBOL6 ,1)  + exp(((x)*(x)+y*y+z*z-64)/3)"
        ],
        "Name": [
          "Pretty Ball"
        ],
        "Varu": [
          "Cos = cos(u)",
          "Sin = sin(u)"
        ],
        "Xmax": [
          "8"
        ],
        "Xmin": [
          "-8"
        ],
        "Ymax": [
          "8"
        ],
        "Ymin": [
          "-8"
        ],
        "Zmax": [
          "8"
        ],
        "Zmin": [
          "-8"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL73",
          "G=1DOTSYMBOL8*abs(cos((x*x+y*y+z*z)/2DOTSYMBOL3) *sin((x*x+y*y+z*z)/2DOTSYMBOL3))",
          "B=2*abs(cos((x*x+y*y+z*z)/2DOTSYMBOL3) *cos((x*x+y*y+z*z)/2DOTSYMBOL3) *sin((x*x+y*y+z*z)/2DOTSYMBOL3))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "0DOTSYMBOL5*NoiseW(x,y,z,4,2,0)"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "P_Skeletal Sphere by Abderrahman Taha 08/12/2015"
        ],
        "Name": [
          "P_Skeletal Sphere_3"
        ],
        "Component": [
          "P_Skeletal Sphere"
        ],
        "Const": [
          "M=1",
          "N=4",
          "P=10",
          "R=13",
          "S=51",
          "T=12"
        ],
        "Funct": [
          "P_Skeletal=x+y+z+(S/100)*(x*y+y*z+x*z)+(T/10)",
          "isoTransform=if(x*(x-2*pi)<0,P_Skeletal(cos(x), cos(y), cos(z), t),1)+M*exp(x*(x-2*pi))"
        ],
        "Fxyz": [
          "-isoTransform((sqrt(x*x+y*y+z*z)-R), P*atan2(y,x), N*pi*atan2(z, sqrt(x*x+y*y)), t)"
        ],
        "Xmax": [
          "19"
        ],
        "Xmin": [
          "-19"
        ],
        "Ymax": [
          "19"
        ],
        "Ymin": [
          "-19"
        ],
        "Zmax": [
          "19"
        ],
        "Zmin": [
          "-19"
        ]
      },
      "Sliders": {
        "Max": [
          "50",
          "50",
          "30",
          "30",
          "100",
          "50",
          "50",
          "50",
          "30",
          "30",
          "100",
          "50",
          "50",
          "50",
          "30",
          "30",
          "100",
          "50",
          "50",
          "50",
          "30",
          "30",
          "100",
          "50"
        ],
        "Min": [
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0"
        ],
        "Name": [
          "M",
          "N",
          "P",
          "R",
          "S",
          "T"
        ],
        "Position": [
          "1",
          "4",
          "10",
          "13",
          "51",
          "12",
          "10",
          "4",
          "10",
          "13",
          "63",
          "12",
          "10",
          "4",
          "6",
          "12",
          "0",
          "9",
          "6",
          "2",
          "5",
          "13",
          "32",
          "13"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Param3D": {
        "Description": [
          "Original Klein Bottle formula from http://www.gnuplotting.org/klein-bottle/ . Implemented by Abderrahman Taha 03/04/2016"
        ],
        "Name": [
          "Klein_4"
        ],
        "Component": [
          "Klein"
        ],
        "Funct": [
          "tx=if(v<2*pi, (A-(A-1)*cos(v))*cos(u),if(v<3*pi, -B+(B+cos(u))*cos(v),-B+B*cos(v)-cos(u)))",
          "ty=if(v<2*pi,(A-(A-1)*cos(v))*sin(u), sin(u))",
          "tz=if(v<pi, -C*sin(v), if(v<2*pi, D*v-D*pi, if(v<3*pi,((D-1)+cos(u))*sin(v)+D*pi,-D*v+D*4*pi  )))"
        ],
        "Fx": [
          "tx(u,v,t)"
        ],
        "Fy": [
          "-ty(u,v,t)"
        ],
        "Fz": [
          "-tz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "4*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Sliders": {
        "Max": [
          "20",
          "20",
          "20",
          "20",
          "20",
          "20",
          "20",
          "20",
          "20",
          "20",
          "20",
          "20",
          "20",
          "20",
          "20",
          "20"
        ],
        "Min": [
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0"
        ],
        "Name": [
          "A",
          "B",
          "C",
          "D"
        ],
        "Position": [
          "3",
          "2",
          "3",
          "3",
          "5",
          "3",
          "0",
          "3",
          "3",
          "0",
          "9",
          "3",
          "7",
          "6",
          "10",
          "3"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Schwarz P Sphere  by Abderrahman Taha 29/03/2016"
        ],
        "Name": [
          "Schwarz P Sphere_3"
        ],
        "Component": [
          "SchwarzPSphere"
        ],
        "Const": [
          "M=1",
          "N=10",
          "P=10",
          "th=4"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
          "Iso2=th*x/(10*sqrt(x*x+y*y+z*z))",
          "Iso4=Iso(x+Iso2(sin(x), sin(y), sin(z),t),y+Iso2(sin(y), sin(x), sin(z),t),z+Iso2(sin(z), sin(y), sin(x),t),t)",
          "Iso5=Iso(x-Iso2(sin(x), sin(y), sin(z),t),y-Iso2(sin(y), sin(x), sin(z),t),z-Iso2(sin(z), sin(y), sin(x),t),t)",
          "SchwarzP= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoTransform=if(x*x<16,SchwarzP(x,y,z,t),1)+M*exp(x*x-14)",
          "SchwarzPSphere = -isoTransform((sqrt(x*x+y*y+z*z)-9),P*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "SchwarzPSphere(x,z,y,t)"
        ],
        "Xmax": [
          "13"
        ],
        "Xmin": [
          "-13"
        ],
        "Ymax": [
          "13"
        ],
        "Ymin": [
          "-13"
        ],
        "Zmax": [
          "13"
        ],
        "Zmin": [
          "-13"
        ]
      },
      "Sliders": {
        "Max": [
          "20",
          "20",
          "20",
          "10",
          "20",
          "20",
          "20",
          "10",
          "20",
          "20",
          "20",
          "10"
        ],
        "Min": [
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0"
        ],
        "Name": [
          "M",
          "N",
          "P",
          "th"
        ],
        "Position": [
          "10",
          "10",
          "10",
          "4",
          "1",
          "12",
          "7",
          "4",
          "1",
          "5",
          "3",
          "4"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Multi-sided Torus by Abderrahman Taha (Update) 01/03/2017"
        ],
        "Name": [
          "Multi-sided Torus_4"
        ],
        "Component": [
          "MultiSidedTorus "
        ],
        "Const": [
          "N=9",
          "R3=3",
          "R=15"
        ],
        "Funct": [
          "F1 = (R3 + (R/(10*N))*cos(u/N+((R/(10*N))-R/10)/(R/(10*N))*v)+(R/10-(R/(10*N)))*cos(u/N+v))",
          "F2 = ((R/(10*N))*sin(u/N+((R/(10*N))-R/10)/(R/(10*N))*v)+(R/10-(R/(10*N)))*sin(u/N+v))"
        ],
        "Fx": [
          "-sin(u)*F1(u+t,v,t)"
        ],
        "Fy": [
          "cos(u)*F1(u+t,v,t) "
        ],
        "Fz": [
          "F2(u+t,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "-pi"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      },
      "Sliders": {
        "Max": [
          "30",
          "30",
          "50"
        ],
        "Min": [
          "1",
          "1",
          "1"
        ],
        "Name": [
          "N",
          "R3",
          "R"
        ],
        "Position": [
          "9",
          "3",
          "15"
        ],
        "Step": [
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Multi-sided Torus by Abderrahman Taha 27/03/2016"
        ],
        "Name": [
          "Multi-sided Torus_5"
        ],
        "Component": [
          "MultiSidedTorus "
        ],
        "Const": [
          "N=9",
          "R3=3",
          "R=15"
        ],
        "Funct": [
          "F1 = (R3 + (R/(10*N))*cos(u/N+((R/(10*N))-R/10)/(R/(10*N))*v)+(R/10-(R/(10*N)))*sin(u/N+v))",
          "F2 = ((R/(10*N))*sin(u/N+((R/(10*N))-R/10)/(R/(10*N))*v)+(R/10-(R/(10*N)))*cos(u/N+v))"
        ],
        "Fx": [
          "sin(u)*F1(u,v,t)"
        ],
        "Fy": [
          "cos(u)*F1(u,v,t) "
        ],
        "Fz": [
          "F2(u,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "-pi"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      },
      "Sliders": {
        "Max": [
          "30",
          "30",
          "50"
        ],
        "Min": [
          "1",
          "1",
          "1"
        ],
        "Name": [
          "N",
          "R3",
          "R"
        ],
        "Position": [
          "9",
          "3",
          "15"
        ],
        "Step": [
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Under Sea by Abderrahman Taha 25/03/2016"
        ],
        "Name": [
          "Under The Sea_03"
        ],
        "Component": [
          "UnderSea"
        ],
        "Const": [
          "M=9",
          "N=6",
          "A=5"
        ],
        "Fx": [
          "u*cos(v)"
        ],
        "Fy": [
          "u*sin(v)"
        ],
        "Fz": [
          "A*exp(-u*u) * (sin(M*pi*(u)/3) -u*cos(N*v))/5"
        ],
        "Umax": [
          "2"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=(61/100)",
          "G=(162/100)*abs(cos((x*x+y*y+z*z)/2) *sin((x*x+y*y+z*z)/2))",
          "B=(172/100)*abs(cos((x*x+y*y+z*z)/2) *cos((x*x+y*y+z*z)/2) *sin((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(4*x,4*y,4*z,4,2,0) +NoiseW(4*x,4*y,4*z,4,12,0)"
      },
      "Sliders": {
        "Max": [
          "30",
          "30",
          "30",
          "30",
          "30",
          "30",
          "30",
          "30",
          "30"
        ],
        "Min": [
          "0",
          "0",
          "1",
          "0",
          "0",
          "1",
          "0",
          "0",
          "1"
        ],
        "Name": [
          "M",
          "N",
          "A"
        ],
        "Position": [
          "9",
          "6",
          "4",
          "9",
          "1",
          "4",
          "20",
          "3",
          "3"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Param3D": {
        "Description": [
          "Super Formula by Abderrahman Taha 12/03/2016"
        ],
        "Name": [
          "Super Formula"
        ],
        "Cnd": [
          "sqrt(x*x+y*y)>S"
        ],
        "Component": [
          "SuperFormula"
        ],
        "Const": [
          "A1=50",
          "B1=1",
          "M1=9",
          "N11=25",
          "N21=1DOTSYMBOL7",
          "N31=1DOTSYMBOL7",
          "A2=50",
          "B2=1",
          "M2=9",
          "N12=20",
          "N22=1DOTSYMBOL7",
          "N32=1DOTSYMBOL7",
          "S=0DOTSYMBOL41"
        ],
        "Funct": [
          "Ru=(abs(cos(M1*u/4)*50/A1)^N21+abs(sin(M1*u/4)*50/B1)^N31)^(-100/N11)",
          "Rv=(abs(cos(M2*v/4)*50/A2)^N22+abs(sin(M2*v/4)*50/B2)^N32)^(-100/N12)"
        ],
        "Fx": [
          "-cos(u)*cos(v)*Ru(u,v,t)*Rv(u,v,t)"
        ],
        "Fy": [
          "cos(u)*sin(v)*Ru(u,v,t)*Rv(u,v,t)"
        ],
        "Fz": [
          "sin(u)*Ru(u,v,t)"
        ],
        "Umax": [
          "pi/2"
        ],
        "Umin": [
          "-pi/2"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Sliders": {
        "Max": [
          "100",
          "100",
          "100",
          "100",
          "20",
          "20",
          "100",
          "100",
          "100",
          "100",
          "100",
          "100",
          "20",
          "20",
          "100",
          "100",
          "100",
          "100",
          "100",
          "100",
          "20",
          "20",
          "100",
          "100",
          "100",
          "100",
          "100",
          "100",
          "20",
          "20",
          "100",
          "100",
          "100",
          "100",
          "100",
          "100",
          "20",
          "20",
          "100",
          "100",
          "100",
          "100",
          "100",
          "100",
          "20",
          "20",
          "100",
          "100",
          "100",
          "100",
          "100",
          "100",
          "20",
          "20",
          "100",
          "100"
        ],
        "Min": [
          "1",
          "1",
          "1",
          "1",
          "0",
          "0",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "0",
          "0",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "0",
          "0",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "0",
          "0",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "0",
          "0",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "0",
          "0",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "0",
          "0",
          "1",
          "1"
        ],
        "Name": [
          "A1",
          "A2",
          "B2",
          "B1",
          "M1",
          "M2",
          "N11",
          "N12"
        ],
        "Position": [
          "50",
          "50",
          "50",
          "50",
          "9",
          "9",
          "20",
          "20",
          "54",
          "47",
          "44",
          "51",
          "8",
          "10",
          "16",
          "51",
          "52",
          "45",
          "53",
          "38",
          "15",
          "16",
          "39",
          "84",
          "55",
          "55",
          "55",
          "58",
          "10",
          "17",
          "44",
          "100",
          "54",
          "53",
          "75",
          "48",
          "8",
          "10",
          "16",
          "51",
          "54",
          "48",
          "56",
          "56",
          "16",
          "16",
          "100",
          "100",
          "50",
          "53",
          "61",
          "46",
          "7",
          "10",
          "29",
          "46"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "The Dome-2.0 by Abderrahman Taha 27/02/2016"
        ],
        "Name": [
          "The Dome-02"
        ],
        "Component": [
          "Dome"
        ],
        "Cnd": [
          "sqrt(x*x+y*y+z*z)>S/3"
        ],
        "Const": [
          "A=4",
          "N1=10",
          "N2=10",
          "R=16"
        ],
        "Funct": [
          "Scherk=sinh(x)*sinh(y)-A*sin(z)",
          "Scherk2=Scherk(N1*atan2(x,sqrt(y*y+z*z)),(sqrt(x*x+y*y+z*z)-R),N2*atan2(z,y),t)"
        ],
        "Fxyz": [
          "-Scherk2(z,y,x,t)"
        ],
        "Xmax": [
          "27"
        ],
        "Xmin": [
          "-27"
        ],
        "Ymax": [
          "27"
        ],
        "Ymin": [
          "-27"
        ],
        "Zmax": [
          "18"
        ],
        "Zmin": [
          "-18"
        ]
      },
      "Sliders": {
        "Max": [
          "20",
          "30",
          "30",
          "30",
          "100",
          "20",
          "30",
          "30",
          "30",
          "100",
          "20",
          "30",
          "30",
          "30",
          "100"
        ],
        "Min": [
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0"
        ],
        "Name": [
          "A",
          "N1",
          "N2",
          "R",
          "S"
        ],
        "Position": [
          "4",
          "10",
          "10",
          "16",
          "63",
          "4",
          "1",
          "7",
          "16",
          "44",
          "4",
          "2",
          "9",
          "15",
          "73"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Schwarz P Tori-1.0 by Abderrahman Taha 25/02/2016"
        ],
        "Name": [
          "Schwarz P Tori-1.0"
        ],
        "Component": [
          "Schwarz P Tori"
        ],
        "Const": [
          "M=1",
          "N1=15",
          "N2=15",
          "R1=8",
          "R2=15",
          "H=4"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
          "R=0DOTSYMBOL1*H*x/sqrt(x*x+y*y+z*z)",
          "Iso4= (Iso(x+R(sin(x),sin(y),sin(z),t),y+R(sin(y),sin(x),sin(z),t), z+R(sin(z),sin(y),sin(x),t),t))",
          "Iso5= (Iso(x-R(sin(x),sin(y),sin(z),t),y-R(sin(y),sin(x),sin(z),t), z-R(sin(z),sin(y),sin(x),t),t))",
          "SchwarzP= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoTransform=if(x*x<10DOTSYMBOL24,SchwarzP(x,y,z,t),1)+0DOTSYMBOL1*M*exp(x*x-9)",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-R1),y,N1*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-R2),N2*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "27"
        ],
        "Xmin": [
          "-27"
        ],
        "Ymax": [
          "27"
        ],
        "Ymin": [
          "-27"
        ],
        "Zmax": [
          "12"
        ],
        "Zmin": [
          "-12"
        ]
      },
      "Sliders": {
        "Max": [
          "20",
          "20",
          "20",
          "15",
          "25",
          "30",
          "20",
          "20",
          "20",
          "15",
          "25",
          "30",
          "20",
          "20",
          "20",
          "15",
          "25",
          "30"
        ],
        "Min": [
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0"
        ],
        "Name": [
          "H",
          "N1",
          "N2",
          "R1",
          "R2",
          "M"
        ],
        "Position": [
          "4",
          "15",
          "15",
          "8",
          "15",
          "1",
          "4",
          "3",
          "13",
          "8",
          "16",
          "0",
          "5",
          "7",
          "9",
          "8",
          "16",
          "0"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Diamond Tori-2.0 by Abderrahman Taha 24/02/2016"
        ],
        "Name": [
          "Diamond Tori_2"
        ],
        "Component": [
          "Diamond Tori"
        ],
        "Const": [
          "M=1",
          "N1=10",
          "N2=10",
          "P=5",
          "R=15"
        ],
        "Funct": [
          "Diamond=sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
          "isoCondition_0=(x^2-2DOTSYMBOL2^2)",
          "isoCondition_1=(x^2-1DOTSYMBOL6^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,-Diamond(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-P),y,N1*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-R),N2*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "25"
        ],
        "Xmin": [
          "-25"
        ],
        "Ymax": [
          "25"
        ],
        "Ymin": [
          "-25"
        ],
        "Zmax": [
          "10DOTSYMBOL5"
        ],
        "Zmin": [
          "-10DOTSYMBOL5"
        ]
      },
      "Sliders": {
        "Max": [
          "50",
          "10",
          "25",
          "25",
          "25",
          "50",
          "10",
          "25",
          "25",
          "25",
          "50",
          "10",
          "25",
          "25",
          "25"
        ],
        "Min": [
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0"
        ],
        "Name": [
          "M",
          "P",
          "R",
          "N1",
          "N2"
        ],
        "Position": [
          "1",
          "7",
          "16",
          "10",
          "12",
          "1",
          "7",
          "16",
          "3",
          "11",
          "5",
          "9",
          "14",
          "7",
          "1"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "P_Skeletal Tori-2.0 by Abderrahman Taha 22/02/2016"
        ],
        "Name": [
          "P_Skeletal Tori_2"
        ],
        "Component": [
          "P_Skeletal Tori"
        ],
        "Const": [
          "M=1",
          "N1=15",
          "N2=15",
          "P=5",
          "R=15"
        ],
        "Funct": [
          "P_Skeletal=cos(x)+cos(y)+cos(z)+0DOTSYMBOL51*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+1DOTSYMBOL2",
          "isoCondition_0=((x-pi)^2-(pi +0DOTSYMBOL05)^2)",
          "isoCondition_1=((x-pi)^2-(pi)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,P_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-P),y,N1*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-R),N2*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "30"
        ],
        "Xmin": [
          "-30"
        ],
        "Ymax": [
          "30"
        ],
        "Ymin": [
          "-30"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      },
      "Sliders": {
        "Max": [
          "50",
          "10",
          "25",
          "25",
          "25",
          "50",
          "10",
          "25",
          "25",
          "25",
          "50",
          "10",
          "25",
          "25",
          "25",
          "50",
          "10",
          "25",
          "25",
          "25"
        ],
        "Min": [
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0",
          "0"
        ],
        "Name": [
          "M",
          "P",
          "R",
          "N1",
          "N2"
        ],
        "Position": [
          "1",
          "5",
          "15",
          "15",
          "15",
          "10",
          "7",
          "18",
          "3",
          "11",
          "0",
          "5",
          "19",
          "4",
          "14",
          "33",
          "8",
          "18",
          "2",
          "11"
        ],
        "Step": [
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1",
          "1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description ": [
          "Fhelix internal function with sliders by Abderrahman Taha 06/02/2016"
        ],
        "Name": [
          "fhelix"
        ],
        "Component": [
          "fhelix1"
        ],
        "Fxyz": [
          "-fhelix1(sqrt(x*x+y*y)-3,Param1*atan2(y,x),z,Param2,Param3,Param4/15,Param5/15,Param6/15,Param7/10,Param8*pi/15)"
        ],
        "Xmax": [
          "5"
        ],
        "Xmin": [
          "-5"
        ],
        "Ymax": [
          "5"
        ],
        "Ymin": [
          "-5"
        ],
        "Zmax": [
          "2DOTSYMBOL2"
        ],
        "Zmin": [
          "-2DOTSYMBOL2"
        ]
      },
      "Sliders": {
        "Max": [
          "10",
          " 10",
          " 10",
          " 30",
          " 30",
          " 30",
          " 20",
          " 30",
          "10",
          " 10",
          " 10",
          " 30",
          " 30",
          " 30",
          " 20",
          " 30",
          "10",
          " 10",
          " 10",
          " 30",
          " 30",
          " 30",
          " 20",
          " 30",
          "10",
          " 10",
          " 10",
          " 30",
          " 30",
          " 30",
          " 20",
          " 30",
          "10",
          " 10",
          " 10",
          " 30",
          " 30",
          " 30",
          " 20",
          " 30"
        ],
        "Min": [
          "0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          "0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          "0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          "0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          "0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0",
          " 0"
        ],
        "Name": [
          "Param1",
          " Param2",
          " Param3",
          " Param4",
          " Param5",
          " Param6",
          " Param7",
          " Param8"
        ],
        "Position": [
          "2",
          "2",
          "2",
          "10",
          "22",
          "15",
          "20",
          "0",
          "2",
          "2",
          "2",
          "8",
          "24",
          "17",
          "10",
          "19",
          "2",
          "3",
          "2",
          "5",
          "9",
          "13",
          "7",
          "0",
          "2",
          "2",
          "2",
          "23",
          "9",
          "3",
          "20",
          "3",
          "2",
          "2",
          "2",
          "8",
          "22",
          "16",
          "0",
          "21"
        ],
        "Step": [
          "1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          "1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          "1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          "1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          "1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1",
          " 1"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Inka Star by Abderrahman Taha 06/02/2016"
        ],
        "Name": [
          "Inka Star"
        ],
        "Component": [
          "InkaStar"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=2"
        ],
        "Funct": [
          "Thickness= ((sin(15*u)*cos(15*u)))^5 + (sin(5*N*v))",
          "Fx=-cos(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
          "Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Strapped Torus (implicit version) by Abderrahman Taha 06/02/2016"
        ],
        "Name": [
          "Strapped Torus"
        ],
        "Component": [
          "Strapped Torus"
        ],
        "Const": [
          "A = 2",
          "B = 2",
          "C = 23/15",
          "D = 9/15",
          "E = 3/15",
          "F = 20/10",
          "G = 3*pi/15"
        ],
        "Funct": [
          "X = x",
          "Z = z",
          "r = sqrt(X(x,y,z,t) * X(x,y,z,t) + Z(x,y,z,t) * Z(x,y,z,t))",
          "X= if ((X(x,y,z,t) = 0) & (Z(x,y,z,t) = 0),         0DOTSYMBOL000001,X(x,y,z,t))",
          "th = atan2(Z(x,y,z,t), X(x,y,z,t))",
          "th = ((th(x,y,z,t) * A + y * B * A) % (2*pi))",
          "th = if (th(x,y,z,t) < 0,        th(x,y,z,t)+2*pi, th(x,y,z,t))",
          "Z = (th(x,y,z,t) - pi) / E / (B * A)",
          "X = r(x,y,z,t) - D",
          "Z = if ((F = 1 | G = 0)=0, X(x,y,z,t) * sin(G * pi/180) + Z(x,y,z,t) * cos(G * pi/180) , Z(x,y,z,t))",
          "X = if ((F = 1 | G = 0)=0, X(x,y,z,t) * cos(G * pi/180) - Z(x,y,z,t) * sin(G * pi/180) , X(x,y,z,t))",
          "r2 = if (F = 1,        sqrt(X(x,y,z,t) * X(x,y,z,t) + Z(x,y,z,t) * Z(x,y,z,t)),                if ((F = 0)=0,                        pow((pow(abs(X(x,y,z,t)), 2/F) + pow(abs(Z(x,y,z,t)), 2/F)), F * 0DOTSYMBOL5),                        if (abs(X(x,y,z,t)) > abs(Z(x,y,z,t)) ,                     abs(X(x,y,z,t)) ,   abs(Z(x,y,z,t))            )    )          )",
          "r3 = if((D + r(x,y,z,t)) < r2(x,y,z,t) , (D + r(x,y,z,t)) , r2(x,y,z,t))",
          "helix = (-C + r3(x,y,z,t))"
        ],
        "Fxyz": [
          "-helix(sqrt(x*x+y*y)-3,2*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "5"
        ],
        "Xmin": [
          "-5"
        ],
        "Ymax": [
          "5"
        ],
        "Ymin": [
          "-5"
        ],
        "Zmax": [
          "2"
        ],
        "Zmin": [
          "-2"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Spiky Fresnel-01 by Abderrahman Taha 5/02/2015"
        ],
        "Name": [
          "Spiky Fresnel"
        ],
        "Component": [
          "SpikyFresnel"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001"
        ],
        "Funct": [
          "Tickness= - 0DOTSYMBOL3*(abs(sin(25*u)*cos(27*v)))^(3*sin(17*u-15*v))^2",
          "Fx=(cos(u)*cos(v)/(-2DOTSYMBOL*sqrt(0DOTSYMBOL965/3DOTSYMBOL-0DOTSYMBOL935/3DOTSYMBOL*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0DOTSYMBOL941/6DOTSYMBOL+0DOTSYMBOL374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1DOTSYMBOL309/6DOTSYMBOL*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1DOTSYMBOL221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0DOTSYMBOL965/3DOTSYMBOL-0DOTSYMBOL935/3DOTSYMBOL*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3DOTSYMBOL)+0DOTSYMBOL8))",
          "Fy= sin(v)/(-2DOTSYMBOL*sqrt(0DOTSYMBOL965/3DOTSYMBOL-0DOTSYMBOL935/3DOTSYMBOL*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0DOTSYMBOL941/6DOTSYMBOL+0DOTSYMBOL374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1DOTSYMBOL309/6DOTSYMBOL*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1DOTSYMBOL221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0DOTSYMBOL965/3DOTSYMBOL-0DOTSYMBOL935/3DOTSYMBOL*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3DOTSYMBOL)+0DOTSYMBOL8)",
          "Fz= sin(u)*cos(v)/(-2DOTSYMBOL*sqrt(0DOTSYMBOL965/3DOTSYMBOL-0DOTSYMBOL935/3DOTSYMBOL*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0DOTSYMBOL941/6DOTSYMBOL+0DOTSYMBOL374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1DOTSYMBOL309/6DOTSYMBOL*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1DOTSYMBOL221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0DOTSYMBOL965/3DOTSYMBOL-0DOTSYMBOL935/3DOTSYMBOL*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3DOTSYMBOL)+0DOTSYMBOL8)",
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
          "Gx=Fx(u,v,t)+Tickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Tickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Tickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "-Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "pi/2"
        ],
        "Vmin": [
          "-pi/2"
        ]
      }
    },
    {
      "Param3D": {
        "Name": [
          "Exotic flower"
        ],
        "Component": [
          "ExoticFlower"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001"
        ],
        "Description ": [
          "Exotic flower-01 by Abderrahman Taha 30/1/2015"
        ],
        "Funct": [
          "Thickness= - 0DOTSYMBOL6*(abs(sin(15*u)*cos(15*v)))^(3*sin(7*u-5*v))^2",
          "Fx=-(cos(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u)))",
          "Fy=sin(v-u)/(sqrt(2DOTSYMBOL)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
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
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "-Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "The Dome-1DOTSYMBOL0 by Abderrahman Taha 12/01/2015"
        ],
        "Name": [
          "The Dome"
        ],
        "Component": [
          "Dome"
        ],
        "Const": [
          "cx=0DOTSYMBOL001",
          "cy=0DOTSYMBOL001",
          "cz=0DOTSYMBOL001"
        ],
        "Funct": [
          "Scherk=sinh(x)*sinh(y)-4*sin(z)",
          "Scherk2=Scherk(10*atan2(x,sqrt(y*y+z*z)),(sqrt(x*x+y*y+z*z)-16),10*atan2(z,y),t)",
          "Tickness2=( 0DOTSYMBOL6)",
          "IsoExterior=Scherk2(x,y,z,t)",
          "DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
          "DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
          "DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
          "Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
          "Iso3=(IsoExterior(x-DFx2(x,y,z,t)*Tickness2(x,y,z,t)/Rapport2(x,y,z,t),y-DFy2(x,y,z,t)*Tickness2(x,y,z,t)/Rapport2(x,y,z,t),z-DFz2(x,y,z,t)*Tickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
          "Iso2=(IsoExterior(x+DFx2(x,y,z,t)*Tickness2(x,y,z,t)/Rapport2(x,y,z,t),y+DFy2(x,y,z,t)*Tickness2(x,y,z,t)/Rapport2(x,y,z,t),z+DFz2(x,y,z,t)*Tickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
          "TickIsoExterior=(Iso2(x,y,z,t)*Iso3(x,y,z,t))"
        ],
        "Fxyz": [
          "if((sqrt(x*x+y*y+z*z)-24)<0,TickIsoExterior(x,y,z,t),1)"
        ],
        "Xmax": [
          "18"
        ],
        "Xmin": [
          "-18"
        ],
        "Ymax": [
          "27"
        ],
        "Ymin": [
          "-27"
        ],
        "Zmax": [
          "27"
        ],
        "Zmin": [
          "-27"
        ]
      }
    },
    {
      "Iso3D": {
        "Name": [
          "Wall Pattern Torus-03"
        ],
        "Description": [
          "Wall Pattern Torus-03 by Abderrahman Taha 10/01/2016"
        ],
        "Component": [
          "f_hex_y"
        ],
        "Funct": [
          "x1=abs((abs(x) % sqrt(3DOTSYMBOL0))-sqrt(3DOTSYMBOL0)/2)",
          "y1 = abs((abs(y) % 3)-1DOTSYMBOL5)",
          "x2=sqrt(3DOTSYMBOL0)/2-x1(x,y,z,t)",
          "y2=1DOTSYMBOL5-y1(x,y,z,t)",
          "x1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), x2(x,y,z,t), x1(x,y,z,t))",
          "y1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), y2(x,y,z,t), y1(x,y,z,t))",
          "th=atan2(y1(x,y,z,t),x1(x,y,z,t))",
          "th = if (th(x,y,z,t) < 0, th(x,y,z,t)+2*pi, th(x,y,z,t))",
          "f_hex_y = if(th(x,y,z,t)<pi/6, y1(x,y,z,t), abs(-sin(pi/3)*x1(x,y,z,t)+cos(pi/3)*y1(x,y,z,t)))",
          "f_hex_y_1=if(abs(z)<0DOTSYMBOL06,f_hex_y(x,y,z,0)- 0DOTSYMBOL08,1)",
          "Cylinder=-f_hex_y_1(x,4DOTSYMBOL3*atan2(z,y),sqrt(y*y+z*z)-1DOTSYMBOL5,t)",
          "Sphere=f_hex_y_1(6DOTSYMBOL3*atan2(x,sqrt(y*y+z*z)),3DOTSYMBOL815*atan2(z,y),sqrt(y*y+z*z+x*x)-4DOTSYMBOL6,t)",
          "Torus=Cylinder(6DOTSYMBOL03*atan2(y,x),sqrt(x*x+y*y)-4,z,t)"
        ],
        "Fxyz": [
          "Torus(x,y,z,t)"
        ],
        "Xmax": [
          "5DOTSYMBOL7"
        ],
        "Xmin": [
          "-5DOTSYMBOL7"
        ],
        "Ymax": [
          "5DOTSYMBOL7"
        ],
        "Ymin": [
          "-5DOTSYMBOL7"
        ],
        "Zmax": [
          "1DOTSYMBOL6"
        ],
        "Zmin": [
          "-1DOTSYMBOL6"
        ]
      }
    },
    {
      "Iso3D": {
        "Name": [
          "Wall Pattern Sphere-03"
        ],
        "Description": [
          "Wall Pattern Sphere-03 by Abderrahman Taha 10/01/2016"
        ],
        "Component": [
          "f_hex_y"
        ],
        "Funct": [
          "x1=abs((abs(x) % sqrt(3DOTSYMBOL0))-sqrt(3DOTSYMBOL0)/2)",
          "y1 = abs((abs(y) % 3)-1DOTSYMBOL5)",
          "x2=sqrt(3DOTSYMBOL0)/2-x1(x,y,z,t)",
          "y2=1DOTSYMBOL5-y1(x,y,z,t)",
          "x1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), x2(x,y,z,t), x1(x,y,z,t))",
          "y1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), y2(x,y,z,t), y1(x,y,z,t))",
          "th=atan2(y1(x,y,z,t),x1(x,y,z,t))",
          "th = if (th(x,y,z,t) < 0, th(x,y,z,t)+2*pi, th(x,y,z,t))",
          "f_hex_y = if(th(x,y,z,t)<pi/6, y1(x,y,z,t), abs(-sin(pi/3)*x1(x,y,z,t)+cos(pi/3)*y1(x,y,z,t)))",
          "f_hex_y_1=if(abs(z)<0DOTSYMBOL06,f_hex_y(x,y,z,0)- 0DOTSYMBOL08,1)",
          "Cylinder=-f_hex_y_1(x,4DOTSYMBOL3*atan2(z,y),sqrt(y*y+z*z)-1DOTSYMBOL5,t)",
          "Sphere=f_hex_y_1(6DOTSYMBOL3*atan2(x,sqrt(y*y+z*z)),3DOTSYMBOL815*atan2(z,y),sqrt(y*y+z*z+x*x)-4DOTSYMBOL6,t)",
          "Torus=Cylinder(6DOTSYMBOL03*atan2(y,x),sqrt(x*x+y*y)-4,z,t)"
        ],
        "Fxyz": [
          "Sphere(x,y,z,t)"
        ],
        "Xmax": [
          "4DOTSYMBOL8"
        ],
        "Xmin": [
          "-4DOTSYMBOL8"
        ],
        "Ymax": [
          "4DOTSYMBOL8"
        ],
        "Ymin": [
          "-4DOTSYMBOL8"
        ],
        "Zmax": [
          "4DOTSYMBOL8"
        ],
        "Zmin": [
          "-4DOTSYMBOL8"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Wall Pattern Sphere-02 by Abderrahman Taha 09/01/2016DOTSYMBOL The f_hex_y formula is from the PovRay team: http://www.povray.org/ "
        ],
        "Name": [
          "Wall Pattern Sphere-02"
        ],
        "Component": [
          "f_hex_y"
        ],
        "Funct": [
          "x1=abs((abs(x) % sqrt(3DOTSYMBOL0))-sqrt(3DOTSYMBOL0)/2)",
          "y1 = abs((abs(y) % 3)-1DOTSYMBOL5)",
          "x2=sqrt(3DOTSYMBOL0)/2-x1(x,y,z,t)",
          "y2=1DOTSYMBOL5-y1(x,y,z,t)",
          "x1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), x2(x,y,z,t), x1(x,y,z,t))",
          "y1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), y2(x,y,z,t), y1(x,y,z,t))",
          "th=atan2(y1(x,y,z,t),x1(x,y,z,t))",
          "th = if (th(x,y,z,t) < 0, th(x,y,z,t)+2*pi, th(x,y,z,t))",
          "f_hex_y = if(th(x,y,z,t)<pi/6, y1(x,y,z,t), abs(-sin(pi/3)*x1(x,y,z,t)+cos(pi/3)*y1(x,y,z,t)))",
          "f_hex_y_1=if(abs(z)<0DOTSYMBOL06,f_hex_y(sqrt(x*x+y*y)-2,4DOTSYMBOL75*atan2(y,x),z,0)- 0DOTSYMBOL08,1)",
          "Cylinder=-f_hex_y_1(x,4DOTSYMBOL3*atan2(z,y),sqrt(y*y+z*z)-1DOTSYMBOL5,t)",
          "Sphere=f_hex_y_1(4*atan2(x,sqrt(y*y+z*z)),4DOTSYMBOL5*atan2(z,y),sqrt(y*y+z*z+x*x)-4DOTSYMBOL5,t)",
          "Torus=Cylinder(8*atan2(y,x),sqrt(x*x+y*y)-4,z,t)"
        ],
        "Fxyz": [
          "Sphere(x,y,z,t)"
        ],
        "Xmax": [
          "4DOTSYMBOL8"
        ],
        "Xmin": [
          "-4DOTSYMBOL8"
        ],
        "Ymax": [
          "4DOTSYMBOL8"
        ],
        "Ymin": [
          "-4DOTSYMBOL8"
        ],
        "Zmax": [
          "4DOTSYMBOL8"
        ],
        "Zmin": [
          "-4DOTSYMBOL8"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Wall Pattern Sphere-01 by Abderrahman Taha 05/01/2016DOTSYMBOL The f_hex_y formula is from the PovRay team: http://www.povray.org/ "
        ],
        "Name": [
          "Wall Pattern Sphere-01"
        ],
        "Component": [
          "f_hex_y"
        ],
        "Funct": [
          "x1=abs((abs(x) % sqrt(3DOTSYMBOL0))-sqrt(3DOTSYMBOL0)/2)",
          "y1 = abs((abs(y) % 3)-1DOTSYMBOL5)",
          "x2=sqrt(3DOTSYMBOL0)/2-x1(x,y,z,t)",
          "y2=1DOTSYMBOL5-y1(x,y,z,t)",
          "x1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), x2(x,y,z,t), x1(x,y,z,t))",
          "y1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), y2(x,y,z,t), y1(x,y,z,t))",
          "th=atan2(y1(x,y,z,t),x1(x,y,z,t))",
          "th = if (th(x,y,z,t) < 0, th(x,y,z,t)+2*pi, th(x,y,z,t))",
          "f_hex_y = if(th(x,y,z,t)<pi/6, y1(x,y,z,t), abs(-sin(pi/3)*x1(x,y,z,t)+cos(pi/3)*y1(x,y,z,t)))",
          "f_hex_y_1=if(z*z- 0DOTSYMBOL01 < 0,f_hex_y(sin(x),1DOTSYMBOL3*sin(y),2*z,0),1)- 0DOTSYMBOL1",
          "Cylinder=-f_hex_y_1(x,4DOTSYMBOL3*atan2(z,y),sqrt(y*y+z*z)-1DOTSYMBOL5,t)",
          "Sphere=f_hex_y_1(4*atan2(x,sqrt(y*y+z*z)),4DOTSYMBOL5*atan2(z,y),sqrt(y*y+z*z+x*x)-4DOTSYMBOL5,t)",
          "Torus=Cylinder(8*atan2(y,x),sqrt(x*x+y*y)-4,z,t)"
        ],
        "Fxyz": [
          "Sphere(x,y,z,t)"
        ],
        "Xmax": [
          "4DOTSYMBOL6"
        ],
        "Xmin": [
          "-4DOTSYMBOL6"
        ],
        "Ymax": [
          "4DOTSYMBOL6"
        ],
        "Ymin": [
          "-4DOTSYMBOL6"
        ],
        "Zmax": [
          "4DOTSYMBOL6"
        ],
        "Zmin": [
          "-4DOTSYMBOL6"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Wall Pattern Torus-01 by Abderrahman Taha 05/01/2016DOTSYMBOL The f_hex_y formula is from the PovRay team: http://www.povray.org/ "
        ],
        "Name": [
          "Wall Pattern Torus-01"
        ],
        "Component": [
          "f_hex_y"
        ],
        "Funct": [
          "x1=abs((abs(x) % sqrt(3DOTSYMBOL0))-sqrt(3DOTSYMBOL0)/2)",
          "y1 = abs((abs(y) % 3)-1DOTSYMBOL5)",
          "x2=sqrt(3DOTSYMBOL0)/2-x1(x,y,z,t)",
          "y2=1DOTSYMBOL5-y1(x,y,z,t)",
          "x1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), x2(x,y,z,t), x1(x,y,z,t))",
          "y1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), y2(x,y,z,t), y1(x,y,z,t))",
          "th=atan2(y1(x,y,z,t),x1(x,y,z,t))",
          "th = if (th(x,y,z,t) < 0, th(x,y,z,t)+2*pi, th(x,y,z,t))",
          "f_hex_y = if(th(x,y,z,t)<pi/6, y1(x,y,z,t), abs(-sin(pi/3)*x1(x,y,z,t)+cos(pi/3)*y1(x,y,z,t)))",
          "f_hex_y_1=if(z*z- 0DOTSYMBOL01 < 0,f_hex_y(sin(x),1DOTSYMBOL3*sin(y),2*z,0),1)- 0DOTSYMBOL1",
          "Cylinder=-f_hex_y_1(x,4DOTSYMBOL3*atan2(z,y),sqrt(y*y+z*z)-1DOTSYMBOL5,t)",
          "Sphere=f_hex_y_1(4*atan2(x,sqrt(y*y+z*z)),4DOTSYMBOL3*atan2(z,y),sqrt(y*y+z*z+x*x)-4DOTSYMBOL5,t)",
          "Torus=Cylinder(8*atan2(y,x),sqrt(x*x+y*y)-4,z,t)"
        ],
        "Fxyz": [
          "Torus(x,y,z,t)"
        ],
        "Xmax": [
          "6"
        ],
        "Xmin": [
          "-6"
        ],
        "Ymax": [
          "6"
        ],
        "Ymin": [
          "-6"
        ],
        "Zmax": [
          "1DOTSYMBOL6"
        ],
        "Zmin": [
          "-1DOTSYMBOL6"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Interlocked Torus-01 by Abderrahman Taha 22/12/2015DOTSYMBOL The Helix formula is from the PovRay team: http://www.povray.org/ "
        ],
        "Name": [
          "Interlocked Torus_01"
        ],
        "Component": [
          "Interlocked Torus"
        ],
        "Const": [
          "A = 4",
          "B = 1",
          "C = 0DOTSYMBOL5",
          "D = 1",
          "E = 1",
          "F = 1",
          "G = 30"
        ],
        "Funct": [
          "X = x",
          "Z = z",
          "r = sqrt(X(x,y,z,t) * X(x,y,z,t) + Z(x,y,z,t) * Z(x,y,z,t))",
          "X= if ((X(x,y,z,t) = 0) & (Z(x,y,z,t) = 0),0DOTSYMBOL001,X(x,y,z,t))",
          "th = atan2(Z(x,y,z,t), X(x,y,z,t))",
          "th = ((th(x,y,z,t) * A + y * B * A) % (2*pi))",
          "th = if (th(x,y,z,t) < 0,        th(x,y,z,t)+2*pi, th(x,y,z,t))",
          "Z = (th(x,y,z,t) - pi) / E / (B * A)",
          "X = r(x,y,z,t) - D",
          "Z = if ((F = 1 | G = 0)=0, X(x,y,z,t) * sin(G * pi/180) + Z(x,y,z,t) * cos(G * pi/180) , Z(x,y,z,t))",
          "X = if ((F = 1 | G = 0)=0, X(x,y,z,t) * cos(G * pi/180) - Z(x,y,z,t) * sin(G * pi/180) , X(x,y,z,t))",
          "r2 = if (F = 1,        sqrt(X(x,y,z,t) * X(x,y,z,t) + Z(x,y,z,t) * Z(x,y,z,t)),                if ((F = 0)=0,                        pow((pow(abs(X(x,y,z,t)), 2/F) + pow(abs(Z(x,y,z,t)), 2/F)), F * 0DOTSYMBOL5),                        if (abs(X(x,y,z,t)) > abs(Z(x,y,z,t)) ,                     abs(X(x,y,z,t)) ,   abs(Z(x,y,z,t))            )    )          )",
          "r3 = if((D + r(x,y,z,t)) < r2(x,y,z,t) , (D + r(x,y,z,t)) , r2(x,y,z,t))",
          "helix = (-C + r3(x,y,z,t))"
        ],
        "Fxyz": [
          "-helix(sqrt(x*x+y*y)-3,2*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "5"
        ],
        "Xmin": [
          "-5"
        ],
        "Ymax": [
          "5"
        ],
        "Ymin": [
          "-5"
        ],
        "Zmax": [
          "2"
        ],
        "Zmin": [
          "-2"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=0DOTSYMBOL81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))+ 0DOTSYMBOL3",
          "B=0DOTSYMBOL8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(2*x,2*y,2*z,4,2,0)+NoiseP(2*x,2*y,2*z,4,12,1/10)"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Perlin Schwarz_01 by Abderrahman Taha 26/12/2015DOTSYMBOL"
        ],
        "Name": [
          "Perlin Schwarz"
        ],
        "Component": [
          "PerlinSchwarz"
        ],
        "Funct": [
          "Schwarz=cos(x)+cos(y)+cos(z)"
        ],
        "Fxyz": [
          "Schwarz(x,y,z,t)-NoiseP(x,y,z,4,11,1/10)"
        ],
        "Xmax": [
          "4"
        ],
        "Xmin": [
          "-4"
        ],
        "Ymax": [
          "4"
        ],
        "Ymin": [
          "-4"
        ],
        "Zmax": [
          "4"
        ],
        "Zmin": [
          "-4"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL82",
          "G=1DOTSYMBOL62*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "B=1DOTSYMBOL72*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "Perlin",
        "Noise": "NoiseP(x,y,z,4,11,1/10)"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Wired Torus_01 by Abderrahman Taha 26/12/2015DOTSYMBOL The mesh formula is from the PovRay team: http://www.povray.org/ "
        ],
        "Name": [
          "Wired Torus_01"
        ],
        "Component": [
          "Wired Torus"
        ],
        "Const": [
          "A=0DOTSYMBOL2",
          "B=0DOTSYMBOL2",
          "C=1",
          "D=0DOTSYMBOL04",
          "E=1",
          "th=pi/A",
          "ph=pi/B"
        ],
        "Funct": [
          "r=(x%(A*2))",
          "r=abs(if(r(x,y,z,t)<0,r(x,y,z,t)+A,r(x,y,z,t)-A))*C",
          "r2=(y-cos(z*ph)*D)*E",
          "temp=-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t))",
          "r=((x-A)%(A*2))",
          "r=abs(if(r(x,y,z,t)<0,r(x,y,z,t)+A,r(x,y,z,t)-A))*C",
          "r2=(y+cos(z*ph)*D)*E",
          "temp=max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t))",
          "r=(z%(B*2))",
          "r=abs(if(r(x,y,z,t)<0,r(x,y,z,t)+B,r(x,y,z,t)-B))*C",
          "r2=(y+cos(x*th)*D)*E",
          "temp=max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t))",
          "r=((z-B)%(B*2))",
          "r=abs(if(r(x,y,z,t)<0,r(x,y,z,t)+B,r(x,y,z,t)-B))*C",
          "r2=(y-cos(x*th)*D)*E",
          "fmesh0=(-max(-sqrt(r2(x,y,z,t)*r2(x,y,z,t)+r(x,y,z,t)*r(x,y,z,t)),temp(x,y,z,t)))",
          "fmesh1=-fmesh0(atan2(y,x),sqrt(x*x+y*y)-1,z,t)+0DOTSYMBOL03",
          "fmesh2=fmesh1(sqrt(x*x+z*z)-2,y,atan2(z,x),t)"
        ],
        "Fxyz": [
          "fmesh2(x,y,z,t)"
        ],
        "Xmax": [
          "3DOTSYMBOL1"
        ],
        "Xmin": [
          "-3DOTSYMBOL1"
        ],
        "Ymax": [
          "1DOTSYMBOL1"
        ],
        "Ymin": [
          "-1DOTSYMBOL1"
        ],
        "Zmax": [
          "3DOTSYMBOL1"
        ],
        "Zmin": [
          "-3DOTSYMBOL1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Wired Sphere-01 by Abderrahman Taha 25/12/2015DOTSYMBOL The mesh formula is from the PovRay team: http://www.povray.org/ "
        ],
        "Name": [
          "Wired Sphere_01"
        ],
        "Component": [
          "Wired Sphere"
        ],
        "Const": [
          "A = 0DOTSYMBOL15",
          "B = 0DOTSYMBOL15",
          "C = 1",
          "D = 0DOTSYMBOL02",
          "E = 1",
          "th = pi / A",
          "ph = pi/ B"
        ],
        "Funct": [
          "r = (x % (A * 2))",
          "r = abs( if (r(x,y,z,t) < 0, r(x,y,z,t) + A, r(x,y,z,t) - A)) * C",
          "r2 = (y - cos(z * ph) * D) * E",
          "temp = -sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t))",
          "r = ((x - A) % (A * 2))",
          "r = abs(if (r(x,y,z,t) < 0, r(x,y,z,t) + A, r(x,y,z,t) - A)) * C",
          "r2 = (y + cos(z * ph) * D) * E",
          "temp = max(-sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t)), temp(x,y,z,t))",
          "r = (z % (B * 2))",
          "r = abs(if (r(x,y,z,t) < 0, r(x,y,z,t) + B, r(x,y,z,t) - B)) * C",
          "r2 = (y + cos(x * th) * D) * E",
          "temp = max( -sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t)), temp(x,y,z,t))",
          "r = ((z- B) % (B * 2))",
          "r = abs(if (r(x,y,z,t) < 0, r(x,y,z,t) + B, r(x,y,z,t) - B)) * C",
          "r2 = (y - cos(x * th) * D) * E",
          "fmesh0 = max( -sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t)), temp(x,y,z,t)) +0DOTSYMBOL03",
          "fmesh0= fmesh0(atan2(y,x),sqrt(x*x+y*y+z*z) -1,atan2(z,sqrt(x*x+y*y)),t)"
        ],
        "Fxyz": [
          "fmesh0(x,y,z,t)"
        ],
        "Xmax": [
          "1DOTSYMBOL1"
        ],
        "Xmin": [
          "-1DOTSYMBOL1"
        ],
        "Ymax": [
          "1DOTSYMBOL1"
        ],
        "Ymin": [
          "-1DOTSYMBOL1"
        ],
        "Zmax": [
          "1DOTSYMBOL1"
        ],
        "Zmin": [
          "-1DOTSYMBOL1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Straw Basket-01 by Abderrahman Taha 22/12/2015DOTSYMBOL The mesh formula is from the PovRay team: http://www.povray.org/ "
        ],
        "Name": [
          "Straw Basket_01"
        ],
        "Component": [
          "Straw Basket"
        ],
        "Const": [
          "A = 0DOTSYMBOL5",
          "B = 0DOTSYMBOL2",
          "C = 1",
          "D = 0DOTSYMBOL09",
          "E = 1",
          "th = pi / A",
          "ph = pi/ B"
        ],
        "Funct": [
          "r = (x % (A * 2))",
          "r = abs( if (r(x,y,z,t) < 0, r(x,y,z,t) + A, r(x,y,z,t) - A)) * C",
          "r2 = (y - cos(z * ph) * D) * E",
          "temp = -sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t))",
          "r = ((x - A) % (A * 2))",
          "r = abs(if (r(x,y,z,t) < 0, r(x,y,z,t) + A, r(x,y,z,t) - A)) * C",
          "r2 = (y + cos(z * ph) * D) * E",
          "temp =   max(-sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t)), temp(x,y,z,t))",
          "r = (z % (B * 2))",
          "r = abs(if (r(x,y,z,t) < 0, r(x,y,z,t) + B, r(x,y,z,t) - B)) * C",
          "r2 = (y + cos(x * th) * D) * E",
          "temp = max( -sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t)  * r(x,y,z,t)), temp(x,y,z,t))",
          "r = ((z- B) % (B * 2))",
          "r = abs(if (r(x,y,z,t) < 0, r(x,y,z,t) + B, r(x,y,z,t) - B)) * C",
          "r2 = (y - cos(x * th) * D) * E",
          "fmesh0 = max( -sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t)), temp(x,y,z,t)) +0DOTSYMBOL08",
          "fmesh0= if(atan2(z,sqrt(x*x+y*y)) < 0DOTSYMBOL89, fmesh0(atan2(y,x),sqrt(x*x+y*y+z*z) -4,atan2(z,sqrt(x*x+y*y)),t), 1)*(atan2(z,sqrt(x*x+y*y)) < 0DOTSYMBOL89)"
        ],
        "Fxyz": [
          "fmesh0(x,y,z,t)"
        ],
        "Xmax": [
          "5"
        ],
        "Xmin": [
          "-5"
        ],
        "Ymax": [
          "5"
        ],
        "Ymin": [
          "-5"
        ],
        "Zmax": [
          "5"
        ],
        "Zmin": [
          "-5"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Mesh Torus_01 by Abderrahman Taha 22/12/2015DOTSYMBOL The mesh formula is from the PovRay team: http://www.povray.org/ "
        ],
        "Name": [
          "Mesh Torus_01"
        ],
        "Component": [
          "Mesh Torus"
        ],
        "Const": [
          "A = 0DOTSYMBOL5",
          "B = 0DOTSYMBOL3",
          "C = 1",
          "D = 0DOTSYMBOL1",
          "E = 1",
          "th = pi / A",
          "ph = pi/ B"
        ],
        "Funct": [
          "r = (x % (A * 2))",
          "r = abs( if (r(x,y,z,t) < 0, r(x,y,z,t) + A, r(x,y,z,t) - A)) * C",
          "r2 = (y - cos(z * ph) * D) * E",
          "temp = -sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t))",
          "r = ((x - A) % (A * 2))",
          "r = abs(if (r(x,y,z,t) < 0, r(x,y,z,t) + A, r(x,y,z,t) - A)) * C",
          "r2 = (y + cos(z * ph) * D) * E",
          "temp =   max(-sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t)), temp(x,y,z,t))",
          "r = (z % (B * 2))",
          "r = abs(if (r(x,y,z,t) < 0, r(x,y,z,t) + B, r(x,y,z,t) - B)) * C",
          "r2 = (y + cos(x * th) * D) * E",
          "temp = max(-sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t)), temp(x,y,z,t))",
          "r = ((z- B) % (B * 2))",
          "r = abs(if (r(x,y,z,t) < 0, r(x,y,z,t) + B, r(x,y,z,t) - B)) * C",
          "r2 = (y - cos(x * th) * D) * E",
          "fmesh0 = (-max(-sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t)), temp(x,y,z,t)))",
          "fmesh1= -fmesh0(atan2(y,x),sqrt(x*x+y*y)-4,z,t) +0DOTSYMBOL08",
          "fmesh2= fmesh1(sqrt(x*x+z*z)-7,y,2*atan2(z,x),t)"
        ],
        "Fxyz": [
          "  fmesh2(x,y,z,t)"
        ],
        "Xmax": [
          "12"
        ],
        "Xmin": [
          "-12"
        ],
        "Ymax": [
          "5"
        ],
        "Ymin": [
          "-5"
        ],
        "Zmax": [
          "12"
        ],
        "Zmin": [
          "-12"
        ]
      }
    },
    {
      "Param3D": {
        "Component": [
          "Bottle shape"
        ],
        "Description ": [
          "Bottle shape surface (found by Robert Israel) by Abderrahman Taha 14/12/2015"
        ],
        "Fx": [
          " (-2/15)*(cos(u)*(3*cos(v)-30*sin(u) + 90*cos(u)^4*sin(u) -60*cos(u)^6*sin(u) +5*cos(u)*cos(v)*sin(u))) "
        ],
        "Fy": [
          " (-1/15)*sin(u)*(3*cos(v)-3*cos(u)^2*cos(v)-48*cos(u)^4*cos(v)+48*cos(u)^6 *cos(v)-60*sin(u)+5*cos(u)*cos(v)*sin(u)-5*cos(u)^3*cos(v)*sin(u) -80*cos(u)^5*cos(v)*sin(u)+80*cos(u)^7*cos(v)*sin(u) ) "
        ],
        "Fz": [
          " (2/15)*(3+5*cos(u)*sin(u))*sin(v) "
        ],
        "Name": [
          "Bottle shape"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=0DOTSYMBOL8*abs(cos((pi*(x*x+y*y+z*z))))",
          "B=0DOTSYMBOL6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
          "T=1"
        ],
        "Name": "Dream",
        "Noise": "NoiseW(2*x,2*y,2*z,8,1,0)"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Richmond polar_2  parametric surface by Abderrahman Taha 14/12/2015"
        ],
        "Name": [
          "Richmond polar_2"
        ],
        "Component": [
          "RichmondPolar"
        ],
        "Fx": [
          "-cos(v)/(2*u) - u^3*cos(3*v)/6"
        ],
        "Fy": [
          "-sin(v)/(2*u) + u^3*sin(3*v)/6"
        ],
        "Fz": [
          "u*cos(v)*sin(v)"
        ],
        "Umax": [
          "1DOTSYMBOL3"
        ],
        "Umin": [
          "0DOTSYMBOL3"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=0DOTSYMBOL8*abs(cos((pi*(x*x+y*y+z*z))))",
          "B=0DOTSYMBOL6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
          "T=1"
        ],
        "Name": "Dream",
        "Noise": "NoiseW(4*x,4*y,4*z,8,1,0)"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Schwarz P Sphere_2 by Abderrahman Taha 13/12/2015"
        ],
        "Name": [
          "Schwarz P Sphere_2"
        ],
        "Component": [
          "Schwarz P Sphere"
        ],
        "Const": [
          "M=1",
          "N=10"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
          "Iso4= (Iso(x+sin(x)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "Iso5= (Iso(x-sin(x)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y-sin(y)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z-sin(z)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "TickIso2= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "SchwarzP= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoCondition_0=(x^2-4DOTSYMBOL8^2)",
          "isoCondition_1=(x^2-4DOTSYMBOL6^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,SchwarzP(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),N*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2(x,y,z,t)"
        ],
        "Xmax": [
          "18"
        ],
        "Xmin": [
          "-18"
        ],
        "Ymax": [
          "18"
        ],
        "Ymin": [
          "-18"
        ],
        "Zmax": [
          "18"
        ],
        "Zmin": [
          "-18"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Under Sea by Abderrahman Taha 12/12/2015"
        ],
        "Name": [
          "Under The Sea_02"
        ],
        "Component": [
          "UnderSea"
        ],
        "Const": [
          "M=2",
          "N=5"
        ],
        "Fx": [
          "u*cos(v)"
        ],
        "Fy": [
          "u*sin(v)"
        ],
        "Fz": [
          "exp(-u*u) * (sin(M*pi*(u)) -u*cos(N*v))"
        ],
        "Umax": [
          "2"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=1DOTSYMBOL5* 0DOTSYMBOL41",
          "G=2*0DOTSYMBOL81*abs(cos((x*x+y*y+z*z)/2) *sin((x*x+y*y+z*z)/2))",
          "B=2*0DOTSYMBOL8601*abs(cos((x*x+y*y+z*z)/2) *cos((x*x+y*y+z*z)/2) *sin((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(4*x,4*y,4*z,4,2,0) +NoiseW(4*x,4*y,4*z,4,12,1/10)"
      }
    },
    {
      "Iso3D": {
        "Name": [
          "HexaGrid Torus_2"
        ],
        "Component": [
          "HexaGrid Torus"
        ],
        "Const": [
          "N=3"
        ],
        "Description ": [
          " HexaGrid Torus_2 by Aberrahman Taha 11/12/2015. Reference: PG_HexaGridCylinder 12/2012 Gerd Platl"
        ],
        "Funct": [
          "HexaGrid=-0DOTSYMBOL55-88*(sqrt(x*x+y*y)-2)^2 -cos( 8*z) -cos(14*atan2(y,x) -4*z) -cos(14*atan2(y,x) +4*z) -0DOTSYMBOL6*( cos( 28*atan2(y,x)) +cos(12*z -14*atan2(y,x)) +cos(12*z +14*atan2(y,x)))"
        ],
        "Fxyz": [
          "HexaGrid((sqrt(x*x+z*z)-4),y,N*atan2(z,x),t)"
        ],
        "Xmax": [
          " 6DOTSYMBOL2"
        ],
        "Xmin": [
          "-6DOTSYMBOL2 "
        ],
        "Ymax": [
          "4DOTSYMBOL5"
        ],
        "Ymin": [
          "-4DOTSYMBOL5"
        ],
        "Zmax": [
          " 6DOTSYMBOL2"
        ],
        "Zmin": [
          "-6DOTSYMBOL2"
        ]
      }
    },
    {
      "Iso3D": {
        "Description ": [
          " HexaGrid Torus by Aberrahman Taha 11/12/2015. Reference: PG_HexaGridCylinder3 12/2012 Gerd Platl, http://k3dsurf.s4.bizhat.com/viewtopic.php… "
        ],
        "Name": [
          "HexaGrid Torus"
        ],
        "Component": [
          "HexaGrid Torus"
        ],
        "Funct": [
          "HexaGrid=-0DOTSYMBOL5-88*(sqrt(x*x+y*y)-2)^2-cos( 8*z)-cos(14*atan2(y,x) -4*z)-cos(14*atan2(y,x) +4*z)-0DOTSYMBOL12*( cos( 28*atan2(y,x))+cos(12*z -14*atan2(y,x))+cos(12*z +14*atan2(y,x)))"
        ],
        "Fxyz": [
          "HexaGrid((sqrt(x*x+z*z)-4),y,3*atan2(z,x),t)"
        ],
        "Xmax": [
          " 6DOTSYMBOL2"
        ],
        "Xmin": [
          "-6DOTSYMBOL2 "
        ],
        "Ymax": [
          " 4DOTSYMBOL5"
        ],
        "Ymin": [
          "-4DOTSYMBOL5 "
        ],
        "Zmax": [
          " 6DOTSYMBOL2"
        ],
        "Zmin": [
          "-6DOTSYMBOL2 "
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Menger L4 SchwarzP by Abderrahman Taha 11/12/2015"
        ],
        "Name": [
          "Menger_4 SchwarzP"
        ],
        "Component": [
          "Menger SchwarzP"
        ],
        "Fxyz": [
          "if(-(Dx+Dy+Dz-1DOTSYMBOL02)*(((abs(x)>1/3|abs(y)>1/3)*(abs(z)>1/3|abs(y)>1/3)*(abs(x)>1/3|abs(z)>1/3))*((Cx*(Cy+Cz)+Cz*Cy)=0)*((Bx*(By+Bz)+Bz*By)=0)*((Ax*(Ay+Az)+Az*Ay)=0)),(cos(254DOTSYMBOL469*(x+Ex*0DOTSYMBOL002/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(254DOTSYMBOL469*(y+Ey*0DOTSYMBOL002/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(254DOTSYMBOL469*(z+Ez*0DOTSYMBOL002/sqrt(Ex*Ex+Ey*Ey+Ez*Ez))))*(cos(254DOTSYMBOL469*(x-Ex*0DOTSYMBOL002/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(254DOTSYMBOL469*(y-Ey*0DOTSYMBOL002/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(254DOTSYMBOL469*(z-Ez*0DOTSYMBOL002/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)"
        ],
        "Varu": [
          "A=((abs(u-2/3)<1/81)+(abs(u-20/27)<1/81)+(abs(u-16/27)<1/81)+(abs(u-8/9)<1/81)+(abs(u-26/27)<1/81)+(abs(u-22/27)<1/81)+(abs(u-4/9)<1/81)+(abs(u-14/27)<1/81)+(abs(u-10/27)<1/81)+(abs(u+2/3)<1/81)+(abs(u+16/27)<1/81)+(abs(u+20/27)<1/81)+(abs(u+4/9)<1/81)+(abs(u+10/27)<1/81)+(abs(u+14/27)<1/81)+(abs(u+8/9)<1/81)+(abs(u+22/27)<1/81)+(abs(u+26/27)<1/81)+(abs(u)<1/81)+(abs(u-2/27)<1/81)+(abs(u+2/27)<1/81)+(abs(u-2/9)<1/81)+(abs(u-8/27)<1/81)+(abs(u-4/27)<1/81)+(abs(u+2/9)<1/81)+(abs(u+4/27)<1/81)+(abs(u+8/27)<1/81))",
          "B=((abs(u-2/3)<1/27)+(abs(u-8/9)<1/27)+(abs(u-4/9)<1/27)+(abs(u+2/3)<1/27)+(abs(u+4/9)<1/27)+(abs(u+8/9)<1/27)+(abs(u)<1/27)+(abs(u-2/9)<1/27)+(abs(u+2/9)<1/27))",
          "C=((abs(u-2/3)<1/9)+(abs(u+2/3)<1/9)+(abs(u)<1/9))",
          "D=u^600",
          "E=sin(254DOTSYMBOL469*u)"
        ],
        "Xmax": [
          "1DOTSYMBOL0005"
        ],
        "Xmin": [
          "0DOTSYMBOL3333"
        ],
        "Ymax": [
          "1DOTSYMBOL0005"
        ],
        "Ymin": [
          "0DOTSYMBOL3333"
        ],
        "Zmax": [
          "1DOTSYMBOL0005"
        ],
        "Zmin": [
          "0DOTSYMBOL3333"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL6*sqrt(4*x^40+y^4+z^4)",
          "G=0DOTSYMBOL3*sqrt(x^4+y^4+4*z^20)",
          "B=0DOTSYMBOL4*sqrt(x^4+4*y^20+z^4)",
          "T=1"
        ],
        "Name": "Granit_2",
        "Noise": "1"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Skeletal SchwarzP Tori_2 by Abderrahman Taha 10/12/2015"
        ],
        "Name": [
          "Skeletal SchwarzP Tori_2"
        ],
        "Component": [
          "Skeletal SchwarzP Tori"
        ],
        "Const": [
          "M=0DOTSYMBOL2",
          "N=15",
          "T=1",
          "S=pi"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
          "Iso2= (Iso(x+t*sin(x)*1DOTSYMBOL2/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+t*sin(y)*1DOTSYMBOL2/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+t*sin(z)*1DOTSYMBOL2/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "SchwarzP= (-Iso2(x,y,z,t))",
          "isoCondition_0=((x-S)^2-2^2)",
          "isoCondition_1=((x-S)^2- 0DOTSYMBOL01^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,SchwarzP(x,y,z,-1),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "30"
        ],
        "Xmin": [
          "-30"
        ],
        "Ymax": [
          "30"
        ],
        "Ymin": [
          "-30"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Skeletal SchwarzP Tori by Abderrahman Taha 10/12/2015"
        ],
        "Name": [
          "Skeletal SchwarzP Tori"
        ],
        "Component": [
          "Skeletal SchwarzP Tori"
        ],
        "Const": [
          "M=0DOTSYMBOL1",
          "N=15",
          "T=1DOTSYMBOL2",
          "S=5"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
          "Iso2= (Iso(x+t*sin(x)*1DOTSYMBOL2/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+t*sin(y)*1DOTSYMBOL2/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+t*sin(z)*1DOTSYMBOL2/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "SchwarzP= (-Iso2(x,y,z,t))",
          "isoCondition_0=((x-S)^2-2DOTSYMBOL4^2)",
          "isoCondition_1=((x-S)^2-1DOTSYMBOL4^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,-SchwarzP(x,y,z,-1),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "30"
        ],
        "Xmin": [
          "-30"
        ],
        "Ymax": [
          "30"
        ],
        "Ymin": [
          "-30"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Schwarz P Tori by Abderrahman Taha 10/12/2015"
        ],
        "Name": [
          "Schwarz P Tori"
        ],
        "Component": [
          "Schwarz P Tori"
        ],
        "Const": [
          "M=0DOTSYMBOL1",
          "N=15"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
          "Iso4= (Iso(x+sin(x)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "Iso5= (Iso(x-sin(x)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y-sin(y)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z-sin(z)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "TickIso2= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "SchwarzP= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoCondition_0=(x^2-3DOTSYMBOL2^2)",
          "isoCondition_1=(x^2-3^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,SchwarzP(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "27"
        ],
        "Xmin": [
          "-27"
        ],
        "Ymax": [
          "27"
        ],
        "Ymin": [
          "-27"
        ],
        "Zmax": [
          "12"
        ],
        "Zmin": [
          "-12"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "G_Skeletal Tori by Abderrahman Taha 09/12/2015"
        ],
        "Name": [
          "G_Skeletal Tori"
        ],
        "Component": [
          "G_Skeletal Tori"
        ],
        "Const": [
          "M=4",
          "N=10",
          "P=0DOTSYMBOL4"
        ],
        "Funct": [
          "G_Skeletal =cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)+0DOTSYMBOL08*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+1",
          "isoCondition_0=((x-pi)^2-(pi-P+ 0DOTSYMBOL3)^2)",
          "isoCondition_1=((x-pi)^2-(pi-P)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,G_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "30"
        ],
        "Xmin": [
          "-30"
        ],
        "Ymax": [
          "30"
        ],
        "Ymin": [
          "-30"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "D_Skeletal Tori by Abderrahman Taha 08/12/2015"
        ],
        "Name": [
          "D_Skeletal Tori"
        ],
        "Component": [
          "D_Skeletal Tori"
        ],
        "Const": [
          "M=4",
          "N=8",
          "P=0DOTSYMBOL3"
        ],
        "Funct": [
          "D_Skeletal =sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)-0DOTSYMBOL07*(cos(4*x)+cos(4*y)+cos(4*z))+ 0DOTSYMBOL95",
          "isoCondition_0=((x-pi)^2-(pi-P+ 0DOTSYMBOL01)^2)",
          "isoCondition_1=((x-pi)^2-(pi-P)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,D_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "30"
        ],
        "Xmin": [
          "-30"
        ],
        "Ymax": [
          "30"
        ],
        "Ymin": [
          "-30"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "D_Skeletal Sphere by Abderrahman Taha 08/12/2015"
        ],
        "Name": [
          "D_Skeletal Sphere"
        ],
        "Component": [
          "D_Skeletal Sphere"
        ],
        "Const": [
          "M=4",
          "N=8",
          "P=0DOTSYMBOL3"
        ],
        "Funct": [
          "D_Skeletal =sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)-0DOTSYMBOL07*(cos(4*x)+cos(4*y)+cos(4*z))+ 0DOTSYMBOL95",
          "isoCondition_0=((x-pi)^2-(pi-P+ 0DOTSYMBOL01)^2)",
          "isoCondition_1=((x-pi)^2-(pi-P)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,D_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),N*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2(x,y,z,t)"
        ],
        "Xmax": [
          "19"
        ],
        "Xmin": [
          "-19"
        ],
        "Ymax": [
          "19"
        ],
        "Ymin": [
          "-19"
        ],
        "Zmax": [
          "19"
        ],
        "Zmin": [
          "-19"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "P_Skeletal Sphere by Abderrahman Taha 08/12/2015"
        ],
        "Name": [
          "P_Skeletal Sphere"
        ],
        "Component": [
          "P_Skeletal Sphere"
        ],
        "Const": [
          "M=4",
          "N=10",
          "P=0DOTSYMBOL7"
        ],
        "Funct": [
          "P_Skeletal =cos(x)+cos(y)+cos(z)+0DOTSYMBOL51*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+1DOTSYMBOL2",
          "isoCondition_0=((x-pi)^2-(pi-P+ 0DOTSYMBOL01)^2)",
          "isoCondition_1=((x-pi)^2-(pi-P)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,P_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),N*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2(x,y,z,t)"
        ],
        "Xmax": [
          "19"
        ],
        "Xmin": [
          "-19"
        ],
        "Ymax": [
          "19"
        ],
        "Ymin": [
          "-19"
        ],
        "Zmax": [
          "19"
        ],
        "Zmin": [
          "-19"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "P_Skeletal Tori by Abderrahman Taha 08/12/2015"
        ],
        "Name": [
          "P_Skeletal Tori"
        ],
        "Component": [
          "P_Skeletal Tori"
        ],
        "Const": [
          "M=1",
          "N=10",
          "P=7"
        ],
        "Funct": [
          "P_Skeletal=cos(x)+cos(y)+cos(z)+0DOTSYMBOL51*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+1DOTSYMBOL2",
          "isoCondition_0=((x-pi)^2-(pi + 0DOTSYMBOL05)^2)",
          "isoCondition_1=((x-pi)^2-(pi)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,P_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "30"
        ],
        "Xmin": [
          "-30"
        ],
        "Ymax": [
          "30"
        ],
        "Ymin": [
          "-30"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "W_Skeletal Cylinder by Abderrahman Taha 07/12/2015"
        ],
        "Name": [
          "W_Skeletal Cylinder"
        ],
        "Component": [
          "W_Skeletal Cylinder"
        ],
        "Const": [
          "M=1",
          "N=8",
          "P=4"
        ],
        "Funct": [
          "W_Skeletal=cos(2*x)+cos(2*y)+cos(2*z)-1DOTSYMBOL95*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+2DOTSYMBOL8",
          "isoCondition_0=(x^2-(pi+ 0DOTSYMBOL5)^2)",
          "isoCondition_1=(x^2-(pi+ 0DOTSYMBOL3)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,W_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2(x,y,z,t)"
        ],
        "Xmax": [
          "11"
        ],
        "Xmin": [
          "-11"
        ],
        "Ymax": [
          "26"
        ],
        "Ymin": [
          "-26"
        ],
        "Zmax": [
          "11"
        ],
        "Zmin": [
          "-11"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "W_Skeletal Tori by Abderrahman Taha 07/12/2015"
        ],
        "Name": [
          "W_Skeletal Tori"
        ],
        "Component": [
          "W_Skeletal Tori"
        ],
        "Const": [
          "M=1",
          "N=10",
          "P=7"
        ],
        "Funct": [
          "W_Skeletal=cos(2*x)+cos(2*y)+cos(2*z)-1DOTSYMBOL95*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+2DOTSYMBOL8",
          "isoCondition_0=(x^2-(pi+ 0DOTSYMBOL5)^2)",
          "isoCondition_1=(x^2-(pi+ 0DOTSYMBOL3)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,W_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "26"
        ],
        "Xmin": [
          "-26"
        ],
        "Ymax": [
          "26"
        ],
        "Ymin": [
          "-26"
        ],
        "Zmax": [
          "12"
        ],
        "Zmin": [
          "-12"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "W_Skeletal Sphere by Abderrahman Taha 07/12/2015"
        ],
        "Name": [
          "W_Skeletal Sphere"
        ],
        "Component": [
          "W_Skeletal Sphere"
        ],
        "Const": [
          "M=1",
          "N=10",
          "P=7"
        ],
        "Funct": [
          "W_Skeletal=cos(2*x)+cos(2*y)+cos(2*z)-1DOTSYMBOL95*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+2DOTSYMBOL8",
          "isoCondition_0=(x^2-(pi+ 0DOTSYMBOL5)^2)",
          "isoCondition_1=(x^2-(pi+ 0DOTSYMBOL3)^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,W_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),P*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2(x,y,z,t)"
        ],
        "Xmax": [
          "16"
        ],
        "Xmin": [
          "-16"
        ],
        "Ymax": [
          "16"
        ],
        "Ymin": [
          "-16"
        ],
        "Zmax": [
          "16"
        ],
        "Zmin": [
          "-16"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Diamond Sphere by Abderrahman Taha 07/12/2015"
        ],
        "Name": [
          "Diamond Sphere"
        ],
        "Component": [
          "Diamond Sphere"
        ],
        "Const": [
          "N=8",
          "M=4"
        ],
        "Funct": [
          "Diamond =sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
          "isoCondition_0=(x^2-2DOTSYMBOL2^2)",
          "isoCondition_1=(x^2-2^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,Diamond(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),N*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2(x,y,z,t)"
        ],
        "Xmax": [
          "15"
        ],
        "Xmin": [
          "-15"
        ],
        "Ymax": [
          "15"
        ],
        "Ymin": [
          "-15"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Neovius Sphere by Abderrahman Taha 05/12/2015"
        ],
        "Name": [
          "Neovius Sphere"
        ],
        "Component": [
          "Neovius Sphere"
        ],
        "Const": [
          "N=10",
          "M=4"
        ],
        "Funct": [
          "Neovius =3*(cos(x)+cos(y)+cos(z))+7*cos(x)*cos(y)*cos(z)",
          "isoCondition_0=(x^2-2DOTSYMBOL2^2)",
          "isoCondition_1=(x^2-1DOTSYMBOL6^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,Neovius(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),10*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2(x,y,z,t)"
        ],
        "Xmax": [
          "15"
        ],
        "Xmin": [
          "-15"
        ],
        "Ymax": [
          "15"
        ],
        "Ymin": [
          "-15"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Neovius Tori by Abderrahman Taha 06/12/2015"
        ],
        "Name": [
          "Neovius Tori"
        ],
        "Component": [
          "Neovius Tori"
        ],
        "Const": [
          "M=1",
          "N=10"
        ],
        "Funct": [
          "Neovius=3*(cos(x)+cos(y)+cos(z))+7*cos(x)*cos(y)*cos(z)",
          "isoCondition_0=(x^2-2DOTSYMBOL4^2)",
          "isoCondition_1=(x^2-1DOTSYMBOL6^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,Neovius(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "25"
        ],
        "Xmin": [
          "-25"
        ],
        "Ymax": [
          "25"
        ],
        "Ymin": [
          "-25"
        ],
        "Zmax": [
          "10DOTSYMBOL5"
        ],
        "Zmin": [
          "-10DOTSYMBOL5"
        ]
      }
    },
    {
      "Iso3D": {
        "Name": [
          "Diamond Tori"
        ],
        "Description": [
          "Diamond Tori by Abderrahman Taha 06/12/2015"
        ],
        "Component": [
          "Diamond Tori"
        ],
        "Const": [
          "M=1",
          "N=10"
        ],
        "Funct": [
          "Diamond=sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
          "isoCondition_0=(x^2-2DOTSYMBOL2^2)",
          "isoCondition_1=(x^2-1DOTSYMBOL6^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,Diamond(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "25"
        ],
        "Xmin": [
          "-25"
        ],
        "Ymax": [
          "25"
        ],
        "Ymin": [
          "-25"
        ],
        "Zmax": [
          "10DOTSYMBOL5"
        ],
        "Zmin": [
          "-10DOTSYMBOL5"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Sleeping bugs by Abderrahman Taha 06/12/2015"
        ],
        "Name": [
          "Sleeping bugs"
        ],
        "Component": [
          "Sleeping Bugs"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=3"
        ],
        "Funct": [
          "Tickness= 0DOTSYMBOL4*(- 0DOTSYMBOL5*(abs(sin(15*u)*cos(15*v)))^9 + 0DOTSYMBOL35*((sin(2*N*u))))",
          "Fx=-cos(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
          "Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
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
          "Gx=Fx(u,v,t)+Tickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Tickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Tickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=0DOTSYMBOL81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))+ 0DOTSYMBOL3",
          "B=0DOTSYMBOL8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(2*x,2*y,2*z,4,2,0)+NoiseP(2*x,2*y,2*z,4,12,1/10)"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Gyroid Tori by Abderrahman Taha 06/12/2015"
        ],
        "Name": [
          "Gyroid Tori"
        ],
        "Component": [
          "Gyroid Tori"
        ],
        "Const": [
          "N=10"
        ],
        "Funct": [
          "Gyroid=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "isoCondition_0=(x^2-2DOTSYMBOL2^2)",
          "isoCondition_1=(x^2-1DOTSYMBOL6^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,Gyroid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "25"
        ],
        "Xmin": [
          "-25"
        ],
        "Ymax": [
          "25"
        ],
        "Ymin": [
          "-25"
        ],
        "Zmax": [
          "10DOTSYMBOL5"
        ],
        "Zmin": [
          "-10DOTSYMBOL5"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Gyroid Sphere by Abderrahman Taha 05/12/2015"
        ],
        "Name": [
          "Gyroid Sphere"
        ],
        "Component": [
          "Gyroid Sphere"
        ],
        "Const": [
          "N=18"
        ],
        "Funct": [
          "Gyroid=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "isoCondition_0=(x^2-2DOTSYMBOL2^2)",
          "isoCondition_1=(x^2-1DOTSYMBOL6^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,Gyroid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),10*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2(x,y,z,t)"
        ],
        "Xmax": [
          "15"
        ],
        "Xmin": [
          "-15"
        ],
        "Ymax": [
          "15"
        ],
        "Ymin": [
          "-15"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Schwarz Cylinder by Abderrahman Taha 05/12/2015"
        ],
        "Name": [
          "Schwarz Cylinder"
        ],
        "Component": [
          "Schwarz Cylinder"
        ],
        "Const": [
          "N=8"
        ],
        "Funct": [
          "Schwarz=cos(x) + cos(y) + cos(z)",
          "isoCondition_0=(x^2-3DOTSYMBOL2^2)",
          "isoCondition_1=(x^2-2DOTSYMBOL6^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,-Schwarz(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+z*z)-12),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2(x,y,z,t)"
        ],
        "Xmax": [
          "15"
        ],
        "Xmin": [
          "-15"
        ],
        "Ymax": [
          "25"
        ],
        "Ymin": [
          "-25"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Lidinoid Sphere by Abderrahman Taha 05/12/2015"
        ],
        "Name": [
          "Lidinoid Sphere"
        ],
        "Component": [
          "Lidinoid Sphere"
        ],
        "Const": [
          "N=8"
        ],
        "Funct": [
          "Lidinoid=((1/2)*(sin(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*sin(x)+sin(2*z)*cos(x)*sin(y))-(1/2)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+0DOTSYMBOL15)",
          "isoCondition_0=(x^2-2DOTSYMBOL6^2)",
          "isoCondition_1=(x^2-2DOTSYMBOL4^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,-Lidinoid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-12),10*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)",
          "isoTransform3=-isoTransform((sqrt(x*x+y*y+z*z)-12),y,N*atan2(z,x),t)"
        ],
        "Fxyz": [
          "-isoTransform2(x,y,z,t)"
        ],
        "Xmax": [
          "15"
        ],
        "Xmin": [
          "-15"
        ],
        "Ymax": [
          "15"
        ],
        "Ymin": [
          "-15"
        ],
        "Zmax": [
          "15"
        ],
        "Zmin": [
          "-15"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Lidinoid Torus by Abderrahman Taha 02/12/2015"
        ],
        "Name": [
          "Lidinoid Torus"
        ],
        "Component": [
          "Neovius Torus_1"
        ],
        "Const": [
          "N=8"
        ],
        "Funct": [
          "Lidinoid=((1/2)*(sin(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*sin(x)+sin(2*z)*cos(x)*sin(y))-(1/2)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+0DOTSYMBOL15)",
          "isoCondition_0=(x^2+z^2-2DOTSYMBOL6^2)",
          "isoCondition_1=(x^2+z^2-2DOTSYMBOL4^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,-Lidinoid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))"
        ],
        "Fxyz": [
          "isoTransform((sqrt(x*x+y*y)-7),N*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "10"
        ],
        "Xmin": [
          "-10"
        ],
        "Ymax": [
          "10"
        ],
        "Ymin": [
          "-10"
        ],
        "Zmax": [
          "2DOTSYMBOL5"
        ],
        "Zmin": [
          "-2DOTSYMBOL5"
        ]
      }
    },
    {
      "Param4D": {
        "Name": [
          "4D Tube"
        ],
        "Description": [
          "4D Tube by Abderrahman Taha 03/12/2015"
        ],
        "Component": [
          "4DTube"
        ],
        "Fw": [
          " 0DOTSYMBOL3*(sin(v)+cos(4*u))"
        ],
        "Fx": [
          "cos(u)"
        ],
        "Fy": [
          "sin(u)"
        ],
        "Fz": [
          " 0DOTSYMBOL3*(cos(v)+sin(4*u))"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "-pi"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      }
    },
    {
      "Iso3D": {
        "Name": [
          "Double Twist Neovius Torus"
        ],
        "Component": [
          "Neovius Torus"
        ],
        "Description": [
          "Double Twist Neovius Torus by Abderrahman Taha 02/12/2015"
        ],
        "Funct": [
          "Iso=3*(cos(x)+cos(y)+cos(z))+4*cos(x)*cos(y)*cos(z)",
          "isoCondition_0=(x^2+(z/9)^2-3DOTSYMBOL2^2)",
          "isoCondition_1=(x^2+(z/9)^2-3^2)",
          "isoTransform_1=if(isoCondition_0(x,y,z,t)<0,Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform_2=if(isoCondition_0(x,y,z,t)<0,-Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform_3 = isoTransform_2((sqrt(x*x+y*y)-3),atan2(y,x),z,t)"
        ],
        "Fxyz": [
          "isoTransform_3(x, (sqrt(y*y+z*z)-8) , 3*atan2(z,y),t)"
        ],
        "Xmax": [
          "6"
        ],
        "Xmin": [
          "-6"
        ],
        "Ymax": [
          "14"
        ],
        "Ymin": [
          "-14"
        ],
        "Zmax": [
          "14"
        ],
        "Zmin": [
          "-14"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Neovius Torus_1 by Abderrahman Taha 02/12/2015"
        ],
        "Name": [
          "Neovius Torus"
        ],
        "Component": [
          "Neovius Torus_1"
        ],
        "Const": [
          "N=12"
        ],
        "Funct": [
          "Iso=3*(cos(x)+cos(y)+cos(z))+4*cos(x)*cos(y)*cos(z)",
          "isoCondition_0=(x^2+z^2-3DOTSYMBOL2^2)",
          "isoCondition_1=(x^2+z^2-3^2)",
          "isoTransform=if(isoCondition_0(x,y,z,t)<0,-Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))"
        ],
        "Fxyz": [
          "isoTransform((sqrt(x*x+y*y)-7),N*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "10"
        ],
        "Xmin": [
          "-10"
        ],
        "Ymax": [
          "10"
        ],
        "Ymin": [
          "-10"
        ],
        "Zmax": [
          "3DOTSYMBOL5"
        ],
        "Zmin": [
          "-3DOTSYMBOL5"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Vase_3 by Abderrahman Taha 30/11/2015"
        ],
        "Name": [
          "Vase"
        ],
        "Component": [
          "Vase",
          "Head",
          "Bottom"
        ],
        "Const": [
          "Thick = 0DOTSYMBOL05"
        ],
        "Funct": [
          "CarvinCondition=abs((z-1) - 0DOTSYMBOL8*cos(18*atan2(x,y)/pi))<1DOTSYMBOL3|abs((z+3) - 0DOTSYMBOL3*cos(18*atan2(x,y)/pi+pi/4))<0DOTSYMBOL5",
          "Torus=(sqrt(x*x+y*y)-3)^2+z*z-1",
          "Bottom=(x*x+y*y+z*z-1)",
          "ThickIsoExterior=(x*x/3+y*y/3-abs(1DOTSYMBOL5*sin(2*z/pi+ 0DOTSYMBOL3)+1DOTSYMBOL8))*(x*x/3+y*y/3-abs(1DOTSYMBOL5*sin(2*z/pi+ 0DOTSYMBOL3)+1DOTSYMBOL8))-Thick",
          "Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "Rapport=(sqrt((-sin(x)*sin(y)+cos(z)*cos(x))*(-sin(x)*sin(y)+cos(z)*cos(x))+(-sin(y)*sin(z)+cos(x)*cos(y))*(-sin(y)*sin(z)+cos(x)*cos(y))+(-sin(z)*sin(x)+cos(y)*cos(z))*(-sin(z)*sin(x)+cos(y)*cos(z))))",
          "Iso4=(Iso(x+t*(-sin(x)*sin(y)+cos(z)*cos(x))* 0DOTSYMBOL2/Rapport(x,y,z,t),y+t*(-sin(y)*sin(z)+cos(x)*cos(y))* 0DOTSYMBOL2/Rapport(x,y,z,t),z+t*(-sin(z)*sin(x)+cos(y)*cos(z))* 0DOTSYMBOL2/Rapport(x,y,z,t),t))",
          "ThickIso2=(Iso4(x,y,z,-1)*Iso4(x,y,z,1))",
          "isoTransform_2=if(CarvinCondition(x,y,z,t)=0,ThickIsoExterior(x,y,z,t),1)",
          "Iso6=(Iso(x+t*(-sin(x)*sin(y)+cos(z)*cos(x))*1DOTSYMBOL2/Rapport(x,y,z,t),y+t*(-sin(y)*sin(z)+cos(x)*cos(y))*1DOTSYMBOL2/Rapport(x,y,z,t),z+t*(-sin(z)*sin(x)+cos(y)*cos(z))*1DOTSYMBOL2/Rapport(x,y,z,t),t))",
          "isoTransform_6=if(CarvinCondition(x,y,z,t)&ThickIsoExterior(x,y,z,t)<0,-ThickIso2(6*x,6*y,6*z,t) * Iso6(x*6,y*6,z*6, -1) *(Iso6(x*6,y*6,z*6,1)),1)"
        ],
        "Fxyz": [
          "isoTransform_2(x,y,-z,t) * isoTransform_6(x,y,-z,t)",
          "Torus(1DOTSYMBOL7*x,1DOTSYMBOL7*y,2DOTSYMBOL2*(z+cos(pi/4*sqrt(x*x+y*y))) -10DOTSYMBOL6,t)",
          "Bottom(x/2DOTSYMBOL4,y/2DOTSYMBOL4,2*(z+5DOTSYMBOL1),t)"
        ],
        "Xmax": [
          "3DOTSYMBOL5",
          "5",
          "3"
        ],
        "Xmin": [
          "-3DOTSYMBOL5",
          "-5",
          "-3"
        ],
        "Ymax": [
          "3DOTSYMBOL5",
          "5",
          "3"
        ],
        "Ymin": [
          "-3DOTSYMBOL5",
          "-5",
          "-3"
        ],
        "Zmax": [
          "4DOTSYMBOL5",
          "10",
          "-2"
        ],
        "Zmin": [
          "-5",
          "0",
          "-7"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL95*abs(cos(z*y*x*y))",
          "G=0DOTSYMBOL45*abs(cos(z*y*x*y))",
          "B=0DOTSYMBOL02*abs(cos(-z*x*z*x*y*y))",
          "T=1"
        ],
        "Name": "Granit_1",
        "Noise": "NoiseP(x,y,z,10,7,12/100)"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Diamon Torus by Abderrahman Taha 28/11/2015"
        ],
        "Name": [
          "Diamon Torus"
        ],
        "Component": [
          "Diamon Torus_1",
          "DiamonTorus_2"
        ],
        "Funct": [
          "Iso=sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
          "isoCondition_0=(x^2+z^2-3DOTSYMBOL2^2)",
          "isoCondition_1=(x^2+z^2-3^2)",
          "isoTransform_1=if(isoCondition_0(x,y,z,t)<0,Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
          "isoTransform_2=if(isoCondition_0(x,y,z,t)<0,-Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))"
        ],
        "Fxyz": [
          "isoTransform_1((sqrt(x*x+y*y)-6),12*atan2(y,x),z,t)",
          "isoTransform_2((sqrt(x*x+y*y)-6),12*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "9DOTSYMBOL8",
          "9DOTSYMBOL8"
        ],
        "Xmin": [
          "-9DOTSYMBOL8",
          "-9DOTSYMBOL8"
        ],
        "Ymax": [
          "9DOTSYMBOL8",
          "9DOTSYMBOL8"
        ],
        "Ymin": [
          "-9DOTSYMBOL8",
          "-9DOTSYMBOL8"
        ],
        "Zmax": [
          "3DOTSYMBOL5",
          "3DOTSYMBOL5"
        ],
        "Zmin": [
          "-3DOTSYMBOL5",
          "-3DOTSYMBOL5"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Octahedron of Octahedra by Abderrahman Taha 04/03/2017"
        ],
        "Name": [
          "OctahedronOfOctahedra"
        ],
        "Component": [
          "OctahedronOfOctahedra"
        ],
        "Const": [
          "N=7"
        ],
        "Funct": [
          "Octahedron=(abs(x)+abs(y)+abs(z))-(1/(2*N))",
          "Octahedr = ( (abs(x- 0DOTSYMBOL5)+abs(y- 0DOTSYMBOL5)+abs(z- 0DOTSYMBOL5))-(1/2))",
          "Octahedr1 = ( (abs(x- 0DOTSYMBOL5)+abs(y- 0DOTSYMBOL5)+abs(z- 0DOTSYMBOL5))-(1/2-1/(N)) )"
        ],
        "Fxyz": [
          "if(Octahedr(x,y,z,t)<0 & Octahedr1(x,y,z,t)>0, Octahedron((x%(1/N))-1/(2*N),(y%(1/N))-1/(2*N),(z%(1/N))-1/(2*N),t), 1) "
        ],
        "Xmax": [
          "1"
        ],
        "Xmin": [
          "0"
        ],
        "Ymax": [
          "1"
        ],
        "Ymin": [
          "0"
        ],
        "Zmax": [
          "1"
        ],
        "Zmin": [
          "0"
        ]
      },
      "Sliders": {
        "Max": [
          "50"
        ],
        "Min": [
          "0"
        ],
        "Name": [
          "N"
        ],
        "Position": [
          "7"
        ],
        "Step": [
          "1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Cube of Octahedrons by Abderrahman Taha 27/11/2015"
        ],
        "Name": [
          "Cube of Octahedrons"
        ],
        "Component": [
          " CubeOctahedrons"
        ],
        "Const": [
          "N=20"
        ],
        "Funct": [
          "Octahedron=(abs(x)+abs(y)+abs(z))-(1/(2*N))",
          "Cube = (((x < 1/N | x>(1-1/N)) | (y < 1/N | y>(1-1/N)) | (z < 1/N | z>(1-1/N))))"
        ],
        "Fxyz": [
          "if(Cube(x,y,z,t), Octahedron((x%(1/N))-1/(2*N),(y%(1/N))-1/(2*N),(z%(1/N))-1/(2*N),t), 1) "
        ],
        "Xmax": [
          "1"
        ],
        "Xmin": [
          "0"
        ],
        "Ymax": [
          "1"
        ],
        "Ymin": [
          "0"
        ],
        "Zmax": [
          "1"
        ],
        "Zmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Cube of Spheres (update) by Abderrahman Taha 03/03/2017"
        ],
        "Name": [
          "Cube of Spheres"
        ],
        "Component": [
          " CubeSpheres"
        ],
        "Const": [
          "N=5"
        ],
        "Funct": [
          "Sphere=sqrt(x*x+y*y+z*z)-1/(2*N+0DOTSYMBOL001)"
        ],
        "Fxyz": [
          "if((((x < 1/N | x>(1-1/N)) | (y < 1/N | y>(1-1/N)) | (z < 1/N | z>(1-1/N)))), Sphere((x%(1/N))-1/(2*N),(y%(1/N))-1/(2*N),(z%(1/N))-1/(2*N),t), 1) "
        ],
        "Xmax": [
          "1"
        ],
        "Xmin": [
          "0"
        ],
        "Ymax": [
          "1"
        ],
        "Ymin": [
          "0"
        ],
        "Zmax": [
          "1"
        ],
        "Zmin": [
          "0"
        ]
      },
      "Sliders": {
        "Max": [
          "20"
        ],
        "Min": [
          "0"
        ],
        "Name": [
          "N"
        ],
        "Position": [
          "5"
        ],
        "Step": [
          "1"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Belted Torus_1 by Abderrahman Taha 26/11/2015"
        ],
        "Name": [
          "Belted Torus"
        ],
        "Component": [
          "BeltedTorus"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001",
          "N=2"
        ],
        "Funct": [
          "Thickness=0DOTSYMBOL4*sin(2*N*v)^100 + 0DOTSYMBOL4*sin(N*v-u)^100",
          "Fx=(N/2+1+ 0DOTSYMBOL6*cos(u))*cos(v)",
          "Fy=0DOTSYMBOL6*sin(u)",
          "Fz=(N/2+1+ 0DOTSYMBOL6*cos(u))*sin(v)",
          "DFxu=((Fx(u,v,t)-Fx(u+cu,v,t))/cu)",
          "DFxv=((Fx(u,v,t)-Fx(u,v+cv,t))/cv)",
          "DFyu=((Fy(u,v,t)-Fy(u+cu,v,t))/cu)",
          "DFyv=((Fy(u,v,t)-Fy(u,v+cv,t))/cv)",
          "DFzu=((Fz(u,v,t)-Fz(u+cu,v,t))/cu)",
          "DFzv=((Fz(u,v,t)-Fz(u,v+cv,t))/cv)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t)-DFzu(u,v,t)*DFyv(u,v,t))",
          "n2=(DFzu(u,v,t)*DFxv(u,v,t)-DFxu(u,v,t)*DFzv(u,v,t))",
          "n3=(DFxu(u,v,t)*DFyv(u,v,t)-DFyu(u,v,t)*DFxv(u,v,t))",
          "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)^3",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=0DOTSYMBOL8*abs(cos((pi*(x*x+y*y+z*z))))",
          "B=0DOTSYMBOL6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
          "T=1"
        ],
        "Name": "Dream",
        "Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Spiral Schwarz Torus_1 by Abderrahman Taha 25/11/2015"
        ],
        "Name": [
          "Spiral Schwarz Torus"
        ],
        "Component": [
          "SpiralSchwarzTorus_1",
          "SpiralSchwarzTorus_2"
        ],
        "Const": [
          "N=1DOTSYMBOL4",
          "k=48"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
          "DFx=-sin(x)",
          "DFy=-sin(y)",
          "DFz=-sin(z)",
          "Rapport=sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z))",
          "Iso3=(Iso(x+sin(x)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "Iso4=(Iso(x+sin(x)*0DOTSYMBOL4/Rapport(x,y,z,t),y+sin(y)*0DOTSYMBOL4/Rapport(x,y,z,t),z+sin(z)*0DOTSYMBOL4/Rapport(x,y,z,t),t))",
          "Iso5=(Iso(x-sin(x)*0DOTSYMBOL4/Rapport(x,y,z,t),y-sin(y)*0DOTSYMBOL4/Rapport(x,y,z,t),z-sin(z)*0DOTSYMBOL4/Rapport(x,y,z,t),t))",
          "ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoCondition=(x^2+z^2-28)",
          "isoTransform_1=if(isoCondition(x,y,z,t)<0,ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)",
          "isoTransform_2=isoTransform_1(x*cos(pi*y/(k*pi))-z*sin(pi*y/(k*pi)),y,x*sin(pi*y/(k*pi))+z*cos(pi*y/(k*pi)),t)",
          "isoTransform_3=if(isoCondition(x,y,z,t)<0,-Iso3(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)",
          "isoTransform_4=isoTransform_3(x*cos(pi*y/(k*pi))-z*sin(pi*y/(k*pi)),y,x*sin(pi*y/(k*pi))+z*cos(pi*y/(k*pi)),t)"
        ],
        "Fxyz": [
          "isoTransform_2((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)",
          "isoTransform_4((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "15DOTSYMBOL5",
          "15DOTSYMBOL5"
        ],
        "Xmin": [
          "-15DOTSYMBOL5",
          "-15DOTSYMBOL5"
        ],
        "Ymax": [
          "15DOTSYMBOL5",
          "15DOTSYMBOL5"
        ],
        "Ymin": [
          "-15DOTSYMBOL5",
          "-15DOTSYMBOL5"
        ],
        "Zmax": [
          "5DOTSYMBOL5",
          "5DOTSYMBOL5"
        ],
        "Zmin": [
          "-5DOTSYMBOL5",
          "-5DOTSYMBOL5"
        ]
      }
    },
    {
      "Param4D": {
        "Description": [
          "Kinky 4D Clifford Torus by Aberrahman Taha 24/11/2015"
        ],
        "Name": [
          "Kinky 4D Clifford Torus"
        ],
        "Component": [
          "4DTorus"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001",
          "N=3"
        ],
        "Funct": [
          "Thickness=-abs( 0DOTSYMBOL1*cos(3*v-7*u)*sin(3*v))",
          "Fx=sin(u)",
          "Fy=cos(u)",
          "Fz=sin(v)",
          "DFxu=cos(u)",
          "DFyu=-sin(u)",
          "DFzv=cos(v)",
          "n1=(DFyu(u,v,t)*DFzv(u,v,t))",
          "n2=(-DFxu(u,v,t)*DFzv(u,v,t))",
          "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)"
        ],
        "Fw": [
          "cos(v)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Schwarz Torus_1 by Abderrahman Taha 24/11/2015"
        ],
        "Name": [
          "Schwarz Torus_1"
        ],
        "Component": [
          "SchwarzTorus_1",
          "SchwarzTorus_2"
        ],
        "Const": [
          "N=1DOTSYMBOL4"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
          "Iso3=(Iso(x+sin(x)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "Iso4=(Iso(x+sin(x)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "Iso5=(Iso(x-sin(x)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y-sin(y)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z-sin(z)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoCondition=(x^2+z^2-20)",
          "isoTransform_1=if(isoCondition(x,y,z,t)<0,ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)",
          "isoTransform_2=if(isoCondition(x,y,z,t)<0,-Iso3(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)"
        ],
        "Fxyz": [
          "-isoTransform_1((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)",
          "-isoTransform_2((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "14",
          "16"
        ],
        "Xmin": [
          "-14",
          "-16"
        ],
        "Ymax": [
          "14",
          "16"
        ],
        "Ymin": [
          "-14",
          "-16"
        ],
        "Zmax": [
          "6",
          "6"
        ],
        "Zmin": [
          "-6",
          "-6"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Schwarz Torus_2 by Abderrahman Taha 23/11/2015"
        ],
        "Name": [
          "Schwarz Torus_2"
        ],
        "Component": [
          "SchwarzTorus_1",
          "SchwarzTorus_2",
          "SchwarzTorus_3"
        ],
        "Const": [
          "N=1DOTSYMBOL4"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
          "Iso3=(Iso(x+sin(x)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "Iso2=(Iso(x-sin(x)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y-sin(y)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z-sin(z)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "Iso4=(Iso(x+sin(x)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "Iso5=(Iso(x-sin(x)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y-sin(y)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z-sin(z)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoCondition=(x^2+z^2-28)",
          "isoTransform_1=if(isoCondition(x,y,z,t)<0,ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)",
          "isoTransform_2=if(isoCondition(x,y,z,t)<0,-Iso3(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)",
          "isoTransform_3=if(isoCondition(x,y,z,t)<0,Iso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)"
        ],
        "Fxyz": [
          "-isoTransform_1((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)",
          "isoTransform_2((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)",
          "-isoTransform_3((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "16",
          "16",
          "16"
        ],
        "Xmin": [
          "-16",
          "-16",
          "-16"
        ],
        "Ymax": [
          "16",
          "16",
          "16"
        ],
        "Ymin": [
          "-16",
          "-16",
          "-16"
        ],
        "Zmax": [
          "6",
          "6",
          "6"
        ],
        "Zmin": [
          "-6",
          "-6",
          "-6"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Schwarz Torus_3 by Abderrahman Taha 23/11/2015"
        ],
        "Name": [
          "Schwarz Torus_3"
        ],
        "Component": [
          "SchwarzTorus"
        ],
        "Const": [
          "N=2"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
          " 0DOTSYMBOL4= ( 0DOTSYMBOL4)",
          "DFx= -sin(x)",
          "DFy= -sin(y)",
          "DFz= -sin(z)",
          "Rapport= sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z))",
          "Iso4= (Iso(x+sin(x)* 0DOTSYMBOL4/Rapport(x,y,z,t),y+sin(y)* 0DOTSYMBOL4/Rapport(x,y,z,t),z+sin(z)* 0DOTSYMBOL4/Rapport(x,y,z,t),t))",
          "Iso5= (Iso(x-sin(x)* 0DOTSYMBOL4/Rapport(x,y,z,t),y-sin(y)* 0DOTSYMBOL4/Rapport(x,y,z,t),z-sin(z)* 0DOTSYMBOL4/Rapport(x,y,z,t),t))",
          "ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoCondition=(x^2+z^2-28)",
          "isoTransform_1=if(isoCondition(x,y,z,t)<0,ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)"
        ],
        "Fxyz": [
          "isoTransform_1((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "15"
        ],
        "Xmin": [
          "-15"
        ],
        "Ymax": [
          "15"
        ],
        "Ymin": [
          "-15"
        ],
        "Zmax": [
          "5"
        ],
        "Zmin": [
          "-5"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Arena_2 by Abderrahman Taha 23/11/2015"
        ],
        "Name": [
          "Arena"
        ],
        "Component": [
          "Arena"
        ],
        "Const": [
          "cx=0DOTSYMBOL00001",
          "cy=0DOTSYMBOL00001",
          "cz=0DOTSYMBOL00001",
          "N=20"
        ],
        "Funct": [
          "Scherk=sinh(x)*sinh(y)-4*sin(z)",
          "Scherk2=Scherk(x,sqrt(y*y+z*z)-16,N*atan2(z,y),t)",
          "Thickness2=( 0DOTSYMBOL6)",
          "IsoExterior=Scherk2(x,y,z,t)",
          "DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
          "DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
          "DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
          "Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
          "Iso3=(IsoExterior(x-DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y-DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z-DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
          "Iso2=(IsoExterior(x+DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y+DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z+DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
          "ThickIsoExterior=(Iso2(x,y,z,t)*Iso3(x,y,z,t))"
        ],
        "Fxyz": [
          "if((sqrt(x*x+y*y+z*z) - 27)<0 & abs(x)<10 ,ThickIsoExterior(x,y,z,t), 1)"
        ],
        "Xmax": [
          "10DOTSYMBOL1"
        ],
        "Xmin": [
          "-10DOTSYMBOL1"
        ],
        "Ymax": [
          "28"
        ],
        "Ymin": [
          "-28"
        ],
        "Zmax": [
          "28"
        ],
        "Zmin": [
          "-28"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Schwarz Cube Torus by Abderrahman Taha 22/11/2015"
        ],
        "Name": [
          "Schwarz Cube Torus"
        ],
        "Component": [
          "SchwarzCubeTorus_1",
          "SchwarzCubeTorus_2",
          "SchwarzCubeTorus_3",
          "SchwarzCubeTorus_4"
        ],
        "Const": [
          "k=6"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
          "Iso4=(Iso(x+sin(x)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "Iso5=(Iso(x-sin(x)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y-sin(y)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z-sin(z)* 0DOTSYMBOL4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
          "ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoCondition=(x^20+(y/4)^20+z^20-3DOTSYMBOL23^20)",
          "isoTransform_2=if(isoCondition(x,y,z,t)<0,ThickIso2(k*x,k*y,k*z,t),1)",
          "isoTransform_3=isoTransform_2(x*cos(pi*y/(k*pi))-z*sin(pi*y/(k*pi)),y,x*sin(pi*y/(k*pi))+z*cos(pi*y/(k*pi)),t)"
        ],
        "Fxyz": [
          "-isoTransform_3(sqrt(x*x+y*y)-6DOTSYMBOL5,3*atan2(y,x),z,t)",
          "-isoTransform_3(sqrt(x*x+y*y)-6DOTSYMBOL5,3*atan2(y,x),z,t)",
          "-isoTransform_3(sqrt(x*x+y*y)-6DOTSYMBOL5,3*atan2(y,x),z,t)",
          "-isoTransform_3(sqrt(x*x+y*y)-6DOTSYMBOL5,3*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "0",
          "0",
          "11",
          "11"
        ],
        "Xmin": [
          "-11",
          "-11",
          "0",
          "0"
        ],
        "Ymax": [
          "0",
          "11",
          "0",
          "11"
        ],
        "Ymin": [
          "-11",
          "0",
          "-11",
          "0"
        ],
        "Zmax": [
          "5",
          "5",
          "5",
          "5"
        ],
        "Zmin": [
          "-5",
          "-5",
          "-5",
          "-5"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL8",
          "G=0DOTSYMBOL6",
          "B=0DOTSYMBOL1",
          "T=1"
        ],
        "Name": "Gold",
        "Noise": "1"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Gyroidal Torus by Abderrahman Taha 21/11/2015"
        ],
        "Name": [
          "Gyroidal Torus"
        ],
        "Component": [
          "GyroidalTorus"
        ],
        "Const": [
          "cx=0DOTSYMBOL0001",
          "cy=0DOTSYMBOL0001",
          "cz=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "Thickness2= ( 0DOTSYMBOL4)",
          "DFx= ((Iso(x,y,z,t)-Iso(x+cx,y,z,t))/cx)",
          "DFy= ((Iso(x,y,z,t)-Iso(x,y+cy,z,t))/cy)",
          "DFz= ((Iso(x,y,z,t)-Iso(x,y,z+cz,t))/cz)",
          "Rapport= (sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
          "Iso4= (Iso(x-DFx(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),y-DFy(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),z-DFz(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),t))",
          "Iso5= (Iso(x+DFx(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),y+DFy(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),z+DFz(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),t))",
          "ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoCondition=(x^2+z^2-16)",
          "isoTransform_1=if(isoCondition(x,y,z,t)<0,ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)"
        ],
        "Fxyz": [
          "isoTransform_1((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)"
        ],
        "Xmax": [
          "14"
        ],
        "Xmin": [
          "-14"
        ],
        "Ymax": [
          "14"
        ],
        "Ymin": [
          "-14"
        ],
        "Zmax": [
          "4"
        ],
        "Zmin": [
          "-4"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "iWP Skeletal Graphis by Abderrahman Taha 20/11/2015"
        ],
        "Name": [
          "W_SkeletalGraph"
        ],
        "Component": [
          "W_SkeletalGraphis"
        ],
        "Fxyz": [
          "-(cos(2*x)+cos(2*y)+cos(2*z)-1DOTSYMBOL95*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+2DOTSYMBOL8)"
        ],
        "Xmax": [
          "4*pi"
        ],
        "Xmin": [
          "0"
        ],
        "Ymax": [
          "4*pi"
        ],
        "Ymin": [
          "0"
        ],
        "Zmax": [
          "4*pi"
        ],
        "Zmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          " Pseudo Chmutov_2 by Abderrahman Taha 19/11/2015"
        ],
        "Name": [
          "Pseudo Chmutov"
        ],
        "Component": [
          "PseudoChmutov",
          "PseudoChmutov_01"
        ],
        "Const": [
          "M=7",
          "N=16"
        ],
        "Fxyz": [
          "-((x^N+y^N+z^N)-(cos(M*x)+cos(M*y)+cos(M*z))- 0DOTSYMBOL1)",
          "((x^N+y^N+z^N)-(cos((2*M)*x)+cos((2*M)*y)+cos((2*M)*z))+ 0DOTSYMBOL5)"
        ],
        "Xmax": [
          "1DOTSYMBOL1",
          "1DOTSYMBOL1"
        ],
        "Xmin": [
          "-1DOTSYMBOL1",
          "-1DOTSYMBOL1"
        ],
        "Ymax": [
          "1DOTSYMBOL1",
          "1DOTSYMBOL1"
        ],
        "Ymin": [
          "-1DOTSYMBOL1",
          "-1DOTSYMBOL1"
        ],
        "Zmax": [
          "1DOTSYMBOL1",
          "1DOTSYMBOL1"
        ],
        "Zmin": [
          "-1DOTSYMBOL1",
          "-1DOTSYMBOL1"
        ]
      }
    },
    {
      "Param4D": {
        "Description": [
          "4D Roller Coaster by Abderrahman Taha 16/11/2015"
        ],
        "Name": [
          "4D Roller Coaster"
        ],
        "Component": [
          "RollerCoaster"
        ],
        "Fx": [
          "sin(u)*(cos(v%(pi/30)))*cos((v-3*u)%(pi/30))"
        ],
        "Fy": [
          "cos(u)*(cos(v%(pi/30)))*cos((v-3*u)%(pi/30))"
        ],
        "Fz": [
          "sin(v-3*u)*(cos(v%(pi/30)))*cos((v-3*u)%(pi/30))"
        ],
        "Fw": [
          "cos(v-3*u)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "pi/1DOTSYMBOL2"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param4D": {
        "Description": [
          "4D Clliford Ribbon by Abderrahman Taha 16/11/2015"
        ],
        "Name": [
          "4D Clliford Ribbon"
        ],
        "Component": [
          "CllifordRibbon"
        ],
        "Fw": [
          "cos(v)"
        ],
        "Fx": [
          "sin(u-4*v)"
        ],
        "Fy": [
          "cos(u-4*v)"
        ],
        "Fz": [
          "sin(v)"
        ],
        "Umax": [
          "pi/1DOTSYMBOL5"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Matrix of Spheres by Abderrahman Taha 16/11/2015"
        ],
        "Name": [
          "Matrix of Spheres"
        ],
        "Component": [
          " MatrixofSpheres"
        ],
        "Const": [
          "N=2",
          "R=1/N"
        ],
        "Funct": [
          "Sphere=sqrt(x*x+y*y+z*z)-1/(2*N)"
        ],
        "Fxyz": [
          "-Sphere((x%(1/N))-1/(2*N),(y%(1/N))-1/(2*N),(z%(1/N))-1/(2*N),t)"
        ],
        "Xmax": [
          "1"
        ],
        "Xmin": [
          "0"
        ],
        "Ymax": [
          "1"
        ],
        "Ymin": [
          "0"
        ],
        "Zmax": [
          "1"
        ],
        "Zmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          " Pseudo Chmutov_2 by Abderrahman Taha 14/11/2015"
        ],
        "Name": [
          "Pseudo Chmutov_2"
        ],
        "Component": [
          "PseudoChmutov"
        ],
        "Const": [
          "M=7",
          "N=16"
        ],
        "Fxyz": [
          "-((x^N+y^N+z^N)-(cos(M*x)+cos(M*y)+cos(M*z))- 0DOTSYMBOL1)"
        ],
        "Xmax": [
          "1DOTSYMBOL1"
        ],
        "Xmin": [
          "-1DOTSYMBOL1"
        ],
        "Ymax": [
          "1DOTSYMBOL1"
        ],
        "Ymin": [
          "-1DOTSYMBOL1"
        ],
        "Zmax": [
          "1DOTSYMBOL1"
        ],
        "Zmin": [
          "-1DOTSYMBOL1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Ring of Fire_1 by Abderrahman Taha 11/11/2015"
        ],
        "Name": [
          "Ring of Fire"
        ],
        "Component": [
          "Ring"
        ],
        "Const": [
          "cx=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Scherk=sinh(x)*sinh(y)-5*sin(z)",
          "Scherk2=Scherk(x,(sqrt(y*y+x*x)-10),z,t)",
          "Thickness2=( 0DOTSYMBOL43)",
          "IsoExterior=Scherk2(x,(sqrt(y*y+z*z)-26),z,t)",
          "DFx2= ((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
          "DFy2= ((IsoExterior(x,y,z,t)-IsoExterior(x,y+cx,z,t))/cx)",
          "DFz2= ((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cx,t))/cx)",
          "Rapport2= (sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
          "Iso3= (IsoExterior(x-DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y-DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z-DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
          "Iso2= (IsoExterior(x+DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y+DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z+DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
          "ThickIsoExterior=(Iso2(x,y,z,t)*Iso3(x,y,z,t))"
        ],
        "Fxyz": [
          "if((sqrt(y*y+z*z)-37<0)&(sqrt(y*y+z*z)-16>0) & ( (sqrt(y*y+z*z)-26)^2+x*x-75>0 ),ThickIsoExterior(x,y,z,t),1)+ 0DOTSYMBOL1"
        ],
        "Xmax": [
          "11"
        ],
        "Xmin": [
          "-11"
        ],
        "Ymax": [
          "38"
        ],
        "Ymin": [
          "-38"
        ],
        "Zmax": [
          "38"
        ],
        "Zmin": [
          "-38"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL71",
          "G=1DOTSYMBOL1*abs(cos((x*x+y*y+z*z))*sin((x*x+y*y+z*z)/2))",
          "B=0DOTSYMBOL01*abs(cos((x*x+y*y+z*z))*cos((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "PerlinNoise",
        "Noise": "NoiseP(x,y,z,6,7/10,1)/30"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Bullet by Abderrahman Taha 10/11/2015"
        ],
        "Name": [
          "Bullet"
        ],
        "Component": [
          "Bullet1",
          "Bullet2"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=1DOTSYMBOL5"
        ],
        "Funct": [
          "Thickness1=if( t = 1, if ( abs(sin(4*u-v))<0DOTSYMBOL4,-1, -u*u*(cos(u) - sin(u)) ),if ( abs(sin(4*u-v))>0DOTSYMBOL4,-1,-u*u*(cos(u) - sin(u))))",
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
          "Gz=Fz(u,v,t)+Thickness1(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,1)",
          "Gx(u,v,0)"
        ],
        "Fy": [
          "Gy(u,v,1)",
          "Gy(u,v,0)"
        ],
        "Fz": [
          "Gz(u,v,1)",
          "Gz(u,v,0)"
        ],
        "Umax": [
          "pi/2",
          "pi/2"
        ],
        "Umin": [
          "-pi/2",
          "-pi/2"
        ],
        "Vmax": [
          "2*pi",
          "2*pi"
        ],
        "Vmin": [
          "0",
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Lobed Torus_1 by Abderrahman Taha 10/11/2015"
        ],
        "Name": [
          "Lobed Torus_1"
        ],
        "Component": [
          "LobedTorus"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001",
          "N=3"
        ],
        "Funct": [
          "Thickness=0DOTSYMBOL4*sin(2*N*v-u) + 0DOTSYMBOL9*sin((N*v)% pi/3)",
          "Fx=(N/2+1+ 0DOTSYMBOL6*cos(u))*cos(v)",
          "Fy=0DOTSYMBOL6*sin(u)",
          "Fz=(N/2+1+ 0DOTSYMBOL6*cos(u))*sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=0DOTSYMBOL8*abs(cos((pi*(x*x+y*y+z*z))))",
          "B=0DOTSYMBOL6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
          "T=1"
        ],
        "Name": "Dream",
        "Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Lobed Torus_2 by Abderrahman Taha 10/11/2015"
        ],
        "Name": [
          "Lobed Torus_2"
        ],
        "Component": [
          "LobedTorus"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001",
          "N=3"
        ],
        "Funct": [
          "Thickness=0DOTSYMBOL9*sin((N*v)% pi/3)",
          "Fx=(N/2+1+ 0DOTSYMBOL6*cos(u))*cos(v)",
          "Fy=0DOTSYMBOL6*sin(u)",
          "Fz=(N/2+1+ 0DOTSYMBOL6*cos(u))*sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=0DOTSYMBOL8*abs(cos((pi*(x*x+y*y+z*z))))",
          "B=0DOTSYMBOL6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
          "T=1"
        ],
        "Name": "Dream",
        "Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Lobed Torus_4 by Abderrahman Taha 08/11/2015"
        ],
        "Name": [
          "Lobed Torus_4"
        ],
        "Component": [
          "LobedTorus"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001",
          "N=3"
        ],
        "Funct": [
          "Thickness=0DOTSYMBOL4*sin(N*v)",
          "Fx=(N/2+1+ 0DOTSYMBOL6*cos(u))*cos(v)",
          "Fy=0DOTSYMBOL6*sin(u)",
          "Fz=(N/2+1+ 0DOTSYMBOL6*cos(u))*sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=0DOTSYMBOL8*abs(cos((pi*(x*x+y*y+z*z))))",
          "B=0DOTSYMBOL6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
          "T=1"
        ],
        "Name": "Dream",
        "Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Lobed Torus_5 by Abderrahman Taha 08/11/2015"
        ],
        "Name": [
          "Lobed Torus_5"
        ],
        "Component": [
          "LobedTorus"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001",
          "N=3"
        ],
        "Funct": [
          "Thickness=0DOTSYMBOL4*sin(N*v-u)^100",
          "Fx=(N/2+1+ 0DOTSYMBOL6*cos(u))*cos(v)",
          "Fy=0DOTSYMBOL6*sin(u)",
          "Fz=(N/2+1+ 0DOTSYMBOL6*cos(u))*sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=0DOTSYMBOL8*abs(cos((pi*(x*x+y*y+z*z))))",
          "B=0DOTSYMBOL6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
          "T=1"
        ],
        "Name": "Dream",
        "Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Lobed Torus_6 by Abderrahman Taha 08/11/2015"
        ],
        "Name": [
          "Lobed Torus_6"
        ],
        "Component": [
          "LobedTorus"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001",
          "N=3"
        ],
        "Funct": [
          "Thickness=0DOTSYMBOL4*sin(2*N*v-u)",
          "Fx=(N/2+1+ 0DOTSYMBOL6*cos(u))*cos(v)",
          "Fy=0DOTSYMBOL6*sin(u)",
          "Fz=(N/2+1+ 0DOTSYMBOL6*cos(u))*sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=0DOTSYMBOL8*abs(cos((pi*(x*x+y*y+z*z))))",
          "B=0DOTSYMBOL6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
          "T=1"
        ],
        "Name": "Dream",
        "Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Lobed Torus_7 by Abderrahman Taha 08/11/2015"
        ],
        "Name": [
          "Lobed Torus_7"
        ],
        "Component": [
          "LobedTorus"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001",
          "N=3"
        ],
        "Funct": [
          "Thickness=0DOTSYMBOL4*sin(N*v)^10",
          "Fx=(N/2+1+ 0DOTSYMBOL6*cos(u))*cos(v)",
          "Fy=0DOTSYMBOL6*sin(u)",
          "Fz=(N/2+1+ 0DOTSYMBOL6*cos(u))*sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=0DOTSYMBOL8*abs(cos((pi*(x*x+y*y+z*z))))",
          "B=0DOTSYMBOL6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
          "T=1"
        ],
        "Name": "Dream",
        "Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
      }
    },
    {
      "Iso3D": {
        "Description ": [
          "Torus Distortion due to moving surface by Abderrahman Taha 09/11/2015"
        ],
        "Name": [
          "Torus Distortion"
        ],
        "Component": [
          "Drope",
          "Torus"
        ],
        "Fxyz": [
          "z-Sx*exp(Ex+Ey)-Cy*exp(Ex+Ey)",
          "(sqrt((x-Sx*exp(Ex+Ey))^2 + (y-Cy*exp(Ex+Ey))^2) -1)^2 +(z-Sx*exp(Ex+Ey)-Cy*exp(Ex+Ey))^2 - 0DOTSYMBOL1"
        ],
        "Varu": [
          "S=1DOTSYMBOL5*u*sin(2*tm)",
          "C=2*u*cos(3*tm)",
          "E=-u*u"
        ],
        "Xmax": [
          "2",
          "1DOTSYMBOL8"
        ],
        "Xmin": [
          "-2",
          "-1DOTSYMBOL8"
        ],
        "Ymax": [
          "2",
          "1DOTSYMBOL8"
        ],
        "Ymin": [
          "-2",
          "-1DOTSYMBOL8"
        ],
        "Zmax": [
          "1DOTSYMBOL7",
          "1DOTSYMBOL5"
        ],
        "Zmin": [
          "-1DOTSYMBOL7",
          "-1DOTSYMBOL5"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Lobs by Abderrahman Taha 08/11/2015"
        ],
        "Name": [
          "Lobs"
        ],
        "Component": [
          "Lobs1",
          "Lobs2"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001"
        ],
        "Funct": [
          "Thickness1=if( t = 1, if ( (sin(13*v-7*u))<0DOTSYMBOL4,-1, 3*cos(u)*cos(v)*sin(u)-0DOTSYMBOL63),if ( (sin(13*v-7*u))>0DOTSYMBOL4,-1,3*cos(u)*cos(v)*sin(u)-0DOTSYMBOL63))",
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
          "Gz=Fz(u,v,t)+Thickness1(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,1)",
          "Gx(u,v,0)"
        ],
        "Fy": [
          "Gy(u,v,1)",
          "Gy(u,v,0)"
        ],
        "Fz": [
          "Gz(u,v,1)",
          "Gz(u,v,0)"
        ],
        "Umax": [
          "pi/2",
          "pi/2"
        ],
        "Umin": [
          "-pi/2",
          "-pi/2"
        ],
        "Vmax": [
          "2*pi",
          "2*pi"
        ],
        "Vmin": [
          "0",
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Sphere Parts by Abderrahman Taha 23/10/2015"
        ],
        "Name": [
          "Sphere Parts"
        ],
        "Component": [
          "Sphere1",
          "Sphere2"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001"
        ],
        "Funct": [
          "Thickness1=if( t = 1, if ( abs(sin(4*u-v))>0DOTSYMBOL35,-1,0DOTSYMBOL6*sin(v)),if ( abs(sin(4*u-v))<0DOTSYMBOL35,-1,0))",
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
          "Gz=Fz(u,v,t)+Thickness1(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,1)",
          "Gx(u,v,0)"
        ],
        "Fy": [
          "Gy(u,v,1)",
          "Gy(u,v,0)"
        ],
        "Fz": [
          "Gz(u,v,1)",
          "Gz(u,v,0)"
        ],
        "Umax": [
          "pi/2",
          "pi/2"
        ],
        "Umin": [
          "-pi/2",
          "-pi/2"
        ],
        "Vmax": [
          "2*pi",
          "2*pi"
        ],
        "Vmin": [
          "0",
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL5*cos(5*(x*x+y*y))",
          "G=0DOTSYMBOL5*cos(5*(x*x+y*y+z*z))",
          "B=0DOTSYMBOL5*cos(5*(x*x+y*y+z*z))",
          "T=1"
        ],
        "Name": "Granit",
        "Noise": "NoiseW(13*x,13*y,13*z,1,2,0)"
      }
    },
    {
      "Param4D": {
        "Description": [
          "Ribbon bending by Abderrahman Taha 05/11/2015"
        ],
        "Name": [
          "Ribbon bending"
        ],
        "Component": [
          "Ribbon1",
          "Ribbon2"
        ],
        "Fw": [
          "sin(200*u)/2000",
          "sin(8*u)/5"
        ],
        "Fx": [
          "sin(u)",
          "sin(u)"
        ],
        "Fy": [
          "cos(u)",
          "cos(u)"
        ],
        "Fz": [
          "sin(v)",
          "sin(v)"
        ],
        "Umax": [
          "2*pi",
          "2*pi"
        ],
        "Umin": [
          "0",
          "0"
        ],
        "Vmax": [
          "2*pi",
          "2*pi"
        ],
        "Vmin": [
          "0",
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description": [
          "Helicoid to Catenoid by Abderrahman Taha 05/11/2015"
        ],
        "Name": [
          "Helicoid to Catenoid"
        ],
        "Component": [
          "HelicoidCatenoid"
        ],
        "Fx": [
          "cos(2*t*pi)*sinh(v)*sin(u) + sin(2*t*pi)*cosh(v)*cos(u)"
        ],
        "Fy": [
          "-cos(2*t*pi)*sinh(v)*cos(u) + sin(2*t*pi)*cosh(v)*sin(u)"
        ],
        "Fz": [
          "3*(u*cos(2*t*pi) + v*sin(2*t*pi))"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "-pi"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Bouncing Ball_1 by Abderrahman Taha 04/11/2015"
        ],
        "Name": [
          "Bouncing Ball"
        ],
        "Component": [
          "Ball",
          "ThickWalls",
          "TransparentWall"
        ],
        "Fxyz": [
          "((x-(abs(((t*2DOTSYMBOL5)%16)-8)-4))^2+(y-(abs(((t*2DOTSYMBOL9)%16)-8)-4))^2+(z-(4DOTSYMBOL4-((((t*1DOTSYMBOL2)%4)-2)^2)))^2-0DOTSYMBOL8)",
          "(z+ 0DOTSYMBOL407)*(y-4DOTSYMBOL9)*(y+4DOTSYMBOL9)*(x+4DOTSYMBOL9)",
          "(x-4DOTSYMBOL9)"
        ],
        "Grid": [
          "25",
          "15",
          "5"
        ],
        "Xmax": [
          "4DOTSYMBOL81",
          "4DOTSYMBOL91",
          "4DOTSYMBOL91"
        ],
        "Xmin": [
          "-4DOTSYMBOL81",
          "-4DOTSYMBOL91",
          "-4DOTSYMBOL91"
        ],
        "Ymax": [
          "4DOTSYMBOL81",
          "4DOTSYMBOL91",
          "4DOTSYMBOL91"
        ],
        "Ymin": [
          "-4DOTSYMBOL81",
          "-4DOTSYMBOL91",
          "-4DOTSYMBOL91"
        ],
        "Zmax": [
          "5DOTSYMBOL5",
          "5DOTSYMBOL5",
          "5DOTSYMBOL5"
        ],
        "Zmin": [
          "- 0DOTSYMBOL5",
          "- 0DOTSYMBOL41",
          "- 0DOTSYMBOL41"
        ]
      }
    },
    {
      "Param3D": {
        "Name": [
          "simple Enneper_10"
        ],
        "Component": [
          "Enneper"
        ],
        "Const": [
          "k=10"
        ],
        "Description ": [
          "simple Enneper by Abderrahman Taha 3/11/2015"
        ],
        "Fx": [
          "k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t)"
        ],
        "Fy": [
          "-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t)"
        ],
        "Fz": [
          "(u^k*cos(k*v+t))"
        ],
        "Umax": [
          "1DOTSYMBOL15"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL91",
          "G=0DOTSYMBOL8*abs(cos(5*pi*atan2(x,y)))",
          "B=0DOTSYMBOL8*abs(cos(5*pi*atan2(x,y)))",
          "T=1"
        ],
        "Name": "Candy",
        "Noise": "1"
      }
    },
    {
      "Param3D": {
        "Name": [
          "simple Enneper_8"
        ],
        "Component": [
          "Enneper"
        ],
        "Const": [
          "k=8"
        ],
        "Description ": [
          "simple Enneper by Abderrahman Taha 3/11/2015"
        ],
        "Fx": [
          "k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t)"
        ],
        "Fy": [
          "-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t)"
        ],
        "Fz": [
          "(u^k*cos(k*v+t))"
        ],
        "Umax": [
          "1DOTSYMBOL15"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL91",
          "G=0DOTSYMBOL8*abs(cos(5*pi*atan2(x,y)))",
          "B=0DOTSYMBOL8*abs(cos(5*pi*atan2(x,y)))",
          "T=1"
        ],
        "Name": "Candy",
        "Noise": "1"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "simple Enneper by Abderrahman Taha 3/11/2015"
        ],
        "Name": [
          "simple Enneper_6"
        ],
        "Component": [
          "Enneper"
        ],
        "Const": [
          "k=6"
        ],
        "Fx": [
          "k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t)"
        ],
        "Fy": [
          "-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t)"
        ],
        "Fz": [
          "(u^k*cos(k*v+t))"
        ],
        "Umax": [
          "1DOTSYMBOL15"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL91",
          "G=0DOTSYMBOL8*abs(cos(5*pi*atan2(x,y)))",
          "B=0DOTSYMBOL8*abs(cos(5*pi*atan2(x,y)))",
          "T=1"
        ],
        "Name": "Candy",
        "Noise": "1"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "simple Enneper by Abderrahman Taha 3/11/2015"
        ],
        "Name": [
          "simple Enneper_4"
        ],
        "Component": [
          "Enneper"
        ],
        "Const": [
          "k=4"
        ],
        "Fx": [
          "k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t)"
        ],
        "Fy": [
          "-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t)"
        ],
        "Fz": [
          "(u^k*cos(k*v+t))"
        ],
        "Umax": [
          "1DOTSYMBOL15"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL91",
          "G=0DOTSYMBOL8*abs(cos(5*pi*atan2(x,y)))",
          "B=0DOTSYMBOL8*abs(cos(5*pi*atan2(x,y)))",
          "T=1"
        ],
        "Name": "Candy",
        "Noise": "1"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Double Enneper by Abderrahman Taha 3/11/2015"
        ],
        "Name": [
          "Double Enneper_4x4"
        ],
        "Component": [
          "Enneper_1",
          "Enneper_2"
        ],
        "Const": [
          "k=4"
        ],
        "Fx": [
          "k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t)",
          "-(k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t))"
        ],
        "Fy": [
          "-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t)",
          "(-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t))"
        ],
        "Fz": [
          "(u^k*cos(k*v+t))",
          "(-u^(k)*cos(k*v+t))"
        ],
        "Umax": [
          "1DOTSYMBOL2",
          "1DOTSYMBOL2"
        ],
        "Umin": [
          "0",
          "0"
        ],
        "Vmax": [
          "pi",
          "pi"
        ],
        "Vmin": [
          "-pi",
          "-pi"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL91",
          "G=0DOTSYMBOL8*abs(cos(5*pi*atan2(x,y)))",
          "B=0DOTSYMBOL8*abs(cos(5*pi*atan2(x,y)))",
          "T=1"
        ],
        "Name": "Granit_2",
        "Noise": "1"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Contour lines by Abderrahman Taha 01/11/2015"
        ],
        "Name": [
          "Contour lines_1"
        ],
        "Cnd": [
          "(z- 0DOTSYMBOL25)*(z+ 0DOTSYMBOL25)*(z- 0DOTSYMBOL5)*(z+ 0DOTSYMBOL5)*(z- 0DOTSYMBOL75)*(z+ 0DOTSYMBOL75)*(z-1)*(z+1)*(z-1DOTSYMBOL5)*(z+1DOTSYMBOL5)*(z-1DOTSYMBOL25)*(z+1DOTSYMBOL25)>0"
        ],
        "Component": [
          "Drope"
        ],
        "Fxyz": [
          "z-4*x*exp(-x^2-y^2)"
        ],
        "Xmax": [
          "2"
        ],
        "Xmin": [
          "-2"
        ],
        "Ymax": [
          "2"
        ],
        "Ymin": [
          "-2"
        ],
        "Zmax": [
          "1DOTSYMBOL8"
        ],
        "Zmin": [
          "-1DOTSYMBOL8"
        ]
      }
    },
    {
      "Param3D": {
        "Description": [
          "Double Helical curve by Abderrahman Taha 01/11/2015"
        ],
        "Name": [
          "Double Helical curve"
        ],
        "Cnd": [
          "sqrt(z^2+y^2)- 0DOTSYMBOL200001>0",
          "1"
        ],
        "Component": [
          "Cosinus",
          "Cylinder"
        ],
        "Fx": [
          "u",
          "v"
        ],
        "Fy": [
          "v",
          " 0DOTSYMBOL2*sin(pi*u)"
        ],
        "Fz": [
          "-sin(5*pi*u)/5",
          " 0DOTSYMBOL2*cos(pi*u)"
        ],
        "Umax": [
          "1",
          "1"
        ],
        "Umin": [
          "-1",
          "-1"
        ],
        "Vmax": [
          " 0DOTSYMBOL5",
          "1"
        ],
        "Vmin": [
          "- 0DOTSYMBOL5",
          "-1"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Menger Schwarz_1 by Abderrahman Taha 28/10/2015. Menger Sponge Level 3 made out of the skeletal graph of Schwarz's D surface"
        ],
        "Name": [
          "Skeletal Menger"
        ],
        "Cnd": [
          "(x+y+z)>0",
          "(x+y+z)>0",
          "(x+y+z)>0",
          "(x+y+z)>0",
          "(x+y+z)>0",
          "(x+y+z)>0",
          "(x+y+z)>0",
          "(x+y+z)>0"
        ],
        "Component": [
          "MengerSchwarz1",
          "MengerSchwarz2",
          "MengerSchwarz3",
          "MengerSchwarz4",
          "MengerSchwarz5",
          "MengerSchwarz6",
          "MengerSchwarz7",
          "MengerSchwarz8"
        ],
        "Funct": [
          "Thickness=-0DOTSYMBOL013",
          "isoCondition=if((abs(x)>1/3|abs(y)>1/3)&(abs(z)>1/3|abs(y)>1/3)&(abs(x)>1/3|abs(z)>1/3)&(((((abs(x-2/3)<1/9)+(abs(x+2/3)<1/9)+(abs(x)<1/9))*((abs(y-2/3)<1/9)+(abs(y)<1/9)+(abs(y+2/3)<1/9)+(abs(z-2/3)<1/9)+(abs(z)<1/9)+(abs(z+2/3)<1/9)))+(((abs(z-2/3)<1/9)+(abs(z+2/3)<1/9)+(abs(z)<1/9))*((abs(y-2/3)<1/9)+(abs(y)<1/9)+(abs(y+2/3)<1/9))))=0)&(((((abs(x-2/3)<1/27)+(abs(x-2/3-2/9)<1/27)+(abs(x-2/3+2/9)<1/27)+(abs(x+2/3)<1/27)+(abs(x+2/3-2/9)<1/27)+(abs(x+2/3+2/9)<1/27)+(abs(x)<1/27)+(abs(x-2/9)<1/27)+(abs(x+2/9)<1/27))*((abs(y-2/3)<1/27)+(abs(y-2/3-2/9)<1/27)+(abs(y-2/3+2/9)<1/27)+(abs(y)<1/27)+(abs(y-2/9)<1/27)+(abs(y+2/9)<1/27)+(abs(y+2/3)<1/27)+(abs(y+2/3-2/9)<1/27)+(abs(y+2/3+2/9)<1/27)+(abs(z-2/3)<1/27)+(abs(z-2/3-2/9)<1/27)+(abs(z-2/3+2/9)<1/27)+(abs(z)<1/27)+(abs(z-2/9)<1/27)+(abs(z+2/9)<1/27)+(abs(z+2/3)<1/27)+(abs(z+2/3-2/9)<1/27)+(abs(z+2/3+2/9)<1/27)))+(((abs(z-2/3)<1/27)+(abs(z-2/3-2/9)<1/27)+(abs(z-2/3+2/9)<1/27)+(abs(z+2/3)<1/27)+(abs(z+2/3-2/9)<1/27)+(abs(z+2/3+2/9)<1/27)+(abs(z)<1/27)+(abs(z-2/9)<1/27)+(abs(z+2/9)<1/27))*((abs(y-2/3)<1/27)+(abs(y-2/3-2/9)<1/27)+(abs(y-2/3+2/9)<1/27)+(abs(y)<1/27)+(abs(y-2/9)<1/27)+(abs(y+2/9)<1/27)+(abs(y+2/3)<1/27)+(abs(y+2/3-2/9)<1/27)+(abs(y+2/3+2/9)<1/27))))=0),x^100+y^100+z^100-1DOTSYMBOL12,1)"
        ],
        "Fxyz": [
          "if(isoCondition(x,y,z,t)<0,-(cos(84DOTSYMBOL823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
          "if(isoCondition(x,y,z,t)<0,-(cos(84DOTSYMBOL823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
          "if(isoCondition(x,y,z,t)<0,-(cos(84DOTSYMBOL823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
          "if(isoCondition(x,y,z,t)<0,-(cos(84DOTSYMBOL823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
          "if(isoCondition(x,y,z,t)<0,-(cos(84DOTSYMBOL823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
          "if(isoCondition(x,y,z,t)<0,-(cos(84DOTSYMBOL823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
          "if(isoCondition(x,y,z,t)<0,-(cos(84DOTSYMBOL823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
          "if(isoCondition(x,y,z,t)<0,-(cos(84DOTSYMBOL823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84DOTSYMBOL823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)"
        ],
        "Varu": [
          "E=sin(84DOTSYMBOL823*u)"
        ],
        "Xmax": [
          "1DOTSYMBOL06",
          "1DOTSYMBOL06",
          "1DOTSYMBOL06",
          "1DOTSYMBOL06",
          "0",
          "0",
          "0",
          "0"
        ],
        "Xmin": [
          "0",
          "0",
          "0",
          "0",
          "-1DOTSYMBOL06",
          "-1DOTSYMBOL06",
          "-1DOTSYMBOL06",
          "-1DOTSYMBOL06"
        ],
        "Ymax": [
          "1DOTSYMBOL06",
          "0",
          "1DOTSYMBOL06",
          "0",
          "0",
          "1DOTSYMBOL06",
          "0",
          "1DOTSYMBOL06"
        ],
        "Ymin": [
          "0",
          "-1DOTSYMBOL06",
          "0",
          "-1DOTSYMBOL06",
          "-1DOTSYMBOL06",
          "0",
          "-1DOTSYMBOL06",
          "0"
        ],
        "Zmax": [
          "1DOTSYMBOL06",
          "1DOTSYMBOL06",
          "0",
          "0",
          "0",
          "0",
          "1DOTSYMBOL06",
          "1DOTSYMBOL06"
        ],
        "Zmin": [
          "0",
          "0",
          "-1DOTSYMBOL06",
          "-1DOTSYMBOL06",
          "-1DOTSYMBOL06",
          "-1DOTSYMBOL06",
          "0",
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL7*sqrt(4*x^40+y^4+z^4)",
          "G=0DOTSYMBOL4*sqrt(x^4+y^4+4*z^20)",
          "B=0DOTSYMBOL5*sqrt(x^4+4*y^20+z^4)",
          "T=1"
        ],
        "Name": "Granit_2",
        "Noise": "1"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Double Nib Parametric surface by Abderrahman Taha 31/10/2015"
        ],
        "Name": [
          "Double Nib"
        ],
        "Component": [
          "DoubleNib"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Fx=-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6",
          "Fy=-sin(t+v)/(2*u)+u^3*sin(t-3*v)/6",
          "Fz=u*cos(t-v)",
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
          "Thickness=DFyv(u,v,t)*0DOTSYMBOL5",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "1DOTSYMBOL3"
        ],
        "Umin": [
          "0DOTSYMBOL3"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=1DOTSYMBOL5* 0DOTSYMBOL41",
          "G=2*0DOTSYMBOL81*abs(cos((x*x+y*y+z*z)/2) *sin((x*x+y*y+z*z)/2))",
          "B=2*0DOTSYMBOL8601*abs(cos((x*x+y*y+z*z)/2) *cos((x*x+y*y+z*z)/2) *sin((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(4*x,4*y,4*z,4,2,0) +NoiseW(4*x,4*y,4*z,4,12,1/10)"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "PrettyBall_1 by Abderrahman Taha 28/10/2015"
        ],
        "Name": [
          "Pretty Ball"
        ],
        "Component": [
          "PrettyBall_1",
          "PrettyBall_2",
          "PrettyBall_3"
        ],
        "Const": [
          "cx=0DOTSYMBOL0001",
          "cy=0DOTSYMBOL0001",
          "cz=0DOTSYMBOL0001",
          "xmax=8",
          "xmin=-8",
          "ymax=8",
          "ymin=-8",
          "zmax=8",
          "zmin=-8"
        ],
        "Funct": [
          "Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "Thickness=( 0DOTSYMBOL9)",
          "Thickness2=( 0DOTSYMBOL4)",
          "DFx=((Iso(x,y,z,t)-Iso(x+cx,y,z,t))/cx)",
          "DFy=((Iso(x,y,z,t)-Iso(x,y+cy,z,t))/cy)",
          "DFz=((Iso(x,y,z,t)-Iso(x,y,z+cz,t))/cz)",
          "Rapport=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
          "Iso3=(Iso(x-DFx(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),y-DFy(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),z-DFz(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),t))",
          "Iso2=(Iso(x+DFx(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),y+DFy(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),z+DFz(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),t))",
          "Iso4=(Iso(x-DFx(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),y-DFy(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),z-DFz(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),t))",
          "Iso5=(Iso(x+DFx(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),y+DFy(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),z+DFz(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),t))",
          "ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
          "isoCondition=(x*x + y*y + z*z - 64)"
        ],
        "Fxyz": [
          "if(isoCondition(x,y,z,t)<0, ThickIso2(x,y,z,t),1) + exp(isoCondition(x,y,z,t)/3)",
          "if(isoCondition(x,y,z,t)<0, Iso3(x,y,z,t),1) + exp(isoCondition(x,y,z,t)/3)",
          "if(isoCondition(x,y,z,t)<0,-Iso2(x,y,z,t),1) + exp(isoCondition(x,y,z,t)/3)"
        ],
        "Xmax": [
          "8",
          "8",
          "8"
        ],
        "Xmin": [
          "-8",
          "-8",
          "-8"
        ],
        "Ymax": [
          "8",
          "8",
          "8"
        ],
        "Ymin": [
          "-8",
          "-8",
          "-8"
        ],
        "Zmax": [
          "8",
          "8",
          "8"
        ],
        "Zmin": [
          "-8",
          "-8",
          "-8"
        ]
      }
    },
    {
      "Iso3D": {
        "Description ": [
          "Hexagrams Menger Sponge Level 4 by Abderrahman Taha 24/10/2015"
        ],
        "Name": [
          "Hexagrams Menger Level 4"
        ],
        "Component": [
          "MengerSponge"
        ],
        "Cnd": [
          "(x + y+z)> 0"
        ],
        "Fxyz": [
          " -(Dx + Dy + Dz -1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*( (Cx*(Cy+Cz) + Cz*Cy) =0)*( (Bx*(By+Bz) + Bz*By) =0)*( (Ax*(Ay+Az) + Az*Ay) =0) ) "
        ],
        "Varu": [
          " A = ((abs(u-2/3) <1/81)+ (abs(u-20/27) <1/81)+ (abs(u-16/27) <1/81)+(abs(u-8/9) <1/81) + (abs(u-26/27) <1/81) + (abs(u-22/27) <1/81) +(abs(u-4/9) <1/81) +(abs(u-14/27) <1/81) +(abs(u-10/27) <1/81) +(abs(u+2/3) <1/81) +(abs(u+16/27) <1/81) +(abs(u+20/27) <1/81) +(abs(u+4/9) <1/81) +(abs(u+10/27) <1/81) +(abs(u+14/27) <1/81) +(abs(u+8/9) <1/81) +(abs(u+22/27) <1/81) +(abs(u+26/27) <1/81) +(abs(u) <1/81) + (abs(u-2/27) <1/81) +(abs(u+2/27) <1/81) +(abs(u-2/9) <1/81) + (abs(u-8/27) <1/81) + (abs(u-4/27) <1/81) +(abs(u+2/9) <1/81)+(abs(u+4/27) <1/81)+(abs(u+8/27) <1/81))",
          " B = ((abs(u-2/3) <1/27)+(abs(u-8/9) <1/27) + (abs(u-4/9) <1/27) +(abs(u+2/3) <1/27) +(abs(u+4/9) <1/27) + (abs(u+8/9) <1/27) +(abs(u) <1/27) + (abs(u-2/9) <1/27) + (abs(u+2/9) <1/27))",
          "C = ((abs(u-2/3) <1/9) + (abs(u+2/3) <1/9) + (abs(u) <1/9))",
          "D = u^100"
        ],
        "Xmax": [
          " 1DOTSYMBOL001"
        ],
        "Xmin": [
          "-1DOTSYMBOL001"
        ],
        "Ymax": [
          " 1DOTSYMBOL001"
        ],
        "Ymin": [
          "-1DOTSYMBOL001"
        ],
        "Zmax": [
          " 1DOTSYMBOL001"
        ],
        "Zmin": [
          "-1DOTSYMBOL001"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Virus by Abderrahman Taha 25/10/2015"
        ],
        "Name": [
          "Virus_2"
        ],
        "Component": [
          "Virus"
        ],
        "Funct": [
          "Thickness= - 0DOTSYMBOL3*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/1DOTSYMBOL8)^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/1DOTSYMBOL9)^5DOTSYMBOL5)",
          "n1= (-(cos(u))*(cos(u)*cos(v)))",
          "n2= ((cos(u))*(-sin(v)*cos(u)))",
          "n3= ((-sin(u)*cos(v))*(cos(u)*cos(v))-(-sin(u)*sin(v))*(-sin(v)*cos(u)))",
          "R=sqrt((n1(u,v,t))^2 + (n2(u,v,t))^2 + (n3(u,v,t))^2 )",
          "Gx=cos(u)*cos(v)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=cos(u)*sin(v)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=sin(u)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)",
          "Hx=n1(u,v,t)* (n1(u,v,t)*Gx(u,v,t)+n2(u,v,t)*Gy(u,v,t)+n3(u,v,t)*Gz(u,v,t))*(1 - cos(2*pi*Thickness(u,v,t)/R(u,v,t))) +Gx(u,v,t)*cos(2*pi*Thickness(u,v,t)/R(u,v,t)) +(-n3(u,v,t)*Gy(u,v,t) + n2(u,v,t)*Gz(u,v,t) ) * sin(2*pi*Thickness(u,v,t)/R(u,v,t))",
          "Hy = n2(u,v,t)* (n1(u,v,t)*Gx(u,v,t)+n2(u,v,t)*Gy(u,v,t)+n3(u,v,t)*Gz(u,v,t))*(1 - cos(2*pi*Thickness(u,v,t)/R(u,v,t))) +Gy(u,v,t)*cos(2*pi*Thickness(u,v,t)/R(u,v,t)) +(n3(u,v,t)*Gx(u,v,t) - n1(u,v,t)*Gz(u,v,t) ) * sin(2*pi*Thickness(u,v,t)/R(u,v,t))",
          "Hz=n3(u,v,t)* (n1(u,v,t)*Gx(u,v,t)+n2(u,v,t)*Gy(u,v,t)+n3(u,v,t)*Gz(u,v,t))*(1 - cos(2*pi*Thickness(u,v,t)/R(u,v,t))) +Gz(u,v,t)*cos(2*pi*Thickness(u,v,t)/R(u,v,t)) +(-n2(u,v,t)*Gx(u,v,t) + n1(u,v,t)*Gy(u,v,t) ) * sin(2*pi*Thickness(u,v,t)/R(u,v,t)) "
        ],
        "Fx": [
          "Hx(u,v,t)"
        ],
        "Fy": [
          "Hy(u,v,t)"
        ],
        "Fz": [
          "Hz(u,v,t)"
        ],
        "Umax": [
          "pi/2"
        ],
        "Umin": [
          "-pi/2"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=1DOTSYMBOL5*abs(cos((x*x+y*y+z*z)/3)*sin((x*x+y*y+z*z)/3))",
          "B=0DOTSYMBOL2*abs(cos((x*x+y*y+z*z)/3)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/3))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(8*x,8*y,8*z,4,2,0)+NoiseW(8*x,8*y,8*z,4,12,1/10)"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Star by Abderrahman Taha 23/10/2015"
        ],
        "Name": [
          "Star_2"
        ],
        "Component": [
          "Star"
        ],
        "Const": [
          "cu=0DOTSYMBOL0000000001",
          "cv=0DOTSYMBOL0000000001",
          "N=5"
        ],
        "Funct": [
          "Thickness= ((sin(15*u)*cos(15*u)))^4 + (sin(2*N*v))",
          "Fx=-cos(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
          "Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Star by Abderrahman Taha 23/10/2015"
        ],
        "Name": [
          "Star_3"
        ],
        "Component": [
          "Star"
        ],
        "Const": [
          "cu=0DOTSYMBOL0000000001",
          "cv=0DOTSYMBOL0000000001",
          "N=5"
        ],
        "Funct": [
          "Thickness= ((sin(15*u)*cos(15*v)))^4 + (sin(2*N*u))",
          "Fx=-cos(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
          "Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description ": [
          "The Beginning by Abderrahman Taha 21/10/2015"
        ],
        "Name": [
          "The Beginning"
        ],
        "Component": [
          "TheBeginning1",
          "TheBeginning2"
        ],
        "Funct": [
          "tail=x^2+y^2+z^2- 0DOTSYMBOL1*t",
          "tail2=(x+sin(5*pi*y/20))^2 + (y/10)^2 + (z)^2 - 1",
          "tail3=tail2(x*30,y*30-30,z*30,1)"
        ],
        "Fxyz": [
          "-((x^2+y^2+z^2-1)+(NoiseW(6*x,6*y,6*z,4,2,0)+NoiseW(6*x,6*y,6*z,4,0,0))/5)*( atan2(y,x)<(pi/2) | atan2(sqrt(x*x+y*y),z)>(pi/2)) *tail(x,y,z,1)",
          "tail3(x*cos(-pi/4)-y*sin(-pi/4),x*sin(-pi/4)+y*cos(-pi/4),z,t)"
        ],
        "Xmax": [
          "1",
          "- 0DOTSYMBOL5"
        ],
        "Xmin": [
          "-1",
          "-1"
        ],
        "Ymax": [
          "1",
          "1DOTSYMBOL4"
        ],
        "Ymin": [
          "-1",
          " 0DOTSYMBOL5"
        ],
        "Zmax": [
          "1",
          " 0DOTSYMBOL1"
        ],
        "Zmin": [
          "-1",
          "- 0DOTSYMBOL1"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL6",
          "G=2DOTSYMBOL4*(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))*sin((x*x+y*y+z*z)/2)",
          "B=0DOTSYMBOL7*(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(2*x,2*y,2*z,4,0,0)+NoiseW(2*x,2*y,2*z,2,0,0)"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Space Ship by Abderrahman Taha 20/10/2015"
        ],
        "Name": [
          "Space Ship_1"
        ],
        "Component": [
          "SpaceShip"
        ],
        "Const": [
          "cu=0DOTSYMBOL000001",
          "cv=0DOTSYMBOL000001",
          "N1=16",
          "N2=11",
          "N3=6"
        ],
        "Funct": [
          "Thickness= ( 0DOTSYMBOL2*(abs(sin(N1*u)*cos(N2*v)))^7 + 0DOTSYMBOL2*((sin(N3*u))))",
          "Fx=-(abs(u)-1)^2 * cos(v)",
          "Fy=u",
          "Fz=(abs(u)-1)^2 * sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "1"
        ],
        "Umin": [
          "-1"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Space Ship by Abderrahman Taha 20/10/2015"
        ],
        "Name": [
          "Space Ship_2"
        ],
        "Component": [
          "SpaceShip"
        ],
        "Const": [
          "cu=0DOTSYMBOL000001",
          "cv=0DOTSYMBOL000001",
          "N1=12",
          "N2=7",
          "N3=5"
        ],
        "Funct": [
          "Thickness= ( 0DOTSYMBOL2*(abs(sin(N1*u)*cos(N2*v)))^6 + 0DOTSYMBOL01*((sin(N3*u))))",
          "Fx=-(abs(u)-1)^2 * cos(v)",
          "Fy=u",
          "Fz=(abs(u)-1)^2 * sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "1"
        ],
        "Umin": [
          "-1"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Space Ship by Abderrahman Taha 20/10/2015"
        ],
        "Name": [
          "Space Ship_3"
        ],
        "Component": [
          "SpaceShip"
        ],
        "Const": [
          "cu=0DOTSYMBOL000001",
          "cv=0DOTSYMBOL000001",
          "N1=12",
          "N2=7",
          "N3=5"
        ],
        "Funct": [
          "Thickness= -( 0DOTSYMBOL2*(abs(sin(N1*u)*cos(N2*v)))^6 + 0DOTSYMBOL01*((sin(N3*u))))",
          "Fx=-(abs(u)-1)^2 * cos(v)",
          "Fy=u",
          "Fz=(abs(u)-1)^2 * sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "1"
        ],
        "Umin": [
          "-1"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Arena_0 by Abderrahman Taha 19/10/2015"
        ],
        "Name": [
          "Arena_0"
        ],
        "Component": [
          "Arena"
        ],
        "Const": [
          "cx=0DOTSYMBOL00001",
          "cy=0DOTSYMBOL00001",
          "cz=0DOTSYMBOL00001"
        ],
        "Funct": [
          "Scherk=sinh(x)*sinh(y)-4*sin(z)",
          "Scherk2=Scherk(x,(sqrt(y*y+z*z)-16),z,t)",
          "Thickness2=( 0DOTSYMBOL6)",
          "IsoExterior=Scherk2(x,y,z,t)",
          "DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
          "DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
          "DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
          "Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
          "Iso3=(IsoExterior(x-DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y-DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z-DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
          "Iso2=(IsoExterior(x+DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y+DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z+DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
          "ThickIsoExterior=(Iso2(x,y,z,t)*Iso3(x,y,z,t))"
        ],
        "Fxyz": [
          "if((sqrt(x*x+y*y+z*z) - 20)<0 & abs(x)<6 ,ThickIsoExterior(x,y,z,t), 1)"
        ],
        "Xmax": [
          "7"
        ],
        "Xmin": [
          "-7"
        ],
        "Ymax": [
          "23"
        ],
        "Ymin": [
          "-23"
        ],
        "Zmax": [
          "23"
        ],
        "Zmin": [
          "-23"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Lumpet Tori by Abderrahman Taha 10/10/2015"
        ],
        "Name": [
          "Lumpet Tori"
        ],
        "Component": [
          "LumpetTori"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Thickness= 0DOTSYMBOL2*(abs(sin(14*u)*cos(14*v)))^9 + 0DOTSYMBOL4*((sin(8*u)))",
          "Fx=-cos(u) / (sqrt(2) + sin(v))",
          "Fy=1 / (sqrt(2) + cos(v))",
          "Fz=sin(u) / (sqrt(2) + sin(v))",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "-pi"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Sphere modelling by Abderrahman Taha 18/10/2015"
        ],
        "Name": [
          "Sphere modelling"
        ],
        "Component": [
          "Sphere modelling1",
          "SphereModelling2"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=1DOTSYMBOL5"
        ],
        "Funct": [
          "Thickness1=if( t = 1, -if (sin(u*(sin(14*v-10*u))) <0DOTSYMBOL4,-1,0DOTSYMBOL2*(13*u-pi)*(cos(u)-sin(u))) ,-if (sin(u*(sin(14*v-10*u))) >0DOTSYMBOL4,-1,0DOTSYMBOL2*(13*u-pi)*(cos(u)-sin(u))))",
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
          "Gz=Fz(u,v,t)+Thickness1(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,1)",
          "Gx(u,v,0)"
        ],
        "Fy": [
          "Gy(u,v,1)",
          "Gy(u,v,0)"
        ],
        "Fz": [
          "Gz(u,v,1)",
          "Gz(u,v,0)"
        ],
        "Umax": [
          "pi/2",
          "pi/2"
        ],
        "Umin": [
          "-pi/2",
          "-pi/2"
        ],
        "Vmax": [
          "2*pi",
          "2*pi"
        ],
        "Vmin": [
          "0",
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description ": [
          "The lamp by Abderrahman Taha 18/10/2015"
        ],
        "Name": [
          "Lamp"
        ],
        "Component": [
          "Lamp"
        ],
        "Funct": [
          "Hyperboloid=x^2+y^2-z^2- 0DOTSYMBOL1",
          "Intersection=max(Hyperboloid(x,y,z*3,1),Hyperboloid(x*3,z*3,y*3,2))",
          "Intersection2=max(Hyperboloid(x,y,z+5,1),Hyperboloid(x,y,z-5,1))",
          "Cylinders=((sqrt((x-4DOTSYMBOL5)*(x-4DOTSYMBOL5)+z*z)-2DOTSYMBOL5)^2+y*y-0DOTSYMBOL25)*((sqrt((x+4DOTSYMBOL5)*(x+4DOTSYMBOL5)+z*z)-2DOTSYMBOL5)^2+y*y-0DOTSYMBOL25)*((sqrt((y+4DOTSYMBOL5)*(y+4DOTSYMBOL5)+z*z)-2DOTSYMBOL5)^2+x*x-0DOTSYMBOL25)*((sqrt((y-4DOTSYMBOL5)*(y-4DOTSYMBOL5)+z*z)-2DOTSYMBOL5)^2+x*x-0DOTSYMBOL25)*((sqrt(x*x+y*y)-5)^2+z*z-0DOTSYMBOL25)*((sqrt(x*x+y*y)-1)^2+(z-5DOTSYMBOL85)*(z-5DOTSYMBOL85)-0DOTSYMBOL02)"
        ],
        "Fxyz": [
          "(Intersection2(x,y,z,t)*Cylinders(x,y,z,t))-50000"
        ],
        "Xmax": [
          "8DOTSYMBOL5"
        ],
        "Xmin": [
          "-8DOTSYMBOL5"
        ],
        "Ymax": [
          "8DOTSYMBOL5"
        ],
        "Ymin": [
          "-8DOTSYMBOL5"
        ],
        "Zmax": [
          "6"
        ],
        "Zmin": [
          "-6"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL88*abs(cos(z*y*x))",
          "G=0DOTSYMBOL43*abs(cos(z*y*x))",
          "B=0DOTSYMBOL019*abs(cos(-z*x*z*x*y*y))",
          "T=1"
        ],
        "Name": "Granit_1",
        "Noise": "NoiseP(x-14,y-17,z-16,10,7,2/10)/1DOTSYMBOL1"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "(Inka Sun) and Carl SequinToroids models by Abderrahman Taha 15/10/2015"
        ],
        "Name": [
          "Carl Sequin Toroids"
        ],
        "Component": [
          "Inka Sun1",
          "Inka Sun2"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=3"
        ],
        "Funct": [
          "ThicknessInkaSun= if(if(t=1,(abs(sin((N/2)*(u*(sin(v))-u))))<0DOTSYMBOL4,(abs(sin((N/2)*(u*(sin(v))-u))))>0DOTSYMBOL38),- 0DOTSYMBOL45,0)",
          "ThicknessSave= if(if(t=1,(abs(sin((N/2)*(u*abs(sin(v))-u))))<0DOTSYMBOL4,(abs(sin((N/2)*(u*abs(sin(v))-u))))>0DOTSYMBOL38),- 0DOTSYMBOL45,0)",
          "Thickness1=if( t = 1, if ( (abs(sin((N/2)*u-v)))>0DOTSYMBOL38,- 0DOTSYMBOL45,0),if ( (abs(sin((N/2)*u-v)))<0DOTSYMBOL38,- 0DOTSYMBOL45,0))",
          "Fx=(1+0DOTSYMBOL5*cos(u))*cos(v)",
          "Fy=0DOTSYMBOL5*sin(u)",
          "Fz=(1+0DOTSYMBOL5*cos(u))*sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness1(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,1)",
          "Gx(u,v,0)"
        ],
        "Fy": [
          "Gy(u,v,1)",
          "Gy(u,v,0)"
        ],
        "Fz": [
          "Gz(u,v,1)",
          "Gz(u,v,0)"
        ],
        "Umax": [
          "2*pi",
          "2*pi"
        ],
        "Umin": [
          "0",
          "0"
        ],
        "Vmax": [
          "2*pi",
          "2*pi"
        ],
        "Vmin": [
          "0",
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "(Inka Sun) and Carl SequinToroids models by Abderrahman Taha 15/10/2015"
        ],
        "Name": [
          "Inka Sun_1"
        ],
        "Component": [
          "Inka Sun11",
          "Inka Sun12"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=3"
        ],
        "Funct": [
          "ThicknessInkaSun= if(if(t=1,(abs(sin((N/2)*(u*(sin(v))-u))))<0DOTSYMBOL4,(abs(sin((N/2)*(u*(sin(v))-u))))>0DOTSYMBOL38),-0DOTSYMBOL45,0)",
          "ThicknessSave= if(if(t=1,(abs(sin((N/2)*(u*abs(sin(v))-u))))<0DOTSYMBOL4,(abs(sin((N/2)*(u*abs(sin(v))-u))))>0DOTSYMBOL38),-0DOTSYMBOL45,0)",
          "Thickness1= if(if(t=1,(abs(sin((N/2)*(u*(sin(v))-u))))<0DOTSYMBOL4,(abs(sin((N/2)*(u*(sin(v))-u))))>0DOTSYMBOL38),-0DOTSYMBOL45,0)",
          "Fx=(1+0DOTSYMBOL5*cos(u))*cos(v)",
          "Fy=0DOTSYMBOL5*sin(u)",
          "Fz=(1+0DOTSYMBOL5*cos(u))*sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness1(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,1)",
          "Gx(u,v,0)"
        ],
        "Fy": [
          "Gy(u,v,1)",
          "Gy(u,v,0)"
        ],
        "Fz": [
          "Gz(u,v,1)",
          "Gz(u,v,0)"
        ],
        "Umax": [
          "2*pi",
          "2*pi"
        ],
        "Umin": [
          "0",
          "0"
        ],
        "Vmax": [
          "2*pi",
          "2*pi"
        ],
        "Vmin": [
          "0",
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "(Inka Sun) and Carl SequinToroids models by Abderrahman Taha 15/10/2015"
        ],
        "Name": [
          "Inka Sun_2"
        ],
        "Component": [
          "Inka Sun21",
          "Inka Sun22"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=3"
        ],
        "Funct": [
          "ThicknessInkaSun= if(if(t=1,(abs(sin((N/2)*(u*(sin(v))-u))))<0DOTSYMBOL4,(abs(sin((N/2)*(u*(sin(v))-u))))>0DOTSYMBOL38),-0DOTSYMBOL45,0)",
          "ThicknessSave= if(if(t=1,(abs(sin((N/2)*(u*abs(sin(v))-u))))<0DOTSYMBOL4,(abs(sin((N/2)*(u*abs(sin(v))-u))))>0DOTSYMBOL38),-0DOTSYMBOL45,0)",
          "Thickness1= if(if(t=1,(abs(sin((N/2)*(u*abs(sin(v))-u))))<0DOTSYMBOL4,(abs(sin((N/2)*(u*abs(sin(v))-u))))>0DOTSYMBOL38),-0DOTSYMBOL45,0)",
          "Fx=(1+0DOTSYMBOL5*cos(u))*cos(v)",
          "Fy=0DOTSYMBOL5*sin(u)",
          "Fz=(1+0DOTSYMBOL5*cos(u))*sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness1(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,1)",
          "Gx(u,v,0)"
        ],
        "Fy": [
          "Gy(u,v,1)",
          "Gy(u,v,0)"
        ],
        "Fz": [
          "Gz(u,v,1)",
          "Gz(u,v,0)"
        ],
        "Umax": [
          "2*pi",
          "2*pi"
        ],
        "Umin": [
          "0",
          "0"
        ],
        "Vmax": [
          "2*pi",
          "2*pi"
        ],
        "Vmin": [
          "0",
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description ": [
          "Pseudo 4-Noids by Abderrahman Taha 12/10/2015"
        ],
        "Name": [
          "Pseudo 4-Noids_0"
        ],
        "Component": [
          "Pseudo-4-Noids"
        ],
        "Fxyz": [
          "((x^2) - 0DOTSYMBOL685*(y)^2)^2 - 2DOTSYMBOL5*(z)^2 - (x^2 + 0DOTSYMBOL75*abs(y*cos(0DOTSYMBOL3*x) - z*sin(0DOTSYMBOL6*x))^2 + (y*sin(1DOTSYMBOL5*x) + z*cos(0DOTSYMBOL05*x))^2-0DOTSYMBOL5)"
        ],
        "Xmax": [
          " 1DOTSYMBOL9"
        ],
        "Xmin": [
          "-1DOTSYMBOL9"
        ],
        "Ymax": [
          " 1DOTSYMBOL5"
        ],
        "Ymin": [
          "-1DOTSYMBOL5"
        ],
        "Zmax": [
          " 1DOTSYMBOL8"
        ],
        "Zmin": [
          "-1DOTSYMBOL8"
        ]
      }
    },
    {
      "Iso3D": {
        "Name": [
          "Pseudo k-Noids_1"
        ],
        "Description ": [
          "Pseudo k-Noids by Abderrahman Taha 14/10/2015"
        ],
        "Component": [
          "Pseudo-k-Noids"
        ],
        "Funct": [
          "Noids=((x^2) - 0DOTSYMBOL685*(y)^2)^2 - 2DOTSYMBOL5*(z)^2 - (x^2 + 0DOTSYMBOL75*abs(y*cos(0DOTSYMBOL3*x) - z*sin(0DOTSYMBOL6*x))^2 + (y*sin(1DOTSYMBOL5*x) + z*cos(0DOTSYMBOL05*x))^2-0DOTSYMBOL5)",
          "Noids1=Noids(x,y,(sqrt(x*x+1DOTSYMBOL6*z*z)-1),t)",
          "Noids2=Noids1(x,(sqrt(x*x+1DOTSYMBOL6*y*y)-1),z,t)",
          "Noids3=Noids2((sqrt(x*x+1DOTSYMBOL6*y*y)-1),y,z,t)"
        ],
        "Fxyz": [
          "Noids2(x,y,z,t)"
        ],
        "Xmax": [
          " 2DOTSYMBOL55"
        ],
        "Xmin": [
          "-2DOTSYMBOL55"
        ],
        "Ymax": [
          " 2"
        ],
        "Ymin": [
          "-2"
        ],
        "Zmax": [
          " 1DOTSYMBOL8"
        ],
        "Zmin": [
          "-1DOTSYMBOL8"
        ]
      }
    },
    {
      "Iso3D": {
        "Name": [
          "Pseudo k-Noids_2"
        ],
        "Description ": [
          "Pseudo k-Noids by Abderrahman Taha 14/10/2015"
        ],
        "Component": [
          "Pseudo-k-Noids"
        ],
        "Funct": [
          "Noids=((x^2) - 0DOTSYMBOL685*(y)^2)^2 - 2DOTSYMBOL5*(z)^2 - (x^2 + 0DOTSYMBOL75*abs(y*cos(0DOTSYMBOL3*x) - z*sin(0DOTSYMBOL6*x))^2 + (y*sin(1DOTSYMBOL5*x) + z*cos(0DOTSYMBOL05*x))^2-0DOTSYMBOL5)",
          "Noids1=Noids(x,y,(sqrt(x*x+1DOTSYMBOL6*z*z)-1),t)",
          "Noids2=Noids1(x,(sqrt(x*x+1DOTSYMBOL6*y*y)-1),z,t)",
          "Noids3=Noids2((sqrt(x*x+1DOTSYMBOL6*y*y)-1),y,z,t)"
        ],
        "Fxyz": [
          "Noids(x,y,z,t)"
        ],
        "Xmax": [
          " 2DOTSYMBOL55"
        ],
        "Xmin": [
          "-2DOTSYMBOL55"
        ],
        "Ymax": [
          " 2"
        ],
        "Ymin": [
          "-2"
        ],
        "Zmax": [
          " 1DOTSYMBOL8"
        ],
        "Zmin": [
          "-1DOTSYMBOL8"
        ]
      }
    },
    {
      "Iso3D": {
        "Name": [
          "Pseudo k-Noids_3"
        ],
        "Description ": [
          "Pseudo k-Noids by Abderrahman Taha 14/10/2015"
        ],
        "Component": [
          "Pseudo-k-Noids"
        ],
        "Funct": [
          "Noids=((x^2) - 0DOTSYMBOL685*(y)^2)^2 - 2DOTSYMBOL5*(z)^2 - (x^2 + 0DOTSYMBOL75*abs(y*cos(0DOTSYMBOL3*x) - z*sin(0DOTSYMBOL6*x))^2 + (y*sin(1DOTSYMBOL5*x) + z*cos(0DOTSYMBOL05*x))^2-0DOTSYMBOL5)",
          "Noids1=Noids(x,y,(sqrt(x*x+1DOTSYMBOL6*z*z)-1),t)",
          "Noids2=Noids1(x,(sqrt(x*x+1DOTSYMBOL6*y*y)-1),z,t)",
          "Noids3=Noids2((sqrt(x*x+1DOTSYMBOL6*y*y)-1),y,z,t)"
        ],
        "Fxyz": [
          "Noids1(x,y,z,t)"
        ],
        "Xmax": [
          " 2DOTSYMBOL55"
        ],
        "Xmin": [
          "-2DOTSYMBOL55"
        ],
        "Ymax": [
          " 2"
        ],
        "Ymin": [
          "-2"
        ],
        "Zmax": [
          " 1DOTSYMBOL8"
        ],
        "Zmin": [
          "-1DOTSYMBOL8"
        ]
      }
    },
    {
      "Iso3D": {
        "Name": [
          "Pseudo k-Noids_4"
        ],
        "Description ": [
          "Pseudo k-Noids by Abderrahman Taha 14/10/2015"
        ],
        "Component": [
          "Pseudo-k-Noids"
        ],
        "Funct": [
          "Noids=((x^2) - 0DOTSYMBOL685*(y)^2)^2 - 2DOTSYMBOL5*(z)^2 - (x^2 + 0DOTSYMBOL75*abs(y*cos(0DOTSYMBOL3*x) - z*sin(0DOTSYMBOL6*x))^2 + (y*sin(1DOTSYMBOL5*x) + z*cos(0DOTSYMBOL05*x))^2-0DOTSYMBOL5)",
          "Noids1=Noids(x,y,(sqrt(x*x+1DOTSYMBOL6*z*z)-1),t)",
          "Noids2=Noids1(x,(sqrt(x*x+1DOTSYMBOL6*y*y)-1),z,t)",
          "Noids3=Noids2((sqrt(x*x+1DOTSYMBOL6*y*y)-1),y,z,t)"
        ],
        "Fxyz": [
          "Noids3(x,y,z,t)"
        ],
        "Xmax": [
          " 2DOTSYMBOL55"
        ],
        "Xmin": [
          "-2DOTSYMBOL55"
        ],
        "Ymax": [
          " 2"
        ],
        "Ymin": [
          "-2"
        ],
        "Zmax": [
          " 1DOTSYMBOL8"
        ],
        "Zmin": [
          "-1DOTSYMBOL8"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Pseudo Hopf Tori by Abderrahman Taha 10/10/2015"
        ],
        "Name": [
          "Pseudo Hopf Tori"
        ],
        "Component": [
          "PseudoHopfTori"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=3"
        ],
        "Funct": [
          "Thickness= (abs(sin(15*u)*cos(15*v)))^7 + 0DOTSYMBOL4*((sin(2*N*u)))",
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
          "R=sqrt(n1(u,v,t)^2+n2(u,v,t)^2+n3(u,v,t)^2)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Embedding of the Square Flat Torus (Level 3 ) by Abderrahman Taha 13/10/2015"
        ],
        "Name": [
          "Embedded Square Flat Torus L3"
        ],
        "Component": [
          "EmbeddedSquareFlatTorus"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=10"
        ],
        "Funct": [
          "Thickness2=if(sin(N*u)>0, 0DOTSYMBOL5*t*((sin(N*u)))^(1/4), - 0DOTSYMBOL5*t*(-(sin(N*u)))^(1/4)) ",
          "Thickness= Thickness2(u,v,1) + Thickness2(15*v-5*u,v,0DOTSYMBOL05)",
          "Fx=(4+ 2*cos(u))*cos(v)",
          "Fy=2*sin(u)",
          "Fz=(4+2*cos(u))*sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Embedding of the Square Flat Torus (Level 2 ) by Abderrahman Taha 13/10/2015"
        ],
        "Name": [
          "Embedded Square Flat Torus L2"
        ],
        "Component": [
          "EmbeddedSquareFlatTorus"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=10"
        ],
        "Funct": [
          "Thickness2=if(sin(N*u)>0, 0DOTSYMBOL5*((sin(N*u)))^(1/4), - 0DOTSYMBOL5*(-(sin(N*u)))^(1/4)) ",
          "Thickness= Thickness2(u,v,t)",
          "Fx=(4+ 2*cos(u))*cos(v)",
          "Fy=2*sin(u)",
          "Fz=(4+2*cos(u))*sin(v)",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Sleeping bugs by Abderrahman Taha 11/10/2015"
        ],
        "Name": [
          "Sleeping bugs"
        ],
        "Component": [
          "Sleepingbugs"
        ],
        "Const": [
          "cu=0DOTSYMBOL001",
          "cv=0DOTSYMBOL001",
          "N=3"
        ],
        "Funct": [
          "Thickness= - 0DOTSYMBOL5*(abs(sin(15*u)*cos(15*v)))^7 + 0DOTSYMBOL35*((sin(2*N*u)))",
          "Fx=-cos(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
          "Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL9",
          "G=0DOTSYMBOL81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))+ 0DOTSYMBOL3",
          "B=0DOTSYMBOL8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(2*x,2*y,2*z,4,2,0)+NoiseP(2*x,2*y,2*z,4,12,1/10)"
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Pseudo Hopf Tori by Abderrahman Taha 10/10/2015"
        ],
        "Name": [
          "Pseudo Hopf Tori_3"
        ],
        "Component": [
          "PseudoHopfTori"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001",
          "N=3"
        ],
        "Funct": [
          "Thickness= (abs(sin(15*u)*cos(15*v)))^7 + 0DOTSYMBOL4*((sin(2*N*u)))",
          "Fx=-cos(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
          "Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
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
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Alien by Abderrahman Taha 10/10/2015"
        ],
        "Name": [
          "Alien"
        ],
        "Component": [
          "Alien"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Fx=-cos(u) *(3 *cos(v) - cos(3 *v))",
          "Fy= 3 *sin(v) - sin(3 * v)",
          "Fz= sin(u) *(3 *cos(v) - cos(3 * v))",
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
          "Thickness= ( 0DOTSYMBOL4*abs(cos(11*(u))^2 - sin(13*(v))^5 ))^3",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/(R(u,v,t)+ 0DOTSYMBOL0001)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/(R(u,v,t)+ 0DOTSYMBOL0001)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/(R(u,v,t)+ 0DOTSYMBOL0001)"
        ],
        "Fx": [
          "Gx(u*cos(v),v*sin(u),t)"
        ],
        "Fy": [
          "Gy(u*cos(v),v*sin(u),t)"
        ],
        "Fz": [
          "Gz(u*cos(v),v*sin(u),t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          " pi/2"
        ],
        "Vmin": [
          "-pi/2"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Shells by Abderrahman Taha 09/10/2015"
        ],
        "Name": [
          "Shells_1"
        ],
        "Component": [
          "Shells"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Fx=-cos(u) *(3 *cos(v) - cos(3 *v))",
          "Fy= 3 *sin(v) - sin(3 * v)",
          "Fz= sin(u) *(3 *cos(v) - cos(3 * v))",
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
          "Thickness=( 0DOTSYMBOL4*abs(cos(11*(u))^2 - sin(13*(v))^5 ))^3",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/(R(u,v,t)+ 0DOTSYMBOL0001)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/(R(u,v,t)+ 0DOTSYMBOL0001)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/(R(u,v,t)+ 0DOTSYMBOL0001)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          " pi/2"
        ],
        "Vmin": [
          "-pi/2"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Spiny Torus by Abderrahman Taha 09/10/2015"
        ],
        "Name": [
          "Spiny Torus"
        ],
        "Component": [
          "SpinyTorus"
        ],
        "Funct": [
          "Thickness=-( 0DOTSYMBOL27*abs(cos(11*(u+v))^2 - sin(13*(v-u))^5 ))^2DOTSYMBOL9"
        ],
        "Fx": [
          "-(1+ 0DOTSYMBOL5*cos(u))*cos(v)+Thickness(u,v,t)*(0DOTSYMBOL5*cos(u)*(1+ 0DOTSYMBOL5*cos(u))*cos(v))/sqrt((0DOTSYMBOL5*cos(u)*(1+ 0DOTSYMBOL5*cos(u))*cos(v))^2+(-0DOTSYMBOL5*sin(u)*sin(v)*sin(v)*(1+ 0DOTSYMBOL5*cos(u))- 0DOTSYMBOL5*sin(u)*cos(v)*(1+ 0DOTSYMBOL5*cos(u))*cos(v))^2+(-0DOTSYMBOL5*cos(u)*sin(v)*(1+ 0DOTSYMBOL5*cos(u)))^2)"
        ],
        "Fy": [
          "0DOTSYMBOL5*sin(u)+Thickness(u,v,t)*(-0DOTSYMBOL5*sin(u)*sin(v)*sin(v)*(1+ 0DOTSYMBOL5*cos(u))- 0DOTSYMBOL5*sin(u)*cos(v)*(1+ 0DOTSYMBOL5*cos(u))*cos(v))/sqrt((0DOTSYMBOL5*cos(u)*(1+ 0DOTSYMBOL5*cos(u))*cos(v))^2+(-0DOTSYMBOL5*sin(u)*sin(v)*sin(v)*(1+ 0DOTSYMBOL5*cos(u))- 0DOTSYMBOL5*sin(u)*cos(v)*(1+ 0DOTSYMBOL5*cos(u))*cos(v))^2+(-0DOTSYMBOL5*cos(u)*sin(v)*(1+ 0DOTSYMBOL5*cos(u)))^2)"
        ],
        "Fz": [
          "(1+ 0DOTSYMBOL5*cos(u))*sin(v)+Thickness(u,v,t)*(-0DOTSYMBOL5*cos(u)*sin(v)*(1+ 0DOTSYMBOL5*cos(u)))/sqrt((0DOTSYMBOL5*cos(u)*(1+ 0DOTSYMBOL5*cos(u))*cos(v))^2+(-0DOTSYMBOL5*sin(u)*sin(v)*sin(v)*(1+ 0DOTSYMBOL5*cos(u))- 0DOTSYMBOL5*sin(u)*cos(v)*(1+ 0DOTSYMBOL5*cos(u))*cos(v))^2+(-0DOTSYMBOL5*cos(u)*sin(v)*(1+ 0DOTSYMBOL5*cos(u)))^2)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Holed Spheres (implicit version) by Abderrahman Taha 09/10/2015. In this example:Thickness= 0DOTSYMBOL05*cos((abs(cos(21*atan2(x,y))+sin(19*atan2(z,sqrt(x*x+y*y))))/1DOTSYMBOL1)^2)"
        ],
        "Name": [
          "Holed Spheres v2 (implicit version)"
        ],
        "Component": [
          "HoledSphere"
        ],
        "Fxyz": [
          "min(x*x+y*y+z*z-1,(x*x*(1-( 0DOTSYMBOL05*cos((abs(cos(21*atan2(x,y))+sin(19*atan2(z,sqrt(x*x+y*y))))/1DOTSYMBOL1)^2))/sqrt(x*x+y*y+z*z))^2+y*y*(1-( 0DOTSYMBOL05*cos((abs(cos(21*atan2(x,y))+sin(19*atan2(z,sqrt(x*x+y*y))))/1DOTSYMBOL1)^2))/sqrt(x*x+y*y+z*z))^2+z*z*(1-( 0DOTSYMBOL05*cos((abs(cos(21*atan2(x,y))+sin(19*atan2(z,sqrt(x*x+y*y))))/1DOTSYMBOL1)^2))/sqrt(x*x+y*y+z*z))^2-1))*(x*x+y*y+z*z-1)"
        ],
        "Xmax": [
          "1DOTSYMBOL2"
        ],
        "Xmin": [
          "-1DOTSYMBOL2"
        ],
        "Ymax": [
          "1DOTSYMBOL2"
        ],
        "Ymin": [
          "-1DOTSYMBOL2"
        ],
        "Zmax": [
          "1DOTSYMBOL2"
        ],
        "Zmin": [
          "-1DOTSYMBOL2"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Holed Sphere by Abderrahman Taha 9/10/2015"
        ],
        "Name": [
          "Holed Sphere v2 (parametric version)"
        ],
        "Component": [
          "HoledSphere"
        ],
        "Fx": [
          "(cos(u)*cos(v))+( 0DOTSYMBOL3*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/1DOTSYMBOL8)^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/1DOTSYMBOL9)^5DOTSYMBOL5))*(-cos(u)*cos(u)*cos(v))/sqrt((-cos(u)*cos(u)*cos(v))^2+(-cos(u)*sin(v)*cos(u))^2+(-sin(u)*cos(v)*cos(u)*cos(v)-sin(v)*cos(u)*sin(u)*sin(v))^2)"
        ],
        "Fy": [
          "(cos(u)*sin(v))+( 0DOTSYMBOL3*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/1DOTSYMBOL8)^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/1DOTSYMBOL9)^5DOTSYMBOL5))*(-cos(u)*sin(v)*cos(u))/sqrt((-cos(u)*cos(u)*cos(v))^2+(-cos(u)*sin(v)*cos(u))^2+(-sin(u)*cos(v)*cos(u)*cos(v)-sin(v)*cos(u)*sin(u)*sin(v))^2)"
        ],
        "Fz": [
          "(sin(u))+( 0DOTSYMBOL3*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/1DOTSYMBOL8)^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/1DOTSYMBOL9)^5DOTSYMBOL5))*(-sin(u)*cos(v)*cos(u)*cos(v)-sin(v)*cos(u)*sin(u)*sin(v))/sqrt((-cos(u)*cos(u)*cos(v))^2+(-cos(u)*sin(v)*cos(u))^2+(-sin(u)*cos(v)*cos(u)*cos(v)-sin(v)*cos(u)*sin(u)*sin(v))^2)"
        ],
        "Umax": [
          "pi/2"
        ],
        "Umin": [
          "-pi/2"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Holed Spheres (implicit version) by Abderrahman Taha 08/10/2015"
        ],
        "Name": [
          "Holed Spheres (implicit version)"
        ],
        "Component": [
          "HoledSphere_2"
        ],
        "Const": [
          "cx=0DOTSYMBOL0001",
          "cy=0DOTSYMBOL0001",
          "cz=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Iso=x*x+y*y+z*z-1",
          "Thickness=( 0DOTSYMBOL05*cos((abs(cos(21*atan2(x,y))+sin(19*atan2(z,sqrt(x*x+y*y))))/1DOTSYMBOL1)^2))",
          "DFx=((Iso(x,y,z,t)-Iso(x+cx,y,z,t))/cx)",
          "DFy=((Iso(x,y,z,t)-Iso(x,y+cy,z,t))/cy)",
          "DFz=((Iso(x,y,z,t)-Iso(x,y,z+cz,t))/cz)",
          "Rapport=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
          "Iso2=(Iso(x+t*DFx(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),y+t*DFy(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),z+t*DFz(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),t))",
          "ThickIso=max(Iso2(x,y,z,1), Iso2(x,y,z,-1))"
        ],
        "Fxyz": [
          "-max(Iso2(x,y,z,1), (x*x+y*y+z*z-1))*Iso2(x,y,z,1)"
        ],
        "Xmax": [
          "1DOTSYMBOL2"
        ],
        "Xmin": [
          "-1DOTSYMBOL2"
        ],
        "Ymax": [
          "1DOTSYMBOL2"
        ],
        "Ymin": [
          "-1DOTSYMBOL2"
        ],
        "Zmax": [
          "1DOTSYMBOL2"
        ],
        "Zmin": [
          "-1DOTSYMBOL2"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Holed Spheres by Abderrahman Taha 08/10/2015"
        ],
        "Name": [
          "Holed Spheres_3"
        ],
        "Component": [
          "HoledSpheres"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Thickness= 0DOTSYMBOL3*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/1DOTSYMBOL8)^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/1DOTSYMBOL9)^5DOTSYMBOL5)",
          "Fx=cos(u)*cos(v)",
          "Fy=cos(u)*sin(v)",
          "Fz=sin(u)",
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
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "pi/2"
        ],
        "Umin": [
          "-pi/2"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Holed Spheres by Abderrahman Taha 08/10/2015"
        ],
        "Name": [
          "Holed Spheres_4"
        ],
        "Component": [
          "HoledSpheres"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          " Thickness= (abs(cos(7*u)+cos(7*(v-u*u*u*u*u))*sin(11*v))/2)^9",
          "Fx=cos(u)*cos(v)",
          "Fy=cos(u)*sin(v)",
          "Fz=sin(u)",
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
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "pi/2"
        ],
        "Umin": [
          "-pi/2"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Holed Spheres by Abderrahman Taha 08/10/2015"
        ],
        "Name": [
          "Holed Spheres_5"
        ],
        "Component": [
          "HoledSpheres"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          " Thickness= (abs(cos(7*u)+cos(7*(v-u*u*u))*sin(11*v))/2)^9",
          "Fx=cos(u)*cos(v)",
          "Fy=cos(u)*sin(v)",
          "Fz=sin(u)",
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
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "pi/2"
        ],
        "Umin": [
          "-pi/2"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "-pi"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Holed Clifford Torus by Abderrahman Taha 07/10/2015"
        ],
        "Name": [
          "Holed Clifford Torus"
        ],
        "Component": [
          "HoledCliffordTorus"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Fx=-(cos(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u)))",
          "Fy=sin(v-u)/(sqrt(2DOTSYMBOL)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
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
          "Thickness=(abs(sin(15*u)*cos(15*v)))^7",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Spiny Sea Creature by Abderrahman Taha 06/10/2015"
        ],
        "Name": [
          "Spiny Sea Creature"
        ],
        "Component": [
          "SpinySeaCreature"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Fx=cos(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
          "Fy=sin(v-u)/(sqrt(2DOTSYMBOL)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
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
          "Thickness=(abs(sin(15*u)*cos(15*v)))^4",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Skeletal Sphere (parametric version) by Abderrahman Taha 05/10/2015"
        ],
        "Name": [
          "Skeletal Sphere (parametric version)"
        ],
        "Component": [
          "SkeletalSphere"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Fx=cos(u)*cos(v)",
          "Fy=cos(u)*sin(v)",
          "Fz=sin(u)",
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
          "Thickness=abs( 0DOTSYMBOL1*cos(10*u)*sin(10*v))",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "pi/2"
        ],
        "Umin": [
          "-pi/2"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Skeletal Sphere (implicit version) by Abderrahman Taha 06/10/2015"
        ],
        "Name": [
          "Skeletal Sphere (implicit version)"
        ],
        "Component": [
          "SkeletalSphere"
        ],
        "Const": [
          "cx=0DOTSYMBOL0001",
          "cy=0DOTSYMBOL0001",
          "cz=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Iso=x*x+y*y+z*z-1",
          "Thickness=( 0DOTSYMBOL1*cos(10*atan2(x,y))*sin(10*atan2(z,sqrt(x*x+y*y))))",
          "DFx=((Iso(x,y,z,t)-Iso(x+cx,y,z,t))/cx)",
          "DFy=((Iso(x,y,z,t)-Iso(x,y+cy,z,t))/cy)",
          "DFz=((Iso(x,y,z,t)-Iso(x,y,z+cz,t))/cz)",
          "Rapport=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
          "Iso2=(Iso(x+t*DFx(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),y+t*DFy(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),z+t*DFz(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),t))",
          "ThickIso=max(Iso2(x,y,z,1), Iso2(x,y,z,-1))"
        ],
        "Fxyz": [
          "ThickIso(x,y,z,t)"
        ],
        "Xmax": [
          "1DOTSYMBOL2"
        ],
        "Xmin": [
          "-1DOTSYMBOL2"
        ],
        "Ymax": [
          "1DOTSYMBOL2"
        ],
        "Ymin": [
          "-1DOTSYMBOL2"
        ],
        "Zmax": [
          "1DOTSYMBOL2"
        ],
        "Zmin": [
          "-1DOTSYMBOL2"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Twisted Clifford Torus by Abderrahman Taha 05/10/2015"
        ],
        "Name": [
          "Twisted Clifford Torus"
        ],
        "Component": [
          "TwistedClifford"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Fx=cos(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
          "Fy=sin(v-u)/(sqrt(2DOTSYMBOL)+cos(v-u))",
          "Fz=sin(u+v)/(sqrt(2DOTSYMBOL)+cos(v-u))",
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
          "Thickness=0DOTSYMBOL3*sin(10*u)*cos(10*v)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Name": [
          "Bumpy Klein"
        ],
        "Description ": [
          "Bumpy Klein by Abderrahman Taha 05/10/2015"
        ],
        "Component": [
          "Klein"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Fx=(2+cos(v/2)*sin(u)-sin(v/2)*sin(2*u))*cos(v)",
          "Fy=sin(v/2)*sin(u)+cos(v/2)*sin(2*u)",
          "Fz=(2+cos(v/2)*sin(u)-sin(v/2)*sin(2*u))*sin(v)",
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
          "Thickness=0DOTSYMBOL1*sin(20*v)*cos(20*u)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "2*pi"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Richmond polar Parametric surface by Abderrahman Taha 04/10/2015"
        ],
        "Component": [
          "richmondpolar1"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Fx=-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6",
          "Fy=-sin(t+v)/(2*u)+u^3*sin(t-3*v)/6",
          "Fz=u*cos(t-v)",
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
          "Thickness=0DOTSYMBOL3",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Fx(u,v,t)"
        ],
        "Fy": [
          "Fy(u,v,t)"
        ],
        "Fz": [
          "Fz(u,v,t)"
        ],
        "Name": [
          "Richmond Polar_1"
        ],
        "Umax": [
          "1DOTSYMBOL3"
        ],
        "Umin": [
          "0DOTSYMBOL3"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Richmond polar Parametric surface by Abderrahman Taha 04/10/2015"
        ],
        "Name": [
          "Richmond Polar_2"
        ],
        "Component": [
          "richmondpolar1",
          "richmondpolar2"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Fx=-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6",
          "Fy=-sin(t+v)/(2*u)+u^3*sin(t-3*v)/6",
          "Fz=u*cos(t-v)",
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
          "Thickness=0DOTSYMBOL1*sin(20*v)",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Fx(u,v,t)",
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Fy(u,v,t)",
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Fz(u,v,t)",
          "Gz(u,v,t)"
        ],
        "Umax": [
          "1DOTSYMBOL3",
          "1DOTSYMBOL3"
        ],
        "Umin": [
          "0DOTSYMBOL3",
          "0DOTSYMBOL3"
        ],
        "Vmax": [
          "2*pi",
          "2*pi"
        ],
        "Vmin": [
          "0",
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Richmond polar Parametric surface by Abderrahman Taha 04/10/2015"
        ],
        "Name": [
          "Bat coat"
        ],
        "Component": [
          "richmondpolar2"
        ],
        "Const": [
          "cu=0DOTSYMBOL0001",
          "cv=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Fx=-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6",
          "Fy=-sin(t+v)/(2*u)+u^3*sin(t-3*v)/6",
          "Fz=u*cos(t-v)",
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
          "Thickness=DFyu(u,v,t)*DFxv(u,v,t)*0DOTSYMBOL5",
          "Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
          "Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
          "Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"
        ],
        "Fx": [
          "Gx(u,v,t)"
        ],
        "Fy": [
          "Gy(u,v,t)"
        ],
        "Fz": [
          "Gz(u,v,t)"
        ],
        "Umax": [
          "1DOTSYMBOL3"
        ],
        "Umin": [
          "0DOTSYMBOL3"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Param3D": {
        "Description ": [
          "Under Sea by Abderrahman Taha 02/10/2015"
        ],
        "Name": [
          "Under The Sea_01"
        ],
        "Component": [
          "UnderSea"
        ],
        "Fx": [
          "u*cos(v)"
        ],
        "Fy": [
          "u*sin(v)"
        ],
        "Fz": [
          "exp(-u*u)*(sin(2*pi*u)-u*cos(3*v))"
        ],
        "Umax": [
          "2"
        ],
        "Umin": [
          "0"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=1DOTSYMBOL5* 0DOTSYMBOL41",
          "G=2*0DOTSYMBOL81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "B=2*0DOTSYMBOL8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(4*x,4*y,4*z,4,2,0)+NoiseW(4*x,4*y,4*z,4,12,1/10)"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Devil's Plate by Abderrahman Taha 01/10/2015"
        ],
        "Name": [
          "Devil Plate"
        ],
        "Component": [
          "DevilPlate"
        ],
        "Const": [
          "cx=0DOTSYMBOL001",
          "cy=0DOTSYMBOL001",
          "cz=0DOTSYMBOL00"
        ],
        "Funct": [
          "Devil=x^4+2*x^2*z^2-0DOTSYMBOL36*x^2-y^4+0DOTSYMBOL25*y^2+z^4",
          "Devil2=Devil(x,sqrt(y*y+z*z)-1DOTSYMBOL5,z,t)",
          "Thickness2=( 0DOTSYMBOL1)",
          "IsoExterior=Devil2(x,y,sqrt(x*x+z*z)-1DOTSYMBOL5,t)",
          "DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
          "DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
          "DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
          "Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
          "Iso2=(IsoExterior(x+t*DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y+t*DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z+t*DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
          "ThickIsoExterior=(Iso2(x,y,z,1)*Iso2(x,y,z,-1))"
        ],
        "Fxyz": [
          "if(y<4DOTSYMBOL4 & y> -2DOTSYMBOL4, ThickIsoExterior(x/1DOTSYMBOL5,y,z,t), 1)"
        ],
        "Xmax": [
          " 4DOTSYMBOL5"
        ],
        "Xmin": [
          "-4DOTSYMBOL5"
        ],
        "Ymax": [
          " 4DOTSYMBOL5"
        ],
        "Ymin": [
          "-2DOTSYMBOL5"
        ],
        "Zmax": [
          " 7DOTSYMBOL5"
        ],
        "Zmin": [
          "-7DOTSYMBOL5"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL95*abs(cos(z*y*x))",
          "G=0DOTSYMBOL45*abs(cos(z*y*x))",
          "B=0DOTSYMBOL02*abs(cos(-z*x*z*x*y*y))",
          "T=1"
        ],
        "Name": "Granit_1",
        "Noise": "NoiseP(x-14,y-17,z-16,10,7,12/100)"
      }
    },
    {
      "Iso3D": {
        "Component": [
          "DevilPlay"
        ],
        "Const": [
          "cx=0DOTSYMBOL0001",
          "cy=0DOTSYMBOL0001",
          "cz=0DOTSYMBOL0001"
        ],
        "Description": [
          "Devil Play by Abderrahman Taha 01/10/2015"
        ],
        "Funct": [
          "Devil=x^4+2*x^2*z^2-0DOTSYMBOL36*x^2-y^4+0DOTSYMBOL25*y^2+z^4",
          "Devil2=Devil(x,sqrt(y*y+z*z)-1DOTSYMBOL5,z,t)",
          "Thickness2=( 0DOTSYMBOL1)",
          "IsoExterior=Devil2(x,y,sqrt(x*x+z*z)-1DOTSYMBOL5,t)",
          "DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
          "DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
          "DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
          "Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
          "Iso2=(IsoExterior(x+t*DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y+t*DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z+t*DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
          "ThickIsoExterior=(Iso2(x,y,z,1)*Iso2(x,y,z,-1))"
        ],
        "Fxyz": [
          "IsoExterior(x,y,z,t)"
        ],
        "Name": [
          "Devil Play"
        ],
        "Xmax": [
          " 4DOTSYMBOL5"
        ],
        "Xmin": [
          "-4DOTSYMBOL5"
        ],
        "Ymax": [
          " 4DOTSYMBOL5"
        ],
        "Ymin": [
          "-2DOTSYMBOL5"
        ],
        "Zmax": [
          " 7DOTSYMBOL5"
        ],
        "Zmin": [
          "-7DOTSYMBOL5"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Tore-1DOTSYMBOL0 by Abderrahman Taha 29/09/2015"
        ],
        "Name": [
          "ToreSherk"
        ],
        "Component": [
          "ToreSherk"
        ],
        "Const": [
          "cx=0DOTSYMBOL0001",
          "cy=0DOTSYMBOL0001",
          "cz=0DOTSYMBOL0001"
        ],
        "Funct": [
          "Scherk=sinh(x)*sinh(y)-5*sin(z)",
          "Scherk2=Scherk(x,(sqrt(y*y+x*x)-10),z,t)",
          "Thickness2=( 0DOTSYMBOL43)",
          "IsoExterior=Scherk2(x,(sqrt(y*y+z*z)-26),z,t)",
          "DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
          "DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
          "DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
          "Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
          "Iso3=(IsoExterior(x-DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y-DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z-DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
          "Iso2=(IsoExterior(x+DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y+DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z+DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
          "ThickIsoExterior=(Iso2(x,y,z,t)*Iso3(x,y,z,t))"
        ],
        "Fxyz": [
          "if((sqrt(y*y+z*z)-37<0)&(sqrt(y*y+z*z)-16>0) & ( (sqrt(y*y+z*z)-26)^2+x*x-75>0 ),ThickIsoExterior(x,y,z,t),1)+ 0DOTSYMBOL1"
        ],
        "Xmax": [
          "11"
        ],
        "Xmin": [
          "-11"
        ],
        "Ymax": [
          "38"
        ],
        "Ymin": [
          "-38"
        ],
        "Zmax": [
          "38"
        ],
        "Zmin": [
          "-38"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL71",
          "G=1DOTSYMBOL1*abs(cos((x*x+y*y+z*z))*sin((x*x+y*y+z*z)/2))",
          "B=0DOTSYMBOL01*abs(cos((x*x+y*y+z*z))*cos((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "PerlinNoise",
        "Noise": "NoiseP(x,y,z,6,7/10,1)/30"
      }
    },
    {
      "Iso3D": {
        "Description ": ["Geode by Abderrahman Taha 28/09/2015"],
        "Name": ["Geode"],
        "Component": ["Geode1","Geode2"],
        "Const": [
          "A=4",
          "B=3"],
        "Fxyz": [
          "-((((x/1DOTSYMBOL01)^2+y^2+(z/1DOTSYMBOL05)^2-1)+(NoiseW(A*x,A*y,A*z,4,2,1)+NoiseW(A*x,A*y,A*z,4,0,0))/3))*(atan2(x,y)<pi/2)*(x^2+y^2+z^2-2/10)",
          "-(((x^2+y^2+z^2-0DOTSYMBOL21)*(atan2(x,y)<pi/2)*((x^2+y^2+z^2-0DOTSYMBOL2)+(NoiseW(B*x,B*y,B*z,4,2,1)+NoiseW(B*x,B*y,B*z,4,2,1))/5)))"],
        "Xmax": [
          "1DOTSYMBOL5",
          "1DOTSYMBOL5"],
        "Xmin": [
          "-1",
          "-1"],
        "Ymax": [
          "1",
          "1" ],
        "Ymin": [
          "-1",
          "-1"],
        "Zmax": [
          "1DOTSYMBOL5",
          "1DOTSYMBOL5"],
        "Zmin": [
          "-1",
          "-1"
        ]
      },
      "Texture": {
        "Colors": [
          "R=if((x*x+y*y+z*z)>0DOTSYMBOL81,0DOTSYMBOL95*cos((x*x+y*y+z*z)/1DOTSYMBOL7), 0DOTSYMBOL2)",
          "G=if((x*x+y*y+z*z)>0DOTSYMBOL8, 0DOTSYMBOL8*(cos((x*x+y*y+z*z)/5)*sin((x*x+y*y+z*z)))*sin((x*x+y*y+z*z)/0DOTSYMBOL3), 0DOTSYMBOL5*sin((x*x+y*y+z*z)*9))",
          "B=if((x*x+y*y+z*z)<0DOTSYMBOL8,(cos((x*x+y*y+z*z))*cos((x*x+y*y+z*z))*sin((x*x+y*y+z*z)))+ 0DOTSYMBOL4, 0DOTSYMBOL1)",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "-(NoiseW(2*x,2*y,2*z,4,0,0)+NoiseW(2*x,2*y,2*z,4,0,0))"
      }
    },
    {
      "Iso3D": {
        "Name": [
          "The Core"
        ],
        "Component": [
          "Core"
        ],
        "Description ": [
          "The core by Abderrahman Taha 27/09/2015"
        ],
        "Fxyz": [
          "-((x^2+y^2+z^2-1)+(NoiseW(6*x,6*y,6*z,4,2,0)+NoiseW(6*x,6*y,6*z,4,0,0))/5)*(atan2(x,y)<pi/2)"
        ],
        "Xmax": [
          "1"
        ],
        "Xmin": [
          "-1"
        ],
        "Ymax": [
          "1"
        ],
        "Ymin": [
          "-1"
        ],
        "Zmax": [
          "1"
        ],
        "Zmin": [
          "-1"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL7",
          "G=2DOTSYMBOL4*(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))*sin((x*x+y*y+z*z)/2)",
          "B=0DOTSYMBOL7*(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(2*x,2*y,2*z,4,0,0)+NoiseW(2*x,2*y,2*z,2,0,0)"
      }
    },
    {
      "Param3D": {
        "Name": [
          "Richmond Polar_4"
        ],
        "Component": [
          "richmondpolar"
        ],
        "Description ": [
          "richmondpolar(n)[t](u,v):={-cos(t + v)/(2*u) -u^(2*n + 1)*cos(t - (2*n + 1)*v)/(4*n + 2),-sin(t + v)/(2*u) +u^(2*n + 1)*sin(t - (2*n + 1)*v)/(4*n + 2),u^n*cos(t - n*v)/n}is the polar parametrization of a 1-parameter family of minimal surfaces such that {r,theta}->richmondpolar[n][0][r,theta] is a minimal surface with one planar end of degree n."
        ],
        "Fx": [
          "-cos(t + v)/(2*u) - u^3*cos(t - 3*v)/6"
        ],
        "Fy": [
          "-sin(t + v)/(2*u) + u^3*sin(t - 3*v)/6"
        ],
        "Fz": [
          "u*cos(t - v)"
        ],
        "Umax": [
          "1DOTSYMBOL3"
        ],
        "Umin": [
          "0DOTSYMBOL3"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      },
      "Texture": {
        "Colors": [
          "R=1DOTSYMBOL5* 0DOTSYMBOL41",
          "G=2*0DOTSYMBOL81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "B=2*0DOTSYMBOL8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
          "T=1"
        ],
        "Name": "WorleyNoise",
        "Noise": "NoiseW(4*x,4*y,4*z,4,2,0)+NoiseW(4*x,4*y,4*z,4,12,1/10)"
      }
    },
    {
      "Param3D": {
        "Description": [
          "Flower_1 by Abderrahman Taha 26/09/2015"
        ],
        "Name": [
          "Flower"
        ],
        "Component": [
          "BreatherNoise"
        ],
        "Fx": [
          "((2*sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u)*(-(sqrt(0DOTSYMBOL84)*cos(v)*cos(sqrt(0DOTSYMBOL84)*v))-sin(v)*sin(sqrt(0DOTSYMBOL84)*v)))/(0DOTSYMBOL4*((sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u))^2+(0DOTSYMBOL4*sin(sqrt(0DOTSYMBOL84)*v))^2)))*(1-NoiseW(((2*sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u)*(-(sqrt(0DOTSYMBOL84)*cos(v)*cos(sqrt(0DOTSYMBOL84)*v))-sin(v)*sin(sqrt(0DOTSYMBOL84)*v)))/(0DOTSYMBOL4*((sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u))^2+(0DOTSYMBOL4*sin(sqrt(0DOTSYMBOL84)*v))^2))),((2*sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u)*(-(sqrt(0DOTSYMBOL84)*sin(v)*cos(sqrt(0DOTSYMBOL84)*v))+cos(v)*sin(sqrt(0DOTSYMBOL84)*v)))/(0DOTSYMBOL4*((sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u))^2+(0DOTSYMBOL4*sin(sqrt(0DOTSYMBOL84)*v))^2))),(-u+(2*0DOTSYMBOL84*cosh(0DOTSYMBOL4*u)*sinh(0DOTSYMBOL4*u))/(0DOTSYMBOL4*((sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u))^2+(0DOTSYMBOL4*sin(sqrt(0DOTSYMBOL84)*v))^2))),1,2,0))"
        ],
        "Fy": [
          "((2*sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u)*(-(sqrt(0DOTSYMBOL84)*sin(v)*cos(sqrt(0DOTSYMBOL84)*v))+cos(v)*sin(sqrt(0DOTSYMBOL84)*v)))/(0DOTSYMBOL4*((sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u))^2+(0DOTSYMBOL4*sin(sqrt(0DOTSYMBOL84)*v))^2)))*(1 -NoiseW(((2*sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u)*(-(sqrt(0DOTSYMBOL84)*cos(v)*cos(sqrt(0DOTSYMBOL84)*v))-sin(v)*sin(sqrt(0DOTSYMBOL84)*v)))/(0DOTSYMBOL4*((sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u))^2+(0DOTSYMBOL4*sin(sqrt(0DOTSYMBOL84)*v))^2))),((2*sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u)*(-(sqrt(0DOTSYMBOL84)*sin(v)*cos(sqrt(0DOTSYMBOL84)*v))+cos(v)*sin(sqrt(0DOTSYMBOL84)*v)))/(0DOTSYMBOL4*((sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u))^2+(0DOTSYMBOL4*sin(sqrt(0DOTSYMBOL84)*v))^2))),(-u+(2*0DOTSYMBOL84*cosh(0DOTSYMBOL4*u)*sinh(0DOTSYMBOL4*u))/(0DOTSYMBOL4*((sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u))^2+(0DOTSYMBOL4*sin(sqrt(0DOTSYMBOL84)*v))^2))),1,2,0))"
        ],
        "Fz": [
          "(-u+(2*0DOTSYMBOL84*cosh(0DOTSYMBOL4*u)*sinh(0DOTSYMBOL4*u))/(0DOTSYMBOL4*((sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u))^2+(0DOTSYMBOL4*sin(sqrt(0DOTSYMBOL84)*v))^2)))*(1 - NoiseW(((2*sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u)*(-(sqrt(0DOTSYMBOL84)*cos(v)*cos(sqrt(0DOTSYMBOL84)*v))-sin(v)*sin(sqrt(0DOTSYMBOL84)*v)))/(0DOTSYMBOL4*((sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u))^2+(0DOTSYMBOL4*sin(sqrt(0DOTSYMBOL84)*v))^2))),((2*sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u)*(-(sqrt(0DOTSYMBOL84)*sin(v)*cos(sqrt(0DOTSYMBOL84)*v))+cos(v)*sin(sqrt(0DOTSYMBOL84)*v)))/(0DOTSYMBOL4*((sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u))^2+(0DOTSYMBOL4*sin(sqrt(0DOTSYMBOL84)*v))^2))),(-u+(2*0DOTSYMBOL84*cosh(0DOTSYMBOL4*u)*sinh(0DOTSYMBOL4*u))/(0DOTSYMBOL4*((sqrt(0DOTSYMBOL84)*cosh(0DOTSYMBOL4*u))^2+(0DOTSYMBOL4*sin(sqrt(0DOTSYMBOL84)*v))^2))),1,2,0))"
        ],
        "Umax": [
          "13DOTSYMBOL2"
        ],
        "Umin": [
          "-13DOTSYMBOL2"
        ],
        "Vmax": [
          "37DOTSYMBOL4"
        ],
        "Vmin": [
          "-37DOTSYMBOL4"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Broken Jar by Abderrahman Taha 24/09/2015"
        ],
        "Name": [
          "BrokenJar"
        ],
        "Component": [
          "Vase1",
          "Vase2",
          "Vase3",
          "Vase4"
        ],
        "Const": [
          "cx=0DOTSYMBOL0001",
          "cy=0DOTSYMBOL0001",
          "cz=0DOTSYMBOL0001",
          "S=6",
          "Thickness2=( 0DOTSYMBOL25)",
          "Thickness4=( 0DOTSYMBOL2)",
          "Thickness5=( 0DOTSYMBOL2)",
          "Thickness6=(1DOTSYMBOL2)",
          "Thickness7=(1DOTSYMBOL2)"
        ],
        "Funct": [
          "Angle1=atan2(sqrt(x*x+y*y),(-z+cx))",
          "Angle2=atan2(x,(y+cx))",
          "CarvinCondition=(abs((z-1)- 0DOTSYMBOL8*cos(18*Angle2(x,y,z,t)/pi))<1DOTSYMBOL3|abs((z+3)- 0DOTSYMBOL3*cos(18*Angle2(x,y,z,t)/pi+pi/4))<0DOTSYMBOL5)",
          "CarvinCondition2=(z-3*sin(3DOTSYMBOL2*Angle2(x,y,z,t)/pi))>0",
          "Torus=(sqrt(x*x+y*y)-3)^2+z*z-1",
          "IsoExterior=if(-z<5,(x*x/3DOTSYMBOL+y*y/3DOTSYMBOL-abs(1DOTSYMBOL5*sin(2*z/pi+ 0DOTSYMBOL3)+1DOTSYMBOL8)),-(-z-5))",
          "DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
          "DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
          "DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
          "Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
          "Iso2=(IsoExterior(x+t*DFx2(x,y,z,t)*Thickness2/Rapport2(x,y,z,t),y+t*DFy2(x,y,z,t)*Thickness2/Rapport2(x,y,z,t),z+t*DFz2(x,y,z,t)*Thickness2/Rapport2(x,y,z,t),t))",
          "ThickIsoExterior=(Iso2(x,y,z,1)*Iso2(x,y,z,-1))",
          "Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "DFx=((Iso(x,y,z,t)-Iso(x+cx,y,z,t))/cx)",
          "DFy=((Iso(x,y,z,t)-Iso(x,y+cy,z,t))/cy)",
          "DFz=((Iso(x,y,z,t)-Iso(x,y,z+cz,t))/cz)",
          "Rapport=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
          "Iso4=(Iso(x+t*DFx(x,y,z,t)*Thickness4/Rapport(x,y,z,t),y+t*DFy(x,y,z,t)*Thickness4/Rapport(x,y,z,t),z+t*DFz(x,y,z,t)*Thickness4/Rapport(x,y,z,t),t))",
          "ThickIso2=(Iso4(x,y,z,-1)*Iso4(x,y,z,1))",
          "isoTransform_2=if(CarvinCondition(x,y,z,t)=0,ThickIsoExterior(x,y,z,t),1)",
          "Iso6=(Iso(x+t*DFx(x,y,z,t)*Thickness6/Rapport(x,y,z,t),y+t*DFy(x,y,z,t)*Thickness6/Rapport(x,y,z,t),z+t*DFz(x,y,z,t)*Thickness6/Rapport(x,y,z,t),t))",
          "isoTransform_6=if(CarvinCondition(x,y,z,t)&ThickIsoExterior(x,y,z,t)<0,-ThickIso2(S*x,S*y,S*z,t)*Iso6(x*S,y*S,z*S,-1)*(Iso6(x*S,y*S,z*S,1)),1)",
          "VaseHead=if(CarvinCondition2(x,y,z,t),isoTransform_2(x,y,-z,t)*isoTransform_6(x,y,-z,t),1)",
          "VaseHead2=VaseHead((x+6)*cos(-pi/2)-(z+2DOTSYMBOL5)*sin(-pi/2),y,(x+6)*sin(-pi/2)+(z+2DOTSYMBOL5)*cos(-pi/2),t)",
          "Torus2=Torus(1DOTSYMBOL7*x,1DOTSYMBOL7*y,2DOTSYMBOL2*(z+cos(pi/4*sqrt(x*x+y*y)))-10DOTSYMBOL6,t)",
          "Torus3=Torus2((x+6)*cos(-pi/2)-(z+2DOTSYMBOL5)*sin(-pi/2),y,(x+6)*sin(-pi/2)+(z+2DOTSYMBOL5)*cos(-pi/2),t)",
          "VaseBottom=if(CarvinCondition2(x,y,z,t)=0,isoTransform_2(x,y,-z,t)*isoTransform_6(x,y,-z,t),1)"
        ],
        "Fxyz": [
          "VaseBottom(x*cos(-pi/5)-y*sin(-pi/5),x*sin(-pi/5)+y*cos(-pi/5),z,t)",
          "((x*x+y*y)/5DOTSYMBOL76+4*(z+5DOTSYMBOL1)*(z+5DOTSYMBOL1)-1)",
          "VaseHead2(x*cos(pi/2)-y*sin(pi/2)-5,x*sin(pi/2)+y*cos(pi/2)+6,z,t)",
          "Torus3(x*cos(pi/2)-y*sin(pi/2)-5,x*sin(pi/2)+y*cos(pi/2)+6,z,t)"
        ],
        "Xmax": [
          "3DOTSYMBOL5",
          "3",
          "-3",
          "-2"
        ],
        "Xmin": [
          "-3DOTSYMBOL5",
          "-3",
          "-9",
          "-9"
        ],
        "Ymax": [
          "3DOTSYMBOL5",
          "3",
          "5DOTSYMBOL47",
          "8"
        ],
        "Ymin": [
          "-3DOTSYMBOL5",
          "-3",
          "-2DOTSYMBOL5",
          "5"
        ],
        "Zmax": [
          "3",
          "-4DOTSYMBOL5",
          "1DOTSYMBOL5",
          "0"
        ],
        "Zmin": [
          "-5",
          "-5DOTSYMBOL7",
          "-6",
          "-5"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL95*abs(cos(z*y*x*y))",
          "G=0DOTSYMBOL45*abs(cos(z*y*x*y))",
          "B=0DOTSYMBOL02*abs(cos(-z*x*z*x*y*y))",
          "T=1"
        ],
        "Name": "Granit_1",
        "Noise": "NoiseP(x,y,z,10,7,12/100)"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Old Vase by Abderrahman Taha 23/09/2015"
        ],
        "Name": [
          "OldVase"
        ],
        "Component": [
          "Vase1",
          "Vase5",
          "Vase6"
        ],
        "Const": [
          "cx=0DOTSYMBOL0001",
          "cy=0DOTSYMBOL0001",
          "cz=0DOTSYMBOL0001",
          "S=6",
          "Thickness2=( 0DOTSYMBOL25)",
          "Thickness4=( 0DOTSYMBOL2)",
          "Thickness5=( 0DOTSYMBOL2)",
          "Thickness6=(1DOTSYMBOL2)",
          "Thickness7=(1DOTSYMBOL2)"
        ],
        "Funct": [
          "Angle1=atan2(sqrt(x*x+y*y),(-z+cx))",
          "Angle2=atan2(x,(y+cx))",
          "CarvinCondition=abs((z-1)- 0DOTSYMBOL8*cos(18*Angle2(x,y,z,t)/pi))<1DOTSYMBOL3|abs((z+3)- 0DOTSYMBOL3*cos(18*Angle2(x,y,z,t)/pi+pi/4))<0DOTSYMBOL5",
          "Torus=(sqrt(x*x+y*y)-3)^2+z*z-1",
          "Bottom=(x*x+y*y+z*z-1)",
          "IsoExterior=x*x/3DOTSYMBOL+y*y/3DOTSYMBOL-abs(1DOTSYMBOL5*sin(2*z/pi+ 0DOTSYMBOL3)+1DOTSYMBOL8)",
          "DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
          "DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
          "DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
          "Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
          "Iso2=(IsoExterior(x+t*DFx2(x,y,z,t)*Thickness2/Rapport2(x,y,z,t),y+t*DFy2(x,y,z,t)*Thickness2/Rapport2(x,y,z,t),z+t*DFz2(x,y,z,t)*Thickness2/Rapport2(x,y,z,t),t))",
          "ThickIsoExterior=(Iso2(x,y,z,1)*Iso2(x,y,z,-1))",
          "Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "DFx=((Iso(x,y,z,t)-Iso(x+cx,y,z,t))/cx)",
          "DFy=((Iso(x,y,z,t)-Iso(x,y+cy,z,t))/cy)",
          "DFz=((Iso(x,y,z,t)-Iso(x,y,z+cz,t))/cz)",
          "Rapport=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
          "Iso4=(Iso(x+t*DFx(x,y,z,t)*Thickness4/Rapport(x,y,z,t),y+t*DFy(x,y,z,t)*Thickness4/Rapport(x,y,z,t),z+t*DFz(x,y,z,t)*Thickness4/Rapport(x,y,z,t),t))",
          "ThickIso2=(Iso4(x,y,z,-1)*Iso4(x,y,z,1))",
          "isoTransform_2=if(CarvinCondition(x,y,z,t)=0,ThickIsoExterior(x,y,z,t),1)",
          "Iso6=(Iso(x+t*DFx(x,y,z,t)*Thickness6/Rapport(x,y,z,t),y+t*DFy(x,y,z,t)*Thickness6/Rapport(x,y,z,t),z+t*DFz(x,y,z,t)*Thickness6/Rapport(x,y,z,t),t))",
          "isoTransform_6=if(CarvinCondition(x,y,z,t)&ThickIsoExterior(x,y,z,t)<0,-ThickIso2(S*x,S*y,S*z,t)*Iso6(x*S,y*S,z*S,-1)*(Iso6(x*S,y*S,z*S,1)),1)"
        ],
        "Fxyz": [
          "isoTransform_2(x,y,-z,t)*isoTransform_6(x,y,-z,t)",
          "Torus(1DOTSYMBOL7*x,1DOTSYMBOL7*y,2DOTSYMBOL2*(z+cos(pi/4*sqrt(x*x+y*y)))-10DOTSYMBOL6,t)",
          "Bottom(x/2DOTSYMBOL4,y/2DOTSYMBOL4,2*(z+5DOTSYMBOL1),t)"
        ],
        "Xmax": [
          "3DOTSYMBOL5",
          "5",
          "3"
        ],
        "Xmin": [
          "-3DOTSYMBOL5",
          "-5",
          "-3"
        ],
        "Ymax": [
          "3DOTSYMBOL5",
          "5",
          "3"
        ],
        "Ymin": [
          "-3DOTSYMBOL5",
          "-5",
          "-3"
        ],
        "Zmax": [
          "4DOTSYMBOL5",
          "10",
          "-2"
        ],
        "Zmin": [
          "-5",
          "0",
          "-7"
        ]
      },
      "Texture": {
        "Colors": [
          "R=0DOTSYMBOL95*abs(cos(z*y*x*y))",
          "G=0DOTSYMBOL45*abs(cos(z*y*x*y))",
          "B=0DOTSYMBOL02*abs(cos(-z*x*z*x*y*y))",
          "T=1"
        ],
        "Name": "Granit_1",
        "Noise": "NoiseP(x,y,z,10,7,12/100)"
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Vases_1 by Abderrahman Taha 19/09/2015"
        ],
        "Name": [
          "Vases_1"
        ],
        "Component": [
          "Vase1",
          "Vase2",
          "Vase3",
          "Vase4",
          "Vase5",
          "Vase6"
        ],
        "Const": [
          "cx=0DOTSYMBOL0001",
          "cy=0DOTSYMBOL0001",
          "cz=0DOTSYMBOL0001",
          "Thickness2=( 0DOTSYMBOL25)",
          "Thickness4=( 0DOTSYMBOL2)",
          "Thickness5=( 0DOTSYMBOL2)",
          "Thickness6=(1DOTSYMBOL2)",
          "Thickness7=(1DOTSYMBOL2)"
        ],
        "Funct": [
          "Torus=(sqrt(x*x+y*y)-3)^2+z*z-1",
          "Bottom=(x*x + y*y + z*z - 1)",
          "CarvinCondition=sin(atan2(sqrt(x*x+y*y),(-z+cx)))>1/1DOTSYMBOL1",
          "IsoExterior=x*x/3DOTSYMBOL+y*y/3DOTSYMBOL-abs(1DOTSYMBOL5*sin(2*z/pi+ 0DOTSYMBOL3)+1DOTSYMBOL8)",
          "DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
          "DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
          "DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
          "Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
          "Iso2=(IsoExterior(x+t*DFx2(x,y,z,t)*Thickness2/Rapport2(x,y,z,t),y+t*DFy2(x,y,z,t)*Thickness2/Rapport2(x,y,z,t),z+t*DFz2(x,y,z,t)*Thickness2/Rapport2(x,y,z,t),t))",
          "ThickIsoExterior=(Iso2(x,y,z,1)*Iso2(x,y,z,-1))",
          "Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
          "DFx=((Iso(x,y,z,t)-Iso(x+cx,y,z,t))/cx)",
          "DFy=((Iso(x,y,z,t)-Iso(x,y+cy,z,t))/cy)",
          "DFz=((Iso(x,y,z,t)-Iso(x,y,z+cz,t))/cz)",
          "Rapport=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
          "Iso4=(Iso(x+t*DFx(x,y,z,t)*Thickness4/Rapport(x,y,z,t),y+t*DFy(x,y,z,t)*Thickness4/Rapport(x,y,z,t),z+t*DFz(x,y,z,t)*Thickness4/Rapport(x,y,z,t),t))",
          "ThickIso2=(Iso4(x,y,z,-1)*Iso4(x,y,z,1))",
          "isoTransform_2=if(CarvinCondition(x,y,z,t)=0,ThickIsoExterior(x,y,z,t),1)",
          "isoTransform_3=if(CarvinCondition(x,y,z,t)&ThickIsoExterior(x,y,z,t)<0,ThickIso2(5*x,5*y,5*z,t),1)",
          "Iso6=(Iso(x+t*DFx(x,y,z,t)*Thickness6/Rapport(x,y,z,t),y+t*DFy(x,y,z,t)*Thickness6/Rapport(x,y,z,t),z+t*DFz(x,y,z,t)*Thickness6/Rapport(x,y,z,t),t))",
          "isoTransform_4=if(CarvinCondition(x,y,z,t)&ThickIsoExterior(x,y,z,t)<0,Iso6(x*5,y*5,z*5,-1),1)",
          "isoTransform_5=if(CarvinCondition(x,y,z,t)&ThickIsoExterior(x,y,z,t)<0,-Iso6(x*5,y*5,z*5,1),1)"
        ],
        "Fxyz": [
          "isoTransform_2(x,y,-z,t)",
          "isoTransform_3(x,y,-z,t)",
          "isoTransform_4(x,y,-z,t)",
          "isoTransform_5(x,y,-z,t)",
          "Torus(1DOTSYMBOL7*x,1DOTSYMBOL7*y,2DOTSYMBOL2*(z+cos(pi/4*sqrt(x*x+y*y)))-10DOTSYMBOL6,t)",
          "Bottom(x/2DOTSYMBOL4,y/2DOTSYMBOL4,2*(z+5DOTSYMBOL1),t)"
        ],
        "Xmax": [
          "5",
          "3DOTSYMBOL5",
          "3DOTSYMBOL5",
          "3DOTSYMBOL5",
          "3",
          "3"
        ],
        "Xmin": [
          "-5",
          "-3DOTSYMBOL5",
          "-3DOTSYMBOL5",
          "-3DOTSYMBOL5",
          "-3",
          "-3"
        ],
        "Ymax": [
          "5",
          "3DOTSYMBOL5",
          "3DOTSYMBOL5",
          "3DOTSYMBOL5",
          "3",
          "3"
        ],
        "Ymin": [
          "-5",
          "-3DOTSYMBOL5",
          "-3DOTSYMBOL5",
          "-3DOTSYMBOL5",
          "-3",
          "-3"
        ],
        "Zmax": [
          "4DOTSYMBOL5",
          "2",
          "2",
          "2",
          "7",
          "-2"
        ],
        "Zmin": [
          "-5",
          "-2",
          "-2",
          "-2",
          "0",
          "-7"
        ]
      }
    },
    {
      "Param3D": {
        "Description": [
          "SeaShells_1 by Abderrahman Taha 12/09/2015"
        ],
        "Name": [
          "SeaShells"
        ],
        "Component": [
          "SeaShells"
        ],
        "Const": [
          "a = 40",
          "b = 14",
          "D = 1",
          "A = 50",
          "Mu = 10*3DOTSYMBOL14/180",
          "Alfa = 84*3DOTSYMBOL14/180",
          "Beta = -19*3DOTSYMBOL14/180",
          "Omega = -2*3DOTSYMBOL14/180",
          "Phi = 45*3DOTSYMBOL14/180",
          "L = 8",
          "P = 0",
          "W1 = 6*3DOTSYMBOL14/180",
          "W2 = 27*3DOTSYMBOL14/180",
          "N = 8"
        ],
        "Funct": [
          "Re=(1/sqrt((cos(u)/a)^2 + (sin(u)/b)^2) + if(W1=0|W2=0|N=0,0, L*exp(-(2*(u-P)/W1)^2-(2*(2*3DOTSYMBOL14*(N*v/(2*3DOTSYMBOL14) -floor(N*v/(2*3DOTSYMBOL14))))/W2)^2)) )"
        ],
        "Fx": [
          "D*(A*sin(Beta)*cos(u) + Re(v,u,t)*(cos(v+Phi)*cos(u+Omega) - sin(Mu)*sin(v+Phi)*sin(u+Omega)))*exp(u*cot(Alfa))"
        ],
        "Fy": [
          "(-A*sin(Beta)*sin(u) - Re(v,u,t)*(cos(v+Phi)*sin(u+Omega) + sin(Mu)*sin(v+Phi)*cos(u+Omega)))*exp(u*cot(Alfa))"
        ],
        "Fz": [
          "(-A*cos(Beta) + Re(v,u,t)*sin(v+Phi)*cos(Mu))*exp(u*cot(Alfa))"
        ],
        "Umax": [
          "4*pi"
        ],
        "Umin": [
          "-4*pi"
        ],
        "Vmax": [
          "2*pi"
        ],
        "Vmin": [
          "0"
        ]
      }
    },
    {
      "Iso3D": {
        "Description": [
          "Pseudo Duplin_2 by Abderrahman Taha 30/03/2017"
        ],
        "Name": [
          "Pseudo Duplin_2"
        ],
        "Component": [
          "PseudoDuplin"
        ],
        "Const": [
          "Th1= 0DOTSYMBOL9",
          "Th2= 0DOTSYMBOL4"
        ],
        "Funct": [
          "Iso=cos(x)+cos(y)+cos(z)",
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
          "isoCondition=(-51DOTSYMBOL11)*(x^4+y^4+z^4)-99DOTSYMBOL92*(x^2*y^2+x^2*z^2+y^2*z^2)+141DOTSYMBOL12*(x-1)*(x^2+y^2+z^2)+256*x*(x-2)+282DOTSYMBOL24*y^2+270",
          "isoTransform_2=if(isoCondition(x/4,y/4,z/4,t)>0,ThickIso2(4*x,2*y,2*z,t),1)+0DOTSYMBOL05*exp((ThickIso2(4*x,2*y,2*z,t)+isoCondition(x/4,y/4,z/4,t))/300)",
          "isoTransform_6=isoTransform_2(x,y*cos( 0DOTSYMBOL4944*(x))-z*sin( 0DOTSYMBOL4944*(x)),y*sin( 0DOTSYMBOL4944*(x))+z*cos( 0DOTSYMBOL4944*(x)),t)"
        ],
        "Fxyz": [
          "-isoTransform_6(x/2,y,z,t)"
        ],
        "Xmax": [
          "18"
        ],
        "Xmin": [
          "-16"
        ],
        "Ymax": [
          "8"
        ],
        "Ymin": [
          "-8"
        ],
        "Zmax": [
          "8"
        ],
        "Zmin": [
          "-8"
        ]
      }
    }
  ]
}
