CC = g++
CFLAGS = -Wpedantic -Wall -Wextra -O2

SRC = ./zadanie2.cpp
EXEC = ./zad2

all: zad2

zad2: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -rf $(EXEC)

.PHONY: all clean
