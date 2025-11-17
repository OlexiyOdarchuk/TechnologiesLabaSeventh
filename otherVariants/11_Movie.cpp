#include <iostream>
#include <string>

class Movie {
private:
  std::string title;
  std::string genre;
  unsigned int duration;

public:
  Movie() : title("Unknown"), genre("Unknown"), duration(0) {
    std::cout << "Movie created" << std::endl;
  }

  Movie(std::string inputTitle, std::string inputGenre,
        unsigned int inputDuration)
      : title(inputTitle), genre(inputGenre), duration(inputDuration) {
    std::cout << "Movie created" << std::endl;
  }

  ~Movie() { std::cout << "Movie destroyed" << std::endl; }

  Movie &setTitle(std::string inputTitle) {
    title = inputTitle;
    return *this;
  }

  Movie &setGenre(std::string inputGenre) {
    genre = inputGenre;
    return *this;
  }

  Movie &setDuration(unsigned int inputDuration) {
    duration = inputDuration;
    return *this;
  }

  std::string getTitle() const { return title; }
  std::string getGenre() const { return genre; }
  unsigned int getDuration() const { return duration; }

  bool isLong() const { return duration > 120; }

  void print() const {
    std::cout << "\nTitle: " << title << "\nGenre: " << genre
              << "\nDuration: " << duration << " minutes\n\n";
  }
};

int main() {
  Movie movie1;
  movie1.print();

  Movie movie2("The Matrix", "Sci-Fi", 136);
  movie2.print();

  movie2.setTitle("The Matrix Reloaded").setGenre("Sci-Fi").setDuration(138);
  movie2.print();

  std::cout << "Is \"" << movie2.getTitle() << "\" a long movie? "
            << (movie2.isLong() ? "Yes" : "No") << std::endl;

  return 0;
}
