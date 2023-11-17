// TryThis06.cpp : Write a program that “bleeps” out words that you don’t like;
// that is, you read in words using cin and print them again on cout. 
// If a word is among a few you have defined, you write out BLEEP instead of that word. 
// Start with one “disliked word” such as string disliked = “Broccoli”;
// When that works, add a few more.

#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> forbiddenWords{"Brocolli", "Kellepaca"};
    std::cout << "Write words you want to censore (Bleep) seperated with an whitespace and finish with enter:\n";
    std::vector <std::string> inputWords;
    // Fill vector with input words
    for (std::string tempInput; std::cin >> tempInput;)
    {
        inputWords.push_back(tempInput);
    }
    // Bleep out the forbidden words
    for (std::string words : inputWords)
    {
        bool isForbidden{ false };
        for  (std::string forbiddenWord: forbiddenWords)
        {
            if (words == forbiddenWord)
            {
                isForbidden = true;
                words = "BLEEP";
                break;
            }
        }
        std::cout << words << " ";
    }
    std::cout << "\n";
    return 0;

}

