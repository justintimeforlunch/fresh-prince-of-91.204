// Copyright [2015] Justin Nguyen

#ifndef ED_HPP_
#define ED_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

class ED {
 private:
  std::string string1;
  std::string string2;
  int **opt;
  int N; // length of string1
  int M; // length of string2
  int edit_distance;
  
 public:
  ED(std::string s1, std::string s2);
  ~ED();
  int penalty(char a, char b);
  int min(int a, int b, int c);
  int OptDistance();
  std::string Alignment();
  int getN();
  int getM();
  int **getOpt();
};

#endif
