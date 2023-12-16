// 09_Exercise.cpp : Try to calculate the number of rice grains that the inventor asked for in exercise 8 above. You’ll find that the number is so large that it won’t fit in an int or a double. Observe what happens when the number gets too large to represent exactly as an int and as a double. What is the largest number of squares for which you can calculate the exact number of grains (using an int)? What is the largest number of squares for which you can calculate the approximate number of grains (using a double)?
//

/*
    Conclusion Integer: When reaching the maximal int value you get an integer overflow which is with my compiler the value: -2147483648
    Conclusion Double: The calculation with double will switch to scientific number representation after probably the value get to big.
*/

#include <iostream>
#include <cmath>

// Function prototypes
bool printRiceRequirment(int numField, int neededRice, int accumulatedRiceGrains);

int main()
{
    const int numOfFields{ 64 };
    int riceGrainsInFieldInt{ 0 };
    int  accumulatedRiceGrainsInt{ 0 };
    double riceGrainsInFieldDouble{ 0 };
    double accumulatedRiceGrainsDouble{ 0 };
    bool wasExecuted1000{ false }, wasExecuted1000000{ false }, wasExecuted1000000000{ false };

    for (int numField{ 0 }; numField < numOfFields; ++numField)
    {
        riceGrainsInFieldInt = std::pow(2, numField);
        accumulatedRiceGrainsInt += riceGrainsInFieldInt;
        riceGrainsInFieldDouble = std::pow(2, numField);
        accumulatedRiceGrainsDouble += riceGrainsInFieldDouble;

        std::cout << "In the field " << (numField + 1) << " you have " << riceGrainsInFieldInt << " grains of rice! with Integer\n";
        std::cout << "In the field " << (numField + 1) << " you have " << riceGrainsInFieldDouble << " grains of rice! with Double\n";
        if (!wasExecuted1000)
        {
            wasExecuted1000 = printRiceRequirment(numField, 1000, accumulatedRiceGrainsInt);
        }
        if (!wasExecuted1000000)
        {
            wasExecuted1000000 = printRiceRequirment(numField, 1000000, accumulatedRiceGrainsInt);
        }
        if (!wasExecuted1000000000)
        {
            wasExecuted1000000000 = printRiceRequirment(numField, 1000000000, accumulatedRiceGrainsInt);
        }
    }

}

bool printRiceRequirment(int numField, int neededRice, int accumulatedRiceGrains)
{
    if (accumulatedRiceGrains >= neededRice)
    {
        std::cout << "===============================\n";
        std::cout << "You will have at least " << neededRice << " grains of rice till field " << (numField + 1) << "\n";
        std::cout << "===============================\n";
        return true;
    }
    return false;
}
