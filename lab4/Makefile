EXECUTABLE = ./prog
SOURCE = ./lab4.cpp
INCLUDE = ./Resistor.hpp
CC = g++
CFLAGS = -std=c++17 -pedantic -Wall -Wextra -O3

all: $(SOURCE) $(INCLUDE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE)

.PHONY: clean all
