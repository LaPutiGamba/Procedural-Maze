#pragma once
#include "Entity.h"

class Player : public Entity
{
	int _direction;

public:
	Player();
	~Player();

	void init();
	void update();
	void render();
};

