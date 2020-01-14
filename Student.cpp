#include "Student.h"

Student::Student() {
	try {
		SetType(1);
		SetErr(false);
		cout << "Введите ФИО студента:" << endl
			<< "Имя: ";
		cin.ignore(256, '\n');
		getline(cin, this->stdFIO.Name);
		cout << "Фамилия: ";
		getline(cin, this->stdFIO.SurName);
		cout << "Отчество: ";
		getline(cin, this->stdFIO.LastName);
		cout << "Группа: ";
		cin >> this->group;
		if (isalpha(this->group))
			throw 1;
		cout << "Специальность: ";
		cin.ignore(256, '\n');
		getline(cin, this->spec);
		cout << "Номер курса: ";
		cin >> this->course;
		if (isalpha(this->course))
			throw 2;
		cout << "Средний балл: ";
		cin >> this->sr_ball;
		if (isalpha(this->sr_ball))
			throw 3;
	}
	catch (int err) {
		SetErr(true);
		switch (err) {
		case 1:
			cout << "Номер группы может быть только числом!" << endl;
			break;
		case 2:
			cout << "Номер курса может быть только числом!" << endl;
			break;
		case 3:
			cout << "Средний балл может быть только числом!" << endl;
			break;
		}
	}
}

Student::Student(ifstream &fin) {
	SetType(1);
	fin.ignore(256, '\n');
	getline(fin, this->stdFIO.Name);
	getline(fin, this->stdFIO.SurName);
	getline(fin, this->stdFIO.LastName);
	fin >> this->group;
	fin.ignore(256, '\n');
	getline(fin, this->spec);
	fin >> this->course;
	fin >> this->sr_ball;
}

Student::~Student() {
	cout << "std dstrctr" << endl;
}

void Student::Edit() {
	SetErr(false);
	int choose;
	FIO fio_temp;
	char i_temp;
	string s_temp;
	char f_temp;
	cout << "Выберите редактируемый параметр:" << endl
		<< "[1] ФИО." << endl
		<< "[2] Группа." << endl
		<< "[3] Специальность." << endl
		<< "[4] Номер курса." << endl
		<< "[5] Средний балл." << endl
		<< "[0] Отмена." << endl
		<< ">> ";
	cin >> choose;
	try {
		switch (choose) {
		case 1:
			cout << "Текущее: ";
			cout << this->stdFIO.Name << " "
				<< this->stdFIO.SurName << " "
				<< this->stdFIO.LastName << endl
				<< "Новое:  Имя >> ";
			cin.ignore(256, '\n');
			getline(cin, fio_temp.Name);
			cout << "\tФамилия >> ";
			getline(cin, fio_temp.SurName);
			cout << "\tОтчество >> ";
			getline(cin, fio_temp.LastName);
			stdFIO = fio_temp;
			break;
		case 2:
			cout << "Текущее: ";
			cout << this->group << endl
				<< "Новое >> ";
			cin >> i_temp;
			if (isalpha(i_temp))
				throw 1;
			group = i_temp;
			break;
		case 3:
			cout << "Текущее: ";
			cout << this->spec << endl
				<< "Новое >> ";
			cin.ignore(256, '\n');
			getline(cin, s_temp);
			spec = s_temp;
			break;
		case 4:
			cout << "Текущее: ";
			cout << this->course << endl
				<< "Новое >> ";
			cin >> i_temp;
			if (isalpha(i_temp))
				throw 2;
			course = i_temp;
			break;
		case 5:
			cout << "Текущее: ";
			cout << this->sr_ball << endl
				<< "Новое >> ";
			cin >> f_temp;
			if (isalpha(f_temp))
				throw 3;
			sr_ball = f_temp;
			break;
		default:
			break;
		}
	}
	catch (int err) {
		SetErr(true);
		switch (err) {
		case 1:
			cout << "Номер группы может быть только числом!" << endl;
			break;
		case 2:
			cout << "Номер курса может быть только числом!" << endl;
			break;
		case 3:
			cout << "Средний балл может быть только числом!" << endl;
			break;
		}
	}
}

void Student::Save(ofstream& fout) {
	fout << GetType() << endl
		<< this->stdFIO.Name << endl
		<< this->stdFIO.SurName << endl
		<< this->stdFIO.LastName << endl
		<< this->group << endl
		<< this->spec << endl
		<< this->course << endl
		<< this->sr_ball << endl;
}

void Student::Print(ostream& out) {
	out << "Студент:" << endl
		<< "ФИО:" << this->stdFIO.Name << " " << this->stdFIO.SurName << " " << this->stdFIO.LastName << endl
		<< "Группа:" << this->group << endl
		<< "Специальность:" << this->spec << endl
		<< "Номер курса:" << this->course << endl
		<< "Средний балл:" << this->sr_ball << endl
		<< "=================================" << endl;
}
