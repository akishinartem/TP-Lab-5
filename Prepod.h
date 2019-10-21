#pragma once
#include "Base.h"
using namespace std;

class Prepod : public VYZ {
private:
	string FIO;
	int groups;
	int discipline;
public:
	Prepod();
	Prepod(ifstream &fin);
	~Prepod();
	void Save(ofstream& fout);
	void Print(ostream& out);
};