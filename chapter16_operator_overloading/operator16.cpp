#include <iostream>
#include <cstdint> // for fixed width integers

class Average
{
private:
    int m_total{0};  // the sum of all numbers we've seen so far
    int m_numbers{0}; // the count of numbers we've seen so far

public:
    Average()
    {
    }

    friend std::ostream &operator<<(std::ostream &out, const Average &average)
    {
        // Our average is the sum of the numbers we've seen divided by the count of the numbers we've seen
        // We need to remember to do a floating point division here, not an integer division
        out << static_cast<double>(average.m_total) / average.m_numbers;

        return out;
    }

    // Because operator+= modifies its left operand, we'll write it as a member
    Average &operator+=(int num)
    {
        // Increment our total by the new number
        m_total += num;
        // And increase the count by 1
        ++m_numbers;

        // return *this in case someone wants to chain +='s together
        return *this;
    }
};

int main()
{
    Average avg{};

    avg += 4;
    std::cout << avg << '\n';

    avg += 8;
    std::cout << avg << '\n';

    avg += 24;
    std::cout << avg << '\n';

    avg += -10;
    std::cout << avg << '\n';

    (avg += 6) += 10; // 2 calls chained together
    std::cout << avg << '\n';

    Average copy{avg};
    std::cout << copy << '\n';

    return 0;
}