#include <iostream>

template <typename T>
T average(const T *myArray, int numValues)
{
    T sum{0};
    for (int count{0}; count < numValues; ++count)
        sum += myArray[count];

    sum /= numValues;
    return sum;
}

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents)
        : m_cents{cents}
    {
    }

    friend std::ostream &operator<<(std::ostream &out, const Cents &c);

    Cents &operator+=(const Cents &c);
    Cents &operator/=(const int x);
};

std::ostream &operator<<(std::ostream &out, const Cents &c)
{
    out << c.m_cents;

    return out;
}

Cents &Cents::operator+=(const Cents &c)
{
    // return Cents{m_cents += c.m_cents};
    m_cents += c.m_cents;
    return *this;
}

Cents &Cents::operator/=(const int x)
{
    // return Cents{m_cents /= x};
    m_cents /= x;
    return *this;
}

int main()
{
    Cents centsArray[]{Cents{5}, Cents{10}, Cents{15}, Cents{14}};
    std::cout << average(centsArray, 4) << '\n';

    return 0;
}