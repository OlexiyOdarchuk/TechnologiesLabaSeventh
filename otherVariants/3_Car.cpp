#include <iostream>
#include <string>

class Car {
private:
  std::string brand;
  std::string model;
  unsigned int year;

public:
  Car() : brand("Unknown"), model("Unknown"), year(2000) {
    std::cout << "Car created" << std::endl;
  }

  Car(std::string inputBrand, std::string inputModel, unsigned int inputYear)
      : brand(inputBrand), model(inputModel), year(inputYear) {
    std::cout << "Car created" << std::endl;
  }

  ~Car() { std::cout << "Car destroyed" << std::endl; }

  Car &setBrand(std::string inputBrand) {
    brand = inputBrand;
    return *this;
  }

  Car &setModel(std::string inputModel) {
    model = inputModel;
    return *this;
  }

  Car &setYear(unsigned int inputYear) {
    year = inputYear;
    return *this;
  }

  std::string getBrand() const { return brand; }

  std::string getModel() const { return model; }

  unsigned int getYear() const { return year; }

  void print() const {
    std::cout << "\nCar Information:"
              << "\n  Brand: " << brand << "\n  Model: " << model
              << "\n  Year: " << year << "\n\n";
  }
};

int main() {
  Car c1;
  c1.setBrand("Toyota").setModel("Camry").setYear(2022);
  c1.print();

  Car c2("Honda", "Civic", 2020);
  c2.print();

  return 0;
}
