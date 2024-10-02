// 12_Exercise.cpp : . Change the representation of a Date to be the number of days since January 1, 1970 (known as day 0), 
// represented as a long int, and re - implement the functions from §9.8.Be sure to reject dates outside the range we can
// represent that way(feel free to reject days before day 0, i.e., no negative days).

// Information: This tasked is not solved according to the description, because most of the functionalities are given from std::chrono.

#include <iostream>
#include "Chrono.h"

int main()
{
	Chrono::Date testDate{};
	std::cout << testDate.getActualDate() << "\n";
	std::cout << testDate.numberOfDays() << "\n";
	
	Chrono::Date secondDate{ std::chrono::year{2024}, std::chrono::October, std::chrono::day{2} };
	std::cout << secondDate.getActualDate() << "\n";
	std::cout << secondDate.numberOfDays() << "\n"; // Result proved with online calculator --> 19998 days
}
