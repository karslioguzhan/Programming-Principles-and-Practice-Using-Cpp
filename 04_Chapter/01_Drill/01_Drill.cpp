// 01_Drill.cpp : Write a program that consists of a while-loop that 
// (each time around the loop) reads in two ints and then prints them. 
// Exit the program when a terminating '|' is entered.

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
		std::cout << input1 << " " << input2 << std::endl;
		std::cout << "Please enter two integers with an whitespace: ";
	}
	return 0;

}
