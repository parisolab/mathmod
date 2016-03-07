{
	"MathModels": [{
		"Iso3D": {
			"Name": ["Schwarz"],
			"Component": ["Schwarz"],
			"Fxyz": [" cos(x) + cos(y) + cos(z)"],
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
			"Colors": ["R=$DOT$82",
			"G=1$DOT$62*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"B=1$DOT$72*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"T=1"],
			"Noise": "NoiseP(x,y,z,4,1$DOT$1,1)",
			"Name": "Granit_4"
		},
		"Iso3D": {
			"Name": ["SchwarzFunction"],
			"Component": [" SchwarzFunction"],
			"Funct": [" Schwarz1=cos(x) + cos(y) + cos(z)"],
			"Fxyz": [" Schwarz1(x,y,z,t)"],
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
			"Name": ["Moon"],
			"Component": ["GravityPlan",
			"EarthPlanet",
			"MoonPlanet"],
			"Fxyz": ["((x-4*sin(t*pi/3))*(x-4*sin(t*pi/3)) + (y-2*cos(t*pi/3))*(y-2*cos(t*pi/3)) + z*z - $DOT$6)*min( (x-4*sin(t*pi/3))*(x-4*sin(t*pi/3)) + (y-2*cos(t*pi/3))*(y-2*cos(t*pi/3))  + z*z - $DOT$6, z) +0$DOT$2",
			"(x-4*sin(t*pi/3))*(x-4*sin(t*pi/3)) + (y-2*cos(t*pi/3))*(y-2*cos(t*pi/3))  + (z-$DOT$2)*(z-$DOT$2) - $DOT$6 ",
			"(x-2*sin(t*pi)-4*sin(t*pi/3))*(x-2*sin(t*pi)-4*sin(t*pi/3)) + (y-2*cos(t*pi)-2*cos(t*pi/3))*(y-2*cos(t*pi)-2*cos(t*pi/3)) + (z-$DOT$2)*(z-$DOT$2) - $DOT$1"],
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
			"1$DOT$5",
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
			"Name": ["Moon2"],
			"Component": ["GravityPlan",
			"EarthPlanet",
			"MoonPlanet"],
			"Varu": [" A=(u-4*sin(tm*pi/10))^2",
			" B=(u-2*cos(tm*pi/10))^2",
			"C=(u-2*sin(tm*pi)-4*sin(tm*pi/10))^2",
			" D=(u-2*cos(tm*pi)-2*cos(tm*pi/10))^2"],
			"Fxyz": ["(Ax + By+ z*z - $DOT$6)*min( Ax + By  + z*z - $DOT$6, z) +0$DOT$2",
			"Ax+ By + (z-$DOT$2)*(z-$DOT$2) - $DOT$6 ",
			"Cx + Dy  + (z-$DOT$2)*(z-$DOT$2) - $DOT$1"],
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
			"1$DOT$10",
			"1"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Moon3"],
			"Component": ["GravityPlan",
			"EarthPlanet",
			"MoonPlanet"],
			"Fxyz": ["((x-4*sin((0$DOT$521*t)*pi/3$DOT$11))^2 + (y-2*cos((0$DOT$521*t)*pi/3$DOT$11))^2+ z*z - $DOT$6)*min( (x-4*sin((0$DOT$521*t)*pi/3$DOT$11))^2+ (y-2*cos((0$DOT$521*t)*pi/3$DOT$11))^2 + z*z - $DOT$6, z) +0$DOT$2",
			"(x-4*sin((0$DOT$521*t)*pi/3$DOT$11))^2+ (y-2*cos((0$DOT$521*t)*pi/3$DOT$11))^2  + (z-$DOT$2)*(z-$DOT$2) - $DOT$6 ",
			"(x-2*sin((0$DOT$521*t)*pi)-4*sin((0$DOT$521*t)*pi/3$DOT$11))^2 + (y-2*cos((0$DOT$521*t)*pi)-2*cos((0$DOT$521*t)*pi/3$DOT$11))^2 + (z-$DOT$2)*(z-$DOT$2) - $DOT$05"],
			"Xmax": [" 5",
			"1+4*sin((0$DOT$521*t)*pi/3$DOT$11)",
			"1+2*sin((0$DOT$521*t)*pi)+4*sin((0$DOT$521*t)*pi/3$DOT$11)"],
			"Xmin": ["-5",
			"-1+4*sin((0$DOT$521*t)*pi/3$DOT$11)",
			"-1+2*sin((0$DOT$521*t)*pi)+4*sin((0$DOT$521*t)*pi/3$DOT$11)"],
			"Ymax": [" 4",
			"1+2*cos((0$DOT$521*t)*pi/3$DOT$11)",
			"1+2*cos((0$DOT$521*t)*pi)+2*cos((0$DOT$521*t)*pi/3$DOT$11)"],
			"Ymin": ["-4",
			"-1+2*cos((0$DOT$521*t)*pi/3$DOT$11)",
			"-1+2*cos((0$DOT$521*t)*pi)+2*cos((0$DOT$521*t)*pi/3$DOT$11)"],
			"Zmax": [" 1",
			"1$DOT$5",
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
			"Name": ["BlackHole"],
			"Component": [" GravityPlan",
			" EarthPlanet",
			" MoonPlanet",
			" WhiteStar "],
			"Varu": ["A=(u-4*sin(tm*pi/10))^2",
			"B=(u-2*cos(tm*pi/10))^2",
			"C=(u-2*sin(tm*pi)-4*sin(tm*pi/10))^2",
			"D=(u-2*cos(tm*pi)-2*cos(tm*pi/10))^2",
			"E=(u-$DOT$2)*(u-$DOT$2) - $DOT$6 ",
			"F =u*u - $DOT$6",
			"H=u*cos(2*tm*pi)",
			"G=u*sin(2*tm*pi)"],
			"Grid": [" 20",
			"20",
			"20",
			"20"],
			"Fxyz": ["(1$DOT$5*(Hx-Gy)^2 + (Gx+ Hy)^2 +(z+$DOT$8)^2 -(abs(2$DOT$2*sin(t*pi/10))))*(Ax + By+ Fz)*min( (1$DOT$5*(Hx-Gy)^2 + (Gx+ Hy)^2 +(z+$DOT$8)^2 -(abs(2$DOT$2*sin(t*pi/10))))*(Ax + By + Fz), z) +1$DOT$",
			"Ax+ By + Ez",
			"Cx + Dy  + Ez + $DOT$5",
			"1$DOT$5*(x*cos(2*t*pi) -y*sin(2*t*pi))^2 + (x*sin(2*t*pi) + y*cos(2*t*pi))^2 +(z+$DOT$2)^2 -(abs($DOT$2*sin(t*pi/10)+$DOT$05))"],
			"Xmin": ["-5",
			"-1+4*sin(t*pi/10)",
			"-1+2*sin(t*pi)+4*sin(t*pi/10)",
			" -$DOT$5"],
			"Xmax": ["5",
			"1+4*sin(t*pi/10)",
			"1+2*sin(t*pi)+4*sin(t*pi/10)",
			" $DOT$5"],
			"Ymin": ["-4",
			"-1+2*cos(t*pi/10)",
			"-1+2*cos(t*pi)+2*cos(t*pi/10)",
			" -$DOT$5"],
			"Ymax": ["4",
			"1+2*cos(t*pi/10)",
			"1+2*cos(t*pi)+2*cos(t*pi/10)",
			" $DOT$5"],
			"Zmin": ["-2",
			"-1",
			"-1",
			" -$DOT$7"],
			"Zmax": ["1",
			"1$DOT$10",
			"1",
			"$DOT$5"]
		}
	},
	{
		"Iso3D": {
			"Name": ["FallingDrop"],
			"Component": ["fallingdrop"],
			"Fxyz": ["-((z-6*(1-cos(sqrt(x^2+y^2)-t*2*pi))/sqrt(x^2+y^2+4))*(2*(x^2+y^2)+(z-40*sin((t+0$DOT$19)*pi)+1)^2-10)-1000)"],
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
					"Vrgba": ["V=$DOT$20",
					"R=$DOT$90",
					"G=$DOT$9",
					"B=$DOT$40",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0$DOT$3",
					"R=1",
					"G=$DOT$1",
					"B=$DOT$31",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0$DOT$6",
					"R=1",
					"G=$DOT$7",
					"B=1",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0$DOT$6",
					"R=1",
					"G=0$DOT$3",
					"B=$DOT$1",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0$DOT$8",
					"R=$DOT$15",
					"G=$DOT$6",
					"B=$DOT$1",
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
			"Varu": ["A = ((abs(u-2/3) <1/81)+ (abs(u-20/27) <1/81)+ (abs(u-16/27) <1/81)+(abs(u-8/9) <1/81) + (abs(u-26/27) <1/81) + (abs(u-22/27) <1/81) +(abs(u-4/9) <1/81) +(abs(u-14/27) <1/81) +(abs(u-10/27) <1/81) +(abs(u+2/3) <1/81) +(abs(u+16/27) <1/81) +(abs(u+20/27) <1/81) +(abs(u+4/9) <1/81) +(abs(u+10/27) <1/81) +(abs(u+14/27) <1/81) +(abs(u+8/9) <1/81) +(abs(u+22/27) <1/81) +(abs(u+26/27) <1/81) +(abs(u) <1/81) + (abs(u-2/27) <1/81) +(abs(u+2/27) <1/81) +(abs(u-2/9) <1/81) + (abs(u-8/27) <1/81) + (abs(u-4/27) <1/81) +(abs(u+2/9) <1/81)+(abs(u+4/27) <1/81)+(abs(u+8/27) <1/81))",
			"B = ((abs(u-2/3) <1/27)+(abs(u-8/9) <1/27) + (abs(u-4/9) <1/27) +(abs(u+2/3) <1/27) +(abs(u+4/9) <1/27) + (abs(u+8/9) <1/27) +(abs(u) <1/27) + (abs(u-2/9) <1/27) + (abs(u+2/9) <1/27))",
			"C = ((abs(u-2/3) <1/9) + (abs(u+2/3) <1/9) + (abs(u) <1/9))",
			"D = u^100"],
			"Fxyz": ["-(Dx + Dy + Dz -1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*((Cx*(Cy+Cz) + Cz*Cy) =0)*((Bx*(By+Bz)+Bz*By) =0)*((Ax*(Ay+Az)+Az*Ay)=0))"],
			"Xmin": ["-1$DOT$001"],
			"Xmax": [" 1$DOT$001"],
			"Ymin": ["-1$DOT$001"],
			"Ymax": [" 1$DOT$001"],
			"Zmin": ["-1$DOT$001"],
			"Zmax": [" 1$DOT$001"]
		}
	},
	{
		"Iso3D": {
			"Name": ["MengerSpongeSubdivision"],
		"Varu": ["A = ((abs(u-2/3) <1/81)+ (abs(u-20/27) <1/81)+ (abs(u-16/27) <1/81)+
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
			"Xmin": ["-1$DOT$001",
			" -1$DOT$001 ",
			" -1$DOT$001",
			"   -1$DOT$001",
			"  0$DOT$000",
			"  0$DOT$000",
			"  0$DOT$000",
			"  0$DOT$000"],
			"Xmax": ["   0$DOT$000 ",
			"   0$DOT$000",
			"  0$DOT$000",
			" 0$DOT$000",
			" 1$DOT$001",
			" 1$DOT$001",
			" 1$DOT$001",
			" 1$DOT$001"],
			"Ymin": ["-1$DOT$001",
			" -1$DOT$001",
			"  0$DOT$000",
			"  0$DOT$000",
			" -1$DOT$001",
			" -1$DOT$001",
			"  0$DOT$000",
			"  0$DOT$000 "],
			"Ymax": ["  0$DOT$000 ",
			"  0$DOT$000",
			" 1$DOT$001",
			" 1$DOT$001",
			"  0$DOT$000 ",
			"  0$DOT$000",
			" 1$DOT$001",
			" 1$DOT$001"],
			"Zmin": ["-1$DOT$001",
			" 0$DOT$000 ",
			" -1$DOT$001",
			"  0$DOT$000",
			" -1$DOT$001",
			" 0$DOT$000 ",
			" -1$DOT$001",
			"  0$DOT$000 "],
			"Zmax": ["   0$DOT$000 ",
			" 1$DOT$001",
			"  0$DOT$000",
			" 1$DOT$001",
			" 0$DOT$000 ",
			" 1$DOT$001",
			"  0$DOT$000",
			" 1$DOT$001"]
		}
	},
	{
		"Iso3D": {
			"Name": ["BouncingBall"],
			"Component": ["Ball",
			"Plan"],
			"Fxyz": ["(x-4*sin((0$DOT$521*t)*pi/3$DOT$11))^2+(y-2*cos((0$DOT$521*t)*pi/3$DOT$11))^2+(z-3*abs(cos((5*t)*pi/3$DOT$11)))^2-$DOT$6",
			"z+$DOT$6"],
			"Grid": ["20",
			"20"],
			"Xmax": ["1+4*sin((0$DOT$521*t)*pi/3$DOT$11)",
			"4"],
			"Xmin": ["-1+4*sin((0$DOT$521*t)*pi/3$DOT$11)",
			"-4"],
			"Ymax": ["1+2*cos((0$DOT$521*t)*pi/3$DOT$11)",
			"4"],
			"Ymin": ["-1+2*cos((0$DOT$521*t)*pi/3$DOT$11)",
			"-4"],
			"Zmax": ["6",
			"$DOT$1"],
			"Zmin": ["-1",
			"-1$DOT$1"]
		}
	},
	{
		"Iso3D": {
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
			"Cnd": ["((x-$DOT$1)^2+(y-$DOT$1)^2+(z-$DOT$1)^2)>1"],
			"Component": [" Nordstrand"],
			"Fxyz": ["  25*(x^3*(y+z)+y^3*(x+z)+z^3*(x+y))+50*(x^2*y^2+x^2*z^2+y^2*z^2)-125*(x^2*y*z+y^2*x*z+z^2*x*y)+60*x*y*z-4*(x*y+x*z+y*z)"],
			"Xmax": [" 1$DOT$1"],
			"Xmin": ["-1$DOT$1"],
			"Ymax": [" 1$DOT$1"],
			"Ymin": ["-1$DOT$1"],
			"Zmax": [" 1$DOT$1"],
			"Zmin": ["-1$DOT$1"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Togliatti"],
			"Cnd": ["(x^2 + y^2 + z^2) > 100"],
			"Component": ["Togliatti"],
			"Const": [" w=1$DOT$3"],
			"Fxyz": ["64*(x -w)*(x^4 - 4*w*x^3 -10*x^2*y^2 - 4*x^2*w^2 + 16*w^3*x - 20*w*x*y^2 + 5*y^4 + 16*w^4 - 20*y^2*w^2) -5*sqrt(5 - sqrt(5))*(2*z - sqrt(5 - sqrt(5))*w)*(4*(x^2 + y^2 - z^2) + (1 + 3*sqrt(5))*w^2)^2"],
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
			"Component": [" Dervish"],
			"Cnd": ["(x^2+y^2+z^2)>15"],
			"Const": ["r = (1/4)*(1+3*sqrt(5))",
			"a = -(8/5)*(1+1/(sqrt(5)))*sqrt(5-sqrt(5))",
			"c = (1/2)*sqrt(5-sqrt(5))"],
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
			"Name": ["Barth-sextic"],
			"Component": ["Barth-sextic"],
			"Cnd": ["(x^2+y^2+z^2)>9"],
			"Const": [" w=1$DOT$0",
			" phi=(1/2)*(1+sqrt(5))"],
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
			"Const": [" w = 1$DOT$0",
			"a1 = -(12/7)*(-0$DOT$14010685)^2 -(384/49)*(-0$DOT$14010685) -(8/7)",
			"a2 = -(32/7)*(-0$DOT$14010685)^2 +(24/49)*(-0$DOT$14010685)  -4",
			"a3 = -4*(-0$DOT$14010685)^2 +(24/49)*(-0$DOT$14010685)  -4",
			"a4 = -(8/7)*(-0$DOT$14010685)^2 +(8/49)*(-0$DOT$14010685)  -8/7",
			"a5 = 49*(-0$DOT$14010685)^2 -7*(-0$DOT$14010685)  +50"],
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
			"Const": [" w = 1$DOT$0",
			"a1 = 1$DOT$0",
			"a2 = 1$DOT$0",
			"a3 = 1$DOT$0",
			"a4 = -1$DOT$0"],
			"Fxyz": ["64 * (x^2 - w^2)*(y^2 - w^2)*((x + y)^2 -2*w^2)*((x - y)^2 -2*w^2)  - (-4*(1 + a1*2^(1/2))*(x^2 + y^2)^2 + (8*(2 + a2*2^(1/2))*z^2 + 2*(2 + a3*7*2^(1/2))*w^2 )* (x^2 + y^2) - 16*z^4+ 8*(1 + a4*2*2^(1/2))*z^2*w^2 - (1 + 12*2^(1/2))*w^4)^2"],
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
			"Component": [" SartiOctic"],
			"Fxyz": ["-1728*x^4*y^2*z^2+928$DOT$0*z^4*x^4+9024$DOT$0*z^2*x^4+928$DOT$0*z^4*y^4+9024$DOT$0*z^2*y^4+9024$DOT$0*x^2*y^2+2720$DOT$0*x^4*y^4-1728*x^2*z^2-1728*y^2*z^2-1728*x^4*y^2-1728*x^2*y^4-1728*x^2*z^4-1728*y^2*z^4-576*x^6*y^2-576*x^6*z^2-576*x^2*y^6-576*x^2*z^6-576*y^6*z^2+9024$DOT$0*z^4*x^2*y^2-24960$DOT$0*z^2*x^2*y^2-1728*x^2*y^4*z^2+2720$DOT$0*z^4+112$DOT$0*z^8-576*z^2+928$DOT$0*x^4+112$DOT$0*x^8+928$DOT$0*y^4+112$DOT$0*y^8-576*x^2-576*y^2-576*x^6-576*y^6-576*z^6+112$DOT$0-576*y^2*z^6"],
			"Xmax": ["5$DOT$6"],
			"Xmin": ["-5$DOT$6"],
			"Ymax": ["5$DOT$6"],
			"Ymin": ["-5$DOT$6"],
			"Zmax": ["5$DOT$6"],
			"Zmin": ["-5$DOT$6"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Breske-Nonic"],
			"Component": ["Breske-Nonic"],
			"Cnd": ["(x^2+y^2+z^2)>9"],
			"Fxyz": ["(2*x^7-42*x^5*y^2+70*x^3*y^4-14*x*y^6-14*x^6+70*x^4*y^2+70*x^2*y^4-14*y^6+28*x^5+56*x^3*y^2+28*x*y^4-84*x^2*y^2+28*y^4-42*x^3-42*x*y^2+14*x^2-14*y^2+14*x) + 0$DOT$5* (64*z^7-112*z^5+56*z^3-7*z+5)"],
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
			"Name": ["Barth-Dedic"],
			"Component": ["Barth-Dedic"],
			"Cnd": ["(x^2+y^2+z^2)> (1+sqrt(5))+0$DOT$2"],
			"Const": [" w  = 1$DOT$0",
			" phi= (1+sqrt(5))/2"],
			"Fxyz": ["8*(Ax-phi^4*Ay)*(Ay-phi^4*Az)*(Az-phi^4*Ax)*(Bx+By+Bz-2*(Ax*Ay+Ax*Az+Ay*Az)) + (3+5*phi)*(Ax+Ay+Az-w^2)^2 * (Ax+Ay+Az- (2-phi)*w^2)^2 * w^2"],
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
			"Name": ["SartiDodecic"],
			"Component": ["Sarti-Dodecic"],
			"Cnd": ["(x^2+y^2+z^2)>13"],
			"Const": [" w  = 1$DOT$0"],
			"Fxyz": ["243*(33*sqrt(5)*(((Ax*Ay+Az*w^2)^2*(Ax*Az+Ay*w^2)-(Ax*Ay+Az*w^2)*(Ax*Az+Ay*w^2)^2)+((Ax*Az+Ay*w^2)^2*(Ax*w^2+Ay*Az)-(Ax*Az+Ay*w^2)*(Ax*w^2+Ay*Az)^2)+((Ax*w^2+Ay*Az)^2*(Ax*Ay+Az*w^2)-(Ax*w^2+Ay*Az)*(Ax*Ay+Az*w^2)^2))+19*(((Ax*Ay+Az*w^2)^2*(Ax*Az+Ay*w^2)+(Ax*Ay+Az*w^2)*(Ax*Az+Ay*w^2)^2)+((Ax*Az+Ay*w^2)^2*(Ax*w^2+Ay*Az)+(Ax*Az+Ay*w^2)*(Ax*w^2+Ay*Az)^2)+((Ax*w^2+Ay*Az)^2*(Ax*Ay+Az*w^2)+(Ax*w^2+Ay*Az)*(Ax*Ay+Az*w^2)^2))+10*((Ax*Ay+Az*w^2)^3+(Ax*Az+Ay*w^2)^3+(Ax*w^2+Ay*Az)^3)-14*(Bx+By+Bz+w^4)*((Ax*Ay+Az*w^2)*(Ax*Az+Ay*w^2)+(Ax*Ay+Az*w^2)*(Ax*w^2+Ay*Az)+(Ax*Az+Ay*w^2)*(Ax*w^2+Ay*Az))+2*(Bx+By+Bz+w^4)^2*((Ax*Ay+Az*w^2)+(Ax*Az+Ay*w^2)+(Ax*w^2+Ay*Az))-6*(Bx+By+Bz+w^4)*((Ax*Ay+Az*w^2)^2+(Ax*Az+Ay*w^2)^2+(Ax*w^2+Ay*Az)^2)-352*(x*y*z*w)^2*((Ax*Ay+Az*w^2)+(Ax*Az+Ay*w^2)+(Ax*w^2+Ay*Az))+336*(x*y*z*w)^2*(Bx+By+Bz+w^4)+48*((Ax*Ay+Az*w^2)*(Ax*Az+Ay*w^2)*(Ax*w^2+Ay*Az)))-22*(Ax+Ay+Az+w^2)^6"],
			"Varu": [" A  = u^2",
			" B  = u^4"],
			"Xmax": ["3$DOT$7"],
			"Xmin": ["-3$DOT$7"],
			"Ymax": ["3$DOT$7"],
			"Ymin": ["-3$DOT$7"],
			"Zmax": ["3$DOT$7"],
			"Zmin": ["-3$DOT$7"]
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
			"Name": ["Blobs"],
			"Component": ["Blobs"],
			"Fxyz": ["x^2 + y ^2 + z^2 +cos(4*x)+cos(4*y)+cos(4*z)-0$DOT$2"],
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
			"Name": ["CubeSphere"],
			"Component": ["CubeSphere"],
			"Fxyz": [" ((1/2$DOT$3)^2 *(x^2 + y^2 + z^2))^-6 + ( (1/2)^8 * (x^8 + y^8 + z^8) )^6 -1"],
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
			"Name": ["Devil"],
			"Component": ["Devil Surface"],
			"Fxyz": ["x^4+2*x^2*z^2-0$DOT$36*x^2-y^4+0$DOT$25*y^2+z^4"],
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
			"Name": ["Hyperboloid"],
			"Component": ["Hyperboloid"],
			"Fxyz": ["x^2 + y^2 - z^2 -0$DOT$3"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-1$DOT$8"],
			"Zmax": [" 1$DOT$8"]
		}
	},
	{
		"Iso3D": {
			"Name": ["DuplinCyclides"],
			"Component": ["DuplinCyclides"],
			"Fxyz": ["(2^2 - (2 + 2$DOT$1)^2) * (2^2 - (2 - 2$DOT$1)^2)*(x^4+y^4+z^4)+ 2*((2^2 - (2 + 2$DOT$1)^2 )*(2^2 - $DOT$1^2)* (x^2 * y^2+x^2 * z^2+y^2 * z^2))+2* 2^2 *((2$DOT$1^2)* (2 *x *2-2^2))*(x^2+y^2+z^2)+ 4 * 2^4 * (2 *x)* (-2^2+2 * x)+4* 2^4 * 2$DOT$1^2 * y^2+2^8"],
			"Xmin": ["-2"],
			"Xmax": [" 2$DOT$2"],
			"Ymin": ["-2$DOT$1"],
			"Ymax": [" 2$DOT$1"],
			"Zmin": ["-1$DOT$3"],
			"Zmax": [" 1$DOT$3"]
		}
	},
	{
		"Iso3D": {
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
			"Name": ["KleinIso"],
			"Component": ["KleinIso"],
			"Fxyz": ["(x^2+y^2+z^2+2*y-1)*((x^2+y^2+z^2-2*y-1)^2-8*z^2)+16*x*z*(x^2+y^2+z^2-2*y-1)"],
			"Xmin": ["-3"],
			"Xmax": [" 3"],
			"Ymin": ["-3$DOT$1"],
			"Ymax": [" 3$DOT$1"],
			"Zmin": ["-4"],
			"Zmax": [" 4"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Leminescape"],
			"Component": ["Leminescape"],
			"Fxyz": ["4*x^2*(x^2+y^2+z^2+z)+y^2*(y^2+z^2-1)"],
			"Xmin": ["-0$DOT$5"],
			"Xmax": [" 0$DOT$5"],
			"Ymin": ["-1"],
			"Ymax": [" 1"],
			"Zmin": ["-1"],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Drope"],
			"Component": ["Drope"],
			"Fxyz": ["z - 4*x*exp(-x^2-y^2)"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2"],
			"Ymax": [" 2"],
			"Zmin": ["-1$DOT$7"],
			"Zmax": [" 1$DOT$7"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Sinus"],
			"Component": ["Sinus"],
			"Colors": ["R=cos(30*x*pi)",
			"G=cos(30*y*pi)",
			"B=cos(4*z*pi)",
			"T=1$DOT$0"],
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
			"Name": ["Chmutov"],
			"Component": ["Chmutov"],
			"Fxyz": ["(x^2)^2 + (y^2)^2 + (z^2)^2 - (x^2 + y^2 + z^2-0$DOT$3)"],
			"Xmin": ["-1$DOT$5"],
			"Xmax": [" 1$DOT$5"],
			"Ymin": ["-1$DOT$5"],
			"Ymax": [" 1$DOT$5"],
			"Zmin": ["-1$DOT$5"],
			"Zmax": [" 1$DOT$5"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Chmutov_2"],
			"Component": ["Chmutov_2"],
			"Fxyz": ["2*(x^2*(3-4*x^2)^2+y^2*(3-4*y^2)^2+z^2*(3-4*z^2)^2) -3"],
			"Xmin": ["-1$DOT$3"],
			"Xmax": [" 1$DOT$3"],
			"Ymin": ["-1$DOT$3"],
			"Ymax": [" 1$DOT$3"],
			"Zmin": ["-1$DOT$3"],
			"Zmax": [" 1$DOT$3"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Composite"],
			"Component": ["Chmutov",
			"RoundCube",
			"Virus",
			"Trap"],
			"Fxyz": ["2*(x^2*(3-4*x^2)^2+y^2*(3-4*y^2)^2+z^2*(3-4*z^2)^2) -3",
			"((x-3)^2)^2 + (y^2)^2 + (z^2)^2 - ((x-3)^2 + y^2 + z^2-0$DOT$3)",
			"-(-(x^2 + (y-3) ^2 + z^2) +cos(5*x)*cos(5*(y-3))*cos(5*z)+0$DOT$215)",
			"((x-3)^8 + z^30 + (y-3)^8 - ((x-3)^4 + z^50 + (y-3)^4 -0$DOT$3))*((x-3)^2 + (y-3)^2 + z^2 -0$DOT$5)"],
			"Xmin": ["-1$DOT$3",
			"1$DOT$5",
			"-$DOT$8",
			"1$DOT$8  "],
			"Xmax": [" 1$DOT$3",
			"4$DOT$5",
			"$DOT$8",
			"4$DOT$2"],
			"Ymin": ["-1$DOT$3",
			"-1$DOT$5",
			"2$DOT$2",
			"1$DOT$8 "],
			"Ymax": [" 1$DOT$3",
			"1$DOT$5",
			"3$DOT$8",
			"4$DOT$3"],
			"Zmin": ["-1$DOT$3",
			"-1$DOT$5",
			"-$DOT$8",
			"-1$DOT$5 "],
			"Zmax": [" 1$DOT$3",
			"1$DOT$5",
			"$DOT$8",
			"1$DOT$5"]
		}
	},
	{
		"Iso3D": {
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
			"Name": ["Icosahedron"],
			"Component": ["Icosahedron"],
			"Fxyz": ["if( (x^2 + y^2 +z^2 < 35), 2 - (cos(x + (1+sqrt(5))/2*y) + cos(x - (1+sqrt(5))/2*y) + cos(y + (1+sqrt(5))/2*z) + cos(y - (1+sqrt(5))/2*z) + cos(z - (1+sqrt(5))/2*x) + cos(z + (1+sqrt(5))/2*x)) , 1)"],
			"Xmin": ["-5$DOT$5"],
			"Xmax": [" 5$DOT$5"],
			"Ymin": ["-5$DOT$5"],
			"Ymax": [" 5$DOT$5"],
			"Zmin": ["-5$DOT$5"],
			"Zmax": [" 5$DOT$5"]
		}
	},
	{
		"Iso3D": {
			"Name": ["DingDong"],
			"Component": ["DingDong"],
			"Fxyz": ["x^2 +y^2 -(1-z)*z^2"],
			"Xmin": ["-1$DOT$5"],
			"Xmax": [" 1$DOT$5"],
			"Ymin": ["-1$DOT$5"],
			"Ymax": [" 1$DOT$5"],
			"Zmin": ["-1"],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Trap"],
			"Component": ["Trap"],
			"Fxyz": ["(x^8 + z^30 + y^8 - (x^4 + z^50 + y^4 -0$DOT$3))*(x^2 + y^2 + z^2 -0$DOT$5)"],
			"Xmin": ["-1$DOT$2"],
			"Xmax": [" 1$DOT$2"],
			"Ymin": ["-1$DOT$3"],
			"Ymax": [" 1$DOT$3"],
			"Zmin": ["-1$DOT$5"],
			"Zmax": [" 1$DOT$5"]
		}
	},
	{
		"Iso3D": {
			"Name": ["OrthoCircle"],
			"Component": ["OrthoCircle"],
			"Fxyz": ["((x^2 + y^2 - 1)^2 + z^2)* ((y^2 + z^2 - 1)^2 + x^2)* ((z^2 + x^2 - 1)^2 + y^2) - 0$DOT$075^2 *(1 + 3* (x^2 + y^2 + z^2))"],
			"Xmin": ["-1$DOT$5"],
			"Xmax": [" 1$DOT$5"],
			"Ymin": ["-1$DOT$5"],
			"Ymax": [" 1$DOT$5"],
			"Zmin": ["-1$DOT$5"],
			"Zmax": [" 1$DOT$5"]
		}
	},
	{
		"Iso3D": {
			"Name": ["CubeSphere_2"],
			"Component": ["CubeSphere_2"],
			"Fxyz": ["12 - ((1/2$DOT$3)^2 *(x^2 + y^2 + z^2))^-6 - ( (1/2)^8 * (x^8 + y^8 + z^8) )^6"],
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
			"Name": ["UnionSpheres"],
			"Component": ["UnionSpheres"],
			"Fxyz": ["min( (x-0$DOT$7)*(x-0$DOT$7) + y*y + z*z - 1,  (x+0$DOT$5)*(x+0$DOT$5) + y*y + z*z - 1)"],
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
			"Name": ["DifferenceSpheres"],
			"Component": ["DifferenceSpheres"],
			"Fxyz": ["((x-0$DOT$7)*(x-0$DOT$7) + y*y + z*z - 1)*min( (x-0$DOT$7)*(x-0$DOT$7) + y*y + z*z - 1, (x+0$DOT$3)*(x+0$DOT$3) + y*y + z*z - 1) +0$DOT$02"],
			"Xmin": ["-2"],
			"Xmax": [" 0$DOT$1"],
			"Ymin": ["-1"],
			"Ymax": [" 1"],
			"Zmin": ["-1"],
			"Zmax": [" 1"]
		}
	},
	{
		"Iso3D": {
			"Name": ["BlendSpheres"],
			"Component": ["BlendSpheres"],
			"Fxyz": ["((x-0$DOT$9)*(x-0$DOT$9) + y*y + z*z - 1)*((x+0$DOT$9)*(x+0$DOT$9) + y*y + z*z - 1) -0$DOT$3"],
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
			"Fxyz": ["((x-(abs(((t*2$DOT$5)%16)-8)-4))^2+(y-(abs(((t*2$DOT$9)%16)-8)-4))^2+(z-(4$DOT$4-((((t*1$DOT$2)%4)-2)^2)))^2-0$DOT$8)",
			"(z+$DOT$407)*(y-4$DOT$9)*(y+4$DOT$9)*(x+4$DOT$9)",
			"(x-4$DOT$9)"],
			"Grid": ["25",
			"15",
			"5"],
			"Xmax": ["4$DOT$81",
			"4$DOT$91",
			"4$DOT$92"],
			"Xmin": ["-4$DOT$81",
			"-4$DOT$91",
			"4$DOT$88"],
			"Ymax": ["4$DOT$81",
			"4$DOT$91",
			"4$DOT$91"],
			"Ymin": ["-4$DOT$81",
			"-4$DOT$91",
			"-4$DOT$91"],
			"Zmax": ["5$DOT$5",
			"5$DOT$5",
			"5$DOT$5"],
			"Zmin": ["-$DOT$5",
			"-$DOT$41",
			"-$DOT$41"]
		}
	},
	{
		"Iso3D": {
			"Name": ["IntersectSpheres"],
			"Component": ["IntersectSpheres"],
			"Fxyz": ["max( (x-0$DOT$7)*(x-0$DOT$7) + y*y + z*z - 1,  (x+0$DOT$5)*(x+0$DOT$5) + y*y + z*z - 1)"],
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
			"Name": ["Bugs"],
			"Component": ["Bugs"],
			"Fxyz": ["min( ((x*cos(0$DOT$866646*y) - z*sin(0$DOT$866646*y))-0$DOT$7)*((x*cos(0$DOT$866646*y) - z*sin(0$DOT$866646*y))-0$DOT$7) + (y/2$DOT$9)*(y/2$DOT$9) + (x*sin(0$DOT$866646*y) + z*cos(0$DOT$866646*y))*(x*sin(0$DOT$866646*y) + z*cos(0$DOT$866646*y)) - 1,  ((x*cos(0$DOT$866646*y) - z*sin(0$DOT$866646*y))+0$DOT$5)*((x*cos(0$DOT$866646*y) - z*sin(0$DOT$866646*y))+0$DOT$5) + (y/2$DOT$9)*(y/2$DOT$9) + (x*sin(0$DOT$866646*y) + z*cos(0$DOT$866646*y))*(x*sin(0$DOT$866646*y) + z*cos(0$DOT$866646*y)) - 1)"],
			"Xmin": ["-2"],
			"Xmax": [" 2"],
			"Ymin": ["-2*2$DOT$9*1"],
			"Ymax": [" 2*2$DOT$9*1"],
			"Zmin": ["-2"],
			"Zmax": [" 2"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Texture_Duplin"],
			"Component": ["Texture_Duplin"],
			"Varu": ["A=cos(0$DOT$9589716*u)",
			"B=sin(0$DOT$9589716*u)"],
			"Fxyz": ["-49$DOT$95*((x/2$DOT$34)^4+(y*Ax - z*Bx)^4+ (y*Bx + z*Ax)^4) +
                        (-99$DOT$95)* ((x/2$DOT$34)^2 * (y*Ax - z*Bx)^2+(x/2$DOT$34)^2 * (y*Bx + z*Ax)^2+(y*Ax - z*Bx)^2 * (y*Bx + z*Ax)^2)+
                        (141$DOT$12* (x/2$DOT$34-1))*((x/2$DOT$34)^2 +(y*Ax - z*Bx)^2+(y*Bx + z*Ax)^2)+
                        (54$DOT$7 *x)* (-4 +0$DOT$8547 * x) + 262$DOT$4 * (y*Ax - z*Bx)^2 + 256"],
			"Xmax": [" 2$DOT$5*3$DOT$9*0$DOT$6"],
			"Xmin": ["-2*3$DOT$9*0$DOT$6"],
			"Ymax": [" 2"],
			"Ymin": ["-2"],
			"Zmax": [" 2"],
			"Zmin": ["-2"]
		},
		"Texture": {
			"Colors": ["R=1",
			"G=0$DOT$8*abs(cos(2*(z*z+(y+1)*(y+1)+x*x)))",
			"B=0$DOT$5+0$DOT$3*abs(cos(2*(z*z +x*x +y*y)))",
			"T=1"],
			"Name": "Granit"
		}
	},
	{
		"Iso3D": {
			"Name": ["Noise_Duplin"],
			"Component": ["Noise_Duplin"],
			"Varu": ["A=cos(0$DOT$9589716*u)",
			"B=sin(0$DOT$9589716*u)"],
			"Fxyz": ["-49$DOT$95*((x/2$DOT$34)^4+(y*Ax - z*Bx)^4+ (y*Bx + z*Ax)^4) +(-99$DOT$95)* ((x/2$DOT$34)^2 * (y*Ax - z*Bx)^2+(x/2$DOT$34)^2 * (y*Bx + z*Ax)^2+(y*Ax - z*Bx)^2 * (y*Bx + z*Ax)^2)+(141$DOT$12* (x/2$DOT$34-1))*((x/2$DOT$34)^2 +(y*Ax - z*Bx)^2+(y*Bx + z*Ax)^2)+(54$DOT$7 *x)* (-4 +0$DOT$8547 * x) + 262$DOT$4 * (y*Ax - z*Bx)^2 + 256"],
			"Xmax": [" 2$DOT$5*3$DOT$9*0$DOT$6"],
			"Xmin": ["-2*3$DOT$9*0$DOT$6"],
			"Ymax": [" 2"],
			"Ymin": ["-2"],
			"Zmax": [" 2"],
			"Zmin": ["-2"]
		},
		"Noise": "",
		"Texture": {
			"Colors": ["R=1",
			"G=0$DOT$8*abs(cos(2*(z*z+(y+1)*(y+1)+x*x)))",
			"B=0$DOT$5+0$DOT$3*abs(cos(2*(z*z +x*x +y*y)))",
			"T=1"],
			"Name": "Granit"
		}
	},
	{
		"Iso3D": {
			"Name": ["Pigment_Duplin"],
			"Component": ["Pigment_Duplin"],
			"Varu": ["A=cos(0$DOT$9589716*u)",
			"B=sin(0$DOT$9589716*u)"],
			"Fxyz": ["-49$DOT$95*((x/2$DOT$34)^4+(y*Ax - z*Bx)^4+ (y*Bx + z*Ax)^4) +(-99$DOT$95)* ((x/2$DOT$34)^2 * (y*Ax - z*Bx)^2+(x/2$DOT$34)^2 * (y*Bx + z*Ax)^2+(y*Ax - z*Bx)^2 * (y*Bx + z*Ax)^2)+(141$DOT$12* (x/2$DOT$34-1))*((x/2$DOT$34)^2 +(y*Ax - z*Bx)^2+(y*Bx + z*Ax)^2)+(54$DOT$7 *x)* (-4 +0$DOT$8547 * x) + 262$DOT$4 * (y*Ax - z*Bx)^2 + 256"],
			"Xmax": [" 2$DOT$5*3$DOT$9*0$DOT$6"],
			"Xmin": ["-2*3$DOT$9*0$DOT$6"],
			"Ymax": [" 2"],
			"Ymin": ["-2"],
			"Zmax": [" 2"],
			"Zmin": ["-2"]
		},
		"Pigment": {
			"Colors": [{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=$DOT$20",
					"R=$DOT$90",
					"G=$DOT$9",
					"B=$DOT$40",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0$DOT$3",
					"R=1",
					"G=$DOT$1",
					"B=$DOT$31",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0$DOT$6",
					"R=1",
					"G=$DOT$7",
					"B=1",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=0$DOT$6",
					"R=1",
					"G=0$DOT$3",
					"B=$DOT$1",
					"A=1"]
				}
			},
			{
				"Color": {
					"Name": "Red",
					"Vrgba": ["V=1",
					"R=$DOT$15",
					"G=$DOT$6",
					"B=$DOT$1",
					"A=1"]
				}
			}],
			"Gradient": "3*cos((x*x *z)*pi)*cos(y*y*z*pi)*cos((y *x)*pi)*cos(z*y*x*pi)"
		}
	},
	{
		"Iso3D": {
			"Name": ["pseudo_Torus"],
			"Component": ["pseudo_Torus"],
			"Fxyz": ["(sqrt((x/2$DOT$7)*(x/2$DOT$7)+(y*sin(0$DOT$436332*x) + z*cos(0$DOT$436332*x))*(y*sin(0$DOT$436332*x) + z*cos(0$DOT$436332*x)))-3)^2 + (y*cos(0$DOT$436332*x) - z*sin(0$DOT$436332*x))*(y*cos(0$DOT$436332*x) - z*sin(0$DOT$436332*x)) - 1"],
			"Xmin": ["-4*2$DOT$7"],
			"Xmax": [" 4*2$DOT$7"],
			"Ymin": ["-4"],
			"Ymax": [" 4"],
			"Zmin": ["-4"],
			"Zmax": [" 4"]
		}
	},
	{
		"Iso3D": {
			"Description": ["(x^N + y ^N + z^N) - (cos(m*7*x) + cos(n*7*y) + cos(k*7*z)) + l
		N : Even integer > 4 --> Sharpness of edges$DOT$
		n, m, k : integers --> number of holes$DOT$
		l : Real number (-3,1) --> Thickness"],
			"Name": ["ChmutySchwarz"],
			"Component": ["ChmutySchwarz"],
			"Fxyz": ["(x^16 + y ^16 + z^16 ) -(cos(7*x) +cos(7*y) +cos(7*z)) -$DOT$1"],
			"Xmin": ["-1$DOT$1"],
			"Xmax": [" 1$DOT$1"],
			"Ymin": ["-1$DOT$1"],
			"Ymax": [" 1$DOT$1"],
			"Zmin": ["-1$DOT$1"],
			"Zmax": [" 1$DOT$1"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Virus"],
			"Component": ["Virus"],
			"Fxyz": ["-(x^2 + y ^2 + z^2) +cos(5*x)*cos(5*y)*cos(5*z)+0$DOT$215"],
			"Xmin": ["-$DOT$8"],
			"Xmax": [" $DOT$8"],
			"Ymin": ["-$DOT$8"],
			"Ymax": [" $DOT$8"],
			"Zmin": ["-$DOT$8"],
			"Zmax": [" $DOT$8"]
		}
	},
	{
		"Iso3D": {
			"Name": ["BlobySchwarz"],
			"Component": ["BlobySchwarz"],
			"Fxyz": ["-(x^2 + y ^2 + z^2) +cos(5*x)+cos(5*y)+cos(5*z) -$DOT$1"],
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
			"Description": [" To make  \"thick\" isosurfaces, you can use this formula:
		G(x, y, z) = F(x, y, z) * F(x - (T/R)*dF()/dx, y - (T/R)*dF()/dy, z - (T/R)*df()/dz)
		dF()/dx == partial derivative of F() to the variable x$DOT$
		F(x, y, z)  : The original Isosurface formula$DOT$
		G(x, y, z) : The new Isosurface formula$DOT$
		R = sqrt((dF()/dx)^2 + (dF()/dy)^2 + (dF()/dz)^2)
		T = Tickness value
		Applied to Schwarz (F()= cos(x) + cos(y) + cos(z) , T = 1/2) ,we obtain the following formula:"],
			"Name": ["TickIso"],
			"Component": ["TickIso"],
			"Fxyz": ["(cos(x) + cos(y) + cos(z))*((cos(x + sin(x)/(2*sqrt(sin(x)^2 + sin(y)^2 + sin(z)^2))) +cos(y + sin(y)/(2*sqrt(sin(x)^2 + sin(y)^2 + sin(z)^2))) +cos(z + sin(z)/(2*sqrt(sin(x)^2 + sin(y)^2 + sin(z)^2)))))"],
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
			"Description": [" Another closed isosurface but in this case we consider the outside volume delimited by the Schwarz surface$DOT$The \"outside\" volume is defined by deleting the signe \"-\""],
			"Name":["CloseIso_1"],
			"Component": ["CloseIso_1"],
			"Fxyz":["if((x^10+y^10+z^10<100000),(cos(x)+cos(y)+cos(z)),(x^10+y^10+z^10-100000))"],
			"Xmin":["-4"], "Xmax":["4"],
			"Ymin":["-4"], "Ymax":["4"],
			"Zmin":["-4"], "Zmax":["4"]
		}},
{
	"Iso3D": {
		"Name": ["CloseIso_2"],
		"Component": ["CloseIso_2"],
		"Fxyz": ["if((x^10+y^10+z^10<3*(3$DOT$5^10)),(cos(x)+cos(y)+cos(z))*((cos(x+sin(x)/(2*sqrt(sin(x)^2+sin(y)^2+sin(z)^2)))+cos(y+sin(y)/(2*sqrt(sin(x)^2+sin(y)^2+sin(z)^2)))+cos(z+sin(z)/(2*sqrt(sin(x)^2+sin(y)^2+sin(z)^2))))),(x^10+y^10+z^10-3*(3$DOT$5^10)))"],
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
		"Fxyz": ["((sqrt(x*x+y*y)-3)^2+z*z-0$DOT$4)*((sqrt((x-4$DOT$5)*(x-4$DOT$5)+z*z)-3)^2+y*y-0$DOT$4)*((sqrt((x+4$DOT$5)*(x+4$DOT$5)+z*z)-3)^2+y*y-0$DOT$4)*((sqrt((y+4$DOT$5)*(y+4$DOT$5)+z*z)-3)^2+x*x-0$DOT$4)*((sqrt((y-4$DOT$5)*(y-4$DOT$5)+z*z)-3)^2+x*x-0$DOT$4)*((sqrt(x*x+y*y)-5)^2+z*z-0$DOT$4)"],
		"Xmin": ["-8$DOT$2"],
		"Xmax": ["8$DOT$2"],
		"Ymin": ["-8$DOT$2"],
		"Ymax": ["8$DOT$2"],
		"Zmin": ["-4"],
		"Zmax": ["4"]
	}
},

{
	"Iso3D": {
		"Cnd": ["(sqrt(x^2+y^2+z^2))<8"],
		"Component": ["DiamondLatice"],
		"Const": ["T=1",
		"G=-1"],
		"Funct": ["df=(cos(x)*sin(y)*sin(z)+cos(x)*cos(y)*cos(z)-sin(x)*sin(y)*cos(z)-sin(x)*cos(y)*sin(z))",
		"R=sqrt((cos(x)*sin(y)*sin(z)+cos(x)*cos(y)*cos(z)-sin(x)*sin(y)*cos(z)-sin(x)*cos(y)*sin(z))^2+(cos(y)*sin(z)*sin(x)+cos(y)*cos(z)*cos(x)-sin(y)*sin(z)*cos(x)-sin(y)*cos(z)*sin(x))^2+(cos(z)*sin(x)*sin(y)+cos(z)*cos(x)*cos(y)-sin(z)*sin(x)*cos(y)-sin(z)*cos(x)*sin(y))^2)",
		"Diamond=(sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z))"],
		"Fxyz": ["Diamond(x-df(x,
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
			t)"],
		"Name": ["DiamondLatice"],
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
		"Const": ["T=1",
		"G=-1"],
		"Funct": ["R=sqrt((-sin(x)*sin(y)+cos(x)*cos(z))^2+(-sin(y)*sin(z)+cos(y)*cos(x))^2+(-sin(z)*sin(x)+cos(z)*cos(y))^2)",
		"df=(-sin(x)*sin(y)+cos(x)*cos(z))",
		"Gyroid=(cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x))"],
		"Fxyz": ["Gyroid(x-df(x,
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
			t)"],
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
		"Const": ["T=$DOT$3",
		"G=-$DOT$3"],
		"Funct": ["df=(-3*sin(x)-4*sin(x)*cos(y)*cos(z))",
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
		"Neovius=(3*(cos(x)+cos(y)+cos(z))+4*cos(x)*cos(y)*cos(z))"],
		"Fxyz": ["Neovius(x-df(x,
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
			t)"],
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
		"Const": ["T=$DOT$05",
		"G=-$DOT$05"],
		"Funct": ["df=((1/2)*(2*cos(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*cos(x)-sin(2*z)*sin(x)*sin(y))-(1/2)*(-2*sin(2*x)*cos(2*y)-2*cos(2*z)*sin(2*x)))",
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
		"Linoid=((1/2)*(sin(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*sin(x)+sin(2*z)*cos(x)*sin(y))-(1/2)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+0$DOT$15)"],
		"Fxyz": ["Linoid(x-df(x,
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
			t)"],
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
		"Fxyz": ["-((1/2)*(sin(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*sin(x)+sin(2*z)*cos(x)*sin(y))-(1/2)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+0$DOT$15)"],
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
        "Name": [
            "G_SkeletalGraph"
        ],
        "Component": [
            "G_SkeletalGraph"
        ],
        "Fxyz": [
            "cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)+0$DOT$08*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+1$DOT$47"
        ],
        "Xmax": [
            "2$DOT$75*pi"
        ],
        "Xmin": [
            "-0$DOT$25*pi"
        ],
        "Ymax": [
            "2$DOT$75*pi"
        ],
        "Ymin": [
            "-0$DOT$25*pi"
        ],
        "Zmax": [
            "2$DOT$75*pi"
        ],
        "Zmin": [
            "-0$DOT$25*pi"
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
        "Fxyz": [
            "sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)-0$DOT$07*(cos(4*x)+cos(4*y)+cos(4*z))+1$DOT$17"
        ],
        "Xmax": [
            "2$DOT$75*pi"
        ],
        "Xmin": [
            "-0$DOT$25*pi"
        ],
        "Ymax": [
            "2$DOT$75*pi"
        ],
        "Ymin": [
            "-0$DOT$25*pi"
        ],
        "Zmax": [
            "2$DOT$75*pi"
        ],
        "Zmin": [
            "-0$DOT$25*pi"
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
        "Fxyz": [
            "cos(x)+cos(y)+cos(z)+0$DOT$51*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+1$DOT$47"
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
        "Fxyz": [
            "cos(2*x)+cos(2*y)+cos(2*z)-1$DOT$95*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+2$DOT$8"
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
            "Constructive Solid Geometry(CSG)with mathematics"
        ],
        "Name": [
            "CSGS pheres"
        ],
        "Component": [
            "DifferenceSpheres",
            "UnionSpheres",
            "IntersectSpheres"
        ],

        "Fxyz": [
            "((x-0$DOT$7)*(x-0$DOT$7)+y*y+z*z-1)*min((x-0$DOT$7)*(x-0$DOT$7)+y*y+z*z-1,(x+0$DOT$3)*(x+0$DOT$3)+y*y+z*z-1)+0$DOT$02",
            "min((x-4$DOT$7)*(x-4$DOT$7)+y*y+z*z-1,(x-3$DOT$5)*(x-3$DOT$5)+y*y+z*z-1)",
            "max((x-0$DOT$7)*(x-0$DOT$7)+y*y+z*z-1,(x-2$DOT$)*(x-2$DOT$)+y*y+z*z-1)"
        ],
        "Xmax": [
            "0$DOT$5",
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
       "Description": [
		"The formula : G(x,y,z)=F(x-2*P(x,y,z)*a/R,y-2*P(x,y,z)*b/R,z-2*P(x,y,z)*c/R)Where: P(x,y,z)=ax+by+cz+d(EquationofthePlan)R=(a^2+b^2+c^2)ThisexampleshowstheresultforaTorus(F)andaPlan(P=y-z+4)"
        ],
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
        "cos(x/1$DOT$5)+cos((y+16)/1$DOT$5)+cos(z/1$DOT$5)",
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
        "G=$DOT$1",
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
            "A=cos(0$DOT$9589716*u)",
			"B=sin(0$DOT$9589716*u)"
        ],
        "Fxyz": [
            "-49$DOT$95*((x/2$DOT$34)^4+(y*Ax-z*Bx)^4+(y*Bx+z*Ax)^4)+(-99$DOT$95)*((x/2$DOT$34)^2*(y*Ax-z*Bx)^2+(x/2$DOT$34)^2*(y*Bx+z*Ax)^2+(y*Ax-z*Bx)^2*(y*Bx+z*Ax)^2)+(141$DOT$12*(x/2$DOT$34-1))*((x/2$DOT$34)^2+(y*Ax-z*Bx)^2+(y*Bx+z*Ax)^2)+(54$DOT$7*x)*(-4+0$DOT$8547*x)+262$DOT$4*(y*Ax-z*Bx)^2+256"
        ],
        "Name": [
            "pseudo_Duplin"
        ],
        "Xmax": [
            "2$DOT$2*3$DOT$9*0$DOT$6"
        ],
        "Xmin": [
            "-2*3$DOT$9*0$DOT$6"
        ],
        "Ymax": [
            "2"
        ],
        "Ymin": [
            "-2"
        ],
        "Zmax": [
            "2"
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
                        "V=$DOT$20",
                        "R=$DOT$4",
                        "G=$DOT$4",
                        "B=$DOT$70",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0$DOT$3",
                        "R=1",
                        "G=$DOT$1",
                        "B=$DOT$31",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0$DOT$6",
                        "R=$DOT$51",
                        "G=$DOT$17",
                        "B=1",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0$DOT$6",
                        "R=1",
                        "G=0$DOT$3",
                        "B=$DOT$1",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=1",
                        "R=$DOT$915",
                        "G=$DOT$17",
                        "B=$DOT$1",
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
                "Name": [
                    "CellNoiseSchwarz"
                ],
                "Component": [
                    "Schwarz"
                ],
                "Fxyz": [
                    "Ax+Ay+Az-NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
                ],
                "Varu": [
                    "A=cos(u)"
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
                    "R=2*$DOT$41",
                    "G=2*0$DOT$81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
                    "B=2*0$DOT$8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
                    "T=1"
                ],
                "Name": "WorleyNoise",
                "Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
            }
        },
{
	"Param3D": {
		"Name": ["Klein"],
		"Component": ["Klein_1",
		"Klein_2"],
		"Fx": ["4*(1-cos(u)/2)*cos(u)*cos(v)+6*cos(u)*(1+sin(u))",
		"4*(1-cos(u)/2)*cos(v+pi)+6*cos(u)*(1+sin(u))"],
		"Fy": ["4*(1-cos(u)/2)*sin(u)*cos(v)+16*sin(u)",
		"16*sin(u)"],
		"Fz": ["4*(1-cos(u)/2)*sin(v)",
		"4*(1-cos(u)/2)*sin(v)"],
		"Umin": ["0",
		"pi"],
		"Umax": ["pi",
		"2*pi"],
		"Vmin": ["0",
		"0"],
		"Vmax": ["2*pi",
		"2*pi"]
	}
},
{
	"Param3D": {
		"Name": ["Klein_1"],
		"Component": ["Klein_1"],
		"Funct": ["KleinFunction=(3*(1+sin(v))+2*(1-cos(v)/2)*cos(u))*cos(v)"],
		"Const": ["T1=2"],
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
		"Component": ["4DTorus4D",
		"4DPTorus",
		"4DCliffordTorus"],
		"Fw": ["cos(v)",
		"cos(3*v)",
		"cos(u)"],
		"Fx": ["sin(u)",
		"sin(u)+2",
		"cos(u+v)/(sqrt(2$DOT$)+cos(v-u))"],
		"Fy": ["cos(u)",
		"cos(u)",
		"sin(u+v)/(sqrt(2$DOT$)+cos(v-u))+3"],
		"Fz": ["sin(v)",
		"sin(2*v)",
		"(sin(v-u)/(sqrt(2$DOT$)+cos(v-u)))*1$DOT$5"],
		"Name": ["4DMathModels"],
		"Umax": ["2*pi",
		"2*pi",
		"pi"],
		"Umin": ["0",
		"0",
		"0"],
		"Vmax": ["2*pi",
		"2*pi",
		"2*pi"],
		"Vmin": ["0",
		"0",
		"0"]
	}
},
{
	"Param3D": {
		"Name": ["Shell"],
		"Cnd": ["(x^2+y^2)>2$DOT$0"],
		"Varu": ["A=(u-4*sin(3$DOT$14/10))^2",
		"B=(u-2*cos(3$DOT$14/10))^2",
		"C=(u-2*sin(3$DOT$14)-4*sin(3$DOT$14/10))^2",
		"D=(u-2*cos(3$DOT$14)-2*cos(3$DOT$14/10))^2"],
		"Funct": ["Schwarz1=cos(u)",
		"Schwarz2=cos(u)+sin(v)"],
		"Component": ["Shell"],
		"Const": ["r=(1/4)*(1+3*sqrt(5))",
		"a=-(8/5)*(1+1/(sqrt(5)))*sqrt(5-sqrt(5))",
		"c=(1/2)*sqrt(5-sqrt(5))"],
		"Fx": ["1$DOT$2^v*(sin(u)^2*sin(v))"],
		"Fy": ["1$DOT$2^v*(sin(u)^2*cos(v))"],
		"Fz": ["1$DOT$2^v*(sin(u)*cos(u))"],
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
		"Fx": ["(1+0$DOT$5*cos(u))*cos(v)"],
		"Fy": ["(1+0$DOT$5*cos(u))*sin(v)"],
		"Fz": ["0$DOT$5*sin(u)"],
		"Umin": ["0"],
		"Umax": ["2*pi"],
		"Vmin": ["0"],
		"Vmax": ["2*pi"]
	}
},
{
	"Param3D": {
		"Name": ["Cosinus"],
		"Component": ["Cosinus"],
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
		"Umin": ["-0$DOT$4"],
		"Umax": ["0$DOT$4"],
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
		"Fx": ["(1-0$DOT$1*cos(v))*cos(u)"],
		"Fy": ["(1-0$DOT$1*cos(v))*sin(u)"],
		"Fz": ["0$DOT$1*(sin(v)+u/1$DOT$7-10)"],
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
		"Umin": ["-1$DOT$3"],
		"Umax": ["1$DOT$3"],
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
		"Name": ["Catalan"],
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
		"Vmin": ["0$DOT$03"],
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
		"Vmin": ["0$DOT$01"],
		"Vmax": ["pi-0$DOT$01"]
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
		"Fz": ["1/3*u^3-1/2*v^2"],
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
		"Fx": ["1/2*sin(2*u)*sin(v)^2"],
		"Fy": ["1/2*sin(u)*cos(2*v)"],
		"Fz": ["1/2*cos(u)*sin(2*v)"],
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
		"Fx": ["1$DOT$2*(1-v/(2*pi))*cos(3*v)*(1+cos(u))+3*cos(3*v)"],
		"Fy": ["1$DOT$2*(1-v/(2*pi))*sin(3*v)*(1+cos(u))+3*sin(3*v)"],
		"Fz": ["9*v/(2*pi)+1$DOT$2*(1-v/(2*pi))*sin(u)"],
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
		"Fx": ["cos(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)+pi)/3$DOT$)+0$DOT$8)"],
		"Fy": ["sin(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)+pi)/3$DOT$)+0$DOT$8)"],
		"Fz": ["sin(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)+pi)/3$DOT$)+0$DOT$8)"],
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
		"Fx": ["cos(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)"],
		"Fy": ["sin(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)"],
		"Fz": ["sin(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)"],
		"Umin": ["0"],
		"Umax": ["2*pi"],
		"Vmin": ["-pi/2"],
		"Vmax": ["pi/2"]
	}
},
{
	"Param3D": {
		"Name": ["Cliffordtorus"],
		"Component": ["Cliffordtorus"],
		"Fx": ["cos(u+v)/(sqrt(2$DOT$)+cos(v-u))"],
		"Fy": ["sin(u+v)/(sqrt(2$DOT$)+cos(v-u))"],
		"Fz": ["sin(v-u)/(sqrt(2$DOT$)+cos(v-u))"],
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
		"Fx": ["2$DOT$*u/(u*u+v*v+1$DOT$)"],
		"Fy": ["2$DOT$*v/(u*u+v*v+1$DOT$)"],
		"Fz": ["(u*u+v*v-1$DOT$)/(u*u+v*v+1$DOT$)"],
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
		"Fy": ["-u*sin(v)-u^(3)/3*sin(3*v)"],
		"Fz": ["u^2*cos(2*v)"],
		"Umin": ["0"],
		"Umax": ["1$DOT$2"],
		"Vmin": ["-pi"],
		"Vmax": ["pi"]
	}
},
{
	"Param3D": {
		"Name": ["Maeder's_Owl"],
		"Component": ["Maeder's_Owl"],
		"Fx": ["v*cos(u)-0$DOT$5*v^2*cos(2*u)"],
		"Fy": ["-v*sin(u)-0$DOT$5*v^2*sin(2*u)"],
		"Fz": ["4*v^1$DOT$5*cos(3*u/2)/3"],
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
		"Fz": ["(cos(v)+log(tan(v/2)))+0$DOT$2*u"],
		"Umin": ["0"],
		"Umax": ["12$DOT$4"],
		"Vmin": ["0$DOT$1"],
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
		"Name": ["Helliptic paraboloid"],
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
		"Fx": ["cos(u)*(4+3$DOT$8*cos(v))"],
		"Fy": ["sin(u)*(4+3$DOT$8*cos(v))"],
		"Fz": ["(cos(v)+sin(v)-1)*(1+sin(v))*log(1-pi*v/10)+7$DOT$5*sin(v)"],
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
		"Fx": ["cos(u)*cos(v)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)*(abs(cos(4*v/4))^100+abs(sin(4*v/4))^100)^(-1/100)"],
		"Fy": ["cos(u)*sin(v)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)*(abs(cos(4*v/4))^100+abs(sin(4*v/4))^100)^(-1/100)"],
		"Fz": ["sin(u)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)"],
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
		"Fx": ["cos(u)*cos(v)*(abs(cos(3*v/4))^500+abs(sin(3*v/4))^500)^(-1/260)*(abs(cos(4*u/4))^200+abs(sin(4*u/4))^200)^(-1/200)"],
		"Fy": ["cos(u)*sin(v)*(abs(cos(3*v/4))^500+abs(sin(3*v/4))^500)^(-1/260)*(abs(cos(4*u/4))^200+abs(sin(4*u/4))^200)^(-1/200)"],
		"Fz": ["sin(u)*(abs(cos(4*u/4))^200+abs(sin(4*u/4))^200)^(-1/200)"],
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
		"Fx": ["cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000)"],
		"Fy": ["cos(u)*sin(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000)"],
		"Fz": ["sin(u)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)"],
		"Umin": ["-pi/2"],
		"Umax": ["pi/2"],
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
		"Name": ["Diamond"],
		"Component": ["Diamond"],
		"Fx": ["cos(u)*cos(v)*(abs(cos(4*u/4))^1+abs(sin(4*u/4))^1)^(-1/1)*(abs(cos(4*v/4))^1+abs(sin(4*v/4))^1)^(-1/1)"],
		"Fy": ["cos(u)*sin(v)*(abs(cos(4*u/4))^1+abs(sin(4*u/4))^1)^(-1/1)*(abs(cos(4*v/4))^1+abs(sin(4*v/4))^1)^(-1/1)"],
		"Fz": ["sin(u)*(abs(cos(4*u/4))^1+abs(sin(4*u/4))^1)^(-1/1)"],
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
		"Fx": ["cos(u)*cos(v)*(abs(cos(1*u/4))^0$DOT$5+abs(sin(1*u/4))^0$DOT$5)^(-1/0$DOT$3)*(abs(cos(5*v/4))^1$DOT$7+abs(sin(5*v/4))^1$DOT$7)^(-1/0$DOT$1)"],
		"Fy": ["cos(u)*sin(v)*(abs(cos(1*u/4))^0$DOT$5+abs(sin(1*u/4))^0$DOT$5)^(-1/0$DOT$3)*(abs(cos(5*v/4))^1$DOT$7+abs(sin(5*v/4))^1$DOT$7)^(-1/0$DOT$1)"],
		"Fz": ["sin(u)*(abs(cos(1*u/4))^0$DOT$5+abs(sin(1*u/4))^0$DOT$5)^(-1/0$DOT$3)"],
		"Umin": ["-pi/2"],
		"Umax": ["pi/2"],
		"Vmin": ["0"],
		"Vmax": ["2*pi"]
	}
},
{
	"Param3D": {
		"Name": ["Star_7"],
		"Component": ["Star_7"],
		"Fx": ["cos(u)*cos(v)*(abs(cos(7*v/4))^1$DOT$7+abs(sin(7*v/4))^1$DOT$7)^(-1/0$DOT$2)*(abs(cos(7*u/4))^1$DOT$7+abs(sin(7*u/4))^1$DOT$7)^(-1/0$DOT$2)"],
		"Fy": ["cos(u)*sin(v)*(abs(cos(7*v/4))^1$DOT$7+abs(sin(7*v/4))^1$DOT$7)^(-1/0$DOT$2)*(abs(cos(7*u/4))^1$DOT$7+abs(sin(7*u/4))^1$DOT$7)^(-1/0$DOT$2)"],
		"Fz": ["sin(u)*(abs(cos(7*u/4))^1$DOT$7+abs(sin(7*u/4))^1$DOT$7)^(-1/0$DOT$2)"],
		"Umin": ["-pi/2"],
		"Umax": ["pi/2"],
		"Vmin": ["0"],
		"Vmax": ["2*pi"]
	}
},
{
	"Param3D": {
		"Name": ["Shape_8"],
		"Component": ["Shape_8"],
		"Fx": ["cos(u)*cos(v)*(abs(cos(3*u/4))^100+abs(sin(3*u/4))^100)^(-1/100)*(abs(cos(2*v/4))^0$DOT$3+abs(sin(2*v/4))^0$DOT$2)^(-1/0$DOT$7)"],
		"Fy": ["cos(u)*sin(v)*(abs(cos(3*u/4))^100+abs(sin(3*u/4))^100)^(-1/100)*(abs(cos(2*v/4))^0$DOT$3+abs(sin(2*v/4))^0$DOT$2)^(-1/0$DOT$7)"],
		"Fz": ["sin(u)*(abs(cos(3*u/4))^100+abs(sin(3*u/4))^100)^(-1/100)"],
		"Umin": ["-pi/2"],
		"Umax": ["pi/2"],
		"Vmin": ["0"],
		"Vmax": ["2*pi"]
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
		"Name": ["Sphere_1"],
		"Component": ["Sphere_1"],
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
		"Name": ["Pseudo_Sphere"],
		"Component": ["Pseudo_Sphere"],
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
		"Name": ["Pseudo_Catenoid"],
		"Component": ["Pseudo_Catenoid"],
		"Fx": ["2$DOT$2*(2*cosh(v/2)*cos(u))"],
		"Fy": ["1$DOT$51166*(2*cosh(v/2)*sin(u)*cos((2$DOT$2*(2*cosh(v/2)*cos(u))--11$DOT$0404)*2*pi*1/22$DOT$0513)-1$DOT$8*(v)*sin((2$DOT$2*(2*cosh(v/2)*cos(u))--11$DOT$0404)*2*pi*1/22$DOT$0513))"],
		"Fz": ["1$DOT$51166*(2*cosh(v/2)*sin(u)*sin((2$DOT$2*(2*cosh(v/2)*cos(u))--11$DOT$0404)*2*pi*1/22$DOT$0513)+1$DOT$8*(v)*cos((2$DOT$2*(2*cosh(v/2)*cos(u))--11$DOT$0404)*2*pi*1/22$DOT$0513))"],
		"Umin": ["-pi"],
		"Umax": ["pi"],
		"Vmin": ["-pi"],
		"Vmax": ["pi"]
	}
},
{
	"Param3D": {
		"Name": ["Pseudo_Helix"],
		"Component": ["Pseudo_Helix"],
		"Fx": ["0$DOT$717627*((1-0$DOT$1*cos(v))*cos(u)*cos(((1-0$DOT$1*cos(v))*sin(u)--1$DOT$1)*2*pi*0$DOT$2/2$DOT$2)-0$DOT$1*(sin(v)+u/1$DOT$7-10)*sin(((1-0$DOT$1*cos(v))*sin(u)--1$DOT$1)*2*pi*0$DOT$2/2$DOT$2))"],
		"Fy": ["(1-0$DOT$1*cos(v))*sin(u)"],
		"Fz": ["0$DOT$717627*((1-0$DOT$1*cos(v))*cos(u)*sin(((1-0$DOT$1*cos(v))*sin(u)--1$DOT$1)*2*pi*0$DOT$2/2$DOT$2)+0$DOT$1*(sin(v)+u/1$DOT$7-10)*cos(((1-0$DOT$1*cos(v))*sin(u)--1$DOT$1)*2*pi*0$DOT$2/2$DOT$2))"],
		"Umin": ["0"],
		"Umax": ["4*pi"],
		"Vmin": ["0"],
		"Vmax": ["2*pi"]
	}
},
{
	"Param3D": {
		"Name": ["Pseudo_Cone"],
		"Component": ["Pseudo_Cone"],
		"Fx": ["u*cos(v)"],
		"Fy": ["0$DOT$848528*(u*sin(v)*cos((u*cos(v)--1)*2*pi*1/2)-u*sin((u*cos(v)--1)*2*pi*1/2))"],
		"Fz": ["0$DOT$848528*(u*sin(v)*sin((u*cos(v)--1)*2*pi*1/2)+u*cos((u*cos(v)--1)*2*pi*1/2))"],
		"Umin": ["-1"],
		"Umax": ["1"],
		"Vmin": ["0"],
		"Vmax": ["2*pi"]
	}
},
{
	"Param3D": {
		"Name": ["Pseudo_Hexagon"],
		"Component": ["Pseudo_Hexagon"],
		"Fx": ["1$DOT$7*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))"],
		"Fy": ["0$DOT$743482*(1$DOT$5*(cos(u)*sin(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))*cos((1$DOT$7*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))--1$DOT$7)*2*pi*0$DOT$3/3$DOT$4)-0$DOT$7*(sin(u)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300))*sin((1$DOT$7*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))--1$DOT$7)*2*pi*0$DOT$3/3$DOT$4))"],
		"Fz": ["0$DOT$743482*(1$DOT$5*(cos(u)*sin(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))*sin((1$DOT$7*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))--1$DOT$7)*2*pi*0$DOT$3/3$DOT$4)+0$DOT$7*(sin(u)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300))*cos((1$DOT$7*(cos(u)*cos(v)*(abs(cos(4*u/4))^300+abs(sin(4*u/4))^300)^(-1/300)*(abs(cos(6*v/4))^400+abs(sin(6*v/4))^400)^(-1/1000))--1$DOT$7)*2*pi*0$DOT$3/3$DOT$4))"],
		"Umin": ["-pi/2"],
		"Umax": ["pi/2"],
		"Vmin": ["0"],
		"Vmax": ["2*pi"]
	}
},
{
	"Param3D": {
		"Name": ["Pseudo_Cube"],
		"Component": ["Pseudo_Cube"],
		"Fx": ["0$DOT$848528*(cos(u)*cos(v)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)*(abs(cos(4*v/4))^100+abs(sin(4*v/4))^100)^(-1/100)*cos((1$DOT$6*(sin(u)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100))--1$DOT$6)*2*pi*0$DOT$3/3$DOT$2)-cos(u)*sin(v)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)*(abs(cos(4*v/4))^100+abs(sin(4*v/4))^100)^(-1/100)*sin((1$DOT$6*(sin(u)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100))--1$DOT$6)*2*pi*0$DOT$3/3$DOT$2))"],
		"Fy": ["0$DOT$848528*(cos(u)*cos(v)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)*(abs(cos(4*v/4))^100+abs(sin(4*v/4))^100)^(-1/100)*sin((1$DOT$6*(sin(u)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100))--1$DOT$6)*2*pi*0$DOT$3/3$DOT$2)+cos(u)*sin(v)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100)*(abs(cos(4*v/4))^100+abs(sin(4*v/4))^100)^(-1/100)*cos((1$DOT$6*(sin(u)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100))--1$DOT$6)*2*pi*0$DOT$3/3$DOT$2))"],
		"Fz": ["1$DOT$6*(sin(u)*(abs(cos(4*u/4))^100+abs(sin(4*u/4))^100)^(-1/100))"],
		"Umin": ["-pi/2"],
		"Umax": ["pi/2"],
		"Vmin": ["0"],
		"Vmax": ["2*pi"]
	}
},
{
	"Param3D": {
		"Name": ["Pseudo_Torus"],
		"Component": ["Pseudo_Torus"],
		"Fx": ["(1+0$DOT$5*cos(u))*cos(v)"],
		"Fy": ["0$DOT$632456*((1+0$DOT$5*cos(u))*sin(v)*cos(((1+0$DOT$5*cos(u))*cos(v)--1$DOT$5)*2*pi*0$DOT$9/3)-0$DOT$5*sin(u)*sin(((1+0$DOT$5*cos(u))*cos(v)--1$DOT$5)*2*pi*0$DOT$9/3))"],
		"Fz": ["0$DOT$632456*((1+0$DOT$5*cos(u))*sin(v)*sin(((1+0$DOT$5*cos(u))*cos(v)--1$DOT$5)*2*pi*0$DOT$9/3)+0$DOT$5*sin(u)*cos(((1+0$DOT$5*cos(u))*cos(v)--1$DOT$5)*2*pi*0$DOT$9/3))"],
		"Umin": ["0"],
		"Umax": ["2*pi"],
		"Vmin": ["0"],
		"Vmax": ["2*pi"]
	}
},
{
	"Param3D": {
		"Name": ["Hurricane"],
		"Component": ["Hurricane"],
		"Fx": ["1*(2*cosh(v/2)*cos(u)*cos((2$DOT$1*(2*cosh(v/2)*sin(u)*sin((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367)+2*(v)*cos((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367))--13$DOT$1947)*2*pi*1$DOT$5/26$DOT$3894)-2$DOT$1*(2*cosh(v/2)*sin(u)*cos((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367)-2*(v)*sin((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367))*sin((2$DOT$1*(2*cosh(v/2)*sin(u)*sin((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367)+2*(v)*cos((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367))--13$DOT$1947)*2*pi*1$DOT$5/26$DOT$3894))"],
		"Fy": ["1*(2*cosh(v/2)*cos(u)*sin((2$DOT$1*(2*cosh(v/2)*sin(u)*sin((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367)+2*(v)*cos((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367))--13$DOT$1947)*2*pi*1$DOT$5/26$DOT$3894)+2$DOT$1*(2*cosh(v/2)*sin(u)*cos((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367)-2*(v)*sin((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367))*cos((2$DOT$1*(2*cosh(v/2)*sin(u)*sin((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367)+2*(v)*cos((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367))--13$DOT$1947)*2*pi*1$DOT$5/26$DOT$3894))"],
		"Fz": ["2$DOT$1*(2*cosh(v/2)*sin(u)*sin((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367)+2*(v)*cos((2*cosh(v/2)*cos(u)--5$DOT$01836)*2*pi*0/10$DOT$0367))"],
		"Umin": ["-pi"],
		"Umax": ["pi"],
		"Vmin": ["-pi"],
		"Vmax": ["pi"]
	}
},
{
	"Param3D": {
		"Name": ["Breather"],
		"Component": ["Breather"],
		"Fx": ["(2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*cos(v)*cos(sqrt(0$DOT$84)*v))-sin(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))"],
		"Fy": ["(2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*sin(v)*cos(sqrt(0$DOT$84)*v))+cos(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))"],
		"Fz": ["-u+(2*0$DOT$84*cosh(0$DOT$4*u)*sinh(0$DOT$4*u))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))"],
		"Umin": ["-13$DOT$2"],
		"Umax": ["13$DOT$2"],
		"Vmin": ["-37$DOT$4"],
		"Vmax": ["37$DOT$4"]
	}
},

{
    "Param3D": {
	"Description":[
		"The formula is: 'Gx': ('Fx(u,
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
            "Thick Parametric Torus"
        ],
        "Component": [
            "Torus_1",
            "Torus_2"
        ],
        "Const": [
            "T=1$DOT$3"
        ],
        "Funct": [
            "Fx=(1+0$DOT$5*cos(u))*cos(v)",
            "Fy=(1+0$DOT$5*cos(u))*sin(v)",
            "Fz=0$DOT$5*sin(u)",
            "a1=(-0$DOT$5*sin(u)*cos(v))",
            "a2=(-0$DOT$5*sin(u)*sin(v))",
            "a3=(0$DOT$5*cos(u))",
            "b1=(-(1+0$DOT$5*cos(u))*sin(v))",
            "b2=((1+0$DOT$5*cos(u))*cos(v))",
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
            "a=0$DOT$2",
            "b=1",
            "c=0$DOT$1",
            "n=2"
        ],
        "Fx": [
            "2*(1-exp(u/(6*pi)))*cos(u)*cos(v/2)^2",
            "((a*(1-v/(2*pi))*(1+cos(u))+c)*cos(n*v))*6+4",
            "2^v*(sin(u)*cos(u))/35",
            "1$DOT$2^v*(sin(u)^2*sin(v))+2"
        ],
        "Fy": [
            "2*(-1+exp(u/(6*pi)))*sin(u)*cos(v/2)^2",
            "((a*(1-v/(2*pi))*(1+cos(u))+c)*sin(n*v))*6+4",
            "2^v*(sin(u)^2*sin(v))/35-4",
            "1$DOT$2^v*(sin(u)*cos(u))+5"
        ],
        "Fz": [
            "1-exp(u/(3*pi))-sin(v)+exp(u/(6*pi))*sin(v)",
            "(b*v/(2*pi)+a*(1-v/(2*pi))*sin(u))*6-6",
            "2^v*(sin(u)^2*cos(v))/35-12",
            "1$DOT$2^v*(sin(u)^2*cos(v))-12"
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
            "Models Intersection"
        ],
        "Component": [
            "Schwarz",
            "Cylinder",
            "Plan"
        ],
        "Cnd": [
            "((x^2+y^2)>$DOT$4)&(x-y-1$DOT$5*z<0)",
            "1>0",
            "1>0"
        ],
        "Fxyz": [
            "cos(x-4*sin(t*pi))+cos(y)+cos(z)",
            "-(x^2+y^2)+$DOT$39",
            "x-y-1$DOT$5*z-$DOT$01"
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
},
        {
            "Param3D": {
                "Name": [
                    "Fresnel Noise"
                ],
                "Component": [
                    "FresnelNoise"
                ],
                "Fx": [
                    "(cos(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8))*(1-NoiseW((cos(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)),
			(sin(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)),
			(sin(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)),
			1,
			2,
			0))"
                ],
                "Fy": [
                    "(sin(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8))*(1-NoiseW((cos(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)),
			(sin(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)),
			(sin(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)),
			1,
			2,
			0))"
                ],
                "Fz": [
                    "(sin(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8))*(1-NoiseW((cos(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)),
			(sin(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)),
			(sin(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)),
			1,
			2,
			0))"
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
        }
,
{
	"Param3D": {
		"Name": ["Torus Noise"],
		"Component": ["TorusNoise"],
		"Fx": ["(1+0$DOT$5*cos(u))*cos(v)*(1-NoiseW((1+0$DOT$5*cos(u))*cos(v),
			(1+0$DOT$5*cos(u))*sin(v),
			0$DOT$5*sin(u),
			1,
			2,
			0))"],
		"Fy": ["(1+0$DOT$5*cos(u))*sin(v)*(1-NoiseW((1+0$DOT$5*cos(u))*cos(v),
			(1+0$DOT$5*cos(u))*sin(v),
			0$DOT$5*sin(u),
			1,
			2,
			0))"],
		"Fz": ["sin(u)*(1-NoiseW((1+0$DOT$5*cos(u))*cos(v),
			(1+0$DOT$5*cos(u))*sin(v),
			0$DOT$5*sin(u),
			1,
			2,
			0))"],
		"Umax": ["2*pi"],
		"Umin": ["0"],
		"Vmax": ["2*pi"],
		"Vmin": ["0"]
	},
	"Texture": {
		"Colors": ["R=2*$DOT$41",
		"G=2*0$DOT$81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
		"B=2*0$DOT$8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
		"T=1"],
		"Name": "PerlinNoise",
		"Noise": "NoiseP(x,
			y,
			z,
			4,
			4,
			$DOT$8)"
	}
},
{
		"Param3D": {
			"Description": [
				"Super Formula by Abderrahman Taha 06/03/2016"
			],
			"Name": [
				"Super Formula"
			],
			"Component": [
				"SuperFormula"
			],
			"Const": [
				"A1=50",
				"B1=1",
				"M1=7",
				"N11=0$DOT$2",
				"N21=1$DOT$7",
				"N31=1$DOT$7",
				"A2=50",
				"B2=1",
				"M2=7",
				"N12=0$DOT$2",
				"N22=1$DOT$7",
				"N32=1$DOT$7"
			],
			"Funct": [
				"Ru= (abs(cos(M1*u/4)*50/A1)^N21+abs(sin(M1*u/4)*50/B1)^N31)^(-1/N11)",
				"Rv= (abs(cos(M2*v/4)*50/A2)^N22+abs(sin(M2*v/4)*50/B2)^N32)^(-1/N12)"
			],
			"Fx": [
				"cos(u)*cos(v)*Ru(u,v,t)*Rv(u,v,t)"
			],
			"Fy": [
				"sin(u)*Ru(u,v,t)"
			],
			"Fz": [
				"cos(u)*sin(v)*Ru(u,v,t)*Rv(u,v,t)"
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
				"100"
			],
			"Min": [
				"1",
				"1",
				"1",
				"1"
			],
			"Name": [
				"A1",
				"A2",
				"B2",
				"B1"
			],
			"Position": [
				"50",
				"50",
				"50",
				"50",
				"54",
				"47",
				"47",
				"45",
				"54",
				"45",
				"45",
				"47"
			],
			"Step": [
				"1",
				"1",
				"1",
				"1"
			]
		}
	},
{
	"Param3D": {
		"Name": ["Breather Noise"],
		"Component": ["BreatherNoise"],
		"Fx": ["((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*cos(v)*cos(sqrt(0$DOT$84)*v))-sin(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2)))*(1-NoiseW(((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*cos(v)*cos(sqrt(0$DOT$84)*v))-sin(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),
			((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*sin(v)*cos(sqrt(0$DOT$84)*v))+cos(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),
			(-u+(2*0$DOT$84*cosh(0$DOT$4*u)*sinh(0$DOT$4*u))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),
			1,
			2,
			0))"],
		"Fy": ["((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*sin(v)*cos(sqrt(0$DOT$84)*v))+cos(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2)))*(1-NoiseW(((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*cos(v)*cos(sqrt(0$DOT$84)*v))-sin(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),
			((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*sin(v)*cos(sqrt(0$DOT$84)*v))+cos(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),
			(-u+(2*0$DOT$84*cosh(0$DOT$4*u)*sinh(0$DOT$4*u))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),
			1,
			2,
			0))"],
		"Fz": ["(-u+(2*0$DOT$84*cosh(0$DOT$4*u)*sinh(0$DOT$4*u))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2)))*(1-NoiseW(((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*cos(v)*cos(sqrt(0$DOT$84)*v))-sin(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),
			((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*sin(v)*cos(sqrt(0$DOT$84)*v))+cos(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),
			(-u+(2*0$DOT$84*cosh(0$DOT$4*u)*sinh(0$DOT$4*u))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),
			1,
			2,
			0))"],
		"Umax": ["13$DOT$2"],
		"Umin": ["-13$DOT$2"],
		"Vmax": ["37$DOT$4"],
		"Vmin": ["-37$DOT$4"]
	}
},
{
		"Iso3D": {
			"Description": ["The Dome-2.0 by Abderrahman Taha 27/02/2016"],
			"Name": ["The Dome-02"],
			"Component": ["Dome"],
			"Cnd": ["sqrt(x*x+y*y+z*z)>S/3"],
			"Const": ["A=4",
			"N1=10",
			"N2=10",
			"R=16"],
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
			"Max": ["20",
			"30",
			"30",
			"30",
			"100"],
			"Min": ["0",
			"0",
			"0",
			"0",
			"0"],
			"Name": ["A",
			"N1",
			"N2",
			"R",
			"S"],
			"Position": ["4",
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
			"73"],
			"Step": ["1",
			"1",
			"1",
			"1",
			"1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Schwarz P Tori-1.0 by Abderrahman Taha 25/02/2016"],
			"Name": ["Schwarz P Tori-1.0"],
			"Component": ["Schwarz P Tori"],
			"Const": ["M=1",
			"N1=15",
			"N2=15",
			"R1=8",
			"R2=15",
			"H=4"],
			"Funct": ["Iso=cos(x)+cos(y)+cos(z)",
			"Ray=$DOT$1*H*x/sqrt(x*x+y*y+z*z)",
			"Iso4= (Iso(x+Ray(sin(x),sin(y),sin(z),t),y+Ray(sin(y),sin(x),sin(z),t), z+Ray(sin(z),sin(y),sin(x),t),t))",
			"Iso5= (Iso(x-Ray(sin(x),sin(y),sin(z),t),y-Ray(sin(y),sin(x),sin(z),t), z-Ray(sin(z),sin(y),sin(x),t),t))",
			"SchwarzP= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"isoTransform=if(x*x<10$DOT$24,SchwarzP(x,y,z,t),1)+$DOT$1*M*exp(x*x-9)",
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
			"Max": ["20",
			"20",
			"20",
			"15",
			"25",
			"30"],
			"Min": ["0",
			"0",
			"0",
			"0",
			"0",
			"0"],
			"Name": ["H",
			"N1",
			"N2",
			"R1",
			"R2",
			"M"],
			"Position": ["4",
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
			"0"],
			"Step": ["1",
			"1",
			"1",
			"1",
			"1",
			"1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Diamond Tori-2.0 by Abderrahman Taha 24/02/2016"],
			"Name": ["Diamond Tori_2"],
			"Component": ["Diamond Tori"],
			"Const": ["M=1",
			"N1=10",
			"N2=10",
			"P=5",
			"R=15"],
			"Funct": ["Diamond=sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
			"isoCondition_0=(x^2-2$DOT$2^2)",
			"isoCondition_1=(x^2-1$DOT$6^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,-Diamond(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+z*z)-P),y,N1*atan2(z,x),t)"],
			"Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-R),N2*atan2(y,x),z,t)"],
			"Xmax": ["25"],
			"Xmin": ["-25"],
			"Ymax": ["25"],
			"Ymin": ["-25"],
			"Zmax": ["10$DOT$5"],
			"Zmin": ["-10$DOT$5"]
		},
		"Sliders": {
			"Max": ["50",
			"10",
			"25",
			"25",
			"25"],
			"Min": ["0",
			"0",
			"0",
			"0",
			"0"],
			"Name": ["M",
			"P",
			"R",
			"N1",
			"N2"],
			"Position": ["1",
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
			"1"],
			"Step": ["1",
			"1",
			"1",
			"1",
			"1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["P_Skeletal Tori-2.0 by Abderrahman Taha 22/02/2016"],
			"Name": ["P_Skeletal Tori_2"],
			"Component": ["P_Skeletal Tori"],
			"Const": ["M=1",
			"N1=15",
			"N2=15",
			"P=5",
			"R=15"],
			"Funct": ["P_Skeletal=cos(x)+cos(y)+cos(z)+0$DOT$51*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+1$DOT$2",
			"isoCondition_0=((x-pi)^2-(pi +$DOT$05)^2)",
			"isoCondition_1=((x-pi)^2-(pi)^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,P_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+z*z)-P),y,N1*atan2(z,x),t)"],
			"Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-R),N2*atan2(y,x),z,t)"],
			"Xmax": ["30"],
			"Xmin": ["-30"],
			"Ymax": ["30"],
			"Ymin": ["-30"],
			"Zmax": ["15"],
			"Zmin": ["-15"]
		},
		"Sliders": {
			"Max": ["50",
			"10",
			"25",
			"25",
			"25"],
			"Min": ["0",
			"0",
			"0",
			"0",
			"0"],
			"Name": ["M",
			"P",
			"R",
			"N1",
			"N2"],
			"Position": ["1",
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
			"11"],
			"Step": ["1",
			"1",
			"1",
			"1",
			"1"]
		}
	},
	{
		"Iso3D": {
			"Description ": ["Fhelix internal function with sliders by Abderrahman Taha 06/02/2016"],
			"Name": ["fhelix"],
			"Component": ["fhelix1"],
			"Fxyz": ["-fhelix1(sqrt(x*x+y*y)-3,Param1*atan2(y,x),z,Param2,Param3,Param4/15,Param5/15,Param6/15,Param7/10,Param8*pi/15)"],
			"Xmax": ["5"],
			"Xmin": ["-5"],
			"Ymax": ["5"],
			"Ymin": ["-5"],
			"Zmax": ["2$DOT$2"],
			"Zmin": ["-2$DOT$2"]
		},
		"Sliders": {
			"Max": ["10",
			" 10",
			" 10",
			" 30",
			" 30",
			" 30",
			" 20",
			" 30"],
			"Min": ["0",
			" 0",
			" 0",
			" 0",
			" 0",
			" 0",
			" 0",
			" 0"],
			"Name": ["Param1",
			" Param2",
			" Param3",
			" Param4",
			" Param5",
			" Param6",
			" Param7",
			" Param8"],
			"Position": ["2",
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
			"21"],
			"Step": ["1",
			" 1",
			" 1",
			" 1",
			" 1",
			" 1",
			" 1",
			" 1"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Inka Star by Abderrahman Taha 06/02/2016"],
			"Name": ["Inka Star"],
			"Component": ["InkaStar"],
			"Const": ["cu=0$DOT$001",
			"cv=0$DOT$001",
			"N=2"],
			"Funct": ["Thickness= ((sin(15*u)*cos(15*u)))^5 + (sin(5*N*v))",
			"Fx=-cos(u+v)/(sqrt(2$DOT$)+cos(v-u))",
			"Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
			"Fz=sin(u+v)/(sqrt(2$DOT$)+cos(v-u))",
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
			"Description": ["Strapped Torus (implicit version) by Abderrahman Taha 06/02/2016"],
			"Name": ["Strapped Torus"],
			"Component": ["Strapped Torus"],
			"Const": ["A = 2",
			"B = 2",
			"C = 23/15",
			"D = 9/15",
			"E = 3/15",
			"F = 20/10",
			"G = 3*pi/15"],
			"Funct": ["X = x",
			"Z = z",
			"r = sqrt(X(x,y,z,t) * X(x,y,z,t) + Z(x,y,z,t) * Z(x,y,z,t))",
			"X= if ((X(x,y,z,t) = 0) & (Z(x,y,z,t) = 0),         0$DOT$000001,X(x,y,z,t))",
			"th = atan2(Z(x,y,z,t), X(x,y,z,t))",
			"th = ((th(x,y,z,t) * A + y * B * A) % (2*pi))",
			"th = if (th(x,y,z,t) < 0,        th(x,y,z,t)+2*pi, th(x,y,z,t))",
			"Z = (th(x,y,z,t) - pi) / E / (B * A)",
			"X = r(x,y,z,t) - D",
			"Z = if ((F = 1 | G = 0)=0, X(x,y,z,t) * sin(G * pi/180) + Z(x,y,z,t) * cos(G * pi/180) , Z(x,y,z,t))",
			"X = if ((F = 1 | G = 0)=0, X(x,y,z,t) * cos(G * pi/180) - Z(x,y,z,t) * sin(G * pi/180) , X(x,y,z,t))",
			"r2 = if (F = 1,        sqrt(X(x,y,z,t) * X(x,y,z,t) + Z(x,y,z,t) * Z(x,y,z,t)),                if ((F = 0)=0,                        pow((pow(abs(X(x,y,z,t)), 2/F) + pow(abs(Z(x,y,z,t)), 2/F)), F *$DOT$5),                        if (abs(X(x,y,z,t)) > abs(Z(x,y,z,t)) ,                     abs(X(x,y,z,t)) ,   abs(Z(x,y,z,t))            )    )          )",
			"r3 = if((D + r(x,y,z,t)) < r2(x,y,z,t) , (D + r(x,y,z,t)) , r2(x,y,z,t))",
			"helix = (-C + r3(x,y,z,t))"],
			"Fxyz": ["-helix(sqrt(x*x+y*y)-3,2*atan2(y,x),z,t)"],
			"Xmax": ["5"],
			"Xmin": ["-5"],
			"Ymax": ["5"],
			"Ymin": ["-5"],
			"Zmax": ["2"],
			"Zmin": ["-2"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Spiky Fresnel-01 by Abderrahman Taha 5/02/2015"],
			"Name": ["Spiky Fresnel"],
			"Component": ["SpikyFresnel"],
			"Const": ["cu=0$DOT$001",
			"cv=0$DOT$001"],
			"Funct": ["Tickness= -$DOT$3*(abs(sin(25*u)*cos(27*v)))^(3*sin(17*u-15*v))^2",
			"Fx=(cos(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8))",
			"Fy= sin(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)",
			"Fz= sin(u)*cos(v)/(-2$DOT$*sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))*cos((acos(-(-0$DOT$941/6$DOT$+0$DOT$374*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4)-1$DOT$309/6$DOT$*((cos(u)^6+sin(u)^6)*cos(v)^6+sin(v)^6)-1$DOT$221*cos(u)^2*cos(v)^4*sin(u)^2*sin(v)^2)/sqrt(0$DOT$965/3$DOT$-0$DOT$935/3$DOT$*((cos(u)^4+sin(u)^4)*cos(v)^4+sin(v)^4))^3)-pi)/3$DOT$)+0$DOT$8)",
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
			"Gz=Fz(u,v,t)+Tickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
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
			"Name": ["Exotic flower"],
			"Component": ["ExoticFlower"],
			"Const": ["cu=0$DOT$001",
			"cv=0$DOT$001"],
			"Description ": ["Exotic flower-01 by Abderrahman Taha 30/1/2015"],
			"Funct": ["Thickness= -$DOT$6*(abs(sin(15*u)*cos(15*v)))^(3*sin(7*u-5*v))^2",
			"Fx=-(cos(u+v)/(sqrt(2$DOT$)+cos(v-u)))",
			"Fy=sin(v-u)/(sqrt(2$DOT$)+cos(v-u))",
			"Fz=sin(u+v)/(sqrt(2$DOT$)+cos(v-u))",
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
			"Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
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
			"Description": ["The Dome-1$DOT$0 by Abderrahman Taha 12/01/2015"],
			"Name": ["The Dome"],
			"Component": ["Dome"],
			"Const": ["cx=0$DOT$001",
			"cy=0$DOT$001",
			"cz=0$DOT$001"],
			"Funct": ["Scherk=sinh(x)*sinh(y)-4*sin(z)",
			"Scherk2=Scherk(10*atan2(x,sqrt(y*y+z*z)),(sqrt(x*x+y*y+z*z)-16),10*atan2(z,y),t)",
			"Tickness2=($DOT$6)",
			"IsoExterior=Scherk2(x,y,z,t)",
			"DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
			"DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
			"DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
			"Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
			"Iso3=(IsoExterior(x-DFx2(x,y,z,t)*Tickness2(x,y,z,t)/Rapport2(x,y,z,t),y-DFy2(x,y,z,t)*Tickness2(x,y,z,t)/Rapport2(x,y,z,t),z-DFz2(x,y,z,t)*Tickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
			"Iso2=(IsoExterior(x+DFx2(x,y,z,t)*Tickness2(x,y,z,t)/Rapport2(x,y,z,t),y+DFy2(x,y,z,t)*Tickness2(x,y,z,t)/Rapport2(x,y,z,t),z+DFz2(x,y,z,t)*Tickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
			"TickIsoExterior=(Iso2(x,y,z,t)*Iso3(x,y,z,t))"],
			"Fxyz": ["if((sqrt(x*x+y*y+z*z)-24)<0,TickIsoExterior(x,y,z,t),1)"],
			"Xmax": ["18"],
			"Xmin": ["-18"],
			"Ymax": ["27"],
			"Ymin": ["-27"],
			"Zmax": ["27"],
			"Zmin": ["-27"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Wall Pattern Torus-03"],
			"Description": ["Wall Pattern Torus-03 by Abderrahman Taha 10/01/2016"],
			"Component": ["f_hex_y"],
			"Funct": ["x1=abs((abs(x) % sqrt(3$DOT$0))-sqrt(3$DOT$0)/2)",
			"y1 = abs((abs(y) % 3)-1$DOT$5)",
			"x2=sqrt(3$DOT$0)/2-x1(x,y,z,t)",
			"y2=1$DOT$5-y1(x,y,z,t)",
			"x1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), x2(x,y,z,t), x1(x,y,z,t))",
			"y1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), y2(x,y,z,t), y1(x,y,z,t))",
			"th=atan2(y1(x,y,z,t),x1(x,y,z,t))",
			"th = if (th(x,y,z,t) < 0, th(x,y,z,t)+2*pi, th(x,y,z,t))",
			"f_hex_y = if(th(x,y,z,t)<pi/6, y1(x,y,z,t), abs(-sin(pi/3)*x1(x,y,z,t)+cos(pi/3)*y1(x,y,z,t)))",
			"f_hex_y_1=if(abs(z)<$DOT$06,f_hex_y(x,y,z,0)-$DOT$08,1)",
			"Cylinder=-f_hex_y_1(x,4$DOT$3*atan2(z,y),sqrt(y*y+z*z)-1$DOT$5,t)",
			"Sphere=f_hex_y_1(6$DOT$3*atan2(x,sqrt(y*y+z*z)),3$DOT$815*atan2(z,y),sqrt(y*y+z*z+x*x)-4$DOT$6,t)",
			"Torus=Cylinder(6$DOT$03*atan2(y,x),sqrt(x*x+y*y)-4,z,t)"],
			"Fxyz": ["Torus(x,y,z,t)"],
			"Xmax": ["5$DOT$7"],
			"Xmin": ["-5$DOT$7"],
			"Ymax": ["5$DOT$7"],
			"Ymin": ["-5$DOT$7"],
			"Zmax": ["1$DOT$6"],
			"Zmin": ["-1$DOT$6"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Wall Pattern Sphere-03"],
			"Description": ["Wall Pattern Sphere-03 by Abderrahman Taha 10/01/2016"],
			"Component": ["f_hex_y"],
			"Funct": ["x1=abs((abs(x) % sqrt(3$DOT$0))-sqrt(3$DOT$0)/2)",
			"y1 = abs((abs(y) % 3)-1$DOT$5)",
			"x2=sqrt(3$DOT$0)/2-x1(x,y,z,t)",
			"y2=1$DOT$5-y1(x,y,z,t)",
			"x1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), x2(x,y,z,t), x1(x,y,z,t))",
			"y1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), y2(x,y,z,t), y1(x,y,z,t))",
			"th=atan2(y1(x,y,z,t),x1(x,y,z,t))",
			"th = if (th(x,y,z,t) < 0, th(x,y,z,t)+2*pi, th(x,y,z,t))",
			"f_hex_y = if(th(x,y,z,t)<pi/6, y1(x,y,z,t), abs(-sin(pi/3)*x1(x,y,z,t)+cos(pi/3)*y1(x,y,z,t)))",
			"f_hex_y_1=if(abs(z)<$DOT$06,f_hex_y(x,y,z,0)-$DOT$08,1)",
			"Cylinder=-f_hex_y_1(x,4$DOT$3*atan2(z,y),sqrt(y*y+z*z)-1$DOT$5,t)",
			"Sphere=f_hex_y_1(6$DOT$3*atan2(x,sqrt(y*y+z*z)),3$DOT$815*atan2(z,y),sqrt(y*y+z*z+x*x)-4$DOT$6,t)",
			"Torus=Cylinder(6$DOT$03*atan2(y,x),sqrt(x*x+y*y)-4,z,t)"],
			"Fxyz": ["Sphere(x,y,z,t)"],
			"Xmax": ["4$DOT$8"],
			"Xmin": ["-4$DOT$8"],
			"Ymax": ["4$DOT$8"],
			"Ymin": ["-4$DOT$8"],
			"Zmax": ["4$DOT$8"],
			"Zmin": ["-4$DOT$8"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Wall Pattern Sphere-02 by Abderrahman Taha 09/01/2016$DOT$ The f_hex_y formula is from the PovRay team: http://www.povray.org/ "],
			"Name": ["Wall Pattern Sphere-02"],
			"Component": ["f_hex_y"],
			"Funct": ["x1=abs((abs(x) % sqrt(3$DOT$0))-sqrt(3$DOT$0)/2)",
			"y1 = abs((abs(y) % 3)-1$DOT$5)",
			"x2=sqrt(3$DOT$0)/2-x1(x,y,z,t)",
			"y2=1$DOT$5-y1(x,y,z,t)",
			"x1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), x2(x,y,z,t), x1(x,y,z,t))",
			"y1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), y2(x,y,z,t), y1(x,y,z,t))",
			"th=atan2(y1(x,y,z,t),x1(x,y,z,t))",
			"th = if (th(x,y,z,t) < 0, th(x,y,z,t)+2*pi, th(x,y,z,t))",
			"f_hex_y = if(th(x,y,z,t)<pi/6, y1(x,y,z,t), abs(-sin(pi/3)*x1(x,y,z,t)+cos(pi/3)*y1(x,y,z,t)))",
			"f_hex_y_1=if(abs(z)<$DOT$06,f_hex_y(sqrt(x*x+y*y)-2,4$DOT$75*atan2(y,x),z,0)-$DOT$08,1)",
			"Cylinder=-f_hex_y_1(x,4$DOT$3*atan2(z,y),sqrt(y*y+z*z)-1$DOT$5,t)",
			"Sphere=f_hex_y_1(4*atan2(x,sqrt(y*y+z*z)),4$DOT$5*atan2(z,y),sqrt(y*y+z*z+x*x)-4$DOT$5,t)",
			"Torus=Cylinder(8*atan2(y,x),sqrt(x*x+y*y)-4,z,t)"],
			"Fxyz": ["Sphere(x,y,z,t)"],
			"Xmax": ["4$DOT$8"],
			"Xmin": ["-4$DOT$8"],
			"Ymax": ["4$DOT$8"],
			"Ymin": ["-4$DOT$8"],
			"Zmax": ["4$DOT$8"],
			"Zmin": ["-4$DOT$8"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Wall Pattern Sphere-01 by Abderrahman Taha 05/01/2016$DOT$ The f_hex_y formula is from the PovRay team: http://www.povray.org/ "],
			"Name": ["Wall Pattern Sphere-01"],
			"Component": ["f_hex_y"],
			"Funct": ["x1=abs((abs(x) % sqrt(3$DOT$0))-sqrt(3$DOT$0)/2)",
			"y1 = abs((abs(y) % 3)-1$DOT$5)",
			"x2=sqrt(3$DOT$0)/2-x1(x,y,z,t)",
			"y2=1$DOT$5-y1(x,y,z,t)",
			"x1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), x2(x,y,z,t), x1(x,y,z,t))",
			"y1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), y2(x,y,z,t), y1(x,y,z,t))",
			"th=atan2(y1(x,y,z,t),x1(x,y,z,t))",
			"th = if (th(x,y,z,t) < 0, th(x,y,z,t)+2*pi, th(x,y,z,t))",
			"f_hex_y = if(th(x,y,z,t)<pi/6, y1(x,y,z,t), abs(-sin(pi/3)*x1(x,y,z,t)+cos(pi/3)*y1(x,y,z,t)))",
			"f_hex_y_1=if(z*z-$DOT$01 < 0,f_hex_y(sin(x),1$DOT$3*sin(y),2*z,0),1)-$DOT$1",
			"Cylinder=-f_hex_y_1(x,4$DOT$3*atan2(z,y),sqrt(y*y+z*z)-1$DOT$5,t)",
			"Sphere=f_hex_y_1(4*atan2(x,sqrt(y*y+z*z)),4$DOT$5*atan2(z,y),sqrt(y*y+z*z+x*x)-4$DOT$5,t)",
			"Torus=Cylinder(8*atan2(y,x),sqrt(x*x+y*y)-4,z,t)"],
			"Fxyz": ["Sphere(x,y,z,t)"],
			"Xmax": ["4$DOT$6"],
			"Xmin": ["-4$DOT$6"],
			"Ymax": ["4$DOT$6"],
			"Ymin": ["-4$DOT$6"],
			"Zmax": ["4$DOT$6"],
			"Zmin": ["-4$DOT$6"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Wall Pattern Torus-01 by Abderrahman Taha 05/01/2016$DOT$ The f_hex_y formula is from the PovRay team: http://www.povray.org/ "],
			"Name": ["Wall Pattern Torus-01"],
			"Component": ["f_hex_y"],
			"Funct": ["x1=abs((abs(x) % sqrt(3$DOT$0))-sqrt(3$DOT$0)/2)",
			"y1 = abs((abs(y) % 3)-1$DOT$5)",
			"x2=sqrt(3$DOT$0)/2-x1(x,y,z,t)",
			"y2=1$DOT$5-y1(x,y,z,t)",
			"x1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), x2(x,y,z,t), x1(x,y,z,t))",
			"y1=if ((x1(x,y,z,t)*x1(x,y,z,t)+y1(x,y,z,t)*y1(x,y,z,t))>(x2(x,y,z,t)*x2(x,y,z,t)+y2(x,y,z,t)*y2(x,y,z,t)), y2(x,y,z,t), y1(x,y,z,t))",
			"th=atan2(y1(x,y,z,t),x1(x,y,z,t))",
			"th = if (th(x,y,z,t) < 0, th(x,y,z,t)+2*pi, th(x,y,z,t))",
			"f_hex_y = if(th(x,y,z,t)<pi/6, y1(x,y,z,t), abs(-sin(pi/3)*x1(x,y,z,t)+cos(pi/3)*y1(x,y,z,t)))",
			"f_hex_y_1=if(z*z-$DOT$01 < 0,f_hex_y(sin(x),1$DOT$3*sin(y),2*z,0),1)-$DOT$1",
			"Cylinder=-f_hex_y_1(x,4$DOT$3*atan2(z,y),sqrt(y*y+z*z)-1$DOT$5,t)",
			"Sphere=f_hex_y_1(4*atan2(x,sqrt(y*y+z*z)),4$DOT$3*atan2(z,y),sqrt(y*y+z*z+x*x)-4$DOT$5,t)",
			"Torus=Cylinder(8*atan2(y,x),sqrt(x*x+y*y)-4,z,t)"],
			"Fxyz": ["Torus(x,y,z,t)"],
			"Xmax": ["6"],
			"Xmin": ["-6"],
			"Ymax": ["6"],
			"Ymin": ["-6"],
			"Zmax": ["1$DOT$6"],
			"Zmin": ["-1$DOT$6"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Interlocked Torus-01 by Abderrahman Taha 22/12/2015$DOT$ The Helix formula is from the PovRay team: http://www.povray.org/ "],
			"Name": ["Interlocked Torus_01"],
			"Component": ["Interlocked Torus"],
			"Const": ["A = 4",
			"B = 1",
			"C = $DOT$5",
			"D = 1",
			"E = 1",
			"F = 1",
			"G = 30"],
			"Funct": ["X = x",
			"Z = z",
			"r = sqrt(X(x,y,z,t) * X(x,y,z,t) + Z(x,y,z,t) * Z(x,y,z,t))",
			"X= if ((X(x,y,z,t) = 0) & (Z(x,y,z,t) = 0),0$DOT$001,X(x,y,z,t))",
			"th = atan2(Z(x,y,z,t), X(x,y,z,t))",
			"th = ((th(x,y,z,t) * A + y * B * A) % (2*pi))",
			"th = if (th(x,y,z,t) < 0,        th(x,y,z,t)+2*pi, th(x,y,z,t))",
			"Z = (th(x,y,z,t) - pi) / E / (B * A)",
			"X = r(x,y,z,t) - D",
			"Z = if ((F = 1 | G = 0)=0, X(x,y,z,t) * sin(G * pi/180) + Z(x,y,z,t) * cos(G * pi/180) , Z(x,y,z,t))",
			"X = if ((F = 1 | G = 0)=0, X(x,y,z,t) * cos(G * pi/180) - Z(x,y,z,t) * sin(G * pi/180) , X(x,y,z,t))",
			"r2 = if (F = 1,        sqrt(X(x,y,z,t) * X(x,y,z,t) + Z(x,y,z,t) * Z(x,y,z,t)),                if ((F = 0)=0,                        pow((pow(abs(X(x,y,z,t)), 2/F) + pow(abs(Z(x,y,z,t)), 2/F)), F *$DOT$5),                        if (abs(X(x,y,z,t)) > abs(Z(x,y,z,t)) ,                     abs(X(x,y,z,t)) ,   abs(Z(x,y,z,t))            )    )          )",
			"r3 = if((D + r(x,y,z,t)) < r2(x,y,z,t) , (D + r(x,y,z,t)) , r2(x,y,z,t))",
			"helix = (-C + r3(x,y,z,t))"],
			"Fxyz": ["-helix(sqrt(x*x+y*y)-3,2*atan2(y,x),z,t)"],
			"Xmax": ["5"],
			"Xmin": ["-5"],
			"Ymax": ["5"],
			"Ymin": ["-5"],
			"Zmax": ["2"],
			"Zmin": ["-2"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=0$DOT$81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))+$DOT$3",
			"B=0$DOT$8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"T=1"],
			"Name": "WorleyNoise",
			"Noise": "NoiseW(2*x,2*y,2*z,4,2,0)+NoiseP(2*x,2*y,2*z,4,12,0$DOT$1)"
		}
	},
	{
		"Iso3D": {
			"Description": ["Perlin Schwarz_01 by Abderrahman Taha 26/12/2015$DOT$"],
			"Name": ["Perlin Schwarz"],
			"Component": ["PerlinSchwarz"],
			"Funct": ["Schwarz=cos(x)+cos(y)+cos(z)"],
			"Fxyz": ["Schwarz(x,y,z,t)-NoiseP(x,y,z,4,11,$DOT$1)"],
			"Xmax": ["4"],
			"Xmin": ["-4"],
			"Ymax": ["4"],
			"Ymin": ["-4"],
			"Zmax": ["4"],
			"Zmin": ["-4"]
		},
		"Texture": {
			"Colors": ["R=$DOT$82",
			"G=1$DOT$62*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"B=1$DOT$72*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"T=1"],
			"Name": "Perlin",
			"Noise": "NoiseP(x,y,z,4,11,$DOT$1)"
		}
	},
	{
		"Iso3D": {
			"Description": ["Wired Torus_01 by Abderrahman Taha 26/12/2015$DOT$ The mesh formula is from the PovRay team: http://www.povray.org/ "],
			"Name": ["Wired Torus_01"],
			"Component": ["Wired Torus"],
			"Const": ["A=$DOT$2",
			"B=$DOT$2",
			"C=1",
			"D=$DOT$04",
			"E=1",
			"th=pi/A",
			"ph=pi/B"],
			"Funct": ["r=(x%(A*2))",
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
			"fmesh1=-fmesh0(atan2(y,x),sqrt(x*x+y*y)-1,z,t)+0$DOT$03",
			"fmesh2=fmesh1(sqrt(x*x+z*z)-2,y,atan2(z,x),t)"],
			"Fxyz": ["fmesh2(x,y,z,t)"],
			"Xmax": ["3$DOT$1"],
			"Xmin": ["-3$DOT$1"],
			"Ymax": ["1$DOT$1"],
			"Ymin": ["-1$DOT$1"],
			"Zmax": ["3$DOT$1"],
			"Zmin": ["-3$DOT$1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Wired Sphere-01 by Abderrahman Taha 25/12/2015$DOT$ The mesh formula is from the PovRay team: http://www.povray.org/ "],
			"Name": ["Wired Sphere_01"],
			"Component": ["Wired Sphere"],
			"Const": ["A = $DOT$15",
			"B = $DOT$15",
			"C = 1",
			"D = $DOT$02",
			"E = 1",
			"th = pi / A",
			"ph = pi/ B"],
			"Funct": ["r = (x % (A * 2))",
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
			"fmesh0 = max( -sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t)), temp(x,y,z,t)) +0$DOT$03",
			"fmesh0= fmesh0(atan2(y,x),sqrt(x*x+y*y+z*z) -1,atan2(z,sqrt(x*x+y*y)),t)"],
			"Fxyz": ["fmesh0(x,y,z,t)"],
			"Xmax": ["1$DOT$1"],
			"Xmin": ["-1$DOT$1"],
			"Ymax": ["1$DOT$1"],
			"Ymin": ["-1$DOT$1"],
			"Zmax": ["1$DOT$1"],
			"Zmin": ["-1$DOT$1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Straw Basket-01 by Abderrahman Taha 22/12/2015$DOT$ The mesh formula is from the PovRay team: http://www.povray.org/ "],
			"Name": ["Straw Basket_01"],
			"Component": ["Straw Basket"],
			"Const": ["A = $DOT$5",
			"B = $DOT$2",
			"C = 1",
			"D = $DOT$09",
			"E = 1",
			"th = pi / A",
			"ph = pi/ B"],
			"Funct": ["r = (x % (A * 2))",
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
			"fmesh0 = max( -sqrt(r2(x,y,z,t) * r2(x,y,z,t) + r(x,y,z,t) * r(x,y,z,t)), temp(x,y,z,t)) +0$DOT$08",
			"fmesh0= if(atan2(z,sqrt(x*x+y*y)) < $DOT$89, fmesh0(atan2(y,x),sqrt(x*x+y*y+z*z) -4,atan2(z,sqrt(x*x+y*y)),t), 1)*(atan2(z,sqrt(x*x+y*y)) < $DOT$89)"],
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
			"Description": ["Mesh Torus_01 by Abderrahman Taha 22/12/2015$DOT$ The mesh formula is from the PovRay team: http://www.povray.org/ "],
			"Name": ["Mesh Torus_01"],
			"Component": ["Mesh Torus"],
			"Const": ["A = $DOT$5",
			"B = $DOT$3",
			"C = 1",
			"D = $DOT$1",
			"E = 1",
			"th = pi / A",
			"ph = pi/ B"],
			"Funct": ["r = (x % (A * 2))",
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
			"fmesh1= -fmesh0(atan2(y,x),sqrt(x*x+y*y)-4,z,t) +0$DOT$08",
			"fmesh2= fmesh1(sqrt(x*x+z*z)-7,y,2*atan2(z,x),t)"],
			"Fxyz": ["  fmesh2(x,y,z,t)"],
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
			"Component": ["Bottle shape"],
			"Description ": ["Bottle shape surface (found by Robert Israel) by Abderrahman Taha 14/12/2015"],
			"Fx": [" (-2/15)*(cos(u)*(3*cos(v)-30*sin(u) + 90*cos(u)^4*sin(u) -60*cos(u)^6*sin(u) +5*cos(u)*cos(v)*sin(u))) "],
			"Fy": [" (-1/15)*sin(u)*(3*cos(v)-3*cos(u)^2*cos(v)-48*cos(u)^4*cos(v)+48*cos(u)^6 *cos(v)-60*sin(u)+5*cos(u)*cos(v)*sin(u)-5*cos(u)^3*cos(v)*sin(u) -80*cos(u)^5*cos(v)*sin(u)+80*cos(u)^7*cos(v)*sin(u) ) "],
			"Fz": [" (2/15)*(3+5*cos(u)*sin(u))*sin(v) "],
			"Name": ["Bottle shape"],
			"Umax": ["pi"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=$DOT$8*abs(cos((pi*(x*x+y*y+z*z))))",
			"B=$DOT$6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
			"T=1"],
			"Name": "Dream",
			"Noise": "NoiseW(2*x,2*y,2*z,8,1,0)"
		}
	},
	{
		"Param3D": {
			"Description ": ["Richmond polar_2  parametric surface by Abderrahman Taha 14/12/2015"],
			"Name": ["Richmond polar_2"],
			"Component": ["RichmondPolar"],
			"Fx": ["-cos(v)/(2*u) - u^3*cos(3*v)/6"],
			"Fy": ["-sin(v)/(2*u) + u^3*sin(3*v)/6"],
			"Fz": ["u*cos(v)*sin(v)"],
			"Umax": ["1$DOT$3"],
			"Umin": ["0$DOT$3"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=$DOT$8*abs(cos((pi*(x*x+y*y+z*z))))",
			"B=$DOT$6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
			"T=1"],
			"Name": "Dream",
			"Noise": "NoiseW(4*x,4*y,4*z,8,1,0)"
		}
	},
	{
		"Iso3D": {
			"Description": ["Schwarz P Sphere_2 by Abderrahman Taha 13/12/2015"],
			"Name": ["Schwarz P Sphere_2"],
			"Component": ["Schwarz P Sphere"],
			"Const": ["M=1",
			"N=10"],
			"Funct": ["Iso=cos(x)+cos(y)+cos(z)",
			"Iso4= (Iso(x+sin(x)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"Iso5= (Iso(x-sin(x)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y-sin(y)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z-sin(z)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"TickIso2= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"SchwarzP= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"isoCondition_0=(x^2-4$DOT$8^2)",
			"isoCondition_1=(x^2-4$DOT$6^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,SchwarzP(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),N*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"],
			"Fxyz": ["-isoTransform2(x,y,z,t)"],
			"Xmax": ["18"],
			"Xmin": ["-18"],
			"Ymax": ["18"],
			"Ymin": ["-18"],
			"Zmax": ["18"],
			"Zmin": ["-18"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Under Sea by Abderrahman Taha 12/12/2015"],
			"Name": ["Under The Sea"],
			"Component": ["UnderSea"],
			"Const": ["M=2",
			"N=5"],
			"Fx": ["u*cos(v)"],
			"Fy": ["u*sin(v)"],
			"Fz": ["exp(-u*u) * (sin(M*pi*(u)) -u*cos(N*v))"],
			"Umax": ["2"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=1$DOT$5*$DOT$41",
			"G=2*0$DOT$81*abs(cos((x*x+y*y+z*z)/2) *sin((x*x+y*y+z*z)/2))",
			"B=2*0$DOT$8601*abs(cos((x*x+y*y+z*z)/2) *cos((x*x+y*y+z*z)/2) *sin((x*x+y*y+z*z)/2))",
			"T=1"],
			"Name": "WorleyNoise",
			"Noise": "NoiseW(4*x,4*y,4*z,4,2,0) +NoiseW(4*x,4*y,4*z,4,12,0$DOT$1)"
		}
	},
	{
		"Iso3D": {
			"Name": ["HexaGrid Torus_2"],
			"Component": ["HexaGrid Torus"],
			"Const": ["N=3"],
			"Description ": [" HexaGrid Torus_2 by Aberrahman Taha 11/12/2015. Reference: PG_HexaGridCylinder 12/2012 Gerd Platl"],
			"Funct": ["HexaGrid=-0$DOT$55-88*(sqrt(x*x+y*y)-2)^2 -cos( 8*z) -cos(14*atan2(y,x) -4*z) -cos(14*atan2(y,x) +4*z) -0$DOT$6*( cos( 28*atan2(y,x)) +cos(12*z -14*atan2(y,x)) +cos(12*z +14*atan2(y,x)))"],
			"Fxyz": ["HexaGrid((sqrt(x*x+z*z)-4),y,N*atan2(z,x),t)"],
			"Xmax": [" 6$DOT$2"],
			"Xmin": ["-6$DOT$2 "],
			"Ymax": ["4$DOT$5"],
			"Ymin": ["-4$DOT$5"],
			"Zmax": [" 6$DOT$2"],
			"Zmin": ["-6$DOT$2"]
		}
	},
	{
		"Iso3D": {
			"Description ": [" HexaGrid Torus by Aberrahman Taha 11/12/2015. Reference: PG_HexaGridCylinder3 12/2012 Gerd Platl, http://k3dsurf.s4.bizhat.com/viewtopic.php… "],
			"Name": ["HexaGrid Torus"],
			"Component": ["HexaGrid Torus"],
			"Funct": ["HexaGrid=-0$DOT$5-88*(sqrt(x*x+y*y)-2)^2-cos( 8*z)-cos(14*atan2(y,x) -4*z)-cos(14*atan2(y,x) +4*z)-0$DOT$12*( cos( 28*atan2(y,x))+cos(12*z -14*atan2(y,x))+cos(12*z +14*atan2(y,x)))"],
			"Fxyz": ["HexaGrid((sqrt(x*x+z*z)-4),y,3*atan2(z,x),t)"],
			"Xmax": [" 6$DOT$2"],
			"Xmin": ["-6$DOT$2 "],
			"Ymax": [" 4$DOT$5"],
			"Ymin": ["-4$DOT$5 "],
			"Zmax": [" 6$DOT$2"],
			"Zmin": ["-6$DOT$2 "]
		}
	},
	{
		"Iso3D": {
			"Description": ["Menger L4 SchwarzP by Abderrahman Taha 11/12/2015"],
			"Name": ["Menger_4 SchwarzP"],
			"Component": ["Menger SchwarzP"],
			"Fxyz": ["if(-(Dx+Dy+Dz-1$DOT$02)*(((abs(x)>1/3|abs(y)>1/3)*(abs(z)>1/3|abs(y)>1/3)*(abs(x)>1/3|abs(z)>1/3))*((Cx*(Cy+Cz)+Cz*Cy)=0)*((Bx*(By+Bz)+Bz*By)=0)*((Ax*(Ay+Az)+Az*Ay)=0)),(cos(254$DOT$469*(x+Ex*0$DOT$002/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(254$DOT$469*(y+Ey*0$DOT$002/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(254$DOT$469*(z+Ez*0$DOT$002/sqrt(Ex*Ex+Ey*Ey+Ez*Ez))))*(cos(254$DOT$469*(x-Ex*0$DOT$002/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(254$DOT$469*(y-Ey*0$DOT$002/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(254$DOT$469*(z-Ez*0$DOT$002/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)"],
			"Varu": ["A=((abs(u-2/3)<1/81)+(abs(u-20/27)<1/81)+(abs(u-16/27)<1/81)+(abs(u-8/9)<1/81)+(abs(u-26/27)<1/81)+(abs(u-22/27)<1/81)+(abs(u-4/9)<1/81)+(abs(u-14/27)<1/81)+(abs(u-10/27)<1/81)+(abs(u+2/3)<1/81)+(abs(u+16/27)<1/81)+(abs(u+20/27)<1/81)+(abs(u+4/9)<1/81)+(abs(u+10/27)<1/81)+(abs(u+14/27)<1/81)+(abs(u+8/9)<1/81)+(abs(u+22/27)<1/81)+(abs(u+26/27)<1/81)+(abs(u)<1/81)+(abs(u-2/27)<1/81)+(abs(u+2/27)<1/81)+(abs(u-2/9)<1/81)+(abs(u-8/27)<1/81)+(abs(u-4/27)<1/81)+(abs(u+2/9)<1/81)+(abs(u+4/27)<1/81)+(abs(u+8/27)<1/81))",
			"B=((abs(u-2/3)<1/27)+(abs(u-8/9)<1/27)+(abs(u-4/9)<1/27)+(abs(u+2/3)<1/27)+(abs(u+4/9)<1/27)+(abs(u+8/9)<1/27)+(abs(u)<1/27)+(abs(u-2/9)<1/27)+(abs(u+2/9)<1/27))",
			"C=((abs(u-2/3)<1/9)+(abs(u+2/3)<1/9)+(abs(u)<1/9))",
			"D=u^600",
			"E=sin(254$DOT$469*u)"],
			"Xmax": ["1$DOT$0005"],
			"Xmin": ["0$DOT$3333"],
			"Ymax": ["1$DOT$0005"],
			"Ymin": ["0$DOT$3333"],
			"Zmax": ["1$DOT$0005"],
			"Zmin": ["0$DOT$3333"]
		},
		"Texture": {
			"Colors": ["R=$DOT$6*sqrt(4*x^40+y^4+z^4)",
			"G=$DOT$3*sqrt(x^4+y^4+4*z^20)",
			"B=$DOT$4*sqrt(x^4+4*y^20+z^4)",
			"T=1"],
			"Name": "Granit_2",
			"Noise": "1"
		}
	},
	{
		"Iso3D": {
			"Description": ["Skeletal SchwarzP Tori_2 by Abderrahman Taha 10/12/2015"],
			"Name": ["Skeletal SchwarzP Tori_2"],
			"Component": ["Skeletal SchwarzP Tori"],
			"Const": ["M=$DOT$2",
			"N=15",
			"T=1",
			"S=pi"],
			"Funct": ["Iso=cos(x)+cos(y)+cos(z)",
			"Iso2= (Iso(x+t*sin(x)*1$DOT$2/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+t*sin(y)*1$DOT$2/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+t*sin(z)*1$DOT$2/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"SchwarzP= (-Iso2(x,y,z,t))",
			"isoCondition_0=((x-S)^2-2^2)",
			"isoCondition_1=((x-S)^2-$DOT$01^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,SchwarzP(x,y,z,-1),1)+M*exp(isoCondition_1(x,y,z,t))",
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
			"Description": ["Skeletal SchwarzP Tori by Abderrahman Taha 10/12/2015"],
			"Name": ["Skeletal SchwarzP Tori"],
			"Component": ["Skeletal SchwarzP Tori"],
			"Const": ["M=$DOT$1",
			"N=15",
			"T=1$DOT$2",
			"S=5"],
			"Funct": ["Iso=cos(x)+cos(y)+cos(z)",
			"Iso2= (Iso(x+t*sin(x)*1$DOT$2/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+t*sin(y)*1$DOT$2/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+t*sin(z)*1$DOT$2/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"SchwarzP= (-Iso2(x,y,z,t))",
			"isoCondition_0=((x-S)^2-2$DOT$4^2)",
			"isoCondition_1=((x-S)^2-1$DOT$4^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,-SchwarzP(x,y,z,-1),1)+M*exp(isoCondition_1(x,y,z,t))",
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
			"Description": ["Schwarz P Tori by Abderrahman Taha 10/12/2015"],
			"Name": ["Schwarz P Tori"],
			"Component": ["Schwarz P Tori"],
			"Const": ["M=$DOT$1",
			"N=15"],
			"Funct": ["Iso=cos(x)+cos(y)+cos(z)",
			"Iso4= (Iso(x+sin(x)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"Iso5= (Iso(x-sin(x)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y-sin(y)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z-sin(z)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"TickIso2= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"SchwarzP= (Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"isoCondition_0=(x^2-3$DOT$2^2)",
			"isoCondition_1=(x^2-3^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,SchwarzP(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"],
			"Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"],
			"Xmax": ["27"],
			"Xmin": ["-27"],
			"Ymax": ["27"],
			"Ymin": ["-27"],
			"Zmax": ["12"],
			"Zmin": ["-12"]
		}
	},
	{
		"Iso3D": {
			"Description": ["G_Skeletal Tori by Abderrahman Taha 09/12/2015"],
			"Name": ["G_Skeletal Tori"],
			"Component": ["G_Skeletal Tori"],
			"Const": ["M=4",
			"N=10",
			"P=$DOT$4"],
			"Funct": ["G_Skeletal =cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)+0$DOT$08*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+1",
			"isoCondition_0=((x-pi)^2-(pi-P+$DOT$3)^2)",
			"isoCondition_1=((x-pi)^2-(pi-P)^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,G_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
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
			"Description": ["D_Skeletal Tori by Abderrahman Taha 08/12/2015"],
			"Name": ["D_Skeletal Tori"],
			"Component": ["D_Skeletal Tori"],
			"Const": ["M=4",
			"N=8",
			"P=$DOT$3"],
			"Funct": ["D_Skeletal =sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)-0$DOT$07*(cos(4*x)+cos(4*y)+cos(4*z))+$DOT$95",
			"isoCondition_0=((x-pi)^2-(pi-P+$DOT$01)^2)",
			"isoCondition_1=((x-pi)^2-(pi-P)^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,D_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
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
			"Description": ["D_Skeletal Sphere by Abderrahman Taha 08/12/2015"],
			"Name": ["D_Skeletal Sphere"],
			"Component": ["D_Skeletal Sphere"],
			"Const": ["M=4",
			"N=8",
			"P=$DOT$3"],
			"Funct": ["D_Skeletal =sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)-0$DOT$07*(cos(4*x)+cos(4*y)+cos(4*z))+$DOT$95",
			"isoCondition_0=((x-pi)^2-(pi-P+$DOT$01)^2)",
			"isoCondition_1=((x-pi)^2-(pi-P)^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,D_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),N*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"],
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
			"Description": ["P_Skeletal Sphere by Abderrahman Taha 08/12/2015"],
			"Name": ["P_Skeletal Sphere"],
			"Component": ["P_Skeletal Sphere"],
			"Const": ["M=4",
			"N=10",
			"P=$DOT$7"],
			"Funct": ["P_Skeletal =cos(x)+cos(y)+cos(z)+0$DOT$51*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+1$DOT$2",
			"isoCondition_0=((x-pi)^2-(pi-P+$DOT$01)^2)",
			"isoCondition_1=((x-pi)^2-(pi-P)^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,P_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),N*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"],
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
			"Description": ["P_Skeletal Tori by Abderrahman Taha 08/12/2015"],
			"Name": ["P_Skeletal Tori"],
			"Component": ["P_Skeletal Tori"],
			"Const": ["M=1",
			"N=10",
			"P=7"],
			"Funct": ["P_Skeletal=cos(x)+cos(y)+cos(z)+0$DOT$51*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+1$DOT$2",
			"isoCondition_0=((x-pi)^2-(pi +$DOT$05)^2)",
			"isoCondition_1=((x-pi)^2-(pi)^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,P_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
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
			"Description": ["W_Skeletal Cylinder by Abderrahman Taha 07/12/2015"],
			"Name": ["W_Skeletal Cylinder"],
			"Component": ["W_Skeletal Cylinder"],
			"Const": ["M=1",
			"N=8",
			"P=4"],
			"Funct": ["W_Skeletal=cos(2*x)+cos(2*y)+cos(2*z)-1$DOT$95*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+2$DOT$8",
			"isoCondition_0=(x^2-(pi+$DOT$5)^2)",
			"isoCondition_1=(x^2-(pi+$DOT$3)^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,W_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
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
			"Description": ["W_Skeletal Tori by Abderrahman Taha 07/12/2015"],
			"Name": ["W_Skeletal Tori"],
			"Component": ["W_Skeletal Tori"],
			"Const": ["M=1",
			"N=10",
			"P=7"],
			"Funct": ["W_Skeletal=cos(2*x)+cos(2*y)+cos(2*z)-1$DOT$95*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+2$DOT$8",
			"isoCondition_0=(x^2-(pi+$DOT$5)^2)",
			"isoCondition_1=(x^2-(pi+$DOT$3)^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,W_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
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
			"Description": ["W_Skeletal Sphere by Abderrahman Taha 07/12/2015"],
			"Name": ["W_Skeletal Sphere"],
			"Component": ["W_Skeletal Sphere"],
			"Const": ["M=1",
			"N=10",
			"P=7"],
			"Funct": ["W_Skeletal=cos(2*x)+cos(2*y)+cos(2*z)-1$DOT$95*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+2$DOT$8",
			"isoCondition_0=(x^2-(pi+$DOT$5)^2)",
			"isoCondition_1=(x^2-(pi+$DOT$3)^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,W_Skeletal(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),P*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"],
			"Fxyz": ["-isoTransform2(x,y,z,t)"],
			"Xmax": ["16"],
			"Xmin": ["-16"],
			"Ymax": ["16"],
			"Ymin": ["-16"],
			"Zmax": ["16"],
			"Zmin": ["-16"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Diamond Sphere by Abderrahman Taha 07/12/2015"],
			"Name": ["Diamond Sphere"],
			"Component": ["Diamond Sphere"],
			"Const": ["N=8",
			"M=4"],
			"Funct": ["Diamond =sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
			"isoCondition_0=(x^2-2$DOT$2^2)",
			"isoCondition_1=(x^2-2^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,Diamond(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),N*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"],
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
			"Description": ["Neovius Sphere by Abderrahman Taha 05/12/2015"],
			"Name": ["Neovius Sphere"],
			"Component": ["Neovius Sphere"],
			"Const": ["N=10",
			"M=4"],
			"Funct": ["Neovius =3*(cos(x)+cos(y)+cos(z))+7*cos(x)*cos(y)*cos(z)",
			"isoCondition_0=(x^2-2$DOT$2^2)",
			"isoCondition_1=(x^2-1$DOT$6^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,Neovius(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),10*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"],
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
			"Description": ["Neovius Tori by Abderrahman Taha 06/12/2015"],
			"Name": ["Neovius Tori"],
			"Component": ["Neovius Tori"],
			"Const": ["M=1",
			"N=10"],
			"Funct": ["Neovius=3*(cos(x)+cos(y)+cos(z))+7*cos(x)*cos(y)*cos(z)",
			"isoCondition_0=(x^2-2$DOT$4^2)",
			"isoCondition_1=(x^2-1$DOT$6^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,Neovius(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"],
			"Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"],
			"Xmax": ["25"],
			"Xmin": ["-25"],
			"Ymax": ["25"],
			"Ymin": ["-25"],
			"Zmax": ["10$DOT$5"],
			"Zmin": ["-10$DOT$5"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Diamond Tori"],
			"Description": ["Diamond Tori by Abderrahman Taha 06/12/2015"],
			"Component": ["Diamond Tori"],
			"Const": ["M=1",
			"N=10"],
			"Funct": ["Diamond=sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
			"isoCondition_0=(x^2-2$DOT$2^2)",
			"isoCondition_1=(x^2-1$DOT$6^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,Diamond(x,y,z,t),1)+M*exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"],
			"Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"],
			"Xmax": ["25"],
			"Xmin": ["-25"],
			"Ymax": ["25"],
			"Ymin": ["-25"],
			"Zmax": ["10$DOT$5"],
			"Zmin": ["-10$DOT$5"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Sleeping bugs by Abderrahman Taha 06/12/2015"],
			"Name": ["Sleeping bugs"],
			"Component": ["Sleeping Bugs"],
			"Const": ["cu=0$DOT$001",
			"cv=0$DOT$001",
			"N=3"],
			"Funct": ["Tickness= $DOT$4*(-$DOT$5*(abs(sin(15*u)*cos(15*v)))^9 + $DOT$35*((sin(2*N*u))))",
			"Fx=-cos(u+v)/(sqrt(2$DOT$)+cos(v-u))",
			"Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
			"Fz=sin(u+v)/(sqrt(2$DOT$)+cos(v-u))",
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
			"Gz=Fz(u,v,t)+Tickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
			"Fx": ["Gx(u,v,t)"],
			"Fy": ["Gy(u,v,t)"],
			"Fz": ["Gz(u,v,t)"],
			"Umax": ["pi"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=0$DOT$81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))+$DOT$3",
			"B=0$DOT$8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"T=1"],
			"Name": "WorleyNoise",
			"Noise": "NoiseW(2*x,2*y,2*z,4,2,0)+NoiseP(2*x,2*y,2*z,4,12,0$DOT$1)"
		}
	},
	{
		"Iso3D": {
			"Description": ["Gyroid Tori by Abderrahman Taha 06/12/2015"],
			"Name": ["Gyroid Tori"],
			"Component": ["Gyroid Tori"],
			"Const": ["N=10"],
			"Funct": ["Gyroid=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
			"isoCondition_0=(x^2-2$DOT$2^2)",
			"isoCondition_1=(x^2-1$DOT$6^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,Gyroid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+z*z)-8),y,N*atan2(z,x),t)"],
			"Fxyz": ["-isoTransform2((sqrt(x*x+y*y)-15),N*atan2(y,x),z,t)"],
			"Xmax": ["25"],
			"Xmin": ["-25"],
			"Ymax": ["25"],
			"Ymin": ["-25"],
			"Zmax": ["10$DOT$5"],
			"Zmin": ["-10$DOT$5"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Gyroid Sphere by Abderrahman Taha 05/12/2015"],
			"Name": ["Gyroid Sphere"],
			"Component": ["Gyroid Sphere"],
			"Const": ["N=18"],
			"Funct": ["Gyroid=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
			"isoCondition_0=(x^2-2$DOT$2^2)",
			"isoCondition_1=(x^2-1$DOT$6^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,Gyroid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),10*pi*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)"],
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
			"Description": ["Gyroid Sphere by Abderrahman Taha 05/12/2015"],
			"Name": ["Gyroid Sphere"],
			"Component": ["Gyroid Sphere"],
			"Const": ["N=18"],
			"Funct": ["Gyroid=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
			"isoCondition_0=(x^2-2$DOT$2^2)",
			"isoCondition_1=(x^2-1$DOT$6^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,Gyroid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-13),10*pi*atan2(y, sqrt(x*x+y*y+z*z)),N*atan2(z,x),t)"],
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
			"Description": ["Schwarz Cylinder by Abderrahman Taha 05/12/2015"],
			"Name": ["Schwarz Cylinder"],
			"Component": ["Schwarz Cylinder"],
			"Const": ["N=8"],
			"Funct": ["Schwarz=cos(x) + cos(y) + cos(z)",
			"isoCondition_0=(x^2-3$DOT$2^2)",
			"isoCondition_1=(x^2-2$DOT$6^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,-Schwarz(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
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
			"Description": ["Lidinoid Sphere by Abderrahman Taha 05/12/2015"],
			"Name": ["Lidinoid Sphere"],
			"Component": ["Lidinoid Sphere"],
			"Const": ["N=8"],
			"Funct": ["Lidinoid=((1/2)*(sin(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*sin(x)+sin(2*z)*cos(x)*sin(y))-(1/2)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+0$DOT$15)",
			"isoCondition_0=(x^2-2$DOT$6^2)",
			"isoCondition_1=(x^2-2$DOT$4^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,-Lidinoid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
			"isoTransform2=isoTransform((sqrt(x*x+y*y+z*z)-12),10*atan2(y, sqrt(x*x+z*z)),N*atan2(z,x),t)",
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
			"Description": ["Lidinoid Torus by Abderrahman Taha 02/12/2015"],
			"Name": ["Lidinoid Torus"],
			"Component": ["Neovius Torus_1"],
			"Const": ["N=8"],
			"Funct": ["Lidinoid=((1/2)*(sin(2*x)*cos(y)*sin(z)+sin(2*y)*cos(z)*sin(x)+sin(2*z)*cos(x)*sin(y))-(1/2)*(cos(2*x)*cos(2*y)+cos(2*y)*cos(2*z)+cos(2*z)*cos(2*x))+0$DOT$15)",
			"isoCondition_0=(x^2+z^2-2$DOT$6^2)",
			"isoCondition_1=(x^2+z^2-2$DOT$4^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,-Lidinoid(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))"],
			"Fxyz": ["isoTransform((sqrt(x*x+y*y)-7),N*atan2(y,x),z,t)"],
			"Xmax": ["10"],
			"Xmin": ["-10"],
			"Ymax": ["10"],
			"Ymin": ["-10"],
			"Zmax": ["2$DOT$5"],
			"Zmin": ["-2$DOT$5"]
		}
	},
	{
		"Param4D": {
			"Name": ["4D Tube"],
			"Description": ["4D Tube by Abderrahman Taha 03/12/2015"],
			"Component": ["4DTube"],
			"Fw": ["$DOT$3*(sin(v)+cos(4*u))"],
			"Fx": ["cos(u)"],
			"Fy": ["sin(u)"],
			"Fz": ["$DOT$3*(cos(v)+sin(4*u))"],
			"Umax": ["pi"],
			"Umin": ["-pi"],
			"Vmax": ["pi"],
			"Vmin": ["-pi"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Double Twist Neovius Torus"],
			"Component": ["Neovius Torus"],
			"Description": ["Double Twist Neovius Torus by Abderrahman Taha 02/12/2015"],
			"Funct": ["Iso=3*(cos(x)+cos(y)+cos(z))+4*cos(x)*cos(y)*cos(z)",
			"isoCondition_0=(x^2+(z/9)^2-3$DOT$2^2)",
			"isoCondition_1=(x^2+(z/9)^2-3^2)",
			"isoTransform_1=if(isoCondition_0(x,y,z,t)<0,Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
			"isoTransform_2=if(isoCondition_0(x,y,z,t)<0,-Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
			"isoTransform_3 = isoTransform_2((sqrt(x*x+y*y)-3),atan2(y,x),z,t)"],
			"Fxyz": ["isoTransform_3(x, (sqrt(y*y+z*z)-8) , 3*atan2(z,y),t)"],
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
			"Description": ["Neovius Torus_1 by Abderrahman Taha 02/12/2015"],
			"Name": ["Neovius Torus"],
			"Component": ["Neovius Torus_1"],
			"Const": ["N=12"],
			"Funct": ["Iso=3*(cos(x)+cos(y)+cos(z))+4*cos(x)*cos(y)*cos(z)",
			"isoCondition_0=(x^2+z^2-3$DOT$2^2)",
			"isoCondition_1=(x^2+z^2-3^2)",
			"isoTransform=if(isoCondition_0(x,y,z,t)<0,-Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))"],
			"Fxyz": ["isoTransform((sqrt(x*x+y*y)-7),N*atan2(y,x),z,t)"],
			"Xmax": ["10"],
			"Xmin": ["-10"],
			"Ymax": ["10"],
			"Ymin": ["-10"],
			"Zmax": ["3$DOT$5"],
			"Zmin": ["-3$DOT$5"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Vase_3 by Abderrahman Taha 30/11/2015"],
			"Name": ["Vase"],
			"Component": ["Vase",
			"Head",
			"Bottom"],
			"Const": ["Thick = $DOT$05"],
			"Funct": ["CarvinCondition=abs((z-1) -$DOT$8*cos(18*atan2(x,y)/pi))<1$DOT$3|abs((z+3) -$DOT$3*cos(18*atan2(x,y)/pi+pi/4))<$DOT$5",
			"Torus=(sqrt(x*x+y*y)-3)^2+z*z-1",
			"Bottom=(x*x+y*y+z*z-1)",
			"ThickIsoExterior=(x*x/3+y*y/3-abs(1$DOT$5*sin(2*z/pi+$DOT$3)+1$DOT$8))*(x*x/3+y*y/3-abs(1$DOT$5*sin(2*z/pi+$DOT$3)+1$DOT$8))-Thick",
			"Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
			"Rapport=(sqrt((-sin(x)*sin(y)+cos(z)*cos(x))*(-sin(x)*sin(y)+cos(z)*cos(x))+(-sin(y)*sin(z)+cos(x)*cos(y))*(-sin(y)*sin(z)+cos(x)*cos(y))+(-sin(z)*sin(x)+cos(y)*cos(z))*(-sin(z)*sin(x)+cos(y)*cos(z))))",
			"Iso4=(Iso(x+t*(-sin(x)*sin(y)+cos(z)*cos(x))*$DOT$2/Rapport(x,y,z,t),y+t*(-sin(y)*sin(z)+cos(x)*cos(y))*$DOT$2/Rapport(x,y,z,t),z+t*(-sin(z)*sin(x)+cos(y)*cos(z))*$DOT$2/Rapport(x,y,z,t),t))",
			"ThickIso2=(Iso4(x,y,z,-1)*Iso4(x,y,z,1))",
			"isoTransform_2=if(CarvinCondition(x,y,z,t)=0,ThickIsoExterior(x,y,z,t),1)",
			"Iso6=(Iso(x+t*(-sin(x)*sin(y)+cos(z)*cos(x))*1$DOT$2/Rapport(x,y,z,t),y+t*(-sin(y)*sin(z)+cos(x)*cos(y))*1$DOT$2/Rapport(x,y,z,t),z+t*(-sin(z)*sin(x)+cos(y)*cos(z))*1$DOT$2/Rapport(x,y,z,t),t))",
			"isoTransform_6=if(CarvinCondition(x,y,z,t)&ThickIsoExterior(x,y,z,t)<0,-ThickIso2(6*x,6*y,6*z,t) * Iso6(x*6,y*6,z*6, -1) *(Iso6(x*6,y*6,z*6,1)),1)"],
			"Fxyz": ["isoTransform_2(x,y,-z,t) * isoTransform_6(x,y,-z,t)",
			"Torus(1$DOT$7*x,1$DOT$7*y,2$DOT$2*(z+cos(pi/4*sqrt(x*x+y*y))) -10$DOT$6,t)",
			"Bottom(x/2$DOT$4,y/2$DOT$4,2*(z+5$DOT$1),t)"],
			"Xmax": ["3$DOT$5",
			"5",
			"3"],
			"Xmin": ["-3$DOT$5",
			"-5",
			"-3"],
			"Ymax": ["3$DOT$5",
			"5",
			"3"],
			"Ymin": ["-3$DOT$5",
			"-5",
			"-3"],
			"Zmax": ["4$DOT$5",
			"10",
			"-2"],
			"Zmin": ["-5",
			"0",
			"-7"]
		},
		"Texture": {
			"Colors": ["R=$DOT$95*abs(cos(z*y*x*y))",
			"G=$DOT$45*abs(cos(z*y*x*y))",
			"B=0$DOT$02*abs(cos(-z*x*z*x*y*y))",
			"T=1"],
			"Name": "Granit_1",
			"Noise": "NoiseP(x,y,z,10,7,0$DOT$12)"
		}
	},
	{
		"Iso3D": {
			"Description": ["Diamon Torus by Abderrahman Taha 28/11/2015"],
			"Name": ["Diamon Torus"],
			"Component": ["Diamon Torus_1",
			"DiamonTorus_2"],
			"Funct": ["Iso=sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
			"isoCondition_0=(x^2+z^2-3$DOT$2^2)",
			"isoCondition_1=(x^2+z^2-3^2)",
			"isoTransform_1=if(isoCondition_0(x,y,z,t)<0,Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
			"isoTransform_2=if(isoCondition_0(x,y,z,t)<0,-Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))"],
			"Fxyz": ["isoTransform_1((sqrt(x*x+y*y)-6),12*atan2(y,x),z,t)",
			"isoTransform_2((sqrt(x*x+y*y)-6),12*atan2(y,x),z,t)"],
			"Xmax": ["9$DOT$8",
			"9$DOT$8"],
			"Xmin": ["-9$DOT$8",
			"-9$DOT$8"],
			"Ymax": ["9$DOT$8",
			"9$DOT$8"],
			"Ymin": ["-9$DOT$8",
			"-9$DOT$8"],
			"Zmax": ["3$DOT$5",
			"3$DOT$5"],
			"Zmin": ["-3$DOT$5",
			"-3$DOT$5"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Octahedron of Octahedrons by Abderrahman Taha 27/11/2015"],
			"Name": ["Octahedron of Octahedrons10"],
			"Component": ["OctahedronOfOctahedrons"],
			"Const": ["N=7"],
			"Funct": ["Octahedron=(abs(x)+abs(y)+abs(z))-(1/(2*N))",
			"Octahedr = ( (abs(x-$DOT$5)+abs(y-$DOT$5)+abs(z-$DOT$5))-(1/2))",
			"Octahedr1 = ( (abs(x-$DOT$5)+abs(y-$DOT$5)+abs(z-$DOT$5))-(1/2-1/(N)) )"],
			"Fxyz": ["if(Octahedr(x,y,z,t)<0 & Octahedr1(x,y,z,t)>0, Octahedron((x%(1/N))-1/(2*N),(y%(1/N))-1/(2*N),(z%(1/N))-1/(2*N),t), 1) "],
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
			"Description": ["Cube of Octahedrons by Abderrahman Taha 27/11/2015"],
			"Name": ["Cube of Octahedrons"],
			"Component": [" CubeOctahedrons"],
			"Const": ["N=20"],
			"Funct": ["Octahedron=(abs(x)+abs(y)+abs(z))-(1/(2*N))",
			"Cube = (((x < 1/N | x>(1-1/N)) | (y < 1/N | y>(1-1/N)) | (z < 1/N | z>(1-1/N))))"],
			"Fxyz": ["if(Cube(x,y,z,t), Octahedron((x%(1/N))-1/(2*N),(y%(1/N))-1/(2*N),(z%(1/N))-1/(2*N),t), 1) "],
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
			"Name": ["Cube of Spheres"],
			"Description": ["Cube of Spheres by Abderrahman Taha 27/11/2015"],
			"Component": [" CubeSpheres"],
			"Const": ["N=20"],
			"Funct": ["Sphere=sqrt(x*x+y*y+z*z)-1/(2*N)"],
			"Fxyz": ["if((((x < 1/N | x>(1-1/N)) | (y < 1/N | y>(1-1/N)) | (z < 1/N | z>(1-1/N)))), Sphere((x%(1/N))-1/(2*N),(y%(1/N))-1/(2*N),(z%(1/N))-1/(2*N),t), 1) "],
			"Xmax": ["1"],
			"Xmin": ["0"],
			"Ymax": ["1"],
			"Ymin": ["0"],
			"Zmax": ["1"],
			"Zmin": ["0"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Belted Torus_1 by Abderrahman Taha 26/11/2015"],
			"Name": ["Belted Torus"],
			"Component": ["BeltedTorus"],
			"Const": ["cu=0$DOT$0001",
			"cv=0$DOT$0001",
			"N=2"],
			"Funct": ["Thickness=$DOT$4*sin(2*N*v)^100 + $DOT$4*sin(N*v-u)^100",
			"Fx=(N/2+1+ $DOT$6*cos(u))*cos(v)",
			"Fy=$DOT$6*sin(u)",
			"Fz=(N/2+1+ $DOT$6*cos(u))*sin(v)",
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
			"Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
			"Fx": ["Gx(u,v,t)"],
			"Fy": ["Gy(u,v,t)"],
			"Fz": ["Gz(u,v,t)"],
			"Umax": ["2*pi"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=$DOT$8*abs(cos((pi*(x*x+y*y+z*z))))",
			"B=$DOT$6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
			"T=1"],
			"Name": "Dream",
			"Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
		}
	},
	{
		"Iso3D": {
			"Description": ["Spiral Schwarz Torus_1 by Abderrahman Taha 25/11/2015"],
			"Name": ["Spiral Schwarz Torus"],
			"Component": ["SpiralSchwarzTorus_1",
			"SpiralSchwarzTorus_2"],
			"Const": ["N=1$DOT$4",
			"k=48"],
			"Funct": ["Iso=cos(x)+cos(y)+cos(z)",
			"DFx=-sin(x)",
			"DFy=-sin(y)",
			"DFz=-sin(z)",
			"Rapport=sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z))",
			"Iso3=(Iso(x+sin(x)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"Iso4=(Iso(x+sin(x)*$DOT$4/Rapport(x,y,z,t),y+sin(y)*$DOT$4/Rapport(x,y,z,t),z+sin(z)*$DOT$4/Rapport(x,y,z,t),t))",
			"Iso5=(Iso(x-sin(x)*$DOT$4/Rapport(x,y,z,t),y-sin(y)*$DOT$4/Rapport(x,y,z,t),z-sin(z)*$DOT$4/Rapport(x,y,z,t),t))",
			"ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"isoCondition=(x^2+z^2-28)",
			"isoTransform_1=if(isoCondition(x,y,z,t)<0,ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)",
			"isoTransform_2=isoTransform_1(x*cos(pi*y/(k*pi))-z*sin(pi*y/(k*pi)),y,x*sin(pi*y/(k*pi))+z*cos(pi*y/(k*pi)),t)",
			"isoTransform_3=if(isoCondition(x,y,z,t)<0,-Iso3(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)",
			"isoTransform_4=isoTransform_3(x*cos(pi*y/(k*pi))-z*sin(pi*y/(k*pi)),y,x*sin(pi*y/(k*pi))+z*cos(pi*y/(k*pi)),t)"],
			"Fxyz": ["isoTransform_2((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)",
			"isoTransform_4((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)"],
			"Xmax": ["15$DOT$5",
			"15$DOT$5"],
			"Xmin": ["-15$DOT$5",
			"-15$DOT$5"],
			"Ymax": ["15$DOT$5",
			"15$DOT$5"],
			"Ymin": ["-15$DOT$5",
			"-15$DOT$5"],
			"Zmax": ["5$DOT$5",
			"5$DOT$5"],
			"Zmin": ["-5$DOT$5",
			"-5$DOT$5"]
		}
	},
	{
		"Param4D": {
			"Description": ["Kinky 4D Clifford Torus by Aberrahman Taha 24/11/2015"],
			"Name": ["Kinky 4D Clifford Torus"],
			"Component": ["4DTorus"],
			"Const": ["cu=0$DOT$0001",
			"cv=0$DOT$0001",
			"N=3"],
			"Funct": ["Thickness=-abs($DOT$1*cos(3*v-7*u)*sin(3*v))",
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
			"Gz=Fz(u,v,t)"],
			"Fw": ["cos(v)"],
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
		"Iso3D": {
			"Description": ["Schwarz Torus_1 by Abderrahman Taha 24/11/2015"],
			"Name": ["Schwarz Torus_1"],
			"Component": ["SchwarzTorus_1",
			"SchwarzTorus_2"],
			"Const": ["N=1$DOT$4"],
			"Funct": ["Iso=cos(x)+cos(y)+cos(z)",
			"Iso3=(Iso(x+sin(x)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"Iso4=(Iso(x+sin(x)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"Iso5=(Iso(x-sin(x)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y-sin(y)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z-sin(z)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"isoCondition=(x^2+z^2-20)",
			"isoTransform_1=if(isoCondition(x,y,z,t)<0,ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)",
			"isoTransform_2=if(isoCondition(x,y,z,t)<0,-Iso3(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)"],
			"Fxyz": ["-isoTransform_1((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)",
			"-isoTransform_2((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)"],
			"Xmax": ["14",
			"16"],
			"Xmin": ["-14",
			"-16"],
			"Ymax": ["14",
			"16"],
			"Ymin": ["-14",
			"-16"],
			"Zmax": ["6",
			"6"],
			"Zmin": ["-6",
			"-6"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Schwarz Torus_2 by Abderrahman Taha 23/11/2015"],
			"Name": ["Schwarz Torus_2"],
			"Component": ["SchwarzTorus_1",
			"SchwarzTorus_2",
			"SchwarzTorus_3"],
			"Const": ["N=1$DOT$4"],
			"Funct": ["Iso=cos(x)+cos(y)+cos(z)",
			"Iso3=(Iso(x+sin(x)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"Iso2=(Iso(x-sin(x)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y-sin(y)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z-sin(z)*N/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"Iso4=(Iso(x+sin(x)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"Iso5=(Iso(x-sin(x)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y-sin(y)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z-sin(z)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"isoCondition=(x^2+z^2-28)",
			"isoTransform_1=if(isoCondition(x,y,z,t)<0,ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)",
			"isoTransform_2=if(isoCondition(x,y,z,t)<0,-Iso3(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)",
			"isoTransform_3=if(isoCondition(x,y,z,t)<0,Iso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)"],
			"Fxyz": ["-isoTransform_1((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)",
			"isoTransform_2((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)",
			"-isoTransform_3((sqrt(x*x+y*y)-10),12*atan2(y,x),z,t)"],
			"Xmax": ["16",
			"16",
			"16"],
			"Xmin": ["-16",
			"-16",
			"-16"],
			"Ymax": ["16",
			"16",
			"16"],
			"Ymin": ["-16",
			"-16",
			"-16"],
			"Zmax": ["6",
			"6",
			"6"],
			"Zmin": ["-6",
			"-6",
			"-6"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Schwarz Torus_3 by Abderrahman Taha 23/11/2015"],
			"Name": ["Schwarz Torus_3"],
			"Component": ["SchwarzTorus"],
			"Const": ["N=2"],
			"Funct": ["Iso=cos(x)+cos(y)+cos(z)",
			"$DOT$4= ($DOT$4)",
			"DFx= -sin(x)",
			"DFy= -sin(y)",
			"DFz= -sin(z)",
			"Rapport= sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z))",
			"Iso4= (Iso(x+sin(x)*$DOT$4/Rapport(x,y,z,t),y+sin(y)*$DOT$4/Rapport(x,y,z,t),z+sin(z)*$DOT$4/Rapport(x,y,z,t),t))",
			"Iso5= (Iso(x-sin(x)*$DOT$4/Rapport(x,y,z,t),y-sin(y)*$DOT$4/Rapport(x,y,z,t),z-sin(z)*$DOT$4/Rapport(x,y,z,t),t))",
			"ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"isoCondition=(x^2+z^2-28)",
			"isoTransform_1=if(isoCondition(x,y,z,t)<0,ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)"],
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
			"Description": ["Arena_2 by Abderrahman Taha 23/11/2015"],
			"Name": ["Arena"],
			"Component": ["Arena"],
			"Const": ["cx=0$DOT$00001",
			"cy=0$DOT$00001",
			"cz=0$DOT$00001",
			"N=20"],
			"Funct": ["Scherk=sinh(x)*sinh(y)-4*sin(z)",
			"Scherk2=Scherk(x,sqrt(y*y+z*z)-16,N*atan2(z,y),t)",
			"Thickness2=($DOT$6)",
			"IsoExterior=Scherk2(x,y,z,t)",
			"DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
			"DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
			"DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
			"Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
			"Iso3=(IsoExterior(x-DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y-DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z-DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
			"Iso2=(IsoExterior(x+DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y+DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z+DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
			"ThickIsoExterior=(Iso2(x,y,z,t)*Iso3(x,y,z,t))"],
			"Fxyz": ["if((sqrt(x*x+y*y+z*z) - 27)<0 & abs(x)<10 ,ThickIsoExterior(x,y,z,t), 1)"],
			"Xmax": ["10$DOT$1"],
			"Xmin": ["-10$DOT$1"],
			"Ymax": ["28"],
			"Ymin": ["-28"],
			"Zmax": ["28"],
			"Zmin": ["-28"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Schwarz Cube Torus by Abderrahman Taha 22/11/2015"],
			"Name": ["Schwarz Cube Torus"],
			"Component": ["SchwarzCubeTorus_1",
			"SchwarzCubeTorus_2",
			"SchwarzCubeTorus_3",
			"SchwarzCubeTorus_4"],
			"Const": ["k=6"],
			"Funct": ["Iso=cos(x)+cos(y)+cos(z)",
			"Iso4=(Iso(x+sin(x)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y+sin(y)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z+sin(z)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"Iso5=(Iso(x-sin(x)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),y-sin(y)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),z-sin(z)*$DOT$4/sqrt(sin(x)*sin(x)+sin(y)*sin(y)+sin(z)*sin(z)),t))",
			"ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"isoCondition=(x^20+(y/4)^20+z^20-3$DOT$23^20)",
			"isoTransform_2=if(isoCondition(x,y,z,t)<0,ThickIso2(k*x,k*y,k*z,t),1)",
			"isoTransform_3=isoTransform_2(x*cos(pi*y/(k*pi))-z*sin(pi*y/(k*pi)),y,x*sin(pi*y/(k*pi))+z*cos(pi*y/(k*pi)),t)"],
			"Fxyz": ["-isoTransform_3(sqrt(x*x+y*y)-6$DOT$5,3*atan2(y,x),z,t)",
			"-isoTransform_3(sqrt(x*x+y*y)-6$DOT$5,3*atan2(y,x),z,t)",
			"-isoTransform_3(sqrt(x*x+y*y)-6$DOT$5,3*atan2(y,x),z,t)",
			"-isoTransform_3(sqrt(x*x+y*y)-6$DOT$5,3*atan2(y,x),z,t)"],
			"Xmax": ["0",
			"0",
			"11",
			"11"],
			"Xmin": ["-11",
			"-11",
			"0",
			"0"],
			"Ymax": ["0",
			"11",
			"0",
			"11"],
			"Ymin": ["-11",
			"0",
			"-11",
			"0"],
			"Zmax": ["5",
			"5",
			"5",
			"5"],
			"Zmin": ["-5",
			"-5",
			"-5",
			"-5"]
		},
		"Texture": {
			"Colors": ["R=$DOT$8",
			"G=0$DOT$6",
			"B=0$DOT$1",
			"T=1"],
			"Name": "Gold",
			"Noise": "1"
		}
	},
	{
		"Iso3D": {
			"Description": ["Gyroidal Torus by Abderrahman Taha 21/11/2015"],
			"Name": ["Gyroidal Torus"],
			"Component": ["GyroidalTorus"],
			"Const": ["cx=0$DOT$0001",
			"cy=0$DOT$0001",
			"cz=0$DOT$0001"],
			"Funct": ["Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
			"Thickness2= ($DOT$4)",
			"DFx= ((Iso(x,y,z,t)-Iso(x+cx,y,z,t))/cx)",
			"DFy= ((Iso(x,y,z,t)-Iso(x,y+cy,z,t))/cy)",
			"DFz= ((Iso(x,y,z,t)-Iso(x,y,z+cz,t))/cz)",
			"Rapport= (sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
			"Iso4= (Iso(x-DFx(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),y-DFy(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),z-DFz(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),t))",
			"Iso5= (Iso(x+DFx(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),y+DFy(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),z+DFz(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),t))",
			"ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"isoCondition=(x^2+z^2-16)",
			"isoTransform_1=if(isoCondition(x,y,z,t)<0,ThickIso2(x,y,z,t),1)+exp(isoCondition(x,y,z,t)/3)"],
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
			"Description": ["iWP Skeletal Graphis by Abderrahman Taha 20/11/2015"],
			"Name": ["W_SkeletalGraph"],
			"Component": ["W_SkeletalGraphis"],
			"Fxyz": ["-(cos(2*x)+cos(2*y)+cos(2*z)-1$DOT$95*(cos(x)*cos(y)+cos(y)*cos(z)+cos(z)*cos(x))+2$DOT$8)"],
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
			"Description": [" Pseudo Chmutov_2 by Abderrahman Taha 19/11/2015"],
			"Name": ["Pseudo Chmutov"],
			"Component": ["PseudoChmutov",
			"PseudoChmutov_01"],
			"Const": ["M=7",
			"N=16"],
			"Fxyz": ["-((x^N+y^N+z^N)-(cos(M*x)+cos(M*y)+cos(M*z))-$DOT$1)",
			"((x^N+y^N+z^N)-(cos((2*M)*x)+cos((2*M)*y)+cos((2*M)*z))+$DOT$5)"],
			"Xmax": ["1$DOT$1",
			"1$DOT$1"],
			"Xmin": ["-1$DOT$1",
			"-1$DOT$1"],
			"Ymax": ["1$DOT$1",
			"1$DOT$1"],
			"Ymin": ["-1$DOT$1",
			"-1$DOT$1"],
			"Zmax": ["1$DOT$1",
			"1$DOT$1"],
			"Zmin": ["-1$DOT$1",
			"-1$DOT$1"]
		}
	},
	{
		"Param4D": {
			"Description": ["4D Roller Coaster by Abderrahman Taha 16/11/2015"],
			"Name": ["4D Roller Coaster"],
			"Component": ["RollerCoaster"],
			"Fx": ["sin(u)*(cos(v%(pi/30)))*cos((v-3*u)%(pi/30))"],
			"Fy": ["cos(u)*(cos(v%(pi/30)))*cos((v-3*u)%(pi/30))"],
			"Fz": ["sin(v-3*u)*(cos(v%(pi/30)))*cos((v-3*u)%(pi/30))"],
			"Fw": ["cos(v-3*u)"],
			"Umax": ["2*pi"],
			"Umin": ["0"],
			"Vmax": ["pi/1$DOT$2"],
			"Vmin": ["0"]
		}
	},
	{
		"Param4D": {
			"Description": ["4D Clliford Ribbon by Abderrahman Taha 16/11/2015"],
			"Name": ["4D Clliford Ribbon"],
			"Component": ["CllifordRibbon"],
			"Fw": ["cos(v)"],
			"Fx": ["sin(u-4*v)"],
			"Fy": ["cos(u-4*v)"],
			"Fz": ["sin(v)"],
			"Umax": ["pi/1$DOT$5"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Matrix of Spheres by Abderrahman Taha 16/11/2015"],
			"Name": ["Matrix of Spheres"],
			"Component": [" MatrixofSpheres"],
			"Const": ["N=2",
			"R=1/N"],
			"Funct": ["Sphere=sqrt(x*x+y*y+z*z)-1/(2*N)"],
			"Fxyz": ["-Sphere((x%(1/N))-1/(2*N),(y%(1/N))-1/(2*N),(z%(1/N))-1/(2*N),t)"],
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
			"Description": [" Pseudo Chmutov_2 by Abderrahman Taha 14/11/2015"],
			"Name": ["Pseudo Chmutov_2"],
			"Component": ["PseudoChmutov"],
			"Const": ["M=7",
			"N=16"],
			"Fxyz": ["-((x^N+y^N+z^N)-(cos(M*x)+cos(M*y)+cos(M*z))-$DOT$1)"],
			"Xmax": ["1$DOT$1"],
			"Xmin": ["-1$DOT$1"],
			"Ymax": ["1$DOT$1"],
			"Ymin": ["-1$DOT$1"],
			"Zmax": ["1$DOT$1"],
			"Zmin": ["-1$DOT$1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Ring of Fire_1 by Abderrahman Taha 11/11/2015"],
			"Name": ["Ring of Fire"],
			"Component": ["Ring"],
			"Const": ["cx=0$DOT$0001"],
			"Funct": ["Scherk=sinh(x)*sinh(y)-5*sin(z)",
			"Scherk2=Scherk(x,(sqrt(y*y+x*x)-10),z,t)",
			"Thickness2=($DOT$43)",
			"IsoExterior=Scherk2(x,(sqrt(y*y+z*z)-26),z,t)",
			"DFx2= ((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
			"DFy2= ((IsoExterior(x,y,z,t)-IsoExterior(x,y+cx,z,t))/cx)",
			"DFz2= ((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cx,t))/cx)",
			"Rapport2= (sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
			"Iso3= (IsoExterior(x-DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y-DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z-DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
			"Iso2= (IsoExterior(x+DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y+DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z+DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
			"ThickIsoExterior=(Iso2(x,y,z,t)*Iso3(x,y,z,t))"],
			"Fxyz": ["if((sqrt(y*y+z*z)-37<0)&(sqrt(y*y+z*z)-16>0) & ( (sqrt(y*y+z*z)-26)^2+x*x-75>0 ),ThickIsoExterior(x,y,z,t),1)+$DOT$1"],
			"Xmax": ["11"],
			"Xmin": ["-11"],
			"Ymax": ["38"],
			"Ymin": ["-38"],
			"Zmax": ["38"],
			"Zmin": ["-38"]
		},
		"Texture": {
			"Colors": ["R=$DOT$71",
			"G=1$DOT$1*abs(cos((x*x+y*y+z*z))*sin((x*x+y*y+z*z)/2))",
			"B=$DOT$01*abs(cos((x*x+y*y+z*z))*cos((x*x+y*y+z*z)/2))",
			"T=1"],
			"Name": "PerlinNoise",
			"Noise": "NoiseP(x,y,z,6,0$DOT$7,1$DOT$1)/30"
		}
	},
	{
		"Param3D": {
			"Description ": ["Bullet by Abderrahman Taha 10/11/2015"],
			"Name": ["Bullet"],
			"Component": ["Bullet1",
			"Bullet2"],
			"Const": ["cu=0$DOT$001",
			"cv=0$DOT$001",
			"N=1$DOT$5"],
			"Funct": ["Thickness1=if( t = 1, if ( abs(sin(4*u-v))<$DOT$4,-1, -u*u*(cos(u) - sin(u)) ),if ( abs(sin(4*u-v))>$DOT$4,-1,-u*u*(cos(u) - sin(u))))",
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
			"Fx": ["Gx(u,v,1)",
			"Gx(u,v,0)"],
			"Fy": ["Gy(u,v,1)",
			"Gy(u,v,0)"],
			"Fz": ["Gz(u,v,1)",
			"Gz(u,v,0)"],
			"Umax": ["pi/2",
			"pi/2"],
			"Umin": ["-pi/2",
			"-pi/2"],
			"Vmax": ["2*pi",
			"2*pi"],
			"Vmin": ["0",
			"0"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Lobed Torus_1 by Abderrahman Taha 10/11/2015"],
			"Name": ["Lobed Torus_1"],
			"Component": ["LobedTorus"],
			"Const": ["cu=0$DOT$0001",
			"cv=0$DOT$0001",
			"N=3"],
			"Funct": ["Thickness=$DOT$4*sin(2*N*v-u) + $DOT$9*sin((N*v)% pi/3)",
			"Fx=(N/2+1+ $DOT$6*cos(u))*cos(v)",
			"Fy=$DOT$6*sin(u)",
			"Fz=(N/2+1+ $DOT$6*cos(u))*sin(v)",
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
			"Umax": ["2*pi"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=$DOT$8*abs(cos((pi*(x*x+y*y+z*z))))",
			"B=$DOT$6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
			"T=1"],
			"Name": "Dream",
			"Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
		}
	},
	{
		"Param3D": {
			"Description ": ["Lobed Torus_2 by Abderrahman Taha 10/11/2015"],
			"Name": ["Lobed Torus_2"],
			"Component": ["LobedTorus"],
			"Const": ["cu=0$DOT$0001",
			"cv=0$DOT$0001",
			"N=3"],
			"Funct": ["Thickness=$DOT$9*sin((N*v)% pi/3)",
			"Fx=(N/2+1+ $DOT$6*cos(u))*cos(v)",
			"Fy=$DOT$6*sin(u)",
			"Fz=(N/2+1+ $DOT$6*cos(u))*sin(v)",
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
			"Umax": ["2*pi"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=$DOT$8*abs(cos((pi*(x*x+y*y+z*z))))",
			"B=$DOT$6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
			"T=1"],
			"Name": "Dream",
			"Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
		}
	},
	{
		"Param3D": {
			"Description ": ["Lobed Torus_4 by Abderrahman Taha 08/11/2015"],
			"Name": ["Lobed Torus_4"],
			"Component": ["LobedTorus"],
			"Const": ["cu=0$DOT$0001",
			"cv=0$DOT$0001",
			"N=3"],
			"Funct": ["Thickness=$DOT$4*sin(N*v)",
			"Fx=(N/2+1+ $DOT$6*cos(u))*cos(v)",
			"Fy=$DOT$6*sin(u)",
			"Fz=(N/2+1+ $DOT$6*cos(u))*sin(v)",
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
			"Umax": ["2*pi"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=$DOT$8*abs(cos((pi*(x*x+y*y+z*z))))",
			"B=$DOT$6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
			"T=1"],
			"Name": "Dream",
			"Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
		}
	},
	{
		"Param3D": {
			"Description ": ["Lobed Torus_5 by Abderrahman Taha 08/11/2015"],
			"Name": ["Lobed Torus_5"],
			"Component": ["LobedTorus"],
			"Const": ["cu=0$DOT$0001",
			"cv=0$DOT$0001",
			"N=3"],
			"Funct": ["Thickness=$DOT$4*sin(N*v-u)^100",
			"Fx=(N/2+1+ $DOT$6*cos(u))*cos(v)",
			"Fy=$DOT$6*sin(u)",
			"Fz=(N/2+1+ $DOT$6*cos(u))*sin(v)",
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
			"Umax": ["2*pi"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=$DOT$8*abs(cos((pi*(x*x+y*y+z*z))))",
			"B=$DOT$6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
			"T=1"],
			"Name": "Dream",
			"Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
		}
	},
	{
		"Param3D": {
			"Description ": ["Lobed Torus_6 by Abderrahman Taha 08/11/2015"],
			"Name": ["Lobed Torus_6"],
			"Component": ["LobedTorus"],
			"Const": ["cu=0$DOT$0001",
			"cv=0$DOT$0001",
			"N=3"],
			"Funct": ["Thickness=$DOT$4*sin(2*N*v-u)",
			"Fx=(N/2+1+ $DOT$6*cos(u))*cos(v)",
			"Fy=$DOT$6*sin(u)",
			"Fz=(N/2+1+ $DOT$6*cos(u))*sin(v)",
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
			"Umax": ["2*pi"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=$DOT$8*abs(cos((pi*(x*x+y*y+z*z))))",
			"B=$DOT$6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
			"T=1"],
			"Name": "Dream",
			"Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
		}
	},
	{
		"Param3D": {
			"Description ": ["Lobed Torus_7 by Abderrahman Taha 08/11/2015"],
			"Name": ["Lobed Torus_7"],
			"Component": ["LobedTorus"],
			"Const": ["cu=0$DOT$0001",
			"cv=0$DOT$0001",
			"N=3"],
			"Funct": ["Thickness=$DOT$4*sin(N*v)^10",
			"Fx=(N/2+1+ $DOT$6*cos(u))*cos(v)",
			"Fy=$DOT$6*sin(u)",
			"Fz=(N/2+1+ $DOT$6*cos(u))*sin(v)",
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
			"Umax": ["2*pi"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=$DOT$8*abs(cos((pi*(x*x+y*y+z*z))))",
			"B=$DOT$6*abs(cos(cos(pi*(x*x+y*y+z*z))))",
			"T=1"],
			"Name": "Dream",
			"Noise": "NoiseW(2*x,2*y,2*z,8,1,2)"
		}
	},
	{
		"Iso3D": {
			"Description ": ["Torus Distortion due to moving surface by Abderrahman Taha 09/11/2015"],
			"Name": ["Torus Distortion"],
			"Component": ["Drope",
			"Torus"],
			"Fxyz": ["z-Sx*exp(Ex+Ey)-Cy*exp(Ex+Ey)",
			"(sqrt((x-Sx*exp(Ex+Ey))^2 + (y-Cy*exp(Ex+Ey))^2) -1)^2 +(z-Sx*exp(Ex+Ey)-Cy*exp(Ex+Ey))^2 -$DOT$1"],
			"Varu": ["S=1$DOT$5*u*sin(2*tm)",
			"C=2*u*cos(3*tm)",
			"E=-u*u"],
			"Xmax": ["2",
			"1$DOT$8"],
			"Xmin": ["-2",
			"-1$DOT$8"],
			"Ymax": ["2",
			"1$DOT$8"],
			"Ymin": ["-2",
			"-1$DOT$8"],
			"Zmax": ["1$DOT$7",
			"1$DOT$5"],
			"Zmin": ["-1$DOT$7",
			"-1$DOT$5"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Lobs by Abderrahman Taha 08/11/2015"],
			"Name": ["Lobs"],
			"Component": ["Lobs1",
			"Lobs2"],
			"Const": ["cu=0$DOT$001",
			"cv=0$DOT$001"],
			"Funct": ["Thickness1=if( t = 1, if ( (sin(13*v-7*u))<$DOT$4,-1, 3*cos(u)*cos(v)*sin(u)-0$DOT$63),if ( (sin(13*v-7*u))>$DOT$4,-1,3*cos(u)*cos(v)*sin(u)-0$DOT$63))",
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
			"Fx": ["Gx(u,v,1)",
			"Gx(u,v,0)"],
			"Fy": ["Gy(u,v,1)",
			"Gy(u,v,0)"],
			"Fz": ["Gz(u,v,1)",
			"Gz(u,v,0)"],
			"Umax": ["pi/2",
			"pi/2"],
			"Umin": ["-pi/2",
			"-pi/2"],
			"Vmax": ["2*pi",
			"2*pi"],
			"Vmin": ["0",
			"0"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Sphere Parts by Abderrahman Taha 23/10/2015"],
			"Name": ["Sphere Parts"],
			"Component": ["Sphere1",
			"Sphere2"],
			"Const": ["cu=0$DOT$001",
			"cv=0$DOT$001"],
			"Funct": ["Thickness1=if( t = 1, if ( abs(sin(4*u-v))>$DOT$35,-1,$DOT$6*sin(v)),if ( abs(sin(4*u-v))<$DOT$35,-1,0))",
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
			"Fx": ["Gx(u,v,1)",
			"Gx(u,v,0)"],
			"Fy": ["Gy(u,v,1)",
			"Gy(u,v,0)"],
			"Fz": ["Gz(u,v,1)",
			"Gz(u,v,0)"],
			"Umax": ["pi/2",
			"pi/2"],
			"Umin": ["-pi/2",
			"-pi/2"],
			"Vmax": ["2*pi",
			"2*pi"],
			"Vmin": ["0",
			"0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$5*cos(5*(x*x+y*y))",
			"G=0$DOT$5*cos(5*(x*x+y*y+z*z))",
			"B=0$DOT$5*cos(5*(x*x+y*y+z*z))",
			"T=1"],
			"Name": "Granit",
			"Noise": "NoiseW(13*x,13*y,13*z,1,2,0)"
		}
	},
	{
		"Param4D": {
			"Description": ["Ribbon bending by Abderrahman Taha 05/11/2015"],
			"Name": ["Ribbon bending"],
			"Component": ["Ribbon1",
			"Ribbon2"],
			"Fw": ["sin(200*u)/2000",
			"sin(8*u)/5"],
			"Fx": ["sin(u)",
			"sin(u)"],
			"Fy": ["cos(u)",
			"cos(u)"],
			"Fz": ["sin(v)",
			"sin(v)"],
			"Umax": ["2*pi",
			"2*pi"],
			"Umin": ["0",
			"0"],
			"Vmax": ["2*pi",
			"2*pi"],
			"Vmin": ["0",
			"0"]
		}
	},
	{
		"Param3D": {
			"Description": ["Helicoid to Catenoid by Abderrahman Taha 05/11/2015"],
			"Name": ["Helicoid to Catenoid"],
			"Component": ["HelicoidCatenoid"],
			"Fx": ["cos(2*t*pi)*sinh(v)*sin(u) + sin(2*t*pi)*cosh(v)*cos(u)"],
			"Fy": ["-cos(2*t*pi)*sinh(v)*cos(u) + sin(2*t*pi)*cosh(v)*sin(u)"],
			"Fz": ["3*(u*cos(2*t*pi) + v*sin(2*t*pi))"],
			"Umax": ["pi"],
			"Umin": ["-pi"],
			"Vmax": ["pi"],
			"Vmin": ["-pi"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Bouncing Ball_1 by Abderrahman Taha 04/11/2015"],
			"Name": ["Bouncing Ball"],
			"Component": ["Ball",
			"ThickWalls",
			"TransparentWall"],
			"Fxyz": ["((x-(abs(((t*2$DOT$5)%16)-8)-4))^2+(y-(abs(((t*2$DOT$9)%16)-8)-4))^2+(z-(4$DOT$4-((((t*1$DOT$2)%4)-2)^2)))^2-0$DOT$8)",
			"(z+$DOT$407)*(y-4$DOT$9)*(y+4$DOT$9)*(x+4$DOT$9)",
			"(x-4$DOT$9)"],
			"Grid": ["25",
			"15",
			"5"],
			"Xmax": ["4$DOT$81",
			"4$DOT$91",
			"4$DOT$91"],
			"Xmin": ["-4$DOT$81",
			"-4$DOT$91",
			"-4$DOT$91"],
			"Ymax": ["4$DOT$81",
			"4$DOT$91",
			"4$DOT$91"],
			"Ymin": ["-4$DOT$81",
			"-4$DOT$91",
			"-4$DOT$91"],
			"Zmax": ["5$DOT$5",
			"5$DOT$5",
			"5$DOT$5"],
			"Zmin": ["-$DOT$5",
			"-$DOT$41",
			"-$DOT$41"]
		}
	},
	{
		"Param3D": {
			"Name": ["simple Enneper_10"],
			"Component": ["Enneper"],
			"Const": ["k=10"],
			"Description ": ["simple Enneper by Abderrahman Taha 3/11/2015"],
			"Fx": ["k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t)"],
			"Fy": ["-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t)"],
			"Fz": ["(u^k*cos(k*v+t))"],
			"Umax": ["1$DOT$15"],
			"Umin": ["0"],
			"Vmax": ["pi"],
			"Vmin": ["-pi"]
		},
		"Texture": {
			"Colors": ["R=$DOT$91",
			"G=0$DOT$8*abs(cos(5*pi*atan2(x,y)))",
			"B=0$DOT$8*abs(cos(5*pi*atan2(x,y)))",
			"T=1"],
			"Name": "Candy",
			"Noise": "1"
		}
	},
	{
		"Param3D": {
			"Name": ["simple Enneper_8"],
			"Component": ["Enneper"],
			"Const": ["k=8"],
			"Description ": ["simple Enneper by Abderrahman Taha 3/11/2015"],
			"Fx": ["k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t)"],
			"Fy": ["-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t)"],
			"Fz": ["(u^k*cos(k*v+t))"],
			"Umax": ["1$DOT$15"],
			"Umin": ["0"],
			"Vmax": ["pi"],
			"Vmin": ["-pi"]
		},
		"Texture": {
			"Colors": ["R=$DOT$91",
			"G=0$DOT$8*abs(cos(5*pi*atan2(x,y)))",
			"B=0$DOT$8*abs(cos(5*pi*atan2(x,y)))",
			"T=1"],
			"Name": "Candy",
			"Noise": "1"
		}
	},
	{
		"Param3D": {
			"Description ": ["simple Enneper by Abderrahman Taha 3/11/2015"],
			"Name": ["simple Enneper_6"],
			"Component": ["Enneper"],
			"Const": ["k=6"],
			"Fx": ["k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t)"],
			"Fy": ["-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t)"],
			"Fz": ["(u^k*cos(k*v+t))"],
			"Umax": ["1$DOT$15"],
			"Umin": ["0"],
			"Vmax": ["pi"],
			"Vmin": ["-pi"]
		},
		"Texture": {
			"Colors": ["R=$DOT$91",
			"G=0$DOT$8*abs(cos(5*pi*atan2(x,y)))",
			"B=0$DOT$8*abs(cos(5*pi*atan2(x,y)))",
			"T=1"],
			"Name": "Candy",
			"Noise": "1"
		}
	},
	{
		"Param3D": {
			"Description ": ["simple Enneper by Abderrahman Taha 3/11/2015"],
			"Name": ["simple Enneper_4"],
			"Component": ["Enneper"],
			"Const": ["k=4"],
			"Fx": ["k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t)"],
			"Fy": ["-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t)"],
			"Fz": ["(u^k*cos(k*v+t))"],
			"Umax": ["1$DOT$15"],
			"Umin": ["0"],
			"Vmax": ["pi"],
			"Vmin": ["-pi"]
		},
		"Texture": {
			"Colors": ["R=$DOT$91",
			"G=0$DOT$8*abs(cos(5*pi*atan2(x,y)))",
			"B=0$DOT$8*abs(cos(5*pi*atan2(x,y)))",
			"T=1"],
			"Name": "Candy",
			"Noise": "1"
		}
	},
	{
		"Param3D": {
			"Description ": ["Double Enneper by Abderrahman Taha 3/11/2015"],
			"Name": ["Double Enneper_4x4"],
			"Component": ["Enneper_1",
			"Enneper_2"],
			"Const": ["k=4"],
			"Fx": ["k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t)",
			"-(k*u*cos(v+t)-u^(2*k-1)/6*cos((2*k-1)*v+t))"],
			"Fy": ["-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t)",
			"(-k*u*sin(v+t)-u^(2*k-1)/6*sin((2*k-1)*v+t))"],
			"Fz": ["(u^k*cos(k*v+t))",
			"(-u^(k)*cos(k*v+t))"],
			"Umax": ["1$DOT$2",
			"1$DOT$2"],
			"Umin": ["0",
			"0"],
			"Vmax": ["pi",
			"pi"],
			"Vmin": ["-pi",
			"-pi"]
		},
		"Texture": {
			"Colors": ["R=$DOT$91",
			"G=0$DOT$8*abs(cos(5*pi*atan2(x,y)))",
			"B=0$DOT$8*abs(cos(5*pi*atan2(x,y)))",
			"T=1"],
			"Name": "Granit_2",
			"Noise": "1"
		}
	},
	{
		"Iso3D": {
			"Description": ["Contour lines by Abderrahman Taha 01/11/2015"],
			"Name": ["Contour lines_1"],
			"Cnd": ["(z-$DOT$25)*(z+$DOT$25)*(z-$DOT$5)*(z+$DOT$5)*(z-$DOT$75)*(z+$DOT$75)*(z-1)*(z+1)*(z-1$DOT$5)*(z+1$DOT$5)*(z-1$DOT$25)*(z+1$DOT$25)>0"],
			"Component": ["Drope"],
			"Fxyz": ["z-4*x*exp(-x^2-y^2)"],
			"Xmax": ["2"],
			"Xmin": ["-2"],
			"Ymax": ["2"],
			"Ymin": ["-2"],
			"Zmax": ["1$DOT$8"],
			"Zmin": ["-1$DOT$8"]
		}
	},
	{
		"Param3D": {
			"Description": ["Double Helical curve by Abderrahman Taha 01/11/2015"],
			"Name": ["Double Helical curve"],
			"Cnd": ["sqrt(z^2+y^2)-$DOT$200001>0",
			"1"],
			"Component": ["Cosinus",
			"Cylinder"],
			"Fx": ["u",
			"v"],
			"Fy": ["v",
			"$DOT$2*sin(pi*u)"],
			"Fz": ["-sin(5*pi*u)/5",
			"$DOT$2*cos(pi*u)"],
			"Umax": ["1",
			"1"],
			"Umin": ["-1",
			"-1"],
			"Vmax": ["$DOT$5",
			"1"],
			"Vmin": ["-$DOT$5",
			"-1"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Menger Schwarz_1 by Abderrahman Taha 28/10/2015. Menger Sponge Level 3 made out of the skeletal graph of Schwarz's D surface"],
			"Name": ["Skeletal Menger"],
			"Cnd": ["(x+y+z)>0",
			"(x+y+z)>0",
			"(x+y+z)>0",
			"(x+y+z)>0",
			"(x+y+z)>0",
			"(x+y+z)>0",
			"(x+y+z)>0",
			"(x+y+z)>0"],
			"Component": ["MengerSchwarz1",
			"MengerSchwarz2",
			"MengerSchwarz3",
			"MengerSchwarz4",
			"MengerSchwarz5",
			"MengerSchwarz6",
			"MengerSchwarz7",
			"MengerSchwarz8"],
			"Funct": ["Thickness=-0$DOT$013",
			"isoCondition=if((abs(x)>1/3|abs(y)>1/3)&(abs(z)>1/3|abs(y)>1/3)&(abs(x)>1/3|abs(z)>1/3)&(((((abs(x-2/3)<1/9)+(abs(x+2/3)<1/9)+(abs(x)<1/9))*((abs(y-2/3)<1/9)+(abs(y)<1/9)+(abs(y+2/3)<1/9)+(abs(z-2/3)<1/9)+(abs(z)<1/9)+(abs(z+2/3)<1/9)))+(((abs(z-2/3)<1/9)+(abs(z+2/3)<1/9)+(abs(z)<1/9))*((abs(y-2/3)<1/9)+(abs(y)<1/9)+(abs(y+2/3)<1/9))))=0)&(((((abs(x-2/3)<1/27)+(abs(x-2/3-2/9)<1/27)+(abs(x-2/3+2/9)<1/27)+(abs(x+2/3)<1/27)+(abs(x+2/3-2/9)<1/27)+(abs(x+2/3+2/9)<1/27)+(abs(x)<1/27)+(abs(x-2/9)<1/27)+(abs(x+2/9)<1/27))*((abs(y-2/3)<1/27)+(abs(y-2/3-2/9)<1/27)+(abs(y-2/3+2/9)<1/27)+(abs(y)<1/27)+(abs(y-2/9)<1/27)+(abs(y+2/9)<1/27)+(abs(y+2/3)<1/27)+(abs(y+2/3-2/9)<1/27)+(abs(y+2/3+2/9)<1/27)+(abs(z-2/3)<1/27)+(abs(z-2/3-2/9)<1/27)+(abs(z-2/3+2/9)<1/27)+(abs(z)<1/27)+(abs(z-2/9)<1/27)+(abs(z+2/9)<1/27)+(abs(z+2/3)<1/27)+(abs(z+2/3-2/9)<1/27)+(abs(z+2/3+2/9)<1/27)))+(((abs(z-2/3)<1/27)+(abs(z-2/3-2/9)<1/27)+(abs(z-2/3+2/9)<1/27)+(abs(z+2/3)<1/27)+(abs(z+2/3-2/9)<1/27)+(abs(z+2/3+2/9)<1/27)+(abs(z)<1/27)+(abs(z-2/9)<1/27)+(abs(z+2/9)<1/27))*((abs(y-2/3)<1/27)+(abs(y-2/3-2/9)<1/27)+(abs(y-2/3+2/9)<1/27)+(abs(y)<1/27)+(abs(y-2/9)<1/27)+(abs(y+2/9)<1/27)+(abs(y+2/3)<1/27)+(abs(y+2/3-2/9)<1/27)+(abs(y+2/3+2/9)<1/27))))=0),x^100+y^100+z^100-1$DOT$12,1)"],
			"Fxyz": ["if(isoCondition(x,y,z,t)<0,-(cos(84$DOT$823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
			"if(isoCondition(x,y,z,t)<0,-(cos(84$DOT$823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
			"if(isoCondition(x,y,z,t)<0,-(cos(84$DOT$823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
			"if(isoCondition(x,y,z,t)<0,-(cos(84$DOT$823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
			"if(isoCondition(x,y,z,t)<0,-(cos(84$DOT$823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
			"if(isoCondition(x,y,z,t)<0,-(cos(84$DOT$823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
			"if(isoCondition(x,y,z,t)<0,-(cos(84$DOT$823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)",
			"if(isoCondition(x,y,z,t)<0,-(cos(84$DOT$823*( x-Ex*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( y-Ey*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))+cos(84$DOT$823*( z-Ez*Thickness(x,y,z,t)/sqrt(Ex*Ex+Ey*Ey+Ez*Ez)))),1)"],
			"Varu": ["E=sin(84$DOT$823*u)"],
			"Xmax": ["1$DOT$06",
			"1$DOT$06",
			"1$DOT$06",
			"1$DOT$06",
			"0",
			"0",
			"0",
			"0"],
			"Xmin": ["0",
			"0",
			"0",
			"0",
			"-1$DOT$06",
			"-1$DOT$06",
			"-1$DOT$06",
			"-1$DOT$06"],
			"Ymax": ["1$DOT$06",
			"0",
			"1$DOT$06",
			"0",
			"0",
			"1$DOT$06",
			"0",
			"1$DOT$06"],
			"Ymin": ["0",
			"-1$DOT$06",
			"0",
			"-1$DOT$06",
			"-1$DOT$06",
			"0",
			"-1$DOT$06",
			"0"],
			"Zmax": ["1$DOT$06",
			"1$DOT$06",
			"0",
			"0",
			"0",
			"0",
			"1$DOT$06",
			"1$DOT$06"],
			"Zmin": ["0",
			"0",
			"-1$DOT$06",
			"-1$DOT$06",
			"-1$DOT$06",
			"-1$DOT$06",
			"0",
			"0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$7*sqrt(4*x^40+y^4+z^4)",
			"G=$DOT$4*sqrt(x^4+y^4+4*z^20)",
			"B=$DOT$5*sqrt(x^4+4*y^20+z^4)",
			"T=1"],
			"Name": "Granit_2",
			"Noise": "1"
		}
	},
	{
		"Param3D": {
			"Description ": ["Double Nib Parametric surface by Abderrahman Taha 31/10/2015"],
			"Name": ["Double Nib"],
			"Component": ["DoubleNib"],
			"Const": ["cu=0$DOT$0001",
			"cv=0$DOT$0001"],
			"Funct": ["Fx=-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6",
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
			"Thickness=DFyv(u,v,t)*0$DOT$5",
			"Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
			"Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
			"Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
			"Fx": ["Gx(u,v,t)"],
			"Fy": ["Gy(u,v,t)"],
			"Fz": ["Gz(u,v,t)"],
			"Umax": ["1$DOT$3"],
			"Umin": ["0$DOT$3"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=1$DOT$5*$DOT$41",
			"G=2*0$DOT$81*abs(cos((x*x+y*y+z*z)/2) *sin((x*x+y*y+z*z)/2))",
			"B=2*0$DOT$8601*abs(cos((x*x+y*y+z*z)/2) *cos((x*x+y*y+z*z)/2) *sin((x*x+y*y+z*z)/2))",
			"T=1"],
			"Name": "WorleyNoise",
			"Noise": "NoiseW(4*x,4*y,4*z,4,2,0) +NoiseW(4*x,4*y,4*z,4,12,0$DOT$1)"
		}
	},
	{
		"Iso3D": {
			"Description": ["PrettyBall_1 by Abderrahman Taha 28/10/2015"],
			"Name": ["Pretty Ball"],
			"Component": ["PrettyBall_1",
			"PrettyBall_2",
			"PrettyBall_3"],
			"Const": ["cx=0$DOT$0001",
			"cy=0$DOT$0001",
			"cz=0$DOT$0001",
			"xmax=8",
			"xmin=-8",
			"ymax=8",
			"ymin=-8",
			"zmax=8",
			"zmin=-8"],
			"Funct": ["Iso=cos(x)*sin(y)+cos(y)*sin(z)+cos(z)*sin(x)",
			"Thickness=($DOT$9)",
			"Thickness2=($DOT$4)",
			"DFx=((Iso(x,y,z,t)-Iso(x+cx,y,z,t))/cx)",
			"DFy=((Iso(x,y,z,t)-Iso(x,y+cy,z,t))/cy)",
			"DFz=((Iso(x,y,z,t)-Iso(x,y,z+cz,t))/cz)",
			"Rapport=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
			"Iso3=(Iso(x-DFx(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),y-DFy(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),z-DFz(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),t))",
			"Iso2=(Iso(x+DFx(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),y+DFy(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),z+DFz(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),t))",
			"Iso4=(Iso(x-DFx(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),y-DFy(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),z-DFz(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),t))",
			"Iso5=(Iso(x+DFx(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),y+DFy(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),z+DFz(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),t))",
			"ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"isoCondition=(x*x + y*y + z*z - 64)"],
			"Fxyz": ["if(isoCondition(x,y,z,t)<0, ThickIso2(x,y,z,t),1) + exp(isoCondition(x,y,z,t)/3)",
			"if(isoCondition(x,y,z,t)<0, Iso3(x,y,z,t),1) + exp(isoCondition(x,y,z,t)/3)",
			"if(isoCondition(x,y,z,t)<0,-Iso2(x,y,z,t),1) + exp(isoCondition(x,y,z,t)/3)"],
			"Xmax": ["8",
			"8",
			"8"],
			"Xmin": ["-8",
			"-8",
			"-8"],
			"Ymax": ["8",
			"8",
			"8"],
			"Ymin": ["-8",
			"-8",
			"-8"],
			"Zmax": ["8",
			"8",
			"8"],
			"Zmin": ["-8",
			"-8",
			"-8"]
		}
	},
	{
		"Iso3D": {
			"Description ": ["Hexagrams Menger Sponge Level 4 by Abderrahman Taha 24/10/2015"],
			"Name": ["Hexagrams Menger Level 4"],
			"Component": ["MengerSponge"],
			"Cnd": ["(x + y+z)> 0"],
			"Fxyz": [" -(Dx + Dy + Dz -1)*(((abs(x) >1/3 | abs(y) > 1/3)*(abs(z) >1/3 | abs(y) > 1/3)*(abs(x) >1/3 | abs(z) > 1/3))*( (Cx*(Cy+Cz) + Cz*Cy) =0)*( (Bx*(By+Bz) + Bz*By) =0)*( (Ax*(Ay+Az) + Az*Ay) =0) ) "],
			"Varu": [" A = ((abs(u-2/3) <1/81)+ (abs(u-20/27) <1/81)+ (abs(u-16/27) <1/81)+(abs(u-8/9) <1/81) + (abs(u-26/27) <1/81) + (abs(u-22/27) <1/81) +(abs(u-4/9) <1/81) +(abs(u-14/27) <1/81) +(abs(u-10/27) <1/81) +(abs(u+2/3) <1/81) +(abs(u+16/27) <1/81) +(abs(u+20/27) <1/81) +(abs(u+4/9) <1/81) +(abs(u+10/27) <1/81) +(abs(u+14/27) <1/81) +(abs(u+8/9) <1/81) +(abs(u+22/27) <1/81) +(abs(u+26/27) <1/81) +(abs(u) <1/81) + (abs(u-2/27) <1/81) +(abs(u+2/27) <1/81) +(abs(u-2/9) <1/81) + (abs(u-8/27) <1/81) + (abs(u-4/27) <1/81) +(abs(u+2/9) <1/81)+(abs(u+4/27) <1/81)+(abs(u+8/27) <1/81))",
			" B = ((abs(u-2/3) <1/27)+(abs(u-8/9) <1/27) + (abs(u-4/9) <1/27) +(abs(u+2/3) <1/27) +(abs(u+4/9) <1/27) + (abs(u+8/9) <1/27) +(abs(u) <1/27) + (abs(u-2/9) <1/27) + (abs(u+2/9) <1/27))",
			"C = ((abs(u-2/3) <1/9) + (abs(u+2/3) <1/9) + (abs(u) <1/9))",
			"D = u^100"],
			"Xmax": [" 1$DOT$001"],
			"Xmin": ["-1$DOT$001"],
			"Ymax": [" 1$DOT$001"],
			"Ymin": ["-1$DOT$001"],
			"Zmax": [" 1$DOT$001"],
			"Zmin": ["-1$DOT$001"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Virus by Abderrahman Taha 25/10/2015"],
			"Name": ["Virus"],
			"Component": ["Virus"],
			"Funct": ["Thickness= -$DOT$3*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/1$DOT$8)^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/1$DOT$9)^5$DOT$5)",
			"n1= (-(cos(u))*(cos(u)*cos(v)))",
			"n2= ((cos(u))*(-sin(v)*cos(u)))",
			"n3= ((-sin(u)*cos(v))*(cos(u)*cos(v))-(-sin(u)*sin(v))*(-sin(v)*cos(u)))",
			"R=sqrt((n1(u,v,t))^2 + (n2(u,v,t))^2 + (n3(u,v,t))^2 )",
			"Gx=cos(u)*cos(v)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
			"Gy=cos(u)*sin(v)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
			"Gz=sin(u)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)",
			"Hx=n1(u,v,t)* (n1(u,v,t)*Gx(u,v,t)+n2(u,v,t)*Gy(u,v,t)+n3(u,v,t)*Gz(u,v,t))*(1 - cos(2*pi*Thickness(u,v,t)/R(u,v,t))) +Gx(u,v,t)*cos(2*pi*Thickness(u,v,t)/R(u,v,t)) +(-n3(u,v,t)*Gy(u,v,t) + n2(u,v,t)*Gz(u,v,t) ) * sin(2*pi*Thickness(u,v,t)/R(u,v,t))",
			"Hy = n2(u,v,t)* (n1(u,v,t)*Gx(u,v,t)+n2(u,v,t)*Gy(u,v,t)+n3(u,v,t)*Gz(u,v,t))*(1 - cos(2*pi*Thickness(u,v,t)/R(u,v,t))) +Gy(u,v,t)*cos(2*pi*Thickness(u,v,t)/R(u,v,t)) +(n3(u,v,t)*Gx(u,v,t) - n1(u,v,t)*Gz(u,v,t) ) * sin(2*pi*Thickness(u,v,t)/R(u,v,t))",
			"Hz=n3(u,v,t)* (n1(u,v,t)*Gx(u,v,t)+n2(u,v,t)*Gy(u,v,t)+n3(u,v,t)*Gz(u,v,t))*(1 - cos(2*pi*Thickness(u,v,t)/R(u,v,t))) +Gz(u,v,t)*cos(2*pi*Thickness(u,v,t)/R(u,v,t)) +(-n2(u,v,t)*Gx(u,v,t) + n1(u,v,t)*Gy(u,v,t) ) * sin(2*pi*Thickness(u,v,t)/R(u,v,t)) "],
			"Fx": ["Hx(u,v,t)"],
			"Fy": ["Hy(u,v,t)"],
			"Fz": ["Hz(u,v,t)"],
			"Umax": ["pi/2"],
			"Umin": ["-pi/2"],
			"Vmax": ["pi"],
			"Vmin": ["-pi"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=1$DOT$5*abs(cos((x*x+y*y+z*z)/3)*sin((x*x+y*y+z*z)/3))",
			"B=$DOT$2*abs(cos((x*x+y*y+z*z)/3)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/3))",
			"T=1"],
			"Name": "WorleyNoise",
			"Noise": "NoiseW(8*x,8*y,8*z,4,2,0)+NoiseW(8*x,8*y,8*z,4,12,0$DOT$1)"
		}
	},
	{
		"Param3D": {
			"Description ": ["Star by Abderrahman Taha 23/10/2015"],
			"Name": ["Star_2"],
			"Component": ["Star"],
			"Const": ["cu=0$DOT$0000000001",
			"cv=0$DOT$0000000001",
			"N=5"],
			"Funct": ["Thickness= ((sin(15*u)*cos(15*u)))^4 + (sin(2*N*v))",
			"Fx=-cos(u+v)/(sqrt(2$DOT$)+cos(v-u))",
			"Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
			"Fz=sin(u+v)/(sqrt(2$DOT$)+cos(v-u))",
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
		"Param3D": {
			"Description ": ["Star by Abderrahman Taha 23/10/2015"],
			"Name": ["Star_3"],
			"Component": ["Star"],
			"Const": ["cu=0$DOT$0000000001",
			"cv=0$DOT$0000000001",
			"N=5"],
			"Funct": ["Thickness= ((sin(15*u)*cos(15*v)))^4 + (sin(2*N*u))",
			"Fx=-cos(u+v)/(sqrt(2$DOT$)+cos(v-u))",
			"Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
			"Fz=sin(u+v)/(sqrt(2$DOT$)+cos(v-u))",
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
			"Component": ["TheBeginning1",
			"TheBeginning2"],
			"Funct": ["tail=x^2+y^2+z^2-$DOT$1*t",
			"tail2=(x+sin(5*pi*y/20))^2 + (y/10)^2 + (z)^2 - 1",
			"tail3=tail2(x*30,y*30-30,z*30,1)"],
			"Fxyz": ["-((x^2+y^2+z^2-1)+(NoiseW(6*x,6*y,6*z,4,2,0)+NoiseW(6*x,6*y,6*z,4,0,0))/5)*( atan2(y,x)<(pi/2) | atan2(sqrt(x*x+y*y),z)>(pi/2)) *tail(x,y,z,1)",
			"tail3(x*cos(-pi/4)-y*sin(-pi/4),x*sin(-pi/4)+y*cos(-pi/4),z,t)"],
			"Xmax": ["1",
			"-$DOT$5"],
			"Xmin": ["-1",
			"-1"],
			"Ymax": ["1",
			"1$DOT$4"],
			"Ymin": ["-1",
			"$DOT$5"],
			"Zmax": ["1",
			"$DOT$1"],
			"Zmin": ["-1",
			"-$DOT$1"]
		},
		"Texture": {
			"Colors": ["R=$DOT$6",
			"G=2$DOT$4*(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))*sin((x*x+y*y+z*z)/2)",
			"B=$DOT$7*(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"T=1"],
			"Name": "WorleyNoise",
			"Noise": "NoiseW(2*x,2*y,2*z,4,0,0)+NoiseW(2*x,2*y,2*z,2,0,0)"
		}
	},
	{
		"Param3D": {
			"Description ": ["Space Ship by Abderrahman Taha 20/10/2015"],
			"Name": ["Space Ship_1"],
			"Component": ["SpaceShip"],
			"Const": ["cu=0$DOT$000001",
			"cv=0$DOT$000001",
			"N1=16",
			"N2=11",
			"N3=6"],
			"Funct": ["Thickness= ($DOT$2*(abs(sin(N1*u)*cos(N2*v)))^7 + $DOT$2*((sin(N3*u))))",
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
			"Const": ["cu=0$DOT$000001",
			"cv=0$DOT$000001",
			"N1=12",
			"N2=7",
			"N3=5"],
			"Funct": ["Thickness= ($DOT$2*(abs(sin(N1*u)*cos(N2*v)))^6 + $DOT$01*((sin(N3*u))))",
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
			"Const": ["cu=0$DOT$000001",
			"cv=0$DOT$000001",
			"N1=12",
			"N2=7",
			"N3=5"],
			"Funct": ["Thickness= -($DOT$2*(abs(sin(N1*u)*cos(N2*v)))^6 + $DOT$01*((sin(N3*u))))",
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
		"Iso3D": {
			"Description": ["Arena_0 by Abderrahman Taha 19/10/2015"],
			"Name": ["Arena_0"],
			"Component": ["Arena"],
			"Const": ["cx=0$DOT$00001",
			"cy=0$DOT$00001",
			"cz=0$DOT$00001"],
			"Funct": ["Scherk=sinh(x)*sinh(y)-4*sin(z)",
			"Scherk2=Scherk(x,(sqrt(y*y+z*z)-16),z,t)",
			"Thickness2=($DOT$6)",
			"IsoExterior=Scherk2(x,y,z,t)",
			"DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
			"DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
			"DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
			"Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
			"Iso3=(IsoExterior(x-DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y-DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z-DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
			"Iso2=(IsoExterior(x+DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y+DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z+DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
			"ThickIsoExterior=(Iso2(x,y,z,t)*Iso3(x,y,z,t))"],
			"Fxyz": ["if((sqrt(x*x+y*y+z*z) - 20)<0 & abs(x)<6 ,ThickIsoExterior(x,y,z,t), 1)"],
			"Xmax": ["7"],
			"Xmin": ["-7"],
			"Ymax": ["23"],
			"Ymin": ["-23"],
			"Zmax": ["23"],
			"Zmin": ["-23"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Lumpet Tori by Abderrahman Taha 10/10/2015"],
			"Name": ["Lumpet Tori"],
			"Component": ["LumpetTori"],
			"Const": ["cu=0$DOT$0001",
			"cv=0$DOT$0001"],
			"Funct": ["Thickness= $DOT$2*(abs(sin(14*u)*cos(14*v)))^9 + $DOT$4*((sin(8*u)))",
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
			"Component": ["Sphere modelling1",
			"SphereModelling2"],
			"Const": ["cu=0$DOT$001",
			"cv=0$DOT$001",
			"N=1$DOT$5"],
			"Funct": ["Thickness1=if( t = 1, -if (sin(u*(sin(14*v-10*u))) <$DOT$4,-1,$DOT$2*(13*u-pi)*(cos(u)-sin(u))) ,-if (sin(u*(sin(14*v-10*u))) >$DOT$4,-1,$DOT$2*(13*u-pi)*(cos(u)-sin(u))))",
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
			"Fx": ["Gx(u,v,1)",
			"Gx(u,v,0)"],
			"Fy": ["Gy(u,v,1)",
			"Gy(u,v,0)"],
			"Fz": ["Gz(u,v,1)",
			"Gz(u,v,0)"],
			"Umax": ["pi/2",
			"pi/2"],
			"Umin": ["-pi/2",
			"-pi/2"],
			"Vmax": ["2*pi",
			"2*pi"],
			"Vmin": ["0",
			"0"]
		}
	},
	{
		"Iso3D": {
			"Description ": ["The lamp by Abderrahman Taha 18/10/2015"],
			"Name": ["Lamp"],
			"Component": ["Lamp"],
			"Funct": ["Hyperboloid=x^2+y^2-z^2-$DOT$1",
			"Intersection=max(Hyperboloid(x,y,z*3,1),Hyperboloid(x*3,z*3,y*3,2))",
			"Intersection2=max(Hyperboloid(x,y,z+5,1),Hyperboloid(x,y,z-5,1))",
			"Cylinders=((sqrt((x-4$DOT$5)*(x-4$DOT$5)+z*z)-2$DOT$5)^2+y*y-0$DOT$25)*((sqrt((x+4$DOT$5)*(x+4$DOT$5)+z*z)-2$DOT$5)^2+y*y-0$DOT$25)*((sqrt((y+4$DOT$5)*(y+4$DOT$5)+z*z)-2$DOT$5)^2+x*x-0$DOT$25)*((sqrt((y-4$DOT$5)*(y-4$DOT$5)+z*z)-2$DOT$5)^2+x*x-0$DOT$25)*((sqrt(x*x+y*y)-5)^2+z*z-0$DOT$25)*((sqrt(x*x+y*y)-1)^2+(z-5$DOT$85)*(z-5$DOT$85)-0$DOT$02)"],
			"Fxyz": ["(Intersection2(x,y,z,t)*Cylinders(x,y,z,t))-50000"],
			"Xmax": ["8$DOT$5"],
			"Xmin": ["-8$DOT$5"],
			"Ymax": ["8$DOT$5"],
			"Ymin": ["-8$DOT$5"],
			"Zmax": ["6"],
			"Zmin": ["-6"]
		},
		"Texture": {
			"Colors": ["R=$DOT$88*abs(cos(z*y*x))",
			"G=$DOT$43*abs(cos(z*y*x))",
			"B=0$DOT$019*abs(cos(-z*x*z*x*y*y))",
			"T=1"],
			"Name": "Granit_1",
			"Noise": "NoiseP(x-14,y-17$DOT$3,z-16$DOT$5,10,7,0$DOT$2)/1$DOT$1"
		}
	},
	{
		"Param3D": {
			"Description ": ["(Inka Sun) and Carl SequinToroids models by Abderrahman Taha 15/10/2015"],
			"Name": ["Carl Sequin Toroids"],
			"Component": ["Inka Sun1",
			"Inka Sun2"],
			"Const": ["cu=0$DOT$001",
			"cv=0$DOT$001",
			"N=3"],
			"Funct": ["ThicknessInkaSun= if(if(t=1,(abs(sin((N/2)*(u*(sin(v))-u))))<$DOT$4,(abs(sin((N/2)*(u*(sin(v))-u))))>$DOT$38),-$DOT$45,0)",
			"ThicknessSave= if(if(t=1,(abs(sin((N/2)*(u*abs(sin(v))-u))))<$DOT$4,(abs(sin((N/2)*(u*abs(sin(v))-u))))>$DOT$38),-$DOT$45,0)",
			"Thickness1=if( t = 1, if ( (abs(sin((N/2)*u-v)))>$DOT$38,-$DOT$45,0),if ( (abs(sin((N/2)*u-v)))<$DOT$38,-$DOT$45,0))",
			"Fx=(1+0$DOT$5*cos(u))*cos(v)",
			"Fy=0$DOT$5*sin(u)",
			"Fz=(1+0$DOT$5*cos(u))*sin(v)",
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
			"Fx": ["Gx(u,v,1)",
			"Gx(u,v,0)"],
			"Fy": ["Gy(u,v,1)",
			"Gy(u,v,0)"],
			"Fz": ["Gz(u,v,1)",
			"Gz(u,v,0)"],
			"Umax": ["2*pi",
			"2*pi"],
			"Umin": ["0",
			"0"],
			"Vmax": ["2*pi",
			"2*pi"],
			"Vmin": ["0",
			"0"]
		}
	},
	{
		"Param3D": {
			"Description ": ["(Inka Sun) and Carl SequinToroids models by Abderrahman Taha 15/10/2015"],
			"Name": ["Inka Sun_1"],
			"Component": ["Inka Sun11",
			"Inka Sun12"],
			"Const": ["cu=0$DOT$001",
			"cv=0$DOT$001",
			"N=3"],
			"Funct": ["ThicknessInkaSun= if(if(t=1,(abs(sin((N/2)*(u*(sin(v))-u))))<$DOT$4,(abs(sin((N/2)*(u*(sin(v))-u))))>$DOT$38),-$DOT$45,0)",
			"ThicknessSave= if(if(t=1,(abs(sin((N/2)*(u*abs(sin(v))-u))))<$DOT$4,(abs(sin((N/2)*(u*abs(sin(v))-u))))>$DOT$38),-$DOT$45,0)",
			"Thickness1= if(if(t=1,(abs(sin((N/2)*(u*(sin(v))-u))))<$DOT$4,(abs(sin((N/2)*(u*(sin(v))-u))))>$DOT$38),-$DOT$45,0)",
			"Fx=(1+0$DOT$5*cos(u))*cos(v)",
			"Fy=0$DOT$5*sin(u)",
			"Fz=(1+0$DOT$5*cos(u))*sin(v)",
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
			"Fx": ["Gx(u,v,1)",
			"Gx(u,v,0)"],
			"Fy": ["Gy(u,v,1)",
			"Gy(u,v,0)"],
			"Fz": ["Gz(u,v,1)",
			"Gz(u,v,0)"],
			"Umax": ["2*pi",
			"2*pi"],
			"Umin": ["0",
			"0"],
			"Vmax": ["2*pi",
			"2*pi"],
			"Vmin": ["0",
			"0"]
		}
	},
	{
		"Param3D": {
			"Description ": ["(Inka Sun) and Carl SequinToroids models by Abderrahman Taha 15/10/2015"],
			"Name": ["Inka Sun_2"],
			"Component": ["Inka Sun21",
			"Inka Sun22"],
			"Const": ["cu=0$DOT$001",
			"cv=0$DOT$001",
			"N=3"],
			"Funct": ["ThicknessInkaSun= if(if(t=1,(abs(sin((N/2)*(u*(sin(v))-u))))<$DOT$4,(abs(sin((N/2)*(u*(sin(v))-u))))>$DOT$38),-$DOT$45,0)",
			"ThicknessSave= if(if(t=1,(abs(sin((N/2)*(u*abs(sin(v))-u))))<$DOT$4,(abs(sin((N/2)*(u*abs(sin(v))-u))))>$DOT$38),-$DOT$45,0)",
			"Thickness1= if(if(t=1,(abs(sin((N/2)*(u*abs(sin(v))-u))))<$DOT$4,(abs(sin((N/2)*(u*abs(sin(v))-u))))>$DOT$38),-$DOT$45,0)",
			"Fx=(1+0$DOT$5*cos(u))*cos(v)",
			"Fy=0$DOT$5*sin(u)",
			"Fz=(1+0$DOT$5*cos(u))*sin(v)",
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
			"Fx": ["Gx(u,v,1)",
			"Gx(u,v,0)"],
			"Fy": ["Gy(u,v,1)",
			"Gy(u,v,0)"],
			"Fz": ["Gz(u,v,1)",
			"Gz(u,v,0)"],
			"Umax": ["2*pi",
			"2*pi"],
			"Umin": ["0",
			"0"],
			"Vmax": ["2*pi",
			"2*pi"],
			"Vmin": ["0",
			"0"]
		}
	},
	{
		"Iso3D": {
			"Description ": ["Pseudo 4-Noids by Abderrahman Taha 12/10/2015"],
			"Name": ["Pseudo 4-Noids_0"],
			"Component": ["Pseudo-4-Noids"],
			"Fxyz": ["((x^2) - $DOT$685*(y)^2)^2 - 2$DOT$5*(z)^2 - (x^2 + $DOT$75*abs(y*cos(0$DOT$3*x) - z*sin(0$DOT$6*x))^2 + (y*sin(1$DOT$5*x) + z*cos(0$DOT$05*x))^2-0$DOT$5)"],
			"Xmax": [" 1$DOT$9"],
			"Xmin": ["-1$DOT$9"],
			"Ymax": [" 1$DOT$5"],
			"Ymin": ["-1$DOT$5"],
			"Zmax": [" 1$DOT$8"],
			"Zmin": ["-1$DOT$8"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Pseudo k-Noids_1"],
			"Description ": ["Pseudo k-Noids by Abderrahman Taha 14/10/2015"],
			"Component": ["Pseudo-k-Noids"],
			"Funct": ["Noids=((x^2) - $DOT$685*(y)^2)^2 - 2$DOT$5*(z)^2 - (x^2 + $DOT$75*abs(y*cos(0$DOT$3*x) - z*sin(0$DOT$6*x))^2 + (y*sin(1$DOT$5*x) + z*cos(0$DOT$05*x))^2-0$DOT$5)",
			"Noids1=Noids(x,y,(sqrt(x*x+1$DOT$6*z*z)-1),t)",
			"Noids2=Noids1(x,(sqrt(x*x+1$DOT$6*y*y)-1),z,t)",
			"Noids3=Noids2((sqrt(x*x+1$DOT$6*y*y)-1),y,z,t)"],
			"Fxyz": ["Noids2(x,y,z,t)"],
			"Xmax": [" 2$DOT$55"],
			"Xmin": ["-2$DOT$55"],
			"Ymax": [" 2"],
			"Ymin": ["-2"],
			"Zmax": [" 1$DOT$8"],
			"Zmin": ["-1$DOT$8"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Pseudo k-Noids_2"],
			"Description ": ["Pseudo k-Noids by Abderrahman Taha 14/10/2015"],
			"Component": ["Pseudo-k-Noids"],
			"Funct": ["Noids=((x^2) - $DOT$685*(y)^2)^2 - 2$DOT$5*(z)^2 - (x^2 + $DOT$75*abs(y*cos(0$DOT$3*x) - z*sin(0$DOT$6*x))^2 + (y*sin(1$DOT$5*x) + z*cos(0$DOT$05*x))^2-0$DOT$5)",
			"Noids1=Noids(x,y,(sqrt(x*x+1$DOT$6*z*z)-1),t)",
			"Noids2=Noids1(x,(sqrt(x*x+1$DOT$6*y*y)-1),z,t)",
			"Noids3=Noids2((sqrt(x*x+1$DOT$6*y*y)-1),y,z,t)"],
			"Fxyz": ["Noids(x,y,z,t)"],
			"Xmax": [" 2$DOT$55"],
			"Xmin": ["-2$DOT$55"],
			"Ymax": [" 2"],
			"Ymin": ["-2"],
			"Zmax": [" 1$DOT$8"],
			"Zmin": ["-1$DOT$8"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Pseudo k-Noids_3"],
			"Description ": ["Pseudo k-Noids by Abderrahman Taha 14/10/2015"],
			"Component": ["Pseudo-k-Noids"],
			"Funct": ["Noids=((x^2) - $DOT$685*(y)^2)^2 - 2$DOT$5*(z)^2 - (x^2 + $DOT$75*abs(y*cos(0$DOT$3*x) - z*sin(0$DOT$6*x))^2 + (y*sin(1$DOT$5*x) + z*cos(0$DOT$05*x))^2-0$DOT$5)",
			"Noids1=Noids(x,y,(sqrt(x*x+1$DOT$6*z*z)-1),t)",
			"Noids2=Noids1(x,(sqrt(x*x+1$DOT$6*y*y)-1),z,t)",
			"Noids3=Noids2((sqrt(x*x+1$DOT$6*y*y)-1),y,z,t)"],
			"Fxyz": ["Noids1(x,y,z,t)"],
			"Xmax": [" 2$DOT$55"],
			"Xmin": ["-2$DOT$55"],
			"Ymax": [" 2"],
			"Ymin": ["-2"],
			"Zmax": [" 1$DOT$8"],
			"Zmin": ["-1$DOT$8"]
		}
	},
	{
		"Iso3D": {
			"Name": ["Pseudo k-Noids_4"],
			"Description ": ["Pseudo k-Noids by Abderrahman Taha 14/10/2015"],
			"Component": ["Pseudo-k-Noids"],
			"Funct": ["Noids=((x^2) - $DOT$685*(y)^2)^2 - 2$DOT$5*(z)^2 - (x^2 + $DOT$75*abs(y*cos(0$DOT$3*x) - z*sin(0$DOT$6*x))^2 + (y*sin(1$DOT$5*x) + z*cos(0$DOT$05*x))^2-0$DOT$5)",
			"Noids1=Noids(x,y,(sqrt(x*x+1$DOT$6*z*z)-1),t)",
			"Noids2=Noids1(x,(sqrt(x*x+1$DOT$6*y*y)-1),z,t)",
			"Noids3=Noids2((sqrt(x*x+1$DOT$6*y*y)-1),y,z,t)"],
			"Fxyz": ["Noids3(x,y,z,t)"],
			"Xmax": [" 2$DOT$55"],
			"Xmin": ["-2$DOT$55"],
			"Ymax": [" 2"],
			"Ymin": ["-2"],
			"Zmax": [" 1$DOT$8"],
			"Zmin": ["-1$DOT$8"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Pseudo Hopf Tori by Abderrahman Taha 10/10/2015"],
			"Name": ["Pseudo Hopf Tori"],
			"Component": ["PseudoHopfTori"],
			"Const": ["cu=0$DOT$001",
			"cv=0$DOT$001",
			"N=3"],
			"Funct": ["Thickness= (abs(sin(15*u)*cos(15*v)))^7 + $DOT$4*((sin(2*N*u)))",
			"Fx=-cos(u+v)/(sqrt(2$DOT$)+cos(v-u))",
			"Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
			"Fz=sin(u+v)/(sqrt(2$DOT$)+cos(v-u))",
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
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Multi-sided Torus by Abderrahman Taha 13/10/2015"],
			"Name": ["Multi-sided Torus_1"],
			"Component": ["MultiSidedTorus "],
			"Const": ["N=15",
			"R3=3",
			"R=1$DOT$5",
			"r=R/N"],
			"Funct": ["F1 = (R3 + r*cos(u/N+(r-R)/r*v)+(R-r)*cos(u/N+v))",
			"F2 = (r*sin(u/N+(r-R)/r*v)+(R-r)*sin(u/N+v))"],
			"Fx": ["sin(u)*F1(u,v,t)"],
			"Fy": ["cos(u)*F1(u,v,t) "],
			"Fz": ["F2(u,v,t)"],
			"Umax": ["pi"],
			"Umin": ["-pi"],
			"Vmax": ["pi"],
			"Vmin": ["-pi"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Multi-sided Torus by Abderrahman Taha 13/10/2015"],
			"Name": ["Multi-sided Torus_2"],
			"Component": ["MultiSidedTorus "],
			"Const": ["N=10",
			"R3=3",
			"R=1$DOT$5",
			"r=R/N"],
			"Funct": ["F1 = (R3 + r*cos(u/N+(r-R)/r*v)+(R-r)*cos(u/N+v))",
			"F2 = (r*sin(u/N+(r-R)/r*v)+(R-r)*sin(u/N+v))"],
			"Fx": ["sin(u)*F1(u,v,t)"],
			"Fy": ["cos(u)*F1(u,v,t) "],
			"Fz": ["F2(u,v,t)"],
			"Umax": ["pi"],
			"Umin": ["-pi"],
			"Vmax": ["pi"],
			"Vmin": ["-pi"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Multi-sided Torus by Abderrahman Taha 13/10/2015"],
			"Name": ["Multi-sided Torus_3"],
			"Component": ["MultiSidedTorus "],
			"Const": ["N=5",
			"R3=3",
			"R=1$DOT$5",
			"r=R/N"],
			"Funct": ["F1 = (R3 + r*cos(u/N+(r-R)/r*v)+(R-r)*cos(u/N+v))",
			"F2 = (r*sin(u/N+(r-R)/r*v)+(R-r)*sin(u/N+v))"],
			"Fx": ["sin(u)*F1(u,v,t)"],
			"Fy": ["cos(u)*F1(u,v,t) "],
			"Fz": ["F2(u,v,t)"],
			"Umax": ["pi"],
			"Umin": ["-pi"],
			"Vmax": ["pi"],
			"Vmin": ["-pi"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Embedding of the Square Flat Torus (Level 3 ) by Abderrahman Taha 13/10/2015"],
			"Name": ["Embedded Square Flat Torus L3"],
			"Component": ["EmbeddedSquareFlatTorus"],
			"Const": ["cu=0$DOT$0000000001",
			"cv=0$DOT$0000000001",
			"N=10"],
			"Funct": ["Thickness2=if(sin(N*u)>0, $DOT$5*t*((sin(N*u)))^(1/4), -$DOT$5*t*(-(sin(N*u)))^(1/4)) ",
			"Thickness= Thickness2(u,v,1) + Thickness2(15*v-5*u,v,$DOT$05)",
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
			"Description ": ["Embedding of the Square Flat Torus (Level 2 ) by Abderrahman Taha 13/10/2015"],
			"Name": ["Embedded Square Flat Torus L2"],
			"Component": ["EmbeddedSquareFlatTorus"],
			"Const": ["cu=0$DOT$0000000001",
			"cv=0$DOT$0000000001",
			"N=10"],
			"Funct": ["Thickness2=if(sin(N*u)>0, $DOT$5*((sin(N*u)))^(1/4), -$DOT$5*(-(sin(N*u)))^(1/4)) ",
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
			"Description ": ["Sleeping bugs by Abderrahman Taha 11/10/2015"],
			"Name": ["Sleeping bugs"],
			"Component": ["Sleepingbugs"],
			"Const": ["cu=0$DOT$0000000001",
			"cv=0$DOT$0000000001",
			"N=3"],
			"Funct": ["Thickness= -$DOT$5*(abs(sin(15*u)*cos(15*v)))^7 + $DOT$35*((sin(2*N*u)))",
			"Fx=-cos(u+v)/(sqrt(2$DOT$)+cos(v-u))",
			"Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
			"Fz=sin(u+v)/(sqrt(2$DOT$)+cos(v-u))",
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
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=$DOT$9",
			"G=0$DOT$81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))+$DOT$3",
			"B=0$DOT$8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"T=1"],
			"Name": "WorleyNoise",
			"Noise": "NoiseW(2*x,2*y,2*z,4,2,0)+NoiseP(2*x,2*y,2*z,4,12,0$DOT$1)"
		}
	},
	{
		"Param3D": {
			"Description ": ["Pseudo Hopf Tori by Abderrahman Taha 10/10/2015"],
			"Name": ["Pseudo Hopf Tori_3"],
			"Component": ["PseudoHopfTori"],
			"Const": ["cu=0$DOT$0001",
			"cv=0$DOT$0001",
			"N=3"],
			"Funct": ["Thickness= (abs(sin(15*u)*cos(15*v)))^7 + $DOT$4*((sin(2*N*u)))",
			"Fx=-cos(u+v)/(sqrt(2$DOT$)+cos(v-u))",
			"Fy=sin(v-u)/(sqrt(2)+cos(v-u))",
			"Fz=sin(u+v)/(sqrt(2$DOT$)+cos(v-u))",
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
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": ["Fx=-cos(u) *(3 *cos(v) - cos(3 *v))",
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
			"Thickness= ($DOT$4*abs(cos(11*(u))^2 - sin(13*(v))^5 ))^3",
			"Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/(R(u,v,t)+$DOT$0001)",
			"Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/(R(u,v,t)+$DOT$0001)",
			"Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/(R(u,v,t)+$DOT$0001)"],
			"Fx": ["Gx(u*cos(v),v*sin(u),t)"],
			"Fy": ["Gy(u*cos(v),v*sin(u),t)"],
			"Fz": ["Gz(u*cos(v),v*sin(u),t)"],
			"Umax": ["2*pi"],
			"Umin": ["0"],
			"Vmax": [" pi/2"],
			"Vmin": ["-pi/2"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Shells by Abderrahman Taha 09/10/2015"],
			"Name": ["Shells_1"],
			"Component": ["Shells"],
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": ["Fx=-cos(u) *(3 *cos(v) - cos(3 *v))",
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
			"Thickness=($DOT$4*abs(cos(11*(u))^2 - sin(13*(v))^5 ))^3",
			"Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/(R(u,v,t)+$DOT$0001)",
			"Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/(R(u,v,t)+$DOT$0001)",
			"Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/(R(u,v,t)+$DOT$0001)"],
			"Fx": ["Gx(u,v,t)"],
			"Fy": ["Gy(u,v,t)"],
			"Fz": ["Gz(u,v,t)"],
			"Umax": ["2*pi"],
			"Umin": ["0"],
			"Vmax": [" pi/2"],
			"Vmin": ["-pi/2"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Spiny Torus by Abderrahman Taha 09/10/2015"],
			"Name": ["Spiny Torus"],
			"Component": ["SpinyTorus"],
			"Funct": ["Thickness=-($DOT$27*abs(cos(11*(u+v))^2 - sin(13*(v-u))^5 ))^2$DOT$9"],
			"Fx": ["-(1+ 0$DOT$5*cos(u))*cos(v)+Thickness(u,v,t)*(0$DOT$5*cos(u)*(1+ 0$DOT$5*cos(u))*cos(v))/sqrt((0$DOT$5*cos(u)*(1+ 0$DOT$5*cos(u))*cos(v))^2+(-0$DOT$5*sin(u)*sin(v)*sin(v)*(1+ 0$DOT$5*cos(u))-$DOT$5*sin(u)*cos(v)*(1+ 0$DOT$5*cos(u))*cos(v))^2+(-0$DOT$5*cos(u)*sin(v)*(1+ 0$DOT$5*cos(u)))^2)"],
			"Fy": ["0$DOT$5*sin(u)+Thickness(u,v,t)*(-0$DOT$5*sin(u)*sin(v)*sin(v)*(1+ 0$DOT$5*cos(u))-$DOT$5*sin(u)*cos(v)*(1+ 0$DOT$5*cos(u))*cos(v))/sqrt((0$DOT$5*cos(u)*(1+ 0$DOT$5*cos(u))*cos(v))^2+(-0$DOT$5*sin(u)*sin(v)*sin(v)*(1+ 0$DOT$5*cos(u))-$DOT$5*sin(u)*cos(v)*(1+ 0$DOT$5*cos(u))*cos(v))^2+(-0$DOT$5*cos(u)*sin(v)*(1+ 0$DOT$5*cos(u)))^2)"],
			"Fz": ["(1+ 0$DOT$5*cos(u))*sin(v)+Thickness(u,v,t)*(-0$DOT$5*cos(u)*sin(v)*(1+ 0$DOT$5*cos(u)))/sqrt((0$DOT$5*cos(u)*(1+ 0$DOT$5*cos(u))*cos(v))^2+(-0$DOT$5*sin(u)*sin(v)*sin(v)*(1+ 0$DOT$5*cos(u))-$DOT$5*sin(u)*cos(v)*(1+ 0$DOT$5*cos(u))*cos(v))^2+(-0$DOT$5*cos(u)*sin(v)*(1+ 0$DOT$5*cos(u)))^2)"],
			"Umax": ["2*pi"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Holed Spheres (implicit version) by Abderrahman Taha 09/10/2015. In this example:Thickness= $DOT$05*cos((abs(cos(21*atan2(x,y))+sin(19*atan2(z,sqrt(x*x+y*y))))/1$DOT$1)^2)"],
			"Name": ["Holed Spheres v2 (implicit version)"],
			"Component": ["HoledSphere"],
			"Fxyz": ["min(x*x+y*y+z*z-1,(x*x*(1-( $DOT$05*cos((abs(cos(21*atan2(x,y))+sin(19*atan2(z,sqrt(x*x+y*y))))/1$DOT$1)^2))/sqrt(x*x+y*y+z*z))^2+y*y*(1-( $DOT$05*cos((abs(cos(21*atan2(x,y))+sin(19*atan2(z,sqrt(x*x+y*y))))/1$DOT$1)^2))/sqrt(x*x+y*y+z*z))^2+z*z*(1-( $DOT$05*cos((abs(cos(21*atan2(x,y))+sin(19*atan2(z,sqrt(x*x+y*y))))/1$DOT$1)^2))/sqrt(x*x+y*y+z*z))^2-1))*(x*x+y*y+z*z-1)"],
			"Xmax": ["1$DOT$2"],
			"Xmin": ["-1$DOT$2"],
			"Ymax": ["1$DOT$2"],
			"Ymin": ["-1$DOT$2"],
			"Zmax": ["1$DOT$2"],
			"Zmin": ["-1$DOT$2"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Holed Sphere by Abderrahman Taha 9/10/2015"],
			"Name": ["Holed Sphere v2 (parametric version)"],
			"Component": ["HoledSphere"],
			"Fx": ["(cos(u)*cos(v))+($DOT$3*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/1$DOT$8)^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/1$DOT$9)^5$DOT$5))*(-cos(u)*cos(u)*cos(v))/sqrt((-cos(u)*cos(u)*cos(v))^2+(-cos(u)*sin(v)*cos(u))^2+(-sin(u)*cos(v)*cos(u)*cos(v)-sin(v)*cos(u)*sin(u)*sin(v))^2)"],
			"Fy": ["(cos(u)*sin(v))+($DOT$3*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/1$DOT$8)^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/1$DOT$9)^5$DOT$5))*(-cos(u)*sin(v)*cos(u))/sqrt((-cos(u)*cos(u)*cos(v))^2+(-cos(u)*sin(v)*cos(u))^2+(-sin(u)*cos(v)*cos(u)*cos(v)-sin(v)*cos(u)*sin(u)*sin(v))^2)"],
			"Fz": ["(sin(u))+($DOT$3*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/1$DOT$8)^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/1$DOT$9)^5$DOT$5))*(-sin(u)*cos(v)*cos(u)*cos(v)-sin(v)*cos(u)*sin(u)*sin(v))/sqrt((-cos(u)*cos(u)*cos(v))^2+(-cos(u)*sin(v)*cos(u))^2+(-sin(u)*cos(v)*cos(u)*cos(v)-sin(v)*cos(u)*sin(u)*sin(v))^2)"],
			"Umax": ["pi/2"],
			"Umin": ["-pi/2"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Holed Spheres (implicit version) by Abderrahman Taha 08/10/2015"],
			"Name": ["Holed Spheres (implicit version)"],
			"Component": ["HoledSphere_2"],
			"Const": ["cx=0$DOT$0000000000001",
			"cy=0$DOT$0000000000001",
			"cz=0$DOT$0000000000001"],
			"Funct": ["Iso=x*x+y*y+z*z-1",
			"Thickness=( $DOT$05*cos((abs(cos(21*atan2(x,y))+sin(19*atan2(z,sqrt(x*x+y*y))))/1$DOT$1)^2))",
			"DFx=((Iso(x,y,z,t)-Iso(x+cx,y,z,t))/cx)",
			"DFy=((Iso(x,y,z,t)-Iso(x,y+cy,z,t))/cy)",
			"DFz=((Iso(x,y,z,t)-Iso(x,y,z+cz,t))/cz)",
			"Rapport=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
			"Iso2=(Iso(x+t*DFx(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),y+t*DFy(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),z+t*DFz(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),t))",
			"ThickIso=max(Iso2(x,y,z,1), Iso2(x,y,z,-1))"],
			"Fxyz": ["-max(Iso2(x,y,z,1), (x*x+y*y+z*z-1))*Iso2(x,y,z,1)"],
			"Xmax": ["1$DOT$2"],
			"Xmin": ["-1$DOT$2"],
			"Ymax": ["1$DOT$2"],
			"Ymin": ["-1$DOT$2"],
			"Zmax": ["1$DOT$2"],
			"Zmin": ["-1$DOT$2"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Holed Spheres by Abderrahman Taha 08/10/2015"],
			"Name": ["Holed Spheres_3"],
			"Component": ["HoledSpheres"],
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": ["Thickness= $DOT$3*cos((abs(cos(12*v)+cos(6*(v-u))*sin(12*u))/1$DOT$8)^5)*2*sin((abs(cos(7*v)+cos(7*(v-u))*sin(17*u))/1$DOT$9)^5$DOT$5)",
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
			"Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
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
			"Description ": ["Holed Spheres by Abderrahman Taha 08/10/2015"],
			"Name": ["Holed Spheres_4"],
			"Component": ["HoledSpheres"],
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": [" Thickness= (abs(cos(7*u)+cos(7*(v-u*u*u*u*u))*sin(11*v))/2)^9",
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
			"Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
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
			"Description ": ["Holed Spheres by Abderrahman Taha 08/10/2015"],
			"Name": ["Holed Spheres_5"],
			"Component": ["HoledSpheres"],
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": [" Thickness= (abs(cos(7*u)+cos(7*(v-u*u*u))*sin(11*v))/2)^9",
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
			"Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
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
			"Description ": ["Holed Clifford Torus by Abderrahman Taha 07/10/2015"],
			"Name": ["Holed Clifford Torus"],
			"Component": ["HoledCliffordTorus"],
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": ["Fx=-(cos(u+v)/(sqrt(2$DOT$)+cos(v-u)))",
			"Fy=sin(v-u)/(sqrt(2$DOT$)+cos(v-u))",
			"Fz=sin(u+v)/(sqrt(2$DOT$)+cos(v-u))",
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
			"Description ": ["Spiny Sea Creature by Abderrahman Taha 06/10/2015"],
			"Name": ["Spiny Sea Creature"],
			"Component": ["SpinySeaCreature"],
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": ["Fx=cos(u+v)/(sqrt(2$DOT$)+cos(v-u))",
			"Fy=sin(v-u)/(sqrt(2$DOT$)+cos(v-u))",
			"Fz=sin(u+v)/(sqrt(2$DOT$)+cos(v-u))",
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
			"Description ": ["Skeletal Sphere (parametric version) by Abderrahman Taha 05/10/2015"],
			"Name": ["Skeletal Sphere (parametric version)"],
			"Component": ["SkeletalSphere"],
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": ["Fx=cos(u)*cos(v)",
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
			"Thickness=abs($DOT$1*cos(10*u)*sin(10*v))",
			"Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
			"Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
			"Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
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
			"Description": ["Skeletal Sphere (implicit version) by Abderrahman Taha 06/10/2015"],
			"Name": ["Skeletal Sphere (implicit version)"],
			"Component": ["SkeletalSphere"],
			"Const": ["cx=0$DOT$0000000000001",
			"cy=0$DOT$0000000000001",
			"cz=0$DOT$0000000000001"],
			"Funct": ["Iso=x*x+y*y+z*z-1",
			"Thickness=($DOT$1*cos(10*atan2(x,y))*sin(10*atan2(z,sqrt(x*x+y*y))))",
			"DFx=((Iso(x,y,z,t)-Iso(x+cx,y,z,t))/cx)",
			"DFy=((Iso(x,y,z,t)-Iso(x,y+cy,z,t))/cy)",
			"DFz=((Iso(x,y,z,t)-Iso(x,y,z+cz,t))/cz)",
			"Rapport=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
			"Iso2=(Iso(x+t*DFx(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),y+t*DFy(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),z+t*DFz(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),t))",
			"ThickIso=max(Iso2(x,y,z,1), Iso2(x,y,z,-1))"],
			"Fxyz": ["ThickIso(x,y,z,t)"],
			"Xmax": ["1$DOT$2"],
			"Xmin": ["-1$DOT$2"],
			"Ymax": ["1$DOT$2"],
			"Ymin": ["-1$DOT$2"],
			"Zmax": ["1$DOT$2"],
			"Zmin": ["-1$DOT$2"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Twisted Clifford Torus by Abderrahman Taha 05/10/2015"],
			"Name": ["Twisted Clifford Torus"],
			"Component": ["TwistedClifford"],
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": ["Fx=cos(u+v)/(sqrt(2$DOT$)+cos(v-u))",
			"Fy=sin(v-u)/(sqrt(2$DOT$)+cos(v-u))",
			"Fz=sin(u+v)/(sqrt(2$DOT$)+cos(v-u))",
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
			"Thickness=0$DOT$3*sin(10*u)*cos(10*v)",
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
			"Description ": ["Bumpy Klein by Abderrahman Taha 05/10/2015"],
			"Component": ["Klein"],
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": ["Fx=(2+cos(v/2)*sin(u)-sin(v/2)*sin(2*u))*cos(v)",
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
			"Thickness=0$DOT$1*sin(20*v)*cos(20*u)",
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
			"Description ": ["Richmond polar Parametric surface by Abderrahman Taha 04/10/2015"],
			"Component": ["richmondpolar1"],
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": ["Fx=-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6",
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
			"Thickness=$DOT$3",
			"Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
			"Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
			"Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
			"Fx": ["Fx(u,v,t)"],
			"Fy": ["Fy(u,v,t)"],
			"Fz": ["Fz(u,v,t)"],
			"Name": ["Richmond Polar_1"],
			"Umax": ["1$DOT$3"],
			"Umin": ["0$DOT$3"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Richmond polar Parametric surface by Abderrahman Taha 04/10/2015"],
			"Name": ["Richmond Polar_2"],
			"Component": ["richmondpolar1",
			"richmondpolar2"],
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": ["Fx=-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6",
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
			"Thickness=0$DOT$1*sin(20*v)",
			"Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
			"Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
			"Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
			"Fx": ["Fx(u,v,t)",
			"Gx(u,v,t)"],
			"Fy": ["Fy(u,v,t)",
			"Gy(u,v,t)"],
			"Fz": ["Fz(u,v,t)",
			"Gz(u,v,t)"],
			"Umax": ["1$DOT$3",
			"1$DOT$3"],
			"Umin": ["0$DOT$3",
			"0$DOT$3"],
			"Vmax": ["2*pi",
			"2*pi"],
			"Vmin": ["0",
			"0"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Richmond polar Parametric surface by Abderrahman Taha 04/10/2015"],
			"Name": ["Bat coat"],
			"Component": ["richmondpolar2"],
			"Const": ["cu=0$DOT$0000000000001",
			"cv=0$DOT$0000000000001"],
			"Funct": ["Fx=-cos(t+v)/(2*u)-u^3*cos(t-3*v)/6",
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
			"Thickness=DFyu(u,v,t)*DFxv(u,v,t)*0$DOT$5",
			"Gx=Fx(u,v,t)+Thickness(u,v,t)*n1(u,v,t)/R(u,v,t)",
			"Gy=Fy(u,v,t)+Thickness(u,v,t)*n2(u,v,t)/R(u,v,t)",
			"Gz=Fz(u,v,t)+Thickness(u,v,t)*n3(u,v,t)/R(u,v,t)"],
			"Fx": ["Gx(u,v,t)"],
			"Fy": ["Gy(u,v,t)"],
			"Fz": ["Gz(u,v,t)"],
			"Umax": ["1$DOT$3"],
			"Umin": ["0$DOT$3"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		}
	},
	{
		"Param3D": {
			"Description ": ["Under Sea by Abderrahman Taha 02/10/2015"],
			"Name": ["Under The Sea"],
			"Component": ["UnderSea"],
			"Fx": ["u*cos(v)"],
			"Fy": ["u*sin(v)"],
			"Fz": ["exp(-u*u)*(sin(2*pi*u)-u*cos(3*v))"],
			"Umax": ["2"],
			"Umin": ["0"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=1$DOT$5*$DOT$41",
			"G=2*0$DOT$81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"B=2*0$DOT$8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"T=1"],
			"Name": "WorleyNoise",
			"Noise": "NoiseW(4*x,4*y,4*z,4,2,0)+NoiseW(4*x,4*y,4*z,4,12,0$DOT$1)"
		}
	},
	{
		"Iso3D": {
			"Description": ["Devil's Plate by Abderrahman Taha 01/10/2015"],
			"Name": ["Devil Plate"],
			"Component": ["DevilPlate"],
			"Const": ["cx=0$DOT$001",
			"cy=0$DOT$001",
			"cz=0$DOT$00"],
			"Funct": ["Devil=x^4+2*x^2*z^2-0$DOT$36*x^2-y^4+0$DOT$25*y^2+z^4",
			"Devil2=Devil(x,sqrt(y*y+z*z)-1$DOT$5,z,t)",
			"Thickness2=($DOT$1)",
			"IsoExterior=Devil2(x,y,sqrt(x*x+z*z)-1$DOT$5,t)",
			"DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
			"DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
			"DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
			"Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
			"Iso2=(IsoExterior(x+t*DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y+t*DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z+t*DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
			"ThickIsoExterior=(Iso2(x,y,z,1)*Iso2(x,y,z,-1))"],
			"Fxyz": ["if(y<4$DOT$4 & y> -2$DOT$4, ThickIsoExterior(x/1$DOT$5,y,z,t), 1)"],
			"Xmax": [" 4$DOT$5"],
			"Xmin": ["-4$DOT$5"],
			"Ymax": [" 4$DOT$5"],
			"Ymin": ["-2$DOT$5"],
			"Zmax": [" 7$DOT$5"],
			"Zmin": ["-7$DOT$5"]
		},
		"Texture": {
			"Colors": ["R=$DOT$95*abs(cos(z*y*x))",
			"G=$DOT$45*abs(cos(z*y*x))",
			"B=0$DOT$02*abs(cos(-z*x*z*x*y*y))",
			"T=1"],
			"Name": "Granit_1",
			"Noise": "NoiseP(x-14,y-17$DOT$3,z-16$DOT$5,10,7,0$DOT$12)"
		}
	},
	{
		"Iso3D": {
			"Component": ["DevilPlay"],
			"Const": ["cx=0$DOT$0000000000001",
			"cy=0$DOT$0000000000001",
			"cz=0$DOT$0000000000001"],
			"Description": ["Devil Play by Abderrahman Taha 01/10/2015"],
			"Funct": ["Devil=x^4+2*x^2*z^2-0$DOT$36*x^2-y^4+0$DOT$25*y^2+z^4",
			"Devil2=Devil(x,sqrt(y*y+z*z)-1$DOT$5,z,t)",
			"Thickness2=($DOT$1)",
			"IsoExterior=Devil2(x,y,sqrt(x*x+z*z)-1$DOT$5,t)",
			"DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
			"DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
			"DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
			"Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
			"Iso2=(IsoExterior(x+t*DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y+t*DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z+t*DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
			"ThickIsoExterior=(Iso2(x,y,z,1)*Iso2(x,y,z,-1))"],
			"Fxyz": ["IsoExterior(x,y,z,t)"],
			"Name": ["Devil Play"],
			"Xmax": [" 4$DOT$5"],
			"Xmin": ["-4$DOT$5"],
			"Ymax": [" 4$DOT$5"],
			"Ymin": ["-2$DOT$5"],
			"Zmax": [" 7$DOT$5"],
			"Zmin": ["-7$DOT$5"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Tore-1$DOT$0 by Abderrahman Taha 29/09/2015"],
			"Name": ["ToreSherk"],
			"Component": ["ToreSherk"],
			"Const": ["cx=0$DOT$0000000000001",
			"cy=0$DOT$0000000000001",
			"cz=0$DOT$0000000000001"],
			"Funct": ["Scherk=sinh(x)*sinh(y)-5*sin(z)",
			"Scherk2=Scherk(x,(sqrt(y*y+x*x)-10),z,t)",
			"Thickness2=($DOT$43)",
			"IsoExterior=Scherk2(x,(sqrt(y*y+z*z)-26),z,t)",
			"DFx2=((IsoExterior(x,y,z,t)-IsoExterior(x+cx,y,z,t))/cx)",
			"DFy2=((IsoExterior(x,y,z,t)-IsoExterior(x,y+cy,z,t))/cy)",
			"DFz2=((IsoExterior(x,y,z,t)-IsoExterior(x,y,z+cz,t))/cz)",
			"Rapport2=(sqrt(DFx2(x,y,z,t)*DFx2(x,y,z,t)+DFy2(x,y,z,t)*DFy2(x,y,z,t)+DFz2(x,y,z,t)*DFz2(x,y,z,t)))",
			"Iso3=(IsoExterior(x-DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y-DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z-DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
			"Iso2=(IsoExterior(x+DFx2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),y+DFy2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),z+DFz2(x,y,z,t)*Thickness2(x,y,z,t)/Rapport2(x,y,z,t),t))",
			"ThickIsoExterior=(Iso2(x,y,z,t)*Iso3(x,y,z,t))"],
			"Fxyz": ["if((sqrt(y*y+z*z)-37<0)&(sqrt(y*y+z*z)-16>0) & ( (sqrt(y*y+z*z)-26)^2+x*x-75>0 ),ThickIsoExterior(x,y,z,t),1)+$DOT$1"],
			"Xmax": ["11"],
			"Xmin": ["-11"],
			"Ymax": ["38"],
			"Ymin": ["-38"],
			"Zmax": ["38"],
			"Zmin": ["-38"]
		},
		"Texture": {
			"Colors": ["R=$DOT$71",
			"G=1$DOT$1*abs(cos((x*x+y*y+z*z))*sin((x*x+y*y+z*z)/2))",
			"B=$DOT$01*abs(cos((x*x+y*y+z*z))*cos((x*x+y*y+z*z)/2))",
			"T=1"],
			"Name": "PerlinNoise",
			"Noise": "NoiseP(x,y,z,6,0$DOT$7,1$DOT$1)/30"
		}
	},
	{
		"Iso3D": {
			"Description ": ["Geode by Abderrahman Taha 28/09/2015"],
			"Name": ["Geode"],
			"Component": ["Geode1",
			"Geode2"],
			"Const": ["A=4",
			"B=3"],
			"Fxyz": ["-((((x/1$DOT$01)^2+y^2+(z/1$DOT$05)^2-1)+(NoiseW(A*x,A*y,A*z,4,2,1)+NoiseW(A*x,A*y,A*z,4,0,0))/3))*(atan2(x,y)<pi/2)*(x^2+y^2+z^2-0$DOT$2)",
			"-(((x^2+y^2+z^2-0$DOT$21)*(atan2(x,y)<pi/2)*((x^2+y^2+z^2-0$DOT$2)+(NoiseW(B*x,B*y,B*z,4,2,1)+NoiseW(B*x,B*y,B*z,4,2,1))/5)))"],
			"Xmax": ["1$DOT$5",
			"1$DOT$5"],
			"Xmin": ["-1",
			"-1"],
			"Ymax": ["1",
			"1"],
			"Ymin": ["-1",
			"-1"],
			"Zmax": ["1$DOT$5",
			"1$DOT$5"],
			"Zmin": ["-1",
			"-1"]
		},
		"Texture": {
			"Colors": ["R=if((x*x+y*y+z*z)>$DOT$81,$DOT$95*cos((x*x+y*y+z*z)/1$DOT$7), 0$DOT$2)",
			"G=if((x*x+y*y+z*z)>$DOT$8, $DOT$8*(cos((x*x+y*y+z*z)/5)*sin((x*x+y*y+z*z)))*sin((x*x+y*y+z*z)/$DOT$3), $DOT$5*sin((x*x+y*y+z*z)*9))",
			"B=if((x*x+y*y+z*z)<$DOT$8,(cos((x*x+y*y+z*z))*cos((x*x+y*y+z*z))*sin((x*x+y*y+z*z)))+$DOT$4, 0$DOT$1)",
			"T=1"],
			"Name": "WorleyNoise",
			"Noise": "-(NoiseW(2*x,2*y,2*z,4,0,0)+NoiseW(2*x,2*y,2*z,4,0,0))"
		}
	},
	{
		"Iso3D": {
			"Name": ["The Core"],
			"Component": ["Core"],
			"Description ": ["The core by Abderrahman Taha 27/09/2015"],
			"Fxyz": ["-((x^2+y^2+z^2-1)+(NoiseW(6*x,6*y,6*z,4,2,0)+NoiseW(6*x,6*y,6*z,4,0,0))/5)*(atan2(x,y)<pi/2)"],
			"Xmax": ["1"],
			"Xmin": ["-1"],
			"Ymax": ["1"],
			"Ymin": ["-1"],
			"Zmax": ["1"],
			"Zmin": ["-1"]
		},
		"Texture": {
			"Colors": ["R=$DOT$7",
			"G=2$DOT$4*(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))*sin((x*x+y*y+z*z)/2)",
			"B=$DOT$7*(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"T=1"],
			"Name": "WorleyNoise",
			"Noise": "NoiseW(2*x,2*y,2*z,4,0,0)+NoiseW(2*x,2*y,2*z,2,0,0)"
		}
	},
	{
		"Param3D": {
			"Name": ["Richmond Polar_4"],
			"Component": ["richmondpolar"],
			"Description ": ["richmondpolar(n)[t](u,v):={-cos(t + v)/(2*u) -u^(2*n + 1)*cos(t - (2*n + 1)*v)/(4*n + 2),-sin(t + v)/(2*u) +u^(2*n + 1)*sin(t - (2*n + 1)*v)/(4*n + 2),u^n*cos(t - n*v)/n}is the polar parametrization of a 1-parameter family of minimal surfaces such that {r,theta}->richmondpolar[n][0][r,theta] is a minimal surface with one planar end of degree n."],
			"Fx": ["-cos(t + v)/(2*u) - u^3*cos(t - 3*v)/6"],
			"Fy": ["-sin(t + v)/(2*u) + u^3*sin(t - 3*v)/6"],
			"Fz": ["u*cos(t - v)"],
			"Umax": ["1$DOT$3"],
			"Umin": ["0$DOT$3"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		},
		"Texture": {
			"Colors": ["R=1$DOT$5*$DOT$41",
			"G=2*0$DOT$81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"B=2*0$DOT$8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
			"T=1"],
			"Name": "WorleyNoise",
			"Noise": "NoiseW(4*x,4*y,4*z,4,2,0)+NoiseW(4*x,4*y,4*z,4,12,0$DOT$1)"
		}
	},
	{
		"Param3D": {
			"Description": ["Flower_1 by Abderrahman Taha 26/09/2015"],
			"Name": ["Flower"],
			"Component": ["BreatherNoise"],
			"Fx": ["((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*cos(v)*cos(sqrt(0$DOT$84)*v))-sin(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2)))*(1-NoiseW(((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*cos(v)*cos(sqrt(0$DOT$84)*v))-sin(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*sin(v)*cos(sqrt(0$DOT$84)*v))+cos(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),(-u+(2*0$DOT$84*cosh(0$DOT$4*u)*sinh(0$DOT$4*u))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),1,2,0))"],
			"Fy": ["((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*sin(v)*cos(sqrt(0$DOT$84)*v))+cos(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2)))*(1 -NoiseW(((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*cos(v)*cos(sqrt(0$DOT$84)*v))-sin(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*sin(v)*cos(sqrt(0$DOT$84)*v))+cos(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),(-u+(2*0$DOT$84*cosh(0$DOT$4*u)*sinh(0$DOT$4*u))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),1,2,0))"],
			"Fz": ["(-u+(2*0$DOT$84*cosh(0$DOT$4*u)*sinh(0$DOT$4*u))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2)))*(1 - NoiseW(((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*cos(v)*cos(sqrt(0$DOT$84)*v))-sin(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),((2*sqrt(0$DOT$84)*cosh(0$DOT$4*u)*(-(sqrt(0$DOT$84)*sin(v)*cos(sqrt(0$DOT$84)*v))+cos(v)*sin(sqrt(0$DOT$84)*v)))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),(-u+(2*0$DOT$84*cosh(0$DOT$4*u)*sinh(0$DOT$4*u))/(0$DOT$4*((sqrt(0$DOT$84)*cosh(0$DOT$4*u))^2+(0$DOT$4*sin(sqrt(0$DOT$84)*v))^2))),1,2,0))"],
			"Umax": ["13$DOT$2"],
			"Umin": ["-13$DOT$2"],
			"Vmax": ["37$DOT$4"],
			"Vmin": ["-37$DOT$4"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Broken Jar by Abderrahman Taha 24/09/2015"],
			"Name": ["BrokenJar"],
			"Component": ["Vase1",
			"Vase2",
			"Vase3",
			"Vase4"],
			"Const": ["cx=0$DOT$0000000000001",
			"cy=0$DOT$0000000000001",
			"cz=0$DOT$0000000000001",
			"S=6",
			"Thickness2=($DOT$25)",
			"Thickness4=($DOT$2)",
			"Thickness5=($DOT$2)",
			"Thickness6=(1$DOT$2)",
			"Thickness7=(1$DOT$2)"],
			"Funct": ["Angle1=atan2(sqrt(x*x+y*y),(-z+cx))",
			"Angle2=atan2(x,(y+cx))",
			"CarvinCondition=(abs((z-1)-$DOT$8*cos(18*Angle2(x,y,z,t)/pi))<1$DOT$3|abs((z+3)-$DOT$3*cos(18*Angle2(x,y,z,t)/pi+pi/4))<$DOT$5)",
			"CarvinCondition2=(z-3*sin(3$DOT$2*Angle2(x,y,z,t)/pi))>0",
			"Torus=(sqrt(x*x+y*y)-3)^2+z*z-1",
			"IsoExterior=if(-z<5,(x*x/3$DOT$+y*y/3$DOT$-abs(1$DOT$5*sin(2*z/pi+$DOT$3)+1$DOT$8)),-(-z-5))",
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
			"VaseHead2=VaseHead((x+6)*cos(-pi/2)-(z+2$DOT$5)*sin(-pi/2),y,(x+6)*sin(-pi/2)+(z+2$DOT$5)*cos(-pi/2),t)",
			"Torus2=Torus(1$DOT$7*x,1$DOT$7*y,2$DOT$2*(z+cos(pi/4*sqrt(x*x+y*y)))-10$DOT$6,t)",
			"Torus3=Torus2((x+6)*cos(-pi/2)-(z+2$DOT$5)*sin(-pi/2),y,(x+6)*sin(-pi/2)+(z+2$DOT$5)*cos(-pi/2),t)",
			"VaseBottom=if(CarvinCondition2(x,y,z,t)=0,isoTransform_2(x,y,-z,t)*isoTransform_6(x,y,-z,t),1)"],
			"Fxyz": ["VaseBottom(x*cos(-pi/5)-y*sin(-pi/5),x*sin(-pi/5)+y*cos(-pi/5),z,t)",
			"((x*x+y*y)/5$DOT$76+4*(z+5$DOT$1)*(z+5$DOT$1)-1)",
			"VaseHead2(x*cos(pi/2)-y*sin(pi/2)-5,x*sin(pi/2)+y*cos(pi/2)+6,z,t)",
			"Torus3(x*cos(pi/2)-y*sin(pi/2)-5,x*sin(pi/2)+y*cos(pi/2)+6,z,t)"],
			"Xmax": ["3$DOT$5",
			"3",
			"-3",
			"-2"],
			"Xmin": ["-3$DOT$5",
			"-3",
			"-9",
			"-9"],
			"Ymax": ["3$DOT$5",
			"3",
			"5$DOT$47",
			"8"],
			"Ymin": ["-3$DOT$5",
			"-3",
			"-2$DOT$5",
			"5"],
			"Zmax": ["3",
			"-4$DOT$5",
			"1$DOT$5",
			"0"],
			"Zmin": ["-5",
			"-5$DOT$7",
			"-6",
			"-5"]
		},
		"Texture": {
			"Colors": ["R=$DOT$95*abs(cos(z*y*x*y))",
			"G=$DOT$45*abs(cos(z*y*x*y))",
			"B=0$DOT$02*abs(cos(-z*x*z*x*y*y))",
			"T=1"],
			"Name": "Granit_1",
			"Noise": "NoiseP(x,y,z,10,7,0$DOT$12)"
		}
	},
	{
		"Iso3D": {
			"Description": ["Old Vase by Abderrahman Taha 23/09/2015"],
			"Name": ["OldVase"],
			"Component": ["Vase1",
			"Vase5",
			"Vase6"],
			"Const": ["cx=0$DOT$0000000000001",
			"cy=0$DOT$0000000000001",
			"cz=0$DOT$0000000000001",
			"S=6",
			"Thickness2=($DOT$25)",
			"Thickness4=($DOT$2)",
			"Thickness5=($DOT$2)",
			"Thickness6=(1$DOT$2)",
			"Thickness7=(1$DOT$2)"],
			"Funct": ["Angle1=atan2(sqrt(x*x+y*y),(-z+cx))",
			"Angle2=atan2(x,(y+cx))",
			"CarvinCondition=abs((z-1)-$DOT$8*cos(18*Angle2(x,y,z,t)/pi))<1$DOT$3|abs((z+3)-$DOT$3*cos(18*Angle2(x,y,z,t)/pi+pi/4))<$DOT$5",
			"Torus=(sqrt(x*x+y*y)-3)^2+z*z-1",
			"Bottom=(x*x+y*y+z*z-1)",
			"IsoExterior=x*x/3$DOT$+y*y/3$DOT$-abs(1$DOT$5*sin(2*z/pi+$DOT$3)+1$DOT$8)",
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
			"isoTransform_6=if(CarvinCondition(x,y,z,t)&ThickIsoExterior(x,y,z,t)<0,-ThickIso2(S*x,S*y,S*z,t)*Iso6(x*S,y*S,z*S,-1)*(Iso6(x*S,y*S,z*S,1)),1)"],
			"Fxyz": ["isoTransform_2(x,y,-z,t)*isoTransform_6(x,y,-z,t)",
			"Torus(1$DOT$7*x,1$DOT$7*y,2$DOT$2*(z+cos(pi/4*sqrt(x*x+y*y)))-10$DOT$6,t)",
			"Bottom(x/2$DOT$4,y/2$DOT$4,2*(z+5$DOT$1),t)"],
			"Xmax": ["3$DOT$5",
			"5",
			"3"],
			"Xmin": ["-3$DOT$5",
			"-5",
			"-3"],
			"Ymax": ["3$DOT$5",
			"5",
			"3"],
			"Ymin": ["-3$DOT$5",
			"-5",
			"-3"],
			"Zmax": ["4$DOT$5",
			"10",
			"-2"],
			"Zmin": ["-5",
			"0",
			"-7"]
		},
		"Texture": {
			"Colors": ["R=$DOT$95*abs(cos(z*y*x*y))",
			"G=$DOT$45*abs(cos(z*y*x*y))",
			"B=0$DOT$02*abs(cos(-z*x*z*x*y*y))",
			"T=1"],
			"Name": "Granit_1",
			"Noise": "NoiseP(x,y,z,10,7,0$DOT$12)"
		}
	},
	{
		"Iso3D": {
			"Description": ["Vases_1 by Abderrahman Taha 19/09/2015"],
			"Name": ["Vases_1"],
			"Component": ["Vase1",
			"Vase2",
			"Vase3",
			"Vase4",
			"Vase5",
			"Vase6"],
			"Const": ["cx=0$DOT$0000000000001",
			"cy=0$DOT$0000000000001",
			"cz=0$DOT$0000000000001",
			"Thickness2=($DOT$25)",
			"Thickness4=($DOT$2)",
			"Thickness5=($DOT$2)",
			"Thickness6=(1$DOT$2)",
			"Thickness7=(1$DOT$2)"],
			"Funct": ["Torus=(sqrt(x*x+y*y)-3)^2+z*z-1",
			"Bottom=(x*x + y*y + z*z - 1)",
			"CarvinCondition=sin(atan2(sqrt(x*x+y*y),(-z+cx)))>1/1$DOT$1",
			"IsoExterior=x*x/3$DOT$+y*y/3$DOT$-abs(1$DOT$5*sin(2*z/pi+$DOT$3)+1$DOT$8)",
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
			"isoTransform_5=if(CarvinCondition(x,y,z,t)&ThickIsoExterior(x,y,z,t)<0,-Iso6(x*5,y*5,z*5,1),1)"],
			"Fxyz": ["isoTransform_2(x,y,-z,t)",
			"isoTransform_3(x,y,-z,t)",
			"isoTransform_4(x,y,-z,t)",
			"isoTransform_5(x,y,-z,t)",
			"Torus(1$DOT$7*x,1$DOT$7*y,2$DOT$2*(z+cos(pi/4*sqrt(x*x+y*y)))-10$DOT$6,t)",
			"Bottom(x/2$DOT$4,y/2$DOT$4,2*(z+5$DOT$1),t)"],
			"Xmax": ["5",
			"3$DOT$5",
			"3$DOT$5",
			"3$DOT$5",
			"3",
			"3"],
			"Xmin": ["-5",
			"-3$DOT$5",
			"-3$DOT$5",
			"-3$DOT$5",
			"-3",
			"-3"],
			"Ymax": ["5",
			"3$DOT$5",
			"3$DOT$5",
			"3$DOT$5",
			"3",
			"3"],
			"Ymin": ["-5",
			"-3$DOT$5",
			"-3$DOT$5",
			"-3$DOT$5",
			"-3",
			"-3"],
			"Zmax": ["4$DOT$5",
			"2",
			"2",
			"2",
			"7",
			"-2"],
			"Zmin": ["-5",
			"-2",
			"-2",
			"-2",
			"0",
			"-7"]
		}
	},
	{
		"Param3D": {
			"Description": ["SeaShells_1 by Abderrahman Taha 12/09/2015"],
			"Name": ["SeaShells"],
			"Component": ["SeaShells"],
			"Const": ["a = 40",
			"b = 14",
			"D = 1",
			"A = 50",
			"Mu = 10*3$DOT$14/180",
			"Alfa = 84*3$DOT$14/180",
			"Beta = -19*3$DOT$14/180",
			"Omega = -2*3$DOT$14/180",
			"Phi = 45*3$DOT$14/180",
			"L = 8",
			"P = 0",
			"W1 = 6*3$DOT$14/180",
			"W2 = 27*3$DOT$14/180",
			"N = 8"],
			"Funct": ["Re=(1/sqrt((cos(u)/a)^2 + (sin(u)/b)^2) + if(W1=0|W2=0|N=0,0, L*exp(-(2*(u-P)/W1)^2-(2*(2*3$DOT$14*(N*v/(2*3$DOT$14) -floor(N*v/(2*3$DOT$14))))/W2)^2)) )"],
			"Fx": ["D*(A*sin(Beta)*cos(u) + Re(v,u,t)*(cos(v+Phi)*cos(u+Omega) - sin(Mu)*sin(v+Phi)*sin(u+Omega)))*exp(u*cot(Alfa))"],
			"Fy": ["(-A*sin(Beta)*sin(u) - Re(v,u,t)*(cos(v+Phi)*sin(u+Omega) + sin(Mu)*sin(v+Phi)*cos(u+Omega)))*exp(u*cot(Alfa))"],
			"Fz": ["(-A*cos(Beta) + Re(v,u,t)*sin(v+Phi)*cos(Mu))*exp(u*cot(Alfa))"],
			"Umax": ["4*pi"],
			"Umin": ["-4*pi"],
			"Vmax": ["2*pi"],
			"Vmin": ["0"]
		}
	},
	{
		"Iso3D": {
			"Description": ["Pseudo Duplin_2 by Abderrahman Taha 12/09/2015"],
			"Name": ["Pseudo Duplin_2"],
			"Component": ["PseudoDuplin"],
			"Const": ["cx=0$DOT$0000000000001",
			"cy=0$DOT$0000000000001",
			"cz=0$DOT$0000000000001"],
			"Funct": ["Iso=cos(x)+cos(y)+cos(z)",
			"Thickness=($DOT$9)",
			"Thickness2=($DOT$4)",
			"DFx=((Iso(x,y,z,t)-Iso(x+cx,y,z,t))/cx)",
			"DFy=((Iso(x,y,z,t)-Iso(x,y+cy,z,t))/cy)",
			"DFz=((Iso(x,y,z,t)-Iso(x,y,z+cz,t))/cz)",
			"Rapport=(sqrt(DFx(x,y,z,t)*DFx(x,y,z,t)+DFy(x,y,z,t)*DFy(x,y,z,t)+DFz(x,y,z,t)*DFz(x,y,z,t)))",
			"Iso3=(Iso(x-DFx(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),y-DFy(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),z-DFz(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),t))",
			"Iso2=(Iso(x+DFx(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),y+DFy(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),z+DFz(x,y,z,t)*Thickness(x,y,z,t)/Rapport(x,y,z,t),t))",
			"Iso4=(Iso(x-DFx(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),y-DFy(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),z-DFz(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),t))",
			"Iso5=(Iso(x+DFx(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),y+DFy(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),z+DFz(x,y,z,t)*Thickness2(x,y,z,t)/Rapport(x,y,z,t),t))",
			"ThickIso2=(Iso4(x,y,z,t)*Iso5(x,y,z,t))",
			"isoCondition=(-51$DOT$11)*(x^4+y^4+z^4)-99$DOT$92*(x^2*y^2+x^2*z^2+y^2*z^2)+141$DOT$12*(x-1)*(x^2+y^2+z^2)+256*x*(x-2)+282$DOT$24*y^2+270",
			"isoTransform_2=if(isoCondition(x/4,y/4,z/4,t)>0,ThickIso2(4*x,2*y,2*z,t),1)+0$DOT$05*exp((ThickIso2(4*x,2*y,2*z,t)+isoCondition(x/4,y/4,z/4,t))/300)",
			"isoTransform_6=isoTransform_2(x,y*cos($DOT$4944*(x))-z*sin($DOT$4944*(x)),y*sin($DOT$4944*(x))+z*cos($DOT$4944*(x)),t)"],
			"Fxyz": ["-isoTransform_6(x/2,y,z,t)"],
			"Xmax": ["18"],
			"Xmin": ["-16"],
			"Ymax": ["8"],
			"Ymin": ["-8"],
			"Zmax": ["8"],
			"Zmin": ["-8"]
		}
	}
],
"TexturesList": [{
	"Texture": {
		"Name": "Lines1",
		"Colors": ["R=cos(7*x*pi)*cos(z*pi)",
		"G=cos(7*y*pi)*cos(x*pi)",
		"B=cos(7*y*pi)*cos(z*pi)",
		"T=1"],
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
	}
},
{
	"Texture": {
		"Name": "Lines2",
		"Colors": ["R=sin(7*x*pi)",
		"G=sin(7*y*pi)",
		"B=cos(7*z*pi)",
		"T=1"],
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
	}
},
{
	"Texture": {
		"Name": "Lines3",
		"Colors": ["R=1$DOT$5*cos(x*pi)*sin(z*pi)",
		"G=1$DOT$5*sin(x*pi)*cos(y*pi)",
		"B=1$DOT$5*sin(y*pi)*cos(z*pi)",
		"T=1"],
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
	}
},
{
	"Texture": {
		"Name": "Lines4",
		"Colors": ["R=cos(7*x*y*pi)",
		"G=sin(7*y*z*pi)",
		"B=sin(7*z*x*pi)",
		"T=1"],
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			3,
			0)"
	}
},
{
	"Texture": {
		"Colors": ["R=cos(2*x*y*pi)",
		"G=sin(2*y*z*pi)",
		"B=sin(2*z*x*pi)",
		"T=1$DOT$0"],
		"Name": "Lines5",
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
	}
},
{
	"Texture": {
		"Colors": ["R=cos((x*x+y*y+z*z)*pi)",
		"G=cos((x*x+y*y+z*z)*pi)*cos(x*pi)",
		"B=sin(y*pi)*cos(x*pi)",
		"T=1"],
		"Name": "Lines6",
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
	}
},
{
	"Texture": {
		"Colors": ["R=cos((x*x+y*y+z*z)*pi)*sin(x*pi)",
		"G=cos((x*x+y*y+z*z)*pi)*sin(y*pi)",
		"B=cos((x*x+y*y+z*z)*pi)*sin(z*pi)",
		"T=1"],
		"Name": "Lines7",
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
	}
},
{
	"Texture": {
		"Colors": ["R=cos((x*x+y*y)*pi)*cos(x*pi)",
		"G=cos((y*y+z*z)*pi)*cos(y*pi)",
		"B=cos((x*x+z*z)*pi)*cos(z*pi)",
		"T=1"],
		"Name": "Lines8",
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
	}
},
{
	"Texture": {
		"Colors": ["R=(int(abs(x))+int(abs(y))+int(abs(z)))%2",
		"G=$DOT$1",
		"B=1",
		"T=1"],
		"Name": "Checker",
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
	}
},
{
	"Texture": {
		"Colors": ["R=1",
		"G=0$DOT$6*abs(cos(6*z*y*x*y*pi))",
		"B=0$DOT$5+0$DOT$3*abs(cos(6*z*z*x*y*pi))",
		"T=1"],
		"Name": "Granit_1",
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
	}
},
{
	"Texture": {
		"Colors": ["R=1",
		"G=0$DOT$9*abs(cos(pi*(x*x+y*y+z*z)))",
		"B=0$DOT$5+0$DOT$2*abs(cos(3*cos(pi*(x*x+y*y+z*z))))",
		"T=1"],
		"Name": "Granit_2",
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
	}
},
{
	"Texture": {
		"Colors": ["R=$DOT$41",
		"G=0$DOT$81*abs(cos(x*x+y*y+z*z)*sin(x*x+y*y+z*z))",
		"B=0$DOT$8601*abs(cos(x*x+y*y+z*z)*cos(x*x+y*y+z*z)*sin(x*x+y*y+z*z))",
		"T=1"],
		"Name": "Granit_3",
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
	}
},
{
	"Texture": {
		"Colors": ["R=2*$DOT$41",
		"G=2*0$DOT$81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
		"B=2*0$DOT$8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
		"T=1"],
		"Name": "WorleyNoise",
		"Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
	}
},
{
	"Texture": {
		"Colors": ["R=2*$DOT$41",
		"G=2*0$DOT$81*abs(cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
		"B=2*0$DOT$8601*abs(cos((x*x+y*y+z*z)/2)*cos((x*x+y*y+z*z)/2)*sin((x*x+y*y+z*z)/2))",
		"T=1"],
		"Name": "PerlinNoise",
		"Noise": "NoiseP(x,
			y,
			z,
			Octaves,
			Lacunarity,
			Gain)"
	}
}],

    "PigmentsList":[
    {


    "Pigment": {
		"Name": "Pigment_1",
        "Colors": [
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=$DOT$20",
                        "R=$DOT$4",
                        "G=$DOT$4",
                        "B=$DOT$70",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0$DOT$3",
                        "R=1",
                        "G=$DOT$1",
                        "B=$DOT$31",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0$DOT$6",
                        "R=$DOT$51",
                        "G=$DOT$17",
                        "B=1",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0$DOT$6",
                        "R=1",
                        "G=0$DOT$3",
                        "B=$DOT$1",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=1",
                        "R=$DOT$915",
                        "G=$DOT$17",
                        "B=$DOT$1",
                        "A=1"
                    ]
                }
            }
        ],
        "Gradient": "3*cos((x*x+y*y)*pi)*sin((y*y+z*z)*pi)",
        "Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
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
                            "V=$DOT$20",
                            "R=$DOT$90",
                            "G=$DOT$9",
                            "B=$DOT$40",
                            "A=1"
                        ]
                    }
                },
                {
                    "Color": {
                        "Name": "Red",
                        "Vrgba": [
                            "V=0$DOT$3",
                            "R=1",
                            "G=$DOT$1",
                            "B=$DOT$31",
                            "A=1"
                        ]
                    }
                },
                {
                    "Color": {
                        "Name": "Red",
                        "Vrgba": [
                            "V=0$DOT$6",
                            "R=1",
                            "G=$DOT$7",
                            "B=1",
                            "A=1"
                        ]
                    }
                },
                {
                    "Color": {
                        "Name": "Red",
                        "Vrgba": [
                            "V=0$DOT$6",
                            "R=1",
                            "G=0$DOT$3",
                            "B=$DOT$1",
                            "A=1"
                        ]
                    }
                },
                {
                    "Color": {
                        "Name": "Red",
                        "Vrgba": [
                            "V=1",
                            "R=$DOT$15",
                            "G=$DOT$6",
                            "B=$DOT$1",
                            "A=1"
                        ]
                    }
                }
            ],
            "Gradient": "3*atan((x*x*y*z)*pi)*cos(y*y*z*pi)",
            "Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
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
                            "V=0$DOT$0",
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
                            "V=0$DOT$2",
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
                            "V=0$DOT$5",
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
                            "V=0$DOT$7",
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
                            "V=1$DOT$0",
                            "R=1",
                            "G=0",
                            "B=0",
                            "A=1"
                        ]
                    }
                }
            ],
            "Gradient": "sin(x*30)+sin(y*30)",
            "Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
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
                        "V=$DOT$20",
                        "R=1$DOT$",
                        "G=$DOT$85",
                        "B=$DOT$40",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0$DOT$3",
                        "R=1",
                        "G=$DOT$1",
                        "B=$DOT$31",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0$DOT$6",
                        "R=$DOT$31",
                        "G=$DOT$31",
                        "B=1",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=0$DOT$6",
                        "R=1",
                        "G=0$DOT$3",
                        "B=$DOT$1",
                        "A=1"
                    ]
                }
            },
            {
                "Color": {
                    "Name": "Red",
                    "Vrgba": [
                        "V=1",
                        "R=$DOT$4",
                        "G=$DOT$6",
                        "B=$DOT$1",
                        "A=1"
                    ]
                }
            }
        ],
        "Gradient": "7*cos(pi*(x*x+y*y))*cos(y*z)*cos(pi*(y*y*x*x))*cos((z*z+x*x)*pi)*(cos(x)*sin(y)*cos(y)*sin(z*z+x*y)-cos(z)*sin(x))",
        "Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
    }
   } ,
   {
            "Pigment": {
                "Colors": [
                    {
                        "Color": {
                            "Name": "Red",
                            "Vrgba": [
                                "V=$DOT$40",
                                "R=1$DOT$",
                                "G=$DOT$85",
                                "B=$DOT$40",
                                "A=1"
                            ]
                        }
                    },
                    {
                        "Color": {
                            "Name": "Red",
                            "Vrgba": [
                                "V=0$DOT$5",
                                "R=1",
                                "G=$DOT$1",
                                "B=$DOT$31",
                                "A=1"
                            ]
                        }
                    },
                    {
                        "Color": {
                            "Name": "Red",
                            "Vrgba": [
                                "V=0$DOT$5",
                                "R=$DOT$31",
                                "G=$DOT$31",
                                "B=1",
                                "A=1"
                            ]
                        }
                    },
                    {
                        "Color": {
                            "Name": "Red",
                            "Vrgba": [
                                "V=0$DOT$7",
                                "R=1",
                                "G=0$DOT$3",
                                "B=$DOT$1",
                                "A=1"
                            ]
                        }
                    },
                    {
                        "Color": {
                            "Name": "Red",
                            "Vrgba": [
                                "V=1",
                                "R=$DOT$4",
                                "G=$DOT$6",
                                "B=$DOT$1",
                                "A=1"
                            ]
                        }
                    }
                ],
                "Gradient": "3*cos(x*x+y*y)*cos(y*z-y*x)*(cos(x*y*z)+sin(x*y*z))",
                "Name": "Pigment_5",
                "Noise": "NoiseW(x,
			y,
			z,
			1,
			2,
			0)"
            }
        }
]
}
