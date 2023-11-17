// 03_Drill.cpp : Augment the program so that it writes the line the numbers are equal (only) if they are equal.
//
#include <iostream>

int main()
{
	std::cout << "Printing two integers until | is inserted\n";
	bool isTerminated{ false };
	int input1{}, input2{};
	std::cout << "Please enter two integers with an whitespace: ";
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
		std::cout << "Please enter two integers with an whitespace: ";
	}
	return 0;

}
