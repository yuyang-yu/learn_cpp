#include <iostream>
#include <string>

int main()
{
    std::cout << "char: " << sizeof(char) << '\n';
    std::cout << "string: " << sizeof(std::string) << '\n';

    std::cout << "short: " << sizeof(short) << '\n';
    std::cout << "int: " << sizeof(int) << '\n';

    std::cout << "double: " << sizeof(double) << '\n';

    return 0;
}