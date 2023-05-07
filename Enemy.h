#pragma once
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
	int _direction;

public:
	Enemy():_direction(0) {}
	~Enemy() {}

	void update();
	void render(int _posY, int _posX);
};