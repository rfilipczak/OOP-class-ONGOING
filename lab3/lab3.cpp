#include <iostream>
#include <string_view>
#include <string>


struct Point
{
    int x{}, y{};

    Point() = default;
    Point(int _x, int _y)
        : x{_x}, y{_y}
    {
    }
    friend Point operator+(const Point& a, const Point& b)
    {
        return Point(a.x + b.x, a.y + b.y);
    }
    friend Point operator-(const Point& a, const Point& b)
    {
        return Point(a.x - b.x, a.y - b.y);
    }
    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        out << "Point{" << p.x << ',' << p.y << '}';
        return out;
    }
};

template <class T>
class ObjCounter
{
private:
    static inline int objCount{0};
protected:
    ObjCounter()
    {
        ++objCount;
    }
    ~ObjCounter()
    {
        --objCount;
    }
public:
    static int getObjCount() { return objCount; }
};

class Vector: public ObjCounter<Vector>
{
private:
    Point start{};
    Point end{};
public:
    Vector() = default;
    
    Vector(const Point& _start, const Point& _end)
        : start{_start}, end{_end}
    {
    }
    
    Vector(const Vector& other)
        : start{other.start}, end{other.end}
    {
    }

    Vector(const Vector&&) = delete;

    ~Vector()
    {
        std::cout << "Dekonstruktor obiektu Vector\n";
    }

    friend Vector operator+(const Vector& a, const Vector& b)
    {
        return Vector(a.start + b.start, a.end + b.end);
    }

    friend Vector operator-(const Vector& a, const Vector& b)
    {
        return Vector(a.start - b.start, a.end - b.end);
    }

    int dotProduct(const Vector& other) const noexcept
    {
        return start.x * other.start.x + start.y * other.start.y + end.x * other.end.x + end.y * other.end.y;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& v)
    {
        out << "Vector{start=" << v.start << ", end=" << v.end << '}';
        return out;
    }
};


class S: public ObjCounter<S>
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
        std::cout << "Konstruktor domyslny, domyslne wartosci: " << "i:" << getInt() << " c:" << getChar() << " f:" << getF() << " s:" << getS() << '\n';
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


int main()
{
    std::cout << "Hello lab3\n\n";
    
    {
        Vector vec0 = Vector({-1,123}, {123,123});
        Vector vec{{0,0}, {1,1}};
        Vector vec2({-21,32}, {31,33});

        std::cout << vec << " + " << vec2 << " = " << vec + vec2 << '\n';
        std::cout << vec << " - " << vec2 << " = " << vec - vec2 << '\n';
        std::cout << vec << " dot product " << vec2 << " = " << vec.dotProduct(vec2) << '\n';

        std::cout << "\nIlosc obiektow typu Vector: " << Vector::getObjCount() << "\n\n";
    }
    std::cout << "\nIlosc obiektow typu Vector: " << Vector::getObjCount() << "\n\n";

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
