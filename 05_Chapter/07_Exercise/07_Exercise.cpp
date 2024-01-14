// 07_Exercise.cpp : Quadratic formula
/*
* Quadratic equations are of the form
*   a*x^2 + b*x + c = 0
* To solve these, one uses the quadratic formula:
*   x = (-b+-sqrt(b^2-4ac)/(2a)
* There is a problem though: if b2-4ac is less than zero, then it will fail.
* Write a program that can calculate x for a quadratic equations,
* Create a function that prints out the roots of a quadratic equation, given a, b, c.
* When the program detects an equation with no real roots, have it print out a message.
* How do you know that your results are plausible= Can you check that they are correct?
*/

// Answer: I can calculate manually to check if the results from our program is legit. Alternatively i can use websites like wolfram alpha to check the answer.

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <vector>

void checkIfRealRoot(double a, double b, double c);
std::stringstream printMenu();
std::stringstream printResults(std::vector<double> results);
std::vector<double> inputValues();
std::vector<double> outputCalculation(const std::vector<double> values);



int main()
{
    try
    {
        std::cout << printMenu().str();
        std::vector<double> inputVector{ inputValues() };
        checkIfRealRoot(inputVector.at(0), inputVector.at(1), inputVector.at(2));
        std::vector<double> results{outputCalculation(inputVector)};
        std::cout << printResults(results).str();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what();
        return -1;
    }
    return 0;
}

std::stringstream printMenu()
{
    std::stringstream ssMenu;
    ssMenu << "============================\n" << "Quadratic equation calculator\n" <<
        "============================\n";
    ssMenu << "You have to enter \"a\", \"b\" and \"c\" regarding the equation \n" <<
        "\ta*(x*x)+b*x+c = 0 \n";
    return ssMenu;
}

void checkIfRealRoot(double a, double b, double c)
{
	double result{ b * b - 4 * a * c };
	if (result < 0)
	{
		throw std::logic_error("Cannot handle complex roots!\n");
	}
}

std::vector<double> inputValues()
{
    std::string input;
    std::vector<double> inputValues;
    bool legitInput{ false };
    while (!legitInput)
    {
        std::cout << "Enter double values separated with an empty space: ";
        std::getline(std::cin, input);
        std::string temp{};
        std::stringstream words(input);
        while (words >> temp)
        {
            inputValues.push_back(std::stod(temp));
        }

        if (inputValues.size() != 3)
        {
            std::cout << "Wrong number of inputs!\n";
            inputValues.clear();
            continue;
        }
        legitInput = true;
    }
    return inputValues;
}

std::vector<double> outputCalculation(const std::vector<double> values)
{
    const double a{ values.at(0) }, b{ values.at(1) }, c{ values.at(2) };
    double firstResult{}, secondResult{};
    double rootCalc{ std::sqrt(b * b - 4 * a * c) };
    firstResult = (-b + rootCalc) / (2 * a);
    secondResult = (-b - rootCalc) / (2 * a);
    std::vector<double> results;
    if (firstResult == secondResult)
    {
        results.push_back(firstResult);
        return results;
    }
    results.push_back(firstResult);
    results.push_back(secondResult);
    return results;
}

std::stringstream printResults(std::vector<double> results)
{
    std::stringstream resultOutput;
    resultOutput << "The result of the calculation is: ";
    for (auto resultsElem : results)
    {
        resultOutput << resultsElem << "\t";
    }
    return resultOutput;
}