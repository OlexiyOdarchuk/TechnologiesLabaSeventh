#include <iostream>

int calculateGCD(int a, int b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

class Fraction {
private:
  int numerator;
  int denominator;

public:
  Fraction() : numerator(0), denominator(1) {
    std::cout << "Fraction created" << std::endl;
  }

  Fraction(int inputNumerator, int inputDenominator)
      : numerator(inputNumerator) {
    if (inputDenominator == 0) {
      std::cerr << "Error: Denominator cannot be zero. Setting to 1."
                << std::endl;
      denominator = 1;
    } else {
      denominator = inputDenominator;
    }
    std::cout << "Fraction created" << std::endl;
  }

  ~Fraction() { std::cout << "Fraction destroyed" << std::endl; }

  Fraction &setNumerator(int inputNumerator) {
    numerator = inputNumerator;
    return *this;
  }

  Fraction &setDenominator(int inputDenominator) {
    if (inputDenominator == 0) {
      std::cerr
          << "Error: Denominator cannot be zero. Keeping current denominator."
          << std::endl;
    } else {
      denominator = inputDenominator;
    }
    return *this;
  }

  int getNumerator() const { return numerator; }
  int getDenominator() const { return denominator; }

  void simplify() {
    int commonDivisor =
        calculateGCD(std::abs(numerator), std::abs(denominator));
    numerator /= commonDivisor;
    denominator /= commonDivisor;
    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
  }

  void print() const {
    std::cout << "\nFraction: " << numerator << "/" << denominator << "\n\n";
  }
};

int main() {
  Fraction f1;
  f1.print();

  Fraction f2(2, 4);
  f2.print();
  f2.simplify();
  std::cout << "Simplified f2:";
  f2.print();

  Fraction f3(10, -15);
  f3.print();
  f3.simplify();
  std::cout << "Simplified f3:";
  f3.print();

  f1.setNumerator(6).setDenominator(9);
  f1.print();
  f1.simplify();
  std::cout << "Simplified f1:";
  f1.print();

  Fraction f4(5, 0);
  f4.print();

  return 0;
}
