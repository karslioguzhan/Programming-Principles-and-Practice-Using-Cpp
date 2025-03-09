// 09_Exercise.cpp : Write a program that takes two files containing sorted 
// whitespace-separated words and merges them, preserving order.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

bool readWordsFromFile(std::string const fileName, std::vector<std::string>& outputVector);

int main()
{
	std::vector<std::string> allWordsVector;
	std::string fileName1{ "sortedFile1.txt" }, fileName2{ "sortedFile2.txt" };

	if (!readWordsFromFile(fileName1, allWordsVector) || !readWordsFromFile(fileName2, allWordsVector))
	{
		return -1;
	}

	std::sort(allWordsVector.begin(), allWordsVector.end());
}


bool readWordsFromFile(std::string const fileName, std::vector<std::string>& outputVector)
{
	std::ifstream inputFile(fileName);
	if (inputFile.bad())
	{
		std::cerr << "Error with reading file " << fileName << " abort program!\n";
		return false;
	}
	std::string tempWord;
	while (inputFile >> tempWord)
	{
		outputVector.push_back(tempWord);
	}
	inputFile.close();
	return true;
}