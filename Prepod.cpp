#include "Prepod.h"

Prepod::Prepod() {
	try {
		SetType(2);
		SetErr(false);
		cout << "Введите ФИО преподавателя:" << endl
			<< "Имя: ";
		cin.ignore(256, '\n');
		getline(cin, this->prepFIO.Name);
		cout << "Фамилия: ";
		getline(cin, this->prepFIO.SurName);
		cout << "Отчество: ";
		getline(cin, this->prepFIO.LastName);
		cout << "Введите группы: ";
		cin >> this->groups;
		if (isalpha(this->groups))
			throw 1;
		cout << "Введите дисциплину: ";
		cin.ignore(256, '\n');
		getline(cin, this->disc);
	}
	catch (int) {
		SetErr(true);
		cout << "Номер группы может быть только числом!" << endl;
	}
}

Prepod::Prepod(ifstream &fin) {
	SetType(2);
	fin.ignore(256, '\n');
	getline(fin, this->prepFIO.Name);
	getline(fin, this->prepFIO.SurName);
	getline(fin, this->prepFIO.LastName);
	fin >> this->groups;
	fin.ignore(256, '\n');
	getline(fin, this->disc);
}

Prepod::~Prepod() {
	cout << "prep dstrctr" << endl;
}

void Prepod::Edit() {
	SetErr(false);
	int choose;
	FIO fio_temp;
	char i_temp;
	string s_temp;
	cout << "Выберите редактируемый параметр:" << endl
		<< "[1] ФИО." << endl
		<< "[2] Группы." << endl
		<< "[3] Дисциплина." << endl
		<< "[0] Отмена." << endl;
	cin >> choose;
	try {
		switch (choose) {
		case 1:
			cout << "Текущее: ";
			cout << this->prepFIO.Name << " "
				<< this->prepFIO.SurName << " "
				<< this->prepFIO.LastName << endl
				<< "Новое:  Имя >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.Name);
			cout << "\tФамилия >> ";
			getline(cin, fio_temp.SurName);
			cout << "\tОтчество >> ";
			getline(cin, fio_temp.LastName);
			prepFIO = fio_temp;
			break;
		case 2:
			cout << "Текущее: ";
			cout << this->groups << endl
				<< "Новое >> ";
			cin >> i_temp;
			if (isalpha(i_temp))
				throw 1;
			groups = i_temp;
			break;
		case 3:
			cout << "Текущее: ";
			cout << this->disc << endl
				<< "Новое >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			disc = s_temp;
			break;
		default:
			break;
		}
	}
	catch (int) {
		SetErr(true);
		cout << "Номер группы может быть только числом!" << endl;
	}
}

void Prepod::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->prepFIO.Name << endl
		<< this->prepFIO.SurName << endl
		<< this->prepFIO.LastName << endl
		<< this->groups << endl
		<< this->disc << endl;
}

void Prepod::Print(ostream& out) {
	out << "Преподаватель:" << endl
		<< "ФИО:" << this->prepFIO.Name << " " << this->prepFIO.SurName << " " << this->prepFIO.LastName << endl
		<< "Группы:" << this->groups << endl
		<< "Дисциплина:" << this->disc << endl
		<< "=================================" << endl;
}
