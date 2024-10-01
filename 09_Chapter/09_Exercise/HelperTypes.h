#pragma once
#include <chrono>
#include <string>
#include <regex>
#include <iostream>

class ISBN {
public:
	// Constructor (Not the standard ISBN10, just for training purpose)
	ISBN(std::string inputISBN);
	std::string getISBN10();
	friend bool operator==(ISBN const firstISBN, ISBN const secondISBN);
	friend bool operator!=(ISBN const firstISBN, ISBN const secondISBN);
private:
	std::regex pattern;
	std::string ISBN10;
	bool checkValidityISBN10(const std::string inputISBN);
};

class Date
{
private:
	std::chrono::year_month_day date;  // Store the date

public:
	Date(int inputDay, int inputMonth, int inputYear);
	void printDate() const;
	std::chrono::year_month_day getDate() const;
	void setDate(int day, int month, int year);
};

enum class gerne { fiction, nonfiction, periodical, biography, children };

