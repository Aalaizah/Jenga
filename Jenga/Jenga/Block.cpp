#include "Block.h"


Block::Block(void)
{
	initBlock();
}// end constructor


Block::~Block(void)
{
} // end destructor

void Block::initBlock() {

	// init vars
	vbo = 0;
	vao = 0;
	drawType = GL_POLYGON;
	drawStart = 0;
	drawCount = 6 * 2 * 3;
	// #TODO: Init texture and shaders

	// assign vertexData
	float vertexData[] = { 
		//  X     Y     Z       U     V
        // back
         0.15, -0.125, 0.5,   //0.0f, 0.0f, // BBR
         0.15, 0.125, 0.5,   //1.0f, 0.0f, // TBR
        -0.15, 0.125, 0.5,   //0.0f, 1.0f, // TBL
        -0.15, -0.125, 0.5,   //1.0f, 0.0f, // BBL

        // right
         0.15, -0.125, -0.5,   //0.0f, 0.0f, // BFR
         0.15, 0.125, -0.5,   //0.0f, 1.0f, // TFR
         0.15, 0.125, 0.5,   //1.0f, 0.0f, // TBR
         0.15, -0.125,  0.5,   //1.0f, 0.0f, // BBR

        // left
        -0.15, -0.125,  0.5,   //1.0f, 0.0f, // BBL
        -0.15, 0.125, 0.5,   //0.0f, 0.0f, // TBL
        -0.15, 0.125, -0.5,   //1.0f, 1.0f, // TFL
        -0.15, -0.125, -0.5,   //0.0f, 0.0f, // BFL

        // top
         0.15, 0.125,  0.5,   //0.0f, 0.0f, // TBR
         0.15, 0.125, -0.5,   //0.0f, 1.0f, // TFR
        -0.15, 0.125, -0.5,   //1.0f, 0.0f, // TFL
        -0.15, 0.125,  0.5,   //1.0f, 0.0f, // TBL

        // bottom
         0.15, -0.125, -0.5,   //0.0f, 1.0f, // BFR
         0.15, -0.125,  0.5,   //1.0f, 0.0f, // BBR
        -0.15, -0.125,  0.5,   //0.0f, 0.0f, // BBL
        -0.15, -0.125, -0.5,   //0.0f, 1.0f, // BFL

        // front
        -0.15, 0.125, -0.5,   //1.0f, 1.0f, // TFL
        -0.15, -0.125, -0.5,   //1.0f, 0.0f, // BFL
         0.15, -0.125, -0.5,   //0.0f, 0.0f, // BFR
         0.15, 0.125, -0.5   //1.0f, 1.0f, // TFR

	}; // end define vertexData

	// generate VBO
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertexData, GL_STATIC_DRAW);
	
	// generate VAO
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL); 



} // end initBlock
