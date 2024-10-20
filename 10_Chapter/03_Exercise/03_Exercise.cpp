// 03_Exercise.cpp : Write a program that reads the data from raw_temps.txt created in exercise 2 
// into a vector and then calculates the mean and median temperatures in your data set.
// Call this program temp_stats.cpp.


#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <algorithm>

struct Reading
{
	int hour;
	double temperature;
	Reading(int inputHour, double inputTemperature) :
		hour(inputHour), temperature(inputTemperature)
	{}
};

double calculateMean(const std::vector<Reading>& inputVector)
{
	double sum{};
	for (auto actualReading : inputVector)
	{
		sum += actualReading.temperature;
	}
	return sum / inputVector.size();
}

double calculateMedian(const std::vector<Reading>& inputVector)
{
	std::vector<double> temperatures;
	for (auto actualReading : inputVector)
	{
		temperatures.push_back(actualReading.temperature);
	}
	std::sort(temperatures.begin(), temperatures.end());
	double medianTemp{};
	if (temperatures.size() % 2 == 0)
	{
		medianTemp = (temperatures.at((temperatures.size() / 2) - 1) + temperatures.at(temperatures.size() / 2)) / 2;
	}
	else
	{
		medianTemp = temperatures.at(temperatures.size() / 2);
	}

	return medianTemp;
}

int main()
{
	std::string fileName{ "raw_temps.txt" };
	std::ifstream inputFile{ fileName };
	std::vector<Reading> vectorOfReadings{};

	try
	{
		int tempHour{};
		double tempTemperature{};
		if (!inputFile)
		{
			throw std::invalid_argument("Cannot open the File");
		}

		while (inputFile >> tempHour >> tempTemperature)
		{
			vectorOfReadings.push_back({ tempHour, tempTemperature });
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	double mean{ calculateMean(vectorOfReadings) };
	double median{ calculateMedian(vectorOfReadings) };
	std::cout << "Mean of temperature: " << mean << "\n";
	std::cout << "Median of temperature: " << median << "\n";
}

