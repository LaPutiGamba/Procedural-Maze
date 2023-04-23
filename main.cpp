#include <iostream>
#include "Map.h"
#include "Player.h"

int main() {
	// Creation of variables.
	Map Maze;
	Player Character;
	bool endGame = false;

	// Initialitzation of the player.
	Character.setMaze(&Maze);
	Character.init();

	do {
		// Update of values of the character (mostly the position).
		Character.update();

		// Paint of the character in the map.
		Character.render();

		// Wait 17ms (60 fps).
		ConsoleWait(17);
	} while (!endGame);

	return 0;
}