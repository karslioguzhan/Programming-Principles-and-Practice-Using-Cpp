#include "Token_stream.h"

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
	case ',':
	case let:
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
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch; // Logical error -> String was not concatenated right
			cin.unget();
			if (s == "#") return Token(let);
			if (s == "exit") return Token(quit);
			if (s.size() == 1 && s[0] == k) return Token(number, 1000);
			if (s == squareRoot) return Token(squareRootVal);
			if (s == powName) return Token(powVal);
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

Token_stream* Token_stream::GetInstance()
{
	if (referenceTokenStream == nullptr) {
		referenceTokenStream = new Token_stream();
	}
	return referenceTokenStream;
}
