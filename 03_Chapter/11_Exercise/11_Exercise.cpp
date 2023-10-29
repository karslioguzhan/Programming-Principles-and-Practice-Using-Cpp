// 11_Exercise.cpp : Write a program that prompts the user to enter some number of pennies (1-cent coins),
//  nickels (5-cent coins), dimes (10-cent coins), quarters (25-cent coins), 
// half dollars (50-cent coins), and one-dollar coins (100-cent coins). 
// Query the user separately for the number of each size coin, e.g., 
// “How many pennies do you have?” Then your program should print out something like this:
    // You have 23 pennies.
    // You have 17 nickels.
    // You have 14 dimes.
    // You have 7 quarters.
    // You have 3 half dollars.
    // The value of all of your coins is 573 cents.

#include <iostream>
#include <vector>


int main()
{
    std::vector<std::string> units{ "pennies", "nickels", "dimes", "quarters", "half dollars", "one-dollar coins" };
    std::vector<int> conversion{ 1, 5, 10, 25, 50, 100 };
    std::vector<int> amount;
    for (auto actualUnit : units)
    {
        std::cout << "Please enter number of " << actualUnit << ": ";
        int actualNumber;
        std::cin >> actualNumber;
        amount.push_back(actualNumber);
    }

    int sum{ 0 };
    for (int numUnit{0}; numUnit < units.size(); ++numUnit)
    {
        std::cout << "You have " << amount.at(numUnit) << " " << units.at(numUnit) << ".\n";
        sum += amount.at(numUnit) * conversion.at(numUnit);
    }
    std::cout << "The value of all your coins is " << sum << " cents.\n";




    return 0;
}
