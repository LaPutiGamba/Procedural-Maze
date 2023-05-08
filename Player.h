#pragma once
#include "Entity.h"
#include "Sword.h"
#include "Key.h"

class Player : public Entity
{
	string _name;
	int _points;
	Sword* _sword;
	Key* _key;

public:
	Player():_points(0), _sword(nullptr), _key(nullptr) {}
	~Player() {}

	void update();
	void render(int _posY, int _posX);

	/*
	Description: Get function to get the value of the variable.
	Input: Nothing.
	Return: The value of the variable.
	*/
	string getName() { return _name; }
	int getPoints() { return _points; }

	/*
	Description: Set function to set the value of the variable.
	Input: The value of the variable.
	Return: Nothing.
	*/
	void setName(string value) { _name = value; }
	void setPoints(int value) { _points = (_points + value); }
	void setSword(Sword* _value) { _sword = _value; }
	void setKey(Key* _value) { _key = _value; }
};