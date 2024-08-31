// 03_Drill.cpp : 
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
		2. The version from §9.4.2
		3. The version from §9.4.3
*/

#include <iostream>
#include <stdexcept>


// Simple Date (too simple?)
class Date
{
	// Year
	int y;
	// Month in year
	int m;
	// Day of month
	int d;
public:
	Date(int inputYear, int inputMonth, int inputDay);
	void add_day(int n);
	int month() { return m; };
	int day() { return d; };
	int year() { return y; };

};

// Helper functions forward declaration
void f();
std::ostream& operator<<(std::ostream& os, const Date& d);


int main()
{
	// Task 1: Initialize date from Task (June 25, 1978)
	Date today{ 1978, 6, 25 };
	// Task 2: define a Date called tomorrow and give it a value by copying today into it and increasing its day by one using add_day()
	Date tomorrow{ today };
	tomorrow.add_day(1);
	// Task 3: Test with invalid date (2004, 13, -5)
	try
	{
		Date invalid{ 2004, 13, -5 };
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what();
	}

	// Task 4: output today and tomorrow
	std::cout << "Today\n\t" << today << "\n";
	std::cout << "Tomorrow\n\t" << tomorrow << "\n";

	// Provided function from the chapter
	f();
}

void f()
{
	Date today{ 2008, 3, 30 };
	std::cout << today << "\n";
	Date tomorrow{ today };
	tomorrow.add_day(1);
	std::cout << tomorrow << "\n";
}

void Date::add_day(int n)
{
	// Check how many days a month can have
	int maxNumOfDays{};
	// Actual month
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
	if (d + n > maxNumOfDays)
	{
		d = 1;
		if (m + 1 > 12)
		{
			m = 1;
			y = ++y;
		}
		else
		{
			m = ++m;
		}
	}
	else
	{
		d = ++d;
	}
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
	Date tempDate{ d };
	return os << '(' << tempDate.year()
		<< ',' << tempDate.month()
		<< ',' << tempDate.day() << ')';
}

// Constructor
Date::Date(int inputYear, int inputMonth, int inputDay)
{
	// Check legit years
	if (inputYear < 0)
	{
		throw std::invalid_argument("Negative years are not supported!");
	}
	// Check valid month
	if (inputMonth <= 0 || inputMonth > 12)
	{
		throw std::invalid_argument("Input month is not supported\n");
	}
	// Check valid days without consideration of month
	if (inputDay <= 0 || inputDay > 31)
	{
		std::string Error{ "Input day is not supported\n" + inputDay };
		throw std::invalid_argument(Error);
	}
	// Check if days in given month are valid
	if (inputMonth == 1 || inputMonth == 3 || inputMonth == 5 || inputMonth == 7 || inputMonth == 8 || inputMonth == 10 || inputMonth == 12)
	{
		if (inputDay > 31)
		{
			std::string Error{ "Input day exceeds the maximum number of day in this months: " + inputDay };
			throw std::invalid_argument(Error);
		}
	}
	else if (inputMonth == 2)
	{
		if (inputDay > 28)
		{
			std::string Error{ "Input day exceeds the maximum number of day in February: " + inputDay };
			throw std::invalid_argument(Error);
		}
	}
	else
	{
		if (inputDay > 30)
		{
			std::string Error{ "Input day exceeds the maximum number of day in this months: " + inputDay };
			throw std::invalid_argument(Error);
		}
	}

	// Initialize day when no error occurs
	y = inputYear;
	m = inputMonth;
	d = inputDay;
}
