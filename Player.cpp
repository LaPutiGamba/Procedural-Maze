#include "Player.h"

Player::Player() 
{
	setY(0);
	setX(0);
	setMaze(nullptr);
	_direction = 0;
}

Player::~Player() 
{

}

void Player::init() 
{
	// If the starting box isn't in a walkable box we select another until it is.
	while (getMaze()->getValueMapBox(getY(), getX()) != 0) {
		setY((rand() % 23 + 1));
		setX((rand() % 23 + 1));

		while (getY() % 2 != 0) setY((rand() % 23 + 1)); // If the generated number is not even we get another number until it is.
		while (getX() % 2 != 0) setX((rand() % 23 + 1)); // If the generated number is not even we get another number until it is.
	}
	setX((getX() * 2));
}

void Player::update() 
{
	int tecla = ConsoleInKey();

	switch (tecla) {
	case KB_UP: case KB_UP2: case KB_UP3:
		if (!thereIsAWall(getY(), (getX() - 1))) {
			setY((getX() - 1));
			_direction = 1;
		}
		break;
	case KB_DOWN: case KB_DOWN2: case KB_DOWN3:
		if (!thereIsAWall(getY(), (getX() + 1))) {
			setY((getX() + 1));
			_direction = 2;
		}
		break;
	case KB_LEFT: case KB_LEFT2: case KB_LEFT3:
		if (!thereIsAWall((getY() - 2), getX())) {
			setX((getY() - 2));
			_direction = 8;
		}
		break;
	case KB_RIGHT: case KB_RIGHT2: case KB_RIGHT3:
		if (!thereIsAWall((getY() + 2), getX())) {
			setX((getY() + 2));
			_direction = 4;
		}
		break;
	default:
		break;
	}

	//switch (tecla) {
	//case KB_UP: case KB_UP2: case KB_UP3:
	//	if (!thereIsAWall((getY() - 1), getX())) {
	//		setY((getY() - 1));
	//		_direction = 1;
	//	}
	//	break;
	//case KB_DOWN: case KB_DOWN2: case KB_DOWN3:
	//	if (!thereIsAWall((getY() + 1), getX())) {
	//		setY((getY() + 1));
	//		_direction = 2;
	//	}
	//	break;
	//case KB_LEFT: case KB_LEFT2: case KB_LEFT3:
	//	if (!thereIsAWall(getY(), (getX() - 2))) {
	//		setX((getX() - 2));
	//		_direction = 8;
	//	}
	//	break;
	//case KB_RIGHT: case KB_RIGHT2: case KB_RIGHT3:
	//	if (!thereIsAWall(getY(), (getX() + 2))) {
	//		setX((getX() + 2));
	//		_direction = 4;
	//	}
	//	break;
	//default:
	//	break;
	//}

	if (getY() > 23) { setY(23); }
	if (getY() < 0) { setY(0); }
	if (getX() > 46) { setX(46); }
	if (getX() < 0) { setX(0); }
}

void Player::render() 
{
	ConsoleXY(getY(), getX());
	ConsoleSetColor(BLACK, WHITE);
	cout << '\2' << '\2';

	switch (_direction) {
	case 1:
		ConsoleXY(getY(), (getX() + 1));
		cout << "  ";
		break;
	case 2:
		ConsoleXY(getY(), (getX() - 1));
		cout << "  ";
		break;
	case 4:
		ConsoleXY((getY() - 2), getX());
		cout << "  ";
		break;
	case 8:
		ConsoleXY((getY() + 2), getX());
		cout << "  ";
		break;
	default:
		break;
	}

	if (_direction != 0) _direction = 0;
}