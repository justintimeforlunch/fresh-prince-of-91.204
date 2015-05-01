// Copyright [2015] Justin Nguyen  [legal/copyright]

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Body.hpp"

Body::Body(int univ_size, double univ_radius, sf::Vector2f window_size) {
  setUniverseSize(univ_size);
  setUniverseRadius(univ_radius);
  setWindowSize(window_size);
}

void Body::setName(sf::String name) {
  _planet_name = name;
}

void Body::setFile(sf::String file) {
  _filename = file;
}

void Body::setPosition(double xpos, double ypos) {
  _xpos = xpos;
  _ypos = ypos;
}

void Body::setVelocity(double xvel, double yvel) {
  _xvel = xvel;
  _yvel = yvel;
}

void Body::setMass(double mass) {
  _mass = mass;
}

void Body::setUniverseSize(int univ_size) {
  _univ_size = univ_size;
}

void Body::setUniverseRadius(double univ_radius) {
  _univ_radius = univ_radius;
}

void Body::setWindowSize(sf::Vector2f window_size) {
  _window_size = window_size;
}

double Body::get_x() const {
  return _xpos;
}

double Body::get_y() const {
  return _ypos;
}

sf::Vector2f Body::getVelocity() {
  sf::Vector2f ret_velo(_xvel, _yvel);
  return ret_velo;
}

double Body::getMass() {
  return _mass;
}

sf::String Body::getName() {
  return _planet_name;
}

sf::String Body::getFile() const {
  return _filename;
}

double Body::getUnivRadius() {
  return _univ_radius;
}

int Body::getUnivSize() {
  return _univ_size;
}

sf::Vector2f Body::getWindowSize() {
  return _window_size;
}

std::istream& operator >> (std::istream& in, Body& body) {
  double x_pos, y_pos, x_vel, y_vel, i_mass;

  in >> x_pos >> y_pos >> x_vel >> y_vel >> i_mass;
  
  x_pos = (((body._window_size.x) / 2) +
            ((x_pos / body.getUnivRadius()) * ((body._window_size.x) / 2)));
  y_pos = (((body._window_size.y) / 2) +
            ((y_pos / body.getUnivRadius()) * ((body._window_size.y) / 2)));
  
  body.setPosition(x_pos, y_pos);
  body.setVelocity(x_vel, y_vel);
  body.setMass(i_mass);
  
  return in;
}

void Body::draw(sf::RenderTarget &target, sf::RenderStates state) const {
  initGraphic(target, state);
}

void Body::initGraphic(sf::RenderTarget &target, sf::RenderStates state) const {
  sf::Sprite sprite;
  sf::Image image;
  sf::Texture texture;
  
  image.loadFromFile(getFile());
  texture.loadFromImage(image);
  sprite.setTexture(texture);
  sprite.setPosition(get_x(), get_y());
  target.draw(sprite, state);
}
