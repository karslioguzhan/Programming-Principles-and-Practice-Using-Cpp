// 02_Exercise.cpp : Write a program that creates a file of data in the form of the temperature
// Reading type defined in §10.5.For testing, fill the file with at least 50
// "temperature readings." Call this program store_temps.cpp and the file it creates raw_temps.txt.

#include <iostream>
#include <random>
#include <vector>
#include <fstream>

struct Reading
{
	int hour;
	double temperature;
	Reading(int inputHour, double inputTemperature) :
		hour(inputHour), temperature(inputTemperature)
	{}
};

double roundDouble(double inputDouble)
{
	return (ceil(inputDouble * 1000)) / 1000;
}

int main()
{
	// Obtain random number from hardware
	std::random_device randomDevice;
	// Seed the generator
	std::mt19937 generator(randomDevice());
	// Define range 0-23 (Hour)
	std::uniform_int_distribution<> distributionHour(0, 23);
	// Define range -20 °C to 45°C (Europe)
	std::uniform_real_distribution<> distributionTemparute(-20.0, 45.0);
	std::vector<Reading> vectorOfReadings{};

	constexpr int maxNumberOfInserts{ 50 };
	for (size_t numInput{}; numInput < maxNumberOfInserts; numInput++)
	{
		vectorOfReadings.push_back({ distributionHour(generator), roundDouble(distributionTemparute(generator)) });
	}

	// Create output file
	std::string fileName{ "raw_temps.txt" };
	std::ofstream outputFile{ fileName };
	outputFile << "Hour," << "Temperature\n";
	for (auto actualReading : vectorOfReadings)
	{
		outputFile << actualReading.hour << "," << actualReading.temperature << "\n";
	}
	outputFile.close();
}
