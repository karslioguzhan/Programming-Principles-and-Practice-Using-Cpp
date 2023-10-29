// 06_Exercise.cpp : Write a program that prompts the user to enter three integer values, 
// and then outputs the values in numerical sequence separated by commas. 
// So, if the user enters the values 10 4 6, the output should be 4, 6, 10.
//  If two values are the same, they should just be ordered together. 
// So, the input 4 5 4 should give 4, 4, 5.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "Please insert three integer values separated with an white space: ";
    int val1, val2, val3;
    std::cin >> val1 >> val2 >> val3;
    std::vector <int> values{val1, val2, val3};
    std::sort(values.begin(), values.end());
    for (auto numVal : values)
    {
        std::cout << numVal << " ";
    }
    std::cout << "\n";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
