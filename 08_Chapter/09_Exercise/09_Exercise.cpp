// 09_Exercise.cpp : Write a function that given two vector<double>s price and weight computes a value(an "index") 
// that is the sum of all price[i] * weight[i].Make sure to have weight.size() == price.size().

#include <iostream>
#include <vector>

double indexCalculator(const std::vector<double>& price, const std::vector<double>& weight);

int main()
{
    // Random vector for testing purpose
    std::vector<double> weight{ 100, 200, 300 };
    std::vector<double> prices{ 5, 10.1, 20 };
    double index{ indexCalculator(prices, weight) };
    if (index < 0)
    {
        std::cout << "Error: Number of elements are not equal\n";
    }
    std::cout << "Result: " << index << "\n";
}

double indexCalculator(const std::vector<double>& price, const std::vector<double>& weight)
{
    if (price.size() != weight.size())
    {
        return -1;
    }
    double index{ 0 };
    for (int numElement{ 0 }; numElement < price.size(); ++numElement)
    {
        index += price.at(numElement) * weight.at(numElement);
    }
    return index;
}
