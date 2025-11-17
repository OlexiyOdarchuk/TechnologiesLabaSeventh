#include <iostream>
#include <string>

class Employee {
private:
  std::string name;
  std::string position;
  double salary;

public:
  Employee() : name(""), position(""), salary(0.0) {}

  Employee(const std::string &name, const std::string &position, double salary)
      : name(name), position(position), salary(salary) {}

  ~Employee() {
    std::cout << "Destructor called for Employee " << name << std::endl;
  }

  std::string getName() const { return name; }
  std::string getPosition() const { return position; }
  double getSalary() const { return salary; }

  Employee &setName(const std::string &name) {
    this->name = name;
    return *this;
  }

  Employee &setPosition(const std::string &position) {
    this->position = position;
    return *this;
  }

  Employee &setSalary(double salary) {
    this->salary = salary;
    return *this;
  }

  double calculateMonthlySalary() const { return salary; }

  void print() const {
    std::cout << "Employee Information:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Position: " << position << std::endl;
    std::cout << "Salary: $" << salary << std::endl;
  }
};

int main() {
  Employee emp1;
  Employee emp2("John Doe", "Software Engineer", 75000.0);

  std::cout << "Employee 1 (default constructor):" << std::endl;
  emp1.print();
  std::cout << std::endl;

  std::cout << "Employee 2 (constructor with parameters):" << std::endl;
  emp2.print();
  std::cout << std::endl;

  std::cout << "Updating Employee 1's information..." << std::endl;
  emp1.setName("Jane Smith").setPosition("Project Manager").setSalary(90000.0);
  emp1.print();
  std::cout << std::endl;

  std::cout << "Final Information:" << std::endl;
  emp1.print();
  emp2.print();

  return 0;
}