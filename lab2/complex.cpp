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
    constexpr int required_argc = 3;

    if (argc != required_argc)
    {
        std::cerr << "Invalid number of arguments\n";
        print_usage();
        std::exit(EXIT_FAILURE);
    }


    std::string_view op{ *argv++ };
    std::string_view c1{ *argv++ };
    std::string_view c2{ *argv++ };

    OP_T opt = sv_to_opt(op);
    Complex a;
    Complex b;

    std::istringstream iss{ std::string{ c1 } };
    iss >> a;
    if (!iss.good())
    {
        std::cerr << "Invalid complex format: " << c1 << '\n';
        print_usage();
        std::exit(EXIT_FAILURE);
    }
    
    iss = std::istringstream(std::string{c2});
    iss >> b;
    if (!iss.good())
    {
        std::cerr << "Invalid complex format: " << c2 << '\n';
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
        "./complex [OP] [Complex1] [Complex2],",
        "   where OP is one of: add, sub, mul, div",
        "   and complex is in format RE+IMGj",
        "Example:",
        "   $ ./complex mul 23+2j -12+-3j",
        "   Complex{23 + 2i} * Complex{-12 + -3i} = Complex{-270 + -93i}"
    };

    for (auto line : usage)
    {
        std::cout << line << '\n';
    }
}
