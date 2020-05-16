#include <iostream>
#include <string>

using namespace std;

class Subscriber {
	string Name;
	int numChannels;
	string *channelList;

public:
	Subscriber();
	void getInput();
	void outputStuff();
	~Subscriber();
};

Subscriber::Subscriber(string Name) {
	this->Name = Name

	cout << "Enter number of channels: ";
	cin >> numChannels;

	channelList = new string[numChannels];
}

void Subscriber::getInput() {
	cout << "Enter channels you have subscribed to:\n";
	for(int i = 0; i < numChannels; i++) {
		cin >> channelList[i];
		cout << endl;
	}
}

void Subscriber::outputStuff() {
	cout << "These are the channels you have subscribed to.\n";
	for(int i = 0; i < numChannels; i++) {
		cout << channelList[i] << endl;
	}
}

Subscriber::~Subscriber() {
	delete[] channelList;
}

int main() {
	Subscriber s("Brad");

	s.getInput();
	s.outputStuff();


	return 0;
}
