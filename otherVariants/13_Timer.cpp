#include <iostream>
class Timer {
private:
  unsigned int hours;
  unsigned int minutes;
  unsigned int seconds;

public:
  Timer() : hours(0), minutes(0), seconds(0) {
    std::cout << "Timer created" << std::endl;
  }

  Timer(unsigned int inputHours, unsigned int inputMinutes,
        unsigned int inputSeconds)
      : hours(inputHours), minutes(inputMinutes), seconds(inputSeconds) {
    std::cout << "Timer created" << std::endl;
  }

  ~Timer() { std::cout << "Timer destroyed" << std::endl; }

  Timer &setHours(unsigned int inputHours) {
    hours = inputHours;
    return *this;
  }

  Timer &setMinutes(unsigned int inputMinutes) {
    minutes = inputMinutes;
    return *this;
  }

  Timer &setSeconds(unsigned int inputSeconds) {
    seconds = inputSeconds;
    return *this;
  }

  unsigned int getHours() const { return hours; }
  unsigned int getMinutes() const { return minutes; }
  unsigned int getSeconds() const { return seconds; }

  void print() const {
    std::cout << "\nTime: ";
    if (hours < 10)
      std::cout << "0";
    std::cout << hours << ":";
    if (minutes < 10)
      std::cout << "0";
    std::cout << minutes << ":";
    if (seconds < 10)
      std::cout << "0";
    std::cout << seconds << "\n\n";
  }
};

int main() {
  Timer timer1;
  timer1.print();

  Timer timer2(10, 30, 45);
  timer2.print();

  timer2.setHours(1).setMinutes(5).setSeconds(9);
  timer2.print();

  return 0;
}