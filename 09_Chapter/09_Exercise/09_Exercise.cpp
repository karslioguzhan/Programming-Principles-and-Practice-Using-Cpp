// 09_Exercise.cpp : Create a Library class. Include vectors of Books and Patrons. Include a
// struct called Transaction.Have it include a Book, a Patron, and a Date
// from the chapter.Make a vector of Transactions.Create functions to add
// books to the library, add patrons to the library, and check out books.
// Whenever a user checks out a book, have the library make sure that both
// the user and the book are in the library.If they aren't, report an error.
// Then check to make sure that the user owes no fees.If the user does,
// report an error.If not, create a Transaction, and place it in the vector of
// Transactions.Also write a function that will return a vector that contains
// the names of all Patrons who owe fees.

#include <iostream>
#include "HelperTypes.h"
#include "Book.h"
#include "Library.h"

int main()
{
	try
	{
		gerne actualGerne{ gerne::fiction };
		ISBN actualISBN{ "123-456-789-A" };
		Date copyRightDate{ 16,1,1993 };
		std::string author{ "Oguzhan" };
		std::string title{ "CppBook" };
		Book firstBook{ actualISBN, title, copyRightDate, author, true , actualGerne };
		std::cout << "Book:\t\t\t" << firstBook.getTitle() << "\nAuthor:\t\t\t" << firstBook.getAuthor() << "\n" << "Copyright date:\t\t";
		firstBook.getCopyRightDate().printDate();
		std::cout << "Gerne: " << "\t\t\t" << firstBook.getGerne() << "\n";
		std::cout << "Checked out: " << (firstBook.getIsCheckedOut() ? "\t\ttrue\n" : "\t\tfalse\n");
		// Operator overloading
		Book secondBook{ firstBook };
		ISBN newISBN{ "222-456-789-A" };
		secondBook.setISBN10(newISBN);
		std::cout << "Check for equality: \t" << (firstBook == firstBook) << "\n";
		std::cout << "Check for inequality: \t" << (firstBook != secondBook) << "\n";

		// Library
		Library libraryObject;
		libraryObject.addBook(firstBook);
		Patron firstPatron("Oguzhan", 123456, 0);
		//firstPatron.setFee(10); Testing behaivor when have fees
		libraryObject.addPatron(firstPatron);
		Date checkoutDate{ 01,10,2024};
		libraryObject.checkoutBook(firstBook, firstPatron, checkoutDate);
		Patron secondPatron("Tony", 1232323, 10);
		Patron thirdPatron("Larry", 515058, 1000);
		libraryObject.addPatron(secondPatron);
		libraryObject.addPatron(thirdPatron);
		libraryObject.printPatronWithFees();


	}
	catch (const std::exception& exc)
	{
		std::cerr << exc.what();
		return -1;
	}
}

