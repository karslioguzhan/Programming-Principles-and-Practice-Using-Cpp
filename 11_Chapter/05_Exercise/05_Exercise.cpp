// 05_Exercise.cpp
//  Write a program that reads strings and for each string outputs the character classification of
//  each character, as defined by the character classification functions presented in §11.6. Note
//  that a character can have several classifications (e.g., x is both a letter and an
//  alphanumeric).

#include <cctype>
#include <ios>
#include <iostream>
#include <map>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class CharClassifications
{
public:
  CharClassifications() = delete;
  CharClassifications(char InputValue) : AnalyzedChar{InputValue}
  {
    AnalyzedMap["IssSpace"] = std::isspace(InputValue);
    AnalyzedMap["IsAlpha"] = std::isalpha(InputValue);
    AnalyzedMap["IsDigit"] = std::isdigit(InputValue);
    AnalyzedMap["IsxDigit"] = std::isxdigit(InputValue);
    AnalyzedMap["IsUpper"] = std::isupper(InputValue);
    AnalyzedMap["IsLower"] = std::islower(InputValue);
    AnalyzedMap["IsAlnum"] = std::isalnum(InputValue);
    AnalyzedMap["IsCntrl"] = std::iscntrl(InputValue);
    AnalyzedMap["IsPunct"] = std::ispunct(InputValue);
    AnalyzedMap["IsPrint"] = std::isprint(InputValue);
    AnalyzedMap["IsGraph"] = std::isgraph(InputValue);
  }
  char getAnalyzedChar() const { return AnalyzedChar; }
  auto getAnalyzedMap() const { return AnalyzedMap; };

private:
  char AnalyzedChar;
  std::map<std::string, bool> AnalyzedMap;
};

class StringAnalyzer
{
public:
  StringAnalyzer() = delete;
  StringAnalyzer(std::string InputValue) : AnalyzerString{InputValue}
  {
    if (InputValue.empty())
    {
      throw std::invalid_argument("Error: String is empty!\n");
    }
    for (auto InputChar : InputValue)
    {
      AnalyzedStringVector.push_back({InputChar, CharClassifications(InputChar)});
    }
  }
  std::string getAnalyzedString() const { return AnalyzerString; }
  auto getAnalyzerStringVector() const { return AnalyzedStringVector; };
  friend std::ostream &operator<<(std::ostream &Os, StringAnalyzer const &Input);

private:
  std::string AnalyzerString;
  std::vector<std::pair<char, CharClassifications>> AnalyzedStringVector;
};

std::ostream &operator<<(std::ostream &Os, StringAnalyzer const &Input)
{
  Os << "Analyzed String: " << Input.getAnalyzedString() << "\n";
  for (auto MapEntry : Input.getAnalyzerStringVector())
  {
    Os << "\tCharacter: " << MapEntry.first << "\n";
    auto CharMap{MapEntry.second.getAnalyzedMap()};
    for (auto CharMapElement : CharMap)
    {
      Os << "\t\t" << CharMapElement.first << ":\t" << std::boolalpha << CharMapElement.second
         << "\n";
    }
  }

  return Os;
}

int main()
{
  std::vector<std::string> TestStrings{"hallo", "was Los 123", "lorem!1ac"};

  std::vector<StringAnalyzer> AnalyzedStringVector;
  // Analyze strings
  for (auto ActualWord : TestStrings)
  {
    AnalyzedStringVector.push_back(StringAnalyzer(ActualWord));
  }

  // Print results
  for (auto AnalyzedWord : AnalyzedStringVector)
  {
    std::cout << AnalyzedWord;
  }

  return 0;
}