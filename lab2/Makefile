PROGNAME = ./prog
CC = g++
CFLAGS = -g -std=c++17 -pedantic -Wall -Wextra

COMPLEX_DIR = ./Complex
LIST_DIR = ./List
PERSONAL_DIR = ./Personal

all: ./complex ./list ./personal

clean:
	rm -rf ./complex ./list ./personal

.PHONY: all clean

complex: $(COMPLEX_DIR)/complex.cpp $(COMPLEX_DIR)/complex.hpp
	$(CC) $(CFLAGS) $(COMPLEX_DIR)/complex.cpp -o ./complex

list: $(LIST_DIR)/list.cpp $(LIST_DIR)/list.hpp
	$(CC) $(CFLAGS) $(LIST_DIR)/list.cpp -o ./list

personal: $(PERSONAL_DIR)/personal.cpp $(PERSONAL_DIR)/personal.hpp
	$(CC) $(CFLAGS) $(PERSONAL_DIR)/personal.cpp -o ./personal

