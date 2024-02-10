// 14_Exercise.cpp : Read (day-of-the-week, value) pairs from standard input. For example
//  Tuesday 23 Friday 56 Tuesday -3 Thursday 99
// Collect all the values for each day of the week in a vector<int>. Write out the values of the seven day-of-the-week vectors. Print out the sum of values in each vector. Ignore illegal days of the week, such as Funday, but accept common synonyms such as Mon and monday. Write out the number of rejected values.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

std::string getUserInput();
void cleanUserInput(const std::string userInput, std::vector<int>& valueOfDay, std::vector<int>& rejectedValueOfDay, std::vector<std::string>& nameOfDay, std::vector<std::string>& rejectedNameOfDay);


int main()
{
    std::cout << "Enter as many \"day-of-the-week, value\" pairs as you like.\n For example Tuesday 23 Friday 56\n Please enter: ";
    std::string userInput{ getUserInput() };
    std::vector<int> valueOfDay, rejectedValueOfDay;
    std::vector<std::string> nameOfDay, rejectedNameOfDay;
    cleanUserInput(userInput, valueOfDay, rejectedValueOfDay, nameOfDay, rejectedNameOfDay);
    // Print results
    std::cout << "Rejected Values:\n";
    for (int numRejected{}; numRejected < rejectedNameOfDay.size(); numRejected++)
    {
        std::cout << "\tName: " << rejectedNameOfDay.at(numRejected) << "\tValue: " << rejectedValueOfDay.at(numRejected) << "\n";
    }
    std::cout << "Number of rejected pairs: " << rejectedNameOfDay.size() << "\n";
    // Legal results
    std::cout << "Legal Values:\n";
    int sum{};
    for (int numAccepted{}; numAccepted < nameOfDay.size(); numAccepted++)
    {
        std::cout << "\tName: " << nameOfDay.at(numAccepted) << "\tValue: " << valueOfDay.at(numAccepted) << "\n";
        sum += valueOfDay.at(numAccepted);
    }
    std::cout << "Number of accepted pairs: " << nameOfDay.size() << "\n";
    std::cout << "Accumulated sum of values: " << sum << "\n";
}

std::string getUserInput()
{

    std::string userInput{};
    bool legitInput{ false };
    do
    {
        std::getline(std::cin, userInput);
        int numOfSpaces{ static_cast<int>(std::count(userInput.begin(), userInput.end(), ' ')) };
        if (numOfSpaces % 2 == 1)
        {
            legitInput = true;
        }
        else
        {
            std::cout << "You don't enter a correct pair!\n Enter again: ";
        }
    } while (!legitInput);

    return userInput;
}

void cleanUserInput(const std::string userInput, std::vector<int>& valueOfDay, std::vector<int>& rejectedValueOfDay, std::vector<std::string>& nameOfDay, std::vector<std::string>& rejectedNameOfDay)
{
    std::vector<std::string> legitDayOfWeeks{ "Monday", "monday", "Mon", "mon", "Tuesday", "tuesday", "Tue", "tue", "Wednesday", "wednesday", "Wed", "wed", "Thursday", "thursday", "Thurs", "thurs", "Friday", "friday", "Fri", "fri", "Saturday", "saturday", "Sat", "sat", "Sunday", "sunday", "Sun", "sun" };

    std::stringstream userInputSS(userInput);
    std::string tempString;
    // int numOfWords{ static_cast<int>( std::count(userInput.begin(), userInput.end(), ' '))+1 };

    std::vector<std::string> userInputAsVector;
    while (userInputSS >> tempString)
    {
        userInputAsVector.push_back(tempString);
    }

    for (int iteratorVector{ 0 }; iteratorVector < userInputAsVector.size(); iteratorVector += 2)
    {
        std::string actualElement{ userInputAsVector.at(iteratorVector) };
        auto iteratorSerach{ std::find(legitDayOfWeeks.begin(), legitDayOfWeeks.end(), actualElement) };
        // Continue if this is not legit
        if (iteratorSerach == legitDayOfWeeks.end())
        {
            rejectedNameOfDay.push_back(userInputAsVector.at(iteratorVector));
            rejectedValueOfDay.push_back(std::stoi(userInputAsVector.at(iteratorVector + 1)));
            continue;
        }
        nameOfDay.push_back(userInputAsVector.at(iteratorVector));
        valueOfDay.push_back(std::stoi(userInputAsVector.at(iteratorVector + 1)));
    }
}
