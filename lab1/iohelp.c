#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "./iohelp.h"

//
// IO HELPER FUNCTIONS
//

prog_option_t iohelp_str_to_prog_option(const char *str)
{
    assert(str != NULL);

    static const char *const prog_options[] = {
        "help",
        "test",
        "factorial",
        "primes",
        "list",
        NULL
    };

    static const int prog_options_len[] = {
        4, /* help */
        4, /* test */
        9, /* factorial */
        6, /* primes */
        4  /* list */
    };

    int numberOfMatchedChars[] = {
        0, /* help */
        0, /* test */
        0, /* factorial */
        0, /* primes */
        0  /* list */
    };


    for (int i = 0; str[i] != '\0'; ++i)
    {
        for (int j = 0; j < 5; ++j)
            if (str[i] == prog_options[j][i])
                numberOfMatchedChars[j] += 1;
    }

    for (int i = 0; i < 5; ++i)
        if (numberOfMatchedChars[i] == prog_options_len[i])
            return (prog_option_t) i;

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
