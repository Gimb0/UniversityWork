#include <iostream>
#include "game.h"
#include "state.h"

int main() {

    // Get board size
    int size = 0;
    std::cout << "Welcome to my puzzle game.\nPlease enter the size of board you wish to play on: ";
    std::cin >> size;
    while(size < 3 || size > 10) {
        std::cout << "Enter a size between 2 and 10\n";
        std::cin >> size;
    }

    State goalState = State(size); // Create goal state

    Game game = Game();

	while(!game.Game::complete(&goalState)) {
		std::cout << "Time to determine possible moves\n";
		/*
			Should look something like this
			Game.getMoves();
			Game.moveManDist();
			Game.moveA*();
		*/

		break;
	}


  return 0;
}
