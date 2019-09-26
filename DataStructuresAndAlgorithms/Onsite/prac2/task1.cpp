#include <iostream>

using namespace std;

int array[] = {1, 3, 8, 9, 12, 14, 22, 25, 33, 34, 38, 59, 61, 66, 68, 73, 75, 99, 101, 203, 454};

void firstMethod() {
	for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
		cout << "Index" << i << " of array contains " << array[i] << endl;
	}
	return;
}

void secondMethod(int x) {
	if(sizeof(array) == 0) {
		cout << "Array is empty!\n";
		return;
	}
	//Binary search for O(log n)
	int first = 0, last = (sizeof(array) / sizeof(array[0])) - 1;
	int mid;

	bool found = false;

	while(first <= last && !found) {
		mid = (first + last) / 2;

		if(array[mid] == x) {
			found = true;
		} else if(array[mid] > x) {
			last = mid - 1;
		} else {
			first = mid + 1;
		}
	}
	if(found) {
		cout << "Found " << x << " at index " << mid << endl;
	} else {
		cout << x << " is not in list\n";
	}
	return;
}

int main() {
	cout << "First method\n";
	firstMethod();
	cout << "\nSecond method\n";
	secondMethod(19);
}
