/* 05_Exercise.cpp : Write two functions that reverse the order of elements in a vector<int>.
	For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The first reverse function
	should produce a new vector with the reversed sequence, leaving its original vector
	unchanged.The other reverse function should reverse the
	elements of its vector without using any other vectors (hint: swap).
*/

#include <iostream>
#include <vector>
#include <sstream>

std::stringstream print(std::string label, std::vector<int>& values);
std::vector<int> reverseWithoutSwap(const std::vector<int>& inputVector);
void reverseWithSwap(std::vector<int>& inputVector);

int main()
{
	std::vector<int> startVector{ 1, 3, 5, 7, 9 };
	std::cout << print("Start Vector", startVector).str();
	std::vector<int> reversedVector{ reverseWithoutSwap(startVector) };
	std::cout << print("Reversed Vector", reversedVector).str();
	reverseWithSwap(startVector);
	std::cout << print("Reversed Vector with swap", startVector).str();
}

std::vector<int> reverseWithoutSwap(const std::vector<int>& inputVector)
{
	std::vector <int> returnVector;
	int sizeVector{ static_cast<int> (inputVector.size()) - 1 };
	for (int numElement{ sizeVector }; numElement >= 0; --numElement)
	{
		returnVector.push_back(inputVector.at(numElement));
	}
	return returnVector;
}

void reverseWithSwap(std::vector<int>& inputVector)
{
	int left = 0;
	int right = inputVector.size() - 1;

	while (left < right) {
		std::swap(inputVector.at(left), inputVector.at(right));
		left++;
		right--;
	}
}

std::stringstream print(std::string label, std::vector<int>& values)
{
	std::stringstream output;
	output << label << ":\n";
	for (auto elementVector : values)
	{
		output << " " << elementVector;
	}
	output << "\n";
	return output;
}
