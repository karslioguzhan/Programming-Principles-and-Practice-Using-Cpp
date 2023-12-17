// 10_Exercise.cpp : Write a program that plays the game “Rock, Paper, Scissors”. If you are not familiar with the game do some research (e.g., on the web using Google). Research is a common task for programmers. Use a switch-statement to solve this exercise. Also, the machine should give random answers (i.e., select the next rock, paper, or scissors randomly). Real randomness is too hard to provide just now, so just build a vector with a sequence of values to be used as “the next value”. If you build the vector into the program, it will always play the same game, so maybe you should let the user enter some values. Try variations to make it less easy for the user to guess which move the machine will make next.


#include <iostream>
#include <sstream>
#include <string>
#include <map>

// Function prototypes
std::stringstream printMenu();
int randomNumberInRange(const int offset, const int maxValue);
bool validateSelection(std::string input);
std::stringstream compareSelections(const int computerSelection, const int userSelection);

int main()
{
    std::map<std::string, int> possibleSelections{ {"rock", 1},{"paper", 2},{"scissors", 3}};

    std::cout << printMenu().str();
    std::string input;
    do
    {
        std::cout << "Please enter rock, paper or scissors to play or END to terminate: ";
        std::cin >> input;
        if (!validateSelection(input))
        {
            std::cout << "Wrong input!\n";
        }
        if (validateSelection(input) && input != "END")
        {
            int computerSelection{ randomNumberInRange(1,3) };
            int userSelection{ possibleSelections.at(input) };
            std::cout << compareSelections(computerSelection, userSelection).str();
        }

    } while (input != "END");



    return 0;
}

std::stringstream printMenu()
{
    std::stringstream ssMenu;
    ssMenu << "================================\n";
    ssMenu << "Rock, paper and scissors game!\n";
    ssMenu << "================================\n";
    return ssMenu;
}

int randomNumberInRange(const int offset, const int maxValue)
{
    return (offset + (std::rand() % maxValue));
}

bool validateSelection(std::string input)
{
    if (input != "rock" && input != "paper" && input != "scissors" && input != "END")
    {
        return false;
    }
    return true;
}

std::stringstream compareSelections(const int computerSelection, const int userSelection)
{
    // { {"rock", 1},{"paper", 2},{"scissors", 3}};
    std::stringstream ssResult;
    switch (computerSelection)
    {
    case 1:
    {
        if (userSelection == 1)
        {
            ssResult << "Both selected rock. Result is tie\n";
        }
        else if (userSelection == 2)
        {
            ssResult << "Paper beats rock. User wins\n";
        }
        else
        {
            ssResult << "Rock beats scissors. Computer wins\n";
        }
        break;
    }
    case 2:
    {
        if (userSelection == 2)
        {
            ssResult << "Both selected paper. Result is tie\n";
        }
        else if (userSelection == 3)
        {
            ssResult << "Scissors beats paper. User wins\n";
        }
        else
        {
            ssResult << "paper beats rock. Computer wins\n";
        }

        break;
    }
    case 3:
    {
        if (userSelection == 3)
        {
            ssResult << "Both selected scissors. Result is tie\n";
        }
        else if (userSelection == 1)
        {
            ssResult << "Rock beats scissors. User wins\n";
        }
        else
        {
            ssResult << "Scissors beats paper. Computer wins\n";
        }
        break;
    }
    }

    return ssResult;
}
