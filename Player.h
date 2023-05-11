#pragma once
#include "Entity.h"

class Player : public Entity
{
	string _name;
	int _points;
	bool _statusGame;

public:
	Player():_points(0), _statusGame(false) {}
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
	bool getStatusGame() { return _statusGame; }

	/*
	Description: Set function to set the value of the variable.
	Input: The value of the variable.
	Return: Nothing.
	*/
	void setName(string value) { _name = value; }
	void setPoints(int value) { _points = (_points + value); }
};