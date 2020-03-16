#pragma once
#include <ostream>
using namespace std;

class Expense {
private:
	int day;
	int money;
	char* type;
public:
	Expense();
	Expense(int day, int money, char* type);
	Expense(const Expense& s);	
	int getDay();
	int getMoney();
	char* getType();
	void setDay(int day);
	void setMoney(int money);
	void setType(char* type);
	Expense& operator=(const Expense& s);						
	bool operator==(const Expense& s);							
	friend ostream& operator<<(ostream& os, const Expense& s);	
};
