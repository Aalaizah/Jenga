#ifndef __SYSTEM_H_
#define __SYSTEM_H_

//Basic libraries
#include <iostream>
#include <math.h>


//OpenGL
#include "GL\glew.h"
//#include "GL\freeglut.h"
//#include "GL\freeglut_ext.h"
#include <GL/glut.h>


//Application

// Misc Data Types

// VEC3 STRUCT
typedef struct Vec3 {
	float x, y, z;
	Vec3(){ x = y = z = 0;} // default constructor

	Vec3(float ax, float ay, float az){
		x = ax;
		y = ay;
		z = az;
	} // end constructor

	// #DEBUG CONSTRUCTOR
	Vec3(float debug){
		x = debug;
		y = debug;
		z = debug;
	}
	

} Vec3; // end struct def


// HEXAHEDRON VERTICES ENUM (for accessing arrays)
enum VertPos {TOP_FRONT_L, TOP_FRONT_R, TOP_BACK_R, TOP_BACK_L, BOTTOM_FRONT_L, BOTTOM_FRONT_R , BOTTOM_BACK_L, BOTTOM_BACK_R};

#endif //__SYSTEM_H_