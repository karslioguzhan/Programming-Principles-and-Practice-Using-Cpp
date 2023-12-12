//If we define the median of a sequence as “a number so that exactly as many elements come before it in the sequence as come after it” fix the program in §4.6.3 so that it always prints out a median. Hint: A median need not be an element of the sequence.

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    std::vector<double> temps;
    for (double temp; std::cin >> temp;)
    {
        temps.push_back(temp);
    }

    // compute mean temperature
    double sum{};
    for (int x : temps)
    {
        sum += x;
    }
    std::cout << "Average temperature: " << sum / temps.size() << "\n";

    // compute median temperature
    std::sort(temps.begin(), temps.end());
    double median{};
    if (temps.size() % 2 == 1)
    {
        median = temps.at(temps.size() / 2);
    }
    else
    {
        int oddElement{ static_cast<int>(temps.size() / 2) - 1 };
        std::cout << "Bin bei element: " << oddElement << "\n";
        median = (temps.at(oddElement) + temps.at(oddElement + 1)) / 2;
    }
    std::cout << "Median temperature: " << median;

    return 0;
}