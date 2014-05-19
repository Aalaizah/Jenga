#include "BlockManager.h"


BlockManager::BlockManager(void)
{
	blockList = new std::list<Block>();
	initBlockList();

} // end constructor


BlockManager::~BlockManager(void)
{
}

void BlockManager::initBlockList(){

	
	blockList->push_back(Block(glm::vec3(0.2, 0.0, 1.0))); // add block to list with specific translation
	blockList->push_back(Block());  // add block with default translation

}// end initBlockList


void BlockManager::render(float size, glm::vec3 color, glm::vec3 translation)  // can be chaged to any render method (GL_TRIANGLES, etc)
{ 
	glPushMatrix();

    glColor3f(color.x,color.y,color.z); 
	glScalef(BLOCK_SCALE_X, BLOCK_SCALE_Y, BLOCK_SCALE_Z);
	glTranslatef(translation.x, translation.y, translation.z);

	// draw cube
    glutSolidCube(size); 


	glPopMatrix();
} 


void BlockManager::renderAll(){

	applyPhysGravity();
	for (std::list<Block>::iterator b=blockList->begin(); b != blockList->end(); b++){ // iterate through list
		render(0.5, b->color, b->translation);
	}// end iteration

}// end renderall

  
void BlockManager::applyPhysGravity(){  // temporary "gravity"

	for (std::list<Block>::iterator b=blockList->begin(); b != blockList->end(); b++){ // iterate through list
		if(b->translation.y > -3.5)
		{
			b->vy += GRAVITY;
			b->translation.y += b->vy;
			//std::cout << b->translation.y << std::endl;
		}
	}// end iteration

}


// ***** HELPER FUNCTIONS *****

// returns a translation matrix
glm::mat4 translate(GLfloat x, GLfloat y, GLfloat z) {
    return glm::translate(glm::mat4(), glm::vec3(x,y,z));
}


// returns a scaling matrix
glm::mat4 scale(GLfloat x, GLfloat y, GLfloat z) {
    return glm::scale(glm::mat4(), glm::vec3(x,y,z));
}



