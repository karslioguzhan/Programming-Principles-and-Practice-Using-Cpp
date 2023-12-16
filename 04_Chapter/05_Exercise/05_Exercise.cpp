// 05_Exercise.cpp : Write a program that performs as a very simple calculator. Your calculator should be able to handle the four basic math operations — add, subtract, multiply, and divide — on two input values. Your program should prompt the user to enter three arguments: two double values and a character to represent an operation. If the entry arguments are 35.6, 24.1, and '+', the program output should be The sum of 35.6 and 24.1 is 59.7. In Chapter 6 we look at a much more sophisticated simple calculator.
//

#include <iostream>
#include <vector>
#include <sstream>

// Function prototypes
std::stringstream printMenu();
std::stringstream printRequest();
std::vector<std::string> readInputsAsStrings();
int checkSelection(const std::vector<std::string> input);
double resultCalculation(const std::vector<std::string> input);

// Input states
enum inputCheck
{
    inputCorrect,
    terminateSession,
    inputIncorrect
};



int main()
{
    std::cout << printMenu().str();
    int selectionCheck{};
    do
    {
        std::cout << printRequest().str();
        std::vector<std::string> selection = readInputsAsStrings();
        selectionCheck = checkSelection(selection);
        if (selectionCheck == inputCheck::inputCorrect)
        {
            std::cout << "The result of the calculation is: " << resultCalculation(selection) << "\n";
        }
    } while (selectionCheck != inputCheck::terminateSession);


    return 0;

}


std::stringstream printMenu()
{
    std::stringstream menuStream;
    menuStream << "=========================\n";
    menuStream << "This is a calculator App\n";
    menuStream << "=========================\n";
    return menuStream;
}

std::stringstream printRequest()
{
    std::stringstream request;
    request << "Enter two doubles and a operation to perform a calculation\n" << "for example: 12.1 10.9 + \nFor closing please enter \"END\"\n";
    request << "Enter please: ";
    return request;
}

std::vector<std::string> readInputsAsStrings()
{
    std::string input;
    std::getline(std::cin, input);
    std::istringstream inputStream(input);
    std::string inputElement;
    std::vector<std::string> inputAsVectorString;
    while (inputStream >> inputElement)
    {
        inputAsVectorString.push_back(inputElement);
    }
    return inputAsVectorString;
}

int checkSelection(const std::vector<std::string> input)
{
    if (input.size() == 1 && input.at(0) == "END")
    {
        std::cout << "Goodbye! \n";
        return inputCheck::terminateSession;
    }
    if (input.size() < 3)
    {
        std::cout << "Not enough inputs!\n";
        return inputCheck::inputIncorrect;
    }
    if (input.size() == 3)
    {
        std::string mathOperation = input.at(2);
        if (mathOperation != "+" && mathOperation != "-" && mathOperation != "/" && mathOperation != "*")
        {
            std::cout << "Math operation is not supported!\n";
            return inputCheck::inputIncorrect;
        }
        for (int numInput{ 0 }; numInput < input.size() - 1; ++numInput)
        {
            std::istringstream checkIfDouble(input.at(numInput));
            double valueFromString;
            checkIfDouble >> valueFromString;
            if (checkIfDouble.fail())
            {
                std::cout << "Input " << (numInput + 1) << " is not an double!\n";
                return inputCheck::inputIncorrect;
            }
        }
        return inputCheck::inputCorrect;
    }
    
    std::cout << "To many arguments!\n";
    return inputCheck::inputIncorrect;
}

double resultCalculation(const std::vector<std::string> input)
{
    enum mathOperations
    {
        additon,
        substraction,
        division,
        multiplication
    };
    int operation{};
    if (input.at(2) == "+")
    {
        operation = mathOperations::additon;
    }
    if (input.at(2) == "-")
    {
        operation = mathOperations::substraction;
    }
    if (input.at(2) == "/")
    {
        operation = mathOperations::division;
    }
    if (input.at(2) == "*")
    {
        operation = mathOperations::multiplication;
    }

    double calculation{};
    switch (operation)
    {
    case mathOperations::additon :
    {
        calculation = std::stod(input.at(0)) + std::stod(input.at(1));
        break; 
    }
    case mathOperations::substraction:
    {
        calculation = std::stod(input.at(0)) - std::stod(input.at(1));
        break;
    }
    case mathOperations::division:
    {
        calculation = std::stod(input.at(0)) / std::stod(input.at(1));
        break;
    }
    case mathOperations::multiplication:
    {
        calculation = std::stod(input.at(0)) * std::stod(input.at(1));
    }
    }
    return calculation;
}
