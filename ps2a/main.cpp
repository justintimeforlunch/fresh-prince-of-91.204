// Copyright [2015] Justin Nguyen

#include <iostream>
#include <string>
#include "LFSR.hpp"

int main(int argc, char* argv[]) {
	std::string s_bit;
	LFSR *lfsr = new LFSR("01101000010", 8);
	for (int i = 0; i < 10; i++) {
		int bit = lfsr->generate(5);
		s_bit = std::to_string(bit);
		std:: cout << *lfsr << " " <<  s_bit << std::endl;
	}
	return 0;
}
