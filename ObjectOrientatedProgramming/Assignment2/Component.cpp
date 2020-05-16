#include "Component.h"

Component::Component(int componentID) {
	id = componentID;
	cost = compCost[componentID];
	name = nameMap[componentID];
}
std::string Component::getName() {
	return name;
}
