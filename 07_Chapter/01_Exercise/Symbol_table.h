#pragma once
#include "std_lib_facilities.h"
#include "Token.h"
#include "Token_stream.h"
#include "Variable.h"

// Create Symbol_table
class Symbol_table
{
public:
	double get_value(string s);
	void set_value(string s, double d);
	int is_declared(string s);
	double declaration();
	static Symbol_table* getInstance();
protected:
	Symbol_table() : names() {};
	static Symbol_table* referenceSymbolTable;
private:
	// Initialize empty global vector
	vector<Variable> names;
};