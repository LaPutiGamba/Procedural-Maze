#include "Key.h"

void Key::update()
{
}

void Key::render(int _posY, int _posX)
{
	int diffY = 0, diffX = 0;
	float boxVector = 0;

	diffY = _Y - _posY;
	diffX = _X - _posX;
	boxVector = (float)sqrt(((diffY * diffY) + (diffX * diffX)));

	if (!_status && boxVector < SIGHTRADIUS) { // If we don't own the key and we're on the player sight radius we paint the key.
		ConsoleXY(_X, _Y);
		ConsoleSetColor(YELLOW, DARKYELLOW);
		cout << "\6\6";
	}
}