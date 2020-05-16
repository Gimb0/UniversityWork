#include <iostream>

using namespace std;

void oddNumbers(int num1, int num2) {
    cout << "Printing odd numbers\n";
	for(int i = num1+1; i < num2; i++) {
		if(i%2!=0){
			cout << i << "\n";
		}
	}
}

void sumOfEven(int num1, int num2) {
    int sum = 0;
	cout << "Prinitng sum of even numbers\n";
	for(int i=num1+1; i<num2; i++ ) {
		if(i%2==0) {
			sum += i;
		}
	}
	cout << sum << "\n";
}

void first10Numbers(int num1, int num2) {
    int k = 0;
	cout << "Printing first 10 numbers\n";
	for(int i = num1+1; i < num2; i++) {
		k++;
		cout << i << "\n";
		if(k>9) {
			break;
		}
	}
}

void squareOfOdds(int num1, int num2) {
    cout << "Printing square of odd numbers\n";
	for(int i = num1+1; i < num2; i++) {
		if(i%2!=0) {
			cout << i*i << "\n";
		}
	}
}

int main() {
	int num1 = 0, num2 = 0, i;

	while( num1==0 || num2 == 0 || num1 >= num2) {
		cout << "Enter a number: ";
		cin >> num1;
		cout << "Enter a larger number: ";
		cin >> num2;
	}

	oddNumbers(num1, num2);

	sumOfEven(num1, num2);

	first10Numbers(num1, num2);

    squareOfOdds(num1, num2);

	return 0;
}
