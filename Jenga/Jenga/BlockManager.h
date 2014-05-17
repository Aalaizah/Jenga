#pragma once
#include "System.h"

#include <list>


// CONSTS
const float BLOCK_SCALE_X = 2.0;
const float BLOCK_SCALE_Y = 0.25;
const float BLOCK_SCALE_Z = 0.5;

const float GRAVITY = -0.000002;


// STRUCTS

struct Block {
	glm::vec3 translation;
	glm::vec3 color;
	float vy; // downward velocity (?)

	Block(){ // default constructor
		translation = glm::vec3(0.0, 0.0, 0.0);
		color = glm::vec3(0.0, 0.0, 1.0);
	}

	Block(glm::vec3 tlation): translation(tlation){
		// default color red
		color.x = 1.0; 
		color.y = 0.0; 
		color.z = 0.0; 
	}// end constructor


}; // end struct Block




// CLASS



class BlockManager
{

public:
	BlockManager(void);
	~BlockManager(void);


	void render(float size, glm::vec3 color, glm::vec3 translation);
	void renderAll();

	void applyPhysGravity();

private:
	// vars
	std::list<Block>* blockList;

	// functions
	void initBlockList();




};// end class

