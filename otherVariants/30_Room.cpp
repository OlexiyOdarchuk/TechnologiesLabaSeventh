#include <iostream>

class Room {
private:
  double length;
  double width;
  double height;

public:
  Room() : length(0.0), width(0.0), height(0.0) {
    std::cout << "Room created" << std::endl;
  }

  Room(double inputLength, double inputWidth, double inputHeight)
      : length(inputLength), width(inputWidth), height(inputHeight) {
    std::cout << "Room created" << std::endl;
  }

  ~Room() { std::cout << "Room destroyed" << std::endl; }

  Room &setLength(double inputLength) {
    length = inputLength;
    return *this;
  }

  Room &setWidth(double inputWidth) {
    width = inputWidth;
    return *this;
  }

  Room &setHeight(double inputHeight) {
    height = inputHeight;
    return *this;
  }

  double getLength() const { return length; }
  double getWidth() const { return width; }
  double getHeight() const { return height; }

  double getVolume() const { return length * width * height; }

  void print() const {
    std::cout << "\nLength: " << length << " m\nWidth: " << width
              << " m\nHeight: " << height << " m"
              << "\nVolume: " << getVolume() << " cubic meters\n\n";
  }
};

int main() {
  Room room1;
  room1.print();

  Room room2(5.0, 4.0, 2.5);
  room2.print();

  room1.setLength(6.0).setWidth(3.0).setHeight(2.7);
  room1.print();

  std::cout << "The volume of room 2 is: " << room2.getVolume()
            << " cubic meters." << std::endl;

  return 0;
}
