#pragma once
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "bundleGenerator.h"
#include "Product.h"

bundleGenerator::bundleGenerator() {
	srand(time(NULL));

	outF.open("orderbundle.txt");

	count = 150 + rand() % 101;

	int temp;

	for(int i = 0; i < count; i++) {
		int pcID = rand() % 16;

		Product p(pcID);

		outF << "[" << i << ","
			 << pcID << ","
			 << rand() % 21 << ","
			 << rand() % 5 << ","
			 << int (p.getUnitPrice() * ((rand() % 51 + 25) * 0.01)) << "]\n";
	}
}
