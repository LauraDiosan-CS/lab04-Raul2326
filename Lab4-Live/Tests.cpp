#include<iostream>
#include<cassert>
#include<string>
#include"Tests.h"
#include"Repo.h"
#include"Expense.h"
using namespace std;

void Tests() {
	char type[12] = "Electricity";
	char type_2[9] = "Internet";
	Expense e2(13, 100, type);
	assert(e2.getDay() == 13);
	assert(e2.getMoney() == 100);
	e2.setDay(14);
	assert(e2.getDay() == 14);
	e2.setMoney(200);
	assert(e2.getMoney() == 200);
	
	char type_repo[9] = "Internet";
	char type_other_repo[12] = "Electricity";

	strcpy_s(type_repo, strlen("Internet") + 1, "Internet");
	strcpy_s(type_other_repo, strlen("Electricity") + 1, "Electricity");

	Expense e_repo(15, 500, type_repo);
	Expense e_other_repo(20, 1000, type_other_repo);

	Repo repository_expenses;

	repository_expenses.addExpense(e_repo);
	repository_expenses.addExpense(e_other_repo);

	assert(repository_expenses.getAll()[0] == e_repo);
	assert(repository_expenses.getAll()[1] == e_other_repo);

}