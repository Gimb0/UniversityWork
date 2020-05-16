#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int ROWS = 8, COLS = 4;

class planeSeats {
	char seats[ROWS][COLS];

public:
	void printSeats() {
		system("clear");
		cout << "  1 2 3 4\n";
		for(int i = 0; i < ROWS; ++i) {
			cout << i+1 << ' ';
			for(int j = 0; j < COLS; ++j) {
				cout << seats[i][j] << ' ';
			}
			cout << endl;
		}
	};

	bool testIfFull() {
		for(int i = 0; i < ROWS; ++i) {
			for(int j = 0; j < COLS; ++j) {
				if(seats[i][j] == '_')
					return false;
			}
		}
		return true;
	};

	void setSeat() {
		int row = 0, col = 0;
		cout << "Enter row number: ";
		cin >> row;
		while(cin.fail() || row < 1 || row > 8) {
			cout << "Enter a number between 1-8!\n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> row;
		}
		cout << "Enter column number: ";
		cin >> col;
		while(cin.fail() || col < 1 || col > 4) {
			cout << "Enter a number between 1-4!\n";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> col;
		}

		if(seats[row-1][col-1] == (char) '_') {
			seats[row-1][col-1] = 'X';
		} else {
			cout << "That seat is taken!\n";
		}
	};

	planeSeats() {
		for(int i = 0; i < ROWS; ++i) {
			for(int j = 0; j < COLS; ++j) {
				seats[i][j] = '_';
			}
		}

	};

};

bool quitProgram() {
	string quit;
	cout << "Do you wish to play again? ";
	cin >> quit;

	if(quit == "y" || quit == "Y") {
		return false;
	}

	return true;
}

int main() {

	planeSeats seats;

	seats.printSeats();

	do {

		seats.setSeat();

		seats.printSeats();

	} while(!seats.testIfFull() && !quitProgram());

	cout << "cya later m8\n";

	return 0;
}
