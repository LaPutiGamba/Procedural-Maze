#pragma once
#include "Entity.h"

class Key : public Entity
{
	bool _keyStatus;

public:
	Key() :_keyStatus(false) {}
	~Key();

	void update();
	void render(int _posY, int _posX);

	/*
	Description: Get function to get the value of the variable.
	Input: Nothing.
	Return: The value of the variable.
	*/
	bool getKeyStatus() { return _keyStatus; }

	/*
	Description: Set function to set the value of the variable.
	Input: The value of the variable.
	Return: Nothing.
	*/
	void setKeyStatus(bool value) { _keyStatus = value; }
};