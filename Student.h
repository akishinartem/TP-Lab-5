#pragma once
#include"Base.h"
using namespace std;

class Student : public VYZ {
private:
	string FIO;
	int group;
	int spec;
	int course;
	float sr_ball;
public:
	Student();
	Student(ifstream &fin);
	~Student();
	void Save(ofstream& fout);
	void Print(ostream& out);
};