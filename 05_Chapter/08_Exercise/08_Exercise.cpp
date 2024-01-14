// 08_Exercise.cpp : Write a program that reads and stores a series of integers and then computes the sum of the first N integers.
// First ask for N, then read the values into a vector, then calculate the sum of the first N values. 
// For example:
//  "Please enter the number of values you want to sum:"
// 3
// "Please enter some integers (press '|' to stop):"
// 12 23 13 24 15 |
// "The sum of the first 3 numbers (12 23 13) is 48."
// Handle all inputs. For example, make sure to give an error message if the user asks for a sum of more numbers than there are in the vector.

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <vector>

int getNumOfElements();
std::vector<int> getElements();
void checkIfRequestIsLegit(int numOfElements, int lengthVector);
int sumOfElements(int sumLength, std::vector<int> elements);
std::stringstream printResult(int sum, int sumLength, std::vector<int> elements);


int main()
{
	try
	{
		std::cout << "Please enter the number of values you want to sum: ";
		int inputN{ getNumOfElements() };
		std::cout << "Please enter some integers (press '|' to stop): ";
		std::vector<int> elements{ getElements() };
		checkIfRequestIsLegit(inputN, elements.size());
		int sum{ sumOfElements(inputN, elements) };
		std::cout << printResult(sum, inputN, elements).str();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
		return -1;
	}
	return 0;
}

int getNumOfElements()
{
	std::string input;
	std::getline(std::cin, input);
	// Check if only one argument is passed
	if (std::count(input.begin(), input.end(), ' ') + 1 != 1)
	{
		throw std::logic_error("Number of arguments are not 1!\n");
	}
	return std::stoi(input);
}

std::vector<int> getElements()
{
	std::string input;
	std::getline(std::cin, input);
	std::istringstream ssInput(input);
	std::string inputElement;
	std::vector<int> result;
	while (ssInput >> inputElement)
	{
		if (inputElement == "|")
		{
			break;
		}
		result.push_back(std::stoi(inputElement));
	}
	return result;
}

void checkIfRequestIsLegit(int numOfElements, int lengthVector)
{
	if (numOfElements > lengthVector)
	{
		throw std::logic_error("You demanded the sum of more numbers than inserted!\n");
	}
}

int sumOfElements(int sumLength, std::vector<int> elements)
{
	int sum{};
	for (int numElem{}; numElem < sumLength; ++numElem)
	{
		sum += elements.at(numElem);
	}
	return sum;
}

std::stringstream printResult(int sum, int sumLength, std::vector<int> elements)
{
	// "The sum of the first 3 numbers (12 23 13) is 48."
	std::stringstream resultStream;
	resultStream << "The sum of the first " << sumLength << " numbers (";
	for (int numElem{}; numElem < sumLength; ++numElem)
	{
		resultStream << elements.at(numElem);
		if (numElem+1 != sumLength)
		{
			resultStream << " ";
		}
	}
	resultStream << ") is " << sum << ".\n";
	return resultStream;
}
