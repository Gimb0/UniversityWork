#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


class numbers {
	public:
		numbers();
		void createRandList();
		void printList();
	private:
		int randNumbers[10];
		vector<int> numberList;
};

numbers::numbers() {
	for(int i = 0; i < 10; i++) {
		numberList.push_back(i);
	}
}

void numbers::createRandList() {
	int tempNum, index;
	int test = 0;
	while(test < 10) {
		index = rand() % numberList.size();
		tempNum = numberList[index];
		randNumbers[test] = tempNum;
		numberList.erase(numberList.begin() + index);
		test++;
	}
}

void numbers::printList() {
	for(int i = 0; i < 10; i++){
		cout << randNumbers[i] << endl;
	}
}

int main() {
	srand(time(NULL));
	numbers test;
	test.createRandList();
	test.printList();
}

/* Method 1 - Randomly select number between 0 and 9, 
 * use that as index to get number from array,
 * append that to new array
 * remove it from old array
 * select new number but -1 from range
 *
 * Treat number as object
*/


/*
 *Swap values
*/ 
