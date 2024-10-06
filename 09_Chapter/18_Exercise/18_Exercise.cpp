// 18_Exercise.cpp : Give an example of a calculation where a Rational gives a mathematically better result than double.

#include <iostream>
#include "RationalNumber.h"

// Answer: The ratio subtraction doesn't have the floating point error unlike the double one

int main()
{
    RationalNumber ratio1{ 1,1000000000 }, ratio2{ 1,1 };
    double test2{ 1 }, test3{ 0.0000000001 };
    std::cout << "Double subtraction: " << test2 - test3 << "\n";
    std::cout << "Rational subtraction: " << (ratio2 - ratio1).getNumerator() << "/" << (ratio2 - ratio1).getDenominator() << "\n";
}
