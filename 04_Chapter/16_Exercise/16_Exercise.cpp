// 16_Exercise.cpp :  In the drill, you wrote a program that, given a series of numbers, found the max and min of that series. The number that appears the most times in a sequence is called the mode. Create a program that finds the mode of a set of positive integers.
//

#include <iostream>
#include <vector>
#include <algorithm>

// Function prototypes
std::vector<int> numOfAppearance(const std::vector<int> sequenceInterger);

int main()
{
    std::cout << "Printing doubles until | is inserted\n";
    double input{};
    std::vector<int> sequenceIntegers;
    std::cout << "Please enter one double: ";
    while (std::cin >> input)
    {
        if (input == '|')
        {
            std::cout << "Terminating the program\n";
            break;
        }
        sequenceIntegers.push_back(input);
        std::cout << "Please enter one double: ";
    }
    std::sort(sequenceIntegers.begin(), sequenceIntegers.end());
    std::cout << "The smallest number is " << sequenceIntegers.front() << "\n"
        << "The largest number is " << sequenceIntegers.back() << "\n";
    std::vector<int> countAndMaxNum{ numOfAppearance(sequenceIntegers) };
    std::cout << "The most appearing number is " << countAndMaxNum.at(1) << " and appears " << countAndMaxNum.at(0) << " times\n";

    return 0;

}

std::vector<int> numOfAppearance(const std::vector<int> sequenceInterger)
{
    int foundMaxCount{}, foundMaxInteger{};
    for (auto integerElement : sequenceInterger)
    {
        int count{ 0 };
        for (auto compareInteger : sequenceInterger)
        {
            if (compareInteger == integerElement)
            {
                count++;
            }
        }
        if (count >= foundMaxCount)
        {
            foundMaxCount = count;
            foundMaxInteger = integerElement;
        }
    }
    std::vector<int> countAndInteger{ foundMaxCount, foundMaxInteger };
    return countAndInteger;
}
