#include <iostream>
#include <cassert>

class Cents
{
private:
    double m_cents{};

public:
    Cents(double cents) : m_cents{cents} {}

    double getCents() const { return m_cents; }

    // friend function
    // friend Cents operator+(const Cents &c1, const Cents &c2);
    // friend Cents operator-(const Cents &c1, const Cents &c2);
    // friend Cents operator*(const Cents &c1, const Cents &c2);
    // friend Cents operator/(const Cents &c1, const Cents &c2);
};

// Cents operator+(const Cents &c1, const Cents &c2)
// {
//     return Cents{c1.m_cents + c2.m_cents};
// }

// Cents operator-(const Cents &c1, const Cents &c2)
// {
//     return Cents{c1.m_cents - c2.m_cents};
// }

// Cents operator*(const Cents &c1, const Cents &c2)
// {
//     return Cents{c1.m_cents * c2.m_cents};
// }

// Cents operator/(const Cents &c1, const Cents &c2)
// {
//     assert(c2.m_cents != 0);
//     return Cents{c1.m_cents / c2.m_cents};
// }

// normal function
Cents operator+(const Cents &c1, const Cents &c2)
{
    return Cents{c1.getCents() + c2.getCents()};
}

Cents operator-(const Cents &c1, const Cents &c2)
{
    return Cents{c1.getCents() - c2.getCents()};
}

Cents operator*(const Cents &c1, const Cents &c2)
{
    return Cents{c1.getCents() * c2.getCents()};
}

Cents operator/(const Cents &c1, const Cents &c2)
{
    return Cents{c1.getCents() / c2.getCents()};
}

int main()
{
    Cents c1{10};
    Cents c2{8};
    std::cout << Cents{c1 + c2}.getCents() << '\n';
    std::cout << Cents{c1 - c2}.getCents() << '\n';
    std::cout << Cents{c1 * c2}.getCents() << '\n';
    std::cout << Cents{c1 / c2}.getCents() << '\n';

    return 0;
}
