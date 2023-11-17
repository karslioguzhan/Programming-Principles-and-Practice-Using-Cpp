// 04_Drill.cpp : Change the program so that it uses doubles instead of ints.
//
#include <iostream>

int main()
{
	std::cout << "Printing two doubles until | is inserted\n";
	bool isTerminated{ false };
	double input1{}, input2{};
	std::cout << "Please enter two doubles with an whitespace: ";
	while (std::cin >> input1 && std::cin >> input2)
	{
		if (input1 == '|' || input2 == '|')
		{
			std::cout << "Terminating the program\n";
			break;
		}
		if (input1 < input2)
		{
			std::cout << "The smaller value is: " << input1 << std::endl;
			std::cout << "The larger value is: " << input2 << std::endl;
		}
		else if (input1 == input2)
		{
			std::cout << "Numbers are equal\n";
		}
		else
		{
			std::cout << "The smaller value is: " << input2 << std::endl;
			std::cout << "The larger value is: " << input1 << std::endl;
		}
		std::cout << "Please enter two doubles with an whitespace: ";
	}
	return 0;

}
