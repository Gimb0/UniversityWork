/*
	Product class inherits item class
	and is used for the whole pc
*/
#include "Item.h"
#include "Component.h"

// List of cycle time for each PC in order
const int cycleMap[] = { 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7 };

// Components included in each PC in order
const int compMap[16][4] = {
		{ 0, 4, 6, 8 }, { 0, 4, 6, 9 }, { 0, 4, 7, 8 }, {
		0, 4, 7, 9 }, { 1, 4, 6, 8 }, { 1, 4, 6, 9 }, { 1, 4, 7, 8 }, { 1, 4, 7,
		9 }, { 2, 5, 6, 8 }, { 2, 5, 6, 9 }, { 2, 5, 7, 8 }, { 2, 5, 7, 9 }, {
		3, 5, 6, 8 }, { 3, 5, 6, 9 }, { 3, 5, 7, 8 }, { 3, 5, 7, 9 }
	};

class Product : public Item {
	int cycles, unitPrice;
public:
	Product(int productID);
	int getCycles();
	int getUnitPrice();
};
