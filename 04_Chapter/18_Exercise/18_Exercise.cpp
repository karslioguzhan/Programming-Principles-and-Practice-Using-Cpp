// 18_Exercise.cpp : Write a program to solve quadratic equations. A quadratic equation is of the form
// ax2 + bx + c = 0
// If you don’t know the quadratic formula for solving such an expression, do some research. Remember, researching how to solve a problem is often necessary before a programmer can teach the computer how to solve it. Use doubles for the user inputs for a, b, and c. Since there are two solutions to a quadratic equation, output both x1 and x2.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

// Function prototypes
std::stringstream printMenu();
std::vector<double> inputValues();
std::vector<double> outputCalculation(const std::vector<double> values);
std::stringstream printResults(std::vector<double>);

int main()
{
    std::cout << printMenu().str();
    std::vector<double> inputVector{ inputValues() };
    if (inputVector.size() != 3)
    {
        return 0;
    }
    std::vector<double> calculationResult{ outputCalculation(inputVector) };
    std::cout << printResults(calculationResult).str();

    return 0;
}

std::stringstream printMenu()
{
    std::stringstream ssMenu;
    ssMenu << "============================\n" << "Quadratic equation calculator\n" <<
        "============================\n";
    ssMenu << "You have to enter \"a\", \"b\" and \"c\" regarding the equation \n" <<
        "\ta*(x*x)+b*x+c = 0 \nTerminate calculation with \"END\"";
    return ssMenu;
}

std::vector<double> inputValues()
{
    std::string input;
    std::vector<double> inputValues;
    bool legitInput{ false };
    while(!legitInput)
    {
        std::cout << "Enter double values separated with an empty space: ";
        std::getline(std::cin, input);
        std::string temp{};
        std::stringstream words(input);
        while (words >> temp)
        {
            if (temp == "END")
            {
                std::cout << "Bye!\n";
                return inputValues;
            }
            inputValues.push_back(std::stod(temp));
        }        

        if (inputValues.size() != 3)
        {
            std::cout << "Wrong number of inputs!\n";
            continue;
        }
        legitInput = true;
    }
    return inputValues;
}

std::vector<double> outputCalculation(const std::vector<double> values)
{
    const double a{ values.at(0) }, b{ values.at(1) }, c{ values.at(2) };
    const double p{ b / a }, q{ c / a };
    const double discriminant{ std::pow(p,2) - 4 * q };
    double firstResult{}, secondResult{};
    if (discriminant > 0)
    {
        firstResult = -(p / 2) + std::sqrt(std::pow((p / 2),2) - q);
        secondResult = -(p / 2) - std::sqrt(std::pow((p / 2),2) - q);
        return std::vector<double>{firstResult, secondResult};

    }
    else if (discriminant == 0)
    {
        firstResult = -(p / 2) + std::sqrt(std::pow((p / 2),2) - q);
        return std::vector<double>{firstResult};
    }
    else
    {
        double realPart{ -(p / 2) };
        double complexPart{ std::sqrt(q - std::powf(p / 2, 2)) };
        return std::vector<double>{realPart, 1, complexPart};

    }
}

std::stringstream printResults(std::vector<double> calculationResult)
{
    const int sizeOfVector{ static_cast<int>(calculationResult.size()) };
    std::stringstream result;
    result << "===========================================\n" << "Results\n" <<
        "===========================================\n";

    switch (sizeOfVector)
    {
    case 1:
    {
        result << "There is only one intersection with the y axis with the value of x: " <<
            calculationResult.at(0) << "\n";
        break;
    }
    case 2:
    {
        result << "There are two real intersection with the y axis with the value of x1: "
            << calculationResult.at(0) << " and " << " x2: " << calculationResult.at(1) << "\n";
        break;
    }
    case 3:
    {
        result << "There are only two complex intersections with the y axis with the value of x1: " <<
            calculationResult.at(0) << " + i" << calculationResult.at(2) << "\n and x2: " <<
            calculationResult.at(0) << " - i" << calculationResult.at(2) << "\n";
        break;
    }
    }
    return result;
}
