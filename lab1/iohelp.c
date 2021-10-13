#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "./iohelp.h"

//
// IO HELPER FUNCTIONS
//

static int streq(const char *a, const char *b)
{
    return (strcmp(a, b) == 0);
}

prog_option_t iohelp_str_to_prog_option(const char *str)
{
    assert(str != NULL);

    // TODO: this could potentially be written with just one iteration over str

    if (streq(str, "help"))         return OPT_HELP;
    if (streq(str, "test"))         return OPT_TEST;
    if (streq(str, "factorial"))    return OPT_FACTORIAL;
    if (streq(str, "primes"))       return OPT_PRIMES;
    if (streq(str, "list"))         return OPT_LIST;

    return OPT_UNKNOWN;
}

void iohelp_clear_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n');
}

int iohelp_get_int_range(const char *prompt, int min, int max, const char *error_msg)
{
    assert(min <= max && "Min should be <= max");

    int res = 0;
    int ok = 0;
    int done = 0;
    do {
        printf("%s", prompt);
        // TODO: change "unsafe" scanf to fgets
        ok = scanf("%d", &res);
        if (!ok || res < min || res > max)
        {
            iohelp_clear_stdin();
            printf("%s\n", error_msg);
        }
        else
        {
            done = 1;
        }
    } while (!done);

    iohelp_clear_stdin();

    return res;
}

int iohelp_get_int(const char *prompt, const char *error_msg)
{
    // TODO: kind of a code repetition from get_int_range
    int res = 0;
    int ok = 0;
    int done = 0;
    do {
        printf("%s", prompt);
        // TODO: change "unsafe" scanf to fgets
        ok = scanf("%d", &res);
        if (!ok) 
        {
            iohelp_clear_stdin();
            printf("%s\n", error_msg);
        }
        else
        {
            done = 1;
        }
    } while (!done);

    iohelp_clear_stdin();

    return res;
}

int iohelp_yes_or_no(const char *prompt, const char *error_msg)
{
    char choice;
    int done = 0;
    do {
        printf("%s", prompt);
        choice = (char) getchar();
        choice = (char) tolower(choice);
        if (choice == 'y' || choice == 'n')
        {
            done = 1;
        }
        else
        {
            iohelp_clear_stdin();
            printf("%s\n", error_msg);
        }
    } while (!done);

    iohelp_clear_stdin();

    return (choice == 'y');
}

const char *iohelp_getarg(char ***args)
{
    const char *arg = **args;
    *args += 1;
    return arg;
}
