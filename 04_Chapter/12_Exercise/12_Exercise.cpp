// 12_Exercise.cpp : Modify the program described in the previous exercise to take an input value max and then find all prime numbers from 1 to max.


#include <iostream>
#include <vector>


bool checkIfPrime(int numberToCheck, std::vector<int> primeNumbers);

int main()
{
    // Assuming first prime number is 2
    std::vector<int> primeNumbers{ 2 };

    int rangeforPrime{ };
    std::cout << "Please insert an maximum integer for looking to prime numbers: ";
    std::cin >> rangeforPrime;

    for (int numIterator{ 3 }; numIterator < rangeforPrime; ++numIterator)
    {
        if (checkIfPrime(numIterator, primeNumbers))
        {
            primeNumbers.push_back(numIterator);
        }
    }

    std::cout << "Found prime Numbers between 1 and 100: \n";
    for (auto primeNumber : primeNumbers)
    {
        std::cout << primeNumber << " | ";
    }
    std::cout << "\nFound total " << primeNumbers.size() << " prime numbers\n";
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
