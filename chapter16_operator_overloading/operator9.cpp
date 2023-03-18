#include <iostream>

class Digit
{
private:
    int m_digit{};

public:
    Digit(int digit) : m_digit{digit} {}

    Digit &operator++();
    Digit &operator--();

    Digit operator++(int);
    Digit operator--(int);

    friend std::ostream &operator<<(std::ostream &out, const Digit &d);
};

Digit &Digit::operator++()
{
    ++m_digit;

    return (*this);
}

Digit &Digit::operator--()
{
    --m_digit;

    return (*this);
}
// note:return_type can not be reference
Digit Digit::operator++(int)
{
    Digit temp{*this};
    ++m_digit;

    return temp;
}

Digit Digit::operator--(int)
{
    Digit temp{*this};
    --m_digit;

    return temp;
}

std::ostream &operator<<(std::ostream &out, const Digit &d)
{
    out << d.m_digit;
    return out;
}

int main()
{
    Digit digit(5);

    std::cout << digit;
    std::cout << ++digit; // calls Digit::operator++();
    std::cout << digit++; // calls Digit::operator++(int);
    std::cout << digit;
    std::cout << --digit; // calls Digit::operator--();
    std::cout << digit--; // calls Digit::operator--(int);
    std::cout << digit;

    return 0;
}