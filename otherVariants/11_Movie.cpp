#include <iostream>
#include <string>

class Movie {
private:
  std::string title;
  std::string genre;
  int duration;

public:
  Movie() : title(""), genre(""), duration(0) {}

  Movie(const std::string &title, const std::string &genre, int duration)
      : title(title), genre(genre), duration(duration) {}

  ~Movie() {
    std::cout << "Destructor called for Movie " << title << std::endl;
  }

  std::string getTitle() const { return title; }
  std::string getGenre() const { return genre; }
  int getDuration() const { return duration; }

  Movie &setTitle(const std::string &title) {
    this->title = title;
    return *this;
  }

  Movie &setGenre(const std::string &genre) {
    this->genre = genre;
    return *this;
  }

  Movie &setDuration(int duration) {
    this->duration = duration;
    return *this;
  }

  bool isLong() const { return duration > 120; }

  void print() const {
    std::cout << "Movie Information:" << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "Duration: " << duration << " minutes" << std::endl;
  }
};

int main() {
  Movie movie1;
  Movie movie2("Inception", "Sci-Fi", 148);

  std::cout << "Movie 1 (default constructor):" << std::endl;
  movie1.print();
  std::cout << std::endl;

  std::cout << "Movie 2 (constructor with parameters):" << std::endl;
  movie2.print();
  std::cout << std::endl;

  std::cout << "Updating Movie 1's information..." << std::endl;
  movie1.setTitle("The Dark Knight").setGenre("Action").setDuration(152);
  movie1.print();
  std::cout << std::endl;

  std::cout << "Final Information:" << std::endl;
  movie1.print();
  movie2.print();
  std::cout << std::endl;

  std::cout << "Is '" << movie1.getTitle() << "' a long movie? "
            << (movie1.isLong() ? "Yes" : "No") << std::endl;
  std::cout << "Is '" << movie2.getTitle() << "' a long movie? "
            << (movie2.isLong() ? "Yes" : "No") << std::endl;

  Movie movie3("Short Movie", "Comedy", 90);
  movie3.print();
  std::cout << "Is '" << movie3.getTitle() << "' a long movie? "
            << (movie3.isLong() ? "Yes" : "No") << std::endl;

  return 0;
}