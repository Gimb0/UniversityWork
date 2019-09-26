#include <iostream>

using namespace std;

template <class Type>
void funcExp(Type list[], int size) {
	Type x = list[0];
	Type y = list[size - 1];

	//x=start of array
	//y=end of array

	for (int j = 1; j < size; j++) {
		//loop through array

		if (x < list[j]) {
			x = list[j];

			
		}
		if (y > list[size - 1 -j]) {
			y = list[size - 1 -j];
		}

		//Loops through array from both start and end.
		//Outputs the largest and smallest value in the array.
	}
	cout << x << endl; 
	cout << y << endl;
}

int main() {

	int list[10] = {5,3,2,10,4,19,45,13,61,11};
	string strList[6] = {"One", "Hello", "Four", "Three", "How", "Six"};

	cout << "Testing int list\n";
	funcExp(list, 10);

	cout << "Testing string list\n";
	funcExp(strList, 6);

	return 0;
}

