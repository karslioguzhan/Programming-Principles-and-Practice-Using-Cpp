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
	friend std::ostream& operator<<(std::ostream& os, const Name_pairs& namePairsInput);
private:
	std::vector<int> age;
	std::vector<std::string> name;
};

