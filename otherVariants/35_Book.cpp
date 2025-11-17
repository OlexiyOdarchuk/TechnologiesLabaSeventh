#include <iostream>
#include <string>

class Book {
private:
  std::string title;
  std::string author;
  unsigned int publicationYear;

public:
  Book() : title("Unknown"), author("Unknown"), publicationYear(0) {
    std::cout << "Book created" << std::endl;
  }

  Book(std::string inputTitle, std::string inputAuthor,
       unsigned int inputPublicationYear)
      : title(inputTitle), author(inputAuthor),
        publicationYear(inputPublicationYear) {
    std::cout << "Book created" << std::endl;
  }

  ~Book() { std::cout << "Book destroyed" << std::endl; }

  Book &setTitle(std::string inputTitle) {
    title = inputTitle;
    return *this;
  }

  Book &setAuthor(std::string inputAuthor) {
    author = inputAuthor;
    return *this;
  }

  Book &setPublicationYear(unsigned int inputPublicationYear) {
    publicationYear = inputPublicationYear;
    return *this;
  }

  std::string getTitle() const { return title; }
  std::string getAuthor() const { return author; }
  unsigned int getPublicationYear() const { return publicationYear; }

  void print() const {
    std::cout << "\nTitle: " << title << "\nAuthor: " << author
              << "\nPublication Year: " << publicationYear << "\n\n";
  }
};

int main() {
  Book book1;
  book1.print();

  Book book2("The Lord of the Rings", "J.R.R. Tolkien", 1954);
  book2.print();

  book1.setTitle("Dune").setAuthor("Frank Herbert").setPublicationYear(1965);
  book1.print();

  return 0;
}
