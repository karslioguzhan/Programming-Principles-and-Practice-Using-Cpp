#include "RomanIntegers.h"
RomanIntegers::RomanIntegers(int inputRomanNumber) :
	romanInteger{ inputRomanNumber }
{
	std::vector<std::string> notation = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
	std::vector<int> numbers = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	int i = numbers.size() - 1;
	std::string tempAnswer;

	while (inputRomanNumber > 0) {
		while (inputRomanNumber >= numbers[i]) {
			tempAnswer += notation[i];
			inputRomanNumber -= numbers[i];
		}
		--i;
	}
	romanLiteral = tempAnswer;
}

RomanIntegers::RomanIntegers() :
	romanInteger{ 0 }
{
}

int RomanIntegers::as_int() const
{
	return romanInteger;
}

int RomanIntegers::romanToInt(std::string& input)
{
	int res = 0;

	for (int i = 0; i < input.length(); i++) {
		int s1 = valueOfRoman(input[i]);
		if (i + 1 < input.length()) {
			int s2 = valueOfRoman(input[i + 1]);
			if (s1 >= s2) {
				res += s1;
			}
			else {
				res += (s2 - s1);
				i++;
			}
		}
		else {
			res += s1;
		}
	}

	return res;
}

int RomanIntegers::valueOfRoman(char input)
{
	if (input == 'I')
		return 1;
	if (input == 'V')
		return 5;
	if (input == 'X')
		return 10;
	if (input == 'L')
		return 50;
	if (input == 'C')
		return 100;
	if (input == 'D')
		return 500;
	if (input == 'M')
		return 1000;
	return -1;
}

std::string RomanIntegers::getRomanLiteral() const
{
	return romanLiteral;
}

std::ostream& operator<<(std::ostream& os, const RomanIntegers& input)
{
	os << input.romanLiteral;
	return os;
}

std::istream& operator>>(std::istream& is, RomanIntegers& input)
{
	std::string romanString;
	is >> romanString;
	input.romanInteger = input.romanToInt(romanString);
	input.romanLiteral = romanString;
	return is;
}