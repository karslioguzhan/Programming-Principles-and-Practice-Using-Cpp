#include "Money.h"

Money::Money(long int inputCents) :
	cents{ inputCents }
{
}

Money::Money(long int inputDollar, long int inputCents) :
	cents{ inputDollar * 100 + inputCents }
{
}

Money::Money():
	cents{0}
{
}

Money Money::operator+(const Money& secondMoney)
{
	return Money((this->cents+secondMoney.cents));
}

Money Money::operator-(const Money& secondMoney)
{
	return Money((this->cents-secondMoney.cents));
}

Money Money::operator*(const Money& secondMoney)
{
	return Money((this->cents*secondMoney.cents));
}

Money Money::operator/(const Money& secondMoney)
{
	return Money((this->cents/secondMoney.cents));
}

std::ostream& operator<<(std::ostream& os, const Money& input)
{
	long int dollar{ input.cents / 100 };
	long int newCents{ input.cents % 100 };
	os << "$" << dollar << "." << newCents;
	return os;
}
