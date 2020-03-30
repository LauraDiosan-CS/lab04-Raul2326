#pragma once
#include "Expense.h"

class Repo {
private:
	Expense expenses[100];
	int n;
public:
	Repo();
	~Repo();
	void Add(Expense s);
	void Delete(int poz, Expense e);
	void DeleteEl(Expense e);
	void Update(int poz, Expense e1);

	int getSize();
	Expense* getAll();

	int FindExpense(Expense f);
};