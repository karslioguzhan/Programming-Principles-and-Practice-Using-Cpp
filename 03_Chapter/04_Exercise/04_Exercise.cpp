// Write a program that prompts the user to enter two integer values. 
// Store these values in int variables named val1 and val2. 
// Write your program to determine the smaller, larger, sum, difference, product, 
// and ratio of these values and report them to the user.
//

#include <iostream>

int main()
{
    std::cout << "Enter please two integer variable for comparision with an whitespace: ";
    int val1, val2;
    std::cin >> val1 >> val2;
    std::cout << "====================================\n";
    std::cout << (val1 > val2 ? "second value is smaller\n" : "first value is smaller\n");
    std::cout << val1 << " - " << val2 << " = " << val1 - val2 << "\n";
    std::cout << val1 << " + " << val2 << " = " << val1 + val2 << "\n";
    std::cout << val1 << " * " << val2 << " = " << val1 * val2 << "\n";
    std::cout << val1 << " / " << val2 << " = " << val1 / val2 << "\n";
    std::cout << "====================================\n";
    return 0;
}