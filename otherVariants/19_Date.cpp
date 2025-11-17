#include <iostream>

class Date {
private:
  unsigned int day;
  unsigned int month;
  unsigned int year;

  bool isLeap(unsigned int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
  }

public:
  Date() : day(1), month(1), year(2000) {
    std::cout << "Date created" << std::endl;
  }

  Date(unsigned int inputDay, unsigned int inputMonth, unsigned int inputYear)
      : day(inputDay), month(inputMonth), year(inputYear) {
    std::cout << "Date created" << std::endl;
  }

  ~Date() { std::cout << "Date destroyed" << std::endl; }

  Date &setDay(unsigned int inputDay) {
    day = inputDay;
    return *this;
  }

  Date &setMonth(unsigned int inputMonth) {
    month = inputMonth;
    return *this;
  }

  Date &setYear(unsigned int inputYear) {
    year = inputYear;
    return *this;
  }

  unsigned int getDay() const { return day; }
  unsigned int getMonth() const { return month; }
  unsigned int getYear() const { return year; }

  bool isValidDate() const {
    if (year == 0 || month == 0 || month > 12 || day == 0 || day > 31) {
      return false;
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeap(year)) {
      daysInMonth[2] = 29;
    }

    if (day > daysInMonth[month]) {
      return false;
    }

    return true;
  }

  void print() const {
    std::cout << "\nDate: ";
    if (day < 10)
      std::cout << "0";
    std::cout << day << ".";
    if (month < 10)
      std::cout << "0";
    std::cout << month << "." << year << "\n\n";
  }
};

int main() {
  Date d1;
  d1.print();
  std::cout << "Is d1 valid? " << (d1.isValidDate() ? "Yes" : "No")
            << std::endl;

  Date d2(29, 2, 2024);
  d2.print();
  std::cout << "Is d2 valid? " << (d2.isValidDate() ? "Yes" : "No")
            << std::endl;

  Date d3(31, 4, 2023);
  d3.print();
  std::cout << "Is d3 valid? " << (d3.isValidDate() ? "Yes" : "No")
            << std::endl;

  d2.setDay(30).setMonth(1).setYear(2025);
  d2.print();
  std::cout << "Is d2 valid? " << (d2.isValidDate() ? "Yes" : "No")
            << std::endl;

  return 0;
}
