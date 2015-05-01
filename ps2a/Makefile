CC = g++
OFLAGS = -c -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework
CFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework

all: 	ps2a test

ps2a: LFSR.o test.o
	$(CC) test.o LFSR.o $(CFLAGS)  -o ps2a

test: main.o LFSR.o
	$(CC) main.o LFSR.o $(CFLAGS)  -o main

main.o: main.cpp
	$(CC) $(OFLAGS) main.cpp

LFSR.o: LFSR.cpp LFSR.hpp
	$(CC) $(OFLAGS) LFSR.cpp

test.o: test.cpp
	$(CC) $(OFLAGS) test.cpp

clean:
	\rm -f *.o  *~ main LFSR test ps2
