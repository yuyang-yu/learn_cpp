#include <iostream>

class Humidity;

class Temperature
{
private:
    double m_temp{};

public:
    Temperature(double temp = 20.0) : m_temp{temp}
    {
    }

    friend void printWeather(const Temperature &temp, const Humidity &humidity);
};

class Humidity
{
private:
    double m_humidity{};

public:
    Humidity(double humidity = 10.0) : m_humidity{humidity}
    {
    }

    friend void printWeather(const Temperature &temp, const Humidity &humidity);
};

void printWeather(const Temperature &temp, const Humidity &humidity)
{
    std::cout << temp.m_temp << ' ' << humidity.m_humidity << '\n';
}

int main()
{
    Temperature temp{25.0};
    Humidity hum{12.0};

    printWeather(temp, hum);

    return 0;
}
