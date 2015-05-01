// Copyright [2015] Justin Nguyen

#include <SFML/System.hpp>
#include <string>
#include <iostream>
#include "ED.hpp"

int main(int argc, char *argv[]) {
  sf::Clock clock;
  sf::Time time;
  std::string string1;
  std::string string2;
  std::string result;
  int edit_distance;
  std::cin >> string1 >> string2;
  ED *test = new ED(string1, string2);
  edit_distance = test->OptDistance();
  time = clock.getElapsedTime();
  std::cout << "Edit distance" << " " <<
            "=" << " " << edit_distance << std::endl;
  result = test->Alignment();
  int size = result.size();
  for (int i = 0; i < size; i += 3) {
    std::cout << result[i] << " " << result[i + 1] <
              < " " << result[i + 2] << std::endl;
  }
  std::cout << "execution time is: " << time.asSeconds() << " seconds \n";

  return 0;
}

