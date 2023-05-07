#pragma once
#include "Entity.h"

class Sword : public Entity
{
	bool _swordStatus;

public:
	Sword():_swordStatus(false) {}
	~Sword();

	void update();
	void render(int _posY, int _posX);

	/*
	Description: Get function to get the value of the variable.
	Input: Nothing.
	Return: The value of the variable.
	*/
	bool getSwordStatus() { return _swordStatus; }

	/*
	Description: Set function to set the value of the variable.
	Input: The value of the variable.
	Return: Nothing.
	*/
	void setSwordStatus(bool value) { _swordStatus = value; }
};