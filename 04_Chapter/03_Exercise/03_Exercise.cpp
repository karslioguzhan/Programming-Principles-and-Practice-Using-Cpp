// 03_Exercise.cpp : Read a sequence of double values into a vector. Think of each value as the distance between two cities along a given route. Compute and print the total distance (the sum of all distances). Find and print the smallest and greatest distance between two neighboring cities. Find and print the mean distance between two neighboring cities.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Function prototypes
std::vector <double> distancesCities();
double sumOfDistances(const std::vector <double> inputVector);


int main()
{
    std::cout << "This programs computes the smallest, greatest and the sum of distances from given neighbor cities!\n";
    std::cout << "You can terminate the input with writing \"end\" as input!\n";
    std::vector<double> distancesOfCities = distancesCities();
    std::sort(distancesOfCities.begin(), distancesOfCities.end());
    if (distancesOfCities.size() == 0)
    {
        std::cout << "You don't entered legit values";
        return 0;
    }
    std::cout << "The smallest distance is: " << distancesOfCities.at(0) << "\n";
    std::cout << "The greatest distance is: " << distancesOfCities.at(distancesOfCities.size()-1) << "\n";
    std::cout << "The sum of distances are: " << sumOfDistances(distancesOfCities) << "\n";
    std::cout << "The mean of all distances are: " << sumOfDistances(distancesOfCities) / distancesOfCities.size() << "\n";

    return 0;
}

std::vector<double> distancesCities()
{
    // Empty vector
    std::vector<double> distancesOfCities;
    bool checkVariable{ true };
    do
    {
        std::cout << "Please enter a double value for define the distance between to cities: ";
        std::string input;
        std::cin >> input;
        if (input == "end")
        {
            checkVariable = false;
            break;
        }
        double inputAsDouble{};
        try
        {
            inputAsDouble = std::stod(input);
            distancesOfCities.push_back(inputAsDouble);
        }
        catch(...)
        {
            std::cout << "The input cannot be casted to double!\n";
        }
    } while (checkVariable);

    return distancesOfCities;
}

double sumOfDistances(const std::vector<double> inputVector)
{
    double sum{};
    for (auto numElement : inputVector)
    {
        sum += numElement;
    }
    return sum;
}
