#pragma once
#include "System.h"

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

