#include "Expense.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Expense::Expense() {
	this->day = 0;
	this->money = 0;
	this->type = NULL;
}

Expense::Expense(int day, int money, char* type)
{
	this->day = day;
	this->money = money;
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, 1 + strlen(type), type);
}

Expense::Expense(const Expense& s) {
	this->day = s.day;
	this->money = s.money;
	this->type = new char[strlen(s.type) + 1];
	strcpy_s(this->type, 1 + strlen(s.type), s.type);
}

int Expense::getDay() {
	return this->day;
}

int Expense::getMoney() {
	return this->money;
}

void Expense::setType(char* type)
{
	if (this->type) {
		delete[] this->type;
	}
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}

void Expense::setDay(int day) {
	this->day = day;
}

void Expense::setMoney(int money) {
	this->money = money;
}

Expense& Expense::operator=(const Expense& s) {			
	this->setDay(s.day);
	this->setMoney(s.money);
	this->setType(s.type);
	return *this;
}

bool Expense:: operator==(const Expense& s) {		
	return this->day == s.day && this->money == s.money && strcmp(this->type, s.type) == 0;
}

ostream& operator<<(ostream& os, const Expense& s)
{
	os << s.day << " " << s.money << " " << s.type;
	return os;
}
