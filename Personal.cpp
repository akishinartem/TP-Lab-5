#include "Personal.h"

Personal::Personal() {
	SetType(3);
	cout << "enter name" << endl
		<< "1st: ";
	cin.ignore(256, '\n');
	getline(cin, this->persFIO.Name);
	cout << "2nd: ";
	getline(cin, this->persFIO.SurName);
	cout << "3rd: ";
	getline(cin, this->persFIO.LastName);
	cout << "enter spec: ";
	getline(cin, this->spec);
	cout << "enter tel: ";
	cin >> this->tel;
	cout << "enter obl:";
	cin.ignore(256, '\n');
	getline(cin, this->obl);
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
	cout << "pers destructor";
}

void Personal::Edit() {
	int choose;
	FIO fio_temp;
	string s_temp;
	int i_temp;
	cout << "chsoose:" << endl
		<< "1name" << endl
		<< "2spec" << endl
		<< "3tel" << endl
		<< "4obl" << endl
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
		persFIO = fio_temp;
		break;
	case 2:
		cout << "new:";
		cin.ignore(256, '\n');
		getline(cin, s_temp);
		spec = s_temp;
		break;
	case 3:
		cout << "new:";
		cin >> i_temp;
		tel = i_temp;
		break;
	case 4:
		cout << "new:";
		cin.ignore(256, '\n');
		getline(cin, s_temp);
		obl = s_temp;
		break;
	default:
		break;
	}
	SetError(false);
}

void Personal::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->persFIO.Name << this->persFIO.SurName << this->persFIO.LastName << endl
		<< this->spec << endl
		<< this->tel << endl
		<< this->obl << endl;
}

void Personal::Print(ostream& out) {
	out << "pers" << endl
		<< "name:" << this->persFIO.Name << this->persFIO.SurName << this->persFIO.LastName << endl
		<< "spec:" << this->spec << endl
		<< "tel:" << this->tel << endl
		<< "obl:" << this->obl << endl;
}