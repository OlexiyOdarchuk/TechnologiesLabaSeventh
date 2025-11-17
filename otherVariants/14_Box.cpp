#include <iostream>

class Box {
private:
  double length;
  double width;
  double height;

public:
  Box() : length(0.0), width(0.0), height(0.0) {
    std::cout << "Box created" << std::endl;
  }

  Box(double inputLength, double inputWidth, double inputHeight)
      : length(inputLength), width(inputWidth), height(inputHeight) {
    std::cout << "Box created" << std::endl;
  }

  ~Box() { std::cout << "Box destroyed" << std::endl; }

  Box &setLength(double inputLength) {
    length = inputLength;
    return *this;
  }

  Box &setWidth(double inputWidth) {
    width = inputWidth;
    return *this;
  }

  Box &setHeight(double inputHeight) {
    height = inputHeight;
    return *this;
  }

  double getLength() const { return length; }
  double getWidth() const { return width; }
  double getHeight() const { return height; }

  double calculateVolume() const { return length * width * height; }

  void print() const {
    std::cout << "\nLength: " << length << "\nWidth: " << width
              << "\nHeight: " << height << "\n\n";
  }
};

int main() {
  Box box1;
  box1.print();

  Box box2(10.0, 5.0, 2.0);
  box2.print();

  box2.setLength(7.0).setWidth(3.0).setHeight(4.0);
  box2.print();

  std::cout << "Volume of box2: " << box2.calculateVolume() << std::endl;

  return 0;
}
