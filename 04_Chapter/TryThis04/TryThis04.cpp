// TryThis04.cpp : Rewrite the character value example from the previous Try this to use a for-statement. 
// Then modify your program to also write out a table of the integer values for uppercase letters and digits.



#include <iostream>

int main()
{
    for (int numChar{ 0 }; numChar < 26; ++numChar)
    {
        std::cout << static_cast<char>(numChar + 97) << "\t" << numChar + 97 << "\t"
            << static_cast<char>(numChar + 65) << "\t" << numChar + 65 << "\n";
    }

    return 0;
}
