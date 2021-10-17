#include <iostream>

#include "./complex.hpp"
#include "./list.hpp"
#include "./personal.hpp"


int main()
{
    // double real, imag;

    // std::cout << "Podaj pierwsza liczbe w formacie liczba_rzecz. liczba uroj.: ";
    // std::cin >> real;
    // std::cin >> imag;
    // Complex a{real, imag};

    // std::cout << "Podaj druga liczbe w formacie liczba_rzecz. liczba uroj.: ";
    // std::cin >> real;
    // std::cin >> imag;
    // Complex b{real, imag};

    // std::cout << a << " + " << b << " = " << a + b << '\n';
    // std::cout << a << " - " << b << " = " << a - b << '\n';
    // std::cout << a << " * " << b << " = " << a * b << '\n';
    // std::cout << a << " / " << b << " = " << a / b << '\n';

    // List<int> list{1, 5, 7, -1};
    // std::cout << list << '\n';

    // list.insert_after(1, 13);
    // std::cout << list << '\n';

    // list.insert_after(13, 15);
    // std::cout << list << '\n';

    // list.insert_after(-1, 123);
    // std::cout << list << '\n';

    // list.remove(1);
    // std::cout << list << '\n';

    // list.remove(13);
    // std::cout << list << '\n';

    // list.remove(7);
    // std::cout << list << '\n';

    // list.remove(123);
    // std::cout << list << '\n';

    // std::cout << list.sort() << '\n';

    // list.insert_after(5, -321);
    // list.insert_after(0, 123);
    // list.insert_after(0, -3213213);

    // std::cout << list << '\n';
    // std::cout << list.sort() << '\n';

    // list.push_back(3);
    // list.push_back(3);
    // list.push_back(3);
    // list.push_back(3);

    // std::cout << list << '\n';
    // std::cout << list.sort() << '\n';


    PersonalDataBank bank{};
    bank.add("Rafal", "Filipczak", "Zurawia 8/60 91-463 Lodz", "93042305017");
    std::cout << bank << '\n';
    bank.remove("93042305017");
    std::cout << bank << '\n';
    bank.add("Foo", "Bar", "Nevertheland", "1234567890");
    bank.add("Foo", "Bar", "Nevertheland", "1234567890");
    bank.add("Foo", "Bar", "Nevertheland", "1234567890");
    bank.add("Foo", "Bar", "Nevertheland", "1234567890");
    std::cout << bank << '\n';
    bank.add("asdl", "asd", "asdsadads asdas", "13asdasd123");
    bank.add("sdasd", "Asddasdasasd", "asddas", "asdasd");
    std::cout << bank << '\n';


    return 0;
}
