#include<iostream>
#include"Service.h"

Service::Service() {
}

Service::~Service() {
}

Service::Service(const Repo& R) {
	repo = R;
}

//------------------------------------------------------------

int Service::Add(int day, int money, char* type) {
	if (money < 0) {
		return -1;
	}
	if (day <= 0 || day > 31) {
		return -1;
	}
	Expense e(day, money, type);
	repo.Add(e);
	return 0;
}

int Service::Delete(int day, int money, char* type) {
	Expense e(day, money, type);
	int poz = repo.FindExpense(e);
	if (poz < 0 || poz > repo.getSize()) {
		return -1;
	}
	repo.Delete(poz, e);
	return 0;
}

int Service::Update(int poz, int day, int money, char* type) {
	if (money < 0) {
		return -1;
	}
	if (day <= 0 || day > 31) {
		return -1;
	}
	Expense e1(day, money, type);
	repo.Update(poz, e1);
	return 0;
}

//------------------------------------------------------------

int Service::getSize() {
	return repo.getSize();
}

Expense* Service::getAll() {
	return repo.getAll();
}

//------------------------------------------------------------

int Service::FindExpense(Expense e) {
	return repo.FindExpense(e);
}

void Service::DeleteEl(Expense e) {
	repo.DeleteEl(e);
}

//------------------------------------------------------------

void Service::DelDay(int day) {
	Expense* expenses = getAll();
	int n = getSize();
	vector<Expense>to_del;
	for (int i = 0; i < n; i++) {
		int el_day = expenses[i].getDay();
		if (el_day == day) {
			to_del.push_back(expenses[i]);
		}
	}
	for (Expense i : to_del) {
		DeleteEl(i);
	}
}

void Service::DelRange(int s, int f) {
	Expense* expenses = getAll();
	int n = getSize();
	vector<Expense>to_del;
	while (s <= f) {
		for (int i = 0; i < n; i++) {
			int el_day = expenses[i].getDay();
			if (el_day == s) {
				to_del.push_back(expenses[i]);
			}
		}
		s++;
	}
	for (Expense i : to_del) {
		DeleteEl(i);
	}
}

void Service::DelType(char* type) {
	Expense* expenses = getAll();
	int n = getSize();
	vector<Expense>to_del;
	for (int i = 0; i < n; i++) {
		char* el_type = expenses[i].getType();
		if (strcmp(el_type, type)==0) {
			to_del.push_back(expenses[i]);
		}
	}
	for (Expense i : to_del) {
		DeleteEl(i);
	}
}

//------------------------------------------------------------

vector<Expense> Service::ShowType(char* type) {
	Expense* expenses = getAll();
	int n = getSize();
	vector<Expense>to_show;
	for (int i = 0; i < n; i++) {
		char* el_type = expenses[i].getType();
		if (strcmp(el_type, type) == 0) {
			to_show.push_back(expenses[i]);
		}
	}
	return to_show;
}

vector<Expense> Service::ShowTGM(char* type, int money) {
	Expense* expenses = getAll();
	int n = getSize();
	vector<Expense>to_show;
	for (int i = 0; i < n; i++) {
		char* el_type = expenses[i].getType();
		int el_money = expenses[i].getMoney();
		if (strcmp(el_type, type) == 0 && el_money >= money) {
			to_show.push_back(expenses[i]);
		}
	}
	return to_show;
}

vector<Expense> Service::ShowTEM(char* type, int money) {
	Expense* expenses = getAll();
	int n = getSize();
	vector<Expense>to_show;
	for (int i = 0; i < n; i++) {
		char* el_type = expenses[i].getType();
		int el_money = expenses[i].getMoney();
		if (strcmp(el_type, type) == 0 && el_money == money) {
			to_show.push_back(expenses[i]);
		}
	}
	return to_show;
}

//------------------------------------------------------------

int Service::SumByType(char* type) {
	Expense* expenses = getAll();
	int n = getSize();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		char* el_type = expenses[i].getType();
		if (strcmp(type, el_type) == 0) {
			int money = expenses[i].getMoney();
			sum += money;
		}
	}
	return sum;
}

vector<int> Service::MaxDayBySum() {
	Expense* expenses = getAll();
	int n = getSize();
	vector<int> maxday;
	vector<int> days;
	for (int i = 0; i < n; i++) {
		int day = expenses[i].getDay();
		int found = -1;
		for(int k : days) {
			if (k == day) {
				found = 0;
			}
		}
		if (found == -1) {
			days.push_back(expenses[i].getDay());
		}

	}
	vector<int> e;
	for (int dayy : days) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (expenses[i].getDay() == dayy) {
				sum += expenses[i].getMoney();
			}
		}
		e.push_back(dayy);
		e.push_back(sum);
	}
	vector<int> max;
	max.push_back(0);
	max.push_back(0);
	int e_size = e.size();
	for (int j = 1; j <= e_size; j += 2) {
		if (max[1] < e[j]) {
			max[0] = e[j - 1];
			max[1] = e[j];
		}
	}
	return max;
}

vector<pair<int, int>> Service::SortDS() {
	Expense* expenses = getAll();
	int n = getSize();
	vector<pair<int, int>> day_and_sum;
	vector<int> days;
	for (int i = 0; i < n; i++) {
		int day = expenses[i].getDay();
		int found = -1;
		for (int k : days) {
			if (k == day) {
				found = 0;
			}
		}
		if (found == -1) {
			days.push_back(expenses[i].getDay());
		}
	}
	for (int dayy : days) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (expenses[i].getDay() == dayy) {
				sum += expenses[i].getMoney();
			}
		}
		day_and_sum.push_back(make_pair(dayy, sum));
	}
	sort(day_and_sum.begin(), day_and_sum.end(), [](auto& left, auto& right) {
		return left.second > right.second;
		});
	return day_and_sum;
}

vector<pair<int, int>> Service::SortDST(char* type) {
	Expense* expenses = getAll();
	int n = getSize();
	vector<pair<int, int>> day_and_sum;
	vector<int> days;
	for (int i = 0; i < n; i++) {
		int day = expenses[i].getDay();
		char* e_type = expenses[i].getType();
		if (strcmp(e_type, type) == 0) {
			int found = -1;
			for (int k : days) {
				if (k == day) {
					found = 0;
				}
			}
			if (found == -1) {
				days.push_back(expenses[i].getDay());
			}
		}
	}
	for (int dayy : days) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (expenses[i].getDay() == dayy && strcmp(expenses[i].getType(), type)==0) {
				sum += expenses[i].getMoney();
			}
		}
		day_and_sum.push_back(make_pair(dayy, sum));
	}
	sort(day_and_sum.begin(), day_and_sum.end(), [](auto& left, auto& right) {
		return left.second < right.second;
		});
	return day_and_sum;
}

//------------------------------------------------------------

void Service::FilterType(char* type) {
	Expense* expenses = getAll();
	int n = getSize();
	vector<Expense>to_del;
	for (int i = 0; i < n; i++) {
		char* el_type = expenses[i].getType();
		if (strcmp(el_type, type) != 0) {
			to_del.push_back(expenses[i]);
		}
	}
	for (Expense i : to_del) {
		DeleteEl(i);
	}
}

void Service::FilterTypeLM(char* type, int sum) {
	Expense* expenses = getAll();
	int n = getSize();
	vector<Expense>to_del;
	for (int i = 0; i < n; i++) {
		char* el_type = expenses[i].getType();
		int el_sum = expenses[i].getMoney();
		if (strcmp(el_type, type) != 0 || el_sum >= sum) {
			to_del.push_back(expenses[i]);
		}
	}
	for (Expense i : to_del) {
		DeleteEl(i);
	}
}

void Service::FilterTypeEM(char* type, int sum) {
	Expense* expenses = getAll();
	int n = getSize();
	vector<Expense>to_del;
	for (int i = 0; i < n; i++) {
		char* el_type = expenses[i].getType();
		int el_sum = expenses[i].getMoney();
		if (strcmp(el_type, type) != 0 || el_sum != sum) {
			to_del.push_back(expenses[i]);
		}
	}
	for (Expense i : to_del) {
		DeleteEl(i);
	}
}
