#include<iostream>

class Base
{
public:
    virtual std::ostream& print(std::ostream& out) const
    {
        out << "Base";
        return out;
    }

    friend std::ostream &operator<<(std::ostream &out, const Base &b);
};

std::ostream &operator<<(std::ostream &out, const Base &b)
{
    return b.print(out);
}

class Derived:public Base
{
public:
    std::ostream& print(std::ostream& out) const override
    {
        out << "Derived";
        return out;
    }
};

int main()
{
    Base b{};
    std::cout << b << '\n';

    Derived d{};
    std::cout << d << '\n'; // note that this works even with no operator<< that explicitly handles Derived objects

    Base &bref{d};
    std::cout << bref << '\n';

    return 0;
}