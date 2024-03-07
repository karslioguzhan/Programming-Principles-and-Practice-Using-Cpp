// 09_Exercise.cpp : Write a program that reads digits and composes them into integers. For example, 123 is read as the characters 1, 2, and 3. The program should output 123 is 1 hundred and 2 tens and 3 ones. The number should be output as an int value. Handle numbers with one, two, three or four digits. Hint: To get the integer value 4 from the character '5' subtract '0' that is, '5'-'0' == 5.
//

#include <iostream>
#include <string>

int main()
{
	bool inputValid{ false };
	std::string inputNumber;
	// Get valid input
	do
	{
		std::cout << "Please insert a four digit number: ";
		std::string tempString;
		std::getline(std::cin, tempString);
		if (tempString.size() > 4)
		{
			std::cout << "Wrong length!\n";
			continue;
		}
		bool legalChars{ true };
		for (auto charElem : tempString)
		{
			// Check if legit value
			if (charElem < 48 || charElem > 57)
			{
				std::cout << "Entered a non numeric value\n";
				legalChars = false;
				break;
			}
		}
		if (!legalChars)
		{
			continue;
		}
		inputNumber = tempString;
		inputValid = true;
	} while (!inputValid);


	// Print result
	std::cout << inputNumber << " is ";
	switch (inputNumber.size())
	{
	case 4:
		std::cout << inputNumber.at(0) << " thousand " << inputNumber.at(1) << " hundred " << inputNumber.at(2) << " tens " << inputNumber.at(3) << " ones\n";		
		break;
	case 3:
		std::cout << inputNumber.at(0) << " hundred " << inputNumber.at(1) << " tens " << inputNumber.at(2) << " ones\n";
		break;
	case 2:
		std::cout << inputNumber.at(0) << " tens " << inputNumber.at(1) << " ones\n";
		break;
	case 1:
		std::cout << inputNumber.at(0) << " ones\n";
		break;
	}
	std::cout << "\n";
	return 0;
}

