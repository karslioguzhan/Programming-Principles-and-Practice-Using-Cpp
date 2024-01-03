// TryThis05.cpp : Get this program to run. Check that our input really does produce that output. Try to “break” the program (i.e., get it to give wrong results) by giving it other input sets. What is the least amount of input you can give it to get it to fail?

// Answer: If you just enter an non double like a you will get a false outputs like high and low temp is 0 and average is -nan(ind)

#include <iostream>
#include "std_lib_facilities.h"

int main()
{
    vector<double> temps;
    for (double temp; cin >> temp;)
    {
        temps.push_back(temp);
    }

    double sum = 0;
    double high_temp = 0;
    double low_temp = 0;

    for (int x : temps)
    {
        if (x > high_temp)
        {
            high_temp = x;
        }
        if (x < low_temp)
        {
            low_temp = x;
        }
        sum += x;
    }

    cout << "High temperature: " << high_temp << "\n";
    cout << "Low temperature: " << low_temp << "\n";
    cout << "Average temperature: " << sum/temps.size() << "\n";
    return 0;
}
