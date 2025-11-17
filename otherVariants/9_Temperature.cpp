#include <iostream>

class Temperature {
private:
  double celsius;
  double fahrenheit;
  double kelvin;

  void updateFahrenheit() { fahrenheit = (celsius * 9.0 / 5.0) + 32.0; }

  void updateKelvin() { kelvin = celsius + 273.15; }

  void updateAll() {
    updateFahrenheit();
    updateKelvin();
  }

public:
  Temperature() : celsius(0.0) {
    updateAll();
    std::cout << "Temperature created" << std::endl;
  }

  Temperature(double inputCelsius) : celsius(inputCelsius) {
    updateAll();
    std::cout << "Temperature created" << std::endl;
  }

  ~Temperature() { std::cout << "Temperature destroyed" << std::endl; }

  Temperature &setCelsius(double inputCelsius) {
    celsius = inputCelsius;
    updateAll();
    return *this;
  }

  Temperature &setFahrenheit(double inputFahrenheit) {
    fahrenheit = inputFahrenheit;
    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    updateKelvin();
    return *this;
  }

  Temperature &setKelvin(double inputKelvin) {
    kelvin = inputKelvin;
    celsius = kelvin - 273.15;
    updateFahrenheit();
    return *this;
  }

  double getCelsius() const { return celsius; }

  double getFahrenheit() const { return fahrenheit; }

  double getKelvin() const { return kelvin; }

  void print() const {
    std::cout << "\nTemperature Values:"
              << "\n  Celsius: " << celsius << "°C"
              << "\n  Fahrenheit: " << fahrenheit << "°F"
              << "\n  Kelvin: " << kelvin << "K"
              << "\n\n";
  }
};

int main() {
  Temperature t1;
  t1.setCelsius(25.0);
  t1.print();

  Temperature t2(100.0);
  t2.print();

  t1.setFahrenheit(68.0);
  t1.print();

  t2.setKelvin(273.15);
  t2.print();

  return 0;
}
