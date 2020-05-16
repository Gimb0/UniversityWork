#include "hexPlayer.h"

void getInt(int _BOARD_SIZE_, int &x, int &y, std::string message);

void humanPlayer::getMove(Board *board, int _BOARD_SIZE_) {
	int x, y,i = 0;
	bool moveMade = false;
	std::string message = "Error selecting tile\n";

	do {
		if(i) {
			getInt(_BOARD_SIZE_, x, y, message);
			moveMade = board->isSet(humanPlayer::playerID, x, y);
		} else {
			getInt(_BOARD_SIZE_, x, y, "");
			moveMade = board->isSet(humanPlayer::playerID, x, y);
		}
		i++;
	} while(!moveMade);

	moveMade = false;
	i = 0;

	return;
}


void computerPlayer::getMove(Board *board, int _BOARD_SIZE_) {
	int row, col;
	srand(time(NULL));
	do {
		row = rand() % _BOARD_SIZE_;
		col = rand() % _BOARD_SIZE_;
	} while(!board->isSet(computerPlayer::playerID, row, col));

	row = 0;
	col = 0;

	return;
}
