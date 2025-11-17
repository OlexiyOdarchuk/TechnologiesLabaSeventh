#include <iostream>

class Time {
private:
  unsigned int hour;
  unsigned int minute;
  unsigned int second;

  void normalizeTime() {
    unsigned int totalSeconds = hour * 3600 + minute * 60 + second;
    second = totalSeconds % 60;
    totalSeconds /= 60;
    minute = totalSeconds % 60;
    hour = totalSeconds / 60 % 24;
  }

public:
  Time() : hour(0), minute(0), second(0) {
    std::cout << "Time created" << std::endl;
  }

  Time(unsigned int inputHour, unsigned int inputMinute,
       unsigned int inputSecond)
      : hour(inputHour), minute(inputMinute), second(inputSecond) {
    normalizeTime();
    std::cout << "Time created" << std::endl;
  }

  ~Time() { std::cout << "Time destroyed" << std::endl; }

  Time &setHour(unsigned int inputHour) {
    hour = inputHour % 24;
    return *this;
  }

  Time &setMinute(unsigned int inputMinute) {
    minute = inputMinute % 60;
    return *this;
  }

  Time &setSecond(unsigned int inputSecond) {
    second = inputSecond % 60;
    return *this;
  }

  unsigned int getHour() const { return hour; }
  unsigned int getMinute() const { return minute; }
  unsigned int getSecond() const { return second; }

  void addSeconds(unsigned int secondsToAdd) {
    second += secondsToAdd;
    normalizeTime();
  }

  void print() const {
    std::cout << "\nTime: ";
    if (hour < 10)
      std::cout << "0";
    std::cout << hour << ":";
    if (minute < 10)
      std::cout << "0";
    std::cout << minute << ":";
    if (second < 10)
      std::cout << "0";
    std::cout << second << "\n\n";
  }
};

int main() {
  Time t1;
  t1.print();

  Time t2(23, 59, 50);
  t2.print();

  t2.addSeconds(15);
  std::cout << "After adding 15 seconds:";
  t2.print();

  t2.setHour(10).setMinute(20).setSecond(30);
  t2.print();

  Time t3(1, 1, 1);
  t3.addSeconds(3600 + 60 + 1);
  std::cout << "After adding 1 hour 1 minute 1 second:";
  t3.print();

  return 0;
}
