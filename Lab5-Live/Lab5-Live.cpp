#include <iostream>
#include <string>
#include"Expense.h"
#include"Service.h"
#include"Tests.h"
using namespace std;

void Menu() {
    cout << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "     |   MENU   |" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl;
    cout << "  0. Exit" << endl;
    cout << "  1. Add expense" << endl;
    cout << "  2. Show all expenses" << endl;
    cout << "  3. Delete expense" << endl;
    cout << "  4. Update expense" << endl;
}

void ShowAll(Service& serv) {
    cout << endl;
    cout << "     |   EXPENSES   |" << endl;
    cout << endl;
    for (int i = 0; i < serv.getSize(); i++) {
        cout << " " << serv.getAll()[i] << endl;
    }
}

int main()
{
    TestService();
    TestExpense();
    TestRepo();
    int cmd;
    Service serv;
    while (true) {
        Menu();
        cout << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Insert your option: ";
        cin >> cmd;
        cout << "----------------------------------------------------------" << endl;
        if (cmd == 0) {
            break;
        }
        if (cmd == 1) {
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
            Expense e(day, money, type);
            serv.addExpense(e);
            cout << endl;
            cout << "        Expense added!   " << endl;
        }
        if (cmd == 2) {
            ShowAll(serv);
        }
        if (cmd == 3) {
            ShowAll(serv);
            cout << endl;
            int del_day;
            cout << "Insert the day of the expense you want to delete: ";
            cin >> del_day;
            int del_money;
            cout << "Insert the money of the expense you want to delete: ";
            cin >> del_money;
            char del_type[100];
            cout << "Insert the type of the expense you want to delete: ";
            cin >> del_type;
            Expense e1(del_day, del_money, del_type);
            serv.deleteExpense(e1);
            cout << endl;
            cout << "        Expense deleted!" << endl;
        }
        if (cmd == 4) {
            ShowAll(serv);
            int op;
            int day;
            int money;
            char type[100];
            cout << endl;
            cout << "----------------------------------------------------------" << endl;
            cout << "Insert the day, money and type of expense you want to update";
            cout << endl;
            cout << endl;
            cout << "Day: ";
            cin >> day;
            cout << "Money: ";
            cin >> money;
            cout << "Type: ";
            cin >> type;
            cout << endl;
            Expense f(day, money, type);
            int poz = serv.FindExpense(f);
            if (poz >= 0) {
                int new_day;
                cout << "Insert the new day: ";
                cin >> new_day;
                int new_money;
                cout << "Insert the new money: ";
                cin >> new_money;
                char new_type[100];
                cout << "Insert the new type: ";
                cin >> new_type;
                Expense e2(new_day, new_money, new_type);
                serv.updateExpense(poz, e2);
                cout << "----------------------------------------------------------" << endl;
                cout << endl;
                cout << "        Expense Updated!" << endl;
            }
            else {
                cout << "        Invalid data!" << endl;
            }
        }
    }
    return 0;
}
