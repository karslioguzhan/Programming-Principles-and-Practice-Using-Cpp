// 11_Exercise.cpp : Write a function that finds the smallest and the largest element of a vector argument and also computes the mean and the median. 
// Do not use global variables.Either return a struct containing the results or pass them back through 
// reference arguments.Which of the two ways of returning several result values do you prefer and why ?

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

void statisticCalc(const std::vector<double>& inputVector, std::vector<double>& outputVector);
std::stringstream output(std::string label, const std::vector<double>& resultVector);
int main()
{
	std::vector<double> inputVector1{ 0, 40, 10, 50 };
	std::vector<double> inputVector2{ 0, 30, 10, 50 , 25 };
	std::vector<double> result1, result2;
	statisticCalc(inputVector1, result1);
	statisticCalc(inputVector2, result2);
	std::cout << output("vector1", result1).str();
	std::cout << output("vector2", result2).str();

}

void statisticCalc(const std::vector<double>& inputVector, std::vector<double> &outputVector)
{
	// Error-handling
	if (inputVector.empty())
	{
		return;
	}
	// Sort vector
	std::vector<double> tempVector{ inputVector };
	std::sort(tempVector.begin(), tempVector.end());
	// Get minumum element
	outputVector.push_back(*tempVector.begin());

	// Median calculation
	int size{ static_cast<int>(tempVector.size())};
	double median{};
	if (size % 2 == 0)
	{
		median = static_cast<double> (tempVector.at((size - 1) / 2) + tempVector.at(size / 2)) / 2.0;
	}
	else
	{
		median = tempVector.at(size/2);
	}

	outputVector.push_back(median);

	// Get maximum element
	outputVector.push_back(tempVector.at(tempVector.size()-1));
}

std::stringstream output(std::string label, const std::vector<double>& resultVector)
{
	std::stringstream tempSS;
	tempSS << label << "\n";
	tempSS << "\tMinimum:\t" << *resultVector.begin() << "\n";
	tempSS << "\tMedian:\t\t" << resultVector.at(1) << "\n";
	tempSS << "\tMaximum:\t" << resultVector.at(resultVector.size()-1) << "\n";
	return tempSS;
}
