#pragma once
#include <cstdint>
#include <stdexcept>

class RationalNumber
{
public:
	RationalNumber();
	RationalNumber(int32_t inputNumerator, int32_t inputDenominator);
	bool operator==(const RationalNumber& secondRationalNumber);
	bool operator!=(const RationalNumber& secondRationalNumber);
	RationalNumber operator+(const RationalNumber& secondRationalNumber);
	RationalNumber operator-(const RationalNumber& secondRationalNumber);
	RationalNumber operator*(const RationalNumber& secondRationalNumber);
	RationalNumber operator/(const RationalNumber& secondRationalNumber);
	double convertToDouble();

private:
	int32_t numerator;
	int32_t denominator;
};

