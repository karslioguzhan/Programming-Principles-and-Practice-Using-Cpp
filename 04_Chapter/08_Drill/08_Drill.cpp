// 08_Drill.cpp : Reject values without units or with “illegal” representations of units, such as y, yard, meter, km, and gallons.

#include <iostream>
#include <map>

int main()
{
	std::cout << "Printing doubles until | is inserted\n";
	std::map<std::string, double> conversion
	{
		{"cm", 1},
		{"m", 100},
		{"in", 2.54},
		{"ft", 12 * 2.54}
	};

	bool firstRun{ true };
	double input{}, smallestDouble{}, biggestDouble{};
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

		std::cout << "You entered the double: " << input << " in cm" << std::endl;

		if (input < smallestDouble)
		{
			smallestDouble = input;
			std::cout << "And it is the smallest double so far\n";
		}
		else if (input > biggestDouble)
		{
			biggestDouble = input;
			std::cout << "And it is the biggest double so far\n";
		}

		if (biggestDouble - smallestDouble < 1.0 / 100)
		{
			std::cout << "The smallest and biggest doubles are almost equal!\n";
		}
		std::cout << "Please enter one double: ";
	}
	return 0;

}
