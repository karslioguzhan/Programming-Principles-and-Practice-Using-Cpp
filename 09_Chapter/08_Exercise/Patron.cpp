#include "Patron.h"

bool Patron::haveFee() const
{
	if (libraryFees >= 0)
	{
		return true;
	}
	return false;
}

double Patron::getFeeValue() const
{
	return libraryFees;
}

int Patron::getCardNumber() const
{
	return cardNumber;
}

bool Patron::setFee(const double& inputFee)
{
	if (inputFee < 0)
	{
		return false;
	}
	libraryFees = inputFee;
	return true;
}

Patron::Patron(std::string inputName, int inputCardNumber, double inputLibraryFee):
	userName{inputName}, cardNumber{inputCardNumber}, libraryFees{inputLibraryFee}
{
}
