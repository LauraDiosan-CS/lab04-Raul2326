#pragma once
#include "Expense.h"

class Repo {
private:
	Expense expenses[100];
	int n;
public:
	Repo();
	~Repo();
	int FindExpense(Expense f);
	void addExpense(Expense s);
	void deleteExpense(Expense e);
	void updateExpense(int poz, Expense e1);
	int getSize();
	Expense* getAll();
};