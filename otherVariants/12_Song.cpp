#include <iostream>
#include <string>

class Song {
private:
  std::string title;
  std::string artist;
  int duration;

public:
  Song() : title(""), artist(""), duration(0) {}
  Song(const std::string &title, const std::string &artist, int duration)
      : title(title), artist(artist), duration(duration) {}

  ~Song() { std::cout << "Destructor called for Song " << title << std::endl; }

  std::string getTitle() const { return title; }
  std::string getArtist() const { return artist; }
  int getDuration() const { return duration; }

  Song *setTitle(const std::string &title) {
    this->title = title;
    return this;
  }

  Song *setArtist(const std::string &artist) {
    this->artist = artist;
    return this;
  }

  Song *setDuration(int duration) {
    this->duration = duration;
    return this;
  }

  void play() const {
    std::cout << "Playing: " << title << " by " << artist << std::endl;
  }

  void print() const {
    std::cout << "Song Information:" << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Artist: " << artist << std::endl;
    std::cout << "Duration: " << duration << " seconds" << std::endl;
  }
};

int main() {
  Song song1;
  Song song2("Bohemian Rhapsody", "Queen", 355);

  std::cout << "Song 1 (default constructor):" << std::endl;
  song1.print();
  std::cout << std::endl;

  std::cout << "Song 2 (constructor with parameters):" << std::endl;
  song2.print();
  std::cout << std::endl;

  std::cout << "Updating Song 1's information..." << std::endl;
  song1.setTitle("Stairway to Heaven")
      ->setArtist("Led Zeppelin")
      ->setDuration(482);
  song1.print();
  std::cout << std::endl;

  std::cout << "Final Information:" << std::endl;
  song1.print();
  song2.print();
  std::cout << std::endl;

  song1.play();
  song2.play();

  return 0;
}