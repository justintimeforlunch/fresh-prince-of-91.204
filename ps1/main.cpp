// Copyright [2015] Justin Nguyen

#include "sierpinski.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
  if (argc < 3) {
    std::cout << "You need to enter a depth and window size.\n";
    exit(1);
  }
  sf::RenderWindow window(sf::VideoMode(atoi(argv[2]), atoi(argv[2])),
                          "Sierpinski Demo");
  Sierpinski sierpinski(atoi(argv[1]), atoi(argv[2]));
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        break;
      }
    }
    window.clear();
    window.draw(sierpinski);
    window.display();
  }
  return 0;
}
