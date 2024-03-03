// 04_Exercise.cpp : Define a class Name_value that holds a string and a value. Rework exercise 19 in Chapter 4 to use a vector<Name_value> instead of two vectors.
// 
// Old exercise description: Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22. For each pair, add the name to a vector called names and the number to a vector called scores (in corresponding positions, so that if names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. Check that each name is unique and terminate with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Name_value
{
private:
    std::string name;
    int age{};
public:
    Name_value(std::string name, int age):
        age{age}, name{name}
    {
    }
    std::string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
};

// Function prototypes
std::stringstream printMenu();
std::stringstream printRequest();
std::vector<std::string> getNamePairs();
std::stringstream printResults(std::vector<Name_value> namesAgesValueVector);


int main()
{
    std::cout << printMenu().str();
    bool continueInput{ true };
    std::vector<Name_value> namesAgesValueVector;
    do
    {
        std::vector<std::string> namePairs{ getNamePairs() };
        continueInput = !namePairs.empty();
        if (continueInput)
        {
            std::string checkedName{ namePairs.at(0) };

            bool isAvailable{ std::any_of(namesAgesValueVector.begin(), namesAgesValueVector.end(),[checkedName](Name_value actualElement) {return actualElement.getName() == checkedName; })};
            if (isAvailable)
            {
                std::cout << checkedName << " already exists!\n";
                continue;
            }
            namesAgesValueVector.push_back(Name_value(namePairs.at(0), std::stoi(namePairs.at(1))));
        }
    } while (continueInput);
    std::cout << printResults(namesAgesValueVector).str();
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

std::stringstream printResults(std::vector<Name_value> namesAgesValueVector)
{
    std::stringstream result;
    for (int numElement{ 0 }; numElement < namesAgesValueVector.size(); ++numElement)
    {
        result << "Name:\t" << namesAgesValueVector.at(numElement).getName() << "\tAge:\t" << namesAgesValueVector.at(numElement).getAge() << "\n";
    }
    return result;
}

