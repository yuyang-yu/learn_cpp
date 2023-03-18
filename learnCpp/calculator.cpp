#include <iostream>
#include <limits>
using std::cin;
using std::cout;

void ignoreLine()
{
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble()
{
    while (true)
    {
        cout << "enter a value:";
        double x{};
        cin >> x;

        if (!cin)
        {
            cin.clear();
            ignoreLine();
            std::cerr << "Thar input is invalid. Please try again.\n";
        }
        else
        {
            ignoreLine();
            return x;
        }
    }
}

char getOperation()
{
    while (true)
    {
        cout << "enter a operation:";
        char operation{};
        cin >> operation;
        ignoreLine();

        switch (operation)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation;

        default:
            std::cerr << "Thar input is invalid. Please try again.\n";
        }
    }
}

void printResult(double x, char operation, double y)
{
    switch (operation)
    {
    case '+':
        cout << x << " + " << y << " = " << (x + y) << '\n';
        break;
    case '-':
        cout << x << " - " << y << " = " << (x - y) << '\n';
        break;
    case '*':
        cout << x << " * " << y << " = " << (x * y) << '\n';
        break;
    case '/':
        cout << x << " / " << y << " = " << (x / y) << '\n';
        break;

    default:
        std::cerr << "Thar input is invalid. Please try again.\n";
    }
}

int main()
{
    double x{getDouble()};
    char operation{getOperation()};
    double y{getDouble()};

    printResult(x, operation, y);

    return 0;
}