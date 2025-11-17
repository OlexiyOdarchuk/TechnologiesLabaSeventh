#include <iostream>
#include <string>

class Country {
private:
  std::string name;
  std::string capital;
  unsigned long population;

public:
  Country() : name("Unknown"), capital("Unknown"), population(0) {
    std::cout << "Country created" << std::endl;
  }

  Country(std::string inputName, std::string inputCapital,
          unsigned long inputPopulation)
      : name(inputName), capital(inputCapital), population(inputPopulation) {
    std::cout << "Country created" << std::endl;
  }

  ~Country() { std::cout << "Country destroyed" << std::endl; }

  Country &setName(std::string inputName) {
    name = inputName;
    return *this;
  }

  Country &setCapital(std::string inputCapital) {
    capital = inputCapital;
    return *this;
  }

  Country &setPopulation(unsigned long inputPopulation) {
    population = inputPopulation;
    return *this;
  }

  std::string getName() const { return name; }
  std::string getCapital() const { return capital; }
  unsigned long getPopulation() const { return population; }

  void comparePopulation(const Country &other) const {
    std::cout << "\nComparing population of " << name << " and " << other.name
              << ":" << std::endl;
    if (population > other.population) {
      std::cout << name << " has a larger population." << std::endl;
    } else if (population < other.population) {
      std::cout << other.name << " has a larger population." << std::endl;
    } else {
      std::cout << "Both countries have the same population." << std::endl;
    }
  }

  void print() const {
    std::cout << "\nCountry Name: " << name << "\nCapital: " << capital
              << "\nPopulation: " << population << "\n\n";
  }
};

int main() {
  Country country1;
  country1.print();

  Country country2("Ukraine", "Kyiv", 43700000);
  country2.print();

  Country country3("Poland", "Warsaw", 38400000);
  country3.print();

  country2.comparePopulation(country3);

  country1.setName("Germany").setCapital("Berlin").setPopulation(83200000);
  country1.print();

  country1.comparePopulation(country2);

  return 0;
}
