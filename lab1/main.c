/*
 * @author Rafal Filipczak <236392@edu.p.lodz.pl>
 *
 * PO1 Lab1
 * 
 * factorial
 * primes
 * circular doubly linked list
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <limits.h>


#include "./iohelp.h"
#include "./array.h"
#include "./circular_list.h"


// Max n! that fits in 64 bits
#define MAX_FACTORIAL (20)
#define MIN_FACTORIAL (0)

// Number of primes that can be printed reasonably fast using brute force approach
#define MAX_PRIMES_TO_PRINT (10000)
#define MIN_PRIMES_TO_PRINT (1)


void print_usage(const char *prog_name)
{
    printf( "Usage: \n"
            "\t%s help                     -- prints this msg\n"
            "\t%s test                     -- runs tests for factorial and primes\n"
            "\t%s factorial N[0-20]        -- prints factorial(N)\n"
            "\t%s primes N[1-10000]        -- prints N first primes\n"
            "\t%s list [initial values...] -- creates a circular doubly-linked list from initial values and starts interactive mode\n",
            prog_name, prog_name, prog_name, prog_name, prog_name
    );
}


//
// FACTORIAL
//

// Returns factorial(n) where 0 <= n <= 20.
long factorial(int n);


//
// PRIMES
//

// Brute force check for prime.
// Returns 1 for primes and 0 for non-primes or negative n.
int is_prime(int n);

// Prints n first primes using brute force check is_prime.
// Printing more than 10000 primes might be slow.
void print_n_first_primes(int n);


//
// CIRCULAR DOUBLY-LINKED LIST
//

// Prints menu for interactive list playground.
void print_menu(void);

// Runs interactive playground for circular doubly linked list
void list_interactive(CircularList *list);


//
// TESTS
//

// Test factorial for n in [0, 20]
void test_factorial(void);

// Test is_prime for first 1000 numbers
void test_is_prime(void);


int main(int argc, char *argv[])
{
    const char *prog_name = iohelp_getarg(&argv);

    if (argc < 2)
    {
        fprintf(stderr, "Invalid options\n");
        print_usage(prog_name);
        exit(EXIT_FAILURE);
    }
    
    const char *option_str = iohelp_getarg(&argv);
    prog_option_t option_type = iohelp_str_to_prog_option(option_str);

    // options other than test and help require additional arguments
    if (option_type != OPT_UNKNOWN && option_type > OPT_TEST && argc < 3)
    {
        fprintf(stderr, "Too few arguments\n");
        print_usage(prog_name);
        exit(EXIT_FAILURE);    
    }

    errno = 0;
    switch (option_type)
    {
        case OPT_HELP: {
            print_usage(prog_name);
        } break;

        case OPT_TEST: {
            test_factorial();
            test_is_prime();
        } break;

        case OPT_FACTORIAL: {
            char *endptr;
            const char *arg = iohelp_getarg(&argv);
            long value = strtol(arg, &endptr, 10);

            if (errno != 0) {
                perror("strtol");
                print_usage(prog_name);
                exit(EXIT_FAILURE);
            }

            if (endptr == arg) {
                fprintf(stderr, "Factorial argument should be a number between 0 and 20\n");
                print_usage(prog_name);
                exit(EXIT_FAILURE);
            }

            if (value < MIN_FACTORIAL || value > MAX_FACTORIAL)
            {
                fprintf(stderr, "Factorial argument should be a number between 0 and 20\n");
                print_usage(prog_name);
                exit(EXIT_FAILURE);
            }

            printf("%ld\n", factorial((int) value));
        } break;

        case OPT_PRIMES: {
            char *endptr;
            const char *arg = iohelp_getarg(&argv);
            long value = strtol(arg, &endptr, 10);

            if (errno != 0) {
                perror("strtol");
                print_usage(prog_name);
                exit(EXIT_FAILURE);
            }

            if (endptr == arg) {
                fprintf(stderr, "Primes argument should be a number between 1 and 10000\n");
                print_usage(prog_name);
                exit(EXIT_FAILURE);
            }

            if (value < MIN_PRIMES_TO_PRINT || value > MAX_PRIMES_TO_PRINT)
            {
                fprintf(stderr, "Primes argument should be a number between 1 and 10000\n");
                print_usage(prog_name);
                exit(EXIT_FAILURE);
            }

            print_n_first_primes((int) value);
        } break;

        case OPT_LIST: {
            int size = argc - 2;
            Array *values = array_create(size);

            const char *arg;
            char *endptr;
            long val;
            
            for (int i = 0; i < size; ++i)
            {
                arg = iohelp_getarg(&argv);
                val = strtol(arg, &endptr, 10);

                if (errno != 0) {
                    perror("strtol");
                    print_usage(prog_name);
                    array_destroy(values);
                    exit(EXIT_FAILURE);
                }

                if (endptr == arg) {
                    fprintf(stderr, "List argument should be a number between -2147483648 and +2147483647\n");
                    print_usage(prog_name);
                    array_destroy(values);
                    exit(EXIT_FAILURE);
                }

                if (val < INT_MIN || val > INT_MAX)
                {
                    fprintf(stderr, "List argument should be a number between -2147483648 and +2147483647\n");
                    print_usage(prog_name);
                    array_destroy(values);
                    exit(EXIT_FAILURE);
                }

                array_push_back(values, (int) val);
            }

            CircularList *list = list_create(values);
            list_print(list);

            if (iohelp_yes_or_no("Would you like to start interactive list mode (y/N)? ", "Bad input. Try again."))
            {
                list_interactive(list);
            }

            list_destroy(list);
            array_destroy(values);
        } break;

        case OPT_UNKNOWN:
            fprintf(stderr, "Invalid options\n");
            print_usage(prog_name);
            exit(EXIT_FAILURE);

        default:
            assert(0 && "unreachable");
    }

    return 0;
}


//
// FACTORIAL
//

long factorial(int n)
{
    assert(n >= 0 && n <= MAX_FACTORIAL && "n should be >= 0 and <= 20");
    long res = 1;
    for (long i = 2; i <= n; ++i)
        res *= i;
    return res;
}


//
// PRIMES
//

int is_prime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    for (int i = 2; i < n; ++i)
        if (n % i == 0)
            return 0;
    return 1;
}

void print_n_first_primes(int n)
{
    assert(n > 0 && "n should be > 0");
    int count = 0;
    int i = 0;
    while (count != n) {
        if (is_prime(i))
        {
            printf("%d ", i);
            ++count;
        }
        ++i;
    }
    printf("\n");
}


//
// CIRCULAR DOUBLY LINKED LIST 
//

void print_menu(void)
{
    static const char *menu[] = {
        "Circular doubly-linked list menu",
        "[h] Print this menu",
        "[q] Exit",
        "[0] Print this list",
        "[1] Print this list in reversed order",
        "[2] Push back value",
        "[3] Push front value",
        "[4] Pop back",
        "[5] Pop front",
        "[6] Delete value",
        "[7] Delete all nodes with value",
        "[8] Clear this list",
        "[9] Check if this list is empty",
        NULL
    };

    for (int i = 0; menu[i]; ++i)
        printf("\t%s\n", menu[i]);
}

void list_interactive(CircularList *list)
{
    // TODO: needs a massive refactor for better user experience

    assert(list != NULL);

    int quit = 0;
    char choice;
    int value;

    print_menu();
    do {
        printf("Enter the option: ");
        choice = (char) getchar();
        if (choice != '\n')
            iohelp_clear_stdin();
        switch (choice)
        {
        case 'h':
            print_menu();
            break;
        case 'q':
            quit = 1;
            break;
        case '0':
            list_print(list);
            break;
        case '1':
            list_print_reversed(list);
            break;
        case '2':
            value = iohelp_get_int("Value to push at the back: ", "Wrong input. Try again.");
            list_push_back(list, value);
            break;
        case '3':
            value = iohelp_get_int("Value to push at front: ", "Wrong input. Try again.");
            list_push_front(list, value);
            break;
        case '4':
            list_pop_back(list);
            break;
        case '5':
            list_pop_front(list);
            break;
        case '6':
            value = iohelp_get_int("Value to delete from the list: ", "Wrong input. Try again.");
            list_delete(list, value);
            break;
        case '7':
            value = iohelp_get_int("Value to delete all from the list: ", "Wrong input. Try again.");
            list_delete_all(list, value);
            break;
        case '8':
            list_clear(list);
            break;
        case '9':
            printf("%s\n", (list_is_empty(list) ? "List is empty" : "List is not empty"));
            break;
        default:
            printf("Incorrect input. Try again\n");
            break;
        }
    } while (!quit);

}

//
// TESTS
//

void test_factorial(void)
{
    const int input[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
    };
    const int count = sizeof(input) / sizeof(int);
    const long expected[] = {
        1,
        1,
        2,
        6,
        24,
        120,
        720,
        5040,
        40320,
        362880,
        3628800,
        39916800,
        479001600,
        6227020800,
        87178291200,
        1307674368000,
        20922789888000,
        355687428096000,
        6402373705728000,
        121645100408832000,
        2432902008176640000
    };
    printf("Running factorial test... ");
    for (int i = 0; i < count; ++i)
    {
        if (factorial(input[i]) != expected[i])
        {
            fprintf(stderr, "Factorial test failed. For i = %d: got %ld, expected %ld\n", i, factorial(input[i]), expected[i]);
            abort();
        }
    }
    printf("passed.\n");
}

void test_is_prime(void)
{
    // "boolean" table for is_prime
    const int primes[] = {
        0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
        0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
        0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0
    };
    const int count = sizeof(primes) / sizeof(int);
    printf("Running primes test... ");
    for (int i = 0; i < count; ++i)
    {
        if (is_prime(i) != primes[i])
        {
            fprintf(stderr, "is_prime test failed. For i = %d: got %d, expected %d\n", i, is_prime(i), primes[i]);
            abort();
        }
    }
    printf("passed.\n");
}
