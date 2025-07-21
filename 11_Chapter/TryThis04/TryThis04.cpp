// TryThis04.cpp Make a simple table including the last name, first name, telephone number,
// and email adress for yourself and at least five of your friends.
// Experiment with different field widths until you are statisfied that the table is well printed.

#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>

// Attention there are no checking implemented for this example
class Person
{
public:
  Person(std::string FirstNameInput, std::string SecondNameInput, std::string TelephoneNumberInput,
         std::string EMailAdressInput)
      : FirstName{FirstNameInput}, SecondName{SecondNameInput},
        TelephoneNumber{TelephoneNumberInput}, EmailAdress{EMailAdressInput} {};
  friend std::ostream &operator<<(std::ostream &Out, Person const &InputPerson);

private:
  Person() = delete;
  std::string FirstName;
  std::string SecondName;
  std::string TelephoneNumber;
  std::string EmailAdress;
};

std::ostream &operator<<(std::ostream &Out, Person const &InputPerson)
{
  Out << std::setw(15) << InputPerson.FirstName << "|" << std::setw(15) << InputPerson.SecondName
      << "|" << std::setw(30) << InputPerson.EmailAdress << "|" << std::setw(15)
      << InputPerson.TelephoneNumber << "\n";
  return Out;
}

int main()
{
  Person Person1{"Oguzhan", "Karsli", "03831574155", "bih-ututedi35@aol.com"};
  Person Person2{"Tony", "Test", "08252403412", "duzac_itofu1@outlook.com"};
  Person Person3{"Tom", "Sanchez", "09861690122", "rocovo_fige78@aol.com.com"};
  Person Person4{"Harry", "Mueller", "09652910009", "roj-icoyaze35@hotmail.com"};
  Person Person5{"Siegmund", "Zimmer", "03721339122", "lada-lacika14@gmail.com"};
  std::vector<Person> PersonVector{Person1, Person2, Person3, Person4, Person5};

  for (Person PersonIteration : PersonVector)
  {
    std::cout << PersonIteration;
  }

  return 0;
}