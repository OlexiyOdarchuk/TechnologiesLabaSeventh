#include <iostream>
#include <string>

class Bank {
private:
  std::string name;
  unsigned int clientCount;
  double totalDeposits;

public:
  Bank() : name("Unknown"), clientCount(0), totalDeposits(0.0) {
    std::cout << "Bank created" << std::endl;
  }

  Bank(std::string inputName, unsigned int inputClientCount,
       double inputTotalDeposits)
      : name(inputName), clientCount(inputClientCount),
        totalDeposits(inputTotalDeposits) {
    std::cout << "Bank created" << std::endl;
  }

  ~Bank() { std::cout << "Bank destroyed" << std::endl; }

  Bank &setName(std::string inputName) {
    name = inputName;
    return *this;
  }

  Bank &setClientCount(unsigned int inputClientCount) {
    clientCount = inputClientCount;
    return *this;
  }

  Bank &setTotalDeposits(double inputTotalDeposits) {
    totalDeposits = inputTotalDeposits;
    return *this;
  }

  std::string getName() const { return name; }
  unsigned int getClientCount() const { return clientCount; }
  double getTotalDeposits() const { return totalDeposits; }

  double averageDeposit() const {
    if (clientCount > 0) {
      return totalDeposits / clientCount;
    } else {
      return 0.0;
    }
  }

  void print() const {
    std::cout << "\nBank Name: " << name << "\nClient Count: " << clientCount
              << "\nTotal Deposits: " << totalDeposits
              << "\nAverage Deposit: " << averageDeposit() << "\n\n";
  }
};

int main() {
  Bank bank1;
  bank1.print();

  Bank bank2("National Bank", 1000, 1500000.0);
  bank2.print();

  bank1.setName("Local Credit Union")
      .setClientCount(500)
      .setTotalDeposits(750000.0);
  bank1.print();

  Bank bank3("Empty Bank", 0, 0.0);
  bank3.print();

  return 0;
}
