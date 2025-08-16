// 05_Exercise.cpp
//  Write a program that reads strings and for each string outputs the character classification of
//  each character, as defined by the character classification functions presented in §11.6. Note
//  that a character can have several classifications (e.g., x is both a letter and an
//  alphanumeric).

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

class CharClassifications
{
public:
  CharClassifications() = delete;
  CharClassifications(char InputValue);

private:
  char AnalyzedChar;
  bool checkIfIsSpace();
  bool checkIfIsAlpha();
  bool checkIfDigit();
  bool checkIfxdigit();
  bool checkIfUpper();
  bool checkIfLower();
  bool checkIfIsalnum();
  bool checkIfIscntrl();
  bool checkIfPunct();
  bool checkIfPrint();
  bool checkIsGraph();
};


int main()
{
  std::vector<std::string> TestStrings{"hallo", "was Los 123", "lorem!1ac"};

  std::vector<std::pair<std::string, std::map<std::string, std::map<std::string, bool>>>>
      AnalyzedString;
  for (auto ActualWord : TestStrings)
  {
    for (auto ActualChar : ActualWord)
    {
    }
  }

  return 0;
}