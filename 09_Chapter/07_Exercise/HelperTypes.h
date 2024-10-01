#pragma once
#include <chrono>
#include <string>
#include <regex>
#include <iostream>


// Class Book should have members for the ISBN, title, author, and copyright date.Also store data on whether or not the book is checked out.Create functions for returning those data values.Create functions for checking a book in and out.Do simple validation of data entered into a Book; for example, accept ISBNs only of the form n - n - n - x where n is an integer and x is a digit or a letter.Store an ISBN as a string.


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

enum class gerne{fiction, nonfiction, periodical, biography, children};
