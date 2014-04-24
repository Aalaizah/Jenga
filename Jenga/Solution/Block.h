#ifndef __BLOCK_H_
#define __BLOCK_H_

#include "SystemClass.h"

class Block
{
public:
	Block(void);
	~Block(void);
	void move(glm::vec3 transformVec);
};

#endif// __BLOCK_H_