/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source. No part of the code has been written/produced for me by another person or copied from any other source.
I hold a copy of this assignment that I can produce if the original is lost or damaged.
**************************/

#include "hexGame.h"

using namespace std;

// Function Declarations
int getInt();


void Game::createObjects() {
	board = new Board;
	player1 = new humanPlayer;
	player1->playerID = 'B';
	player2 = new computerPlayer;
	player2->playerID = 'R';
}

void Game::gameLoop() {

	bool curPlayer = true;
	bool completePath = false;
	bool gameStatus;

	board->printBoard();

	do {


		if(curPlayer) {
			player1->getMove(board, board->_BOARD_SIZE_);
			board->printBoard();
			completePath = board->completePathSide();
			curPlayer = false;
		} else {
			player2->getMove(board, board->_BOARD_SIZE_);
			board->printBoard();
			completePath = board->completePathTopDown();
			curPlayer = true;
		}

		if(board->isBoardFull()) {
			gameStatus = true;
			break;
		}


	} while (!completePath);


	if(completePath) {
		if(curPlayer ) {
			cout << "*** Congratulations Player 2 ***\n\t!!! You Win !!!\n";
		} else {
			cout << "*** Congratulations Player 1 ***\n\t!!! You Win !!!\n";
		}
	} else {
		std::cout << "Someone won but I am not capable of knowing. :(\nSo let's call it a draw\n";
	}
	return;
}

void Game::endGame() {
	board->deleteBoard();
	delete board;
	delete player1;
	delete player2;
}

int main() {

	Game playGame;

	playGame.createObjects();

	playGame.gameLoop();

	playGame.endGame();

	return 0;
}
