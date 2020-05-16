#include <iostream>

using namespace std;

int getInt() {
	int x = 0;

	cout << "What size board do you wish to play on: (3-19) ";
	cin >> x;
	while (cin.fail() || x < 3 || x > 19) {
		cout << "Please enter a number between 3 and 19.\n" ;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> x;
	}
	return x;
}

void getInt(int boardSize, int &x, int &y, string message) {
	cout << message;
	cout << "Enter column number: ";
	cin >> x;
	while(cin.fail() || x < 1 || x > boardSize) {
		cout << "Enter a number between 1 and " << boardSize << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> x;
	}
	cout << "Enter row number: ";
	cin >> y;
	while(cin.fail() || y < 1 || y > boardSize) {
		cout << "Enter a number between 1 and " << boardSize << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> y;
	}
	x--;
	y--;
	return;
}
