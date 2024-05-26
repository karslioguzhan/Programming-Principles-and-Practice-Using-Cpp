#include "my.h"
#include "std_lib_facilities.h"

void print_foo()
{
	std::cout << "Value of foo: " << foo << "\n";
}

void print(int i)
{
	std::cout << "Value of variable i: " << i << "\n";
}

void swap_v(int x, int y)
{
	int temp{ x };
	x = y;
	y = temp;
}

void swap_r(int& x, int& y)
{
	int temp{ x };
	x = y;
	y = temp;
}

// Info: This function is not legit with Visual c++ compiler because the lvalue must be modifiable (E0137)
void swap_cr(const int& x, const int& y)
{
	int temp{ x };
	//x = y;
	//y = temp;
}
