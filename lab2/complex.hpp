#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
private:
    double m_real{1};
    double m_imag{1};

public:
    Complex()
        : m_real{1}, m_imag{1}
    {
    }

    Complex(double real, double imag)
        : m_real{real}, m_imag{imag}
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& c)
    {
        out << "Complex{" << c.m_real << " + " << c.m_imag << "i}";
        return out;
    }

    friend Complex operator+(const Complex& a, const Complex& b)
    {
        return Complex(a.m_real + b.m_real, a.m_imag + b.m_imag);
    }

    friend Complex operator-(const Complex& a, const Complex& b)
    {
        return Complex(a.m_real - b.m_real, a.m_imag - b.m_imag);
    }
    
    friend Complex operator*(const Complex& a, const Complex& b)
    {
        double real = a.m_real * b.m_real + (a.m_imag * b.m_imag * (-1.0));
        double imag = a.m_real * b.m_imag + a.m_imag * b.m_real;
        return Complex(real, imag);
    }

    friend Complex operator/(const Complex& a, const Complex& b)
    {
        double div = (b.m_real * b.m_real + b.m_imag * b.m_imag);
        double real = (a.m_real * b.m_real + a.m_imag * b.m_imag) / div;
        double imag = (a.m_imag * b.m_real - a.m_real * b.m_imag) / div;
        return Complex(real, imag);
    }
};

#endif
