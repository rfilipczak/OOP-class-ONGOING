CC = g++
CFLAGS = -std=c++2a -pedantic -Wall -Wextra -Wconversion -O3


all: zad1 zad2 zad3


zad1: zad1.cpp
	$(CC) $(CFLAGS) ./zad1.cpp -o ./zad1

zad2: zad2.cpp
	$(CC) $(CFLAGS) ./zad2.cpp -o ./zad2

zad2: zad3.cpp
	$(CC) $(CFLAGS) ./zad3.cpp -o ./zad3

.PHONY: clean all

