#include "Player.h"

Player::Player() 
{
	_Y = 0;
	_X = 0;
	_key = false;
	setMaze(nullptr);
}

Player::~Player() 
{

}

void Player::init() 
{
	while (getMaze()->getValueMapBox(_Y, (_X / 2)) != 0) { // If the starting box isn't in a walkable box we select another until it is.
		_Y = (rand() % 23 + 1);
		_X = (rand() % 46 + 1);

		while (_Y % 2 != 0) _Y = (rand() % 23 + 1); // If the generated number is not even we get another number until it is.
		while (_X % 2 != 0) _X = (rand() % 46 + 1); // If the generated number is not even we get another number until it is.
	}
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

	// If the position of the player is the same of the key we collect it and we change the position of the key to make that the map doesn't paint it.
	if (_Y == getMaze()->getKeyPositionY() && _X == (getMaze()->getKeyPositionX() * 2)) {
		_key = true;
		getMaze()->setKeyPosition(80, 80);
	}

	// If the position of the player pass the map we change it back.
	if (_Y > 23) { _Y = 23; }
	if (_Y < 0) { _Y = 0; }
	if (_X > 46) { _X = 46; }
	if (_X < 0) { _X = 0; }
}

void Player::render() 
{
	// Painting of the player.
	ConsoleXY(_X, _Y);
	ConsoleSetColor(BLACK, WHITE);
	cout << '\2' << '\2';

	if (_Y == getMaze()->getFinalPositionY() && _X == (getMaze()->getFinalPositionX() * 2)) { // If the player is in the final position we paint a text.
		ConsoleXY(52, 11);
		if (!_key) { // If the player have the key we tell him to press E but if it haven't collected it we alert him.
			cout << "You need to pick the key!";
		}
		else {
			cout << "Press E to go down the stairs.";
		}
	} else { // If it's not we paint black the alert.
		ConsoleXY(52, 11);
		ConsoleSetColor(BLACK, BLACK);
		cout << "                              ";
		ConsoleXY(0, 24);
	}
}