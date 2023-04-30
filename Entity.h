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

	bool thereIsAWall(int _posY, int _posX);

	// Initialization, update and render of every herency.
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

public:
	Entity():_X(0), _Y(0), _pInfoMaze(nullptr) {}
	~Entity();

	// Gets and sets of variables.
	int getX() { return _X; }
	int getY() { return _Y; }
	Map* getMaze() { return _pInfoMaze; }
	void setX(int _valor) { _X = _valor; }
	void setY(int _valor) { _Y = _valor; }
	void setMaze(Map* _valor) { _pInfoMaze = _valor; }
};