#include <iostream>
#include <string>

class Teacher {
private:
  std::string name;
  std::string subject;
  unsigned int experience;

public:
  Teacher() : name("Unknown"), subject("Unknown"), experience(0) {
    std::cout << "Teacher created" << std::endl;
  }

  Teacher(std::string inputName, std::string inputSubject,
          unsigned int inputExperience)
      : name(inputName), subject(inputSubject), experience(inputExperience) {
    std::cout << "Teacher created" << std::endl;
  }

  ~Teacher() { std::cout << "Teacher destroyed" << std::endl; }

  Teacher &setName(std::string inputName) {
    name = inputName;
    return *this;
  }

  Teacher &setSubject(std::string inputSubject) {
    subject = inputSubject;
    return *this;
  }

  Teacher &setExperience(unsigned int inputExperience) {
    experience = inputExperience;
    return *this;
  }

  std::string getName() const { return name; }
  std::string getSubject() const { return subject; }
  unsigned int getExperience() const { return experience; }

  void introduce() const {
    std::cout << "\nHello, my name is " << name << ". I teach " << subject
              << " and have " << experience << " years of experience.\n";
  }

  void print() const {
    std::cout << "\nName: " << name << "\nSubject: " << subject
              << "\nExperience: " << experience << " years\n\n";
  }
};

int main() {
  Teacher teacher1;
  teacher1.print();

  Teacher teacher2("Mr. Smith", "Mathematics", 15);
  teacher2.print();
  teacher2.introduce();

  teacher1.setName("Ms. Davis").setSubject("History").setExperience(10);
  teacher1.print();
  teacher1.introduce();

  return 0;
}
