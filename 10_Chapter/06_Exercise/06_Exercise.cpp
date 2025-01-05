// 06_Exercise.cpp : Define a Roman_int class for holding Roman numerals (as ints) with a << and >>.
// Provide Roman_int with an as_int() member that returns the int value, so that if r is a Roman_int, 
// we can write cout << "Roman" << r << "equals" << r.as_int() << '\n'; .

#include <iostream>
#include <unordered_map>


class Roman_int
{
public:
	Roman_int(int inputRomanNumber);
	Roman_int();
	int as_int() const;
	friend std::ostream& operator<< (std::ostream& os, const Roman_int& input);
	friend std::istream& operator>> (std::istream& is, Roman_int& input);

private:
	static int romanToInt(std::string& input);
	static int valueOfRoman(char r);

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

Roman_int::Roman_int(int inputRomanNumber) :
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

Roman_int::Roman_int():
	romanInteger{0}
{
}

int Roman_int::as_int() const
{
	return romanInteger;
}

int Roman_int::romanToInt(std::string& input)
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

int Roman_int::valueOfRoman(char input)
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

std::ostream& operator<<(std::ostream& os, const Roman_int& input)
{
	os << input.romanLiteral;
	return os;
}

std::istream& operator>>(std::istream& is, Roman_int& input)
{
	std::string romanString;
	is >> romanString;
	input.romanInteger = input.romanToInt(romanString);
	input.romanLiteral = romanString;
	return is;
}

int main()
{
	Roman_int test1{ 19 }; // XIX
	Roman_int test2{ 2540 }; // MMDXL
	Roman_int test3;
	// Operator test
	std::cout << "Roman number: " << test1 << "\t" << " Arabic number: " << test1.as_int() << "\n";
	std::cout << "Roman number: " << test2 << "\t" << " Arabic number: " << test2.as_int() << "\n";
	std::cout << "Enter Roman numeral: ";
	std::cin >> test3;
	std::cout << "Roman number: " << test3 << "\t" << " Arabic number: " << test3.as_int() << "\n";
}

