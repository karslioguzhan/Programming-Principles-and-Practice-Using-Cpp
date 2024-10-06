#include "RationalNumber.h"

RationalNumber::RationalNumber() :
	numerator{ 1 }, denominator{ 1 }
{
}

RationalNumber::RationalNumber(int32_t inputNumerator, int32_t inputDenominator)
	:numerator{ inputNumerator }, denominator{ inputDenominator }
{
	if (inputDenominator == 0)
	{
		throw std::invalid_argument("Denominator can not be zero!");
	}
}

bool RationalNumber::operator==(const RationalNumber& secondRationalNumber)
{
	double lhs{ this->numerator / static_cast<double>(this->denominator) };
	double rhs{ secondRationalNumber.numerator / static_cast<double>(secondRationalNumber.denominator) };
	return lhs == rhs;
}

bool RationalNumber::operator!=(const RationalNumber& secondRationalNumber)
{
	return !(*this == secondRationalNumber);
}

RationalNumber RationalNumber::operator+(const RationalNumber& secondRationalNumber)
{
	int32_t newNumerator{ this->numerator * secondRationalNumber.denominator +
	secondRationalNumber.numerator * this->denominator };
	return RationalNumber(newNumerator, (this->denominator * secondRationalNumber.denominator));
}

RationalNumber RationalNumber::operator-(const RationalNumber& secondRationalNumber)
{
	int32_t newNumerator{ this->numerator * secondRationalNumber.denominator -
secondRationalNumber.numerator * this->denominator };
	return RationalNumber(newNumerator, (this->denominator * secondRationalNumber.denominator));
}

RationalNumber RationalNumber::operator*(const RationalNumber& secondRationalNumber)
{
	return RationalNumber(this->numerator * secondRationalNumber.numerator, this->denominator * secondRationalNumber.denominator);
}

RationalNumber RationalNumber::operator/(const RationalNumber& secondRationalNumber)
{
	RationalNumber swapped{ secondRationalNumber.denominator, secondRationalNumber.numerator };
	return (*this*swapped);
}

double RationalNumber::convertToDouble()
{
	return this->numerator/static_cast<double>(this->denominator);
}
