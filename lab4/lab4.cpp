#include <iostream>

#include "./Resistor.hpp"


int main()
{
    Resistor r1{312.32};
    Resistor r2{2023.213};

    std::cout << "r1 = " << r1 << '\n';
    std::cout << "r2 = " << r1 << '\n';
    std::cout << '\n';

    std::cout << "Methods:\n";
    std::cout << "r1.r() = " << r1.r() << '\n';
    const double newResistance = 500;
    std::cout << "r1.r(" << newResistance << ")\n";
    r1.r(newResistance);
    std::cout << "r1 = " << r1 << '\n';
    std::cout << '\n';

    std::cout << "Operators:\n";
    std::cout << "r1 + r2 = " << r1 + r2 << '\n';
    std::cout << "r1 * r2 = " << r1 * r2 << '\n';

    return 0;
}
