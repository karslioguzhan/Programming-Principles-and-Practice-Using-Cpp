// 07_Exercise.cpp : Modify the “mini calculator” from exercise 5 to accept (just) single-digit numbers written as either digits or spelled out.
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
    request << "Enter two integers written out or as number and a operation to perform a calculation\n" << "for example: one 9 + \nFor closing please enter \"END\"\n";
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
        // Check if integers are correct
        for (int numInput{ 0 }; numInput < input.size() - 1; ++numInput)
        {
            std::istringstream checkIfInt(input.at(numInput));
            std::vector<std::string> stringOfInts{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
            if (checkIfInt.str().size() == 1)
            {
                int valueFromString;
                checkIfInt >> valueFromString;
                if (checkIfInt.fail())
                {
                    std::cout << "Input " << (numInput + 1) << " is not an Integer!\n";
                    return inputCheck::inputIncorrect;
                }
            }
            else
            {
                bool notAvailable{ true };
                for (auto compare : stringOfInts)
                {
                    if (compare == checkIfInt.str())
                    {
                        notAvailable = false;
                    }
                }
                if (notAvailable == true)
                {
                    std::cout << "Input " << input.at(numInput) << " is not an integer or supported!\n";
                    return inputCheck::inputIncorrect;
                }
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
    int firstValue, secondValue;
    std::vector<std::string> stringOfInts{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    if (input.at(0).size() == 1)
    {
        firstValue = std::stoi(input.at(0));
    }
    else
    {
        for (int numIterator{0}; numIterator < 9; ++numIterator)
        {
            if (input.at(0) == stringOfInts.at(numIterator))
            {
                firstValue = numIterator;
                break;
            }
        }
    }
    if (input.at(1).size() == 1)
    {
        secondValue = std::stoi(input.at(1));
    }
    else
    {
        for (int numIterator{ 0 }; numIterator < 9; ++numIterator)
        {
            if (input.at(1) == stringOfInts.at(numIterator))
            {
                secondValue = numIterator;
                break;
            }
        }
    }
    switch (operation)
    {
    case mathOperations::additon:
    { 
        calculation = firstValue + secondValue;
        break;
    }
    case mathOperations::substraction:
    {
        calculation = firstValue - secondValue;
        break;
    }
    case mathOperations::division:
    {
        calculation = static_cast<double>( firstValue) / secondValue;
        break;
    }
    case mathOperations::multiplication:
    {
        calculation = firstValue * secondValue;
    }
    }
    return calculation;
}

