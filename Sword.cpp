#include "Sword.h"

void Sword::update()
{
}

void Sword::render(int _posY, int _posX)
{
	int diffY = 0, diffX = 0;
	float boxVector = 0;

	diffY = _Y - _posY;
	diffX = _X - _posX;
	boxVector = (float)sqrt(((diffY * diffY) + (diffX * diffX)));

	if (!_status && boxVector < SIGHTRADIUS) { // If we don't own the key and we're on the player sight radius we paint the key.
		ConsoleXY(_X, _Y);
		ConsoleSetColor(BLACK, DARKMAGENTA);
		cout << "\4\4";
	}
}