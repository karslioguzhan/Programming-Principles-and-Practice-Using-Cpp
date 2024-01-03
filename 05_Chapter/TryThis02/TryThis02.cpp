// TryThis02.cpp : Try to compile those examples and see how the compiler responds. Try thinking of a few more errors yourself, and try those.
//

#include <iostream>


// Function prototypes
int area(int length, int width);

int main()
{
	// From the book
	int x0 = arena(7);				// E0020	identifier "arena" is undefined
	int x1 = area(7);				// E0165	too few arguments in function call
	int x2 = area("seven", 2);		// E0167	argument of type "const char *" is incompatible with parameter of type "int"

	// Own errors
	std::string x3 = area(4, 4);	// E0415	no suitable constructor exists to convert from "int" to "std::basic_string<char, std::char_traits<char>, std::allocator<char>>"
	area(4, 9) = int x4;			// E0137	expression must be a modifiable lvalue & E0254	type name is not allowed
	int x5 = area(1, 2, 3];			// E0140	too many arguments in function call
}									// Sum 9 errors

