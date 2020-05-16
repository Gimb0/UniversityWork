#include <iostream>
#include <string>
#include <cstdlib>
#include "hexBoard.h"

int getInt();

Board::Board() {
	boardSize = getInt();
	_BOARD_SIZE_ = boardSize;
	gameBoard = new char*[boardSize];
	for(int i = 0; i < boardSize; i++) {
		gameBoard[i] = new char[boardSize];
	}
	for(int i = 0; i < boardSize; ++i) {
		for(int j = 0; j < boardSize; ++j) {
			gameBoard[i][j] = ' ';
		}
	}
}

bool Board::isBoardFull() {
	for(int i = 0; i < boardSize; i++) {
		for(int j = 0; j < boardSize; j++) {
			if(gameBoard[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

void Board::deleteBoard() {
	for(int i = 0; i < boardSize; i++) {
		delete[] gameBoard[i];
	}

	delete[] gameBoard;
	gameBoard = NULL;
	return;
}

bool Board::isSet(char playerID, int column, int row) {
	if(gameBoard[row][column] == ' ' && !(gameBoard[row][column] == 'B' || gameBoard[row][column] == 'R')) {
		gameBoard[row][column] = playerID;
		return true;
	}
	return false;
}

void Board::printBoard() {
	system("clear");
	std::cout << "\n ";
	for(int k = 0; k < boardSize; k++) {
		if(k<10){
			std::cout << "   " << k + 1;
		} else {
			std::cout << "  " << k + 1;
		}
	}
	std::cout << std::endl;
	for(int i = 0; i < boardSize; i++) {
		std::string boardIndent = std::string(i*2, ' ');
		if(i==0) {
			std::cout << i + 1 << " ";
		} else if(i == 1){
			std::cout << "  " << i+1 << " ";
		} else if(i >= 9) {
			boardIndent.pop_back();
			std::cout << boardIndent << i+1 << " " ;
		} else {
			std::cout << boardIndent << i + 1 << " ";
		}
		boardIndent = "";

		for(int j = 0; j < boardSize ; j++) {
			std::cout << "| " << gameBoard[i][j] << " ";
		}
		std::cout << "|\n";
	}
}

bool Board::followPathSide(int curTile) {
	int upToColumn = 1, numberOfTilesTaken, previousTile = curTile;

	do {
		numberOfTilesTaken = 0;
		if(gameBoard[curTile][upToColumn] == 'B') { // Check the tile next to the given tile
			numberOfTilesTaken++;

			for(int i = curTile + 1; i < boardSize; i++ ) {
				if(gameBoard[i][upToColumn] == 'B') {
					previousTile = curTile;
					curTile = i;
					numberOfTilesTaken++;
				} else {
					break;
				}
			}
		} else if(curTile > 0 && gameBoard[curTile - 1][upToColumn] == 'B') { // Check tile 1 above 1 right
			previousTile = curTile;
			curTile--;
			numberOfTilesTaken++;

			for(int i = 1; i <= curTile + 1; i++) { // Follow tiles above if they are selected.
				if(curTile > 1 && gameBoard[curTile - 1][upToColumn] == 'B') { // Check tile above 1
					previousTile = curTile;
					curTile--;
					numberOfTilesTaken++;
				} else {
					break;
				}
			}
		}
		if(curTile == -1) {
			return false;
		} else if(upToColumn == boardSize -1 && numberOfTilesTaken > 0) {
			return true;
		}

		upToColumn++;

	} while(numberOfTilesTaken > 0);

	return false;
}



bool Board::completePathSide() {
	if(tries < boardSize - 1) {
		tries++;
		return false;
	}

	for(int i = 0; i < boardSize; i++) {
		if(gameBoard[i][0] == 'B') {
			if(followPathSide(i)) {
				return true;
			}
		}
	}

	return false;

}

bool Board::completePathTopDown() {
	if(tries < boardSize) {
		return false;
	}

	for(int i = 0; i < boardSize; i++) {
		if(gameBoard[0][i] == 'R') {
			if(followPathTopDown(i)) {
				return true;
			}
		}
	}

	return false;

}

bool Board::followPathTopDown(int curTile) {
	int upToRow = 1, numberOfTilesTaken;

	do {
		numberOfTilesTaken = 0;
		if(gameBoard[upToRow][curTile] == 'R') { // Check the tile below the given
			numberOfTilesTaken++;

			for(int i = curTile + 1; i < boardSize; i++ ) {
				if(gameBoard[upToRow][i] == 'R') {
					curTile = i;
					numberOfTilesTaken++;
				} else {
					break;
				}
			}
		} else if(curTile > 0 && gameBoard[upToRow][curTile - 1] == 'R') {
			curTile--;
			numberOfTilesTaken++;
			for(int i = 1; i <= curTile + 1; i++) {
				if(curTile > 1 && gameBoard[upToRow][curTile - 1] == 'R') {
					curTile--;
					numberOfTilesTaken++;
				} else {
					break;
				}
			}
		}

		if(curTile == -1) {
			return false;
		} else if(upToRow == boardSize -1 && numberOfTilesTaken > 0) {
			return true;
		}

		upToRow++;

	} while(numberOfTilesTaken > 0);

	return false;
}
