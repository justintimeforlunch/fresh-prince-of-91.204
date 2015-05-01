CC = g++
OFLAGS = -c -Wall -ansi -pedantic -Werror -ansi -g -lboost_unit_test_framework
CFLAGS = -Wall -ansi -pedantic -Werror -ansi -g -lboost_unit_test_framework
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system

all:	RingBuffer

RingBuffer: RingBuffer.o test.o
	$(CC) RingBuffer.o test.o $(CFLAGS) $(LFLAGS)  -o ps5a

test.o: test.cpp
	$(CC) $(OFLAGS) $(LFLAGS) test.cpp

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) $(OFLAGS) RingBuffer.cpp


clean:
	\rm -f *.o  *~ RingBuffer test ps5a
