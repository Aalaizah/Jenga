#pragma once
#include "System.h"

class Block
{
public:
	Block(void);
	~Block(void);

private:
	// VARS
	//------------------
	//#TODO: Shaders?
	//#TODO: Textures?
    GLuint vbo;
    GLuint vao;
    GLenum drawType;
    GLint drawStart;
    GLint drawCount;

	//  METHODS
	//-------------------
	
	void initBlock();


};

