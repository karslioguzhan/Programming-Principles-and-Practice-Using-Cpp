// 09_Exercise.cpp : Write a program that converts spelled-out numbers such as “zero” and “two” into digits, 
// such as 0 and 2. When the user inputs a number, the program should print out the corresponding digit. 
// Do it for the values 0, 1, 2, 3, and 4 and write out not a number I know if the user enters something 
// that doesn’t correspond, such as stupid computer!.
//

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::cout << "Insert a number as a digit or spelled out from 0 to 4: ";
    std::string input;
    std::cin >> input;
    if (input.length() == 1)
    {
        switch (std::stoi(input))
        {
            case 0:
                std::cout << input << " is spelled out zero\n";
                break;
            case 1:
                std::cout << input << " is spelled out one\n";
                break;
            case 2:
                std::cout << input << " is spelled out two\n";
                break;
            case 3:
                std::cout << input << " is spelled out three\n";
                break;
            case 4:
                std::cout << input << " is spelled out four\n";
                break;
            default:
                std::cout << "Such an stupid computer!\n";
        }
        return 0;
    }
    std::vector<std::string> possibleAnswers{ "zero", "one", "two", "three", "four" };
    bool  found{ false };
    for (int numAnswer{0}; numAnswer < 5; ++numAnswer)
    {
        if (possibleAnswers.at(numAnswer) == input)
        {
            std::cout << "The input " << input << " is in digits: " << numAnswer << "\n";
            return 0;
        }
    }
    std::cout << "Such an stupid computer\n";
    return 0;

}

