#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

#include "./point.hpp"
#include "./objCounter.hpp"

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

    ~Vector()
    {
        std::cout << "Destruktor obiektu Vector\n";
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


#endif