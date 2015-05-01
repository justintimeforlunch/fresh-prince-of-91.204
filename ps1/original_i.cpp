// Copyright [2015] Justin Nguyen

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

#include "original.hpp"

void Frac::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(base_poly, states);
  frac_re(size * 0.5, 0.5 * size, 0.25 * size, depth, target, states);
}
Frac::Frac(int N, int o_size) {
  depth = N;
  size = o_size;
  length = o_size;
  base_poly.setPointCount(4);
  base_poly.setPoint(0, sf::Vector2f(length / 2, 0));
  base_poly.setPoint(1, sf::Vector2f(0, length / 2));
  base_poly.setPoint(2, sf::Vector2f(length / 2, (length)));
  base_poly.setPoint(3, sf::Vector2f((length), length / 2));
  base_poly.setFillColor(sf::Color::Black);
}

Frac::~Frac() {
}

void Frac::filledPoly(sf::Vector2f set_point[4], sf::RenderTarget& target,
                      sf::RenderStates states) const {
  sf::ConvexShape poly;
  poly.setPointCount(4);
  poly.setPoint(0, set_point[0]);
  poly.setPoint(1, set_point[1]);
  poly.setPoint(2, set_point[2]);
  poly.setPoint(3, set_point[3]);
  poly.setFillColor(sf::Color::White);
  poly.setOutlineColor(sf::Color::Black);
  poly.setOutlineThickness(1);
  poly.setPosition(0, (length - (2 * set_point[0].y)));
  target.draw(poly, states);
}

void Frac::frac_re(double x, double y, double s, int count,
                   sf::RenderTarget& target, sf::RenderStates states) const {
  sf::Vector2f set_next_points[4];
  if (count == 0) {
    return;
  } else {
    // top right
    set_next_points[0].x = (x + s);
    set_next_points[0].y = (y + s);
    // bot right
    set_next_points[1].x = (x + s);
    set_next_points[1].y = (y + (s * 3));
    // bot left
    set_next_points[2].x = (x - s);
    set_next_points[2].y = (y + (s * 3));
    // top left
    set_next_points[3].x = (x - s);
    set_next_points[3].y = (y + s);
    filledPoly(set_next_points, target, states);
    frac_re((x - ((s / 3) * 4)), y, (s / 3), count - 1, target, states);
    frac_re(x, (y + ((s / 3) * 4)), (s / 3), count - 1, target, states);
    frac_re((x + ((s / 3) * 4)), y, (s / 3), count - 1, target, states);
    frac_re(x, ((y - ((s / 3) * 4))), (s / 3), count - 1, target, states);
    frac_re(x, y, (s / 3), count - 1, target, states);
  }
}
