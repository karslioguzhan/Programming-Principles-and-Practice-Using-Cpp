// 03_Exercise.cpp : Replace Name_pair :: print() with a (global) operator << and define == and != for Name_pairs.

#include <iostream>
#include "Name_pairs.h"

int main()
{
    Name_pairs pairs;
    std::vector<std::string> names{ "Tom", "Dick", "Harry" };
    if (pairs.readNames(names) != true)
    {
        std::cout << "Reading names was not successful.\n";
        return -1;
    }
    if (pairs.readAges() != true)
    {
        std::cout << "Reading ages was not successful.\n";
        return -1;
    }
    std::cout << "Before sorting!\n" << pairs;
    pairs.sortAlphabetical();
    std::cout << "After sorting!\n" << pairs;

    return 0;
}

