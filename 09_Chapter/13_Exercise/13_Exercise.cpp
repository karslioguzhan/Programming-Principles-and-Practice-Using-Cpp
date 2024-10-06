// 13_Exercise.cpp : Design and implement a rational number class, Rational. A rational number has two parts : a numerator and a denominator, for example,
// 5 / 6 (five - sixths, also known as approximately .83333).Look up the definition if you need 
// to.Provide assignment, addition, subtraction, multiplication, division, and equality
// operators.Also, provide a conversion to double.
// Why would people want to use a Rational class ?

// Answer: Rational classes are useful for avoiding floating point errors!

#include <iostream>
#include "RationalNumber.h"

int main()
{
    RationalNumber test1{ 1,10 };
    RationalNumber test2{ 1,59 };
    std::cout << "Conversion test:\t" << test1.convertToDouble() << "\n";
    RationalNumber addition{ test1 + test2 };
    std::cout << "Test adding:\t\t" << addition.convertToDouble() << "\n";
    RationalNumber substration{ test1 - test2 };
    std::cout << "Test substraction:\t" << substration.convertToDouble() << "\n";
    RationalNumber multiplication{ test1 * test2 };
    std::cout << "Test multiplication:\t" << multiplication.convertToDouble() << "\n";
    RationalNumber division{ test1 / test2 };
    std::cout << "Test division:\t\t" << division.convertToDouble() << "\n";
}

