// TryThis01.cpp : Try to compile those examples and see how the compiler resonds.
//

#include <iostream>

// Function prototypes
int area(int length, int width);

int main()
{
    int s1 = area(7;    // E0018	expected a ')'
    int s2 = area(7)    // E0165	too few arguments in function call
    Int s3 = area(7);   // E0065	expected a ';'
    int s4 = area('7);  // E0008	missing closing quote
}                       // E0018	expected a ')'

// Sum 17 errors