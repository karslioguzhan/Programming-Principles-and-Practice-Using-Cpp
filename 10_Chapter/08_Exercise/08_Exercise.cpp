// 08_Exercise.cpp : Write a program that accepts two file names and produces a new file that is the contents of 
// the first file followed by the contents of the second; that is, the program concatenates the two files.
//

#include <iostream>
#include <string>
#include <fstream>

bool readFromFile(std::string const fileName, std::string& textFromFile);
inline std::string concatenateStrings(std::string textFromFile1Input, std::string textFromFile2Input);

int main()
{
	std::string fileName1{ "LoremIpsum.txt" }, fileName2{ "RandomSequence.txt" };
	std::string textFromFile1, textFromFile2;

	if (!readFromFile(fileName1, textFromFile1) || !readFromFile(fileName2, textFromFile2))
	{
		return -1;
	}
	std::string conCatString{ concatenateStrings(textFromFile1, textFromFile2) };
	std::ofstream outputFile{ "conCatFiles.txt" };
	outputFile << conCatString.c_str();
	outputFile.close();

	return 0;
}

bool readFromFile(std::string const fileName, std::string& textFromFile)
{
	std::ifstream inputFile(fileName);
	if (inputFile.bad())
	{
		std::cerr << "Error with reading file " << fileName << " abort program!\n";
		return false;
	}
	std::string tempLine;
	while (std::getline(inputFile, tempLine))
	{
		textFromFile += tempLine + "\n";
	}
	inputFile.close();
	return true;
}

inline std::string concatenateStrings(std::string const inputString1, std::string const inputString2)
{
	return inputString1 + inputString2;
}
