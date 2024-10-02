// 11_Exercise.cpp : Design and implement a set of useful helper functions for the Date class
// with functions such as next_workday() (assume that any day that is not
// a Saturday or a Sunday is a workday) and week_of_year() (assume that
// week 1 is the week with January 1 in it and that the first day of a week is a Sunday).

#include <iostream>
#include "Chrono.h"

int main()
{
	Chrono::Date firstDate(2000, Chrono::Month::apr, 20);
	Chrono::Date secondDate(1900, Chrono::Month::apr, 20);
	std::cout << firstDate << "\n";
	std::cout << "Is leap year: " << Chrono::leapyear(2000) << "\n";
	std::cout << secondDate << "\n";
	std::cout << "Is leap year: " << Chrono::leapyear(1900) << "\n";
	int calendarWeek{ Chrono::week_of_year(firstDate) };
	Chrono::Date nextWork{ Chrono::nextWorkday(firstDate) };
	std::cout << "Next Workday: \n" << nextWork;

}
