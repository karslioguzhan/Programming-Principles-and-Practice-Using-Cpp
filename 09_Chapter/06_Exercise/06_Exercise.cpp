// 06_Exercise.cpp : Add operators for the Book class. Have the == operator check whether
// the ISBN numbers are the same for two books.Have != also compare
// the ISBN numbers.Have a << print out the title, author, and ISBN on
// separate lines.

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
		// Operator overloading
		Book secondBook{ firstBook };
		ISBN newISBN{ "222-456-789-A" };
		secondBook.setISBN10(newISBN);
		std::cout << "Check for equality: " << (firstBook == firstBook) << "\n";
		std::cout << "Check for inequality: " << (firstBook != secondBook) << "\n";
	}
	catch (const std::exception& exc)
	{
		std::cerr << exc.what();
		return -1;
	}
}

