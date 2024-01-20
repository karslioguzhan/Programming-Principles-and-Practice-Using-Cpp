// 10_Exercise.cpp : Modify the exercise 8 to use double instead of int. Also,make a vector of doubles containing the N - 1 differences between adjacent values and write out that vector of differences.

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <vector>

int getNumOfElements();
std::vector<double> getElements();
void checkIfRequestIsLegit(int numOfElements, int lengthVector);
double sumOfElements(int sumLength, std::vector<double> elements);
std::vector<double> adjacentDifferences(std::vector<double> elements);
std::stringstream printResult(int sum, int sumLength, std::vector<double> elements, std::vector<double> diff);



int main()
{
	try
	{
		std::cout << "Please enter the number of values you want to sum: ";
		int inputN{ getNumOfElements() };
		std::cout << "Please enter some integers (press '|' to stop): ";
		std::vector<double> elements{ getElements() };
		checkIfRequestIsLegit(inputN, static_cast<int>(elements.size()));
		double sum{ sumOfElements(inputN, elements) };
		std::vector<double> adjacentDifference{ adjacentDifferences(elements) };
		std::cout << printResult(sum, inputN, elements, adjacentDifference).str();
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

std::vector<double> getElements()
{
	std::string input;
	std::getline(std::cin, input);
	std::istringstream ssInput(input);
	std::string inputElement;
	std::vector<double> result;
	while (ssInput >> inputElement)
	{
		if (inputElement == "|")
		{
			break;
		}
		result.push_back(std::stod(inputElement));
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

double sumOfElements(int sumLength, std::vector<double> elements)
{
	double sum{};
	for (int numElem{}; numElem < sumLength; ++numElem)
	{
		sum += elements.at(numElem);
	}
	return sum;
}

std::vector<double> adjacentDifferences(std::vector<double> elements)
{
	const int sizeVector{ static_cast<int> (elements.size() - 1) };
	std::vector<double> adjacentDiff;
	for (int numElement{ 0 }; numElement < sizeVector; ++numElement)
	{
		adjacentDiff.push_back(elements.at(numElement + 1) - elements.at(numElement));
	}

	return adjacentDiff;
}

std::stringstream printResult(int sum, int sumLength, std::vector<double> elements, std::vector<double> diff)
{
	// "The sum of the first 3 numbers (12 23 13) is 48."
	std::stringstream resultStream;
	resultStream << "The sum of the first " << sumLength << " numbers (";
	for (int numElem{}; numElem < sumLength; ++numElem)
	{
		resultStream << elements.at(numElem);
		if (numElem + 1 != sumLength)
		{
			resultStream << " ";
		}
	}
	resultStream << ") is " << sum << ".\n";

	resultStream << "The adjacent differences are:\n";
	for (auto numDiff : diff)
	{
		resultStream << numDiff << " ";
	}
	resultStream << "\n";
	return resultStream;
}

