#pragma once
#include "Entity.h"
#include "Sword.h"
#include "Key.h"

class Player : public Entity
{
	bool _status;
	Sword* _sword;
	Key* _key;

public:
	Player():_status(true), _sword(nullptr), _key(nullptr) {}
	~Player();

	void update();
	void render(int _posY, int _posX);

	/*
	Description: Get function to get the value of the variable.
	Input: Nothing.
	Return: The value of the variable.
	*/
	bool getStatus() { return _status; }

	/*
	Description: Set function to set the value of the variable.
	Input: The value of the variable.
	Return: Nothing.
	*/
	void setStatus(bool value) { _status = value; }
	void setSword(Sword* _value) { _sword = _value; }
	void setKey(Key* _value) { _key = _value; }
};