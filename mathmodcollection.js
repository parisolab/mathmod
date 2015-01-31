{
	"MathModels": [{
		"Iso3D": {
			"Description": ["This example shows the minimum required fields "],
			"Name": ["Schwarz"],
			"Component": ["Schwarz"],
			"Fxyz": [" cos(x) + cos(y) + cos(z)"],
			"Cnd": ["(x^2 + y^2) > cos(t*pi)*5.0"],
			"Xmin": ["-4"],
			"Xmax": [" 4"],
			"Ymin": ["-4"],
			"Ymax": [" 4"],
			"Zmin": ["-4"],
			"Zmax": [" 4"]
		}
	},
	{
		"Texture": {
			"Colors": [
				"R=.82",
				"G=1.62*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
				"B=1.72*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
				"T=1"
			],
			"Name": "Granit_4"
		},
		"Noise": "True",
		"Iso3D": {
			"Component": [" SchwarzFunction"],
			"Const": ["r = (1/4)*(1+3*sqrt(5))",
			"a = -(8/5)*(1+1/(sqrt(5)))*sqrt(5-sqrt(5))",
			"c = (1/2)*sqrt(5-sqrt(5))"],
			"Funct": [" Schwarz1=cos(x) + cos(y) + cos(z)",
			" Schwarz2=cos(x) + cos(y)",
			" Schwarz3 = cos(x)"],
			"Fxyz": [" Schwarz1(x,y,z,t)"],
			"Name": ["SchwarzFunction"],
			"Varu": [" A=(u-4*sin(tm*pi/10))^2",
			" B=(u-2*cos(tm*pi/10))^2",
			"C=(u-2*sin(tm*pi)-4*sin(tm*pi/10))^2",
			" D=(u-2*cos(tm*pi)-2*cos(tm*pi/10))^2"],
			"Xmax": [" 4"],
			"Xmin": ["-4"],
			"Ymax": [" 4"],
			"Ymin": ["-4"],
			"Zmax": [" 4"],
			"Zmin": ["-4"]
		}
	},
	{
		"Texture": {
			"Name": "Lines4",
			"Colors": ["R=cos(x*pi)",
			"G=sin(y*pi)",
			"B=cos(z*pi)",
			"T=1"]
		},
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Moon"],
			"Component": ["GravityPlan",
			"EarthPlanet",
			"MoonPlanet"],
			"Fxyz": ["((x-4*sin(t*pi/3))*(x-4*sin(t*pi/3)) + (y-2*cos(t*pi/3))*(y-2*cos(t*pi/3)) + z*z - .6)
		*min( (x-4*sin(t*pi/3))*(x-4*sin(t*pi/3)) + (y-2*cos(t*pi/3))*(y-2*cos(t*pi/3))  + z*z - .6, z) +0.2",
			"
		(x-4*sin(t*pi/3))*(x-4*sin(t*pi/3)) + (y-2*cos(t*pi/3))*(y-2*cos(t*pi/3))  + (z-.2)*(z-.2) - .6 ",
			"
		(x-2*sin(t*pi)-4*sin(t*pi/3))*(x-2*sin(t*pi)-4*sin(t*pi/3)) + (y-2*cos(t*pi)-2*cos(t*pi/3))*(y-2*cos(t*pi)-2*cos(t*pi/3)) + (z-.2)*(z-.2) - .1
		"],
			"Xmin": ["-5",
			"-1+4*sin(t*pi/3)",
			"-1+2*sin(t*pi)+4*sin(t*pi/3)"],
			"Xmax": [" 5",
			"1+4*sin(t*pi/3)",
			"1+2*sin(t*pi)+4*sin(t*pi/3)"],
			"Ymin": ["-4",
			"-1+2*cos(t*pi/3)",
			"-1+2*cos(t*pi)+2*cos(t*pi/3)"],
			"Ymax": [" 4",
			"1+2*cos(t*pi/3)",
			"1+2*cos(t*pi)+2*cos(t*pi/3)"],
			"Zmin": ["-1",
			"-1",
			"-1"],
			"Zmax": [" 1",
			"1.5",
			"1"]
		}
	},
	{
		"Texture": {
			"Colors": ["R=cos((x*x +y*y +z*z)*pi)",
			"G=cos((x*x +y*y +z*z)*pi)*cos(x*pi)",
			"B=sin(y*pi)*cos(x*pi)",
			"T=1"],
			"Name": "Lines6"
		},
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Moon2"],
			"Component": ["GravityPlan",
			"EarthPlanet",
			"MoonPlanet"],
			"Varu": [" A=(u-4*sin(tm*pi/10))^2",
			" B=(u-2*cos(tm*pi/10))^2",
			"C=(u-2*sin(tm*pi)-4*sin(tm*pi/10))^2",
			" D=(u-2*cos(tm*pi)-2*cos(tm*pi/10))^2"],
			"Fxyz": ["(Ax + By+ z*z - .6)
		*min( Ax + By  + z*z - .6, z) +0.2",
			"
		Ax+ By + (z-.2)*(z-.2) - .6 ",
			"
		Cx + Dy  + (z-.2)*(z-.2) - .1
		"],
			"Xmin": ["-5",
			"-1+4*sin(t*pi/10)",
			"-1+2*sin(t*pi)+4*sin(t*pi/10)"],
			"Xmax": [" 5",
			"1+4*sin(t*pi/10)",
			"1+2*sin(t*pi)+4*sin(t*pi/10)"],
			"Ymin": ["-4",
			"-1+2*cos(t*pi/10)",
			"-1+2*cos(t*pi)+2*cos(t*pi/10)"],
			"Ymax": [" 4",
			"1+2*cos(t*pi/10)",
			"1+2*cos(t*pi)+2*cos(t*pi/10)"],
			"Zmin": ["-1",
			"-1",
			"-1"],
			"Zmax": [" 1",
			"1.10",
			"1"]
		}
	},
	{
		"Iso3D": {
			"Component": ["GravityPlan",
			"EarthPlanet",
			"MoonPlanet"],
			"Fxyz": ["((x-4*sin((0.521*t)*pi/3.11))^2 + (y-2*cos((0.521*t)*pi/3.11))^2+ z*z - .6)*min( (x-4*sin((0.521*t)*pi/3.11))^2+ (y-2*cos((0.521*t)*pi/3.11))^2 + z*z - .6, z) +0.2",
			"(x-4*sin((0.521*t)*pi/3.11))^2+ (y-2*cos((0.521*t)*pi/3.11))^2  + (z-.2)*(z-.2) - .6 ",
			"(x-2*sin((0.521*t)*pi)-4*sin((0.521*t)*pi/3.11))^2 + (y-2*cos((0.521*t)*pi)-2*cos((0.521*t)*pi/3.11))^2 + (z-.2)*(z-.2) - .05"],
			"Name": ["Moon3"],
			"Xmax": [" 5",
			"1+4*sin((0.521*t)*pi/3.11)",
			"1+2*sin((0.521*t)*pi)+4*sin((0.521*t)*pi/3.11)"],
			"Xmin": ["-5",
			"-1+4*sin((0.521*t)*pi/3.11)",
			"-1+2*sin((0.521*t)*pi)+4*sin((0.521*t)*pi/3.11)"],
			"Ymax": [" 4",
			"1+2*cos((0.521*t)*pi/3.11)",
			"1+2*cos((0.521*t)*pi)+2*cos((0.521*t)*pi/3.11)"],
			"Ymin": ["-4",
			"-1+2*cos((0.521*t)*pi/3.11)",
			"-1+2*cos((0.521*t)*pi)+2*cos((0.521*t)*pi/3.11)"],
			"Zmax": [" 1",
			"1.5",
			"1"],
			"Zmin": ["-1",
			"-1",
			"-1"]
		}
	},
	{
		"Texture": {
			"Name": "Lines4",
			"Colors": ["R=cos(7*x*y*pi)",
			"G=sin(7*y*z*pi)",
			"B=sin(7*z*x*pi)",
			"T=1"]
		},
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["BlackHole"],
			"Component": [" GravityPlan",
			" EarthPlanet",
			" MoonPlanet",
			" WhiteStar "],
			"Varu": ["
		A=(u-4*sin(tm*pi/10))^2",
			"
		B=(u-2*cos(tm*pi/10))^2",
			"
		C=(u-2*sin(tm*pi)-4*sin(tm*pi/10))^2",
			"
		D=(u-2*cos(tm*pi)-2*cos(tm*pi/10))^2",
			"
		E=(u-.2)*(u-.2) - .6 ",
			"
		F =u*u - .6",
			"
		H=u*cos(2*tm*pi)",
			"
		G=u*sin(2*tm*pi)
		"],
			"Grid": [" 20",
			"20",
			"20",
			"20"],
			"Fxyz": ["
		(1.5*(Hx-Gy)^2 + (Gx+ Hy)^2 +(z+.8)^2 -(abs(2.2*sin(t*pi/10))))*(Ax + By+ Fz)*min( (1.5*(Hx-Gy)^2 + (Gx+ Hy)^2 +(z+.8)^2 -(abs(2.2*sin(t*pi/10))))*(Ax + By + Fz), z) +1.",
			"
		Ax+ By + Ez",
			"
		Cx + Dy  + Ez + .5",
			"
		1.5*(x*cos(2*t*pi) -y*sin(2*t*pi))^2 + (x*sin(2*t*pi) + y*cos(2*t*pi))^2 +(z+.2)^2 -(abs(.2*sin(t*pi/10)+.05))
		"],
			"Xmin": ["
		-5",
			"-1+4*sin(t*pi/10)",
			"-1+2*sin(t*pi)+4*sin(t*pi/10)",
			" -.5"],
			"Xmax": ["
		5",
			"1+4*sin(t*pi/10)",
			"1+2*sin(t*pi)+4*sin(t*pi/10)",
			" .5
		"],
			"Ymin": ["
		-4",
			"-1+2*cos(t*pi/10)",
			"-1+2*cos(t*pi)+2*cos(t*pi/10)",
			" -.5"],
			"Ymax": ["
		4",
			"1+2*cos(t*pi/10)",
			"1+2*cos(t*pi)+2*cos(t*pi/10)",
			" .5
		"],
			"Zmin": ["
		-2",
			"-1",
			"-1",
			" -.7"],
			"Zmax": ["
		1",
			"1.10",
			"1",
			".5
		"]
		}
	},
	{
		"Iso3D": {
			"Component": ["fallingdrop"],
			"Fxyz": ["-((z-6*(1-cos(sqrt(x^2+y^2)-t*2*pi))/sqrt(x^2+y^2+4))*(2*(x^2+y^2)+(z-40*sin((t+0.19)*pi)+1)^2-10)-1000)"],
			"Name": ["FallingDrop"],
			"Xmax": ["20"],
			"Xmin": ["-20"],
			"Ymax": ["20"],
			"Ymin": ["-20"],
			"Zmax": ["50"],
			"Zmin": ["-1"]
		},
		"Pigment": {
			"Colors": [{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=.20",
					"R=.90",
					"G=.9",
					"B=.40",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0.3",
					"R=1",
					"G=.1",
					"B=.31",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0.6",
					"R=1",
					"G=.7",
					"B=1",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0.6",
					"R=1",
					"G=0.3",
					"B=.1",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0.8",
					"R=.15",
					"G=.6",
					"B=.1",
					"A=1"]
				}
			}],
			"Gradient": "3*cos((x*x +y*y)*pi)*cos(x*y*pi)*cos((x*y +z*z)*pi)*cos(z*y*pi)"
		}
	},
	{
		"Iso3D": {
			"Name": ["MengerSponge"],
			"Component": ["MengerSponge"],
			"Varu": [" 
		A = ((abs(u-2/3) <1/81)+ (abs(u-20/27) <1/81)+ (abs(u-16/27) <1/81)+
		(abs(u-8/9) <1/81) + (abs(u-26/27) <1/81) + (abs(u-22/27) <1/81) +
		(abs(u-4/9) <1/81) +(abs(u-14/27) <1/81) +(abs(u-10/27) <1/81) +
		(abs(u+2/3) <1/81) +(abs(u+16/27) <1/81) +(abs(u+20/27) <1/81) +
		(abs(u+4/9) <1/81) +(abs(u+10/27) <1/81) +(abs(u+14/27) <1/81) +
		(abs(u+8/9) <1/81) +(abs(u+22/27) <1/81) +(abs(u+26/27) <1/81) +
		(abs(u) <1/81) + (abs(u-2/27) <1/81) +(abs(u+2/27) <1/81) +
		(abs(u-2/9) <1/81) + (abs(u-8/27) <1/81) + (abs(u-4/27) <1/81) +
		(abs(u+2/9) <1/81)+(abs(u+4/27) <1/81)+(abs(u+8/27) <1/81))",
			" 
		B = ((abs(u-2/3) <1/27)+(abs(u-8/9) <1/27) + (abs(u-4/9) <1/27) 
		+(abs(u+2/3) <1/27) +(abs(u+4/9) <1/27) + (abs(u+8/9) <1/27) +
		(abs(u) <1/27) + (abs(u-2/9) <1/27) + (abs(u+2/9) <1/27))",
			"
		C = ((abs(u-2/3) <1/9) + (abs(u+2/3) <1/9) + (abs(u) <1/9))",
			"
		D = u^100
		"],
			"Fxyz": [" 
		-(Dx + Dy + Dz -1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*
		( (Cx*(Cy+Cz) + Cz*Cy) =0)*
		( (Bx*(By+Bz) + Bz*By) =0)*
		( (Ax*(Ay+Az) + Az*Ay) =0) ) 
		"],
			"Xmin": ["-1.001"],
			"Xmax": [" 1.001"],
			"Ymin": ["-1.001"],
			"Ymax": [" 1.001"],
			"Zmin": ["-1.001"],
			"Zmax": [" 1.001"]
		}
	},
	{
		"Iso3D": {
			"Name": ["MengerSpongeSubdivision"],
			"Varu": [" 
		A = ((abs(u-2/3) <1/81)+ (abs(u-20/27) <1/81)+ (abs(u-16/27) <1/81)+
		(abs(u-8/9) <1/81) + (abs(u-26/27) <1/81) + (abs(u-22/27) <1/81) +
		(abs(u-4/9) <1/81) +(abs(u-14/27) <1/81) +(abs(u-10/27) <1/81) +
		(abs(u+2/3) <1/81) +(abs(u+16/27) <1/81) +(abs(u+20/27) <1/81) +
		(abs(u+4/9) <1/81) +(abs(u+10/27) <1/81) +(abs(u+14/27) <1/81) +
		(abs(u+8/9) <1/81) +(abs(u+22/27) <1/81) +(abs(u+26/27) <1/81) +
		(abs(u) <1/81) + (abs(u-2/27) <1/81) +(abs(u+2/27) <1/81) +
		(abs(u-2/9) <1/81) + (abs(u-8/27) <1/81) + (abs(u-4/27) <1/81) +
		(abs(u+2/9) <1/81)+(abs(u+4/27) <1/81)+(abs(u+8/27) <1/81))",
			" 
		B = ((abs(u-2/3) <1/27)+(abs(u-8/9) <1/27) + (abs(u-4/9) <1/27) 
		+(abs(u+2/3) <1/27) +(abs(u+4/9) <1/27) + (abs(u+8/9) <1/27) +
		(abs(u) <1/27) + (abs(u-2/9) <1/27) + (abs(u+2/9) <1/27))",
			"
		C = ((abs(u-2/3) <1/9) + (abs(u+2/3) <1/9) + (abs(u) <1/9))",
			"
		D = u^100
		"],
			"Component": [" MengerSponge1",
			" MengerSponge2",
			" MengerSponge3",
			" MengerSponge4",
			" MengerSponge5",
			" MengerSponge6",
			" MengerSponge7",
			" MengerSponge8"],
			"Fxyz": [" 
		-(Dx + Dy + Dz -1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*
		( (Cx*(Cy+Cz) + Cz*Cy) =0)*
		( (Bx*(By+Bz) + Bz*By) =0)*
		( (Ax*(Ay+Az) + Az*Ay) =0) ) ",
			"
		-(Dx + Dy + Dz -1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*
		( (Cx*(Cy+Cz) + Cz*Cy) =0)*
		( (Bx*(By+Bz) + Bz*By) =0)*
		( (Ax*(Ay+Az) + Az*Ay) =0) ) ",
			"
		-(Dx + Dy + Dz -1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*
		( (Cx*(Cy+Cz) + Cz*Cy) =0)*
		( (Bx*(By+Bz) + Bz*By) =0)*
		( (Ax*(Ay+Az) + Az*Ay) =0) ) ",
			"
		-(Dx + Dy + Dz -1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*
		( (Cx*(Cy+Cz) + Cz*Cy) =0)*
		( (Bx*(By+Bz) + Bz*By) =0)*
		( (Ax*(Ay+Az) + Az*Ay) =0) )",
			"
		-(Dx + Dy + Dz -1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*
		( (Cx*(Cy+Cz) + Cz*Cy) =0)*
		( (Bx*(By+Bz) + Bz*By) =0)*
		( (Ax*(Ay+Az) + Az*Ay) =0) ) ",
			"
		-(Dx + Dy + Dz -1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*
		( (Cx*(Cy+Cz) + Cz*Cy) =0)*
		( (Bx*(By+Bz) + Bz*By) =0)*
		( (Ax*(Ay+Az) + Az*Ay) =0) ) ",
			"
		-(Dx + Dy + Dz -1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*
		( (Cx*(Cy+Cz) + Cz*Cy) =0)*
		( (Bx*(By+Bz) + Bz*By) =0)*
		( (Ax*(Ay+Az) + Az*Ay) =0) ) ",
			"
		-(Dx + Dy + Dz -1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*
		( (Cx*(Cy+Cz) + Cz*Cy) =0)*
		( (Bx*(By+Bz) + Bz*By) =0)*
		( (Ax*(Ay+Az) + Az*Ay) =0) )
		"],
			"Xmin": ["-1.001",
			" -1.001 ",
			" -1.001",
			"   -1.001",
			"  0.000",
			"  0.000",
			"  0.000",
			"  0.000"],
			"Xmax": ["   0.000 ",
			"   0.000",
			"  0.000",
			" 0.000",
			" 1.001",
			" 1.001",
			" 1.001",
			" 1.001"],
			"Ymin": ["-1.001",
			" -1.001",
			"  0.000",
			"  0.000",
			" -1.001",
			" -1.001",
			"  0.000",
			"  0.000 "],
			"Ymax": ["  0.000 ",
			"  0.000",
			" 1.001",
			" 1.001",
			"  0.000 ",
			"  0.000",
			" 1.001",
			" 1.001"],
			"Zmin": ["-1.001",
			" 0.000 ",
			" -1.001",
			"  0.000",
			" -1.001",
			" 0.000 ",
			" -1.001",
			"  0.000 "],
			"Zmax": ["   0.000 ",
			" 1.001",
			"  0.000",
			" 1.001",
			" 0.000 ",
			" 1.001",
			"  0.000",
			" 1.001"]
		}
	},
	{
		"Iso3D": {
			"Component": ["Ball",
			"Plan"],
			"Fxyz": ["(x-4*sin((0.521*t)*pi/3.11))^2+(y-2*cos((0.521*t)*pi/3.11))^2+(z-3*abs(cos((5*t)*pi/3.11)))^2-.6",
			"z+.6"],
			"Grid": ["20",
			"20"],
			"Name": ["BouncingBall"],
			"Xmax": ["1+4*sin((0.521*t)*pi/3.11)",
			"4"],
			"Xmin": ["-1+4*sin((0.521*t)*pi/3.11)",
			"-4"],
			"Ymax": ["1+2*cos((0.521*t)*pi/3.11)",
			"4"],
			"Ymin": ["-1+2*cos((0.521*t)*pi/3.11)",
			"-4"],
			"Zmax": ["6",
			".1"],
			"Zmin": ["-1",
			"-1.1"]
		}
	},
	{
		"Iso3D": {
			"Description ": [""],
			"Name": ["Cayley_1"],
			"Component": ["Cayley_1"],
			"Fxyz": ["(x^2 + y ^2 - x^2 *z + y ^2 *z + z ^2 -1)"],
			"Cnd": ["   (sqrt(x^2  + y ^2 + z ^2)) < 4"],
			"Xmin": ["-4 "],
			"Xmax": [" 4"],
			"Ymin": ["-4 "],
			"Ymax": [" 4"],
			"Zmin": ["-4 "],
			"Zmax": [" 4"]
		}
	},
	{
		"Iso3D": {
			"Description ": [""],
			"Name": ["Cayley_2"],
			"Component": ["Cayley_2"],
			"Fxyz": ["-5*(x*x*y + x*x*z + y*y*x + y*y*z + z*z*y + z*z*x)   +2*(x*y + x*z + y*z)"],
			"Cnd": ["   (sqrt(x^2  + y ^2 + z ^2)) < 1"],
			"Xmin": ["-1 "],
			"Xmax": [" 1"],
			"Ymin": ["-1 "],
			"Ymax": [" 1"],
			"Zmin": ["-1 "],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Nordstrand"],
			"Cnd": ["((x-.1)^2+(y-.1)^2+(z-.1)^2)>1"],
			"Component": [" Nordstrand"],
			"Fxyz": ["  25*(x^3*(y+z)+y^3*(x+z)+z^3*(x+y))+50*(x^2*y^2+x^2*z^2+y^2*z^2)-125*(x^2*y*z+y^2*x*z+z^2*x*y)+60*x*y*z-4*(x*y+x*z+y*z)"],
			"Xmax": [" 1.1"],
			"Xmin": ["-1.1"],
			"Ymax": [" 1.1"],
			"Ymin": ["-1.1"],
			"Zmax": [" 1.1"],
			"Zmin": ["-1.1"]
		}
	},
	{
		"Iso3D": {
			"Cnd": ["(x^2 + y^2 + z^2) > 100"],
			"Component": ["Togliatti"],
			"Const": [" w=1.3"],
			"Fxyz": ["64*(x -w)*(x^4 - 4*w*x^3 -10*x^2*y^2 - 4*x^2*w^2 + 16*w^3*x - 20*w*x*y^2 + 5*y^4 + 16*w^4 - 20*y^2*w^2) -5*sqrt(5 - sqrt(5))*(2*z - sqrt(5 - sqrt(5))*w)*(4*(x^2 + y^2 - z^2) + (1 + 3*sqrt(5))*w^2)^2"],
			"Name": ["Togliatti"],
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
			"Cnd": ["(x^2+y^2+z^2)>15"],
			"Const": ["r = (1/4)*(1+3*sqrt(5))",
			"a = -(8/5)*(1+1/(sqrt(5)))*sqrt(5-sqrt(5))",
			"c = (1/2)*sqrt(5-sqrt(5))"],
			"Component": [" Dervish"],
			"Fxyz": [" a*(x-z)*(cos((2*pi)/5)*x-sin((2*pi)/5)*y-z) *(cos((4*pi)/5)*x-sin((4*pi)/5)*y-z) *(cos((6*pi)/5)*x-sin((6*pi)/5)*y-z) *(cos((8*pi)/5)*x-sin((8*pi)/5)*y-z)  + (1-c*z)*(x^2+y^2-1+r*z^2)^2"],
			"Xmin": ["-4"],
			"Xmax": [" 4"],
			"Ymin": ["-4"],
			"Ymax": [" 4"],
			"Zmin": ["-4"],
			"Zmax": [" 4"]
		}
	},
	{
		"Iso3D": {
			"Cnd": ["(x^2+y^2+z^2)>9"],
			"Component": ["Barth-sextic"],
			"Const": [" w=1.0",
			" phi=(1/2)*(1+sqrt(5))"],
			"Fxyz": ["4*(phi^2*x^2-y^2)*(phi^2*y^2-z^2)*(phi^2*z^2-x^2)-(1+2*phi)*(x^2+y^2+z^2-w^2)^2*w^2"],
			"Name": ["Barth-sextic"],
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
			"Cnd": ["(x^2+y^2+z^2)>25"],
			"Component": ["Labs-Septic"],
			"Const": [" w = 1.0",
			"a1 = -(12/7)*(-0.14010685)^2 -(384/49)*(-0.14010685) -(8/7)",
			"a2 = -(32/7)*(-0.14010685)^2 +(24/49)*(-0.14010685)  -4",
			"a3 = -4*(-0.14010685)^2 +(24/49)*(-0.14010685)  -4",
			"a4 = -(8/7)*(-0.14010685)^2 +(8/49)*(-0.14010685)  -8/7",
			"a5 = 49*(-0.14010685)^2 -7*(-0.14010685)  +50"],
			"Fxyz": ["(x*(x^6-3*7*x^4*y^2+5*7*x^2*y^4-7*y^6)+7*z*((x^2+y^2)^3-2^3*z^2*(x^2+y^2)^2+2^4*z^4*(x^2+y^2))-2^6*z^7)-((z+a5*w)*((z+w)*(x^2+y^2)+a1*z^3+a2*z^2*w+a3*z*w^2+a4*w^3)^2)"],
			"Name": ["Labs-Septic"],
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
			"Cnd": ["(x^2+y^2+z^2)>25"],
			"Component": ["Endraß-Octic"],
			"Const": [" w = 1.0",
			"a1 = 1.0",
			"a2 = 1.0",
			"a3 = 1.0",
			"a4 = -1.0"],
			"Fxyz": ["64 * (x^2 - w^2)*(y^2 - w^2)*((x + y)^2 -2*w^2)*((x - y)^2 -2*w^2)  - (-4*(1 + a1*2^(1/2))*(x^2 + y^2)^2 + 
			 (8*(2 + a2*2^(1/2))*z^2 + 2*(2 + a3*7*2^(1/2))*w^2 )* (x^2 + y^2) - 
			 16*z^4+ 8*(1 + a4*2*2^(1/2))*z^2*w^2 - (1 + 12*2^(1/2))*w^4)^2"],
			"Name": ["Endraß-Octic"],
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
			"Component": [" SartiOctic"],
			"Fxyz": ["-1728*x^4*y^2*z^2+928.0*z^4*x^4+9024.0*z^2*x^4+928.0*z^4*y^4+9024.0*z^2*y^4+9024.0*x^2*y^2+2720.0*x^4*y^4-1728*x^2*z^2-1728*y^2*z^2-1728*x^4*y^2-1728*x^2*y^4-1728*x^2*z^4-1728*y^2*z^4-576*x^6*y^2-576*x^6*z^2-576*x^2*y^6-576*x^2*z^6-576*y^6*z^2+9024.0*z^4*x^2*y^2-24960.0*z^2*x^2*y^2-1728*x^2*y^4*z^2+2720.0*z^4+112.0*z^8-576*z^2+928.0*x^4+112.0*x^8+928.0*y^4+112.0*y^8-576*x^2-576*y^2-576*x^6-576*y^6-576*z^6+112.0-576*y^2*z^6"],
			"Name": ["SartiOctic"],
			"Xmax": ["5.6"],
			"Xmin": ["-5.6"],
			"Ymax": ["5.6"],
			"Ymin": ["-5.6"],
			"Zmax": ["5.6"],
			"Zmin": ["-5.6"]
		}
	},
	{
		"Iso3D": {
			"Cnd": ["(x^2+y^2+z^2)>9"],
			"Component": ["Breske-Nonic"],
			"Fxyz": ["(2*x^7-42*x^5*y^2+70*x^3*y^4-14*x*y^6-14*x^6+70*x^4*y^2+70*x^2*y^4-14*y^6+28*x^5+56*x^3*y^2+28*x*y^4-84*x^2*y^2+28*y^4-42*x^3-42*x*y^2+14*x^2-14*y^2+14*x) + 
				0.5* (64*z^7-112*z^5+56*z^3-7*z+5)"],
			"Name": ["Breske-Nonic"],
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
			"Cnd": ["(x^2+y^2+z^2)> (1+sqrt(5))+0.2"],
			"Component": ["Barth-Dedic"],
			"Const": [" w  = 1.0",
			" phi= (1+sqrt(5))/2"],
			"Fxyz": ["8*(Ax-phi^4*Ay)*(Ay-phi^4*Az)*(Az-phi^4*Ax)*(Bx+By+Bz-2*(Ax*Ay+Ax*Az+Ay*Az)) + (3+5*phi)*(Ax+Ay+Az-w^2)^2 * (Ax+Ay+Az- (2-phi)*w^2)^2 * w^2"],
			"Name": ["Barth-Dedic"],
			"Varu": [" A  = u^2",
			" B  = u^4"],
			"Xmax": ["sqrt(1+sqrt(5))"],
			"Xmin": ["-sqrt(1+sqrt(5))"],
			"Ymax": ["sqrt(1+sqrt(5))"],
			"Ymin": ["-sqrt(1+sqrt(5))"],
			"Zmax": ["sqrt(1+sqrt(5))"],
			"Zmin": ["-sqrt(1+sqrt(5))"]
		}
	},
	{
		"Iso3D": {
			"Cnd": ["(x^2+y^2+z^2)>13"],
			"Component": ["Sarti-Dodecic"],
			"Const": [" w  = 1.0"],
			"Fxyz": ["243*(33*sqrt(5)*(((Ax*Ay+Az*w^2)^2*(Ax*Az+Ay*w^2)-(Ax*Ay+Az*w^2)*(Ax*Az+Ay*w^2)^2)+((Ax*Az+Ay*w^2)^2*(Ax*w^2+Ay*Az)-(Ax*Az+Ay*w^2)*(Ax*w^2+Ay*Az)^2)+((Ax*w^2+Ay*Az)^2*(Ax*Ay+Az*w^2)-(Ax*w^2+Ay*Az)*(Ax*Ay+Az*w^2)^2))+19*(((Ax*Ay+Az*w^2)^2*(Ax*Az+Ay*w^2)+(Ax*Ay+Az*w^2)*(Ax*Az+Ay*w^2)^2)+((Ax*Az+Ay*w^2)^2*(Ax*w^2+Ay*Az)+(Ax*Az+Ay*w^2)*(Ax*w^2+Ay*Az)^2)+((Ax*w^2+Ay*Az)^2*(Ax*Ay+Az*w^2)+(Ax*w^2+Ay*Az)*(Ax*Ay+Az*w^2)^2))+10*((Ax*Ay+Az*w^2)^3+(Ax*Az+Ay*w^2)^3+(Ax*w^2+Ay*Az)^3)-14*(Bx+By+Bz+w^4)*((Ax*Ay+Az*w^2)*(Ax*Az+Ay*w^2)+(Ax*Ay+Az*w^2)*(Ax*w^2+Ay*Az)+(Ax*Az+Ay*w^2)*(Ax*w^2+Ay*Az))+2*(Bx+By+Bz+w^4)^2*((Ax*Ay+Az*w^2)+(Ax*Az+Ay*w^2)+(Ax*w^2+Ay*Az))-6*(Bx+By+Bz+w^4)*((Ax*Ay+Az*w^2)^2+(Ax*Az+Ay*w^2)^2+(Ax*w^2+Ay*Az)^2)-352*(x*y*z*w)^2*((Ax*Ay+Az*w^2)+(Ax*Az+Ay*w^2)+(Ax*w^2+Ay*Az))+336*(x*y*z*w)^2*(Bx+By+Bz+w^4)+48*((Ax*Ay+Az*w^2)*(Ax*Az+Ay*w^2)*(Ax*w^2+Ay*Az)))-22*(Ax+Ay+Az+w^2)^6"],
			"Name": ["SartiDodecic"],
			"Varu": [" A  = u^2",
			" B  = u^4"],
			"Xmax": ["3.7"],
			"Xmin": ["-3.7"],
			"Ymax": ["3.7"],
			"Ymin": ["-3.7"],
			"Zmax": ["3.7"],
			"Zmin": ["-3.7"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Scherk"],
			"Component": ["Scherk"],
			"Fxyz": ["sinh(x)*sinh(y) - sin(z)"],
			"Xmax": [" 3"],
			"Xmin": ["-3 "],
			"Ymax": [" 3"],
			"Ymin": ["-3 "],
			"Zmax": [" 5*pi/2"],
			"Zmin": ["-5*pi/2 "]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Blobs"],
			"Component": ["Blobs"],
			"Fxyz": ["x^2 + y ^2 + z^2 +cos(4*x)+cos(4*y)+cos(4*z)-0.2"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["CubeSphere"],
			"Component": ["CubeSphere"],
			"Fxyz": [" ((1/2.3)^2 *(x^2 + y^2 + z^2))^-6 + ( (1/2)^8 * (x^8 + y^8 + z^8) )^6 -1"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Hyperbolic"],
			"Component": ["Hyperbolic"],
			"Fxyz": ["x*x + y - z*z"],
			"Xmin": ["-1"],
			"Xmax": [" 1"],
			"Ymin": ["-1"],
			"Ymax": [" 1"],
			"Zmin": ["-1"],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Devil"],
			"Component": ["Devil Surface"],
			"Fxyz": ["x^4+2*x^2*z^2-0.36*x^2-y^4+0.25*y^2+z^4"],
			"Xmin": ["-1"],
			"Xmax": [" 1"],
			"Ymin": ["-1"],
			"Ymax": [" 1"],
			"Zmin": ["-1"],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Hyperboloid"],
			"Component": ["Hyperboloid"],
			"Fxyz": ["x^2 + y^2 - z^2 -0.3"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-1.8"],
			"Zmax": [" 1.8"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["DuplinCyclides"],
			"Component": ["DuplinCyclides"],
			"Fxyz": ["(2^2 - (2 + 2.1)^2) * (2^2 - (2 - 2.1)^2)*(x^4+y^4+z^4)+ 2*((2^2 - (2 + 2.1)^2 )*(2^2 - .1^2)* (x^2 * y^2+x^2 * z^2+y^2 * z^2))+2* 2^2 *((2.1^2)* (2 *x *2-2^2))*(x^2+y^2+z^2)+ 4 * 2^4 * (2 *x)* (-2^2+2 * x)+4* 2^4 * 2.1^2 * y^2+2^8"],
			"Xmin": ["-2"],
			"Xmax": [" 2.2"],
			"Ymin": ["-2.1"],
			"Ymax": [" 2.1"],
			"Zmin": ["-1.3"],
			"Zmax": [" 1.3"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Blobs_2"],
			"Component": ["Blobs_2"],
			"Fxyz": ["x^2 + y ^2 + z^2 +sin(4*x) + sin(4*y) + sin(4*z) -1"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["KleinIso"],
			"Component": ["KleinIso"],
			"Fxyz": ["(x^2+y^2+z^2+2*y-1)*((x^2+y^2+z^2-2*y-1)^2-8*z^2)+16*x*z*(x^2+y^2+z^2-2*y-1)"],
			"Xmin": ["-3"],
			"Xmax": [" 3"],
			"Ymin": ["-3.1"],
			"Ymax": [" 3.1"],
			"Zmin": ["-4"],
			"Zmax": [" 4"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Leminescape"],
			"Component": ["Leminescape"],
			"Fxyz": ["4*x^2*(x^2+y^2+z^2+z)+y^2*(y^2+z^2-1)"],
			"Xmin": ["-0.5"],
			"Xmax": [" 0.5"],
			"Ymin": ["-1"],
			"Ymax": [" 1"],
			"Zmin": ["-1"],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Drope"],
			"Component": ["Drope"],
			"Fxyz": ["z - 4*x*exp(-x^2-y^2)"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-1.7"],
			"Zmax": [" 1.7"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Sinus"],
			"Colors": ["R=cos(30*x*pi)",
			"G=cos(30*y*pi)",
			"B=cos(4*z*pi)",
			"T=1.0"],
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
			"Description": ["This is a Description"],
			"Name": ["TorusIso"],
			"Component": ["TorusIso"],
			"Fxyz": ["(sqrt(x*x+y*y)-3)^2 + z*z - 1"],
			"Xmin": ["-4"],
			"Xmax": [" 4"],
			"Ymin": ["-4"],
			"Ymax": [" 4"],
			"Zmin": ["-1"],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["SphereIso"],
			"Component": ["SphereIso"],
			"Fxyz": ["x*x + y*y + z*z - 1"],
			"Xmin": ["-1"],
			"Xmax": [" 1"],
			"Ymin": ["-1"],
			"Ymax": [" 1"],
			"Zmin": ["-1"],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Octahedron"],
			"Component": ["Octahedron"],
			"Fxyz": ["abs(x)+abs(y)+abs(z) - 1"],
			"Xmin": ["-1"],
			"Xmax": [" 1"],
			"Ymin": ["-1"],
			"Ymax": [" 1"],
			"Zmin": ["-1"],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["IsoCube"],
			"Component": ["IsoCube"],
			"Fxyz": ["x^100 + y^100 + z^100 -1"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["IsoToupie"],
			"Component": ["IsoToupie"],
			"Fxyz": ["(sqrt(x*x+y*y)-3)^3 + z*z - 1"],
			"Xmin": ["-4"],
			"Xmax": [" 4"],
			"Ymin": ["-4"],
			"Ymax": [" 4"],
			"Zmin": ["-6"],
			"Zmax": [" 6"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["RoundCube"],
			"Component": ["RoundCube"],
			"Fxyz": ["x^4 + y^4 + z^4 - (x^2 + y^2 + z^2)"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Chmutov"],
			"Component": ["Chmutov"],
			"Fxyz": ["(x^2)^2 + (y^2)^2 + (z^2)^2 - (x^2 + y^2 + z^2-0.3)"],
			"Xmin": ["-1.5"],
			"Xmax": [" 1.5"],
			"Ymin": ["-1.5"],
			"Ymax": [" 1.5"],
			"Zmin": ["-1.5"],
			"Zmax": [" 1.5"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Chmutov_2"],
			"Component": ["Chmutov_2"],
			"Fxyz": ["2*(x^2*(3-4*x^2)^2+y^2*(3-4*y^2)^2+z^2*(3-4*z^2)^2) -3"],
			"Xmin": ["-1.3"],
			"Xmax": [" 1.3"],
			"Ymin": ["-1.3"],
			"Ymax": [" 1.3"],
			"Zmin": ["-1.3"],
			"Zmax": [" 1.3"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Composite"],
			"Component": ["Chmutov",
			"RoundCube",
			"Virus",
			"Trap"],
			"Fxyz": ["2*(x^2*(3-4*x^2)^2+y^2*(3-4*y^2)^2+z^2*(3-4*z^2)^2) -3",
			"
		((x-3)^2)^2 + (y^2)^2 + (z^2)^2 - ((x-3)^2 + y^2 + z^2-0.3)",
			"
		-(-(x^2 + (y-3) ^2 + z^2) +cos(5*x)*cos(5*(y-3))*cos(5*z)+0.215)",
			"
		((x-3)^8 + z^30 + (y-3)^8 - ((x-3)^4 + z^50 + (y-3)^4 -0.3))*((x-3)^2 + (y-3)^2 + z^2 -0.5)
		"],
			"Xmin": ["-1.3",
			"1.5",
			"-.8",
			"1.8  "],
			"Xmax": [" 1.3",
			"4.5",
			".8",
			"4.2"],
			"Ymin": ["-1.3",
			"-1.5",
			"2.2",
			"1.8 "],
			"Ymax": [" 1.3",
			"1.5",
			"3.8",
			"4.3"],
			"Zmin": ["-1.3",
			"-1.5",
			"-.8",
			"-1.5 "],
			"Zmax": [" 1.3",
			"1.5",
			".8",
			"1.5"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Clebsch"],
			"Component": ["Clebsch"],
			"Fxyz": ["81*(x^3+y^3+z^3)-189*(x^2*y+x^2*z+y^2*x+y^2*z+z^2*x+z^2*y) +54*x*y*z+126*(x*y+x*z+y*z)-9*(x^2+y^2+z^2)-9*(x+y+z)+1"],
			"Xmin": ["-1"],
			"Xmax": [" 1"],
			"Ymin": ["-1"],
			"Ymax": [" 1"],
			"Zmin": ["-1"],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Icosahedron"],
			"Component": ["Icosahedron"],
			"Fxyz": ["if( (x^2 + y^2 +z^2 < 35), 2 - (cos(x + (1+sqrt(5))/2*y) + cos(x - (1+sqrt(5))/2*y) + cos(y + (1+sqrt(5))/2*z) + cos(y - (1+sqrt(5))/2*z) + cos(z - (1+sqrt(5))/2*x) + cos(z + (1+sqrt(5))/2*x)) , 1)"],
			"Xmin": ["-5.5"],
			"Xmax": [" 5.5"],
			"Ymin": ["-5.5"],
			"Ymax": [" 5.5"],
			"Zmin": ["-5.5"],
			"Zmax": [" 5.5"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["DingDong"],
			"Component": ["DingDong"],
			"Fxyz": ["x^2 +y^2 -(1-z)*z^2"],
			"Xmin": ["-1.5"],
			"Xmax": [" 1.5"],
			"Ymin": ["-1.5"],
			"Ymax": [" 1.5"],
			"Zmin": ["-1"],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Trap"],
			"Component": ["Trap"],
			"Fxyz": ["(x^8 + z^30 + y^8 - (x^4 + z^50 + y^4 -0.3))*(x^2 + y^2 + z^2 -0.5)"],
			"Xmin": ["-1.2"],
			"Xmax": [" 1.2"],
			"Ymin": ["-1.3"],
			"Ymax": [" 1.3"],
			"Zmin": ["-1.5"],
			"Zmax": [" 1.5"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["OrthoCircle"],
			"Component": ["OrthoCircle"],
			"Fxyz": ["((x^2 + y^2 - 1)^2 + z^2)* ((y^2 + z^2 - 1)^2 + x^2)* ((z^2 + x^2 - 1)^2 + y^2) - 0.075^2 *(1 + 3* (x^2 + y^2 + z^2))"],
			"Xmin": ["-1.5"],
			"Xmax": [" 1.5"],
			"Ymin": ["-1.5"],
			"Ymax": [" 1.5"],
			"Zmin": ["-1.5"],
			"Zmax": [" 1.5"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["CubeSphere_2"],
			"Component": ["CubeSphere_2"],
			"Fxyz": ["12 - ((1/2.3)^2 *(x^2 + y^2 + z^2))^-6 - ( (1/2)^8 * (x^8 + y^8 + z^8) )^6"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["UnionSpheres"],
			"Component": ["UnionSpheres"],
			"Fxyz": ["min( (x-0.7)*(x-0.7) + y*y + z*z - 1,  (x+0.5)*(x+0.5) + y*y + z*z - 1)"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["DifferenceSpheres"],
			"Component": ["DifferenceSpheres"],
			"Fxyz": ["((x-0.7)*(x-0.7) + y*y + z*z - 1)*min( (x-0.7)*(x-0.7) + y*y + z*z - 1, (x+0.3)*(x+0.3) + y*y + z*z - 1) +0.02"],
			"Xmin": ["-2"],
			"Xmax": [" 0.1"],
			"Ymin": ["-1"],
			"Ymax": [" 1"],
			"Zmin": ["-1"],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["BlendSpheres"],
			"Component": ["BlendSpheres"],
			"Fxyz": ["((x-0.9)*(x-0.9) + y*y + z*z - 1)*((x+0.9)*(x+0.9) + y*y + z*z - 1) -0.3"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{
		"Iso3D": {
			"Name": ["BouncingBall2"],
			"Component": ["SphereIso",
			"ThickWalls",
			"TransparentWall"],
			"Fxyz": ["((x-(abs(((t*2.5)%16)-8)-4))^2+(y-(abs(((t*2.9)%16)-8)-4))^2+(z-(4.4-((((t*1.2)%4)-2)^2)))^2-0.8)",
			"(z+.407)*(y-4.9)*(y+4.9)*(x+4.9)",
			"(x-4.9)"],
			"Grid": ["25",
			"15",
			"5"],
			"Xmax": ["4.81",
			"4.91",
			"4.92"],
			"Xmin": ["-4.81",
			"-4.91",
			"4.88"],
			"Ymax": ["4.81",
			"4.91",
			"4.91"],
			"Ymin": ["-4.81",
			"-4.91",
			"-4.91"],
			"Zmax": ["5.5",
			"5.5",
			"5.5"],
			"Zmin": ["-.5",
			"-.41",
			"-.41"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["IntersectSpheres"],
			"Component": ["IntersectSpheres"],
			"Fxyz": ["max( (x-0.7)*(x-0.7) + y*y + z*z - 1,  (x+0.5)*(x+0.5) + y*y + z*z - 1)"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["TwoCylinderBlend"],
			"Component": ["TwoCylinderBlend"],
			"Fxyz": ["(x^2 + y^2 - 1) * ( x^2 + z^2 - 1) - 1"],
			"Xmin": ["-3"],
			"Xmax": [" 3"],
			"Ymin": ["-3"],
			"Ymax": [" 3"],
			"Zmin": ["-3"],
			"Zmax": [" 3"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["BlendThreeCylinder"],
			"Component": ["BlendThreeCylinder"],
			"Fxyz": ["(x^2 + y^2 - 1) * ( x^2 + z^2 - 1)* ( y^2 + z^2 - 1) - 1"],
			"Xmin": ["-3"],
			"Xmax": [" 3"],
			"Ymin": ["-3"],
			"Ymax": [" 3"],
			"Zmin": ["-3"],
			"Zmax": [" 3"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Holes"],
			"Component": ["Holes"],
			"Fxyz": ["3*(cos(x) + cos(y) + cos(z)) + 4* cos(x) * cos(y) * cos(z)"],
			"Xmin": ["-3"],
			"Xmax": [" 3"],
			"Ymin": ["-3"],
			"Ymax": [" 3"],
			"Zmin": ["-3"],
			"Zmax": [" 3"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Gyroid"],
			"Component": ["Gyroid"],
			"Fxyz": ["cos(x) * sin(y) + cos(y) * sin(z) + cos(z) * sin(x)"],
			"Xmin": ["-4"],
			"Xmax": [" 4"],
			"Ymin": ["-4"],
			"Ymax": [" 4"],
			"Zmin": ["-4"],
			"Zmax": [" 4"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Diamand"],
			"Component": ["Diamand"],
			"Fxyz": ["sin(x) *sin(y) *sin(z) +sin(x) * cos(y) * cos(z) +cos(x) * sin(y) * cos(z) + cos(x) * cos(y) * sin(z)"],
			"Xmin": ["-4"],
			"Xmax": [" 4"],
			"Ymin": ["-4"],
			"Ymax": [" 4"],
			"Zmin": ["-4"],
			"Zmax": [" 4"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Tetrahedral"],
			"Component": ["Tetrahedral"],
			"Fxyz": ["(x^2 + y^2 + z^2)^2 + 8*x*y*z - 10*(x^2 + y^2 + z^2) + 25"],
			"Xmin": ["-4"],
			"Xmax": [" 4"],
			"Ymin": ["-4"],
			"Ymax": [" 4"],
			"Zmin": ["-4"],
			"Zmax": [" 4"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Holes_2"],
			"Component": ["Holes_2"],
			"Fxyz": ["sin(4*x) + sin(4*y) + sin(4*z)  + 4*x*y*z"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["Bugs"],
			"Component": ["Bugs"],
			"Fxyz": ["min( ((x*cos(0.866646*y) - z*sin(0.866646*y))-0.7)*((x*cos(0.866646*y) - z*sin(0.866646*y))-0.7) + (y/2.9)*(y/2.9) + (x*sin(0.866646*y) + z*cos(0.866646*y))*(x*sin(0.866646*y) + z*cos(0.866646*y)) - 1,  ((x*cos(0.866646*y) - z*sin(0.866646*y))+0.5)*((x*cos(0.866646*y) - z*sin(0.866646*y))+0.5) + (y/2.9)*(y/2.9) + (x*sin(0.866646*y) + z*cos(0.866646*y))*(x*sin(0.866646*y) + z*cos(0.866646*y)) - 1)"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2*2.9*1"],
			"Ymax": [" 2*2.9*1"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{

            "Iso3D": {
                "Component": [
                    "Noise_pseudo_Duplin"
                ],
                "Varu": [
                    "A=cos(0.9589716*u)",
                    "B=sin(0.9589716*u)"
                ],
                "Fxyz": [
                    "-49.95*((x/2.34)^4+(y*Ax - z*Bx)^4+ (y*Bx + z*Ax)^4) +
                    (-99.95)* ((x/2.34)^2 * (y*Ax - z*Bx)^2+(x/2.34)^2 * (y*Bx + z*Ax)^2+(y*Ax - z*Bx)^2 * (y*Bx + z*Ax)^2)+
                    (141.12* (x/2.34-1))*((x/2.34)^2 +(y*Ax - z*Bx)^2+(y*Bx + z*Ax)^2)+
                    (54.7 *x)* (-4 +0.8547 * x) + 262.4 * (y*Ax - z*Bx)^2 + 256"
                ],
                "Name": [
                    "pseudo_Duplin"
                ],
                "Xmax": [
                    " 2.5*3.9*0.6"
                ],
                "Xmin": [
                    "-2*3.9*0.6"
                ],
                "Ymax": [
                    " 2"
                ],
                "Ymin": [
                    "-2"
                ],
                "Zmax": [
                    " 2"
                ],
                "Zmin": [
                    "-2"
                ]
            },
    "Noise": "True",
    "Texture": {
        "Colors": [
            "R=1",
            "G=0.6*abs(cos(2*(z*z+(y+1)*(y+1)+x*x)))",
            "B=0.5+0.3*abs(cos(2.5*(z*z +x*x +y*y)))",
            "T=1"
        ],
        "Name": "Granit"
    }			
},
{

            "Iso3D": {
                "Component": [
                    "Pigment_pseudo_Duplin"
                ],
                "Varu": [
                    "A=cos(0.9589716*u)",
                    "B=sin(0.9589716*u)"
                ],
                "Fxyz": [
                    "-49.95*((x/2.34)^4+(y*Ax - z*Bx)^4+ (y*Bx + z*Ax)^4) +
                    (-99.95)* ((x/2.34)^2 * (y*Ax - z*Bx)^2+(x/2.34)^2 * (y*Bx + z*Ax)^2+(y*Ax - z*Bx)^2 * (y*Bx + z*Ax)^2)+
                    (141.12* (x/2.34-1))*((x/2.34)^2 +(y*Ax - z*Bx)^2+(y*Bx + z*Ax)^2)+
                    (54.7 *x)* (-4 +0.8547 * x) + 262.4 * (y*Ax - z*Bx)^2 + 256"
                ],
                "Name": [
                    "pseudo_Duplin"
                ],
                "Xmax": [
                    " 2.5*3.9*0.6"
                ],
                "Xmin": [
                    "-2*3.9*0.6"
                ],
                "Ymax": [
                    " 2"
                ],
                "Ymin": [
                    "-2"
                ],
                "Zmax": [
                    " 2"
                ],
                "Zmin": [
                    "-2"
                ]
            },


		"Pigment": {
			"Colors": [{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=.20",
					"R=.90",
					"G=.9",
					"B=.40",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0.3",
					"R=1",
					"G=.1",
					"B=.31",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0.6",
					"R=1",
					"G=.7",
					"B=1",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0.6",
					"R=1",
					"G=0.3",
					"B=.1",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=1",
					"R=.15",
					"G=.6",
					"B=.1",
					"A=1"]
				}
			}],
			"Gradient": "3*cos((x*x *z)*pi)*cos(y*y*z*pi)*cos((y *x)*pi)*cos(z*y*x*pi)"
		}





	},
	{
		"Iso3D": {
			"Description": ["This is a Description"],
			"Name": ["pseudo_Torus"],
			"Component": ["pseudo_Torus"],
			"Fxyz": ["(sqrt((x/2.7)*(x/2.7)+(y*sin(0.436332*x) + z*cos(0.436332*x))*(y*sin(0.436332*x) + z*cos(0.436332*x)))-3)^2 + (y*cos(0.436332*x) - z*sin(0.436332*x))*(y*cos(0.436332*x) - z*sin(0.436332*x)) - 1"],
			"Xmin": ["-4*2.7"],
			"Xmax": [" 4*2.7"],
			"Ymin": ["-4"],
			"Ymax": [" 4"],
			"Zmin": ["-4"],
			"Zmax": [" 4"]
		}
	},
	{
		"Iso3D": {
			"Description": [" We used Schwarz formula to make a parametrable Chmutov-like  isosurface:
		(x^N + y ^N + z^N) - (cos(m*7*x) + cos(n*7*y) + cos(k*7*z)) + l
		N : Even integer > 4 --> Sharpness of edges.
		n, m, k : integers --> number of holes.
		l : Real number (-3,1) --> Thickness
		"],
			"Name": ["ChmutySchwarz"],
			"Component": ["ChmutySchwarz"],
			"Fxyz": ["
		(x^16 + y ^16 + z^16 ) -(cos(7*x) +cos(7*y) +cos(7*z)) -.1"],
			"Xmin": ["-1.1"],
			"Xmax": [" 1.1"],
			"Ymin": ["-1.1"],
			"Ymax": [" 1.1"],
			"Zmin": ["-1.1"],
			"Zmax": [" 1.1"]
		}
	},
	{
		"Iso3D": {
			"Description": [" This example was obtained by using the above formula !"],
			"Name": ["Virus"],
			"Component": ["Virus"],
			"Fxyz": ["-(x^2 + y ^2 + z^2) +cos(5*x)*cos(5*y)*cos(5*z)+0.215"],
			"Xmin": ["-.8"],
			"Xmax": [" .8"],
			"Ymin": ["-.8"],
			"Ymax": [" .8"],
			"Zmin": ["-.8"],
			"Zmax": [" .8"]
		}
	},
	{
		"Iso3D": {
			"Description": [" We can even obtain a smoothly closed Schwarz Isosurface... "],
			"Name": ["BlobySchwarz"],
			"Component": ["BlobySchwarz"],
			"Fxyz": ["-(x^2 + y ^2 + z^2) +cos(5*x)+cos(5*y)+cos(5*z) -.1"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{
		"Iso3D": {
			"Description": [" To make  \"tick\" isosurfaces, you can use this general  method:
		G(x, y, z) = F(x, y, z) * F(x - (T/R)*dF()/dx, y - (T/R)*dF()/dy, z - (T/R)*df()/dz)
		dF()/dx == partial derivative of F() to the variable x.
		F(x, y, z)  : The original Isosurface formula.
		G(x, y, z) : The new Isosurface formula.
		R = sqrt((dF()/dx)^2 + (dF()/dy)^2 + (dF()/dz)^2)
		T = Tickness value
		Applied to Schwarz (F()= cos(x) + cos(y) + cos(z) , T = 1/2) ,we obtain the following formula:"],
			"Name": ["TickIso"],
			"Component": ["TickIso"],
			"Fxyz": ["(cos(x) + cos(y) + cos(z))*((
		cos(x + sin(x)/(2*sqrt(sin(x)^2 + sin(y)^2 + sin(z)^2))) +
		cos(y + sin(y)/(2*sqrt(sin(x)^2 + sin(y)^2 + sin(z)^2))) +
		cos(z + sin(z)/(2*sqrt(sin(x)^2 + sin(y)^2 + sin(z)^2)))))"],
			"Xmin": ["-4"],
			"Xmax": [" 4"],
			"Ymin": ["-4"],
			"Ymax": [" 4"],
			"Zmin": ["-4"],
			"Zmax": [" 4"]
		}
	},
	{
		"Iso3D": {
			"Description": [" To make a closed Isosurface, you can use the \"if\" instruction like in this example with Schwarz :
		if((x^10 + y^10 +z^10 < 200000),   // We use a Cube as a condition
		cos(x) + cos(y) + cos(z) ,           // Schwarz
		(x^10 + y^10 +z^10 - 200000 )     // Cube"],
			"Name": ["CloseIso"],
			"Component": ["CloseIso"],
			"Fxyz": [" if((x^10 + y^10 +z^10 < 200000), cos(x) + cos(y) + cos(z), (x^10 + y^10 +z^10 - 200000))"],
			"Xmin": ["-4"],
			"Xmax": [" 4"],
			"Ymin": ["-4"],
			"Ymax": [" 4"],
			"Zmin": ["-4"],
			"Zmax": [" 4"]
		}
	},
	{
		"Iso3D": {
			"Description": [" Another closed isosurface but in this case we consider the outside volume delimited by the Schwarz surface.
		The \"outside\" volume is defined by deleting the signe \"-\""],
			"Name":["CloseIso_1"],
			"Component": ["CloseIso_1"],
			"Fxyz":["if((x^10+y^10+z^10<100000),
			(cos(x)+cos(y)+cos(z)),
			(x^10+y^10+z^10-100000))"],
			"Xmin":["-4"], "Xmax":["4"],
			"Ymin":["-4"], "Ymax":["4"],
			"Zmin":["-4"], "Zmax":["4"]
		}},

		{"Iso3D":
		{
		"Description":["TomakethickandclosedSchwarzIsosurface,
			weusethetwoformulasdescribedabove: "],
		"Name":["CloseIso_2"],
		"Component": ["CloseIso_2"],
		"Fxyz":["if((x^10+y^10+z^10<3*(3.5^10)),
			(cos(x)+cos(y)+cos(z))*((cos(x+sin(x)/(2*sqrt(sin(x)^2+sin(y)^2+sin(z)^2)))+cos(y+sin(y)/(2*sqrt(sin(x)^2+sin(y)^2+sin(z)^2)))+cos(z+sin(z)/(2*sqrt(sin(x)^2+sin(y)^2+sin(z)^2))))),
			(x^10+y^10+z^10-3*(3.5^10)))"],
		"Xmin":["-4"], "Xmax":["4"],
		"Ymin":["-4"], "Ymax":["4"],
		"Zmin":["-4"], "Zmax":["4"]
		}},

		{"Iso3D":
		{
		"Description":["Byreplacing: bytheoperator*,
			weobtainONEuniqueisosurfacecomposedofsixTorus"],
		"Name":["Chain"],
		"Component": ["Chain"],
		"Fxyz":["((sqrt(x*x+y*y)-3)^2+z*z-0.4)*((sqrt((x-4.5)*(x-4.5)+z*z)-3)^2+y*y-0.4)*((sqrt((x+4.5)*(x+4.5)+z*z)-3)^2+y*y-0.4)*((sqrt((y+4.5)*(y+4.5)+z*z)-3)^2+x*x-0.4)*((sqrt((y-4.5)*(y-4.5)+z*z)-3)^2+x*x-0.4)*((sqrt(x*x+y*y)-5)^2+z*z-0.4)"],
		"Xmin":["-8.2"], "Xmax":["8.2"],
		"Ymin":["-8.2"], "Ymax":["8.2"],
		"Zmin":["-4"], "Zmax":["4"]
		}},
{ 
"Iso3D": { 
"Cnd": [ 
"(sqrt(x^2+y^2+z^2))<8" 
], 
"Component": [ 
"DiamondLatice" 
], 
"Const": [ 
"T=1", 
"G=-1" 
], 
"Funct": [ 
"df=(cos(x)*sin(y)*sin(z)+cos(x)*cos(y)*cos(z)-sin(x)*sin(y)*cos(z)-sin(x)*cos(y)*sin(z))", 
"R=sqrt((cos(x)*sin(y)*sin(z)+cos(x)*cos(y)*cos(z)-sin(x)*sin(y)*cos(z)-sin(x)*cos(y)*sin(z))^2+(cos(y)*sin(z)*sin(x)+cos(y)*cos(z)*cos(x)-sin(y)*sin(z)*cos(x)-sin(y)*cos(z)*sin(x))^2+(cos(z)*sin(x)*sin(y)+cos(z)*cos(x)*cos(y)-sin(z)*sin(x)*cos(y)-sin(z)*cos(x)*sin(y))^2)", 
"Diamond=(sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z))" 
], 
"Fxyz": [ 
"Diamond(x-df(x,
			y,
			z,
			t)*T/R(x,
			y,
			z,
			t),
			y-df(y,
			z,
			x,
			t)*T/R(x,
			y,
			z,
			t),
			z-df(z,
			x,
			y,
			t)*T/R(x,
			y,
			z,
			t),
			t)*Diamond(x-df(x,
			y,
			z,
			t)*G/R(x,
			y,
			z,
			t),
			y-df(y,
			z,
			x,
			t)*G/R(x,
			y,
			z,
			t),
			z-df(z,
			x,
			y,
			t)*G/R(x,
			y,
			z,
			t),
			t)" 
], 
"Name": [ 
"DiamondLatice" 
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
} 
},
{ 
"Iso3D": { 
"Cnd": [ 
"(sqrt(x^2+y^2+z^2))<8" 
], 
"Component": [ 
"GyroidLatice" 
], 
"Const": [ 
"T=1", 
"G=-1" 
], 
"Funct": [ 
"R=sqrt((-sin(x)*sin(y)+cos(x)*cos(z))^2+(-sin(y)*sin(z)+cos(y)*cos(x))^2+(-sin(z)*sin(x)+cos(z)*cos(y))^2)", 
"df=(-sin(x)*sin(y)+cos(x)*cos(z))", 
"Gyroid=(cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x))" 
], 
"Fxyz": [ 
"Gyroid(x-df(x,
			y,
			z,
			t)*T/R(x,
			y,
			z,
			t),
			y-df(y,
			z,
			x,
			t)*T/R(x,
			y,
			z,
			t),
			z-df(z,
			x,
			y,
			t)*T/R(x,
			y,
			z,
			t),
			t)*Gyroid(x-df(x,
			y,
			z,
			t)*G/R(x,
			y,
			z,
			t),
			y-df(y,
			z,
			x,
			t)*G/R(x,
			y,
			z,
			t),
			z-df(z,
			x,
			y,
			t)*G/R(x,
			y,
			z,
			t),
			t)" 
], 
"Name": [ 
"GyroidLatice" 
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
} 
},
{
    "Iso3D": {
        "Cnd": [
            "(sqrt(x^2+y^2+z^2))<9"
        ],
        "Component": [
            "NeoviusLatice"
        ],
        "Const": [
            "T=.3",
            "G=-.3"
        ],
        "Funct": [
            "df=(-3*sin(x)-4*sin(x)*cos(y)*cos(z))",
            "R=sqrt(df(x,
			y,
			z,
			t)^2+df(y,
			z,
			x,
			t)^2+df(z,
			y,
			x,
			t)^2)",
            "Neovius=(3*(cos(x)+cos(y)+cos(z))+4*cos(x)*cos(y)*cos(z))"
        ],
        "Fxyz": [
            "Neovius(x-df(x,
			y,
			z,
			t)*T/R(x,
			y,
			z,
			t),
			y-df(y,
			z,
			x,
			t)*T/R(x,
			y,
			z,
			t),
			z-df(z,
			x,
			y,
			t)*T/R(x,
			y,
			z,
			t),
			t)*Neovius(x-df(x,
			y,
			z,
			t)*G/R(x,
			y,
			z,
			t),
			y-df(y,
			z,
			x,
			t)*G/R(x,
			y,
			z,
			t),
			z-df(z,
			x,
			y,
			t)*G/R(x,
			y,
			z,
			t),
			t)"
        ],
        "Name": [
            "NeoviusLatice"
        ],
        "Xmax": [
            "9"
        ],
        "Xmin": [
            "-9"
        ],
        "Ymax": [
            "9"
        ],
        "Ymin": [
            "-9"
        ],
        "Zmax": [
            "9"
        ],
        "Zmin": [
            "-9"
        ]
    }
},
{ 
"Iso3D": { 
"Name": [ 
"LinoidLatice" 
], 
"Cnd": [ 
"(sqrt(x^2+y^2+z^2))<3" 
], 
"Component": [ 
"LinoidLatice" 
], 
"Const": [ 
"T=.05", 
"G=-.05" 
], 
"Funct": [ 
"df=((1/2)*(2*cos(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*cos(x)-sin(2*z)*sin(x)*sin(y))-(1/2)*(-2*sin(2*x)*cos(2*y)-2*cos(2*z)*sin(2*x)))", 
"R=sqrt(df(x,
			y,
			z,
			t)^2+df(y,
			z,
			x,
			t)^2+df(z,
			y,
			x,
			t)^2)", 
"Linoid=((1/2)*(sin(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*sin(x)+sin(2*z)*cos(x)*sin(y))-(1/2)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+0.15)" 
], 
"Fxyz": [ 
"Linoid(x-df(x,
			y,
			z,
			t)*T/R(x,
			y,
			z,
			t),
			y-df(y,
			z,
			x,
			t)*T/R(x,
			y,
			z,
			t),
			z-df(z,
			x,
			y,
			t)*T/R(x,
			y,
			z,
			t),
			t)*Linoid(x-df(x,
			y,
			z,
			t)*G/R(x,
			y,
			z,
			t),
			y-df(y,
			z,
			x,
			t)*G/R(x,
			y,
			z,
			t),
			z-df(z,
			x,
			y,
			t)*G/R(x,
			y,
			z,
			t),
			t)" 
], 
"Xmax": [ 
"3" 
], 
"Xmin": [ 
"-3" 
], 
"Ymax": [ 
"3" 
], 
"Ymin": [ 
"-3" 
], 
"Zmax": [ 
"3" 
], 
"Zmin": [ 
"-3" 
] 
} 
},
{
"Iso3D": {
"Component": [
"Lidinoid"
],
"Description": [
"SvenLidinandStefanLarsson"
],
"Fxyz": [
"-((1/2)*(sin(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*sin(x)+sin(2*z)*cos(x)*sin(y))-(1/2)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+0.15)"
],
"Name": [
"Lidinoid"
],
"Xmax": [
"3"
],
"Xmin": [
"-3"
],
"Ymax": [
"3"
],
"Ymin": [
"-3"
],
"Zmax": [
"3"
],
"Zmin": [
"-3"
]
}
},
{
    "Iso3D": {
        "Name": [
            "G_SkeletalGraph"
        ],
        "Component": [
            "G_SkeletalGraph"
        ],
        "Description": [
            "GyroidSkeletalGraph"
        ],
        "Fxyz": [
            "cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)+0.08*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+1.47"
        ],
        "Xmax": [
            "2.75*pi"
        ],
        "Xmin": [
            "-0.25*pi"
        ],
        "Ymax": [
            "2.75*pi"
        ],
        "Ymin": [
            "-0.25*pi"
        ],
        "Zmax": [
            "2.75*pi"
        ],
        "Zmin": [
            "-0.25*pi"
        ]
    }
},
{
    "Iso3D": {
        "Name": [
            "D_SkeletalGraph"
        ],
        "Component": [
            "D_SkeletalGraph"
        ],
        "Description": [
            "DiamondSkeletalGraph"
        ],
        "Fxyz": [
            "sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)-0.07*(cos(4*x)+cos(4*y)+cos(4*z))+1.17"
        ],
        "Xmax": [
            "2.75*pi"
        ],
        "Xmin": [
            "-0.25*pi"
        ],
        "Ymax": [
            "2.75*pi"
        ],
        "Ymin": [
            "-0.25*pi"
        ],
        "Zmax": [
            "2.75*pi"
        ],
        "Zmin": [
            "-0.25*pi"
        ]
    }
},
{
    "Iso3D": {
        "Name": [
            "P_SkeletalGraph"
        ],
        "Component": [
            "P_SkeletalGraph"
        ],
        "Description": [
            "Schwarz(Primitive)SkeletalGraph"
        ],
        "Fxyz": [
            "cos(x)+cos(y)+cos(z)+0.51*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+1.47"
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
        "Name": [
            "W_SkeletalGraph"
        ],
        "Component": [
            "W_SkeletalGraph"
        ],
        "Description": [
            "iWPSkeletalGraph"
        ],
        "Fxyz": [
            "cos(2*x)+cos(2*y)+cos(2*z)-1.95*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+2.8"
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
            "ConstructiveSolidGeometry(CSG)withmathematics"
        ],
        "Name": [
            "CSGSpheres"
        ],
        "Component": [
            "DifferenceSpheres",
            "UnionSpheres",
            "IntersectSpheres"
        ],

        "Fxyz": [
            "((x-0.7)*(x-0.7)+y*y+z*z-1)*min((x-0.7)*(x-0.7)+y*y+z*z-1,
			(x+0.3)*(x+0.3)+y*y+z*z-1)+0.02",
            "min((x-4.7)*(x-4.7)+y*y+z*z-1,
			(x-3.5)*(x-3.5)+y*y+z*z-1)",
            "max((x-0.7)*(x-0.7)+y*y+z*z-1,
			(x-2.)*(x-2.)+y*y+z*z-1)"
        ],
        "Xmax": [
            "0.5",
            "6",
            "2"
        ],
        "Xmin": [
            "-2",
            "2",
            "0"
        ],
        "Ymax": [
            "2",
            "2",
            "2"
        ],
        "Ymin": [
            "-2",
            "-2",
            "-2"
        ],
        "Zmax": [
            "2",
            "2",
            "2"
        ],
        "Zmin": [
            "-2",
            "-2",
            "-2"
        ]
    }
},
{
    "Iso3D": {
        "Name": [
            "MirroredTorus"
        ],
        "Component": [
            "Torus",
            "Plan"
        ],
        "Const": [
            "a=0",
            "b=1",
            "c=-1",
            "d=4",
            "R=(a^2+b^2+c^2)"
        ],
        "Funct": [
            "Torus=((sqrt(x*x+y*y)-3)^2+z*z-1)",
            "P=(a*x+b*y+c*z+d)"
        ],
        "Fxyz": [
            "Torus(x,
			y,
			z+1,
			t)*Torus(x-2*P(x,
			y,
			z,
			t)*a/R,
			y-2*P(x,
			y,
			z,
			t)*b/R,
			z+1-2*P(x,
			y,
			z,
			t)*c/R,
			t)",
            "y+4-z"
        ],
        "Xmax": [
            "4",
            "4"
        ],
        "Xmin": [
            "-4",
            "-4"
        ],
        "Ymax": [
            "8",
            "8"
        ],
        "Ymin": [
            "-6",
            "-6"
        ],
        "Zmax": [
            "9",
            "9"
        ],
        "Zmin": [
            "-4",
            "-4"
        ],
       "Description": [
"Givenanisosurface(F)andaPlan(P),
			wecandefineanewisosurface(G)thatisthe'mirrored'projectionof(F),
			byusingtheformula: G(x,
			y,
			z)=F(x-2*P(x,
			y,
			z)*a/R,
			y-2*P(x,
			y,
			z)*b/R,
			z-2*P(x,
			y,
			z)*c/R)Where: P(x,
			y,
			z)=ax+by+cz+d(EquationofthePlan)R=(a^2+b^2+c^2)ThisexampleshowstheresultforaTorus(F)andaPlan(P=y-z+4)"
        ]
    }
},
        {
        "Iso3D": {
        "Name": [
        "CheckerTexture"
        ],
        "Component": [
        "Sphere",
        "Cube",
        "Schwarz",
        "Sinus"
        ],
        "Funct": [
        "Radius=sqrt(x*x+y*y+z*z)",
        "Theta=atan(y/x)",
        "Phi=acos(z/sqrt(x*x+y*y+z*z))"
        ],
        "Fxyz": [
        "x*x+y*y+z*z-36",
        "(x+14)^100+y^100+z^100-6*10^77",
        "cos(x/1.5)+cos((y+16)/1.5)+cos(z/1.5)",
        "sin(2*pi*(((x+14)/4)^2+((y+14)/4)^2))/8+z/4"
        ],
        "Xmax": [
        "6",
        "-8",
        "6",
        "-9"
        ],
        "Xmin": [
        "-6",
        "-20",
        "-6",
        "-19"
        ],
        "Ymax": [
        "6",
        "6",
        "-10",
        "-9"
        ],
        "Ymin": [
        "-6",
        "-6",
        "-22",
        "-19"
        ],
        "Zmax": [
        "6",
        "6",
        "6",
        "4"
        ],
        "Zmin": [
        "-6",
        "-6",
        "-6",
        "-4"
        ]
        },
        "Texture": {
        "Colors": [
        "R=(int(abs(x))+int(abs(y))+int(abs(z)))%2",
        "G=.1",
        "B=1",
        "T=1"
        ],
        "Name": "Checker"
        }
        },
{
"Iso3D": {
        "Component": [
            "pseudo_Duplin"
        ],
        "Varu": [
            "A=cos(0.9589716*u)",
			"B=sin(0.9589716*u)"
        ],
        "Fxyz": [
            "-49.95*((x/2.34)^4+(y*Ax - z*Bx)^4+ (y*Bx + z*Ax)^4) + 
			(-99.95)* ((x/2.34)^2 * (y*Ax - z*Bx)^2+(x/2.34)^2 * (y*Bx + z*Ax)^2+(y*Ax - z*Bx)^2 * (y*Bx + z*Ax)^2)+ 
			(141.12* (x/2.34-1))*((x/2.34)^2 +(y*Ax - z*Bx)^2+(y*Bx + z*Ax)^2)+ 
			(54.7 *x)* (-4 +0.8547 * x) + 262.4 * (y*Ax - z*Bx)^2 + 256"
        ],
        "Name": [
            "pseudo_Duplin"
        ],
        "Xmax": [
            " 2.2*3.9*0.6"
        ],
        "Xmin": [
            "-2*3.9*0.6"
        ],
        "Ymax": [
            " 2"
        ],
        "Ymin": [
            "-2"
        ],
        "Zmax": [
            " 2"
        ],
        "Zmin": [
            "-2"
        ]
    },
    "Pigment": {
        "Colors": [
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=.20",
                        "R=.4",
                        "G=.4",
                        "B=.70",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0.3",
                        "R=1",
                        "G=.1",
                        "B=.31",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0.6",
                        "R=.51",
                        "G=.17",
                        "B=1",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0.6",
                        "R=1",
                        "G=0.3",
                        "B=.1",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=1",
                        "R=.915",
                        "G=.17",
                        "B=.1",
                        "A=1"
                    ]
                }
            }
        ],
        "Gradient": "3*cos((x*x+y*y)*pi)*sin((y*y+z*z)*pi)"
    }
},
{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Klein"],
		"Component":["Klein_1","Klein_2"],
		"Fx":["4*(1-cos(u)/2)*cos(u)*cos(v)+6*cos(u)*(1+sin(u))","4*(1-cos(u)/2)*cos(v+pi)+6*cos(u)*(1+sin(u))"],
		"Fy":["4*(1-cos(u)/2)*sin(u)*cos(v)+16*sin(u)","16*sin(u)"],
		"Fz":["4*(1-cos(u)/2)*sin(v)","4*(1-cos(u)/2)*sin(v)"],
		"Umin":["0","pi"] , "Umax":["pi","2*pi"],
		"Vmin":["0","0"] , "Vmax":["2*pi","2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Klein_1"],
		"Component": ["Klein_1"],
		"Funct": ["KleinFunction=(3*(1+sin(v))+2*(1-cos(v)/2)*cos(u))*cos(v)"],
		"Const": ["T1=2"],
		"Fx":["KleinFunction(u,
			v,
			t)"],
		"Fy":["(4+2*(1-cos(v)/2)*cos(u))*sin(v)"],
		"Fz":["-2*(1-cos(v)/2)*sin(u)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param4D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["4DTorus"],
		"Component": ["4DTorus"],
		"Fx":["sin(u)"],
		"Fy":["cos(u)"],
		"Fz":["sin(v)"],
		"Fw":["cos(v)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{
			"Param4D": {
				"Description": [
					"Descriptionofthemodel"
				],
                "Component":["4DTorus4D","4DPTorus","4DCliffordTorus"],
				"Fw": [
					"cos(v)",
					"cos(3*v)",
					"cos(u)"
				],
				"Fx": [
					"sin(u)",
					"sin(u)+2",
					"cos(u+v)/(sqrt(2.)+cos(v-u))"
				],
				"Fy": [
					"cos(u)",
					"cos(u)",
					"sin(u+v)/(sqrt(2.)+cos(v-u))+3"
				],
				"Fz": [
					"sin(v)",
					"sin(2*v)",
					"(sin(v-u)/(sqrt(2.)+cos(v-u)))*1.5"
				],
				"Name": [
					"4DMathModels"
				],
				"Umax": [
					"2*pi",
					"2*pi",
					"pi"
				],
				"Umin": [
					"0",
					"0",
					"0"
				],
				"Vmax": [
					"2*pi",
					"2*pi",
					"2*pi"
				],
				"Vmin": [
					"0",
					"0",
					"0"
				]
			}
		},
{
    "Param3D": {
        "Name": [
            "Shell"
        ],
        "Cnd": [
            "(x^2+y^2)>2.0"
        ],
        "Varu": [
            "A=(u-4*sin(3.14/10))^2",
            "B=(u-2*cos(3.14/10))^2",
            "C=(u-2*sin(3.14)-4*sin(3.14/10))^2",
            "D=(u-2*cos(3.14)-2*cos(3.14/10))^2"
        ],
        "Funct": [
            "Schwarz1=cos(u)",
            "Schwarz2=cos(u)+sin(v)"
        ],
        "Component": [
            "Shell"
        ],
        "Const": [
            "r=(1/4)*(1+3*sqrt(5))",
            "a=-(8/5)*(1+1/(sqrt(5)))*sqrt(5-sqrt(5))",
            "c=(1/2)*sqrt(5-sqrt(5))"
        ],
        "Fx": [
            "1.2^v*(sin(u)^2*sin(v))"
        ],
        "Fy": [
            "1.2^v*(sin(u)^2*cos(v))"
        ],
        "Fz": [
            "1.2^v*(sin(u)*cos(u))"
        ],
        "Umax": [
            "pi"
        ],
        "Umin": [
            "0"
        ],
        "Vmax": [
            "5*pi/2"
        ],
        "Vmin": [
            "-pi/4"
        ]
    }
}
,
		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Torus"],
		"Component": ["Torus"],
		"Fx":["(1+0.5*cos(u))*cos(v)"],
		"Fy":["(1+0.5*cos(u))*sin(v)"],
		"Fz":["0.5*sin(u)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Cosinus"],
		"Component": ["Cosinus"],
		"Fx":["u"],
		"Fy":["v"],
		"Fz":["-sin(pi*((u)^2+(v)^2))/3"],
		"Umin":["-1"] , "Umax":["1"],
		"Vmin":["-1"] , "Vmax":["1"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Moebius"],
		"Component": ["Moebius"],
		"Fx":["cos(v)+u*cos(v/2)*cos(v)"],
		"Fy":["sin(v)+u*cos(v/2)*sin(v)"],
		"Fz":["u*sin(v/2)"],
		"Umin":["-0.4"] , "Umax":["0.4"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Riemann"],
		"Component": ["Riemann"],
		"Fx":["u*v"],
		"Fy":["v^2-u^2"],
		"Fz":["30*u"],
		"Umin":["-6"] , "Umax":["6"],
		"Vmin":["-25"] , "Vmax":["25"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Klein_2"],
		"Component": ["Klein_2"],
		"Fx":["(2+cos(v/2)*sin(u)-sin(v/2)*sin(2*u))*cos(v)"],
		"Fy":["(2+cos(v/2)*sin(u)-sin(v/2)*sin(2*u))*sin(v)"],
		"Fz":["sin(v/2)*sin(u)+cos(v/2)*sin(2*u)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Henneberg"],
		"Component": ["Henneberg"],
		"Fx":["2*sinh(u)*cos(v)-(2/3)*sinh(3*u)*cos(3*v)"],
		"Fy":["2*sinh(u)*sin(v)+(2/3)*sinh(3*u)*sin(3*v)"],
		"Fz":["2*cosh(2*u)*cos(2*v)"],
		"Umin":["-1"] , "Umax":["1"],
		"Vmin":["-pi/2"] , "Vmax":["pi/2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Enneper"],
		"Component": ["Enneper"],
		"Fx":["u-u^3/3+u*v^2"],
		"Fy":["v-v^3/3+v*u^2"],
		"Fz":["u^2-v^2"],
		"Umin":["-2"] , "Umax":["2"],
		"Vmin":["-2"] , "Vmax":["2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Helix"],
		"Component": ["Helix"],
		"Fx":["(1-0.1*cos(v))*cos(u)"],
		"Fy":["(1-0.1*cos(v))*sin(u)"],
		"Fz":["0.1*(sin(v)+u/1.7-10)"],
		"Umin":["0"] , "Umax":["4*pi"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Hexaedron"],
		"Component": ["Hexaedron"],
		"Fx":["cos(v)^3*cos(u)^3"],
		"Fy":["sin(v)^3*cos(u)^3"],
		"Fz":["sin(u)^3"],
		"Umin":["-1.3"] , "Umax":["1.3"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Sphere"],
		"Component": ["Sphere"],
		"Fx":["cos(u)*cos(v)"],
		"Fy":["cos(u)*sin(v)"],
		"Fz":["sin(u)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Catalan"],
		"Component": ["Catalan"],
		"Fx":["u-sin(u)*cosh(v)"],
		"Fy":["1-cos(u)*cosh(v)"],
		"Fz":["4*sin(1/2*u)*sinh(v/2)"],
		"Umin":["-pi"] , "Umax":["3*pi"],
		"Vmin":["-2"] , "Vmax":["2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Toupie"],
		"Component": ["Toupie"],
		"Fx":["(abs(u)-1)^2*cos(v)"],
		"Fy":["(abs(u)-1)^2*sin(v)"],
		"Fz":["u"],
		"Umin":["-1"] , "Umax":["1"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Trumpet"],
		"Component": ["Trumpet"],
		"Fx":["cos(u)*sin(v)"],
		"Fy":["sin(u)*sin(v)"],
		"Fz":["(cos(v)+log(tan(1/2*v)))"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["0.03"] , "Vmax":["2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Bonbon"],
		"Component": ["Bonbon"],
		"Fx":["u"],
		"Fy":["cos(u)*cos(v)"],
		"Fz":["cos(u)*sin(v)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Kuen"],
		"Component": ["Kuen"],
		"Fx":["(2*(cos(u)+u*sin(u))*sin(v))/(1+u^2*sin(v)^2)"],
		"Fy":["(2*(sin(u)-u*cos(u))*sin(v))/(1+u^2*sin(v)^2)"],
		"Fz":["log(tan(1/2*v))+(2*cos(v))/(1+u^2*sin(v)^2)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["0.01"] , "Vmax":["pi-0.01"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Catenoid"],
		"Component": ["Catenoid"],
		"Fx":["2*cosh(v/2)*cos(u)"],
		"Fy":["2*cosh(v/2)*sin(u)"],
		"Fz":["v"],
		"Umin":["-pi"] , "Umax":["pi"],
		"Vmin":["-pi"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Shoe"],
		"Component": ["Shoe"],
		"Fx":["u"],
		"Fy":["v"],
		"Fz":["1/3*u^3-1/2*v^2"],
		"Umin":["-2"] , "Umax":["2"],
		"Vmin":["-2"] , "Vmax":["2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Helicoidal"],
		"Component": ["Helicoidal"],
		"Fx":["sinh(v)*sin(u)"],
		"Fy":["-sinh(v)*cos(u)"],
		"Fz":["3*u"],
		"Umin":["-pi"] , "Umax":["pi"],
		"Vmin":["-pi"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Cresent"],
		"Component": ["Cresent"],
		"Fx":["(2+sin(2*pi*u)*sin(2*pi*v))*sin(3*pi*v)"],
		"Fy":["(2+sin(2*pi*u)*sin(2*pi*v))*cos(3*pi*v)"],
		"Fz":["cos(2*pi*u)*sin(2*pi*v)+4*v-2"],
		"Umin":["0"] , "Umax":["1"],
		"Vmin":["0"] , "Vmax":["1"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
        "Name":["HyperbolicHelicoid"],
        "Component": ["HyperbolicHelicoid"],
		"Fx":["(sinh(v)*cos(3*u))/(1+cosh(u)*cosh(v))"],
		"Fy":["(sinh(v)*sin(3*u))/(1+cosh(u)*cosh(v))"],
		"Fz":["(cosh(v)*sinh(u))/(1+cosh(u)*cosh(v))"],
		"Umin":["-pi"] , "Umax":["pi"],
		"Vmin":["-pi"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Roman"],
		"Component": ["Roman"],
		"Fx":["1/2*sin(2*u)*sin(v)^2"],
		"Fy":["1/2*sin(u)*cos(2*v)"],
		"Fz":["1/2*cos(u)*sin(2*v)"],
		"Umin":["0"] , "Umax":["pi"],
		"Vmin":["-pi/2"] , "Vmax":["pi/2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Snake"],
		"Component": ["Snake"],
		"Fx":["1.2*(1-v/(2*pi))*cos(3*v)*(1+cos(u))+3*cos(3*v)"],
		"Fy":["1.2*(1-v/(2*pi))*sin(3*v)*(1+cos(u))+3*sin(3*v)"],
		"Fz":["9*v/(2*pi)+1.2*(1-v/(2*pi))*sin(u)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Horn"],
		"Component": ["Horn"],
		"Fx":["(2+u*cos(v))*sin(2*pi*u)"],
		"Fy":["(2+u*cos(v))*cos(2*pi*u)+2*u"],
		"Fz":["u*sin(v)"],
		"Umin":["0"] , "Umax":["1"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Fresnel_1"],
		"Component": ["Fresnel_1"],
		"Fx":["cos(u)*cos(v)/(-2.*sqrt(0.965/3.-0.935/3.*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0.941/6.+0.374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1.309/6.*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1.221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0.965/3.-0.935/3.*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)+pi)/3.)+0.8)"],
		"Fy":["sin(u)*cos(v)/(-2.*sqrt(0.965/3.-0.935/3.*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0.941/6.+0.374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1.309/6.*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1.221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0.965/3.-0.935/3.*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)+pi)/3.)+0.8)"],
		"Fz":["sin(v)/(-2.*sqrt(0.965/3.-0.935/3.*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0.941/6.+0.374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1.309/6.*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1.221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0.965/3.-0.935/3.*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)+pi)/3.)+0.8)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["-pi/2"] , "Vmax":["pi/2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Steiner"],
		"Component": ["Steiner"],
		"Fx":["(sin(2*u)*cos(v)*cos(v))"],
		"Fy":["(sin(u)*sin(2*v))"],
		"Fz":["(cos(u)*sin(2*v))"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["-pi/2"] , "Vmax":["pi/2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Cross_cap"],
		"Component": ["Cross_cap"],
		"Fx":["(sin(u)*sin(2*v)/2)"],
		"Fy":["(sin(2*u)*cos(v)*cos(v))"],
		"Fz":["(cos(2*u)*cos(v)*cos(v))"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["-pi/2"] , "Vmax":["pi/2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Fresnel_2"],
		"Component": ["Fresnel_2"],
		"Fx":["cos(u)*cos(v)/(-2.*sqrt(0.965/3.-0.935/3.*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0.941/6.+0.374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1.309/6.*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1.221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0.965/3.-0.935/3.*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3.)+0.8)"],
		"Fy":["sin(u)*cos(v)/(-2.*sqrt(0.965/3.-0.935/3.*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0.941/6.+0.374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1.309/6.*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1.221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0.965/3.-0.935/3.*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3.)+0.8)"],
		"Fz":["sin(v)/(-2.*sqrt(0.965/3.-0.935/3.*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0.941/6.+0.374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1.309/6.*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1.221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0.965/3.-0.935/3.*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3.)+0.8)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["-pi/2"] , "Vmax":["pi/2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Cliffordtorus"],
		"Component": ["Cliffordtorus"],
		"Fx":["cos(u+v)/(sqrt(2.)+cos(v-u))"],
		"Fy":["sin(u+v)/(sqrt(2.)+cos(v-u))"],
		"Fz":["sin(v-u)/(sqrt(2.)+cos(v-u))"],
		"Umin":["0"] , "Umax":["pi"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Stereosphere"],
		"Component": ["Stereosphere"],
		"Fx":["2.*u/(u*u+v*v+1.)"],
		"Fy":["2.*v/(u*u+v*v+1.)"],
		"Fz":["(u*u+v*v-1.)/(u*u+v*v+1.)"],
		"Umin":["-2"] , "Umax":["2"],
		"Vmin":["-2"] , "Vmax":["2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Enneper_2"],
		"Component": ["Enneper_2"],
		"Fx":["u*cos(v)-u^3/3*cos(3*v)"],
		"Fy":["-u*sin(v)-u^(3)/3*sin(3*v)"],
		"Fz":["u^2*cos(2*v)"],
		"Umin":["0"] , "Umax":["1.2"],
		"Vmin":["-pi"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Maeder's_Owl"],
		"Component": ["Maeder's_Owl"],
		"Fx":["v*cos(u)-0.5*v^2*cos(2*u)"],
		"Fy":["-v*sin(u)-0.5*v^2*sin(2*u)"],
		"Fz":["4*v^1.5*cos(3*u/2)/3"],
		"Umin":["0"] , "Umax":["4*pi"],
		"Vmin":["0"] , "Vmax":["1"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Boy"],
		"Component": ["Boy"],
		"Fx":["2/3*(cos(u)*cos(2*v)+sqrt(2)*sin(u)*cos(v))*cos(u)/(sqrt(2)-sin(2*u)*sin(3*v))"],
		"Fy":["2/3*(cos(u)*sin(2*v)-sqrt(2)*sin(u)*sin(v))*cos(u)/(sqrt(2)-sin(2*u)*sin(3*v))"],
		"Fz":["sqrt(2)*cos(u)*cos(u)/(sqrt(2)-sin(2*u)*sin(3*v))"],
		"Umin":["0"] , "Umax":["pi"],
		"Vmin":["0"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Dini"],
		"Component": ["Dini"],
		"Fx":["cos(u)*sin(v)"],
		"Fy":["sin(u)*sin(v)"],
		"Fz":["(cos(v)+log(tan(v/2)))+0.2*u"],
		"Umin":["0"] , "Umax":["12.4"],
		"Vmin":["0.1"] , "Vmax":["2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["EightSurface"],
		"Component": ["EightSurface"],
		"Fx":["cos(u)*sin(2*v)"],
		"Fy":["sin(u)*sin(2*v)"],
		"Fz":["sin(v)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["-pi/2"] , "Vmax":["pi/2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Hellipticparaboloid"],
		"Component": ["Hellipticparaboloid"],
		"Fx":["v*2*cos(u)"],
		"Fy":["v*sin(u)"],
		"Fz":["v^2"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["0"] , "Vmax":["2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Plan"],
		"Component": ["Plan"],
		"Fx":["u"],
		"Fy":["0"],
		"Fz":["v"],
		"Umin":["-1"] , "Umax":["1"],
		"Vmin":["-1"] , "Vmax":["1"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Apple"],
		"Component": ["Apple"],
		"Fx":["cos(u)*(4+3.8*cos(v))"],
		"Fy":["sin(u)*(4+3.8*cos(v))"],
		"Fz":["(cos(v)+sin(v)-1)*(1+sin(v))*log(1-pi*v/10)+7.5*sin(v)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["-pi"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Drop"],
		"Component": ["Drop"],
		"Fx":["u*cos(v)"],
		"Fy":["u*sin(v)"],
		"Fz":["exp(-u*u)*(sin(2*pi*u)-u*cos(3*v))"],
		"Umin":["0"] , "Umax":["2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Cone"],
		"Component": ["Cone"],
		"Fx":["u*cos(v)"],
		"Fy":["u*sin(v)"],
		"Fz":["u"],
		"Umin":["-1"] , "Umax":["1"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Kinky_Torus"],
		"Component": ["Kinky_Torus"],
		"Fx":["1/cosh(u)-cos(v)"],
		"Fy":["sin(v)"],
		"Fz":["u/pi-tanh(v)"],
		"Umin":["-2*pi"] , "Umax":["2*pi"],
		"Vmin":["-pi"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Kidney"],
		"Component": ["Kidney"],
		"Fx":["cos(u)*(3*cos(v)-cos(3*v))"],
		"Fy":["sin(u)*(3*cos(v)-cos(3*v))"],
		"Fz":["3*sin(v)-sin(3*v)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["-pi/2"] , "Vmax":["pi/2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Triaxial_Hexatorus"],
		"Component": ["Triaxial_Hexatorus"],
		"Fx":["sin(u)/(sqrt(2)+cos(v))"],
		"Fy":["sin(u+2*pi/3)/(sqrt(2)+cos(v+2*pi/3))"],
		"Fz":["cos(u-2*pi/3)/(sqrt(2)+cos(v-2*pi/3))"],
		"Umin":["-pi"] , "Umax":["pi"],
		"Vmin":["-pi"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Limpet_Torus"],
		"Component": ["Limpet_Torus"],
		"Fx":["cos(u)/(sqrt(2)+sin(v))"],
		"Fy":["sin(u)/(sqrt(2)+sin(v))"],
		"Fz":["1/(sqrt(2)+cos(v))"],
		"Umin":["-pi"] , "Umax":["pi"],
		"Vmin":["-pi"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Twisted_Triaxial"],
		"Component": ["Twisted_Triaxial"],
		"Fx":["(1-sqrt(u*u+v*v)/sqrt(2*pi*pi))*cos(u)*cos(v)+sqrt(u*u+v*v)/sqrt(2*pi*pi)*sin(u)*sin(v)"],
		"Fy":["(1-sqrt(u*u+v*v)/sqrt(2*pi*pi))*cos(u+2*pi/3)*cos(v+2*pi/3)+sqrt(u*u+v*v)/sqrt(2*pi*pi)*sin(u+2*pi/3)*sin(v+2*pi/3)"],
		"Fz":["(1-sqrt(u*u+v*v)/sqrt(2*pi*pi))*cos(u+4*pi/3)*cos(v+4*pi/3)+sqrt(u*u+v*v)/sqrt(2*pi*pi)*sin(u+4*pi/3)*sin(v+4*pi/3)"],
		"Umin":["-pi"] , "Umax":["pi"],
		"Vmin":["-pi"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Snail"],
		"Component": ["Snail"],
		"Fx":["u*cos(v)*sin(u)"],
		"Fy":["u*cos(u)*cos(v)"],
		"Fz":["-u*sin(v)"],
		"Umin":["0"] , "Umax":["2"],
		"Vmin":["-pi/2"] , "Vmax":["pi/2"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Implicit_Lemniscape"],
		"Component": ["Implicit_Lemniscape"],
		"Fx":["cos(v)*sqrt(abs(sin(2*u)))*cos(u)"],
		"Fy":["cos(v)*sqrt(abs(sin(2*u)))*sin(u)"],
		"Fz":["(cos(v)*sqrt(abs(sin(2*u)))*cos(u))^2-(cos(v)*sqrt(abs(sin(2*u)))*sin(u))^2+2*(cos(v)*sqrt(abs(sin(2*u)))*cos(u))*(cos(v)*sqrt(abs(sin(2*u)))*sin(u))*(tan(v)^2)"],
		"Umin":["0"] , "Umax":["pi"],
		"Vmin":["0"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Bent_Horns"],
		"Component": ["Bent_Horns"],
		"Fx":["(2+cos(u))*(v/3-sin(v))"],
		"Fy":["(2+cos(u-2*pi/3))*(cos(v)-1)"],
		"Fz":["(2+cos(u+2*pi/3))*(cos(v)-1)"],
		"Umin":["-pi"] , "Umax":["pi"],
		"Vmin":["-2*pi"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Folium"],
		"Component": ["Folium"],
		"Fx":["cos(u)*(2*v/pi-tanh(v))"],
		"Fy":["cos(u+2*pi/3)/cosh(v)"],
		"Fz":["cos(u-2*pi/3)/cosh(v)"],
		"Umin":["-pi"] , "Umax":["pi"],
		"Vmin":["-pi"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Heart"],
		"Component": ["Heart"],
		"Fx":["cos(u)*(4*sqrt(1-v^2)*sin(abs(u))^abs(u))"],
		"Fy":["sin(u)*(4*sqrt(1-v^2)*sin(abs(u))^abs(u))"],
		"Fz":["v"],
		"Umin":["-pi"] , "Umax":["pi"],
		"Vmin":["-1"] , "Vmax":["1"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Cube"],
		"Component": ["Cube"],
		"Fx":["cos(u)*cos(v)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)*(abs(cos(4*v/4))^100+abs(sin(4*v/4))^100)^(-1/100)"],
		"Fy":["cos(u)*sin(v)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)*(abs(cos(4*v/4))^100+abs(sin(4*v/4))^100)^(-1/100)"],
		"Fz":["sin(u)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Prism"],
		"Component": ["Prism"],
		"Fx":["cos(u)*cos(v)*(abs(cos(3*v/4))^500+abs(sin(3*v/4))^500)^(-1/260)*(abs(cos(4*u/4))^200+abs(sin(4*u/4))^200)^(-1/200)"],
		"Fy":["cos(u)*sin(v)*(abs(cos(3*v/4))^500+abs(sin(3*v/4))^500)^(-1/260)*(abs(cos(4*u/4))^200+abs(sin(4*u/4))^200)^(-1/200)"],
		"Fz":["sin(u)*(abs(cos(4*u/4))^200+abs(sin(4*u/4))^200)^(-1/200)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Hexagon"],
		"Component": ["Hexagon"],
		"Fx":["cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000)"],
		"Fy":["cos(u)*sin(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000)"],
		"Fz":["sin(u)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Cone"],
		"Component": ["Cone"],
		"Fx":["u*cos(v)"],
		"Fy":["u*sin(v)"],
		"Fz":["u"],
		"Umin":["-1"] , "Umax":["1"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Diamond"],
		"Component": ["Diamond"],
		"Fx":["cos(u)*cos(v)*(abs(cos(4*u/4))^1+abs(sin(4*u/4))^1)^(-1/1)*(abs(cos(4*v/4))^1+abs(sin(4*v/4))^1)^(-1/1)"],
		"Fy":["cos(u)*sin(v)*(abs(cos(4*u/4))^1+abs(sin(4*u/4))^1)^(-1/1)*(abs(cos(4*v/4))^1+abs(sin(4*v/4))^1)^(-1/1)"],
		"Fz":["sin(u)*(abs(cos(4*u/4))^1+abs(sin(4*u/4))^1)^(-1/1)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Star"],
		"Component": ["Star"],
		"Fx":["cos(u)*cos(v)*(abs(cos(1*u/4))^0.5+abs(sin(1*u/4))^0.5)^(-1/0.3)*(abs(cos(5*v/4))^1.7+abs(sin(5*v/4))^1.7)^(-1/0.1)"],
		"Fy":["cos(u)*sin(v)*(abs(cos(1*u/4))^0.5+abs(sin(1*u/4))^0.5)^(-1/0.3)*(abs(cos(5*v/4))^1.7+abs(sin(5*v/4))^1.7)^(-1/0.1)"],
		"Fz":["sin(u)*(abs(cos(1*u/4))^0.5+abs(sin(1*u/4))^0.5)^(-1/0.3)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Star_7"],
		"Component": ["Star_7"],
		"Fx":["cos(u)*cos(v)*(abs(cos(7*v/4))^1.7+abs(sin(7*v/4))^1.7)^(-1/0.2)*(abs(cos(7*u/4))^1.7+abs(sin(7*u/4))^1.7)^(-1/0.2)"],
		"Fy":["cos(u)*sin(v)*(abs(cos(7*v/4))^1.7+abs(sin(7*v/4))^1.7)^(-1/0.2)*(abs(cos(7*u/4))^1.7+abs(sin(7*u/4))^1.7)^(-1/0.2)"],
		"Fz":["sin(u)*(abs(cos(7*u/4))^1.7+abs(sin(7*u/4))^1.7)^(-1/0.2)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Shape_8"],
		"Component": ["Shape_8"],
		"Fx":["cos(u)*cos(v)*(abs(cos(3*u/4))^100+abs(sin(3*u/4))^100)^(-1/100)*(abs(cos(2*v/4))^0.3+abs(sin(2*v/4))^0.2)^(-1/0.7)"],
		"Fy":["cos(u)*sin(v)*(abs(cos(3*u/4))^100+abs(sin(3*u/4))^100)^(-1/100)*(abs(cos(2*v/4))^0.3+abs(sin(2*v/4))^0.2)^(-1/0.7)"],
		"Fz":["sin(u)*(abs(cos(3*u/4))^100+abs(sin(3*u/4))^100)^(-1/100)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Shape_9"],
		"Component": ["Shape_9"],
		"Fx":["cos(u)*cos(v)*(abs(cos(2*u/4))^10+abs(sin(2*u/4))^10)^(-1/10)*(abs(cos(8*v/4))^100+abs(sin(8*v/4))^30)^(-1/60)"],
		"Fy":["cos(u)*sin(v)*(abs(cos(2*u/4))^10+abs(sin(2*u/4))^10)^(-1/10)*(abs(cos(8*v/4))^100+abs(sin(8*v/4))^30)^(-1/60)"],
		"Fz":["sin(u)*(abs(cos(2*u/4))^10+abs(sin(2*u/4))^10)^(-1/10)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Shape_10"],
		"Component": ["Shape_10"],
		"Fx":["cos(u)*cos(v)*(abs(cos(3*u/4))^1+abs(sin(3*u/4))^1)^(-1/1)*(abs(cos(6*v/4))^1+abs(sin(6*v/4))^1)^(-1/1)"],
		"Fy":["cos(u)*sin(v)*(abs(cos(3*u/4))^1+abs(sin(3*u/4))^1)^(-1/1)*(abs(cos(6*v/4))^1+abs(sin(6*v/4))^1)^(-1/1)"],
		"Fz":["sin(u)*(abs(cos(3*u/4))^1+abs(sin(3*u/4))^1)^(-1/1)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Sphere_1"],
		"Component": ["Sphere_1"],
		"Fx":["cos(u)*cos(v)"],
		"Fy":["cos(u)*sin(v)"],
		"Fz":["sin(u)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Sphere_2"],
		"Component": ["Sphere_2"],
		"Fx":["cos(u)*cos(v)"],
		"Fy":["cos(u)*sin(v)"],
		"Fz":["sin(u)*sin(v)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Sphere_3"],
		"Component": ["Sphere_3"],
		"Fx":["cos(u)*cos(v)"],
		"Fy":["cos(u)*sin(v)"],
		"Fz":["sin(u)*sin(v)*cos(v)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Sphere_4"],
		"Component": ["Sphere_4"],
		"Fx":["cos(u)*cos(v)"],
		"Fy":["cos(u)*sin(v)*sin(v)"],
		"Fz":["sin(u)*sin(v)"],
		"Umin":["-pi/2"] , "Umax":["0"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Sphere_5"],
		"Component": ["Sphere_5"],
		"Fx":["cos(u)*cos(v)*sin(v)"],
		"Fy":["cos(u)*sin(v)*sin(v)"],
		"Fz":["sin(u)*sin(v)"],
		"Umin":["-pi/2"] , "Umax":["0"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Sphere_6"],
		"Component": ["Sphere_6"],
		"Fx":["cos(u)*cos(v)*sin(u)"],
		"Fy":["sin(u)"],
		"Fz":["sin(u)*sin(v)*sin(u)"],
		"Umin":["-pi/2"] , "Umax":["0"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Sphere_7"],
		"Component": ["Sphere_7"],
		"Fx":["cos(u)*cos(v)*sin(u)"],
		"Fy":["sin(u)*sin(v)*cos(u)"],
		"Fz":["sin(u)*sin(v)*sin(u)"],
		"Umin":["-pi/2"] , "Umax":["0"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Sphere_8"],
		"Component": ["Sphere_8"],
		"Fx":["cos(u)*cos(v)*sin(u)"],
		"Fy":["cos(u)*sin(v)*cos(u)"],
		"Fz":["sin(u)*sin(v)*sin(u)"],
		"Umin":["-pi/2"] , "Umax":["0"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Sphere_9"],
		"Component": ["Sphere_9"],
		"Fx":["cos(u)*cos(v)*sin(u)"],
		"Fy":["cos(u)*sin(v)*cos(u)*sin(v)"],
		"Fz":["sin(u)*sin(v)*sin(u)*sin(v)"],
		"Umin":["-pi/2"] , "Umax":["0"],
		"Vmin":["0"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Sphere_10"],
		"Component": ["Sphere_10"],
		"Fx":["cos(u)*cos(v)*sin(u)*sin(v)*sin(v)*sin(v)"],
		"Fy":["cos(u)*sin(v)*cos(u)*sin(v)"],
		"Fz":["sin(u)*sin(v)*sin(u)*sin(v)*cos(u)"],
		"Umin":["-pi/2"] , "Umax":["0"],
		"Vmin":["0"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Curve"],
		"Component": ["Curve"],
		"Fx":["cos(2*u)"],
		"Fy":["sin(3*u)"],
		"Fz":["cos(u)"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["0"] , "Vmax":["0"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Helice_Curve"],
		"Component": ["Helice_Curve"],
		"Fx":["sin(u)"],
		"Fy":["cos(u)"],
		"Fz":["(u^2)/100"],
		"Umin":["0"] , "Umax":["6*pi"],
		"Vmin":["0"] , "Vmax":["0"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Pseudo_Sphere"],
		"Component": ["Pseudo_Sphere"],
		"Fx":["cos(u)*cos(v)+sin((sin(u)+1)*2*pi)"],
		"Fy":["cos(u)*sin(v)+cos((sin(u)+1)*2*pi)"],
		"Fz":["4*sin(u)"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Pseudo_Catenoid"],
		"Component": ["Pseudo_Catenoid"],
		"Fx":["2.2*(2*cosh(v/2)*cos(u))"],
		"Fy":["1.51166*(2*cosh(v/2)*sin(u)*cos((2.2*(2*cosh(v/2)*cos(u))--11.0404)*2*pi*1/22.0513)-1.8*(v)*sin((2.2*(2*cosh(v/2)*cos(u))--11.0404)*2*pi*1/22.0513))"],
		"Fz":["1.51166*(2*cosh(v/2)*sin(u)*sin((2.2*(2*cosh(v/2)*cos(u))--11.0404)*2*pi*1/22.0513)+1.8*(v)*cos((2.2*(2*cosh(v/2)*cos(u))--11.0404)*2*pi*1/22.0513))"],
		"Umin":["-pi"] , "Umax":["pi"],
		"Vmin":["-pi"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Pseudo_Helix"],
		"Component": ["Pseudo_Helix"],
		"Fx":["0.717627*((1-0.1*cos(v))*cos(u)*cos(((1-0.1*cos(v))*sin(u)--1.1)*2*pi*0.2/2.2)-0.1*(sin(v)+u/1.7-10)*sin(((1-0.1*cos(v))*sin(u)--1.1)*2*pi*0.2/2.2))"],
		"Fy":["(1-0.1*cos(v))*sin(u)"],
		"Fz":["0.717627*((1-0.1*cos(v))*cos(u)*sin(((1-0.1*cos(v))*sin(u)--1.1)*2*pi*0.2/2.2)+0.1*(sin(v)+u/1.7-10)*cos(((1-0.1*cos(v))*sin(u)--1.1)*2*pi*0.2/2.2))"],
		"Umin":["0"] , "Umax":["4*pi"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Pseudo_Cone"],
		"Component": ["Pseudo_Cone"],
		"Fx":["u*cos(v)"],
		"Fy":["0.848528*(u*sin(v)*cos((u*cos(v)--1)*2*pi*1/2)-u*sin((u*cos(v)--1)*2*pi*1/2))"],
		"Fz":["0.848528*(u*sin(v)*sin((u*cos(v)--1)*2*pi*1/2)+u*cos((u*cos(v)--1)*2*pi*1/2))"],
		"Umin":["-1"] , "Umax":["1"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Pseudo_Hexagon"],
		"Component": ["Pseudo_Hexagon"],
		"Fx":["1.7*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))"],
		"Fy":["0.743482*(1.5*(cos(u)*sin(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))*cos((1.7*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))--1.7)*2*pi*0.3/3.4)-0.7*(sin(u)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300))*sin((1.7*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))--1.7)*2*pi*0.3/3.4))"],
		"Fz":["0.743482*(1.5*(cos(u)*sin(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))*sin((1.7*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))--1.7)*2*pi*0.3/3.4)+0.7*(sin(u)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300))*cos((1.7*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))--1.7)*2*pi*0.3/3.4))"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Pseudo_Cube"],
		"Component": ["Pseudo_Cube"],
		"Fx":["0.848528*(cos(u)*cos(v)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)*(abs(cos(4*v/4))^100+abs(sin(4*v/4))^100)^(-1/100)*cos((1.6*(sin(u)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100))--1.6)*2*pi*0.3/3.2)-cos(u)*sin(v)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)*(abs(cos(4*v/4))^100+abs(sin(4*v/4))^100)^(-1/100)*sin((1.6*(sin(u)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100))--1.6)*2*pi*0.3/3.2))"],
		"Fy":["0.848528*(cos(u)*cos(v)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)*(abs(cos(4*v/4))^100+abs(sin(4*v/4))^100)^(-1/100)*sin((1.6*(sin(u)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100))--1.6)*2*pi*0.3/3.2)+cos(u)*sin(v)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)*(abs(cos(4*v/4))^100+abs(sin(4*v/4))^100)^(-1/100)*cos((1.6*(sin(u)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100))--1.6)*2*pi*0.3/3.2))"],
		"Fz":["1.6*(sin(u)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100))"],
		"Umin":["-pi/2"] , "Umax":["pi/2"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Pseudo_Torus"],
		"Component": ["Pseudo_Torus"],
		"Fx":["(1+0.5*cos(u))*cos(v)"],
		"Fy":["0.632456*((1+0.5*cos(u))*sin(v)*cos(((1+0.5*cos(u))*cos(v)--1.5)*2*pi*0.9/3)-0.5*sin(u)*sin(((1+0.5*cos(u))*cos(v)--1.5)*2*pi*0.9/3))"],
		"Fz":["0.632456*((1+0.5*cos(u))*sin(v)*sin(((1+0.5*cos(u))*cos(v)--1.5)*2*pi*0.9/3)+0.5*sin(u)*cos(((1+0.5*cos(u))*cos(v)--1.5)*2*pi*0.9/3))"],
		"Umin":["0"] , "Umax":["2*pi"],
		"Vmin":["0"] , "Vmax":["2*pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Hurricane"],
		"Component": ["Hurricane"],
		"Fx":["1*(2*cosh(v/2)*cos(u)*cos((2.1*(2*cosh(v/2)*sin(u)*sin((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367)+2*(v)*cos((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367))--13.1947)*2*pi*1.5/26.3894)-2.1*(2*cosh(v/2)*sin(u)*cos((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367)-2*(v)*sin((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367))*sin((2.1*(2*cosh(v/2)*sin(u)*sin((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367)+2*(v)*cos((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367))--13.1947)*2*pi*1.5/26.3894))"],
		"Fy":["1*(2*cosh(v/2)*cos(u)*sin((2.1*(2*cosh(v/2)*sin(u)*sin((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367)+2*(v)*cos((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367))--13.1947)*2*pi*1.5/26.3894)+2.1*(2*cosh(v/2)*sin(u)*cos((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367)-2*(v)*sin((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367))*cos((2.1*(2*cosh(v/2)*sin(u)*sin((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367)+2*(v)*cos((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367))--13.1947)*2*pi*1.5/26.3894))"],
		"Fz":["2.1*(2*cosh(v/2)*sin(u)*sin((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367)+2*(v)*cos((2*cosh(v/2)*cos(u)--5.01836)*2*pi*0/10.0367))"],
		"Umin":["-pi"] , "Umax":["pi"],
		"Vmin":["-pi"] , "Vmax":["pi"]
		}},

		{"Param3D":
		{
		"Description":["Descriptionofthemodel"],
		"Name":["Breather"],
		"Component": ["Breather"],
		"Fx":["(2*sqrt(0.84)*cosh(0.4*u)*(-(sqrt(0.84)*cos(v)*cos(sqrt(0.84)*v))-sin(v)*sin(sqrt(0.84)*v)))/(0.4*((sqrt(0.84)*cosh(0.4*u))^2+(0.4*sin(sqrt(0.84)*v))^2))"],
		"Fy":["(2*sqrt(0.84)*cosh(0.4*u)*(-(sqrt(0.84)*sin(v)*cos(sqrt(0.84)*v))+cos(v)*sin(sqrt(0.84)*v)))/(0.4*((sqrt(0.84)*cosh(0.4*u))^2+(0.4*sin(sqrt(0.84)*v))^2))"],
		"Fz":["-u+(2*0.84*cosh(0.4*u)*sinh(0.4*u))/(0.4*((sqrt(0.84)*cosh(0.4*u))^2+(0.4*sin(sqrt(0.84)*v))^2))"],
		"Umin":["-13.2"] , "Umax":["13.2"],
		"Vmin":["-37.4"] , "Vmax":["37.4"]
		}
		},
{
    "Param3D": {
	"Description":[
		"Making'Thick'parametricsurfaces: Wecangivesomethicknesstoaparametricsurface(F)bydefiningasecondparametricsurface(G)withtheformula: 'Gx': ('Fx(u,
			v,
			t)+T*n1(u,
			v,
			t)/R(u,
			v,
			t)')'Gy': ('Fy(u,
			v,
			t)+T*n2(u,
			v,
			t)/R(u,
			v,
			t)')'Gz': ('Fz(u,
			v,
			t)+T*n3(u,
			v,
			t)/R(u,
			v,
			t)')WhereT=Thicknessvalue;'n1=(a2(u,
			v,
			t)*b3(u,
			v,
			t)-a3(u,
			v,
			t)*b2(u,
			v,
			t))',
			'n2=(a3(u,
			v,
			t)*b1(u,
			v,
			t)-a1(u,
			v,
			t)*b3(u,
			v,
			t))',
			'n3=(a1(u,
			v,
			t)*b2(u,
			v,
			t)-a2(u,
			v,
			t)*b1(u,
			v,
			t))',
			'R=sqrt(n1(u,
			v,
			t)^2+n2(u,
			v,
			t)^2+n3(u,
			v,
			t)^2)''a1=dFx/du',
			'a2=dFy/du',
			'a3=dFz/du',
			'b1=dFx/dv',
			'b2=dFy/dv',
			'b3=dFz/dv'"
		],
        "Name": [
            "ThickParametricTorus"
        ],
        "Component": [
            "Torus_1",
            "Torus_2"
        ],
        "Const": [
            "T=1.3"
        ],
        "Funct": [
            "Fx=(1+0.5*cos(u))*cos(v)",
            "Fy=(1+0.5*cos(u))*sin(v)",
            "Fz=0.5*sin(u)",
            "a1=(-0.5*sin(u)*cos(v))",
            "a2=(-0.5*sin(u)*sin(v))",
            "a3=(0.5*cos(u))",
            "b1=(-(1+0.5*cos(u))*sin(v))",
            "b2=((1+0.5*cos(u))*cos(v))",
            "b3=0",
            "n1=(a2(u,
			v,
			t)*b3(u,
			v,
			t)-a3(u,
			v,
			t)*b2(u,
			v,
			t))",
            "n2=(a3(u,
			v,
			t)*b1(u,
			v,
			t)-a1(u,
			v,
			t)*b3(u,
			v,
			t))",
            "n3=(a1(u,
			v,
			t)*b2(u,
			v,
			t)-a2(u,
			v,
			t)*b1(u,
			v,
			t))",
            "R=sqrt(n1(u,
			v,
			t)^2+n2(u,
			v,
			t)^2+n3(u,
			v,
			t)^2)",
            "Gx=Fx(u,
			v,
			t)+T*n1(u,
			v,
			t)/R(u,
			v,
			t)",
            "Gy=Fy(u,
			v,
			t)+T*n2(u,
			v,
			t)/R(u,
			v,
			t)",
            "Gz=Fz(u,
			v,
			t)+T*n3(u,
			v,
			t)/R(u,
			v,
			t)"
        ],
        "Fx": [
            "Fx(u,
			v,
			t)",
            "Gx(u,
			v,
			t)"
        ],
        "Fy": [
            "Fy(u,
			v,
			t)",
            "Gy(u,
			v,
			t)"
        ],
        "Fz": [
            "Fz(u,
			v,
			t)",
            "Gz(u,
			v,
			t)"
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
            "pi/3",
            "pi/3"
        ]
    }
},
{
    "Param3D": {
        "Name": [
            "HelicoidCatenoid"
        ],
        "Component": [
            "HelicoidCatenoid"
        ],
        "Fx": [
            "cos(2*t*pi)*sinh(v)*sin(u)+sin(2*t*pi)*cosh(v)*cos(u)"
        ],
        "Fy": [
            "-cos(2*t*pi)*sinh(v)*cos(u)+sin(2*t*pi)*cosh(v)*sin(u)"
        ],
        "Fz": [
            "3*(u*cos(2*t*pi)+v*sin(2*t*pi))"
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
        "Name": [
            "Shells"
        ],
        "Component": [
            "Shell1",
            "Shell2",
            "Shell3",
            "Shell4"
        ],
        "Const": [
            "a=0.2",
            "b=1",
            "c=0.1",
            "n=2"
        ],
        "Fx": [
            "2*(1-exp(u/(6*pi)))*cos(u)*cos(v/2)^2",
            "((a*(1-v/(2*pi))*(1+cos(u))+c)*cos(n*v))*6+4",
            "2^v*(sin(u)*cos(u))/35",
            "1.2^v*(sin(u)^2*sin(v))+2"
        ],
        "Fy": [
            "2*(-1+exp(u/(6*pi)))*sin(u)*cos(v/2)^2",
            "((a*(1-v/(2*pi))*(1+cos(u))+c)*sin(n*v))*6+4",
            "2^v*(sin(u)^2*sin(v))/35-4",
            "1.2^v*(sin(u)*cos(u))+5"
        ],
        "Fz": [
            "1-exp(u/(3*pi))-sin(v)+exp(u/(6*pi))*sin(v)",
            "(b*v/(2*pi)+a*(1-v/(2*pi))*sin(u))*6-6",
            "2^v*(sin(u)^2*cos(v))/35-12",
            "1.2^v*(sin(u)^2*cos(v))-12"
        ],
        "Umax": [
            "6*pi",
            "2*pi",
            "pi",
            "pi"
        ],
        "Umin": [
            "0",
            "0",
            "0",
            "0"
        ],
        "Vmax": [
            "2*pi",
            "2*pi",
            "5*pi/2",
            "5*pi/2"
        ],
        "Vmin": [
            "0",
            "0",
            "0",
            "0"
        ]
    }
},
{
    "Iso3D": {
        "Name": [
            "ModelsIntersection"
        ],
        "Cnd": [
            "((x^2+y^2)>.4)&(x-y-1.5*z<0)",
            "1>0",
            "1>0"
        ],
        "Component": [
            "Schwarz",
            "Cylinder",
            "Plan"
        ],
        "Fxyz": [
            "cos(x-4*sin(t*pi))+cos(y)+cos(z)",
            "-(x^2+y^2)+.39",
            "x-y-1.5*z-.01"
        ],
        "Xmax": [
            "4+4*sin(t*pi)",
            "4",
            "6"
        ],
        "Xmin": [
            "-4+4*sin(t*pi)",
            "-4",
            "-6"
        ],
        "Ymax": [
            "4",
            "4",
            "6"
        ],
        "Ymin": [
            "-4",
            "-4",
            "-6"
        ],
        "Zmax": [
            "4",
            "4",
            "6"
        ],
        "Zmin": [
            "-4",
            "-4",
            "-6"
        ]
    }
}
],
"TexturesList":[
{
	"Texture":{
		"Name": "Lines1",
		"Colors":[
			"R=cos(7*x*pi)*cos(z*pi)",
			"G=cos(7*y*pi)*cos(x*pi)",
			"B=cos(7*y*pi)*cos(z*pi)",
			"T=1"]
	}
},
{
	"Texture":{
		"Name": "Lines2",
		"Colors":[
			"R=sin(7*x*pi)",
			"G=sin(7*y*pi)",
			"B=cos(7*z*pi)",
			"T=1"]
	}
},
{
	"Texture":{
		"Name": "Lines3",
		"Colors":[
			"R=cos(7*x*pi)*sin(z*pi)",
			"G=sin(x*pi)*cos(7*y*pi)",
			"B=sin(y*pi)*cos(7*z*pi)",
			"T=1"]
	}
},
{
	"Texture":{
		"Name": "Lines4",
		"Colors":[
			"R=cos(7*x*y*pi)",
			"G=sin(7*y*z*pi)",
			"B=sin(7*z*x*pi)",
			"T=1"]
	}
},
{
    "Texture": {
        "Colors": [
            "R=cos(2*x*y*pi)",
            "G=sin(2*y*z*pi)",
            "B=sin(2*z*x*pi)",
            "T=1.0"],
            "Name": "Lines5"
        }
},
{
    "Texture": {
        "Colors": [
            "R=cos((x*x+y*y+z*z)*pi)",
            "G=cos((x*x+y*y+z*z)*pi)*cos(x*pi)",
            "B=sin(y*pi)*cos(x*pi)",
            "T=1"
        ],
        "Name": "Lines6"
    }
},
{
    "Texture": {
        "Colors": [
            "R=cos((x*x+y*y+z*z)*pi)*sin(x*pi)",
            "G=cos((x*x+y*y+z*z)*pi)*sin(y*pi)",
            "B=cos((x*x+y*y+z*z)*pi)*sin(z*pi)",
            "T=1"
        ],
        "Name": "Lines7"
    }
},
{
    "Texture": {
        "Colors": [
            "R=cos((x*x+y*y)*pi)*cos(x*pi)",
            "G=cos((y*y+z*z)*pi)*cos(y*pi)",
            "B=cos((x*x+z*z)*pi)*cos(z*pi)",
            "T=1"
        ],
        "Name": "Lines8"
    }
},
{
    "Texture": {
        "Colors": [
            "R=(int(abs(x))+int(abs(y))+int(abs(z)))%2",
            "G=.1",
            "B=1",
            "T=1"
        ],
        "Name": "Checker"
    }
},
{
    "Texture": {
        "Colors": [
            "R=1",
            "G=0.6*abs(cos(6*z*y*x*y*pi))",
            "B=0.5+0.3*abs(cos(6*z*z*x*y*pi))",
            "T=1"
        ],
        "Name": "Granit_1"
    }
},
{
    "Texture": {
        "Colors": [
            "R=1",
            "G=0.9*abs(cos(pi*(x*x+y*y+z*z)))",
            "B=0.5+0.2*abs(cos(3*cos(pi*(x*x+y*y+z*z))))",
            "T=1"
        ],
        "Name": "Granit_2"
    }
},
{
    "Texture": {
        "Colors": [
            "R=.41",
            "G=0.81*abs(cos(x*x+y*y+z*z)*sin(x*x+y*y+z*z))",
            "B=0.8601*abs(cos(x*x+y*y+z*z)*cos(x*x+y*y+z*z)*sin(x*x+y*y+z*z))",
            "T=1"
        ],
        "Name": "Granit_3"
    }
},
{
    "Texture": {
        "Colors": [
            "R=2*.41",
            "G=2*0.81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
            "B=2*0.8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
            "T=1"
        ],
        "Name": "Granit_4"
    }
}


],
    "PigmentsList":[
    {


    "Pigment": {
		"Name": "Pigment_1",
        "Colors": [
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=.20",
                        "R=.4",
                        "G=.4",
                        "B=.70",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0.3",
                        "R=1",
                        "G=.1",
                        "B=.31",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0.6",
                        "R=.51",
                        "G=.17",
                        "B=1",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0.6",
                        "R=1",
                        "G=0.3",
                        "B=.1",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=1",
                        "R=.915",
                        "G=.17",
                        "B=.1",
                        "A=1"
                    ]
                }
            }
        ],
        "Gradient": "3*cos((x*x+y*y)*pi)*sin((y*y+z*z)*pi)"
    }
},

{
        "Pigment": {
			"Name": "Pigment_2",
            "Colors": [
                {
                    "Color": {
                        "Name": "Red",
                        "Vrgba": [
                            "V=.20",
                            "R=.90",
                            "G=.9",
                            "B=.40",
                            "A=1"
                        ]
                    }
                },
                {
                    "Color": {
                        "Name": "Red",
                        "Vrgba": [
                            "V=0.3",
                            "R=1",
                            "G=.1",
                            "B=.31",
                            "A=1"
                        ]
                    }
                },
                {
                    "Color": {
                        "Name": "Red",
                        "Vrgba": [
                            "V=0.6",
                            "R=1",
                            "G=.7",
                            "B=1",
                            "A=1"
                        ]
                    }
                },
                {
                    "Color": {
                        "Name": "Red",
                        "Vrgba": [
                            "V=0.6",
                            "R=1",
                            "G=0.3",
                            "B=.1",
                            "A=1"
                        ]
                    }
                },
                {
                    "Color": {
                        "Name": "Red",
                        "Vrgba": [
                            "V=1",
                            "R=.15",
                            "G=.6",
                            "B=.1",
                            "A=1"
                        ]
                    }
                }
            ],
            "Gradient": "3*atan((x*x *y*z)*pi)*cos(y*y*z*pi)"
        }
    },
     {
        "Pigment": {
			"Name": "Pigment_3",
            "Colors": [
                {
                    "Color": {
                        "Name": "Red",
                        "Vrgba": [
                            "V=0.0",
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
                        "Vrgba": [
                            "V=0.2",
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
                        "Vrgba": [
                            "V=0.5",
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
                        "Vrgba": [
                            "V=0.7",
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
                        "Vrgba": [
                            "V=1.0",
                            "R=1",
                            "G=0",
                            "B=0",
                            "A=1"
                        ]
                    }
                }
            ],
            "Gradient": "sin(x*30) + sin(y*30)"
        }
   },
   {
    "Pigment": {
       "Name": "Pigment_4",
        "Colors": [
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=.20",
                        "R=1.",
                        "G=.85",
                        "B=.40",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0.3",
                        "R=1",
                        "G=.1",
                        "B=.31",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0.6",
                        "R=.31",
                        "G=.31",
                        "B=1",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0.6",
                        "R=1",
                        "G=0.3",
                        "B=.1",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=1",
                        "R=.4",
                        "G=.6",
                        "B=.1",
                        "A=1"
                    ]
                }
            }
        ],
        "Gradient": "7*cos(pi*(x*x +y *y))*cos(y*z)*cos(pi*(y*y * x*x))*cos((z*z + x*x)*pi) *(cos(x) * sin(y) * cos(y) * sin(z*z + x*y) - cos(z) * sin(x))"
    }
   } ,
   {
            "Pigment": {
                "Colors": [
                    {
                        "Color": {
                            "Name": "Red",
                            "Vrgba": [
                                "V=.40",
                                "R=1.",
                                "G=.85",
                                "B=.40",
                                "A=1"
                            ]
                        }
                    },
                    {
                        "Color": {
                            "Name": "Red",
                            "Vrgba": [
                                "V=0.5",
                                "R=1",
                                "G=.1",
                                "B=.31",
                                "A=1"
                            ]
                        }
                    },
                    {
                        "Color": {
                            "Name": "Red",
                            "Vrgba": [
                                "V=0.5",
                                "R=.31",
                                "G=.31",
                                "B=1",
                                "A=1"
                            ]
                        }
                    },
                    {
                        "Color": {
                            "Name": "Red",
                            "Vrgba": [
                                "V=0.7",
                                "R=1",
                                "G=0.3",
                                "B=.1",
                                "A=1"
                            ]
                        }
                    },
                    {
                        "Color": {
                            "Name": "Red",
                            "Vrgba": [
                                "V=1",
                                "R=.4",
                                "G=.6",
                                "B=.1",
                                "A=1"
                            ]
                        }
                    }
                ],
                "Gradient": "3*cos(x*x +y *y)*cos(y*z- y*x)*(cos(x*y*z) + sin(x*y*z))",
                "Name": "Pigment_4"
            }
        }
]
}
