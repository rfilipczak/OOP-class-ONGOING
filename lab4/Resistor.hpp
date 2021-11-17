#ifndef RESISTOR_H
#define RESISTOR_H

#include <iostream>

class Resistor
{
private:
    double resistance{0};
public:
    Resistor()
        : resistance{0}
    {
    }

    explicit Resistor(double _resistance)
        : resistance{_resistance}
    {
    }
    
    [[nodiscard]] double r() const { return resistance; }
    void r(double _resistance) { resistance = _resistance; }

    friend Resistor operator+(const Resistor& a, const Resistor& b)
    {
        return Resistor(a.resistance + b.resistance);
    }    

    friend Resistor operator*(const Resistor& a, const Resistor& b)
    {
        return Resistor((a.resistance * b.resistance) / (a.resistance + b.resistance));
    }

    friend std::ostream& operator<<(std::ostream& out, const Resistor& resistor)
    {
        out << "Resistor{r=" << resistor.resistance << '}';
        return out;
    }

};

#endif
