#include <iostream>
#include <string>

class Course {
private:
  std::string courseName;
  unsigned int hours;
  std::string instructor;

public:
  Course() : courseName("Unknown"), hours(0), instructor("Unknown") {
    std::cout << "Course created" << std::endl;
  }

  Course(std::string inputCourseName, unsigned int inputHours,
         std::string inputInstructor)
      : courseName(inputCourseName), hours(inputHours),
        instructor(inputInstructor) {
    std::cout << "Course created" << std::endl;
  }

  ~Course() { std::cout << "Course destroyed" << std::endl; }

  Course &setCourseName(std::string inputCourseName) {
    courseName = inputCourseName;
    return *this;
  }

  Course &setHours(unsigned int inputHours) {
    hours = inputHours;
    return *this;
  }

  Course &setInstructor(std::string inputInstructor) {
    instructor = inputInstructor;
    return *this;
  }

  std::string getCourseName() const { return courseName; }
  unsigned int getHours() const { return hours; }
  std::string getInstructor() const { return instructor; }

  void info() const {
    std::cout << "\nCourse Name: " << courseName << "\nHours: " << hours
              << "\nInstructor: " << instructor << "\n\n";
  }

  void print() const { info(); }
};

int main() {
  Course course1;
  course1.print();

  Course course2("Introduction to C++", 40, "Mr. Smith");
  course2.print();

  course1.setCourseName("Advanced Algorithms")
      .setHours(60)
      .setInstructor("Ms. Davis");
  course1.print();

  return 0;
}
