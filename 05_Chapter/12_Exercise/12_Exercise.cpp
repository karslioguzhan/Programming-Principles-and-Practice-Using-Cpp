// 12_Exercise.cpp : Implement a little guessing game called (for some obscure reason) "Bulls and Cows." The program has a vector of four different integers in the range 0 to 9 (e.g., 1234 but not 1122) and it is the user's task to discover those numbers by repeated guesses.Say the number to be guessed is 1234 and the user guesses 1359; the response should be "1 bull and 1 cow" because the user got one digit(1) right and in the right position(a bull) and one digit(3) right but in the wrong position(a cow). The guessing continues until the user gets four bulls, that is, has the four digits correct and in the correct order.

#include <iostream>
#include <vector>
#include <algorithm>

// Function prototypes
std::vector<int> numberToGuess();
int randomNumberInRange(const int offset, const int maxValue);

int main()
{
	std::vector<int> seacherNumber{ numberToGuess() };
	std::cout << "hello";
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
