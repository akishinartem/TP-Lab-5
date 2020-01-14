#include "Personal.h"

Personal::Personal() {
	try {
		SetType(3);
		SetErr(false);
		cout << "Введите ФИО:" << endl
			<< "Имя: ";
		cin.ignore(256, '\n');
		getline(cin, this->persFIO.Name);
		cout << "Фамилия: ";
		getline(cin, this->persFIO.SurName);
		cout << "Отчесво: ";
		getline(cin, this->persFIO.LastName);
		cout << "Введите специальность: ";
		getline(cin, this->spec);
		cout << "Введите телефон: ";
		cin >> this->tel;
		if (isalpha(this->tel))
			throw 1;
		cout << "Введите область ответственности:";
		cin.ignore(256, '\n');
		getline(cin, this->obl);
	}
	catch (int) {
		SetErr(true);
		cout << "Номер телефона может быть только числом!" << endl;
	}
}

Personal::Personal(ifstream &fin) {
	SetType(3);
	fin.ignore(256, '\n');
	getline(fin, this->persFIO.Name);
	getline(fin, this->persFIO.SurName);
	getline(fin, this->persFIO.LastName);
	getline(fin, this->spec);
	fin >> this->tel;
	fin.ignore(256, '\n');
	getline(fin, this->obl);
}

Personal::~Personal() {
	cout << "pers dstrctr";
}

void Personal::Edit() {
	int choose;
	FIO fio_temp;
	string s_temp;
	char i_temp;
	cout << "Выберите редактируемый параметр:" << endl
		<< "[1] ФИО." << endl
		<< "[2] Специальность." << endl
		<< "[3] Телефон." << endl
		<< "[4] Область ответственности." << endl
		<< "[0] Отмена." << endl;
	cin >> choose;
	try {
		switch (choose) {
		case 1:
			cout << "Текущее: ";
			cout << this->persFIO.Name << " "
				<< this->persFIO.SurName << " "
				<< this->persFIO.LastName << endl
				<< "Новое:  Имя >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.Name);
			cout << "\tФамилия >> ";
			getline(cin, fio_temp.SurName);
			cout << "\tОтчество >> ";
			getline(cin, fio_temp.LastName);
			persFIO = fio_temp;
			break;
		case 2:
			cout << "Текущее: ";
			cout << this->spec << endl
				<< "Новое >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			spec = s_temp;
			break;
		case 3:
			cout << "Текущее: ";
			cout << this->tel << endl
				<< "Новое >> ";
			cin >> i_temp;
			if (isalpha(i_temp))
				throw 1;
			tel = i_temp;
			break;
		case 4:
			cout << "Текущее: ";
			cout << this->obl << endl
				<< "Новое >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			obl = s_temp;
			break;
		default:
			break;
		}
	}
	catch (int) {
		SetErr(true);
		cout << "Номер телефона может быть только числом!" << endl;
	}
}

void Personal::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->persFIO.Name << endl
		<< this->persFIO.SurName << endl
		<< this->persFIO.LastName << endl
		<< this->spec << endl
		<< this->tel << endl
		<< this->obl << endl;
}

void Personal::Print(ostream& out) {
	out << "Персонал:" << endl
		<< "ФИО:" << this->persFIO.Name << " " << this->persFIO.SurName << " " << this->persFIO.LastName << endl
		<< "Специальность:" << this->spec << endl
		<< "Телефон:" << this->tel << endl
		<< "Область ответственности:" << this->obl << endl
		<< "=================================" << endl;
}
