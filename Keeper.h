#pragma once
#include "Base.h"
#include "Personal.h"
#include "Prepod.h"
#include "Student.h"
#include <fstream>
using namespace std;

class Keeper {
private:
	VYZ** Value;
	int size;
public:
	Keeper();
	~Keeper();
	int GetSize();
	void Add();
	void Add(int value, ifstream &fin);
	void Del();
	void Save();
	void Load();
	friend ostream& operator<< (ostream& out, Keeper& obj);
};