#pragma once
#include "Entity.h"
#include "Key.h"

class Player : public Entity
{
	bool _sword;
	Key* _key;

public:
	Player():_sword(false), _key(nullptr) {}
	~Player();

	void update();
	void render(int _posY, int _posX);

	/*
	Description: Set function to set the value of the variable.
	Input: The value of the variable.
	Return: Nothing.
	*/
	void setKey(Key* _value) { _key = _value; }
};