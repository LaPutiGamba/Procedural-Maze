#pragma once
#include "Entity.h"

class Key : public Entity
{
public:
	Key() {}
	~Key() {}

	void update();
	void render(int _posY, int _posX);
};