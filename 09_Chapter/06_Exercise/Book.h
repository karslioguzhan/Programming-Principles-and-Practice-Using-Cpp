#pragma once
#include <chrono>
#include "HelperTypes.h"

//Class Book should have members for the ISBN, title, author, and copyright date.
//This exercise and the next few require you to design and implement a Book class, such as you can imagine as part of software for a library.Class Book should have members for the ISBN, title, author, and copyright date.Also store data on whether or not the book is checked out.Create functions for returning those data values.Create functions for checking a book in and out.Do simple validation of data entered into a Book; for example, accept ISBNs only of the form n - n - n - x where n is an integer and x is a digit or a letter.Store an ISBN as a string.

class Book
{
private:
	ISBN ISBN10;
	std::string title;
	std::string author;
	Date copyRightDate;
	bool isCheckedOut;
public:
	Book(ISBN inputISBN, std::string inputTitle, Date inputDate, std::string inputAuthor, bool inputIsCheckedOut);
	ISBN getISBN10() const;
	void setISBN10(ISBN newISBN10);
	std::string getTitle() const;
	std::string getAuthor() const;
	Date getCopyRightDate() const;
	bool getIsCheckedOut() const;
	void setIsCheckedOut(bool inputIsCheckedOut);
	// Operator overloading
	friend bool operator==(const Book& firstBook, const Book& secondBook);
	friend bool operator!=(const Book& firstBook, const Book& secondBook);
};

