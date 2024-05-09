// 01_Drill.cpp : This drill divided into subtask
/*
	1. Starting from the file calculator08buggy.cpp get the calculator to compile.
	2. Go through the entire program and add appropriate comments.
	3. As you commented, you found errors (deviously inserted especially for you to find). Fix them; they are not in the text of the book.
	4. Testing: prepare a set of inputs and use them to test the calculator. Is your list pretty complete? What should you look for? Include negative values, 0, very small, very large, and "silly" inputs.
	5. Do the testing and fix any bugs that you missed when you commented.
	6. Add a predefined name k meaning 1000
*/

/*
	4. Exercise test-set
		-4*3; --> Negative number
		0+1; --> Zeros
		10/0 --> Dividing with zero
		9999999999999999999*9999999999999999999; --> Very large number
		1/9999999999999999999 --> Very small number
		a+1; --> "silly" inputs
		((5+5) --> Missing brackets
*/

#include "std_lib_facilities.h"

// Token as struct
struct Token {
	// Member variables of Struct
	char kind;
	double value;
	string name;
	// All Token constructors with initializer list
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string name) :kind(ch), name(name), value(0) { } // 1. Error: Missing constructor
};

// Token_stream class
class Token_stream {
	// Member variables
	bool full;
	Token buffer;
public:
	// Default Constructor (Not sure if 0 is legit
	Token_stream() :full(false), buffer(0) { }

	// Method prototype for getting Tokens
	Token get();
	// Method for assigning tokens to buffer
	void unget(Token t) { buffer = t; full = true; }
	// Method prototype for ignoring inputs
	void ignore(char);
};

// Global variables with arbitrary values
const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char k = 'k';

// Getter-Method for Tokens
Token Token_stream::get()
{
	// Returning actual Token if buffer is full
	if (full) { full = false; return buffer; }
	// Read input as character
	char ch{};
	cin >> ch;
	// Switch for determining token type
	switch (ch) {
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ';':
		case '=':
			// non numeric characters
			return Token(ch);
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			// Return numeric values
			cin.unget();
			double val;
			cin >> val;
			return Token(number, val);
		}
	default:
		// Getting strings from input
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch; // Logical error -> String was not concatenated right
			cin.unget();
			if (s == "let") return Token(let);
			if (s == "Q") return Token(quit);
			if (s.size() == 1 && s[0] == k) return Token(number, 1000);
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
	Variable(string n, double v) :name(n), value(v) { }
};

// Initialize empty global vector
vector<Variable> names;

// Get string values
double get_value(string s)
{
	// Iterate through vector and check if input string is in names
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

// Setter for names with string and value
void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

// Check if string is declared
bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
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
		return get_value(t.name);
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
double declaration()
{
	Token t = ts.get();
	// kind name
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

// Handle statements
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
		// distincition between declaration and expression
	case let:
		return declaration();
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