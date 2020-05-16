#include "Product.h"

Product::Product(int productID) {
	cycles = cycleMap[productID];

	Component cpu(compMap[productID][0]);
	Component mb(compMap[productID][1]);
	Component ram(compMap[productID][2]);
	Component hd(compMap[productID][3]);

	unitPrice = cpu.getCost() + mb.getCost() + ram.getCost() + hd.getCost();
	cost = cycles*100 + unitPrice;

}

int Product::getCycles() {
	return cycles;
}

int Product::getUnitPrice() {
	return unitPrice;
}
