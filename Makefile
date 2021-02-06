# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o Pizza.o
	$(CC) $(CFLAGS) -o main main.o Pizza.o
 
# The main.o target can be written more simply
 
main.o: ./src/main.cpp 
	$(CC) $(CFLAGS) -c ./src/main.cpp
 
Pizza.o: ./src/Pizza.cpp
	$(CC) $(CFLAGS) -c ./src/Pizza.cpp

clean:
	rm *.o
	rm main