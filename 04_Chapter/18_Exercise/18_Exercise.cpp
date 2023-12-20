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

int main()
{
    std::cout << printMenu().str();
    std::vector<double> inputVector{ inputValues() };
    if (inputVector.size() == 0)
    {
        return 0;
    }
    std::vector<double> calculationResult{ outputCalculation(inputVector) };
    std::cout << "The first result of the calculation is: " << calculationResult.at(0) << " \n The second result is: " << calculationResult.at(1) << "\n";

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

std::vector<double> inputValues()
{
    std::string input;
    std::vector<double> inputValues;
    bool legitInput{ false };
    while(!legitInput)
    {
        std::cout << "Enter double values separated with an empty space: ";
        std::getline(std::cin, input);
        std::stringstream words(input);
        while (words >> input)
        {
            if (words.str() == "END")
            {
                std::cout << "Bye!\n";
                return inputValues;
            }
        }        // TODO Vektor wird falsch befüllt!
        while (words >> input)
        {
            inputValues.push_back(std::stod(words.str()));
        }
        if (inputValues.size() != 3)
        {
            std::cout << "Wrong number of inputs!\n";
            continue;
        }
        legitInput = true;
    }


    return std::vector<double>();
}

std::vector<double> outputCalculation(const std::vector<double> values)
{
    const double a{ values.at(0) }, b{ values.at(1) }, c{ values.at(2) };
    const double p{ b / a }, q{ c / a };

    double firstResult{ -(p / 2) + std::sqrt(std::pow((p / 2),2) - q) };
    double secondResult{ -(p / 2) - std::sqrt(std::pow((p / 2),2) - q) };
    return std::vector<double>{firstResult, secondResult};
}
