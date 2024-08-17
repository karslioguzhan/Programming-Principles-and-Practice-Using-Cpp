// 13_Exercise.cpp : Write a function that takes a vector<string> argument and returns a vector<int> containing 
// the number of characters in each string. Also find the longest and the shortest string and the lexicographically 
// first and last string. How many separate functions would you use for these tasks ? Why ?

// Conclusion:
//	Technically we don't need any user function (if we didn't count lambda functions). Because the algorithm library provides everything.
//	In this solution I've used only one function because the task asked for it.

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> numOfChars(const std::vector<std::string>& inputVector);

int main()
{
	std::vector<std::string> testVector{ "Can", "These", "Words", "Be", "Sorted", "?" };
	std::sort(testVector.begin(), testVector.end());
	std::vector<int> numCharVector{ numOfChars(testVector) };
	// Print result
	for (int numElement{}; numElement < testVector.size(); ++numElement)
	{
		std::cout << testVector.at(numElement) << "\tNumber of Chars: " << numCharVector.at(numElement) << "\n";
	}
	// Find longest and shortest 
	auto minElementIterator{ std::min_element(testVector.begin(), testVector.end(),[](const std::string& a, const std::string b)
	{
		return a.size() < b.size();
	}) };
	std::cout << "Shortest element: " << *minElementIterator << "\n";
	auto maxElementIterator{ std::max_element(testVector.begin(), testVector.end(),[](const std::string& a, const std::string b)
	{
		return a.size() < b.size();
	}) };
	std::cout << "Longest element: " << *maxElementIterator << "\n";

}

std::vector<int> numOfChars(const std::vector<std::string>& inputVector)
{
	std::vector<int> tempVector;
	for (auto elementVector : inputVector)
	{
		tempVector.push_back(elementVector.length());
	}
	return tempVector;
}

