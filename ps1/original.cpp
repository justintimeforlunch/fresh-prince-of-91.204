// Copyright [2015] Justin Nguyen  [legal/copyright]

#include "original.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "You need to enter a depth and window size";
    exit(1);
  }
  sf::RenderWindow window(sf::VideoMode(atoi(argv[2]), atoi(argv[2])),
                          "Fractal Demo");
  Frac frac(atoi(argv[1]), atoi(argv[2]));
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        break;
      }
    }
    window.clear();
    window.draw(frac);
    window.display();
  }
  return 0;
}
