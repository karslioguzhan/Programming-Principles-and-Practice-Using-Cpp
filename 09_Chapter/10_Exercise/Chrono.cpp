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
		if (m<Month::jan || Month::dec >m) return false;

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

	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year() && a.month() == b.month() && a.day() == b.day();
	}

	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}

	std::ostream& operator<<(std::ostream os, const Date& d)
	{
		return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
	}

	// TODO continue here page 337
}