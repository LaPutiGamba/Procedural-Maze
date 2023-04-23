#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "ConsoleControl.h"
using namespace std;

class Map
{
	struct pos {
		int PosX;
		int PosY;

		/*
		Description: Function to make a "progressive operator overload" comparing the internal parameters of the struct.
		Input: The pos variable (as a pointer).
		Return: It returns a boolean value if the comparsion is true or not.
		*/
		bool isEqual(pos *Other) { if ((PosX == Other->PosX) && (PosY == Other->PosY)) return true; else return false; }
	};

	vector<pos> _boxesTraveled;
	pos _actualPosition;
	int _mazeLogic[8][8];
	int _mazeReal[24][24];
	int _numberBoxesTraveled;
	int _direction;
	int _triedDirections;

public:
	Map();
	~Map();

	int getActualPositionX() { return _actualPosition.PosX; }
	int getActualPositionY() { return _actualPosition.PosY; }
	int getValueMapBox(int _posX, int _posY) { return _mazeReal[_posX][_posY]; }

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
};