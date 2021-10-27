#ifndef SCLASS_H
#define SCLASS_H

#include <iostream>
#include <string>

class S
{
private:
    int i;
    char c;
    const float f{};
    const std::string s{};
public:
    S()
    {
        setInt(0);
        setChar('a');
        std::cout << "Konstruktor domyslny, domyslne wartosci: " << "i=" << getInt() << " c=" << getChar() << " f=" << getF() << " s=" << getS() << '\n';
    }
    
    S(int i, char c)
    {
        setInt(i);
        setChar(c);
        std::cout << "Konstruktor z parametrami int i char: " << getInt() << ' ' << getChar() << '\n';
    }

    S(int _i, char _c, float _f, const std::string& _s)
        : i{_i}, c{_c}, f{_f}, s{_s}
    {
        std::cout << "Konstruktor z lista inicializacyjna: " << _i << ' ' << _c << ' ' << _f << ' ' << _s << '\n';
    }

    S(const S& other)
        : i{other.i}, c{other.c}, f{other.f}, s{other.s}
    {
        std::cout << "Konstruktor kopiujacy z argumentem const reference do: " << other << '\n';
    }
    
    
    int getInt() const { return i; }
    char getChar() const { return c; }
    float getF() const { return f; }
    const std::string& getS() const { return s; }

    void setInt(int _i) { i = _i; }
    void setChar(char _c) { c = _c; };

    friend std::ostream& operator<<(std::ostream& out, const S& s)
    {
        out << "S{i=" << s.getInt() << ", c=" << s.getChar() << ", f=" << s.getF() << ", s=" << s.getS() << '}';
        return out;
    }
};

#endif
