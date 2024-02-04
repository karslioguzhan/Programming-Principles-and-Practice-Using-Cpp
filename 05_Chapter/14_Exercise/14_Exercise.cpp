// 14_Exercise.cpp : Read (day-of-the-week, value) pairs from standard input. For example
//  Tuesday 23 Friday 56 Tuesday -3 Thursday 99
// Collect all the values for each day of the week in a vector<int>. Write out the values of the seven day-of-the-week vectors. Print out the sum of values in each vector. Ignore illegal days of the week, such as Funday, but accept common synonyms such as Mon and monday. Write out the number of rejected values.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string getUserInput();

int main()
{
	std::cout << "Enter as many \"day-of-the-week, value\" pairs as you like.\n For example Tuesday 23 Friday 56\n Please enter: ";
	std::string userInput{ getUserInput() };
	std::vector<int> digitOfInput;
	std::vector<std::string> nameOfInput;

}

std::string getUserInput()
{

	std::string userInput{};
	bool legitInput{ false };
	do
	{
		std::getline(std::cin, userInput);
		int numOfSpaces{ static_cast<int>( std::count(userInput.begin(), userInput.end(), ' ')) };
		if (numOfSpaces % 2 == 1)
		{
			legitInput = true;
		}
		else
		{
			std::cout << "You don't enter a correct pair!\n Enter again: ";
		}
	} while (!legitInput);

	return userInput;
}
