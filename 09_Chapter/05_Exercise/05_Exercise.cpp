// 05_Exercise.cpp :This exercise and the next few require you to design and implement a Book class, such as you can imagine as part of software for a library. Class Book should have members for the ISBN, title, author, and copyright date. Also store data on whether or not the book is checked out. Create functions for returning those data values. Create functions for checking a book in and out.Do simple validation of data entered into a Book; for example, accept ISBNs only of the form n - n - n - x where n is an integer and x is a digit or a letter.Store an ISBN as a string.

// Information: Switched C++ Version to ISO C20 (Chrono date was added)

#include <iostream>
#include "HelperTypes.h"
#include "Book.h"

int main()
{
	try
	{
		ISBN actualISBN{ "123-456-789-A" };
		Date copyRightDate{ 16,1,1993 };
		std::string author{ "Oguzhan" };
		std::string title{ "CppBook" };
		Book firstBook{ actualISBN, title, copyRightDate, author, true };
		std::cout << "Book:\t\t\t" << firstBook.getTitle() << "\nAuthor:\t\t\t" << firstBook.getAuthor() << "\n" << "Copyright date:\t\t";
		firstBook.getCopyRightDate().printDate();
		std::cout << "Checked out: " << (firstBook.getIsCheckedOut() ? "\t\ttrue\n" : "\t\tfalse\n");
	}
	catch (const std::exception& exc)
	{
		std::cerr << exc.what();
		return -1;
	}
}

