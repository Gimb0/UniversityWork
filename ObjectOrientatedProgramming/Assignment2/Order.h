#include "Product.h"

class Order {
private:
	int orderID, PCId, quantity, dueDate, unitProfit;
	Product *pc;
	int unitPrice, orderPrice, totalCycles, daysCompletedOn[5] = {0,0,0,0,0}, productCost;
public:
	Order(int oID, int pcID, int quant, int date, int profit);
	int getUnitPrice();
	int getProductCost();
	int getOrderPrice();
	int getOrderID();
	int getQuantity();
	int getPcID();
	int getDueDate() const;
	int getProfit() const;
	int getTotalCycles() const;
	int getTotalProfit() const;
	void setDaysCompleted(int day);
	void setDaysCompleted(int day, int quantity);
	int getDaysCompleted(int i);
};
