#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Name_pairs
{
public:
	bool readNames(std::vector<std::string> inputNames);
	bool readAges();
	void print();
	void sortAlphabetical();
private:
	std::vector<int> age;
	std::vector<std::string> name;
};

