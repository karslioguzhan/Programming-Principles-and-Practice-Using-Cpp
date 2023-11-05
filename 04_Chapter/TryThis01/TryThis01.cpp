// TryThis01.cpp : Use the example above as a model for a program that converts yen, euros, and pounds into dollars. 
// If you like realism, you can find conversion rates on the web.
//

#include <iostream>

int main()
{
    // exchange rates from 05.11.2023
    constexpr double yenToDollar{ 0.0067 };
    constexpr double euroToDollar{ 1.07 };
    constexpr double poundsToDollar{ 1.24 };

    std::cout << "This programm converts yen, euro and pounds to dollars!";
    std::cout << "You have to enter the amount you want to convert with the currency for example: 124.4 e\n";
    std::cout << "\tEuro --> e; Yen --> y; Pounds --> p\n";
    std::cout << "Please enter values: ";
    double inputAmount{};
    char inputCurrency{ '0' };
    std::cin >> inputAmount >> inputCurrency;
    double dollars{};
    std::string currency;

    if (inputCurrency == 'y')
    {
        dollars = inputAmount * yenToDollar;
        currency = "yen";
    }
    else if (inputCurrency == 'e')
    {
        dollars = inputAmount * euroToDollar;
        currency = "euro";
    }
    else if (inputCurrency == 'p')
    {
        dollars = inputAmount * poundsToDollar;
        currency = "pounds";
    }
    else
    {
        std::cout << "Wrong unit. Terminate program!\n";
        return 1;
    }

    std::cout << inputAmount << " " << currency << " in $ is " << dollars << std::endl;
    return 0;
}

