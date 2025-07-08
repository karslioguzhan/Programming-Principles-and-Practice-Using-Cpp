// TryThis01.cpp: Output your birth year in decimal, hexadecimal, and octal form. Label each value.
//  Line up your output in columns using the tab character. Now output your Age.

#include <chrono>
#include <iostream>

static void printInputs(int const Input)
{
  std::cout << std::dec <<"Decimal: " << Input << "\t Hex: " << std::hex << Input << "\t Oct: " << std::oct
            << Input << "\n";
}

int main()
{
  constexpr int BirthYear{1993};

  // Birth year
  std::cout << "Birthyear\n";
  printInputs(BirthYear);

  // Age
  auto SystemTimeNow{std::chrono::system_clock::now()};
  std::chrono::year_month_day YearDaysMonth{std::chrono::floor<std::chrono::days>(SystemTimeNow)};
  std::chrono::year const ActualYear{YearDaysMonth.year()};

  std::cout << "Age\n";
  printInputs(static_cast<int>(ActualYear) - BirthYear);

  return 0;
}