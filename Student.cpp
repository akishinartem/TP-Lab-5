#include "Student.h"

Student::Student() {
	stdFIO.Name = "";
	stdFIO.SurName = "";
	stdFIO.LastName = "";
	group = 0;
	spec = 0;
	course = 0;
	sr_ball = 0;
}

Student::Student(ifstream &fin) {
	//
}

Student::~Student() {

}

void Student::Edit() {
	//
}

void Student::Save(ofstream& fout) {
	//
}

void Student::Print(ostream& out) {
	//
}