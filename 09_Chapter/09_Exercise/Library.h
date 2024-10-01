#pragma once
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Patron.h"
#include "transactions.h"

class Library
{
public:
	void addBook(Book& inputBus);
	void addPatron(Patron& inputPatron);
	bool checkoutBook(const Book& inputBook, const Patron& inputPatron, Date inputDate);
	void printPatronWithFees();

private:
	std::vector<Book> listOfBooks;
	std::vector<Patron> listOfPatrons;
	std::vector<transactions> listOfTransactions;
};

