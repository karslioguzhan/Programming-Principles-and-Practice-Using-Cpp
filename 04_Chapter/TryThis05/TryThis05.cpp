// TryThis05.cpp : Implement square() without using the multiplication operator; 
// that is, do the x*x by repeated addition (start a variable result at 0 and add x to it x times). 
// Then run some version of “the first program” using that square().

#include <iostream>

int squareWithoutMultiplication(int inputNumber)
{
    int tempVariable{ 0 };
    for (int numIteartion{ 0 }; numIteartion < inputNumber; ++numIteartion)
    {
        tempVariable += inputNumber;
    }
    return tempVariable;
}

int main()
{
    std::cout << "Input an integer that you want to square: ";
    int inputNumber{ 0 };
    std::cin >> inputNumber;
    std::cout << "The square is: " << squareWithoutMultiplication(inputNumber) << std::endl;
    return 0;
}

