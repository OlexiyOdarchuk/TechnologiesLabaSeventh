#include <iostream>
#include <string>
class BankCard {
private:
  std::string cardNumber;
  std::string cardHolderName;
  double balance;

public:
  BankCard() : cardNumber("Unknown"), cardHolderName("Unknown"), balance(0.0) {
    std::cout << "BankCard created" << std::endl;
  }

  BankCard(std::string inputCardNumber, std::string inputCardHolderName,
           double initialBalance)
      : cardNumber(inputCardNumber), cardHolderName(inputCardHolderName),
        balance(initialBalance) {
    std::cout << "BankCard created" << std::endl;
  }

  ~BankCard() { std::cout << "BankCard destroyed" << std::endl; }

  BankCard &setCardNumber(std::string inputCardNumber) {
    cardNumber = inputCardNumber;
    return *this;
  }

  BankCard &setCardHolderName(std::string inputCardHolderName) {
    cardHolderName = inputCardHolderName;
    return *this;
  }

  BankCard &setBalance(double inputBalance) {
    balance = inputBalance;
    return *this;
  }

  std::string getCardNumber() const { return cardNumber; }

  std::string getCardHolderName() const { return cardHolderName; }

  double getBalance() const { return balance; }

  void topUp(double amount) {
    if (amount > 0) {
      balance += amount;
      std::cout << "Topped up " << amount << ". New balance: " << balance
                << std::endl;
    } else {
      std::cout << "Top-up amount must be positive." << std::endl;
    }
  }

  void spend(double amount) {
    if (amount > 0 && balance >= amount) {
      balance -= amount;
      std::cout << "Spent " << amount << ". New balance: " << balance
                << std::endl;
    } else if (amount <= 0) {
      std::cout << "Spending amount must be positive." << std::endl;
    } else {
      std::cout << "Insufficient funds for spending." << std::endl;
    }
  }

  void print() const {
    std::cout << "\nBank Card Information:"
              << "\n  Card Number: " << cardNumber
              << "\n  Card Holder: " << cardHolderName
              << "\n  Balance: " << balance << "\n\n";
  }
};

int main() {
  BankCard bc1;
  bc1.setCardNumber("1111-2222-3333-4444")
      .setCardHolderName("Eve")
      .setBalance(500.0);
  bc1.print();
  bc1.topUp(100.0);
  bc1.spend(75.0);
  bc1.print();

  BankCard bc2("5555-6666-7777-8888", "Frank", 200.0);
  bc2.print();
  bc2.spend(300.0);
  bc2.print();

  return 0;
}
