/*

	Assignment 2 for OOP
	Created by Brad Gimbo

	I hold a copy of this assignment that I can produce if the original is lost or damaged.
	I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source except where due acknowledgement is made in the assignment.
	No part of this assignment has been written/produced for me by another person except where such collaboration has been authorised by the subject lecturer concerned.

*/
#include <string>
#include <iostream>

#include "Schedule.h"
#include "bundleGenerator.h"

int main(int argc, char *argv[]) {
	string file;
	if(argc == 2) {
		file = argv[1];
	} else {
		bundleGenerator bg;
		file = "orderbundle.txt";
	}

	Schedule s1(file);

	s1.process();

	std::cout << "Schedule has been made!\n";

	return 0;
}
