#include <iostream>
#include <string>

class Smartphone {
private:
  std::string name;
  std::string osVersion;
  unsigned int storageGB;

public:
  Smartphone() : name("Unknown"), osVersion("Unknown"), storageGB(0) {
    std::cout << "Smartphone created" << std::endl;
  }

  Smartphone(std::string inputName, std::string inputOsVersion,
             unsigned int inputStorageGB)
      : name(inputName), osVersion(inputOsVersion), storageGB(inputStorageGB) {
    std::cout << "Smartphone created" << std::endl;
  }

  ~Smartphone() { std::cout << "Smartphone destroyed" << std::endl; }

  Smartphone &setName(std::string inputName) {
    name = inputName;
    return *this;
  }

  Smartphone &setOsVersion(std::string inputOsVersion) {
    osVersion = inputOsVersion;
    return *this;
  }

  Smartphone &setStorageGB(unsigned int inputStorageGB) {
    storageGB = inputStorageGB;
    return *this;
  }

  std::string getName() const { return name; }

  std::string getOsVersion() const { return osVersion; }

  unsigned int getStorageGB() const { return storageGB; }

  void showInfo() const {
    std::cout << "\nSmartphone Information:"
              << "\n  Name: " << name << "\n  OS Version: " << osVersion
              << "\n  Storage: " << storageGB << "GB"
              << "\n\n";
  }
};

int main() {
  Smartphone s1;
  s1.setName("iPhone 14").setOsVersion("iOS 16").setStorageGB(128);
  s1.showInfo();

  Smartphone s2("Samsung Galaxy S23", "Android 13", 256);
  s2.showInfo();

  return 0;
}
