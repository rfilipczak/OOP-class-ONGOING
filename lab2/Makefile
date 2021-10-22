CC = g++
CFLAGS = -std=c++17 -pedantic -Wall -Wextra -O3

COMPLEX_DIR = ./Complex
LIST_DIR = ./List
PERSONAL_DIR = ./Personal

COMPLEX_EXECUTABLE = ./complex
LIST_EXECUTABLE = ./list
PERSONAL_EXECUTABLE = ./personal

all: $(COMPLEX_EXECUTABLE) $(LIST_EXECUTABLE) $(PERSONAL_EXECUTABLE)

clean:
	rm -rf $(COMPLEX_EXECUTABLE) $(LIST_EXECUTABLE) $(PERSONAL_EXECUTABLE)

.PHONY: all clean

complex: $(COMPLEX_DIR)/complex.cpp $(COMPLEX_DIR)/complex.hpp
	$(CC) $(CFLAGS) $(COMPLEX_DIR)/complex.cpp -o $(COMPLEX_EXECUTABLE)

list: $(LIST_DIR)/list.cpp $(LIST_DIR)/list.hpp
	$(CC) $(CFLAGS) $(LIST_DIR)/list.cpp -o $(LIST_EXECUTABLE)

personal: $(PERSONAL_DIR)/personal.cpp $(PERSONAL_DIR)/personal.hpp
	$(CC) $(CFLAGS) $(PERSONAL_DIR)/personal.cpp -o $(PERSONAL_EXECUTABLE)

