// 07_Exercise.cpp : Do exercise 6, but with three string values. 
// So, if the user enters the values Steinbeck, Hemingway, Fitzgerald, 
// the output should be Fitzgerald, Hemingway, Steinbeck.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::cout << "Enter please 3 strings separated with white spaces: \n";
    std::string val1, val2, val3;
    std::cin >> val1 >> val2 >> val3;
    std::vector <std::string> values{ val1, val2, val3 };
    std::sort(values.begin(), values.end());
    for (auto numValue : values)
    {
        std::cout << numValue << " ";
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
