// 09_Drill.cpp :
// Keep track of the sum of values entered (as well as the smallest and the largest) and the number of values entered. When the loop ends, print the smallest, the largest, the number of values, and the sum of values. Note that to keep the sum, you have to decide on a unit to use for that sum; use meters.
#include <iostream>
#include <map>



int main()
{
	std::cout << "Printing doubles until | is inserted\n";
	std::map<std::string, double> conversion
	{
		{"cm", 0.01},
		{"m", 1},
		{"in", 0.0254},
		{"ft", 0.3048}
	};

	bool firstRun{ true };
	double input{}, smallestDouble{}, biggestDouble{}, sumInput{};
	int numOfInputs{};
	std::string unit{};
	std::cout << "Please enter one double followed by an unit (cm, m, in, ft --> Example 1.9cm): ";
	while (std::cin >> input && std::cin >> unit)
	{
		if (conversion.find(unit) == conversion.end())
		{
			std::cout << "Illegal unit";
			return 1;
		}

		input *= conversion.at(unit);
		sumInput += input;
		++numOfInputs;

		if (firstRun)
		{
			smallestDouble = input;
			biggestDouble = input;
			firstRun = false;
		}

		if (input == '|')
		{
			std::cout << "Terminating the program\n";
			break;
		}

		std::cout << "You entered the double: " << input << " in m" << std::endl;

		if (input < smallestDouble)
		{
			smallestDouble = input;
		}
		else if (input > biggestDouble)
		{
			biggestDouble = input;
		}

		if (biggestDouble - smallestDouble < 1.0 / 100)
		{
			std::cout << "The smallest and biggest doubles are almost equal!\n";
		}
		std::cout << "Please enter one double: ";
	}
	std::cout << "====================================================\n";
	std::cout << "You have entered " << numOfInputs << " values\n";
	std::cout << "The sum of all entered values is: " << sumInput << "m\n";
	std::cout << "The smallest number was: " << smallestDouble << "m\n";
	std::cout << "The biggest number was: " << biggestDouble << "m\n";
	return 0;

}