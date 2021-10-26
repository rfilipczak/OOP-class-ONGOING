#ifndef POINT_H
#define POINT_H

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


#endif