#include "Base.h"

void VYZ::SetType(int _type) {
	type = _type;
}

int VYZ::GetType() {
	return type;
}

bool VYZ::IsError() {
	return this->error;
}

void VYZ::SetError(bool _error) {
	this->error = _error;
}

VYZ::~VYZ() {
	//
}