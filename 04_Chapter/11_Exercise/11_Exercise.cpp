// 11_Exercise.cpp : Create a program to find all the prime numbers between 1 and 100. One way to do this is to write a function that will check if a number is prime (i.e., see if the number can be divided by a prime number smaller than itself) using a vector of primes in order (so that if the vector is called primes, primes[0]==2, primes[1]==3, primes[2]==5, etc.). Then write a loop that goes from 1 to 100, checks each number to see if it is a prime, and stores each prime found in a vector. Write another loop that lists the primes you found. You might check your result by comparing your vector of prime numbers with primes. Consider 2 the first prime.
//

#include <iostream>
#include <vector>


bool checkIfPrime(int numberToCheck, std::vector<int> primeNumbers);

int main()
{
    // Assuming first prime number is 2
    std::vector<int> primeNumbers{ 2 };

    const int maxNum{ 100 };
    for (int numIterator{ 3 }; numIterator < maxNum; ++numIterator)
    {
        if(checkIfPrime(numIterator, primeNumbers))
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
