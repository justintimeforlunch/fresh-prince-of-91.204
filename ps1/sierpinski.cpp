// Copyright [2015] Justin Nguyen

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "sierpinski.hpp"

void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(base_triangle, states);
  sierpinski(0.5 * size, 0.0, 0.5 * size, depth, target, states);
}

Sierpinski::Sierpinski(int N, int tri_size) {
  depth = N;
  size = tri_size;
  length = tri_size;
  // sets the base triangle to the size of the window
  base_triangle.setPointCount(3);
  base_triangle.setPoint(0, sf::Vector2f(0, length));
  base_triangle.setPoint(1, sf::Vector2f(length, length));
  base_triangle.setPoint(2, sf::Vector2f((length / 2),
                                         (length - (sqrt(3) / 2) * length)));
  base_triangle.setFillColor(sf::Color::Red);
}

Sierpinski::~Sierpinski() {
}

void Sierpinski::sierpinski(double x, double y, double s, int count,
                            sf::RenderTarget& target,
                            sf::RenderStates states) const {
  sf::Vector2f set_next_points[3];
  if (count == 0) {  // causes segmentation error without
    return;
  } else {
    // sets coords
    set_next_points[0].x = x;
    set_next_points[0].y = y;
    set_next_points[1].x = (x - (s / 2));
    set_next_points[1].y = (y - (sqrt(3) / 2) * s);
    set_next_points[2].x = (x + (s / 2));
    set_next_points[2].y = (y - (sqrt(3) / 2) * s);
    // makes triangle
    filledTriangle(set_next_points, target, states);
    // recursion
    sierpinski(x, y + ( (sqrt(3) / 2) * (s)), (s / 2),
               count - 1, target, states);
    sierpinski(x - (s / 2), y, (s / 2), count - 1, target, states);
    sierpinski(x + (s / 2), y, (s / 2), count - 1, target, states);
  }
}

void Sierpinski::filledTriangle(sf::Vector2f set_point[3],
                                sf::RenderTarget& target,
                                sf::RenderStates states) const {
  // creates a filled triangle
  sf::ConvexShape triangle;
  triangle.setPointCount(3);
  triangle.setPoint(0, set_point[0]);
  triangle.setPoint(1, set_point[1]);
  triangle.setPoint(2, set_point[2]);
  triangle.setFillColor(sf::Color::White);
  triangle.setPosition(0, size - (2 * set_point[0].y));
  target.draw(triangle, states);
}
