#pragma once
#include <iostream>
#include <sstream>
#include <ostream>
#include <chrono>

namespace Chrono
{
	class Date
	{
	public:
		class Invalid {};

		Date(std::chrono::year inputYear, std::chrono::month inputMonth, std::chrono::day inputDay);
		Date();
		std::chrono::year_month_day getActualDate() const;
		long int numberOfDays();

	private:
		std::chrono::year_month_day actualDate{};
		std::chrono::year_month_day defaultDate{ std::chrono::year{1970},std::chrono::January ,std::chrono::day{1} };
		long int daysAfterDefault{};
	};
}
