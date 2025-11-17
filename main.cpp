#include <iostream>
#include <string>

class Ticket {
private:
  std::string place;
  unsigned int price;
  std::string event;

public:
  Ticket() : place("Unknow"), price(0), event("Unknow") {
    std::cout << "Ticket created";
  }

  Ticket(std::string inputPlace, unsigned int inputPrice,
         std::string inputEvent)
      : place(inputPlace), price(inputPrice), event(inputEvent) {
    std::cout << "Ticket created";
  }

  ~Ticket() { std::cout << "Ticket destroyed" << std::endl; }

  Ticket &setPlace(std::string inputPlace) {
    place = inputPlace;
    return *this;
  }
  Ticket &setPrice(unsigned int inputPrice) {
    price = inputPrice;
    return *this;
  }
  Ticket &setEvent(std::string inputEvent) {
    event = inputEvent;
    return *this;
  }
  void print() const {
    std::cout << "\nPlace: " << place << "\nPrice: " << price
              << "\nEvent: " << event << "\n\n";
  }
};

int main() {
  Ticket obj;
  obj.setEvent("Our event");
  obj.setPrice(2000);
  obj.setPlace("Коледж");
  obj.print();
}