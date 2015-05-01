// Copyright [2015] Justin Nguyen

#ifndef LFSR_HPP_
#define LFSR_HPP_

#include <iostream>
#include <string>

class LFSR {
 private:
	int length;
	int tap;
	std::string _data;
	
 public:
	LFSR(std::string seed, int t);
	int step(); // ensures either 0 or 1. 
				// steps the register once.
	int generate(int k); // steps the register k times
	friend std::ostream& operator << (std::ostream& out, LFSR& lfsr);
};

#endif
