// TryThis09.cpp : Find a pair of values so that the pre-condition of this version of area holds, but the post-condition doesn’t.

#include <iostream>
#include "std_lib_facilities.h"

int area(int length, int width)
// Calculate area of a rectangle
// Preconditions: length and width are positive
// Postconditions: returns a positive vale that is the area
{
    if (length <= 0 || width <= 0)
    {
        error("area() precondition");
    }
    int a = length * width;
    if (a <= 0)
    {
        error("area() postcondition"); // 1000000 and 1000000 are ok for precondition but not for the postcondition --> int overflow --> negative value is calculated in my compiler
    }
    return a;
}

int main()
{
    while (true)
    {
        int inputLength{}, inputWidth{};
        std::cout << "Please enter two integer values separated with an empty space: ";
        std::cin >> inputLength >> inputWidth;
        std::cout << "Area of square: " << area(inputLength, inputWidth) << "\n";
    }
    return 0;
}
