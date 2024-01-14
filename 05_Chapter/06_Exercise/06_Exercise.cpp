// 06_Exercise.cpp : Write a program that converts from Celsius to Fahrenheit and from Fahrenheit to Celsius (formula in §4.3.3). Use estimation (§5.8) to see if your results are plausible.

#include <iostream>
#include <stdexcept>


double ctof(double c) // Converts Celsius to Fahrenheit 
{
	if (c < -273.15)
	{
		throw std::logic_error("Temperature below -273.15 doesn't exists!");
	}
	double f{ (9.0 / 5) * c + 32 };
	return f;
}

double ftoc(double f) // Converts Fahrenheit to Celsius
{
	if (f < -459.67)
	{
		throw std::logic_error("Temperature below -459.67 F doesn't exists!");
	}
	return 5*(f-32)/9.0;
}

int main()
{
	try
	{
		double input{ 0 }, result{};
		char conversion{};
		std::string resultUnit{};
		std::cout << "Please insert a temperature and the unit F: Fahrenheit or C: Celsius for conversion.\nFor Example 0 C or 127.5 F.\nEnter: ";
		std::cin >> input >> conversion;
		if (conversion == 'C')
		{
			resultUnit = "F";
			result = ctof(input);
		}
		else if (conversion == 'F')
		{
			resultUnit = 'C';
			result = ftoc(input);
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


