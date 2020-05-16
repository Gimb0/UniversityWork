#include <algorithm>
#include <regex>
#include <string>
#include <iostream>
#include <iomanip>

#include "Schedule.h"

Schedule::Schedule(const string passedInputFile) {
	// Open order list
	inputFile.open(passedInputFile);

	for(string line; getline(inputFile, line); ) {
		smatch match;

		if(regex_match(line, match, regex("\\[(\\d+),([0-9]|1[0-5]),([1-9]|1[0-9]|20),([0-4]),(\\d+)\\]" ))) {
			order = new Order(stoi(match.str(1)), stoi(match.str(2)), stoi(match.str(3)), stoi(match.str(4)), stoi(match.str(5)));

			orderList.push_back(order);
		}
	}

}

// Destructor to close file stream when finished
Schedule::~Schedule() {
	inputFile.close();

	delete order;
}

bool sortOrder(const Order* lhs, const Order* rhs) {
	return (lhs->getDueDate() < rhs->getDueDate());
}

bool sortOrderProfit(const Order* lhs, const Order* rhs) {
	return (lhs->getTotalProfit() < rhs->getTotalProfit()); // Sort cheapest to most expensive
}

// Process to schedule orders for most profit
void Schedule::process() {
	writeScheduleHeader();

	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < orderList.size(); j++) {
			if(orderList[j]->getDueDate() == i) {
				orderListDay.push_back(orderList[j]);
			}
		}
		sort(orderListDay.begin(), orderListDay.end(), sortOrderProfit);

		writeSchedule();
	}

	writeDelayedAndCancelled();

	outputFile.open("Schedule.txt", std::fstream::app);

	outputFile << "\n\nTotal Profit for week: " << totalProfit << endl;

	outputFile.close();
}

void Schedule::writeScheduleHeader() {
	outputFile.open("Schedule.txt");

	outputFile << "Completed Orders:"

	outputFile << setfill(' ') << setw(8) << "orderID"
			   << setfill(' ') << setw(8) << "pcID"
			   << setfill(' ') << setw(8) << "qty"
			   << setfill(' ') << setw(8) << "dueDate"
			   << setfill(' ') << setw(8) << "profit"
			   << setfill(' ') << setw(6) << "day0"
			   << setfill(' ') << setw(6) << "day1"
			   << setfill(' ') << setw(6) << "day2"
			   << setfill(' ') << setw(6) << "day3"
			   << setfill(' ') << setw(6) << "day4"
			   << setfill(' ') << setw(10) << "TtlProfit"
			   << endl;

	outputFile.close();
}

void Schedule::writeSchedule() {
	outputFile.open("Schedule.txt", std::fstream::app);

	while(cyclesPerDay[day] >= 4 && !orderListDay.empty()) {

		int i = orderListDay.size() - 1;
		if((cyclesPerDay[day] - orderListDay[i]->getTotalCycles()) > 0) {
			orderListDay[i]->setDaysCompleted(day);

			outputFile << setfill(' ') << setw(8) << orderListDay[i]->getOrderID()
					   << setfill(' ') << setw(8) << orderListDay[i]->getPcID()
					   << setfill(' ') << setw(8) << orderListDay[i]->getQuantity()
					   << setfill(' ') << setw(8) << orderListDay[i]->getDueDate()
					   << setfill(' ') << setw(8) << orderListDay[i]->getProfit();
			for(int j = 0; j < 5; j++) {
				outputFile << setfill(' ') << setw(6) << orderListDay[i]->getDaysCompleted(j);
			}

			outputFile << setfill(' ') << setw(10) << orderListDay[i]->getTotalProfit() << endl;

			cyclesPerDay[day] -= orderListDay[i]->getTotalCycles();

			totalProfit += orderListDay[i]->getTotalProfit();

			orderListDay.pop_back();

		} else if(cyclesPerDay[day] - ( orderListDay[i]->getTotalCycles()/orderListDay[i]->getQuantity()) > 0 && day < 4) {
			int cycleAmount = orderListDay[i]->getTotalCycles()/orderListDay[i]->getQuantity();
			int quantityForDay = cyclesPerDay[day] / cycleAmount;

			orderListDay[i]->setDaysCompleted(day, quantityForDay);

			delayedList.push_back(orderListDay[i]);

			totalProfit += orderListDay[i]->getTotalProfit() - (0.1 * (orderListDay[i]->getProductCost() * orderListDay[i]->getQuantity()));
			cyclesPerDay[day] -= cycleAmount * quantityForDay;
			cyclesPerDay[day+1] -= orderListDay[i]->getTotalCycles();

			orderListDay.pop_back();
		} else {
			cancelledList.push_back(orderListDay[i]);

			// Minus 50% of product cost from profit
			totalProfit -= (0.5 * (orderListDay[i]->getProductCost() * orderListDay[i]->getQuantity()));

			orderListDay.pop_back();
		}
	}
	day++;

	outputFile.close();
}

void Schedule::writeDelayedAndCancelled() {
	outputFile.open("Schedule.txt", std::fstream::app);

	outputFile << "\n\nDelayed Orders\n";

	outputFile << setfill(' ') << setw(8) << "orderID"
			   << setfill(' ') << setw(8) << "pcID"
			   << setfill(' ') << setw(8) << "qty"
			   << setfill(' ') << setw(8) << "dueDate"
			   << setfill(' ') << setw(8) << "profit"
			   << setfill(' ') << setw(6) << "day0"
			   << setfill(' ') << setw(6) << "day1"
			   << setfill(' ') << setw(6) << "day2"
			   << setfill(' ') << setw(6) << "day3"
			   << setfill(' ') << setw(6) << "day4"
			   << setfill(' ') << setw(10) << "TtlProfit"
			   << endl;

	for(int i = 0; i < delayedList.size(); i++) {

		outputFile << setfill(' ') << setw(8) << orderListDay[i]->getOrderID()
				   << setfill(' ') << setw(8) << orderListDay[i]->getPcID()
				   << setfill(' ') << setw(8) << orderListDay[i]->getQuantity()
				   << setfill(' ') << setw(8) << orderListDay[i]->getDueDate()
				   << setfill(' ') << setw(8) << orderListDay[i]->getProfit();

		for(int j = 0; j < 5; j++) {
			outputFile << setfill(' ') << setw(6) << orderListDay[i]->getDaysCompleted(j);
		}
		outputFile << setfill(' ') << setw(10) << orderListDay[i]->getTotalProfit() << endl;

	}

	outputFile << "\n\nCancelled Orders\n";

	outputFile << setfill(' ') << setw(8) << "orderID"
			   << setfill(' ') << setw(8) << "pcID"
			   << setfill(' ') << setw(8) << "qty"
			   << setfill(' ') << setw(8) << "dueDate"
			   << setfill(' ') << setw(8) << "profit"
			   << setfill(' ') << setw(10) << "MoneyLoss"
			   << endl;

	for(int i = 0; i < cancelledList.size(); i++) {

		outputFile << setfill(' ') << setw(8) << orderListDay[i]->getOrderID()
				   << setfill(' ') << setw(8) << orderListDay[i]->getPcID()
				   << setfill(' ') << setw(8) << orderListDay[i]->getQuantity()
				   << setfill(' ') << setw(8) << orderListDay[i]->getDueDate()
				   << setfill(' ') << setw(8) << orderListDay[i]->getProfit();

		if(orderListDay[i]->getTotalProfit() > 9999) {
			outputFile << setfill(' ') << setw(5) << "-" << orderListDay[i]->getTotalProfit() << endl;
		} else 	if(orderListDay[i]->getTotalProfit() > 999) {
			outputFile << setfill(' ') << setw(6) << "-" << orderListDay[i]->getTotalProfit() << endl;
		} else {
			outputFile << setfill(' ') << setw(7) << "-" << orderListDay[i]->getTotalProfit() << endl;
		}
	}
	outputFile.close();
}
