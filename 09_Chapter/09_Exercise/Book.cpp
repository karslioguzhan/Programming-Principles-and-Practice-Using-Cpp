#include "Book.h"

Book::Book(ISBN inputISBN, std::string inputTitle, Date inputDate, std::string inputAuthor, bool inputIsCheckedOut, gerne inputGerne) :
	ISBN10{ inputISBN }, title{ inputTitle }, author{ inputAuthor }, copyRightDate{ inputDate }, isCheckedOut{ inputIsCheckedOut }, gerneBook(inputGerne)
{
}

ISBN Book::getISBN10() const
{
	return ISBN10;
}

void Book::setISBN10(ISBN newISBN10)
{
	ISBN10 = newISBN10;
}

std::string Book::getGerne() const
{
	switch (gerneBook)
	{
	case gerne::fiction:
		return "fiction";
		break;
	case gerne::nonfiction:
		return "nonfiction";
		break;
	case gerne::periodical:
		return "periodical";
		break;
	case gerne::biography:
		return "biography";
		break;
	case gerne::children:
		return "children";
		break;
	default:
		return "no gerne";
		break;
	}
}

void Book::setGerne(gerne inputGerne)
{
	gerneBook = inputGerne;
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

bool operator==(const Book& firstBook, const Book& secondBook)
{
	return firstBook.getISBN10() == secondBook.getISBN10();
}

bool operator!=(const Book& firstBook, const Book& secondBook)
{
	return (firstBook == secondBook);
}
