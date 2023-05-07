#include "Entity.h"

void Entity::init()
{
	while (getMaze()->getValueMapBox(_Y, (_X / 2)) != 0) { // If the starting box isn't in a walkable box we select another until it is.
		_Y = (rand() % (MAPREALSIZEY - 2) + 1);
		_X = (rand() % ((MAPREALSIZEX * 2) - 2) + 1);

		while (_Y % 2 != 0) _Y = (rand() % (MAPREALSIZEX - 2) + 1); // If the generated number is not even we get another number until it is.
		while (_X % 2 != 0) _X = (rand() % ((MAPREALSIZEX * 2) - 2) + 1); // If the generated number is not even we get another number until it is.
	}
}

bool Entity::thereIsAWall(int _posY, int _posX)
{
	int _newPosX = 0;
	if ((_posX % 2) == .5) _newPosX = (int((_posX / 2) - 0.5)); else _newPosX = (_posX / 2); // We get the half of the PosX to make the real PosX and not the painting one.

	if (_pInfoMaze->getValueMapBox(_posY, _newPosX) == 1) return true; // If there's a wall on the position given we return that there is.
	return false;
}