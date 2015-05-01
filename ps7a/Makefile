CC = g++
OFLAGS = -g -Wall -ansi -pedantic -Werror -ansi -std=c++0x
CFLAGS = -Wall -ansi -pedantic -Werror -ansi -std=c++0x -lboost_unit_test_framework 
LFLAGS = -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window 
BFLAGS = -lboost_regex -lboost_date_time -lboost_unit_test_framework

all: ps7a

ps7a: Kronos.o
	$(CC) Kronos.o $(CFLAGS) $(BFLAGS) -o ps7a

Kronos.o: Kronos.cpp
	$(CC) -c Kronos.cpp $(OFLAGS) -o Kronos.o

clean:
	\rm -f *.o  *~ ps7a *.rpt
