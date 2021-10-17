#include <iostream>

#include "./complex.hpp"
#include "./list.hpp"


int main()
{
    double real, imag;

    std::cout << "Podaj pierwsza liczbe w formacie liczba_rzecz. liczba uroj.: ";
    std::cin >> real;
    std::cin >> imag;
    Complex a{real, imag};

    std::cout << "Podaj druga liczbe w formacie liczba_rzecz. liczba uroj.: ";
    std::cin >> real;
    std::cin >> imag;
    Complex b{real, imag};

    std::cout << a << " + " << b << " = " << a + b << '\n';
    std::cout << a << " - " << b << " = " << a - b << '\n';
    std::cout << a << " * " << b << " = " << a * b << '\n';
    std::cout << a << " / " << b << " = " << a / b << '\n';

    List<int> list{1, 5, 7, -1};
    std::cout << list << '\n';

    list.insert_after(1, 13);
    std::cout << list << '\n';

    list.insert_after(13, 15);
    std::cout << list << '\n';

    list.insert_after(-1, 123);
    std::cout << list << '\n';

    list.remove(1);
    std::cout << list << '\n';

    list.remove(13);
    std::cout << list << '\n';

    list.remove(7);
    std::cout << list << '\n';

    list.remove(123);
    std::cout << list << '\n';

    std::cout << list.sort() << '\n';

    return 0;
}
