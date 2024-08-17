// 14_Exercise.cpp : Can we declare a non-reference function argument const (e.g., void f(const int);) ? 
// What might that mean ? Why might we want to do that ? Why don't people do that often? 
// Try it; write a couple of small programs to see what works.

// Conclusion:
//  With const we prevent that the value of the input (pass by value) cannot be modified.
//  For non-reference passing this can be unnecessary because we don't change the data from the caller,
//  But if we input a constant variable, which shouldn't be change like Gravitational acceleration this can be handy

#include <iostream>
#include <vector>

void f(const int);
void f2(const std::vector<int> test);

int main()
{
    std::cout << "Hello World!\n";
}

void f(const int input)
{
    //input = 12; --> Doesn't work
}

void f2(const std::vector<int> test)
{
    //test.push_back(1); --> Doesn't work
    int test{}; // --> This works because of new variable is inside the function body scope
}
