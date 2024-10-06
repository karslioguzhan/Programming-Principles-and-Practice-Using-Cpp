// 01_Drill.cpp :
//      1: Start a program to work with points, discussed in �10.4. Begin by defining the data type Point that has two
//          coordinate members x and y.
//      2: Using the code and discussion in �10.4, prompt the user to input seven(x,y) pairs.
//          As the data is entered, store it in a vector of Points called original_points.
//		3: Print the data in original_points to see what it looks like.
//		4: Open an ofstream and output each point to a file named mydata.txt.
//			On Windows, we suggest the .txt suffix to make it easier to look at the data with 
//			an ordinary text editor (such as WordPad).
//		5: Close the ofstream and then open an ifstream for mydata.txt. Read the data from mydata.txt
//			and store it in a new vector called processed_points
//		6: Print the data elements from both vectors
//		7: Compare the two vectors and print Something's wrong! if the number of elements or the values of elements differ.

#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <exception>
#include "Point.h"

int main()
{
	// Drill 2
	std::vector<Point> original_points;
	// Insert seven x,y pairs
	std::cout << "Please enter 7 x,y (example: 0 -10) pairs. Finish each input with an Enter: ";
	for (int numIteration{}; numIteration < 7; ++numIteration)
	{
		int tempX{}, tempY{};
		std::cin >> tempX >> tempY;
		original_points.push_back({ tempX, tempY });
	}
	// Drill 3
	std::cout << "Printing vector of Points\n";
	for (auto originalPoint : original_points)
	{
		std::cout << "X: " << originalPoint.getX() << " | Y: " << originalPoint.getY() << "\n";
	}
	// Drill 4
	std::string fileName{ "mydata.txt" };
	std::ofstream test;
	std::ofstream outputFile{ fileName };
	for (auto originalPoint : original_points)
	{
		outputFile << originalPoint.getX() << " " << originalPoint.getY() << "\n";
	}
	// Drill 5
	outputFile.close();
	std::vector<Point> processed_points;
	std::ifstream inputFile{ fileName };
	try
	{
		int tempX{}, tempY{};
		if (!inputFile)
		{
			throw std::invalid_argument("Cannot open the File");
		}
		while (inputFile >> tempX >> tempY)
		{
			processed_points.push_back({ tempX, tempY });
		}
		// Drill 6
		std::cout << "Printing vector of read Points\n";
		for (auto originalPoint : processed_points)
		{
			std::cout << "X: " << originalPoint.getX() << " | Y: " << originalPoint.getY() << "\n";
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	// Drill 7
	if (original_points.size() != processed_points.size())
	{
		std::cerr << "Something's wrong! (Different length)";
	}
	for (int numElement{}; numElement < original_points.size(); ++numElement)
	{
		if (original_points.at(numElement) != processed_points.at(numElement))
		{
			std::cerr << "Something's wrong! (Diffrent values)";
			break;
		}
	}
}