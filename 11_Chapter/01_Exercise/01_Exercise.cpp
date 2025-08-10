// 01_Exercise.cpp:
//  Write a program that reads a text file and converts its input to all lower case, producing a new
//  file.

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iostream>
#include <fstream>

static std::string lowerCaseString(std::string const& InputString)
{
  std::string OutputString;
  std::transform(InputString.begin(), InputString.end(), OutputString.begin(), ::tolower);
  return OutputString;
}


int main()
{
  std::string InputFileName{"inputFile.txt"};
  std::ifstream InputFile(InputFileName);
  if (InputFile.bad())
  {
    std::cerr << "Error with reading file " << InputFileName << " abort program!\n";
    return 1;
  }
  std::string OutputFileName{ "outputFile.txt" };
	std::ofstream OutputFile{ OutputFileName };

  std::string TempWord;

  while (InputFile >> TempWord)
  {
    OutputFile << lowerCaseString(TempWord);
  }
  InputFile.close();
  OutputFile.close();
}