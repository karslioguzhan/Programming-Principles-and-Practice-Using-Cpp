// TryThis04.cpp : To see what an uncaught exception error looks like, run a small program that uses error() without catching any exceptions.

#include <iostream>
#include <string>
#include "std_lib_facilities.h"

int main()
{
	try 
	{
		error("throwing Error!");
	}
	catch (exception& e)
	{
		std::cerr << e.what();
	}
	return 0;
}

