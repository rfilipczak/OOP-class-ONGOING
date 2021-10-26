EXECUTABLE = ./prog
SOURCE = ./lab3.cpp
INCLUDE = ./point.hpp ./objCounter.hpp ./vector.hpp ./Sclass.hpp
CC = g++
CFLAGS = -std=c++17 -pedantic -Wall -Wextra -O3

all: $(SOURCE) $(INCLUDE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE)


.PHONY: clean

