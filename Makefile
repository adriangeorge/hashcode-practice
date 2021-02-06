# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o Pizza.o Package.o
	$(CC) $(CFLAGS) -o pizza main.o Pizza.o Package.o
 
# The main.o target can be written more simply
 
main.o: ./src/main.cpp 
	$(CC) $(CFLAGS) -c ./src/main.cpp
 
Pizza.o: ./src/Pizza.cpp
	$(CC) $(CFLAGS) -c ./src/Pizza.cpp

Package.o: ./src/Package.cpp
	$(CC) $(CFLAGS) -c ./src/Package.cpp

clean:
	rm *.o
	rm pizza