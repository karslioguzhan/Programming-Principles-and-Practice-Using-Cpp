// 01_Drill.cpp : Below are 25 code fragments. Each is meant to be inserted into this “scaffolding”:
// Each has zero or more errors. Your task is to find and remove all errors in each program. When you have removed those bugs, the resulting program will compile, run, and write “Success!” Even if you think you have spotted an error, you still need to enter the (original, unimproved) program fragment and test it; you may have guessed wrong about what the error is, or there may be more errors in a fragment than you spotted. Also, one purpose of this drill is to give you a feel for how your compiler reacts to different kinds of errors. Do not enter the scaffolding 25 times — that’s a job for cut and paste or some similar “mechanical” technique. Do not fix problems by simply deleting a statement; repair them by changing, adding, or deleting a few characters.

#include "std_lib_facilities.h"

int main()
{
	try
	{
		// 1. Cout << "Success!\n";  E0020	identifier "Cout" is undefined

		// 2. cout << "Success!\n;  E0008	missing closing quote

		// 3. cout << "Success" << !\n"; E0007	unrecognized token

		// 4. cout << success << '\n'; E0020	identifier "success" is undefined

		// 5. string res = 7; E0415	no suitable constructor exists to convert from "int" to "std::basic_string<char, std::char_traits<char>, std::allocator<char>>
		/* 5. Finished
			int res = 7;
			vector<int> v(10);
			v[5] = res;
			cout << "Success!\n";
		*/

		// 6. v(5) = 7; E0980	call of an object of a class type without appropriate operator() or conversion functions to pointer - to - function type
		/* 6. Finished
			vector<int> v(10);
			v[5] = 7;
			if (v[5] == 7)
			{
				cout << "Success!\n";
			}
		*/

		// 7. if (cond) E0020	identifier "cond" is undefined
		/*7. Finished
			if (true)
			{
				cout << "Success!\n";
			}
			else
			{
				cout << "Fail!\n";
			}
		*/

		// 8. bool c = false; logical error because need to be true if you want success
		/* 8. Finished
			bool c = true;
			if (c)
			{
				cout << "Success!\n";
			}
			else
			{
				cout << "Fail!\n";
			}
		*/

		// 9. boo  c = "fool" < s; E0020	identifier "boo" is undefined; bool  c = "fool" < s is a logical error because fool is bigger than ape
		/* 9. Finished
			string s = "ape";
			bool  c = "fool" > s;
			if (c)
			{
				cout << "Success!\n";
			}
		*/

		// 10.  if (s == "fool") is a logical error --> we need to check unequal
		/* 10. Finished
			string s = "ape";
			if (s != "fool")
			{
				cout << "Success!\n";
			}
		*/

		// 11. cout < "Success!\n"; E0349	no operator "<" matches these operands
		/* 11. Finished
			string s = "ape";
			if (s != "fool")
			{
				cout << "Success!\n";
			}
		*/

		// 12 . if (s + "fool") E0711	expression must have bool type(or be convertible to bool)
		/* 12. Finished
			string s = "ape";
			if (s != "fool")
			{
				cout << "Success!\n";
			}
		*/

		// 13. for (int i = 0; 0 < v.size(); ++i) creates an infinity loop because 0 is always smaller than v with the size of 5
		/* 13. Finished
			vector<char> v(5);
			for (int i = 0; i < v.size(); ++i)
			{
				cout << "Success!\n";
			}
		*/

		// 14. No Errors 
		/* Finished
			vector<char> v(5);
			for (int i = 0; i <= v.size(); ++i)
			{
				cout << "Success!\n";
			}
		*/

		// 15. for (int i = 0; i < 6; ++i) --> Logic error because only Succes gets printed
		/*
			string s = "Success!\n";
				for (int i = 0; i < s.size(); ++i)
				{
					cout << s[i];
				}
		*/

		// 16. if (true) then --> E0020	identifier "then" is undefined
		/* 16. Finished
			if (true)
			{
				cout << "Success!\n";
			}
			else
			{
				cout << "Fail!\n";
			}

		*/

		// 17. if (c == 2000) --> logic error because char cannot hold this value
		/* 17. finished
			int x = 2000;
			char c = x;
			if (c == static_cast<char>(2000))
			{
				cout << "Success!\n";
			}
		*/

		/* 18. Finished --> No error with my compiler
			string s = "Success!\n";
			for (int i = 0; i < 10; ++i)
			{
				cout << s[i];
			}
		*/

		// 19. vector v(5); --> E0441	argument list for class template "Vector" is missing
		/* 19. Finished
			vector <int> v(5);
			for (int i = 0; i <= v.size(); ++i)
			{
				cout << "Success!\n";
			}
		*/

		// 20. while (i < 10) --> causing an infinity loop because i is always lesser than 10
		/*
			int i = 0;
			int j = 9;
			while (i < 10)
			{
				++j;
				++i;
			}
			if (j > i)
			{
				cout << "Success!\n";
			}
		*/


		// 21. double d = 5 / (x - 2); --> Cannot divide by zero and integer division truncates
		/* 21. Finished
			int x = 2;
			double d = 5 / (x - static_cast<double>(2));
			if (d != 2 * x + .5)
			{
				cout << "Success!\n";
			}
		*/

		// 22. string<char> s = "Success!\n"; --> E0519	type "std::string" may not have a template argument list
		//		for (int i = 0; i <= 10; ++i) --> Accessing string in a non existent place --> program terminates
		/* 22. Finished
			string s = "Success!\n";
			for (int i = 0; i < 10; ++i)
			{
				cout << s[i];
			}
		*/


		// 23. ++j; --> E0020	identifier "j" is undefined	
		/* 23. Finished
			int i = 0;
			int j = -1;
			while (i < 10)
			{
				++j;
				++i;
			}
			if (j < i)
			{
				cout << "Success!\n";
			}
		*/

		// 24. double d = 5 / (x - 2); --> logic Error because its an integer division
		/* 24. Finished
		int x = 4;
		double d = static_cast<double>(5) / (x - 2);
		if (d != 2 * x + .5)
		{
			cout << "Success!\n";
		}
		*/

		// 25. cin << "Success!\n"; --> E0349	no operator "<<" matches these operands and it should be cout
		cout << "Success!\n";
		
		keep_window_open();
		return 0;
	}
	catch (exception& e)
	{
		cerr << "error: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...)
	{
		cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2;
	}
}