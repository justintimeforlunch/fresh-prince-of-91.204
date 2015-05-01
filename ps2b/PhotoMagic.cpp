// Copyright [2015] Justin Nguyen

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <algorithm>
#include "LFSR.hpp"

sf::Image transform(sf::Image picture, LFSR lfsr) {
  sf::Vector2u size = picture.getSize();
  sf::Color p2;
  for (size_t x = 0; x < size.x; x++) {
    for (size_t y = 0; y < size.y; y++) {
      p2 = picture.getPixel(x, y);
      p2.r = p2.r ^ lfsr.generate(8);
      p2.g = p2.g ^ lfsr.generate(8);
      p2.b = p2.b ^ lfsr.generate(8);
      picture.setPixel(x, y, p2);
    }
  }
  return picture;
}

int main(int argc, char *argv[]) {
  std::string fi;
  if (argc < 3) {
    std::cout << "Usage: " << argv[0] << "inputfile LFSR bit" << std::endl;
    exit(0);
  } else {
    fi = argv[1];
  }
  sf::Image image;
  if (!image.loadFromFile(fi))
    return -1;
  sf::Image imageOut;
  if (!imageOut.loadFromFile(fi))
    return -1;
  LFSR lfsr(argv[2], atoi(argv[3]));
  imageOut = transform(imageOut, lfsr);
  sf::Vector2u size = image.getSize();
  sf::RenderWindow window(sf::VideoMode(size.x * 2, size.y), "Meow");
  if (!imageOut.saveToFile(fi))
    return -1;
  sf::Texture texture;
  texture.loadFromImage(image);
  sf::Sprite sprite;
  sprite.setTexture(texture);
  sf::Texture textureOut;
  textureOut.loadFromImage(imageOut);
  sf::Sprite spriteOut;
  spriteOut.setTexture(textureOut);
  spriteOut.setPosition(size.x, 0);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear(sf::Color::White);
    window.draw(sprite);
    window.draw(spriteOut);
    window.display();
  }
  if (!imageOut.saveToFile("cat-out.bmp"))
    return -1;
  return 0;
}
