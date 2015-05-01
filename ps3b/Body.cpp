// Copyright [2015] Justin Nguyen

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

void Body::setPosition(sf::Vector2f pos) {
  _pos = pos;
}

void Body::setVelocity(sf::Vector2f velo) {
  _velo = velo;
}

void Body::setMass(double mass) {
  _mass = mass;
}

void Body::setAccel(sf::Vector2f accel) {
  _accel = accel;
}

void Body::setUniverseSize(double univ_size) {
  _univ_size = univ_size;
}

void Body::setUniverseRadius(double univ_radius) {
  _univ_radius = univ_radius;
}

void Body::setWindowSize(sf::Vector2f window_size) {
  _window_size = window_size;
}

void Body::setnormalPos(sf::Vector2f normalPos) {
  _normalPos = normalPos;
}

void Body::setFnet(sf::Vector2f force) {
  _Fnet = force;
}

sf::Vector2f Body::getVelocity() {
  return _velo;
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

double Body::getUniverseRadius() {
  return _univ_radius;
}

double Body::getUniverseSize() {
  return _univ_size;
}

sf::Vector2f Body::getWindowSize() {
  return _window_size;
}

sf::Vector2f Body::getPos() const {
  return _pos;
}

sf::Vector2f Body::getAccel() const {
  return _accel;
}

sf::Vector2f Body::getnormalPos() const {
  return _normalPos;
}

sf::Vector2f Body::getFnet() const {
  return _Fnet;
}

std::istream& operator >> (std::istream& in, Body& body) {
  sf::Vector2f pos;
  sf::Vector2f vel;
  sf::Vector2f accel;
  double _mass;
  in >> (pos.x) >> (pos.y) >> (vel.x) >> (vel.y) >> _mass;
  body.setPosition(pos);
  body.setVelocity(vel);
  body.setMass(_mass);
  return in;
}

void Body::setUpPos() {
  sf::Vector2f velo;
  sf::Vector2f pos;
  (pos.x) = (((getWindowSize().x) / 2) +
             ((((getPos()).x) / getUniverseRadius()) *
              ((getWindowSize().x) / 2)));
  (pos.y) = (((getWindowSize().y) / 2) - (
               (((getPos()).y) / getUniverseRadius()) *
               ((getWindowSize().y) / 2)));
  setnormalPos(pos);
}

void Body::draw(sf::RenderTarget &target, sf::RenderStates state) const {
  graphics(target, state);
}

void Body::graphics(sf::RenderTarget &target, sf::RenderStates state) const {
  sf::Sprite sprite;
  sf::Image image;
  sf::Texture texture;
  image.loadFromFile(getFile());
  texture.loadFromImage(image);
  sprite.setTexture(texture);
  sprite.setPosition((getnormalPos()).x, (getnormalPos()).y);
  target.draw(sprite, state);
}

void Body::setNewVelo(double seconds) {
  sf::Vector2f velo;
  velo.x = ((getVelocity()).x + (seconds * (getAccel()).x));
  velo.y = ((getVelocity()).y + (seconds * (getAccel()).y));
  setVelocity(velo);
}

void Body::setNewPos(double seconds) {
  sf::Vector2f pos;
  pos.x = ((getPos()).x + (seconds * (getVelocity()).x));
  pos.y = ((getPos()).y + (seconds * (getVelocity()).y));
  setPosition(pos);
}

void Body::setNewAccel() {
  sf::Vector2f accel;
  accel.x = ((getFnet()).x / (getMass()));
  accel.y = ((getFnet()).y / (getMass()));
  setAccel(accel);
}

void Body::step(double seconds) {
  setNewAccel();
  setNewVelo(seconds);
  setNewPos(seconds);
  setUpPos();
}
