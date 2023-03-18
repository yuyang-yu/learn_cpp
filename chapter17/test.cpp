#include <iostream>
#include <random>

int getCard(std::mt19937 mt)
{
    std::uniform_int_distribution card{1, 52};
    return card(mt);
}

int main()
{
    std::mt19937 mt{std::random_device{}()}; // this gets created and seeded every time the function is called
    std::cout << getCard(mt);

    return 0;
}
