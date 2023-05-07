#include <iostream>
#include "Map.h"
#include "Sword.h"
#include "Key.h"
#include "Player.h"
#include "Enemy.h"
#include "Cat.h"

int main() {
    srand((int)time(NULL));
    int _option = 0;

    do {
        ConsoleXY(0, 0);
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
            Sword* _pSword = new Sword(); // Create Sword object in dynamic memory.
            Key* _pKey = new Key(); // Create Key object in dynamic memory.
            Player* _pCharacter = new Player(); // Create Player object in dynamic memory.
            Enemy* _pMonsters = new Enemy(); // Create Enemy object in dynamic memory.
            bool endGame = false;

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

            // Initial painting of the map.
            _pMaze->PaintedMap(_pCharacter->getY(), _pCharacter->getX());
            
            do {
                // If the enemy is in the same position as the player and the player doesn't have the sword we kill him. If the player has the sword we kill the enemy.
                if ((_pMonsters->getY() == _pCharacter->getY() && _pMonsters->getX() == _pCharacter->getX()) && ) _pCharacter->setStatus(false);

                // If the player is in the same position of the sword we collect it.
                if (_pSword->getY() == _pCharacter->getY() && _pSword->getX() == _pCharacter->getX()) _pSword->setSwordStatus(true);

                // Paint of the sword in the map if we don't own it.
                if (!_pSword->getSwordStatus()) _pSword->render(_pCharacter->getY(), _pCharacter->getX());

                // If the player is in the same position of the key we collect it.
                if (_pKey->getY() == _pCharacter->getY() && _pKey->getX() == _pCharacter->getX()) _pKey->setKeyStatus(true);

                // Paint of the key in the map if we don't own it.
                if (!_pKey->getKeyStatus()) _pKey->render(_pCharacter->getY(), _pCharacter->getX());

                // Update of values (mostly the position) and render of the character.
                _pCharacter->update();
                _pCharacter->render(NULL, NULL);

                // Update of values and render of the monsters.
                if ((rand() % 10) == 5) {
                    _pMonsters->update();
                    _pMaze->PaintedMap(_pCharacter->getY(), _pCharacter->getX());
                    _pMonsters->render(_pCharacter->getY(), _pCharacter->getX());
                }

                // Wait 17ms (60 fps).
                ConsoleWait(17);
            } while (_pCharacter->getStatus());

            delete _pMaze; // Delete the Map object.
            delete _pKey; // Delete the Key object.
            delete _pCharacter; // Delete the Player object.
            delete _pMonsters; // Delete the Enemy object.
            break;
        }
    } while (_option != 48);

    return 0;
}