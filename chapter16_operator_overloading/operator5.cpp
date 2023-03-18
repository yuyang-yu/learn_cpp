#include <iostream>

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents) : m_cents{cents} {}

    int getCents() const { return m_cents; }

    // friend Cents operator+(const Cents &c, const int value);
    Cents operator+(const int value);
};

// Cents operator+(const Cents &c, const int value)
// {
//     return c.m_cents + value;
// }

Cents Cents::operator+(const int value)
{
    return m_cents + value; 
}

int main()
{
    Cents cents1{6};
    Cents cents2{cents1 + 2};
    std::cout << "I have " << cents2.getCents() << " cents.\n";

    return 0;
}