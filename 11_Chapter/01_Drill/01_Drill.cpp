// 01_Drill.cpp:
//      Task 1:Start a program called test_output.cpp. Declare an  integer birth_year and assign
//              it the year you were born.
//      Task 2: Output your birth year in decimal, hexadecimal and octal form.
//      Task 3: Label each value with the name of the base used.
//      Task 4: Did you line up your ouput in columns using the tab character? If not, do it.
//      Task 5: Now output your age.
//      Task 6: Was there a problem? What happened? Fix your output to decimal.
//      Task 7: Go back to 2 and cause your output to show the base for each output.
//      Task 8: Try reading as octal, hexadecimal, etc.:
//                cin >> a >> oct >> b >> hex >> c >> d;
//                cout << a << '\t' << b << '\t' << c << '\t' << d << '\t' << "\n";
//                Run this code with the input: 1234 1234 1234 1234 1234
//      Task 9: Write some code to print the number 1234567.89 three times, first using defaultfloat,
//                then fixed, then scientific forms. Which output form presents the user with the most accurate
//                representation? Explain why.



//      Attention: Filename and variable name differs from the task.

#include <chrono>
#include <iostream>
#include <sstream>

enum class TypeOfOutput : int
{
  decimal,
  hexadecimal,
  octal
};

static std::stringstream formattedOutput(int const &InputInt, TypeOfOutput OutputType)
{
  std::stringstream StringStreamOutput;

  switch (OutputType)
  {
  case TypeOfOutput::decimal:
    StringStreamOutput << "Decimal:\t" << std::dec << InputInt << "\n";
    break;
  case TypeOfOutput::hexadecimal:
    StringStreamOutput << "Hexadecimal:\t" << std::hex << InputInt << "\n";
    break;
  case TypeOfOutput::octal:
    StringStreamOutput << "Octal:\t\t" << std::oct << InputInt << "\n";
    break;
  }
  return StringStreamOutput;
}

int main()
{
  // Task 1-7
  int BirthYear{1993};
  auto SystemTimeNow{std::chrono::system_clock::now()};
  std::chrono::year_month_day YearDaysMonth{std::chrono::floor<std::chrono::days>(SystemTimeNow)};
  std::chrono::year const ActualYear{YearDaysMonth.year()};
  int Age{static_cast<int>(ActualYear) - BirthYear};


  std::cout << "Output birth year\n";
  std::cout << formattedOutput(BirthYear, TypeOfOutput::decimal).str();
  std::cout << formattedOutput(BirthYear, TypeOfOutput::hexadecimal).str();
  std::cout << formattedOutput(BirthYear, TypeOfOutput::octal).str();
  
  std::cout << "Output age in  years\n";
  std::cout << formattedOutput(Age, TypeOfOutput::decimal).str();
  std::cout << formattedOutput(Age, TypeOfOutput::hexadecimal).str();
  std::cout << formattedOutput(Age, TypeOfOutput::octal).str();

  // Task 8
  int a, b, c, d;
  std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
  std::cout << a << '\t' << b << '\t' << c << '\t' << d << '\t' << "\n";
  // Result: 1234    668     4660    4660 -> The last two are interpreted as hexadecimal. Because of the last entry was hex


  return 0;
}