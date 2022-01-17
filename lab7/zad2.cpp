#include <iostream>
#include <cmath>
#include <complex>

int main()
{
    std::cout << "Rzeczywiste czy zespolone [r/z]: ";
    char choice;
    std::cin >> choice;

    if (choice != 'r' && choice != 'z')
    {
        std::cerr << "Nieprawidlowa opcja\n";
        return 0;
    }

    try
    {
        std::cout << "Podaj a, b, c: ";
        double a, b, c;
        std::cin >> std::ws >> a >> std::ws >> b >> std::ws >> c;

        if (!std::cin.good())
        {
            throw "nieprawidlowe dane";
        }

        if (a == 0)
            throw "dzielenie przez zero";

        double delta = b * b - 4 * a * c;

        switch (choice)
        {
            case 'r': {
                
                if (delta < 0)
                {
                    throw "delta ujemna";
                }
                else if (delta == 0)
                {
                    double pierwiastek = (-1.0) * b / (2 * a);
                    std::cout << "Pierwiastek: " << pierwiastek;
                }
                else
                {
                    double p1 = ( (-1.0) * b - std::sqrt(delta) ) / (2 * a);
                    double p2 = ( (-1.0) * b + std::sqrt(delta) ) / (2 * a);
                    std::cout << "P1: " << p1 << '\n'
                            << "P2: " << p2 << '\n';
                }
            } break;

            case 'z': {
                if (delta < 0)
                {
                    std::complex p1 { (-1.0) * b / (2 * a), (-1.0) * std::sqrt((-1.0) * delta) / (2 * a) };
                    std::complex p2 { (-1.0) * b / (2 * a), (+1.0) * std::sqrt((-1.0) * delta) / (2 * a) };

                    std::cout << "P1: " << p1 << '\n'
                            << "P2: " << p2 << '\n';
                }
                else if (delta == 0)
                {
                    std::complex pierwiastek {(-1.0) * b / (2 * a), 0.0};
                    std::cout << "Pierwiastek: " <<  pierwiastek;
                }
                else
                {
                    std::complex p1 {( (-1.0) * b - std::sqrt(delta) ) / (2 * a), 0.0};
                    std::complex p2 {( (-1.0) * b + std::sqrt(delta) ) / (2 * a), 0.0};
                    std::cout << "P1: " << p1 << '\n'
                            << "P2: " << p2 << '\n';
                }
                
            } break;
        }
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }
    
    return 0;
}