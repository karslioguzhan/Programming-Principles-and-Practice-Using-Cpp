// 02_Exercise.cpp:
//  Write a program that given a file name and a word outputs each line that contains that word
//  together with the line number. Hint: getline()

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>

static std::string lowerCaseString(std::string const &InputString)
{
  std::string OutputString{InputString};
  std::transform(OutputString.begin(), OutputString.end(), OutputString.begin(), ::tolower);
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

  std::string SearchedWord{"hendrerit"};
  std::string ActualLine;
  uint LineIndex{0};

  while (std::getline(InputFile, ActualLine))
  {
    ++LineIndex;
 
    if(ActualLine.find(SearchedWord) != std::string::npos)
    {
      std::cout << "Searched Word: " << SearchedWord << " found in Line: " << LineIndex << "!\n";
    }
  }
  InputFile.close();
}