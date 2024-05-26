// 03_Drill.cpp : Write a program using a single file containing three namespaces X, Y and Z so that the following main() works correctly.
// Each namespace need to define a variable called var and a function called print() that outputs the appropiate var using cout.

#include <iostream>
#include "03_Drill.h"


namespace X
{
	int var;
	void print()
	{
		std::cout << "Value of var from X namespace is " << var << "\n";
	}
}

namespace Y
{
	int var;
	void print()
	{
		std::cout << "Value of var from Y namespace is " << var << "\n";
	}
}

namespace Z
{
	int var;
	void print()
	{
		std::cout << "Value of var from Z namespace is " << var << "\n";
	}
}

int main()
{
	// Copied from textbook
	X::var = 7;
	X::print(); // print X's var

	using namespace Y; // makes all functions/variable visible from namespace
	var = 9;
	print(); // print Y's var

	{
		using Z::var; // make specific variable visible from Z
		using Z::print;
		var = 11;
		print(); // print Z's var
	}
	print(); // print Y's var
	X::print(); // print X's var



}

