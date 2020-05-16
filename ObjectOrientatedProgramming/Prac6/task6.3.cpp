#include <fstream>
#include <iostream>
#include <string>

class Maths {
public:
	int doMath(int a, char b, int c);
};

int Maths::doMath(int a, char b, int c) {
	if(b == 'x')
		return a*c;
	else if(b == '+')
		return a+c;
	else if(b == '-')
		return a-c;
	else if(b == '/')
		return a/c;
	else
		std::cout << "Error! Bad Operation!\n";
		return 0;
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>\n";
	}

	Maths math;

	std::string input;

	std::ofstream outputFile ("mathFileComplete.txt");

	std::ifstream inputFile (argv[1]);

	int a, c, result;
	char b, d;

	while(inputFile >> a >> b >> c >> d) {

		result = math.doMath(a, b, c);

		outputFile << a << b << c << d << result << std::endl;

	}

	return 0;

}
