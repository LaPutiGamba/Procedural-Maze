#include "Entity.h"

Entity::Entity()
{
	_X = 0;
	_Y = 0;
	_infoMaze = nullptr;
}

Entity::~Entity()
{
}

bool Entity::thereIsAWall(int _posY, int _posX)
{
	int _newPosX = 0;
	if ((_posX % 2) == .5) _newPosX = ((_posX / 2) - 0.5); else _newPosX = (_posX / 2);

	if (_infoMaze->getValueMapBox(_posY, _newPosX) == 1) return true;
	return false;
}