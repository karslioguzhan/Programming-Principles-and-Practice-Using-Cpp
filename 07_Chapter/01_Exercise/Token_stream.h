#pragma once
#include "Token.h"
#include "GlobalVariables.h"
// Token_stream class
class Token_stream {
public:
	// Member variables
	bool full;
	Token buffer;
	// Method prototype for getting Tokens
	Token get();
	// Method for assigning tokens to buffer
	void unget(Token t) { buffer = t; full = true; }
	// Method prototype for ignoring inputs
	void ignore(char);
	static Token_stream* GetInstance();
protected:
	// Default Constructor (Not sure if 0 is legit
	Token_stream() :full(false), buffer(0) { }
	static Token_stream* referenceTokenStream;

};