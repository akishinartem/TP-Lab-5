#pragma once
#include "Base.h"
using namespace std;

class Personal : public VYZ {
private:
	string FIO;
	int spec;
	int tel;
	string obl;
public:
	Personal();
	Personal(ifstream &fin);
	~Personal();
	void Save(ofstream& fout);
	void Print(ostream& out);
};