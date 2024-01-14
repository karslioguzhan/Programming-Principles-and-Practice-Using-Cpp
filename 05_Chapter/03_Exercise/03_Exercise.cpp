// 03_Exercise.cpp : Absolute zero is the lowest temperature that can be reached; it is -273.15 °C or 0K. The above program even when corrected, will produce erroneous results when given a temperature below this. Place a check in the main program that will produce an error if a temperature is given below -273.15°C.
//

#include <iostream>
#include <stdexcept>

double ctok(double c) // Converts Celsius to Kelvin
{
	double k{ c + 273.15 };
	return k;
}

int main()
{
	double c{ 0 };
	try 
	{
		std::cin >> c;
		if (c < -273.15)
		{
			throw std::logic_error("Temperature below -273.15 doesn't exists!");
		}
	}
	catch (const std::logic_error e)
	{
		std::cerr << e.what();
		return -1;
	}
	
	double k = ctok(c);
	std::cout << k << '\n;';
	return 0;
}

