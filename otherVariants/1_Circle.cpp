#include <cmath>
#include <iostream>

class Circle {
private:
  double radius;
  double x_coordinate;
  double y_coordinate;

public:
  Circle() : radius(0.0), x_coordinate(0.0), y_coordinate(0.0) {
    std::cout << "Circle created" << std::endl;
  }

  Circle(double r, double x, double y)
      : radius(r), x_coordinate(x), y_coordinate(y) {
    std::cout << "Circle created" << std::endl;
  }

  ~Circle() { std::cout << "Circle destroyed" << std::endl; }

  Circle &setRadius(double r) {
    radius = r;
    return *this;
  }

  Circle &setXCoordinate(double x) {
    x_coordinate = x;
    return *this;
  }

  Circle &setYCoordinate(double y) {
    y_coordinate = y;
    return *this;
  }

  double getRadius() const { return radius; }

  double getXCoordinate() const { return x_coordinate; }

  double getYCoordinate() const { return y_coordinate; }

  double calculateArea() const { return M_PI * pow(radius, 2); }

  double calculateCircumference() const { return 2 * M_PI * radius; }

  void print() const {
    std::cout << "\nCircle Properties:"
              << "\n  Radius: " << radius << "\n  Center X: " << x_coordinate
              << "\n  Center Y: " << y_coordinate
              << "\n  Area: " << calculateArea()
              << "\n  Circumference: " << calculateCircumference() << "\n\n";
  }
};

int main() {
  Circle c1;
  c1.setRadius(5.0).setXCoordinate(1.0).setYCoordinate(2.0);
  c1.print();

  Circle c2(10.0, 5.0, 5.0);
  c2.print();

  return 0;
}
