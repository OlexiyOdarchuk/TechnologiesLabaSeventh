#include <iostream>

class Building {
private:
  unsigned int floors;
  double area;
  unsigned int apartmentCount;

public:
  Building() : floors(0), area(0.0), apartmentCount(0) {
    std::cout << "Building created" << std::endl;
  }

  Building(unsigned int inputFloors, double inputArea,
           unsigned int inputApartmentCount)
      : floors(inputFloors), area(inputArea),
        apartmentCount(inputApartmentCount) {
    std::cout << "Building created" << std::endl;
  }

  ~Building() { std::cout << "Building destroyed" << std::endl; }

  Building &setFloors(unsigned int inputFloors) {
    floors = inputFloors;
    return *this;
  }

  Building &setArea(double inputArea) {
    area = inputArea;
    return *this;
  }

  Building &setApartmentCount(unsigned int inputApartmentCount) {
    apartmentCount = inputApartmentCount;
    return *this;
  }

  unsigned int getFloors() const { return floors; }
  double getArea() const { return area; }
  unsigned int getApartmentCount() const { return apartmentCount; }

  double getTotalArea() const { return floors * area; }

  void print() const {
    std::cout << "\nFloors: " << floors << "\nArea per floor: " << area
              << " sq meters"
              << "\nApartment Count: " << apartmentCount
              << "\nTotal Area: " << getTotalArea() << " sq meters\n\n";
  }
};

int main() {
  Building b1;
  b1.print();

  Building b2(10, 500.0, 40);
  b2.print();

  b1.setFloors(5).setArea(350.5).setApartmentCount(20);
  b1.print();

  std::cout << "Total area for building 2 is: " << b2.getTotalArea()
            << std::endl;

  return 0;
}
