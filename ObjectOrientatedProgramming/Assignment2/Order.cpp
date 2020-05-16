#include "Order.h"
#include <iostream>

Order::Order(int oID, int pcID, int quant, int date, int profit) {
	orderID = oID; PCId = pcID; quantity = quant; dueDate = date; unitProfit = profit;

	pc = new Product(PCId);

 	productCost = pc->getCost();
	unitPrice = productCost + unitProfit;

	orderPrice = unitPrice;
	orderPrice *= quantity;

	totalCycles = pc->getCycles() * quantity;
}

int Order::getProductCost() {
	return productCost;
}

int Order::getUnitPrice() {
	return unitPrice;
}

int Order::getPcID() {
	return PCId;
}

int Order::getOrderPrice() {
	return orderPrice;
}

int Order::getOrderID() {
	return orderID;
}

int Order::getDueDate() const {
	return dueDate;
}

int Order::getProfit() const {
	return unitProfit;
}

int Order::getTotalProfit() const {
	return (unitProfit*quantity);
}

int Order::getTotalCycles() const {
	return (pc->getCycles() * quantity);
}

int Order::getQuantity() {
	return quantity;
}

void Order::setDaysCompleted(int day) {
	for(int i = 0; i < 5; i++) {
		if(i == day) {
			daysCompletedOn[i] = quantity;
		}
	}
}

void Order::setDaysCompleted(int day, int q) {
	daysCompletedOn[day] = q;
	quantity -= q;
	daysCompletedOn[day+1] = quantity;
}

int Order::getDaysCompleted(int i) {
	return daysCompletedOn[i];
}
