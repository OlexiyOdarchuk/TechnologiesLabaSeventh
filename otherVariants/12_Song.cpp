#include <iostream>
#include <string>

class Song {
private:
  std::string title;
  std::string artist;
  unsigned int duration;

public:
  Song() : title("Unknown"), artist("Unknown"), duration(0) {
    std::cout << "Song created" << std::endl;
  }

  Song(std::string inputTitle, std::string inputArtist,
       unsigned int inputDuration)
      : title(inputTitle), artist(inputArtist), duration(inputDuration) {
    std::cout << "Song created" << std::endl;
  }

  ~Song() { std::cout << "Song destroyed" << std::endl; }

  Song &setTitle(std::string inputTitle) {
    title = inputTitle;
    return *this;
  }

  Song &setArtist(std::string inputArtist) {
    artist = inputArtist;
    return *this;
  }

  Song &setDuration(unsigned int inputDuration) {
    duration = inputDuration;
    return *this;
  }

  std::string getTitle() const { return title; }
  std::string getArtist() const { return artist; }
  unsigned int getDuration() const { return duration; }

  void play() const {
    std::cout << "Playing: " << title << " by " << artist << std::endl;
  }

  void print() const {
    std::cout << "\nTitle: " << title << "\nArtist: " << artist
              << "\nDuration: " << duration << " seconds\n\n";
  }
};

int main() {
  Song song1;
  song1.print();
  song1.play();

  Song song2("Bohemian Rhapsody", "Queen", 354);
  song2.print();
  song2.play();

  song2.setTitle("Stairway to Heaven")
      .setArtist("Led Zeppelin")
      .setDuration(482);
  song2.print();
  song2.play();

  return 0;
}
