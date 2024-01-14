// 05_Exercise.cpp : Add to the program so that it can also convert from Kelvin to Celsius.

#include <iostream>
#include <stdexcept>

double ctok(double c) // Converts Celsius to Kelvin 
{
	if (c < -273.15)
	{
		throw std::logic_error("Temperature below -273.15 doesn't exists!");
	}
	double k{ c + 273.15 };
	return k;
}

double ktoc(double k) // Converts Kelvin to Celsius
{
	if (k < 0)
	{
		throw std::logic_error("Temperature below 0K doesn't exists!");
	}
	return k - 273.15;
}

int main()
{
	try
	{
		double input{ 0 }, result{};
		char conversion{};
		std::string resultUnit{};
		std::cout << "Please insert a temperature and the unit K: Kelvin or C: Celsius for conversion.\nFor Example 0 C or 127.5 K.\nEnter: ";
		std::cin >> input >> conversion;
		if (conversion == 'C')
		{
			resultUnit = "K";
			result = ctok(input);
		}
		else if (conversion == 'K')
		{
			resultUnit = 'C';
			result = ktoc(input);
		}
		else
		{
			throw std::logic_error("Conversion is not supported!\n");
		}

		std::cout << "Result: " << result << " " << resultUnit << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
		return -1;
	}
	return 0;
}
