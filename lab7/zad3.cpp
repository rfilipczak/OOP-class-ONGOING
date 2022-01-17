#include <iostream>
#include <cmath>
#include <exception>
#include <string>


class DivByZeroException : public std::exception
{
private:
    std::string error;
public:
    DivByZeroException(const std::string& _error = "dzielenie przez zero")
        : error{_error}
    {
    }
    const char* what() const noexcept override
    {
        return error.c_str();
    }
};

class SqrtDomainException : public std::exception
{
private:
    std::string error;
public:
    SqrtDomainException(const std::string& _error = "pierwiastek z liczby nieujemnej")
        : error{_error}
    {
    }
    const char* what() const noexcept override
    {
        return error.c_str();
    }
};


double oblicz_wzor(double x, double z)
{
    //y=pierwiastek (x^2-z^2)/ pierwiastek (x-z)

    if (((x*x - z*z) < 0) || ((x - z) < 0))
        throw SqrtDomainException();

    double mianownik = std::sqrt(x-z);
    if (mianownik == 0)
        throw DivByZeroException();

    return std::sqrt(x*x - z*z) / mianownik;
}

int main()
{
    double a, b;

    std::cout << "podaj a, b: ";
    std::cin >> a >> std::ws >> b;

    if (!std::cin.good())
    {
        std::cout << "nieprawidlowe dane\n";
        return 0;
    }

    try {
        auto result = oblicz_wzor(a, b);
        std::cout << result << '\n';
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
