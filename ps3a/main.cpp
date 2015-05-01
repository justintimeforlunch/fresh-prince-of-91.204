// Copyright [2015] Justin Nguyen

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Body.hpp"

void removeWhitespace(std::string& str) {
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
      str.erase(i, 1);
      i--;
    }
  }
}

int main(int argc, char* argv[]) {
  int planet_count;
  double univ_radius;
  std::string planet_name;
  std::string planet_filename;
  std::vector<Body> planets;
  sf::Image background;
  if (!background.loadFromFile("starfield.jpg"))
    return -1;
  sf::Texture texture;
  texture.loadFromImage(background);
  sf::Sprite sprite;
  sprite.setTexture(texture);
  sf::Vector2f size;
  size.x = background.getSize().x;
  size.y = background.getSize().y;
  std::cin >> planet_count >> univ_radius;
  for (int i = 0; i < planet_count; i++) {
    Body *planet = new Body (planet_count, univ_radius, size);
    std::cin >> *planet;
    getline(std::cin, planet_filename);
    removeWhitespace(planet_filename);
    planet_name = planet_filename;
    planet->setName(planet_name);
    planet->setFile(planet_filename);
    planets.push_back(*planet);
  }
  sf::RenderWindow window(sf::VideoMode(size.x, size.y), "ps3a");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        break;
      }
    }
    window.draw(sprite);
    for (std::vector<Body>::iterator iter = planets.begin();
         iter != planets.end(); iter++)
      window.draw(*iter);
    window.display();
  }
  return 0;
}
