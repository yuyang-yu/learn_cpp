#include <iostream>

class Matrix
{
private:
    double data[4][4]{};

public:
    double &operator()(int row, int col);
};

double &Matrix::operator()(int row, int col)
{
    return data[row][col];
}

int main()
{
    Matrix m{};
    m(2, 2) = 10;
    std::cout << m(2, 2) << '\n';

    return 0;
}