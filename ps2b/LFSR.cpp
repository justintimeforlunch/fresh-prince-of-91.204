// Copyright [2015] Justin Nguyen

#include <iostream>
#include <cmath>
#include "LFSR.hpp"

LFSR::LFSR(std::string seed, int t) {
  _data = seed;
  length =  _data.size();
  tap = t;
}

int LFSR::step() {
  int bit;
  int length = _data.size();
  std::string s_bit;
  bit = _data.front() ^ _data[length -  tap - 1];
  s_bit = std::to_string(bit);
  _data.erase(0, 1);
  _data = _data + s_bit;
  return bit;
}

int LFSR::generate(int k) {
  int count = 0;
  for (int i = k - 1; i >= 0; i--) {
    if (step() == 1)
      count +=  pow(2, i);
  }
  return count;
}

std::ostream& operator << (std::ostream& out, LFSR& lfsr) {
  out << lfsr._data;
  return out;
}
