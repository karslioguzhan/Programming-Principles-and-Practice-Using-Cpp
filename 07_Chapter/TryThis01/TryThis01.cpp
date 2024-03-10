// TryThis01.cpp : Feed a few such "problematic" expressions to the calculator and try to figure out in how many ways you can get it to misbehave. Can you get it to crash, that is, to get it past our error handling and give a machine error? We don't think you can. Can you get it to exit without a useful error message? You can.

#include "std_lib_facilities.h"

/*
    Tested inputs
        �=              --> Bad token
        (1+1))=         --> error: primary expected
        a+1             --> Bad token
        1/0             --> error: divide by zero

      1 / 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001      --> error: divide by zero
	  9999! = 0			--> No error handling (Overflow)
	  -2+3				--> error: primary expected
*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// lass Token{ -> First Error: lass is undefined and should be class
class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

//Token get() --> Error 4 False declaration for function. Should be Token_stream::
Token Token_stream::get()
{
	if (full) {       // do we already have a Token ready?
		// remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case '=':    // for "print"
	case 'x':    // for "quit"
	case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/': case '!':
		if (ch == '{')
		{
			return Token('(');
		}
		if (ch == '}')
		{
			return Token(')');
		}
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': // 3. logic error:  Missing 8 
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token('8', val);   // let '8' represent "a number"
	}
	default:
		error("Bad token");
	}
}




//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
	Token t = ts.get();
	//double actualValueOfToken{ t.value };
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
	{
		double d = expression();
		t = ts.get();
		//if (t.kind != ')') error("')' expected); Second error --> Missing "
		if (t.kind != ')')
		{
			error("')' expected");
		}
		return d;
	}
	case '8':            // we use '8' to represent a number
		return t.value;  // return the number's value
	default:
		error("primary expected");
	}
}

double factorial()
{
	double left = primary();
	Token t = ts.get();
	while (true)
	{
		switch (t.kind)
		{
		case '!':
		{
			int x = left;
			if (x == 0) { x = 1; }
			else if (x < 0)
			{
				error("Factorial must be a positive integer"); keep_window_open();
			}
			else for (int y = x - 1; y > 0; --y)  // So this is where the error was
			{
				x = x * y;
			}
			t = ts.get();
			double left = x;
			ts.putback(t);
			return left;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
	double left = factorial();
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= factorial();
			t = ts.get();
			break;
			// 3. Logic error: Missing break 
		case '/':
		{
			double d = factorial();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
	//double left = term(;      // read and evaluate a Term --> Error 3. Missing brace )
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left += term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------

int main()
try
{
	// Greeting menu
	cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers.\n";
	cout << "Possible Operations\n\t'+' -> Addition\n\t'-' -> Subtraction\n\t'*' -> Multiplication\n\t'/' -> Division\n\t'x' -> Terminate program\nPlease enter: ";
	// 5. Error missing assignment of val;
	double val{};
	while (cin) {
		Token t = ts.get();
		if (t.kind == 'x') break; // 'x' for quit
		if (t.kind == '=')        // '=' for "print now"
		{
			cout << val << '\n';
		}
		else
		{
			ts.putback(t);
			// 1. logic Error. Only do calculation if not ";" and "q"!
			val = expression();
		}
	}
	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}


//------------------------------------------------------------------------------

