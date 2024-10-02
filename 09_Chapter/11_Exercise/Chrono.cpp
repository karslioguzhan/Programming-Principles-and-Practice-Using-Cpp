#include "Chrono.h"
namespace Chrono {

	Date::Date(int yy, Month mm, int dd) :
		y{ yy }, m{ mm }, d{ dd }
	{
		if (!is_date(yy, mm, dd)) throw Invalid();
	}

	const Date& default_date()
	{
		static Date dd{ 2001, Month::jan, 1 };
		return dd;
	}

	Date::Date() :
		y{ default_date().year() }, m{ default_date().month() }, d{ default_date().day() }
	{
	}

	void Date::add_day(int n)
	{
		// TODO
	}

	void Date::add_month(int n)
	{
		// TODO
	}

	void Date::add_year(int n)
	{
		if (m == Month::feb && d == 29 && !leapyear(y + n))
		{
			m = Month::mar;
			d = 1;
		}
		y += n;
	}

	// helper functions
	bool is_date(int y, Month m, int d)
	{
		if (d <= 0) return false;
		if (m<Month::jan || m > Month::dec) return false;

		int days_in_month{ 31 };

		switch (m)
		{
		case Month::feb:
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr:
		case Month::jun:
		case Month::sep:
		case Month::nov:
			days_in_month = 30;
			break;
		}

		if (days_in_month < d) return false;

		return true;
	}

	

	// Exercise 10
	bool leapyear(int y)
	{
		if (y % 100 == 0 && y % 4 == 0 && y%400 == 0)
		{
			return true;
		}
		else if (y % 4 == 0 && y % 100 != 0)
		{
			return true;
		}

		return false;
	}

	// Using chrono c++ library would be better, for the sake of the exercise its done manually 
	int week_of_year(const Date& d)
	{
		int actualMonth{ static_cast<int>(d.month()) };
		int dayOfActualMonth(d.day());
		int numOfDays{ dayOfActualMonth };
		for (int numMonth{1}; numMonth < actualMonth; ++numMonth)
		{
			numOfDays += dayInMonth(Month(numMonth), d.year());
		}
		// Calculate calender week (approximation)
		return numOfDays/7;
	}

	int dayInMonth(Month m, int y)
	{
		int days_in_month{ 31 };

		switch (m)
		{
		case Month::feb:
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr:
		case Month::jun:
		case Month::sep:
		case Month::nov:
			days_in_month = 30;
			break;
		}
		return days_in_month;
	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year() && a.month() == b.month() && a.day() == b.day();
	}

	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}
	
	std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		os << "(" << d.year() << "," << static_cast<int>(d.month()) << "," << d.day() << ")";
		return os;
	}

	std::istream& operator>>(std::istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
		{
			is.clear(std::ios_base::failbit);
			return is;
		}
		dd = Date(y, Month(m), d);
		return is;
	}

	enum class Day
	{
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};

	Day day_of_week(const Date& d)
	{
		// TODO
		return Day::monday;
	}

	Date next_Sunday(const Date& d)
	{
		// TODO
		return d;
	}

	Date next_weekday(const Date& d)
	{
		// TODO
		return d;
	}
}