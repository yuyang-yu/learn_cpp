#include <iostream>

class Accummlator
{
private:
    int m_counter{};

public:
    Accummlator(int counter = 0) : m_counter{counter} {}

    int operator()(int i) { return i += m_counter; }
};

int main()
{
    Accummlator acc{50};
    std::cout << acc(10) << '\n';
    std::cout << acc(20) << '\n';

    return 0;
}