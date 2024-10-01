#pragma once

#include "Book.h"
#include "Patron.h"
#include "HelperTypes.h"

struct transactions
{
	transactions(Book inputBook, Patron inputPatron, Date inputDate):
		actualBook{ inputBook }, actualPatron{inputPatron}, actualDate{ inputDate }
	{};
	Book actualBook;
	Patron actualPatron;
	Date actualDate;
};