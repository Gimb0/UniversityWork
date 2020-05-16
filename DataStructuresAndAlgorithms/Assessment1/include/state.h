#ifndef _STATE_H
#define _STATE_H

#include <vector>

class State {
    int **c_board; // Current board
    int b_size; // Board Size
    int manDist; // Manhattan Distance
    std::vector<int> numList;


public:
    State(int size);
    State();
    ~State();

    void printBoard() const; // Print Board
    void calcManDist(State *g_State); // modifies manDist so not const
	void coords(int value, int *i2, int *j2);
	int getManDist(State *g_state);
	// bool operator== (State &g_state);
	// Create == overload operator
};

#endif
