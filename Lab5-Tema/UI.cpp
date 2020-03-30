#include <iostream>
#include "UI.h"
using namespace std;

UI::UI() {
}

UI::~UI() {
}

void UI::Menu() {
	cout << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "     |   MENU   |" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << endl;
	cout << "  0.  Exit" << endl;
	cout << "  1.  Add expense" << endl;
	cout << "  2.  Delete expense" << endl;
	cout << "  3.  Update expense" << endl;
	cout << endl;
	//--------------------------------------------------------------------------------------------------------
	cout << "  4.  Delete day" << endl;
	cout << "  5.  Delete range day" << endl;
	cout << "  6.  Delete type" << endl;
	cout << endl;
	//--------------------------------------------------------------------------------------------------------
	cout << "  7.  Show all" << endl;
	cout << "  8.  Show type" << endl;
	cout << "  9.  Show type greater money" << endl;
	cout << "  10. Show type exact money" << endl;
	cout << endl;
	//--------------------------------------------------------------------------------------------------------
	cout << "  11. Sum by type" << endl;
	cout << "  12. Max day by sum" << endl;
	cout << "  13. Sorted days decreasing by sum" << endl;
	cout << "  14. Sorted days by sum for type" << endl;
	cout << endl;
	//--------------------------------------------------------------------------------------------------------
	cout << "  15. Filter type" << endl;
	cout << "  16. Filter type lower money" << endl;
	cout << "  17. Filter type exact money" << endl;
	cout << endl;
	//--------------------------------------------------------------------------------------------------------
	cout << "  18. Get creative! Give a command in a single line!" << endl;
	cout << "  29. Undo" << endl;
}

//------------------------------------------------------------------------------------------------------------

void UI::Add() {
	int day;
	int money;
	char type[1000];
	cout << endl;
	cout << "Insert the day: ";
	cin >> day;
	cout << "Insert the spent sum: ";
	cin >> money;
	cout << "Insert the type of expense: ";
	cin >> type;
	int r = S.Add(day, money, type);
	if (r == 0) {
		cout << endl;
		cout << "        Expense added!   " << endl;
	}
	if (r == -1) {
		cout << endl;
		cout << "        Invalid data!   " << endl;
	}
}

void UI::Delete()
{
	ShowAll();
	int del_day;
	int del_money;
	char del_type[100];
	cout << endl;
	cout << "Insert the day of the expense you want to delete: ";
	cin >> del_day;
	cout << "Insert the money of the expense you want to delete: ";
	cin >> del_money;
	cout << "Insert the type of the expense you want to delete: ";
	cin >> del_type;
	int r = S.Delete(del_day, del_money, del_type);
	if (r == 0) {
		cout << endl;
		cout << "        Expense deleted!" << endl;
	}
	if (r == -1) {
		cout << endl;
		cout << "        Invalid data!" << endl;
	}
}

void UI::Update()
{
	ShowAll();
	int upd_day;
	int upd_money;
	char upd_type[100];
	cout << endl;
	cout << "Insert the day of the expense you want to update: ";
	cin >> upd_day;
	cout << "Insert the money of the expense you want to update: ";
	cin >> upd_money;
	cout << "Insert the type of the expense you want to update: ";
	cin >> upd_type;
	Expense e(upd_day, upd_money, upd_type);
	int poz = S.FindExpense(e);
	if (poz < 0 || poz > S.getSize()) {
		cout << endl;
		cout << "        Invalid data!" << endl;
	}
	else {
		int new_day;
		int new_money;
		char new_type[100];
		cout << endl;
		cout << "Insert the new day of the expense: ";
		cin >> new_day;
		cout << "Insert the new money of the expense: ";
		cin >> new_money;
		cout << "Insert the new type of the expense: ";
		cin >> new_type;
		int r = S.Update(poz, new_day, new_money, new_type);
		if (r == -1) {
			cout << endl;
			cout << "        Invalid data!" << endl;
		}
		if (r == 0) {
			cout << endl;
			cout << "        Expense updated!" << endl;
		}
	}
}

//------------------------------------------------------------------------------------------------------------

void UI::DelDay() {
	cout << endl;
	cout << "	    |   DELDAY   |" << endl;
	cout << endl;
	int day;
	cout << endl;
	cout << "  Insert the day to delete: ";
	cin >> day;
	S.DelDay(day);
	cout << endl;
	cout << "        Expenses deleted!" << endl;
}

void UI::DelRange() {
	int s, f;
	cout << endl;
	cout << "		  |   DEL-RANGE   |" << endl;
	cout << endl;
	cout << "  Insert start day: ";
	cin >> s;
	cout << "  Insert last day: ";
	cin >> f;
	S.DelRange(s, f);
	cout << endl;
	cout << "        Expenses deleted!" << endl;
}

void UI::DelType() {
	cout << endl;
	cout << "	    |   DEL-TYPE   |" << endl;
	cout << endl;
	char type[100];
	cout << endl;
	cout << "  Insert the type to delete: ";
	cin >> type;
	S.DelType(type);
	cout << endl;
	cout << "        Expenses deleted!" << endl;
}

//------------------------------------------------------------------------------------------------------------

void UI::ShowAll()
{
	cout << endl;
	cout << "	     |   EXPENSES   |" << endl;
	cout << endl;
	if (S.getSize() == 0) {
		cout << " There are no expenses added! " << endl;
		cout << "             You should add some : 3 " << endl;
	}
	else {
		for (int i = 0; i < S.getSize(); i++)
		{
			cout << "    " << S.getAll()[i] << endl;
		}
	}
}

void UI::ShowType() {
	cout << endl;
	cout << "	    |   EXPENSES TYPE   |" << endl;
	cout << endl;
	char type[100];
	cout << endl;
	cout << "  Insert the type: ";
	cin >> type;
	cout << endl;
	vector<Expense>found = S.ShowType(type);
	for (Expense i : found) {
		cout << i << endl;
	}
}

void UI::ShowTGM() {
	cout << endl;
	cout << "	    |   EXPENSES TYPE SORTED   |" << endl;
	cout << endl;
	char type[100];
	int money;
	cout << endl;
	cout << "  Insert the type: ";
	cin >> type;
	cout << "  Insert the money: ";
	cin >> money;
	cout << endl;
	vector<Expense>found = S.ShowTGM(type, money);
	for (Expense i : found) {
		cout << i << endl;
	}
}

void UI::ShowTEM() {
	cout << endl;
	cout << "	    |   EXPENSES TYPE SORTED   |" << endl;
	cout << endl;
	char type[100];
	int money;
	cout << endl;
	cout << "  Insert the type: ";
	cin >> type;
	cout << "  Insert the money: ";
	cin >> money;
	cout << endl;
	vector<Expense>found = S.ShowTEM(type, money);
	for (Expense i : found) {
		cout << i << endl;
	}
}

//------------------------------------------------------------------------------------------------------------

void UI::SumByType() {
	cout << endl;
	cout << "	    |   TYPE-SUM   |" << endl;
	cout << endl;
	char type[100];
	cout << endl;
	cout << "  Insert the type: ";
	cin >> type;
	cout << endl;
	int sum = S.SumByType(type);
	cout << "  The sum is: " << sum << endl;
}

void UI::MaxDayBySum() {
	cout << endl;
	cout << "	    |   MAX-DAY-SUM   |" << endl;
	cout << endl;
	int day = S.MaxDayBySum()[0];
	int sum = S.MaxDayBySum()[1];
	cout << "  The day with the greatest expenses is: " << day << " and the family spent: " << sum << " $!" << endl;
}

void UI::SortDS() {
	cout << endl;
	cout << "	    |   SORTED DAYS   |" << endl;
	cout << endl;
	vector<pair<int, int>> sorted = S.SortDS();
	for (int i = 0; i < sorted.size(); i++) {
		cout << "  Day: " << sorted[i].first << " | Sum: " << sorted[i].second << endl;
	}
}

void UI::SortDST() {
	cout << endl;
	cout << "	    |   SORTED-DAYS-TYPE   |" << endl;
	cout << endl;
	char type[100];
	cout << "  Insert the type: ";
	cin >> type;
	cout << endl;
	vector<pair<int, int>> sorted = S.SortDST(type);
	for (int i = 0; i < sorted.size(); i++) {
		cout << "  Day: " << sorted[i].first << " | Sum: " << sorted[i].second << endl;
	}
}

//------------------------------------------------------------------------------------------------------------

void UI::FilterType() {
	cout << endl;
	cout << "	    |   FILTER TYPE   |" << endl;
	cout << endl;
	char type[100];
	cout << "  Insert the type: ";
	cin >> type;
	S.FilterType(type);
	cout << endl;
	cout << "        Expenses filtered!" << endl;
}

void UI::FilterTypeLM() {
	cout << endl;
	cout << "	    |   FILTER TYPE AND MAX SUM   |" << endl;
	cout << endl;
	int sum;
	char type[100];
	cout << "  Insert the type: ";
	cin >> type;
	cout << "  Insert the max sum: ";
	cin >> sum;
	S.FilterTypeLM(type, sum);
	cout << endl;
	cout << "        Expenses filtered!" << endl;
}

void UI::FilterTypeEM() {
	cout << endl;
	cout << "	    |   FILTER TYPE AND SUM   |" << endl;
	cout << endl;
	int sum;
	char type[100];
	cout << "  Insert the type: ";
	cin >> type;
	cout << "  Insert the max sum: ";
	cin >> sum;
	S.FilterTypeEM(type, sum);
	cout << endl;
	cout << "        Expenses filtered!" << endl;
}

//------------------------------------------------------------------------------------------------------------

vector<string> UI::ParsCommand() {
	string cmdl;
	cout << endl;
	cout << " Insert your command in line!" << endl;
	cout << "    ex: add 10 internet" << endl;
	cout << endl;
	cout << " Command: ";
	getline(cin >> ws, cmdl);
	stringstream buf(cmdl);
	vector<string> tokens; 
	string item;
	while (getline(buf, item, ' ')) {
		tokens.push_back(item);
	}
	return tokens;
}

void UI::HandleCLI(vector<string> tokens) {
	int n = tokens.size();
	string command = tokens[0];
	if (command == "add") {
		int day;
		int money;
		char type[1000];
		if (n == 3) {
			int LocalTime;
			time_t now = time(NULL);
			tm localTime;
			localtime_s(&localTime, &now);
			int LocalDay = (&localTime)->tm_mday;
			money = stoi(tokens[1]);
			strcpy_s(type, tokens[2].size() + 1, tokens[2].c_str());
			S.Add(LocalDay, money, type);
		}
		if (n == 4) {
			day = stoi(tokens[1]);
			money = stoi(tokens[2]);
			strcpy_s(type, tokens[3].size() + 1, tokens[3].c_str());
			S.Add(day, money, type);
		}
	}
	if (command == "delete") {
		if (n == 2) {
			int ok = -1;
			vector<string> numbs;
			for (int i = 1; i < 32; i++) {
				string a = to_string(i);
				numbs.push_back(a);
			}
			for (string b : numbs) {
				if (b == tokens[1]) {
					ok = 0;
					break;
				}
			}
			if (ok == 0) {
				int day = stoi(tokens[1]);
				S.DelDay(day);
			}
			if (ok == -1) {
				char type[50];
				strcpy_s(type, tokens[1].size() + 1, tokens[1].c_str());
				S.DelType(type);
			}
		}
		if (n == 4) {
			int s, f;
			s = stoi(tokens[1]);
			f = stoi(tokens[3]);
			S.DelRange(s, f);
		}
	}
	if (command == "show") {
		if (n == 1) {
			ShowAll();
		}
		if (n == 2) {
			char type[50];
			strcpy_s(type, tokens[1].size() + 1, tokens[1].c_str());
			cout << endl;
			cout << "	    |   EXPENSES TYPE   |" << endl;
			cout << endl;
			vector<Expense>found = S.ShowType(type);
			for (Expense i : found) {
				cout << "    " << i << endl;
			}
		}
		if (n == 4) {
			if (tokens[2] == ">") {
				cout << endl;
				cout << "	    |   EXPENSES TYPE SORTED   |" << endl;
				cout << endl;
				char type[100];
				int money;
				money = stoi(tokens[3]);
				strcpy_s(type, tokens[1].size() + 1, tokens[1].c_str());
				vector<Expense>found = S.ShowTGM(type, money);
				for (Expense i : found) {
					cout << "    " << i << endl;
				}
			}
			if (tokens[2] == "=") {
				cout << endl;
				cout << "	    |   EXPENSES TYPE SORTED   |" << endl;
				cout << endl;
				int money;
				char type[50];
				money = stoi(tokens[3]);
				strcpy_s(type, tokens[1].size() + 1, tokens[1].c_str());
				cout << endl;
				vector<Expense>found = S.ShowTEM(type, money);
				for (Expense i : found) {
					cout << "   " << i << endl;
				}
			}
		}
	}
	if (command == "get") {
		if (n == 2) {
			cout << endl;
			cout << "	    |   SORTED DAYS   |" << endl;
			cout << endl;
			vector<pair<int, int>> sorted = S.SortDS();
			for (int i = 0; i < sorted.size(); i++) {
				cout << "  Day: " << sorted[i].first << " | Sum: " << sorted[i].second << endl;
			}
		}
		if (n == 3) {
			if (tokens[1] == "sum") {
				char type[50];
				strcpy_s(type, tokens[2].size() + 1, tokens[2].c_str());
				cout << endl;
				cout << "	    |   TYPE-SUM   |" << endl;
				cout << endl;
				int sum = S.SumByType(type);
				cout << "  The sum is: " << sum << endl;
			}
			if (tokens[1] == "max") {
				cout << endl;
				cout << "	    |   MAX-DAY-SUM   |" << endl;
				cout << endl;
				int day = S.MaxDayBySum()[0];
				int sum = S.MaxDayBySum()[1];
				cout << "  The day with the greatest expenses is: " << day << " and the family spent: " << sum << " $!" << endl;
			}
			if (tokens[1] == "sorted") {
				cout << endl;
				cout << "	    |   SORTED-DAYS-TYPE   |" << endl;
				cout << endl;
				char type[50];
				strcpy_s(type, tokens[2].size() + 1, tokens[2].c_str());
				vector<pair<int, int>> sorted = S.SortDST(type);
				for (int i = 0; i < sorted.size(); i++) {
					cout << "  Day: " << sorted[i].first << " | Sum: " << sorted[i].second << endl;
				}
			}
		}
	}
	if (command == "filter") {
		if (n == 2) {
			char type[50];
			strcpy_s(type, tokens[1].size() + 1, tokens[1].c_str());
			cout << endl;
			cout << "	    |   FILTER TYPE   |" << endl;
			cout << endl;
			S.FilterType(type);
			cout << endl;
			cout << "        Expenses filtered!" << endl;
		}
		if (n == 4) {
			if (tokens[2] == "<") {
				char type[50];
				int sum = stoi(tokens[3]);
				strcpy_s(type, tokens[1].size() + 1, tokens[1].c_str());
				cout << endl;
				cout << "	    |   FILTER TYPE AND MAX SUM   |" << endl;
				cout << endl;
				S.FilterTypeLM(type, sum);
				cout << endl;
				cout << "        Expenses filtered!" << endl;
			}
			if (tokens[2] == "=") {
				char type[50];
				int sum = stoi(tokens[3]);
				strcpy_s(type, tokens[1].size() + 1, tokens[1].c_str());
				cout << endl;
				cout << "	    |   FILTER TYPE AND SUM   |" << endl;
				cout << endl;
				S.FilterTypeEM(type, sum);
				cout << endl;
				cout << "        Expenses filtered!" << endl;
			}
		}
	}
	if(command != "add" && command != "delete" && command != "show" && command != "get" && command != "filter" || n == 0) {
		cout << "  Invalid command!  :(  " << endl;
	}
}

void UI::Undo() {
	cout << " Coming soon!" << endl;
}

//------------------------------------------------------------------------------------------------------------

void UI::Run()
{
	bool ok = false;
	while (!ok) {
		Menu();
		int cmd;
		cout << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "  Insert your option: ";
		cin >> cmd;
		cout << "----------------------------------------------------------" << endl;
		switch (cmd)
		{
		case(0): { ok = true; break; }
		case(1): { Add(); break; }
		case(2): { Delete(); break; }
		case(3): { Update(); break; }

		case(4): {DelDay(); break; }
		case(5): {DelRange(); break; }
		case(6): {DelType(); break; }

		case(7): {ShowAll(); break; }
		case(8): {ShowType(); break; }
		case(9): {ShowTGM(); break; }
		case(10): {ShowTEM(); break; }

		case(11): {SumByType(); break; }
		case(12): {MaxDayBySum(); break; }
		case(13): {SortDS(); break; }
		case(14): {SortDST(); break; }

		case(15): {FilterType(); break; }
		case(16): {FilterTypeLM(); break; }
		case(17): {FilterTypeEM(); break; }

		case(18): {vector<string>tokens = ParsCommand(); HandleCLI(tokens); break; }
		case(19): {Undo(); break; }
		}
	}
}