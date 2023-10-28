// Write a program in C++ that converts from miles to kilometers. 
// Your program should have a reasonable prompt for the user to enter a number of miles. 
// Hint: There are 1.609 kilometers to the mile.

#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Hello this program converts miles to kilometers!\n";
    std::cout << "Enter miles that should be converted: ";
    double miles{};
    std::cin >> miles;
    std::cout << miles << " miles are " << miles * 1.609 << " kilometers\n";
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
