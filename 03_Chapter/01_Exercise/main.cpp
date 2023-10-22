#include "std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to: \n";
	string firstName;
	cin >> firstName;
	cout << "Dear " << firstName << "\n";
	cout << "\tHow are you? I am fine and trying to learn C++\nToday i've started the 3rd sections drills.\n\n"; 

	cout << "Give the name of a friend of you: ";
	string friendName{};
	cin >> friendName;
	cout << "Have you seen " << friendName << " lately?\n";
	char friendSex{ 0 };
	cout << "Enter the sex of your friend m or f: ";
	cin >> friendSex;
	if (friendSex == 'm')
	{
		cout << "If you see " << friendName << " please ask him to call me.\n";
	}
	else
	{
		cout << "If you see " << friendName << " please ask her to call me.\n";
	}

	cout << "Enter the age in years of the recipent of this letter: ";
	int ageRecipent{ 0 };
	cin >> ageRecipent;
	if (ageRecipent <= 0 || ageRecipent >= 110)
	{
		simple_error("you're kidding!");
	}
	else if (ageRecipent < 12)
	{
		cout << "Next year you will be " << ageRecipent + 1 << "\n";
	}
	else if (ageRecipent == 17)
	{
		cout << "Next year you will able to vote!\n";
	}
	else if (ageRecipent > 70)
	{
		cout << "I hope you are enjoying retirement!\n";
	}

	cout << "Yours sincerely, \n\n Oguzhan Karsli\n";
	return 0;

}