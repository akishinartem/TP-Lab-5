#include "Keeper.h"

int Choose() {
	int x = 0;
	cout << "Выберите класс:" << endl
		<< "[1] Студенты." << endl
		<< "[2] Преподаватели." << endl
		<< "[3] Персонал." << endl
		<< ">> " << endl;
	cin >> x;
	return x;
}

Keeper::Keeper() {
	this->Value = nullptr;
	this->size = 0;
}

Keeper::~Keeper() {
	delete[] Value;
}

int Keeper::GetSize() {
	return size;
}

void Keeper::Add() {
	VYZ** temp = new VYZ*[size + 1];
	int i = 0;
	while (i < size) {
		temp[i] = Value[i];
	}
	switch (Choose()) {
	case 1:
		temp[size] = new Student;
		break;
	case 2:
		temp[size] = new Prepod;
		break;
	case 3:
		temp[size] = new Personal;
		break;
	default:
		break;
	}
	size++;
	if (Value) {
		delete[] Value;
	}
	Value = temp;
}

void Keeper::Add(int value, ifstream &fin) {
	//
}

void Keeper::Del() {
	//
}

void Keeper::Save() {
	//
}

void Keeper::Load() {
	//
}

ostream& operator<< (ostream& out, Keeper& obj) {
	//
}