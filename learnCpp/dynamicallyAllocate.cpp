#include <algorithm>
#include <iostream>
#include <string>

int getNameCount()
{
    int count{};
    std::cout << "How many names would you like to enter?  ";
    std::cin >> count;
    return count;
}

void getName(std::string *name, int count)
{
    for (int i{0}; i < count; ++i)
    {
        std::cout << "Enter name: #" << (i + 1) << ": ";
        std::getline(std::cin >> std::ws, name[i]);
    }
}

void printName(std::string *name, int count)
{
    std::cout << "Here is your sorted list:\n";
    for (int i{0}; i < count; ++i)
    {
        std::cout << "Name #" << (i + 1) << ": " << name[i] << '\n';
    }
}

int main()
{
    int length{getNameCount()};
    auto *array{new std::string[length]{}};

    getName(array, length);
    std::cout << '\n';

    // sort the array
    std::sort(array, array + length);

    printName(array, length);

    return 0;
}