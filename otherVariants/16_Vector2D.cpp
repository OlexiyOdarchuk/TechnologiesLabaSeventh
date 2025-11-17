#include <iostream>

class Vector2D {
private:
  double x;
  double y;

public:
  Vector2D() : x(0.0), y(0.0) { std::cout << "Vector2D created" << std::endl; }

  Vector2D(double inputX, double inputY) : x(inputX), y(inputY) {
    std::cout << "Vector2D created" << std::endl;
  }

  ~Vector2D() { std::cout << "Vector2D destroyed" << std::endl; }

  Vector2D &setX(double inputX) {
    x = inputX;
    return *this;
  }

  Vector2D &setY(double inputY) {
    y = inputY;
    return *this;
  }

  double getX() const { return x; }
  double getY() const { return y; }

  Vector2D add(const Vector2D &other) const {
    return Vector2D(x + other.x, y + other.y);
  }

  Vector2D subtract(const Vector2D &other) const {
    return Vector2D(x - other.x, y - other.y);
  }

  void print() const {
    std::cout << "\nVector2D: <" << x << ", " << y << ">\n\n";
  }
};

int main() {
  Vector2D v1;
  v1.print();

  Vector2D v2(3.0, 4.0);
  v2.print();

  v2.setX(5.0).setY(12.0);
  v2.print();

  Vector2D v3(1.0, 2.0);
  Vector2D sum = v2.add(v3);
  std::cout << "Sum of v2 and v3:";
  sum.print();

  Vector2D difference = v2.subtract(v3);
  std::cout << "Difference of v2 and v3:";
  difference.print();

  return 0;
}
