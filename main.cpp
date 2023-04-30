#include <iostream>
#include "Map.h"
#include "Player.h"

int main() {
    int _option = 0;

    do {
        // HACER GATITO CON EL DE CLASE HECHO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        ConsoleSetColor(BLACK, DARKMAGENTA);
        cout << "1. Play\n0. Exit\n";
        cin >> _option;
        // consoleInKey();

        switch (_option) {
        case 1:
            // Creation of variables.
            Map * _pMaze = new Map(); // Create Map object in dynamic memory.
            Player* _pCharacter = new Player(); // Create Player object in dynamic memory.
            bool endGame = false;

            // Initialitzation of the player.
            _pCharacter->setMaze(_pMaze);
            _pCharacter->init();

            // Initial painting of the map.
            _pMaze->PaintedMap(_pCharacter->getY(), _pCharacter->getX());

            do {
                // Update of values of the character (mostly the position).
                _pCharacter->update();

                // Paint of the character in the map.
                _pCharacter->render();

                // Wait 17ms (60 fps).
                ConsoleWait(17);
            } while (!endGame);

            delete _pMaze; // Delete the Map object.
            delete _pCharacter; // Delete the Player object.
            break;
        }
    } while (_option != 0);

    return 0;
}