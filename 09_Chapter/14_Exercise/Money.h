#pragma once
#include <cmath>
#include <sstream>

class Money
{
public:
	Money(long int inputCents);
	Money(long int inputDollar, long int inputCents);
	Money();
	Money operator+(const Money& secondMoney);
	Money operator-(const Money& secondMoney);
	Money operator*(const Money& secondMoney);
	Money operator/(const Money& secondMoney);
	friend  std::ostream& operator<<(std::ostream& os, const Money& input);
private:
	long int cents;
};

