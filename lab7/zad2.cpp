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
        return 1;
    }

    try
    {
        switch (choice)
        {
            case 'r': {
                std::cout << "Podaj a, b, c: ";
                double a, b, c;
                std::cin >> std::ws >> a >> std::ws >> b >> std::ws >> c;
                double delta = b * b - 4 * a * c;
                if (delta < 0)
                {
                    throw "delta ujemna";
                }
                else if (delta == 0)
                {
                    if (a == 0)
                        throw "dzielenie przez zero";
                    double pierwiastek = (-1.0) * b / (2 * a);
                    std::cout << "Pierwiastek: " << pierwiastek;
                }
                else
                {
                    if (a == 0)
                        throw "dzielenie przez zero";
                    double p1 = ( (-1.0) * b - std::sqrt(delta) ) / (2 * a);
                    double p2 = ( (-1.0) * b + std::sqrt(delta) ) / (2 * a);
                    std::cout << "P1: " << p1 << '\n'
                            << "P2: " << p2 << '\n';
                }
            } break;

            case 'z': {
                std::cout << "Podaj a, b, c: ";
                std::complex<double> a, b, c;
                std::cin >> std::ws >> a >> std::ws >> b >> std::ws >> c;
                auto delta = b * b - std::complex<double>(4, 0) * a * c;
                std::cout << delta << '\n';
            } break;
        }
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }
    
    

    return 0;
}