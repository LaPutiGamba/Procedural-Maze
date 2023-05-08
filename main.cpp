#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include "Sword.h"
#include "Key.h"
#include "Player.h"
#include "Enemy.h"
#include "Cat.h"

int main() {
    srand((int)time(NULL));
    // Creation of variables.
    int _option = 0;
    string _auxiliaryName;
    vector<string> _names;
    vector<int> _points;
    Map* _pMaze = nullptr;
    Sword* _pSword = nullptr;
    Key* _pKey = nullptr;
    Player* _pCharacter = nullptr;
    Enemy* _pMonsters = nullptr;
    string _listPointsText;
    fstream _handler;

    do {
        // CHOICE SELECTOR
        ConsoleXY(0, 0);
        paintCat();
        ConsoleXY(20, 12);
        ConsoleSetColor(DARKMAGENTA, LIGHTGREY);
        cout << "1. Play\n";
        ConsoleXY(19, 13);
        cout << "2. TOP 10\n";
        ConsoleXY(20, 14);
        cout << "0. Exit\n";
        ConsoleXY(23, 15);
        _option = 0;
        while (_option == 0) _option = ConsoleInKey();
        ConsoleClear();

        switch (_option) {
        case 49:
            _option = 0;

            // Creation of variables.
            _pMaze = new Map(); // Create Map object in dynamic memory.
            _pSword = new Sword(); // Create Sword object in dynamic memory.
            _pKey = new Key(); // Create Key object in dynamic memory.
            _pCharacter = new Player(); // Create Player object in dynamic memory.
            _pMonsters = new Enemy(); // Create Enemy object in dynamic memory.

            // Initialitzation of the classes.
            _pSword->setMaze(_pMaze);
            _pSword->init();
            _pKey->setMaze(_pMaze);
            _pKey->init();
            _pCharacter->setMaze(_pMaze);
            _pCharacter->setSword(_pSword);
            _pCharacter->setKey(_pKey);
            _pCharacter->init();
            _pMonsters->setMaze(_pMaze);
            _pMonsters->init();

            // Asking the name of the player.
            ConsoleXY(0, 0);
            paintCat();
            ConsoleXY(15, 12);
            ConsoleSetColor(DARKMAGENTA, LIGHTGREY);
            cout << "What's your name?\n";
            ConsoleXY(19, 13);
            cin >> _auxiliaryName;
            _pCharacter->setName(_auxiliaryName);
            ConsoleClear();

            // Initial painting of the map.
            _pMaze->PaintedMap(_pCharacter->getY(), _pCharacter->getX());

            do {
                // If the enemy is in the same position as the player and the player doesn't have the sword we kill him. If the player has the sword we kill the enemy.
                if ((_pMonsters->getY() == _pCharacter->getY() && _pMonsters->getX() == _pCharacter->getX()) && !_pSword->getStatus()) _pCharacter->setStatus(true);
                else if ((_pMonsters->getY() == _pCharacter->getY() && _pMonsters->getX() == _pCharacter->getX()) && _pSword->getStatus()) {
                    _pMonsters->setStatus(true);
                    _pMonsters->setY(100);
                    _pMonsters->setX(100);
                    _pCharacter->setPoints(100); // Adding points to the player for killing the enemy.
                }

                // If the player is in the same position of the sword we collect it.
                if (_pSword->getY() == _pCharacter->getY() && _pSword->getX() == _pCharacter->getX()) {
                    _pSword->setStatus(true);
                    _pCharacter->setPoints(50); // Adding points to the player for picking up the sword.
                }

                // Paint of the sword in the map if we don't own it.
                if (!_pSword->getStatus()) _pSword->render(_pCharacter->getY(), _pCharacter->getX());

                // If the player is in the same position of the key we collect it.
                if (_pKey->getY() == _pCharacter->getY() && _pKey->getX() == _pCharacter->getX()) {
                    _pKey->setStatus(true);
                    _pCharacter->setPoints(50); // Adding points to the player for picking up the key.
                }

                // Paint of the key in the map if we don't own it.
                if (!_pKey->getStatus()) _pKey->render(_pCharacter->getY(), _pCharacter->getX());

                // Update of values (mostly the position) and render of the character.
                _pCharacter->update();
                _pCharacter->render(NULL, NULL);

                // Update of values and render of the monsters.
                if ((rand() % 10) == 5 && !_pMonsters->getStatus()) {
                    _pMonsters->update();
                    _pMaze->PaintedMap(_pCharacter->getY(), _pCharacter->getX());
                    _pMonsters->render(_pCharacter->getY(), _pCharacter->getX());
                }

                // Wait 17ms (60 fps).
                ConsoleWait(17);
            } while (!_pCharacter->getStatus());

            // Adding the points to the points list file of the top 10 best punctuations.
            _handler.open("PointsList.txt", ios::app); // Opening the file in the reading mode.

            _handler << _pCharacter->getName() << "|" << _pCharacter->getPoints() << ",";

            _handler.close(); // Closing the file.

            delete _pMaze; // Delete the Map object.
            delete _pSword; // Delete the Sword object.
            delete _pKey; // Delete the Key object.
            delete _pCharacter; // Delete the Player object.
            delete _pMonsters; // Delete the Enemy object.
            break;
        case 50:
            _option = 0;
            paintListCat();

            // Reading the points of the points list file and giving the top 10 best punctuations in screen.
            _handler.open("PointsList.txt", ios::in); // Opening the file in the reading mode.

            while (!_handler.eof()) { // Until is the end of the file we read.
                _handler >> _listPointsText;

                _names.push_back(_listPointsText.substr(0, _listPointsText.find_first_of(124)));
                //_points.push_back(_listPointsText.substr(0, _listPointsText.find_first_of(44)));
            }

            _handler.close(); // Closing the file
            while (_option == 0) _option = ConsoleInKey();
            while (_option == KB_ESCAPE) break;
        default:
            break;
        }
    } while (_option != 48);

    return 0;
}