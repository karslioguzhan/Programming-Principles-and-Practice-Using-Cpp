//Modify the program from exercise 04 to ask the user to enter floating - point values 
// and store them in double variables.Compare the outputs of the two programs for some 
// inputs of your choice.Are the results the same ? Should they be ? What’s the difference ?


#include <iostream>

int main()
{
    std::cout << "Enter please two integer variable for comparision with an whitespace: ";
    double val1, val2;
    std::cin >> val1 >> val2;
    std::cout << "====================================\n";
    std::cout << (val1 > val2 ? "second value is smaller\n" : "first value is smaller\n");
    std::cout << val1 << " - " << val2 << " = " << val1 - val2 << "\n";
    std::cout << val1 << " + " << val2 << " = " << val1 + val2 << "\n";
    std::cout << val1 << " * " << val2 << " = " << val1 * val2 << "\n";
    std::cout << val1 << " / " << val2 << " = " << val1 / val2 << "\n";
    std::cout << "====================================\n";
    return 0;
}

/* Result
* The result are not the same, because you get floating points numbers for division.
*/ 

