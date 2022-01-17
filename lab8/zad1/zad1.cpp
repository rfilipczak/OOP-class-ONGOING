#include <iostream>


class Kondensator
{
private:
    double m_pojemnosc;
public:
    Kondensator()
        : m_pojemnosc{1}
    {
    }

    Kondensator(double _pojemnosc) 
        : m_pojemnosc{_pojemnosc}
    {
    }
    
    double pojemnosc() const
    {
        return m_pojemnosc;
    }

    void pojemnosc(double _pojemnosc)
    {
        m_pojemnosc = _pojemnosc;
    }

    friend Kondensator operator+(const Kondensator& a, const Kondensator& b)
    {
        return Kondensator( (a.m_pojemnosc * b.m_pojemnosc) / (a.m_pojemnosc + b.m_pojemnosc) );
    }

    friend Kondensator operator*(const Kondensator& a, const Kondensator& b)
    {
        return Kondensator( a.m_pojemnosc + b.m_pojemnosc );
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Kondensator& c)
    {
        out << "Kondensator{pojemnosc=" << c.m_pojemnosc << '}';
        return out;
    }
};

int main()
{
    std::cout << "Lab8\n";
    Kondensator a{1};
    Kondensator b{3};
    std::cout << a << '+' << b << '=' << a + b << '\n';
    std::cout << a << '*' << b << '=' << a * b << '\n';
    return 0;
}
