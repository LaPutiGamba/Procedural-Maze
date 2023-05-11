#include <iostream>
#include "Map.h"
#include "Sword.h"
#include "Key.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"

int main() {
    srand((int)time(NULL));
    // Creation of variables.
    int _option = 0;
    Map* _pMaze = nullptr;
    Player* _pCharacter = nullptr;
    Enemy* _pMonsters = nullptr;

    do {
        // CHOICE SELECTOR
        choiceSelector(_option);

        switch (_option) {
        case 49:
            _option = 0;

            // Creation of variables.
            _pMaze = new Map(); // Create Map object in dynamic memory.
            _pCharacter = new Player(); // Create Player object in dynamic memory.
            _pMonsters = new Enemy(); // Create Enemy object in dynamic memory.

            // Initialitzation of the classes.
            _pMaze->getKey()->setMaze(_pMaze);
            _pMaze->getKey()->init();
            _pMaze->getSword()->setMaze(_pMaze);
            _pMaze->getSword()->init();
            _pCharacter->setMaze(_pMaze);
            _pCharacter->init();
            _pMonsters->setMaze(_pMaze);
            _pMonsters->init();

            // Asking the name of the player.
            playerName(_pCharacter);

            // Initial painting of the map.
            _pMaze->PaintedMap(_pCharacter->getY(), _pCharacter->getX());

            do {
                // If the enemy is in the same position as the player and the player doesn't have the sword we kill him. If the player has the sword we kill the enemy.
                if ((_pMonsters->getY() == _pCharacter->getY() && _pMonsters->getX() == _pCharacter->getX()) && !_pMaze->getSword()->getStatus())
                    _pCharacter->setStatus(true);
                else if ((_pMonsters->getY() == _pCharacter->getY() && _pMonsters->getX() == _pCharacter->getX()) && _pMaze->getSword()->getStatus()) {
                    _pMonsters->setStatus(true);
                    _pMonsters->setY(100);
                    _pMonsters->setX(100);
                    _pCharacter->setPoints(100); // Adding points to the player for killing the enemy.
                }

                // If the player is in the same position of the sword we collect it.
                if (_pMaze->getSword()->getY() == _pCharacter->getY() && _pMaze->getSword()->getX() == _pCharacter->getX() && !_pMaze->getSword()->getStatus()) {
                    _pMaze->getSword()->setStatus(true);
                    _pCharacter->setPoints(50); // Adding points to the player for picking up the sword.
                }

                // Paint of the sword in the map if we don't own it.
                if (!_pMaze->getSword()->getStatus())
                    _pMaze->getSword()->render(_pCharacter->getY(), _pCharacter->getX());

                // If the player is in the same position of the key we collect it.
                if (_pMaze->getKey()->getY() == _pCharacter->getY() && _pMaze->getKey()->getX() == _pCharacter->getX() && !_pMaze->getKey()->getStatus()) {
                    _pMaze->getKey()->setStatus(true);
                    _pCharacter->setPoints(50); // Adding points to the player for picking up the key.
                }

                // Paint of the key in the map if we don't own it.
                if (!_pMaze->getKey()->getStatus())
                    _pMaze->getKey()->render(_pCharacter->getY(), _pCharacter->getX());

                // Update of values and render of the monsters.
                if ((rand() % 10) == 5 && !_pMonsters->getStatus())
                    _pMonsters->update();

                if (!_pMonsters->getStatus())
                    _pMonsters->render(_pCharacter->getY(), _pCharacter->getX());

                // Update of values (mostly the position) and render of the character.
                _pCharacter->update();
                _pCharacter->render(NULL, NULL);

                _option = ConsoleInKey();
                // Wait 17ms (60 fps).
                ConsoleWait(17);
            } while ((!_pCharacter->getStatus()) && (_option != KB_ESCAPE) && (!_pCharacter->getStatusGame()));

            _option = 0;

            if (_pCharacter->getStatusGame()) {
                paintWinnerCat();
                while (_option != KB_ESCAPE) _option = ConsoleInKey();
            }
            if (_pCharacter->getStatus()) {
                paintLoserCat();
                while (_option != KB_ESCAPE) _option = ConsoleInKey();
            }

            writePointsFile(_pCharacter); // Function to write the points of the game.

            delete _pMaze; // Delete the Map object.
            delete _pCharacter; // Delete the Player object.
            delete _pMonsters; // Delete the Enemy object.
            break;
        case 50:
            _option = 0;
            
            readPointsFile(); // Function to read and show the top 10.

            while (_option == 0) _option = ConsoleInKey();
            while (_option == KB_ESCAPE) break;
        default:
            break;
        }
    } while (_option != 48);

    return 0;
}