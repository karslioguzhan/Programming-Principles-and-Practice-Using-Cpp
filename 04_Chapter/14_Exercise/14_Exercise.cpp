// 14_Exercise.cpp : Modify the program described in the previous exercise to take an input value max and then find all prime numbers from 1 to max.

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "Please enter a maximum number to search for prime numbers: ";
    int maxNum{};
    std::cin >> maxNum;
    const int maxNumInit{ maxNum};
    std::vector<int> consecutiveIntegers;
    for (int numIterator{ 2 }; numIterator <= maxNum; ++numIterator)
    {
        consecutiveIntegers.push_back(numIterator);
    }

    for (int numVectorElement{ 0 }; numVectorElement < consecutiveIntegers.size(); ++numVectorElement)
    {
        int intVector{ consecutiveIntegers.at(numVectorElement) };
        int increment{ 2 };
        int removeNumber{};
        maxNum = consecutiveIntegers.back();
        while (removeNumber <= maxNum)
        {
            removeNumber = increment * intVector;
            auto beginOfVector{ consecutiveIntegers.begin() };
            auto endOfVector{ consecutiveIntegers.end() };
            auto pastEndIterator{ std::remove_if(beginOfVector, endOfVector, [removeNumber](int x) {return removeNumber == x; }) };
            consecutiveIntegers.erase(pastEndIterator, endOfVector);
            ++increment;
        }
    }

    std::cout << "Found prime numbers till " << maxNumInit << " are: \n";
    for (auto primeNumber : consecutiveIntegers)
    {
        std::cout << primeNumber << " | ";
    }
    std::cout << "\nTotal count of prime numbers are: " << consecutiveIntegers.size() << "\n";

}
