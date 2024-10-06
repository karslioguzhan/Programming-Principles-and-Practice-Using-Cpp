// 15_Exercise.cpp : Refine the Money class by adding a currency (given as a constructor argument).
// Accept a floating - point initializer as long as it can be exactly
// represented as a long int.Don't accept illegal operations. For example,
// Money * Money doesn't make sense, and USD1.23+DKK5.00 makes sense
// only if you provide a conversion table defining the conversion factor between U.S.dollars(USD) and Danish kroner(DKK).

#include <iostream>
#include "Money.h"

int main()
{
	Money test1{ 12.5, currency::dollar };
	Money test2{ 30.1, currency::DKK };
	std::cout << "Addition base dollar: " << (test1 + test2);
	std::cout << "Subtraction base dollar: " << (test1 - test2);
	std::cout << "Addition base DKK: " << (test2 + test1);
	std::cout << "Subtraction base DKKdollar: " << (test2 - test1);

}
