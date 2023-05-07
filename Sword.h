#pragma once
#include "Entity.h"

class Sword : public Entity
{
public:
	Sword() {}
	~Sword() {}

	void update();
	void render(int _posY, int _posX);
};