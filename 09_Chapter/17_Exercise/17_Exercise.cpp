// 17_Exercise.cpp : Give an example of a calculation where a Rational gives a mathematically better result than Money.

#include <iostream>
#include "Money.h"
#include "RationalNumber.h"

// Answer: A rational deals better with very small numbers and doesn't have a floating point error

int main()
{
	Money testMoney1(12, 99, currency::dollar);
	Money testMoney2(0.001, currency::dollar); // This throws an error because we only allowed two decimal points
	std::cout << "Substraction with loss: " << testMoney1 - testMoney2 << "\n";
	RationalNumber testRational1(1299, 1);
	RationalNumber testRational2(1, 1000);
	RationalNumber testRational3((testRational1 - testRational2));
	std::cout << "Substraction rational without loss: " << testRational3.getNumerator() << "/" << testRational3.getDenominator() << "\n";

}

