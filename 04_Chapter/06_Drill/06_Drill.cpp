// 06_Drill.cpp : Now change the body of the loop so that it reads just one double each time around. 
// Define two variables to keep track of which is the smallest and which is the largest value you have seen so far. 
// Each time through the loop write out the value entered. 
// If it’s the smallest so far, write the smallest so far after the number. 
// If it is the largest so far, write the largest so far after the number.

#include <iostream>

int main()
{
	std::cout << "Printing doubles until | is inserted\n";
	bool firstRun{ true };
	double input{}, smallestDouble{}, biggestDouble{};
	std::cout << "Please enter one double: ";
	while (std::cin >> input)
	{
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

		std::cout << "You entered the double: " << input << std::endl;

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
