// 02_Exercise.cpp : The following program takes in a temperature value in Celsius and converts it to Kelvin. This code has many errors in it. Find the errors, list them, and correct the code.
//

#include <iostream>

double ctok(double c) // Converts Celsius to Kelvin
{
	//int k = c + 273.15; --> Logic Error because the calculation gets truncated to an int
	//return int --> false return and missing semicolon
	double k{ c + 273.15 };
	return k;
}

int main()
{
	//double c = 0; --> is ok but brace installation is type-safe
	//cin >> d; --> "d" is undefined
	//double k = ctok("c"); --> argument is incompatible with parameter of this function
	//Cout << k << '\n;' --> Cout is undefined and missing semicolon
	double c{ 0 };
	std::cin >> c;
	double k = ctok(c);
	std::cout << k << '\n;';
	return 0;
}

