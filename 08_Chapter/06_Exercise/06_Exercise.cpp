// 06_Exercise.cpp : Write versions of the functions from exercise 5, but with a vector<string>.

#include <iostream>
#include <vector>
#include <sstream>

std::stringstream print(std::string label, std::vector<std::string>& values);
std::vector<std::string> reverseWithoutSwap(const std::vector<std::string>& inputVector);
void reverseWithSwap(std::vector<std::string>& inputVector);

int main()
{
	std::vector<std::string> startVector{ "Hallo", "Was los", "Ciao"};
	std::cout << print("Start Vector", startVector).str();
	std::vector<std::string> reversedVector{ reverseWithoutSwap(startVector) };
	std::cout << print("Reversed Vector", reversedVector).str();
	reverseWithSwap(startVector);
	std::cout << print("Reversed Vector with swap", startVector).str();
}

std::vector<std::string> reverseWithoutSwap(const std::vector<std::string>& inputVector)
{
	std::vector <std::string> returnVector;
	int sizeVector{ static_cast<int> (inputVector.size()) - 1 };
	for (int numElement{ sizeVector }; numElement >= 0; --numElement)
	{
		returnVector.push_back(inputVector.at(numElement));
	}
	return returnVector;
}

void reverseWithSwap(std::vector<std::string>& inputVector)
{
	int left = 0;
	int right = inputVector.size() - 1;

	while (left < right) {
		std::swap(inputVector.at(left), inputVector.at(right));
		left++;
		right--;
	}
}

std::stringstream print(std::string label, std::vector<std::string>& values)
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
