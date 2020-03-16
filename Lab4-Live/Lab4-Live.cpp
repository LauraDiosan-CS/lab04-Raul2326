#include <iostream>
#include"Expense.h"
#include"Repo.h"
#include"Tests.h"
using namespace std;

int main()
{
    int cmd;
    int day;
    int money;
    char type[1000];
    while (true) {
        Tests();
        cout << endl;
        cout << "0. Exit" << endl;
        cout << "1. Add expense" << endl;
        cout << endl;
        cout << "Insert your option: ";
        cin >> cmd;
        if (cmd == 0) {
            break;
        }
        if (cmd == 1) {
            cout << "Insert the day: ";
            cin >> day;
            cout << "Insert the spent sum: ";
            cin >> money;
            cout << "Insert the type of expense: ";
            cin >> type;
            Expense e1(day, money, type);
            cout << e1;
        }
    }
}
