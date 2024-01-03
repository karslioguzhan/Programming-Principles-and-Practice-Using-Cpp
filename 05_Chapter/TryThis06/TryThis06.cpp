// TryThis06.cpp : Look it up. Check some information sources to pick good values for the min_temp (the “minimum temperature”) and max_temp (the “maximum temperature”) constants for our program. Those values will determine the limits of usefulness of our program.

// Answer: This program has still logic errors. Because if the inputs doesn't exceed the lower and upper ground -90 and 57 will be printed

#include <iostream>
#include "std_lib_facilities.h"

int main()
{
    double sum = 0;
    double high_temp = 57; // Highest recorded temparature in °C
    double low_temp = -90; // Lowest recorded temparture in °C
    int no_of_temps = 0;

    for (double temp; cin >> temp;)
    {
        ++no_of_temps;
        sum += temp;
        if (temp > high_temp)
        {
            high_temp = temp;
        }
        if (temp < low_temp)
        {
            low_temp = temp;
        }
    }


    cout << "High temperature: " << high_temp << "\n";
    cout << "Low temperature: " << low_temp << "\n";
    cout << "Average temperature: " << sum / no_of_temps << "\n";
    return 0;
}
