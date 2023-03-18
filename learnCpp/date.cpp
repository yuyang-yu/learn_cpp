#include <iostream>

class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};

public:
    Date(int year, int month, int day) : m_year{year}, m_month{month}, m_day{day}
    {
    }

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
};

void printDate(const Date &date)
{
    std::cout << date.getYear() << ' ' << date.getMonth() << ' ' << date.getDay() << '\n';
}

int main()
{
    Date d{2022, 9, 10};

    printDate(d);

    return 0;
}