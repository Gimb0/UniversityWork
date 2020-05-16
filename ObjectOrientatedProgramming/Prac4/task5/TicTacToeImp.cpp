

//Tic-Tac-Toe Implementation file

#include <iostream>
#include <iomanip>

#include "TicTacToe.h"

using namespace std;

void ticTacToe::play()
{
    bool done = false;
    char player = 'X';

    displayBoard();

    while (!done)
    {
        done = getXOMove(player);

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}

void ticTacToe::displayBoard() const
{
    cout << "   1    2    3    4    5" << endl << endl;

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        cout << row + 1;

        for (int col = 0; col < BOARD_SIZE; col++)
        {
            cout << setw(3) << board[row][col];

            if (col != 4)
                cout << " |";
        }

        cout << endl;

        if (row != 4)
            cout << " ____|____|____|____|____" << endl
                 << "     |    |    |    |    " << endl;
    }

    cout << endl;
}

bool ticTacToe::isValidMove(int row, int col) const
{
    if (0 <= row && row <= 2 && 0 <= col && col <= 2
        && board[row][col] == ' ')
        return true;
    else
        return false;
}

bool ticTacToe::getXOMove(char playerSymbol)
{
    int row, col;

    do
    {
        cout << "Player " << playerSymbol
             << " enter move: ";
        cin >> row >> col;
        cout << endl;
    }
    while (!isValidMove(row - 1, col - 1) );

    row--;
    col--;

    noOfMoves++;

    board[row][col] = playerSymbol;
    displayBoard();

    status gStatus = gameStatus();

    if (gStatus == WIN)
    {
        cout << "Player " << playerSymbol << " wins!" << endl;
        return true;
    }
    else if (gStatus == DRAW)
    {
        cout << "This game is a draw!" << endl;
        return true;
    }
    else if(noOfMoves >= 9) {
    	return true;
    } else
        return false;
}

status ticTacToe::gameStatus()
{
    //Write your code here to check if the game has been in a win status or a draw status
    //Check rows for a win

	//Re-write all of this.
	return CONTINUE;
}

void ticTacToe::reStart()
{
    for (int row = 0; row < BOARD_SIZE; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::ticTacToe()
{
    for (int row = 0; row < BOARD_SIZE; row++)
        for (int col = 0; col < BOARD_SIZE; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}
