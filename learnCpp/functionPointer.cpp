#include <cassert>
#include <functional>
#include <iostream>

int getInteger()
{
    int input{};
    std::cout << "Enter a value: ";
    std::cin >> input;
    return input;
}

char getOperation()
{
    char op{};
    do
    {
        std::cout << "Enter an op: ";
        std::cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');
    return op;
}

int add(int a, int b) { return (a + b); }

int subtract(int a, int b) { return (a - b); }

int multiply(int a, int b) { return (a * b); }

int division(int a, int b) { return (a / b); }

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op)
{
    switch (op)
    {
    case '+':
        return &add;
    case '-':
        return &subtract;
    case '*':
        return &multiply;
    case '/':
        return &division;

    default:
        return nullptr;
    }
}

int main()
{
    int a{getInteger()};
    char op{getOperation()};
    int b{getInteger()};

    ArithmeticFunction fcn{getArithmeticFunction(op)};
    assert(fcn);
    std::cout << fcn(a, b);

    return 0;
}
