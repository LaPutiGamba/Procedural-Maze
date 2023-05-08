#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "ConsoleControl.h"
using namespace std;

#define MAPSIZEY 8
#define MAPSIZEX 8
#define MAPREALSIZEY MAPSIZEY*3
#define MAPREALSIZEX MAPSIZEX*3
#define SIGHTRADIUS 6

class Map
{
	struct pos {
		int PosY;
		int PosX;
	};

	vector<pos> _boxesTraveled;
	pos _actualPosition, _finalPosition;
	int _mazeLogic[MAPSIZEY][MAPSIZEX], _mazeReal[MAPREALSIZEY][MAPREALSIZEX];
	int _numberBoxesTraveled, _direction, _triedDirections;

public:
	Map();
	~Map() {}

	/*
	Description: Get function to get the value of the variable.
	Input: Nothing.
	Return: The value of the variable.
	*/
	int getActualPositionY() { return _actualPosition.PosY; }
	int getActualPositionX() { return _actualPosition.PosX; }
	int getFinalPositionY() { return _finalPosition.PosY; }
	int getFinalPositionX() { return _finalPosition.PosX; }	
	int getValueMapBox(int _posY, int _posX) { return _mazeReal[_posY][_posX]; }

	/*
	Description: Function to fill int one line the variables of the struct pos.
	Input: The pos variable (as a pointer), the PosX and the PosY.
	Return: Nothing, only changes the values of the pos variable.
	*/
	void FillStruct(pos* _pointer, int _posY, int _posX);

	/*
	Description: Function to calculate the logical map of a maze.
	Input: Nothing.
	Return: Nothing, it just calculate the variable _mazeLogic[][] with the necessary values.
	*/
	void LogicalMap();

	/*
	Description: Function to create the real map (x3 than the logical map) to travel with walls.
	Input: Nothing.
	Return: Nothing, it just calculate the variable _mazeReal[][] with the necessary values.
	*/
	void RealMap();

	/*
	Description: Function to make the render of the map and make it visual.
	Input: The PosY and PosX of the player or enemies, etc.
	Return: Nothing, it just make the map visual.
	*/
	void PaintedMap(int _posY, int _posX);
};