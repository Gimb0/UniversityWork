#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

int riverLength, riverWidth, costOverLand, costUnderWater, bestLength;

int calcCheapestTotal() {
	int curLowestCost = INT_MAX, curHypotenuse, curCost;

	for(int i = 0; i <= riverLength; i++) {
		curHypotenuse = (int) hypot(riverWidth, riverLength-i);
		curCost = i*costOverLand + curHypotenuse*costUnderWater;
		if(curCost<curLowestCost) {
			curLowestCost = curCost;
			bestLength = i;
		}
	}

	return curLowestCost;
}

int main() {
	cout << "Enter the length of the river: ";
	cin >> riverLength;
	cout << "Enter the width of the river: ";
	cin >> riverWidth;
	cout << "Enter the cost of powerlines over land: ";
	cin >> costOverLand;
	cout << "Enter the cost of powerlines under water: ";
	cin >> costUnderWater;

	bestLength = riverLength;
	int cheapestTotal = calcCheapestTotal();

	cout << "The cheapest cost of " << cheapestTotal
		<< " is given with a length of " << bestLength << endl;

		return 0;
}
