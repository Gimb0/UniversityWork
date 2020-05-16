#include <iostream>

using namespace std;

int main() {
	char name[16];
	int age;

	cout << "What is your name: ";
	cin >> name;
	cout << "How old are you: ";
	cin >> age;

	cout << "Hello " << name << " you are " << age << " years old\n";

	return 0;
}
