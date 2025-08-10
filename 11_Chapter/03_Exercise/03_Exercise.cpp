// 03_Exercise.cpp:
// Write a program that removes all vowels from a file ("disemvovels"). For example, Once upon a
// time! becomes nc pn tm!. Suprisingly often, the result is still readable; try it on your friends.

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

std::string static disemvovels(std::string const &InputString)
{
  std::string TempWord;
  for (char CharInString : InputString)
  {
    if (toupper(CharInString) == 'A' || toupper(CharInString) == 'E' ||
        toupper(CharInString) == 'I' || toupper(CharInString) == 'O' ||
        toupper(CharInString) == 'U')
    {
      continue;
    }
    TempWord += CharInString;
  }
  return TempWord;
}

int main()
{
  std::string InputFileName{"disemvovels.txt"};
  std::ifstream InputFile(InputFileName);
  if (InputFile.bad())
  {
    std::cerr << "Error with reading file " << InputFileName << " abort program!\n";
    return 1;
  }
  std::string OutputFileName{"outputFile.txt"};
  std::ofstream OutputFile{OutputFileName};

  std::string TempWord;

  while (InputFile >> TempWord)
  {
    OutputFile << disemvovels(TempWord) << " ";
  }
  InputFile.close();
  OutputFile.close();
}