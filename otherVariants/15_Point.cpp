#include <cmath>
#include <iostream>

class Point {
private:
  double x;
  double y;

public:
  Point() : x(0.0), y(0.0) { std::cout << "Point created" << std::endl; }

  Point(double inputX, double inputY) : x(inputX), y(inputY) {
    std::cout << "Point created" << std::endl;
  }

  ~Point() { std::cout << "Point destroyed" << std::endl; }

  Point &setX(double inputX) {
    x = inputX;
    return *this;
  }

  Point &setY(double inputY) {
    y = inputY;
    return *this;
  }

  double getX() const { return x; }
  double getY() const { return y; }

  double calculateDistanceToOrigin() const {
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
  }

  void print() const { std::cout << "\nPoint: (" << x << ", " << y << ")\n\n"; }
};

int main() {
  Point p1;
  p1.print();

  Point p2(3.0, 4.0);
  p2.print();

  p2.setX(5.0).setY(12.0);
  p2.print();

  std::cout << "Distance of p2 to origin: " << p2.calculateDistanceToOrigin()
            << std::endl;

  return 0;
}
