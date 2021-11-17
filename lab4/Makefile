CC = g++
CFLAGS = -std=c++2a -pedantic -Wall -Wextra -Wconversion -O3

EMPLOYEE_EXEC = ./employee
RESISTOR_EXEC = ./resistor
PERSON_EXEC = ./person

all: employee resistor person

employee: ./Employee.hpp ./employeeExample.cpp
	$(CC) $(CFLAGS) ./employeeExample.cpp -o $(EMPLOYEE_EXEC)

person: ./Person.hpp ./personExample.cpp
	$(CC) $(CFLAGS) ./personExample.cpp -o $(PERSON_EXEC)

resistor: ./Resistor.hpp ./resistorExample.cpp
	$(CC) $(CFLAGS) ./resistorExample.cpp -o $(RESISTOR_EXEC)

clean:
	rm -rf $(EMPLOYEE_EXEC) $(RESISTOR_EXEC) $(PERSON_EXEC)


.PHONY: clean all

