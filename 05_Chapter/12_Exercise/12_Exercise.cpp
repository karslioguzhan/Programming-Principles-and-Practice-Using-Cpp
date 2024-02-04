// 12_Exercise.cpp : Implement a little guessing game called (for some obscure reason) "Bulls and Cows." The program has a vector of four different integers in the range 0 to 9 (e.g., 1234 but not 1122) and it is the user's task to discover those numbers by repeated guesses.Say the number to be guessed is 1234 and the user guesses 1359; the response should be "1 bull and 1 cow" because the user got one digit(1) right and in the right position(a bull) and one digit(3) right but in the wrong position(a cow). The guessing continues until the user gets four bulls, that is, has the four digits correct and in the correct order.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

// Function prototypes
std::vector<int> numberToGuess();
int randomNumberInRange(const int offset, const int maxValue);
std::vector <int> userInputNumber();
std::stringstream getBullsAndCows(const std::vector <int>& numberToGuess, const std::vector <int>& userInputNumber);


int main()
{
	std::vector<int> seachedNumber{ numberToGuess() };
	bool allBulls{ false };
	do
	{
		std::vector<int> userInputVector(userInputNumber());
		std::string result{ getBullsAndCows(seachedNumber, userInputVector).str() };
		std::cout << result;
		allBulls = result == "4 bulls 0 cows\n";
	} while (!allBulls);
	std::cout << "You've won the game and guessed the number: ";
	std::for_each(seachedNumber.begin(), seachedNumber.end(), [](int element) {std::cout << element << " "; });
	std::cout << "\n";
}

std::vector<int> numberToGuess()
{
	std::vector<int> vectorOfFourUniqueDigits;
	// First element cannot start with a zero
	vectorOfFourUniqueDigits.push_back(randomNumberInRange(1, 9));
	// Assign rest 3 elements
	for (int numElement{ 0 }; numElement < 3; ++numElement)
	{
		int nextElement{};
		bool numberAvailable{ false };
		do
		{
			nextElement = randomNumberInRange(0, 9);
			std::vector<int>::iterator searchVector{ std::find_if(vectorOfFourUniqueDigits.begin(), vectorOfFourUniqueDigits.end(),[=](int actualElement)
				{return actualElement == nextElement; }) };
			numberAvailable = searchVector != vectorOfFourUniqueDigits.end();
		} while (numberAvailable);
		vectorOfFourUniqueDigits.push_back(nextElement);
	}


	return vectorOfFourUniqueDigits;
}

int randomNumberInRange(const int offset, const int maxValue)
{
	// Seed is current time in seconds
	std::srand(time(0));
	return (offset + (std::rand() % maxValue));
}

std::vector<int> userInputNumber()
{
	bool legitInput{ false };
	std::vector<int> userInput;
	do
	{
		std::cout << "Please enter a 4 digit number: ";
		std::string inputString;
		std::getline(std::cin, inputString);
		if (inputString.length() != 4)
		{
			std::cout << "Wrong length of Input!\n";
			continue;
		}
		userInput.clear();
		for (auto charString : inputString)
		{
			userInput.push_back(charString - '0');
		}
		// Check if range of input is legit and do not start with zero
		bool rangeCheck{ std::any_of(userInput.begin(), userInput.end(), [](int element)
			{
				if (element < 0 || element>9)
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
		bool uniqueElements{ std::unique(userInput.begin(), userInput.end()) == userInput.end() };
		if (!uniqueElements)
		{
			std::cout << "You inserted at least two same digits!\n";
			continue;
		}

		legitInput = true;
	} while (!legitInput);
	return userInput;
}

std::stringstream getBullsAndCows(const std::vector<int>& numberToGuess, const std::vector<int>& userInputNumber)
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
