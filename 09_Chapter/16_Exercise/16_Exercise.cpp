// 16_Exercise.cpp : Define an input operator (>>) that reads monetary amounts with currency denominations, 
// such as USD1.23 and DKK5.00, into a Money variable.Also define a corresponding output operator ( >> ).

#include <iostream>
#include "Money.h"

int main()
{
	Money test1{ 12.5, currency::dollar };
	Money test2{ 30.1, currency::DKK };
	std::cout << "Addition base dollar: " << (test1 + test2);
	std::cout << "Substraction base dollar: " << (test1 - test2);
	std::cout << "Addition base DKK: " << (test2 + test1);
	std::cout << "Substraction base DKKdollar: " << (test2 - test1);
	try
	{
		Money test3;
		std::cout << "Please enter Currency followed by value (example USD10.24): ";
		std::cin >> test3;
		std::cout << test3;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
}
