#include<iostream>
#include "Repo.h"
using namespace std;

Repo::Repo() {
	this->n = 0;
}

Repo::~Repo() {
	this->n = 0;
}

int Repo::FindExpense(Expense f) {
	for (int i = 0; i < this->n; i++)
		if (f == this->expenses[i])
			return i;
	return -1;
}

void Repo::addExpense(Expense s) {
	this->expenses[this->n++] = s;
}

void Repo::deleteExpense(Expense e) {
	int poz = FindExpense(e);
	if (poz >= 0 && poz <= n - 1) {
		for (int i = poz; i <= n - 2; i++)
			this->expenses[i] = this->expenses[i + 1];
		n--;
	}
	else {
		cout << endl;
		cout << "There is no expense with that day!" << endl;
	}
}

void Repo::updateExpense(int poz, Expense e1) {
	expenses[poz] = e1;
}

Expense* Repo::getAll() {
	return this->expenses;
}

int Repo::getSize() {
	return this->n;
}