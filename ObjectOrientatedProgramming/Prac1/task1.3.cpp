#include <iostream>

using namespace std;

int main() {
	int num1 = 0, num2 = 0, i;

	while( num1==0 || num2 == 0 || num1 >= num2) {
		cout << "Enter a number: ";
		cin >> num1;
		cout << "Enter a larger number: ";
		cin >> num2;
	}
	
	cout << "Printing odd numbers\n";
	for(i = num1+1; i < num2; i++) {
		if(i%2!=0){
			cout << i << "\n";
		}
	}

	int sum = 0;
	cout << "Prinitng sum of even numbers\n";
	for( i=num1+1; i<num2; i++ ) {	
		if(i%2==0) {
			sum += i;
		}
	}
	cout << sum << "\n";
	
	int k = 0;
	cout << "Printing first 10 numbers\n";
	for(i = num1+1; i < num2; i++) {
		k++;
		cout << i << "\n";
		if(k>9) {
			break;
		}
	}

	cout << "Printing square of odd numbers\n";
	for(i = num1+1; i < num2; i++) {
		if(i%2!=0) {
			cout << i*i << "\n";
		}
	}

	return 0;

}
