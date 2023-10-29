// 08_Exercise.cpp : Write a program to test an integer value to determine if it is odd or even. 
// As always, make sure your output is clear and complete. 
// In other words, don’t just output yes or no. 
// Your output should stand alone, like The value 4 is an even number. 
// Hint: See the remainder (modulo) operator in §3.4.

#include <iostream>

int main()
{
    std::cout << "Enter an integer for checking if it is odd or even: ";
    int value;
    std::cin >> value;
    std::string result;
    if (value % 2 == 0)
    {
        result = "even";
    }
    else
    {
        result = "odd";
    }
    std::cout << "The value " << value << " is an " << result << " number\n";

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
