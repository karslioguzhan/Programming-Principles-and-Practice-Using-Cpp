/*  03_Exercise.cpp : Create a vector of Fibonacci numbers and print them using the function from exercise 2. 
    To create the vector, write a function, fibonacci(x, y, v, n), where integers x and y are ints, v is an empty
    vector<int>, and n is the number of elements to put into v; v[0] will be x and v[1] will be y.A Fibonacci
    number is one that is part of a sequence where each element is the sum of the two previous ones.For example,
    starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, ....Your fibonacci() function should make such a sequence
    starting with its x and y arguments.
*/

#include <iostream>
#include <sstream>
#include <vector>

std::stringstream print(std::string label, std::vector<int>& values);
void fibonaccciCalculator(int xFirstValue, int ySecondValue, std::vector<int>& emptyVector, int nNumberOfElements);

int main()
{
    std::vector<int> emptyVector;
    int xFirstValue{ 1 }, ySecondValue{ 2 }, numOfElements{ 7 };
    fibonaccciCalculator(xFirstValue, ySecondValue, emptyVector, numOfElements);
    std::stringstream label;
    label << "Fibonacci of " << numOfElements << " Elements";
    std::cout << print(label.str(), emptyVector).str();
}

std::stringstream print(std::string label, std::vector<int>& values)
{
    std::stringstream output;
    output << label << ":\t";
    for (auto elementVector : values)
    {
        output << " " << elementVector;
    }
    output << "\n";
    return output;
}

void fibonaccciCalculator(int xFirstValue, int ySecondValue, std::vector<int>& emptyVector, int nNumberOfElements)
{
    static int numOfCalls{ 1 };
    // Checking if vector is not empty (first call)
    if (!emptyVector.empty() && numOfCalls == 0)
    {
        std::cout << "Error: Vector is not empty\n";
        return;
    }
    // Boundary check
    constexpr int maxInt{ std::numeric_limits<int>::max() };
    if (xFirstValue > maxInt || ySecondValue > maxInt)
    {
        std::cout << "Error: Exceeding maximum possible int value\n";
    }
    //// First call
    //if (numOfCalls == 0)
    //{

    //}

    // Check if maximum number of calls is exceeded
    if (numOfCalls > nNumberOfElements)
    {
        return;
    }
    emptyVector.push_back(xFirstValue);
    numOfCalls++;
    return fibonaccciCalculator(ySecondValue, ySecondValue + xFirstValue, emptyVector, nNumberOfElements);

}
