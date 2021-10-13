#ifndef IOHELP_H
#define IOHELP_H

//
// IO HELPER FUNCTIONS
//

typedef enum prog_option_t {
    OPT_HELP = 0,
    OPT_TEST,
    OPT_FACTORIAL,
    OPT_PRIMES,
    OPT_LIST,
    OPT_UNKNOWN
} prog_option_t;

// Match program argument with enumerated type
prog_option_t iohelp_str_to_prog_option(const char *str);

// clears stdin, i.e reads and discards characters in stdin until '\n' (inclusive).
void iohelp_clear_stdin(void);

// Gets int in range [min, max] (inclusive) from user with prompt until correct input.
// Prints prompt msg on each try and error_msg whenever the user typed incorrect input.
int iohelp_get_int_range(const char *prompt, int min, int max, const char *error_msg);

// Gets int from user with prompt until correct input (y/N).
// Prints prompt msg on each try and error_msg whenever the user typed incorrect input.
int iohelp_get_int(const char *prompt, const char *error_msg);

// Asks user with prompt until correct input (y/N).
// Returns 1 if user agreed with y/Y, 0 if user typed n/N.
// Prints error_msg on incorrect input.
int iohelp_yes_or_no(const char *prompt, const char *error_msg);

// Returns argument from args and increments the pointer
const char *iohelp_getarg(char ***args);

#endif // IOHELP_H