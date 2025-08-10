// 04_Exercise.cpp:
// Write a program called multi_input.cpp that prompts the user to enter several integers in any
// combination of octal, decimal or hexadecimal using the 0 and 0x base suffixes; interprets the
// numbers correctly; and converts them to decimal form. Then your program should output the values
// in properly spaced columns like this:
//    0x43    hexadecimal   converts to   67    decimal
//    0123    octal         converts to   83    decimal
//    65      decimal       converts to   65    decimal

#include <iostream>
#include <string>
#include <vector>

void static promptInput()
{
  std::cout << "Please enter a integer with a suffix 0 for octal, 0x for hexadecimal or without "
               "for decimal:";
}

bool static validateInput(std::string const & InputString)
{
  if (InputString.find("0x") != std::string::npos) 
  {
    return true;   
  }
  else if (InputString.at(0) == "0") {
  
  }
else if (condition) {

}
  return false;
}

int main()
{
  std::string InputValue{};
  std::vector<int> CollectedIntegers;
  promptInput();
  while (std::cin >> InputValue)
  {
    promptInput();
    int test{std::stoi(InputValue)};
    std::cout << "Hallo";
  }

  return 0;
}