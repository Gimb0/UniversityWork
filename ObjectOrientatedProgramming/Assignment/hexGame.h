#pragma once
#include "hexBoard.h"
#include "hexPlayer.h"

class Game {
private:
	int _BOARD_SIZE_;
	Board *board;
	humanPlayer *player1;
	computerPlayer *player2;
public:
	void createObjects();
	void gameLoop();
	void endGame();
};
