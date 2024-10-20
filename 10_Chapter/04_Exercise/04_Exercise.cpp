// 04_Exercise.cpp : Modify the store_temps.cpp program from exercise 2 to include a temperature suffix c for Celsius or f for 
// Fahrenheit temperatures.Then modify the temp_stats.cpp program to test each temperature, converting the 
// Celsius readings to Fahrenheit before putting them into the vector.

#include <iostream>
#include <random>
#include <vector>
#include <fstream>
#include <string>

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

double temparatureConverter(std::string inputTemp, char wantedUnit)
{
	char temparatureUnit{ inputTemp.back() };
	inputTemp.pop_back();
	double temperature{ std::stod(inputTemp) }, convertedTemp{};
	if (wantedUnit == temparatureUnit)
	{
		return temperature;
	}
	switch (temparatureUnit)
	{
	case 'c':
	case 'C':
		convertedTemp = temperature * 1.8 + 32;
		break;
	case 'f':
	case 'F':
		convertedTemp = (temperature - 32) / 1.8;
		break;
	default:
		throw std::invalid_argument("Unit is not supported!\n");
	}
	return convertedTemp;
}

int main()
{
	// Obtain random number from hardware
	std::random_device randomDevice;
	// Seed the generator
	std::mt19937 generator(randomDevice());
	// Define range 0-23 (Hour)
	std::uniform_int_distribution<> distributionHour(0, 23);
	// Define range -20 �C to 45�C (Europe)
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
	for (auto actualReading : vectorOfReadings)
	{
		outputFile << actualReading.hour << " " << actualReading.temperature << "c\n";
	}
	outputFile.close();
	std::ifstream inputFile{ fileName };
	std::vector<Reading> vectorOfReadingsInput{};
	try
	{
		int tempHour{};
		std::string tempTemperature{};
		if (!inputFile)
		{
			throw std::invalid_argument("Cannot open the File");
		}
		char wantedUnit{ 'f' };
		while (inputFile >> tempHour >> tempTemperature)
		{
			vectorOfReadingsInput.push_back({ tempHour, temparatureConverter(tempTemperature, wantedUnit)});
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
}

