#include <iostream>
#include <string>

class Train {
private:
  std::string trainNumber;
  unsigned int carCount;
  std::string destination;

public:
  Train() : trainNumber("Unknown"), carCount(0), destination("Unknown") {
    std::cout << "Train created" << std::endl;
  }

  Train(std::string inputTrainNumber, unsigned int inputCarCount,
        std::string inputDestination)
      : trainNumber(inputTrainNumber), carCount(inputCarCount),
        destination(inputDestination) {
    std::cout << "Train created" << std::endl;
  }

  ~Train() { std::cout << "Train destroyed" << std::endl; }

  Train &setTrainNumber(std::string inputTrainNumber) {
    trainNumber = inputTrainNumber;
    return *this;
  }

  Train &setCarCount(unsigned int inputCarCount) {
    carCount = inputCarCount;
    return *this;
  }

  Train &setDestination(std::string inputDestination) {
    destination = inputDestination;
    return *this;
  }

  std::string getTrainNumber() const { return trainNumber; }
  unsigned int getCarCount() const { return carCount; }
  std::string getDestination() const { return destination; }

  void depart() const {
    std::cout << "\nTrain " << trainNumber << " is departing for "
              << destination << " with " << carCount << " cars.\n";
  }

  void print() const {
    std::cout << "\nTrain Number: " << trainNumber
              << "\nCar Count: " << carCount << "\nDestination: " << destination
              << "\n\n";
  }
};

int main() {
  Train train1;
  train1.print();

  Train train2("IC 715", 10, "Kyiv");
  train2.print();
  train2.depart();

  train1.setTrainNumber("RE 1").setCarCount(5).setDestination("Hamburg");
  train1.print();
  train1.depart();

  return 0;
}
