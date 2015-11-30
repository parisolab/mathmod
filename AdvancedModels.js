{
	"MathModels": [{
		"Iso3D": {
			"Description": ["Diamon Torus-1.0 by Abderrahman Taha 28/11/2015"],
			"Name": ["Diamon Torus"],
			"Component": ["Diamon Torus_1",
			"DiamonTorus_2"],
			"Funct": ["Iso=sin(x)*sin(y)*sin(z)+sin(x)*cos(y)*cos(z)+cos(x)*sin(y)*cos(z)+cos(x)*cos(y)*sin(z)",
			"isoCondition_0=(x^2+z^2-3.2^2)",
			"isoCondition_1=(x^2+z^2-3^2)",
			"isoTransform_1=if(isoCondition_0(x,y,z,t)<0,Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))",
			"isoTransform_2=if(isoCondition_0(x,y,z,t)<0,-Iso(x,y,z,t),1)+exp(isoCondition_1(x,y,z,t))"],
			"Fxyz": ["isoTransform_1((sqrt(x*x+y*y)-6),12*atan2(y,x),z,t)",
			"isoTransform_2((sqrt(x*x+y*y)-6),12*atan2(y,x),z,t)"],
			"Xmax": ["9.8",
			"9.8"],
			"Xmin": ["-9.8",
			"-9.8"],
			"Ymax": ["9.8",
			"9.8"],
			"Ymin": ["-9.8",
			"-9.8"],
			"Zmax": ["3.5",
			"3.5"],
			"Zmin": ["-3.5",
			"-3.5"]
		}
	},
{
"Iso3D": {
"Description": ["Octahedron of Octahedrons by Abderrahman Taha 27/11/2015"],
"Name": ["Octahedron of Octahedrons10"],
"Component": ["OctahedronOfOctahedrons"],
"Const": ["N=7"],
"Funct": ["Octahedron=(abs(x)+abs(y)+abs(z))-(1/(2*N))",
"Octahedr = ( (abs(x-.5)+abs(y-.5)+abs(z-.5))-(1/2))",
"Octahedr1 = ( (abs(x-.5)+abs(y-.5)+abs(z-.5))-(1/2-1/(N)) )"],
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
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	]
}