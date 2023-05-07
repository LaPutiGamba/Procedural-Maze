#include "Map.h"

Map::Map()
{
	// Initialization of all the variables.
	FillStruct(&_actualPosition, 0, 0);
	FillStruct(&_finalPosition, 0, 0);
	_direction = 0;
	_triedDirections = 0;
	_numberBoxesTraveled = 0;

	// Initialization of the maze with "walls" (0) for futures interactions. 
	for (size_t y = 0; y < MAPSIZEY; y++)
	{
		for (size_t x = 0; x < MAPSIZEX; x++)
		{
			_mazeLogic[y][x] = 0;
		}
	}

	// Creation of the logical map.
	LogicalMap();

	// Creation of the real map.
	RealMap();
}

void Map::FillStruct(pos* _pointer, int _posY, int _posX)
{
	_pointer->PosY = _posY;
	_pointer->PosX = _posX;
}

void Map::LogicalMap()
{
	// Auxiliar variables (without _ to avoid confusing it with the parameters).
	int directions[4] = { 1, 2, 4, 8 };
	int direction;
	pos previousPosition;

	// Starting box with an open direction.
	FillStruct(&_actualPosition, rand() % MAPSIZEY, rand() % MAPSIZEX);
	_boxesTraveled.push_back(_actualPosition);

	do {
		// Random direction.
		direction = rand() % 4;
		_direction = directions[direction];

		// CHECKING DIRECTIONS //
		// If the direction leads to an unbreakable wall we stop continuing and we only add the tried direction.
		if ((_actualPosition.PosY - 1) == -1 && _direction == 1) _triedDirections |= 1;
		if ((_actualPosition.PosY + 1) == 8 && _direction == 2) _triedDirections |= 2;
		if ((_actualPosition.PosX - 1) == -1 && _direction == 8) _triedDirections |= 8;
		if ((_actualPosition.PosX + 1) == 8 && _direction == 4) _triedDirections |= 4;
		
		// If we check all the directions and none has an exit we back off.
		if (_triedDirections == 15) {
			previousPosition = _boxesTraveled.at(_boxesTraveled.size() - 2); // We save the previous position.

			if (previousPosition.PosY <= -1) previousPosition.PosY++; // We check if the PosX is a correct value.
			if (previousPosition.PosX <= -1) previousPosition.PosX++; // We check if the PosY is a correct value.
			if (previousPosition.PosY >= 8) previousPosition.PosY--; // We check if the PosX is a correct value.
			if (previousPosition.PosX >= 8) previousPosition.PosX--; // We check if the PosY is a correct value.

			FillStruct(&_actualPosition, previousPosition.PosY, previousPosition.PosX); // We back off.
			_boxesTraveled.erase(_boxesTraveled.end() - 1, _boxesTraveled.end()); // We delete the last box traveled to be able to return to the last box again if it's necessary.
			_triedDirections = 0; // Tried directions restart.
		}

		// Checking north direction. If the box isn't checked we change positions and we break a wall. If is checked, then we add the north value to the tried directions.
		if ((_actualPosition.PosY - 1) != -1 && _direction == 1) {
			if (_mazeLogic[_actualPosition.PosY - 1][_actualPosition.PosX] == 0) {
				_mazeLogic[_actualPosition.PosY][_actualPosition.PosX] |= 1; // Breaking walls.
				_mazeLogic[_actualPosition.PosY - 1][_actualPosition.PosX] |= 2; // Breaking walls.

				_actualPosition.PosY -= 1; // Changing the actual position.

				_boxesTraveled.push_back(_actualPosition); // Filling the traveled boxes with the actual position.

				_triedDirections = 0; // Tried directions restart.
			}
			else {
				_triedDirections |= 1; // Adding the nord value to the tried directions.
			}
		}

		// Checking south direction. If the box isn't checked we change positions and we break a wall. If is checked, then we add the south value to the tried directions.
		if ((_actualPosition.PosY + 1) != 8 && _direction == 2) {
			if (_mazeLogic[_actualPosition.PosY + 1][_actualPosition.PosX] == 0) {
				_mazeLogic[_actualPosition.PosY][_actualPosition.PosX] |= 2; // Breaking walls.
				_mazeLogic[_actualPosition.PosY + 1][_actualPosition.PosX] |= 1; // Breaking walls.

				_actualPosition.PosY += 1; // Changing the actual position.

				_boxesTraveled.push_back(_actualPosition); // Filling the traveled boxes with the actual position.

				_triedDirections = 0; // Tried directions restart.
			}
			else {
				_triedDirections |= 2; // Adding the south value to the tried directions.
			}
		}

		// Checking east direction. If the box isn't checked we change positions and we break a wall. If is checked, then we add the east value to the tried directions.
		if ((_actualPosition.PosX + 1) != 8 && _direction == 4) {
			if (_mazeLogic[_actualPosition.PosY][_actualPosition.PosX + 1] == 0) {
				_mazeLogic[_actualPosition.PosY][_actualPosition.PosX] |= 4; // Breaking walls.
				_mazeLogic[_actualPosition.PosY][_actualPosition.PosX + 1] |= 8; // Breaking walls.

				_actualPosition.PosX += 1; // Changing the actual position.

				_boxesTraveled.push_back(_actualPosition); // Filling the traveled boxes with the actual position.

				_triedDirections = 0; // Tried directions restart.
			}
			else {
				_triedDirections |= 4; // Adding the east value to the tried directions.
			}
		}

		// Checking west direction. If the box isn't checked we change positions and we break a wall. If is checked, then we add the west value to the tried directions.
		if ((_actualPosition.PosX - 1) != -1 && _direction == 8) {
			if (_mazeLogic[_actualPosition.PosY][_actualPosition.PosX - 1] == 0) {
				_mazeLogic[_actualPosition.PosY][_actualPosition.PosX] |= 8; // Breaking walls.
				_mazeLogic[_actualPosition.PosY][_actualPosition.PosX - 1] |= 4; // Breaking walls.

				_actualPosition.PosX -= 1; // Changing the actual position.

				_boxesTraveled.push_back(_actualPosition); // Filling the traveled boxes with the actual position.

				_triedDirections = 0; // Tried directions restart.
			}
			else {
				_triedDirections |= 8; // Adding the west value to the tried directions.
			}
		}

		_numberBoxesTraveled = 0; // Restart of _numberBoxesTraveled for check it again.

		// Checking if all the boxes we're traveled.
		for (size_t y = 0; y < MAPSIZEY; y++)
		{
			for (size_t x = 0; x < MAPSIZEX; x++)
			{
				if (_mazeLogic[y][x] != 0) _numberBoxesTraveled++; // Adding a traveled box to the number count.
			}
		}
	} while (_numberBoxesTraveled < (MAPSIZEY * MAPSIZEX));
}

void Map::RealMap()
{
	// We travel inside all the logic maze and we create the real maze with the structure. It's 3 times bigger the real maze.
	for (size_t y = 0; y < MAPSIZEY; y++)
	{
		for (size_t x = 0; x < MAPSIZEX; x++)
		{
			switch (_mazeLogic[x][y]) {
			case 0:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 1; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 1; _mazeReal[y * 3 + 1][x * 3 + 1] = 1; _mazeReal[y * 3 + 2][x * 3 + 1] = 1;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 1; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 1:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 0; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 1; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 1;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 1; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 2:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 1; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 1; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 1;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 0; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 3:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 0; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 1; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 1;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 0; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 4:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 1; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 1; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 0;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 1; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 5:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 0; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 1; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 0;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 1; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 6:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 1; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 1; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 0;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 0; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 7:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 0; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 1; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 0;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 0; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 8:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 1; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 0; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 1;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 1; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 9:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 0; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 0; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 1;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 1; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 10:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 1; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 0; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 1;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 0; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 11:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 0; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 0; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 1;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 0; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 12:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 1; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 0; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 0;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 1; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 13:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 0; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 0; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 0;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 1; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 14:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 1; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 0; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 0;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 0; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			case 15:
				_mazeReal[y * 3][x * 3] = 1; _mazeReal[y * 3 + 1][x * 3] = 0; _mazeReal[y * 3 + 2][x * 3] = 1;
				_mazeReal[y * 3][x * 3 + 1] = 0; _mazeReal[y * 3 + 1][x * 3 + 1] = 0; _mazeReal[y * 3 + 2][x * 3 + 1] = 0;
				_mazeReal[y * 3][x * 3 + 2] = 1; _mazeReal[y * 3 + 1][x * 3 + 2] = 0; _mazeReal[y * 3 + 2][x * 3 + 2] = 1;
				break;
			default:
				break;
			}
		}
	}

	do {
		_triedDirections = 0;
		_finalPosition.PosY = rand() % (MAPREALSIZEY - 2) + 1;
		_finalPosition.PosX = rand() % (MAPREALSIZEX - 2) + 1;

		if (_mazeReal[_finalPosition.PosY][_finalPosition.PosX] == 0) {
			if (_mazeReal[_finalPosition.PosY + 1][_finalPosition.PosX] == 0) _triedDirections |= 2;
			if (_mazeReal[_finalPosition.PosY - 1][_finalPosition.PosX] == 0) _triedDirections |= 1;
			if (_mazeReal[_finalPosition.PosY][_finalPosition.PosX + 1] == 0) _triedDirections |= 4;
			if (_mazeReal[_finalPosition.PosY][_finalPosition.PosX - 1] == 0) _triedDirections |= 8;
		}
	} while (_triedDirections != 1 && _triedDirections != 2 && _triedDirections != 4 && _triedDirections != 8);
}

void Map::PaintedMap(int _posY, int _posX)
{
	_posX = _posX / 2;
	int diffY = 0, diffX = 0;
	float boxVector = 0;

	ConsoleClear();
	ConsoleXY(0, 0);

	// We paint the real maze.
	for (int y = 0; y < MAPREALSIZEY; y++)
	{
		for (int x = 0; x < MAPREALSIZEX; x++)
		{
			diffY = y - _posY;
			diffX = x - _posX;
			boxVector = (float)sqrt(((diffY * diffY) + (diffX * diffX)));

			if (boxVector < SIGHTRADIUS) {
				if (y == _finalPosition.PosY && x == _finalPosition.PosX) { // If it's the final box we painted it dark red.
					ConsoleSetColor(DARKRED, DARKRED);
					cout << "  ";
				} else if (_mazeReal[y][x] == 0) { // If it's a walkable box we painted white.
					ConsoleSetColor(WHITE, WHITE);
					cout << "  ";
					} else if (_mazeReal[y][x] == 1) { // If it's a wall we painted red. 
						ConsoleSetColor(RED, RED);
						cout << "  ";
					}
			} else { 
				ConsoleSetColor(BLACK, BLACK);
				cout << "  ";
			}
		}
		cout << endl;
	}

	ConsoleSetColor(WHITE, BLACK);
}