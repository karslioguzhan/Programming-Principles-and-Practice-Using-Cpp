// 02_Exercise.cpp : 
// Design and implement a Name_pairs class holding (name,age) pairs where name is a string and age is a double.Represent that as a vector<string> (called name) and a vector<double>(called age) member.Provide an in - put operation read_names() that reads a series of names.Provide a read ages() operation that prompts the user for an age for each name.Provide a print() operation that prints out the(name[i], age[i]) pairs(one per line) in the order determined by the name vector.Provide a sort() operation that sorts the name vector in alphabetical order and reorganizes the age vector to match.Implement all "operations" as member functions.Test the class (of course : test early and often).


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
    std::cout << "Before sorting!\n";
    pairs.print();
    pairs.sortAlphabetical();
    std::cout << "After sorting!\n";
    pairs.print();



    return 0;
}

