#include "Block.h"

// #TODO: Add consts for width, height and depth

Block::Block(void)
{
	*_blockVertices = new Vec3[];
	// allocate memory for block verts
	for (int i = 0; i < BLOCKVERTS; i++){
		_blockVertices[i] = new Vec3();
	}
}

Block::Block(Vec3* verts[]){
	*_blockVertices = new Vec3[];
	for (int i = 0; i < BLOCKVERTS; i++){
		_blockVertices[i] = new Vec3(verts[i]->x, verts[i]->y, verts[i]->z);
	}// end copy array loop

}// end constructor


Block::~Block(void)
{
}


void Block::draw(){
	/*glBegin(GL_POLYGON);
	glColor3f(   1.0,  1.0, 1.0 );
	glVertex3f(  0.15, -0.125, 0.5 );
	glVertex3f(  0.15,  0.125, 0.5 );
	glVertex3f( -0.15,  0.125, 0.5 );
	glVertex3f( -0.15, -0.125, 0.5 );
	glEnd();*/

}

