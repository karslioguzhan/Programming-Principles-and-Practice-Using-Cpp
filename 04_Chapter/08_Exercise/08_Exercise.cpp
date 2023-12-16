// 08_Exercise.cpp : There is an old story that the emperor wanted to thank the inventor of the game of chess and asked the inventor to name his reward. The inventor asked for one grain of rice for the first square, 2 for the second, 4 for the third, and so on, doubling for each of the 64 squares. That may sound modest, but there wasn’t that much rice in the empire! Write a program to calculate how many squares are required to give the inventor at least 1000 grains of rice, at least 1,000,000 grains, and at least 1,000,000,000 grains. You’ll need a loop, of course, and probably an int to keep track of which square you are at, an int to keep the number of grains on the current square, and an int to keep track of the grains on all previous squares. We suggest that you write out the value of all your variables for each iteration of the loop so that you can see what’s going on.
//

#include <iostream>
#include <cmath>

// Function prototypes
bool printRiceRequirment(int numField,int neededRice, unsigned long int	 accumulatedRiceGrains);

int main()
{
    const int numOfFields{ 64 };
    unsigned long int riceGrainsInField{ 0 };
    unsigned long int  accumulatedRiceGrains{ 0 };
    bool wasExecuted1000{ false }, wasExecuted1000000{ false }, wasExecuted1000000000{ false };

    for (int numField{ 0 }; numField < numOfFields; ++numField)
    {
        riceGrainsInField = std::pow(2, numField);
        accumulatedRiceGrains += riceGrainsInField;
        std::cout << "In the field " << (numField +1) << " you have " << riceGrainsInField << " grains of rice!\n";
        if (!wasExecuted1000)
        {
            wasExecuted1000 = printRiceRequirment(numField, 1000, accumulatedRiceGrains);
        }
        if (!wasExecuted1000000)
        {
            wasExecuted1000000 = printRiceRequirment(numField, 1000000, accumulatedRiceGrains);
        }
        if (!wasExecuted1000000000)
        {
            wasExecuted1000000000 = printRiceRequirment(numField, 1000000000, accumulatedRiceGrains);
        }
        if (accumulatedRiceGrains > 1000000000)
        {
            return 0;
        }
    }

}

bool printRiceRequirment(int numField, int neededRice, unsigned long int accumulatedRiceGrains)
{
        if (accumulatedRiceGrains >= neededRice)
        {
            std::cout << "===============================\n";
            std::cout << "You will have at least " << neededRice << " grains of rice till field " << (numField +1) << "\n";
            std::cout << "===============================\n";
            return true;
        }
        return false;
}
