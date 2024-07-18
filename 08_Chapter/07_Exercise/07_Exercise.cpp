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

std::vector<std::string> vectorOfNames(bool limited);
std::vector<double> vectorOfAges(bool limited);

int main()
{
	vectorOfNames(true);
}

std::vector<std::string> vectorOfNames(bool limited)
{
	std::vector<std::string> tempVector;
	int numInput{ 0 }, maxNames{ 2 - 1};
	std::string actualName;
	do
	{
		std::cout << "Enter a name: ";
		std::cin >> actualName;
		numInput++;
		if (actualName == "\n" || (limited && numInput < maxNames))
		{
			break;
		}
		tempVector.push_back(actualName);
	} while (actualName != "\n" || (!limited && numInput < maxNames));
	return tempVector;
}

std::vector<double> vectorOfAges(bool limited)
{
	return std::vector<double>();
}
