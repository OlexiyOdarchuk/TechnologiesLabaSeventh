#include <cmath>
#include <iostream>

class ComplexNumber {
private:
  double real;
  double imaginary;

public:
  ComplexNumber() : real(0.0), imaginary(0.0) {
    std::cout << "ComplexNumber created" << std::endl;
  }

  ComplexNumber(double inputReal, double inputImaginary)
      : real(inputReal), imaginary(inputImaginary) {
    std::cout << "ComplexNumber created" << std::endl;
  }

  ~ComplexNumber() { std::cout << "ComplexNumber destroyed" << std::endl; }

  ComplexNumber &setReal(double inputReal) {
    real = inputReal;
    return *this;
  }

  ComplexNumber &setImaginary(double inputImaginary) {
    imaginary = inputImaginary;
    return *this;
  }

  double getReal() const { return real; }
  double getImaginary() const { return imaginary; }

  double calculateModulus() const {
    return std::sqrt(std::pow(real, 2) + std::pow(imaginary, 2));
  }

  void print() const {
    std::cout << "\nComplex Number: " << real;
    if (imaginary >= 0) {
      std::cout << " + " << imaginary << "i";
    } else {
      std::cout << " - " << -imaginary << "i";
    }
    std::cout << "\n\n";
  }
};

int main() {
  ComplexNumber c1;
  c1.print();

  ComplexNumber c2(3.0, 4.0);
  c2.print();

  c2.setReal(5.0).setImaginary(-2.0);
  c2.print();

  std::cout << "Modulus of c2: " << c2.calculateModulus() << std::endl;

  return 0;
}
