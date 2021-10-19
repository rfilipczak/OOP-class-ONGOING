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
        out << "Complex{" << c.m_real << " + " << c.m_imag << "j}";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Complex& c)
    {
        double real, imag;
        char ch;
        std::string end;
        in >> real;
        in >> ch;
        if (ch == '+')
        {
            in >> imag;
            in >> end;
            if (end == "j")
            {
                c.m_real = real;
                c.m_imag = imag;
            }
            else
            {
                in.setstate(std::ios_base::failbit);
            }
        }
        else
        {
            in.setstate(std::ios_base::failbit);
        }
        return in;
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
