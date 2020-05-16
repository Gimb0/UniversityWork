#include "game.h"
#include <queue>
#include <iostream>

// Game constructor creates initial board
Game::Game() {
    State *initialState = new State();
	std::cout << "\n\nCurrent state:\n";
    initialState->printBoard();
}

bool Game::complete(State *g_state) {
	initialState->State::calcManDist(g_state);
	if(initialState->getManDist(g_state) == 0)
		return true;
	else
		return false;
}
