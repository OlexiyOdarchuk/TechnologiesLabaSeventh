#include <iostream>
#include <string>

class City {
private:
  std::string name;
  unsigned long population;
  double area;

public:
  City() : name("Unknown"), population(0), area(0.0) {
    std::cout << "City created" << std::endl;
  }

  City(std::string inputName, unsigned long inputPopulation, double inputArea)
      : name(inputName), population(inputPopulation), area(inputArea) {
    std::cout << "City created" << std::endl;
  }

  ~City() { std::cout << "City destroyed" << std::endl; }

  City &setName(std::string inputName) {
    name = inputName;
    return *this;
  }

  City &setPopulation(unsigned long inputPopulation) {
    population = inputPopulation;
    return *this;
  }

  City &setArea(double inputArea) {
    area = inputArea;
    return *this;
  }

  std::string getName() const { return name; }
  unsigned long getPopulation() const { return population; }
  double getArea() const { return area; }

  double calculatePopulationDensity() const {
    if (area > 0) {
      return static_cast<double>(population) / area;
    } else {
      return 0.0;
    }
  }

  void print() const {
    std::cout << "\nCity Name: " << name << "\nPopulation: " << population
              << "\nArea: " << area << " sq km\n"
              << "Population Density: " << calculatePopulationDensity()
              << " people/sq km\n\n";
  }
};

int main() {
  City city1;
  city1.print();

  City city2("Kyiv", 2960000, 839.0);
  city2.print();

  city2.setName("Lviv").setPopulation(720000).setArea(182.0);
  city2.print();

  City city3("Smallville", 1000, 0.0);
  city3.print();

  return 0;
}