#include "Student.h"

Student::Student() {
	SetType(1);
	cout << "enter name" << endl
		<< "1st: ";
	cin.ignore(256, '\n');
	getline(cin, this->stdFIO.Name);
	cout << "2nd: ";
	getline(cin, this->stdFIO.SurName);
	cout << "3rd: ";
	getline(cin, this->stdFIO.LastName);
	cout << "enter group: ";
	cin >> this->group;
	cout << "enter spec: ";
	cin.ignore(256, '\n');
	getline(cin, this->spec);
	cout << "enter course: ";
	cin >> this->course;
	cout << "enter sr_ball: ";
	cin >> this->sr_ball;
}

Student::Student(ifstream &fin) {
	SetType(1);
	fin.ignore(256, '\n');
	getline (fin, this->stdFIO.Name);
	getline(fin, this->stdFIO.SurName);
	getline(fin, this->stdFIO.LastName);
	fin >> this->group;
	fin.ignore(256, '\n');
	getline(fin, this->spec);
	fin >> this->course;
	fin >> this->sr_ball;
}

Student::~Student() {
	cout << "std destructor" << endl;
}

void Student::Edit() {
	int choose;
	FIO fio_temp;
	int i_temp;
	string s_temp;
	float f_temp;
	cout << "chsoose:" << endl
		<< "1name" << endl
		<< "2group" << endl
		<< "3spec" << endl
		<< "4course" << endl
		<< "5sr_ball" << endl
		<< "0cancel" << endl;
	cin >> choose;
	switch(choose) {
	case 1:
		cout << "new" << endl
			<< "1name: ";
		cin.ignore(256, '\n');
		getline(cin, fio_temp.Name);
		cout << "2surname: ";
		getline(cin, fio_temp.SurName);
		cout << "3lastname: ";
		getline(cin, fio_temp.LastName);
		stdFIO = fio_temp;
		break;
	case 2:
		cout << "new: ";
		cin >> i_temp;
		group = i_temp;
		break;
	case 3:
		cout << "new: ";
		cin.ignore(256, '\n');
		getline(cin, s_temp);
		spec = s_temp;
		break;
	case 4:
		cout << "new: ";
		cin >> i_temp;
		course = i_temp;
		break;
	case 5:
		cout << "new: ";
		cin >> f_temp;
		sr_ball = f_temp;
		break;
	default:
		cout << "canceled!" << endl;
		break;
	}
}

void Student::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->stdFIO.Name << this->stdFIO.SurName << this->stdFIO.LastName << endl
		<< this->group << endl
		<< this->spec << endl
		<< this->course << endl
		<< this->sr_ball << endl;
}

void Student::Print(ostream& out) {
	out << "std" << endl
		<< "name:" << this->stdFIO.Name << this->stdFIO.SurName << this->stdFIO.LastName << endl
		<< "group:" << this->group << endl
		<< "spec:" << this->spec << endl
		<< "course:" << this->course << endl
		<< "sr_ball:" << this->sr_ball << endl;
}