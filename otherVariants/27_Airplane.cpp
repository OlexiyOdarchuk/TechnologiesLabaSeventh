#include <iostream>
#include <string>

class Airplane {
private:
  std::string model;
  double speed;
  double altitude;

public:
  Airplane() : model("Unknown"), speed(0.0), altitude(0.0) {
    std::cout << "Airplane created" << std::endl;
  }

  Airplane(std::string inputModel, double inputSpeed, double inputAltitude)
      : model(inputModel), speed(inputSpeed), altitude(inputAltitude) {
    std::cout << "Airplane created" << std::endl;
  }

  ~Airplane() { std::cout << "Airplane destroyed" << std::endl; }

  Airplane &setModel(std::string inputModel) {
    model = inputModel;
    return *this;
  }

  Airplane &setSpeed(double inputSpeed) {
    speed = inputSpeed;
    return *this;
  }

  Airplane &setAltitude(double inputAltitude) {
    altitude = inputAltitude;
    return *this;
  }

  std::string getModel() const { return model; }
  double getSpeed() const { return speed; }
  double getAltitude() const { return altitude; }

  void fly() const {
    std::cout << "\nThe " << model << " is flying at " << speed
              << " km/h at an altitude of " << altitude << " meters.\n";
  }

  void print() const {
    std::cout << "\nModel: " << model << "\nSpeed: " << speed << " km/h"
              << "\nAltitude: " << altitude << " meters\n\n";
  }
};

int main() {
  Airplane plane1;
  plane1.print();

  Airplane plane2("Boeing 747", 900.0, 10000.0);
  plane2.print();
  plane2.fly();

  plane1.setModel("Airbus A320").setSpeed(850.0).setAltitude(11000.0);
  plane1.print();
  plane1.fly();

  return 0;
}
