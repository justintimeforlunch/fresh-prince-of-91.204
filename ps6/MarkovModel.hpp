// Copyright 2015 Justin Nguyen

#ifndef MM_HPP_
#define MM_HPP_

#include <string>
#include <unordered_map>
#include <vector>

class MarkovModel {
 public:
  MarkovModel(std::string text, int k);
  ~MarkovModel();
  int order();
  int freq(std::string kgram);
  int freq(std::string kgram, char c);
  char randk(std::string kgram);
  std::string gen(std::string kgram, int T);
 private:
  std::vector<std::vector <int> > _fCount;
  unsigned int _order;
  std::unordered_map<std::string, int> _kgrams;
  std::unordered_map<char, int>  _alphabet;
  std::vector<int> _freq;
  std::vector<char> _reverseAlphabet;
};

#endif
