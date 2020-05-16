#pragma once

static int tries = 0;
static int boardSize;

class Board {

private:
	char** gameBoard;

public:
	Board();
	void deleteBoard();
	bool isBoardFull();
	bool isSet(char playerID, int column, int row);
	void printBoard();
	bool completePathSide();
	bool completePathTopDown();
	bool followPathSide(int curTile);
	bool followPathTopDown(int curTile);
	int _BOARD_SIZE_;
};
