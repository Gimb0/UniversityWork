#include <iostream>

using namespace std;

class someClass {
	static int numOfObjects;
public:
	someClass();
};

int someClass::numOfObjects = 0;

someClass::someClass() {
	numOfObjects++;
	cout << numOfObjects;
}

int main() {
	someClass a;
	someClass b;
	someClass c;

	return 0;
}
