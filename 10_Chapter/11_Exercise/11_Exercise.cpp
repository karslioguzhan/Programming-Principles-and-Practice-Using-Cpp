// 11_Exercise.cpp: Write a program that produces the sum of all the
// whitespace-separated integers in a text file. For example, bears: 17
// elephants 9 end should output 26.

#include <fstream>
#include <iostream>
#include <string>

static int returnIntegerValue(std::string const &Input);

int main()
{
  std::string FileName{"inputFile.txt"};
  std::ifstream InputFile(FileName);
  if (InputFile.bad())
  {
    std::cerr << "Error with reading file " << FileName << " abort program!\n";
    return 1;
  }
  std::string TempWord;
  int SumOfInts{};
  while (InputFile >> TempWord)
  {
    SumOfInts += returnIntegerValue(TempWord);
  }
  InputFile.close();

  std::cout << "The file: " << FileName << " has integers with sum of: " << SumOfInts << "\n";
  return 0;
}

int returnIntegerValue(std::string const &Input)
{
  if (Input.empty())
    return 0;

  for (char ActualChar : Input)
  {
    if (!std::isdigit(ActualChar))
      return 0;
  }
  return std::stod(Input);
}
