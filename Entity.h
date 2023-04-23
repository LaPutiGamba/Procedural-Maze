#pragma once
#include <iostream>
#include "Map.h"
#include "ConsoleControl.h"
using namespace std;

class Entity
{
	int _X;
	int _Y;
	Map* _infoMaze;

public:
	Entity();
	~Entity();

	// Gets and sets of variables.
	int getX() { return _X; }
	int getY() { return _Y; }
	Map* getMaze() { return _infoMaze; }
	void setX(int _valor) { _X = _valor; }
	void setY(int _valor) { _Y = _valor; }
	void setMaze(Map* _valor) { _infoMaze = _valor; }

protected:
	bool thereIsAWall(int _posX, int _posY);

	// Initialization, update and render of every herency.
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};