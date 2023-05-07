#pragma once
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
	int _direction;
	int _lastDirection;

public:
	Enemy():_direction(0), _lastDirection(0) {}
	~Enemy();

	void update();
	void render(int _posY, int _posX);
};