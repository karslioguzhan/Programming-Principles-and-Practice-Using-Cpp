// 12_Exercise.cpp :Improve print_until_s() from §8.5.2.Test it. What makes a good set of test cases ? 
// Give reasons. Then, write a print_until_ss() that prints until it sees a second occurrence of its quit argument.

#include <iostream>
#include<vector>

void print_until_s(std::vector <std::string> v, std::string quit);
void print_until_ss(std::vector<std::string> v, std::string quit);

int main()
{
	// This is a basic good test to see if printing works
	std::vector<std::string> test1{ "Hallo", "Bye", "Tony" };
	std::vector<std::string> test2{ "Hallo", "Bye", "Tony", "Larry" };
	// This is a good test because there are multiple names which can trigger the second quit
	std::vector<std::string> test3{ "Hallo", "Bye", "Tony", "Larry", "Tony", "Hans" }; 

	std::cout << "print_until_s\n";
	print_until_s(test1, "Bye");
	print_until_s(test2, "Tony");
	print_until_s(test3, "Hans");

	std::cout << "print_until_ss\n";
	print_until_ss(test1, "Tony");
	print_until_ss(test2, "Hans");
	print_until_ss(test3, "Tony");

}

void print_until_s(std::vector<std::string> v, std::string quit)
{
	for (auto s : v)
	{
		if (s == quit)
		{
			std::cout << "\n";
			return;
		}
		std::cout << s << "\t";
	}
	std::cout << "\n";
}

void print_until_ss(std::vector<std::string> v, std::string quit)
{
	int numOfQuits{};
	for (auto s : v)
	{
		if (s == quit)
		{
			numOfQuits++;
		}
		if (numOfQuits == 2)
		{
			std::cout << "\n";
			return;
		}
		std::cout << s << "\t";
	}
	std::cout << "\n";
}
