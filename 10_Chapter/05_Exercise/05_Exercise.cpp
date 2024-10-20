// 05_Exercise.cpp : Write the function print_year() mentioned in §10.11.2.

#include <iostream>
#include <vector>
#include <fstream>
#include <random>

struct Year 
{
    Year(int yearInput) :
        year(yearInput)
    {}
    int year;
};

void printYear(std::ofstream& ofs, const Year inputYear)
{
    ofs << "Year: " << inputYear.year << "\n";
}

int main()
{
    // Attention shortened exercise (Reading from file skipped)
    std::vector<Year> ys;
    // Obtain random number from hardware
    std::random_device randomDevice;
    // Seed the generator
    std::mt19937 generator(randomDevice());
    // Define range -1000 - 2024 (Year)
    std::uniform_int_distribution<> distributionYear(-1000, 2024);
    constexpr int maxNumberOfInserts{ 50 };
    for (size_t numInput{}; numInput < maxNumberOfInserts; numInput++)
    {
        ys.push_back({ distributionYear(generator)});
    }
    // Output years
    std::string fileName{ "raw_years.txt" };
    std::ofstream ofs{ fileName };
    for (auto actualYear : ys)
    {
        printYear(ofs, actualYear);
    }
}

