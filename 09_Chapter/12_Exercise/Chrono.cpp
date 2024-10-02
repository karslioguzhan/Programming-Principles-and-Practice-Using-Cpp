#include "Chrono.h"
namespace Chrono {
	Date::Date(std::chrono::year inputYear, std::chrono::month inputMonth, std::chrono::day inputDay) :
		actualDate{ inputYear, inputMonth, inputDay }
	{
	}

	Date::Date()
	{
		actualDate = defaultDate;
	}

	std::chrono::year_month_day Date::getActualDate() const
	{
		return actualDate;
	}

	long int Date::numberOfDays()
	{
		std::chrono::sys_days laterDay{ actualDate };
		std::chrono::sys_days defaultDay{ defaultDate };
		std::chrono::days difference{ laterDay - defaultDay };
		daysAfterDefault = difference.count();
		return daysAfterDefault;
	}

}