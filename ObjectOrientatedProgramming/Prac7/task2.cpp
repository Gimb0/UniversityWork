#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <regex>
#include <string>

#include "Date.h"

using namespace std;

void outputDates(Date d) {
	ofstream tempOut("dates.txt", fstream::app);

	tempOut << d << endl;
}

void generateDates() {
	srand(time(NULL));

	int day = 1, month = 1, year = 2000, numOfDates = 0;

	Date d(day, month, year);

	while(numOfDates < 100) {
		day = rand() % 31;
		month = rand() % 12;
		year = 2000 + rand() % 3;
		d.setDate(day, month, year);
		outputDates(d);
		numOfDates++;
	}


}

void sortDates() {
	ifstream sortIn("dates.txt");

	smatch m;
	for(string l; getline(sortIn, l); ){
		if(regex_match(l, m, regex("([0-9]|1[0-9]|2[0-9]|3[0-1]),\\/([0-9]|1[0-2]),\\/(200[0-2])"))) {
			cout << m.str(0) << endl;
		} else {
			cout << "no match!\n";
		}
	}

}

int main() {

	generateDates();

	sortDates();

	return 1;
}
