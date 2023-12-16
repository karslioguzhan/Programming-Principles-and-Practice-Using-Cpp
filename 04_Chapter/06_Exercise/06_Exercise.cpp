// 06_Exercise.cpp : Make a vector holding the ten string values "zero", "one", … "nine". Use that in a program that converts a digit to its corresponding spelled-out value; e.g., the input 7 gives the output seven. Have the same program, using the same input loop, convert spelled-out numbers into their digit form; e.g., the input seven gives the output 7.
//

#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::cout << "This programs converts number from 0 to 9 to strings or strings to number\n";
    std::cout << "Select if you want int to string conversion with entering 0 or string to int with 1\nto terminate enter 3\n";
    int selection{};
    std::vector<int> stringToNum{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<std::string> numToString{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    while (selection != 3)
    {
        std::cout << "Please enter selection: ";
        std::cin.clear();
        std::cin >> selection;
        if (selection != 0 && selection != 1 && selection != 3)
        {
            std::cout << "Wrong selection!\n";
            continue;
        }
        if (selection == 0)
        {
            std::cout << "Please enter number of desired string: ";
            int input;
            std::cin >> input;
            for (int numIterator{ 0 }; numIterator < 10; ++numIterator)
            {
                if (input == stringToNum.at(numIterator))
                {
                    std::cout << "The string of the number " << input << " is " << numToString.at(numIterator) << "\n";
                    break;
                }
            }
        }
        if (selection == 1)
        {
            std::cout << "Please enter string of desired number: ";
            std::string input;
            std::cin >> input;
            for (int numIterator{ 0 }; numIterator < 10; ++numIterator)
            {
                if (input == numToString.at(numIterator))
                {
                    std::cout << "The number of " << input << " is " << numIterator << "\n";
                    break;
                }
            }
        }
        if (selection == 3)
        {
            std::cout << "Goodbye \n";
            return 0;
        }

    }
    std::cout << "Hello World!\n";
}


