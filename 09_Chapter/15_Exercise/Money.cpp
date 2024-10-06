#include "Money.h"

Money::Money(long int inputCents, currency inputCurrency) :
	cents{ inputCents }, actualCurrency{ inputCurrency }
{
}

Money::Money(long int inputDollar, long int inputCents, currency inputCurrency) :
	cents{ inputDollar * 100 + inputCents }, actualCurrency{ inputCurrency }
{
}


Money::Money(double inputFloat, currency inputCurrency)
{
	if (std::fmod(inputFloat * 100, 1) != 0)
	{
		throw std::logic_error("Provided to small decimal");
	}
	long int dollarsInput{ static_cast<long int>(std::trunc(inputFloat)) * 100 };
	double whole{ };
	double test{ std::modf(inputFloat, &whole) };
	actualCurrency = inputCurrency;
	cents = dollarsInput + (inputFloat - whole) * 100;
}

Money::Money() :
	cents{ 0 }, actualCurrency{ currency::dollar }
{
}

Money Money::operator+(const Money& secondMoney)
{
	if (this->actualCurrency == secondMoney.actualCurrency)
	{
		return Money((this->cents + secondMoney.cents), this->actualCurrency);
	}
	return Money((this->cents + convertMoneyToCents(secondMoney, this->actualCurrency)), this->actualCurrency);

}

Money Money::operator-(const Money& secondMoney)
{
	if (this->actualCurrency == secondMoney.actualCurrency)
	{
		return Money((this->cents - secondMoney.cents), this->actualCurrency);
	}
	return Money((this->cents - convertMoneyToCents(secondMoney, this->actualCurrency)), this->actualCurrency);
}

long int Money::convertMoneyToCents(const Money& secondMoney, currency wantedCurrency)
{
	double actualConversionRate{};
	switch (wantedCurrency)
	{
	case currency::dollar:
		actualConversionRate = conversionRate.at("DKKtoDollar");
		break;
	case currency::DKK:
		actualConversionRate = conversionRate.at("DollarToDKK");
		break;
	}
	return secondMoney.cents * actualConversionRate;
}

std::ostream& operator<<(std::ostream& os, const Money& input)
{
	long int dollar{ input.cents / 100 };
	long int newCents{ input.cents % 100 };
	std::string currencyString{};
	if (input.actualCurrency == currency::dollar)
	{
		currencyString = "$";
	}
	else
	{
		currencyString = "DKK";
	}
	os << currencyString << dollar << "." << abs(newCents) << "\n";
	return os;
}
