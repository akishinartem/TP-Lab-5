#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class VYZ {
private:
	int type;
	bool error;
public:
	void SetType(int _type);
	int GetType();
	bool IsError();
	void SetError(bool _error);
	virtual ~VYZ() = 0;
	virtual void Save(ofstream& fout) = 0;
	virtual void Edit() = 0;
	virtual void Print(ostream& out) = 0;
};