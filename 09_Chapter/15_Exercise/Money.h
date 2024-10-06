#pragma once
#include <cmath>
#include <sstream>
#include "Currency.h"
#include <map>

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

