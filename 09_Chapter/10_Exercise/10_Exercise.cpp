// 10_Exercise.cpp : Implement leapyear() from §9.8.
//

#include <iostream>
#include "Chrono.h"

int main()
{
    Chrono::Date firstDate(2000, Chrono::Month::apr, 20);
    Chrono::Date secondDate(1900, Chrono::Month::apr, 20);
    std::cout << firstDate << "\n";
    std::cout << "Is leap year: " << Chrono::leapyear(2000) << "\n";
    std::cout << secondDate << "\n";
    std::cout << "Is leap year: " << Chrono::leapyear(1900) << "\n";
}
