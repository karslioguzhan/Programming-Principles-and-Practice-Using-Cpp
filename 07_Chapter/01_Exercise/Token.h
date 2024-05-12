#pragma once
#include "std_lib_facilities.h"
// Token as struct
class Token {
public:
	// Member variables of Struct
	char kind;
	double value;
	string name;
	// All Token constructors with initializer list
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string name) :kind(ch), name(name), value(0) { } // 1. Error: Missing constructor
};