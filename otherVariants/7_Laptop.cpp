#include <iostream>
#include <string>

class Laptop {
private:
  std::string model;
  std::string processor;
  unsigned int ramGB;

public:
  Laptop() : model("Unknown"), processor("Unknown"), ramGB(0) {
    std::cout << "Laptop created" << std::endl;
  }

  Laptop(std::string inputModel, std::string inputProcessor,
         unsigned int inputRamGB)
      : model(inputModel), processor(inputProcessor), ramGB(inputRamGB) {
    std::cout << "Laptop created" << std::endl;
  }

  ~Laptop() { std::cout << "Laptop destroyed" << std::endl; }

  Laptop &setModel(std::string inputModel) {
    model = inputModel;
    return *this;
  }

  Laptop &setProcessor(std::string inputProcessor) {
    processor = inputProcessor;
    return *this;
  }

  Laptop &setRamGB(unsigned int inputRamGB) {
    ramGB = inputRamGB;
    return *this;
  }

  std::string getModel() const { return model; }

  std::string getProcessor() const { return processor; }

  unsigned int getRamGB() const { return ramGB; }

  void comparePerformance(const Laptop &other) const {
    std::cout << "\nComparing " << this->model << " with " << other.model
              << ":\n";
    if (this->ramGB > other.ramGB) {
      std::cout << this->model << " has more RAM (" << this->ramGB
                << "GB) than " << other.model << " (" << other.ramGB << "GB)."
                << std::endl;
    } else if (this->ramGB < other.ramGB) {
      std::cout << other.model << " has more RAM (" << other.ramGB
                << "GB) than " << this->model << " (" << this->ramGB << "GB)."
                << std::endl;
    } else {
      std::cout << this->model << " and " << other.model
                << " have the same RAM (" << this->ramGB << "GB)." << std::endl;
    }
  }

  void print() const {
    std::cout << "\nLaptop Information:"
              << "\n  Model: " << model << "\n  Processor: " << processor
              << "\n  RAM: " << ramGB << "GB"
              << "\n\n";
  }
};

int main() {
  Laptop l1;
  l1.setModel("Dell XPS 15").setProcessor("Intel i7").setRamGB(16);
  l1.print();

  Laptop l2("MacBook Pro", "Apple M1", 8);
  l2.print();

  l1.comparePerformance(l2);

  return 0;
}
