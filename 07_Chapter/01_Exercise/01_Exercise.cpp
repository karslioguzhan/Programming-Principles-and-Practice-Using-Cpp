// 01_Exercise.cpp : This exercise divided into subtask
/*
	1. Allow underscores in the calculator's variable names.
	2. Provide an assignment operator, =, so that you can change the value of a variable after you introduce it using let. Discuss why that can be useful and how it can be a source of problems.
	3. Provide named constants that you really can't change the value of. Hint: You have to add a member to Variable that distinguishes between constants and variables and check for it in set_value(). If you want to let the user define constants (rather than just having pi and e defined as constants), you'll have to add a notation to let the user express that, for example, const pi = 3.14 ;.
	4. The get_value(), set_value(), is_declared(), and define_name() functions all operate on the variable var_table. Define a class called Symbol_table with a member var_table of type vector<Variable> and member functions get(), set(), is_declared(), and declare(). Rewrite the calculator to use a variable of type Symbol_table.
*/

/*
	Solution
	2. With the possibility to change values after they are declared earlier calculation can be misinterpreted. But the advantage is to change values if they are false or needed to update. For example are exchange rates that changes regularly.


*/

#include "std_lib_facilities.h"
#include "Symbol_table.h"
#include "Token.h"
#include "Token_stream.h"
#include "GlobalVariables.h"

// SquareRoot function prototype
double squareRootFunction();

// Pow function prototype
double powFunction();

// Function prototype for expressions
double expression();

// get primaries
double primary()
{
	Symbol_table* referenceSymbolTable = Symbol_table::getInstance();
	Token_stream* ts = Token_stream::GetInstance();
	// Get token from token-stream
	Token t = ts->get();
	// Switch regarding of token kind
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts->get();
		if (t.kind != ')') error("')' expected");
		return d; // Missing return
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return referenceSymbolTable->get_value(t.name);
	case squareRootVal:
		return squareRootFunction();
	case powVal:
		return powFunction();
	default:
		error("primary expected");
	}
}

// Handler for terms
double term()
{
	// Get left primary
	double left = primary();
	Token_stream* ts = Token_stream::GetInstance();
	while (true) {
		// Get token and check if multiplication or division
		Token t = ts->get();
		switch (t.kind) {
		case '*':
			// Multiply with primary
			left *= primary();
			break;
		case '/':
		{
			// Division with check if dividing with zero
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		// Default just return the value
		default:
			ts->unget(t);
			return left;
		}
	}
}

// Handle expressions
double expression()
{
	Token_stream* ts = Token_stream::GetInstance();
	double left = term();
	while (true) {
		Token t = ts->get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts->unget(t);
			return left;
		}
	}
}

// Handle statements
double statement()
{
	Symbol_table* referenceSymbolTable = Symbol_table::getInstance();
	Token t = ts.get();
	switch (t.kind) {
		// distinction between declaration and expression
	case let:
		return referenceSymbolTable->declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

// Setting outputs for prompt and result printing
const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

double squareRootFunction()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		// getting first expression
		double d = expression();

		t = ts.get();
		if (t.kind != ')')
			error(" Missing ')'!");
		if (d < 0) error(" Dont support negative square roots!");
		return sqrt(d);
	}
	default:
		error(" 'Missing ')'!");
	}
}

double powFunction()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '(':
	{
		// Get first expression
		double d = expression();

		// Check if ',' as parameter delimiter is inserted
		t = ts.get();
		if (t.kind != ',') error(" Missing ','!");

		// get second double
		double d2{ expression() };
		if (fmod(d2, 1) != 0) error(" Doesn't support floating point number for pow!");

		// Get closing bracket
		t = ts.get();
		if (t.kind != ')') error(" Missing ')'!");

		// Return result
		return pow(d, d2);
	}
	default:
		error(" 'Missing ')'!");
	}
}

// Main function
int main()
{
	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}

}