#include <iostream>
#include "Map.h"
#include "Key.h"
#include "Player.h"
#include "Enemy.h"
#include "Cat.h"

int main() {
    srand((int)time(NULL));
    int _option = 0;

    do {
        paintCat();
        ConsoleXY(20, 12);
        ConsoleSetColor(DARKMAGENTA, LIGHTGREY);
        cout << "1. Play\n";
        ConsoleXY(20, 13);
        cout << "0. Exit\n";
        ConsoleXY(23, 14);
        while (_option == 0) _option = ConsoleInKey();
        ConsoleClear();

        switch (_option) {
        case 49:
            // Creation of variables.
            Map* _pMaze = new Map(); // Create Map object in dynamic memory.
            Key* _pKey = new Key(); // Create Key object in dynamic memory.
            Player* _pCharacter = new Player(); // Create Player object in dynamic memory.
            Enemy* _pMonsters = new Enemy(); // Create Enemy object in dynamic memory.
            bool endGame = false;

            // Initialitzation of the classes.
            _pKey->setMaze(_pMaze);
            _pKey->init();
            _pCharacter->setMaze(_pMaze);
            _pCharacter->setKey(_pKey);
            _pCharacter->init();
            _pMonsters->setMaze(_pMaze);
            _pMonsters->init();

            // Initial painting of the map.
            _pMaze->PaintedMap(_pCharacter->getY(), _pCharacter->getX());
            
            do {
                // If the player is in the same position of the key we collect it.
                if (_pKey->getY() == _pCharacter->getY() && _pKey->getX() == _pCharacter->getX()) _pKey->setKeyStatus(true);

                // Update of values of the character (mostly the position).
                _pCharacter->update();
                
                // Update of values of the monsters.
                if ((rand() % 4) == 3) _pMonsters->update();

                // Paint of the key in the map if we don't own it.
                if (!_pKey->getKeyStatus()) _pKey->render(_pCharacter->getY(), _pCharacter->getX());

                // Paint of the character in the map.
                _pCharacter->render(NULL, NULL);

                // Paint of the monster in the map.
                _pMonsters->render(_pCharacter->getY(), _pCharacter->getX());

                // Wait 17ms (60 fps).
                ConsoleWait(17);
            } while (!endGame);

            delete _pMaze; // Delete the Map object.
            delete _pKey; // Delete the Key object.
            delete _pCharacter; // Delete the Player object.
            delete _pMonsters; // Delete the Enemy object.
            break;
        }
    } while (_option != 48);

    return 0;
}