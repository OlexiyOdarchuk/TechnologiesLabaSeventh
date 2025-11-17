#include <iostream>
#include <string>

class Employee {
private:
  std::string name;
  std::string position;
  double salary;

public:
  Employee() : name("Unknown"), position("Unknown"), salary(0.0) {
    std::cout << "Employee created" << std::endl;
  }

  Employee(std::string inputName, std::string inputPosition, double inputSalary)
      : name(inputName), position(inputPosition), salary(inputSalary) {
    std::cout << "Employee created" << std::endl;
  }

  ~Employee() { std::cout << "Employee destroyed" << std::endl; }

  Employee &setName(std::string inputName) {
    name = inputName;
    return *this;
  }

  Employee &setPosition(std::string inputPosition) {
    position = inputPosition;
    return *this;
  }

  Employee &setSalary(double inputSalary) {
    salary = inputSalary;
    return *this;
  }

  std::string getName() const { return name; }
  std::string getPosition() const { return position; }
  double getSalary() const { return salary; }

  double calculateMonthlySalary() const { return salary; }

  void print() const {
    std::cout << "\nName: " << name << "\nPosition: " << position
              << "\nSalary: " << salary << "\n\n";
  }
};

int main() {
  Employee emp1;
  emp1.print();

  Employee emp2("John Doe", "Software Engineer", 5000.0);
  emp2.print();

  emp2.setName("Jane Doe")
      .setPosition("Senior Software Engineer")
      .setSalary(6000.0);
  emp2.print();

  std::cout << "Monthly salary for " << emp2.getName() << " is "
            << emp2.calculateMonthlySalary() << std::endl;

  return 0;
}
