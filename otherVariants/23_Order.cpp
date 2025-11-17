#include <iostream>
#include <string>

class Order {
private:
  std::string orderNumber;
  double amount;
  std::string status;

public:
  Order() : orderNumber("N/A"), amount(0.0), status("Pending") {
    std::cout << "Order created" << std::endl;
  }

  Order(std::string inputOrderNumber, double inputAmount,
        std::string inputStatus)
      : orderNumber(inputOrderNumber), amount(inputAmount),
        status(inputStatus) {
    std::cout << "Order created" << std::endl;
  }

  ~Order() { std::cout << "Order destroyed" << std::endl; }

  Order &setOrderNumber(std::string inputOrderNumber) {
    orderNumber = inputOrderNumber;
    return *this;
  }

  Order &setAmount(double inputAmount) {
    amount = inputAmount;
    return *this;
  }

  Order &setStatus(std::string inputStatus) {
    status = inputStatus;
    return *this;
  }

  std::string getOrderNumber() const { return orderNumber; }
  double getAmount() const { return amount; }
  std::string getStatus() const { return status; }

  void completeOrder() {
    status = "Completed";
    std::cout << "Order " << orderNumber << " marked as Completed."
              << std::endl;
  }

  void print() const {
    std::cout << "\nOrder Number: " << orderNumber << "\nAmount: " << amount
              << "\nStatus: " << status << "\n\n";
  }
};

int main() {
  Order order1;
  order1.print();

  Order order2("ORD001", 150.75, "Pending");
  order2.print();

  order2.setOrderNumber("ORD002").setAmount(299.99).setStatus("Processing");
  order2.print();

  order2.completeOrder();
  order2.print();

  return 0;
}
