CC = g++
OFLAGS = -c -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework
CFLAGS = -Wall -ansi -pedantic -Werror -std=c++0x -lboost_unit_test_framework
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system

all: 	NBody

NBody: Body.o main.o
	$(CC) Body.o main.o $(CFLAGS) $(LFLAGS)  -o NBody


main.o: main.cpp
	$(CC) $(OFLAGS) $(LFLAGS) main.cpp

Body.o: Body.cpp Body.hpp
	$(CC) $(OFLAGS) Body.cpp


clean:
	\rm -f *.o  *~ NBody main Body
