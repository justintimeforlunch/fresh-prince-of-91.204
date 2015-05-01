// Copyright [2015] Justin Nguyen

#ifndef N_BODY_HPP_
#define N_BODY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Body : public sf::Drawable {
 private:
  sf::Vector2f _window_size;
  int _univ_size;
  double _xpos, _ypos, _xvel, _yvel, _mass, _univ_radius;
  sf::String _filename;
  sf::String _planet_name;
  virtual void draw( sf::RenderTarget &target, sf::RenderStates state ) const;
  
 public:
  Body(int univ_size, double univ_radius, sf::Vector2f window_size);
  void setName(sf::String name) ;
  void setFile(sf::String file);
  void setPosition(double xpos, double ypos);
  void setVelocity(double xvel, double yvel);
  void setMass(double mass);
  void setUniverseSize(int univ_size);
  void setUniverseRadius(double univ_radius);
  void setWindowSize(sf::Vector2f window_size);
  int getUnivSize();
  double get_x() const;
  double get_y() const;
  double getMass();
  double getUnivRadius();
  sf::Vector2f getVelocity();
  sf::Vector2f getWindowSize();
  sf::Texture getTexture() const;
  sf::Sprite getSprite() const;
  sf::String getName();
  sf::String getFile() const;
  friend std::istream& operator >> (std::istream& in, Body& body);
  void initGraphic( sf::RenderTarget &target, sf::RenderStates state) const;
};

#endif
