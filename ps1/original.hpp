// Copyright [2015] Justin Nguyen  [legal/copyright]

// include guard
#ifndef FRAC_HPP_
#define FRAC_HPP_

// incluced dependencies
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Frac : public sf::Drawable {
 public:
  Frac(int N, int o_size);
  ~Frac();
  void filledPoly(sf::Vector2f set_point[4], sf::RenderTarget& target,
                  sf::RenderStates states) const;
  void frac_re(double x, double y, double s, int count,
               sf::RenderTarget& target, sf::RenderStates states) const;
  
 private:
  sf::ConvexShape base_poly;
  int depth;
  int size;
  int length;
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
