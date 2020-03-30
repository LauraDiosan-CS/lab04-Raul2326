#include<iostream>
#include "Repository.h"

Repo::Repo() {
	this->n = 0;
}

Repo::~Repo() {
	this->n = 0;
}

//---------------------------------------------------

void Repo::Add(Expense s) {
	this->expenses[this->n++] = s;
}

void Repo::Delete(int poz, Expense e) {
	for (int i = poz; i <= n - 2; i++)
		this->expenses[i] = this->expenses[i + 1];
	n--;
}

void Repo::DeleteEl(Expense e) {
	int poz = FindExpense(e);
	for (int i = poz; i <= n - 2; i++)
		this->expenses[i] = this->expenses[i + 1];
	n--;
}

void Repo::Update(int poz, Expense e1) {
	expenses[poz] = e1;
}

//---------------------------------------------------

int Repo::getSize() {
	return this->n;
}

Expense* Repo::getAll() {
	return this->expenses;
}

//---------------------------------------------------

int Repo::FindExpense(Expense f) {
	for (int i = 0; i < this->n; i++)
		if (f == this->expenses[i])
			return i;
	return -1;
}