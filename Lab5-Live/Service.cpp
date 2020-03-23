#include<iostream>
#include"Service.h"

Service::Service() {
}

Service::Service(const Repo& R) {
	repo = R;
}

Service::~Service() {
}

int Service::getSize() {
	return repo.getSize();
}

Expense* Service::getAll() {
	return repo.getAll();
}

void Service::addExpense(Expense e) {
	repo.addExpense(e);
}

void Service::deleteExpense(Expense e) {
	repo.deleteExpense(e);
}

int Service::FindExpense(Expense e) {
	return repo.FindExpense(e);
}

void Service::updateExpense(int poz, Expense e1) {
	repo.updateExpense(poz, e1);
}
