/* 07_Exercise.cpp : Read five names into a vector<string> name, then prompt the user for
	the ages of the people named and store the ages in a vector<double> age.
	Then print out the five (name[i],age[i]) pairs. Sort the names (sort(name
	.begin(),name.end())) and print out the (name[i],age[i]) pairs. The tricky
	part here is to get the age vector in the correct order to match the sorted
	name vector. Hint: Before sorting name, take a copy and use that to
	make a copy of age in the right order after sorting name. Then, do that
	exercise again but allowing an arbitrary number of names.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

std::vector<std::string> vectorOfNames(bool limited);
std::vector<double> vectorOfAges(bool limited, int numOfAges);
void sortVector(std::vector<std::string>& vectorOfNames, std::vector<double>& vectorOfAges);
std::stringstream print(std::string label, const std::vector<std::string>& names, const std::vector<double>& ages);


int main()
{
	// Restricted to 5 inputs, to allow more inputs set false
	std::vector<std::string> namesVector{ vectorOfNames(true) };
	std::vector<double> agesVector{ vectorOfAges(true, namesVector.size()) };
	std::cout << print("Before sorting", namesVector, agesVector).str();
	sortVector(namesVector, agesVector);
	std::cout << print("After sorting", namesVector, agesVector).str();
	return 0;
}

std::vector<std::string> vectorOfNames(bool limited)
{
	std::vector<std::string> tempVector;
	int numInput{ 0 }, maxNames{ 5 - 1 };
	std::string actualName;
	do
	{
		std::cout << "Enter a name or \"end\" to end input: ";
		std::cin >> actualName;
		numInput++;
		if (actualName == "end")
		{
			break;
		}
		tempVector.push_back(actualName);
		if (numInput > maxNames && limited)
		{
			break;
		}

	} while (actualName != "end");
	return tempVector;
}

std::vector<double> vectorOfAges(bool limited, int numOfAges)
{
	std::vector<double> tempVector;
	for (int numIteration{ 0 }; numIteration < numOfAges; ++numIteration)
	{
		std::cout << "Enter age: ";
		double inputAge{};
		std::cin >> inputAge;
		tempVector.push_back(inputAge);
	}
	return tempVector;
}

void sortVector(std::vector<std::string>& vectorOfNames, std::vector<double>& vectorOfAges)
{
	std::vector<std::string> copyNames{ vectorOfNames };
	std::vector<double> copyAges{ vectorOfAges };
	std::sort(vectorOfNames.begin(), vectorOfNames.end());
	for (int numNames{ 0 }; numNames < copyNames.size(); ++numNames)
	{
		std::string searchedName{ copyNames.at(numNames) };
		// Replace with right one
		for (int numSortedNames{ 0 }; numSortedNames < vectorOfNames.size(); ++numSortedNames)
		{
			if (vectorOfNames.at(numSortedNames) == searchedName)
			{
				vectorOfAges.at(numSortedNames) = copyAges.at(numNames);
				break;
			}
		}
	}
}

std::stringstream print(std::string label, const std::vector<std::string>& names, const std::vector<double>& ages)
{
	std::stringstream output;
	output << label << ":\n";
	for (int numElement{ 0 }; numElement < names.size(); ++numElement)
	{
		output << "\t" << names.at(numElement) << "\t" << ages.at(numElement) << "\n";
	}
	return output;
}
