#pragma once
#include "System.h"

#define BLOCKVERTS 8 // number of vertices a hexahedron has -- this obviously won't change

// class declaration
class Block
{
private:
	// defining vertices
	Vec3* _blockVertices[BLOCKVERTS];
	void drawFace();
	
public:
	Block(void);
	Block(Vec3* verts[]);
	~Block(void);
	void draw();

};

