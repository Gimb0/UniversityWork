#include <iostream>

using namespace std;

void funcExercise(int x, int y) {
	cout << "x=" << y << ", y=" << x << endl;
	return;
}

int main() {
	int x, y;
	cout << "Enter 2 numbers: ";
	cin >> x;
	cin >> y;

	funcExercise(x, y);
}
