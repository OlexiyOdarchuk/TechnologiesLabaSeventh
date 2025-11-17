#include <iostream>
#include <string>

class Student {
private:
  std::string name;
  double averageGrade;
  std::string group;
  int minBal;

public:
  Student() : name("Unknown"), averageGrade(0.0), group("Unknown") {
    std::cout << "Student created" << std::endl;
  }

  Student(std::string inputName, double inputAverageGrade,
          std::string inputGroup)
      : name(inputName), averageGrade(inputAverageGrade), group(inputGroup) {
    std::cout << "Student created" << std::endl;
  }

  ~Student() { std::cout << "Student destroyed" << std::endl; }

  Student &setName(std::string inputName) {
    name = inputName;
    return *this;
  }

  Student &setAverageGrade(double inputAverageGrade) {
    averageGrade = inputAverageGrade;
    return *this;
  }

  Student &setGroup(std::string inputGroup) {
    group = inputGroup;
    return *this;
  }

  std::string getName() const { return name; }

  double getAverageGrade() const { return averageGrade; }

  std::string getGroup() const { return group; }

  bool isAdmittedToExam() const { return averageGrade >= minBal; }

  void print() const {
    std::cout << "\nStudent Information:"
              << "\n  Name: " << name << "\n  Average Grade: " << averageGrade
              << "\n  Group: " << group
              << "\n  Admitted to Exam: " << (isAdmittedToExam() ? "Yes" : "No")
              << "\n\n";
  }
};

int main() {
  Student s1;
  s1.setName("Alice").setAverageGrade(75.5).setGroup("A1");
  s1.print();

  Student s2("Bob", 55.0, "B2");
  s2.print();

  return 0;
}
