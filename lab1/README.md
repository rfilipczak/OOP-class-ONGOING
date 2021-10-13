# LAB1

* Prints factorial(N) for N in [0, 20]
* Prints N first prime numbers for N in [1, 10000]
* Creates circular doubly-linked list from list of initial values and allows user to enter interactive mode where they can check out various operations on the list

## Supported platforms

* gcc 10.3.0
* Ubuntu 21.04

(but should compile on most systems and compilers)

## Quick Start

```console
$ make
$ ./prog help
```

## Usage

### Program arguments

```console
help                     -- prints this msg
test                     -- runs tests for factorial and primes
factorial N[0-20]        -- prints factorial(N)
primes N[1-10000]        -- prints N first primes
list [initial values...] -- creates a circular doubly-linked list from initial values and starts interactive mode
```

### Circular doubly-linked list menu (interactive mode)

```console
[h] Print this menu
[q] Exit.
[0] Print this list
[1] Print this list in reversed order
[2] Push back value
[3] Push front value
[4] Pop back
[5] Pop front
[6] Delete value
[7] Delete all nodes with value
[8] Clear this list
[9] Check if this list is empty
```
### Examples

```console
$ ./prog test
Running factorial test... passed.
Running primes test... passed.
$ ./prog factorial 12
479001600
$ ./prog primes 10
2 3 5 7 11 13 17 19 23 29
$ ./prog list 12 -12 123
12 -12 123 
Would you like to start interactive list mode (y/N)? y
        Circular doubly-linked list menu
        [h] Print this menu
        [q] Exit
        [0] Print this list
        [1] Print this list in reversed order
        [2] Push back value
        [3] Push front value
        [4] Pop back
        [5] Pop front
        [6] Delete value
        [7] Delete all nodes with value
        [8] Clear this list
        [9] Check if this list is empty
Enter the option: 1
123 -12 12 
Enter the option: 2
Value to push at the back: 5
Enter the option: 0
12 -12 123 5 
Enter the option: 4
Enter the option: 0
12 -12 123 
Enter the option: 5
Enter the option: 0
-12 123 
Enter the option: 8
Enter the option: 9
List is empty
Enter the option: q
```
