// 08_Exercise.cpp : Redo the "Bulls and Cows" game from exercise 12 in Chapter 5 to use four letters rather than four digits.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cctype>

// Function prototypes
std::vector<char> stringToGuess();
char randomNumberInRange(const int offset, const int maxValue);
std::vector <char> userInputNumber();
std::stringstream getBullsAndCows(const std::vector <char>& numberToGuess, const std::vector <char>& userInputNumber);


int main()
{
	std::vector<char> seachedString{ stringToGuess() };

	bool allBulls{ false };
	do
	{
		std::vector<char> userInputVector(userInputNumber());
		std::string result{ getBullsAndCows(seachedString, userInputVector).str() };
		std::cout << result;
		allBulls = result == "4 bulls 0 cows\n";
	} while (!allBulls);
	std::cout << "You've won the game and guessed the string: ";
	std::for_each(seachedString.begin(), seachedString.end(), [](char element) {std::cout << element << " "; });
	std::cout << "\n";
	return 0;
}

std::vector<char> stringToGuess()
{
	std::vector<char> vectorOfFourUniqueChars;
	// First element cannot start with a zero
	vectorOfFourUniqueChars.push_back(randomNumberInRange(65, 26));
	// Assign rest 3 elements
	for (int numElement{ 0 }; numElement < 3; ++numElement)
	{
		char nextElement{};
		bool numberAvailable{ false };
		do
		{
			nextElement = randomNumberInRange(65, 26);
			std::vector<char>::iterator searchVector{ std::find_if(vectorOfFourUniqueChars.begin(), vectorOfFourUniqueChars.end(),[=](int actualElement)
				{return actualElement == nextElement; }) };
			numberAvailable = searchVector != vectorOfFourUniqueChars.end();
		} while (numberAvailable);
		vectorOfFourUniqueChars.push_back(nextElement);
	}


	return vectorOfFourUniqueChars;
}

char randomNumberInRange(const int offset, const int range)
{
	// Seed is current time in seconds
	std::srand(time(0));
	return (offset + (std::rand() % range));
}

std::vector<char> userInputNumber()
{
	bool legitInput{ false };
	std::vector<char> userInput;
	do
	{
		std::cout << "Please enter a 4 letters: ";
		std::string inputString;
		std::getline(std::cin, inputString);
		if (inputString.length() != 4)
		{
			std::cout << "Wrong length of Input!\n";
			continue;
		}
		userInput.clear();
		// Format all in upper case
		for (auto charString : inputString)
		{
			userInput.push_back(std::toupper(charString));
		}
		// Check if range of input is legit and do not start with zero
		bool rangeCheck{ std::any_of(userInput.begin(), userInput.end(), [](int element)
			{
				if (element < 65 || element>90)
				{
					return true;
				}
				return false;
			}
			) };
		if (rangeCheck)
		{
			std::cout << "You've entered a digit less than 0 or greater than 9!\n";
			continue;
		}
		// Check if all elements are unique
		bool isUnique{ true };
		for (int numChar{}; numChar < userInput.size(); ++numChar)
		{
			char checkedChar{ userInput.at(numChar) };
			for (int nextChar{ numChar + 1 }; nextChar < userInput.size(); ++nextChar)
			{
				if (checkedChar == userInput.at(nextChar))
				{
					isUnique = false;
				}
			}
		}
		if (!isUnique)
		{
			std::cout << "You inserted at least two same digits!\n";
			continue;
		}

		legitInput = true;
	} while (!legitInput);
	return userInput;
}

std::stringstream getBullsAndCows(const std::vector<char>& numberToGuess, const std::vector<char>& userInputNumber)
{
	// Calculate Bulls and Cows
	int numBulls{};
	int numCows{};
	for (int numElement{}; numElement < numberToGuess.size(); ++numElement)
	{
		int actualSearchedInt{ numberToGuess.at(numElement) };
		if (userInputNumber.at(numElement) == actualSearchedInt)
		{
			++numBulls;
			continue;
		}
		for (int numElementUser{}; numElementUser < numberToGuess.size(); ++numElementUser)
		{
			if (actualSearchedInt == userInputNumber.at(numElementUser))
			{
				++numCows;
			}
		}
	}

	std::stringstream answerStringStream;
	answerStringStream << numBulls << " bulls " << numCows << " cows\n";
	return answerStringStream;
}
