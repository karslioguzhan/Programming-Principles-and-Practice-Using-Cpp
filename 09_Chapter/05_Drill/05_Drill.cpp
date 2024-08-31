// 05_Drill.cpp : 
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
		4. The version from §9.7.1
		5. The version from §9.7.4
*/

#include <iostream>
#include <stdexcept>

enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};


class Year
{
	static const int min{ 1800 };
	static const int max{ 2200 };
public:
	class Invalid {};
	Year(int x) : y{ x } { if (x <= min || max <= x) throw std::invalid_argument("Wrong year"); }
	int year() { return y; }
private:
	int y;
};

// Simple Date (too simple?)
class Date
{
public:
	Date(Year inputYear, Month inputMonth, int inputDay);
	Month month() const;
	int day() const;
	int year() const;

	void add_day(int n);
	void add_month(int n);
	void add_year(int n);

private:
	// Year
	Year y;
	// Month in year
	Month m;
	// Day of month
	int d;

};

// Helper functions forward declaration
std::ostream& operator<<(std::ostream& os, const Date& d);


int main()
{
	// Task 1: Initialize date from Task (June 25, 1978)
	Date today{ Year{1978}, Month::jun, 25 };
	// Task 2: define a Date called tomorrow and give it a value by copying today into it and increasing its day by one using add_day()
	Date tomorrow{ today };
	tomorrow.add_day(1);

	Date monthPlus20{ today };
	monthPlus20.add_month(20);

	// Task 3: output today and tomorrow
	std::cout << "Today\n\t" << today << "\n";
	std::cout << "Tomorrow\n\t" << tomorrow << "\n";
	std::cout << "20 Month added\n\t" << monthPlus20 << "\n";


}

void Date::add_day(int n)
{
	// Check how many days a month can have
	int maxNumOfDays{};
	int tempMonth{ static_cast<int>(m) };
	// Actual month
	if (tempMonth == 1 || tempMonth == 3 || tempMonth == 5 || tempMonth == 7 || tempMonth == 8 || tempMonth == 10 || tempMonth == 12)
	{
		maxNumOfDays = 31;
	}
	else if (tempMonth == 2)
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
		if (tempMonth + 1 > 12)
		{
			m = Month::jan;
			add_year(1);
		}
		else
		{
			add_month(1);
		}
	}
	else
	{
		d = ++d;
	}
}

void Date::add_month(int n)
{
	int monthAsInt{ static_cast<int>(m) };
	int yearsCount{ (monthAsInt + n) / 12 };
	add_year(yearsCount);
	int restMonth{ (monthAsInt + n) % 12 };
	m = static_cast<Month>(restMonth);

}

void Date::add_year(int n)
{
	y = Year{ y.year() + n };
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
	Date tempDate{ d };
	return os << '(' << tempDate.year()
		<< ',' << static_cast<int>(tempDate.month())
		<< ',' << tempDate.day() << ')';
}

// Constructor
Date::Date(Year inputYear, Month inputMonth, int inputDay) :
	y{ inputYear }, m{ inputMonth }
{
	int checkMonth{ static_cast<int>(inputMonth) };
	// Check valid days without consideration of month
	if (inputDay <= 0 || inputDay > 31)
	{
		std::string Error{ "Input day is not supported\n" + inputDay };
		throw std::invalid_argument(Error);
	}
	// Check if days in given month are valid
	if (checkMonth == 1 || checkMonth == 3 || checkMonth == 5 || checkMonth == 7 || checkMonth == 8 || checkMonth == 10 || checkMonth == 12)
	{
		if (inputDay > 31)
		{
			std::string Error{ "Input day exceeds the maximum number of day in this months: " + inputDay };
			throw std::invalid_argument(Error);
		}
	}
	else if (checkMonth == 2)
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
	d = inputDay;
}

Month Date::month() const
{
	return m;
}

int Date::day() const
{
	return d;
}

int Date::year() const
{
	Year tempYear{ y };
	return tempYear.year();
}
