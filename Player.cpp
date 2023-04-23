#include "Player.h"

Player::Player() 
{
	setX(0);
	setY(0);
	setMaze(nullptr);
	_direction = 0;
}

Player::~Player() 
{

}

void Player::init() 
{
	setX((rand() % 46 + 1));
	setY((rand() % 23 + 1));
	
	// If the starting box isn't in a walkable box we select another until it is.
	while (getMaze()->getValueMapBox(getX(), getY()) != 0) {
		setX((rand() % 46 + 1));
		setY((rand() % 23 + 1));

		while (getX() % 2 != 0) setX((rand() % 46 + 1)); // If the generated number is not even we get another number until it is.
		while (getY() % 2 != 0) setY((rand() % 23 + 1)); // If the generated number is not even we get another number until it is.
	}
}

void Player::update() 
{
	int tecla = ConsoleInKey();

	switch (tecla) {
	case KB_UP: case KB_UP2: case KB_UP3:
		if (!thereIsAWall(getX(), (getY() - 1))) {
			setY((getY() - 1));
			_direction = 1;
		}
		break;
	case KB_DOWN: case KB_DOWN2: case KB_DOWN3:
		if (!thereIsAWall(getX(), (getY() + 1))) {
			setY((getY() + 1));
			_direction = 2;
		}
		break;
	case KB_LEFT: case KB_LEFT2: case KB_LEFT3:
		if (!thereIsAWall((getX() - 2), getY())) {
			setX((getX() - 2));
			_direction = 8;
		}
		break;
	case KB_RIGHT: case KB_RIGHT2: case KB_RIGHT3:
		if (!thereIsAWall((getX() + 2), getY())) {
			setX((getX() + 2));
			_direction = 4;
		}
		break;
	default:
		break;
	}

	if (getX() > 46) { setX(46); }
	if (getX() < 0) { setX(0); }
	if (getY() > 23) { setY(23); }
	if (getY() < 0) { setY(0); }
}

void Player::render() 
{
	ConsoleXY(getX(), getY());
	ConsoleSetColor(BLACK, WHITE);
	cout << '\2' << '\2';

	switch (_direction) {
	case 1:
		ConsoleXY(getX(), getY() + 1);
		cout << "  ";
		break;
	case 2:
		ConsoleXY(getX(), getY() - 1);
		cout << "  ";
		break;
	case 4:
		ConsoleXY(getX() - 2, getY());
		cout << "  ";
		break;
	case 8:
		ConsoleXY(getX() + 2, getY());
		cout << "  ";
		break;
	default:
		break;
	}

	if (_direction != 0) _direction = 0;
}