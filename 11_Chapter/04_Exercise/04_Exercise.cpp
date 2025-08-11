// 04_Exercise.cpp:
// Write a program called multi_input.cpp that prompts the user to enter several integers in any
// combination of octal, decimal or hexadecimal using the 0 and 0x base suffixes; interprets the
// numbers correctly; and converts them to decimal form. Then your program should output the values
// in properly spaced columns like this:
//    0x43    hexadecimal   converts to   67    decimal
//    0123    octal         converts to   83    decimal
//    65      decimal       converts to   65    decimal

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

bool static isDecimal(std::string const &InputValue)
{
  for (char ActualChar : InputValue)
  {
    if (!std::isdigit(ActualChar))
    {
      return false;
    }
  }
  return true;
}

void static promptInput()
{
  std::cout << "Please enter a integer with a suffix 0 for octal, 0x for hexadecimal or without "
               "for decimal:";
}

enum class TypeOfInt : int
{
  decimal,
  hexadecimal,
  octal
};

std::pair<bool, std::pair<TypeOfInt, int>> static validateAndConvertInput(
    std::string const &InputString)
{
  // Checking for decimal values
  bool CheckIfDecimal{isDecimal(InputString)};
  if (CheckIfDecimal)
  {
    return std::pair<bool, std::pair<TypeOfInt, int>>{true,
                                                      {TypeOfInt::decimal, std::stoi(InputString)}};
  }

  // Checking for hexadecimal  values
  if (InputString.substr(0, 2).compare("0x") == 0)
  {
    bool CheckIfDecimal{isDecimal(InputString.substr(2, InputString.length() - 1))};
    if (CheckIfDecimal)
    {
      int TempValue{};
      std::stringstream TempStringStream;
      TempStringStream << std::hex << InputString;
      TempStringStream >> TempValue;
      return std::pair<bool, std::pair<TypeOfInt, int>>{true, {TypeOfInt::hexadecimal, TempValue}};
    }
  }

  if (InputString.substr(0, 1).compare("0") == 0)
  {
    bool CheckIfDecimal{isDecimal(InputString.substr(2, InputString.length() - 1))};
    if (CheckIfDecimal)
    {
      int TempValue{};
      std::stringstream TempStringStream;
      TempStringStream << std::hex << InputString;
      TempStringStream >> TempValue;
      return std::pair<bool, std::pair<TypeOfInt, int>>{true, {TypeOfInt::hexadecimal, TempValue}};
    }
  }



  return std::pair<bool, std::pair<TypeOfInt, int>>{true,
                                                    {TypeOfInt::decimal, std::stoi(InputString)}};
}

int main()
{
  std::string InputValue{};
  std::vector<std::pair<bool, std::pair<TypeOfInt, int>>> CollectedIntegers;
  promptInput();
  while (std::cin >> InputValue)
  {
    promptInput();
    auto TempValue{validateAndConvertInput(InputValue)};
    if (TempValue.first)
    {
      CollectedIntegers.push_back(TempValue);
    }
  }

  return 0;
}