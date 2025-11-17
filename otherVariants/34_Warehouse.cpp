#include <iostream>
#include <string>

class Warehouse {
private:
  std::string name;
  unsigned int itemCount;
  double area;

public:
  Warehouse() : name("Unknown"), itemCount(0), area(0.0) {
    std::cout << "Warehouse created" << std::endl;
  }

  Warehouse(std::string inputName, unsigned int inputItemCount,
            double inputArea)
      : name(inputName), itemCount(inputItemCount), area(inputArea) {
    std::cout << "Warehouse created" << std::endl;
  }

  ~Warehouse() { std::cout << "Warehouse destroyed" << std::endl; }

  Warehouse &setName(std::string inputName) {
    name = inputName;
    return *this;
  }

  Warehouse &setItemCount(unsigned int inputItemCount) {
    itemCount = inputItemCount;
    return *this;
  }

  Warehouse &setArea(double inputArea) {
    area = inputArea;
    return *this;
  }

  std::string getName() const { return name; }
  unsigned int getItemCount() const { return itemCount; }
  double getArea() const { return area; }

  void addGoods(unsigned int count) {
    itemCount += count;
    std::cout << "\nAdded " << count << " items. Total items: " << itemCount
              << std::endl;
  }

  void removeGoods(unsigned int count) {
    if (count > itemCount) {
      std::cout << "\nCannot remove " << count << " items. Only " << itemCount
                << " available. Removing all items." << std::endl;
      itemCount = 0;
    } else {
      itemCount -= count;
      std::cout << "\nRemoved " << count
                << " items. Remaining items: " << itemCount << std::endl;
    }
  }

  void print() const {
    std::cout << "\nWarehouse Name: " << name << "\nItem Count: " << itemCount
              << "\nArea: " << area << " sq meters\n\n";
  }
};

int main() {
  Warehouse w1;
  w1.print();

  Warehouse w2("Main Warehouse", 5000, 10000.0);
  w2.print();

  w2.addGoods(500);
  w2.print();

  w2.removeGoods(1200);
  w2.print();

  w2.removeGoods(5000);
  w2.print();

  w1.setName("Local Storage").setItemCount(100).setArea(500.0);
  w1.print();

  return 0;
}
