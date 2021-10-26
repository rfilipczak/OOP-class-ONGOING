#include <iostream>

#include "./vector.hpp"
#include "./Sclass.hpp"

int main()
{
    std::cout << "Hello lab3\n\n";
    
    {
        Vector vec1{{0,0}, {1,1}};
        Vector vec2({-21,32}, {31,33});

        std::cout << vec1 << " + " << vec2 << " = " << vec1 + vec2 << '\n';
        std::cout << vec1 << " - " << vec2 << " = " << vec1 - vec2 << '\n';
        std::cout << vec1 << " dot product " << vec2 << " = " << vec1.dotProduct(vec2) << '\n';

        std::cout << "\nIlosc istniejacych obiektow typu Vector: " << Vector::getObjCount() << "\n\n";
    }
    std::cout << "\nIlosc istniejacych obiektow typu Vector: " << Vector::getObjCount() << '\n';
    std::cout << "Ilosc utworzonych obiektow typu Vector: " << Vector::getTotalConstructed() << '\n';
    std::cout << "Ilosc usunietych obiektow typu Vector: " << Vector::getTotalDestructed() << "\n\n";

    S s1;
    std::cout << "Obiekt z domyslnego konstruktora: " << s1 << "\n\n";
    
    S s2{132, 'z'};
    std::cout << "Obiekt z konstruktora (int, char): " << s2 << "\n\n";

    S s3{12, 'a', -213.9f, "ala ma kota"};
    std::cout << "Obiekt z listy inicjalizacyjnej: " << s3 << "\n\n";

    S s4{s3};
    std::cout << "Obiekt z konstruktora kopiujacego: " << s4 << "\n\n";

    return 0;
}
