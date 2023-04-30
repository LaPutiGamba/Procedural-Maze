#pragma once
#include "Entity.h"

class Player : public Entity
{
	bool _key;

public:
	Player();
	~Player();

	void init();
	void update();
	void render();
};

