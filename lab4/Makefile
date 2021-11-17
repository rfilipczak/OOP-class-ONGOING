CC = g++
CFLAGS = -std=c++2a -pedantic -Wall -Wextra -Wconversion -O3

EMPLOYEE_EXEC = ./employee
RESISTOR_EXEC = ./resistor

all: employee resistor

employee: ./Employee.hpp ./employeeExample.cpp
	$(CC) $(CFLAGS) ./employeeExample.cpp -o $(EMPLOYEE_EXEC)

resistor: ./Resistor.hpp ./resistorExample.cpp
	$(CC) $(CFLAGS) ./resistorExample.cpp -o $(RESISTOR_EXEC)

clean:
	rm -rf $(EMPLOYEE_EXEC) $(RESISTOR_EXEC)


.PHONY: clean all

