#pragma once
#include "System.h"

#include <list>

// STRUCTS
struct BlockAsset {
    //#TODO: Shaders?
	//#TODO: Textures?
    GLuint vbo;
    GLuint vao;
    GLenum drawType;
    GLint drawStart;
    GLint drawCount;

	// default constructor
    BlockAsset() :
        vbo(0),
        vao(0),
        drawType(GL_TRIANGLES),
        drawStart(0),
        drawCount(0)
    {}
};// end struct BlockAsset

struct Block {
    BlockAsset* asset;
    //glm::mat4 transform;

    Block() :
        asset(NULL)
        //transform()
    {}
}; // end struct Block




// CLASS

class BlockManager
{

public:
	BlockManager(void);
	~BlockManager(void);

private:
	// vars
	BlockAsset jBlockAsset;
	std::list<Block> blockInstances;
	GLfloat degreesRotated;

	// functions
	void loadBlockAsset();




};// end class

