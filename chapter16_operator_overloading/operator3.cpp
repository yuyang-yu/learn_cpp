#include <iostream>
#include <limits>
#include <numeric> // for std::gcd

class Fraction
{
private:
    int m_numerator{0};
    int m_denominator{1};

public:
    Fraction(int numerator = 0, int denominator = 1) : m_numerator{numerator}, m_denominator{denominator}
    {
        // We put reduce() in the constructor to ensure any new fractions we make get reduced!
        // Any fractions that are overwritten will need to be re-reduced
        reduce();
    }

    void reduce()
    {
        int gcd{std::gcd(m_numerator, m_denominator)};
        if (gcd)
        {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, int value);
    friend Fraction operator*(int value, const Fraction &f1);

    friend std::ostream &operator<<(std::ostream &out, const Fraction &f1);
    friend std::istream &operator>>(std::istream &in, Fraction &f1);

    void print()
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return {f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator};
}

Fraction operator*(const Fraction &f1, int value)
{
    return {f1.m_numerator * value, f1.m_denominator};
}

Fraction operator*(int value, const Fraction &f1)
{
    return {f1.m_numerator * value, f1.m_denominator};
}

std::ostream &operator<<(std::ostream &out, const Fraction &f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

std::istream &operator>>(std::istream &in, Fraction &f1)
{
    // Overwrite the values of f1
    in >> f1.m_numerator;

    // Ignore the '/' separator
    in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
 
    in >> f1.m_denominator;

    // Since we overwrite the existing f1, we need to reduce again
    f1.reduce();

    return in;
}

int main()
{
    Fraction f1;
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2;
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

    return 0;
}