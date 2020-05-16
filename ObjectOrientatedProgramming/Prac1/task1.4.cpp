#include <iostream>

using namespace std;

int main() {
	int i, k;

	for(i=1; i <= 10; i++) {
		for(k = 1; k<= 10; k++) {
			cout << i*k << "  ";
		}
		cout << endl;
	}
}
