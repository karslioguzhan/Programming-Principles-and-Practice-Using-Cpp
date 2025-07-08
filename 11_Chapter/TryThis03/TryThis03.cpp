// TryThis03.cpp: Write some code to print the number 1234567.89 three times, 
//  first using defaultfloat, then fixed, then scientific.
//  Which output form presents the user with the most accurate representation?
//  Explain why.

// Result:
//  The fixed point representation is the most accurate, because in this case the the 6 digits are enough to represent the float.


#include <ios>
#include <iostream>

int main()
{
  constexpr double RandomDouble{1234567.89};
  std::cout << "Default Float:\t\t" <<std::defaultfloat << RandomDouble 
  << "\nFixed Float:\t\t" << std::fixed << RandomDouble
  << "\nScientific Float:\t" << std::scientific << RandomDouble << "\n";

  return 0;
}