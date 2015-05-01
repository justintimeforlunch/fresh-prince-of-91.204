// Copyright [2015] Justin Nguyen

#include <iostream>
#include <string>
#include "MarkovModel.hpp"

int main(int argc, char* argv[]) {
  int order = atoi(argv[1]);
  int time = atoi(argv[2]);

  std::string text;
  std::string result;
  std::getline(std::cin, text);

  MarkovModel mm(text, order);

  result = mm.gen(text.substr(0, order), time-order);

  std::cout << result << std::endl;

  return 0;
}
