#include <iostream>

int main()
{
    int a{5};
    const int b{10};

    // pointer to const
    const int *pb{&a};
    std::cout << "pb: " << *pb << '\n';
    pb = &b;
    // *pb = 30; // invavid
    std::cout << "pb: " <<* pb << '\n';

    // std::cout << "p1: " << *p1 << '\n';

    // const pointer
    int *const pa{&a};
    std::cout << "pa: " << *pa << '\n';
    *pa = 20;
    // pa = &b; // invavid
    std::cout << "pa: " << *pa << '\n';

    // const pointer to a const value
    const int *const pc{&b};
    std::cout << "pc: " << *pc << '\n';

    return 0;
}