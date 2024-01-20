// 11_Exercise.cpp : Write a program that writes out the first so many values of the Fibonacci series, that is, the series that starts With 1 1 2 3 5 8 13 21 34. The next number of the series is the sum of the two previous ones. Find the largest Fibonacci number that fits in an int.

#include <iostream>
#include <limits>


int fibonacci(int input1, int input2, const int& maxInt);


int main()
{
	constexpr int maxInt{ std::numeric_limits<int>::max() };
	int maxFibonacciNumber{ fibonacci(0, 1, maxInt) };
	std::cout << "The maximum fibonacci number with int with this machine is: " << maxFibonacciNumber << "\n";
	return 0;
}

int fibonacci(int input1, int input2, const int& maxInt)
{

	if (input1 > maxInt || input1 < 0 || input2 < 0)
	{
		return input1;
	}

	return fibonacci(input2, input2 + input1, maxInt);
}
