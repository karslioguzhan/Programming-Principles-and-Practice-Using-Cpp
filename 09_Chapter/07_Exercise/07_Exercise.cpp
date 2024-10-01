// 07_Exercise.cpp : Create an enumerated type for the Book class called Genre. Have the
// types be fiction, nonfiction, periodical, biography, and children. Give
// each book a Genre and make appropriate changes to the Book constructor and member functions.
//

#include <iostream>
#include "HelperTypes.h"
#include "Book.h"

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
		std::cout << "Check for equality: " << (firstBook == firstBook) << "\n";
		std::cout << "Check for inequality: " << (firstBook != secondBook) << "\n";
	}
	catch (const std::exception& exc)
	{
		std::cerr << exc.what();
		return -1;
	}
}

