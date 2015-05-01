// Copyright [2015] Justin Nguyen

// include guard
#ifndef SIERPINSKI_HPP_
#define SIERPINSKI_HPP_

// incluced dependencies
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Sierpinski : public sf::Drawable {
 public:
  Sierpinski(int N, int tri_size);
  ~Sierpinski();
  void filledTriangle(sf::Vector2f set_point[3], sf::RenderTarget& target,
                      sf::RenderStates states) const;
  void sierpinski(double x, double y, double s, int count,
                  sf::RenderTarget& target, sf::RenderStates states) const;
  
 private:
  sf::ConvexShape base_triangle;
  int depth;
  // 2 units so they don't change the value of each other
  int size;
  int length;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
