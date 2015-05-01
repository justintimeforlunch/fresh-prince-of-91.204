CC = g++
OFLAGS = -c -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework
CFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system

all: 	ps2b

ps2b: LFSR.o PhotoMagic.o
	$(CC) PhotoMagic.o LFSR.o $(CFLAGS) $(LFLAGS)  -o PhotoMagic


PhotoMagic.o: PhotoMagic.cpp
	$(CC) $(OFLAGS) $(LFLAGS) PhotoMagic.cpp

LFSR.o: LFSR.cpp LFSR.hpp
	$(CC) $(OFLAGS) LFSR.cpp


clean:
	\rm -f *.o  *~ PhotoMagic ps2b
