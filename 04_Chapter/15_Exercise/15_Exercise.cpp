// 15_Exercise.cpp : Write a program that takes an input value n and then finds the first n primes.
//

#include <iostream>
#include <vector>
#include <algorithm>

// Function prototypes
bool checkIfPrime(int numberToCheck, std::vector<int> primeNumbers);

int main()
{
    // Assuming first prime number is 2
    std::vector<int> primeNumbers{ 2 };
    const int maxNum{ 10000000 };
    std::cout << "Please insert how many prime numbers you want to find: ";
    int maxNumOfPrimes{};
    std::cin >> maxNumOfPrimes;

    int numOfFoundPrimes{ 1 };
    for (int numIterator{ 3 }; numIterator < maxNum; ++numIterator)
    {
        if (checkIfPrime(numIterator, primeNumbers))
        {
            primeNumbers.push_back(numIterator);
            ++numOfFoundPrimes;
        }
        if (numOfFoundPrimes >= maxNumOfPrimes)
        {
            break;
        }
    }

    std::cout << "The first " << maxNumOfPrimes << " prime numbers are: \n";
    for (auto primeNumber : primeNumbers)
    {
        std::cout << primeNumber << " | ";
    }
    return 0;
}

bool checkIfPrime(int numberToCheck, std::vector<int> primeNumbers)
{
    for (auto primeNumber : primeNumbers)
    {
        if (numberToCheck % primeNumber == 0)
        {
            return false;
        }
    }
    return true;
}