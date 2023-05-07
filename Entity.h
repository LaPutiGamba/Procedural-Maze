#pragma once
#include <iostream>
#include "Map.h"
#include "ConsoleControl.h"
using namespace std;

class Entity
{
	Map* _pInfoMaze;

protected:
	int _X, _Y;

	/*
	Description: Function to get if there's a wall in the position that gets or no.
	Input: The PosY and PosX.
	Return: If there's a wall or no.
	*/
	bool thereIsAWall(int _posY, int _posX);

	// Update and render of every herency.
	virtual void update() = 0;
	virtual void render(int _posY, int _posX) = 0;

public:
	Entity():_X(0), _Y(0), _pInfoMaze(nullptr) {}
	~Entity();

	// Initialization.
	void init();

	/*
	Description: Get function to get the value of the variable.
	Input: Nothing.
	Return: The value of the variable.
	*/
	int getX() { return _X; }
	int getY() { return _Y; }
	Map* getMaze() { return _pInfoMaze; }

	/*
	Description: Set function to set the value of the variable.
	Input: The value of the variable.
	Return: Nothing.
	*/
	void setX(int _value) { _X = _value; }
	void setY(int _value) { _Y = _value; }
	void setMaze(Map* _value) { _pInfoMaze = _value; }
};