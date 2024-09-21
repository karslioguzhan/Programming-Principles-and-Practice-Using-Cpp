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
	friend bool operator==(const Name_pairs& pair1, const Name_pairs& pair2);
	friend bool operator!=(const Name_pairs& pair1, const Name_pairs& pair2);
private:
	std::vector<int> age;
	std::vector<std::string> name;
};

