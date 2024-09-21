#include "Name_pairs.h"

bool Name_pairs::readNames(std::vector<std::string> inputNames)
{
	if (inputNames.empty())
	{
		return false;
	}
	for (auto actualName : inputNames)
	{
		name.push_back(actualName);
	}
	return true;
}

bool Name_pairs::readAges()
{
	if (name.empty())
	{
		return false;
	}
	for (auto actualName : name)
	{
		std::cout << "Enter a age for " << actualName << ": ";
		int inputAge{};
		std::cin >> inputAge;
		age.push_back(inputAge);
	}
	return true;
}

void Name_pairs::print()
{
	std::cout << "Name and age pairs:\n";
	for (int numIteration{}; numIteration < name.size(); ++numIteration)
	{
		std::cout << "\t" << name.at(numIteration) << "\t" << age.at(numIteration) << "\n";
	}
}

void Name_pairs::sortAlphabetical()
{
	std::vector<int> tempAges{ age };
	std::vector<std::string> tempName{ name };
	std::sort(name.begin(), name.end());
	
	for (int numIteration{}; numIteration < name.size(); ++numIteration)
	{
		// Find iterator of name
		auto iterator{ std::find(tempName.begin(), tempName.end(), name.at(numIteration)) };
		int position{ static_cast<int>( std::distance(tempName.begin(), iterator)) };
		age.at(numIteration) = tempAges.at(position);
	}

}
