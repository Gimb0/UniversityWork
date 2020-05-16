#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>

#include "state.h"

static int boardSize;

// Create goal board
State::State(int size) {
    boardSize = size;
    State::b_size = boardSize;
    std::srand(std::time(NULL));

    // Declare board
    c_board = new int *[State::b_size];
    for(int i = 0; i < State::b_size; i++) {
        c_board[i] = new int[State::b_size];
    }
    // Define board
    int a = 1;
    for(int i = 0; i < State::b_size; i++) {
        for(int j = 0; j < State::b_size; j++) {
            c_board[j][i] = a;
            a++;
        }
    }
    c_board[State::b_size - 1][State::b_size - 1] = 0;
}

// Create initial board
State::State() {
    // Declare board
    State::b_size = boardSize;
    c_board = new int *[State::b_size];
    for(int i = 0; i < State::b_size; i++) {
        c_board[i] = new int[State::b_size];
    }
    // Create list of numbers
    for(int i = 0; i < State::b_size*State::b_size; i++) {
        numList.push_back(i);
    }
    // Define board by randomly selecting numbers from list
    int temp, index;
    for(int i = 0; i < State::b_size; i++) {
        for(int j = 0; j < State::b_size; j++) {
            index = rand() % numList.size();
            temp = numList[index];
            c_board[i][j] = temp;
            numList.erase(numList.begin() + index);
        }
    }
}

State::~State() {
    for(int i = 0; i < State::b_size; i++) {
        delete[] c_board[i];
    }
    delete[] c_board;
    c_board = NULL;
}

void State::printBoard() const {
    for(int i = 0; i < State::b_size; i++) {
        for(int j = 0; j < State::b_size; j++) {
            if(c_board[j][i] == 0) {
                continue;
            }
            std::cout << " " << c_board[j][i];
        }
        std::cout << "\n\n";
    }
    return;
}

void State::calcManDist(State *g_State) {
	std::cout << "Checking every element of current board\nBoard Size is " << State::b_size << std::endl;
	// std::cout << "Test access of c_board: " << c_board[1][1] << std::endl;
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
			int value = 3;
			int *i2, *j2;
			std::cout << "Checking coords\n";
			g_State->coords(value, i2, j2);
			return;
			// std::cout << "Value: " << State::c_board[i][j] << " x: " << i2 << " y: " << j2 << std::endl;
			// State::manDist += abs(i - *i2) + abs(j - *j2);
        }
    }
}

void State::coords(int value, int *i2, int *j2) {
	std::cout << "Finding coords of " << value << " in goal board\n";
	for(int k = 0; k < State::b_size; k++) {
		for(int l = 0; l < State::b_size; l++) {
			std::cout << "Comparing values now\n";
			if(value == State::c_board[k][l]) {
				*i2 = k;
				*j2 = l;
				return;
			}
		}
	}
}

int State::getManDist(State *g_state) {
	return State::manDist;
}
