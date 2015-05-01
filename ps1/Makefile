CC = g++
OFLAGS = -c -Wall -ansi -pedantic -Werror
CFLAGS = -Wall -ansi -pedantic -Werror
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system

all: ps1 ps1_original

ps1: main.o sierpinski.o
	$(CC) main.o sierpinski.o $(CFLAGS) $(LFLAGS) -o sierpinski

ps1_original: original.o original_i.o 
	$(CC) original.o original_i.o $(CFLAGS) $(LFLAGS) -o original

main.o: main.cpp
	$(CC) $(OFLAGS) $(LFLAGS) main.cpp

original.o: original.cpp
	$(CC) $(OFLAGS) $(LFLAGS) original.cpp

sierpinski.o: sierpinski.cpp
	$(CC) $(OFLAGS) $(LFLAGS) sierpinski.cpp

original_i.o: original_i.cpp
	$(CC) $(OFLAGS) $(LFLAGS) original_i.cpp

clean:
	\rm -f *.o  *~ sierpinski original
