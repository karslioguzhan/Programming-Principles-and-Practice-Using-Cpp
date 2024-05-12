#pragma once
#include "std_lib_facilities.h"

// Create Variable struct
class Variable {
public:
	string name;
	double value;
	bool isConst{};
	Variable(string n, double v, bool isConst) :name(n), value(v), isConst(isConst) { }
};