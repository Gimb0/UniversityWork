#include <iostream>
#include <string>

using namespace std;

void guess() {
	int randNum = rand() % 15 + 1, tries = 3, guess = 0;

	while(guess != randNum && tries > 0) {
		guess = 0;
		while(guess <= 0 || guess >= 16) {
			cout << "Guess a number between 1 and 15: ";
			cin >> guess;
		}

		if(guess == randNum) {
			cout << "You win!\n";
			return;
		}
		else {
			cout << "Wrong number!\n";
			if(guess > randNum) {
				cout << "Try something lower\n";
			} else {
				cout << "Try something higher\n";
			}
		}
		tries--;
	}
	return;
}

int main() {
	bool play = true;	
	string playInput;

	while(play) {
		guess();
		cout << "Do you wish to play again? ";
		cin >> playInput;
		if(playInput[0] == 'N' || playInput[0] == 'n') {
			play = false;
		}
	}
	return 0;
}
