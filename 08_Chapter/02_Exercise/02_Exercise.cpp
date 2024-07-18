// 02_Exercise.cpp : Write a function print() that prints a vector of ints to cout. Give it two arguments: a string for "labeling" the output and a vector.

#include <iostream>
#include <sstream>
#include <vector>

std::stringstream print(std::string label, std::vector<int>& values);
int main()
{
    std::vector<int> elements{ 1, 3, 45, 50, 600 };
    std::string label{ "Random" };
    std::cout << print(label, elements).str();
}

std::stringstream print(std::string label, std::vector<int>& values)
{
    std::stringstream output;
    output << label << ":\t";
    for (auto elementVector:values)
    {
        output << " " << elementVector;
    }
    output << "\n";
    return output;
}
