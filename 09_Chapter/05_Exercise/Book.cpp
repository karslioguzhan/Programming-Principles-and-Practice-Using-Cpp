#include "Book.h"

Book::Book(ISBN inputISBN, std::string inputTitle, Date inputDate, std::string inputAuthor, bool inputIsCheckedOut) :
	ISBN10{ inputISBN }, title{ inputTitle }, author{ inputAuthor }, copyRightDate{ inputDate }, isCheckedOut{ inputIsCheckedOut }
{
}

ISBN Book::getISBN10() const
{
	return ISBN10;
}

std::string Book::getTitle() const
{
	return title;
}

std::string Book::getAuthor() const
{
	return author;
}

Date Book::getCopyRightDate() const
{
	return copyRightDate;
}

bool Book::getIsCheckedOut() const
{
	return isCheckedOut;
}

void Book::setIsCheckedOut(bool inputIsCheckedOut)
{
	isCheckedOut = inputIsCheckedOut;
}
