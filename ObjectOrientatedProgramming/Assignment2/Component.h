/*
	Component class inherits item class
	and is used for the components in the pc
*/
#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include "Item.h"

const std::string nameMap[10] = {
		"Pintel CPU 3 GHz", "Pintel CPU 5 GHz",
		"IMD CPU 3 GHz", "IMD CPU 5 GHz", "Pintel motherboard",
		"IMD motherboard", "Memory 4 GB", "Memory 8 GB", "Hard disk 1 TB",
		"Hard disk 2 TB"
	};

const int compCost[10] = {1000, 1500, 1000, 1500, 250, 250, 100, 200, 300, 400};

class Component : public Item {
	std::string name;
public:
	Component(int componentID);
	std::string getName();
};

#endif // COMPONONT_H
