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

class Map
{
	struct pos {
		int PosY;
		int PosX;

		/*
		Description: Function to make a "progressive operator overload" comparing the internal parameters of the struct.
		Input: The pos variable (as a pointer).
		Return: It returns a boolean value if the comparsion is true or not.
		*/
		bool isEqual(pos *Other) { if ((PosY == Other->PosY) && (PosX == Other->PosX)) return true; else return false; }
	};

	vector<pos> _boxesTraveled;
	pos _actualPosition, _finalPosition, _keyPosition;
	int _mazeLogic[MAPSIZEY][MAPSIZEX], _mazeReal[MAPREALSIZEY][MAPREALSIZEX];
	int _numberBoxesTraveled, _direction, _triedDirections;

public:
	Map();
	~Map();

	int getActualPositionY() { return _actualPosition.PosY; }
	int getActualPositionX() { return _actualPosition.PosX; }
	int getFinalPositionY() { return _finalPosition.PosY; }
	int getFinalPositionX() { return _finalPosition.PosX; }	
	int getKeyPositionY() { return _keyPosition.PosY; }
	int getKeyPositionX() { return _keyPosition.PosX; }
	int getValueMapBox(int _posY, int _posX) { return _mazeReal[_posY][_posX]; }
	void setKeyPosition(int _posY, int _posX) { FillStruct(&_keyPosition, _posY, _posX); }

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
	Description: We create the real map (x3 than the logical map) to travel with walls.
	Input: Nothing.
	Return: Nothing, it just calculate the variable _mazeReal[][] with the necessary values.
	*/
	void RealMap();

	void PaintedMap(int playerPosY, int playerPosX);
};