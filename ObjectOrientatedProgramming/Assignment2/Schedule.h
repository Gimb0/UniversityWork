#include <vector>
#include <fstream>
#include "Order.h"

using namespace std;

class Schedule {
private:
	ifstream inputFile; // Declare an input file stream
	ofstream outputFile;
	Order *order;
	vector<Order*> orderList;
	vector<Order*> orderListDay;
	vector<Order*> delayedList;
	vector<Order*> cancelledList;
	int cyclesPerDay[5] = {2000,2000,2000,2000,2000}, totalProfit = 0, day = 0;
public:
	Schedule(const string passedInputFile);
	~Schedule();
	void process();
	void writeSchedule();
	void writeScheduleHeader();
	void writeDelayedAndCancelled();
};
