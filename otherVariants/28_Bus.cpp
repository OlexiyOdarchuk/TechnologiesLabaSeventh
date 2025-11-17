#include <iostream>
#include <string>

class Bus {
private:
  std::string route;
  std::string busNumber;
  unsigned int passengerCount;

public:
  Bus() : route("Unknown"), busNumber("Unknown"), passengerCount(0) {
    std::cout << "Bus created" << std::endl;
  }

  Bus(std::string inputRoute, std::string inputBusNumber,
      unsigned int inputPassengerCount)
      : route(inputRoute), busNumber(inputBusNumber),
        passengerCount(inputPassengerCount) {
    std::cout << "Bus created" << std::endl;
  }

  ~Bus() { std::cout << "Bus destroyed" << std::endl; }

  Bus &setRoute(std::string inputRoute) {
    route = inputRoute;
    return *this;
  }

  Bus &setBusNumber(std::string inputBusNumber) {
    busNumber = inputBusNumber;
    return *this;
  }

  Bus &setPassengerCount(unsigned int inputPassengerCount) {
    passengerCount = inputPassengerCount;
    return *this;
  }

  std::string getRoute() const { return route; }
  std::string getBusNumber() const { return busNumber; }
  unsigned int getPassengerCount() const { return passengerCount; }

  void arriveAtStop() const {
    std::cout << "\nBus " << busNumber << " on route " << route
              << " has arrived at the stop with " << passengerCount
              << " passengers.\n";
  }

  void print() const {
    std::cout << "\nRoute: " << route << "\nBus Number: " << busNumber
              << "\nPassenger Count: " << passengerCount << "\n\n";
  }
};

int main() {
  Bus bus1;
  bus1.print();

  Bus bus2("10A", "AE 1234 BC", 25);
  bus2.print();
  bus2.arriveAtStop();

  bus1.setRoute("City Circle").setBusNumber("BH 5678 IO").setPassengerCount(15);
  bus1.print();
  bus1.arriveAtStop();

  return 0;
}
