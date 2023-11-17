// 05_Drill.cpp : Change the program so that it writes out the numbers are almost equal 
// after writing out which is the larger and the smaller if the two numbers differ by less than 1.0/100.

#include <iostream>

int main()
{
	std::cout << "Printing two doubles until | is inserted\n";
	bool isTerminated{ false };
	double input1{}, input2{};
	std::cout << "Please enter two doubles with an whitespace: ";
	while (std::cin >> input1 && std::cin >> input2)
	{
		double largerInput{}, smallerInput{};
		if (input1 == '|' || input2 == '|')
		{
			std::cout << "Terminating the program\n";
			break;
		}
		if (input1 < input2)
		{
			std::cout << "The smaller value is: " << input1 << std::endl;
			std::cout << "The larger value is: " << input2 << std::endl;
			largerInput = input2;
			smallerInput = input1;
		}
		else if (input1 == input2)
		{
			std::cout << "Numbers are equal\n";
		}
		else
		{
			std::cout << "The smaller value is: " << input2 << std::endl;
			std::cout << "The larger value is: " << input1 << std::endl;
			largerInput = input1;
			smallerInput = input2;
		}
		if (largerInput- smallerInput < 1.0/100)
		{
			std::cout << "The numbers are almost equal!\n";
		}
		std::cout << "Please enter two doubles with an whitespace: ";
	}
	return 0;

}
