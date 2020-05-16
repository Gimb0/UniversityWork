#include <iostream>

using namespace std;

class Account {
protected:
	string firstName, lastName;
	double curBalance;
public:
	Account(const string& fname, const string& lname, double curbalance);
	void debitTransaction(double debitamount); void creditTransaction(double creditamount); void print();
};

Account::Account(const string& fname, const string& lname, double curbalance) {
	firstName = fname; lastName = lname; curBalance = curbalance;
}

void Account::debitTransaction(double debitamount) {
	curBalance -= debitamount;
}

void Account::creditTransaction(double creditamount) {
	curBalance += creditamount;
}

void Account::print() {
	cout << "\nAccount information" << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Current Balance: " << curBalance << endl;
}


class checkingAccount : public Account {
	double miniBalance;
	void chargeFee();
	checkingAccount(const string& fname, const string& lname, double curbalance, double minibalance);
	void debitTransaction(double debitamount);
	void creditTransaction(double creditamount);
};

checkingAccount::checkingAccount(const string& fname, const string& lname, double curbalance, double minibalance) : Account (fname, lname, curbalance) {
	miniBalance = minibalance;
}

void checkingAccount::chargeFee() {
	curBalance -= 10;
}

void checkingAccount::debitTransaction(double debitamount) {
	if(debitamount < miniBalance) {
		curBalance -= debitamount;
		chargeFee();
	} else {
		curBalance -= debitamount;
	}
}

void checkingAccount::creditTransaction(double creditamount) {
	if(creditamount < miniBalance) {
		curBalance += creditamount;
		chargeFee();
	} else {
		curBalance += creditamount;
	}
}

class SavingsAccount : public Account {
	double interestRate;
	SavingsAccount(const string& fname, const string& lname, double curbalance);
	void debitTransaction(double debitamount);
	void creditTransaction(double creditamount);
};

SavingsAccount::SavingsAccount(const string& fname, const string& lname, double curbalance) : Account (fname, lname, curbalance) {
	interestRate = 0.02;
}

void SavingsAccount::debitTransaction(double debitamount) {
	Account::debitTransaction(debitamount);
	curBalance *= (1+interestRate);
}

void SavingsAccount::creditTransaction(double creditamount) {
	Account::creditTransaction(creditamount);
	curBalance *= (1+interestRate);
}

int main() {
	return 0;
}
