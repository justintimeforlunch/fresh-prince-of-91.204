CC = g++
OFLAGS = -c -Wall -ansi -pedantic -Werror -std=c++0x -g
CFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x -g
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system

all:	ED

ED: ED.o main.o
	$(CC) ED.o main.o $(CFLAGS) $(LFLAGS)  -o ED


main.o: main.cpp
	$(CC) $(OFLAGS) $(LFLAGS) main.cpp

ED.o: ED.cpp ED.hpp
	$(CC) $(OFLAGS) ED.cpp


clean:
	\rm -f *.o  *~ ED main
