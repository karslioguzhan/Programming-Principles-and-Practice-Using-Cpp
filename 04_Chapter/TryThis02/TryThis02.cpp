// TryThis02.cpp : Rewrite your currency converter program from the previous Try this to use a switch-statement. Add conversions from yuan and kroner.
//  Which version of the program is easier to write, understand, and modify? Why?

#include <iostream>


int main()
{
    // exchange rates from 05.11.2023
    constexpr double yenToDollar{ 0.0067 };
    constexpr double euroToDollar{ 1.07 };
    constexpr double poundsToDollar{ 1.24 };
    constexpr double yuanToDollar{ 0.14 };
    constexpr double kronerToDollar{ 0.091 };

    std::cout << "This programm converts yen, euro and pounds to dollars!";
    std::cout << "You have to enter the amount you want to convert with the currency for example: 124.4 e\n";
    std::cout << "\tEuro --> e; Yen --> y; Pounds --> p; Yuan --> c; Kroner --> k\n";
    std::cout << "Please enter values: ";
    double inputAmount{};
    char inputCurrency{ '0' };
    std::cin >> inputAmount >> inputCurrency;
    double dollars{}, selectedCurrency{};
    std::string currency;

    switch (inputCurrency)
    {
        case 'e':
            currency = "Euro";
            selectedCurrency = euroToDollar;
            break;
        case 'y':
            currency = "Yen";
            selectedCurrency = yenToDollar;
            break;
        case 'p':
            currency = "Pounds";
            selectedCurrency = poundsToDollar;
            break;
        case 'c':
            currency = "Yuan";
            selectedCurrency = yuanToDollar;
            break;
        case 'k':
            currency = "Kroner";
            selectedCurrency = kronerToDollar;
            break;
        default:
            std::cout << "This currency is not supported\n";
            return 1;
            break;
    }

    dollars = selectedCurrency * inputAmount;
    std::cout << inputAmount << " " << currency << " in $ is " << dollars << std::endl;
    return 0;
}

