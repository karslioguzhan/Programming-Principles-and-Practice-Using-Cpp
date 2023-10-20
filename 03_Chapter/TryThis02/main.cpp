#include "std_lib_facilities.h"

int main()
{
	cout << "Please enter a integer value: ";
	int num;
	cin >> num;
	cout << "num == " << num
		<< "\nnum+1 == " << num+1
		<< "\nthree times num == " << num * 3
		<< "\ntwice num == " << num * 2
		<< "\nnum squared == " << num * num
		<< "\nhalf of num == " << num / 2
		<< "\nsquare root of num == " << static_cast<double>(sqrt(num))
		<< "\n";
	return 0;
}
