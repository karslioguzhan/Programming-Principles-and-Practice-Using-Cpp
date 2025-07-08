// TryThis02.cpp: Complete the code fragment above to make it into a program. Try the suggested
// input;
//  then type in 1234 1234 1234 1234
//  Explain the results. Try other inputs to see whats happens.

// Explanations of the results:
//  1. Input is getted as decimal and printed in decimal
//  2. Input is getted as hex and printed in decimal
//  3. & 4. Input is getted as oct and printed in decimal
//    Conclusion -> The last modifier decides which format the input are interpreted

#include <iostream>

int main()
{
  int a, b, c, d;
  std::cin >> a >> std::hex >> b >> std::oct >> c >> d;
  std::cout << a << "\t" << b << "\t" << c << "\t" << d << "\n";

  return 0;
}