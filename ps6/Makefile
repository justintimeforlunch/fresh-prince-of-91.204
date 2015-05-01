CC = g++
OFLAGS = -c -Wall -ansi -pedantic -Werror -ansi -std=c++11 -lboost_unit_test_framework
CFLAGS = -Wall -ansi -pedantic -Werror -ansi -std=c++11 -lboost_unit_test_framework 
LFLAGS = -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window 

all: TextGenerator

TextGenerator: MarkovModel.o TextGenerator.o
	$(CC) MarkovModel.o TextGenerator.o $(CFLAGS) -o TextGenerator

#mmtest.o: mmtest.cpp
#	$(CC) $(OFLAGS) $(LFLAGS) mmtest.cpp

MarkovModel.o: MarkovModel.cpp MarkovModel.hpp
	$(CC) $(OFLAGS) $(LFLAGS) MarkovModel.cpp

TextGenerator.o: TextGenerator.cpp
	$(CC) $(OFLAGS) $(LFLAGS) TextGenerator.cpp

clean:
	\rm -f *.o  *~ MarkovModel ps6 TextGenerator
