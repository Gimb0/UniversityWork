#include <iostream>

using namespace std;

int main() {
	int counter = 0, k;
	

	cout << "Enter number of times to loop: ";
	cin >> counter;

	cout << "Enter numbers: ";
	cin >> k;

	while(counter != 0) {
		cout << rand() % k << endl;
		counter--;
	}
	return 0;
}
