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
//      Task 9: Write some code to print the number 1234567.89 three times, first using
//      defaultfloat,
//                then fixed, then scientific forms. Which output form presents the user with the
//                most accurate representation? Explain why.
//      Task 10: Make a simple table including last name, first name, telephone number and  email
//      address
//                for yourself and at least five of your friends. Experiment with different field
//                width until you are satisfied that the table is well represented.

//      Attention: Filename and variable name differs from the task.

#include <chrono>
#include <ios>
#include <iostream>
#include <sstream>
#include <vector>

enum class TypeOfOutput : int
{
  decimal,
  hexadecimal,
  octal
};

enum class TypeOfFormat : int
{
  defaultfloat,
  fixed,
  scientific
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

static std::stringstream formatFloats(double const &InputDouble, TypeOfFormat OutputType)
{
  std::stringstream StringStreamOutput;

  switch (OutputType)
  {
  case TypeOfFormat::defaultfloat:
    StringStreamOutput << "DefaultFloat:\t" << std::defaultfloat << InputDouble << "\n";
    break;
  case TypeOfFormat::fixed:
    StringStreamOutput << "Fixed:\t\t" << std::fixed << InputDouble << "\n";
    break;
  case TypeOfFormat::scientific:
    StringStreamOutput << "Scientific:\t" << std::scientific << InputDouble << "\n";
    break;
  }
  return StringStreamOutput;
}

// Attention there are no checking implemented for this example
class Person
{
public:
  Person(std::string FirstNameInput, std::string SecondNameInput, std::string TelephoneNumberInput,
         std::string EMailAdressInput)
      : FirstName{FirstNameInput}, SecondName{SecondNameInput},
        TelephoneNumber{TelephoneNumberInput}, EmailAdress{EMailAdressInput} {};
  friend std::ostream &operator<<(std::ostream &Out, Person const &InputPerson);
  std::string FirstName;
  std::string SecondName;
  std::string TelephoneNumber;
  std::string EmailAdress;

private:
  Person() = delete;
};

static std::stringstream personTableStringStream(std::vector<Person> const &InputVector)
{
  std::stringstream StringStreamOutput;

  StringStreamOutput << std::setw(15) << "First Name" << "|" << std::setw(15)
                     << "Second Name" << "|" << std::setw(30) << "Email"
                     << "|" << std::setw(20) << "Telephone Number" << "\n";

  for (Person ActualPerson : InputVector)
  {
    StringStreamOutput << std::setw(15) << ActualPerson.FirstName << "|" << std::setw(15)
                       << ActualPerson.SecondName << "|" << std::setw(30)
                       << ActualPerson.EmailAdress << "|" << std::setw(20)
                       << ActualPerson.TelephoneNumber << "\n";
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
  // Result: 1234    668     4660    4660 -> The last two are interpreted as hexadecimal. Because of
  // the last entry was hex

  // Task 9
  double Number{1234567.89};
  std::cout << "Output Format\n";
  std::cout << formatFloats(Number, TypeOfFormat::defaultfloat).str();
  std::cout << formatFloats(Number, TypeOfFormat::fixed).str();
  std::cout << formatFloats(Number, TypeOfFormat::scientific).str();
  // Result
  // DefaultFloat:   1.23457e+06
  // Fixed:          1234567.890000
  // Scientific:     1.234568e+06
  // In this case the Fixed is the most acurate, because the precision is enough to represent the
  // value


  // Task 10
  Person Person1{"Oguzhan", "Karsli", "03831574155", "bih-ututedi35@aol.com"};
  Person Person2{"Tony", "Test", "08252403412", "duzac_itofu1@outlook.com"};
  Person Person3{"Tom", "Sanchez", "09861690122", "rocovo_fige78@aol.com.com"};
  Person Person4{"Harry", "Mueller", "09652910009", "roj-icoyaze35@hotmail.com"};
  Person Person5{"Siegmund", "Zimmer", "03721339122", "lada-lacika14@gmail.com"};
  Person Person6{"Fernando", "Sanchez", "015486548", "f-sanchez30@gmail.com"};
  std::vector<Person> PersonVector{Person1, Person2, Person3, Person4, Person5};

  std::cout << personTableStringStream(PersonVector).str(); 
  // Result
  /*
     First Name|    Second Name|                         Email|    Telephone Number
        Oguzhan|         Karsli|         bih-ututedi35@aol.com|         03831574155
           Tony|           Test|      duzac_itofu1@outlook.com|         08252403412
            Tom|        Sanchez|     rocovo_fige78@aol.com.com|         09861690122
          Harry|        Mueller|     roj-icoyaze35@hotmail.com|         09652910009
       Siegmund|         Zimmer|       lada-lacika14@gmail.com|         03721339122
  */

}