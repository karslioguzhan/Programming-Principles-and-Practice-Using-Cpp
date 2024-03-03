// 06_Exercise.cpp : Write a program that checks if a sentence is correct according to the "English" grammar in §6.4.1. Assume that every sentence is terminated by a full stop(.) surrounded by whitespace. For example, "birds fly but the fish swim ." is a sentence, but "birds fly but the fish swim" (terminating dot missing) and "birds fly but the fish swim." (no space before dot) are not. For each sentence entered, the program should simply respond "OK" or "not OK". Hint: Don't bother with tokens; just read into a string using >>.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main()
{
	// Helper variables
	std::vector<std::string> nouns{ "birds", "fish", "C++" };
	std::string article{ "the" };
	std::vector<std::string> conjunctions{ "and", "or", "but" };
	std::vector<std::string> verbs{ "rules", "fly", "swim" };
	bool runProgram{ true };
	do
	{
		std::cout << "Please enter a full sentence terminated with a whitespace and .\nYou can stop the program with entering stop\nNow Enter: ";
		std::string input;
		std::getline(std::cin, input);
		if (!input.compare("stop"))
		{
			std::cout << "Bye!\n";
			break;
		}
		bool sentenceCorrect{};
		// Initialize Stringstream
		std::istringstream inputStringStream(input);
		std::string actualWord{};
		std::vector<std::string> sentence;
		while (inputStringStream >> actualWord)
		{
			sentence.push_back(actualWord);
		}
		// Check if sentence ended correct
		if (sentence.back().compare("."))
		{
			std::cout << "Not OK!\n";
			continue;
		}
		enum possibleTypes { Article, Noun, Verb, Conjunctions };
		// Check if sentence is empty
		if (sentence.size() == 0)
		{
			std::cout << "Not OK!\n";
			continue;
		}
		int nextType{-1};
		if (std::any_of(nouns.begin(), nouns.end(), [=](std::string vecName) {return sentence.at(0) == vecName; }))
		{
			nextType = possibleTypes::Verb;
		}
		else if (!sentence.at(0).compare(article))
		{
			nextType = possibleTypes::Noun;
		}
		else
		{
			std::cout << "Not OK!\n";
			continue;
		}

		for (int numWord{ 1 }; numWord < sentence.size()-1; ++numWord)
		{
			bool nextIteration{ true };
			switch (nextType)
			{
			case possibleTypes::Article:
			{
				nextIteration = !sentence.at(numWord).compare(article);
				nextType = possibleTypes::Noun;
				break;
			}
			case possibleTypes::Noun:
			{
				nextIteration = !std::any_of(verbs.begin(), verbs.end(), [=](std::string vecName) {return sentence.at(numWord) == vecName; });
				nextType = possibleTypes::Verb;
				break;
			}
			case possibleTypes::Verb:
			{
				nextIteration = !std::any_of(conjunctions.begin(), conjunctions.end(), [=](std::string vecName) {return sentence.at(numWord) == vecName; });
				nextType = possibleTypes::Conjunctions;
				break;
			}
			case possibleTypes::Conjunctions:
			{
				if (std::any_of(nouns.begin(), nouns.end(), [=](std::string vecName) {return sentence.at(numWord + 1) == vecName; }))
				{
					nextType = possibleTypes::Noun;
					break;
				}
				else if (!sentence.at(numWord + 1).compare(article))
				{
					nextType = possibleTypes::Article;
					break;
				}
				else
				{
					nextIteration = false;
					break;
				}
			}
			default:
			{
				nextIteration = false;
				break;
			}
			}
			if (!nextIteration)
			{
				std::cout << "Not OK!\n";
				break;
			}
		}
		std::string lastWord{ sentence.at(sentence.size() - 2) };
		if (!std::any_of(verbs.begin(), verbs.end(), [=](std::string vecName) {return lastWord == vecName; }))
		{
			std::cout << "Not OK!\n";
		}
		else
		{
			std::cout << "OK!\n";
		}

	} while (runProgram);

}
