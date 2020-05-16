#ifndef _GAME_H
#define _GAME_H

#include <vector>
#include "state.h"

class Game {
    State *initialState;
	State *bestCurrentState;
	std::vector<State> possibleMoves;


public:
    Game();
	bool complete(State *g_state);
};

#endif
