// 01_Drill.cpp : 
/*
	This drill simply involves getting the sequence of versions of Date to work. For
	each version define a Date called today initialized to June 25, 1978. Then, define a
	Date called tomorrow and give it a value by copying today into it and increasing
	its day by one using add_day(). Finally, output today and tomorrow using a <<
	defined as in §9.8.
	Your check for a valid date may be very simple. Feel free to ignore leap years.
	However, don't accept a month that is not in the [1,12] range or day of the month
	that is not in the [1,31] range. Test each version with at least one invalid date (e.g.,
	2004, 13, -5).
		1. The version from §9.4.1
*/

#include <iostream>
#include <stdexcept>


// Simple Date (too simple?)
struct Date
{
	// Year
	int y;
	// Month in year
	int m;
	// Day of month
	int d;
};

// Helper functions forward declaration
void init_day(Date& dd, int y, int m, int d);
void add_day(Date& dd, int n);
std::ostream& operator<<(std::ostream& os, const Date& d);


int main()
{
	// Task 1: Initialize date from Task (June 25, 1978)
	Date today;
	init_day(today, 1978, 6, 25);
	// Task 2: define a Date called tomorrow and give it a value by copying today into it and increasing its day by one using add_day()
	Date tomorrow{ today };
	add_day(tomorrow, 1);
	// Task 3: Test with invalid date (2004, 13, -5)
	try
	{
		Date invalid;
		init_day(invalid, 2004, 13, -5);

	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what();
	}

	// Task 4: output today and tomorrow

	std::cout << "Today\n\t" << today << "\n";
	std::cout << "Tomorrow\n\t" << tomorrow << "\n";
}

void init_day(Date& dd, int y, int m, int d)
{
	// Check legit years
	if (y < 0)
	{
		throw std::invalid_argument("Negative years are not supported!");
	}
	// Check valid month
	if (m <= 0 || m > 12)
	{
		throw std::invalid_argument("Input month is not supported\n");
	}
	// Check valid days without consideration of month
	if (d <= 0 || d > 31)
	{
		std::string Error{ "Input day is not supported\n" + d };
		throw std::invalid_argument(Error);
	}
	// Check if days in given month are valid
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (d > 31)
		{
			std::string Error{ "Input day exceeds the maximum number of day in this months: " + d };
			throw std::invalid_argument(Error);
		}
	}
	else if (m == 2)
	{
		if (d > 28)
		{
			std::string Error{ "Input day exceeds the maximum number of day in February: " + d };
			throw std::invalid_argument(Error);
		}
	}
	else
	{
		if (d > 30)
		{
			std::string Error{ "Input day exceeds the maximum number of day in this months: " + d };
			throw std::invalid_argument(Error);
		}
	}

	// Initialize day when no error occurs
	dd.y = y;
	dd.m = m;
	dd.d = d;
}

void add_day(Date& dd, int n)
{
	// Check how many days a month can have
	int maxNumOfDays{};
	// Actual month
	int m = dd.m;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		maxNumOfDays = 31;
	}
	else if (m == 2)
	{
		maxNumOfDays = 28;

	}
	else
	{
		maxNumOfDays = 30;
	}
	if (dd.d + n > maxNumOfDays)
	{
		dd.d = 1;
		if (dd.m + 1 > 12)
		{
			dd.m = 1;
			dd.y = ++dd.y;
		}
		else
		{
			dd.m = ++dd.m;
		}
	}
	else
	{
		dd.d = ++dd.d;
	}
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
	return os << '(' << d.y
		<< ',' << d.m
		<< ',' << d.d << ')';
}
