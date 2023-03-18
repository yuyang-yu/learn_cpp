#include <iostream>

template <typename T, typename U, typename V>
struct Triad
{
    T first{};
    U second{};
    V third{};
};

template <typename T, typename U, typename V>
Triad(T, U, V) -> Triad<T, U, V>;

template <typename T, typename U, typename V>
void print(Triad<T, U, V> t)
{
    std::cout << '[' << t.first << ',' << t.second << ',' << t.third << ']';
}

int main()
{

    Triad t1{1, 2, 3}; // note: uses CTAD to deduce template arguments
    print(t1);

    Triad t2{1.2, 3.4, 5.6}; // note: uses CTAD to deduce template arguments
    print(t2);

    return 0;
}