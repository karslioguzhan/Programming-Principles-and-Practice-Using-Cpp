#include "HelperTypes.h"
#include <stdexcept>

ISBN::ISBN(std::string inputISBN) :
	pattern("^(\\d+)-(\\d+)-(\\d+)-[a-zA-Z0-9]$")
{
	// Check if input empty
	if (inputISBN.empty())
	{
		throw std::invalid_argument("Input ISBN is empty!");
	}
	if (!checkValidityISBN10(inputISBN))
	{
		throw std::invalid_argument("Input ISBN isn't valid!");
	}
	ISBN10 = inputISBN;
}

std::string ISBN::getISBN10()
{
	return ISBN10;
}

bool ISBN::checkValidityISBN10(const std::string inputISBN)
{
	return std::regex_match(inputISBN, pattern);
}

Date::Date(int inputDay, int inputMonth, int inputYear)
	: date{ std::chrono::year{inputYear}, std::chrono::month{static_cast<unsigned int>(inputMonth)}, std::chrono::day{static_cast<unsigned int>(inputDay)} }
{
}

void Date::printDate() const
{
	std::cout << std::format("{:02}.{:02}.{}", unsigned(date.day()), unsigned(date.month()), int(date.year())) << std::endl;
}

// Getter for the date
std::chrono::year_month_day Date::getDate() const {
	return date;
}

// Setter for the date
void Date::setDate(int day, int month, int year)
{
	date = std::chrono::year_month_day{ std::chrono::year{year}, std::chrono::month{static_cast<unsigned int>(month)}, std::chrono::day{static_cast<unsigned int>(day)} };
}

bool operator==(ISBN const firstISBN, ISBN const secondISBN)
{
	return firstISBN.ISBN10 == secondISBN.ISBN10;
}

bool operator!=(ISBN const firstISBN, ISBN const secondISBN)
{
	return !(firstISBN == secondISBN);
}
