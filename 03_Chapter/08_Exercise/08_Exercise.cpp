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

