CC = g++
CFLAGS = -Wpedantic -Wall -Wextra -O2

SRC = ./zadanie1.cpp
EXEC = ./zad1

all: zad1

zad1: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -rf $(EXEC)

.PHONY: all clean
