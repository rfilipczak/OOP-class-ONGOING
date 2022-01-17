#include <iostream>
#include <cmath>

class wektor3D
{
private:
    double x,y,z;
public:
    wektor3D()
        : x{0}, y{0}, z{0}
    {
    }

    wektor3D(double _x, double _y, double _z)
        : x{_x}, y{_y}, z{_z}
    {
    }

    wektor3D operator-() const
    {
        return wektor3D(-x, -y, -z);
    }

    wektor3D operator*(double scalar) const
    {
        return wektor3D(x * scalar, y * scalar, z * scalar);
    }

    friend wektor3D operator*(double scalar, const wektor3D& w)
    {
        return w * scalar;
    }

    friend wektor3D operator+(const wektor3D& a, const wektor3D& b)
    {
        return wektor3D(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    friend wektor3D operator-(const wektor3D& a, const wektor3D& b)
    {
        return wektor3D(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    // iloczyn skalarny
    friend double operator*(const wektor3D& a, const wektor3D& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    // iloczyn wektorowy
    friend wektor3D operator/(const wektor3D& a, const wektor3D& b)
    {
        return wektor3D(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
    }

    double length() const
    {
        return std::sqrt(x*x + y*y + z*z);
    }

    friend double angle(const wektor3D& a, const wektor3D& b)
    {
        return std::acos(a * b / (a.length() * b.length()));
    }

    friend std::ostream& operator<<(std::ostream& out, const wektor3D& w)
    {
        out << "wektor3D{" << "x=" << w.x << ",y=" << w.y << ",z=" << w.z << '}';
        return out;
    }
};


int main()
{
    wektor3D a{1,2,3};
    wektor3D b{4,5,6};

    std::cout << "mnozenie przez liczbe:\n\t";
    std::cout << "5 * " << a << " = " <<  5 * a << '\n';
    std::cout << '\t' << a << " * 5 = " <<  a * 5 << '\n';

    std::cout << "dodawanie/odejmowanie:\n\t";
    std::cout << a << " + " << b << " = " << a + b << '\n';
    std::cout << '\t' << a << " - " << b << " = " << a - b << '\n';

    std::cout << "ilczyn skalarny:\n\t" << a << " * " << b << " = " << a * b << '\n';

    std::cout << "iloczyn wektorowy:\n\t" << a << " / " << b << " = " << a / b << '\n';

    std::cout << "kat pomiedzy wektorami:\n\t";
    std::cout << a << " i " << b << " = " << angle(a,b) << " radianow" << '\n';
    
    return 0;
}
