#include <iostream>

using namespace std;

void doStuff(int parValue, int &parRef) {
	parValue = 100;
	cout << "parValue = " << parValue << endl;

	parRef = 222;
	cout << "parRef = " << parRef << endl;
}

int main() {
	int n1 = 1, n2 = 2;

	doStuff(n1, n2);

	cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;

	return 0;
}
