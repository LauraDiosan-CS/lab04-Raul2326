#pragma once
#include "Expense.h"

class Repo {
private:
	Expense expenses[100];
	int n;
public:
	Repo();
	~Repo();
	void addExpense(Expense s);
	Expense* getAll();
};