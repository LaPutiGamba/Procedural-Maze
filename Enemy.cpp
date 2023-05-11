#include "Enemy.h"
#include "Map.h"

void Enemy::update()
{
	_direction = rand() % 4 + 1;

	switch (_direction) {
	case 1: // North direction.
		if (!thereIsAWall((_Y - 1), _X)) {
			_Y--;
		}
		break;
	case 2: // South direction.
		if (!thereIsAWall((_Y + 1), _X)) {
			_Y++;
		}
		break;
	case 3: // East direction.
		if (!thereIsAWall(_Y, (_X + 2))) {
			_X += 2;
		}
		break;
	case 4: // West direction.
		if (!thereIsAWall(_Y, (_X - 2))) {
			_X -= 2;
		}
		break;
	default:
		break;
	}
}

void Enemy::render(int _posY, int _posX)
{
	int diffY = 0, diffX = 0;
	float boxVector = 0;

	diffY = _Y - _posY;
	diffX = _X - _posX;
	boxVector = (float)sqrt(((diffY * diffY) + (diffX * diffX)));

	if (boxVector < SIGHTRADIUS) { // If we're on the player sight radius we paint the key.
		getMaze()->PaintedMap(_posY, _posX);
		ConsoleXY(_X, _Y);
		ConsoleSetColor(DARKMAGENTA, WHITE);
		cout << '\2' << '\2';
	}
}