// 14_Exercise.cpp : Design and implement a Money class for calculations involving dollars
// and cents where arithmetic has to be accurate to the last cent using the
// 4 / 5 rounding rule(.5 of a cent rounds up; anything less than .5 rounds
// down).Represent a monetary amount as a number of cents in a long int,
// but input and output as dollars and cents, e.g., $123.45.Do not worry
// about amounts that don't fit into a long int.

#include <iostream>
#include "Money.h"

int main()
{
    Money test1{ 100, 50 };
    Money test2{ 22, 23 };
    std::cout << "Print test: " << test1 << "\n";
    std::cout << "Addition test: " << (test1 + test2) << "\n";
    std::cout << "Subtraction test: " << (test1 - test2) << "\n";
    std::cout << "Multiplication test: " << (test1 * test2) << "\n";
    std::cout << "Division test: " << (test1 / test2) << "\n";
}

