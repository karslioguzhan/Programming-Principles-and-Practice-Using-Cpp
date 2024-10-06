#pragma once
#include <cmath>
#include <sstream>
#include <iostream>
#include <map>
#include "Currency.h"

class Money
{
public:
	Money(long int inputCents, currency inputCurrency);
	Money(long int inputDollar, long int inputCents, currency inputCurrency);
	Money(double inputFloat, currency inputCurrency);
	Money(); 
	Money operator+(const Money& secondMoney);
	Money operator-(const Money& secondMoney);
	friend  std::ostream& operator<<(std::ostream& os, const Money& input);
	friend std::istream& operator>>(std::istream& inputStream, Money& input);
private:
	long int cents;
	currency actualCurrency;
	long int convertMoneyToCents(const Money& secondMoney, currency wantedCurrency);
	std::map <std::string, double> conversionRate
	{
		{"DKKtoDollar", 0.15},
		{"DollarToDKK", 6.66},
	};
};

