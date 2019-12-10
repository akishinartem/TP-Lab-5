#include "Prepod.h"

Prepod::Prepod() {
	SetType(2);
	cout << "������� ��� �������������:" << endl
		<< "���: ";
	cin.ignore(256, '\n');
	getline(cin, this->prepFIO.Name);
	cout << "�������: ";
	getline(cin, this->prepFIO.SurName);
	cout << "��������: ";
	getline(cin, this->prepFIO.LastName);
	cout << "������� ������: ";
	cin >> this->groups;
	cout << "������� ����������: ";
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
	cout << "prep dstrctr" << endl;
}

void Prepod::Edit() {
	int choose;
	FIO fio_temp;
	int i_temp;
	string s_temp;
	cout << "�������� ������������� ��������:" << endl
		<< "[1] ���." << endl
		<< "[2] ������." << endl
		<< "[3] ����������." << endl
		<< "[0] ������." << endl;
	cin >> choose;
	switch (choose) {
	case 1:
		cout << "�������: ";
		cout << this->prepFIO.Name << " "
			<< this->prepFIO.SurName << " "
			<< this->prepFIO.LastName << endl
			<< "�����:  ��� >> ";
		cin.ignore(256, '\n');
		getline(cin, fio_temp.Name);
		cout << "\t������� >> ";
		getline(cin, fio_temp.SurName);
		cout << "\t�������� >> ";
		getline(cin, fio_temp.LastName);
		prepFIO = fio_temp;
		break;
	case 2:
		cout << "�������: ";
		cout << this->groups << endl
			<< "����� >> ";
		cin >> i_temp;
		groups = i_temp;
		break;
	case 3:
		cout << "�������: ";
		cout << this->disc << endl
			<< "����� >> ";
		cin.ignore(256, '\n');
		getline(cin, s_temp);
		disc = s_temp;
		break;
	default:
		break;
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
	out << "�������������:" << endl
		<< "���:" << this->prepFIO.Name << " " << this->prepFIO.SurName << " " << this->prepFIO.LastName << endl
		<< "������:" << this->groups << endl
		<< "����������:" << this->disc << endl
		<< "=================================" << endl;
}