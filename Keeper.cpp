#include "Keeper.h"

int Choose() {
	int x = 0;
	cout << "Выберите класс:" << endl
		<< "[1] Студенты." << endl
		<< "[2] Преподаватели." << endl
		<< "[3] Персонал." << endl
		<< ">> ";
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
	try {
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
		}
		if (!temp[size])
			throw 1;
		else
			cout << "Объект успешно добавлен!" << endl;
		size++;
		if (Value)
			delete[] Value;
		Value = temp;
	}
	catch (...) {
		cout << "Объект не был добавлен из-за ошибки." << endl;
	}
}

void Keeper::Add(int _type, ifstream &fin) {
	try {
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
		}
		if (!temp[size])
			throw 1;
		else
			cout << "Объект успешно добавлен!" << endl;
		size++;
		if (Value)
			delete[] Value;
		Value = temp;
	}
	catch (...) {
		cout << "Объект не был добавлен из-за ошибки." << endl;
	}
}

void Keeper::Edit() {
	int x;
	if (!size)
		cout << "Контейнер пуст!" << endl;
	for (int i = 0; i < size; i++) {
		cout << "[" << i+1 << "] ";
		switch (Value[i]->GetType()) {
		case 1:
			cout << "Студент" << endl;
			break;
		case 2:
			cout << "Преподаватель" << endl;
			break;
		case 3:
			cout << "Персонал" << endl;
			break;
		default:
			break;
		}
	}
	try {
		cout << ">> ";
		cin >> x;
		if ((x < 1) || (x > size)) {
			throw 1;
		}
		x -= 1;
		Value[x]->Edit();
		if (!Value[x])
			cout << "Редактирование не удалось." << endl;
		else
			cout << "Редактирование завершено." << endl;
	}
	catch (...) {
		cout << "Выбранный пункт недоступен." << endl;
	}
}

void Keeper::Del() {
	int x;
	if (!size)
	cout << "Контейнер пуст!" << endl;
	for (int i = 0; i < size; i++) {
		cout << i;
		switch (Value[i]->GetType()) {
		case 1:
			cout << "Студент:" << endl;
			break;
		case 2:
			cout << "Преподаватель:" << endl;
			break;
		case 3:
			cout << "Персонал:" << endl;
			break;
		default:
			break;
		}
	}
	cin >> x;
	if (size == 1) {
		delete[] Value;
		Value = nullptr;
		cout << "Удаление успешно!" << endl;
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
	cout << "Удаление успешно!" << endl;
}

void Keeper::Save() {
	ofstream fout("test.txt");
	for (int i = 0; i < size; i++) {
		Value[i]->Save(fout);
	}
	fout.close();
	cout << "Сохранено!" << endl;
}

void Keeper::Load() {
	ifstream fin("test.txt");
	if (fin.fail())
		cout << "Файл пуст." << endl;
	int type = 0;
	while (fin) {
		fin >> type;
		if (fin.peek() == -1)
			break;
		Add(type, fin);
	}
	fin.close();
	cout << "Успешно загружено!" << endl;
}

ostream& operator<< (ostream& out, Keeper& obj) {
	if (!obj.size) {
		cout << "Контейнер пуст!" << endl;
		return out;
	}
	for (int i = 0; i < obj.size; i++) {
		obj.Value[i]->Print(out);
	}
	return out;
}