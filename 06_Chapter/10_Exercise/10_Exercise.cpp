// 10_Exercise.cpp : A permutation is an ordered subset of a set. For example, say you wanted to pick a combination to a vault. There are 60 possible numbers, and you need three different number for the combination. There are P(60,3) permutations for the combination, where P is defined by the formula:
//      P (a,b) = a!/(a-b)!
// where ! is used as a suffix factorial operator. For example, 4! is 4*3*2*1. Combinations are similar to permutations, except that the order of the objects doesn't matter. For example, if you were making a "banana split" sundae and wished to use three different flavors of ice cream out of five that you had, you wouldn't care if you used a scoop of vanilla at the beginning or the end; you would still have used vanilla. The formula for combination is
//      C(a,b) = P(a,b)/b!
// Design a program that asks users for two numbers, asks them whether they want to calculate permutations or combinations, and prints out the results. This will have several parts. Do an analysis of the above requirements. Write exactly what the program will have to do. Then, go into the design phase. Write pseudo code for the program, and break it into sub-components. This program should have error checking. Make sure that all erroneous inputs will generate good error messages.

/*
	First task: Analysis
		- Ask user input if Combination or Permutation
		- Only valid for integers and a > b
		- Implement function for factorial
		- Implement function for Permutation
		- Implement function for Combination
		- Print results
*/

/*
	Second task: Design
		- Print Menu and greetings
		- Get userinput for selection of Permutation or Combination
		- Switch case inside do while loop with error checking
		- Print results with suitable name
*/

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <boost/math/special_functions/factorials.hpp>

// Function prototypes
std::stringstream printMenu();
bool selectCalculation(char& userSelection);
bool getParameters(int& A, int& B);
uint64_t calculatePermutation(const int A, const int B);
uint64_t calculateCombination(const uint64_t permutationValue, const int B);

int main()
{
	std::cout << printMenu().str();
	bool validInput{};
	// Get calculation method
	char selection{};
	do
	{
		std::cout << "Please select calculation: ";
		validInput = selectCalculation(selection);
	} while (!validInput);
	// Get both calculation Parameters
	int A{}, B{};
	validInput = false;
	do
	{
		std::cout << "Enter A and B Integers separated with a whitespace, for example 3 1\n";
		std::cout << "Please enter: ";
		validInput = getParameters(A, B);
	} while (!validInput);

	uint64_t permutationValue{ calculatePermutation(A, B) };
	switch (selection)
	{
	case 'P':
		std::cout << "P(" << A << ", " << B << ") = " << permutationValue << "\n";
		break;
	case 'C':
		std::cout << "C(" << A << ", " << B << ") = " << calculateCombination(permutationValue, B) << "\n";
		break;
	}


	return 0;
}

std::stringstream printMenu()
{
	std::stringstream menu;
	menu << "=======================================\n";
	menu << "Combination or Permutation Calculator\n";
	menu << "=======================================\n";
	menu << "Possible inputs: P = Permutation or C = Combination\n";
	return menu;
}

bool selectCalculation(char& userSelection)
{
	std::string tempInput;
	std::getline(std::cin, tempInput);
	// Check if string length is right
	if (tempInput.size() != 1)
	{
		std::cout << "ERROR: Wrong length of selection!\n";
		return false;
	}
	// Check if selection is P or C
	if (!(std::toupper(tempInput.at(0)) == 'P') && !(std::toupper(tempInput.at(0)) == 'C'))
	{
		std::cout << "ERROR: Not selected P or C!\n";
		return false;
	}
	userSelection = std::toupper(tempInput.at(0));
	return true;
}

bool getParameters(int& A, int& B)
{
	std::string inputString;
	std::getline(std::cin, inputString);
	std::istringstream stringStreamInput(inputString);
	std::vector<std::string> inputs;
	do
	{
		std::string tempElement;
		stringStreamInput >> tempElement;
		inputs.push_back(tempElement);
	} while (stringStreamInput);
	inputs.pop_back();
	if (inputs.size() != 2)
	{
		std::cout << "ERROR: Not inserted only two arguments!\n";
		return false;
	}
	// Check if input are integers
	try
	{
		int tempA{ std::stoi(inputs.at(0)) };
		int tempB{ std::stoi(inputs.at(1)) };
		if (tempA != std::stod(inputs.at(0)) || tempB != std::stod(inputs.at(1)))
		{
			throw std::invalid_argument("Input is not an integer!\n");
		}
		// Assign if valid values
		A = tempA;
		B = tempB;
	}
	catch (...)
	{
		std::cout << "ERROR: One of the values is not an int!\n";
		return false;
	}
	// Check if A is greater if B
	if (A < B || A < 0 || B < 0)
	{
		std::cout << "ERROR: Complex calculation is not supported. A must be greater than B\n";
		return false;
	}

	return true;
}

uint64_t calculatePermutation(const int A, const int B)
{
	return static_cast<uint64_t>(boost::math::factorial<double>(A)/ boost::math::factorial<double>(A-B));
}

uint64_t calculateCombination(const uint64_t permutationValue, const int B)
{
	return static_cast<uint64_t>(permutationValue / boost::math::factorial<double>(B));
}

