#pragma once
#include <string>
class Patron
{
public:
	bool haveFee() const;
	double getFeeValue() const;
	int getCardNumber() const;
	bool setFee(const double& inputFee);
	Patron(std::string inputName, int inputCardNumber, double inputLibraryFee);
private:
	std::string userName;
	int cardNumber{};
	double libraryFees{};
};

