#pragma once
#pragma comment( lib, "freeglut.lib" )
#pragma comment( lib, "glew32.lib" )
#pragma comment( lib, "glew32mx.lib" )
#pragma comment( lib, "glew32mxs.lib" )
#pragma comment( lib, "glew32s.lib" )
//#pragma comment( lib, "GLFW.lib" )
//#pragma comment( lib, "GLFWDLL.lib" )
#pragma comment( lib, "glut32.lib" )

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
//#include <GL/glut.h>
#include <glm\glm.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "glm\gtx\transform.hpp"

#include "Camera.h"
#include "Block.h"

class Manager
{
public:
	Manager(void);
	~Manager(void);
	int main(int argc, char** argv);
};

