// 10_Exercise.cpp : Write a program that takes an operation followed by two operands and outputs the result. 
// For example:+ 100 3.14 | * 4 5
// Read the operation into a string called operation and use an if-statement to figure out 
// which operation the user wants, for example, if (operation=="+"). 
// Read the operands into variables of type double. 
// Implement this for operations called +, –, *, /, plus, minus, mul, and div with their obvious meanings.


#include <iostream>
#include <string>


int main()
{
    std::cout << "Insert operation and two numbers like + 100 3.14 for calculation: ";
    std::string inputOpterator, num1, num2;
    std::cin >> inputOpterator >> num1 >> num2;
    if (inputOpterator == "+" || inputOpterator == "plus")
    {
        std::cout << num1 << " + " << num2 << " = " << std::stod(num1) + std::stod(num2) << "\n";
    }
    else if (inputOpterator == "-" || inputOpterator == "minus")
    {
        std::cout << num1 << " + " << num2 << " = " << std::stod(num1) - std::stod(num2) << "\n";
    }
    else if (inputOpterator == "*" || inputOpterator == "mul")
    {
        std::cout << num1 << " * " << num2 << " = " << std::stod(num1) * std::stod(num2) << "\n";
    }
    else if (inputOpterator == "/" || inputOpterator == "div")
    {
        std::cout << num1 << " / " << num2 << " = " << std::stod(num1) / std::stod(num2) << "\n";
    }
    else
    {
        std::cout << inputOpterator << " is not an legal operation!\n";
    return 1;
    }
    return 0;
}