//
// Created by rfilipczak on 21.11.2021.
//

#include <cmath>
#include <iostream>

namespace constants
{
    inline constexpr double pi = 3.141592;
}

class Figure
{
public:
    [[nodiscard]] virtual double Area() const = 0;
    [[nodiscard]] virtual double Volume() const = 0;
};

class FigureWithDiagonal : public Figure
{
public:
    [[nodiscard]] virtual double Diagonal() const = 0;
};

class Sphere : public Figure
{
private:
    double radius{};
public:
    explicit Sphere(double _r)
            : radius{_r}
    {
    }

    [[nodiscard]] double Area() const override
    {
        return 4.0 * constants::pi * radius * radius;
    }

    [[nodiscard]] double Volume() const override
    {
        return 4.0 / 3.0 * constants::pi * radius * radius * radius;
    }

    friend std::ostream& operator<<(std::ostream& out, const Sphere& sphere)
    {
        out << "Sphere{" << "radius=" << sphere.radius << '}';
        return out;
    }
};

class Cuboid : public FigureWithDiagonal
{
private:
    double length{};
    double width{};
    double height{};
public:
    explicit Cuboid(double _length, double _width, double _height)
            : length{_length}, width{_width}, height{_height}
    {
    }

    [[nodiscard]] double Area() const override
    {
        return 2.0 * (width * length + height * length + height * width);
    }

    [[nodiscard]] double Volume() const override
    {
        return length * width * height;
    }

    [[nodiscard]] double Diagonal() const override
    {
        return std::sqrt(length * length + width * width + height * height);
    }

    friend std::ostream& operator<<(std::ostream& out, const Cuboid& cuboid)
    {
        out << "Cuboid{" << "length=" << cuboid.length << ", width=" << cuboid.width << ", height=" << cuboid.height << '}';
        return out;
    }
};

class Pyramid : public Figure
{
private:
    double baseLength{};
    double baseWidth{};
    double height{};
public:
    explicit Pyramid(double _baseLength, double _baseWidth, double _height)
            : baseLength{_baseLength}, baseWidth{_baseWidth}, height{_height}
    {
    }

    [[nodiscard]] double Area() const override
    {
        auto height2 = height * height;
        return baseWidth * baseLength +
        baseWidth * sqrt(baseLength * baseLength / 4.0 + height2) +
        baseLength * sqrt(baseWidth * baseWidth / 4.0 + height2);
    }

    [[nodiscard]] double Volume() const override
    {
        return (baseLength * baseWidth * height) / 3.0;
    }

    friend std::ostream& operator<<(std::ostream& out, const Pyramid& pyramid)
    {
        out << "Pyramid{" << "baseLength=" << pyramid.baseLength << ", baseWidth=" << pyramid.baseWidth << ", height=" << pyramid.height << '}';
        return out;
    }
};

int main()
{
    const Sphere sphere{10};
    std::cout << sphere << " area = " << sphere.Area() << ", volume = " << sphere.Volume() << '\n';

    const Cuboid cuboid{10, 10, 10};
    std::cout << cuboid << " area = " << cuboid.Area() << ", volume = " << cuboid.Volume() << ", diagonal = " << cuboid.Diagonal() << '\n';

    const Pyramid pyramid{10,10,10};
    std::cout << pyramid << " area = " << pyramid.Area() << ", volume = " << pyramid.Volume() << '\n';

    return 0;
}
