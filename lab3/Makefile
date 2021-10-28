EXECUTABLE = ./prog
SOURCE = ./lab3.cpp
INCLUDE = ./Point.hpp ./ObjCounter.hpp ./Vector.hpp ./S.hpp
CC = g++
CFLAGS = -std=c++17 -pedantic -Wall -Wextra -O3

all: $(SOURCE) $(INCLUDE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE)


.PHONY: clean

