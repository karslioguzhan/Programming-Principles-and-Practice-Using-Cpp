// 13_Exercise.cpp : Create a program to find all the prime numbers between 1 and 100. There is a classic method for doing this, called the “Sieve of Eratosthenes”. If you don’t know that method, get on the web and look it up. Write your program using this method.
/*
 From Wikipedia : To find all the prime numbers less than or equal to a given integer n by Eratosthenes’ method:
    1. Create a list of consecutive integers from 2 through n: (2, 3, 4, ..., n).
    2. Initially, let p equal 2, the smallest prime number.
    3. Enumerate the multiples of p by counting in increments of p from 2p to n, and mark them in the list (these will be 2p, 3p, 4p, ...; the p itself should not be marked).
    4. Find the smallest number in the list greater than p that is not marked. If there was no such number, stop. Otherwise, let p now equal this new number (which is the next prime), and repeat from step 3.
    5. When the algorithm terminates, the numbers remaining not marked in the list are all the primes below n.
*/


#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    const int maxNumInit{ 100 };
    int maxNum{ maxNumInit};
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
            auto endOfVector{ consecutiveIntegers.end()};
            auto pastEndIterator{ std::remove_if(beginOfVector, endOfVector, [removeNumber](int x) {return removeNumber == x; }) };
            consecutiveIntegers.erase(pastEndIterator, endOfVector);
            ++increment;
        }
    }
  
    std::cout << "Found prime numbers till" << maxNumInit << " are: \n";
    for (auto primeNumber : consecutiveIntegers)
    {
        std::cout << primeNumber << " | ";
    }
    std::cout << "\nTotal count of prime numbers are: " << consecutiveIntegers.size() << "\n";

}

