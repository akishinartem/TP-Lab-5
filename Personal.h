#pragma once
#include "Base.h"
#include "Data.h"
using namespace std;

class Personal : public VYZ {
private:
	FIO persFIO;
	string spec;
	char tel;
	string obl;
public:
	Personal();
	Personal(ifstream &fin);
	~Personal();
	void Edit();
	void Save(ofstream& fout);
	void Print(ostream& out);
};