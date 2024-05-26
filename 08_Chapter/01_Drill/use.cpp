// use.cpp : Drill Chapter 8
//

/*
	1. Create three files: my.h, my.cpp, and use.cpp. The header file my.h contains
			extern int foo;
			void print_foo();
			void print(int);
		The source code file my.cpp #includes my.h and std_lib_facilities.h, defines print_foo() to print the value of foo using cout, and print(int i) to print the value of i using cout.
		The source code file use.cpp #includes my.h, defines main() to  set the value of foo to 7 and print it using print_foo(), and to print the value of 99 using print(). Note that use.cpp does not #include std_lib_facilities.h as it doesn't directly use any of those facilities. Get these files compiled and run. On Windows, you need to have both use.cpp and my.cpp in a project and use { char cc; cin>>cc; } in use.cpp to be able to see your output. Hint: You need to #include <iostream> to use cin.
	2. Write three functions swap_v(int, int), swaap_r(int&, int&), and swap_cr(const int&, const int&). Each should have the body
			{int temp; temp = a; a = b; b = temp; }
		where a and be are the names of the arguments.
		Try calling each swap like this
			int x = 7;
			int y = 9;
			swap_?(x,y); // replace ? by v, r, or cr
			const int cx = 7;
			const int cy = 9;
			swap_?(cx,cy);
			swap_?(7.7,9.9);
			double dx = 7.7;
			double dy = 9.9;
			swap_?(dx,dy);
			swap_?(7.7,9.9);
		Which functions and calls compiled, and why? After each swap that compiled, print the value of arguments after the call to see if they were actually swapper. If you are suprised by a result, consult §8.6.
*/

#include <iostream>
#include "my.h"

// Must be here to prevent linkage errors (extern variable)
int foo;

int main()
{
	// Exercise 1
	// Setting extern variable from my.h  
	foo = 7;
	print_foo();
	print(99);

	// Exercise 2
	int x = 7;
	int y = 9;
	swap_v(x, y); // replace ? by v, r, or cr
	std::cout << "x: " << x << " y: " << y << "\n"; // values unchanged because of pass by value
	swap_r(x, y); // replace ? by v, r, or cr
	std::cout << "x: " << x << " y: " << y << "\n"; // values swapped because pass by ref
	const int cx = 7;
	const int cy = 9;
	//swap_r(cx, cy);  This doesn't work because you cannot modify const values
	swap_v(cx, cy);
	std::cout << "cx: " << cx << " cy: " << cy << "\n";
	//swap_r(7.7, 9.9); This doesn't work because the values are not not lvalues
	swap_v(7.7, 9.9); // values unchanged because of pass by value
	
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx, dy); // values unchanged because of pass by value
	swap_v (7.7, 9.9);
	std::cout << "dx: " << dx << " dy: " << dy << "\n"; 
	//swap_r(dx, dy); // cannot be compiled because the refs from double are not qualified with ints (Cannot be converted C2664)

	// There is no need for return or cin with Visual C++ compiler
}

