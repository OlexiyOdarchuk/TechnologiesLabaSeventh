#include <cmath>
#include <iostream>

class Triangle {
private:
  double sideA;
  double sideB;
  double sideC;

public:
  Triangle() : sideA(0.0), sideB(0.0), sideC(0.0) {
    std::cout << "Triangle created" << std::endl;
  }

  Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
    std::cout << "Triangle created" << std::endl;
  }

  ~Triangle() { std::cout << "Triangle destroyed" << std::endl; }

  Triangle &setSideA(double a) {
    sideA = a;
    return *this;
  }

  Triangle &setSideB(double b) {
    sideB = b;
    return *this;
  }

  Triangle &setSideC(double c) {
    sideC = c;
    return *this;
  }

  double getSideA() const { return sideA; }

  double getSideB() const { return sideB; }

  double getSideC() const { return sideC; }

  bool isValid() const {
    return (sideA + sideB > sideC) && (sideA + sideC > sideB) &&
           (sideB + sideC > sideA);
  }

  double calculatePerimeter() const {
    if (!isValid()) {
      return 0.0;
    }
    return sideA + sideB + sideC;
  }

  double calculateArea() const {
    if (!isValid()) {
      return 0.0;
    }
    double s = calculatePerimeter() / 2;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
  }

  void print() const {
    std::cout << "\nTriangle Properties:"
              << "\n  Side A: " << sideA << "\n  Side B: " << sideB
              << "\n  Side C: " << sideC;
    if (isValid()) {
      std::cout << "\n  Perimeter: " << calculatePerimeter()
                << "\n  Area: " << calculateArea();
    } else {
      std::cout << "\n  (Invalid Triangle)";
    }
    std::cout << "\n\n";
  }
};

int main() {
  Triangle t1;
  t1.setSideA(3.0).setSideB(4.0).setSideC(5.0);
  t1.print();

  Triangle t2(7.0, 10.0, 5.0);
  t2.print();

  Triangle t3(1.0, 2.0, 5.0);
  t3.print();

  return 0;
}
