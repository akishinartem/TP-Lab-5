#include "Keeper.h"

int Choose() {
	try {
		int x = 0;
		cout << "choose:" << endl
			<< "[1] std." << endl
			<< "[2] prep." << endl
			<< "[3] pers." << endl
			<< ">> " << endl;
		cin >> x;
		if (x < 1 || x > 3)
			throw 1;
		return x;
	}
	catch (...) {
		cout << "error";
	}
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
	VYZ** temp = new VYZ * [size + 1];
	int i = 0;
	while (i < size) {
		temp[i] = Value[i];
		i++;
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
	if (temp[size]->IsError())
		cout << "error(-)" << endl;
	else
		cout << "+!" << endl;
	size++;
	if (Value)
		delete[] Value;
	Value = temp;
}

void Keeper::Add(int _type, ifstream &fin) {
	VYZ** temp = new VYZ * [size + 1];
	int i = 0;
	while (i < size) {
		temp[i] = Value[i];
		i++;
	}
	switch (_type) {
	case 1:
		temp[size] = new Student(fin);
		break;
	case 2:
		temp[size] = new Prepod(fin);
		break;
	case 3:
		temp[size] = new Personal(fin);
		break;
	default:
		break;
	}
	if (temp[size]->IsError())
		cout << "error(-)" << endl;
	else
		cout << "+!" << endl;
	size++;
	if (Value) {
		delete[] Value;
	}
	Value = temp;
}

void Keeper::Edit() {
	int x;
	if (!size)
		cout << "empty" << endl;
	for (int i = 0; i < size; i++) {
		cout << i;
		switch (Value[i]->GetType()) {
		case 1:
			cout << "std" << endl;
			break;
		case 2:
			cout << "prep" << endl;
			break;
		case 3:
			cout << "pers" << endl;
			break;
		default:
			break;
		}
	}
	cin >> x;
	Value[x]->Edit();
	if (Value[x]->IsError())
		cout << "error(-)" << endl;
	else
		cout << "+" << endl;
}

void Keeper::Del() {
	int x;
	if (!size)
	cout << "empty" << endl;
	for (int i = 0; i < size; i++) {
		cout << i;
		switch (Value[i]->GetType()) {
		case 1:
			cout << "std" << endl;
			break;
		case 2:
			cout << "prep" << endl;
			break;
		case 3:
			cout << "pers" << endl;
			break;
		default:
			break;
		}
	}
	cin >> x;
	if (size == 1) {
		delete[] Value;
		Value = nullptr;
		cout << "deleted!" << endl;
		size--;
	}
	VYZ** temp = new VYZ * [size - 1];
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (x == i)
			continue;
		temp[j] = Value[i];
	}
	delete[] Value;
	Value = temp;
	size--;
	cout << "deleted!" << endl;
}

void Keeper::Save() {
	ofstream fout("test.txt");
	for (int i = 0; i < size; i++) {
		Value[i]->Save(fout);
	}
	fout.close();
	cout << "saved!" << endl;
}

void Keeper::Load() {
	ifstream fin("test.txt");
	if (fin.fail())
		cout << "empty file" << endl;
	int type = 0;
	while (fin) {
		fin >> type;
		if (fin.peek() == -1)
			break;
		Add(type, fin);
	}
	fin.close();
	cout << "loaded!" << endl;
}

ostream& operator<< (ostream& out, Keeper& obj) {
	if (!obj.size) {
		cout << "empty!" << endl;
		return out;
	}
	for (int i = 0; i < obj.size; i++) {
		obj.Value[i]->Print(out);
	}
	return out;
}