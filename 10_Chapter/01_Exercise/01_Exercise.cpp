// 01_Exercise.cpp : Write a program that produces the sum of all the numbers in a file of whitespace-separated integers.
//

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

int main()
{
	std::string fileName{ "myData.txt" };
	std::ifstream inputFile{ fileName };
	try
	{
		int sum{};
		if (!inputFile)
		{
			throw std::invalid_argument("Cannot open file!");
		}
		int tempData{};
		while (inputFile >> tempData)
		{
			sum += tempData;
		}
		std::cout << "Sum of all data is: " << sum << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

}

