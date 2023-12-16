// 04_Exercise.cpp : Write a program to play a numbers guessing game. The user thinks of a number between 1 and 100 and your program asks questions to figure out what the number is (e.g., “Is the number you are thinking of less than 50?”). Your program should be able to identify the number after asking no more than seven questions. Hint: Use the < and <= operators and the if-else construct.
//

#include <iostream>
#include <sstream>
#include <vector>

// Function prototypes
std::stringstream printMenu();
int guessNumber();

int main()
{
    std::cout << printMenu().str();
    int guessedNumber{ guessNumber() };
    std::cout << "The number you thought is: " << guessedNumber << " \n";

    return 0;
}

std::stringstream printMenu()
{
    std::stringstream menuStream;
    menuStream << "===============================\n";
    menuStream << "Number guessing game\nPlease guess an natural number between 1 and 100\n";
    menuStream << "===============================\n";
    return menuStream;
}

int guessNumber()
{
    std::vector<int> possibleNumber;
    for (int number{ 1 }; number <= 100; ++number)
    {
        possibleNumber.push_back(number);
    }
    std::cout << possibleNumber.at(49) << std::endl;

    do
    {
        if (possibleNumber.size() == 2)
        {
            std::cout << "Is your number even?\n";
            std::cout << "Enter Y if yes and N for no: ";
            std::string inputAnswer;
            std::cin >> inputAnswer;
            if (inputAnswer != "Y" && inputAnswer != "N")
            {
                std::cout << "Wrong Input!\n";
                continue;
            }
            if (inputAnswer == "Y")
            {
                for (auto numElement : possibleNumber)
                {
                    if (numElement % 2 == 0)
                    {
                        return numElement;
                    }
                }
            }
            if (inputAnswer == "N")
            {
                for (auto numElement : possibleNumber)
                {
                    if (numElement % 2 != 0)
                    {
                        return numElement;
                    }
                }
            }
        }
        std::cout << "Is your number between " << *possibleNumber.begin() << " and " << possibleNumber.at(possibleNumber.size() / 2) << "\n";
        std::string inputAnswer;
        std::cout << "Enter Y if yes and N for no: ";
        std::cin >> inputAnswer;
        if (inputAnswer != "Y" && inputAnswer != "N")
        {
            std::cout << "Wrong Input!\n";
        }
        if (inputAnswer == "Y")
        {
            possibleNumber.erase(possibleNumber.begin() + static_cast<int>(possibleNumber.size() / 2 + 1), possibleNumber.begin() + static_cast<int>(possibleNumber.size()));
        }
        if (inputAnswer == "N")
        {
            possibleNumber.erase(possibleNumber.begin(), possibleNumber.begin() + static_cast<int>(possibleNumber.size() / 2));
        }

    } while (possibleNumber.size() != 1);


    return 0;
}
