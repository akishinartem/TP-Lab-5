#pragma once
#include <iostream>
using namespace std;

class VYZ {
private:
	int type;
public:
	void SetType(int _type);
	int GetType();
	virtual void Save(ofstream& fout) = 0;
	virtual ~VYZ() = 0;
	virtual void Print(ostream& out) = 0;
};