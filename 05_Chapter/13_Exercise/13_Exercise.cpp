// 13_Exercise.cpp : The program is a bit tedious because the answer is hard-coded into the program. Make a version where the user can play repeatedly (without stopping and restarting the program) and each game has a new set of four digits. You can get four random digits by calling the random number generator randint(10) from std_lib_facilities.h four times. You will note that if you run that program repeatedly, it will pick the same sequence of four digits each time you start the program. To avoid that, ask the user to enter a number (any numbeR) and call srand(n) where n is the number the user entered before calling randint(10). such an n is called a seed and different sequences of random numbers.

// Note: The version i've implemented in exercise 12 doesn't have this issue. Only a game loop is added!

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
	bool gameLoop{ false };
	do {
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
		std::cout << "Do you want to play a new round (y: yes or n: no): ";
		char gameContinue{};
		std::cin >> gameContinue;
		if (gameContinue == 'n')
		{
			gameLoop = true;
		}

	} while (!gameLoop);
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
