#include "Personal.h"

Personal::Personal() {
	persFIO.Name = "";
	persFIO.SurName = "";
	persFIO.LastName = "";
	spec = "";
	tel = 0;
	obl = "";
}

Personal::Personal(ifstream &fin) {
	//
}

Personal::~Personal() {

}

void Personal::Edit() {
	//
}

void Personal::Save(ofstream& fout) {
	//
}

void Personal::Print(ostream& out) {
	//
}