#include<iostream>
#include<cassert>
#include<string>
#include"Tests.h"
using namespace std;

void TestServiceCRUD() {
	char type[12] = "Electricity";
	char type_2[9] = "Internet";
	char type_3[6] = "Water";

	Service S;
	Expense e(13, 100, type);
	Expense e1(26, 500, type_2);
	Expense e3(18, 250, type_3);
	S.Add(13, 100, type);
	S.Add(26, 500, type_2);
	S.Add(18, 250, type_3);
	S.Update(1, 18, 250, type_3);
	S.Delete(18, 250, type_3);

	assert(S.FindExpense(e) == 0);
	assert(S.getSize() == 2);
	assert(S.getAll()[0] == e);
	assert(S.getAll()[1] == e3);
}

void TestServiceDel() {
	char type_1[12] = "Electricity";
	char type_2[9] = "Internet";
	char type_3[6] = "Water";

	Service S;
	Expense e1(13, 100, type_1);
	Expense e2(26, 500, type_2);
	Expense e3(5, 50, type_3);
	S.Add(13, 100, type_1);
	S.Add(26, 500, type_2);
	S.Add(5, 50, type_3);
	S.DelDay(13);
	S.DelRange(20, 28);
	S.DelType(type_3);

	assert(S.getSize() == 0);
}

void TestServiceShow() {
	char type_1[12] = "Electricity";
	char type_2[9] = "Internet";
	char type_3[6] = "Water";

	Service S;
	Expense e1(13, 100, type_1);
	Expense e2(26, 500, type_2);
	Expense e3(5, 50, type_3);
	S.Add(13, 100, type_1);
	S.Add(26, 500, type_2);
	S.Add(5, 50, type_3);

	assert(S.ShowType(type_1)[0] == e1);
	assert(S.ShowTGM(type_2, 100)[0] == e2);
	assert(S.ShowTEM(type_3, 50)[0] == e3);
}

void TestServiceSort() {
	char type_1[12] = "Electricity";
	char type_2[9] = "Internet";
	char type_3[6] = "Water";

	Service S;
	Expense e1(13, 100, type_1);
	Expense e2(26, 500, type_2);
	Expense e3(5, 50, type_3);
	S.Add(13, 100, type_1);
	S.Add(26, 500, type_2);
	S.Add(5, 50, type_3);

	assert(S.SumByType(type_1) == 100);
	assert(S.MaxDayBySum()[0] == 26);
	assert(S.MaxDayBySum()[1] == 500);
}

void TestServiceFilter() {
	char type_1[12] = "Electricity";
	char type_2[9] = "Internet";
	char type_3[6] = "Water";

	Service S;
	Expense e1(13, 100, type_1);
	Expense e2(26, 500, type_1);
	Expense e3(5, 50, type_1);
	S.Add(13, 100, type_1);
	S.Add(26, 500, type_1);
	S.Add(5, 50, type_1);
	S.FilterTypeLM(type_1, 400);
	S.FilterTypeEM(type_1, 100);

	assert(S.getSize() == 1);
}

//---------------------------------------------------------------------------------------

void TestRepository() {
	char type[12] = "Electricity";
	char type_2[9] = "Internet";
	char type_3[6] = "Water";

	Repo R;
	Expense e(13, 100, type);
	Expense e1(26, 500, type_2);
	Expense e3(18, 250, type_3);
	R.Add(e);
	R.Add(e1);
	R.Add(e3);
	R.Update(1, e3);
	R.Delete(2, e3);

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
