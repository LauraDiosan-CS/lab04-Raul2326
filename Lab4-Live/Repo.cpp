#include "Repo.h"

Repo::Repo() {
	this->n = 0;
}
Repo::~Repo() {
	this->n = 0;
}
void Repo::addExpense(Expense s) {
	this->expenses[this->n++] = s;
}

Expense* Repo::getAll() {
	return this->expenses;
}