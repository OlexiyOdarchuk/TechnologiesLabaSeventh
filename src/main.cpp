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

  Ticket &setPlace(const std::string &inputPlace) {
    place = inputPlace;
    return *this;
  }
  Ticket &setPrice(const unsigned int inputPrice) {
    price = inputPrice;
    return *this;
  }
  Ticket &setEvent(const std::string &inputEvent) {
    event = inputEvent;
    return *this;
  }

  std::string getPlace() const { return place; }
  unsigned int getPrice() const { return price; }
  std::string getEvent() const { return event; }

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