#include<iostream>
#include<cassert>
#include<string>
#include"Tests.h"
#include"Repo.h"
#include"Service.h"
#include"Expense.h"
using namespace std;

void TestService() {
	char type[12] = "Electricity";
	char type_2[9] = "Internet";
	char type_3[6] = "Water";

	Service S;
	Expense e(13, 100, type);
	Expense e1(26, 500, type_2);
	Expense e3(18, 250, type_3);
	S.addExpense(e);
	S.addExpense(e1);
	S.addExpense(e3);
	S.updateExpense(1, e3);
	S.deleteExpense(e3);

	assert(S.FindExpense(e) == 0);
	assert(S.getSize() == 2);
	assert(S.getAll()[0] == e);
	assert(S.getAll()[1] == e3);
}

//---------------------------------------------------------------------------------------

void TestRepo() {
	char type[12] = "Electricity";
	char type_2[9] = "Internet";
	char type_3[6] = "Water";

	Repo R;
	Expense e(13, 100, type);
	Expense e1(26, 500, type_2);
	Expense e3(18, 250, type_3);
	R.addExpense(e);
	R.addExpense(e1);
	R.addExpense(e3);
	R.updateExpense(1, e3);
	R.deleteExpense(e3);

	assert(R.FindExpense(e) == 0);
	assert(R.getSize() == 2);
	assert(R.getAll()[0] == e);
	assert(R.getAll()[1] == e3);
}

//---------------------------------------------------------------------------------------

void TestExpense() {
	char type[12] = "Electricity";
	char type_2[9] = "Internet";
	char type_set[6] = "Water";

	Expense e(13, 100, type);
	Expense e1(26, 500, type_2);
	e1.setDay(18);
	e1.setMoney(250);
	e1.setType(type_set);

	assert(e.getDay() == 13);
	assert(e.getMoney() == 100);
	assert(strcmp(e.getType(), type) == 0);
	assert(e1.getDay() == 18);
	assert(e1.getMoney() == 250);
	assert(strcmp(e1.getType(), type_set) == 0);
}
