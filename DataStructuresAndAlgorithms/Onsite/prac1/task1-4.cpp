#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


class method1 {
	public:
		method1();
		void createRandList();
		void printList();
		int noShiftChanges();	
	private:
		int randNumbers[10];
		vector<int> numberList;
};

method1::method1() {
	for(int i = 0; i < 10; i++) {
		numberList.push_back(i);	
	}
	return;
}

void method1::createRandList() {
	int tempNum, index;
	for(int i = 0; i < 10; i++) {
		index = rand() % numberList.size();
		tempNum = numberList[index];
		randNumbers[i] = tempNum;
		numberList.erase(numberList.begin() + index);
	}
	return;
}

void method1::printList() {
	for(int i = 0; i < 10; i++){
		cout << randNumbers[i] << " ";	
	}
	return;
}

int method1::noShiftChanges() {
	int noOfNoChanges = 0;
	for(int i = 0; i < 10; i++) {
		if(randNumbers[i] == i) {
			noOfNoChanges++;
		}
	}
	return noOfNoChanges;
}

class method2 {
	public:
		method2();
		int generateNumber();
		void storeNumber();
		int noOfShiftChanges();
		void printList();
		int randUseCount() {return randCount;}
	private:
		int randNumbers[10];
		int size = 10, index = 0;
		int randCount = 0;
};

method2::method2() {
	for(int i = 0; i < size; i++) {
		randNumbers[i] = -1;
	}
	return;
}

int method2::generateNumber() {
	int i;
	i = rand() % 10;
	randCount++;
	return i;
}

void method2::storeNumber() {
	while(index < size) {
		int num = generateNumber();
		for(int i = 0; i <= index; i++) {
			if(randNumbers[i] == num) {
				break;
			} else if(index > i && randNumbers[i] != num) {
				continue;
			} else {
				randNumbers[index] = num;
				index++;
				break;
			}
		} 
	}
	return;
}

int method2::noOfShiftChanges() {
	int num = 0;
	for(int i = 0; i < size; i++) {
		if(randNumbers[i] == i) {
			num++;
		}
	}
	return num;
}

void method2::printList() {
	for(int i = 0; i < size; i++) {
		cout << randNumbers[i] << " ";
	}
	return;
}

int main() {
	srand(time(NULL));
	int totalUnchanged = 0;
	
	cout << "Method 1\n";
	for(int i = 0; i < 20; i++) {
		method1 test1;
		test1.createRandList();
		test1.printList();
		totalUnchanged += test1.noShiftChanges();
		cout << " Unchanged: " << totalUnchanged << " rand() used 10 times." << endl;
	}
	cout << "Total unchanged: " << totalUnchanged << endl;
	totalUnchanged = 0;

	cout << "\nMethod2\n";
	for(int i = 0; i < 20; i++) {
		method2 test2;
		test2.storeNumber();
		test2.printList();
		totalUnchanged += test2.noOfShiftChanges();
		cout << " Unchanged: " << totalUnchanged << " rand() used " << test2.randUseCount() << " times." << endl;
	}
	cout << "Total unchanged: " << totalUnchanged << endl;

	return 0;
}

/* 
 * Method 1 - Randomly select number between 0 and 9, 
 * use that as index to get number from array,
 * append that to new array
 * remove it from old array
 * select new number but -1 from range
 *
 * Treat number as object
*/


/*
 * Method 2 - Generate random number between 0 and 9
 * If it is in the list of stored numbers, generate another
 * If not in list store on next position on list
*/ 
