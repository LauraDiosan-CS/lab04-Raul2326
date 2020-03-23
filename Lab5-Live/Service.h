#pragma once
#include"Expense.h"
#include"Repo.h"
using namespace std;

class Service {
private:
	Repo repo;
public:
	Service();
	~Service();
	Service(const Repo&);
	int getSize();
	Expense* getAll();
	int FindExpense(Expense e);
	void addExpense(Expense e);
	void deleteExpense(Expense e);
	void updateExpense(int poz, Expense e);
};