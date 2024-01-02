// 19_Exercise.cpp : Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22. For each pair, add the name to a vector called names and the number to a vector called scores (in corresponding positions, so that if names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. Check that each name is unique and terminate with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// Function prototypes
std::stringstream printMenu();
std::stringstream printRequest();
std::vector<std::string> getNamePairs();
std::stringstream printResults(std::vector<std::string> names, std::vector<int> ages);

int main()
{
    std::cout << printMenu().str();
    bool continueInput{ true };
    std::vector<std::string> names;
    std::vector<int> ages;
    do
    {
        std::vector<std::string> namePairs{ getNamePairs()};
        continueInput = !namePairs.empty();
        if (continueInput)
        {
            std::string checkedName{ namePairs.at(0) };
            bool isAvailable{ std::any_of(names.begin(), names.end(),[checkedName](std::string search) {return search == checkedName; }) };
            if (isAvailable)
            {
                std::cout << checkedName << " already exists!\n";
                break;
            }
            names.push_back(namePairs.at(0));
            ages.push_back(std::stoi(namePairs.at(1)));
        }
    } while (continueInput);
    std::cout << printResults(names, ages).str();
    return 0;
}

std::stringstream printMenu()
{
    std::stringstream menu;
    menu << "=========================\n" <<
        "Name and age inserter\n" << "=========================\n";
    return menu;
}

std::stringstream printRequest()
{
    std::stringstream request;
    request << "Enter a name with following with a whitespace and a age\n" <<
        "For example \"Anna 15\"\nYou can terminate with \"NoName 0\"\n" <<
        "Please enter: ";
    return request;
}

std::vector<std::string> getNamePairs()
{
    bool continueInput{ true };
    std::string input;
    do
    {
        std::vector<std::string> namePairs;
        std::cout << printRequest().str();
        std::getline(std::cin, input);
        std::stringstream values(input);
        std::string temp;
        while (values >> temp)
        {
            namePairs.push_back(temp);
        }
        if (namePairs.size() != 2)
        {
            std::cout << "Wrong input! Try again\n";
        }
        if (namePairs.at(0) == "NoName" && namePairs.at(1) == "0")
        {
            return std::vector<std::string>();
        }
        if (namePairs.size() == 2)
        {
            continueInput = false;
            return namePairs;
        }
    } while (continueInput);
}

std::stringstream printResults(std::vector<std::string> names, std::vector<int> ages)
{
    std::stringstream result;
    for (int numElement{ 0 }; numElement < names.size(); ++numElement)
    {
        result << "Name:\t" << names.at(numElement) << "\tAge:\t" << ages.at(numElement) << "\n";
    }
    return result;
}

