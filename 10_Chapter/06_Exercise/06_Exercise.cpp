// 06_Exercise.cpp : Define a Roman_int class for holding Roman numerals (as ints) with a << and >>.
// Provide Roman_int with an as_int() member that returns the int value, so that if r is a Roman_int, 
// we can write cout << "Roman" << r << "equals" << r.as_int() << '\n'; .

#include <iostream>
#include <unordered_map>


class Roman_int
{
public:
	Roman_int(int inputRomanNumber);
	int as_int() const;
	//std::ostream& operator<< (std::ostream& os);
	
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

Roman_int::Roman_int(int inputRomanNumber):
	romanInteger{inputRomanNumber}
{
	std::vector<std::string> notation = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
	std::vector<int> numbers = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	int i = numbers.size() - 1;
	std::string tempAnswer;

	while (inputRomanNumber > 0) {
		while (inputRomanNumber >= numbers[i]) {  // Changed condition here
			tempAnswer += notation[i];
			inputRomanNumber -= numbers[i];
		}
		--i;
	}
	romanLiteral = tempAnswer;
}

int Roman_int::as_int() const
{
	return romanInteger;
}

//std::ostream& Roman_int::operator<<(std::ostream& os)
//{
//	// TODO: insert return statement here
//}


int main()
{
	Roman_int test1{ 19 }; // XIX
	Roman_int test2{ 2540 }; // MMDXL

    std::cout << "Hello World!\n";
}

