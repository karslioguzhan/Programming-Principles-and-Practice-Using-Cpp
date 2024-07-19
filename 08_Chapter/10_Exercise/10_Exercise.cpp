// 10_Exercise.cpp : Write a function maxv() that returns the largest element of a vector argument.


#include <iostream>
#include <vector>
#include <algorithm>

double maxc(const std::vector<double>& inputVector);

int main()
{
    std::vector<double> randomNumbers{ 1, 30, 506068, 5074877, 84848484, 0, 9999 }; 
    std::cout << maxc(randomNumbers);
}

double maxc(const std::vector<double>& inputVector)
{
    return *std::max_element(inputVector.begin(), inputVector.end());
}
