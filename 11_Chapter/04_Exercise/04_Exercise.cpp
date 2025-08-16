// 04_Exercise.cpp:
// Write a program called multi_input.cpp that prompts the user to enter several integers in any
// combination of octal, decimal or hexadecimal using the 0 and 0x base suffixes; interprets the
// numbers correctly; and converts them to decimal form. Then your program should output the values
// in properly spaced columns like this:
//    0x43    hexadecimal   converts to   67    decimal
//    0123    octal         converts to   83    decimal
//    65      decimal       converts to   65    decimal

#include <cctype>
#include <iomanip>
#include <ios>
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
  octal,
  error
};

std::pair<bool, std::pair<TypeOfInt, int>> static validateAndConvertInput(
    std::string const &InputString)
{
  bool CheckIfDecimal{isDecimal(InputString)};

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
    bool CheckIfDecimal{isDecimal(InputString.substr(1, InputString.length() - 1))};
    if (CheckIfDecimal)
    {
      int TempValue{};
      std::stringstream TempStringStream;
      TempStringStream << std::oct << InputString;
      TempStringStream >> TempValue;
      return std::pair<bool, std::pair<TypeOfInt, int>>{true, {TypeOfInt::octal, TempValue}};
    }
  }
  // Checking for decimal values
  if (CheckIfDecimal)
  {
    return std::pair<bool, std::pair<TypeOfInt, int>>{true,
                                                      {TypeOfInt::decimal, std::stoi(InputString)}};
  }

  // Negative return
  return std::pair<bool, std::pair<TypeOfInt, int>>{false, {TypeOfInt::error, 0}};
}

auto static collectIntegers()
{
  std::vector<std::pair<bool, std::pair<TypeOfInt, int>>> TempCollectedIntegers;
  std::cout << "Integer Converter. To exit press  \"x\"\n";
  std::string InputValue{};
  do
  {
    promptInput();
    std::cin >> InputValue;
    auto TempValue{validateAndConvertInput(InputValue)};
    if (TempValue.first)
    {
      TempCollectedIntegers.push_back(TempValue);
    }
    else if (InputValue.compare("x") != 0)
    {
      std::cout << "Error: " << InputValue << " in not an valid value!\n";
    }
  } while (InputValue.compare("x") != 0);
  return TempCollectedIntegers;
}

std::stringstream static convertIntegersToStream(
    std::vector<std::pair<bool, std::pair<TypeOfInt, int>>> const &CollectedIntegersInput)
{
  std::stringstream TempStream;
  if (CollectedIntegersInput.empty())
  {
    TempStream << "No valid values inserted! Nothing to print. \n";
  }
  for (auto ActualInteger : CollectedIntegersInput)
  {
    switch (ActualInteger.second.first)
    {
    case TypeOfInt::decimal:
      TempStream << std::dec << std::setw(10) << ActualInteger.second.second
                 << " decimal\tconverts to " << ActualInteger.second.second << " decimal\n";
      break;
    case TypeOfInt::hexadecimal:
      TempStream << std::showbase << std::hex << std::setw(10) << ActualInteger.second.second
                 << std::setw(10) << " hexadecimal\tconverts to " << std::dec
                 << ActualInteger.second.second << " decimal\n";
      break;
    case TypeOfInt::octal:
      TempStream << std::showbase << std::oct << std::setw(10) << ActualInteger.second.second
                 << std::setw(10) << " octal\tconverts to " << std::dec
                 << ActualInteger.second.second << " decimal\n";
      break;
    case TypeOfInt::error:
      break;
    }
  }
  return TempStream;
}

int main()
{
  std::vector<std::pair<bool, std::pair<TypeOfInt, int>>> CollectedIntegers{collectIntegers()};
  std::cout << convertIntegersToStream(CollectedIntegers).str();
  return 0;
}