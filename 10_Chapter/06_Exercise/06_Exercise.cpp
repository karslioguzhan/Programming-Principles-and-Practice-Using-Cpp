// 06_Exercise.cpp : Define a Roman_int class for holding Roman numerals (as ints) with a << and >>.
// Provide Roman_int with an as_int() member that returns the int value, so that if r is a Roman_int, 
// we can write cout << "Roman" << r << "equals" << r.as_int() << '\n'; .

#include <iostream>
#include <unordered_map>


class Roman_int
{
public:
	Roman_int();
	int as_int() const;
	std::ostream& operator<< (std::ostream& os);
	
private:
	std::string romanLiteral;
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

Roman_int::Roman_int()
{
}

int Roman_int::as_int() const
{
	return 0;
}

std::ostream& Roman_int::operator<<(std::ostream& os)
{
	// TODO: insert return statement here
}

Roman_int::~Roman_int()
{
}
int main()
{
    std::cout << "Hello World!\n";
}

