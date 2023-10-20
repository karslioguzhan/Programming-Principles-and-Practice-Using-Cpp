#include "std_lib_facilities.h"


int main()
{
	cout << "Please enter your first name and age\n";
	string firstName;
	double ageInYears{ -1 };
	cin >> firstName;
	cin >> ageInYears;
	cout << "Hello, " << firstName << " (age: " << ageInYears * 12 << " in months)\n";

	return 0;
}