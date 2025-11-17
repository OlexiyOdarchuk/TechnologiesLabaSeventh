#include <iostream>
#include <string>

class Product {
private:
  std::string name;
  double price;
  unsigned int quantity;

public:
  Product() : name("Unknown"), price(0.0), quantity(0) {
    std::cout << "Product created" << std::endl;
  }

  Product(std::string inputName, double inputPrice, unsigned int inputQuantity)
      : name(inputName), price(inputPrice), quantity(inputQuantity) {
    std::cout << "Product created" << std::endl;
  }

  ~Product() { std::cout << "Product destroyed" << std::endl; }

  Product &setName(std::string inputName) {
    name = inputName;
    return *this;
  }

  Product &setPrice(double inputPrice) {
    price = inputPrice;
    return *this;
  }

  Product &setQuantity(unsigned int inputQuantity) {
    quantity = inputQuantity;
    return *this;
  }

  std::string getName() const { return name; }
  double getPrice() const { return price; }
  unsigned int getQuantity() const { return quantity; }

  double calculateTotalPrice() const { return price * quantity; }

  void print() const {
    std::cout << "\nProduct Name: " << name << "\nPrice: " << price
              << "\nQuantity: " << quantity
              << "\nTotal Value: " << calculateTotalPrice() << "\n\n";
  }
};

int main() {
  Product p1;
  p1.print();

  Product p2("Laptop", 1200.50, 2);
  p2.print();

  p2.setName("Gaming Mouse").setPrice(75.99).setQuantity(5);
  p2.print();

  std::cout << "Total price for " << p2.getName() << ": "
            << p2.calculateTotalPrice() << std::endl;

  return 0;
}
