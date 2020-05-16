/*
	Item class is used as a foundation
	for Component and Product class
*/
#ifndef ITEM_H
#define ITEM_H

class Item {
protected:
	int id;
	int cost;
public:
	/*
	Item() {
		id = -1;
		cost = 0;
	}  // the id for an empty item is -1
	Item(int i) {
		id = i;
		cost = 0;
	}

	Item(int i, int c) {
		id = i;
		cost = c;
	}
	*/
	int getId() {
		return id;
	}
	int getCost() {
		return cost;
	}
};
#endif
