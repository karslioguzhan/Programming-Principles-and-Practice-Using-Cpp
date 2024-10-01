#include "Library.h"

void Library::addBook(Book& inputBus)
{
	listOfBooks.push_back(inputBus);
}

void Library::addPatron(Patron& inputPatron)
{
	listOfPatrons.push_back(inputPatron);
}

bool Library::checkoutBook(const Book& inputBook, const Patron& inputPatron, Date inputDate)
{
	std::vector<Book>::iterator iteratorBook{ std::find_if(listOfBooks.begin(), listOfBooks.end(),
		[&](Book bookOfList) { return bookOfList == inputBook; } )};
	if (iteratorBook == listOfBooks.end())
	{
		std::cerr << "Book not found!\n";
		return false;
	}
	std::vector<Patron>::iterator iteratorPatrons{ std::find_if(listOfPatrons.begin(), listOfPatrons.end(), 
		  [&](Patron actualPatron) {return actualPatron.getCardNumber() == inputPatron.getCardNumber(); }) };
	if (iteratorPatrons == listOfPatrons.end())
	{
		std::cerr << "Patron not found!\n";
		return false;
	}
	if (inputPatron.haveFee())
	{
		std::cerr << "Patron has open fees\n";
		return false;
	}
	transactions tempTransaction{inputBook, inputPatron, inputDate };
	listOfTransactions.push_back(tempTransaction);
	return true;
}

void Library::printPatronWithFees()
{
	std::cout << "List of User with Fees:\n";
	std::for_each(listOfPatrons.begin(), listOfPatrons.end(), [](Patron input)
		{
			if (input.haveFee())
			{
				std::cout << "\tUser name:\t" << input.getUserName() << "\tFee:" << input.getFeeValue() << "\n";
			}
		}
	);
}
