#include <iostream>
#include <string_view>
#include <string>
#include <sstream>
#include <array>

#include "./complex.hpp"

void print_usage();
std::string_view get_arg(int& argc, char **& argv);

enum class OP_T
{
    ADD, SUB, MUL, DIV,
    UNKNOWN
};


OP_T sv_to_opt(std::string_view sv)
{
    if (sv == "add")
        return OP_T::ADD;
    if (sv == "sub")
        return OP_T::SUB;
    if (sv == "mul")
        return OP_T::MUL;
    if (sv == "div")
        return OP_T::DIV;
    return OP_T::UNKNOWN;
}

OP_T ch_to_opt(char c)
{
    if (c == '+')
        return OP_T::ADD;
    if (c == '-')
        return OP_T::SUB;
    if (c == '*')
        return OP_T::MUL;
    if (c == '/')
        return OP_T::DIV;
    return OP_T::UNKNOWN;
}

char opt_to_char(OP_T op)
{
    if (op == OP_T::ADD)
        return '+';
    if (op == OP_T::SUB)
        return '-';
    if (op == OP_T::MUL)
        return '*';
    if (op == OP_T::DIV)
        return '/';
    return '?';
}


int main(int argc, char *argv[])
{
    --argc;
    ++argv;

    int result = 0;
    constexpr int required_argc = 1;

    if (argc != required_argc)
    {
        std::cerr << "Invalid number of arguments\n";
        print_usage();
        std::exit(EXIT_FAILURE);
    }

    OP_T opt;
    Complex a;
    Complex b;
    char op;

    std::istringstream iss{ *argv };
    iss >> a >> op >> b;
    opt = ch_to_opt(op);
    if (!iss || opt == OP_T::UNKNOWN)
    {
        std::cerr << "Incorrect expression: " << *argv << '\n';
        print_usage();
        std::exit(EXIT_FAILURE);
    }

    switch (opt)
    {
    case OP_T::ADD:
        std::cout << a << ' ' << opt_to_char(opt) << ' ' << b << " = " << a + b << '\n';
        break;
    case OP_T::SUB:
        std::cout << a << ' ' << opt_to_char(opt) << ' ' << b << " = " << a - b << '\n';
        break;
    case OP_T::MUL:
        std::cout << a << ' ' << opt_to_char(opt) << ' ' << b << " = " << a * b << '\n';
        break;
    case OP_T::DIV:
        std::cout << a << ' ' << opt_to_char(opt) << ' ' << b << " = " << a / b << '\n';
        break;

    default:
        std::cerr << "Invalid operation: " << op << '\n';
        print_usage();
        result = EXIT_FAILURE;
        break;
    }

    return result;
}

void print_usage()
{
    static constexpr std::array usage = {
        "Usage:",
        "./complex \"[Complex1] [OP] [Complex2]\"",
        "   where OP is one of: +, -, *, /",
        "   and complex is in format RE+IMGj",
        "Example:",
        "   $ ./complex \"23+2j * -12+-3j\"",
        "   Complex{23 + 2j} * Complex{-12 + -3j} = Complex{-270 + -93j}"
    };

    for (auto line : usage)
    {
        std::cout << line << '\n';
    }
}
