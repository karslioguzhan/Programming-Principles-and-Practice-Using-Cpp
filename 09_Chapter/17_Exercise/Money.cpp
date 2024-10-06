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

std::istream& operator>>(std::istream& inputStream, Money& input)
{
	std::string inputString;
	std::cin >> inputString;
	// 6 = Currency + min value -> USD0.10
	if (inputString.length() < 6)
	{
		throw std::invalid_argument("Input is not enough");
	}
	if (inputString.find("USD") == std::string::npos && inputString.find("DKK") == std::string::npos)
	{
		throw std::invalid_argument("Currency is not supported or is not entered!\n");
	}
	if (inputString.find("USD") != std::string::npos)
	{
		input.actualCurrency = currency::dollar;
	}
	else
	{
		input.actualCurrency = currency::DKK;
	}
	if (inputString.find(".") == std::string::npos)
	{
		throw std::invalid_argument("Missing . for decimal places\n");
	}
	long int dollars{ std::stoi(inputString.substr(3, inputString.find("."))) };
	long int cents{ std::stoi(inputString.substr(inputString.find(".")+1, inputString.length()-1)) };
	input.cents = dollars * 100 + cents;
	return inputStream;
}
