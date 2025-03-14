// 10_Exercise.cpp : Add a command from x to the calculator from Chapter 7 that makes it
// take input from a file x.Add a command to y to the calculator that makes 
// it write its output(both standard output and error output) to file y. 
// Write a collection of test cases based on ideas from �7.3 and use that to test the 
// calculator.Discuss how you would use these commands for testing.

#include "std_lib_facilities.h"
#include <limits>
#include <fstream>

// SquareRoot function prototype
double squareRootFunction();

// Pow function prototype
double powFunction();

// Function prototype helper menu
void printHelp();

// Function prototype file input
double fileInputHandler();

// Function prototype file input
void fileOutputHandler();


void clearScreen();

// Token as struct
struct Token {
	// Member variables of Struct
	char kind;
	double value;
	string name;
	// All Token constructors with initializer list
	Token(char ch) :kind(ch), value(0) {}
	Token(char ch, double val) :kind(ch), value(val) {}
	Token(char ch, string name) :kind(ch), name(name), value(0) {} // 1. Error: Missing constructor
};

// Token_stream class
class Token_stream {
	// Member variables
	bool full;
	Token buffer;
public:
	// Default Constructor (Not sure if 0 is legit
	Token_stream() :full(false), buffer(0) {}

	// Method prototype for getting Tokens
	Token get();
	// Method for assigning tokens to buffer
	void unget(Token t) { buffer = t; full = true; }
	// Method prototype for ignoring inputs
	void ignore(char);
};

// Global variables with arbitrary values
const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char k = 'k';
const char squareRootVal{ 's' };
const char powVal{ 'p' };
const char help{ 'H' };
const char clear{ 'C' };
const char fileInputVal{ 'i' };
const char fileOutputVal{ 'o' };

// Constants
const string squareRoot{ "sqrt" };
const string powName{ "pow" };
const string helpName{ "help" };
const string quitName{ "quit" };
const string clearName{ "clear" };
const string fileInputFunction{ "from" };
const string fileOutputFunction{ "to" };


// Getter-Method for Tokens
Token Token_stream::get()
{
	// Returning actual Token if buffer is full
	if (full) { full = false; return buffer; }
	// Read input as character
	char ch{};
	// Get all chars
	do
	{
		cin.get(ch);
	} while (ch == ' ');
	// Switch for determining token type
	switch (ch) {
	case '\n':
		return Token{ print };
	case '(': case ')': case '+': case '-': case '*': case '/': case '%':
	case ';': case '=': case ',': case let:
		// non numeric characters
		return Token(ch);
	case '.': case '0': case '1': case '2': case '3': case '4': case '5':
	case '6': case '7': case '8': case '9':
	{
		// Return numeric values
		cin.unget();
		double val;
		cin >> val;
		if (val > numeric_limits<int>::max())
		{
			error("Overflow Error!");
		}
		else if (val < numeric_limits<int>::min())
		{
			error("Underflow Error!");
		}
		// Check if actual value is suitable for ints
		narrow_cast<int>(val);
		return Token(number, val);
	}
	default:
		// Getting strings from input
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch; // Logical error -> String was not concatenated right
			cin.unget();
			if (s == "#") return Token(let);
			if (s == fileInputFunction) return Token(fileInputVal); // TODO Hier weiter
			if (s == fileOutputFunction) return Token(fileOutputVal); // TODO Hier weiter
			if (s == "exit") return Token(quit);
			if (s == quitName) return Token(quit);
			if (s.size() == 1 && s[0] == k) return Token(number, 1000);
			if (s == squareRoot) return Token(squareRootVal);
			if (s == powName) return Token(powVal);
			if (s == helpName) return Token(help);
			if (s == clearName) return Token(clear);
			return Token(name, s);
		}
		// Error message if nothing valid is inserted
		error("Bad token");
	}
}

// Method for ignoring input chars
void Token_stream::ignore(char c)
{
	// Check if buffer is full and kind of buffer
	if (full && c == buffer.kind) {
		// Set full to false
		full = false;
		return;
	}

	full = false;
	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

// Create Variable struct
struct Variable {
	string name;
	double value;
	bool isConst{};
	Variable(string n, double v, bool isConst) :name(n), value(v), isConst(isConst) {}
};

class Symbol_table {
	vector<Variable> var_table;
public:
	int is_declared(string);
	double get_value(string);
	void set_value(string, double);
	double declaration();
};

// Initialize empty global vector
vector<Variable> names{};

// Get string values
double Symbol_table::get_value(string s)
{
	// Iterate through vector and check if input string is in names
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

// Setter for names with string and value
void Symbol_table::set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

// Check if string is declared
int Symbol_table::is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return i;
	return -1;
}

// Token stream as global variable (not best practice)
Token_stream ts;

// Function prototype for expressions
double expression();

// get primaries
double primary()
{
	// Get token from token-stream
	Token t = ts.get();
	Symbol_table symbolTable{};
	// Switch regarding of token kind
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d; // Missing return
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return symbolTable.get_value(t.name);
	case squareRootVal:
		return squareRootFunction();
	case powVal:
		return powFunction();
	case help:
		printHelp();
		break;
	case clear:
		clearScreen();
		break;
	case fileInputVal:
		return fileInputHandler();
		break;
	case fileOutputVal:
		fileOutputHandler();
		break;
	default:
		error("primary expected");
	}
}

// Handler for terms
double term()
{
	// Get left primary
	double left = primary();
	while (true) {
		// Get token and check if multiplication or division
		Token t = ts.get();
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
			ts.unget(t);
			return left;
		}
	}
}

// Handle expressions
double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

// Handle declarations
double Symbol_table::declaration()
{
	Token t = ts.get();
	// kind name
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	// Case for const
	if (strcmp(name.c_str(), "const") == 0)
	{
		Token variableNameToken = ts.get();
		if (variableNameToken.kind != 'a')
		{
			error("name expected in declaration");
		}
		string name = variableNameToken.name;
		Token equalSignToken = ts.get();
		if (equalSignToken.kind != '=') error("= missing in declaration of ", name);
		double d = expression();
		int searchResult{ is_declared(name) };
		if (searchResult >= 0 && !names.at(searchResult).isConst) // TODO Continue here
		{
			names.at(searchResult).value = d;
			names.at(searchResult).isConst = true;
			return d;
		}
		names.push_back(Variable(name, d, true));
		return d;
	}
	// Default case
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	int searchResult{ is_declared(name) };
	if (searchResult >= 0 && names.at(searchResult).isConst)
	{
		error("Cannot override const variable");
	}
	if (searchResult >= 0 && !names.at(searchResult).isConst) // TODO Continue here
	{
		names.at(searchResult).value = d;
		return d;
	}

	names.push_back(Variable(name, d, false));
	return d;
}

// Handle statements
double statement()
{
	Token t = ts.get();
	Symbol_table symbolTable{};
	switch (t.kind) {
		// distinction between declaration and expression
	case let:
		return symbolTable.declaration();
	case 'H':
		ts.unget(t);
		expression();
		return numeric_limits<double>::min();
	case clear:
		ts.unget(t);
		expression();
		return numeric_limits<double>::min();
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
		double resultStatement{ statement() };
		if (resultStatement != numeric_limits<double>::min())
		{
			cout << result << resultStatement << endl;
		}
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

void printHelp()
{
	std::cout << "Supported calculations:\n\t+\tAddition\n\t-\tSubtraction\n\t*\tMultiplication\n\t/\tDivision\n\t%\tModulo\n"
		<< "\tpow(a,b)\tPower\n\tsqrt(a)\tSquare Root\n"
		<< "Printing results with ';' or a new line"
		<< "Supports Braces ()\n"
		<< "Supports variable definition\n"
		<< "\tNon-Constant variables for example: # a = 12;\n"
		<< "\tConstant variables for example: # const pi = 3.14\n"
		<< "\t\"clear\" for clearing the command prompt screen\n"
		<< "\t\"quit\" for quit\n";
}

double fileInputHandler()
{
	std::string fileName;
	std::cin >> fileName;
	std::ifstream inputFile(fileName);
	if (inputFile.fail())
	{
		error("Error reading file: " + fileName + "\n");
	}
	std::string tempString;
	std::getline(inputFile, tempString);
	std::istringstream buffer(tempString);
	std::cin.rdbuf(buffer.rdbuf());
	
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) break;
		ts.unget(t);
		double resultStatement{ statement() };
		if (resultStatement != numeric_limits<double>::min())
		{
			return resultStatement;
		}
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

void fileOutputHandler()
{
}

// Works only for windows
void clearScreen()
{
	system("cls");
}

// Main function
int main()
{
	try {
		cout << "=======================================\nCalculator program (Insert \"help\" for help)\n=======================================\n";
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