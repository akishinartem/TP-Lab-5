#include "Prepod.h"

Prepod::Prepod() {
	SetType(2);
	cout << "enter name" << endl
		<< "1st: ";
	cin.ignore(256, '\n');
	getline(cin, this->prepFIO.Name);
	cout << "2nd: ";
	getline(cin, this->prepFIO.SurName);
	cout << "3rd: ";
	getline(cin, this->prepFIO.LastName);
	cout << "enter groups: ";
	cin >> this->groups;
	cout << "enter disc: ";
	cin.ignore(256, '\n');
	getline(cin, this->disc);
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
	cout << "prep destructor" << endl;
}

void Prepod::Edit() {
	int choose;
	FIO fio_temp;
	int i_temp;
	string s_temp;
	cout << "chsoose:" << endl
		<< "1name" << endl
		<< "2groups" << endl
		<< "3disc" << endl
		<< "0cancel" << endl;
	cin >> choose;
	switch (choose) {
	case 1:
		cout << "new" << endl
			<< "1name: ";
		cin.ignore(256, '\n');
		getline(cin, fio_temp.Name);
		cout << "2surname: ";
		getline(cin, fio_temp.SurName);
		cout << "3lastname: ";
		getline(cin, fio_temp.LastName);
		prepFIO = fio_temp;
		break;
	case 2:
		cout << "new: ";
		cin >> i_temp;
		groups = i_temp;
		break;
	case 3:
		cout << "new: ";
		cin.ignore(256, '\n');
		getline(cin, s_temp);
		disc = s_temp;
		break;
	default:
		cout << "canceled!" << endl;
		break;
	}
	SetError(false);
}

void Prepod::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->prepFIO.Name << this->prepFIO.SurName << this->prepFIO.LastName << endl
		<< this->groups << endl
		<< this->disc << endl;
}

void Prepod::Print(ostream& out) {
	out << "prep" << endl
		<< "name:" << this->prepFIO.Name << this->prepFIO.SurName << this->prepFIO.LastName << endl
		<< "groups:" << this->groups << endl
		<< "disc:" << this->disc << endl;
}