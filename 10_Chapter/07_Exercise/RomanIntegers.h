#pragma once
#include <iostream>
#include <unordered_map>

class RomanIntegers
{
public:
	RomanIntegers(int inputRomanNumber);
	RomanIntegers();
	int as_int() const;
	friend std::ostream& operator<< (std::ostream& os, const RomanIntegers& input);
	friend std::istream& operator>> (std::istream& is, RomanIntegers& input);
	static int romanToInt(std::string& input);
	static int valueOfRoman(char r);
	std::string getRomanLiteral() const;

private:
	std::string romanLiteral;
	int romanInteger;
	std::unordered_map<char, int> romanToIntMap
	{
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000},
	};
};

