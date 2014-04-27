#pragma once
#pragma comment( lib, "freeglut.lib" )
#pragma comment( lib, "glew32.lib" )
#pragma comment( lib, "glew32mx.lib" )
#pragma comment( lib, "glew32mxs.lib" )
#pragma comment( lib, "glew32s.lib" )
//#pragma comment( lib, "GLFW.lib" )
//#pragma comment( lib, "GLFWDLL.lib" )
#pragma comment( lib, "glut32.lib" )

class Manager
{
public:
	Manager(void);
	~Manager(void);
	int main(int argc, char** argv);
};

