// TryThis03.cpp : The character 'b' is char('a'+1), 'c' is char('a'+2), etc. 
// Use a loop to write out a table of characters with their corresponding integer values:

#include <iostream>

int main()
{
    char startChar{ 'a' };
    char endChar{ 'z' };
    while (startChar <= endChar)
    {
     
        std::cout << startChar << "\t" << static_cast<int>(startChar) << "\n";
        ++startChar;
    }
    return 0;
}
