#include "Player.h"

Player::~Player() 
{

}

void Player::update()
{
	int tecla = ConsoleInKey();

	// If the player is trying to go to a wall it won't change the position but if it's a walkable box it will change.
	switch (tecla) {
	case KB_UP: case KB_UP2: case KB_UP3:
		if (!thereIsAWall((_Y - 1), _X)) {
			_Y = (_Y - 1);
			getMaze()->PaintedMap(_Y, _X);
		}
		break;
	case KB_DOWN: case KB_DOWN2: case KB_DOWN3:
		if (!thereIsAWall((_Y + 1), _X)) {
			_Y = (_Y + 1);
			getMaze()->PaintedMap(_Y, _X);
		}
		break;
	case KB_LEFT: case KB_LEFT2: case KB_LEFT3:
		if (!thereIsAWall(_Y, (_X - 2))) {
			_X = (_X - 2);
			getMaze()->PaintedMap(_Y, _X);
		}
		break;
	case KB_RIGHT: case KB_RIGHT2: case KB_RIGHT3:
		if (!thereIsAWall(_Y, (_X + 2))) {
			_X = (_X + 2);
			getMaze()->PaintedMap(_Y, _X);
		}
		break;
	default:
		break;
	}
}

void Player::render(int _posY, int _posX)
{
	if (!_sword) { // Painting of the player if it doesn't own the sword.
		ConsoleXY(_X, _Y);
		ConsoleSetColor(BLACK, WHITE);
		cout << '\2' << '\2';
	} else { // Painting of the player if it does own the sword.
		ConsoleXY(_X, _Y);
		ConsoleSetColor(BLACK, WHITE);
		cout << '\2' << '\4';
	}

	if (_Y == getMaze()->getFinalPositionY() && _X == (getMaze()->getFinalPositionX() * 2)) { // If the player is in the final position we paint a text.
		ConsoleXY(52, 11);
		if (!_key->getKeyStatus()) { // If the player own the key we tell him to press E but if it haven't collected it we alert him.
			cout << "You need to pick the key!";
		}
		else {
			cout << "Press E to go down the stairs.";
		}
	} else { // If it's not we paint black the alert.
		ConsoleXY(52, 11);
		ConsoleSetColor(BLACK, BLACK);
		cout << "                              ";
	}
}