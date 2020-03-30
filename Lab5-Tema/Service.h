#pragma once
#include<algorithm>
#include<vector>
#include"Expense.h"
#include"Repository.h"
using namespace std;

class Service {
private:
	Repo repo;
public:
	Service();
	~Service();
	Service(const Repo&);

	int Add(int day, int money, char* type);
	int Delete(int day, int money, char* type);
	int Update(int poz, int day, int money, char* type);

	int getSize();
	Expense* getAll();

	int FindExpense(Expense e);
	void DeleteEl(Expense e);

	void DelDay(int day);
	void DelRange(int s, int f);
	void DelType(char* type);
	
	vector<Expense> ShowType(char* type);
	vector<Expense> ShowTGM(char* type, int money);
	vector<Expense> ShowTEM(char* type, int money);

	int SumByType(char* type);
	vector<int> MaxDayBySum();
	vector<pair<int, int>> SortDS();
	vector<pair<int, int>> SortDST(char* type);

	void FilterType(char* type);
	void FilterTypeLM(char* type, int sum);
	void FilterTypeEM(char* type, int sum);
};
