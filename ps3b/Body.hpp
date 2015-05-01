// Copyright [2015] Justin Nguyen

#ifndef N_BODY_HPP_
#define N_BODY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Body : public sf::Drawable {
 private:
  sf::Vector2f _window_size, _pos, _velo, _accel, _Fnet, _normalPos;
  double _univ_size, _univ_radius, _mass;
  sf::String _filename;
  sf::String _planet_name;
  virtual void draw( sf::RenderTarget &target, sf::RenderStates state ) const ;
  
 public:
  Body(int univ_size, double univ_radius, sf::Vector2f window_size);
  void setName(sf::String name) ;
  void setFile(sf::String file);
  void setPosition(sf::Vector2f pos);
  void setVelocity(sf::Vector2f velo);
  void setMass(double mass);
  void setUniverseSize(double univ_size);
  void setUniverseRadius(double univ_radius);
  void setWindowSize(sf::Vector2f window_size);
  void setnormalPos(sf::Vector2f normalPos);
  void setAccel(sf::Vector2f accel);
  void setFnet(sf::Vector2f force);
  double getUniverseSize();
  double getMass();
  double getUniverseRadius();
  sf::Vector2f getVelocity();
  sf::Vector2f getAccel() const;
  sf::Vector2f getWindowSize();
  sf::Texture getTexture() const;
  sf::Sprite getSprite() const;
  sf::String getName();
  sf::String getFile() const;
  sf::Vector2f getPos() const;
  sf::Vector2f getnormalPos() const;
  sf::Vector2f getFnet() const;
  friend std::istream& operator >> (std::istream& in, Body& body);
  void step(double seconds);
  void setNewAccel();
  void setNewVelo(double seconds);
  void setNewPos(double seconds);
  void setUpPos();
  void graphics( sf::RenderTarget &target, sf::RenderStates state ) const;
};

#endif
