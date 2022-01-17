CC = g++
CFLAGS = -Wpedantic -Wall -Wextra -O2

SRC = ./zadanie_extra.cpp
EXEC = ./zadanie_extra

all: zadanie_extra

zadanie_extra: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

clean:
	rm -rf $(EXEC)

.PHONY: all clean
