#ifndef __SYSTEM_H_
#define __SYSTEM_H_


#pragma comment( lib, "freeglut.lib" )
#pragma comment( lib, "glew32.lib" )
#pragma comment( lib, "glew32mx.lib" )
#pragma comment( lib, "glew32mxs.lib" )
#pragma comment( lib, "glew32s.lib" )
//#pragma comment( lib, "GLFW.lib" )
//#pragma comment( lib, "GLFWDLL.lib" )
#pragma comment( lib, "glut32.lib" )

//Basic libraries
<<<<<<< HEAD
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

// OpenGL

#include <GL/glew.h>
#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <glm/glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtx\transform.hpp>
=======
#include "World.h"

//OpenGL
//#include "GL\glew.h"
//#include "GL\freeglut.h"
//#include "GL\freeglut_ext.h"


//Application

// Misc Data Types
>>>>>>> origin/dev-camera

// HEXAHEDRON VERTICES ENUM (for accessing arrays)
// #TODO: Delete this?
enum VertPos {TOP_FRONT_L, TOP_FRONT_R, TOP_BACK_R, TOP_BACK_L, BOTTOM_FRONT_L, BOTTOM_FRONT_R , BOTTOM_BACK_L, BOTTOM_BACK_R};

#define PI 3.14159f

#endif //__SYSTEM_H_