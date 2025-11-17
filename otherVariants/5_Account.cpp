#include <iostream>

class Account {
private:
  std::string accountNumber;
  std::string ownerName;
  double balance;

public:
  Account() : accountNumber("Unknown"), ownerName("Unknown"), balance(0.0) {
    std::cout << "Account created" << std::endl;
  }

  Account(std::string inputAccountNumber, std::string inputOwnerName,
          double initialBalance)
      : accountNumber(inputAccountNumber), ownerName(inputOwnerName),
        balance(initialBalance) {
    std::cout << "Account created" << std::endl;
  }

  ~Account() { std::cout << "Account destroyed" << std::endl; }

  Account &setAccountNumber(std::string inputAccountNumber) {
    accountNumber = inputAccountNumber;
    return *this;
  }

  Account &setOwnerName(std::string inputOwnerName) {
    ownerName = inputOwnerName;
    return *this;
  }

  Account &setBalance(double inputBalance) {
    balance = inputBalance;
    return *this;
  }

  std::string getAccountNumber() const { return accountNumber; }

  std::string getOwnerName() const { return ownerName; }

  double getBalance() const { return balance; }

  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      std::cout << "Deposited " << amount << ". New balance: " << balance
                << std::endl;
    } else {
      std::cout << "Deposit amount must be positive." << std::endl;
    }
  }

  void withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
      balance -= amount;
      std::cout << "Withdrew " << amount << ". New balance: " << balance
                << std::endl;
    } else if (amount <= 0) {
      std::cout << "Withdrawal amount must be positive." << std::endl;
    }
  }

  void print() const {
    std::cout << "\nAccount Information:"
              << "\n  Account Number: " << accountNumber
              << "\n  Owner: " << ownerName << "\n  Balance: " << balance
              << "\n\n";
  }
};

int main() {
  Account acc1;
  acc1.setAccountNumber("12345").setOwnerName("Charlie").setBalance(1000.0);
  acc1.print();
  acc1.deposit(200.0);
  acc1.withdraw(50.0);
  acc1.print();

  Account acc2("67890", "Diana", 500.0);
  acc2.print();
  acc2.withdraw(700.0);
  acc2.print();

  return 0;
}
