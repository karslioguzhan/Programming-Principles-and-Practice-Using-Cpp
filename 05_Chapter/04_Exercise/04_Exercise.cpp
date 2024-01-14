// 04_Exercise.cpp : Do exercise 3 again, but this time handle the error inside ctok().
//

#include <iostream>
#include <stdexcept>

double ctok(double c) // Converts Celsius to Kelvin
{
	if (c < 273.15)
	{
		throw std::logic_error("Temperature below -273.15 doesn't exists!");
	}
	double k{ c + 273.15 };
	return k;
}

int main()
{
	try
	{
		double c{ 0 };
		std::cin >> c;
		double k = ctok(c);
		std::cout << k << '\n;';
	}
	catch (std::exception &e)
	{
		std::cerr << e.what();
		return -1;
	}
	return 0;
}

