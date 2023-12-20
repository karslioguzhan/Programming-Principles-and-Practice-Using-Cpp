// 17_Exerecise.cpp : Write a program that finds the min, max, and mode of a sequence of strings. 
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

// Function prototypes
std::stringstream findMode(const std::vector<std::string> sequenceOfStrings);

int main()
{
    std::vector<std::string> sequenceOfStrings;
    std::string input;
    bool terminateSession{ false };
    do
    {
        std::cout << "Please enter an string. You can Terminate with entering END: ";
        std::cin >> input;
        if (input != "END" && input != "")
        {
            sequenceOfStrings.push_back(input);
        }
        if (input == "END")
        {
            terminateSession = true;
        }
    } while (!terminateSession);

    std::sort(sequenceOfStrings.begin(), sequenceOfStrings.end(), [](std::string a, std::string b)
        {
            return (a.length() < b.length());
        });

    std::cout << "The smallest string is \"" << sequenceOfStrings.front() << "\" and the largest string is \""
        << sequenceOfStrings.back() << "\"\n";
    std::cout << findMode(sequenceOfStrings).str();


    return 0;
}

std::stringstream findMode(const std::vector<std::string> sequenceOfStrings)
{
    std::stringstream outputMode;
    std::vector<std::string> uniqueVector{ sequenceOfStrings };
    auto lastIterator{ std::unique(uniqueVector.begin(), uniqueVector.end()) };
    uniqueVector.erase(lastIterator, uniqueVector.end());
    if (uniqueVector.size() == sequenceOfStrings.size())
    {
        outputMode << "All the strings only appeare once!\n";
        return outputMode;
    }
    int count{ 1 };
    int countMax{ 1 };
    std::string modeElement;
    std::vector<std::string>::iterator iteratorMax;

    // Counting identical elements
    for (auto elementsUnique : uniqueVector)
    {
        count = 0;
        for (auto elements : sequenceOfStrings)
        {
            if (elementsUnique == elements)
            {
                ++count;
            }
        }
        if (count > countMax)
        {
            countMax = count;
            modeElement = elementsUnique;
        }
    }
    outputMode << "The string \"" << modeElement << "\" is the mode and appears " << countMax << " times\n";
    return outputMode;
}
