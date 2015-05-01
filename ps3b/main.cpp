#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "Body.hpp"

sf::Vector2f force(Body p1, Body p2)
{
  sf::Vector2f planet_force;
  double totalForce, dx, dy, radius, radius_squared;
  double grav = (-6.67e-11);
  
  dx = (((p1.getPos()).x) - ((p2.getPos()).x));
  dy = (((p1.getPos()).y) - ((p2.getPos()).y));

  radius_squared = pow(dx, 2) + pow(dy, 2);
  radius = sqrt(radius_squared);

  totalForce = ((grav) * (p1.getMass()) * (p2.getMass())) / (radius_squared);

  planet_force.x = totalForce * (dx/radius);
  planet_force.y = totalForce * (dy/radius);

  return planet_force;
}

void removeWhitespace(std::string& str) 
{
  for (size_t i = 0; i < str.length(); i++) 
    {
      if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
	str.erase(i, 1);
	i--;
      }
    }
}

int main(int argc, char* argv[]) 
{
  int planet_count;

  double univ_radius;
  double time, time_step, current;
  
  std::string planet_name;
  std::string planet_filename;
  
  std::vector<Body> planets;

  sf::Vector2f t_force;
  
  sf::Image background;

  sf::Music music;

  sf::Font font;
  sf::Text timestamp;

  if(argc != 3)
    {
      std::cout << "error: not enough/or too much arguments" << std::endl;
      exit(1);
    }

  time = atof(argv[1]);
  time_step = atof(argv[2]);

  if(!music.openFromFile("2001.ogg"))
    return -1;

  music.setLoop(true);
  music.play();

  if(!(font.loadFromFile("DJB Poppyseed.ttf")))
    return -1;

  timestamp.setFont(font);
  timestamp.setScale(0.5f, 0.5f);
  timestamp.setPosition(0.f, 0.f);

  if(!background.loadFromFile("starfield.jpg"))
    return -1;  

  sf::Texture texture;
  texture.loadFromImage(background);
  
  sf::Sprite sprite;
  sprite.setTexture(texture);
  sf::Vector2f size;

  size.x = background.getSize().x;
  size.y = background.getSize().y;
  
  std::cin >> planet_count >> univ_radius ;
  
  for (int i = 0; i < planet_count; i++) 
    {
    Body *planet = new Body (planet_count, univ_radius, size);

    std::cin >> *planet;
    getline(std::cin, planet_filename);
    removeWhitespace(planet_filename);
    planet_name = planet_filename;
    planet->setName(planet_name);
    planet->setFile(planet_filename);
    planets.push_back(*planet);    
    }
  
  sf::RenderWindow window( sf::VideoMode(size.x, size.y), "ps3a");
  
  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed) {
	window.close();
	break;
      }
    }
    window.draw(sprite);

    for(std::vector<Body>::iterator iter = planets.begin(); iter != planets.end(); iter++)
      {
	iter->setUpPos();
	window.draw(*iter);
      }

    if (current < time) 
      {
	for(std::vector<Body>::iterator iter1 = planets.begin(); iter1 != planets.end(); ++iter1) {
	  sf::Vector2f Force_net;
	  for(std::vector<Body>::iterator iter2 = planets.begin(); iter2 != planets.end(); ++iter2) {
	     if (iter1->getName() != iter2->getName())
	       {
		 t_force = force(*iter1, *iter2);
		 Force_net.x = Force_net.x + t_force.x;
		 Force_net.y = Force_net.y + t_force.y;
	       }
	  }
	  iter1->setFnet(Force_net);
	}
	
	for (std::vector<Body>::iterator iter = planets.begin() ; iter != planets.end() ; iter++ ){
	  iter->step(time_step);
	  window.draw(*iter);
	}
	std::cout << current << std::endl;
	timestamp.setString(std::to_string(current));
	current += time_step;
      }
    window.draw(timestamp);
    window.display();
  }
  return 0 ;
}

