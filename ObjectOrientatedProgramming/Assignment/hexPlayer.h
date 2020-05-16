#pragma once
#include <iostream>
#include "hexBoard.h"

class humanPlayer {
public:
	char playerID;
	void getMove(Board *board, int _BOARD_SIZE_);
};

class computerPlayer{
public:
	char playerID;
	void getMove(Board *board, int _BOARD_SIZE_);
};
