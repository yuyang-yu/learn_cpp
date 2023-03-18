#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0)
        : m_x{x}, m_y{y}, m_z{z}
    {
    }

    friend std::ostream &operator<<(std::ostream &out, const Point &point);
    friend std::istream &operator>>(std::istream &in, Point &point);
};

std::ostream &operator<<(std::ostream &out, const Point &point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

    return out;
}

std::istream &operator>>(std::istream &in, Point &point)
{
    // Since operator>> is a friend of the Point class, we can access Point's members directly.
    // note that parameter point must be non-const so we can modify the class members with the input values
    in >> point.m_x;
    in >> point.m_y;
    in >> point.m_z;

    return in;
}

int main()
{
    Point point1{2.0, 3.5, 4.0};
    Point point2{6.0, 7.5, 8.0};

    std::cout << point1 << ' ' << point2 << '\n';
    
    std::cout << "Enter a point: ";

    Point point{};
    std::cin >> point;

    std::cout << "You entered: " << point << '\n';

    return 0;
}